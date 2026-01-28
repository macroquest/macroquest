/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

#include "MQ2DeveloperTools.h"
#include "MQ2ImGuiTools.h"
#include "ImGuiManager.h"
#include "mq/zep/ImGuiZepEditor.h"
#include "mq/zep/ImGuiZepConsole.h"
#include "mq/imgui/MQConsoleDelegate.h"
#include "zep.h"

#include "imgui/ImGuiTreePanelWindow.h"
#include "mq/imgui/ConsoleWidget.h"

#include <imgui/imgui_internal.h>

#include <optional>
#include "sqlite3.h"

namespace mq {

//----------------------------------------------------------------------------

// Indicates that there has been a request to toggle the console.
bool gbToggleConsoleRequested = false;

// Indicates that there has been a request to hide/show the console
std::optional<bool> gbSetConsoleVisibilityRequest = std::nullopt;

// If true, we will autosize the everquest window viewport to match the dockspace central node.
bool gbAutoDockspaceViewport = false;
bool gbAutoDockspacePreserveRatio = false;


static constexpr MQColor s_defaultColor = MQColor(240, 240, 240, 255);
static ImGuiID s_dockspaceId = 0;
static ImGuiID s_dockspaceTopSegmentId = 0;

// Some default color constants to patch eq style links
static const ImU32 s_linkHoverColorDefault = Zep::ZepColor(0, 0, 255);
static const ImU32 s_linkHoverColorSpam = Zep::ZepColor(0, 255, 0);
static const ImU32 s_linkHoverColorPlayer = Zep::ZepColor(138, 163, 255);
static const ImU32 s_linkColorDefault = Zep::ZepColor(0, 255, 255);
static const ImU32 s_linkColorSpam = Zep::ZepColor(128, 128, 0);
static const ImU32 s_linkColorPlayer = Zep::ZepColor(0, 0, 0, 0); // use current color

static const int s_userColorItemLink = USERCOLOR_LINK;
static const int s_userColorAchievementLink = USERCOLOR_ACHIEVEMENT;
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_ROF + 1)
static const int s_userColorDialogLink = USERCOLOR_DIALOG_LINK;
static const int s_userColorCommandLink = USERCOLOR_DIALOG_LINK;
static const int s_userColorFactionLink = USERCOLOR_FACTION_LINK;
#endif

static bool s_dockspaceVisible = true;
static bool s_consoleVisible = false;
static bool s_consoleVisibleOnStartup = false;
static bool s_resetConsolePosition = false;
static bool s_setFocus = false;
static bool s_consolePersistentCommandHistory = false;

class MQConsole;
MQConsole* gMQConsole = nullptr;

static void Strtrim(char* str)
{
	char* str_end = str + strlen(str);
	while (str_end > str && str_end[-1] == ' ')
		str_end--;
	*str_end = 0;
}

static void MakeColorGradient(float frequency1, float frequency2, float frequency3,
	float phase1, float phase2, float phase3,
	float center = 128, float width = 127, int length = 50);

//============================================================================

#pragma region Zep Integration

//----------------------------------------------------------------------------

bool MQConsoleDelegate::OnHyperlinkClicked(ImGuiZepConsole* console, Zep::ZepMouseButton button,
	uint32_t modifiers, const std::string& hyperlinkData, int hyperlinkId)
{
	TextTagInfo tagInfo = ExtractLink(hyperlinkData);

	if (tagInfo.tagCode == ETAG_INVALID)
		return false;

	ExecuteTextLink(tagInfo);
	return true;
}

