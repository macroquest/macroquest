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

enum class TaskTypeMembers
{
	Index = 1,
	Title,
	Timer,
	Member,
	Members,
	Leader,
	Step,
	Objective,
	Type,
	MemberList,
	ID,
	WindowIndex
};

enum class TaskTypeMethods
{
	Select = 1,
};

int FindTaskIndex(CTaskEntry* task)
{
	if (!task || !pTaskManager)
		return -1;

	switch (task->TaskSystem)
	{
	case TaskSystemType::cTaskSystemTypeSharedQuest:
		for (int i = 0; i < MAX_SHARED_TASK_ENTRIES; ++i)
		{
			if (&pTaskManager->SharedTaskEntries[i] == task)
				return i;
		}
		break;

	case TaskSystemType::cTaskSystemTypeSoloQuest:
		for (int i = 0; i < MAX_QUEST_ENTRIES; ++i)
		{
			if (&pTaskManager->QuestEntries[i] == task)
				return i;
		}
		break;

	default:
		break;
	}

	return -1;
}

MQ2TaskType::MQ2TaskType() : MQ2Type("task")
{
	ScopedTypeMember(TaskTypeMembers, Index);
	ScopedTypeMember(TaskTypeMembers, Title);
	ScopedTypeMember(TaskTypeMembers, Timer);
	ScopedTypeMember(TaskTypeMembers, Member);
	ScopedTypeMember(TaskTypeMembers, Members);
	ScopedTypeMember(TaskTypeMembers, Leader);
	ScopedTypeMember(TaskTypeMembers, Step);
	ScopedTypeMember(TaskTypeMembers, Objective);
	ScopedTypeMember(TaskTypeMembers, Type);
	ScopedTypeMember(TaskTypeMembers, MemberList);
	ScopedTypeMember(TaskTypeMembers, ID);
	ScopedTypeMember(TaskTypeMembers, WindowIndex);

	ScopedTypeMethod(TaskTypeMethods, Select);
}


