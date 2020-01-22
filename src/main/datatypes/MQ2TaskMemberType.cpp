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

enum class TaskMemberTypeMembers
{
	Name = 1,
	Leader,
	Index
};

MQ2TaskMemberType::MQ2TaskMemberType() : MQ2Type("taskmember")
{
	ScopedTypeMember(TaskMemberTypeMembers, Name);
	ScopedTypeMember(TaskMemberTypeMembers, Leader);
	ScopedTypeMember(TaskMemberTypeMembers, Index);
}

bool MQ2TaskMemberType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	auto pTaskMemberData = static_cast<SharedTaskPlayerInfo*>(VarPtr.Ptr);
	if (!pTaskMemberData)
		return false;

	MQTypeMember* pMember = MQ2TaskMemberType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TaskMemberTypeMembers>(pMember->ID))
	{
	case TaskMemberTypeMembers::Name:
		strcpy_s(DataTypeTemp, pTaskMemberData->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TaskMemberTypeMembers::Leader:
		Dest.DWord = pTaskMemberData->IsLeader;
		Dest.Type = pBoolType;
		return true;

	case TaskMemberTypeMembers::Index:
	{
		if (!pTaskMember)
			return false;

		Dest.DWord = 0;
		Dest.Type = pIntType;

		auto taskMember = pTaskMember;
		for (int i = 1; taskMember; taskMember = taskMember->pNext, i++)
		{
			if (taskMember == pTaskMemberData)
			{
				Dest.DWord = i;
				return true;
			}
		}
		return false;
	}

	default:
		return false;
	}
}

bool MQ2TaskMemberType::ToString(MQVarPtr VarPtr, char* Destination)
{
	auto taskMember = static_cast<SharedTaskPlayerInfo*>(VarPtr.Ptr);
	if (!taskMember)
		return false;

	strcpy_s(Destination, MAX_STRING, taskMember->Name);
	return true;
}

