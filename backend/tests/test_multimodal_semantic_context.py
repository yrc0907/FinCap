from __future__ import annotations

import unittest

import numpy as np

from services.multimodal_semantic_context import (
    NormalizedSubtitleRegion,
    build_short_video_semantic_rubric,
    compact_text_evidence,
    encode_vlm_frame_variants,
    format_multimodal_evidence_block,
    select_asr_text_for_window,
)


class MultimodalSemanticContextTests(unittest.TestCase):
    def test_encode_vlm_frame_variants_adds_subtitle_crop(self) -> None:
        frame = np.zeros((120, 200, 3), dtype=np.uint8)
        frame[72:108, 20:180] = 255

        images = encode_vlm_frame_variants(
            frame=frame,
            time_sec=12.345,
            subtitle_region=NormalizedSubtitleRegion(x=0.1, y=0.6, width=0.8, height=0.3),
        )

        self.assertEqual(len(images), 2)
        self.assertEqual([item["kind"] for item in images], ["scene", "subtitle"])
        self.assertEqual(images[0]["timeSec"], 12.345)
        self.assertEqual(images[1]["timeSec"], 12.345)
        self.assertTrue(images[0]["jpegBase64"])
        self.assertTrue(images[1]["jpegBase64"])

    def test_short_video_rubric_mentions_pressure_and_low_value_transitions(self) -> None:
        rubric = build_short_video_semantic_rubric()

        self.assertIn("threats, pressure, scolding, humiliation", rubric)
        self.assertIn("ordinary walking, calm transition, plain exposition", rubric)

    def test_compact_text_evidence_deduplicates_and_strips(self) -> None:
        evidence = compact_text_evidence([" boss ", "", "Boss", "Finish it today"])

        self.assertEqual(evidence, ["boss", "Finish it today"])

    def test_select_asr_text_for_window_returns_overlapping_segments(self) -> None:
        segments = [
            {"startSec": 0.0, "endSec": 1.0, "text": "hello"},
            {"startSec": 1.2, "endSec": 2.0, "text": "finish it today"},
        ]

        selected = select_asr_text_for_window(segments, 1.0, 2.2)

        self.assertEqual(selected, ["finish it today"])

    def test_format_multimodal_evidence_block_lists_each_evidence_source(self) -> None:
        block = format_multimodal_evidence_block(
            text_evidence_lines=["You must finish it today."],
            text_evidence_source="ocr",
            text_evidence_conflict=False,
            text_evidence_note="",
            character_references=[{"name": "大雄"}],
        )

        self.assertIn("Text evidence source: ocr", block)
        self.assertIn("Character references", block)
        self.assertIn("大雄", block)


if __name__ == "__main__":
    unittest.main()
