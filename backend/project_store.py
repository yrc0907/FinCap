from __future__ import annotations

import sqlite3
import time
from pathlib import Path

from fastapi import HTTPException
from platformdirs import user_data_dir

APP_DATA_DIR = Path(user_data_dir("FinCap", "FinCap"))
VIDEOS_DIR = APP_DATA_DIR / "videos"
DATABASE_PATH = APP_DATA_DIR / "fincap.sqlite3"

APP_DATA_DIR.mkdir(parents=True, exist_ok=True)
VIDEOS_DIR.mkdir(parents=True, exist_ok=True)


def get_db_connection() -> sqlite3.Connection:
    connection = sqlite3.connect(DATABASE_PATH)
    connection.row_factory = sqlite3.Row
    return connection


def fetch_project_or_404(connection: sqlite3.Connection, project_id: str) -> sqlite3.Row:
    row = connection.execute("SELECT * FROM projects WHERE id = ?", (project_id,)).fetchone()
    if row is None:
        raise HTTPException(status_code=404, detail="Project not found.")
    return row


def resolve_project_video_path(row: sqlite3.Row) -> Path:
    stored_file_name = row["stored_file_name"]
    if not stored_file_name:
        raise HTTPException(status_code=400, detail="This project does not have a local video file.")

    video_path = VIDEOS_DIR / stored_file_name
    if not video_path.exists():
        raise HTTPException(status_code=404, detail="Project video file is missing.")
    return video_path


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
        connection.execute(
            """
            CREATE TABLE IF NOT EXISTS workspace_states (
                project_id TEXT PRIMARY KEY,
                semantic_draft_json TEXT,
                clip_overrides_json TEXT,
                frame_overrides_json TEXT,
                runtime_state_json TEXT,
                updated_at INTEGER NOT NULL,
                FOREIGN KEY(project_id) REFERENCES projects(id) ON DELETE CASCADE
            )
            """
        )
        _ensure_column(connection, "workspace_states", "runtime_state_json", "TEXT")
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


def _ensure_column(
    connection: sqlite3.Connection,
    table_name: str,
    column_name: str,
    column_definition: str,
) -> None:
    columns = {
        row["name"]
        for row in connection.execute(f"PRAGMA table_info({table_name})").fetchall()
    }
    if column_name in columns:
        return
    connection.execute(
        f"ALTER TABLE {table_name} ADD COLUMN {column_name} {column_definition}"
    )
