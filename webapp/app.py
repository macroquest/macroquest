import asyncio
import io
import json
import os
import secrets
import tarfile
from datetime import datetime, timedelta, timezone
from typing import Annotated

import pyotp
import qrcode
import qrcode.image.svg
from fastapi import Depends, FastAPI, Form, HTTPException, Request, Response
from fastapi.responses import HTMLResponse, RedirectResponse, StreamingResponse
from fastapi.staticfiles import StaticFiles
from fastapi.templating import Jinja2Templates
from sqlalchemy.orm import Session
from starlette.middleware.sessions import SessionMiddleware

from . import github_client as gh
from .config import settings
from .db import BuildHistory, User, UserSession, get_db, init_db, seed_admin

app = FastAPI(title="MacroQuest Admin")
app.add_middleware(SessionMiddleware, secret_key=settings.SECRET_KEY, max_age=settings.SESSION_MAX_AGE, https_only=True, same_site="strict")

BASE_DIR = os.path.dirname(__file__)
templates = Jinja2Templates(directory=os.path.join(BASE_DIR, "templates"))
app.mount("/static", StaticFiles(directory=os.path.join(BASE_DIR, "static")), name="static")

ENVS = ["live", "test", "emu"]
WORKFLOW_MAP = {
    "live": "build_custom_live.yaml",
    "test": "build_custom_test.yaml",
    "emu": "build_custom_emu.yaml",
}


@app.on_event("startup")
async def startup():
    init_db()
    seed_admin()


# ---------------------------------------------------------------------------
# Security headers middleware
# ---------------------------------------------------------------------------
@app.middleware("http")
async def security_headers(request: Request, call_next):
    response = await call_next(request)
    response.headers["X-Frame-Options"] = "SAMEORIGIN"
    response.headers["X-Content-Type-Options"] = "nosniff"
    response.headers["Referrer-Policy"] = "strict-origin-when-cross-origin"
    response.headers["Strict-Transport-Security"] = "max-age=31536000; includeSubDomains"
    return response


# ---------------------------------------------------------------------------
# Auth helpers
# ---------------------------------------------------------------------------
def _get_current_user(request: Request, db: Session) -> User | None:
    user_id = request.session.get("user_id")
    totp_verified = request.session.get("totp_verified", False)
    if not user_id or not totp_verified:
        return None
    user = db.query(User).filter(User.id == user_id, User.is_active == True).first()
    return user


def get_current_user(request: Request, db: Session = Depends(get_db)) -> User:
    user = _get_current_user(request, db)
    if not user:
        raise HTTPException(status_code=303, headers={"Location": "/auth/login"})
    return user


def require_super_admin(request: Request, db: Session = Depends(get_db)) -> User:
    user = _get_current_user(request, db)
    if not user:
        raise HTTPException(status_code=303, headers={"Location": "/auth/login"})
    if user.role != "super_admin":
        raise HTTPException(status_code=403, detail="Super admin required")
    return user


def _redirect_login(msg: str = "") -> RedirectResponse:
    r = RedirectResponse("/auth/login", status_code=303)
    return r


def _flash(request: Request, message: str, level: str = "info"):
    request.session.setdefault("flash", []).append({"message": message, "level": level})


def _get_flashes(request: Request) -> list[dict]:
    flashes = request.session.pop("flash", [])
    return flashes


def _render(request: Request, template: str, db: Session, **ctx):
    user = _get_current_user(request, db)
    return templates.TemplateResponse(
        template,
        {"request": request, "current_user": user, "flashes": _get_flashes(request), **ctx},
    )


# ---------------------------------------------------------------------------
# Auth routes
# ---------------------------------------------------------------------------
@app.get("/auth/login", response_class=HTMLResponse)
async def login_page(request: Request, db: Session = Depends(get_db)):
    return _render(request, "login.html", db)


