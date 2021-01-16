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
				return false;

			auto clist = static_cast<CListWnd*>(pTaskWnd->GetChildItem("TASK_TaskList"));
			if (!clist)
				return false;

			for (int i = 0; i < clist->ItemsArray.Count; ++i)
			{
				if (ci_equals(pTask->TaskTitle, clist->GetItemText(i, 2)))
				{
					Dest.Set(SendListSelect2(clist, i));
					return true;
				}
			}

			return false;
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
			const auto sharedTask = &pTaskManager->SharedTaskEntries[i];
			if (sharedTask && sharedTask->TaskID && sharedTask == pTask)
			{
				Dest.Int = i + 1;
				return true;
			}

			if (sharedTask && sharedTask->TaskID)
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
		for (auto taskMember = pTaskMember; taskMember; taskMember = taskMember->pNext)
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

		auto taskStatus = pTaskManager->GetTaskStatus(pPCData, idx, pTask->TaskSystem);

		if (!taskStatus)
			return false;

		Dest.UInt64 = std::max(0UL, taskStatus->MovingStartTime + pTask->DurationSeconds - GetFastTime());
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

		for (auto taskMember = pTaskMember; pTaskMember; pTaskMember = pTaskMember->pNext)
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
		for (auto taskMember = pTaskMember; taskMember; taskMember = taskMember->pNext, ++Dest.DWord);
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

		auto taskStatus = pTaskManager->GetTaskStatus(pPCData, idx, pTask->TaskSystem);

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
			auto sharedEntry = &pTaskManager->SharedTaskEntries[i];
			if (taskIndex == i && sharedEntry && sharedEntry->TaskID)
			{
				Ret.Ptr = sharedEntry;
				return true;
			}

			// shared entry exists, but we don't want it by index
			if (sharedEntry && sharedEntry->TaskID)
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
	for (auto& SharedTaskEntry : pTaskManager->SharedTaskEntries)
	{
		auto* sharedEntry = &SharedTaskEntry;
		if (sharedEntry && sharedEntry->TaskID && MaybeExactCompare(sharedEntry->TaskTitle, szIndex))
		{
			Ret.Ptr = sharedEntry;
			return true;
		}
	}

	for (auto& QuestEntry : pTaskManager->QuestEntries)
	{
		auto* questEntry = &QuestEntry;
		if (questEntry && questEntry->TaskID && MaybeExactCompare(questEntry->TaskTitle, szIndex))
		{
			Ret.Ptr = questEntry;
			return true;
		}
	}

	return false;
}

} // namespace mq::datatypes
