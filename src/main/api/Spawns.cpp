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

#include "mq/api/Spawns.h"

#include "eqlib/game/Globals.h"
#include "eqlib/game/PcClient.h"
#include "eqlib/game/PlayerClient.h"

using namespace eqlib;

namespace mq {

bool IsMarkedNPC(PlayerClient* pSpawn)
{
	if (pLocalPlayer && pSpawn)
	{
		for (uint32_t id : pLocalPlayer->RaidMarkNPC)
		{
			if (id == pSpawn->SpawnID)
			{
				return true;
			}
		}

		for (uint32_t id : pLocalPlayer->GroupMarkNPC)
		{
			if (id == pSpawn->SpawnID)
			{
				return true;
			}
		}
	}

	return false;
}

int GetNPCMarkNumber(PlayerClient* pSpawn)
{
	if (pLocalPlayer && pSpawn)
	{
		for (int nMark = 0; nMark < 3; nMark++)
		{
			if (pLocalPlayer->RaidMarkNPC[nMark] == pSpawn->SpawnID)
			{
				return nMark + 1;
			}
		}

		for (int nMark = 0; nMark < 3; nMark++)
		{
			if (pLocalPlayer->GroupMarkNPC[nMark] == pSpawn->SpawnID)
			{
				return nMark + 1;
			}
		}
	}

	return 0;
}

uint32_t GetGroupMainAssistTargetID()
{
	if (!pLocalPC || !pLocalPC->Group) return 0;
	if (!pLocalPlayer) return 0;

	return pLocalPlayer->GroupAssistNPC[0];
}

uint32_t GetRaidMainAssistTargetID(int index)
{
	if (!pLocalPlayer) return 0;

	if (index < 0 || index >= MAX_RAID_ASSISTS)
		return 0;

	return pLocalPlayer->RaidAssistNPC[index];
}

bool IsAssistNPC(PlayerClient* pSpawn)
{
	if (!pSpawn) return false;

	uint32_t AssistID = GetGroupMainAssistTargetID();
	if (AssistID != 0 && AssistID == pSpawn->SpawnID)
	{
		return true;
	}

	for (int nAssist = 0; nAssist < MAX_RAID_ASSISTS; nAssist++)
	{
		AssistID = GetRaidMainAssistTargetID(nAssist);
		
		if (AssistID != 0 && AssistID == pSpawn->SpawnID)
		{
			return true;
		}
	}

	return false;
}

} // namespace mq