@app.post("/auth/login")
async def login_post(request: Request, db: Session = Depends(get_db),
                     username: str = Form(...), password: str = Form(...)):
    user = db.query(User).filter(User.username == username).first()
    if not user or not user.is_active:
        _flash(request, "Invalid credentials", "error")
        return RedirectResponse("/auth/login", status_code=303)

    if user.is_locked:
        _flash(request, "Account temporarily locked. Try again later.", "error")
        return RedirectResponse("/auth/login", status_code=303)

    if not user.check_password(password):
        user.failed_login_attempts += 1
        if user.failed_login_attempts >= settings.LOGIN_MAX_ATTEMPTS:
            user.locked_until = datetime.now(timezone.utc) + timedelta(minutes=settings.LOGIN_LOCKOUT_MINUTES)
        db.commit()
        _flash(request, "Invalid credentials", "error")
        return RedirectResponse("/auth/login", status_code=303)

    user.failed_login_attempts = 0
    user.locked_until = None
    db.commit()

    request.session["user_id"] = user.id
    request.session["username"] = user.username
    request.session["role"] = user.role
    request.session["totp_verified"] = False

    if not user.totp_enrolled:
        return RedirectResponse("/auth/setup-2fa", status_code=303)
    return RedirectResponse("/auth/totp", status_code=303)


@app.get("/auth/totp", response_class=HTMLResponse)
async def totp_page(request: Request, db: Session = Depends(get_db)):
    if not request.session.get("user_id"):
        return RedirectResponse("/auth/login", status_code=303)
    return _render(request, "totp.html", db)


@app.post("/auth/totp")
async def totp_post(request: Request, db: Session = Depends(get_db), code: str = Form(...)):
    user_id = request.session.get("user_id")
    if not user_id:
        return RedirectResponse("/auth/login", status_code=303)
    user = db.query(User).filter(User.id == user_id).first()
    if not user:
        return RedirectResponse("/auth/login", status_code=303)

    secret = user.get_totp_secret()
    if not secret or not pyotp.TOTP(secret).verify(code.strip(), valid_window=1):
        _flash(request, "Invalid 2FA code", "error")
        return RedirectResponse("/auth/totp", status_code=303)

    request.session["totp_verified"] = True
    user.last_login = datetime.now(timezone.utc)
    db.commit()
    return RedirectResponse("/", status_code=303)


@app.get("/auth/setup-2fa", response_class=HTMLResponse)
async def setup_2fa_page(request: Request, db: Session = Depends(get_db)):
    user_id = request.session.get("user_id")
    if not user_id:
        return RedirectResponse("/auth/login", status_code=303)
    user = db.query(User).filter(User.id == user_id).first()
    if not user:
        return RedirectResponse("/auth/login", status_code=303)

    # Generate or reuse pending secret
    secret = request.session.get("pending_totp_secret") or pyotp.random_base32()
    request.session["pending_totp_secret"] = secret

    totp_uri = pyotp.TOTP(secret).provisioning_uri(name=user.username, issuer_name="MQ Admin")
    img = qrcode.make(totp_uri)
    buf = io.BytesIO()
    img.save(buf, format="PNG")
    qr_b64 = __import__("base64").b64encode(buf.getvalue()).decode()

    return _render(request, "setup_2fa.html", db, qr_b64=qr_b64, totp_secret=secret)


@app.post("/auth/setup-2fa")
async def setup_2fa_post(request: Request, db: Session = Depends(get_db), code: str = Form(...)):
    user_id = request.session.get("user_id")
    secret = request.session.get("pending_totp_secret")
    if not user_id or not secret:
        return RedirectResponse("/auth/login", status_code=303)
    user = db.query(User).filter(User.id == user_id).first()
    if not user:
        return RedirectResponse("/auth/login", status_code=303)

    if not pyotp.TOTP(secret).verify(code.strip(), valid_window=1):
        _flash(request, "Code did not match — try again", "error")
        return RedirectResponse("/auth/setup-2fa", status_code=303)

    user.set_totp_secret(secret)
    user.totp_enrolled = True
    db.commit()
    del request.session["pending_totp_secret"]
    request.session["totp_verified"] = True
    user.last_login = datetime.now(timezone.utc)
    db.commit()
    _flash(request, "2FA enrolled successfully", "success")
    return RedirectResponse("/", status_code=303)


