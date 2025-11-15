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

#include "mq/base/Common.h"

#include "eqlib/game/EQClasses.h"
#include "eqlib/game/Globals.h"
#include "eqlib/game/PcClient.h"

#include <string_view>

namespace mq {

/**
 * @fn GetAdjustedSkill
 *
 * @brief Retrieves the adjusted skill level for a given skill
 *
 * Returns the total skill level for a given skill, including
 * any bonuses from items, spells, or other sources.
 *
 * @param nSkill The skill identifier
 *
 * @return int The adjusted skill level or 0 if pLocalPC is not available.
 **/
inline int GetAdjustedSkill(int nSkill)
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetAdjustedSkill(nSkill) : 0;
}

/**
 * @fn GetBaseSkill
 *
 * @brief Retrieves the base skill level for a given skill
 *
 * Returns the base skill level for a given skill, before
 * any bonuses from items, spells, or adjustments.
 *
 * @param nSkill The skill identifier
 *
 * @return int The base skill level or 0 if pLocalPC is not available.
 **/
inline int GetBaseSkill(int nSkill)
{
	return eqlib::pLocalPC ? eqlib::pLocalPC->GetBaseSkill(nSkill) : 0;
}

/**
 * @fn HasSkill
 *
 * @brief Checks if the character has a specific skill
 *
 * Returns whether the character has a specific skill. Does not
 * work for innate skills.
 *
 * @param nSkill The skill identifier
 *
 * @return bool True if the character has the specified skill, false otherwise
 **/
inline bool HasSkill(int nSkill)
{
	return eqlib::pLocalPC && eqlib::pLocalPC->HasSkill(nSkill);
}

/**
 * @fn SkillIsActivatable
 *
 * @brief Checks if the skill is activatable
 *
 * Returns whether the skill is activatable. An activatable skill
 * is also known as an Ability. Does not include innate skills.
 *
 * @param nSkill The skill identifier
 *
 * @return bool True if the skill is activatable, false otherwise
 **/
inline bool SkillIsActivatable(int nSkill)
{
	return nSkill < eqlib::NUM_SKILLS
		&& eqlib::pSkillMgr
		&& eqlib::pSkillMgr->pSkill[nSkill]->Activated;
}

/**
 * @fn HasInnateSkill
 *
 * @brief Checks if the character has a specific innate skill
 *
 * Returns whether the character has a specific innate skill. Does not
 * work for non-innate skills. Innate skills can be specified as either
 * their actual number or the "stacked" number.
 *
 * For example, slam is identified by both 111 and 11.
 *
 * @param nSkill The innate skill identifier (either version)
 *
 * @return bool True if the character has the specified innate skill, false otherwise
 **/
MQLIB_API bool HasInnateSkill(int nSkill);

/**
 * @fn InnateSkillIsActivatable
 *
 * @brief Checks if the innate skill is activatable
 *
 * Returns whether the innate skill is activatable. An activatable skill
 * is also known as an Ability. Does not work for non-innate skills.
 * Innate skills can be specified as either their actual number or the
 * "stacked" number.
 *
 * @param nSkill The innate skill identifier (either version)
 *
 * @return bool True if the innate skill is activatable, false otherwise
 **/
MQLIB_API bool InnateSkillIsActivatable(int nSkill);

/**
 * @fn HasSkillOrInnate
 *
 * @brief Checks if the character has a specific skill
 *
 * Returns whether the character has a specific skill. This includes
 * innate skills, but innate skills must be specified as their "stacked"
 * (above 100) number.
 *
 * @param nSkill The skill identifier
 *
 * @return bool True if the character has the specified skill, false otherwise
 **/
MQLIB_API bool HasSkillOrInnate(int nSkill);

/**
 * @fn SkillOrInnateIsActivatable
 *
 * @brief Checks if the skill is activatable
 *
 * Returns whether the skill is activatable. An activatable skill
 * is also known as an Ability. This includes innate skills, but
 * innate skills must be specified as their "stacked" (above 100)
 * number.
 *
 * @param nSkill The skill identifier
 *
 * @return bool True if the skill is activatable, false otherwise
 **/
MQLIB_API bool SkillOrInnateIsActivatable(int nSkill);

/**
 * @fn GetSkillName
 *
 * @brief Retrieves the name of a skill based on its identifier
 *
 * Returns the name of a skill given its identifier. This includes
 * innate skills, but innate skills must be specified as their
 * "stacked" (above 100) number.
 *
 * @param nSkill The skill identifier
 *
 * @return const char* The name of the skill, or nullptr if an issue
 **/
MQLIB_API const char* GetSkillName(int nSkill);

/**
 * @fn GetSkillIDFromString
 *
 * @brief Converts a string to a corresponding skill identifier
 *
 * Attempts to convert a string into an skill identifier. If the string
 * represents a numeric value, it is converted directly to an integer.
 * If it's a non-numeric string, the function searches for a matching
 * skill name and returns its identifier.
 *
 * For innate abilities, the function will only return the "stacked"
 * (above 100) value.
 *
 * The function returns a default value (iReturnOnFail) if the string is
 * empty, if no matching skill is found, or if the numeric conversion
 * results in a value outside the valid range of skill identifiers.
 *
 * @param svString The string representing the skill, either as a name or a number
 * @param iReturnOnFail (Optional) The value to return on failure to convert, defaults to -1
 *
 * @return int The skill identifier corresponding to the string, or iReturnOnFail on failure
 **/
MQLIB_API int GetSkillIDFromString(std::string_view svString, int iReturnOnFail = -1);

/**
 * @fn GetAbilityIDFromString
 *
 * @brief Converts a string to a corresponding ability identifier
 *
 * Attempts to convert a string into an ability identifier using GetSkillIDFromString.
 * An ability is a skill that can be activated, so if the skill is not activatable,
 * this will return a failure.
 *
 * @see GetSkillIDFromString
 *
 * @param svString The string representing the ability, either as a name or a number
 * @param iReturnOnFail (Optional) The value to return on failure to convert, defaults to -1
 *
 * @return int The ability identifier corresponding to the string, or iReturnOnFail on failure
 **/
MQLIB_API int GetAbilityIDFromString(std::string_view svString, int iReturnOnFail = -1);

} // namespace mq
