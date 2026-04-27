import os
from dotenv import load_dotenv

load_dotenv()


class Settings:
    SECRET_KEY: str = os.environ["SECRET_KEY"]
    GITHUB_PAT: str = os.environ["GITHUB_PAT"]
    GITHUB_OWNER: str = os.getenv("GITHUB_OWNER", "teichoui")
    GITHUB_REPO: str = os.getenv("GITHUB_REPO", "macroquest")
    DB_PATH: str = os.getenv("DB_PATH", "webapp/data/mq_admin.db")
    ENCRYPTION_KEY: str = os.environ["ENCRYPTION_KEY"]
    ADMIN_USERNAME: str = os.getenv("ADMIN_USERNAME", "admin")
    ADMIN_PASSWORD: str = os.getenv("ADMIN_PASSWORD", "")
    SESSION_MAX_AGE: int = int(os.getenv("SESSION_MAX_AGE", "28800"))  # 8 hours
    LOGIN_MAX_ATTEMPTS: int = int(os.getenv("LOGIN_MAX_ATTEMPTS", "5"))
    LOGIN_LOCKOUT_MINUTES: int = int(os.getenv("LOGIN_LOCKOUT_MINUTES", "15"))


settings = Settings()
