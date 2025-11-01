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
#include "lua_MQBindings.h"

#include "LuaCommon.h"
#include "LuaCoroutine.h"
#include "LuaEvent.h"
#include "LuaImGui.h"
#include "LuaThread.h"

#include <mq/Plugin.h>

#include "lua_Bindings.h"

namespace mq::lua::bindings {

//============================================================================

#pragma region Utility Bindings

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
				fmt::format_to(fmt::appender(str), "{}{}", del, value);
				del = delim;
			}
		}

		return fmt::to_string(str);
	}

	return "";
}

static uint64_t lua_gettime(sol::this_state s)
{
	auto t = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::steady_clock::now().time_since_epoch());

	return t.count();
}

static std::string lua_Parse(sol::this_state s, const char* text)
{
	if (text == nullptr)
	{
		luaL_argerror(s, 1, "Expected string, got nil");
		return {};
	}

	char buffer[MAX_STRING] = { 0 };
	strncpy_s(buffer, text, sizeof(buffer));
	auto old_parser = std::exchange(gParserVersion, 2);
	ParseMacroData(buffer, sizeof(buffer));
	gParserVersion = old_parser;
	return buffer;
}

#pragma endregion

//============================================================================

#pragma region Thread Bindings

static void lua_delay(sol::object delayObj, std::optional<sol::object> conditionObj, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (!thread_ptr->GetAllowYield())
		{
			switch (thread_ptr->GetYieldDisabledReason())
			{
			case YieldDisabledReason::Default:
				luaL_error(s.lua_state(), "Cannot delay from non-yieldable thread");
				break;

			case YieldDisabledReason::Require:
				luaL_error(s.lua_state(), "Cannot delay while importing a module");
				break;
			}
			return;
		}

		if (auto co_ptr = thread_ptr->GetCurrentCoroutine())
		{
			const bool toggled = luaJIT_setmode(s, 0, LUAJIT_MODE_ENGINE | LUAJIT_MODE_OFF) == 1;
			co_ptr->Delay(delayObj, conditionObj, s);
			if (toggled)
				luaJIT_setmode(s, 0, LUAJIT_MODE_ENGINE | LUAJIT_MODE_ON);
		}
	}
}

// also exposed as os.exit
void lua_exit(sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		thread_ptr->Exit(LuaThreadExitReason::Exit);
	}
}

#pragma endregion

//============================================================================

#pragma region Command Bindings

void ExecuteCommand(const std::string& cmdString, sol::this_state s)
{
	bool delayed = false;
	std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s);
	if (thread_ptr && !thread_ptr->GetAllowYield())
		delayed = true;

	HideDoCommand(pLocalPlayer, cmdString.c_str(), delayed);

	if (thread_ptr && thread_ptr->GetAllowYield() && !bRunNextCommand)
		thread_ptr->DoYield();
}

//----------------------------------------------------------------------------
// lua_MQCommand

lua_MQCommand::lua_MQCommand(std::string_view command)
	: command(command)
{
}

void lua_MQCommand::operator()(sol::variadic_args va, sol::this_state s)
{
	fmt::memory_buffer cmd;
	fmt::format_to(fmt::appender(cmd), "{}", command);

	for (const auto& a : va)
	{
		auto value = luaL_tolstring(a.lua_state(), a.stack_index(), nullptr);
		if (value != nullptr && strlen(value) > 0)
			fmt::format_to(fmt::appender(cmd), " {}", value);
	}

	ExecuteCommand(fmt::to_string(cmd).c_str(), s);
}

//----------------------------------------------------------------------------

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

		ExecuteCommand(command, s);
	}

	static void command(sol::variadic_args va, sol::this_state s)
	{
		// replicate string.format
		std::string command = lua_join(s, " ", va);

		ExecuteCommand(command, s);
	}

	// Provide direct access to DoCommand
	void operator()(sol::variadic_args va, sol::this_state s)
	{
		command(va, s);
	}
};

#pragma endregion

//============================================================================

#pragma region Event Bindings

static void lua_doevents(sol::variadic_args va, sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
		{
			std::vector<std::string> args;
			for (sol::stack_proxy a : va)
			{
				if (const auto& arg = a.as<std::optional<std::string>>())
					args.emplace_back(*arg);
			}

			events->PrepareEvents(args);
			thread_ptr->DoYield(); // doevents needs to yield, event processing will pick up next frame
		}
	}
}

