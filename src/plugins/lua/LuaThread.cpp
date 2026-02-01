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
#include "LuaThread.h"
#include "LuaCoroutine.h"
#include "LuaEvent.h"
#include "LuaImGui.h"
#include "LuaActor.h"
#include "LuaModuleRegistry.h"
#include "bindings/lua_Bindings.h"
#include "bindings/lua_MQBindings.h"

#include <mq/base/String.h>
#include <mq/Plugin.h>
#include <lauxlib.h>
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

	m_imguiProcessor.reset();
	m_eventProcessor.reset();
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
	m_globalState["mq"] = RegisterMQNamespace(m_globalState.lua_state());
}

void LuaThread::Exit(LuaThreadExitReason reason)
{
	if (m_exitReason != LuaThreadExitReason::Unspecified || !IsValid())
		return;

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

sol::table LuaThread::RegisterMQNamespace(sol::this_state L)
{
	sol::state_view sv{ L };

	auto mq = sv.create_table();
	bindings::RegisterBindings_MQ(this, mq);
	bindings::RegisterBindings_MQMacroData(mq);

	return mq;
}

int LuaThread::PackageLoader(const std::string& pkg, lua_State* L)
{
	constexpr std::string_view kPluginPrefixDot = "plugin.";
	constexpr std::string_view kPluginPrefixSlash = "plugin/";
	std::string_view pkg_view{ pkg };
	std::string_view plugin_name;

	if (ci_starts_with(pkg_view, kPluginPrefixDot))
		plugin_name = pkg_view.substr(kPluginPrefixDot.size());
	else if (ci_starts_with(pkg_view, kPluginPrefixSlash))
		plugin_name = pkg_view.substr(kPluginPrefixSlash.size());

	if (!plugin_name.empty())
	{
		MQPlugin* ownerPlugin = GetPlugin(plugin_name);
		if (!ownerPlugin)
			return 0;

		using CreateLuaModule = sol::object (*)(sol::this_state);
		auto module_proc = reinterpret_cast<CreateLuaModule>(
			GetPluginProc(ownerPlugin->szFilename, "CreateLuaModule"));
		if (!module_proc)
			return 0;

		std::string owner_name = ownerPlugin->name;
		std::string module_name = pkg;
		sol::stack::push(L, std::function([this, owner_name, module_name](sol::this_state L)
		{
			MQPlugin* plugin = GetPlugin(owner_name);
			if (!plugin)
			{
				luaL_error(L, "Module '%s' owner is no longer loaded", module_name.c_str());
				return sol::make_object(L, sol::nil);
			}

			using CreateLuaModule = sol::object (*)(sol::this_state);
			auto proc = reinterpret_cast<CreateLuaModule>(
				GetPluginProc(plugin->szFilename, "CreateLuaModule"));
			if (!proc)
			{
				luaL_error(L, "Module '%s' does not export CreateLuaModule", module_name.c_str());
				return sol::make_object(L, sol::nil);
			}

			if (AddDependency(plugin))
				AddNamedDependency(fmt::format("module:{}(plugin:{})", module_name, plugin->name));

			try
			{
				return proc(L);
			}
			catch (const std::exception& e)
			{
				luaL_error(L, "Module '%s' factory failed: %s", module_name.c_str(), e.what());
				return sol::make_object(L, sol::nil);
			}
		}));

		return 1;
	}

	//check built-in module registry
	if (auto entry = GetLuaModuleRegistry().Find(pkg))
	{
		sol::stack::push(L, std::function([entry, pkg = pkg](sol::this_state L)
		{
			try
			{
				return entry->factory(L);
			}
			catch (const std::exception& e)
			{
				luaL_error(L, "Module '%s' factory failed: %s", pkg.c_str(), e.what());
				return sol::make_object(L, sol::nil);
			}
		}));

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
	// filename here is canonical file name, but we need to reconstruct the path
	ScriptLocationInfo locationInfo = m_luaEnvironmentSettings->GetScriptLocationInfo(filename);
	if (!locationInfo.found)
		return std::nullopt;

	return StartFile(locationInfo, args);
}

std::optional<LuaThreadInfo> LuaThread::StartFile(
	const ScriptLocationInfo& locationInfo, const std::vector<std::string>& args)
{
	namespace fs = std::filesystem;

	// Add the current directory as highest priority search path (unless its the luadir, which is already
	// the highest priority search path)
	std::string runDir = fs::path{ locationInfo.fullPath }.parent_path().string();

	if (!runDir.empty() && fs::path{ runDir }.compare(m_luaEnvironmentSettings->luaDir) != 0)
	{
		m_globalState["package"]["path"] = fmt::format("{runDir}\\?\\init.lua;{runDir}\\?.lua;{existingPath}",
			fmt::arg("runDir", runDir),
			fmt::arg("existingPath", m_globalState["package"]["path"].get<std::string_view>()));

		m_globalState["package"]["cpath"] = fmt::format("{runDir}\\?.dll;{existingPath}",
			fmt::arg("runDir", runDir),
			fmt::arg("existingPath", m_globalState["package"]["cpath"].get<std::string_view>()));
	}

	m_name = locationInfo.canonicalName;
	m_path = locationInfo.fullPath;

	auto co = m_coroutine->thread.state().load_file(m_path);
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

void LuaThread::UpdateLuaDir(const std::filesystem::path& newLuaDir)
{
	UNUSED(newLuaDir);
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

void LuaThread::SetAllowYield(bool allowYield, YieldDisabledReason reason)
{
	m_allowYield = allowYield;
	m_yieldDisabledReason = reason;
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

sol::table LuaThread::GetSpawnTable()
{
	if (m_spawnTable == sol::nil)
	{
		m_spawnTable = m_globalState.create_named_table("__spawns");

		if (pSpawnManager != nullptr)
		{
			auto spawn = pSpawnManager->FirstSpawn;

			while (spawn != nullptr)
			{
				m_spawnTable[spawn->SpawnID] = bindings::lua_MQTypeVar(datatypes::pSpawnType->MakeTypeVar(spawn));
				spawn = spawn->GetNext();
			}
		}
	}

	return m_spawnTable;
}

void LuaThread::AddSpawn(eqlib::PlayerClient* spawn)
{
	if (m_coroutine->coroutine.status() == sol::call_status::yielded && m_spawnTable != sol::nil)
	{
		m_spawnTable[spawn->SpawnID] = bindings::lua_MQTypeVar(datatypes::pSpawnType->MakeTypeVar(spawn));
	}
}

void LuaThread::RemoveSpawn(eqlib::PlayerClient* spawn)
{
	if (m_coroutine->coroutine.status() == sol::call_status::yielded && m_spawnTable != sol::nil)
	{
		m_spawnTable[spawn->SpawnID] = sol::nil;
	}
}

sol::table LuaThread::GetGroundItemTable()
{
	if (m_groundItemTable == sol::nil)
	{
		m_groundItemTable = m_globalState.create_named_table("__groundItems");

		if (pItemList != nullptr)
		{
			auto item = pItemList->Top;
			while (item != nullptr)
			{
				m_groundItemTable[item->DropID] = bindings::lua_MQTypeVar(datatypes::MQ2GroundType::MakeTypeVar(MQGroundSpawn(item)));
				item = item->pNext;
			}
		}
	}

	return m_groundItemTable;
}

void LuaThread::AddGroundItem(eqlib::EQGroundItem* item)
{
	if (m_coroutine->coroutine.status() == sol::call_status::yielded && m_groundItemTable != sol::nil)
	{
		m_groundItemTable[item->DropID] = bindings::lua_MQTypeVar(datatypes::MQ2GroundType::MakeTypeVar(MQGroundSpawn(item)));
	}
}

void LuaThread::RemoveGroundItem(eqlib::EQGroundItem* item)
{
	if (m_coroutine->coroutine.status() == sol::call_status::yielded && m_groundItemTable != sol::nil)
	{
		m_groundItemTable[item->DropID] = sol::nil;
	}
}

} // namespace mq::lua
