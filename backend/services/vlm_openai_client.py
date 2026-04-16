from __future__ import annotations

import json
import re
from typing import Any
from urllib import request
from urllib.error import HTTPError, URLError


def call_openai_compatible_vision(
    vlm_config: dict[str, str],
    prompt: str,
    images: list[dict[str, Any]],
) -> dict[str, Any]:
    payload = {
        "model": vlm_config["model"].strip(),
        "messages": [
            {
                "role": "user",
                "content": [
                    {"type": "text", "text": prompt},
                    *[
                        {
                            "type": "image_url",
                            "image_url": {
                                "url": f"data:image/jpeg;base64,{image['jpegBase64']}",
                            },
                        }
                        for image in images
                    ],
                ],
            }
        ],
        "temperature": 0,
        "max_tokens": 400,
        "stream": False,
    }
    data = json.dumps(payload).encode("utf-8")
    http_request = request.Request(
        url=vlm_config["endpoint"].strip(),
        data=data,
        method="POST",
        headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {vlm_config['key'].strip()}",
        },
    )

    try:
        with request.urlopen(http_request, timeout=90) as response:
            raw = response.read().decode("utf-8")
    except HTTPError as exc:  # pragma: no cover
        detail = exc.read().decode("utf-8", errors="ignore")
        raise RuntimeError(detail or str(exc)) from exc
    except URLError as exc:  # pragma: no cover
        raise RuntimeError(str(exc)) from exc

    parsed = json.loads(raw)
    text = _extract_message_text(parsed)
    content = _extract_json_object(text)
    if not isinstance(content, dict):
        raise RuntimeError("Vision response did not contain a JSON object.")
    return content


def call_openai_compatible_json(
    llm_config: dict[str, str],
    prompt: str,
    max_tokens: int = 400,
) -> dict[str, Any]:
    payload = {
        "model": llm_config["model"].strip(),
        "messages": [
            {
                "role": "user",
                "content": prompt,
            }
        ],
        "temperature": 0,
        "max_tokens": max_tokens,
        "stream": False,
    }
    data = json.dumps(payload).encode("utf-8")
    http_request = request.Request(
        url=llm_config["endpoint"].strip(),
        data=data,
        method="POST",
        headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {llm_config['key'].strip()}",
        },
    )

    try:
        with request.urlopen(http_request, timeout=90) as response:
            raw = response.read().decode("utf-8")
    except HTTPError as exc:  # pragma: no cover
        detail = exc.read().decode("utf-8", errors="ignore")
        raise RuntimeError(detail or str(exc)) from exc
    except URLError as exc:  # pragma: no cover
        raise RuntimeError(str(exc)) from exc

    parsed = json.loads(raw)
    text = _extract_message_text(parsed)
    content = _extract_json_object(text)
    if not isinstance(content, dict):
        raise RuntimeError("LLM response did not contain a JSON object.")
    return content


def _extract_message_text(payload: dict[str, Any]) -> str:
    choices = payload.get("choices") or []
    if not choices:
        raise RuntimeError("Vision response is missing choices.")

    message = choices[0].get("message") or {}
    content = message.get("content", "")
    if isinstance(content, str):
        return content
    if isinstance(content, list):
        chunks = []
        for item in content:
            if item.get("type") == "text":
                chunks.append(str(item.get("text", "")))
        return "\n".join(chunks)
    return str(content)


def _extract_json_object(text: str) -> Any:
    stripped = text.strip()
    if stripped.startswith("{") and stripped.endswith("}"):
        return json.loads(stripped)

    match = re.search(r"\{.*\}", stripped, re.DOTALL)
    if not match:
        raise RuntimeError("Vision response did not include JSON.")

    return json.loads(match.group(0))