bool MQConsoleDelegate::OnInsertFormattedText(ImGuiZepConsole* console, Zep::GlyphIterator position,
	std::string_view text, ImU32 color)
{
	// Parse hyperlink data
	static TextTagInfo textTagInfo[MAX_EXTRACT_LINKS];
	size_t linkCount = eqlib::ExtractLinks(text, textTagInfo, MAX_EXTRACT_LINKS);

	if (linkCount > 0)
	{
		// Insert text in segments, broken up by the links.
		size_t segPos = 0;

		for (size_t curTag = 0; curTag < linkCount; ++curTag)
		{
			TextTagInfo& tagInfo = textTagInfo[curTag];

			// Get text before.
			std::string_view curSeg = text.substr(segPos, tagInfo.link.data() - text.data() - segPos);
			if (!curSeg.empty())
			{
				position = console->InsertText(position, curSeg, color);
				segPos += curSeg.length();
			}

			// Insert hyperlink.
			InsertHyperlink(console, position, tagInfo);
			position = position.Move(static_cast<long>(tagInfo.text.length()));
			segPos = tagInfo.link.data() - text.data() + tagInfo.link.size();
		}

		// If there is anything at the end, do that too.
		std::string_view endSeg = text.substr(segPos);
		if (!endSeg.empty())
		{
			position = console->InsertText(position, endSeg, color);
		}

		return true;
	}

	return false;
}

void MQConsoleDelegate::InsertHyperlink(ImGuiZepConsole* console, Zep::GlyphIterator position, const TextTagInfo& tagInfo)
{
	auto& style = console->GetStyle();

	uint32_t color = style.colors[ImGuiZepConsoleCol_Link];
	uint32_t hoverColor = style.colors[ImGuiZepConsoleCol_LinkHover];

	switch (tagInfo.tagCode)
	{
	case ETAG_SPELL:
	case ETAG_ITEM:
		color = GetColorForChatColor(s_userColorItemLink).ToABGR();
		break;
	case ETAG_PLAYER:
		color = s_linkColorPlayer;
		hoverColor = s_linkHoverColorPlayer;
		break;
	case ETAG_SPAM:
		color = s_linkColorSpam;
		hoverColor = s_linkHoverColorSpam;
		break;
	case ETAG_ACHIEVEMENT:
		color = GetColorForChatColor(s_userColorAchievementLink).ToABGR();
		break;
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_ROF + 1)
	case ETAG_DIALOG_RESPONSE:
		color = GetColorForChatColor(s_userColorDialogLink).ToABGR();
		break;
	case ETAG_COMMAND:
		color = GetColorForChatColor(s_userColorCommandLink).ToABGR();
		break;
	case ETAG_FACTION:
		color = GetColorForChatColor(s_userColorFactionLink).ToABGR();
		break;
#endif
	default:
		break;
	}

	console->InsertHyperlink(position, tagInfo.text, std::string(tagInfo.link), color, hoverColor);
}

class MQMainConsoleDelegate : public MQConsoleDelegate
{
public:
	bool OnHyperlinkClicked(ImGuiZepConsole* console, Zep::ZepMouseButton button, uint32_t modifiers,
		const std::string& hyperlinkData, int hyperlinkId) override
	{
		if (starts_with(hyperlinkData, "testlink:"))
		{
			std::string text = fmt::format("Clicked hyperlink: {}", std::string_view{ hyperlinkData }.substr(9));

			console->AppendText(text, MQColor(255, 255, 0), true);
		}
		else
		{
			if (MQConsoleDelegate::OnHyperlinkClicked(console, button, modifiers, hyperlinkData, hyperlinkId))
				return true;

			console->AppendText(fmt::format("Clicked link: {}", hyperlinkData));
		}

		return true;
	}
};

#pragma endregion