static void lua_flushevents(sol::variadic_args va, sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
		{
			std::vector<std::string> args;
			for (sol::stack_proxy a : va)
			{
				if (const auto& arg = a.as<std::optional<std::string>>())
					args.emplace_back(*arg);
			}

			events->RemoveEvents(args);
		}
	}
}

static bool lua_addevent(std::string_view name, std::string_view expression, sol::function function,
	sol::optional<sol::table> options, sol::this_state s)
{
	if (function == sol::nil)
	{
		luaL_error(s, "nil function passed as event callback");
		return false;
	}

	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
			return events->AddEvent(name, expression, function, options);
	}

	return false;
}

static bool lua_removeevent(std::string_view name, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
			return events->RemoveEvent(name);
	}
	
	return false;
}

static bool lua_addbind(std::string_view name, sol::function function, sol::this_state s)
{
	if (function == sol::nil)
	{
		luaL_error(s, "nil function passed as bind callback");
		return false;
	}

	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
			return events->AddBind(name, function);
	}

	return false;
}

static bool lua_removebind(std::string_view name, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaEventProcessor* events = thread_ptr->GetEventProcessor())
			return events->RemoveBind(name);
	}

	return false;
}

#pragma endregion

//============================================================================

#pragma region ImGui Bindings

// We also bind these inside ImGui namespace
void lua_addimgui(std::string_view name, sol::function function, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaImGuiProcessor* imgui = thread_ptr->GetImGuiProcessor())
			imgui->AddCallback(name, function);
	}
}

void lua_removeimgui(std::string_view name, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaImGuiProcessor* imgui = thread_ptr->GetImGuiProcessor())
			imgui->RemoveCallback(name);
	}
}

static bool lua_hasimgui(std::string_view name, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaImGuiProcessor* imgui = thread_ptr->GetImGuiProcessor())
			return imgui->HasCallback(name);
	}

	return false;
}

#pragma endregion

#pragma region Serialization

static bool can_serialize(sol::object obj)
{
	switch (obj.get_type())
	{
	case sol::type::string:
	case sol::type::number:
	case sol::type::boolean:
	case sol::type::table:
		return true;
	default:
		return false;
	}
}

static void serialize(sol::object obj, int prefix_count, fmt::appender& appender)
{
	switch (obj.get_type())
	{
	case sol::type::string:
	{
		const char* str = obj.as<const char*>();
		size_t length = strlen(str);

		*appender++ = '\'';
		for (size_t pos = 0; pos < length; ++pos)
		{
			char c = str[pos];
			switch (c)
			{
			case '\\':
				*appender++ = '\\';
				*appender++ = '\\';
				break;
			case '\'':
				*appender++ = '\\';
				*appender++ = '\'';
				break;
			case '\r':
				*appender++ = '\\';
				*appender++ = 'r';
				break;
			case '\n':
				*appender++ = '\\';
				*appender++ = 'n';
				break;
			case '\t':
				*appender++ = '\\';
				*appender++ = 't';
				break;

			default:
				*appender++ = c;
				break;
			}
		}
		*appender++ = '\'';
		return;
	}
	case sol::type::number:
	{
		double number = obj.as<double>();
		if (std::floor(number) == number)
			fmt::format_to(appender, "{}", obj.as<int64_t>());
		else
			fmt::format_to(appender, "{}", obj.as<double>());
		return;
	}
	case sol::type::boolean:
		fmt::format_to(appender, "{}", obj.as<bool>());
		return;
	case sol::type::table:
	{
		if (obj.as<sol::table>().empty())
			fmt::format_to(appender, "{{}}");
		else
		{
			fmt::format_to(appender, "{{\n");

			for (const auto& [key, val] : obj.as<sol::table>())
			{
				if (can_serialize(val))
				{
					fmt::format_to(appender, "{:\t>{}}\t[", "", prefix_count);
					serialize(key, prefix_count + 1, appender);
					fmt::format_to(appender, "] = ");

					serialize(val, prefix_count + 1, appender);
					fmt::format_to(appender, ",\n");
				}
			}

			fmt::format_to(appender, "{:\t>{}}}}", "", prefix_count);
		}

		return;
	}
	// keep these here as reference. We don't want to serialize these things though, so they will all fall through to default (no serialization)
	case sol::type::none:
	case sol::type::lua_nil:
	case sol::type::thread:
	case sol::type::function:
	case sol::type::userdata:
	case sol::type::lightuserdata:
	case sol::type::poly:
	default:
		return; // we don't ever actually want to serialize nil, because nil removes an entry from a table
	}
}

