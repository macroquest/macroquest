import os
import secrets
from datetime import datetime, timezone
from cryptography.fernet import Fernet
from passlib.context import CryptContext
from sqlalchemy import (
    Boolean, Column, DateTime, ForeignKey, Integer, String, create_engine
)
from sqlalchemy.orm import DeclarativeBase, Session, sessionmaker

from .config import settings

engine = create_engine(
    f"sqlite:///{settings.DB_PATH}",
    connect_args={"check_same_thread": False},
)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)
pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")
_fernet = Fernet(settings.ENCRYPTION_KEY.encode())


def encrypt(value: str) -> str:
    return _fernet.encrypt(value.encode()).decode()


def decrypt(value: str) -> str:
    return _fernet.decrypt(value.encode()).decode()


class Base(DeclarativeBase):
    pass


class User(Base):
    __tablename__ = "users"

    id = Column(Integer, primary_key=True, index=True)
    username = Column(String, unique=True, nullable=False)
    password_hash = Column(String, nullable=False)
    role = Column(String, nullable=False, default="builder")  # super_admin | builder
    totp_secret_enc = Column(String, nullable=True)            # Fernet-encrypted
    totp_enrolled = Column(Boolean, default=False, nullable=False)
    is_active = Column(Boolean, default=True, nullable=False)
    created_at = Column(DateTime, default=lambda: datetime.now(timezone.utc))
    last_login = Column(DateTime, nullable=True)
    failed_login_attempts = Column(Integer, default=0, nullable=False)
    locked_until = Column(DateTime, nullable=True)

    def set_password(self, password: str):
        self.password_hash = pwd_context.hash(password)

    def check_password(self, password: str) -> bool:
        return pwd_context.verify(password, self.password_hash)

    def set_totp_secret(self, secret: str):
        self.totp_secret_enc = encrypt(secret)

    def get_totp_secret(self) -> str | None:
        if not self.totp_secret_enc:
            return None
        return decrypt(self.totp_secret_enc)

    @property
    def is_locked(self) -> bool:
        if self.locked_until and self.locked_until > datetime.now(timezone.utc):
            return True
        return False


class BuildHistory(Base):
    __tablename__ = "build_history"

    id = Column(Integer, primary_key=True, index=True)
    run_id = Column(String, nullable=False)
    client_target = Column(String, nullable=False)
    started_at = Column(DateTime, nullable=False)
    completed_at = Column(DateTime, nullable=True)
    status = Column(String, nullable=False, default="queued")

    @property
    def duration_seconds(self) -> float | None:
        if self.completed_at and self.started_at:
            return (self.completed_at - self.started_at).total_seconds()
        return None


class UserSession(Base):
    __tablename__ = "user_sessions"

    id = Column(String, primary_key=True)
    user_id = Column(Integer, ForeignKey("users.id"), nullable=False)
    created_at = Column(DateTime, default=lambda: datetime.now(timezone.utc))
    expires_at = Column(DateTime, nullable=False)
    ip_address = Column(String, nullable=True)
    totp_verified = Column(Boolean, default=False, nullable=False)


def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()


def init_db():
    os.makedirs(os.path.dirname(settings.DB_PATH), exist_ok=True)
    Base.metadata.create_all(bind=engine)


def seed_admin():
    """Create initial super_admin from env vars if no users exist."""
    if not settings.ADMIN_PASSWORD:
        return
    db = SessionLocal()
    try:
        if db.query(User).count() == 0:
            user = User(
                username=settings.ADMIN_USERNAME,
                role="super_admin",
            )
            user.set_password(settings.ADMIN_PASSWORD)
            db.add(user)
            db.commit()
            print(f"[init] Created super_admin: {settings.ADMIN_USERNAME}")
    finally:
        db.close()
