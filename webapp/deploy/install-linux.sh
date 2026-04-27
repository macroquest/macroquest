#!/usr/bin/env bash
# MacroQuest Admin Panel — Linux server install script
# Run as root on Ubuntu 22.04+ / Debian 12+

set -euo pipefail

RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'; NC='\033[0m'
info()  { echo -e "${GREEN}[+]${NC} $*"; }
warn()  { echo -e "${YELLOW}[!]${NC} $*"; }
error() { echo -e "${RED}[✗]${NC} $*"; exit 1; }

[[ $EUID -ne 0 ]] && error "Run as root: sudo bash install-linux.sh"

INSTALL_DIR="/opt/mq-admin"
SERVICE_NAME="mq-admin"
APP_USER="mqadmin"

# ── Collect inputs ──────────────────────────────────────────────────────────
echo ""
echo "════════════════════════════════════════════"
echo "  MacroQuest Admin Panel — Install Script  "
echo "════════════════════════════════════════════"
echo ""
read -rp "Domain name (e.g. admin.example.com): " DOMAIN
read -rp "Admin username: " ADMIN_USER
read -rsp "Admin password (min 12 chars): " ADMIN_PASS; echo ""
[[ ${#ADMIN_PASS} -lt 12 ]] && error "Password must be at least 12 characters"
read -rp "GitHub Personal Access Token (repo + actions:write): " GITHUB_PAT
read -rp "GitHub repo owner [teichoui]: " GITHUB_OWNER
GITHUB_OWNER="${GITHUB_OWNER:-teichoui}"
read -rp "GitHub repo name [macroquest]: " GITHUB_REPO
GITHUB_REPO="${GITHUB_REPO:-macroquest}"

# ── System packages ─────────────────────────────────────────────────────────
info "Installing system packages..."
apt-get update -q
apt-get install -y -q python3.11 python3.11-venv python3-pip nginx certbot python3-certbot-nginx git curl

# ── Create app user ──────────────────────────────────────────────────────────
if ! id "$APP_USER" &>/dev/null; then
    info "Creating system user $APP_USER..."
    useradd --system --shell /bin/false --home "$INSTALL_DIR" --create-home "$APP_USER"
fi

# ── Clone / update source ────────────────────────────────────────────────────
if [[ -d "$INSTALL_DIR/.git" ]]; then
    info "Updating existing installation..."
    git -C "$INSTALL_DIR" pull
else
    info "Cloning repository to $INSTALL_DIR..."
    git clone --depth 1 -b claude/remote-macro-quest-build-D8VXZ \
        "https://github.com/${GITHUB_OWNER}/${GITHUB_REPO}.git" "$INSTALL_DIR"
fi

# ── Python venv + deps ───────────────────────────────────────────────────────
info "Creating Python virtual environment..."
python3.11 -m venv "$INSTALL_DIR/venv"
"$INSTALL_DIR/venv/bin/pip" install --quiet --upgrade pip
"$INSTALL_DIR/venv/bin/pip" install --quiet -r "$INSTALL_DIR/webapp/requirements.txt"

# ── Generate keys ────────────────────────────────────────────────────────────
info "Generating cryptographic keys..."
SECRET_KEY=$(openssl rand -hex 32)
ENCRYPTION_KEY=$("$INSTALL_DIR/venv/bin/python" -c \
    "from cryptography.fernet import Fernet; print(Fernet.generate_key().decode())")

# ── Write .env ───────────────────────────────────────────────────────────────
info "Writing configuration..."
mkdir -p "$INSTALL_DIR/webapp/data"
cat > "$INSTALL_DIR/.env" << ENV
SECRET_KEY=${SECRET_KEY}
ENCRYPTION_KEY=${ENCRYPTION_KEY}
GITHUB_PAT=${GITHUB_PAT}
GITHUB_OWNER=${GITHUB_OWNER}
GITHUB_REPO=${GITHUB_REPO}
ADMIN_USERNAME=${ADMIN_USER}
ADMIN_PASSWORD=${ADMIN_PASS}
DB_PATH=${INSTALL_DIR}/webapp/data/mq_admin.db
ENV
chmod 600 "$INSTALL_DIR/.env"

# ── Initialise DB ────────────────────────────────────────────────────────────
info "Initialising database and creating admin user..."
cd "$INSTALL_DIR"
"$INSTALL_DIR/venv/bin/python" -c \
    "import sys; sys.path.insert(0, '.'); from webapp.db import init_db, seed_admin; init_db(); seed_admin()"

# ── Fix ownership ─────────────────────────────────────────────────────────────
chown -R "$APP_USER:$APP_USER" "$INSTALL_DIR"

# ── Systemd service ───────────────────────────────────────────────────────────
info "Installing systemd service..."
sed "s|YOURDOMAIN|$DOMAIN|g" "$INSTALL_DIR/webapp/deploy/macroquest-webapp.service" \
    > "/etc/systemd/system/${SERVICE_NAME}.service"
systemctl daemon-reload
systemctl enable --now "$SERVICE_NAME"

# ── nginx config ──────────────────────────────────────────────────────────────
info "Configuring nginx..."
sed "s/YOURDOMAIN/$DOMAIN/g" "$INSTALL_DIR/webapp/deploy/nginx.conf" \
    > "/etc/nginx/sites-available/$SERVICE_NAME"
ln -sf "/etc/nginx/sites-available/$SERVICE_NAME" "/etc/nginx/sites-enabled/$SERVICE_NAME"
rm -f /etc/nginx/sites-enabled/default
nginx -t && systemctl reload nginx

# ── SSL certificate ───────────────────────────────────────────────────────────
if [[ -n "$DOMAIN" && "$DOMAIN" != "localhost" ]]; then
    info "Obtaining SSL certificate from Let's Encrypt..."
    certbot --nginx -d "$DOMAIN" --non-interactive --agree-tos \
        --email "admin@${DOMAIN}" --redirect || warn "certbot failed — configure SSL manually"
fi

echo ""
echo "════════════════════════════════════════════"
info "Installation complete!"
echo ""
echo "  URL:      https://${DOMAIN}"
echo "  Username: ${ADMIN_USER}"
echo ""
warn "Log in and set up 2FA immediately."
warn "Store your backup of /opt/mq-admin/.env securely."
echo "════════════════════════════════════════════"
