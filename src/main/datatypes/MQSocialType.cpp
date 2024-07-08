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

//============================================================================

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
	ScopedTypeMember(SocialTypeMembers, Cmd);
	ScopedTypeMember(SocialTypeMembers, Color);
	ScopedTypeMember(SocialTypeMembers, Name);
	ScopedTypeMember(SocialTypeMembers, TimerBegin);
	ScopedTypeMember(SocialTypeMembers, TimerDuration);
}

static const char* getCommandLine(const int socialIdx, const int lineIdx)
{
	if (socialIdx >= 0 && socialIdx < (NUM_SOCIAL_PAGES * SOCIALS_PER_PAGE) && lineIdx >= 0 && lineIdx < SOCIAL_NUM_LINES)
	{
		return pSocialList[socialIdx].Line[lineIdx];
	}

	return "";
}

bool MQSocialType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC || !pLocalPlayer)
		return false;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	int socialIndex = VarPtr.Int;

	if (socialIndex < 0 || socialIndex >= (NUM_SOCIAL_PAGES * SOCIALS_PER_PAGE))
		return false;

	switch (static_cast<SocialTypeMembers>(pMember->ID))
	{
	case SocialTypeMembers::Name:
		strcpy_s(DataTypeTemp, pSocialList[socialIndex].Name);
		Dest.Type = mq::datatypes::pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case SocialTypeMembers::Cmd:
	{
		int idx = GetIntFromString(Index, -1);

		if (idx >= 0 && idx < SOCIAL_NUM_LINES)
		{
			strcpy_s(DataTypeTemp, getCommandLine(socialIndex, idx));
		}
		else
		{
			DataTypeTemp[0] = 0;

			for (int i = 0; i < SOCIAL_NUM_LINES; ++i)
			{
				const char* line = getCommandLine(socialIndex, i);
				if (i > 0 && DataTypeTemp[strlen(DataTypeTemp) - 1] != '\n')
					strcat_s(DataTypeTemp, "\n");

				strcat_s(DataTypeTemp, line);
			}

			if (DataTypeTemp[strlen(DataTypeTemp) - 1] == '\n')
				DataTypeTemp[strlen(DataTypeTemp) - 1] = 0;
		}

		Dest.Type = mq::datatypes::pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

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

bool MQSocialType::ToString(MQVarPtr VarPtr, char* Destination)
{
	int socialIndex = VarPtr.Int;

	if (socialIndex < 0 || socialIndex >= (NUM_SOCIAL_PAGES * SOCIALS_PER_PAGE))
		return false;

	strcpy_s(Destination, MAX_STRING, pSocialList[socialIndex].Name);
	return true;
}

bool MQSocialType::dataSocial(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Type = pSocialType;
	Ret.Int = GetIntFromString(szIndex, 0) - 1;
	
	return true;
}

} // namespace mq::datatypes
