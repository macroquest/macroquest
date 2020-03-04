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
#include "CrashHandler.h"

// Crashpad client headers
#include <client/crash_report_database.h>
#include <client/settings.h>
#include <client/crashpad_client.h>
#include <client/crashpad_info.h>

#include <spdlog/spdlog.h>
#include <wil/resource.h>
#include <filesystem>

#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")

#if __has_include("config/crashpad.h")
#include "config/crashpad.h"
#endif
#if !defined(CRASHPAD_SUBMISSIONS_ENABLED)
#define CRASHPAD_SUBMISSIONS_ENABLED false
#endif
#if !defined(CRASHPAD_SUBMISSIONS_URL)
#define CRASHPAD_SUBMISSIONS_URL ""
#endif
#if !defined(CRASHPAD_SUBMISSIONS_RATELIMITED)
#define CRASHPAD_SUBMISSIONS_RATELIMITED true
#endif

namespace fs = std::filesystem;

namespace mq {

// CrashHandler TODO:
// - Provide a means to retrieve the client UUID so that a user can inform developers of which
//   crash reports are theirs.
// - Improved crash notification to include information about what kind of unhandled exception occurred.
// - Stretch: Create a way to notify the user that a process has crashed from the launcher.

// Some of these settings are mirrored in MacroQuest2.exe

static bool gEnableCrashpad = true;                                  // Indicates if we we want to be using crashpad.
static bool gEnableSharedCrashpad = true;                            // If using crashpad, use the shared crashpad process.
static bool gEnableSilentCrashpad = false;                           // If using crashpad, crash & report silently.
static bool gEnableCrashSubmissions = CRASHPAD_SUBMISSIONS_ENABLED;  // If using crashpad, we will submit them.
static bool gEnableRateLimit = false;                                // If using crashpad, upload rate limiting.

static std::string gCrashpadSubmissionURL = CRASHPAD_SUBMISSIONS_URL;

// The actual crashpad client. If this is null, then crashpad wasn't successfully enabled.
static crashpad::CrashpadClient* gCrashpadClient = nullptr;

// The crashpad unhandled exception filter. We will call into this if we want to show a dialog first.
static LPTOP_LEVEL_EXCEPTION_FILTER lpCrashpadTopLevelExceptionFilter = nullptr;

// The original unhandled exception filter. We need to hold this so we can put it back if we unload.
static LPTOP_LEVEL_EXCEPTION_FILTER lpOrigTopLevelExceptionFilter = nullptr;

static LONG WINAPI OurCrashHandler(EXCEPTION_POINTERS* ex);
static void ReplaceCrashpadUnhandledExceptionFilter()
{
	if (!gEnableSilentCrashpad)
	{
		// Crashpad handler will install its own unhandled exception filter. We want to go first
		// and issue a prompt first, so reinstall our handler and save the crashpad handler
		// so we can invoke it after our own handler.
		lpCrashpadTopLevelExceptionFilter = SetUnhandledExceptionFilter(OurCrashHandler);
	}
}

// Use this function to start crashpad with a new crashpad process.
bool InitializeCrashpad()
{
	// Don't replace another crashpad instance if it exists.
	if (gCrashpadClient != nullptr)
		return true;

	std::map<std::string, std::string> annotations;
	std::vector<std::string> arguments;

	// This is the directory you will use to store and queue crash data.
	std::wstring dbPath(utf8_to_wstring(mq::internal_paths::CrashDumps));

	// Crashpad has the ability to support crashes both in-process and out-of-process.
	// The out-of-process handler is significantly more robust than traditional in-process
	// crash handlers. This path may be relative.
	std::wstring handlerPath(utf8_to_wstring(mq::internal_paths::MQRoot + "\\mq_crash_handler.exe"));

	// This should point to your server dump submission port (labeled as "http/writer"
	// in the listener configuration pane. Preferrably, the SSL enabled port should
	// be used. If Backtrace is hosting your instance, the default port is 6098.
	std::string url(gCrashpadSubmissionURL);

	if (!gEnableRateLimit)
	{
		arguments.emplace_back("--no-rate-limit");
	}

	base::FilePath db(dbPath);
	base::FilePath handler(handlerPath);
	std::unique_ptr<crashpad::CrashReportDatabase> database = crashpad::CrashReportDatabase::Initialize(db);

	if (database == nullptr || database->GetSettings() == nullptr)
	{
		SPDLOG_ERROR("Failed to create crashpad::CrashReportDatabase");
		return false;
	}

	if (gEnableCrashSubmissions && !gCrashpadSubmissionURL.empty())
	{
		database->GetSettings()->SetUploadsEnabled(true);
		SPDLOG_INFO("Crash report submission is: enabled");

		crashpad::UUID uuid;
		database->GetSettings()->GetClientID(&uuid);
		SPDLOG_INFO("Crash report guid: {}", uuid.ToString());
	}

	gCrashpadClient = new crashpad::CrashpadClient();

	SPDLOG_INFO("Initializing crashpad handler with path: {}", mq::wstring_to_utf8(handlerPath));

	bool rc = gCrashpadClient->StartHandler(handler,
		db,
		db,
		url,
		annotations,
		arguments,
		true,
		true);
	if (rc == false)
	{
		delete gCrashpadClient;
		gCrashpadClient = nullptr;

		return false;
	}

	// Wait for Crashpad to initialize.
	bool success = gCrashpadClient->WaitForHandlerStart(INFINITE);

	if (success)
	{
		ReplaceCrashpadUnhandledExceptionFilter();
	}
	else
	{
		delete gCrashpadClient;
		gCrashpadClient = nullptr;

		SPDLOG_ERROR("Failed to start crashpad process.");
	}

	return success;
}

// Use this function to start crashpad using an existing crashpad instance.
void InitializeCrashpadPipe(const std::string& pipeName)
{
	// Can't initialize without a name
	if (pipeName.empty())
		return;

	// Only continue if using a shared crashpad instance and we haven't already initialized
	if (gEnableCrashpad && !gCrashpadClient && gEnableSharedCrashpad)
	{
		SPDLOG_INFO("Received crashpad pipe name: {0}", pipeName);
		std::wstring wPipeName = mq::utf8_to_wstring(pipeName);

		// Open database and read the guid.
		std::wstring dbPath(utf8_to_wstring(mq::internal_paths::CrashDumps));
		std::unique_ptr<crashpad::CrashReportDatabase> database = crashpad::CrashReportDatabase::Initialize(base::FilePath(dbPath));
		if (!database || !database->GetSettings())
		{
			SPDLOG_ERROR("Failed to create crashpad::CrashReportDatabase");
			return;
		}

		crashpad::UUID uuid;
		database->GetSettings()->GetClientID(&uuid);
		SPDLOG_INFO("Enabling shared crash reporter. Crash report guid: {}", uuid.ToString());

		gCrashpadClient = new crashpad::CrashpadClient();

		if (gCrashpadClient->SetHandlerIPCPipe(wPipeName))
		{
			ReplaceCrashpadUnhandledExceptionFilter();
		}
		else
		{
			SPDLOG_ERROR("Failed to initialize shared crash reporter!");
		}
	}
}

// If crashpad is not initialized we need a fallback plan. Returns the path to the minidump.
// Try to avoid allocations here.
static std::string MakeMiniDump(const std::string& filename, EXCEPTION_POINTERS* e)
{
	fs::path file = fs::path{ filename }.filename().replace_extension();

	SYSTEMTIME t;
	GetSystemTime(&t);

	std::string dumpFilename = fmt::format(R"({}\reports\{}_{:04}{:02}{:02}_{:02}{:02}{:02}.dmp)",
		mq::internal_paths::CrashDumps, file.string(), t.wYear, t.wMonth, t.wDay, t.wHour, t.wMinute, t.wSecond);

	// Try to create the CrashDumps directory if it doesn't exist.
	std::error_code ec;
	fs::create_directories(mq::internal_paths::CrashDumps, ec);

	wil::unique_hfile hFile(::CreateFileA(dumpFilename.c_str(), GENERIC_WRITE, FILE_SHARE_READ, nullptr,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr));
	if (!hFile)
	{
		SPDLOG_ERROR("Failed to create crash dump file: {}", dumpFilename);
		return {};
	}

	MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
	exceptionInfo.ThreadId = GetCurrentThreadId();
	exceptionInfo.ExceptionPointers = e;
	exceptionInfo.ClientPointers = FALSE;

	BOOL dumped = MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		hFile.get(),
		MINIDUMP_TYPE(MiniDumpWithUnloadedModules | MiniDumpWithIndirectlyReferencedMemory | MiniDumpScanMemory),
		e ? &exceptionInfo : nullptr,
		nullptr,
		nullptr);

