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

namespace eqlib
{
	class MemoryPatcher;
	class MemoryPatch;
}

namespace mq {

enum class AddressDetourState {
	None = 0,
	CodeDetour = 1,
	KnownSkippable = 2,
};

class MQDetourAPI
{
public:
	MQDetourAPI(eqlib::MemoryPatcher* memoryPatcher);
	~MQDetourAPI();

	bool CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);
	bool CreateDetour(uintptr_t address, size_t width, std::string_view name,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	bool RemoveDetour(uintptr_t address,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	AddressDetourState IsAddressDetoured(uintptr_t address, size_t width) const;

	std::vector<eqlib::MemoryPatch*> FindPatches(uintptr_t address, size_t width);

private:
	bool ValidateNewPatch(uintptr_t address, std::string_view name,
		const MQPluginHandle& pluginHandle) const;

	eqlib::MemoryPatcher* m_memoryPatcher = nullptr;
};

extern MQDetourAPI* pDetourAPI;

} // namespace mq
