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

#include "MQ2DataTypes.h"
#include "MQ2DataTypes.h"

namespace mq::datatypes {

//============================================================================

#define MAX_SOCIAL 120

enum class SocialTypeMembers
{
	Name,
	Cmd,
	TimerBegin,
	TimerDuration,
	Color,
};

MQSocialType::MQSocialType() : MQ2Type("social")
{
	ScopedTypeMember(SocialTypeMembers, Name);
	ScopedTypeMember(SocialTypeMembers, Cmd);
	ScopedTypeMember(SocialTypeMembers, TimerBegin);
	ScopedTypeMember(SocialTypeMembers, TimerDuration);
	ScopedTypeMember(SocialTypeMembers, Color);
}

bool MQSocialType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC || !pLocalPlayer)
		return false;

	if (!pCursorAttachment)
		return false;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	int socialIndex = VarPtr.Int;

	if (socialIndex < 0 || socialIndex >= MAX_SOCIAL)
		return false;

	switch (static_cast<SocialTypeMembers>(pMember->ID))
	{
	case SocialTypeMembers::Name:
		strcpy_s(DataTypeTemp, pSocialList[socialIndex].Name);
		Dest.Type = mq::datatypes::pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SocialTypeMembers::Cmd:
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int idx = GetIntFromString(Index, 0);

				if (idx >= 0 && idx < 5)
				{
					strcpy_s(DataTypeTemp, getCommandLine(socialIndex, idx));
					Dest.Type = mq::datatypes::pStringType;
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;

	case SocialTypeMembers::TimerBegin:
		Dest.Type = mq::datatypes::pIntType;
		Dest.Int = static_cast<int>(pSocialList[socialIndex].TimerBegin);
		return true;

	case SocialTypeMembers::TimerDuration:
		Dest.Type = mq::datatypes::pIntType;
		Dest.Int = static_cast<int>(pSocialList[socialIndex].TimerDuration);
		return true;

	case SocialTypeMembers::Color:
		Dest.Type = mq::datatypes::pIntType;
		Dest.Int = static_cast<int>(pSocialList[socialIndex].Color);
		return true;

	default:
		break;
	}

	return false;
}

const char* MQSocialType::getCommandLine(const int socialIdx, const int lineIdx)
{
	if (socialIdx >= 0 && socialIdx < MAX_SOCIAL && lineIdx >= 0 && lineIdx < 5)
	{
		return pSocialList[socialIdx].Line[lineIdx];
	}

	return "";
}

bool MQSocialType::dataSocial(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pSocialType;

	if (IsNumber(szIndex))
	{
		Ret.Int = GetIntFromString(szIndex, 0);
	}

	return true;
}

} // namespace mq::datatypes
