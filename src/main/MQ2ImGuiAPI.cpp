/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "pch.h"
#include "MQ2Main.h"

#include "imgui/ImGuiTreePanelWindow.h"
#include "imgui/ImGuiColorTextEdit.h"
#include <imgui/imgui_internal.h>

#include <fmt/format.h>

namespace mq {

static bool gbShowDemoWindow = false;
static bool gbShowSettingsWindow = false;
static bool gbShowDebugWindow = false;
static bool gbShowConsoleWindow = true;
static int gRenderCallbacksId = 0;

imgui::ImGuiTreePanelWindow gSettingsWindow("MacroQuest Settings");
imgui::ImGuiTreePanelWindow gDebugWindow("MacroQuest Debug Tools");

static void InitializeMQ2ImGuiAPI();
static void ShutdownMQ2ImGuiAPI();
static void PulseMQ2ImGuiAPI();
static void UpdateOverlayUI();
static DWORD WriteChatColorImGuiAPI(const char* line, DWORD color, DWORD filter);

static MQModule gImGuiModule = {
	"ImGuiAPI",                   // Name
	false,                        // CanUnload
	InitializeMQ2ImGuiAPI,        // Initialize
	ShutdownMQ2ImGuiAPI,          // Shutdown
	PulseMQ2ImGuiAPI,             // Pulse
	nullptr,                      // SetGameState
	UpdateOverlayUI,              // UpdateImGui
	nullptr,                      // Zoned
	WriteChatColorImGuiAPI,       // WriteChatColor
};
MQModule* GetImGuiAPIModule() { return &gImGuiModule; }

//----------------------------------------------------------------------------

static const ImU32 s_defaultColor = IM_COL32(255, 255, 255, 255);

const mq::imgui::TextEditor::Palette& GetColorPalette()
{
	const static mq::imgui::TextEditor::Palette p = { {
			0xffffffff, // Default
			0xffffffff, // Keyword
			0xffffffff, // Number
			0xffffffff, // String
			0xffffffff, // Char literal
			0xffffffff, // Punctuation
			0xffffffff, // Preprocessor
			0xffffffff, // Identifier
			0xffffffff, // Known identifier
			0xffffffff, // Preproc identifier
			0xffffffff, // Comment (single line)
			0xffffffff, // Comment (multi line)
			0xff101010, // Background
			0xffe0e0e0, // Cursor
			0x80a06020, // Selection
			0x800020ff, // ErrorMarker
			0x40f08000, // Breakpoint
			0xff707000, // Line number
			0x40000000, // Current line fill
			0x40808080, // Current line fill (inactive)
			0x40a0a0a0, // Current line edge
		} };
	return p;
}

//----------------------------------------------------------------------------

static void Strtrim(char* str)
{
	char* str_end = str + strlen(str);
	while (str_end > str && str_end[-1] == ' ')
		str_end--;
	*str_end = 0;
}

class ImGuiConsole
{
public:
	char                     m_inputBuffer[2048];
	ImVector<const char*>    m_commands;
	std::vector<std::string> m_history;
	int                      m_historyPos;          // -1: new line, 0..History.Size-1 browsing history.
	ImGuiTextFilter          m_filter;
	bool                     m_autoScroll;
	bool                     m_scrollToBottom;
	bool                     m_visible = true;
	ImGuiID                  m_dockspaceId = 0;
	bool                     m_reset = false;
	mq::imgui::TextEditor    m_editor;

	ImGuiConsole()
		: m_historyPos(-1)
		, m_autoScroll(true)
		, m_scrollToBottom(true)
	{
		ZeroMemory(m_inputBuffer, lengthof(m_inputBuffer));

		m_editor.SetPalette(GetColorPalette());
		m_editor.SetReadOnly(true);
		m_editor.SetRenderCursor(false);
		m_editor.SetShowWhitespace(false);
		m_editor.SetRenderLineNumbers(false);
		m_editor.SetRawColorMode(true);
	}

	~ImGuiConsole()
	{
		ClearLog();
	}

