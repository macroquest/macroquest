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

#pragma region Text Links

static sol::table lua_ExtractLinks(sol::this_state L, std::string_view str)
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

static std::string lua_FormatDialogLink(std::string_view keyword, sol::optional<std::string_view> text)
{
	char buffer[MAX_STRING];
	FormatDialogLink(buffer, MAX_STRING, keyword, text.has_value() ? text.value() : std::string_view());

	return buffer;
}

static std::string lua_FormatItemLink(sol::this_state L, const lua_MQTypeVar& typeVar)
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

static std::string lua_FormatSpellLink(sol::this_state L, const lua_MQTypeVar& typeVar, sol::optional<const char*> nameOverride)
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

static std::string lua_FormatAchievementLink(sol::this_state L, const lua_MQTypeVar& typeVar, std::string_view playerName)
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

static sol::optional<DialogLinkInfo> lua_ParseDialogLink(std::string_view str)
{
	DialogLinkInfo linkInfo;

	if (ParseDialogLink(str, linkInfo))
		return linkInfo;

	return {};
}

static sol::optional<ItemLinkInfo> lua_ParseItemLink(std::string_view str)
{
	ItemLinkInfo linkInfo;

	if (ParseItemLink(str, linkInfo))
		return linkInfo;

	return {};
}

static sol::optional<SpellLinkInfo> lua_ParseSpellLink(std::string_view str)
{
	SpellLinkInfo linkInfo;

	if (ParseSpellLink(str, linkInfo))
		return linkInfo;

	return {};
}

static std::string lua_StripTextLinks(std::string_view str)
{
	CXStr text(str);

	text = CleanItemTags(text);
	return std::string{ text };
}

static sol::table lua_getAllSpawns(sol::this_state L)
{
	sol::table allSpawns = sol::state_view(L).create_table();

	if (auto thisThread = LuaThread::get_from(L))
	{
		sol::table spawnTable = thisThread->GetSpawnTable();

		for (const auto& [_, value] : spawnTable)
		{
			allSpawns.add(value);
		}
	}

	return allSpawns;
}

static sol::table lua_getFilteredspawns(sol::this_state L, sol::optional<sol::unsafe_function> predicate_)
{
	sol::table filteredSpawns = sol::state_view(L).create_table();
	auto thisThread = LuaThread::get_from(L);

	if (thisThread && predicate_.has_value())
	{
		sol::table spawnTable = thisThread->GetSpawnTable();
		const sol::unsafe_function& predicate = predicate_.value();

		for (const auto& [_, value] : spawnTable)
		{
			if (predicate(value))
			{
				filteredSpawns.add(value);
			}
		}
	}

	return filteredSpawns;
}

static sol::table lua_getAllGroundItems(sol::this_state L)
{
	sol::table allGroundItems = sol::state_view(L).create_table();

	if (auto thisThread = LuaThread::get_from(L))
	{
		sol::table groundItemTable = thisThread->GetGroundItemTable();

		for (const auto& [_, value] : groundItemTable)
		{
			allGroundItems.add(value);
		}
	}

	return allGroundItems;
}

static sol::table lua_getFilteredGroundItems(sol::this_state L, sol::unsafe_function predicate_)
{
	sol::table filteredGroundItems = sol::state_view(L).create_table();
	auto thisThread = LuaThread::get_from(L);

	if (thisThread && predicate_.valid())
	{
		sol::table groundItemTable = thisThread->GetGroundItemTable();
		const sol::unsafe_function& predicate = predicate_;

		for (const auto& [_, value] : groundItemTable)
		{
			if (predicate(value))
			{
				filteredGroundItems.add(value);
			}
		}
	}

	return filteredGroundItems;
}

#pragma endregion

//============================================================================

