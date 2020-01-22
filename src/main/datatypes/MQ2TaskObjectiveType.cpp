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

enum class TaskObjectiveTypeMembers
{
	Instruction = 1,
	Status,
	Zone,
	Index,
	Type,
	RequiredCount,
	Optional,
	RequiredItem,
	RequiredSkill,
	RequiredSpell,
	DZSwitchID,
	CurrentCount
};

struct ObjectiveIndex {
	int taskIndex;
	int objectiveIndex;
	TaskSystemType systemType;
};

ObjectiveIndex FindObjectiveIndex(CTaskElement* objective)
{
	if (!pTaskManager || !objective)
		return { -1, -1, TaskSystemType::cTaskSystemTypeTask };

	for (int i = 0; i < MAX_SHARED_TASK_ENTRIES; ++i)
	{
		auto sharedEntry = &pTaskManager->SharedTaskEntries[i];
		if (!sharedEntry || !sharedEntry->TaskID)
			continue;

		for (int j = 0; j < MAX_TASK_ELEMENTS; ++j)
		{
			if (&sharedEntry->Elements[j] == objective)
				return { i, j, TaskSystemType::cTaskSystemTypeSharedQuest };
		}
	}

	for (int i = 0; i < MAX_QUEST_ENTRIES; ++i)
	{
		auto questEntry = &pTaskManager->QuestEntries[i];
		if (!questEntry || !questEntry->TaskID)
			continue;

		for (int j = 0; j < MAX_TASK_ELEMENTS; ++j)
		{
			if (&questEntry->Elements[j] == objective)
				return { i, j, TaskSystemType::cTaskSystemTypeSoloQuest };
		}
	}

	return { -1, -1, TaskSystemType::cTaskSystemTypeTask };
}

MQ2TaskObjectiveType::MQ2TaskObjectiveType() : MQ2Type("taskobjectivemember")
{
	ScopedTypeMember(TaskObjectiveTypeMembers, Instruction);
	ScopedTypeMember(TaskObjectiveTypeMembers, Status);
	ScopedTypeMember(TaskObjectiveTypeMembers, Zone);
	ScopedTypeMember(TaskObjectiveTypeMembers, Index);
	ScopedTypeMember(TaskObjectiveTypeMembers, Type);
	ScopedTypeMember(TaskObjectiveTypeMembers, RequiredCount);
	ScopedTypeMember(TaskObjectiveTypeMembers, Optional);
	ScopedTypeMember(TaskObjectiveTypeMembers, RequiredItem);
	ScopedTypeMember(TaskObjectiveTypeMembers, RequiredSkill);
	ScopedTypeMember(TaskObjectiveTypeMembers, RequiredSpell);
	ScopedTypeMember(TaskObjectiveTypeMembers, DZSwitchID);
	ScopedTypeMember(TaskObjectiveTypeMembers, CurrentCount);
}

