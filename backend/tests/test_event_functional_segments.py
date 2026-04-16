from __future__ import annotations

import unittest

from services.event_functional_segments import extract_event_functional_segments


class EventFunctionalSegmentsTests(unittest.TestCase):
    def test_extracts_build_peak_result_around_peak_shot(self) -> None:
        result = extract_event_functional_segments(
            events=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 10.0,
                    "durationSec": 10.0,
                    "sourceGroupIndexes": [1],
                }
            ],
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 10.0,
                    "peakTimesSec": [4.5],
                    "peakRole": "conflict",
                    "highlightScore": 0.82,
                }
            ],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
                {"index": 2, "startSec": 2.0, "endSec": 4.0, "durationSec": 2.0},
                {"index": 3, "startSec": 4.0, "endSec": 6.0, "durationSec": 2.0},
                {"index": 4, "startSec": 6.0, "endSec": 8.0, "durationSec": 2.0},
                {"index": 5, "startSec": 8.0, "endSec": 10.0, "durationSec": 2.0},
            ],
        )

        self.assertEqual(
            [
                (item["type"], item["startSec"], item["endSec"], item["selected"])
                for item in result["events"][0]["functionalSegments"]
            ],
            [
                ("build", 0.0, 4.0, True),
                ("peak", 4.0, 6.0, True),
                ("result", 6.0, 8.0, True),
                ("transition", 8.0, 10.0, False),
            ],
        )
        self.assertEqual(
            [item["type"] for item in result["functionalClips"]],
            ["build", "peak", "result"],
        )

    def test_stops_before_unrelated_trailing_group(self) -> None:
        result = extract_event_functional_segments(
            events=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 10.0,
                    "durationSec": 10.0,
                    "sourceGroupIndexes": [1, 2],
                }
            ],
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 6.0,
                    "peakTimesSec": [4.5],
                    "peakRole": "conflict",
                    "highlightScore": 0.82,
                },
                {
                    "index": 2,
                    "startSec": 6.0,
                    "endSec": 10.0,
                    "peakTimesSec": [],
                    "peakRole": "transition",
                    "highlightScore": 0.22,
                },
            ],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
                {"index": 2, "startSec": 2.0, "endSec": 4.0, "durationSec": 2.0},
                {"index": 3, "startSec": 4.0, "endSec": 6.0, "durationSec": 2.0},
                {"index": 4, "startSec": 6.0, "endSec": 8.0, "durationSec": 2.0},
                {"index": 5, "startSec": 8.0, "endSec": 10.0, "durationSec": 2.0},
            ],
        )

        self.assertEqual(
            [
                (item["type"], item["startSec"], item["endSec"])
                for item in result["events"][0]["functionalSegments"]
            ],
            [
                ("build", 0.0, 4.0),
                ("peak", 4.0, 6.0),
                ("transition", 6.0, 10.0),
            ],
        )
        self.assertEqual(
            [(item["type"], item["startSec"], item["endSec"]) for item in result["functionalClips"]],
            [("build", 0.0, 4.0), ("peak", 4.0, 6.0)],
        )


if __name__ == "__main__":
    unittest.main()
