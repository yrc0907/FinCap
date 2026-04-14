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
from platformdirs import user_data_dir
from pydantic import BaseModel, Field

DEFAULT_TEST_TEXT = "This is a test from FinCap."
APP_DATA_DIR = Path(user_data_dir("FinCap", "FinCap"))
VIDEOS_DIR = APP_DATA_DIR / "videos"
DATABASE_PATH = APP_DATA_DIR / "fincap.sqlite3"

APP_DATA_DIR.mkdir(parents=True, exist_ok=True)
VIDEOS_DIR.mkdir(parents=True, exist_ok=True)

app = FastAPI(title="FinCap Backend", version="0.1.0")
app.mount("/media", StaticFiles(directory=str(VIDEOS_DIR)), name="media")

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


class RenameProjectRequest(BaseModel):
    name: str = Field(min_length=1, max_length=200)


def get_db_connection() -> sqlite3.Connection:
    connection = sqlite3.connect(DATABASE_PATH)
    connection.row_factory = sqlite3.Row
    return connection


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


def fetch_project_or_404(connection: sqlite3.Connection, project_id: str) -> sqlite3.Row:
    row = connection.execute("SELECT * FROM projects WHERE id = ?", (project_id,)).fetchone()

    if row is None:
        raise HTTPException(status_code=404, detail="Project not found.")

    return row


def init_database() -> None:
    connection = get_db_connection()

    try:
        connection.execute(
            """
            CREATE TABLE IF NOT EXISTS projects (
                id TEXT PRIMARY KEY,
                name TEXT NOT NULL,
                meta TEXT NOT NULL,
                created_at INTEGER NOT NULL,
                updated_at INTEGER NOT NULL,
                deleted_at INTEGER,
                thumb TEXT,
                is_video INTEGER NOT NULL DEFAULT 0,
                stored_file_name TEXT
            )
            """
        )

        count = connection.execute("SELECT COUNT(*) FROM projects").fetchone()[0]

        if count == 0:
            now = int(time.time() * 1000)
            seed_projects = [
                (
                    "project-1",
                    "Cinematic_Sequence_01",
                    "4K | 24fps | 12.4GB",
                    now - 2 * 60 * 1000,
                    now - 2 * 60 * 1000,
                    None,
                    "https://images.unsplash.com/photo-1492691527719-9d1e07e534b4?w=400&q=80",
                    0,
                    None,
                ),
                (
                    "project-2",
                    "FinCap_Social_Promo",
                    "1080p | 60fps | 2.1GB",
                    now - 60 * 60 * 1000,
                    now - 60 * 60 * 1000,
                    None,
                    "https://images.unsplash.com/photo-1536240478700-b869070f9279?w=400&q=80",
                    0,
                    None,
                ),
                (
                    "project-3",
                    "Draft_B_Roll_Nature",
                    "4K | 30fps | 45.8GB",
                    now - 24 * 60 * 60 * 1000,
                    now - 24 * 60 * 60 * 1000,
                    None,
                    "https://images.unsplash.com/photo-1441974231531-c6227db76b6e?w=400&q=80",
                    0,
                    None,
                ),
            ]
            connection.executemany(
                """
                INSERT INTO projects (
                    id, name, meta, created_at, updated_at, deleted_at, thumb, is_video, stored_file_name
                ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
                """,
                seed_projects,
            )

        connection.commit()
    finally:
        connection.close()


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
