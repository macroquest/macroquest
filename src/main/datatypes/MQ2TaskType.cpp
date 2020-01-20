#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2TaskType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pTaskManager)
		return false;
	if (!pTaskWnd)
		return false;

	int index = VarPtr.HighPart;
	if (index == -1)
		return false;

	int type = VarPtr.LowPart;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2TaskType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<TaskMethods>(pMethod->ID))
		{
		case Select: {
			Dest.DWord = 0;
			Dest.Type = pBoolType;

			char szTask[MAX_STRING] = { 0 };

			switch (type)
			{
			case cTaskSystemTypeSoloQuest:
				if (CTaskEntry* entry = &pTaskManager->QuestEntries[index])
				{
					strcpy_s(szTask, entry->TaskTitle);
				}
				break;
			case cTaskSystemTypeSharedQuest:
				if (CTaskEntry* entry = &pTaskManager->SharedTaskEntries[0])
				{
					strcpy_s(szTask, entry->TaskTitle);
				}
				break;
			};

			if (szTask[0])
			{
				char szOut[MAX_STRING] = { 0 };

				if (CListWnd* clist = (CListWnd*)pTaskWnd->GetChildItem("TASK_TaskList"))
				{
					CXStr str;
					for (int i = 0; i < clist->ItemsArray.Count; i++)
					{
						CXStr str = clist->GetItemText(i, 2);

						if (ci_equals(szTask, str))
						{
							if (SendListSelect2(clist, i))
							{
								Dest.DWord = 1;
							}
						}
					}
				}
				return true;
			}
		}

		default: break;
		}

		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2TaskType::FindMember(Member);
	if (!pMember)
		return false;

	TASKMEMBER* pTaskmember = (TASKMEMBER*)pTaskMember;
	switch (static_cast<TaskTypeMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)pTaskmember;
		Dest.Type = pIntType;
		return true;

	case Type: {
		switch (type)
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

	case xIndex:
		Dest.Int = VarPtr.Int + 1;
		Dest.Type = pIntType;
		return true;

	case Leader:
		strcpy_s(DataTypeTemp, "NULL");

		for (int i = 1; pTaskmember && i <= MAX_GROUP_SIZE; pTaskmember = pTaskmember->pNext, i++)
		{
			if (pTaskmember->IsLeader)
			{
				strcpy_s(DataTypeTemp, pTaskmember->Name);
				break;
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Title:
		strcpy_s(DataTypeTemp, "NULL");

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			if (CTaskEntry* entry = &pTaskManager->QuestEntries[index])
			{
				strcpy_s(DataTypeTemp, entry->TaskTitle);
			}
			break;

		case cTaskSystemTypeSharedQuest:
			if (CTaskEntry* entry = &pTaskManager->SharedTaskEntries[0])
			{
				strcpy_s(DataTypeTemp, entry->TaskTitle);
			}
			break;

		default:
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Timer: {
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;

		PCTaskStatus* ts = nullptr;
		CTaskEntry* entry = nullptr;

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			ts = pTaskManager->GetTaskStatus(pPCData, index, cTaskSystemTypeSoloQuest);
			entry = &pTaskManager->QuestEntries[index];
			break;

		case cTaskSystemTypeSharedQuest:
			ts = pTaskManager->GetTaskStatus(pPCData, 0, cTaskSystemTypeSharedQuest);
			entry = &pTaskManager->SharedTaskEntries[0];
			break;

		default:
			break;
		}

		if (ts && entry)
		{
			const int ft = static_cast<int>(GetFastTime());
			int timer = 0;
			if (ts->MovingStartTime + entry->DurationSeconds > ft)
			{
				timer = (ts->MovingStartTime + entry->DurationSeconds) - ft;
			}

			Dest.UInt64 = static_cast<uint64_t>(timer) * 1000;
			return true;
		}

		return false;
	}

	case xMember:
		Dest.Type = pTaskMemberType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int pos = GetIntFromString(Index, 0);
			for (int i = 1; pTaskmember && i <= MAX_GROUP_SIZE; pTaskmember = pTaskmember->pNext, i++)
			{
				if (i == pos)
				{
					Dest.Ptr = pTaskmember;
					return true;
				}
			}
		}
		else
		{
			for (; pTaskmember; pTaskmember = pTaskmember->pNext)
			{
				if (!_stricmp(pTaskmember->Name, Index))
				{
					Dest.Ptr = pTaskmember;
					return true;
				}
			}
		}
		return false;

	case Members:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (; pTaskmember && Dest.DWord < MAX_GROUP_SIZE; pTaskmember = pTaskmember->pNext, Dest.DWord++)
		{
		}
		return true;

	case ID: {
		Dest.Int = 0;
		Dest.Type = pIntType;

		CTaskEntry* entry = nullptr;
		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			entry = &pTaskManager->QuestEntries[index];
			break;

		case cTaskSystemTypeSharedQuest:
			entry = &pTaskManager->SharedTaskEntries[0];
			break;

		default:
			break;
		}

		if (entry)
		{
			Dest.Int = entry->TaskID;
		}
		return true;
	}

	case Objective: {
		Dest.Int = 0;
		Dest.Type = pTaskObjectiveType;

		PCTaskStatus* ts = nullptr;
		CTaskEntry* entry = nullptr;

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			ts = pTaskManager->GetTaskStatus(pPCData, index, cTaskSystemTypeSoloQuest);
			entry = &pTaskManager->QuestEntries[index];
			break;

		case cTaskSystemTypeSharedQuest:
			ts = pTaskManager->GetTaskStatus(pPCData, 0, cTaskSystemTypeSharedQuest);
			entry = &pTaskManager->SharedTaskEntries[0];
			break;

		default: break;
		}

		if (ts && entry)
		{
			int stepIndex = -1;

			if (IsNumber(Index))
			{
				stepIndex = std::clamp(GetIntFromString(Index, stepIndex) - 1, 0, MAX_TASK_ELEMENTS - 1);
			}
			else
			{
				char szOut[MAX_STRING] = { 0 };

				for (int i = 0; i < MAX_TASK_ELEMENTS; i++)
				{
					pTaskManager->GetElementDescription(&entry->Elements[i], szOut);

					if (ci_find_substr(szOut, Index))
					{
						stepIndex = i;
						break;
					}
				}
			}

			// FIXME: Search Dword = (int)MAKELPARAM and fix through this whole commit.
			Dest.DWord = (int)MAKELPARAM(type, index);
			Dest.HighPart = stepIndex;
			return true;
		}

		return false;
	}

	case Step: { // gets the first step that's not Done in the task objective.
		Dest.Int = 0;
		Dest.Type = pTaskObjectiveType;

		PCTaskStatus* ts = nullptr;
		CTaskEntry* entry = nullptr;

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			ts = pTaskManager->GetTaskStatus(pPCData, index, cTaskSystemTypeSoloQuest);
			entry = &pTaskManager->QuestEntries[index];
			break;
		case cTaskSystemTypeSharedQuest:
			ts = pTaskManager->GetTaskStatus(pPCData, 0, cTaskSystemTypeSharedQuest);
			entry = &pTaskManager->SharedTaskEntries[0];
			break;
		}

		if (ts && entry)
		{
			int reqCount = 0;
			int curCount = 0;

			for (int i = 0; i < MAX_TASK_ELEMENTS; i++)
			{
				reqCount = entry->Elements[i].RequiredCount;
				curCount = ts->CurrentCounts[i];

				if (curCount < reqCount && !entry->Elements[i].bOptional)
				{
					Dest.DWord = (int)MAKELPARAM(type, index);
					Dest.HighPart = i;
					return true;
				}
			}
		}
		return false;
	}

	case WindowIndex: {
		char szTask[MAX_STRING] = { 0 };
		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			if (CTaskEntry* entry = &pTaskManager->QuestEntries[index])
			{
				strcpy_s(szTask, entry->TaskTitle);
			}
			break;

		case cTaskSystemTypeSharedQuest:
			if (CTaskEntry* entry = &pTaskManager->SharedTaskEntries[0])
			{
				strcpy_s(szTask, entry->TaskTitle);
			}
			break;
		};

		if (CListWnd* clist = (CListWnd*)pTaskWnd->GetChildItem("TASK_TaskList"))
		{
			for (int i = 0; i < clist->ItemsArray.Count; i++)
			{
				CXStr str = clist->GetItemText(i, 2);

				if (ci_equals(szTask, str))
				{
					Dest.DWord = i + 1;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	}

	default: break;
	}

	return false;
}

bool MQ2TaskType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, "NULL");

	int index = HIWORD(VarPtr.DWord);
	int type = LOWORD(VarPtr.DWord);

	if (pTaskManager)
	{
		CTaskEntry* entry = nullptr;

		switch (type)
		{
		case cTaskSystemTypeSoloQuest:
			entry = &pTaskManager->QuestEntries[index];
			break;

		case cTaskSystemTypeSharedQuest:
			entry = &pTaskManager->SharedTaskEntries[0];
			break;
		};

		strcpy_s(Destination, MAX_STRING, entry->TaskTitle);
	}

	return true;
}

