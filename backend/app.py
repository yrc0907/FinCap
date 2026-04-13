from io import BytesIO

import edge_tts
from fastapi import FastAPI, HTTPException, Response
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel, Field

DEFAULT_TEST_TEXT = "This is a test from FinCap."

app = FastAPI(title="FinCap Backend", version="0.1.0")

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)


class TtsRequest(BaseModel):
    text: str = Field(default=DEFAULT_TEST_TEXT, min_length=1, max_length=1000)
    voice: str = Field(min_length=1)


async def synthesize_audio(text: str, voice: str) -> bytes:
    communicator = edge_tts.Communicate(text=text, voice=voice)
    buffer = BytesIO()

    try:
        async for chunk in communicator.stream():
            if chunk["type"] == "audio":
                buffer.write(chunk["data"])
    except Exception as exc:  # pragma: no cover
        raise HTTPException(status_code=502, detail=str(exc)) from exc

    audio = buffer.getvalue()

    if not audio:
        raise HTTPException(status_code=502, detail="No audio returned from TTS service.")

    return audio


@app.get("/health")
async def health() -> dict[str, str]:
    return {"status": "ok"}


@app.get("/api/tts/voices")
async def get_tts_voices() -> dict[str, list[dict[str, str]]]:
    try:
        voices = await edge_tts.list_voices()
    except Exception as exc:  # pragma: no cover
        raise HTTPException(status_code=502, detail=str(exc)) from exc

    normalized = [
        {
            "ShortName": voice.get("ShortName", ""),
            "Locale": voice.get("Locale", ""),
            "DisplayName": voice.get("DisplayName", ""),
            "LocalName": voice.get("LocalName", ""),
            "FriendlyName": voice.get("FriendlyName", ""),
            "Gender": voice.get("Gender", ""),
        }
        for voice in voices
        if voice.get("ShortName")
    ]

    normalized.sort(key=lambda item: (item["Locale"], item["ShortName"]))
    return {"voices": normalized}


@app.post("/api/tts/test")
async def test_tts_connection(payload: TtsRequest) -> dict[str, str]:
    await synthesize_audio(payload.text, payload.voice)
    return {"status": "ok"}


@app.post("/api/tts/synthesize")
async def synthesize_tts(payload: TtsRequest) -> Response:
    audio = await synthesize_audio(payload.text, payload.voice)
    return Response(
        content=audio,
        media_type="audio/mpeg",
        headers={"Cache-Control": "no-store"},
    )
