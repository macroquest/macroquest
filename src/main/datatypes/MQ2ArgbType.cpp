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

enum class ArgbMembers
{
	A = 0,
	R = 1,
	G = 2,
	B = 3,
	Int = 4,
};

MQ2ArgbType::MQ2ArgbType() : MQ2Type("argb")
{
	ScopedTypeMember(ArgbMembers, A);
	ScopedTypeMember(ArgbMembers, R);
	ScopedTypeMember(ArgbMembers, G);
	ScopedTypeMember(ArgbMembers, B);
	ScopedTypeMember(ArgbMembers, Int);
}

bool MQ2ArgbType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<ArgbMembers>(pMember->ID))
	{
	case ArgbMembers::A:
		Dest.DWord = VarPtr.Argb.A;
		Dest.Type = pIntType;
		return true;

	case ArgbMembers::R:
		Dest.DWord = VarPtr.Argb.R;
		Dest.Type = pIntType;
		return true;

	case ArgbMembers::G:
		Dest.DWord = VarPtr.Argb.G;
		Dest.Type = pIntType;
		return true;

	case ArgbMembers::B:
		Dest.DWord = VarPtr.Argb.B;
		Dest.Type = pIntType;
		return true;

	case ArgbMembers::Int:
		Dest.DWord = VarPtr.DWord;
		Dest.Type = pIntType;
		return true;
	}

	return false;
}

bool MQ2ArgbType::ToString(MQVarPtr VarPtr, char* Destination)
{
	sprintf_s(Destination, MAX_STRING, "%x", VarPtr.Int);
	return true;
}

bool MQ2ArgbType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	VarPtr.DWord = Source.DWord;
	return true;
}

bool MQ2ArgbType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	ARGBCOLOR input;
	if (sscanf_s(Source, "%x", &input.ARGB))
	{
		VarPtr.Argb = input;
		return true;
	}

	return false;
}