	void ClearLog()
	{
		m_editor.SetText("");
	}

	template <typename... Args>
	void AddLog(ImU32 color, std::string_view fmt, const Args&... args)
	{
		fmt::basic_memory_buffer<char> buf;
		fmt::format_to(buf, fmt, args...);

		m_editor.MoveBottom();
		m_editor.MoveEnd();
		m_editor.InsertText(std::string(buf.data(), buf.size()));
		m_editor.InsertText("\n");
	}

	template <typename... Args>
	void AddLog(std::string_view fmt, const Args&... args)
	{
		AddLog(s_defaultColor, std::move(fmt), args...);
	}

	void DrawDockSpace()
	{
		// when using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
		// and handle the pass-thru hole, so we ask Begin() to not render a background.
		ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None
			| ImGuiDockNodeFlags_PassthruCentralNode
			| ImGuiDockNodeFlags_NoDockingInCentralNode
			//| ImGuiDockNodeFlags_AutoHideTabBar
			;

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each other.
		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoDocking
			| ImGuiWindowFlags_NoTitleBar
			| ImGuiWindowFlags_NoCollapse
			| ImGuiWindowFlags_NoResize
			| ImGuiWindowFlags_NoMove
			| ImGuiWindowFlags_NoBringToFrontOnFocus
			| ImGuiWindowFlags_NoNavFocus
			| ImGuiWindowFlags_NoBackground;

		//if (m_visible)
		//	windowFlags |= ImGuiWindowFlags_MenuBar;

		if (!m_visible)
			dockspaceFlags |= ImGuiDockNodeFlags_KeepAliveOnly;

		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);

		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

		// Important: note that we proceed even if Begin() returns false (a.k.a. window is collapsed).
		// This is because we want to keep our DockSpace() active. If DockSpace() is inactive,
		// all active windows docked to it will lose their parent and become undocked.

		// We cannot preserve the docking relationship between an active window and an inactive docking,
		// otherwise any change of dockspace/setings would leat to windows being stuck in limbo and never
		// being visible.
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

		bool display = ImGui::Begin("Overlay DockSpace Window", &m_visible, windowFlags);
		ImGui::PopStyleVar(3);

		// DockSpace
		ImGuiIO& op = ImGui::GetIO();
		m_dockspaceId = ImGui::GetID("Overlay DockSpace");

		ImGui::DockSpace(m_dockspaceId, ImVec2(0.0f, 0.0f), dockspaceFlags);

		if (ImGui::DockBuilderGetNode(m_dockspaceId) == nullptr || m_reset)
		{
			m_reset = false;

			ImGuiViewport* viewport = ImGui::GetMainViewport();
			// Reset layout
			ImGui::DockBuilderRemoveNode(m_dockspaceId);
			ImGui::DockBuilderAddNode(m_dockspaceId, ImGuiDockNodeFlags_DockSpace);
			ImGui::DockBuilderSetNodeSize(m_dockspaceId, viewport->Size);

			// This variable will track the document node, however we are not using it
			// here as we aren't docking anything into it.
			ImGuiID dock_main_id = m_dockspaceId;

			ImGuiID dock_id_console = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Up, 0.25f, nullptr, &dock_main_id);
			ImGui::DockBuilderDockWindow("MacroQuest Console", dock_id_console);

			ImGui::DockBuilderFinish(m_dockspaceId);
		}

