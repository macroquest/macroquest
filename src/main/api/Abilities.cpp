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

#include "mq/api/Abilities.h"
#include "eqlib/game/Globals.h"

using namespace eqlib;

namespace mq {

// Defined in MQ2Globals.cpp but we don't want to bring in all of MQ2Globals.h
MQLIB_VAR const char* szInnates[];

bool HasInnateSkill(int nSkill)
{
	if (pLocalPC == nullptr)
		return false;

	// Innate skills stack on top of normal skills when used with Skill Manager
	// Allow for both
	if (nSkill >= NUM_SKILLS)
		nSkill -= NUM_SKILLS;

	if (nSkill < 0 || nSkill > NUM_INNATE)
		return false;

	// 255 is the default value for an unset innate skill
	return pLocalPC->GetCurrentPcProfile()->InnateSkill[nSkill] != 255;
}

bool InnateSkillIsActivatable(int nSkill)
{
	if (nSkill < NUM_SKILLS)
		nSkill += NUM_SKILLS;
	//              slam            inspect          open        reveal trap
	return nSkill == 111 || nSkill == 114 || nSkill == 115 || nSkill == 116;
}

bool HasSkillOrInnate(int nSkill)
{
	if (nSkill < 0 || nSkill >= NUM_SKILLS + NUM_INNATE)
		return false;

	if (nSkill < NUM_SKILLS)
		return HasSkill(nSkill);
	return HasInnateSkill(nSkill);
}

bool SkillOrInnateIsActivatable(int nSkill)
{
	if (nSkill < 0 || nSkill >= NUM_SKILLS + NUM_INNATE)
		return false;

	if (nSkill < NUM_SKILLS)
		return SkillIsActivatable(nSkill);
	return InnateSkillIsActivatable(nSkill);
}

const char* GetSkillName(int nSkill)
{
	if (nSkill < 0 || nSkill >= NUM_SKILLS + NUM_INNATE)
		return nullptr;

	if (nSkill < NUM_SKILLS)
		return pStringTable && pSkillMgr ? pStringTable->getString(pSkillMgr->GetNameToken(nSkill)) : nullptr;

	return szInnates[nSkill - 100];
}

int GetSkillIDFromString(std::string_view svString, int iReturnOnFail /* = -1 */)
{
	if (svString.empty())
		return iReturnOnFail;

	int nSkill = iReturnOnFail;
	if (IsNumber(svString))
	{
		nSkill = GetIntFromString(svString, iReturnOnFail);
	}
	else
	{
		// Search by Name
		for (int i = 0; i < NUM_SKILLS + NUM_INNATE; ++i)
		{
			if (const char* skill_name = GetSkillName(i))
			{
				if (ci_equals(svString, skill_name))
				{
					nSkill = i;
					break;
				}
			}
		}
	}

	if (nSkill < 0 || nSkill >= NUM_SKILLS + NUM_INNATE)
		nSkill = iReturnOnFail;

	return nSkill;
}

int GetAbilityIDFromString(std::string_view svString, int iReturnOnFail /* = -1 */)
{
	int nSkill = GetSkillIDFromString(svString, iReturnOnFail);
	if (!SkillOrInnateIsActivatable(nSkill))
		nSkill = iReturnOnFail;
	return nSkill;
}

} // namespace mq
