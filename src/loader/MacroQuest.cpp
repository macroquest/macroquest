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

#include "loader/MacroQuest.h"
#include "loader/ProcessMonitor.h"
#include "loader/Crashpad.h"
#include "loader/PostOffice.h"
#include "loader/ImGui.h"
#include "loader/LoaderAutoLogin.h"
#include "login/AutoLogin.h"
#include "imgui/fonts/IconsFontAwesome.h"
#include "imgui/ImGuiUtils.h"
#include "mq/utils/Naming.h"
#include "mq/utils/OS.h"
#include "mq/base/BuildInfo.h"
#include "mq/base/Logging.h"
#include "mq/base/WString.h"
#include "loader/WinToastLib.h"

#include "resource.h"

#include <date/date.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/ringbuffer_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <extras/wil/Constants.h>
#include <wil/registry.h>
#include <wil/resource.h>
#include <filesystem>
#include <tuple>
#include <shellapi.h>
#include <fcntl.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <aclapi.h>
#include <sddl.h>

#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "Crypt32.lib")
#pragma comment(lib, "dbghelp.lib")
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "shlwapi.lib")

#ifdef ShellExecute
#undef ShellExecute
#endif

namespace fs = std::filesystem;
using namespace std::chrono_literals;

using namespace WinToastLib;

namespace LauncherImGui {
	bool HandleWndProc(HWND hWnd, uint32_t msg, uintptr_t wParam, intptr_t lParam);
}

HWND hMainWnd;
bool s_isElevated = false;

PROCESS_INFORMATION pInfo = { 0 };
STARTUPINFO sInfo = { 0 };
NOTIFYICONDATA NID = { 0 };
PAINTSTRUCT PS;

std::string ServerType;
char WinDir[_MAX_PATH] = { 0 };

uint32_t gNextWindowHotKey = 0;
uint32_t gPrevWindowHotKey = 0;
uint32_t gBossModeHotKey = 0;

bool gbAllEQWindowsHidden = false;
DWORD gLastEQGameSwitchedTo = 0;
HINSTANCE g_hInst = nullptr;

char gszWinClassName[64] = { 0 };
char gszWinName[64] = { 0 };

const int HOTKEY_EQWIN_PREVIOUS = 1;
const int HOTKEY_EQWIN_NEXT = 2;
const int HOTKEY_EQWIN_BOSSKEY = 3;

bool gbConsoleVisible = false;
bool gbConsoleCreated = false;
bool gCrashPadInitialized = false;

std::map<std::tuple<uint16_t, uint16_t>, HWND> hotkeyMap;
uint32_t gFocusProcessID = 0;

static std::set<uint32_t> s_processIds;

static uint32_t s_taskbarRestart = 0;

// Log cleanup settings
static uint32_t s_logCleanupMaxCount = 200;         // Default to only keeping a max of 200 log files
static uint32_t s_logCleanupMaxAgeDays = 14;        // Default to 14 days before deleting log files
static uint32_t s_logFileCleanupIntervalMins = 360; // Default to 6 hours between cleanings

static std::chrono::steady_clock::time_point s_lastLogFileCleanupRun;
static std::shared_ptr<spdlog::sinks::ringbuffer_sink_mt> s_ringBufferSink;
static std::shared_ptr<spdlog::sinks::wincolor_stdout_sink_mt> s_stdOutSink;
static bool s_dumpsPathOK = true;

//----------------------------------------------------------------------------

#pragma region Console & Logging

void InitializeConsole()
{
	if (gbConsoleCreated)
		return;
	if (!AllocConsole())
		return;

	// std::cout, std::clog, std::cerr, std::cin
	FILE* fDummy;
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	std::cout.clear();
	std::clog.clear();
	std::cerr.clear();
	std::cin.clear();

	SetConsoleCtrlHandler(nullptr, true);

	// set the screen buffer to be big enough to let us scroll text
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	::GetConsoleScreenBufferInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	coninfo.dwSize.Y = 500;
	::SetConsoleScreenBufferSize(::GetStdHandle(STD_OUTPUT_HANDLE), coninfo.dwSize);

	SetConsoleTitle("Debug Console");

	gbConsoleVisible = true;
	gbConsoleCreated = true;

	// create the std out logger.
	s_stdOutSink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();

	if (s_ringBufferSink)
	{
		// The logger already exists, so replace ring buffer sink with stdout sink.
		auto logger = spdlog::default_logger();
		
		// Erase the ring buffer sink from the logger's list of sinks.
		auto& sinks = logger->sinks();
		sinks.erase(std::remove_if(sinks.begin(), sinks.end(), [](const auto& sink) { return sink == s_ringBufferSink; }), sinks.end());
		sinks.push_back(s_stdOutSink);

		auto storedItems = s_ringBufferSink->last_raw();
		SPDLOG_INFO("Console opened, only showing {} most recent messages...", storedItems.size());

		for (const auto& item : storedItems)
		{
			if (s_stdOutSink->should_log(item.level))
				s_stdOutSink->log(item);
		}

		s_ringBufferSink.reset();
	}
}

void ShutdownConsole()
{
	if (!gbConsoleCreated)
		return;

	FreeConsole();

	gbConsoleVisible = false;
	gbConsoleCreated = false;
}

void HideConsole()
{
	if (gbConsoleCreated)
		ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void ShowConsole()
{
	if (!gbConsoleCreated)
		InitializeConsole();
	else
		ShowWindow(GetConsoleWindow(), SW_SHOW);
}

void UpdateShowConsole(bool showConsole, bool updateIni)
{
	if (showConsole != gbConsoleVisible)
	{
		if (showConsole)
			ShowConsole();
		else
			HideConsole();

		gbConsoleVisible = showConsole;

		if (updateIni)
			WritePrivateProfileBool("MacroQuest", "ShowLoaderConsole", showConsole, internal_paths::MQini);
	}
}

static void PerformLoggingCleanup()
{
	fs::path loggingPath = internal_paths::Logs;

	const auto durationCutoff = s_logCleanupMaxAgeDays * 24h;
	const size_t countCutoff = s_logCleanupMaxCount;

	static bool firstTime = true;

	try
	{
		fs::directory_iterator dirIter(loggingPath);
		fs::directory_iterator dirIterEnd;

		using file_clock = fs::file_time_type::clock;

		struct DirEntry
		{
			fs::path fileName;
			file_clock::time_point modifiedTime;

			DirEntry(const fs::path& fileName_, const file_clock::time_point& modifiedTime_)
				: fileName(fileName_), modifiedTime(modifiedTime_) {}
			DirEntry() = default;
		};

		std::vector<DirEntry> dirItems;
		std::vector<DirEntry> removeItems;
		auto file_time_now = file_clock::now();
		std::error_code ec;

		for (; dirIter != dirIterEnd; ++dirIter)
		{
			const auto& dirEntry = *dirIter;

			if (!dirEntry.is_regular_file(ec) || !ci_equals(dirEntry.path().extension().string(), ".log"))
			{
				continue;
			}

			// Check last modified time. If it is too old we purge.
			auto file_time = fs::last_write_time(dirEntry.path(), ec);

			if (s_logCleanupMaxAgeDays > 0 && file_time_now - file_time > durationCutoff)
			{
				removeItems.emplace_back(dirEntry.path(), file_time);
			}
			else
			{
				dirItems.emplace_back(dirEntry.path(), file_time);
			}
		}

		// Check if we need to remove log files based on total number remaining
		if (countCutoff > 0 && dirItems.size() > countCutoff)
		{
			// Sort by modified time descending.
			std::sort(std::begin(dirItems), std::end(dirItems), [&](const DirEntry& a, const DirEntry& b)
				{
					return a.modifiedTime > b.modifiedTime;
				});

			std::copy_n(std::begin(dirItems), dirItems.size() - countCutoff, std::back_inserter(removeItems));
		}

		if (firstTime && !removeItems.empty())
		{
			SPDLOG_INFO("Performing log file cleanup, found {} files to remove.", removeItems.size());
		}

		// Delete the entries selected for deletion
		for (const DirEntry& entry : removeItems)
		{
			try
			{
				SPDLOG_INFO("Removed {}", entry.fileName.string());
				fs::remove(entry.fileName);
			}
			catch (const std::exception& ex)
			{
				SPDLOG_WARN("Failed to remove log file: {} ({})", entry.fileName.string(), ex.what());
			}
		}
	}
	catch (const std::exception& exc)
	{
		SPDLOG_WARN("Exception occurred while performing log file cleanup: {}", exc.what());
	}

	firstTime = false;
}

static void CheckPruneLogging()
{
	using namespace std::chrono;

	if (s_logFileCleanupIntervalMins > 0)
	{
		auto now = steady_clock::now();
		if (now - s_lastLogFileCleanupRun > minutes(s_logFileCleanupIntervalMins))
		{
			s_lastLogFileCleanupRun = now;

			PerformLoggingCleanup();
		}
	}
}

void InitializeLogging()
{
	std::shared_ptr<spdlog::sinks::sink> baseSink;

	// If we don't have a stdout sink yet, create a ring buffer to hold messages in case we get one later.
	if (!s_stdOutSink)
	{
		s_ringBufferSink = std::make_shared<spdlog::sinks::ringbuffer_sink_mt>(20);
		baseSink = s_ringBufferSink;
	}
	else
	{
		baseSink = s_stdOutSink;
	}

	auto logger = std::make_shared<spdlog::logger>("MQ", baseSink);
	spdlog::details::registry::instance().initialize_logger(logger);
	spdlog::set_default_logger(logger);
	spdlog::flush_on(spdlog::level::trace);
	spdlog::set_level(spdlog::level::trace);

	if (IsDebuggerPresent())
	{
		logger->sinks().push_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
	}

	fmt::memory_buffer filename;
	auto out = fmt::format_to(fmt::appender(filename),
		"{}\\{}", internal_paths::Logs, mq::CreateLogFilename("MacroQuest-Launcher"));
	*out = 0;

	try
	{
		auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filename.data(), true);
		fileSink->set_pattern("%^%L %Y-%m-%d %T.%f%$ [%n] %v (%@)");

		logger->sinks().push_back(fileSink);
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		// Failed to create log file. How would we report this so early?
		SPDLOG_WARN("Failed to create file logger: {}, ex: {}", std::string_view(filename.data(), filename.size()), ex.what());
	}

	SPDLOG_DEBUG("Logging Initialized");
}

