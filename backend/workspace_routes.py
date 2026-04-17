from __future__ import annotations

from pathlib import Path

from fastapi import APIRouter, HTTPException

from api_models import (
    ClipRangeOverrideRequest,
    FrameOverrideRequest,
    FunctionalClipExportRequest,
    VlmDraftPayloadRequest,
)
from project_store import APP_DATA_DIR, fetch_project_or_404, get_db_connection, resolve_project_video_path
from workspace_export_service import export_project_functional_clips
from workspace_state_store import (
    VALID_CLIP_OVERRIDE_SCOPES,
    get_clip_overrides,
    get_frame_overrides,
    get_runtime_state,
    get_semantic_draft,
    save_clip_overrides,
    save_frame_overrides,
    save_runtime_state,
    save_semantic_draft,
)

router = APIRouter(prefix="/api/projects/{project_id}/workspace")


def _load_project_video_path(project_id: str) -> Path:
    connection = get_db_connection()
    try:
        row = fetch_project_or_404(connection, project_id)
        return resolve_project_video_path(row)
    finally:
        connection.close()


@router.get("/semantic-draft")
async def read_semantic_draft(project_id: str) -> dict[str, object]:
    connection = get_db_connection()
    try:
        return {
            "vlmPayload": get_semantic_draft(connection, project_id),
        }
    finally:
        connection.close()


@router.put("/semantic-draft")
async def write_semantic_draft(
    project_id: str,
    payload: VlmDraftPayloadRequest,
) -> dict[str, object]:
    connection = get_db_connection()
    try:
        updated_at = save_semantic_draft(connection, project_id, payload.model_dump())
        return {
            "updatedAt": updated_at,
            "vlmPayload": payload.model_dump(),
        }
    finally:
        connection.close()


@router.get("/clip-overrides/{scope}")
async def read_clip_overrides(project_id: str, scope: str) -> dict[str, object]:
    if scope not in VALID_CLIP_OVERRIDE_SCOPES:
        raise HTTPException(status_code=400, detail="Unsupported clip override scope.")
    connection = get_db_connection()
    try:
        return {
            "scope": scope,
            "items": get_clip_overrides(connection, project_id, scope),
        }
    finally:
        connection.close()


@router.put("/clip-overrides/{scope}")
async def write_clip_overrides(
    project_id: str,
    scope: str,
    payload: list[ClipRangeOverrideRequest],
) -> dict[str, object]:
    if scope not in VALID_CLIP_OVERRIDE_SCOPES:
        raise HTTPException(status_code=400, detail="Unsupported clip override scope.")
    connection = get_db_connection()
    try:
        updated_at = save_clip_overrides(
            connection,
            project_id,
            scope,
            [item.model_dump() for item in payload],
        )
        return {
            "scope": scope,
            "updatedAt": updated_at,
            "items": [item.model_dump() for item in payload],
        }
    finally:
        connection.close()


@router.get("/frame-overrides")
async def read_frame_overrides(project_id: str) -> dict[str, object]:
    connection = get_db_connection()
    try:
        return {
            "items": get_frame_overrides(connection, project_id),
        }
    finally:
        connection.close()


@router.put("/frame-overrides")
async def write_frame_overrides(
    project_id: str,
    payload: list[FrameOverrideRequest],
) -> dict[str, object]:
    connection = get_db_connection()
    try:
        updated_at = save_frame_overrides(
            connection,
            project_id,
            [item.model_dump() for item in payload],
        )
        return {
            "updatedAt": updated_at,
            "items": [item.model_dump() for item in payload],
        }
    finally:
        connection.close()


@router.get("/runtime-state")
async def read_runtime_state(project_id: str) -> dict[str, object]:
    connection = get_db_connection()
    try:
        return {
            "runtimeState": get_runtime_state(connection, project_id),
        }
    finally:
        connection.close()


@router.put("/runtime-state")
async def write_runtime_state(
    project_id: str,
    payload: dict[str, object],
) -> dict[str, object]:
    connection = get_db_connection()
    try:
        updated_at = save_runtime_state(connection, project_id, payload)
        return {
            "updatedAt": updated_at,
            "runtimeState": payload,
        }
    finally:
        connection.close()


@router.post("/export-functional-clips")
async def run_export_functional_clips(
    project_id: str,
    payload: FunctionalClipExportRequest,
) -> dict[str, object]:
    try:
        video_path = _load_project_video_path(project_id)
        return export_project_functional_clips(
            project_id=project_id,
            video_path=video_path,
            clips=[clip.model_dump() for clip in payload.clips],
            output_root=APP_DATA_DIR / "exports",
        )
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] Functional clip export failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc
