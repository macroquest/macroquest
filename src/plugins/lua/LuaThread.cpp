/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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
#include "LuaThread.h"
#include "LuaCoroutine.h"
#include "LuaEvent.h"
#include "LuaImGui.h"
#include "LuaActor.h"
#include "bindings/lua_Bindings.h"

#include <mq/Plugin.h>
#include <luajit.h>
#include <chrono>
#include <fmt/format.h>

#if LUAJIT_VERSION_NUM == 20005
bool lua_isyieldable(lua_State* L)
{
#if _M_AMD64
	constexpr int offset = 0x30;
#else
	constexpr int offset = 0x28;
#endif

	// this is defined in luajit 2.1, but not in 2.0.5 -- this is a hack that is steady because
	// it's a single version, and it's preferable to pulling in 2 internal luajit headers to do
	// this nicely (lj_obj.h and lj_frame.h)

	// return ((intptr_t)(L->cframe) & CFRAME_RESUME);
	return (*(intptr_t*)((char*)L + offset) & 1);
}
#endif

namespace mq::lua {

//============================================================================

static uint32_t NextID()
{
	// no need to do anything special, this will be fine
	static uint32_t current = 0;
	return ++current;
}

std::shared_ptr<mq::lua::LuaThread> GetLuaThreadByPID(int pid);
void OnLuaThreadDestroyed(LuaThread* thread);
void OnLuaTLORemoved(MQTopLevelObject* tlo, int pidOwner);


// Mapping of TLOs to the pid of the script that created it
std::unordered_map<const MQTopLevelObject*, int> s_allRegisteredTLOs;

//============================================================================

void LuaThreadInfo::SetResult(const sol::protected_function_result& result, bool evaluate)
{
	if (result.status() != sol::call_status::yielded)
	{
		EndRun();

		if (result.return_count() >= 1)
		{
			returnValues = std::vector<std::string>(result.return_count());

			// need to skip the first "return" (which is not a return, it's at index + 0) which is the function itself
			for (int i = 0; i < result.return_count(); ++i)
			{
				returnValues[i] = luaL_tolstring(result.lua_state(), result.stack_index() + i, nullptr);
			}

			if (evaluate)
			{
				std::string results;

				for (const std::string& returnValue : returnValues)
				{
					if (!results.empty())
						results.append("\t");

					results.append(returnValue);
				}

				WriteChatColor(results.c_str(), USERCOLOR_CHAT_CHANNEL);
			}
		}
	}
}

void LuaThreadInfo::EndRun()
{
	status = LuaThreadStatus::Exited;
	endTime = std::chrono::system_clock::now();
}

//============================================================================
//============================================================================

LuaThread::LuaThread(this_is_private&&, LuaEnvironmentSettings* environment)
	: m_luaEnvironmentSettings(environment)
	, m_name("(unnamed)")
	, m_pid(NextID())
	, m_coroutine(LuaCoroutine::Create(sol::thread::create(m_globalState), this))
{
	m_globalState.open_libraries();
	m_luaEnvironmentSettings->ConfigureLuaState(m_globalState);

	m_environment = sol::environment(m_globalState, sol::create, m_globalState.globals());
	m_environment.set_on(m_coroutine->thread);

	m_threadTable = m_globalState.create_table();
}

LuaThread::~LuaThread()
{
	RemoveAllDataObjects();
}

/*static*/ std::shared_ptr<LuaThread> LuaThread::Create(LuaEnvironmentSettings* environment)
{
	std::shared_ptr<LuaThread> luaThread = std::make_shared<LuaThread>(this_is_private{}, environment);
	luaThread->Initialize();

	return luaThread;
}

void LuaThread::Initialize()
{
	bindings::RegisterBindings_Globals(this, m_globalState);
	bindings::RegisterBindings_Bit32(m_globalState);

	m_globalState.add_package_loader(LuaThread::lua_PackageLoader);
}

void LuaThread::EnableImGui()
{
	if (!m_imguiProcessor)
	{
		m_imguiProcessor = std::make_unique<LuaImGuiProcessor>(this);
	}
}

void LuaThread::EnableEvents()
{
	if (!m_eventProcessor)
	{
		m_eventProcessor = std::make_unique<LuaEventProcessor>(this);
	}
}

void LuaThread::InjectMQNamespace()
{
	RegisterMQNamespace(m_globalState);

	m_globalState["mq"] = *m_mqTable;
}

void LuaThread::Exit(LuaThreadExitReason reason)
{
	m_exitReason = reason;
	YieldAt(0);

	OnLuaThreadDestroyed(this);
	m_coroutine->thread.abandon();
}

std::pair<uint32_t, sol::thread> LuaThread::CreateThread()
{
	auto thread = sol::thread::create(m_globalState);
	m_environment.set_on(thread);
	m_threadTable[m_threadIndex] = thread;

	// note the mutation here, it's important that we mutate exactly once after we have done any work with it
	return std::make_pair(m_threadIndex++, thread);
}

void LuaThread::RemoveThread(uint32_t index)
{
	m_threadTable[index] = sol::lua_nil;
}

void LuaThread::RegisterMQNamespace(sol::state_view sv)
{
	if (!m_mqTable.has_value())
	{
		auto mq = sv.create_table();
		bindings::RegisterBindings_MQ(this, mq);
		bindings::RegisterBindings_MQMacroData(mq);

		m_mqTable = mq;
	}
}

int LuaThread::PackageLoader(const std::string& pkg, lua_State* L)
{
	sol::state_view sv{ L };

	if (pkg == "mq")
	{
		RegisterMQNamespace(sv);
		m_globalState.set("_mq_internal_table", *m_mqTable);

		std::string_view script("return _mq_internal_table");
		luaL_loadbuffer(sv, script.data(), script.size(), pkg.c_str());
		return 1;
	}

	if (pkg == "actors")
	{
		sol::stack::push(L, std::function([](sol::this_state L) { return LuaActors::RegisterLua(L); }));
		return 1;
	}

	if (pkg == "ImGui")
	{
		bindings::RegisterBindings_ImGui(sv);

		std::string_view script("return ImGui");
		luaL_loadbuffer(sv, script.data(), script.size(), pkg.c_str());
		return 1;
	}

	return 0;
}

/*static*/ int LuaThread::lua_PackageLoader(lua_State* L)
{
	std::string pkg = sol::stack::get<std::string>(L);

	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(L))
	{
		return thread_ptr->PackageLoader(pkg, L);
	}

	return 0;
}

//============================================================================
//============================================================================

bool LuaThread::IsValid() const
{
	return m_coroutine->thread.valid();
}

sol::state_view LuaThread::GetState() const
{
	return m_globalState;
}

sol::thread LuaThread::GetLuaThread() const
{
	return m_coroutine->thread;
}

//----------------------------------------------------------------------------

std::optional<LuaThreadInfo> LuaThread::StartFile(
	std::string_view filename, const std::vector<std::string>& args)
{
	namespace fs = std::filesystem;

	// filename here is canonical file name, but we need to reconstruct the path
	auto script_path = GetScriptPath(filename, m_luaEnvironmentSettings->luaDir);
	if (script_path.empty())
		return std::nullopt;

	// prefix the package paths with the runDir if it's different than the luaDir
	std::string runDir = fs::path{ script_path }.parent_path().string();
	if (!runDir.empty() && fs::path{ runDir }.compare(m_luaEnvironmentSettings->luaDir) != 0)
	{
		m_globalState["package"]["path"] = fmt::format("{runDir}\\?\\init.lua;{runDir}\\?.lua;{existingPath}",
			fmt::arg("runDir", runDir),
			fmt::arg("existingPath", m_globalState["package"]["path"].get<std::string_view>()));

		m_globalState["package"]["cpath"] = fmt::format("{runDir}\\?.dll;{existingPath}",
			fmt::arg("runDir", runDir),
			fmt::arg("existingPath", m_globalState["package"]["cpath"].get<std::string_view>()));
	}

	m_name = GetCanonicalScriptName(script_path, m_luaEnvironmentSettings->luaDir);
	m_path = script_path;

	auto co = m_coroutine->thread.state().load_file(script_path);
	if (!co.valid())
	{
		sol::error err = co;
		LuaError("Failed to load script %s with error: %s", m_name.c_str(), err.what());
		return std::nullopt;
	}

	m_coroutine->coroutine = co;
	YieldAt(m_turboNum);

	auto start_time = std::chrono::system_clock::now();
	CoroutineResult result = m_coroutine->RunCoroutine(args);

	LuaThreadInfo ret{
		m_pid,
		m_name,
		m_path,
		args,
		start_time,
		{},
		{},
		LuaThreadStatus::Starting,
		false
	};

	if (result)
		ret.SetResult(*result, m_evaluateResult);
	else if (m_coroutine->coroutine.status() != sol::call_status::yielded)
		ret.EndRun();

	return ret;
}

