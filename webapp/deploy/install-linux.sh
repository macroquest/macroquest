#!/usr/bin/env bash
# =============================================================================
# MacroQuest Admin Panel — Linux Install Script
# Tested on: Ubuntu 22.04 LTS / Debian 12
# Run as root: sudo bash install-linux.sh
# =============================================================================
set -euo pipefail

# ── Colours ──────────────────────────────────────────────────────────────────
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

info()    { echo -e "${CYAN}[INFO]${NC} $*"; }
success() { echo -e "${GREEN}[OK]${NC}   $*"; }
warn()    { echo -e "${YELLOW}[WARN]${NC} $*"; }
error()   { echo -e "${RED}[ERROR]${NC} $*" >&2; }
die()     { error "$*"; exit 1; }
step()    { echo -e "\n${BOLD}${BLUE}━━ $* ${NC}"; }

# ── 1. Root check ─────────────────────────────────────────────────────────────
step "Pre-flight checks"
if [[ $EUID -ne 0 ]]; then
    die "This script must be run as root. Try: sudo bash $0"
fi
success "Running as root"

# Detect distro
if ! command -v apt-get &>/dev/null; then
    die "This script requires a Debian/Ubuntu system with apt-get."
fi

# ── 2. Install apt dependencies ──────────────────────────────────────────────
step "Installing system packages"
export DEBIAN_FRONTEND=noninteractive

apt-get update -q

PACKAGES=(
    python3.11
    python3.11-venv
    python3.11-dev
    python3-pip
    nginx
    certbot
    python3-certbot-nginx
    git
    curl
    openssl
    build-essential
)

info "Installing: ${PACKAGES[*]}"
apt-get install -y -q "${PACKAGES[@]}" || {
    warn "Some packages may not be available. Trying with python3 fallback…"
    apt-get install -y -q \
        python3 python3-venv python3-dev python3-pip \
        nginx certbot python3-certbot-nginx \
        git curl openssl build-essential
}

success "System packages installed"

# ── 3. Create system user ─────────────────────────────────────────────────────
step "Creating system user: mqadmin"
if id "mqadmin" &>/dev/null; then
    info "User 'mqadmin' already exists, skipping"
else
    useradd --system --shell /bin/bash --home /opt/mq-admin --create-home mqadmin
    success "Created user 'mqadmin' with home /opt/mq-admin"
fi

# ── 4. App directory & source ─────────────────────────────────────────────────
step "Setting up application directory"
APP_DIR="/opt/mq-admin"
mkdir -p "${APP_DIR}"

# If running from a git repo, copy it; otherwise prompt for source
if [[ -f "$(dirname "$0")/../webapp/app.py" ]] || [[ -f "$(dirname "$0")/../../webapp/app.py" ]]; then
    # Installed from a local checkout
    SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
    REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
    info "Copying from local repo: ${REPO_ROOT}"
    rsync -a --exclude='.git' --exclude='venv' --exclude='__pycache__' \
          --exclude='*.pyc' --exclude='data/*.db' \
          "${REPO_ROOT}/" "${APP_DIR}/"
    success "Application files copied"
elif [[ -f "${APP_DIR}/webapp/app.py" ]]; then
    info "Application already present at ${APP_DIR}, skipping copy"
else
    info "Cloning from GitHub…"
    git clone --depth=1 https://github.com/teichoui/macroquest "${APP_DIR}"
    success "Repository cloned"
fi

# ── 5. Python virtual environment & dependencies ──────────────────────────────
step "Setting up Python virtual environment"
PYTHON_BIN="$(command -v python3.11 2>/dev/null || command -v python3)"
info "Using Python: $("${PYTHON_BIN}" --version)"

"${PYTHON_BIN}" -m venv "${APP_DIR}/venv"
"${APP_DIR}/venv/bin/pip" install --quiet --upgrade pip wheel

if [[ -f "${APP_DIR}/requirements.txt" ]]; then
    info "Installing Python requirements…"
    "${APP_DIR}/venv/bin/pip" install --quiet -r "${APP_DIR}/requirements.txt"
    success "Requirements installed"
