/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

namespace mqplugin {

HINSTANCE ghPluginModule = nullptr;
mq::MQPlugin* ThisPlugin = nullptr;
mq::MainInterface* MainInterface = nullptr;

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
	return mqplugin::MainInterface->AddTopLevelObject(szName, std::move(Function), mqplugin::ThisPlugin);
}

bool mq::RemoveTopLevelObject(const char* szName)
{
	return mqplugin::MainInterface->RemoveTopLevelObject(szName, mqplugin::ThisPlugin);
}

mq::MQTopLevelObject* mq::FindTopLevelObject(const char* szName)
{
	return mqplugin::MainInterface->FindTopLevelObject(szName);
}

void mq::postoffice::DropboxAPI::PostData(const Address& address, uint16_t messageId, const std::string& data)
{
	mqplugin::MainInterface->SendToActor(Dropbox, address, messageId, data, mqplugin::ThisPlugin);
}

void mq::postoffice::DropboxAPI::Remove()
{
	mqplugin::MainInterface->RemoveActor(Dropbox, mqplugin::ThisPlugin);
}

mq::postoffice::DropboxAPI mq::postoffice::AddActor(ReceiveCallback&& receive)
{
	if (mqplugin::ThisPlugin != nullptr)
	{
		return mq::postoffice::DropboxAPI{
			mqplugin::MainInterface->AddActor(mqplugin::ThisPlugin->name.c_str(), std::move(receive), mqplugin::ThisPlugin)
		};
	}

	return mq::postoffice::DropboxAPI{ nullptr };
}

mq::postoffice::DropboxAPI mq::postoffice::AddActor(const char* localAddress, ReceiveCallback&& receive)
{
	std::string address(localAddress);
	if (mqplugin::ThisPlugin != nullptr)
		address = fmt::format("{}:{}", mqplugin::ThisPlugin->name, address);


	return mq::postoffice::DropboxAPI{
		mqplugin::MainInterface->AddActor(address.c_str(), std::move(receive), mqplugin::ThisPlugin)
	};
}

//============================================================================

#if __has_include("../../private/pluginapi-private.cpp")
#include "../../private/pluginapi-private.cpp"
#endif