std::optional<LuaThreadInfo> LuaThread::StartString(std::string_view script,
	std::string_view name /* = "" */)
{
	m_isString = true;

	if (!name.empty())
	{
		m_name = name;
	}

	if (m_evaluateResult)
	{
		std::string evalScript = fmt::format("return {}", script);
		sol::load_result co = m_coroutine->thread.state().load(evalScript);

		if (co.valid())
		{
			m_coroutine->coroutine = co;
		}
	}

	if (!m_coroutine->coroutine.valid())
	{
		// Failed to evaluate as an expression.
		m_evaluateResult = false;
		sol::load_result co = m_coroutine->thread.state().load(script);
		if (!co.valid())
		{
			sol::error err = co;
			LuaError("Failed to load script with error: %s", err.what());
			return std::nullopt;
		}
		else
		{
			m_coroutine->coroutine = co;
		}
	}

	YieldAt(m_turboNum);

	auto start_time = std::chrono::system_clock::now();
	CoroutineResult result = m_coroutine->RunCoroutine();

	LuaThreadInfo ret{
		m_pid,
		m_name,
		std::string(script),
		{},
		start_time,
		{},
		{},
		LuaThreadStatus::Starting,
		true
	};

	if (result)
		ret.SetResult(*result, m_evaluateResult);
	else if (m_coroutine->coroutine.status() != sol::call_status::yielded)
		ret.EndRun();

	return ret;
}

LuaThread::RunResult LuaThread::Run()
{
	if (m_coroutine->coroutine.status() == sol::call_status::yielded)
	{
		return RunOnce();
	}

	return { static_cast<sol::thread_status>(m_coroutine->coroutine.status()), std::nullopt };
}

sol::thread_status LuaThread::GetThreadStatus() const
{
	if (!m_coroutine->thread.valid())
		return sol::thread_status::dead;

	return m_coroutine->thread.status();
}

std::string LuaThread::GetScriptPath(std::string_view script, const std::filesystem::path& luaDir)
{
	namespace fs = std::filesystem;

	std::error_code ec;
	const auto script_path = fs::absolute(luaDir / script, ec).lexically_normal();
	const auto lua_path = script_path.parent_path() / (script_path.filename().string() + ".lua");

	if (fs::exists(script_path, ec) && fs::is_directory(script_path, ec) && fs::exists(script_path / "init.lua", ec))
	{
		return (script_path / "init.lua").string();
	}
	else if (!fs::exists(script_path, ec) && fs::exists(lua_path, ec) && fs::is_directory(lua_path, ec) && fs::exists(lua_path / "init.lua", ec))
	{
		return (lua_path / "init.lua").string();
	}
	else if (fs::exists(script_path, ec) && !fs::is_directory(script_path, ec))
	{
		return script_path.string();
	}
	else if (fs::exists(lua_path, ec) && !fs::is_directory(lua_path, ec))
	{
		return lua_path.string();
	}

	LuaError("Cannot find %.*s in the filesystem.", script.size(), script.data());
	return {};
}

std::string LuaThread::GetCanonicalScriptName(std::string_view script, const std::filesystem::path& luaDir)
{
	namespace fs = std::filesystem;

	std::error_code ec;
	auto script_path = fs::absolute(luaDir / script, ec).lexically_normal();

	auto relative = script_path.lexically_relative(luaDir);
	if (!relative.empty() && relative.native()[0] != '.')
		script_path = relative;

	if (ci_equals(script_path.filename().string(), "init.lua"))
		script_path = script_path.parent_path();
	else if (script_path.extension() == ".lua")
		script_path.replace_extension("");

	return mq::replace(script_path.string(), "\\", "/");
}

void LuaThread::UpdateLuaDir(const std::filesystem::path& newLuaDir)
{
	m_name = GetCanonicalScriptName(m_path, newLuaDir);
	m_luaEnvironmentSettings->luaDir = newLuaDir.string();
}

LuaThread::RunResult LuaThread::RunOnce()
{
	if (!m_coroutine->thread.valid())
		return { sol::thread_status::dead, std::nullopt };

	if (m_coroutine->thread.status() != sol::thread_status::ok && m_coroutine->thread.status() != sol::thread_status::yielded)
	{
		return { m_coroutine->thread.status(), std::nullopt };
	}

	DataTypeTemp.push_buffer(buffer);

	if (m_eventProcessor)
	{
		// TODO: allow the user to set "aggressive" events (which gets prepared here) and "passive" binds (which would Get prepared in `doevents`)
		m_eventProcessor->PrepareBinds();
	}

	YieldAt(m_turboNum);
	m_yieldToFrame = false;

	if (m_eventProcessor)
	{
		m_eventProcessor->RunEvents(*this);
	}

	if (!m_coroutine->ShouldRun())
	{
		DataTypeTemp.pop_buffer();
		return { m_coroutine->thread.status(), std::nullopt };
	}

	if (!m_yieldToFrame)
	{
		CoroutineResult result = m_coroutine->RunCoroutine();
		sol::thread_status status = result ? static_cast<sol::thread_status>(result->status()) : sol::thread_status::dead;
		DataTypeTemp.pop_buffer();
		return std::make_pair(std::move(status), std::move(result));
	}

	DataTypeTemp.pop_buffer();

	if (!m_coroutine->thread.valid())
	{
		return { sol::thread_status::dead, std::nullopt };
	}

	return { m_coroutine->thread.status(), std::nullopt };
}

