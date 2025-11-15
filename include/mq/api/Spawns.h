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

#pragma once

#include "mq/base/Common.h"

#include "eqlib/game/PlayerClient.h"

namespace mq {

/**
 * Returns true if the given spawn is marked by the group or raid.
 *
 * @param pSpawn The spawn to check
 * @return Whether the spawn is marked or not.
 */
MQLIB_API bool IsMarkedNPC(eqlib::PlayerClient* pSpawn);

/**
 * Returns the mark number for the given spawn if the spawn is marked.
 * If the spawn is not marked, returns zero.
 * 
 * @param pSpawn The spawn to check
 * @return The mark number of the spawn if it is marked.
 */
MQLIB_API int GetNPCMarkNumber(eqlib::PlayerClient* pSpawn);

/**
 * Returns the Spawn ID of the group main assist target, if one exists.
 * Otherwise returns zero.
 * 
 * @return The Spawn Id of the group main assist target.
 */
MQLIB_API uint32_t GetGroupMainAssistTargetID();

/**
 * Returns the Spawn ID of the specified raid main assist target, if one exists.
 * Otherwise returns zero. If the specified raid assist index is out of range,
 * also returns zero.
 * 
 * @return The Spawn ID of the specified raid main assist target.
 */
MQLIB_API uint32_t GetRaidMainAssistTargetID(int index);

/**
 * Returns true if the spawn is an assist target.
 * 
 * @param pSpawn The spawn to check
 * @return True if the spawn is an assist target.
 */
MQLIB_API bool IsAssistNPC(eqlib::PlayerClient* pSpawn);


} // namespace mq
