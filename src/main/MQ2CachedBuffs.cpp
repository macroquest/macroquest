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

#include <optional>

namespace mq {

class SpawnBuffs
{
public:
	// timestamp of buff packet, target buff received in packet
	std::vector<CachedBuff> cachedBuffs;

	void Clear() noexcept { cachedBuffs.clear(); }

	void Audit()
	{
		if (!pZoneInfo || !pZoneInfo->bNoBuffExpiration)
		{
			cachedBuffs.erase(std::remove_if(std::begin(cachedBuffs), std::end(cachedBuffs),
				[](const CachedBuff& buff) { return buff.duration >= 0 && buff.Duration() == 0U; }), std::end(cachedBuffs));
		}
	}

	template <typename ...Args>
	void Emplace(Args&& ... args)
	{
		// by virtue of how we add to this vector, we won't have duplicates since we always clear before
		cachedBuffs.emplace_back(std::forward<Args>(args)...);
	}

	auto Drop(std::function<bool(CachedBuff)> predicate)
	{
		return std::remove_if(std::begin(cachedBuffs), std::end(cachedBuffs),
			[&predicate](CachedBuff buff) { return predicate(buff); });
	}

	void Drop(int index)
	{
		cachedBuffs.erase(std::begin(cachedBuffs) + index);
	}

	std::optional<CachedBuff> Get(const std::function<bool(CachedBuff)>& predicate)
	{
		Audit();
		auto buff_it = std::find_if(std::begin(cachedBuffs), std::end(cachedBuffs),
			[&predicate](CachedBuff buff) { return predicate(buff); });

		if (buff_it != std::end(cachedBuffs))
			return *buff_it;

		return std::nullopt;
	}

	std::optional<CachedBuff> Get(size_t index)
	{
		Audit();
		if (index >= 0 && index < cachedBuffs.size())
			return cachedBuffs.at(index);

		return std::nullopt;
	}

	std::vector<CachedBuff> Filter(const std::function<bool(CachedBuff)>& predicate)
	{
		Audit();
		std::vector<CachedBuff> ret;
		for (auto b : cachedBuffs)
		{
			if (predicate(b))
				ret.emplace_back(b);
		}

		return ret;
	}
};

// spawnID -> spawn buffs
static std::map<int, std::unique_ptr<SpawnBuffs>> gCachedBuffMap;

class CEverQuestHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, CTargetWnd__RefreshTargetBuffs_Trampoline, (CUnSerializeBuffer&))
	void CTargetWnd__RefreshTargetBuffs_Detour(CUnSerializeBuffer& buffer)
	{
		gTargetbuffs = false;
		CTargetWnd__RefreshTargetBuffs_Trampoline(buffer);

		// the songs are sent with this packet, but this function just discards them. Unless there is another place
		// that parses this packet, then this is the best we can do.
		buffer.Reset();

		struct TargetHeader
		{
			int m_id;
			int m_timeNext;
			bool m_bComplete;
			short m_count;
		} header;

		buffer.Read(header.m_id); // This is spawn ID
		buffer.Read(header.m_timeNext); // TODO: see if this can be used for freshness!
		buffer.Read(header.m_bComplete); // is this a complete buff message?
		buffer.Read(header.m_count); // buffs being sent in this message (only full buff count if bComplete is true)

		// this boolean indicates if we are getting a full buff message;
		// apparently we often get single buffs sent down (especially for
		// shaman buffs), which aren't helpful to store (and will give
		// incorrect "BuffsPopulated" and "BuffCount" values). Only parse
		// full buff messages.
		if (header.m_bComplete)
		{
			auto [it, result] = gCachedBuffMap.try_emplace(header.m_id, std::make_unique<SpawnBuffs>());
			it->second->Clear();

			for (int i = 0; i < header.m_count; i++)
			{
				CachedBuff curBuff;
				buffer.Read(curBuff.slot);
				buffer.Read(curBuff.spellId);
				buffer.Read(curBuff.duration);
				buffer.Read(curBuff.count);
				buffer.ReadString(curBuff.casterName, lengthof(curBuff.casterName));
				curBuff.timeStamp = EQGetTime();

				it->second->Emplace(curBuff);
			}

			gTargetbuffs = true;
		}

		if (gbAssistComplete == AS_AssistSent)
			gbAssistComplete = AS_AssistReceived;
	}
};