void ShowLoggingSettings()
{
	if (ImGui::Button("Open Logs Folder"))
	{
		ShellExecuteA(nullptr, "explore", internal_paths::Logs.c_str(), nullptr, nullptr, SW_SHOW);
	}

	ImGui::NewLine();

	ImGui::PushFont(mq::imgui::LargeTextFont);
	ImGui::Text("Logging Cleanup");
	ImGui::PopFont();
	ImGui::Separator();

	ImGui::TextWrapped("Logging cleanup will automatically delete old log files in the logs folder to avoid consuming excessive amounts of disk space.");
	ImGui::NewLine();

	using namespace std::chrono;

	using days = std::chrono::duration<int, std::ratio<1440 * 60>>;       // 1440 minutes in a day
	using weeks = std::chrono::duration<int, std::ratio<1440 * 60 * 7>>;
	using years = std::chrono::duration<int, std::ratio<1440 * 60 * 365>>;

	// Cleanup interval
	{
		static uint32_t lastLogFileCleanupIntervalMins = 0;
		static fmt::memory_buffer buffer;
		static bool init = false;

		if  (lastLogFileCleanupIntervalMins != s_logFileCleanupIntervalMins || !init)
		{
			lastLogFileCleanupIntervalMins = s_logFileCleanupIntervalMins;
			init = true;

			buffer.clear();
			auto buf = fmt::appender(buffer);

			if (lastLogFileCleanupIntervalMins <= 0)
			{
				fmt::format_to(fmt::appender(buffer), "Never");
				*buf = 0;
			}
			else
			{
				// Define durations for days, hours, and minutes
				auto minutes_duration = minutes(lastLogFileCleanupIntervalMins);
				auto hours_duration = duration_cast<hours>(minutes_duration);
				auto days_duration = duration_cast<days>(hours_duration);

				// Calculate remaining hours and minutes
				hours_duration -= days_duration;
				minutes_duration -= hours_duration;
				minutes_duration -= duration_cast<minutes>(days_duration);

				if (days_duration.count() > 0) {
					fmt::format_to(buf, "{} day{}", days_duration.count(), days_duration.count() != 1 ? "s " : "");
					if (hours_duration.count() > 0 || minutes_duration.count() > 0) {
						*buf = ' ';
					}
				}
				if (hours_duration.count() > 0) {
					fmt::format_to(buf, "{} hour{}", hours_duration.count(), hours_duration.count() != 1 ? "s " : "");
					if (minutes_duration.count() > 0) {
						*buf = ' ';
					}
				}
				if (minutes_duration.count() > 0) {
					fmt::format_to(buf, "{} minute{}", minutes_duration.count(), minutes_duration.count() != 1 ? "s" : "");
				}

				*buf = 0;
			}
		}

		constexpr uint32_t minValue = 0;
		constexpr uint32_t maxValue = 1440; // 1 day

		ImGui::SetNextItemWidth(200);

		if (ImGui::SliderScalar("Cleanup Frequency", ImGuiDataType_U32, &s_logFileCleanupIntervalMins, &minValue, &maxValue, buffer.data(),
			ImGuiSliderFlags_NoRoundToFormat))
		{
			WritePrivateProfileInt("MacroQuest", "LogCleanupIntervalMins", s_logFileCleanupIntervalMins, internal_paths::MQini);
		}
		ImGui::SameLine();
		mq::imgui::HelpMarker(
			"How often logging cleanup runs.\n\n"
			"Log file cleanup will occur on startup and then whenever this amount\n"
			"of time passes while the application is running.\n\n"
			"Set this to 0 to disable.");
	}

	// Log cleanup max days
	{
		static uint32_t lastMaxAgeDays = 0;
		static fmt::memory_buffer buffer;
		static bool init = false;

		if (lastMaxAgeDays != s_logCleanupMaxAgeDays || !init)
		{
			init = true;
			lastMaxAgeDays = s_logCleanupMaxAgeDays;

			buffer.clear();
			auto buf = fmt::appender(buffer);

			if (lastMaxAgeDays == 0)
			{
				fmt::format_to(buf, "Disabled");
			}
			else
			{
				// Define durations for days, hours, and minutes
				auto days_duration = days(lastMaxAgeDays);
				auto years_duration = duration_cast<years>(days_duration); // 365 days in a year
				auto weeks_duration = duration_cast<weeks>(days_duration - years_duration); // 7 days in a week

				// Calculate remaining hours and minutes
				auto remaining_days_duration = days_duration - years_duration - weeks_duration;

				if (years_duration.count() > 0)
				{
					fmt::format_to(buf, "{} year{}", years_duration.count(), years_duration.count() != 1 ? "s" : "");
					if (weeks_duration.count() > 0 || remaining_days_duration.count() > 0)
					{
						*buf = ' ';
					}
				}

				if (weeks_duration.count() > 0)
				{
					fmt::format_to(buf, "{} week{}", weeks_duration.count(), weeks_duration.count() != 1 ? "s" : "");
					if (days_duration.count() > 0)
					{
						*buf = ' ';
					}
				}

				if (remaining_days_duration.count() > 0)
				{
					fmt::format_to(buf, "{} day{}", remaining_days_duration.count(), remaining_days_duration.count() != 1 ? "s" : "");
				}
			}
			*buf = 0;
		}

		constexpr uint32_t minValue = 0;
		constexpr uint32_t maxValue = 365; // 1 year

		ImGui::SetNextItemWidth(200);

		if (ImGui::SliderScalar("How long to keep log files", ImGuiDataType_U32, &s_logCleanupMaxAgeDays, &minValue, &maxValue, buffer.data(),
			ImGuiSliderFlags_NoRoundToFormat | ImGuiSliderFlags_Logarithmic))
		{
			WritePrivateProfileInt("MacroQuest", "LogCleanupMaxAgeDays", s_logCleanupMaxAgeDays, internal_paths::MQini);
		}
		ImGui::SameLine();
		mq::imgui::HelpMarker(
			"Deletes log files that are older than this amount of time.\n\n"
			"Set this to 0 to disable deleting files by age.");
	}

	// Log clean max count
	{
		//s_logCleanupMaxCount

		static uint32_t lastMaxCount = 0;
		static fmt::memory_buffer buffer;
		static bool init = false;

		if (lastMaxCount != s_logCleanupMaxCount || !init)
		{
			init = true;
			lastMaxCount = s_logCleanupMaxCount;

			buffer.clear();
			auto buf = fmt::appender(buffer);

			if (lastMaxCount == 0)
			{
				fmt::format_to(buf, "Disabled");
			}
			else
			{
				fmt::format_to(buf, "{}", lastMaxCount);
			}
			*buf = 0;
		}

		constexpr uint32_t minValue = 0;
		constexpr uint32_t maxValue = 10000;

		ImGui::SetNextItemWidth(200);
		if (ImGui::SliderScalar("How many log files to keep", ImGuiDataType_U32, &s_logCleanupMaxCount, &minValue, &maxValue, buffer.data(),
			ImGuiSliderFlags_NoRoundToFormat))
		{
			WritePrivateProfileInt("MacroQuest", "LogCleanupMaxCount", s_logCleanupMaxCount, internal_paths::MQini);
		}
		ImGui::SameLine();
		mq::imgui::HelpMarker(
			"Deletes old log files until only this amount remain.\n\n"
			"Set to 0 to disable this deleting by count.");
	}

	if (ImGui::Button("Run Cleanup Now"))
	{
		PerformLoggingCleanup();
	}
}