@app.get("/auth/logout")
async def logout(request: Request):
    request.session.clear()
    return RedirectResponse("/auth/login", status_code=303)


# ---------------------------------------------------------------------------
# Dashboard
# ---------------------------------------------------------------------------
@app.get("/", response_class=HTMLResponse)
async def dashboard(request: Request, db: Session = Depends(get_db),
                    current_user: User = Depends(get_current_user)):
    runs_by_env: dict[str, list] = {}
    for env in ENVS:
        try:
            runs_by_env[env] = await gh.get_workflow_runs_for_workflow(WORKFLOW_MAP[env], limit=3)
        except Exception:
            runs_by_env[env] = []

    all_runs = await gh.get_workflow_runs(limit=15)
    return _render(request, "dashboard.html", db, runs_by_env=runs_by_env, all_runs=all_runs, envs=ENVS)


# ---------------------------------------------------------------------------
# Build trigger + log viewer
# ---------------------------------------------------------------------------
@app.post("/builds/trigger")
async def trigger_build(request: Request, db: Session = Depends(get_db),
                        current_user: User = Depends(get_current_user),
                        client_target: str = Form(...)):
    if client_target not in ENVS:
        _flash(request, f"Unknown environment: {client_target}", "error")
        return RedirectResponse("/", status_code=303)
    ok = await gh.trigger_workflow(WORKFLOW_MAP[client_target])
    if ok:
        _flash(request, f"Build triggered for {client_target.upper()}", "success")
    else:
        _flash(request, f"Failed to trigger build for {client_target}", "error")
    return RedirectResponse("/", status_code=303)


@app.get("/builds/{run_id}", response_class=HTMLResponse)
async def build_log_page(run_id: int, request: Request, db: Session = Depends(get_db),
                         current_user: User = Depends(get_current_user)):
    return _render(request, "logs.html", db, run_id=run_id)


@app.get("/builds/{run_id}/stream")
async def build_log_stream(run_id: int, request: Request, db: Session = Depends(get_db),
                           current_user: User = Depends(get_current_user)):
    async def event_gen():
        seen_lines = 0
        for _ in range(120):  # ~6 min timeout
            if await request.is_disconnected():
                break
            try:
                jobs = await gh.get_run_jobs(run_id)
                total_steps = sum(len(j.get("steps", [])) for j in jobs)
                done_steps = sum(
                    1 for j in jobs for s in j.get("steps", [])
                    if s.get("conclusion") in ("success", "failure", "skipped")
                )
                progress = int((done_steps / total_steps * 100) if total_steps else 0)
                status = jobs[0].get("status", "queued") if jobs else "queued"

                log_text = await gh.get_run_log_text(run_id)
                lines = log_text.splitlines()
                new_lines = lines[seen_lines:]
                seen_lines = len(lines)

                for line in new_lines:
                    yield f"event: log\ndata: {json.dumps(line)}\n\n"

                yield f"event: progress\ndata: {progress}\n\n"

                if status in ("completed", "failure"):
                    yield f"event: complete\ndata: {status}\n\n"
                    break
            except Exception as e:
                yield f"event: log\ndata: {json.dumps(f'[stream error] {e}')}\n\n"

            await asyncio.sleep(3)

    return StreamingResponse(event_gen(), media_type="text/event-stream",
                             headers={"Cache-Control": "no-cache", "X-Accel-Buffering": "no"})


# ---------------------------------------------------------------------------
# Plugin manager
# ---------------------------------------------------------------------------
@app.get("/plugins", response_class=HTMLResponse)
async def plugins_page(request: Request, db: Session = Depends(get_db),
                       current_user: User = Depends(require_super_admin)):
    try:
        content, sha = await gh.get_file_contents("custom_plugins.json")
        plugin_data = json.loads(content)
    except Exception:
        plugin_data = {"all": [], "live_test": [], "emu": []}
        sha = ""
    return _render(request, "plugins.html", db, plugin_data=plugin_data, plugins_sha=sha)


