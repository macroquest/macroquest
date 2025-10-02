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
#include <imgui/imgui.h>

#include <map>
#include <string>
#include <vector>
#include <fmt/chrono.h>

#include "imgui/ImGuiUtils.h"
#include "main/MQVersionInfo.h"

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
std::unique_ptr<crashpad::CrashReportDatabase> s_database;

bool ShouldAutoSubmitCrashReports()
{
	return gEnableCrashSubmissions && !gCrashpadSubmissionURL.empty() && MQMAIN_VERSION_BUILD != 0;
}

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
	s_database = crashpad::CrashReportDatabase::Initialize(db);

	if (s_database == nullptr || s_database->GetSettings() == nullptr)
	{
		return false;
	}

	SPDLOG_INFO("Initializing crashpad handler");
	SPDLOG_DEBUG("Handler Path: {}", handlerPath);

	if (ShouldAutoSubmitCrashReports())
	{
		s_database->GetSettings()->SetUploadsEnabled(true);
		SPDLOG_INFO("Crash report submission is: enabled");

		crashpad::UUID uuid;
		s_database->GetSettings()->GetClientID(&uuid);
		SPDLOG_INFO("Crash report guid: {}", uuid.ToString());
	}
	else
	{
		s_database->GetSettings()->SetUploadsEnabled(false);
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

template <size_t bufferLength>
void FormatBytes(char(&szBuffer)[bufferLength], uint64_t bytes)
{
	if (bytes < 1024)
	{
		sprintf_s(szBuffer, bufferLength, "%d Bytes", static_cast<int>(bytes));
	}
	else if (bytes < 1024 * 1024)
	{
		sprintf_s(szBuffer, bufferLength, "%.2f KB", static_cast<float>(bytes) / 1024);
	}
	else if (bytes < 1024 * 1024 * 1024)
	{
		sprintf_s(szBuffer, bufferLength, "%.2f MB", static_cast<float>(bytes) / (1024 * 1024));
	}
	else
	{
		sprintf_s(szBuffer, bufferLength, "%.2f GB", static_cast<float>(bytes) / (1024 * 1024 * 1024));
	}
}

void ShowCrashReport(const crashpad::CrashReportDatabase::Report& report, bool pending, bool uploadsEnabled)
{
	fmt::memory_buffer buf;

	if (pending)
	{
		ImGui::PushStyleColor(ImGuiCol_TableRowBg, IM_COL32(19, 185, 241, 23));
	}
	ImGui::TableNextRow();

	ImGui::TableNextColumn();
	ImGui::Text("%s", report.uuid.ToString().c_str());

	if (ImGui::BeginPopupContextItem("##GuidMenu"))
	{
		if (ImGui::MenuItem("Copy"))
		{
			ImGui::SetClipboardText(report.uuid.ToString().c_str());
		}

		ImGui::EndPopup();
	}

	if (ImGui::BeginItemTooltip())
	{
		buf.clear();

		if (report.last_upload_attempt_time)
			fmt::format_to(fmt::appender(buf), "{:%Y-%m-%d %H:%M:%S}", fmt::localtime(report.last_upload_attempt_time));
		else
			fmt::format_to(fmt::appender(buf), "Never");

		ImGui::Text("Last upload attempt: %.*s", (int)buf.size(), buf.data());
		ImGui::Text("Upload attempts: %d", report.upload_attempts);

		char byteSize[64];
		FormatBytes(byteSize, report.total_size);
		ImGui::Text("Total size: %s", byteSize);

		ImGui::Text("Right click to copy GUID");
		ImGui::EndTooltip();
	}

	ImGui::TableNextColumn();

	buf.clear();
	fmt::format_to(fmt::appender(buf), "{:%Y-%m-%d %H:%M:%S}", fmt::localtime(report.creation_time));
	ImGui::Text("%.*s", (int)buf.size(), buf.data());

	ImGui::TableNextColumn();
	ImGui::BeginDisabled();
	bool uploaded = report.uploaded;
	ImGui::Checkbox("##Uploaded", &uploaded);
	ImGui::EndDisabled();

	ImGui::TableNextColumn();
	if (!report.uploaded && uploadsEnabled)
	{
		ImGui::BeginDisabled(report.upload_explicitly_requested);
		if (ImGui::Button("Request Upload"))
		{
			s_database->RequestUpload(report.uuid);
		}
		ImGui::EndDisabled();

		ImGui::SameLine();
	}

	if (ImGui::Button("Delete"))
	{
		s_database->DeleteReport(report.uuid);
	}

	if (pending)
	{
		ImGui::PopStyleColor();
	}
}

void ShowCrashReportingPanel()
{
	if (gCrashpadInitialized && s_database)
	{
		ImGui::Text("Crashpad status:"); ImGui::SameLine();
		ImGui::TextColored(ImVec4(0, 1.0f, 0, 1.0f), "Ready");

		ImGui::Text("Crash report submissions:"); ImGui::SameLine();
		bool uploadsEnabled = false;
		if (s_database->GetSettings()->GetUploadsEnabled(&uploadsEnabled) && uploadsEnabled)
			ImGui::TextColored(ImVec4(0, 1.0f, 0, 1.0f), "Enabled");
		else
		{
			ImGui::TextColored(ImVec4(1.0f, 0, 0, 1.0f), "Disabled");

			if (ImGui::BeginItemTooltip())
			{
				ImGui::Text("Submissions are disabled because:");
				if (!gEnableCrashSubmissions)
					ImGui::BulletText("The EnableCrashSubmissions option is disabled");
				if (gCrashpadSubmissionURL.empty())
					ImGui::BulletText("The Submissions URL is not set");
				if constexpr (MQMAIN_VERSION_BUILD == 0)
					ImGui::BulletText("This build is not an official build");

				ImGui::EndTooltip();
			}
		}

		static char uuidStr[64] = {};
		if (uuidStr[0] == 0)
		{
			crashpad::UUID uuid;
			s_database->GetSettings()->GetClientID(&uuid);

			strcpy_s(uuidStr, uuid.ToString().c_str());
		}

		ImGui::Text("Client GUID:"); ImGui::SameLine();
		ImGui::SetNextItemWidth(280.0f);
		ImGui::InputText("##ClientGuid", uuidStr, 64, ImGuiInputTextFlags_ReadOnly);

		ImGui::Separator();

		ImGui::PushFont(mq::imgui::LargeTextFont);
		ImGui::Text("Crash Reports");
		ImGui::PopFont();

		std::vector<crashpad::CrashReportDatabase::Report> pendingReports;
		bool pendingValid = s_database->GetPendingReports(&pendingReports) == CrashReportDatabase::kNoError;

		std::vector<crashpad::CrashReportDatabase::Report> completedReports;
		bool completedValid = s_database->GetCompletedReports(&completedReports) == CrashReportDatabase::kNoError;

		size_t totalReports = (pendingValid ? pendingReports.size() : 0) + (completedValid ? completedReports.size() : 0);
		if (totalReports > 0)
		{
			struct CrashReport
			{
				const crashpad::CrashReportDatabase::Report* report;
				bool pending;
			};
			std::vector<CrashReport> allReports;
			allReports.reserve(totalReports);

			for (const auto& report : pendingReports)
			{
				allReports.push_back({ &report, true });
			}
			for (const auto& report : completedReports)
			{
				allReports.push_back({ &report, false });
			}

			std::sort(begin(allReports), end(allReports),
				[](const CrashReport& a, const CrashReport& b)
				{
					return a.report->creation_time > b.report->creation_time;
				});

			ImGui::Text("%d crash reports", (int)totalReports);

			if (ImGui::BeginTable("##CrashReports", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_ScrollY | ImGuiTableFlags_Resizable))
			{
				ImGui::TableSetupColumn("Crash GUID", ImGuiTableColumnFlags_WidthFixed, 280.0f);
				ImGui::TableSetupColumn("Time", ImGuiTableColumnFlags_WidthFixed, 140.0f);
				ImGui::TableSetupColumn("Uploaded");
				ImGui::TableSetupColumn("##Options");
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableHeadersRow();

				for (const auto& report : allReports)
				{
					ImGui::PushID(reinterpret_cast<void*>(static_cast<intptr_t>(report.report->creation_time)));
					ShowCrashReport(*report.report, report.pending, uploadsEnabled);
					ImGui::PopID();
				}

				ImGui::EndTable();
			}
		}
		else
		{
			ImGui::Text("No crash reports");
		}
	}
	else
	{
		ImGui::Text("Crashpad status:"); ImGui::SameLine();
		ImGui::TextColored(ImVec4(1.0f, 0, 0, 1.0f), "Error");
	}
}