std::vector<std::string> InitConsoleDatabase(sqlite3*& db, int process_id)
{
	std::vector<std::string> history;
	if (s_consolePersistentCommandHistory)
	{
		const std::string db_path = internal_paths::Logs + "\\ConsoleBuffer.db";
		if (sqlite3_open_v2(db_path.c_str(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE | SQLITE_OPEN_WAL, nullptr) != SQLITE_OK)
		{
			WriteChatf("MQ Console Error opening console buffer database: %s", sqlite3_errmsg(db));
			sqlite3_close(db);
			db = nullptr;
		}
		else
		{
			char* err_msg = nullptr;
			if (sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS entries (entry_timestamp TEXT, pid INTEGER, command TEXT)", nullptr, nullptr, &err_msg) != SQLITE_OK)
			{
				WriteChatf("MQ Console Error creating console buffer table: %s", err_msg);
				sqlite3_free(err_msg);
				sqlite3_close(db);
				db = nullptr;
			}
			else
			{
				if (sqlite3_exec(db, "PRAGMA journal_mode=WAL;", nullptr, nullptr, &err_msg) != SQLITE_OK)
				{
					WriteChatf("MQ Console Error setting console buffer journal mode: %s", err_msg);
					sqlite3_free(err_msg);
					sqlite3_close(db);
					db = nullptr;
				}
				else
				{
					// Fill the history buffer prioritizing this PID and limiting result sets from other PIDs.
					const char* query = R"(
						WITH PriorityEntries AS (
							SELECT entry_timestamp,
								pid,
								command,
								1 AS Priority,
								MAX(entry_timestamp) OVER() AS LastTimestamp
							FROM entries
							WHERE pid = ? -- Prioritize the current PID
						),

						OtherPIDs AS (
							SELECT pid,
								MAX(entry_timestamp) AS LastTimestamp
							FROM entries
							WHERE pid != ? -- exclude the current PID
							GROUP BY pid
							ORDER BY LastTimeStamp DESC
							LIMIT 3 -- only get the last 3 processes
						),

						OtherEntries AS (
							SELECT oe.entry_timestamp,
								oe.pid,
								oe.command,
								2 AS Priority,
								op.LastTimeStamp
							FROM entries oe
							INNER JOIN OtherPIDs op ON oe.pid = op.pid
						)

						SELECT command
						FROM (
							SELECT *
							FROM PriorityEntries

							UNION ALL

							SELECT *
							FROM OtherEntries
							ORDER BY LastTimestamp DESC -- get the latest entries first
							LIMIT 50 -- we only want 50 commands since this isn't our original pid anyway
						)
						--ORDER BY Priority ASC, LastTimeStamp DESC, pid ASC, entry_timestamp DESC
						ORDER BY
							Priority DESC,       -- Sort by the current PID first
							LastTimeStamp ASC,   -- Then sort by the last timestamp of the other PIDs
							pid DESC,            -- Then sort by the PID in case there's a tie
							entry_timestamp ASC  -- Then sort by the timestamp of the entry so they're in order
					)";

					sqlite3_stmt* stmt;
			        if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK)
			        {
						WriteChatf("MQ Console Error preparing query for console buffer retrieval: %s", sqlite3_errmsg(db));
					}
					else
					{
						sqlite3_bind_int(stmt, 1, process_id);
						sqlite3_bind_int(stmt, 2, process_id);

						while (sqlite3_step(stmt) == SQLITE_ROW)
						{
							if (const char* text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)))
							{
								history.emplace_back(text);
							}
						}

						sqlite3_finalize(stmt);
					}
				}
			}
		}
	}
	return history;
}

void AddEntryToDatabase(sqlite3* db, int process_id, const char* entry)
{
	if (db != nullptr)
	{
		const char* query = "INSERT INTO entries (entry_timestamp, pid, command) VALUES (strftime('%Y-%m-%d %H:%M:%f', 'now', 'localtime'), ?, ?);";
		sqlite3_stmt* stmt;
		if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK)
		{
			WriteChatf("MQ Console Error preparing query for console buffer insertion: %s", sqlite3_errmsg(db));
		}
		else
		{
			sqlite3_bind_int(stmt, 1, process_id);
			sqlite3_bind_text(stmt, 2, entry, -1, SQLITE_STATIC);

			if (sqlite3_step(stmt) != SQLITE_DONE)
			{
				WriteChatf("MQ Console Error inserting into console buffer: %s", sqlite3_errmsg(db));
			}

			sqlite3_finalize(stmt);
		}
	}
}
//============================================================================

#pragma region ImGui Console

class MQConsole
{
public:
	char m_inputBuffer[2048];
	ImVector<const char*> m_commands;
	std::vector<std::string> m_history;
	sqlite3* m_db = nullptr;
	int current_pid = GetCurrentProcessId();
	int m_historyPos = -1;    // -1: new line, 0..History.Size-1 browsing history.
	bool m_scrollToBottom = true;
	std::unique_ptr<ImGuiZepConsole> m_zepConsole;
	bool m_localEcho = true;