		ImGui::End(); // end DockSpace()
	}

	void ResetPosition()
	{
		m_reset = true;
	}

	void ToggleVisibility()
	{
		m_visible = !m_visible;
	}

	void Draw()
	{
		DrawDockSpace();

		if (ImGui::Begin("Debug"))
		{
			if (ImGui::Button("Toggle"))
				ToggleVisibility();
			if (ImGui::Button("Reset"))
				ResetPosition();
		}
		ImGui::End();

		if (!m_visible)
			return;

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar;

		if (!ImGui::Begin("MacroQuest Console", &m_visible, windowFlags))
		{
			ImGui::End();
			return;
		}

		// As a specific feature guaranteed by the library, after calling Begin() the last Item
		// represent the title bar. So e.g. IsItemHovered() will return true when hovering the title bar.
		// Here we create a context menu only available from the title bar.
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Options"))
			{
				ImGui::MenuItem("Auto-scroll", nullptr, &m_autoScroll);

				ImGui::Separator();

				if (ImGui::MenuItem("Close Console"))
					m_visible = false;
				if (ImGui::MenuItem("Reset Position"))
					ResetPosition();

				ImGui::Separator();

				if (ImGui::MenuItem("Clear Console"))
					ClearLog();

				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		if (ImGui::SmallButton("Add Dummy Text"))
		{
			AddLog("{0} some text", m_editor.GetTotalLines());
			AddLog("some more text");
			AddLog("display very important message here!");
		}
		ImGui::SameLine();

		if (ImGui::SmallButton("Add Dummy Error"))
		{
			AddLog("[error] something went wrong");
		}
		ImGui::SameLine();

		bool copy_to_clipboard = ImGui::SmallButton("Copy");

		ImGui::Separator();

		ImGui::SameLine();
		m_filter.Draw("Filter (\"incl,-excl\") (\"error\")", 180);
		ImGui::Separator();

		const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing(); // 1 separator, 1 input text
		ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar); // Leave room for 1 separator + 1 InputText
		if (ImGui::BeginPopupContextWindow())
		{
			if (ImGui::Selectable("Clear")) ClearLog();
			ImGui::EndPopup();
		}

		// Display every line as a separate entry so we can change their color or add custom widgets. If you only want raw text you can use ImGui::TextUnformatted(log.begin(), log.end());
		// NB- if you have thousands of entries this approach may be too inefficient and may require user-side clipping to only process visible items.
		// You can seek and display only the lines that are visible using the ImGuiListClipper helper, if your elements are evenly spaced and you have cheap random access to the elements.
		// To use the clipper we could replace the 'for (int i = 0; i < Items.Size; i++)' loop with:
		//     ImGuiListClipper clipper(Items.Size);
		//     while (clipper.Step())
		//         for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++)
		// However, note that you can not use this code as is if a filter is active because it breaks the 'cheap random-access' property. We would need random-access on the post-filtered list.
		// A typical application wanting coarse clipping and filtering may want to pre-compute an array of indices that passed the filtering test, recomputing this array when user changes the filter,
		// and appending newly elements as they are inserted. This is left as a task to the user until we can manage to improve this example code!
		// If your items are of variable size you may want to implement code similar to what ImGuiListClipper does. Or split your data into fixed height items to allow random-seeking into your list.
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing

		ImGui::PushAllowKeyboardFocus(false);
		m_editor.Render("TextEditor");
		ImGui::PopAllowKeyboardFocus();

		if (m_scrollToBottom || (m_autoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
			ImGui::SetScrollHereY(1.0f);
		m_scrollToBottom = false;

		ImGui::PopStyleVar();
		ImGui::EndChild();
		ImGui::Separator();

		// Command-line
		bool reclaim_focus = false;

		int textFlags = ImGuiInputTextFlags_EnterReturnsTrue
			| ImGuiInputTextFlags_CallbackCompletion
			| ImGuiInputTextFlags_CallbackHistory;

		bool bTextEdit = ImGui::InputText("Input", m_inputBuffer, IM_ARRAYSIZE(m_inputBuffer), textFlags,
			[](ImGuiInputTextCallbackData* data)
			{ return static_cast<ImGuiConsole*>(data->UserData)->TextEditCallback(data); }, this);

		if (bTextEdit)
		{
			char* s = m_inputBuffer;
			Strtrim(s);
			if (s[0])
				ExecCommand(s);
			strcpy_s(s, MAX_STRING, "");
			reclaim_focus = true;
		}

		// Auto-focus on window apparition
		ImGui::SetItemDefaultFocus();
		if (reclaim_focus)
			ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

		ImGui::End();
	}

	void ExecCommand(const char* commandLine)
	{
		AddLog("# {0}\n", commandLine);

		// Inhsert into history. First find match and delete it so i can be pushed to the back. This isn't
		// trying to be smart or optimal.
		m_historyPos = -1;

		for (int i = (int)m_history.size() - 1; i >= 0; --i)
		{
			if (ci_equals(m_history[i], commandLine))
			{
				m_history.erase(m_history.begin() + i);
				break;
			}
		}
		m_history.emplace_back(commandLine);

		// Process command
		if (ci_equals(commandLine, "clear"))
		{
			ClearLog();
		}
		else if (ci_equals(commandLine, "help"))
		{
			AddLog("Commands:");

			for (int i = 0; i < m_commands.Size; i++)
				AddLog("- {0}", m_commands[i]);
		}
		else if (ci_equals(commandLine, "history"))
		{
			int first = m_history.size() - 10;

			for (size_t i = first > 0 ? first : 0; i < m_history.size(); i++)
				AddLog("{0:3d}: {1}\n", i, m_history[i].c_str());
		}
		else if (strlen(commandLine) > 1 && commandLine[0] == '/')
		{
			mq::EzCommand(commandLine);
		}
		else
		{
			AddLog("Unknown command: '{0}'\n", commandLine);
		}

		// On command input, we scroll to bottom even if AutoScroll == false
		m_scrollToBottom = true;
	}

	int TextEditCallback(ImGuiInputTextCallbackData* data)
	{
		switch (data->EventFlag)
		{
		case ImGuiInputTextFlags_CallbackCompletion:
			{
				// Example of TEXT COMPLETION

				// Locate beginning of current word
				const char* word_end = data->Buf + data->CursorPos;
				const char* word_start = word_end;
				while (word_start > data->Buf)
				{
					const char c = word_start[-1];
					if (c == ' ' || c == '\t' || c == ',' || c == ';')
						break;

					word_start--;
				}

				// Build a list of candidates
				ImVector<const char*> candidates;
				std::string_view word{ word_start, (size_t)(word_end - word_start) };

				for (int i = 0; i < m_commands.Size; i++)
				{
					if (ci_starts_with(m_commands[i], word))
						candidates.push_back(m_commands[i]);
				}

				if (candidates.Size == 0)
				{
					// No match
					AddLog("No match for \"{0}\"!\n", word);
				}
				else if (candidates.size() == 1)
				{
					// Single match. Delete the beginning of the word and replace it entirely so we've got nice casing
					data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
					data->InsertChars(data->CursorPos, candidates[0]);
					data->InsertChars(data->CursorPos, " ");
				}
				else
				{
					// Multiple matches. Complete as much as we can, so inputing "C" will complete to "CL" and display "CLEAR" and "CLASSIFY"
					int match_len = (int)(word_end - word_start);
					for (;;)
					{
						int c = 0;
						bool all_candidates_matches = true;
						for (int i = 0; i < candidates.Size && all_candidates_matches; i++)
							if (i == 0)
								c = toupper(candidates[i][match_len]);
							else if (c == 0 || c != toupper(candidates[i][match_len]))
								all_candidates_matches = false;
						if (!all_candidates_matches)
							break;
						match_len++;
					}

					if (match_len > 0)
					{
						data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
						data->InsertChars(data->CursorPos, candidates[0], candidates[0] + match_len);
					}

					// List matches
					AddLog("Possible matches:\n");
					for (int i = 0; i < candidates.Size; i++)
						AddLog("- {0}\n", candidates[i]);
				}

				break;
			}

		case ImGuiInputTextFlags_CallbackHistory:
			{
				// Example of HISTORY
				const int prev_history_pos = m_historyPos;
				if (data->EventKey == ImGuiKey_UpArrow)
				{
					if (m_historyPos == -1)
						m_historyPos = m_history.size() - 1;
					else if (m_historyPos > 0)
						m_historyPos--;
				}
				else if (data->EventKey == ImGuiKey_DownArrow)
				{
					if (m_historyPos != -1)
						if (++m_historyPos >= (int)m_history.size())
							m_historyPos = -1;
				}

				// A better implementation would preserve the data on the current input line along with cursor position.
				if (prev_history_pos != m_historyPos)
				{
					const char* history_str = (m_historyPos >= 0) ? m_history[m_historyPos].c_str() : "";
					data->DeleteChars(0, data->BufTextLen);
					data->InsertChars(0, history_str);
				}
			}
		}
		return 0;
	}
};

ImGuiConsole gImGuiConsole;

//----------------------------------------------------------------------------

void AddSettingsPanel(const char* name, fPanelDrawFunction drawFunction)
{
	gSettingsWindow.AddPanel(name, drawFunction);
}

void RemoveSettingsPanel(const char* name)
{
	gSettingsWindow.RemovePanel(name);
}

void AddDebugPanel(const char* name, fPanelDrawFunction drawFunction)
{
	gDebugWindow.AddPanel(name, drawFunction);
}

void RemoveDebugPanel(const char* name)
{
	gDebugWindow.RemovePanel(name);
}

static void DoToggleImGuiOverlay(const char* name, bool down)
{
	if (down)
	{
		SetOverlayEnabled(!IsOverlayEnabled());
	}
}

static void UpdateOverlayUI()
{
	gImGuiConsole.Draw();

	if (gbShowDemoWindow)
	{
		ImGui::ShowDemoWindow(&gbShowDemoWindow);
	}

	if (gbShowSettingsWindow)
	{
		gSettingsWindow.Draw(&gbShowSettingsWindow);
	}

	if (gbShowDebugWindow)
	{
		gDebugWindow.Draw(&gbShowDebugWindow);
	}
}

static DWORD WriteChatColorImGuiAPI(const char* line, DWORD color, DWORD filter)
{
	// TODO: Translate color to RGBA

	gImGuiConsole.AddLog("{0}", line);

	return 0;
}

static void InitializeMQ2ImGuiAPI()
{
	// Init settings
	gbShowDemoWindow = GetPrivateProfileBool("MacroQuest", "ShowDemoWindow", gbShowDemoWindow, mq::internal_paths::MQini);
	gbShowDebugWindow = GetPrivateProfileBool("MacroQuest", "ShowDebugWindow", gbShowDebugWindow, mq::internal_paths::MQini);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "ShowDemoWindow", gbShowDemoWindow, mq::internal_paths::MQini);
		WritePrivateProfileBool("MacroQuest", "ShowDebugWindow", gbShowDebugWindow, mq::internal_paths::MQini);
	}

	// Add keybind to toggle imgui
	AddMQ2KeyBind("TOGGLE_IMGUI_OVERLAY", DoToggleImGuiOverlay);

	AddCascadeMenuItem("Settings", []() { gbShowSettingsWindow = true; }, 2);
	AddCascadeMenuItem("Debug Window", []() { gbShowDebugWindow = true; });
	AddCascadeMenuItem("ImGui Demo", []() { gbShowDemoWindow = true; });
}

static void ShutdownMQ2ImGuiAPI()
{
	RemoveMQ2KeyBind("TOGGLE_IMGUI_OVERLAY");

	// Remove the imgui render function
	RemoveRenderCallbacks(gRenderCallbacksId);
}

static void PulseMQ2ImGuiAPI()
{
	static bool bShowDebugWindowLast = gbShowDebugWindow;
	if (bShowDebugWindowLast != gbShowDebugWindow)
	{
		WritePrivateProfileBool("MacroQuest", "ShowDebugWindow", gbShowDebugWindow, mq::internal_paths::MQini);
		bShowDebugWindowLast = gbShowDebugWindow;
	}

	static bool bShowDemoWindowLast = gbShowDemoWindow;
	if (bShowDemoWindowLast != gbShowDemoWindow)
	{
		WritePrivateProfileBool("MacroQuest", "ShowDemoWindow", gbShowDemoWindow, mq::internal_paths::MQini);
		bShowDemoWindowLast = gbShowDemoWindow;
	}
}

} // namespace mq
