/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

#include <mq/Plugin.h>

PreSetup("MQ2EQBugFix");

// This class implementation is specifically for the bug fix.
class CUnSerializeBuffer_BugFix
{
	const char* m_buffer = nullptr;
	uint32_t    m_length = 0;
	uint32_t    m_offset = 0;

public:
	DETOUR_TRAMPOLINE_DEF(bool, GetString_Trampoline, (char* dest, unsigned int destSize))
	bool GetString_Detour(char* dest, unsigned int destSize)
	{
		// Use our own implementation which does not have the bug.
		uint32_t size = (uint32_t)strnlen(m_buffer + m_offset, m_length - m_offset) + 1;
		uint32_t readAmount = std::min(static_cast<uint32_t>(destSize) - 1, size);

		if (m_offset + readAmount > m_length)
		{
			*dest = 0;
			return false;
		}

		memcpy(dest, m_buffer + m_offset, readAmount);
		dest[readAmount] = 0;
		m_offset += size;
		return true;
	}
};

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("Initializing MQ2EQBugFix");

	// Avoid a buffer over-read in CUnSerializeBuffer::GetString. This function will call strlen on
	// a network message that may already have been read to the end, resulting in a buffer over-read.
	// In some cases this will read past the end of the page boundary. If this happens, and the next
	// page isn't allocated, this will result in a crash. The fix is to use strnlen instead, so that
	// the strlen call is properly bounds checked.
	// As of the 5/21/2020 live patch, this happens occasionally when receiving guild names, regardless
	// of if MQ2 is loaded.
	EzDetour(CUnSerializeBuffer__GetString, &CUnSerializeBuffer_BugFix::GetString_Detour, &CUnSerializeBuffer_BugFix::GetString_Trampoline);
}

PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("Shutting down MQ2EQBugFix");

	RemoveDetour(CUnSerializeBuffer__GetString);
}

PLUGIN_API void OnPulse()
{
	if (gGameState == GAMESTATE_INGAME)
	{
		// If an ItemLocation is set on the CastingData, a Label might try to
		// render its name. If the item doesn't exist, it'll crash.
		if (pLocalPC && pLocalPC->me->CastingData.SpellID != -1)
		{
			if (pLocalPC->me->CastingData.ItemLocation.IsValidIndex()
				&& pLocalPC->GetItemByGlobalIndex(pLocalPC->me->CastingData.ItemLocation) == nullptr)
			{
				pLocalPC->me->CastingData.ItemLocation = ItemGlobalIndex();
			}
		}
	}
}