#pragma endregion

#pragma region Paths and Configuration

std::string internal_paths::MQRoot = ".";
std::string internal_paths::Config = "Config";
std::string internal_paths::MQini = internal_paths::Config + "\\MacroQuest.ini";
std::string internal_paths::Macros = "Macros";
std::string internal_paths::Logs = "Logs";
std::string internal_paths::CrashDumps = internal_paths::Logs + "\\Dumps";
std::string internal_paths::Plugins = "Plugins";
std::string internal_paths::Resources = "Resources";

bool InitializeDirectory(std::string& strPathToInit,
	const std::string& iniKey, const std::string& iniFile,
	const fs::path& appendPathIfRelative = internal_paths::MQRoot)
{
	fs::path pathToInit =
		GetPrivateProfileString("MacroQuest", iniKey, strPathToInit, iniFile);

	if (pathToInit.is_relative())
	{
		pathToInit = fs::absolute(appendPathIfRelative / pathToInit);
	}

	strPathToInit = pathToInit.string();

	std::error_code ec_fs;

	if (fs::exists(pathToInit, ec_fs) || fs::create_directories(pathToInit, ec_fs))
	{
		return true;
	}

	const std::string strTemp = "Could not find or create " + iniKey + " path: " + strPathToInit;
	MessageBox(nullptr, strTemp.c_str(), "MacroQuest", MB_OK);
	return false;
}

bool InitializePaths()
{
	// Get path right to the exe and then strip off the filename.
	char szFileName[_MAX_PATH] = { 0 };
	::GetModuleFileNameA(nullptr, szFileName, _MAX_PATH);

	char* szProcessName = strrchr(szFileName, '\\');
	*szProcessName = 0;

	internal_paths::MQRoot = szFileName;

	// Initialize the MacroQuest.ini and read in paths preferences, if any

	fs::path pathMQRoot = internal_paths::MQRoot;

	// If we still have a relative path to the MQ2 directory, make it absolute.
	if (pathMQRoot.is_relative())
	{
		pathMQRoot = fs::absolute(pathMQRoot).string();
	}

	internal_paths::MQRoot = pathMQRoot.string();
	std::error_code ec;

	// If the path to MQ2 doesn't exist none of our relative paths are going to work.
	if (fs::exists(pathMQRoot, ec))
	{
		internal_paths::MQini = GetCreateMacroQuestIni(pathMQRoot, internal_paths::Config, internal_paths::MQini);

		// Init the Config directory based on the ini we found.
		if (InitializeDirectory(internal_paths::Config, "ConfigPath", internal_paths::MQini, internal_paths::MQRoot))
		{
			// Initialize the rest
			if (InitializeDirectory(internal_paths::Macros, "MacroPath", internal_paths::MQini, internal_paths::MQRoot)
				&& InitializeDirectory(internal_paths::Logs, "LogPath", internal_paths::MQini, internal_paths::MQRoot)
				&& InitializeDirectory(internal_paths::CrashDumps, "CrashDumpPath", internal_paths::MQini, internal_paths::MQRoot)
				&& InitializeDirectory(internal_paths::Plugins, "PluginPath", internal_paths::MQini, internal_paths::MQRoot)
				&& InitializeDirectory(internal_paths::Resources, "ResourcePath", internal_paths::MQini, internal_paths::MQRoot))
			{
				return true;
			}
		}
	}

	return false;
}

#pragma endregion

//----------------------------------------------------------------------------

void SetFocusWindowPID(uint32_t pid, bool state)
{
	if (state)
	{
		gFocusProcessID = pid;
		SPDLOG_TRACE("Process has focus: {}", gFocusProcessID);
	}
	else if (pid == gFocusProcessID)
	{
		SPDLOG_TRACE("Process no longer has focus: {}", gFocusProcessID);
		gFocusProcessID = 0;
	}
}

void SetForegroundWindowInternal(HWND hWnd)
{
	if (IsWindow(hWnd))
	{
		if (IsIconic(hWnd))
			ShowWindow(hWnd, SW_RESTORE);

		if (!::SetForegroundWindow(hWnd) && !SendSetForegroundWindow(hWnd, gFocusProcessID))
		{
			SPDLOG_DEBUG("Failed to set foreground window. Doing it with min/restore.");

			ShowWindow(hWnd, SW_MINIMIZE);
			ShowWindow(hWnd, SW_RESTORE);
		}
	}
}

void OnProcessAdded(uint32_t processId)
{
	s_processIds.insert(processId);
	Inject(processId);
}

void OnProcessRemoved(uint32_t processId)
{
	AutoLoginRemoveProcess(processId);
	s_processIds.erase(processId);
}

LRESULT HandleHotkey(WPARAM wParam, LPARAM lParam)
{
	if ((wParam == HOTKEY_EQWIN_NEXT && lParam == gNextWindowHotKey) ||
		(wParam == HOTKEY_EQWIN_PREVIOUS && lParam == gPrevWindowHotKey))
	{
		HWND hWindow = nullptr;
		int retryCount = 0;

		do
		{
			// Switch to the next or previous EQ window
			auto eqGames = GetAllEqGameSessions();
			if (eqGames.empty())
			{
				gLastEQGameSwitchedTo = 0;
				return 0;
			}

			if (gLastEQGameSwitchedTo == 0)
			{
				gLastEQGameSwitchedTo = eqGames[0];
			}
			else
			{
				// find what the next EQWindow should be
				if (wParam == HOTKEY_EQWIN_PREVIOUS)
					std::reverse(std::begin(eqGames), std::end(eqGames));

				// Find the current window
				auto iter = std::find(std::begin(eqGames), std::end(eqGames), gLastEQGameSwitchedTo);
				if (iter != std::end(eqGames))
					iter++;
				if (iter == std::end(eqGames))
				{
					iter = std::begin(eqGames);
				}

				gLastEQGameSwitchedTo = *iter;
			}

			hWindow = GetEQWindowHandleForProcessId(gLastEQGameSwitchedTo);
		} while (hWindow == nullptr && retryCount++ < 3); // If window isn't found for process, try again.

		if (hWindow != nullptr)
		{
			SetForegroundWindowInternal(hWindow);
		}
	}
	else if (wParam == HOTKEY_EQWIN_BOSSKEY)
	{
		if (lParam == gBossModeHotKey)
		{
			gbAllEQWindowsHidden = !gbAllEQWindowsHidden;

			auto eqWnds = GetEQWindowHandles();
			for (HWND hWnd : eqWnds)
			{
				ShowWindow(hWnd, gbAllEQWindowsHidden ? SW_HIDE : SW_SHOW);
			}
		}
	}
	else
	{
		// check if it is a profile hotkey.
		HWND hWndFG = GetForegroundWindow();

		if (HWND hWndHotkey = LocateHotkeyWindow(LOWORD(lParam), HIWORD(lParam)))
		{
			if (hWndHotkey != hWndFG)
				SetForegroundWindowInternal(hWndHotkey);
		}
	}

	return 0;
}

void CheckMQ2MainUpdate(bool alwaysDisplay = false)
{
#ifdef MQ_UPDATE_URL
	const std::string local_version = GetVersionStringLocal("./MQ2Main.dll");
	const std::string remote_version = GetVersionStringRemote(MQ_UPDATE_URL);
	std::string strMessage = "No updates available.\n\nCurrent Version: ";
	int iMessageType = MB_OK;
	// If the return is FAILED or contains a web page (account for cloudflare outages)
	if (remote_version == "FAILED" || remote_version.find('<') != std::string::npos || remote_version.find('>') != std::string::npos)
	{
		strMessage = "Failed to retrieve remote version information";
		iMessageType |= MB_ICONERROR;
	}
	else if (local_version == "FAILED")
	{
		strMessage = "Failed to retrieve local version information";
		iMessageType |= MB_ICONERROR;
	}
	else if (remote_version == local_version)
	{
		strMessage.append(local_version);
		iMessageType |= MB_ICONINFORMATION;
	}
	else
	{
		strMessage = "UPDATE AVAILABLE!\n\nYou are running version: ";
		strMessage.append(local_version);
		strMessage.append("\n\nCurrent latest version: ");
		strMessage.append(remote_version);
		iMessageType |= MB_ICONWARNING;
	}
	if (alwaysDisplay || !(iMessageType & MB_ICONINFORMATION))
	{
		ThreadedMessage(strMessage,  iMessageType);
	}
#endif
}

