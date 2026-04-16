from __future__ import annotations

import unittest

from services.corrected_event_timeline import generate_corrected_event_timeline


class CorrectedEventTimelineTests(unittest.TestCase):
    def test_trims_left_event_and_extends_right_event(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {"index": 1, "startSec": 0.0, "endSec": 10.0},
                {"index": 2, "startSec": 10.0, "endSec": 20.0},
            ],
            adjacent_pairs=[
                {
                    "leftGroupIndex": 1,
                    "rightGroupIndex": 2,
                    "shouldReassignTail": True,
                    "reassignFromSec": 8.5,
                }
            ],
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["events"]],
            [(0.0, 8.5), (8.5, 20.0)],
        )
        self.assertEqual(result["summary"]["changedEventCount"], 2)

    def test_boundary_aligned_reassignment_keeps_same_ranges(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {"index": 1, "startSec": 0.0, "endSec": 8.0},
                {"index": 2, "startSec": 8.0, "endSec": 16.0},
            ],
            adjacent_pairs=[
                {
                    "leftGroupIndex": 1,
                    "rightGroupIndex": 2,
                    "shouldReassignTail": True,
                    "reassignFromSec": 8.0,
                }
            ],
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["events"]],
            [(0.0, 8.0), (8.0, 16.0)],
        )
        self.assertEqual(result["summary"]["changedEventCount"], 0)

    def test_middle_event_can_receive_prev_tail_and_trim_to_next(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {"index": 1, "startSec": 0.0, "endSec": 10.0},
                {"index": 2, "startSec": 10.0, "endSec": 20.0},
                {"index": 3, "startSec": 20.0, "endSec": 30.0},
            ],
            adjacent_pairs=[
                {
                    "leftGroupIndex": 1,
                    "rightGroupIndex": 2,
                    "shouldReassignTail": True,
                    "reassignFromSec": 8.0,
                },
                {
                    "leftGroupIndex": 2,
                    "rightGroupIndex": 3,
                    "shouldReassignTail": True,
                    "reassignFromSec": 18.0,
                },
            ],
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["events"]],
            [(0.0, 8.0), (8.0, 18.0), (18.0, 30.0)],
        )
        self.assertEqual(result["events"][1]["sourceGroupIndexes"], [1, 2])
        self.assertEqual(result["summary"]["changedEventCount"], 3)

    def test_marks_peak_overlap_span_as_keep(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 10.0,
                    "peakTimesSec": [],
                    "peakRole": "setup",
                    "highlightScore": 0.35,
                },
                {
                    "index": 2,
                    "startSec": 10.0,
                    "endSec": 20.0,
                    "peakTimesSec": [12.0],
                    "peakRole": "conflict",
                    "highlightScore": 0.82,
                },
            ],
            adjacent_pairs=[
                {
                    "leftGroupIndex": 1,
                    "rightGroupIndex": 2,
                    "shouldReassignTail": True,
                    "reassignFromSec": 8.0,
                }
            ],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 5.0},
                {"index": 2, "startSec": 5.0, "endSec": 10.0},
                {"index": 3, "startSec": 10.0, "endSec": 15.0},
                {"index": 4, "startSec": 15.0, "endSec": 20.0},
            ],
        )

        keep_spans = [
            (item["startSec"], item["endSec"], item["label"])
            for item in result["events"][1]["narrationSpans"]
            if item["label"] == "keep"
        ]
        self.assertIn((10.0, 15.0, "keep"), keep_spans)

    def test_marks_low_transition_middle_span_as_drop(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 12.0,
                    "peakTimesSec": [],
                    "peakRole": "transition",
                    "highlightScore": 0.22,
                }
            ],
            adjacent_pairs=[],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 4.0},
                {"index": 2, "startSec": 4.0, "endSec": 8.0},
                {"index": 3, "startSec": 8.0, "endSec": 12.0},
            ],
        )

        self.assertEqual(
            [item["label"] for item in result["events"][0]["narrationSpans"]],
            ["bridge", "drop", "bridge"],
        )

    def test_merges_adjacent_bridge_spans_within_same_event(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 8.0,
                    "peakTimesSec": [],
                    "peakRole": "setup",
                    "highlightScore": 0.32,
                }
            ],
            adjacent_pairs=[],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0},
                {"index": 2, "startSec": 2.0, "endSec": 4.0},
                {"index": 3, "startSec": 4.0, "endSec": 8.0},
            ],
        )

        self.assertEqual(len(result["events"][0]["narrationSpans"]), 1)
        self.assertEqual(result["events"][0]["narrationSpans"][0]["label"], "bridge")
        self.assertEqual(
            (result["events"][0]["narrationSpans"][0]["startSec"], result["events"][0]["narrationSpans"][0]["endSec"]),
            (0.0, 8.0),
        )

    def test_exports_keep_and_bridge_spans_as_selected_clips(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 12.0,
                    "peakTimesSec": [6.0],
                    "peakRole": "conflict",
                    "highlightScore": 0.8,
                }
            ],
            adjacent_pairs=[],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 4.0},
                {"index": 2, "startSec": 4.0, "endSec": 8.0},
                {"index": 3, "startSec": 8.0, "endSec": 12.0},
            ],
        )

        self.assertEqual(
            [item["label"] for item in result["selectedClips"]],
            ["bridge", "keep", "bridge"],
        )
        self.assertEqual(result["summary"]["selectedClipCount"], 3)

    def test_excludes_drop_spans_from_selected_clips(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 12.0,
                    "peakTimesSec": [],
                    "peakRole": "transition",
                    "highlightScore": 0.22,
                }
            ],
            adjacent_pairs=[],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 4.0},
                {"index": 2, "startSec": 4.0, "endSec": 8.0},
                {"index": 3, "startSec": 8.0, "endSec": 12.0},
            ],
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"], item["label"]) for item in result["selectedClips"]],
            [(0.0, 4.0, "bridge"), (8.0, 12.0, "bridge")],
        )
        self.assertEqual(result["summary"]["selectedBridgeClipCount"], 2)

    def test_selected_clips_include_frame_aligned_export_metadata(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 16.153,
                    "peakTimesSec": [12.0],
                    "peakRole": "conflict",
                    "highlightScore": 0.8,
                }
            ],
            adjacent_pairs=[],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 10.753},
                {"index": 2, "startSec": 10.753, "endSec": 16.153},
            ],
            fps=30.0,
            video_duration_sec=60.967,
        )

        self.assertEqual(result["selectedClips"][0]["exportStartFrame"], 0)
        self.assertEqual(result["selectedClips"][0]["exportEndFrame"], 323)
        self.assertEqual(result["selectedClips"][1]["exportStartFrame"], 323)
        self.assertEqual(result["selectedClips"][1]["exportEndFrame"], 485)

    def test_snaps_semantic_boundaries_back_to_strict_shot_boundaries(self) -> None:
        result = generate_corrected_event_timeline(
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 10.753,
                    "peakTimesSec": [],
                    "peakRole": "setup",
                    "highlightScore": 0.35,
                },
                {
                    "index": 2,
                    "startSec": 10.753,
                    "endSec": 16.153,
                    "peakTimesSec": [12.0],
                    "peakRole": "conflict",
                    "highlightScore": 0.8,
                },
            ],
            adjacent_pairs=[],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 10.733},
                {"index": 2, "startSec": 10.733, "endSec": 16.133},
            ],
            fps=30.0,
            video_duration_sec=60.967,
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["events"]],
            [(0.0, 10.733), (10.733, 16.133)],
        )
        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["selectedClips"]],
            [(0.0, 10.733), (10.733, 16.133)],
        )
        self.assertEqual(result["selectedClips"][0]["exportEndFrame"], 322)
        self.assertEqual(result["selectedClips"][1]["exportStartFrame"], 322)

    def test_attaches_functional_clips_that_stop_before_unrelated_tail(self) -> None:
        result = generate_corrected_event_timeline(
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
            adjacent_pairs=[],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0},
                {"index": 2, "startSec": 2.0, "endSec": 4.0},
                {"index": 3, "startSec": 4.0, "endSec": 6.0},
                {"index": 4, "startSec": 6.0, "endSec": 8.0},
                {"index": 5, "startSec": 8.0, "endSec": 10.0},
            ],
        )

        self.assertEqual(
            [(item["type"], item["startSec"], item["endSec"]) for item in result["functionalClips"]],
            [("build", 0.0, 4.0), ("peak", 4.0, 6.0)],
        )
        self.assertEqual(
            [(item["type"], item["startSec"], item["endSec"]) for item in result["events"][0]["functionalSegments"]],
            [("build", 0.0, 4.0), ("peak", 4.0, 6.0)],
        )
        self.assertEqual(
            [(item["type"], item["startSec"], item["endSec"]) for item in result["events"][1]["functionalSegments"]],
            [("transition", 6.0, 10.0)],
        )


if __name__ == "__main__":
    unittest.main()