	MQConsole()
	{
		ZeroMemory(m_inputBuffer, lengthof(m_inputBuffer));
		m_zepConsole = std::make_unique<ImGuiZepConsole>("##ZepConsole");
		m_zepConsole->SetDelegate(std::make_shared<MQMainConsoleDelegate>());

		m_localEcho = GetPrivateProfileBool("Console", "LocalEcho", m_localEcho, internal_paths::MQini);

		bool autoScroll = GetPrivateProfileBool("Console", "AutoScroll", m_zepConsole->GetAutoScroll(), internal_paths::MQini);
		m_zepConsole->SetAutoScroll(autoScroll);

		int maxBufferLines = GetPrivateProfileInt("Console", "MaxBufferLines", m_zepConsole->GetMaxBufferLines(), internal_paths::MQini);
		m_zepConsole->SetMaxBufferLines(maxBufferLines);
		m_history = InitConsoleDatabase(m_db, current_pid);
	}

	~MQConsole()
	{
		ClearLog();
		if (m_db != nullptr)
		{
			sqlite3_close(m_db);
		}
	}

	void ClearLog()
	{
		m_zepConsole->Clear();
	}

	template <typename... Args>
	void AddLog(ImU32 color, std::string_view fmt, Args&&... args)
	{
		fmt::basic_memory_buffer<char> buf;
		fmt::vformat_to(fmt::appender(buf), fmt, fmt::make_format_args(std::forward<Args>(args)...));

		m_zepConsole->AppendText(std::string_view(buf.data(), buf.size()), color, false);
	}

	template <typename... Args>
	void AddLog(std::string_view fmt, const Args&... args)
	{
		AddLog(s_defaultColor.ToImU32(), std::move(fmt), args...);
	}

	void AddWriteChatColorLog(const char* line, MQColor defaultColor, bool newline = false)
	{
		m_zepConsole->AppendText(line, defaultColor, newline);
	}

	void Draw(bool* pOpen)
	{
		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar;

		ImGui::SetNextWindowSize(ImVec2(640, 240), ImGuiCond_FirstUseEver);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(1, 0));

		if (!ImGui::Begin("MacroQuest Console", pOpen, windowFlags))
		{
			ImGui::End();

			ImGui::PopStyleVar();
			return;
		}

		// Need to unpop this for the menu.
		ImGui::PopStyleVar();

		// As a specific feature guaranteed by the library, after calling Begin() the last Item
		// represent the title bar. So e.g. IsItemHovered() will return true when hovering the title bar.
		// Here we create a context menu only available from the title bar.
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Options"))
			{
				bool autoScroll = m_zepConsole->GetAutoScroll();
				if (ImGui::MenuItem("Auto-scroll", nullptr, &autoScroll))
				{
					m_zepConsole->SetAutoScroll(autoScroll);
					WritePrivateProfileBool("Console", "AutoScroll", autoScroll, internal_paths::MQini);
				}

				bool localEcho = GetLocalEcho();
				if (ImGui::MenuItem("Local Echo", nullptr, &m_localEcho))
					SetLocalEcho(localEcho);

				ImGui::Separator();

				if (ImGui::MenuItem("Close Console"))
					*pOpen = false;
				if (ImGui::MenuItem("Reset Position"))
					s_resetConsolePosition = true;

				ImGui::Separator();

				if (ImGui::MenuItem("Clear Console"))
					ClearLog();

				if (ImGui::BeginMenu("Extras"))
				{
					if (ImGui::MenuItem("Color Test"))
					{
						WriteChatColor("\ayYELLOW    \a-yDARK YELLOW");
						WriteChatColor("\aoORANGE    \a-oDARK ORANGE");
						WriteChatColor("\agGREEN     \a-gDARK GREEN");
						WriteChatColor("\auBLUE      \a-uDARK BLUE");
						WriteChatColor("\arRED       \a-rDARK RED");
						WriteChatColor("\atTEAL      \a-tDARK TEAL");
						WriteChatColor("\abBLACK");
						WriteChatColor("\amMAGENTA   \a-mDARK MAGENTA");
						WriteChatColor("\apPURPLE    \a-pDARK PURPLE");
						WriteChatColor("\awWHITE     \a-wGREY");

						MakeColorGradient(.3f, .3f, .3f, 0, 2, 4);
					}

					if (m_zepConsole)
					{
						if (ImGui::MenuItem("Hyperlink Test"))
						{
							DoHyperlinkTest();
						}
						if (ImGui::MenuItem("Achievement link Test"))
						{
							DoAchievementLinkTest();
						}
					}

					ImGui::EndMenu();
				}
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Windows"))
			{
				ImGuiTools_DrawWindowsMenu();
				ImGui::EndMenu();
			}

			DeveloperTools_DrawMenu();

			ImGui::EndMenuBar();
		}

