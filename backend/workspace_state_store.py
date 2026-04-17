from __future__ import annotations

import json
import sqlite3
import time
from typing import Any

from project_store import fetch_project_or_404

VALID_CLIP_OVERRIDE_SCOPES = {"shots", "functional-clips"}


def init_workspace_state_schema(connection: sqlite3.Connection) -> None:
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
    connection.commit()


def get_semantic_draft(connection: sqlite3.Connection, project_id: str) -> dict[str, Any] | None:
    row = _get_state_row(connection, project_id)
    return _decode_json_object(row["semantic_draft_json"]) if row else None


def save_semantic_draft(
    connection: sqlite3.Connection,
    project_id: str,
    semantic_draft: dict[str, Any],
) -> int:
    _ensure_state_row(connection, project_id)
    updated_at = _now_ms()
    connection.execute(
        "UPDATE workspace_states SET semantic_draft_json = ?, updated_at = ? WHERE project_id = ?",
        (json.dumps(semantic_draft, ensure_ascii=False), updated_at, project_id),
    )
    connection.commit()
    return updated_at


def get_clip_overrides(
    connection: sqlite3.Connection,
    project_id: str,
    scope: str,
) -> list[dict[str, Any]]:
    _validate_scope(scope)
    row = _get_state_row(connection, project_id)
    if row is None:
        return []
    payload = _decode_json_object(row["clip_overrides_json"]) or {}
    items = payload.get(scope, [])
    return items if isinstance(items, list) else []


def save_clip_overrides(
    connection: sqlite3.Connection,
    project_id: str,
    scope: str,
    items: list[dict[str, Any]],
) -> int:
    _validate_scope(scope)
    _ensure_state_row(connection, project_id)
    row = _get_state_row(connection, project_id)
    payload = _decode_json_object(None if row is None else row["clip_overrides_json"]) or {}
    payload[scope] = items
    updated_at = _now_ms()
    connection.execute(
        "UPDATE workspace_states SET clip_overrides_json = ?, updated_at = ? WHERE project_id = ?",
        (json.dumps(payload, ensure_ascii=False), updated_at, project_id),
    )
    connection.commit()
    return updated_at


def get_frame_overrides(connection: sqlite3.Connection, project_id: str) -> list[dict[str, Any]]:
    row = _get_state_row(connection, project_id)
    if row is None:
        return []
    payload = _decode_json_value(row["frame_overrides_json"])
    return payload if isinstance(payload, list) else []


def save_frame_overrides(
    connection: sqlite3.Connection,
    project_id: str,
    items: list[dict[str, Any]],
) -> int:
    _ensure_state_row(connection, project_id)
    updated_at = _now_ms()
    connection.execute(
        "UPDATE workspace_states SET frame_overrides_json = ?, updated_at = ? WHERE project_id = ?",
        (json.dumps(items, ensure_ascii=False), updated_at, project_id),
    )
    connection.commit()
    return updated_at


def get_runtime_state(connection: sqlite3.Connection, project_id: str) -> dict[str, Any] | None:
    row = _get_state_row(connection, project_id)
    return _decode_json_object(row["runtime_state_json"]) if row else None


def save_runtime_state(
    connection: sqlite3.Connection,
    project_id: str,
    runtime_state: dict[str, Any],
) -> int:
    _ensure_state_row(connection, project_id)
    updated_at = _now_ms()
    connection.execute(
        "UPDATE workspace_states SET runtime_state_json = ?, updated_at = ? WHERE project_id = ?",
        (json.dumps(runtime_state, ensure_ascii=False), updated_at, project_id),
    )
    connection.commit()
    return updated_at


def _ensure_state_row(connection: sqlite3.Connection, project_id: str) -> None:
    fetch_project_or_404(connection, project_id)
    exists = connection.execute(
        "SELECT 1 FROM workspace_states WHERE project_id = ?",
        (project_id,),
    ).fetchone()
    if exists is not None:
        return
    connection.execute(
        """
        INSERT INTO workspace_states (
            project_id,
            semantic_draft_json,
            clip_overrides_json,
            frame_overrides_json,
            runtime_state_json,
            updated_at
        ) VALUES (?, NULL, NULL, NULL, NULL, ?)
        """,
        (project_id, _now_ms()),
    )
    connection.commit()


def _get_state_row(connection: sqlite3.Connection, project_id: str) -> sqlite3.Row | None:
    fetch_project_or_404(connection, project_id)
    return connection.execute(
        "SELECT * FROM workspace_states WHERE project_id = ?",
        (project_id,),
    ).fetchone()


def _decode_json_object(raw_value: str | None) -> dict[str, Any] | None:
    payload = _decode_json_value(raw_value)
    return payload if isinstance(payload, dict) else None


def _decode_json_value(raw_value: str | None) -> Any:
    if not raw_value:
        return None
    try:
        return json.loads(raw_value)
    except json.JSONDecodeError:
        return None


def _validate_scope(scope: str) -> None:
    if scope not in VALID_CLIP_OVERRIDE_SCOPES:
        raise ValueError(f"Unsupported clip override scope: {scope}")


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


def _now_ms() -> int:
    return int(time.time() * 1000)
