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
	char                  InputBuf[2048];
	ImVector<char*>       Items;
	ImVector<const char*> Commands;
	ImVector<char*>       History;
	int                   HistoryPos;          // -1: new line, 0..History.Size-1 browsing history.
	ImGuiTextFilter       Filter;
	bool                  AutoScroll;
	bool                  ScrollToBottom;
	bool                  m_visible = true;
	ImGuiID               m_dockspaceId = 0;
	bool                  m_reset = false;
	mq::imgui::TextEditor m_editor;

	ImGuiConsole()
		: HistoryPos(-1)
		, AutoScroll(true)
		, ScrollToBottom(true)
	{
		ZeroMemory(InputBuf, lengthof(InputBuf));

		m_editor.SetReadOnly(true);
		m_editor.SetPalette(mq::imgui::TextEditor::GetDarkPalette());
		m_editor.SetRenderCursor(false);
		m_editor.SetShowWhitespaces(false);
		m_editor.SetRenderLineNumbers(false);
	}

	~ImGuiConsole()
	{
		ClearLog();

		for (int i = 0; i < History.Size; i++)
			free(History[i]);
	}

	void ClearLog()
	{
		for (int i = 0; i < Items.Size; i++)
			free(Items[i]);
		Items.clear();
	}

	void AddLog(const char* fmt, ...) IM_FMTARGS(2)
	{
		char buf[MAX_STRING];
		va_list args;
		va_start(args, fmt);
		vsnprintf(buf, IM_ARRAYSIZE(buf), fmt, args);
		buf[IM_ARRAYSIZE(buf) - 1] = 0;
		va_end(args);

		//Items.push_back(strdup(buf));
		m_editor.MoveBottom();
		m_editor.MoveEnd();
		m_editor.AppendLine(buf);
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

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_None
			| ImGuiWindowFlags_MenuBar;

		//ImGui::PushStyleColor(ImGuiCol_ResizeGrip, 0);
		//ImGui::SetNextWindowDockID(m_dockspaceId, ImGuiCond_Once);

		bool bBegin = ImGui::Begin("MacroQuest Console", &m_visible, windowFlags);

		//ImGui::PopStyleColor();

		if (!bBegin)
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
				ImGui::MenuItem("Auto-scroll", nullptr, &AutoScroll);

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
			AddLog("%d some text", Items.Size);
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
		Filter.Draw("Filter (\"incl,-excl\") (\"error\")", 180);
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

#if 0
		for (int i = 0; i < Items.Size; i++)
		{
			const char* item = Items[i];
			if (!Filter.PassFilter(item))
				continue;

			// Normally you would store more information in your item (e.g. make Items[] an array of structure, store color/type etc.)
			bool pop_color = false;
			if (strstr(item, "[error]")) { ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.4f, 0.4f, 1.0f)); pop_color = true; }
			else if (strncmp(item, "# ", 2) == 0) { ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.8f, 0.6f, 1.0f)); pop_color = true; }
			ImGui::TextUnformatted(item);
			if (pop_color)
				ImGui::PopStyleColor();
		}ad
#endif
		ImGui::PushAllowKeyboardFocus(false);
		m_editor.Render("TextEditor");
		ImGui::PopAllowKeyboardFocus();

		if (ScrollToBottom || (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
			ImGui::SetScrollHereY(1.0f);
		ScrollToBottom = false;

		ImGui::PopStyleVar();
		ImGui::EndChild();
		ImGui::Separator();

		// Command-line
		bool reclaim_focus = false;

		int textFlags = ImGuiInputTextFlags_EnterReturnsTrue
			| ImGuiInputTextFlags_CallbackCompletion
			| ImGuiInputTextFlags_CallbackHistory;

		bool bTextEdit = ImGui::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf), textFlags,
			[](ImGuiInputTextCallbackData* data)
			{ return static_cast<ImGuiConsole*>(data->UserData)->TextEditCallback(data); }, this);

		if (bTextEdit)
		{
			char* s = InputBuf;
			Strtrim(s);
			if (s[0])
				ExecCommand(s);
			strcpy(s, "");
			reclaim_focus = true;
		}

		// Auto-focus on window apparition
		ImGui::SetItemDefaultFocus();
		if (reclaim_focus)
			ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

		ImGui::End();
	}

	void ExecCommand(const char* command_line)
	{
		AddLog("# %s\n", command_line);

		// Inhsert into history. First find match and delete it so i can be pushed to the back. This isn't
		// trying to be smart or optimal.
		HistoryPos = -1;

		for (int i = History.Size - 1; i >= 0; i--)
		{
			if (ci_equals(History[i], command_line))
			{
				free(History[i]);
				History.erase(History.begin() + i);
				break;
			}
		}

		History.push_back(strdup(command_line));

		// Process command
		if (ci_equals(command_line, "CLEAR"))
		{
			ClearLog();
		}
		else if (ci_equals(command_line, "HELP"))
		{
			AddLog("Commands:");

			for (int i = 0; i < Commands.Size; i++)
				AddLog("- %s", Commands[i]);
		}
		else if (ci_equals(command_line, "HISTORY"))
		{
			int first = History.Size - 10;

			for (int i = first > 0 ? first : 0; i < History.Size; i++)
				AddLog("%3d: %s\n", i, History[i]);
		}
		else if (strlen(command_line) > 1 && command_line[0] == '/')
		{
			mq::EzCommand(command_line);
		}
		else
		{
			AddLog("Unknown command: '%s'\n", command_line);
		}

		// On command input, we scroll to bottom even if AutoScroll == false
		ScrollToBottom = true;
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

				for (int i = 0; i < Commands.Size; i++)
				{
					if (strnicmp(Commands[i], word_start, (int)(word_end - word_start)) == 0)
						candidates.push_back(Commands[i]);
				}

				if (candidates.Size == 0)
				{
					// No match
					AddLog("No match for \"%.*s\"!\n", (int)(word_end - word_start), word_start);
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
						AddLog("- %s\n", candidates[i]);
				}

				break;
			}

		case ImGuiInputTextFlags_CallbackHistory:
			{
				// Example of HISTORY
				const int prev_history_pos = HistoryPos;
				if (data->EventKey == ImGuiKey_UpArrow)
				{
					if (HistoryPos == -1)
						HistoryPos = History.Size - 1;
					else if (HistoryPos > 0)
						HistoryPos--;
				}
				else if (data->EventKey == ImGuiKey_DownArrow)
				{
					if (HistoryPos != -1)
						if (++HistoryPos >= History.Size)
							HistoryPos = -1;
				}

				// A better implementation would preserve the data on the current input line along with cursor position.
				if (prev_history_pos != HistoryPos)
				{
					const char* history_str = (HistoryPos >= 0) ? History[HistoryPos] : "";
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
	gImGuiConsole.AddLog("%s", line);

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
