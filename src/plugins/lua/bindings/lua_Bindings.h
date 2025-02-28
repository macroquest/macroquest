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

namespace mq::lua::bindings {

void RegisterBindings_EQ(LuaThread* thread, sol::table& mq);
void RegisterBindings_Globals(LuaThread* thread, sol::state_view sv);
void RegisterBindings_MQ(LuaThread* thread, sol::table& mq);
sol::table RegisterBindings_ImGui(sol::state_view sv);
void RegisterBindings_Bit32(sol::state_view sv);

sol::table RegisterBindings_ImPlot(sol::this_state L);
sol::table RegisterBindings_Zep(sol::this_state L);

void RegisterBindings_MQMacroData(sol::table& lua);
void InitializeBindings_MQMacroData();
void ShutdownBindings_MQMacroData();

} // namespace mq::lua::bindings
