/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2020 MacroQuest Authors
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

using namespace mq;

class SpawnBuffs
{
public:
	// timestamp of buff packet, target buff received in packet
	std::vector<CachedBuff> cachedBuffs;

	void Clear() noexcept { cachedBuffs.clear(); }

	void Audit()
	{
		cachedBuffs.erase(std::remove_if(std::begin(cachedBuffs), std::end(cachedBuffs),
			[](const CachedBuff& buff) { return buff.duration != -1 && buff.Duration() == 0U; }), std::end(cachedBuffs));
	}

	void Emplace(const CachedBuff& buff)
	{
		// by virtue of how we add to this vector, we won't have duplicates since we always clear before
		cachedBuffs.emplace_back(buff);
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
std::map<int, std::unique_ptr<SpawnBuffs>> cachedBuffMap;

class CEverQuestHook
{
public:
	void CTargetWnd__RefreshTargetBuffs_Trampoline(CUnSerializeBuffer&);
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

		buffer.Read(header.m_id); // TODO: double check that this is spawn ID!
		buffer.Read(header.m_timeNext); // TODO: see if this can be used for freshness!
		buffer.Read(header.m_bComplete);
		buffer.Read(header.m_count);

		auto [it, result] = cachedBuffMap.try_emplace(header.m_id, std::make_unique<SpawnBuffs>());
		it->second->Clear();

		for (int i = 0; i < header.m_count; i++)
		{
			CachedBuff curBuff;
			buffer.Read(curBuff.slot);
			buffer.Read(curBuff.spellId);
			buffer.Read(curBuff.duration);
			buffer.Read(curBuff.count);
			buffer.ReadpChar(curBuff.casterName);
			curBuff.timeStamp = EQGetTime();

			it->second->Emplace(curBuff);
		}

		gTargetbuffs = true;

		if (gbAssistComplete == AS_AssistSent)
			gbAssistComplete = AS_AssistReceived;
	}
};

DETOUR_TRAMPOLINE_EMPTY(void CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Trampoline(CUnSerializeBuffer&));

void mq::InitializeCachedBuffs()
{
	EzDetour(CTargetWnd__RefreshTargetBuffs, &CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Detour, &CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Trampoline);
}

void mq::ShutdownCachedBuffs()
{
	RemoveDetour(CTargetWnd__RefreshTargetBuffs);
}

std::optional<CachedBuff> mq::GetCachedBuffAtSlot(SPAWNINFO* pSpawn, int slot)
{
	if (pSpawn)
	{
		auto buffs = cachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(cachedBuffMap))
		{
			return buffs->second->Get([&slot](CachedBuff buff) { return buff.slot == slot; });
		}
	}

	return std::nullopt;
}

int mq::GetCachedBuff(SPAWNINFO* pSpawn, const std::function<bool(CachedBuff)>& predicate)
{
	if (pSpawn)
	{
		auto buffs = cachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(cachedBuffMap))
		{
			auto buff = buffs->second->Get(predicate);
			if (buff) return buff->slot;
		}
	}

	return -1;
}

int mq::GetCachedBuffAt(SPAWNINFO* pSpawn, size_t index)
{
	if (pSpawn)
	{
		auto buffs = cachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(cachedBuffMap))
		{
			auto buff = buffs->second->Get(index);
			if (buff) return buff->slot;
		}
	}

	return -1;
}

int mq::GetCachedBuffAt(SPAWNINFO* pSpawn, size_t index, const std::function<bool(CachedBuff)>& predicate)
{
	if (pSpawn)
	{
		auto buffs = FilterCachedBuffs(pSpawn, predicate);
		if (index >= 0 && index < buffs.size())
			return buffs.at(index).slot;
	}

	return -1;
}

std::vector<CachedBuff> mq::FilterCachedBuffs(SPAWNINFO* pSpawn, const std::function<bool(CachedBuff)>& predicate)
{
	if (pSpawn)
	{
		auto buffs = cachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(cachedBuffMap))
		{
			return buffs->second->Filter(predicate);
		}
	}

	return {};
}

DWORD mq::GetCachedBuffCount(SPAWNINFO* pSpawn, const std::function<bool(CachedBuff)>& predicate)
{
	if (pSpawn)
	{
		auto buffs = cachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(cachedBuffMap))
		{
			buffs->second->Audit();
			return std::count_if(std::begin(buffs->second->cachedBuffs), std::end(buffs->second->cachedBuffs), predicate);
		}
	}

	return 0U;
}

DWORD mq::GetCachedBuffCount(SPAWNINFO* pSpawn)
{
	if (pSpawn)
	{
		auto buffs = cachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(cachedBuffMap))
		{
			buffs->second->Audit();
			return buffs->second->cachedBuffs.size();
		}
	}

	return 0U;
}

void mq::ClearCachedBuffsSpawn(SPAWNINFO* pSpawn)
{
	if (pSpawn)
	{
		auto buffs = cachedBuffMap.find(pSpawn->SpawnID);
		if (buffs != std::end(cachedBuffMap))
			buffs->second->Clear();
	}
}

void mq::ClearCachedBuffs()
{
	cachedBuffMap.clear();
}
