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

#include <cstdint>

namespace mq {

// Opaque value-type used to uniquely identify a plugin
struct MQPluginHandle
{
	explicit MQPluginHandle(uint64_t pluginID) : pluginID(pluginID) {}
	MQPluginHandle() = default;

	MQPluginHandle(const MQPluginHandle& other) : pluginID(other.pluginID) {}
	MQPluginHandle(MQPluginHandle&& other) noexcept : pluginID(std::exchange(other.pluginID, 0)) {}
	MQPluginHandle& operator=(const MQPluginHandle& other) { pluginID = other.pluginID; return *this; }
	MQPluginHandle& operator=(MQPluginHandle&& other) noexcept { pluginID = std::exchange(other.pluginID, 0); return *this; }

	uint64_t             pluginID = 0;
};

inline bool operator==(const MQPluginHandle& a, const MQPluginHandle& b) { return a.pluginID == b.pluginID; }
inline bool operator!=(const MQPluginHandle& a, const MQPluginHandle& b) { return a.pluginID != b.pluginID; }

} // namespace mq

namespace mqplugin
{
	extern mq::MQPluginHandle ThisPluginHandle;
}
