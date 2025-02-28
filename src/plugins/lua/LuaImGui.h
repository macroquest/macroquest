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

struct ImPlotContext;

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

class LuaImGuiProcessor
{
public:
	LuaImGuiProcessor(const LuaThread* thread);
	~LuaImGuiProcessor();

	void AddCallback(std::string_view name, sol::function callback);
	void RemoveCallback(std::string_view name);
	bool HasCallback(std::string_view name);
	void Pulse();

private:
	const LuaThread* m_thread;
	std::vector<std::unique_ptr<LuaImGui>> m_imguis;

	std::shared_ptr<ImPlotContext> m_imPlotContext;
};

} // namespace mq::lua
