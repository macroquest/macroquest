import base64
import json
import zipfile
from io import BytesIO

import httpx
from nacl import encoding, public

from .config import settings

_BASE = "https://api.github.com"
_REPO = f"{_BASE}/repos/{settings.GITHUB_OWNER}/{settings.GITHUB_REPO}"
_HEADERS = {
    "Authorization": f"Bearer {settings.GITHUB_PAT}",
    "Accept": "application/vnd.github+json",
    "X-GitHub-Api-Version": "2022-11-28",
}


def _client() -> httpx.AsyncClient:
    return httpx.AsyncClient(headers=_HEADERS, timeout=30)


async def get_run(run_id: int) -> dict:
    async with _client() as c:
        r = await c.get(f"{_REPO}/actions/runs/{run_id}")
        r.raise_for_status()
        return r.json()


async def get_workflow_runs(limit: int = 20) -> list[dict]:
    async with _client() as c:
        r = await c.get(f"{_REPO}/actions/runs", params={"per_page": limit})
        r.raise_for_status()
        return r.json().get("workflow_runs", [])


async def get_workflow_runs_for_workflow(workflow_file: str, limit: int = 5) -> list[dict]:
    async with _client() as c:
        r = await c.get(
            f"{_REPO}/actions/workflows/{workflow_file}/runs",
            params={"per_page": limit},
        )
        r.raise_for_status()
        return r.json().get("workflow_runs", [])


async def trigger_workflow(workflow_file: str, ref: str = "custom-release", inputs: dict | None = None) -> bool:
    payload: dict = {"ref": ref}
    if inputs:
        payload["inputs"] = inputs
    async with _client() as c:
        r = await c.post(
            f"{_REPO}/actions/workflows/{workflow_file}/dispatches",
            json=payload,
        )
        return r.status_code == 204


async def get_run_jobs(run_id: int) -> list[dict]:
    async with _client() as c:
        r = await c.get(f"{_REPO}/actions/runs/{run_id}/jobs")
        r.raise_for_status()
        return r.json().get("jobs", [])


async def get_run_log_text(run_id: int) -> str:
    """Download and return the plain-text log for a run."""
    async with _client() as c:
        r = await c.get(f"{_REPO}/actions/runs/{run_id}/logs", follow_redirects=True)
        if r.status_code != 200:
            return ""
    # Log is a zip archive; extract all .txt entries
    try:
        buf = BytesIO(r.content)
        lines: list[str] = []
        with zipfile.ZipFile(buf) as zf:
            for name in sorted(zf.namelist()):
                if name.endswith(".txt"):
                    lines.append(zf.read(name).decode("utf-8", errors="replace"))
        return "\n".join(lines)
    except Exception:
        return r.text


async def get_file_contents(path: str) -> tuple[str, str]:
    """Return (decoded_content, sha)."""
    async with _client() as c:
        r = await c.get(f"{_REPO}/contents/{path}")
        r.raise_for_status()
        data = r.json()
        content = base64.b64decode(data["content"]).decode("utf-8")
        return content, data["sha"]


async def update_file_contents(path: str, content: str, sha: str, message: str) -> bool:
    encoded = base64.b64encode(content.encode("utf-8")).decode("utf-8")
    async with _client() as c:
        r = await c.put(
            f"{_REPO}/contents/{path}",
            json={"message": message, "content": encoded, "sha": sha},
        )
        return r.status_code in (200, 201)


async def get_variable(name: str) -> str:
    async with _client() as c:
        r = await c.get(f"{_REPO}/actions/variables/{name}")
        if r.status_code == 404:
            return ""
        r.raise_for_status()
        return r.json().get("value", "")


async def set_variable(name: str, value: str) -> bool:
    async with _client() as c:
        # Try PATCH first (update), fall back to POST (create)
        r = await c.patch(f"{_REPO}/actions/variables/{name}", json={"name": name, "value": value})
        if r.status_code == 404:
            r = await c.post(f"{_REPO}/actions/variables", json={"name": name, "value": value})
        return r.status_code in (200, 201, 204)


async def _get_repo_public_key() -> tuple[str, str]:
    """Return (key_id, base64_key)."""
    async with _client() as c:
        r = await c.get(f"{_REPO}/actions/secrets/public-key")
        r.raise_for_status()
        data = r.json()
        return data["key_id"], data["key"]


def _encrypt_secret(public_key_b64: str, secret_value: str) -> str:
    """Encrypt secret_value with the repo's libsodium public key."""
    pk_bytes = base64.b64decode(public_key_b64)
    pk = public.PublicKey(pk_bytes)
    sealed = public.SealedBox(pk).encrypt(secret_value.encode("utf-8"))
    return base64.b64encode(sealed).decode("utf-8")


async def set_secret(name: str, value: str) -> bool:
    key_id, pub_key = await _get_repo_public_key()
    encrypted = _encrypt_secret(pub_key, value)
    async with _client() as c:
        r = await c.put(
            f"{_REPO}/actions/secrets/{name}",
            json={"encrypted_value": encrypted, "key_id": key_id},
        )
        return r.status_code in (201, 204)
