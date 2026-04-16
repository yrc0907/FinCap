from __future__ import annotations

import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from run_dual_functional_comparison import run_comparison


class RunDualFunctionalComparisonTests(unittest.TestCase):
    @patch("run_dual_functional_comparison.export_functional_clips")
    @patch("run_dual_functional_comparison.extract_lighthouse_segments")
    @patch("run_dual_functional_comparison.extract_shot_level_vlm_segments")
    @patch("run_dual_functional_comparison.generate_corrected_event_timeline")
    @patch("run_dual_functional_comparison.analyze_adjacent_story_reassignment")
    @patch("run_dual_functional_comparison.analyze_shot_sequence")
    def test_run_comparison_writes_separate_route_outputs(
        self,
        analyze_shot_sequence_mock,
        analyze_adjacent_story_reassignment_mock,
        generate_corrected_event_timeline_mock,
        extract_shot_level_vlm_segments_mock,
        extract_lighthouse_segments_mock,
        export_functional_clips_mock,
    ) -> None:
        analyze_shot_sequence_mock.return_value = {
            "groups": [{"index": 1, "startSec": 0.0, "endSec": 4.0, "shotIndexes": [1, 2]}],
            "summary": {"groupCount": 1},
        }
        analyze_adjacent_story_reassignment_mock.return_value = {
            "pairs": [],
            "summary": {"pairCount": 0},
        }
        generate_corrected_event_timeline_mock.return_value = {
            "events": [{"index": 1, "startSec": 0.0, "endSec": 4.0, "sourceGroupIndexes": [1]}],
            "summary": {"eventCount": 1},
        }
        extract_shot_level_vlm_segments_mock.return_value = {
            "peakClips": [
                {"index": 1, "label": "peak", "type": "peak", "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0}
            ],
            "summary": {"peakClipCount": 1},
        }
        extract_lighthouse_segments_mock.return_value = {
            "status": "ok",
            "peakClips": [
                {
                    "index": 1,
                    "label": "lighthouse_peak",
                    "type": "peak",
                    "startSec": 2.0,
                    "endSec": 4.0,
                    "durationSec": 2.0,
                }
            ],
            "summary": {"peakClipCount": 1},
        }
        export_functional_clips_mock.side_effect = [
            {"clips": [{"file": "vlm_peak.mp4"}]},
            {"clips": [{"file": "lighthouse_peak.mp4"}]},
        ]

        with tempfile.TemporaryDirectory() as temp_dir:
            temp_path = Path(temp_dir)
            manifest_path = temp_path / "strict_shots.json"
            manifest_path.write_text(
                json.dumps(
                    {
                        "video": str((temp_path / "demo.mp4").resolve()),
                        "strictShots": {
                            "shots": [
                                {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
                                {"index": 2, "startSec": 2.0, "endSec": 4.0, "durationSec": 2.0},
                            ]
                        },
                    },
                    ensure_ascii=False,
                    indent=2,
                ),
                encoding="utf-8",
            )

            result = run_comparison(
                manifest_path=manifest_path,
                output_dir=temp_path / "out",
                vlm_config={"endpoint": "https://example.com", "key": "demo", "model": "gpt-4.1"},
            )

            self.assertEqual(result["routes"]["shotLevelVlm"]["peakClipCount"], 1)
            self.assertEqual(result["routes"]["lighthouse"]["peakClipCount"], 1)
            self.assertTrue((temp_path / "out" / "comparison_summary.json").exists())
            self.assertTrue((temp_path / "out" / "shot-level-vlm" / "result.json").exists())
            self.assertTrue((temp_path / "out" / "lighthouse" / "result.json").exists())


if __name__ == "__main__":
    unittest.main()