bool MQ2TaskType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto pTask = static_cast<CTaskEntry*>(VarPtr.Ptr);
	if (!pTask)
		return false;

	//----------------------------------------------------------------------------
	// methods

	if (MQTypeMember* pMethod = MQ2TaskType::FindMethod(Member))
	{
		switch (static_cast<TaskTypeMethods>(pMethod->ID))
		{
		case TaskTypeMethods::Select:
		{
			Dest.Type = pBoolType;
			Dest.Set(false);

			if (!pTaskWnd || !pTask->TaskTitle[0])
				return true;

			auto clist = static_cast<CListWnd*>(pTaskWnd->GetChildItem("TASK_TaskList"));
			if (!clist)
				return true;

			for (int i = 0; i < clist->ItemsArray.Count; ++i)
			{
				if (ci_equals(pTask->TaskTitle, clist->GetItemText(i, 2)))
				{
					Dest.Set(SendListSelect2(clist, i));
					return true;
				}
			}

			return true;
		}

		default:
			return false;
		}
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2TaskType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<TaskTypeMembers>(pMember->ID))
	{
	case TaskTypeMembers::Type: {
		switch (pTask->TaskSystem)
		{
		case cTaskSystemTypeSoloQuest:
			strcpy_s(DataTypeTemp, "Quest");
			break;
		case cTaskSystemTypeSharedQuest:
			strcpy_s(DataTypeTemp, "Shared");
			break;
		default:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		}

		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case TaskTypeMembers::Index:
	{
		if (!pTaskManager)
			return false;

		Dest.Type = pIntType;

		unsigned int offset = 0;
		for (int i = 0; i < MAX_SHARED_TASK_ENTRIES; ++i)
		{
			auto& sharedTask = pTaskManager->SharedTaskEntries[i];
			if (sharedTask.TaskID && &sharedTask == pTask)
			{
				Dest.Int = i + 1;
				return true;
			}

			if (sharedTask.TaskID)
				++offset;
		}

		for (int i = 0; i < MAX_QUEST_ENTRIES; ++i)
		{
			if (&pTaskManager->QuestEntries[i] == pTask)
			{
				Dest.Int = i + offset + 1;
				return true;
			}
		}

		return false;
	}

	case TaskTypeMembers::Leader:
		for (auto taskMember = pTaskMember.get(); taskMember != nullptr; taskMember = taskMember->pNext)
		{
			if (taskMember->IsLeader) {
				Dest.Type = pTaskMemberType;
				Dest.Ptr = taskMember;
				return true;
			}
		}

		return false;

	case TaskTypeMembers::Title:
		strcpy_s(DataTypeTemp, pTask->TaskTitle);

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TaskTypeMembers::Timer:
	{
		if (!pTaskManager)
			return false;

		int idx = FindTaskIndex(pTask);
		if (idx < 0)
			return false;

		auto taskStatus = pTaskManager->GetTaskStatus(pLocalPC, idx, pTask->TaskSystem);

		if (!taskStatus)
			return false;

		int seconds = pTask->DurationSeconds - GetFastTime();

		Dest.UInt64 = (uint64_t)std::max(0, (taskStatus->MovingStartTime + seconds) * 1000);
		Dest.Type = pTimeStampType;
		return true;
	}

	case TaskTypeMembers::Member:
	{
		Dest.Type = pTaskMemberType;
		if (!Index[0])
			return false;

		int pos = GetIntFromString(Index, 0);
		if (pos >= 0)
		{
			int i = 1;
			for (SharedTaskPlayerInfo* taskMember = pTaskMember;
				taskMember;
				taskMember = taskMember->pNext, ++i)
			{
				if (i == pos)
				{
					Dest.Ptr = taskMember;
					return true;
				}
			}

			return false;
		}

		for (auto taskMember = pTaskMember.get(); taskMember; taskMember = taskMember->pNext)
		{
			if (!_stricmp(taskMember->Name, Index))
			{
				Dest.Ptr = taskMember;
				return true;
			}
		}

		return false;
	}

	case TaskTypeMembers::Members:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (auto taskMember = pTaskMember.get(); taskMember != nullptr; taskMember = taskMember->pNext)
		{
			++Dest.DWord;
		}
		return true;

	case TaskTypeMembers::ID:
		Dest.Int = pTask->TaskID;
		Dest.Type = pIntType;
		return true;

	case TaskTypeMembers::Objective:
	{
		if (!Index[0] || !pTaskManager)
			return false;

		Dest.Type = pTaskObjectiveType;

		int index = GetIntFromString(Index, 0) - 1;
		if (index >= 0)
		{
			// avoid array out of bounds and elements that don't exist
			if (index >= MAX_TASK_ELEMENTS || pTask->Elements[index].Type <= 0)
				return false;

			Dest.Ptr = &pTask->Elements[index];
			return true;
		}

		char szOut[MAX_STRING] = { 0 };
		for (auto& Element : pTask->Elements)
		{
			pTaskManager->GetElementDescription(&Element, szOut);
			if (MaybeExactCompare(szOut, Index))
			{
				Dest.Ptr = &Element;
				return true;
			}
		}

		return false;
	}

	case TaskTypeMembers::Step: // gets the first step that's not Done in the task objective.
	{
		if (!pTaskManager)
			return false;

		Dest.Type = pTaskObjectiveType;

		int idx = FindTaskIndex(pTask);
		if (idx < 0)
			return false;

		auto taskStatus = pTaskManager->GetTaskStatus(pLocalPC, idx, pTask->TaskSystem);

		for (int i = 0; i < MAX_TASK_ELEMENTS; ++i)
		{
			if (taskStatus->CurrentCounts[i] < pTask->Elements[i].RequiredCount && !pTask->Elements[i].bOptional)
			{
				Dest.Ptr = &pTask->Elements[i];
				return true;
			}
		}

		return false;
	}

	case TaskTypeMembers::WindowIndex:
	{
		if (!pTaskWnd)
			return false;

		auto clist = static_cast<CListWnd*>(pTaskWnd->GetChildItem("TASK_TaskList"));
		if (!clist)
			return false;

		Dest.Type = pIntType;

		for (int i = 0; i < clist->ItemsArray.Count; ++i)
		{
			if (ci_equals(pTask->TaskTitle, clist->GetItemText(i, 2)))
			{
				Dest.DWord = i + 1;
				return true;
			}
		}

		return false;
	}

	default:
		return false;
	}
}

