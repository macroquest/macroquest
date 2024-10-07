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

static void lua_initializeSpawnTable(sol::this_state L)
{
	std::shared_ptr<LuaThread> thread = LuaThread::get_from(L);
	if (thread)
		thread->InitializeSpawnTable();
}

static void lua_initializeGroundItemTable(sol::this_state L)
{
	std::shared_ptr<LuaThread> thread = LuaThread::get_from(L);
	if (thread)
		thread->InitializeGroundItemTable();
}

#pragma endregion

#pragma region Text Links

sol::table lua_ExtractLinks(sol::this_state L, std::string_view str)
{
	auto table = sol::state_view(L).create_table();

	TextTagInfo tags[MAX_EXTRACT_LINKS];
	size_t numTags = ExtractLinks(str, tags, MAX_EXTRACT_LINKS);

	for (size_t i = 0; i < numTags; ++i)
	{
		table.add(std::move(tags[i]));
	}

	return table;
}

std::string lua_FormatDialogLink(std::string_view keyword, sol::optional<std::string_view> text)
{
	char buffer[MAX_STRING];
	FormatDialogLink(buffer, MAX_STRING, keyword, text.has_value() ? text.value() : std::string_view());

	return buffer;
}

std::string lua_FormatItemLink(sol::this_state L, const lua_MQTypeVar& typeVar)
{
	MQTypeVar var = typeVar.EvaluateMember();

	if (var.Type != datatypes::pItemType)
		luaL_error(L, "Expected an item type var");

	ItemPtr pItem = datatypes::pItemType->GetItem(var);
	if (pItem == nullptr)
		luaL_error(L, "Expected item, got nil");

	char buffer[MAX_STRING];
	FormatItemLink(buffer, MAX_STRING, pItem.get());

	return buffer;
}

std::string lua_FormatSpellLink(sol::this_state L, const lua_MQTypeVar& typeVar, sol::optional<const char*> nameOverride)
{
	MQTypeVar var = typeVar.EvaluateMember();

	if (var.Type != datatypes::pSpellType)
		luaL_error(L, "Expected a spell type var");

	EQ_Spell* pSpell = datatypes::MQ2SpellType::GetSpell(var);
	if (pSpell == nullptr)
		luaL_error(L, "Expected spell, got nil");

	char buffer[MAX_STRING];
	FormatSpellLink(buffer, MAX_STRING, pSpell, nameOverride.value_or(nullptr));

	return buffer;
}

std::string lua_FormatAchievementLink(sol::this_state L, const lua_MQTypeVar& typeVar, std::string_view playerName)
{
	MQTypeVar var = typeVar.EvaluateMember();

	if (var.Type != datatypes::pAchievementType)
		luaL_error(L, "Expected an achievement type var");

	const Achievement* pAchievement = datatypes::MQ2AchievementType::GetAchievement(var);
	if (pAchievement == nullptr)
		luaL_error(L, "Expected achievement, got nil");

	char buffer[MAX_STRING];
	FormatAchievementLink(buffer, MAX_STRING, pAchievement, playerName);

	return buffer;
}

sol::optional<DialogLinkInfo> lua_ParseDialogLink(std::string_view str)
{
	DialogLinkInfo linkInfo;

	if (ParseDialogLink(str, linkInfo))
		return linkInfo;

	return {};
}

sol::optional<ItemLinkInfo> lua_ParseItemLink(std::string_view str)
{
	ItemLinkInfo linkInfo;

	if (ParseItemLink(str, linkInfo))
		return linkInfo;

	return {};
}

sol::optional<SpellLinkInfo> lua_ParseSpellLink(std::string_view str)
{
	SpellLinkInfo linkInfo;

	if (ParseSpellLink(str, linkInfo))
		return linkInfo;

	return {};
}