// https://docs.microsoft.com/en-us/windows/win32/api/wow64apiset/nf-wow64apiset-iswow64process
bool IsWow64()
{
	typedef BOOL (WINAPI* LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	BOOL bIsWow64 = false;

    //IsWow64Process is not available on all supported versions of Windows.
    //Use GetModuleHandle to get a handle to the DLL that contains the function
    //and GetProcAddress to get a pointer to the function if available.

    const LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

    if(nullptr != fnIsWow64Process)
    {
        if (!fnIsWow64Process(GetCurrentProcess(), &bIsWow64))
        {
            //handle error (but I'm not going to)
        }
    }
    return bIsWow64;
}

enum AppCompatFlagReturn {
	SUCCESS = 0,
	ERROR_GENERAL = -1,
	ERROR_NOLAYERS = -2,
	ERROR_ENUMERATION = -3,
};

int CheckAppCompatFlags(HKEY RegBase, const std::vector<std::string>& SearchItems, bool crossCheck = false)
{
	// if there are no search items, there is nothing to search.
	if (SearchItems.empty())
	{
		return AppCompatFlagReturn::SUCCESS;
	}

	HKEY hRegKey;

	int retVal = AppCompatFlagReturn::ERROR_GENERAL;
	// Check the parent registry key first, if this is missing there's an issue (permissions, manual intervention)
	// crossCheck should actually flip archs, but since we always build in 32 bit there's no reason to do it the other direction
	if (RegOpenKeyEx(RegBase, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags", 0, crossCheck ? KEY_READ|KEY_WOW64_64KEY : KEY_READ, &hRegKey) == ERROR_SUCCESS)
	{
		// Now we can check the full key
		if (RegOpenKeyEx(RegBase, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers", 0, crossCheck ? KEY_READ | KEY_WOW64_64KEY : KEY_READ, &hRegKey) != ERROR_SUCCESS)
		{
			retVal = AppCompatFlagReturn::ERROR_NOLAYERS;
		}
		else
		{
			DWORD n = 0;
			if (RegQueryInfoKey(hRegKey, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &n, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS)
			{
				retVal = AppCompatFlagReturn::SUCCESS;
				for (DWORD i = 0; i < n; ++i)
				{
					char value[wil::max_registry_value_name_length + 1] = { 0 };
					DWORD valueSize = wil::max_registry_value_name_length;
					// We know we're done on the first error since they're sequential
					if (const int res = RegEnumValue(hRegKey, i, value, &valueSize, nullptr, nullptr, nullptr, nullptr) != ERROR_SUCCESS)
					{
						if (res != ERROR_NO_MORE_ITEMS)
						{
							retVal = AppCompatFlagReturn::ERROR_ENUMERATION;
						}
						break;
					}

					for (const std::string& searchItem : SearchItems)
					{
						// If it's in the name value, we don't need to check the data (only valid for exe, but it's fast)
						if (ci_find_substr(value, searchItem) != -1)
						{
							retVal++;
						}
						else
						{
							char data[wil::max_registry_value_name_length + 1] = { 0 };
							DWORD dataSize = wil::max_registry_value_name_length;
							if (RegGetValue(hRegKey, nullptr, value, RRF_RT_REG_SZ, nullptr, data, &dataSize) == ERROR_SUCCESS)
							{
								if (ci_find_substr(value, searchItem) != -1)
								{
									retVal++;
								}
							}
						}
					}
				}
			}
			RegCloseKey(hRegKey);
		}
	}
	return retVal;
}

void CheckAppCompat(bool alwaysDisplay = false)
{
	std::string searchPaths[] = { internal_paths::MQRoot, internal_paths::Plugins };
	std::string searchExtensions[] = { ".dll" };

	std::vector<std::string> checkFor;

	std::error_code ec;
	for (const std::string& searchPath : searchPaths)
	{
		if (std::filesystem::exists(searchPath, ec))
		{
			for (const auto& file : std::filesystem::directory_iterator(searchPath))
			{
				if (is_regular_file(file, ec) && file.path().has_extension())
				{
					std::filesystem::path filePath =  file.path();
					for (const std::string& searchExtension : searchExtensions)
					{
						if (ci_equals(filePath.extension().string(), searchExtension))
						{
							checkFor.push_back(filePath.filename().string());
						}
					}
				}
			}
		}
	}

	int iMessageType = MB_OK;

	std::string strMessage = "No Application Compatibility Layer issues found.";

	bool crossCheck = IsWow64();
	int foundHKLM = CheckAppCompatFlags(HKEY_LOCAL_MACHINE, checkFor);
	if (foundHKLM == AppCompatFlagReturn::SUCCESS && crossCheck)
	{
		foundHKLM = CheckAppCompatFlags(HKEY_LOCAL_MACHINE, checkFor, true);
	}

	int foundHKCU = CheckAppCompatFlags(HKEY_CURRENT_USER, checkFor);
	if (foundHKCU == AppCompatFlagReturn::SUCCESS && crossCheck)
	{
		foundHKCU = CheckAppCompatFlags(HKEY_CURRENT_USER, checkFor, true);
	}

	// For now, ignore issues with the NO_LAYERS return.  Future work might be to include it and have an option to display it based on verbosity or check the actual returns to determine what to display here
	if (foundHKLM != AppCompatFlagReturn::SUCCESS && foundHKLM != AppCompatFlagReturn::ERROR_NOLAYERS || foundHKCU != AppCompatFlagReturn::SUCCESS && foundHKCU != AppCompatFlagReturn::ERROR_NOLAYERS)
	{
		strMessage = "Application Compatibility Layer issues found:\n";
		iMessageType |= MB_ICONWARNING;

		if (foundHKLM < 0)
		{
			strMessage += fmt::format("\nError accessing values in HKEY_LOCAL_MACHINE: {}", foundHKLM);
			iMessageType = MB_OK | MB_ICONERROR;
		}
		else if (foundHKLM > 0)
		{
			strMessage += fmt::format("\nFound {} issue{} in HKEY_LOCAL_MACHINE.", foundHKLM, foundHKLM > 1 ? "s" : "");
		}

		if (foundHKCU < 0)
		{
			strMessage += fmt::format("\nError accessing values in HKEY_CURRENT_USER: {}", foundHKCU);
		}
		else if (foundHKCU > 0)
		{
			strMessage += fmt::format("\nFound {} issue{} in HKEY_CURRENT_USER.", foundHKCU, foundHKCU > 1 ? "s" : "");
			iMessageType = MB_OK | MB_ICONERROR;
		}
	}
	else
	{
		iMessageType |= MB_ICONINFORMATION;
	}

	if (alwaysDisplay || !(iMessageType & MB_ICONINFORMATION))
	{
		ThreadedMessage(strMessage, iMessageType);
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT MSG, WPARAM wParam, LPARAM lParam)
{
	if (LauncherImGui::HandleWndProc(hWnd, MSG, wParam, lParam))
		return true;

	switch (MSG)
	{
	case WM_HOTKEY:
		return HandleHotkey(wParam, lParam);

	case WM_WINDOWPOSCHANGING:
		Shell_NotifyIcon(NIM_ADD, &NID); //Add the systray icon.
		break;

	case WM_SIZE:
		Shell_NotifyIcon(NIM_ADD, &NID); //Add the systray icon.
		break;

	case WM_SYSCOMMAND:
		switch (LOWORD(wParam)) // We capture the 'X' button
		{
		case SC_CLOSE:
			Shell_NotifyIcon(NIM_ADD, &NID);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_USER_PROCESS_ADDED:
		OnProcessAdded(static_cast<uint32_t>(wParam));
		break;

	case WM_USER_PROCESS_REMOVED:
		OnProcessRemoved(static_cast<uint32_t>(wParam));
		break;

	case WM_USER_HOTKEY_ADD:
	{
		uint16_t modkey = static_cast<uint16_t>(wParam);
		uint16_t hotkey = static_cast<uint16_t>(lParam);
		RegisterHotKey(hMainWnd, MAKELONG(modkey, hotkey), modkey, hotkey);
		break;
	}

	case WM_USER_HOTKEY_REMOVE:
	{
		uint16_t modkey = static_cast<uint16_t>(wParam);
		uint16_t hotkey = static_cast<uint16_t>(lParam);
		UnregisterHotKey(hMainWnd, MAKELONG(modkey, hotkey));
		break;
	}

	default:
		if (MSG == NID.uCallbackMessage) // This is where we get our SysTray Icon notifications.
		{
			switch (lParam)
			{
			case WM_LBUTTONUP:
				LauncherImGui::OpenMainWindow();
				break;

			case WM_RBUTTONUP:
				LauncherImGui::OpenContextMenu();
				break;
			}
			break;
		}
		if (MSG == s_taskbarRestart)
		{
			Shell_NotifyIcon(NIM_ADD, &NID);
		}
	}

	return DefWindowProc(hWnd, MSG, wParam, lParam);
}

static void AddUnderline(ImColor color)
{
	ImVec2 min = ImGui::GetItemRectMin();
	ImVec2 max = ImGui::GetItemRectMax();
	min.y = max.y;
	ImGui::GetWindowDrawList()->AddLine(min, max, color, 1.f);
}

static void DrawTextLink(const std::string& label, const std::string& url)
{
	ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered]);
	ImGui::Text(label.c_str());
	ImGui::PopStyleColor();

	if (ImGui::IsItemHovered())
	{
		if (ImGui::IsMouseClicked(ImGuiMouseButton_Left))
		{
			ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOW);
		}
		AddUnderline(ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered]);
		ImGui::SetTooltip(ICON_FA_LINK " Open in default browser\n%s", url.c_str());
	}
	else
	{
		AddUnderline(ImGui::GetStyle().Colors[ImGuiCol_Button]);
	}
}

void ShowMacroQuestInfo()
{
	ImGui::Spacing();
	if (mq::imgui::LargeTextFont != nullptr) ImGui::PushFont(mq::imgui::LargeTextFont);
	ImGui::Text("MacroQuest Useful Links");
	if (mq::imgui::LargeTextFont != nullptr) ImGui::PopFont();
	ImGui::Separator();
	ImGui::Spacing();

	ImGui::Bullet(); DrawTextLink("MacroQuest Website", "https://macroquest.org");
	ImGui::Bullet(); DrawTextLink("MacroQuest Documentation", "https://docs.macroquest.org/");
	ImGui::Bullet(); DrawTextLink("MacroQuest on GitHub", "https://github.com/macroquest/macroquest");
}

struct PidInfo
{
	const LoginInstance* inst;
	const std::string* key;
	bool running = false;
};


void ShowProcessInfo()
{
	auto& loadedInstances = GetLoadedInstances();

	std::map<uint32_t, PidInfo> pidInstances;

	for (uint32_t pid : s_processIds)
	{
		pidInstances[pid] = { nullptr, nullptr, true };
	}

	for (auto& [key, inst] : loadedInstances)
	{
		pidInstances[inst.PID] = { &inst, &key, pidInstances[inst.PID].running };
	}

	if (ImGui::BeginTable("##ProcessList", 7, ImGuiTableFlags_Resizable))
	{
		ImGui::TableSetupColumn("PID", ImGuiTableColumnFlags_WidthFixed);
		ImGui::TableSetupColumn("Running", ImGuiTableColumnFlags_WidthFixed);
		ImGui::TableSetupColumn("Key", ImGuiTableColumnFlags_WidthFixed);
		ImGui::TableSetupColumn("Server", ImGuiTableColumnFlags_WidthFixed);
		ImGui::TableSetupColumn("Character", ImGuiTableColumnFlags_WidthFixed);
		ImGui::TableSetupColumn("Profile Grp", ImGuiTableColumnFlags_WidthFixed);
		ImGui::TableSetupColumn("Hotkey", ImGuiTableColumnFlags_WidthFixed);
		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableHeadersRow();

		for (auto& [pid, info] : pidInstances)
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			ImGui::Text("%d", pid);

			ImGui::TableNextColumn();
			ImGui::Text("%s", info.running ? "Yes" : "No");

			ImGui::TableNextColumn();
			ImGui::Text("%s", info.key ? info.key->c_str() : "(none)");

			if (info.inst)
			{
				ImGui::TableNextColumn();
				ImGui::Text("%s", info.inst->Server.c_str());

				ImGui::TableNextColumn();
				ImGui::Text("%s", info.inst->Character.c_str());

				ImGui::TableNextColumn();
				ImGui::Text("%s", info.inst->ProfileGroup.value_or("").c_str());

				ImGui::TableNextColumn();
				ImGui::Text("%s", info.inst->Hotkey.value_or("").c_str());
			}
		}

		ImGui::EndTable();
	}
}

void ShowMacroQuestMenu()
{
	if (ImGui::BeginMenu("Open Folder"))
	{
		if (ImGui::MenuItem("MacroQuest Root"))
			ShellExecuteA(nullptr, "explore", internal_paths::MQRoot.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Config"))
			ShellExecuteA(nullptr, "explore", internal_paths::Config.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Macros"))
			ShellExecuteA(nullptr, "explore", internal_paths::Macros.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Resources"))
			ShellExecuteA(nullptr, "explore", internal_paths::Resources.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Logs"))
			ShellExecuteA(nullptr, "explore", internal_paths::Logs.c_str(), nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Crash Dumps"))
			ShellExecuteA(nullptr, "explore", internal_paths::CrashDumps.c_str(), nullptr, nullptr, SW_SHOW);

		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("MQ Sites"))
	{
		if (ImGui::MenuItem("GitHub"))
			ShellExecuteA(nullptr, "open", "https://github.com/macroquest/macroquest", nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Issue Tracker"))
			ShellExecuteA(nullptr, "open", "https://github.com/macroquest/macroquest/issues", nullptr, nullptr, SW_SHOW);

		ImGui::Separator();

		if (ImGui::MenuItem("Website"))
			ShellExecuteA(nullptr, "open", "https://macroquest.org", nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Forums"))
			ShellExecuteA(nullptr, "open", "https://macroquest.org/phpBB3", nullptr, nullptr, SW_SHOW);
		if (ImGui::MenuItem("Wiki"))
			ShellExecuteA(nullptr, "open", "https://docs.macroquest.org", nullptr, nullptr, SW_SHOW);

		ImGui::EndMenu();
	}

	if (ImGui::MenuItem("Change Log"))
	{
		// NOTE: This change log search logic is duplicated in the news feed in MQ2Main.cpp
		// This is one of the few places we want to hardcode the path since if the user redirects their resources we would not have distributed that file and they would always have old news.
		const std::filesystem::path pathMQRootChangeLog = std::filesystem::path(internal_paths::MQRoot) / "resources" / "CHANGELOG.md";
		const std::filesystem::path pathResourceChangeLog = std::filesystem::path(internal_paths::Resources) / "CHANGELOG.md";
		// Default to the one in the resource path.
		std::filesystem::path pathChangeLog = pathResourceChangeLog;

		std::error_code ec;
		// If the paths are different, and the Resource Change Log doesn't exist or is older than the Root\Resource changelog
		if (pathMQRootChangeLog != pathResourceChangeLog
			&& (!exists(pathResourceChangeLog, ec)
				|| last_write_time(pathMQRootChangeLog, ec) > last_write_time(pathResourceChangeLog, ec)))
		{
			pathChangeLog = pathMQRootChangeLog;
		}
		// END Duplicate logic

		if (exists(pathChangeLog))
		{
			ShellExecuteA(nullptr, "open", pathChangeLog.string().c_str(), nullptr, nullptr, SW_SHOW);
		}
		else
		{
			LauncherImGui::OpenMessageBox(nullptr, fmt::format("Could not find CHANGELOG.md: {}", pathChangeLog.string()), "View Changelog");
		}
	}

	if (ImGui::MenuItem("INI File"))
		ShellExecuteA(nullptr, "open", internal_paths::MQini.c_str(), nullptr, internal_paths::MQRoot.c_str(), SW_SHOW);
}

void ShowEQBCMenu()
{
	if (ImGui::MenuItem("Start EQBC Server"))
	{
		if (IsProcessRunning("eqbcs.exe"))
		{
			LauncherImGui::OpenMessageBox(nullptr, "EQBCS is already running.", "EQBCS Launcher");
		}
		else
		{
			std::string strCommandLine = fmt::format("{}\\eqbcs.exe", internal_paths::MQRoot);
			std::error_code ec;
			if (std::filesystem::exists(strCommandLine, ec))
			{
				ShellExecuteA(nullptr, "open", strCommandLine.c_str(), nullptr, internal_paths::MQRoot.c_str(), SW_SHOW);
			}
			else
			{
				LauncherImGui::OpenMessageBox(nullptr, fmt::format("EQBCS could not be found: {}", strCommandLine), "EQBCS Launcher");
			}
		}
	}
}

void ShowAdvancedMenu()
{
	if (ImGui::BeginMenu("Advanced"))
	{
		if (ImGui::MenuItem("Toggle Debug Console"))
			UpdateShowConsole(!gbConsoleVisible, true);

		if (ImGui::MenuItem("Unload All Instances"))
			SendUnloadAllCommand();

		if (ImGui::MenuItem("Unload All Instances (Forced)"))
			SendForceUnloadAllCommand();

		if (ImGui::MenuItem("Check App Compatibility"))
			CheckAppCompat(true);

		ImGui::EndMenu();
	}

	if (ImGui::MenuItem("Refresh Injections"))
		RefreshInjections();
}

void InitializeWindows()
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.lpszClassName = gszWinClassName;
	wc.lpszMenuName = nullptr;
	wc.hInstance = g_hInst;
	RegisterClass(&wc);

	hMainWnd = ::CreateWindowA(gszWinClassName, gszWinName, WS_OVERLAPPEDWINDOW, 0, 0,
		GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN),
		nullptr, nullptr, g_hInst, nullptr);

	::SendMessageA(hMainWnd, WM_SETICON, ICON_SMALL, (LPARAM)::LoadIconA(g_hInst, MAKEINTRESOURCE(IDI_ICON1)));

	NID.cbSize = sizeof(NID);
	NID.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_ICON1));
	NID.uCallbackMessage = WM_USER_SHELLNOTIFY_CALLBACK;
	NID.hWnd = hMainWnd;
	NID.uID = WM_USER_SYSTRAY;
	NID.uFlags = NIF_TIP | NIF_ICON | NIF_MESSAGE;
	Shell_NotifyIcon(NIM_ADD, &NID);

	s_taskbarRestart = ::RegisterWindowMessageW(L"TaskbarCreated");

	LauncherImGui::AddMainPanel("Crash Reporting", ShowCrashReportingPanel);
	LauncherImGui::AddMainPanel("MacroQuest Info", ShowMacroQuestInfo);
	LauncherImGui::AddMainPanel("Logging", ShowLoggingSettings);
	LauncherImGui::AddMainPanel("Processes", ShowProcessInfo);
	LauncherImGui::AddContextGroup("##MacroQuest", ShowMacroQuestMenu);
}

class MQ2ProcessMonitorEvents : public ProcessMonitorEvents
{
public:
	virtual void HandleProcessCreation(uint32_t processId) override
	{
		SPDLOG_INFO("New process detected: {}", processId);
		::SendMessageA(hMainWnd, WM_USER_PROCESS_ADDED, processId, 0);
	}

	virtual void HandleProcessDestruction(uint32_t processId) override
	{
		SPDLOG_DEBUG("Process closed: {}", processId);
		::SendMessageA(hMainWnd, WM_USER_PROCESS_REMOVED, processId, 0);
	}
};

void InitializeVersionInfo()
{
	std::string injectee = GetInjecteePath();
	SPDLOG_INFO("MQ2Main Path: {0}", injectee);

	wil::unique_hmodule hModule(::LoadLibraryA(injectee.c_str()));
	if (!hModule.is_valid())
	{
		SPDLOG_WARN("MQ2Main was not loadable at startup. This might cause issues later");
		return;
	}

	char* szVersion = (char*)GetProcAddress(hModule.get(), "gszVersion");
	if (!szVersion)
	{
		SPDLOG_WARN("Failed to get version from MQ2Main at startup. This may cause issues later");
		return;
	}

	ServerType = GetBuildTargetName(
		static_cast<BuildTarget>(*reinterpret_cast<int*>(GetProcAddress(hModule.get(), "gBuild"))));

	fmt::format_to(NID.szTip, "{}{} [{} ({})]\0", gszWinName, s_isElevated ? " (Elevated)" : "", szVersion, ServerType);
	SPDLOG_INFO("Build: {0}", NID.szTip);

	to_lower(ServerType);
}

//------------------------------------------------------------------------------------------------------
// Gross block of COM code to make this launch de-elevated

HRESULT GetShellViewForDesktop(REFIID riid, void** ppv)
{
	*ppv = NULL;

	IShellWindows* psw;
	HRESULT hr = CoCreateInstance(CLSID_ShellWindows, NULL, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&psw));
	if (SUCCEEDED(hr))
	{
		HWND hwnd;
		IDispatch* pdisp;
		VARIANT vEmpty = {}; // VT_EMPTY
		if (S_OK == psw->FindWindowSW(&vEmpty, &vEmpty, SWC_DESKTOP, (long*)&hwnd, SWFO_NEEDDISPATCH, &pdisp))
		{
			IShellBrowser* psb;
			hr = IUnknown_QueryService(pdisp, SID_STopLevelBrowser, IID_PPV_ARGS(&psb));
			if (SUCCEEDED(hr))
			{
				IShellView* psv;
				hr = psb->QueryActiveShellView(&psv);
				if (SUCCEEDED(hr))
				{
					hr = psv->QueryInterface(riid, ppv);
					psv->Release();
				}
				psb->Release();
			}
			pdisp->Release();
		}
		else
		{
			hr = E_FAIL;
		}
		psw->Release();
	}
	return hr;
}

// From a shell view object gets its automation interface and from that gets the shell
// application object that implements IShellDispatch2 and related interfaces.

HRESULT GetShellDispatchFromView(IShellView* psv, REFIID riid, void** ppv)
{
	*ppv = NULL;

	IDispatch* pdispBackground;
	HRESULT hr = psv->GetItemObject(SVGIO_BACKGROUND, IID_PPV_ARGS(&pdispBackground));
	if (SUCCEEDED(hr))
	{
		IShellFolderViewDual* psfvd;
		hr = pdispBackground->QueryInterface(IID_PPV_ARGS(&psfvd));
		if (SUCCEEDED(hr))
		{
			IDispatch* pdisp;
			hr = psfvd->get_Application(&pdisp);
			if (SUCCEEDED(hr))
			{
				hr = pdisp->QueryInterface(riid, ppv);
				pdisp->Release();
			}
			psfvd->Release();
		}
		pdispBackground->Release();
	}
	return hr;
}

bool ShellExecInExplorerProcess(PCWSTR pszFile, PCWSTR pszArgs, PCWSTR pszDir)
{
	IShellView* psv;
	HRESULT hr = GetShellViewForDesktop(IID_PPV_ARGS(&psv));
	if (SUCCEEDED(hr))
	{
		IShellDispatch2* psd;
		hr = GetShellDispatchFromView(psv, IID_PPV_ARGS(&psd));
		if (SUCCEEDED(hr))
		{
			BSTR bstrFile = SysAllocString(pszFile);
			VARIANT vtArgs = {};
			vtArgs.bstrVal = SysAllocString(pszArgs);
			vtArgs.vt = VT_BSTR;
			VARIANT vtDir = {};
			vtDir.bstrVal = SysAllocString(pszDir);
			vtDir.vt = VT_BSTR;
			
			VARIANT vtEmpty = {}; // VT_EMPTY
			hr = psd->ShellExecute(bstrFile, vtArgs, vtDir, vtEmpty, vtEmpty);

			SysFreeString(bstrFile);
			SysFreeString(vtArgs.bstrVal);
			SysFreeString(vtDir.bstrVal);

			psd->Release();
		}
		psv->Release();
	}

	return hr == S_OK;
}

bool IsElevated()
{
	bool isElevated = false;
	wil::unique_handle hToken;

	if (::OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, hToken.addressof()))
	{
		TOKEN_ELEVATION elevation;
		DWORD size;

		if (::GetTokenInformation(hToken.get(), TokenElevation, &elevation, sizeof(elevation), &size))
		{
			isElevated = elevation.TokenIsElevated;
		}
	}

	return isElevated;
}

//------------------------------------------------------------------------------------------------------

wil::unique_handle GetImpersonationToken()
{
	wil::unique_handle hToken;
	wil::unique_handle hImpersonationToken;

	if (!::OpenProcessToken(GetCurrentProcess(), TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_DUPLICATE | STANDARD_RIGHTS_READ, hToken.addressof()))
	{
		SPDLOG_WARN("OpenProcessToken failed with error: {}", ::GetLastError());
		return nullptr;
	}

	// Duplicate the token for impersonation
	if (!DuplicateToken(hToken.get(), SecurityImpersonation, hImpersonationToken.addressof()))
	{
		SPDLOG_WARN("DuplicateToken failed with error: {}", ::GetLastError());
		return nullptr;
	}

	return hImpersonationToken;
}

bool HasWriteAccess(HANDLE hToken, const fs::path& directoryPath, DWORD dwAccessDesired = GENERIC_WRITE)
{
	// In event of error just treat it as ok.

	constexpr SECURITY_INFORMATION si = OWNER_SECURITY_INFORMATION | GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION;
	DWORD length = 0;

	if (::GetFileSecurityW(directoryPath.wstring().c_str(), si, nullptr, 0, &length) != 0
		|| ::GetLastError() != ERROR_INSUFFICIENT_BUFFER)
	{
		SPDLOG_WARN("Unexpected result while querying GetFileSecurity for buffer size, path={} error={}",
			directoryPath.string(), ::GetLastError());
		return true;
	}

	wil::unique_any<PSECURITY_DESCRIPTOR, decltype(&::free), free> pSD(::malloc(length));

	if (!::GetFileSecurityW(directoryPath.wstring().c_str(), si, pSD.get(), length, &length))
	{
		SPDLOG_WARN("Failed to get security descriptor for path={} error={}",
			directoryPath.string(), ::GetLastError());
		return true;
	}

	PRIVILEGE_SET PrivilegeSet;
	DWORD PrivilegeSetLength = sizeof(PrivilegeSet);
	DWORD dwAccessGranted = 0;
	BOOL accessStatus = FALSE;

	GENERIC_MAPPING mapping;
	mapping.GenericRead = FILE_GENERIC_READ;
	mapping.GenericWrite = FILE_GENERIC_WRITE;
	mapping.GenericExecute = FILE_GENERIC_EXECUTE;
	mapping.GenericAll = FILE_ALL_ACCESS;
	::MapGenericMask(&dwAccessDesired, &mapping);

	if (!::AccessCheck(pSD.get(), hToken, dwAccessDesired, &mapping,
		&PrivilegeSet, &PrivilegeSetLength, &dwAccessGranted, &accessStatus))
	{
		SPDLOG_WARN("AccessCheck failed: path={} error={}", directoryPath.string(), ::GetLastError());
		return true;
	}

	return (dwAccessGranted & dwAccessDesired) == dwAccessDesired;
}

class PermissionNotificationHandler : public IWinToastHandler
{
public:
	PermissionNotificationHandler(const std::vector<std::string>& failedPaths, const std::string& message)
		: m_failedPaths(failedPaths), m_message(message)
	{
	}

	void toastActivated() override
	{
	}

	void toastActivated(int actionIndex) override
	{
		if (actionIndex == 0)
		{
			// "More Info" clicked. Throw up a dialog with more info.
			DisplayMessageBox();
		}
	}

	void toastActivated(const char* response) override
	{
	}

	void toastDismissed(WinToastDismissalReason state) override
	{
	}

	void toastFailed() override
	{
	}

	void DisplayMessageBox()
	{
		fmt::memory_buffer buf;
		fmt::appender it(buf);

		fmt::format_to(it, "MacroQuest is unable to write to the following paths in the MacroQuest directory:\n\n");
		for (const std::string& path : m_failedPaths)
		{
			fmt::format_to(it, "{}\n", path);
		}

		fmt::format_to(it, "\nThis means that files in the MacroQuest directory are not writable, and this "
			"may cause issues. This commonly happens as a result of running EverQuest or MacroQuest as Administrator, but may also "
			"be caused by an incorrect installation. Note: running EverQuest as Administrator is STRONGLY discouraged.\n\n"
			"MacroQuest Path: {}", internal_paths::MQRoot);

		LauncherImGui::OpenMessageBox(nullptr, to_string(buf), "MacroQuest File Permission Errors",
			ImVec2(600, 400));
	}

	std::vector<std::string> m_failedPaths;
	std::string m_message;
};

void CheckPaths()
{
	if (GetPrivateProfileBool("MacroQuest", "DisableFilePermissionsCheck", false, internal_paths::MQini))
		return;

	wil::unique_handle hToken = GetImpersonationToken();
	if (!hToken)
	{
		SPDLOG_WARN("Failed to get impersonation token");
		return;
	}

	// Get list of paths to check
	const std::vector<fs::path> paths = {
		internal_paths::MQRoot,
		internal_paths::MQini,
		internal_paths::Config,
		internal_paths::Logs,
		internal_paths::Macros,
		internal_paths::Plugins,
		internal_paths::Resources,
	};

	std::vector<std::string> failedPaths;

	for (const auto& path : paths)
	{
		if (!HasWriteAccess(hToken.get(), path))
			failedPaths.push_back(path.string());
	}

	if (!HasWriteAccess(hToken.get(), internal_paths::CrashDumps))
	{
		failedPaths.push_back(internal_paths::CrashDumps);
		s_dumpsPathOK = false;
	}

	if (!failedPaths.empty())
	{
		for (const std::string& path : failedPaths)
		{
			SPDLOG_WARN("No write access to path: {}", path);
		}


		std::string message = "MacroQuest is unable to write to paths in the MacroQuest directory.\n\n"
			"MacroQuest may not run properly (or may not run at all).";
		std::shared_ptr<PermissionNotificationHandler> handler = std::make_shared<PermissionNotificationHandler>(failedPaths, message);

		if (WinToast::instance()->isInitialized())
		{
			WinToastTemplate templ(WinToastTemplate::Text02);
			templ.setFirstLine("File Permission Problems Detected");
			templ.setSecondLine(message);
			templ.addAction("More Info");

			WinToast::instance()->showToast(templ, handler);
		}
		else
		{
			handler->DisplayMessageBox();
		}
	}

	::RevertToSelf();
}

void ShowBalloonTip(HWND hwnd, const wchar_t* title, const wchar_t* msg)
{
	NOTIFYICONDATAW nid = {};
	nid.cbSize = sizeof(nid);
	nid.hWnd = hwnd;
	nid.uID = WM_USER_SYSTRAY;
	nid.uFlags = NIF_INFO;
	wcscpy_s(nid.szInfoTitle, title);
	wcscpy_s(nid.szInfo, msg);
	::Shell_NotifyIconW(NIM_MODIFY, &nid);
}

void ReportFailedInjection(InjectResult result, DWORD pid)
{
	if (result == InjectResult::FailedElevationRequired)
	{
		std::string message = fmt::format("Access denied - PID {}", pid);
		ShowBalloonTip(hMainWnd, L"Failed to inject", mq::utf8_to_wstring(message).c_str());
	}
}

// ***************************************************************************
// Function:    WinMain
// Description: EXE entry point
// ***************************************************************************
int WINAPI CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	g_hInst = hInstance;

	// Initialize Paths so we know where to put our logs and where to load our config from
	InitializePaths();

	bool showConsole = GetPrivateProfileBool("MacroQuest", "ShowLoaderConsole", false, internal_paths::MQini);
	UpdateShowConsole(showConsole, false);

	// Initialize Logging
	InitializeLogging();

	s_isElevated = IsElevated();

	SPDLOG_INFO("Starting MacroQuest Loader{}. Built {}", s_isElevated ? " (Elevated)" : "", __TIMESTAMP__);

	// Initialize COM
	auto coCleanup = wil::CoInitializeEx(COINIT_MULTITHREADED | COINIT_DISABLE_OLE1DDE);

	// TODO:  Allow argument processing of passing ini file so the file can be launched from anywhere
	std::string fullCommandLine = "";
	bool spawnedProcess = false;
	bool disableAppCompatCheck = false;
	bool injectOnce = false;
	for (int i = 1; i < __argc; ++i)
	{
		// Recreate the command line
		if (!fullCommandLine.empty())
		{
			fullCommandLine += " ";
		}
		std::string thisArg = __argv[i];
		if (thisArg.find(' ') != std::string::npos)
		{
			thisArg = fmt::format("\"{}\"", thisArg);
		}
		fullCommandLine += thisArg;

		if (ci_find_substr(thisArg, "noappcompat") != -1)
		{
			disableAppCompatCheck = true;
		}
		else if (ci_find_substr(thisArg, "injectonce") != -1)
		{
			injectOnce = true;
		}
		// Only need this if we're not already the spawned process
		else if (!spawnedProcess && ci_find_substr(thisArg, "spawnedprocess") != -1)
		{
			SPDLOG_INFO("I am a spawned process");
			spawnedProcess = true;
		}
	}

	if (!spawnedProcess)
	{
		char szFileName[MAX_PATH] = { 0 };
		GetModuleFileName(nullptr, szFileName, MAX_PATH);
		std::filesystem::path thisProgramPath = szFileName;

		if (!thisProgramPath.is_absolute())
		{
			std::error_code ec;
			thisProgramPath = absolute(thisProgramPath, ec);
		}

		std::filesystem::path ProgramPath;

		const std::string oldProcessName = GetPrivateProfileString("Internal", "SpawnedProcess", "", internal_paths::MQini.c_str());
		if (oldProcessName.empty())
		{
			ProgramPath = GetUniqueFileName(thisProgramPath.parent_path(), "exe");
		}
		else
		{
			ProgramPath = thisProgramPath.parent_path() / oldProcessName;
		}

		// Launch a new process if this process isn't the renamed process
		if (!ci_equals(ProgramPath.filename().string(), thisProgramPath.filename().string()))
		{
			std::string programPathStr = ProgramPath.string();

			std::error_code ec;
			if (exists(ProgramPath, ec))
			{
				if (IsProcessRunning(oldProcessName))
				{
					if (!file_equals(thisProgramPath, ProgramPath))
					{
						ShowWarningBlocking("Please exit out of the alternate loader for an update: " + oldProcessName);
					}
					else
					{
						SPDLOG_WARN("Alternate loader is already running: {}", programPathStr);
						exit(0);
					}
				}
				if (!file_equals(thisProgramPath, ProgramPath) && !remove(ProgramPath, ec))
				{
					ShowErrorBlocking("Could not delete alternate loader: " + programPathStr);
					exit(1);
				}
			}
			if (!exists(ProgramPath, ec) && !std::filesystem::copy_file(thisProgramPath, ProgramPath, ec))
			{
				ShowErrorBlocking("Could not create duplicate of this program at: " + programPathStr);
				exit(1);
			}

			std::wstring arguments = utf8_to_wstring(fmt::format("\"{}\" {} /spawnedprocess", ProgramPath.string(), fullCommandLine));
			SPDLOG_INFO("Relaunching as spawned process");

			STARTUPINFOW si = {};
			wil::unique_process_information pi;

			if (::CreateProcessW(ProgramPath.wstring().c_str(), &arguments[0], nullptr, nullptr, false, CREATE_NEW_CONSOLE,
				nullptr, nullptr, &si, &pi))
			{
				WritePrivateProfileString("Internal", "SpawnedProcess", ProgramPath.filename().string(), internal_paths::MQini);
			}
			else
			{
				ShowErrorBlocking("Could not launch alternate loader at: " + programPathStr);
				exit(1);
			}
			exit(0);
		}
	}

	WinToast::instance()->setAppName(L"MacroQuest");
	WinToast::instance()->setAppUserModelId(L"MacroQuest.MacroQuest");
	if (!WinToast::instance()->initialize())
	{
		SPDLOG_WARN("System does not support windows notifications");
	}

	CheckPaths();

	// Initialize crash handler
	if (!s_dumpsPathOK)
		SPDLOG_ERROR("Permission Error with Crashpad path, not initializing crashpad");
	else
	{
		gCrashPadInitialized = InitializeCrashpad();

		if (!gCrashPadInitialized && gEnableCrashpad)
			SPDLOG_WARN("Crashpad handler failed to initialize.");
		else if (!gEnableCrashpad)
			SPDLOG_INFO("Crashpad is disabled.");
	}

	INITCOMMONCONTROLSEX ccex = { sizeof(INITCOMMONCONTROLSEX) };
	ccex.dwICC = ICC_STANDARD_CLASSES | ICC_HOTKEY_CLASS;
	::InitCommonControlsEx(&ccex);

	GetPrivateProfileString("MacroQuest", "MacroQuestWinClassName", "__MacroQuestTray", gszWinClassName, lengthof(gszWinClassName), internal_paths::MQini);
	GetPrivateProfileString("MacroQuest", "MacroQuestWinName", "MacroQuest", gszWinName, lengthof(gszWinClassName), internal_paths::MQini);

	// Make sure a MacroQuest instance isn't already running, if one is running, exit
	HWND hWndRunning = FindWindow(gszWinClassName, gszWinName);
	if (hWndRunning != nullptr)
	{
		SPDLOG_INFO("Closing because another window of class \"{}\" is open", gszWinClassName);
		return 0;
	}

	const std::string cycleNextWindowKey = GetPrivateProfileString("MacroQuest", "CycleNextWindow", "", internal_paths::MQini);
	const std::string cyclePrevWindowKey = GetPrivateProfileString("MacroQuest", "CyclePrevWindow", "", internal_paths::MQini);
	const std::string bossModeKey = GetPrivateProfileString("MacroQuest", "BossMode", "", internal_paths::MQini);

	s_logCleanupMaxCount = GetPrivateProfileInt("MacroQuest", "LogCleanupMaxCount", s_logCleanupMaxCount, internal_paths::MQini);
	s_logCleanupMaxAgeDays = GetPrivateProfileInt("MacroQuest", "LogCleanupMaxAgeDays", s_logCleanupMaxAgeDays, internal_paths::MQini);
	s_logFileCleanupIntervalMins = GetPrivateProfileInt("MacroQuest", "LogCleanupIntervalMins", s_logFileCleanupIntervalMins, internal_paths::MQini);

	// Update version information shown in the system tray tooltip
	InitializeVersionInfo();
	InitializeNamedPipeServer();
	InitializeWindows();
	InitializeAutoLogin();

	auto pids = GetAllEqGameSessions();
	s_processIds = { begin(pids), end(pids) };

	auto pMonitorEvents = std::make_unique<MQ2ProcessMonitorEvents>();
	StartProcessMonitor(pMonitorEvents.get());

	// Handle global hotkeys
	uint16_t modkey = 0;
	uint16_t hotkey = 0;

	if (!cycleNextWindowKey.empty() && cycleNextWindowKey != "0")
	{
		if (ConvertStringToModifiersAndVirtualKey(cycleNextWindowKey, modkey, hotkey))
		{
			if (RegisterHotKey(hMainWnd, HOTKEY_EQWIN_NEXT, modkey, hotkey))
			{
				gNextWindowHotKey = MAKELONG(modkey, hotkey);
			}
		}
	}
	if (!cyclePrevWindowKey.empty() && cyclePrevWindowKey != "0")
	{
		if (ConvertStringToModifiersAndVirtualKey(cyclePrevWindowKey, modkey, hotkey))
		{
			if (RegisterHotKey(hMainWnd, HOTKEY_EQWIN_PREVIOUS, modkey, hotkey))
			{
				gPrevWindowHotKey = MAKELONG(modkey, hotkey);
			}
		}
	}
	if (!bossModeKey.empty() && bossModeKey != "0")
	{
		if (ConvertStringToModifiersAndVirtualKey(bossModeKey, modkey, hotkey))
		{
			if (RegisterHotKey(hMainWnd, HOTKEY_EQWIN_BOSSKEY, modkey, hotkey))
			{
				gBossModeHotKey = MAKELONG(modkey, hotkey);
			}
		}
	}

	// This also initializes mqversion
	if (!InitializeInjector(injectOnce))
		PostQuitMessage(1);

	CheckMQ2MainUpdate();

	if (!GetPrivateProfileBool("MacroQuest", "DisableAppCompatCheck", disableAppCompatCheck, internal_paths::MQini))
		CheckAppCompat();

	// EQBC menu
	LauncherImGui::AddContextGroup("EQBC", ShowEQBCMenu);

	// advanced menu items
	LauncherImGui::AddContextGroup("##Advanced Menu Items", ShowAdvancedMenu);

	SPDLOG_INFO("Waiting for events...");

	MSG msg;
	LauncherImGui::Run(
		[&msg]()
		{
			ProcessPendingLogins();
			CheckPruneLogging();

			if (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE) != 0)
			{
				switch (msg.message)
				{
				case WM_QUIT:
					return false;
				default:
					TranslateMessage(&msg);
					DispatchMessageA(&msg);
					return true;
				}
			}

			return true;
		});

	SPDLOG_INFO("Shutting down...");

	// Shutdown
	UnregisterHotKey(hMainWnd, HOTKEY_EQWIN_PREVIOUS);
	UnregisterHotKey(hMainWnd, HOTKEY_EQWIN_NEXT);
	UnregisterHotKey(hMainWnd, HOTKEY_EQWIN_BOSSKEY);
	UnregisterGlobalHotkey(hMainWnd);
	Shell_NotifyIcon(NIM_DELETE, &NID);

	ShutdownAutoLogin();
	ShutdownInjector();
	ShutdownNamedPipeServer();
	StopProcessMonitor();
	if (injectOnce)
		UpdateShowConsole(false, false);
	ShutdownConsole();

	UnregisterClass(gszWinClassName, hInstance);

	s_ringBufferSink.reset();
	s_stdOutSink.reset();
	spdlog::shutdown();

	return (int)msg.wParam;
}

HWND LocateHotkeyWindow(WORD modkey, WORD hotkey)
{
	auto wnd_it = hotkeyMap.find(std::make_pair(modkey, hotkey));
	if (wnd_it != hotkeyMap.end())
	{
		if (IsWindow(wnd_it->second))
		{
			// if we have a valid window, then return it -- the hotkey is valid
			return wnd_it->second;
		}

		// we don't have a valid window, so let's drop the hotkey
		SendMessageA(hMainWnd, WM_USER_HOTKEY_ADD, modkey, hotkey);
		hotkeyMap.erase(wnd_it);
	}

	return nullptr;
}

void RegisterGlobalHotkey(HWND hWnd, std::string_view hotkeyString)
{
	uint16_t modkey, hotkey;
	ConvertStringToModifiersAndVirtualKey(std::string(hotkeyString), modkey, hotkey);

	auto wnd_it = hotkeyMap.find(std::make_pair(modkey, hotkey));
	if (wnd_it != hotkeyMap.end())
	{
		// the hotkey already exists, so drop it and replace it with the new one
		SendMessageA(hMainWnd, WM_USER_HOTKEY_REMOVE, modkey, hotkey);
		hotkeyMap.erase(wnd_it);
	}

	hotkeyMap[std::make_pair(modkey, hotkey)] = hWnd;
	SendMessageA(hMainWnd, WM_USER_HOTKEY_ADD, modkey, hotkey);
}

void UnregisterGlobalHotkey(std::string_view hotkeyString)
{
	uint16_t modkey, hotkey;
	ConvertStringToModifiersAndVirtualKey(std::string(hotkeyString), modkey, hotkey);

	auto wnd_it = hotkeyMap.find(std::make_pair(modkey, hotkey));
	if (wnd_it != hotkeyMap.end())
	{
		SendMessageA(hMainWnd, WM_USER_HOTKEY_REMOVE, modkey, hotkey);
		hotkeyMap.erase(wnd_it);
	}
}

void UnregisterGlobalHotkey(HWND hWnd)
{
	auto wnd_it = std::find_if(hotkeyMap.cbegin(), hotkeyMap.cend(),
		[&hWnd](const auto& pair) {
			return pair.second == hWnd;
		});
	if (wnd_it != hotkeyMap.end())
	{
		SendMessageA(hMainWnd, WM_USER_HOTKEY_REMOVE, std::get<0>(wnd_it->first), std::get<1>(wnd_it->first));
		hotkeyMap.erase(wnd_it);
	}
}

std::string_view GetServerType()
{
	return ServerType;
}
