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

#include <mq/plugin/pluginapi.h>
#include <mq/api/Main.h>

char INIFileName[MAX_STRING] = { 0 };

#pragma comment(lib, "detours.lib")

namespace mqplugin {

HINSTANCE ghPluginModule = nullptr;
mq::MQPlugin* ThisPlugin = nullptr;
mq::MQPluginHandle ThisPluginHandle;
mq::MainInterface* MainInterface = nullptr;

PLUGIN_API void InitPluginHandle(mq::MQPlugin* thisPlugin, mq::MQPluginHandle thisPluginHandle)
{
	ThisPlugin = thisPlugin;
	ThisPluginHandle = thisPluginHandle;
}

// This is a sentinel that is used to identify a plugin as being built with the
// mqnext codebase.
PLUGIN_API bool IsBuiltForNext = true;

// Exported symbol that ensures that the plugin was built for the specified version of the game
PLUGIN_API const char EverQuestVersion[] = __ExpectedVersionDate " " __ExpectedVersionTime;

// Plugin Entrypoint
bool PluginMain(HINSTANCE hModule, DWORD dwReason, void* lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		ghPluginModule = hModule;
		mq::DebugSpewAlways("%s Module Loaded", mqplugin::PluginName);
		sprintf_s(INIFileName, "%s\\%s.ini", mq::gPathConfig, mqplugin::PluginName);

		mqplugin::MainInterface = mq::GetMainInterface();
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		mq::DebugSpewAlways("%s Module Unloaded", mqplugin::PluginName);
	}

	return true;
}

} // namespace mqplugin

//============================================================================
//============================================================================

bool mq::AddTopLevelObject(const char* szName, mq::MQTopLevelObjectFunction Function)
{
	return mqplugin::MainInterface->AddTopLevelObject(szName, std::move(Function), mqplugin::ThisPluginHandle);
}

bool mq::RemoveTopLevelObject(const char* szName)
{
	return mqplugin::MainInterface->RemoveTopLevelObject(szName, mqplugin::ThisPluginHandle);
}

mq::MQTopLevelObject* mq::FindTopLevelObject(const char* szName)
{
	return mqplugin::MainInterface->FindTopLevelObject(szName);
}

//============================================================================
//============================================================================

void mq::postoffice::DropboxAPI::Post(const mq::postoffice::Address& address, const std::string& data, const ResponseCallbackAPI& callback) const
{
	mqplugin::MainInterface->SendToActor(Dropbox, address, data, callback, mqplugin::ThisPluginHandle);
}

void mq::postoffice::DropboxAPI::PostReply(const std::shared_ptr<mq::postoffice::Message>& message, const std::string& data, uint8_t status) const
{
	mqplugin::MainInterface->ReplyToActor(Dropbox, message, data, status, mqplugin::ThisPluginHandle);
}

void mq::postoffice::DropboxAPI::Remove()
{
	mqplugin::MainInterface->RemoveActor(Dropbox, mqplugin::ThisPluginHandle);
}

mq::postoffice::DropboxAPI mq::postoffice::AddActor(ReceiveCallbackAPI&& receive)
{
	return mq::postoffice::DropboxAPI{
		mqplugin::MainInterface->AddActor(mqplugin::ThisPlugin->name.c_str(), std::move(receive), mqplugin::ThisPluginHandle)
	};
}

mq::postoffice::DropboxAPI mq::postoffice::AddActor(const char* localAddress, ReceiveCallbackAPI&& receive)
{
	fmt::memory_buffer buffer;
	auto appender = fmt::appender(buffer);

	fmt::format_to(appender, "{}:{}", mqplugin::ThisPlugin->name, localAddress);
	*appender = 0;

	return mq::postoffice::DropboxAPI{
		mqplugin::MainInterface->AddActor(buffer.data(), std::move(receive), mqplugin::ThisPluginHandle)
	};
}

void mq::postoffice::SendToActor(const Address& address, const std::string& data, const ResponseCallbackAPI& callback)
{
	mqplugin::MainInterface->SendToActor(nullptr, address, data, callback, mqplugin::ThisPluginHandle);
}

//============================================================================
//============================================================================

bool mq::AddCommand(std::string_view command, MQCommandHandler handler, bool eq, bool parse, bool inGame)
{
	return mqplugin::MainInterface->AddCommand(command, std::move(handler), eq, parse, inGame, mqplugin::ThisPluginHandle);
}

bool mq::RemoveCommand(std::string_view command)
{
	return mqplugin::MainInterface->RemoveCommand(command, mqplugin::ThisPluginHandle);
}

bool mq::IsCommand(std::string_view command)
{
	return mqplugin::MainInterface->IsCommand(command);
}

void mq::TimedCommand(const char* command, int msDelay)
{
	mqplugin::MainInterface->TimedCommand(command, msDelay, mqplugin::ThisPluginHandle);
}

void mq::DoCommand(const char* command, bool delayed)
{
	mqplugin::MainInterface->DoCommand(command, delayed, mqplugin::ThisPluginHandle);
}

void mq::DoCommandf(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;
	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);

	mqplugin::MainInterface->DoCommand(szOutput, false, mqplugin::ThisPluginHandle);;
}

void mq::HideDoCommand(PlayerClient* pChar, const char* command, bool delayed)
{
	UNUSED(pChar);

	mqplugin::MainInterface->DoCommand(command, delayed, mqplugin::ThisPluginHandle);
}

void mq::DoCommand(PlayerClient* pChar, const char* command)
{
	UNUSED(pChar);

	mqplugin::MainInterface->DoCommand(command, true, mqplugin::ThisPluginHandle);
}

void mq::EzCommand(const char* command)
{
	mqplugin::MainInterface->DoCommand(command, true, mqplugin::ThisPluginHandle);
}

bool mq::AddAlias(const std::string& alias, const std::string& replacement, bool persist)
{
	return mqplugin::MainInterface->AddAlias(alias, replacement, persist, mqplugin::ThisPluginHandle);
}

bool mq::RemoveAlias(const std::string& alias)
{
	return mqplugin::MainInterface->RemoveAlias(alias, mqplugin::ThisPluginHandle);
}

bool mq::IsAlias(const std::string& alias)
{
	return mqplugin::MainInterface->IsAlias(alias);
}

bool mq::detail::CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name)
{
	return mqplugin::MainInterface->CreateDetour(address, target, detour, name, mqplugin::ThisPluginHandle);
}

bool mq::RemoveDetour(uintptr_t address)
{
	return mqplugin::MainInterface->RemoveDetour(address, mqplugin::ThisPluginHandle);
}

bool mq::AddPatch(uintptr_t address, size_t width, std::string_view name)
{
	return mqplugin::MainInterface->AddPatch(address, width, name, mqplugin::ThisPluginHandle);
}

bool AddPatch(uintptr_t address, const uint8_t* newBytes, size_t numBytes,
	const uint8_t* expectedBytes, std::string_view name)
{
	return mqplugin::MainInterface->AddPatch(address, newBytes, numBytes, expectedBytes, name, mqplugin::ThisPluginHandle);
}

bool mq::RemovePatch(uintptr_t address)
{
	return mqplugin::MainInterface->RemovePatch(address, mqplugin::ThisPluginHandle);
}


//============================================================================

#if __has_include("../../private/pluginapi-private.cpp")
#include "../../private/pluginapi-private.cpp"
#endif
