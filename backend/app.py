import shutil
import sqlite3
import time
from io import BytesIO
from pathlib import Path
from uuid import uuid4

import edge_tts
from fastapi import FastAPI, File, HTTPException, Request, Response, UploadFile
from fastapi.middleware.cors import CORSMiddleware
from fastapi.staticfiles import StaticFiles
from api_models import (
    RenameProjectRequest,
    TtsRequest,
)
from project_store import VIDEOS_DIR, fetch_project_or_404, get_db_connection, init_database
from services.gpu_runtime import get_gpu_runtime_summary
from timeline_routes import router as timeline_router
from workspace_routes import router as workspace_router

DEFAULT_TEST_TEXT = "This is a test from FinCap."

app = FastAPI(title="FinCap Backend", version="0.1.0")
app.mount("/media", StaticFiles(directory=str(VIDEOS_DIR)), name="media")
app.include_router(timeline_router)
app.include_router(workspace_router)

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

def format_file_size(size: int) -> str:
    if size < 1024 * 1024 * 1024:
        return f"{size / (1024 * 1024):.1f}MB"

    return f"{size / (1024 * 1024 * 1024):.1f}GB"


def build_project_name(file_name: str) -> str:
    stem = Path(file_name).stem.strip()
    return stem.replace(" ", "_") or "New_Project"


def build_media_url(request: Request, stored_file_name: str) -> str:
    return str(request.base_url).rstrip("/") + f"/media/{stored_file_name}"


def serialize_project(row: sqlite3.Row, request: Request) -> dict[str, object]:
    thumb = row["thumb"]

    if row["stored_file_name"]:
        thumb = build_media_url(request, row["stored_file_name"])

    return {
        "id": row["id"],
        "name": row["name"],
        "meta": row["meta"],
        "createdAt": row["created_at"],
        "updatedAt": row["updated_at"],
        "deletedAt": row["deleted_at"],
        "thumb": thumb,
        "isVideo": bool(row["is_video"]),
    }

@app.on_event("startup")
def on_startup() -> None:
    init_database()


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


@app.get("/api/runtime/gpu")
async def get_gpu_runtime() -> dict[str, object]:
    return get_gpu_runtime_summary()


@app.get("/api/projects")
async def get_projects(request: Request) -> dict[str, list[dict[str, object]]]:
    connection = get_db_connection()

    try:
        rows = connection.execute("SELECT * FROM projects ORDER BY created_at DESC").fetchall()
        return {"projects": [serialize_project(row, request) for row in rows]}
    finally:
        connection.close()


@app.post("/api/projects/upload")
async def upload_project(request: Request, file: UploadFile = File(...)) -> dict[str, object]:
    file_name = file.filename or "video.mp4"

    if not (file.content_type or "").startswith("video/"):
        raise HTTPException(status_code=400, detail="Only video uploads are supported.")

    project_id = str(int(time.time() * 1000))
    stored_file_name = f"{uuid4().hex}{Path(file_name).suffix or '.mp4'}"
    destination = VIDEOS_DIR / stored_file_name

    try:
        with destination.open("wb") as buffer:
            shutil.copyfileobj(file.file, buffer)
    finally:
        await file.close()

    file_size = destination.stat().st_size
    now = int(time.time() * 1000)
    project = (
        project_id,
        build_project_name(file_name),
        f"Video | {format_file_size(file_size)}",
        now,
        now,
        None,
        None,
        1,
        stored_file_name,
    )

    connection = get_db_connection()

    try:
        connection.execute(
            """
            INSERT INTO projects (
                id, name, meta, created_at, updated_at, deleted_at, thumb, is_video, stored_file_name
            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
            """,
            project,
        )
        connection.commit()
        row = fetch_project_or_404(connection, project_id)
        return serialize_project(row, request)
    finally:
        connection.close()


@app.patch("/api/projects/{project_id}/rename")
async def rename_project(
    project_id: str, payload: RenameProjectRequest, request: Request
) -> dict[str, object]:
    connection = get_db_connection()

    try:
        fetch_project_or_404(connection, project_id)
        connection.execute(
            "UPDATE projects SET name = ?, updated_at = ? WHERE id = ?",
            (payload.name.strip(), int(time.time() * 1000), project_id),
        )
        connection.commit()
        row = fetch_project_or_404(connection, project_id)
        return serialize_project(row, request)
    finally:
        connection.close()


@app.post("/api/projects/{project_id}/trash")
async def move_project_to_trash(project_id: str, request: Request) -> dict[str, object]:
    connection = get_db_connection()

    try:
        fetch_project_or_404(connection, project_id)
        deleted_at = int(time.time() * 1000)
        connection.execute(
            "UPDATE projects SET deleted_at = ? WHERE id = ?",
            (deleted_at, project_id),
        )
        connection.commit()
        row = fetch_project_or_404(connection, project_id)
        return serialize_project(row, request)
    finally:
        connection.close()


@app.post("/api/projects/{project_id}/restore")
async def restore_project(project_id: str, request: Request) -> dict[str, object]:
    connection = get_db_connection()

    try:
        fetch_project_or_404(connection, project_id)
        connection.execute(
            "UPDATE projects SET deleted_at = NULL, updated_at = ? WHERE id = ?",
            (int(time.time() * 1000), project_id),
        )
        connection.commit()
        row = fetch_project_or_404(connection, project_id)
        return serialize_project(row, request)
    finally:
        connection.close()


@app.delete("/api/projects/{project_id}")
async def delete_project_forever(project_id: str) -> dict[str, str]:
    connection = get_db_connection()

    try:
        row = fetch_project_or_404(connection, project_id)

        if row["stored_file_name"]:
            file_path = VIDEOS_DIR / row["stored_file_name"]
            if file_path.exists():
                file_path.unlink()

        connection.execute("DELETE FROM projects WHERE id = ?", (project_id,))
        connection.commit()
        return {"status": "ok"}
    finally:
        connection.close()


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