	return dumped ? dumpFilename : std::string();
}

int MQ2CrashHandler(EXCEPTION_POINTERS* ex, const char* description, bool isDebugTry)
{
	// FIXME
	if (isDebugTry)
	{
		return EXCEPTION_CONTINUE_SEARCH;
	}

	SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);
	HANDLE hProcess = GetCurrentProcess();

	SymInitialize(hProcess, nullptr, true);

	// Set the symbols search path
	char szSymSearchPath[MAX_STRING] = { 0 };
	GetPrivateProfileString("Debug", "SymbolsPath", "", szSymSearchPath, MAX_STRING, mq::internal_paths::MQini);
	if (szSymSearchPath[0])
		SymSetSearchPath(hProcess, szSymSearchPath);
	SymGetSearchPath(hProcess, szSymSearchPath, MAX_STRING);

	// Reusing szSymSearchPath now, for the crashing module filename.

	DWORD64 dwAddress = (DWORD64)ex->ExceptionRecord->ExceptionAddress; // Address you want to check on.
	HMODULE hModule = nullptr;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)dwAddress, &hModule);
	GetModuleFileName(hModule, szSymSearchPath, MAX_STRING);

	// Get buffer for symbol data
	char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
	PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)buffer;
	pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
	pSymbol->MaxNameLen = MAX_SYM_NAME;

	IMAGEHLP_LINE64 line = { sizeof(IMAGEHLP_LINE64) };
	DWORD64 dwDisplacement64 = 0;

	char szTemp[MAX_STRING] = { 0 };

	if (SymFromAddr(hProcess, dwAddress, &dwDisplacement64, pSymbol))
	{
		DWORD dwDisplacement = 0;
		if (SymGetLineFromAddr64(hProcess, dwAddress, &dwDisplacement, &line))
		{
			sprintf_s(szTemp,
				"MacroQuest caught a crash:\n"
				"Location: %s+%d @ %s:%d (%s+%p)\n",
				pSymbol->Name, dwDisplacement, line.FileName, line.LineNumber, szSymSearchPath, (void*)(line.Address - (DWORD)hModule));
		}
		else
		{
			sprintf_s(szTemp,
				"MacroQuest caught a crash:\n"
				"Location: %s+%d (%s+%p)\n",
				pSymbol->Name, dwDisplacement, szSymSearchPath, (void*)(pSymbol->Address - (DWORD)hModule));
		}
	}
	else
	{
		sprintf_s(szTemp,
			"MacroQuest caught a crash:\n"
			"Location: %s+%p\n",
			szSymSearchPath, (void*)(dwAddress - (DWORD)hModule));
	}

	SymCleanup(hProcess);

	if (description)
	{
		strcat_s(szTemp, "Description:");
		strcat_s(szTemp, description);
		strcat_s(szTemp, "\n");
	}

	char szMessage[MAX_STRING] = { 0 };

	sprintf_s(szMessage,
		"%s"
		"\n"
		"You can either:\n"
		" * [RETRY] Continue execution and hope for the best.\n"
		" * [CANCEL] Write a crash dump and terminate EverQuest.\n",
		szTemp);

	int mbRet = ::MessageBoxA(nullptr, szMessage, "EverQuest Crash Detected", MB_RETRYCANCEL | MB_DEFBUTTON2 | MB_ICONERROR | MB_SYSTEMMODAL);

	if (mbRet == IDRETRY)
	{
		return EXCEPTION_CONTINUE_EXECUTION;
	}

	// Call into crashpad if it is available.
	if (lpCrashpadTopLevelExceptionFilter)
	{
		return lpCrashpadTopLevelExceptionFilter(ex);
	}

	// We got here which means there is no crashpad handler available, so we gotta do a dump ourselves.
	std::string path = MakeMiniDump("eqgame.exe", ex);

	if (!path.empty())
	{
		sprintf_s(szMessage,
			"A crash dump has been written to:\n"
			"\n"
			"%s\n", path.c_str());
	}
	else
	{
		strcat_s(szMessage, "Failed to create crash dump!");
	}

	::MessageBoxA(nullptr, szMessage, "EverQuest Crash Detected", MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL);

	// Go boom.
	::TerminateProcess(::GetCurrentProcess(), 1);
	return EXCEPTION_CONTINUE_SEARCH;
}