		// And put it back ...

		const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing(); // 1 separator, 1 input text

		// Right click menu for editor
		if (ImGui::BeginPopupContextWindow())
		{
			if (ImGui::Selectable("Clear")) ClearLog();
			ImGui::EndPopup();
		}

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

		ImVec2 contentSize = ImGui::GetContentRegionAvail();
		contentSize.y -= footer_height_to_reserve;

		m_zepConsole->Render(contentSize);

		// Command-line
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(2, 4));
		ImGui::Separator();

		int textFlags = ImGuiInputTextFlags_EnterReturnsTrue
			| ImGuiInputTextFlags_CallbackCompletion
			| ImGuiInputTextFlags_CallbackHistory;

		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 6);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 4);
		ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x);
		ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
		ImGui::PushFont(mq::imgui::ConsoleFont);

		bool bTextEdit = ImGui::InputText("##Input", m_inputBuffer, IM_ARRAYSIZE(m_inputBuffer), textFlags,
			[](ImGuiInputTextCallbackData* data)
		{ return static_cast<MQConsole*>(data->UserData)->TextEditCallback(data); }, this);

		ImGui::PopFont();
		ImGui::PopStyleColor();
		ImGui::PopStyleVar(2);


		if (bTextEdit)
		{
			char* s = m_inputBuffer;
			Strtrim(s);
			if (s[0])
				ExecCommand(s);
			strcpy_s(s, MAX_STRING, "");
			s_setFocus = true;
		}

		// Auto-focus on window apparition
		ImGui::SetItemDefaultFocus();
		if (s_setFocus)
		{
			s_setFocus = false;
			ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget
		}

		ImGui::End();
	}

	void ExecCommand(const char* commandLine)
	{
		if (GetLocalEcho())
			AddLog(MQColor(128, 128, 128).ToImU32(), "> {0}\n", commandLine);

		// Insert into history. First find match and delete it so i can be pushed to the back. This isn't
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
		AddEntryToDatabase(m_db, current_pid, commandLine);

		// Process command
		if (ci_equals(commandLine, "clear"))
		{
			ClearLog();
		}
		else if (ci_equals(commandLine, "help"))
		{
			AddLog("Commands:\n");

			for (int i = 0; i < m_commands.Size; i++)
				AddLog("- {0}\n", m_commands[i]);
		}
		else if (ci_equals(commandLine, "history"))
		{
			int first = static_cast<int>(m_history.size()) - 10;

			for (size_t i = first > 0 ? first : 0; i < m_history.size(); i++)
				AddLog("{0:3d}: {1}\n", i, m_history[i].c_str());
		}
		else if (strlen(commandLine) > 1 && commandLine[0] == '/')
		{
			mq::DoCommand(commandLine, true);
		}
		else if (gBuild == static_cast<int>(BuildTarget::Emu) && strlen(commandLine) > 1 && commandLine[0] == '#')
		{
			mq::DoCommandf("/say %s", commandLine, true);
		}
		else
		{
			AddLog(IM_COL32(255, 0, 0, 255), "Unknown command: '{0}'\n", commandLine);
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
					m_historyPos = static_cast<int>(m_history.size()) - 1;
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

	void DoAchievementLinkTest()
	{
		std::string_view line = "You say to your guild, '\x12" "3TestToon^500010200^1^0^0^0^0^0^'Welcome to Crescent Reach (1+)\x12'";
		m_zepConsole->AppendText(line, s_defaultColor, true);
	}

	void DoHyperlinkTest()
	{
		static int hyperlinkNum = 1;
		std::string text = fmt::format("This is hyperlink {}", hyperlinkNum++);

		m_zepConsole->InsertHyperlink(m_zepConsole->GetActiveBuffer()->End(), text,
			ZepAttribute::HyperlinkAttributeData{ fmt::format("testlink:{}'s data", text) });
		m_zepConsole->InsertText(m_zepConsole->GetActiveBuffer()->End(), "\n");
	}

	bool GetLocalEcho() const { return m_localEcho; }

	void SetLocalEcho(bool localEcho)
	{
		m_localEcho = localEcho;
		WritePrivateProfileBool("Console", "LocalEcho", m_localEcho, internal_paths::MQini);
	}
};

#pragma endregion

//============================================================================

static ImGuiDockNodeFlags s_dockspace_flags = ImGuiDockNodeFlags_None
	| ImGuiDockNodeFlags_NoDockingOverCentralNode
	| ImGuiDockNodeFlags_PassthruCentralNode;

void DrawDockSpace(bool* p_open)
{
	ImGuiDockNodeFlags dockspace_flags = s_dockspace_flags;
	if (!s_dockspaceVisible)
	{
		dockspace_flags |= ImGuiDockNodeFlags_KeepAliveOnly;
	}

	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking;
	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->WorkPos);
	ImGui::SetNextWindowSize(viewport->WorkSize);
	ImGui::SetNextWindowViewport(viewport->ID);

	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("Hidden DockSpace Window", nullptr, window_flags);

	ImGui::PopStyleVar(3);

	// Submit the DockSpace
	ImGuiIO& io = ImGui::GetIO();

	s_dockspaceId = ImGui::GetID("Main DockSpace");
	ImGui::DockSpace(s_dockspaceId, ImVec2(0.0f, 0.0f), dockspace_flags);
	ImGui::End();
}

