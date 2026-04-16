from __future__ import annotations

import json
import tempfile
import unittest
from pathlib import Path

from lighthouse_inference_runner import load_request


class LighthouseInferenceRunnerTests(unittest.TestCase):
    def test_load_request_accepts_utf8_bom(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            request_path = Path(temp_dir) / "request.json"
            request_path.write_text(
                json.dumps({"videoPath": "demo.mp4"}, ensure_ascii=False),
                encoding="utf-8-sig",
            )

            payload = load_request(request_path)

        self.assertEqual(payload["videoPath"], "demo.mp4")


if __name__ == "__main__":
    unittest.main()