std::optional<CachedBuff> GetCachedBuffAtSlot(SPAWNINFO* pSpawn, int slot)
{
	if (pSpawn)
	{
		auto buffs = gCachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(gCachedBuffMap))
		{
			return buffs->second->Get([&slot](const CachedBuff& buff) { return buff.slot == slot; });
		}
	}

	return std::nullopt;
}

int GetCachedBuff(SPAWNINFO* pSpawn, const std::function<bool(const CachedBuff&)>& predicate)
{
	if (pSpawn)
	{
		auto buffs = gCachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(gCachedBuffMap))
		{
			auto buff = buffs->second->Get(predicate);
			if (buff) return buff->slot;
		}
	}

	return -1;
}

int GetCachedBuffAt(SPAWNINFO* pSpawn, size_t index)
{
	if (pSpawn)
	{
		auto buffs = gCachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(gCachedBuffMap))
		{
			auto buff = buffs->second->Get(index);
			if (buff) return buff->slot;
		}
	}

	return -1;
}

int GetCachedBuffAt(SPAWNINFO* pSpawn, size_t index, const std::function<bool(const CachedBuff&)>& predicate)
{
	if (pSpawn)
	{
		auto buffs = FilterCachedBuffs(pSpawn, predicate);
		if (index >= 0 && index < buffs.size())
			return buffs.at(index).slot;
	}

	return -1;
}

std::vector<CachedBuff> FilterCachedBuffs(SPAWNINFO* pSpawn, const std::function<bool(const CachedBuff&)>& predicate)
{
	if (pSpawn)
	{
		auto buffs = gCachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(gCachedBuffMap))
		{
			return buffs->second->Filter(predicate);
		}
	}

	return {};
}

DWORD GetCachedBuffCount(SPAWNINFO* pSpawn, const std::function<bool(const CachedBuff&)>& predicate)
{
	if (pSpawn)
	{
		auto buffs = gCachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(gCachedBuffMap))
		{
			buffs->second->Audit();
			return static_cast<DWORD>(std::count_if(std::begin(buffs->second->cachedBuffs), std::end(buffs->second->cachedBuffs), predicate));
		}
	}

	return 0U;
}

DWORD GetCachedBuffCount(SPAWNINFO* pSpawn)
{
	if (pSpawn)
	{
		auto buffs = gCachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(gCachedBuffMap))
		{
			buffs->second->Audit();
			return static_cast<DWORD>(buffs->second->cachedBuffs.size());
		}
	}

	return 0U;
}

void ClearCachedBuffsSpawn(SPAWNINFO* pSpawn)
{
	if (pSpawn)
	{
		auto buffs = gCachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(gCachedBuffMap))
			buffs->second->Clear();
	}
}

void ClearCachedBuffs()
{
	gCachedBuffMap.clear();
}

void CachedBuffsCommand(PlayerClient* pChar, const char* szLine)
{
	if (!strcmp(szLine, "cleartarget"))
	{
		if (!pTarget)
		{
			WriteChatf("Select a target before using /cachedbuffs cleartarget");
			return;
		}

		ClearCachedBuffsSpawn(pTarget);
		WriteChatf("Cached Buffs for Target cleared.");
		return;
	}

	if (!strcmp(szLine, "reset"))
	{
		pTarget = nullptr;

		ClearCachedBuffs();
		WriteChatf("Cached Buffs for ALL Targets cleared.");
		return;
	}

	WriteChatf("\ayUsage: /cachedbuffs [cleartarget | reset]");
}

void InitializeCachedBuffs()
{
	EzDetour(CTargetWnd__RefreshTargetBuffs,
		&CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Detour,
		&CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Trampoline);
}

void ShutdownCachedBuffs()
{
	RemoveDetour(CTargetWnd__RefreshTargetBuffs);
}

} // namespace mq