static void MakeColorGradient(float frequency1, float frequency2, float frequency3,
	float phase1, float phase2, float phase3,
	float center, float width, int length)
{
	if (!gMQConsole)
		return;

	char szBuffer[2048] = { 0 };

	for (int i = 1; i < length + 1; ++i)
	{
		ImU32 color = ImGui::ColorConvertFloat4ToU32(ImVec4(
			(sin(frequency1 * i + phase1) * width + center) / 255,
			(sin(frequency2 * i + phase2) * width + center) / 255,
			(sin(frequency3 * i + phase3) * width + center) / 255, 1.0));

		std::string test = fmt::format("\a#{:06x}x", (color & 0xffffff));
		strcat_s(szBuffer, test.c_str());

		if (i % 50 == 0)
		{
			WriteChatColor(szBuffer);
			szBuffer[0] = 0;
		}
	}

	WriteChatColor(szBuffer);
}

//----------------------------------------------------------------------------

void UpdateImGuiConsole()
{
	// Initialize dockspace first so other windows can utilize it.
	if (s_dockspaceVisible)
		DrawDockSpace(&s_dockspaceVisible);

	bool shouldSetFocusToMainViewport = false;

	if (gbSetConsoleVisibilityRequest)
	{
		if (gbSetConsoleVisibilityRequest.value() != s_consoleVisible)
			gbToggleConsoleRequested = true;

		gbSetConsoleVisibilityRequest.reset();
	}

	if (gbToggleConsoleRequested)
	{
		gbToggleConsoleRequested = false;

		s_consoleVisible = !s_consoleVisible;
		if (s_consoleVisible)
		{
			s_setFocus = true;
			shouldSetFocusToMainViewport = true;
		}
	}

	if (s_consoleVisible)
	{
		if (s_setFocus)
		{
			ImGui::SetNextWindowFocus();
		}

		ImGuiWindow* consoleWindow = ImGui::FindWindowByName("MacroQuest Console");
		ImGuiDockNode* dockspaceNode = ImGui::DockBuilderGetNode(s_dockspaceId);

		if ((s_resetConsolePosition || !consoleWindow) && dockspaceNode)
		{
			ImGuiDockNode* topNode = nullptr;

			if (dockspaceNode->IsSplitNode())
			{
				if (dockspaceNode->SplitAxis == ImGuiAxis_Y)
					topNode = dockspaceNode->ChildNodes[0];
				else
				{
					// Check central node?
					if (ImGuiDockNode* centralNode = ImGui::DockNodeGetRootNode(dockspaceNode)->CentralNode)
					{
						if (centralNode->IsSplitNode())
						{
							if (centralNode->SplitAxis == ImGuiAxis_Y)
								topNode = centralNode->ChildNodes[0];
						}
						else
						{
							ImGuiID topId;
							ImGui::DockBuilderSplitNode(centralNode->ID, ImGuiDir_Up, 0.30f, &topId, nullptr);
							topNode = ImGui::DockBuilderGetNode(topId);
						}
					}
				}

				// reset layout
				if (!topNode)
				{
					ImGui::DockBuilderRemoveNodeChildNodes(dockspaceNode->ID);
					ImGui::DockBuilderRemoveNodeDockedWindows(dockspaceNode->ID, true);
				}
			}

			if (!topNode)
			{
				ImGuiID topId;
				ImGui::DockBuilderSplitNode(dockspaceNode->ID, ImGuiDir_Up, 0.30f, &topId, nullptr);
				topNode = ImGui::DockBuilderGetNode(topId);
			}

			if (consoleWindow)
			{
				ImGui::SetWindowDock(consoleWindow, topNode->ID, ImGuiCond_Always);
				consoleWindow->DockOrder = -1;
			}
			else
			{
				ImGui::SetNextWindowDockID(topNode->ID, ImGuiCond_FirstUseEver);
			}

			ImGui::DockBuilderFinish(s_dockspaceId);
		}
		s_resetConsolePosition = false;

		gMQConsole->Draw(&s_consoleVisible);

		if (shouldSetFocusToMainViewport)
		{
			// activate main viewport in case it isn't currently in focus
			ImGuiViewport* mainViewport = ImGui::GetMainViewport();

			if (ImGui::GetCurrentWindowRead()->Viewport->ID != mainViewport->ID)
			{
				// Activate the main viewport window.
				::SetActiveWindow((HWND)mainViewport->PlatformHandle);
			}
		}
	}

	if (gbAutoDockspaceViewport)
	{
		if (auto node = ImGui::DockBuilderGetCentralNode(s_dockspaceId))
		{
			if (ImGuiWindow* hostWindow = node->HostWindow)
			{
				int sizeX = static_cast<int>(node->Size.x);
				int sizeY = static_cast<int>(node->Size.y);
				int posX = static_cast<int>(node->Pos.x);
				int posY = static_cast<int>(node->Pos.y);

				posX = posX - static_cast<int>(hostWindow->Pos.x);
				posY = posY - static_cast<int>(hostWindow->Pos.y);

				if (gbAutoDockspacePreserveRatio)
				{
					float heightRatio = static_cast<float>(pEverQuestInfo->ScreenYRes) / static_cast<float>(pEverQuestInfo->ScreenXRes);
					float widthRatio = 1.0f / heightRatio;

					if (sizeY * widthRatio <= sizeX)
					{
						sizeX = static_cast<int>(sizeY * widthRatio);
					}
					else if (sizeX * heightRatio <= sizeY)
					{
						sizeY = static_cast<int>(sizeX * heightRatio);
					}
				}

				pEverQuestInfo->Render_MinX = posX;
				pEverQuestInfo->Render_MinY = posY;

				pEverQuestInfo->Render_MaxX = posX + sizeX;
				pEverQuestInfo->Render_MaxY = posY + sizeY;

				pEverQuestInfo->Render_XScale = 0;
				pEverQuestInfo->Render_YScale = 0;
				pEverQuestInfo->Render_WidthScale = 0;
				pEverQuestInfo->Render_HeightScale = 0;
			}
		}
	}
}