std::string lua_StripTextLinks(std::string_view str)
{
	CXStr text(str);

	text = CleanItemTags(text);
	return std::string{ text };
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
	// Chat links
	mq.set_function("ExtractLinks"        , &lua_ExtractLinks);
	mq.set_function("ExecuteTextLink"     , &eqlib::ExecuteTextLink);
	mq.set_function("FormatAchievementLink", &lua_FormatAchievementLink);
	mq.set_function("FormatDialogLink"    , &lua_FormatDialogLink);
	mq.set_function("FormatItemLink"      , &lua_FormatItemLink);
	mq.set_function("FormatSpellLink"     , &lua_FormatSpellLink);
	mq.set_function("ParseDialogLink"     , &lua_ParseDialogLink);
	mq.set_function("ParseItemLink"       , &lua_ParseItemLink);
	mq.set_function("ParseSpellLink"      , &lua_ParseSpellLink);
	mq.set_function("StripTextLinks"      , &lua_StripTextLinks);

	mq.new_usertype<TextTagInfo>(
		"TextTagInfo"                     , sol::no_constructor,
		"type"                            , sol::readonly(&TextTagInfo::tagCode),
		"link"                            , sol::readonly(&TextTagInfo::link),
		"text"                            , sol::readonly(&TextTagInfo::text));

	mq.new_enum("LinkTypes",
		"Item"                            , ETAG_ITEM,
		"Player"                          , ETAG_PLAYER,
		"Spam"                            , ETAG_SPAM,
		"Achievement"                     , ETAG_ACHIEVEMENT,
		"Dialog"                          , ETAG_DIALOG_RESPONSE,
		"Command"                         , ETAG_COMMAND,
		"Spell"                           , ETAG_SPELL,
		"Faction"                         , ETAG_FACTION,
		"Invalid"                         , ETAG_INVALID);

	mq.new_usertype<DialogLinkInfo>(
		"DialogLinkInfo"                  , sol::no_constructor,
		"keyword"                         , sol::readonly(&DialogLinkInfo::keyword),
		"text"                            , sol::readonly(&DialogLinkInfo::text));
	mq.new_usertype<ItemLinkInfo>(
		"ItemLinkInfo"                    , sol::no_constructor,
		"itemID"                          , sol::readonly(&ItemLinkInfo::itemID),
		"sockets"                         , [](ItemLinkInfo* pThis) { return &pThis->sockets; },
		"socketLuck"                      , [](ItemLinkInfo* pThis) { return &pThis->socketLuck; },
		"isEvolving"                      , sol::readonly(&ItemLinkInfo::isEvolving),
		"evolutionGroup"                  , sol::readonly(&ItemLinkInfo::evolutionGroup),
		"evolutionLevel"                  , sol::readonly(&ItemLinkInfo::evolutionLevel),
		"ornamentationIconID"             , sol::readonly(&ItemLinkInfo::ornamentationIconID),
		"luck"                            , sol::readonly(&ItemLinkInfo::luck),
		"itemHash"                        , sol::readonly(&ItemLinkInfo::itemHash),
		"itemName"                        , sol::readonly(&ItemLinkInfo::itemName),
		"IsSocketed"                      , &ItemLinkInfo::IsSocketed);
	mq.new_usertype<SpellLinkInfo>(
		"SpellLinkInfo"                   , sol::no_constructor,
		"spellID"                         , sol::readonly(&SpellLinkInfo::spellID),
		"spellName"                       , sol::readonly(&SpellLinkInfo::spellName));

	mq.set("MAX_AUG_SOCKETS"              , MAX_AUG_SOCKETS);

	//----------------------------------------------------------------------------
	// Direct Data Bindings
	mq.set_function("initializeSpawnTable", &lua_initializeSpawnTable);
	mq.set_function("initializeGroundItemTable", &lua_initializeGroundItemTable);

	sol::function getAllSpawns = thread->GetState().script(R"(
		return function()
			if not __spawns then require('mq').initializeSpawnTable() end
			local spawns = {}
			for _, spawn in pairs(__spawns) do table.insert(spawns, spawn) end
			return spawns
		end
	)");
	mq.set("getAllSpawns", getAllSpawns);

	sol::function getFilteredSpawns = thread->GetState().script(R"(
		return function(predicate)
			if not __spawns then require('mq').initializeSpawnTable() end
			local spawns = {}
			for _, spawn in pairs(__spawns) do
				if predicate(spawn) then table.insert(spawns, spawn) end
			end
			return spawns
		end
	)");
	mq.set_function("getFilteredSpawns", getFilteredSpawns);

	sol::function getAllGroundItems = thread->GetState().script(R"(
		return function()
			if not __groundItems then require('mq').initializeGroundItemTable() end
			local items = {}
			for _, item in pairs(__groundItems) do table.insert(items, item) end
			return items
		end
	)");
	mq.set_function("getAllGroundItems", getAllGroundItems);

	sol::function getFilteredGroundItems = thread->GetState().script(R"(
		return function(predicate)
			if not __groundItems then require('mq').initializeGroundItemTable() end
			local items = {}
			for _, item in pairs(__groundItems) do
				if predicate(item) then table.insert(items, item) end
			end
			return items
		end
	)");
	mq.set_function("getFilteredGroundItems", getFilteredGroundItems);
}

} // namespace mq::lua::bindings
