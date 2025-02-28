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

enum class EverQuestMembers
{
	GameState = 1,
	LoginName,
	Server,
	LastCommand,
	LastTell,
	Running,
	MouseX,
	MouseY,
	Ping,
	ConnectionStrength,
	LClickedObject,
	WinTitle,
	PID,
	PPriority,
	ChatChannels,
	ChatChannel,
	ViewportX,
	ViewportY,
	ViewportXMax,
	ViewportYMax,
	ViewportXCenter,
	ViewportYCenter,
	xScreenMode,
	LayoutCopyInProgress,
	LastMouseOver,
	CharSelectList,
	CurrentUI,
	IsDefaultUILoaded,
	HWND,
	Foreground,
	ValidLoc,
	Path,
	MaxFPS,
	MaxBGFPS,
	UiScale,
};

MQ2EverQuestType::MQ2EverQuestType() : MQ2Type("everquest")
{
	ScopedTypeMember(EverQuestMembers, GameState);
	ScopedTypeMember(EverQuestMembers, LoginName);
	ScopedTypeMember(EverQuestMembers, Server);
	ScopedTypeMember(EverQuestMembers, LastCommand);
	ScopedTypeMember(EverQuestMembers, LastTell);
	ScopedTypeMember(EverQuestMembers, Running);
	ScopedTypeMember(EverQuestMembers, MouseX);
	ScopedTypeMember(EverQuestMembers, MouseY);
	ScopedTypeMember(EverQuestMembers, Ping);
	ScopedTypeMember(EverQuestMembers, ChatChannels);
	ScopedTypeMember(EverQuestMembers, ChatChannel);
	ScopedTypeMember(EverQuestMembers, ViewportX);
	ScopedTypeMember(EverQuestMembers, ViewportY);
	ScopedTypeMember(EverQuestMembers, ViewportXMax);
	ScopedTypeMember(EverQuestMembers, ViewportYMax);
	ScopedTypeMember(EverQuestMembers, ViewportXCenter);
	ScopedTypeMember(EverQuestMembers, ViewportYCenter);
	ScopedTypeMember(EverQuestMembers, LClickedObject);
	ScopedTypeMember(EverQuestMembers, WinTitle);
	ScopedTypeMember(EverQuestMembers, PID);
	ScopedTypeMember(EverQuestMembers, PPriority);
	AddMember(static_cast<int>(EverQuestMembers::xScreenMode), "ScreenMode");
	ScopedTypeMember(EverQuestMembers, LayoutCopyInProgress);
	ScopedTypeMember(EverQuestMembers, LastMouseOver);
	ScopedTypeMember(EverQuestMembers, CharSelectList);
	ScopedTypeMember(EverQuestMembers, CurrentUI);
	ScopedTypeMember(EverQuestMembers, IsDefaultUILoaded);
	ScopedTypeMember(EverQuestMembers, HWND);
	ScopedTypeMember(EverQuestMembers, Foreground);
	ScopedTypeMember(EverQuestMembers, ValidLoc);
	ScopedTypeMember(EverQuestMembers, Path);
	ScopedTypeMember(EverQuestMembers, MaxFPS);
	ScopedTypeMember(EverQuestMembers, MaxBGFPS);
	ScopedTypeMember(EverQuestMembers, UiScale);
	ScopedTypeMember(EverQuestMembers, ConnectionStrength);
}

