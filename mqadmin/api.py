"""API client for the MQ Admin web panel."""
import keyring
import httpx

SERVICE = "mq-admin"
KEY_TOKEN = "session_token"
KEY_URL   = "base_url"


def get_base_url() -> str:
    return keyring.get_password(SERVICE, KEY_URL) or ""


def set_base_url(url: str):
    keyring.set_password(SERVICE, KEY_URL, url.rstrip("/"))


def get_token() -> str:
    return keyring.get_password(SERVICE, KEY_TOKEN) or ""


def set_token(token: str):
    keyring.set_password(SERVICE, KEY_TOKEN, token)


def clear_token():
    try:
        keyring.delete_password(SERVICE, KEY_TOKEN)
    except Exception:
        pass


def _headers() -> dict:
    token = get_token()
    return {"Cookie": f"session={token}"} if token else {}


def _client() -> httpx.Client:
    return httpx.Client(base_url=get_base_url(), headers=_headers(), timeout=30, verify=True)


def login(username: str, password: str) -> dict:
    with _client() as c:
        r = c.post("/auth/login", data={"username": username, "password": password},
                   follow_redirects=False)
        cookie = r.headers.get("set-cookie", "")
        if "session=" in cookie:
            token = cookie.split("session=")[1].split(";")[0]
            set_token(token)
            return {"ok": True, "location": r.headers.get("location", "")}
        return {"ok": False, "status": r.status_code}


def verify_totp(code: str) -> bool:
    with _client() as c:
        r = c.post("/auth/totp", data={"code": code}, follow_redirects=False)
        if r.status_code in (302, 303) and r.headers.get("location", "").rstrip("/") in ("/", ""):
            return True
        return False


def get_runs() -> list[dict]:
    with _client() as c:
        r = c.get("/api/runs")  # extend app.py if needed
        if r.status_code == 200:
            return r.json()
        return []


def trigger_build(env: str) -> bool:
    with _client() as c:
        r = c.post("/builds/trigger", data={"client_target": env}, follow_redirects=False)
        return r.status_code in (302, 303, 200)
