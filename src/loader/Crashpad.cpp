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

#include "MacroQuest.h"
#include "Crashpad.h"

#include "common/StringUtils.h"
#include "mq/base/WString.h"

#include <client/crash_report_database.h>
#include <client/settings.h>
#include <client/crashpad_client.h>
#include <spdlog/spdlog.h>

#include <map>
#include <string>
#include <vector>

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

using namespace crashpad;
CrashpadClient client;

bool gEnableCrashpad = true;                                  // Indicates if we we want to be using crashpad.
bool gEnableSharedCrashpad = true;                            // If using crashpad, use the shared crashpad process.
bool gEnableSilentCrashpad = false;                           // If using crashpad, crash & report silently.
bool gEnableCrashSubmissions = CRASHPAD_SUBMISSIONS_ENABLED;  // If using crashpad, we will submit them.
bool gEnableRateLimit = false;                                // If using crashpad, upload rate limiting.

bool gCrashpadInitialized = false;                            // Internal state-tracking of initialization

static std::string gCrashpadSubmissionURL = CRASHPAD_SUBMISSIONS_URL;

bool InitializeCrashpad()
{
	// Load preferences. Decide if we want to enable the crash reporting system.
	gEnableCrashpad = GetPrivateProfileBool("Crash Handler", "EnableCrashpad", gEnableCrashpad, internal_paths::MQini);
	gEnableSharedCrashpad = GetPrivateProfileBool("Crash Handler", "EnableSharedCrashpad", gEnableSharedCrashpad, internal_paths::MQini);
	gEnableSilentCrashpad = GetPrivateProfileBool("Crash Handler", "EnableSilentCrashpad", gEnableSilentCrashpad, internal_paths::MQini);
	gEnableCrashSubmissions = GetPrivateProfileBool("Crash Handler", "EnableCrashSubmissions", gEnableCrashSubmissions, internal_paths::MQini);
	gCrashpadSubmissionURL = GetPrivateProfileString("Crash Handler", "CrashpadSubmissionURL", gCrashpadSubmissionURL.c_str(), internal_paths::MQini);

	if (!gEnableCrashpad)
	{
		return false;
	}

	std::map<std::string, std::string> annotations;
	std::vector<std::string> arguments;

	// This is the directory you will use to store and queue crash data.
	std::wstring dbPath(utf8_to_wstring(internal_paths::CrashDumps));

	// Crashpad has the ability to support crashes both in-process and out-of-process.
	// The out-of-process handler is significantly more robust than traditional in-process
	// crash handlers. This path may be relative.
	std::string handlerPath(internal_paths::MQRoot + "\\crashpad_handler.exe");

	// This should point to your server dump submission port (labeled as "http/writer"
	// in the listener configuration pane. Preferrably, the SSL enabled port should
	// be used. If Backtrace is hosting your instance, the default port is 6098.
	std::string url(gCrashpadSubmissionURL);

	if (!gEnableRateLimit)
	{
		arguments.emplace_back("--no-rate-limit");
	}

	base::FilePath db(dbPath);
	base::FilePath handler(utf8_to_wstring(handlerPath));
	std::unique_ptr<crashpad::CrashReportDatabase> database = crashpad::CrashReportDatabase::Initialize(db);

	if (database == nullptr || database->GetSettings() == nullptr)
	{
		return false;
	}

	SPDLOG_INFO("Initializing crashpad handler");
	SPDLOG_DEBUG("Handler Path: {}", handlerPath);

	if (gEnableCrashSubmissions && !gCrashpadSubmissionURL.empty())
	{
		database->GetSettings()->SetUploadsEnabled(true);
		SPDLOG_INFO("Crash report submission is: enabled");

		crashpad::UUID uuid;
		database->GetSettings()->GetClientID(&uuid);
		SPDLOG_INFO("Crash report guid: {}", uuid.ToString());
	}
	else
	{
		database->GetSettings()->SetUploadsEnabled(false);
		SPDLOG_INFO("Crash report submission is: disabled");
	}

	if (gEnableSharedCrashpad)
	{
		SPDLOG_INFO("Using shared crash reporter for all MacroQuest instances");
	}

	bool rc = client.StartHandler(handler,
		db,
		base::FilePath(),
		url,
		annotations,
		arguments,
		true,
		true);
	if (rc == false)
	{
		return false;
	}

	// Wait for Crashpad to initialize.
	gCrashpadInitialized = client.WaitForHandlerStart(INFINITE);
	return gCrashpadInitialized;
}

std::string GetHandlerIPCPipe()
{
	std::wstring pipeName = client.GetHandlerIPCPipe();

	return mq::wstring_to_utf8(pipeName);
}

bool IsCrashpadInitialized()
{
	return gCrashpadInitialized;
}
