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

#include <spdlog/spdlog.h>
#include <cpr/cpr.h>

std::string GetVersionStringLocal(const std::filesystem::path& filePath)
{
	std::error_code ec;
	if (exists(filePath, ec))
	{
		DWORD versionHandle;
		const DWORD versionInfoSize = GetFileVersionInfoSize(filePath.string().c_str(), &versionHandle);
		if (versionInfoSize != 0)
		{
			std::vector<BYTE> versionData(versionInfoSize);
			if (GetFileVersionInfo(filePath.string().c_str(), 0, versionInfoSize, versionData.data()))
			{
				VS_FIXEDFILEINFO* fileInfo = nullptr;
				uint32_t len = 0;
				if (VerQueryValue(versionData.data(), "\\", reinterpret_cast<LPVOID*>(&fileInfo), &len))
				{
					// Going to cheat here to keep this language independent -- it makes the assumption that the string is made up of the version which is not always true (but works for all of our use cases)
					return fmt::format("{Major:d}.{Minor:d}.{Build:d}.{Revision:d}",
					                   fmt::arg("Major", HIWORD(fileInfo->dwFileVersionMS)),
					                   fmt::arg("Minor", LOWORD(fileInfo->dwFileVersionMS)),
					                   fmt::arg("Build", HIWORD(fileInfo->dwFileVersionLS)),
					                   fmt::arg("Revision", LOWORD(fileInfo->dwFileVersionLS)));
				}
			}
		}
	}
	return "FAILED";
}

std::string GetVersionStringRemote(const std::string& versionURL)
{
	cpr::Response r = cpr::Get(cpr::Url{versionURL});
	if (r.status_code == 200)
	{
		return r.text;
	}
	return "FAILED";
}

void ShowWarningBlocking(const std::string& Message)
{
	SPDLOG_WARN(Message);
	MessageBox(nullptr, Message.c_str(), "MacroQuest", MB_OK | MB_ICONWARNING);
}

void ShowErrorBlocking(const std::string& Message)
{
	SPDLOG_ERROR(Message);
	MessageBox(nullptr, Message.c_str(), "MacroQuest", MB_OK | MB_ICONERROR);
}

void ThreadedMessage(const std::string& Message, int MessageType)
{
	std::thread message([messagebox_message = Message, messagebox_type = MessageType]()
	{
		SPDLOG_DEBUG("Message Box thread started: " + messagebox_message);
		MessageBox(nullptr, messagebox_message.c_str(), "MacroQuest", messagebox_type);
		SPDLOG_DEBUG("Message Box thread finished: " + messagebox_message);
	});

	message.detach();
}
