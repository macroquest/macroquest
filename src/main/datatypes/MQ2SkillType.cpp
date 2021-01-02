/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2SkillType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!VarPtr.Ptr)
		return false;
	SKILL* pSkill = *(SKILL**)VarPtr.Ptr;
	if (!pSkill)
		return false;

	MQTypeMember* pMember = MQ2SkillType::FindMember(Member);
	if (!pMember)
		return false;

	if (PcProfile* pProfile = GetPcProfile())
	{
		int nIndex = pProfile->Class;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// class by number
				nIndex = GetIntFromString(Index, nIndex);
			}
			else
			{
				// class by name or shortname
				for (int index = 1; index < 17; index++)
				{
					if (ci_equals(Index, GetClassDesc(index))
						|| ci_equals(Index, pEverQuest->GetClassThreeLetterCode(index)))
					{
						nIndex = index;
						break;
					}
				}
			}
		}

		switch (static_cast<SkillMembers>(pMember->ID))
		{
		case Name:
			Dest.Type = pStringType;
			if (const char* ptr = pStringTable->getString(pSkill->nName))
			{
				strcpy_s(DataTypeTemp, ptr);
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
			return false;

		case ID:
			Dest.DWord = GetSkillIDFromName(pStringTable->getString(pSkill->nName));
			Dest.Type = pIntType;
			return true;

		case ReuseTime:
			Dest.DWord = pSkill->ReuseTimer;
			Dest.Type = pIntType;
			return true;

		case MinLevel:
			Dest.DWord = pSkill->MinLevel[nIndex];
			Dest.Type = pIntType;
			return true;

		case SkillCap:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pCharData)
			{
				int i = GetSkillIDFromName(pStringTable->getString(pSkill->nName));
				Dest.DWord = pSkillMgr->GetSkillCap(pCharData, pProfile->Level, pProfile->Class, i, true, true, true);
				return true;
			}
			return false;

		case AltTimer:
			Dest.DWord = pSkill->SkillCombatType;
			Dest.Type = pIntType;
			return true;

		case Activated:
			Dest.Set(pSkill->Activated);
			Dest.Type = pBoolType;
			return true;

		case Auto: { // return a bool representing if a skill has /autoskill on or off.
			Dest.Set(false);
			Dest.Type = pBoolType;
			int id = GetSkillIDFromName(pStringTable->getString(pSkill->nName));
			if (gAutoSkill.Skill[0] == id || gAutoSkill.Skill[1] == id)
			{
				Dest.Set(true);
			}
			return true;
		}

		default: break;
		}
	}

	return false;
}