void RegisterBindings_EQ(LuaThread* thread, sol::table& mq)
{
	auto texAnim = mq.new_usertype<CTextureAnimation>("CTextureAnimation", sol::no_constructor);
	texAnim.set("SetTextureCell"          , &CTextureAnimation::SetCurCell);
	texAnim.set("GetTextureCell"          , &CTextureAnimation::GetCurCell);
	texAnim.set("GetSize"                 , [](CTextureAnimation& mThis) -> ImVec2 { return mThis.Size; });
	texAnim.set("GetCellSize"             , [](CTextureAnimation& mThis) -> ImVec2 { return ImVec2((float)mThis.CellWidth, (float)mThis.CellHeight); });

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

	auto textTagInfo = mq.new_usertype<TextTagInfo>("TextTagInfo", sol::no_constructor);
	textTagInfo.set("type"                , sol::readonly(&TextTagInfo::tagCode));
	textTagInfo.set("link"                , sol::readonly(&TextTagInfo::link));
	textTagInfo.set("text"                , sol::readonly(&TextTagInfo::text));

	auto linkTypes = mq.new_enum("LinkTypes");
	linkTypes.set("Item"                  , ETAG_ITEM);
	linkTypes.set("Player"                , ETAG_PLAYER);
	linkTypes.set("Spam"                  , ETAG_SPAM);
	linkTypes.set("Achievement"           , ETAG_ACHIEVEMENT);
	linkTypes.set("Dialog"                , ETAG_DIALOG_RESPONSE);
	linkTypes.set("Command"               , ETAG_COMMAND);
	linkTypes.set("Spell"                 , ETAG_SPELL);
	linkTypes.set("Faction"               , ETAG_FACTION);
	linkTypes.set("Invalid"               , ETAG_INVALID);

	auto dialogLinkInfo = mq.new_usertype<DialogLinkInfo>("DialogLinkInfo", sol::no_constructor);
	dialogLinkInfo.set("keyword"          , sol::readonly(&DialogLinkInfo::keyword));
	dialogLinkInfo.set("text"             , sol::readonly(&DialogLinkInfo::text));

	auto itemLinkInfo = mq.new_usertype<ItemLinkInfo>("ItemLinkInfo", sol::no_constructor);
	itemLinkInfo.set("itemID"             , sol::readonly(&ItemLinkInfo::itemID));
	itemLinkInfo.set("sockets"            , [](ItemLinkInfo* pThis) { return &pThis->sockets; });
	itemLinkInfo.set("socketLuck"         , [](ItemLinkInfo* pThis) { return &pThis->socketLuck; });
	itemLinkInfo.set("isEvolving"         , sol::readonly(&ItemLinkInfo::isEvolving));
	itemLinkInfo.set("evolutionGroup"     , sol::readonly(&ItemLinkInfo::evolutionGroup));
	itemLinkInfo.set("evolutionLevel"     , sol::readonly(&ItemLinkInfo::evolutionLevel));
	itemLinkInfo.set("ornamentationIconID", sol::readonly(&ItemLinkInfo::ornamentationIconID));
	itemLinkInfo.set("luck"               , sol::readonly(&ItemLinkInfo::luck));
	itemLinkInfo.set("itemHash"           , sol::readonly(&ItemLinkInfo::itemHash));
	itemLinkInfo.set("itemName"           , sol::readonly(&ItemLinkInfo::itemName));
	itemLinkInfo.set("IsSocketed"         , &ItemLinkInfo::IsSocketed);

	auto spellLinkInfo = mq.new_usertype<SpellLinkInfo>("SpellLinkInfo", sol::no_constructor);
	spellLinkInfo.set("spellID"           , sol::readonly(&SpellLinkInfo::spellID));
	spellLinkInfo.set("spellName"         , sol::readonly(&SpellLinkInfo::spellName));

	mq.set("MAX_AUG_SOCKETS"              , MAX_AUG_SOCKETS);

	//----------------------------------------------------------------------------
	// Direct Data Bindings

	mq.set("getAllSpawns", lua_getAllSpawns);
	mq.set_function("getFilteredSpawns", lua_getFilteredspawns);
	mq.set_function("getAllGroundItems", lua_getAllGroundItems);
	mq.set_function("getFilteredGroundItems", lua_getFilteredGroundItems);
}

} // namespace mq::lua::bindings
