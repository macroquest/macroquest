/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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
#include "lua_MQBindings.h"

#include "LuaCommon.h"
#include "LuaThread.h"

#include <mq/Plugin.h>

namespace mq::lua {

std::string lua_join(sol::this_state L, std::string_view delim, sol::variadic_args va)
{
	if (va.size() > 0)
	{
		fmt::memory_buffer str;
		std::string_view del;
		for (const auto& arg : va)
		{
			auto value = luaL_tolstring(arg.lua_state(), arg.stack_index(), nullptr);
			if (value != nullptr && strlen(value) > 0)
			{
				fmt::format_to(str, "{}{}", del, value);
				del = delim;
			}
		}

		return fmt::to_string(str);
	}

	return "";
}

//============================================================================

#pragma region Command Bindings

struct lua_MQCommand
{
	std::string command;

	lua_MQCommand(std::string_view command)
		: command(command)
	{
	}

	void operator()(sol::variadic_args va, sol::this_state s)
	{
		fmt::memory_buffer cmd;
		fmt::format_to(cmd, "{}", command);

		for (const auto& a : va)
		{
			auto value = luaL_tolstring(a.lua_state(), a.stack_index(), nullptr);
			if (value != nullptr && strlen(value) > 0)
				fmt::format_to(cmd, " {}", value);
		}

		HideDoCommand(pLocalPlayer, fmt::to_string(cmd).c_str(), false);

		if (!bRunNextCommand)
		{
			if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
			{
				thread_ptr->DoYield();
			}
		}
	}
};

struct lua_MQDoCommand
{
	// this is only used to provide a namespace for commands
	sol::object Get(sol::stack_object key, sol::this_state L) const
	{
		auto maybe_key = key.as<std::optional<std::string>>();
		if (maybe_key)
		{
			std::string cmd("/");
			cmd += *maybe_key;
			// do no validation. Any thing prefixed with `cmd` will be attempted to be submitted (they are pure side effect anyway)
			return sol::object(L, sol::in_place, lua_MQCommand(cmd));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	static void command_format(sol::variadic_args va, sol::this_state s)
	{
		// replicate string.format
		sol::function string_format = sol::state_view(s)["string"]["format"];
		std::string command = string_format(va);

		HideDoCommand(pLocalPlayer, command.c_str(), false);

		if (!bRunNextCommand)
		{
			if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
			{
				thread_ptr->DoYield();
			}
		}
	}

	static void command(sol::variadic_args va, sol::this_state s)
	{
		// replicate string.format
		std::string command = lua_join(s, " ", va);

		HideDoCommand(pLocalPlayer, command.c_str(), false);

		if (!bRunNextCommand)
		{
			if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
			{
				thread_ptr->DoYield();
			}
		}
	}

	// Provide direct access to DoCommand
	void operator()(sol::variadic_args va, sol::this_state s)
	{
		command(va, s);
	}
};

#pragma endregion

//============================================================================

static std::unique_ptr<CTextureAnimation> gettextanim(std::string_view name, sol::this_state s)
{
	auto anim = std::make_unique<CTextureAnimation>();

	if (pSidlMgr)
	{
		if (CTextureAnimation* temp = pSidlMgr->FindAnimation(CXStr(name)))
			*anim = *temp;
	}

	return anim;
}

//============================================================================

void MQ_RegisterLua_MQBindings(sol::table& mq)
{
	mq["configDir"] = gPathConfig;
	mq["join"] = &lua_join;

	//----------------------------------------------------------------------------
	// command bindings

	mq.new_usertype<lua_MQCommand>("command", sol::no_constructor);
	mq.new_usertype<lua_MQDoCommand>("docommand", sol::no_constructor,
		sol::meta_function::index, &lua_MQDoCommand::Get);
	mq["cmd"] = lua_MQDoCommand();
	mq["cmdf"] = &lua_MQDoCommand::command_format;

	//----------------------------------------------------------------------------
	// Macro bindings



	//----------------------------------------------------------------------------

	mq.new_usertype<CTextureAnimation>("CTextureAnimation",
		sol::no_constructor,
		"SetTextureCell", &CTextureAnimation::SetCurCell
	);
	mq["FindTextureAnimation"] = &gettextanim;
}

} // namespace mq::lua
