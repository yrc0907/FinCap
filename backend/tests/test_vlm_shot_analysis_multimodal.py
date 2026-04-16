from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

from api_models import VlmShotAnalysisRequest
from services.multimodal_semantic_context import NormalizedSubtitleRegion
from services.vlm_shot_analysis import (
    VlmShotAnalysisConfig,
    _build_prompt_with_frames,
    analyze_shot_sequence,
)


class VlmShotAnalysisMultimodalTests(unittest.TestCase):
    def test_request_model_accepts_subtitle_region(self) -> None:
        payload = VlmShotAnalysisRequest.model_validate(
            {
                "shots": [
                    {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
                ],
                "vlmConfig": {
                    "endpoint": "https://example.com/v1/chat/completions",
                    "key": "demo",
                    "model": "gpt-4.1",
                },
                "group_size": 2,
                "keyframes_per_shot": 2,
                "highlight_threshold": 0.7,
                "enableSubtitleRegion": True,
                "subtitleRegion": {
                    "x": 0.05,
                    "y": 0.78,
                    "width": 0.9,
                    "height": 0.18,
                },
                "promptProfile": "short-video",
            }
        )

        self.assertTrue(payload.enableSubtitleRegion)
        self.assertIsNotNone(payload.subtitleRegion)
        self.assertEqual(payload.promptProfile, "short-video")

    def test_request_model_accepts_asr_and_character_references(self) -> None:
        payload = VlmShotAnalysisRequest.model_validate(
            {
                "shots": [
                    {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
                ],
                "vlmConfig": {
                    "endpoint": "https://example.com/v1/chat/completions",
                    "key": "demo",
                    "model": "gpt-4.1",
                },
                "enableSubtitleRegion": True,
                "subtitleRegion": {
                    "x": 0.05,
                    "y": 0.78,
                    "width": 0.9,
                    "height": 0.18,
                },
                "promptProfile": "short-video",
                "enableOcr": True,
                "enableAutoAsr": True,
                "asrText": "Boss is scolding Nobita's father.",
                "asrSegments": [
                    {"startSec": 0.5, "endSec": 1.6, "text": "You must finish it today."},
                ],
                "characterReferences": [
                    {"name": "大雄", "imageBase64": "demo-image"},
                ],
            }
        )

        self.assertTrue(payload.enableOcr)
        self.assertTrue(payload.enableAutoAsr)
        self.assertEqual(payload.asrText, "Boss is scolding Nobita's father.")
        self.assertEqual(len(payload.asrSegments), 1)
        self.assertEqual(payload.characterReferences[0].name, "大雄")

    def test_prompt_includes_ocr_asr_character_and_speaker_fields(self) -> None:
        prompt = _build_prompt_with_frames(
            shot_lines="- shot 1: 0.000s to 2.000s",
            images=[
                {"timeSec": 1.0, "jpegBase64": "scene-a", "kind": "scene"},
                {"timeSec": 1.0, "jpegBase64": "subtitle-a", "kind": "subtitle"},
            ],
            include_subtitle_region=True,
            prompt_profile="short-video",
            ocr_lines=["You must finish it today."],
            asr_lines=["Boss: You must finish it today."],
            character_references=[{"name": "大雄"}],
        )

        self.assertIn("speaker_hint", prompt)
        self.assertIn("speaker_confidence", prompt)
        self.assertIn("OCR evidence", prompt)
        self.assertIn("ASR evidence", prompt)
        self.assertIn("Character references", prompt)
        self.assertIn("大雄", prompt)
        self.assertIn("You must finish it today.", prompt)

    @patch("services.vlm_shot_analysis._extract_keyframes_for_shot")
    @patch("services.vlm_shot_analysis.extract_ocr_lines")
    @patch("services.vlm_shot_analysis.call_openai_compatible_vision")
    def test_multimodal_prompt_mentions_subtitle_and_high_peak_rubric(
        self,
        call_openai_mock,
        extract_ocr_mock,
        extract_keyframes_mock,
    ) -> None:
        extract_keyframes_mock.return_value = [
            {"timeSec": 1.2, "jpegBase64": "scene-a", "kind": "scene"},
            {"timeSec": 1.2, "jpegBase64": "subtitle-a", "kind": "subtitle"},
        ]
        extract_ocr_mock.return_value = ["You must finish it today."]
        call_openai_mock.return_value = {
            "is_continuous_story": True,
            "highlight_score": 0.82,
            "peak_times": [1.2],
            "peak_role": "conflict",
            "reason": "Strong pressure and confrontation are visible in subtitle and image.",
            "speaker_hint": "boss",
            "speaker_confidence": 0.76,
        }

        analyze_shot_sequence(
            video_path=Path("demo.mp4"),
            shots=[{"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0}],
            vlm_config={
                "endpoint": "https://example.com/v1/chat/completions",
                "key": "demo",
                "model": "gpt-4.1",
            },
            config=VlmShotAnalysisConfig(
                group_size=2,
                keyframes_per_shot=2,
                enable_ocr=True,
                enable_auto_asr=False,
                enable_subtitle_region=True,
                subtitle_region=NormalizedSubtitleRegion(x=0.05, y=0.78, width=0.9, height=0.18),
                prompt_profile="short-video",
            ),
            asr_text="Boss: You must finish it today.",
            character_references=[{"name": "大雄", "imageBase64": "demo-character"}],
        )

        prompt = call_openai_mock.call_args.kwargs["prompt"]
        images = call_openai_mock.call_args.kwargs["images"]
        self.assertIn("subtitle-region crops", prompt)
        self.assertIn("threats, pressure, scolding, humiliation", prompt)
        self.assertIn("OCR evidence", prompt)
        self.assertIn("ASR evidence", prompt)
        self.assertIn("Character references", prompt)
        self.assertEqual([item["kind"] for item in images], ["character-reference", "scene", "subtitle"])


if __name__ == "__main__":
    unittest.main()