bool MQ2TaskType::ToString(MQVarPtr VarPtr, char* Destination)
{
	auto pTask = static_cast<CTaskEntry*>(VarPtr.Ptr);
	if (!pTask)
		return false;

	strcpy_s(Destination, MAX_STRING, pTask->TaskTitle);

	return true;
}

bool MQ2TaskType::dataTask(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Type = pTaskType;

	if (!pTaskManager || !szIndex[0])
		return false;

	int taskIndex = GetIntFromString(szIndex, 0) - 1; // this is 1-indexed in the TLO
	if (taskIndex >= 0) {
		unsigned char offset = 0;

		// let's bail early if we have a bad index, no need to log because this argument is unconstrained
		if (taskIndex >= MAX_SHARED_TASK_ENTRIES + MAX_QUEST_ENTRIES)
			return false;

		for (int i = 0; i < MAX_SHARED_TASK_ENTRIES; ++i)
		{
			auto& sharedEntry = pTaskManager->SharedTaskEntries[i];
			if (taskIndex == i && sharedEntry.TaskID)
			{
				Ret.Ptr = &sharedEntry;
				return true;
			}

			// shared entry exists, but we don't want it by index
			if (sharedEntry.TaskID)
				++offset;
		}

		// offset the index by the number of shared tasks that existed before looking for solo tasks
		// this should never be less than 0 because offset only increases if we didn't find a
		// shared task by index and there was a shared task, but just in case let's make sure we
		// don't get an array out of bounds
		if (taskIndex < offset || taskIndex - offset >= MAX_QUEST_ENTRIES)
		{
			DebugSpewAlways("Index %d (passed %s) out of bounds for quest entries", taskIndex - offset, szIndex);
			return false;
		}

		Ret.Ptr = &pTaskManager->QuestEntries[taskIndex - offset];
		return true;
	}

	// look up the task by name -- we loop by index here because it's the easiest way to
	// loop by address of the task arrays
	for (auto& sharedEntry : pTaskManager->SharedTaskEntries)
	{
		if (sharedEntry.TaskID && MaybeExactCompare(sharedEntry.TaskTitle, szIndex))
		{
			Ret.Ptr = &sharedEntry;
			return true;
		}
	}

	for (auto& questEntry : pTaskManager->QuestEntries)
	{
		if (questEntry.TaskID && MaybeExactCompare(questEntry.TaskTitle, szIndex))
		{
			Ret.Ptr = &questEntry;
			return true;
		}
	}

	return false;
}

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

bool MQ2TaskMemberType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
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
		Dest.Set(pTaskMemberData->IsLeader != 0);
		Dest.Type = pBoolType;
		return true;

	case TaskMemberTypeMembers::Index:
	{
		if (!pTaskMember)
			return false;

		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (auto taskMember = pTaskMember.get(); taskMember != nullptr; taskMember = taskMember->pNext)
		{
			++Dest.DWord;

			if (taskMember == pTaskMemberData)
				return true;
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

struct ObjectiveIndex
{
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

MQ2TaskObjectiveType::MQ2TaskObjectiveType() : MQ2Type("taskobjective")
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

bool MQ2TaskObjectiveType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
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

		auto taskStatus = pTaskManager->GetTaskStatus(pLocalPC, idx.taskIndex, idx.systemType);
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
		int zid = GetIntFromString(pTaskObjective->ZoneID, 0) & 0x7FFF;

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

		auto taskStatus = pTaskManager->GetTaskStatus(pLocalPC, idx.taskIndex, idx.systemType);
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
		Dest.Set(pTaskObjective->bOptional);
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

} // namespace mq::datatypes
