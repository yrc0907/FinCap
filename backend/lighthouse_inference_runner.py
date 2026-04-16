from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path
from typing import Any
from urllib.request import urlretrieve


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run Lighthouse inference in an isolated runtime.")
    parser.add_argument("--input", required=True, help="JSON request path.")
    parser.add_argument("--output", required=True, help="JSON result path.")
    return parser.parse_args()


def ensure_checkpoint(weight_dir: Path, feature_name: str, model_name: str) -> Path:
    weight_dir.mkdir(parents=True, exist_ok=True)
    file_name = f"{feature_name}_{model_name}_qvhighlight.ckpt"
    checkpoint_path = weight_dir / file_name
    if checkpoint_path.exists():
        return checkpoint_path
    url = f"https://zenodo.org/records/13960580/files/{file_name}"
    print(f"[Download] Lighthouse checkpoint: {url}", file=sys.stderr)
    urlretrieve(url, checkpoint_path)
    return checkpoint_path


def select_model_class(model_name: str) -> type[Any]:
    from lighthouse.models import (
        CGDETRPredictor,
        EaTRPredictor,
        MomentDETRPredictor,
        QDDETRPredictor,
        TRDETRPredictor,
        UVCOMPredictor,
    )

    model_classes = {
        "cg_detr": CGDETRPredictor,
        "moment_detr": MomentDETRPredictor,
        "qd_detr": QDDETRPredictor,
        "eatr": EaTRPredictor,
        "tr_detr": TRDETRPredictor,
        "uvcom": UVCOMPredictor,
    }
    if model_name not in model_classes:
        raise ValueError(f"Unsupported Lighthouse model: {model_name}")
    return model_classes[model_name]


def load_request(input_path: Path) -> dict[str, Any]:
    return json.loads(input_path.read_text(encoding="utf-8-sig"))


def choose_device(prefer_gpu: bool) -> str:
    import torch

    if prefer_gpu and torch.cuda.is_available():
        return "cuda"
    return "cpu"


def main() -> None:
    args = parse_args()
    request = load_request(Path(args.input))
    repo_path = Path(request["repoPath"]).resolve()
    if str(repo_path) not in sys.path:
        sys.path.insert(0, str(repo_path))

    model_name = str(request.get("modelName", "cg_detr"))
    feature_name = str(request.get("featureName", "clip"))
    weight_dir = Path(request["weightDir"]).resolve()
    video_path = str(Path(request["videoPath"]).resolve())
    queries = request.get("queries", [])
    device = choose_device(bool(request.get("preferGpu", True)))

    checkpoint_path = ensure_checkpoint(weight_dir, feature_name, model_name)
    model_class = select_model_class(model_name)
    predictor = model_class(
        str(checkpoint_path),
        device=device,
        feature_name=feature_name,
        slowfast_path=None,
        pann_path=None,
    )
    encoded_video = predictor.encode_video(video_path)

    query_results: list[dict[str, Any]] = []
    for query in queries:
        query_name = str(query.get("name", "")).strip() or "query"
        query_text = str(query.get("text", "")).strip()
        prediction = predictor.predict(query_text, encoded_video) or {}
        query_results.append(
            {
                "queryName": query_name,
                "queryText": query_text,
                "predRelevantWindows": prediction.get("pred_relevant_windows", []),
                "predSaliencyScores": prediction.get("pred_saliency_scores", []),
            }
        )

    result = {
        "status": "ok",
        "device": device,
        "featureName": feature_name,
        "modelName": model_name,
        "queryResults": query_results,
    }
    output_path = Path(args.output)
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")


if __name__ == "__main__":
    main()