void MQConsoleCommand(SPAWNINFO* pChar, char* Line)
{
	char szCommand[MAX_STRING] = { 0 };
	GetArg(szCommand, Line, 1);

	if (ci_equals("clear", szCommand))
	{
		if (gMQConsole != nullptr)
			gMQConsole->ClearLog();

		return;
	}

	if (ci_equals("toggle", szCommand))
	{
		gbToggleConsoleRequested = true;
		return;
	}

	if (ci_equals("show", szCommand))
	{
		gbSetConsoleVisibilityRequest = true;
		return;
	}

	if (ci_equals("hide", szCommand))
	{
		gbSetConsoleVisibilityRequest = false;
		return;
	}

	WriteChatf("Usage: /mqconsole [command]");
	WriteChatf("  Commands: clear, toggle, show, hide");
}

static void ConsoleSettings()
{
	if (ImGui::Checkbox("Show Console on Load", &s_consoleVisibleOnStartup))
	{
		WritePrivateProfileBool("MacroQuest", "ShowMacroQuestConsole", s_consoleVisibleOnStartup, mq::internal_paths::MQini);
	}

	ImGui::SameLine();
	mq::imgui::HelpMarker("This feature allows you to automatically show the MacroQuest Console upon load.");


	if (ImGui::Checkbox("Developer: Persistent Command History", &s_consolePersistentCommandHistory))
	{
		WritePrivateProfileBool("Console", "PersistentCommandHistory", s_consolePersistentCommandHistory, mq::internal_paths::MQini);
	}
	ImGui::SameLine();
	mq::imgui::HelpMarker("This feature stores commands between sessions. Use at your own risk.");

	ImGui::NewLine();

	if (gMQConsole != nullptr)
	{
		ImGui::Text("Maximum Number of Buffer Lines");

		int maxBufferLines = gMQConsole->m_zepConsole->GetMaxBufferLines();
		if (ImGui::InputInt("##BufferLineMaxEntry", &maxBufferLines))
		{
			WritePrivateProfileInt("Console", "MaxBufferLines", maxBufferLines, internal_paths::MQini);
			gMQConsole->m_zepConsole->SetMaxBufferLines(maxBufferLines);
		}

		ImGui::SameLine();
		mq::imgui::HelpMarker("Set the number of lines to keep in the scrollback buffer. Any lines above this amount will be deleted from the top of the buffer and won't be available for viewing in the console. Larger numbers here may cause performance issues like hitching or FPS slowdowns.");

		ImGui::NewLine();
	}

	if (ImGui::Button("Clear Saved Console Settings"))
	{
		s_consoleVisibleOnStartup = false;
		s_consolePersistentCommandHistory = false;
		WritePrivateProfileBool("MacroQuest", "ShowMacroQuestConsole", s_consoleVisibleOnStartup, mq::internal_paths::MQini);
		WritePrivateProfileBool("Console", "PersistentCommandHistory", s_consolePersistentCommandHistory, mq::internal_paths::MQini);
	}
}

