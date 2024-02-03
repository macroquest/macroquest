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
#include "MQ2DataTypes.h"

namespace mq::datatypes {

enum class SkillMembers
{
	Name = 1,
	ID,
	ReuseTime,
	MinLevel,
	SkillCap,
	AltTimer,
	Activated,
	Auto,
};

MQ2SkillType::MQ2SkillType() : MQ2Type("skill")
{
	ScopedTypeMember(SkillMembers, Name);
	ScopedTypeMember(SkillMembers, ID);
	ScopedTypeMember(SkillMembers, ReuseTime);
	ScopedTypeMember(SkillMembers, MinLevel);
	ScopedTypeMember(SkillMembers, SkillCap);
	ScopedTypeMember(SkillMembers, AltTimer);
	ScopedTypeMember(SkillMembers, Activated);
	ScopedTypeMember(SkillMembers, Auto);
}

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
		case SkillMembers::Name:
			Dest.Type = pStringType;
			if (const char* ptr = pStringTable->getString(pSkill->nName))
			{
				strcpy_s(DataTypeTemp, ptr);
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
			return false;

		case SkillMembers::ID:
			Dest.DWord = GetSkillIDFromName(pStringTable->getString(pSkill->nName));
			Dest.Type = pIntType;
			return true;

		case SkillMembers::ReuseTime:
			Dest.DWord = pSkill->ReuseTimer;
			Dest.Type = pIntType;
			return true;

		case SkillMembers::MinLevel:
			Dest.DWord = pSkill->MinLevel[nIndex];
			Dest.Type = pIntType;
			return true;

		case SkillMembers::SkillCap:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pLocalPC)
			{
				int i = GetSkillIDFromName(pStringTable->getString(pSkill->nName));
				Dest.DWord = pSkillMgr->GetSkillCap(pLocalPC, pProfile->Level, pProfile->Class, i, true, true, true);
				return true;
			}
			return false;

		case SkillMembers::AltTimer:
			Dest.DWord = pSkill->SkillCombatType;
			Dest.Type = pIntType;
			return true;

		case SkillMembers::Activated:
			Dest.Set(pSkill->Activated);
			Dest.Type = pBoolType;
			return true;

		case SkillMembers::Auto: { // return a bool representing if a skill has /autoskill on or off.
			Dest.Set(false);
			Dest.Type = pBoolType;

#if HAS_AUTOSKILLS
			int id = GetSkillIDFromName(pStringTable->getString(pSkill->nName));
			for (int i = 0; i < CONCURRENT_SKILLS; ++i)
			{
				if (pEverQuestInfo->AutoSkills[i] == id)
				{
					Dest.Set(true);
					return true;
				}
			}
#endif
			return true;
		}

		default: break;
		}
	}

	return false;
}

bool MQ2SkillType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	if (SKILL* pSkill = *(SKILL**)VarPtr.Ptr)
	{
		if (const char* pName = pStringTable->getString(pSkill->nName))
		{
			strcpy_s(Destination, MAX_STRING, pName);
			return true;
		}
	}
	return false;
}

bool MQ2SkillType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pSkillType)
		return false;
	VarPtr.Ptr = Source.Ptr;
	return true;
}

bool MQ2SkillType::dataSkill(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		int nSkill = GetIntFromString(szIndex, 0) - 1;
		if (nSkill < 0)
			nSkill = 0;

		if (nSkill > NUM_SKILLS)
			return false;

		Ret.Ptr = &pSkillMgr->pSkill[nSkill];
		Ret.Type = pSkillType;
		return true;
	}

	for (int nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
	{
		if (SKILL* pSkill = pSkillMgr->pSkill[nSkill])
		{
			if (const char* pName = pStringTable->getString(pSkill->nName))
			{
				if (!_stricmp(szIndex, pName))
				{
					Ret.Ptr = &pSkillMgr->pSkill[nSkill];
					Ret.Type = pSkillType;
					return true;
				}
			}
		}
	}

	return false;
}

} // namespace mq::datatypes