@app.post("/plugins/save")
async def plugins_save(request: Request, db: Session = Depends(get_db),
                       current_user: User = Depends(require_super_admin)):
    form = await request.form()
    try:
        new_json = form.get("plugins_json", "{}")
        json.loads(new_json)  # validate
        _, sha = await gh.get_file_contents("custom_plugins.json")
        ok = await gh.update_file_contents(
            "custom_plugins.json", new_json, sha,
            f"chore: update custom_plugins.json via admin panel [{current_user.username}]"
        )
        if ok:
            _flash(request, "Plugin configuration saved and committed", "success")
        else:
            _flash(request, "Failed to save plugin configuration", "error")
    except json.JSONDecodeError:
        _flash(request, "Invalid JSON in plugin configuration", "error")
    except Exception as e:
        _flash(request, f"Error: {e}", "error")
    return RedirectResponse("/plugins", status_code=303)


# ---------------------------------------------------------------------------
# eqlib config
# ---------------------------------------------------------------------------
@app.get("/eqlib", response_class=HTMLResponse)
async def eqlib_page(request: Request, db: Session = Depends(get_db),
                     current_user: User = Depends(require_super_admin)):
    eqlib_repo = await gh.get_variable("CUSTOM_EQLIB_REPO")
    live_branch = await gh.get_variable("EQLIB_BRANCH_LIVE") or "live"
    test_branch = await gh.get_variable("EQLIB_BRANCH_TEST") or "test"
    emu_branch = await gh.get_variable("EQLIB_BRANCH_EMU") or "emu"
    return _render(request, "eqlib.html", db, eqlib_repo=eqlib_repo,
                   live_branch=live_branch, test_branch=test_branch, emu_branch=emu_branch)


@app.post("/eqlib/save")
async def eqlib_save(request: Request, db: Session = Depends(get_db),
                     current_user: User = Depends(require_super_admin)):
    form = await request.form()
    eqlib_repo = form.get("eqlib_repo", "").strip()
    pat = form.get("eqlib_pat", "").strip()
    live_branch = form.get("live_branch", "live").strip()
    test_branch = form.get("test_branch", "test").strip()
    emu_branch = form.get("emu_branch", "emu").strip()

    try:
        await gh.set_variable("CUSTOM_EQLIB_REPO", eqlib_repo)
        await gh.set_variable("EQLIB_BRANCH_LIVE", live_branch)
        await gh.set_variable("EQLIB_BRANCH_TEST", test_branch)
        await gh.set_variable("EQLIB_BRANCH_EMU", emu_branch)
        if pat:
            await gh.set_secret("CUSTOM_EQLIB_PAT", pat)
        _flash(request, "eqlib configuration saved", "success")
    except Exception as e:
        _flash(request, f"Error saving eqlib config: {e}", "error")
    return RedirectResponse("/eqlib", status_code=303)


# ---------------------------------------------------------------------------
# Settings
# ---------------------------------------------------------------------------
@app.get("/settings", response_class=HTMLResponse)
async def settings_page(request: Request, db: Session = Depends(get_db),
                        current_user: User = Depends(require_super_admin)):
    rg_id_live = await gh.get_variable("REDGUIDES_RESOURCE_ID_LIVE")
    rg_id_test = await gh.get_variable("REDGUIDES_RESOURCE_ID_TEST")
    rg_id_emu = await gh.get_variable("REDGUIDES_RESOURCE_ID_EMU")
    return _render(request, "settings.html", db,
                   rg_id_live=rg_id_live, rg_id_test=rg_id_test, rg_id_emu=rg_id_emu)


