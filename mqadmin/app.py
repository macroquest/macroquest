"""
MQ Admin — Desktop TUI
Matches redfetch's dark Textual style.
Run: python -m mqadmin.app
"""
from textual.app import App, ComposeResult
from textual.binding import Binding
from textual.containers import Container, Horizontal, Vertical
from textual.screen import Screen
from textual.widgets import (
    Button, DataTable, Footer, Header, Input, Label, Static, TabbedContent, TabPane
)
from textual import work
from . import api


# ─────────────────────────────────────────────────────────────────────────────
# Login screen
# ─────────────────────────────────────────────────────────────────────────────
class LoginScreen(Screen):
    CSS = """
    LoginScreen { align: center middle; }
    #login-box { width: 50; border: round $primary; padding: 1 2; background: $surface; }
    #login-box Label { color: $text-muted; margin-bottom: 1; }
    #login-box Input { margin-bottom: 1; }
    #error-msg { color: red; height: 1; }
    """

    def compose(self) -> ComposeResult:
        with Container(id="login-box"):
            yield Label("⚙  MacroQuest Admin", id="title")
            yield Label("Server URL")
            yield Input(placeholder="https://admin.example.com", id="url-input",
                        value=api.get_base_url())
            yield Label("Username")
            yield Input(placeholder="username", id="user-input")
            yield Label("Password")
            yield Input(placeholder="password", password=True, id="pass-input")
            yield Button("Sign In", variant="primary", id="login-btn")
            yield Static("", id="error-msg")

    def on_button_pressed(self, event: Button.Pressed):
        if event.button.id == "login-btn":
            self._do_login()

    def on_input_submitted(self, event: Input.Submitted):
        self._do_login()

    def _do_login(self):
        url = self.query_one("#url-input", Input).value.strip()
        user = self.query_one("#user-input", Input).value.strip()
        pw = self.query_one("#pass-input", Input).value

        if not url or not user or not pw:
            self.query_one("#error-msg", Static).update("All fields required")
            return

        api.set_base_url(url)
        result = api.login(user, pw)
        location = result.get("location", "")

        if "/auth/totp" in location:
            self.app.push_screen(TotpScreen())
        elif "/auth/setup-2fa" in location:
            self.query_one("#error-msg", Static).update("Set up 2FA in the web panel first")
        elif result.get("ok"):
            self.app.switch_screen(DashboardScreen())
        else:
            self.query_one("#error-msg", Static).update("Invalid credentials")


# ─────────────────────────────────────────────────────────────────────────────
# TOTP screen
# ─────────────────────────────────────────────────────────────────────────────
class TotpScreen(Screen):
    CSS = """
    TotpScreen { align: center middle; }
    #totp-box { width: 40; border: round $primary; padding: 1 2; background: $surface; }
    #totp-error { color: red; height: 1; }
    """

    def compose(self) -> ComposeResult:
        with Container(id="totp-box"):
            yield Label("🔐 Two-Factor Authentication")
            yield Label("Enter the 6-digit code from your authenticator app:")
            yield Input(placeholder="000000", id="code-input", max_length=6)
            yield Button("Verify", variant="primary", id="verify-btn")
            yield Static("", id="totp-error")

    def on_button_pressed(self, event: Button.Pressed):
        if event.button.id == "verify-btn":
            self._verify()

    def on_input_submitted(self, _):
        self._verify()

    def _verify(self):
        code = self.query_one("#code-input", Input).value.strip()
        if api.verify_totp(code):
            self.app.switch_screen(DashboardScreen())
        else:
            self.query_one("#totp-error", Static).update("Invalid code — try again")


# ─────────────────────────────────────────────────────────────────────────────
# Dashboard screen
# ─────────────────────────────────────────────────────────────────────────────
class DashboardScreen(Screen):
    BINDINGS = [
        Binding("r", "refresh", "Refresh"),
        Binding("l", "trigger_live", "Trigger LIVE"),
        Binding("t", "trigger_test", "Trigger TEST"),
        Binding("e", "trigger_emu", "Trigger EMU"),
        Binding("q", "logout", "Logout"),
    ]
    CSS = """
    #env-cards { height: 7; }
    .env-card { border: round $primary; width: 1fr; padding: 0 1; }
    .env-card.live { border: round green; }
    .env-card.test { border: round yellow; }
    .env-card.emu  { border: round magenta; }
    #status-bar { height: 1; background: $surface-darken-1; }
    """

    def compose(self) -> ComposeResult:
        yield Header(show_clock=True)
        with Vertical():
            with Horizontal(id="env-cards"):
                for env in ("live", "test", "emu"):
                    with Container(classes=f"env-card {env}", id=f"card-{env}"):
                        yield Static(f"[bold]{env.upper()}[/bold]", id=f"label-{env}")
                        yield Static("Loading...", id=f"status-{env}")
                        yield Button(f"▶ Trigger {env.upper()}", id=f"btn-{env}", variant="default")
            yield Static("", id="status-bar")
            yield DataTable(id="runs-table")
        yield Footer()

    def on_mount(self):
        tbl = self.query_one("#runs-table", DataTable)
        tbl.add_columns("Run", "Workflow", "Status", "Started")
        self.refresh_data()

    def on_button_pressed(self, event: Button.Pressed):
        for env in ("live", "test", "emu"):
            if event.button.id == f"btn-{env}":
                self._trigger(env)

    @work(thread=True)
    def refresh_data(self):
        runs = api.get_runs()
        self.call_from_thread(self._update_table, runs)

    def _update_table(self, runs: list):
        tbl = self.query_one("#runs-table", DataTable)
        tbl.clear()
        for r in runs[:20]:
            status = r.get("conclusion") or r.get("status", "?")
            tbl.add_row(
                f"#{r.get('run_number', '?')}",
                r.get("name", "")[:40],
                status,
                (r.get("created_at", "")[:19] or "").replace("T", " "),
            )

    @work(thread=True)
    def _trigger(self, env: str):
        ok = api.trigger_build(env)
        msg = f"✓ {env.upper()} build triggered" if ok else f"✗ Failed to trigger {env.upper()}"
        self.call_from_thread(self._set_status, msg)

    def _set_status(self, msg: str):
        self.query_one("#status-bar", Static).update(msg)

    def action_refresh(self):       self.refresh_data()
    def action_trigger_live(self):  self._trigger("live")
    def action_trigger_test(self):  self._trigger("test")
    def action_trigger_emu(self):   self._trigger("emu")

    def action_logout(self):
        api.clear_token()
        self.app.switch_screen(LoginScreen())


# ─────────────────────────────────────────────────────────────────────────────
# App
# ─────────────────────────────────────────────────────────────────────────────
class MQAdminApp(App):
    TITLE = "MQ Admin"
    CSS_PATH = None

    def on_mount(self):
        if api.get_token() and api.get_base_url():
            self.push_screen(DashboardScreen())
        else:
            self.push_screen(LoginScreen())


def main():
    MQAdminApp().run()


if __name__ == "__main__":
    main()
