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

#include "MQ2Main.h"

#include "MQPostOfficeInternal.cpp"

namespace mq {

static MQModule s_PostOfficeModule = {
	"PostOffice",
	false,
	[] { InitializePostOffice(); },                             // Initialize
	[] { ShutdownPostOffice(); },                               // Shutdown
	[] { PulsePostOffice(); },                                  // Pulse
	[](int GameState) { SetGameStatePostOffice(GameState); },   // SetGameState
	nullptr,                                                    // UpdateImGui
	nullptr,                                                    // Zoned
	nullptr,                                                    // WriteChatColor
	nullptr,                                                    // SpawnAdded
	nullptr,                                                    // SpawnRemoved
	nullptr,                                                    // BeginZone
	nullptr,                                                    // EndZone
	nullptr,                                                    // LoadPlugin
	nullptr                                                     // UnloadPlugin
};
MQModule* GetPostOfficeModule() { return &s_PostOfficeModule; }

template <>
PostOffice& postoffice::GetPostOffice<PostOffice>(uint32_t index)
{
	return postoffice::GetPostOffice<MQPostOffice>(index);
}

ActorIdentification::Client GetDefaultClient()
{
	ActorIdentification::Client client;
	if (__LoginName)
		client.account = (char*)__LoginName;

	if (strlen(pEverQuestInfo->WorldServerShortname) > 0)
		client.server = pEverQuestInfo->WorldServerShortname;

	if (pLocalPC)
		client.character = pLocalPC->Name;

	return client;
}

bool ShouldUpdateIdentity(int GameState, bool& logged_in)
{
	// 0 is sent from init
	if (GameState == 0)
	{
		if (pLocalPC)
			logged_in = true;

		return true;
	}

	if (logged_in && GameState != GAMESTATE_LOGGINGIN && GameState != GAMESTATE_INGAME)
	{
		// this is used only when we are changing characters
		logged_in = false;
		return true;
	}

	if (!logged_in && (GameState == GAMESTATE_LOGGINGIN || GameState == GAMESTATE_INGAME))
	{
		logged_in = true;
		return true;
	}

	return false;
}

namespace pipeclient {

void NotifyIsForegroundWindow(bool isForeground)
{
	GetPostOffice<MQPostOffice>().NotifyIsForegroundWindow(isForeground);
}

void RequestActivateWindow(HWND hWnd, bool sendMessage)
{
	GetPostOffice<MQPostOffice>().RequestActivateWindow(hWnd, sendMessage);
}

void SendNotification(const std::string& message, const std::string& title)
{
	static_cast<MQPostOffice&>(GetPostOffice()).SendNotification(message, title);
}

} // namespace pipeclient

} // namespace mq