@app.post("/settings/save")
async def settings_save(request: Request, db: Session = Depends(get_db),
                        current_user: User = Depends(require_super_admin)):
    form = await request.form()
    try:
        await gh.set_variable("REDGUIDES_RESOURCE_ID_LIVE", form.get("rg_id_live", ""))
        await gh.set_variable("REDGUIDES_RESOURCE_ID_TEST", form.get("rg_id_test", ""))
        await gh.set_variable("REDGUIDES_RESOURCE_ID_EMU", form.get("rg_id_emu", ""))
        if api_key := form.get("rg_api_key", "").strip():
            await gh.set_secret("REDGUIDES_API_KEY", api_key)
        if webhook := form.get("discord_webhook", "").strip():
            await gh.set_secret("DISCORD_WEBHOOK_URL", webhook)
        _flash(request, "Settings saved", "success")
    except Exception as e:
        _flash(request, f"Error: {e}", "error")
    return RedirectResponse("/settings", status_code=303)


# ---------------------------------------------------------------------------
# Backup & Restore
# ---------------------------------------------------------------------------
@app.get("/backup", response_class=HTMLResponse)
async def backup_page(request: Request, db: Session = Depends(get_db),
                      current_user: User = Depends(require_super_admin)):
    return _render(request, "backup.html", db)


@app.get("/backup/download")
async def backup_download(request: Request, db: Session = Depends(get_db),
                          current_user: User = Depends(require_super_admin)):
    buf = io.BytesIO()
    with tarfile.open(fileobj=buf, mode="w:gz") as tar:
        if os.path.exists(settings.DB_PATH):
            tar.add(settings.DB_PATH, arcname="mq_admin.db")
        env_path = ".env"
        if os.path.exists(env_path):
            tar.add(env_path, arcname=".env")
    buf.seek(0)
    ts = datetime.now(timezone.utc).strftime("%Y%m%d_%H%M%S")
    return StreamingResponse(buf, media_type="application/gzip",
                             headers={"Content-Disposition": f"attachment; filename=mq_admin_backup_{ts}.tar.gz"})


@app.post("/backup/restore")
async def backup_restore(request: Request, db: Session = Depends(get_db),
                         current_user: User = Depends(require_super_admin)):
    form = await request.form()
    upload = form.get("backup_file")
    if not upload:
        _flash(request, "No file uploaded", "error")
        return RedirectResponse("/backup", status_code=303)
    try:
        content = await upload.read()
        buf = io.BytesIO(content)
        with tarfile.open(fileobj=buf, mode="r:gz") as tar:
            for member in tar.getmembers():
                if member.name == "mq_admin.db":
                    os.makedirs(os.path.dirname(settings.DB_PATH), exist_ok=True)
                    with open(settings.DB_PATH, "wb") as f:
                        f.write(tar.extractfile(member).read())
                elif member.name == ".env":
                    with open(".env", "wb") as f:
                        f.write(tar.extractfile(member).read())
        _flash(request, "Backup restored — please restart the service", "success")
    except Exception as e:
        _flash(request, f"Restore failed: {e}", "error")
    return RedirectResponse("/backup", status_code=303)


# ---------------------------------------------------------------------------
# User management
# ---------------------------------------------------------------------------
@app.get("/users", response_class=HTMLResponse)
async def users_page(request: Request, db: Session = Depends(get_db),
                     current_user: User = Depends(require_super_admin)):
    users = db.query(User).order_by(User.created_at).all()
    return _render(request, "users.html", db, users=users)


@app.post("/users/add")
async def users_add(request: Request, db: Session = Depends(get_db),
                    current_user: User = Depends(require_super_admin),
                    username: str = Form(...), role: str = Form(...)):
    if db.query(User).filter(User.username == username).first():
        _flash(request, f"Username '{username}' already exists", "error")
        return RedirectResponse("/users", status_code=303)
    temp_pw = secrets.token_urlsafe(12)
    user = User(username=username, role=role)
    user.set_password(temp_pw)
    db.add(user)
    db.commit()
    _flash(request, f"User '{username}' created. Temporary password: {temp_pw}", "success")
    return RedirectResponse("/users", status_code=303)


