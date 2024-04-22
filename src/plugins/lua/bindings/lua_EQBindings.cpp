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

namespace mq::lua::bindings {

//============================================================================

static std::unique_ptr<CTextureAnimation> FindTextureAnimation(std::string_view name, sol::this_state s)
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

#pragma region MQ Data Bindings

static sol::table lua_getAllSpawns(sol::this_state L)
{
	auto table = sol::state_view(L).create_table();

	if (pSpawnManager)
	{
		auto spawn = pSpawnManager->FirstSpawn;
		while (spawn != nullptr)
		{
			auto lua_spawn = lua_MQTypeVar(datatypes::pSpawnType->MakeTypeVar(spawn));
			table.add(std::move(lua_spawn));

			spawn = spawn->GetNext();
		}
	}

	return table;
}

static sol::table lua_getFilteredSpawns(sol::this_state L, std::optional<sol::unsafe_function> predicate)
{
	auto table = sol::state_view(L).create_table();

	if (pSpawnManager && predicate)
	{
		auto spawn = pSpawnManager->FirstSpawn;
		const auto& predicate_value = predicate.value();
		while (spawn != nullptr)
		{
			auto lua_spawn = lua_MQTypeVar(datatypes::pSpawnType->MakeTypeVar(spawn));
			if (predicate_value(lua_spawn))
				table.add(std::move(lua_spawn));

			spawn = spawn->GetNext();
		}
	}

	return table;
}

static sol::table lua_getAllGroundItems(sol::this_state L)
{
	auto table = sol::state_view(L).create_table();

	if (pItemList)
	{
		auto pGroundItem = pItemList->Top;
		while (pGroundItem != nullptr)
		{
			auto groundTypeVar = datatypes::MQ2GroundType::MakeTypeVar(MQGroundSpawn(pGroundItem));
			auto lua_ground = lua_MQTypeVar(groundTypeVar);
			table.add(std::move(lua_ground));

			pGroundItem = pGroundItem->pNext;
		}
	}

	return table;
}

static sol::table lua_getFilteredGroundItems(sol::this_state L, std::optional<sol::unsafe_function> predicate)
{
	auto table = sol::state_view(L).create_table();

	if (pItemList && predicate)
	{
		auto pGroundItem = pItemList->Top;
		const auto& predicate_value = predicate.value();
		while (pGroundItem != nullptr)
		{
			auto groundTypeVar = datatypes::MQ2GroundType::MakeTypeVar(MQGroundSpawn(pGroundItem));
			auto lua_ground = lua_MQTypeVar(groundTypeVar);
			if (predicate_value(lua_ground))
				table.add(std::move(lua_ground));

			pGroundItem = pGroundItem->pNext;
		}
	}

	return table;
}

#pragma endregion

//============================================================================

void RegisterBindings_EQ(LuaThread* thread, sol::table& mq)
{
	mq.new_usertype<CTextureAnimation>(
		"CTextureAnimation", sol::no_constructor,
		"SetTextureCell", &CTextureAnimation::SetCurCell,
		"GetTextureCell", &CTextureAnimation::GetCurCell,
		"GetSize", [](CTextureAnimation& mThis) -> ImVec2 { return mThis.Size; },
		"GetCellSize", [](CTextureAnimation& mThis) -> ImVec2 { return ImVec2((float)mThis.CellWidth, (float)mThis.CellHeight); }
	);

	mq.set_function("FindTextureAnimation", &FindTextureAnimation);

	mq.set_function("AttachSpellToCursor", [](int SpellID)
		{
			if (pCursorAttachment) return pCursorAttachment->AttachSpellToCursor(SpellID);
			return false;
		});
	mq.set_function("RemoveCursorAttachment", []()
		{
			if (pCursorAttachment && pCursorAttachment->IsOkToActivate(-1))
			{
				pCursorAttachment->RemoveAttachment();
				return true;
			}
			return false;
		});

	//----------------------------------------------------------------------------
	// Direct Data Bindings
	mq.set_function("getAllSpawns", &lua_getAllSpawns);
	mq.set_function("getFilteredSpawns", &lua_getFilteredSpawns);
	mq.set_function("getAllGroundItems", &lua_getAllGroundItems);
	mq.set_function("getFilteredGroundItems", &lua_getFilteredGroundItems);
}

} // namespace mq::lua::bindings
