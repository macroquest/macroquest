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

#ifndef MQ2MAIN_EXPORTS
#error This header should only be included from the MQ2Main project
#endif

#include "mq/api/DetourAPI.h"
#include "mq/base/PluginHandle.h"

namespace mq {

class MQDetour final
{
public:
	MQDetour(uintptr_t address, void** target, void* detour, std::string_view name,
		const MQPluginHandle& pluginHandle);
	MQDetour(uintptr_t address, std::string_view name, size_t width, const MQPluginHandle& pluginHandle);

	~MQDetour();

	uintptr_t GetAddress() const { return m_address; }
	MQPluginHandle GetPluginHandle() const { return m_pluginHandle; }

	const uint8_t* GetBytes() const { return m_bytes.data(); }
	uint8_t* GetBytes() { return m_bytes.data(); }

	bool IsAddressInRange(uintptr_t address, size_t width) const
	{
		return std::max(m_address, address) < std::min(m_address + m_width, address + width);
	}

	bool IsAddressInRange(uintptr_t address) const
	{
		return address >= m_address && address < m_address + m_width;
	}

	MQDetour* next = nullptr;
	MQDetour* prev = nullptr;

private:
	const uintptr_t m_address;
	const std::string m_name;
	std::vector<uint8_t> m_bytes;
	void** m_target = nullptr;
	void* m_detour = nullptr;
	MQPluginHandle m_pluginHandle;
	size_t m_width = DETOUR_BYTES_COUNT;
};


enum class AddressDetourState {
	None = 0,
	CodeDetour = 1,
	KnownSkippable = 2,
};


class MQDetourAPI
{
public:
	MQDetourAPI();
	~MQDetourAPI();

	bool CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);
	bool CreateDetour(uintptr_t address, size_t width, std::string_view name,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	bool RemoveDetour(uintptr_t address,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	void RemoveDetours();

	AddressDetourState IsAddressDetoured(uintptr_t address, size_t width) const;

	MQDetour* FindDetour(uintptr_t address, size_t width = DETOUR_BYTES_COUNT) const;
	MQDetour* FindDetourExact(uintptr_t addrss) const;

	uint8_t GetDetouredByte(uintptr_t address, uint8_t original) const;

private:
	bool ValidateNewDetour(uintptr_t address, std::string_view name,
		const MQPluginHandle& pluginHandle) const;
};

extern MQDetourAPI* pDetourAPI;

} // namespace mq
