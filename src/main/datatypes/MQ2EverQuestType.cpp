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

enum class EverQuestMembers
{
	GameState,
	LoginName,
	Server,
	LastCommand,
	LastTell,
	Running,
	MouseX,
	MouseY,
	Ping,
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
	Path
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
}

bool MQ2EverQuestType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2EverQuestType::FindMember(Member);
	if (!pMember)
		return false;

	EVERQUEST* pEQ = (EVERQUEST*)pEverQuest;

	switch (static_cast<EverQuestMembers>(pMember->ID))
	{
	case EverQuestMembers::HWND:
		if (EQW_GetDisplayWindow)
			Dest.DWord = (DWORD)EQW_GetDisplayWindow();
		else
			Dest.DWord = *(DWORD*)EQADDR_HWND;
		Dest.Type = pIntType;
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
		if (EQADDR_SERVERNAME[0])
		{
			strcpy_s(DataTypeTemp, EQADDR_SERVERNAME);
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
		if (EQADDR_LASTTELL[0])
		{
			strcpy_s(DataTypeTemp, EQADDR_LASTTELL);
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
		Dest.DWord = pConnection->Last;
		Dest.Type = pIntType;
		return true;

	case EverQuestMembers::ChatChannels:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pEQ->ChatService)
		{
			Dest.DWord = pEQ->ChatService->ActiveChannels;
			return true;
		}
		return false;

	case EverQuestMembers::ChatChannel:
		Dest.Type = pStringType;
		if (pEQ->ChatService)
		{
			UniversalChatProxy* pChat = pEQ->ChatService;
			if (IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (pChat->ActiveChannels && index >= 0 && index < pChat->ActiveChannels)
				{
					strcpy_s(DataTypeTemp, pChat->ChannelList[index]);
					Dest.Ptr = &DataTypeTemp[0];
					Dest.Type = pStringType;
					return true;
				}
			}
			else
			{
				char Name[MAX_STRING] = { 0 };
				strcpy_s(Name, Index);

				for (int i = 0; i < pChat->ActiveChannels; i++)
				{
					if (!_stricmp(Name, pChat->ChannelList[i]))
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
		HWND hEQWnd = GetEQWindowHandle();
		if (hEQWnd)
		{
			GetWindowTextA(hEQWnd, DataTypeTemp, MAX_STRING);

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

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int num = GetIntFromString(Index, 0) - 1;
				if (num < 0)
					num = 0;

				if (pEQ)
				{
					if (num <= pEQ->pCharSelectPlayerArray.Count)
					{
						Dest.DWord = num;
						return true;
					}
				}
			}
			else
			{
				char szName[256] = { 0 };
				if (pEQ)
				{
					for (int i = 0; i < pEQ->pCharSelectPlayerArray.Count; i++)
					{
						strcpy_s(szName, pEQ->pCharSelectPlayerArray[i].Name);
						if (!_stricmp(Index, szName))
						{
							Dest.DWord = i;
							return true;
						}
					}
				}
			}
		}
		return false;

	case EverQuestMembers::CurrentUI:
		Dest.Type = pStringType;
		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			char szFilename[MAX_STRING] = { 0 };
			sprintf_s(szFilename, "UI_%s_%s.ini", pCharInfo->Name, EQADDR_SERVERNAME);
			GetPrivateProfileString("Main", "UISkin", "default", DataTypeTemp, MAX_STRING, szFilename);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case EverQuestMembers::IsDefaultUILoaded:
		Dest.Set(true);
		Dest.Type = pBoolType;

		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			char szFilename[MAX_STRING] = { 0 };
			sprintf_s(szFilename, "UI_%s_%s.ini", pCharInfo->Name, EQADDR_SERVERNAME);
			GetPrivateProfileString("Main", "UISkin", "default", DataTypeTemp, MAX_STRING, szFilename);

			if (_stricmp(DataTypeTemp, "default"))
			{
				Dest.Set(false);
			}
		}
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

		Dest.Set(pLocalPlayer->IsValidTeleport(Y, X, Z, 0, 0));
		Dest.Type = pBoolType;
		return true;
	}

	case EverQuestMembers::Path: {
		Dest.Type = pStringType;
		std::error_code ec;
		strcpy_s(DataTypeTemp, std::filesystem::current_path(ec).string().c_str());
		Dest.Ptr = &DataTypeTemp[0];
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