int MQ2DebugTryFilter(EXCEPTION_POINTERS* ex, const char* description, ...)
{
	va_list vl;
	va_start(vl, description);

	char szTemp[MAX_STRING] = { 0 };
	vsprintf_s(szTemp, description, vl);

	return MQ2CrashHandler(ex, szTemp, true);
}

//============================================================================

LONG WINAPI OurCrashHandler(EXCEPTION_POINTERS* ex)
{
	__try
	{
		return MQ2CrashHandler(ex, nullptr, false);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		if (lpCrashpadTopLevelExceptionFilter)
		{
			return lpCrashpadTopLevelExceptionFilter(ex);
		}

		std::terminate();
	}
}

// this is the effectively the first thing that we do when we attach to EQ.
void InstallUnhandledExceptionFilter()
{
	// We install our own exception filter super early, it won't report to
	// crashpad if its enabled, but it will give us an opportunity to catch any crash that
	// occurs before we hook up to crashpad.

	lpOrigTopLevelExceptionFilter = SetUnhandledExceptionFilter(OurCrashHandler);
}

// This is the last thing we do before we detach from EQ.
void UninstallUnhandledExceptionFilter()
{
	// Set our exception filter to our own, in case its still using crashpad's. This is to ensure
	// if Crashpad somehow crashes in the next couple lines, we can catch it.
	SetUnhandledExceptionFilter(OurCrashHandler);

	if (gCrashpadClient)
	{
		delete gCrashpadClient;
		gCrashpadClient = nullptr;
	}

	// Restore the old unhandled exception filter
	SetUnhandledExceptionFilter(lpOrigTopLevelExceptionFilter);
}