bool MQ2TaskObjectiveType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	auto pTaskObjective = static_cast<CTaskElement*>(VarPtr.Ptr);
	if (!pTaskObjective)
		return false;

	MQTypeMember* pMember = MQ2TaskObjectiveType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TaskObjectiveTypeMembers>(pMember->ID))
	{
	case TaskObjectiveTypeMembers::Instruction:
		if (!pTaskManager)
			return false;

		pTaskManager->GetElementDescription(pTaskObjective, DataTypeTemp);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TaskObjectiveTypeMembers::Status:
	{
		if (!pTaskManager)
			return false;

		auto idx = FindObjectiveIndex(pTaskObjective);

		if (idx.taskIndex < 0)
			return false;

		auto taskStatus = pTaskManager->GetTaskStatus(pPCData, idx.taskIndex, idx.systemType);
		if (!taskStatus)
			return false;

		if (taskStatus->CurrentCounts[idx.objectiveIndex] == pTaskObjective->RequiredCount)
			strcpy_s(DataTypeTemp, "Done");
		else
			sprintf_s(DataTypeTemp, "%d/%d", taskStatus->CurrentCounts[idx.objectiveIndex], pTaskObjective->RequiredCount);

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}

	case TaskObjectiveTypeMembers::Zone:
	{
		int zid = GetIntFromString(pTaskObjective->TargetZoneID, 0) & 0x7FFF;

		if (zid == 0)
		{
			strcpy_s(DataTypeTemp, "ALL");

			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}

		if (zid < MAX_ZONES && pWorldData->ZoneArray[zid])
		{
			Dest.Ptr = pWorldData->ZoneArray[zid];
			Dest.Type = pZoneType;
			return true;
		}

		return false;
	}

	case TaskObjectiveTypeMembers::Index:
	{
		auto idx = FindObjectiveIndex(pTaskObjective);
		if (idx.objectiveIndex < 0)
			return false;

		Dest.Int = idx.objectiveIndex + 1;
		Dest.Type = pIntType;
		return true;
	}

	case TaskObjectiveTypeMembers::Type:
	{
		switch (pTaskObjective->Type)
		{
		case cTaskTypeUnknown:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		case cTaskTypeNone:
			strcpy_s(DataTypeTemp, "None");
			break;
		case cTaskTypeDeliver:
			strcpy_s(DataTypeTemp, "Deliver");
			break;
		case cTaskTypeKill:
			strcpy_s(DataTypeTemp, "Kill");
			break;
		case cTaskTypeLoot:
			strcpy_s(DataTypeTemp, "Loot");
			break;
		case cTaskTypeHail:
			strcpy_s(DataTypeTemp, "Hail");
			break;
		case cTaskTypeExplore:
			strcpy_s(DataTypeTemp, "Explore");
			break;
		case cTaskTypeTradeskill:
			strcpy_s(DataTypeTemp, "Tradeskill");
			break;
		case cTaskTypeFishing:
			strcpy_s(DataTypeTemp, "Fishing");
			break;
		case cTaskTypeForaging:
			strcpy_s(DataTypeTemp, "Foraging");
			break;
		case cTaskTypeCast:
			strcpy_s(DataTypeTemp, "Cast");
			break;
		case cTaskTypeUseSkill:
			strcpy_s(DataTypeTemp, "UseSkill");
			break;
		case cTaskTypeDZSwitch:
			strcpy_s(DataTypeTemp, "DZSwitch");
			break;
		case cTaskTypeDestroyObject:
			strcpy_s(DataTypeTemp, "DestroyObject");
			break;
		case cTaskTypeCollect:
			strcpy_s(DataTypeTemp, "Collect");
			break;
		case cTaskTypeDialogue:
			strcpy_s(DataTypeTemp, "Dialogue");
			break;
		default:
			strcpy_s(DataTypeTemp, "NULL");
			break;
		};

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}

	case TaskObjectiveTypeMembers::CurrentCount:
	{
		auto idx = FindObjectiveIndex(pTaskObjective);
		if (idx.taskIndex < 0)
			return false;

		auto taskStatus = pTaskManager->GetTaskStatus(pPCData, idx.taskIndex, idx.systemType);
		if (!taskStatus)
			return false;

		Dest.Int = taskStatus->CurrentCounts[idx.objectiveIndex];
		Dest.Type = pIntType;
		return true;
	}

	case TaskObjectiveTypeMembers::RequiredCount:
		Dest.Int = pTaskObjective->RequiredCount;
		Dest.Type = pIntType;
		return true;

	case TaskObjectiveTypeMembers::Optional:
		Dest.DWord = pTaskObjective->bOptional;
		Dest.Type = pBoolType;
		return true;

	case TaskObjectiveTypeMembers::RequiredItem:
		strcpy_s(DataTypeTemp, pTaskObjective->ItemNameList.c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TaskObjectiveTypeMembers::RequiredSkill:
		strcpy_s(DataTypeTemp, pTaskObjective->SkillIDList.c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TaskObjectiveTypeMembers::RequiredSpell:
		strcpy_s(DataTypeTemp, pTaskObjective->SpellIDList.c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TaskObjectiveTypeMembers::DZSwitchID:
		Dest.DWord = pTaskObjective->DZSwitchID;
		Dest.Type = pIntType;
		return true;

	default:
		return false;
	}
}

bool MQ2TaskObjectiveType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!pTaskManager)
		return false;

	auto pTaskObjective = static_cast<CTaskElement*>(VarPtr.Ptr);
	if (!pTaskObjective)
		return false;

	char szOut[MAX_STRING] = { 0 };
	pTaskManager->GetElementDescription(pTaskObjective, szOut);

	if (szOut[0])
	{
		strcpy_s(Destination, MAX_STRING, szOut);
		return true;
	}

	return false;
}