@app.post("/users/{user_id}/role")
async def users_set_role(user_id: int, request: Request, db: Session = Depends(get_db),
                         current_user: User = Depends(require_super_admin),
                         role: str = Form(...)):
    user = db.query(User).filter(User.id == user_id).first()
    if not user:
        raise HTTPException(404)
    user.role = role
    db.commit()
    _flash(request, f"Role updated for {user.username}", "success")
    return RedirectResponse("/users", status_code=303)


@app.post("/users/{user_id}/reset-2fa")
async def users_reset_2fa(user_id: int, request: Request, db: Session = Depends(get_db),
                          current_user: User = Depends(require_super_admin)):
    user = db.query(User).filter(User.id == user_id).first()
    if not user:
        raise HTTPException(404)
    user.totp_secret_enc = None
    user.totp_enrolled = False
    db.commit()
    _flash(request, f"2FA reset for {user.username}", "success")
    return RedirectResponse("/users", status_code=303)


@app.post("/users/{user_id}/deactivate")
async def users_deactivate(user_id: int, request: Request, db: Session = Depends(get_db),
                           current_user: User = Depends(require_super_admin)):
    user = db.query(User).filter(User.id == user_id).first()
    if not user:
        raise HTTPException(404)
    if user.id == current_user.id:
        _flash(request, "Cannot deactivate your own account", "error")
        return RedirectResponse("/users", status_code=303)
    user.is_active = not user.is_active
    db.commit()
    state = "activated" if user.is_active else "deactivated"
    _flash(request, f"User {user.username} {state}", "success")
    return RedirectResponse("/users", status_code=303)


@app.post("/users/{user_id}/delete")
async def users_delete(user_id: int, request: Request, db: Session = Depends(get_db),
                       current_user: User = Depends(require_super_admin)):
    user = db.query(User).filter(User.id == user_id).first()
    if not user:
        raise HTTPException(404)
    if user.id == current_user.id:
        _flash(request, "Cannot delete your own account", "error")
        return RedirectResponse("/users", status_code=303)
    db.delete(user)
    db.commit()
    _flash(request, f"User {user.username} deleted", "success")
    return RedirectResponse("/users", status_code=303)


# ---------------------------------------------------------------------------
# My Account
# ---------------------------------------------------------------------------
@app.get("/account", response_class=HTMLResponse)
async def account_page(request: Request, db: Session = Depends(get_db),
                       current_user: User = Depends(get_current_user)):
    return _render(request, "account.html", db)


@app.post("/account/password")
async def account_change_password(request: Request, db: Session = Depends(get_db),
                                  current_user: User = Depends(get_current_user),
                                  current_password: str = Form(...),
                                  new_password: str = Form(...),
                                  confirm_password: str = Form(...)):
    if not current_user.check_password(current_password):
        _flash(request, "Current password is incorrect", "error")
        return RedirectResponse("/account", status_code=303)
    if new_password != confirm_password:
        _flash(request, "New passwords do not match", "error")
        return RedirectResponse("/account", status_code=303)
    if len(new_password) < 12:
        _flash(request, "Password must be at least 12 characters", "error")
        return RedirectResponse("/account", status_code=303)
    current_user.set_password(new_password)
    db.commit()
    request.session.clear()
    _flash(request, "Password changed — please log in again", "success")
    return RedirectResponse("/auth/login", status_code=303)


@app.post("/account/reset-2fa")
async def account_reset_2fa(request: Request, db: Session = Depends(get_db),
                            current_user: User = Depends(get_current_user),
                            current_password: str = Form(...)):
    if not current_user.check_password(current_password):
        _flash(request, "Incorrect password", "error")
        return RedirectResponse("/account", status_code=303)
    current_user.totp_secret_enc = None
    current_user.totp_enrolled = False
    db.commit()
    request.session["totp_verified"] = False
    return RedirectResponse("/auth/setup-2fa", status_code=303)