void InitializeImGuiConsole()
{
	s_consoleVisibleOnStartup = GetPrivateProfileBool("MacroQuest", "ShowMacroQuestConsole", false, mq::internal_paths::MQini);
	s_consoleVisible = s_consoleVisibleOnStartup;
	s_consolePersistentCommandHistory = GetPrivateProfileBool("Console", "PersistentCommandHistory", false, mq::internal_paths::MQini);
	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "ShowMacroQuestConsole", s_consoleVisibleOnStartup, mq::internal_paths::MQini);
		WritePrivateProfileBool("Console", "PersistentCommandHistory", s_consolePersistentCommandHistory, mq::internal_paths::MQini);
	}

	AddSettingsPanel("Console", ConsoleSettings);

	gMQConsole = new MQConsole();
	AddCommand("/mqconsole", MQConsoleCommand);
}

void ShutdownImGuiConsole()
{
	delete gMQConsole;
	gMQConsole = nullptr;

	if (gbAutoDockspaceViewport)
	{
		ImGuiManager_ResetGameViewport();
	}

	RemoveSettingsPanel("Console");
	RemoveCommand("/mqconsole");
}

DWORD ImGuiConsoleAddText(const char* line, DWORD color, DWORD filter)
{
	MQColor col = GetColorForChatColor(color);

	if (gMQConsole)
		gMQConsole->AddWriteChatColorLog(line, col, true);

	return 0;
}

} // namespace mq
