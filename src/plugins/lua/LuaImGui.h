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

#include "LuaCommon.h"
#include "imgui/imgui.h"

struct ImPlotContext;
struct iam_context;

namespace mq::lua {

class LuaThread;

class LuaImGui
{
public:
	LuaImGui(std::string_view name, const sol::thread& parent_thread, const sol::function& callback);
	~LuaImGui();

	bool Pulse() const;
	std::string_view GetName() { return m_name; }

private:
	std::string m_name;
	sol::thread m_thread;
	sol::function m_callback;
	mutable sol::coroutine m_coroutine;
	sol::thread m_parentThread;
};

struct LuaImAnimState
{
	LuaImAnimState();
	~LuaImAnimState();

	LuaImAnimState(const LuaImAnimState&) = delete;
	LuaImAnimState& operator=(const LuaImAnimState&) = delete;

	enum ClipCallbackType
	{
		CB_Begin = 0,
		CB_Update,
		CB_Complete,
		CB_Marker
	};

	struct ClipCallbackKey
	{
		ImGuiID clip_id;
		int type;

		bool operator==(const ClipCallbackKey& other) const
		{
			return clip_id == other.clip_id && type == other.type;
		}
	};

	struct ClipCallbackKeyHash
	{
		size_t operator()(const ClipCallbackKey& k) const
		{
			return std::hash<uint64_t>()(((uint64_t)k.clip_id << 32) | k.type);
		}
	};

	// Marker callback key
	struct MarkerCallbackKey
	{
		ImGuiID clip_id;
		ImGuiID marker_id;

		bool operator==(const MarkerCallbackKey& other) const
		{
			return clip_id == other.clip_id && marker_id == other.marker_id;
		}
	};

	struct MarkerCallbackKeyHash
	{
		size_t operator()(const MarkerCallbackKey& k) const
		{
			return std::hash<uint64_t>()(((uint64_t)k.clip_id << 32) | k.marker_id);
		}
	};

	iam_context* ctx = nullptr;
	std::array<sol::function, 16> ease_functions = {};

	uint32_t marker_counter = 0;

	// Clip and marker callback storage
	std::unordered_map<ClipCallbackKey, sol::function, ClipCallbackKeyHash> clip_callbacks;
	std::unordered_map<MarkerCallbackKey, sol::function, MarkerCallbackKeyHash> marker_callbacks;
};

class LuaImGuiProcessor
{
public:
	LuaImGuiProcessor(const LuaThread* thread);
	~LuaImGuiProcessor();

	void AddCallback(std::string_view name, sol::function callback);
	void RemoveCallback(std::string_view name);
	bool HasCallback(std::string_view name);
	void Pulse();

	void InitImAnimContext();

private:
	const LuaThread* m_thread;
	std::vector<std::unique_ptr<LuaImGui>> m_imguis;

	std::shared_ptr<ImPlotContext> m_imPlotContext;
	std::unique_ptr<LuaImAnimState> m_imAnimState;
};

} // namespace mq::lua