bool MQ2EverQuestType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2EverQuestType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<EverQuestMembers>(pMember->ID))
	{
	case EverQuestMembers::HWND:
		if (EQW_GetDisplayWindow)
			Dest.Int64 = (uintptr_t)EQW_GetDisplayWindow();
		else
			Dest.Int64 = *(uintptr_t*)EQADDR_HWND;
		Dest.Type = pInt64Type;
		return true;

	case EverQuestMembers::GameState:
		if (gGameState == GAMESTATE_CHARSELECT)
			strcpy_s(DataTypeTemp, "CHARSELECT");
		else if (gGameState == GAMESTATE_INGAME)
			strcpy_s(DataTypeTemp, "INGAME");
		else if (GetGameState() == GAMESTATE_PRECHARSELECT)
			strcpy_s(DataTypeTemp, "PRECHARSELECT");
		else
			strcpy_s(DataTypeTemp, "UNKNOWN");

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case EverQuestMembers::LoginName:
		Dest.Type = pStringType;
		if (const char* pTemp = GetLoginName())
		{
			strcpy_s(DataTypeTemp, pTemp);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case EverQuestMembers::Server:
		Dest.Type = pStringType;
		if (GetServerShortName()[0])
		{
			strcpy_s(DataTypeTemp, GetServerShortName());
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case EverQuestMembers::LastCommand:
		Dest.Type = pStringType;
		if (szLastCommand[0])
		{
			Dest.Ptr = &szLastCommand[0];
			return true;
		}
		return false;

	case EverQuestMembers::LastTell:
		Dest.Type = pStringType;
		if (pEverQuestInfo->LastTellFromList[0][0])
		{
			strcpy_s(DataTypeTemp, pEverQuestInfo->LastTellFromList[0]);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case EverQuestMembers::Running:
		Dest.DWord = (DWORD)clock();
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::MouseX:
		Dest.DWord = EQADDR_MOUSE->X;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::MouseY:
		Dest.DWord = EQADDR_MOUSE->Y;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::Ping:
		Dest.DWord = pConnection ? pConnection->GetAveragePing() : 0;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::ConnectionStrength:
		Dest.Float = pConnection ? (pConnection->GetConnectionStrength() * 100.f) : 0.0f;
		Dest.Type = pFloatType;
		return true;


	case EverQuestMembers::ChatChannels:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pEverQuest && pEverQuest->chatService)
		{
			Dest.DWord = pEverQuest->chatService->ActiveChannels;
			return true;
		}
		return false;

	case EverQuestMembers::ChatChannel:
		Dest.Type = pStringType;
		if (pEverQuest && pEverQuest->chatService)
		{
			if (IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (pEverQuest->chatService->ActiveChannels
					&& index >= 0
					&& index < pEverQuest->chatService->ActiveChannels)
				{
					strcpy_s(DataTypeTemp, pEverQuest->chatService->ChannelList[index]);
					Dest.Ptr = &DataTypeTemp[0];
					Dest.Type = pStringType;
					return true;
				}
			}
			else
			{
				char Name[MAX_STRING] = { 0 };
				strcpy_s(Name, Index);

				for (int i = 0; i < pEverQuest->chatService->ActiveChannels; i++)
				{
					if (!_stricmp(Name, pEverQuest->chatService->ChannelList[i]))
					{
						Dest.Set(true);
						Dest.Type = pBoolType;
						return true;
					}
				}
			}
		}
		return false;

	case EverQuestMembers::ViewportX:
		Dest.DWord = ScreenX;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::ViewportY:
		Dest.DWord = ScreenY;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::ViewportXMax:
		Dest.DWord = ScreenXMax;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::ViewportYMax:
		Dest.DWord = ScreenYMax;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::ViewportXCenter:
		Dest.DWord = ScreenXMax / 2;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::ViewportYCenter:
		Dest.DWord = ScreenYMax / 2;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::LClickedObject:
		Dest.Set(gLClickedObject);
		Dest.Type = pBoolType;
		return true;

	case EverQuestMembers::WinTitle: {
		Dest.Type = pStringType;
		HWND hEQWnd = GetEQWindowHandle();
		if (hEQWnd)
		{
			GetWindowTextA(hEQWnd, DataTypeTemp, static_cast<int>(DataTypeTemp.size()));

			if (DataTypeTemp[0] != 0)
			{
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}

		return false;
	}

	case EverQuestMembers::PID:
		Dest.DWord = GetCurrentProcessId();
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::xScreenMode:
		Dest.DWord = ScreenMode;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::MaxFPS:
		Dest.DWord = pEverQuestInfo->gOpt.maxFPS;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::MaxBGFPS:
		Dest.DWord = pEverQuestInfo->gOpt.maxBGFPS;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::PPriority:
		strcpy_s(DataTypeTemp, "UNKNOWN");

		if (HANDLE heqg = OpenProcess(PROCESS_QUERY_INFORMATION, false, GetCurrentProcessId()))
		{
			DWORD prio = GetPriorityClass(heqg);
			switch (prio)
			{
			case IDLE_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "LOW");
				break;
			case BELOW_NORMAL_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "BELOW NORMAL");
				break;
			case NORMAL_PRIORITY_CLASS:
				prio = NORMAL_PRIORITY_CLASS;
				strcpy_s(DataTypeTemp, "NORMAL");
				break;
			case ABOVE_NORMAL_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "ABOVE NORMAL");
				break;
			case HIGH_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "HIGH");
				break;
			case REALTIME_PRIORITY_CLASS:
				strcpy_s(DataTypeTemp, "REALTIME");
				break;
			default:
				break;
			}

			CloseHandle(heqg);
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case EverQuestMembers::LayoutCopyInProgress:
		Dest.Set(*(BYTE*)CSidlScreenWnd__m_layoutCopy != 0);
		Dest.Type = pBoolType;
		return true;

	case EverQuestMembers::LastMouseOver:
		Dest.Type = pWindowType;
		if (pWndMgr)
		{
			Dest.Ptr = pWndMgr->LastMouseOver;
			return true;
		}
		return false;

	case EverQuestMembers::CharSelectList:
		Dest.DWord = 0;
		Dest.Type = pCharSelectListType;

		if (Index[0] && pEverQuest)
		{
			if (IsNumber(Index))
			{
				int num = GetIntFromString(Index, 0) - 1;
				if (num < 0)
					num = 0;

				if (num <= pEverQuest->charSelectPlayerArray.GetCount())
				{
					Dest.DWord = num;
					return true;
				}
			}
			else
			{
				for (int i = 0; i < pEverQuest->charSelectPlayerArray.GetCount(); i++)
				{
					if (!_stricmp(Index, pEverQuest->charSelectPlayerArray[i].Name))
					{
						Dest.DWord = i;
						return true;
					}
				}
			}
		}
		return false;

	case EverQuestMembers::CurrentUI:
		Dest.Ptr = &gUISkin[0];
		Dest.Type = pStringType;
		return true;

	case EverQuestMembers::IsDefaultUILoaded:
		Dest.Set(ci_equals(gUISkin, "Default"));
		Dest.Type = pBoolType;
		return true;

	case EverQuestMembers::Foreground:
		Dest.Set(gbInForeground);
		Dest.Type = pBoolType;
		return true;

	case EverQuestMembers::ValidLoc: {
		//usage /echo ${EverQuest.ValidLoc[123 456 789]}

		auto szLoc = std::make_unique<char[]>(MAX_STRING);
		GetArg(szLoc.get(), Index, 1);
		float X = GetFloatFromString(szLoc.get(), 0);
		GetArg(szLoc.get(), Index, 2);
		float Y = GetFloatFromString(szLoc.get(), 0);
		GetArg(szLoc.get(), Index, 3);
		float Z = GetFloatFromString(szLoc.get(), 0);

		Dest.Set(pLocalPlayer ? pLocalPlayer->IsValidTeleport(Y, X, Z, 0, 0) : false);
		Dest.Type = pBoolType;
		return true;
	}

	case EverQuestMembers::Path: {
		Dest.Type = pStringType;
		Dest.Ptr = &mq::internal_paths::EverQuest[0];
		return true;
	}

	case EverQuestMembers::UiScale: {
		Dest.Type = pFloatType;
#if HAS_GAMEFACE_UI
		Dest.Float = static_cast<float>(pEverQuestInfo->UiScale);
#else
		Dest.Float = 1.0f;
#endif
		return true;
	}

	default: break;
	}

	return false;
}

bool MQ2EverQuestType::ToString(MQVarPtr VarPtr, char* Destination)
{
	return false;
}

bool MQ2EverQuestType::dataEverQuest(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = 0;
	Ret.Type = pEverQuestType;
	return true;
}

} // namespace mq::datatypes
