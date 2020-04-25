
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

namespace mq {

static void StringDB_Initialize();
static void StringDB_Shutdown();

static MQModule s_stringDBModule = {
	"StringDB",                    // Name
	true,                          // CanUnload
	StringDB_Initialize,
	StringDB_Shutdown,
};
DECLARE_MODULE_INITIALIZER(s_stringDBModule);

//----------------------------------------------------------------------------

class TokenCallbackEntry
{
public:
	int StringID;
	int CallbackID;
	fMQTokenMessageCmd Callback;

	TokenCallbackEntry(int StringID, int CallbackID, fMQTokenMessageCmd Callback)
		: StringID(StringID)
		, CallbackID(CallbackID)
		, Callback(Callback)
	{}
};

std::map<int, std::vector<std::unique_ptr<TokenCallbackEntry>>> s_callbackMap;
static int s_uniqueId = 0;

int AddTokenMessageCmd(int StringID, fMQTokenMessageCmd Command)
{
	s_callbackMap[StringID].push_back(std::make_unique<TokenCallbackEntry>(StringID, ++s_uniqueId, Command));
	return s_uniqueId;
}

void RemoveTokenMessageCmd(int StringID, int CallbackID)
{
	auto entry = s_callbackMap.find(StringID);
	if (entry != std::end(s_callbackMap))
	{
		entry->second.erase(std::remove_if(std::begin(entry->second), std::end(entry->second),
			[CallbackID](const std::unique_ptr<TokenCallbackEntry>& ptr)
			{
				return ptr && ptr->CallbackID == CallbackID;
			}),
			std::end(entry->second));
	}
}

// no need to copy the whole stream, just sweep a pointer over it and copy the individual elements.
TokenTextParam::TokenTextParam(const char* Data, DWORD Length)
{
	char const* DataBuffer = Data;
	DataBuffer += 4; // 4 bytes of padding

	World = *(bool*)DataBuffer;
	DataBuffer += 1;
	StringID = *(int*)DataBuffer;
	DataBuffer += 4;
	Color = *(int*)DataBuffer;
	DataBuffer += 4;

	// this could also currently be a loop of 9 elements since there are always currently 9 elements
	// but doing it this way provides a guarantee that we always get all reported data without needing
	// to adjust the code
	while (DataBuffer < Data + Length)
	{
		int len = *(int*)DataBuffer;
		DataBuffer += 4;
		Tokens.emplace_back(DataBuffer, len);
		DataBuffer += len;
	}
}

void msgTokenTextParam__Trampoline(const char*, DWORD);
void msgTokenTextParam__Detour(const char* Data, DWORD Length)
{
	if (Data)
	{
		auto entry = s_callbackMap.find(*(int*)(Data + 5));
		if (entry != std::end(s_callbackMap))
		{
			mq::TokenTextParam param(Data, Length);
			for (const auto& cmd : entry->second)
			{
				if (cmd)
					cmd->Callback(param);
			}
		}
	}

	msgTokenTextParam__Trampoline(Data, Length);
}
DETOUR_TRAMPOLINE_EMPTY(void msgTokenTextParam__Trampoline(const char*, DWORD))

static void StringDB_Initialize()
{
	EzDetour(__msgTokenTextParam, msgTokenTextParam__Detour, msgTokenTextParam__Trampoline);
}

static void StringDB_Shutdown()
{
	RemoveDetour(__msgTokenTextParam);
}

} // namespace mq