static void lua_pickle(sol::this_state L, std::string_view file_path, sol::table table)
{
	fmt::memory_buffer buf;
	fmt::appender appender(buf);
	fmt::format_to(appender, "return ");
	serialize(table, 0, appender);

	std::filesystem::path path = std::filesystem::path{ gPathConfig } / file_path;

	std::error_code ec;
	std::filesystem::create_directories(path.parent_path(), ec);
	if (ec)
	{
		LuaError("Failed to create directory for pickling %.*s with error: %s", file_path.size(), file_path.data(), ec.message());
		return;
	}

	try
	{
		std::ofstream ofs(path, std::ios_base::out | std::ios_base::trunc);
		ofs << fmt::to_string(buf);
		ofs.close();
	}
	catch (std::exception e)
	{
		LuaError("Failed to write to file %.*s with error: %s", file_path.size(), file_path.data(), e.what());
	}
}

static sol::object lua_unpickle(sol::this_state L, std::string_view file_path)
{
	sol::state_view lua(L);
	std::filesystem::path path = std::filesystem::path{ gPathConfig } / file_path;

	try
	{
		sol::protected_function_result result = lua.do_file(path.string());
		if (!result.valid())
		{
			sol::error err = result;
			LuaError("Failed to execute file %.*s with error: %s", file_path.size(), file_path.data(), err.what());
			return sol::make_object(lua, sol::nil);
		}

		return sol::make_object(lua, result);
	}
	catch (std::exception& e)
	{
		LuaError("Exception occurred while unpickling file %.*s: %s", file_path.size(), file_path.data(), e.what());
		return sol::make_object(lua, sol::nil);
	}
}

#pragma endregion

//============================================================================

void RegisterBindings_MQ(LuaThread* thread, sol::table& mq)
{
	// values
	mq.set("configDir",                          gPathConfig);
	mq.set("luaDir",                             thread->GetLuaDir());
	mq.set("moduleDir",                          thread->GetModuleDir());

	// utility bindings
	mq.set_function("join",                      &lua_join);
	mq.set_function("gettime",                   &lua_gettime);
	mq.set_function("parse",                     &lua_Parse);
	mq.set_function("pickle",                    &lua_pickle);
	mq.set_function("unpickle",                  &lua_unpickle);

	mq.set_function("NumericLimits_Float",       [](){ return std::make_pair(FLT_MIN, FLT_MAX); });

	// thread bindings
	mq.set_function("delay",                     &lua_delay);
	mq.set_function("exit",                      &lua_exit);

	// event bindings
	mq.set_function("doevents",                  &lua_doevents);
	mq.set_function("flushevents",               &lua_flushevents);
	mq.set_function("event",                     &lua_addevent);
	mq.set_function("unevent",                   &lua_removeevent);
	mq.set_function("bind",                      &lua_addbind);
	mq.set_function("unbind",                    &lua_removebind);

	// imgui bindings (under mq.imgui.xxx)
	mq["imgui"] = mq.create_with(
		"init",                                  &lua_addimgui,
		"destroy",                               &lua_removeimgui,
		"exists",                                &lua_hasimgui
	);

	//----------------------------------------------------------------------------

	RegisterBindings_EQ(thread, mq);

	//----------------------------------------------------------------------------
	// command bindings

	mq.new_usertype<lua_MQCommand>(
		"command",                               sol::no_constructor);
	mq.new_usertype<lua_MQDoCommand>(
		"docommand",                             sol::no_constructor,
		sol::meta_function::index,               &lua_MQDoCommand::Get);

	mq.set("cmd",                                lua_MQDoCommand());
	mq.set_function("cmdf",                      &lua_MQDoCommand::command_format);

	//----------------------------------------------------------------------------

	mq.new_usertype<mq::MQTexture>(
		"MQTexture"                  , sol::no_constructor,
		"size"                       , sol::property([](const MQTexture& mThis) -> ImVec2 { return mThis.GetTextureSize(); }),
		"fileName"                   , sol::property(&mq::MQTexture::GetFilename),
		"GetTextureID"               , &mq::MQTexture::GetTextureID
	);
	mq.set_function("CreateTexture", [](const std::string& name) { return CreateTexturePtr(name); });
}

} // namespace mq::lua::bindings
