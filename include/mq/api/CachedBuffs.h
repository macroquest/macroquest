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

#include "eqlib/game/ForwardDecls.h"
#include "eqlib/game/Globals.h"

#include <optional>
#include <vector>

namespace mq {

class CachedBuff
{
public:
	uint32_t Duration() const
	{
		uint32_t end = timeStamp + (duration * 6000);
		uint32_t now = eqlib::EQGetTime();

		if (end > now)
		{
			return end - now;
		}

		return 0UL;
	}

	uint32_t Staleness() const
	{
		return eqlib::EQGetTime() - timeStamp;
	}

	int      slot;
	int      spellId;
	int      duration;            // in ticks
	int      count;
	char     casterName[64];
	uint32_t timeStamp;
};


MQLIB_API    int         GetCachedBuff(eqlib::PlayerClient* pSpawn, const std::function<bool(const CachedBuff&)>& predicate);
MQLIB_API    int         GetCachedBuffAt(eqlib::PlayerClient* pSpawn, size_t index);
MQLIB_OBJECT int         GetCachedBuffAt(eqlib::PlayerClient* pSpawn, size_t index, const std::function<bool(const CachedBuff&)>& predicate);
MQLIB_OBJECT std::optional<CachedBuff> GetCachedBuffAtSlot(eqlib::PlayerClient* pSpawn, int slot);
MQLIB_OBJECT std::vector<CachedBuff> FilterCachedBuffs(eqlib::PlayerClient* pSpawn, const std::function<bool(const CachedBuff&)>& predicate);
MQLIB_API    uint32_t    GetCachedBuffCount(eqlib::PlayerClient* pSpawn);
MQLIB_OBJECT uint32_t    GetCachedBuffCount(eqlib::PlayerClient* pSpawn, const std::function<bool(const CachedBuff&)>& predicate);

MQLIB_OBJECT bool        HasSPA(const CachedBuff& buff, eqlib::eEQSPA eSPA, bool bIncrease = false);
MQLIB_OBJECT int         GetSpellCategory(const CachedBuff& buff);
MQLIB_OBJECT bool        IsSpellUsableForClass(const CachedBuff& buff, unsigned int classmask = 0);
MQLIB_OBJECT int         GetSpellSubcategory(const CachedBuff& buff);

MQLIB_OBJECT uint32_t    GetSpellID(const CachedBuff& buff);
MQLIB_OBJECT const char* GetSpellName(const CachedBuff& buff);
MQLIB_OBJECT const char* GetSpellCaster(const CachedBuff& buff);

MQLIB_API    bool        HasBuffCastByPlayer(eqlib::PlayerClient* pBuffOwner, const char* szBuffName, const char* casterName);


MQLIB_API int GetTargetBuffByCategory(uint32_t category, uint32_t classmask = 0, int startslot = 0);
MQLIB_API int GetTargetBuffBySubCat(const char* subcat, uint32_t classmask = 0, int startslot = 0);
MQLIB_API int GetTargetBuffBySPA(int spa, bool bIncrease, int startslot = 0);
MQLIB_API bool HasCachedTargetBuffSubCat(const char* subcat, eqlib::PlayerClient* pSpawn, void*, DWORD classmask = 0);
MQLIB_API bool HasCachedTargetBuffSPA(int spa, bool bIncrease, eqlib::PlayerClient* pSpawn, void*);

MQLIB_API bool TargetBuffCastByMe(const char* szBuffName);

MQLIB_API int GetSelfBuffByCategory(DWORD category, DWORD classmask = 0, int startslot = 0);
MQLIB_API int GetSelfBuffBySubCat(PCHAR subcat, DWORD classmask = 0, int startslot = 0);
MQLIB_API int GetSelfBuffBySPA(int spa, bool bIncrease, int startslot = 0);
MQLIB_API int GetSelfShortBuffBySPA(int spa, bool bIncrease, int startslot = 0);


} // namespace mq