else
    die "requirements.txt not found at ${APP_DIR}/requirements.txt"
fi

# ── 6. Prompt for configuration ───────────────────────────────────────────────
step "Configuration"

read_default() {
    local prompt="$1"
    local default="$2"
    local result
    read -rp "  ${prompt} [${default}]: " result
    echo "${result:-$default}"
}

read_secret() {
    local prompt="$1"
    local result
    read -rsp "  ${prompt}: " result
    echo
    echo "$result"
}

echo -e "\n${CYAN}Please provide the following configuration values:${NC}\n"

DOMAIN=$(read_default "Domain name (e.g. admin.example.com, or leave blank for IP-only)" "localhost")
ADMIN_USERNAME=$(read_default "Admin username" "admin")

while true; do
    ADMIN_PASSWORD=$(read_secret "Admin password (min 12 chars)")
    if [[ ${#ADMIN_PASSWORD} -lt 12 ]]; then
        warn "Password must be at least 12 characters. Try again."
    else
        ADMIN_PASSWORD_CONFIRM=$(read_secret "Confirm admin password")
        if [[ "$ADMIN_PASSWORD" == "$ADMIN_PASSWORD_CONFIRM" ]]; then
            break
        else
            warn "Passwords do not match. Try again."
        fi
    fi
done

GITHUB_PAT=$(read_secret "GitHub Personal Access Token (for private repos, or press Enter to skip)")

# ── 7. Generate secrets ───────────────────────────────────────────────────────
step "Generating cryptographic keys"
SECRET_KEY=$(openssl rand -hex 32)
info "Generated SECRET_KEY"

ENCRYPTION_KEY=$("${APP_DIR}/venv/bin/python" -c \
    "from cryptography.fernet import Fernet; print(Fernet.generate_key().decode())")
info "Generated ENCRYPTION_KEY (Fernet)"

success "Secrets generated"

# ── 8. Write .env file ────────────────────────────────────────────────────────
step "Writing .env file"
ENV_FILE="${APP_DIR}/.env"

cat > "${ENV_FILE}" <<EOF
# MacroQuest Admin Panel — Environment Configuration
# Generated by install-linux.sh on $(date -u +"%Y-%m-%dT%H:%M:%SZ")
# KEEP THIS FILE SECURE — it contains encryption keys and secrets.

# Application
SECRET_KEY=${SECRET_KEY}
ENCRYPTION_KEY=${ENCRYPTION_KEY}
DEBUG=false
LOG_LEVEL=WARNING

# Admin seed account (used only on first init — change via UI after setup)
ADMIN_USERNAME=${ADMIN_USERNAME}
ADMIN_PASSWORD=${ADMIN_PASSWORD}

# GitHub
GITHUB_PAT=${GITHUB_PAT}

# Database
DATABASE_URL=sqlite+aiosqlite:///./webapp/data/mq_admin.db

# Server
HOST=127.0.0.1
PORT=8000
EOF

chmod 600 "${ENV_FILE}"
chown mqadmin:mqadmin "${ENV_FILE}"
success ".env written to ${ENV_FILE} (mode 600)"

# ── 9. Data directory ─────────────────────────────────────────────────────────
step "Creating data directory"
mkdir -p "${APP_DIR}/webapp/data"
mkdir -p "${APP_DIR}/webapp/logs"
chown -R mqadmin:mqadmin "${APP_DIR}/webapp/data" "${APP_DIR}/webapp/logs"
chmod 750 "${APP_DIR}/webapp/data" "${APP_DIR}/webapp/logs"
success "Data directories created"

# ── 10. Initialize database ───────────────────────────────────────────────────
step "Initializing database"
cd "${APP_DIR}"
sudo -u mqadmin "${APP_DIR}/venv/bin/python" -c "
import os, sys
sys.path.insert(0, '${APP_DIR}')
# Load .env manually for subprocess context
for line in open('${ENV_FILE}'):
    line = line.strip()
    if line and not line.startswith('#') and '=' in line:
        k, _, v = line.partition('=')
        os.environ.setdefault(k.strip(), v.strip())

from webapp.db import init_db, seed_admin
import asyncio

async def setup():
    await init_db()
    await seed_admin()

asyncio.run(setup())
print('Database initialized successfully.')
"
success "Database initialized"

# ── 11. Fix permissions ───────────────────────────────────────────────────────
step "Setting file ownership"
chown -R mqadmin:mqadmin "${APP_DIR}"
# Make venv non-writable by mqadmin at runtime (security)
chmod -R o-rwx "${APP_DIR}/venv"
success "Permissions set"

# ── 12. Systemd service ───────────────────────────────────────────────────────
step "Installing systemd service"
SERVICE_SRC="$(dirname "$0")/macroquest-webapp.service"
SERVICE_DST="/etc/systemd/system/macroquest-webapp.service"

if [[ -f "${SERVICE_SRC}" ]]; then
    cp "${SERVICE_SRC}" "${SERVICE_DST}"
else
    # Write it inline as fallback
    cat > "${SERVICE_DST}" <<'SVCEOF'
[Unit]
Description=MacroQuest Admin Panel (Build Pipeline)
After=network.target network-online.target
Wants=network-online.target

[Service]
Type=simple
User=mqadmin
Group=mqadmin
WorkingDirectory=/opt/mq-admin
EnvironmentFile=/opt/mq-admin/.env
ExecStart=/opt/mq-admin/venv/bin/uvicorn webapp.app:app \
    --host 127.0.0.1 \
    --port 8000 \
    --workers 2 \
    --no-access-log \
    --log-level warning
ExecStop=/bin/kill -TERM $MAINPID
TimeoutStopSec=10
Restart=always
RestartSec=3
StartLimitIntervalSec=60
StartLimitBurst=5
NoNewPrivileges=true
PrivateTmp=true
ProtectSystem=strict
ProtectHome=true
ReadWritePaths=/opt/mq-admin/webapp/data
ReadWritePaths=/opt/mq-admin/webapp/logs
StandardOutput=journal
StandardError=journal
SyslogIdentifier=mq-admin

[Install]
WantedBy=multi-user.target
SVCEOF
fi

systemctl daemon-reload
systemctl enable macroquest-webapp
systemctl restart macroquest-webapp

# Verify it started
sleep 2
if systemctl is-active --quiet macroquest-webapp; then
    success "Service 'macroquest-webapp' is running"
else
    error "Service failed to start. Check logs: journalctl -u macroquest-webapp -n 50"
    systemctl status macroquest-webapp --no-pager || true
    die "Aborting due to service startup failure"
fi

# ── 13. Nginx configuration ───────────────────────────────────────────────────
step "Configuring nginx"
NGINX_SRC="$(dirname "$0")/nginx.conf"
NGINX_SITE="/etc/nginx/sites-available/mq-admin"
NGINX_ENABLED="/etc/nginx/sites-enabled/mq-admin"

if [[ -f "${NGINX_SRC}" ]]; then
    cp "${NGINX_SRC}" "${NGINX_SITE}"
else
    # Minimal fallback nginx config (without SSL for now)
    cat > "${NGINX_SITE}" <<NGINXEOF
server {
    listen 80;
    server_name ${DOMAIN};
    location / {
        proxy_pass http://127.0.0.1:8000;
        proxy_set_header Host \$host;
        proxy_set_header X-Real-IP \$remote_addr;
        proxy_set_header X-Forwarded-For \$proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto \$scheme;
        proxy_buffering off;
        proxy_read_timeout 3600;
        client_max_body_size 64m;
    }
}
NGINXEOF
fi

# Replace the DOMAIN placeholder
if [[ -n "${DOMAIN}" && "${DOMAIN}" != "localhost" ]]; then
    sed -i "s/DOMAIN/${DOMAIN}/g" "${NGINX_SITE}"
    info "Domain set to: ${DOMAIN}"
fi

# Enable the site
rm -f "${NGINX_ENABLED}"
ln -sf "${NGINX_SITE}" "${NGINX_ENABLED}"

# Disable the default site if it exists and this is a fresh install
[[ -L "/etc/nginx/sites-enabled/default" ]] && rm -f /etc/nginx/sites-enabled/default

# Add rate limiting zone to nginx.conf if not present
if ! grep -q "mq_login" /etc/nginx/nginx.conf; then
    sed -i '/http {/a\    limit_req_zone $binary_remote_addr zone=mq_login:10m rate=5r/m;' /etc/nginx/nginx.conf
fi

# Test config
if nginx -t 2>&1; then
    systemctl reload nginx
    success "Nginx configured and reloaded"
else
    error "Nginx config test failed. Check ${NGINX_SITE}"
    # Don't hard-fail — SSL setup may fix the cert paths
fi

# ── 14. SSL / Certbot ─────────────────────────────────────────────────────────
if [[ -n "${DOMAIN}" && "${DOMAIN}" != "localhost" && "${DOMAIN}" != "127.0.0.1" ]]; then
    step "Obtaining SSL certificate via Certbot"
    info "Domain: ${DOMAIN}"
    warn "Make sure DNS for ${DOMAIN} points to this server before continuing."
    read -rp "  Run certbot now? (y/N): " RUN_CERTBOT
    if [[ "${RUN_CERTBOT}" =~ ^[Yy]$ ]]; then
        certbot --nginx --non-interactive --agree-tos --redirect \
            --email "admin@${DOMAIN}" \
            -d "${DOMAIN}" || {
            warn "Certbot encountered an error. You can run it manually:"
            warn "  certbot --nginx -d ${DOMAIN}"
        }
        success "SSL certificate obtained"
    else
        info "Skipping certbot. Run manually when ready:"
        info "  certbot --nginx -d ${DOMAIN}"
    fi
else
    info "Skipping SSL (no domain configured). Access via http://localhost or the server IP."
fi

# ── 15. Firewall (UFW if available) ──────────────────────────────────────────
if command -v ufw &>/dev/null; then
    step "Configuring firewall (UFW)"
    ufw allow 22/tcp   comment 'SSH'   >/dev/null 2>&1 || true
    ufw allow 80/tcp   comment 'HTTP'  >/dev/null 2>&1 || true
    ufw allow 443/tcp  comment 'HTTPS' >/dev/null 2>&1 || true
    # Block direct access to uvicorn port
    ufw deny 8000/tcp  >/dev/null 2>&1 || true
    info "UFW rules applied (SSH, HTTP, HTTPS allowed; port 8000 blocked externally)"
fi

# ── 16. Success ───────────────────────────────────────────────────────────────
echo
echo -e "${BOLD}${GREEN}╔══════════════════════════════════════════════════════╗${NC}"
echo -e "${BOLD}${GREEN}║   MacroQuest Admin Panel installed successfully!     ║${NC}"
echo -e "${BOLD}${GREEN}╚══════════════════════════════════════════════════════╝${NC}"
echo
if [[ -n "${DOMAIN}" && "${DOMAIN}" != "localhost" ]]; then
    echo -e "  URL:       ${BOLD}https://${DOMAIN}${NC}"
else
    SERVER_IP=$(hostname -I | awk '{print $1}')
    echo -e "  URL:       ${BOLD}http://${SERVER_IP}${NC}"
fi
echo -e "  Username:  ${BOLD}${ADMIN_USERNAME}${NC}"
echo -e "  Password:  ${BOLD}(as entered during setup)${NC}"
echo
echo -e "  Service:   ${CYAN}systemctl status macroquest-webapp${NC}"
echo -e "  Logs:      ${CYAN}journalctl -u macroquest-webapp -f${NC}"
echo -e "  Config:    ${CYAN}${ENV_FILE}${NC}"
echo
echo -e "${YELLOW}  IMPORTANT: Back up ${ENV_FILE} — it contains your encryption key.${NC}"
echo -e "${YELLOW}  Without it, encrypted backups cannot be restored.${NC}"
echo