//============================================================================

static crashpad::StringAnnotation<32> buildTypeAnnotation("buildType");
static crashpad::StringAnnotation<32> buildTimestampAnnotation("eqVersion");

void InitializeCrashHandler()
{
	// Load preferences. Decide if we want to enable the crash reporting system. These are primarily aimed at developers.
	gEnableCrashpad = GetPrivateProfileBool("Crash Handler", "EnableCrashpad", gEnableCrashpad, internal_paths::MQini);
	gEnableSharedCrashpad = GetPrivateProfileBool("Crash Handler", "EnableSharedCrashpad", gEnableSharedCrashpad, internal_paths::MQini);
	gEnableSilentCrashpad = GetPrivateProfileBool("Crash Handler", "EnableSilentCrashpad", gEnableSilentCrashpad, internal_paths::MQini);
	gEnableCrashSubmissions = GetPrivateProfileBool("Crash Handler", "EnableCrashSubmissions", gEnableCrashSubmissions, internal_paths::MQini);
	gCrashpadSubmissionURL = GetPrivateProfileString("Crash Handler", "CrashpadSubmissionURL", gCrashpadSubmissionURL.c_str(), internal_paths::MQini);

	// Configure / initialize crashpad

	if (gEnableCrashpad && !gEnableSharedCrashpad)
	{
		// If we're not using the shared crashpad instance then we need to initialize crashpad here.
		InitializeCrashpad();
	}
	else if (!gEnableCrashpad)
	{
		SPDLOG_INFO("Crashpad is disabled.");
	}

	// Set some annotations.

	// FIXME: Add enum values for gBuild.
	const char* buildType = "UNKNOWN";
	switch (gBuild)
	{
	case 1: buildType = "LIVE"; break;
	case 2: buildType = "TEST"; break;
	case 3: buildType = "BETA"; break;
	case 4: buildType = "EMU(ROF2)"; break;
	case 5: buildType = "EMU(UF)"; break;
	}

#pragma warning(suppress: 4996)
	buildTypeAnnotation.Set(buildType);
	buildTimestampAnnotation.Set(__ExpectedVersionDate " " __ExpectedVersionTime);
}

//----------------------------------------------------------------------------

void DoCrash(SPAWNINFO* pChar, char* szLine)
{
	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	// Indicate to crash reporting that this is a synthetic crash
	auto pAnno = new crashpad::StringAnnotation<32>("synthesized");
	pAnno->Set("true");

	if (ci_equals(szArg1, "force"))
	{
		int* pc = nullptr;
		*pc = 18;
	}
	else
	{
		CONTEXT context;
		crashpad::CaptureContext(&context);
		crashpad::CrashpadClient::DumpWithoutCrash(context);
	}
}

void InitializeMQ2CrashHandler()
{
	AddCommand("/crash", DoCrash);
}

void ShutdownMQ2CrashHandler()
{
	RemoveCommand("/crash");
}

} // namespace mq