LuaThreadStatus LuaThread::Pause()
{
	if (m_paused)
	{
		YieldAt(m_turboNum);

		WriteChatStatus("Resuming paused lua script '%s' with PID %d", m_name.c_str(), m_pid);
		m_paused = false;

		return LuaThreadStatus::Running;
	}

	// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
	YieldAt(0);

	WriteChatStatus("Pausing running lua script '%s' with PID %d", m_name.c_str(), m_pid);
	m_paused = true;

	return LuaThreadStatus::Paused;
}

// this is the special sauce that lets us execute everything on the main thread without blocking
/*static*/ void LuaThread::lua_forceYield(lua_State* L, lua_Debug* D)
{
	if (lua_isyieldable(L))
	{
		if (std::shared_ptr<LuaThread> thread_ptr = get_from(L))
		{
			thread_ptr->m_yieldToFrame = true;
		}

		lua_yield(L, 0);
	}
	else if (D->event != LUA_HOOKRET && D->event != LUA_HOOKTAILRET) // if we have either of these, we know we've already set the hook
	{
		// we can just keep retrying at every return (every chance we get to possibly change boundaries)
		lua_sethook(L, LuaThread::lua_forceYield, LUA_MASKRET, 0);
	}
}

void LuaThread::YieldAt(int count) const
{
	if (m_allowYield)
	{
		lua_sethook(m_coroutine->thread.state(), &LuaThread::lua_forceYield, count == 0 ? LUA_MASKLINE : LUA_MASKCOUNT, count);
	}
}

//============================================================================

bool LuaThread::AddTopLevelObject(const char* name, MQTopLevelObjectFunction func)
{
	if (mq::AddTopLevelObject(name, std::move(func)))
	{
		m_registeredTLOs.emplace(name);

		MQTopLevelObject* tlo = FindTopLevelObject(name);
		s_allRegisteredTLOs.emplace(tlo, m_pid);
		return true;
	}

	return false;
}

bool LuaThread::RemoveTopLevelObject(const char* name)
{
	if (m_registeredTLOs.erase(name) == 0)
		return false;

	MQTopLevelObject* tlo = FindTopLevelObject(name);

	auto iter = s_allRegisteredTLOs.find(tlo);
	if (iter != end(s_allRegisteredTLOs))
	{
		int pid = iter->second;
		s_allRegisteredTLOs.erase(iter);

		OnLuaTLORemoved(tlo, pid);
	}

	return mq::RemoveTopLevelObject(name);
}

void LuaThread::RemoveAllDataObjects()
{
	for (const std::string& name : m_registeredTLOs)
	{
		MQTopLevelObject* tlo = FindTopLevelObject(name.c_str());

		auto iter = s_allRegisteredTLOs.find(tlo);
		if (iter != end(s_allRegisteredTLOs))
		{
			int pid = iter->second;
			s_allRegisteredTLOs.erase(iter);

			OnLuaTLORemoved(tlo, pid);
		}

		mq::RemoveTopLevelObject(name.c_str());
	}

	m_registeredTLOs.clear();
}

//----------------------------------------------------------------------------

void LuaThread::AssociateTopLevelObject(const MQTopLevelObject* tlo)
{
	if (tlo->Owner != nullptr)
	{
		if (tlo->Owner == mqplugin::ThisPlugin)
		{
			if (AddDependency(tlo))
			{
				AddNamedDependency(fmt::format("tlo:{}", tlo->Name.c_str()));
			}

			// TLO is owned by lua. Probably a lua script.
			auto it = s_allRegisteredTLOs.find(tlo);
			if (it != end(s_allRegisteredTLOs))
			{
				int pid = it->second;
				if (const auto& luaThread = GetLuaThreadByPID(pid))
				{
					if (AddDependency(luaThread.get()))
					{
						AddNamedDependency(fmt::format("lua:{}", luaThread->GetName()));
					}
				}
			}
		}
		else
		{
			if (AddDependency(tlo->Owner))
				AddNamedDependency(fmt::format("plugin:{}", tlo->Owner->name));
		}
	}
}

//============================================================================

} // namespace mq::lua
