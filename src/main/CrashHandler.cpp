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

#include <client/crash_report_database.h>
#include <client/settings.h>
#include "client/crashpad_client.h"

namespace mq {

using namespace crashpad;
static crashpad::CrashpadClient client;

bool InitializeCrashpad()
{
	std::map<std::string, std::string> annotations;
	std::vector<std::string> arguments;

	// This is the directory you will use to store and queue crash data.
	std::wstring db_path(utf8_to_wstring(mq::internal_paths::CrashDumps));

	// Crashpad has the ability to support crashes both in-process and out-of-process.
	// The out-of-process handler is significantly more robust than traditional in-process
	// crash handlers. This path may be relative.
	std::wstring handler_path(utf8_to_wstring(mq::internal_paths::MQRoot + "/crashpad_handler.exe"));

	// This should point to your server dump submission port (labeled as "http/writer"
	// in the listener configuration pane. Preferrably, the SSL enabled port should
	// be used. If Backtrace is hosting your instance, the default port is 6098.
	std::string url("https://submit.backtrace.io/mq2/7d4625da4231505c0a7b8adc4a55d55fb50e2d2ce0cc8526693b5d07740e038a/minidump");
	// TODO: Control this flag with config.
	arguments.emplace_back("--no-rate-limit");

	base::FilePath db(db_path);
	base::FilePath handler(handler_path);
	std::unique_ptr<CrashReportDatabase> database = crashpad::CrashReportDatabase::Initialize(db);

	if (database == nullptr || database->GetSettings() == nullptr)
	{
		return false;
	}

	// TODO: Control this flag with config
	database->GetSettings()->SetUploadsEnabled(true);

	bool rc = client.StartHandler(handler,
		db,
		db,
		url,
		annotations,
		arguments,
		true,
		true);
	if (rc == false)
	{
		return false;
	}

	/* Optional, wait for Crashpad to initialize. */
	return client.WaitForHandlerStart(INFINITE);
}

} // namespace mq::backtrace
