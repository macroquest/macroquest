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

#include <mq/Plugin.h>

#include <vector>
#include <list>
#include <string>
#include <mq/imgui/ImGuiUtils.h>

// MQ2ChatWnd: Single-window MQ Chat

PreSetup("MQ2ChatWnd");

static constexpr auto LINES_PER_FRAME = 3;
static constexpr auto CMD_HIST_MAX = 50;
static constexpr auto MAX_LINES_OUTBOX = 700;

std::list<CXStr> sPendingChat;
DWORD ulOldVScrollPos = 0;
DWORD bmStripFirstStmlLines = 0;
char szChatINISection[MAX_STRING] = { 0 };
bool bAutoScroll = true;
bool bNoCharSelect = false;
bool bSaveByChar = true;

static uint32_t s_pendingRemoveStyle = 0;
static uint32_t s_pendingAddStyle = 0;

class CMQChatWnd : public CCustomWnd
{
public:
	CMQChatWnd(const char* Template) : CCustomWnd(Template)
	{
		DebugSpew("CMQChatWnd()");

		SetWindowStyle(CWS_CLIENTMOVABLE | CWS_USEMYALPHA | CWS_RESIZEALL | CWS_BORDER | CWS_MINIMIZE | CWS_TITLE);
		RemoveStyle(CWS_TRANSPARENT | CWS_CLOSE);

		if (s_pendingAddStyle)
		{
			AddStyle(s_pendingAddStyle);
			s_pendingAddStyle = 0;
		}

		if (s_pendingRemoveStyle)
		{
			RemoveStyle(s_pendingRemoveStyle);
			s_pendingRemoveStyle = 0;
		}

		SetBGColor(0xFF000000); // black background

		InputBox = (CEditWnd*)GetChildItem("CW_ChatInput");
		InputBox->AddStyle(CWS_AUTOVSCROLL | CWS_RELATIVERECT | CWS_BORDER); // 0x800C0;
		SetFaded(false);
		SetEscapable(false);
		SetAlpha(0xFF);
		SetBGType(1);

		ContextMenuID = 3;
		InputBox->SetCRNormal(0xFFFFFFFF); // we want a white cursor
		InputBox->SetMaxChars(512);
		OutputBox = (CStmlWnd*)GetChildItem("CW_ChatOutput");
		OutputBox->SetParentWindow(this);
		InputBox->SetParentWindow(this);
		OutputBox->MaxLines = MAX_LINES_OUTBOX;
		OutputBox->SetClickThrough(true);
		OutputBox->AddStyle(CWS_CLIENTMOVABLE);
		iCurrentCmd = -1;
		SetZLayer(1); // Make this the topmost window (we will leave it as such for charselect, and allow it to move to background ingame)
	}

	virtual int WndNotification(CXWnd* pWnd, unsigned int Message, void* data) override
	{
		if (pWnd == nullptr)
		{
			if (Message == XWM_CLOSE)
			{
				SetVisible(1);
				return 1;
			}
		}
		else if (pWnd == InputBox)
		{
			if (Message == XWM_HITENTER)
			{
				CXStr text = InputBox->InputText;
				if (!text.empty())
				{
					if (!sCmdHistory.size() || sCmdHistory.front().compare(text.c_str()))
					{
						if (sCmdHistory.size() > CMD_HIST_MAX)
						{
							sCmdHistory.pop_back();
						}

						sCmdHistory.insert(sCmdHistory.begin(), text.c_str());
					}

					iCurrentCmd = -1;
					//bool bScrollDown=bAutoScroll?true:(MQChatWnd->OutputBox->VScrollPos==MQChatWnd->OutputBox->VScrollMax?true:false);
					//char szProcessed[MAX_STRING];
					//MQToSTML(szBuffer,szProcessed,MAX_STRING);
					//strcat_s(szProcessed,"<br>");
					//CXStr NewText(szProcessed);
					//OutputBox->AppendSTML(NewText);
					//if (bScrollDown) ((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->VScrollMax);

					InputBox->InputText.clear();
					if (text[0] == '/')
					{
						DoCommand((SPAWNINFO*)pLocalPlayer, text.c_str());
					}
					else
					{
						Echo((SPAWNINFO*)pLocalPlayer, (char*)text.c_str());
					}
				}

				InputBox->ClrFocus();
			}
			else if (Message == XWM_HISTORY)
			{
				if (data)
				{
					int* pInt = (int*)data;
					int iKeyPress = pInt[1];
					if (iKeyPress == 0xc8) // KeyUp
					{
						if (sCmdHistory.size() > 0)
						{
							iCurrentCmd++;
							if (iCurrentCmd < (static_cast<int>(sCmdHistory.size())) && iCurrentCmd >= 0)
							{
								const std::string& s = sCmdHistory.at(iCurrentCmd);
								InputBox->SetWindowText(s.c_str());
							}
							else
							{
								iCurrentCmd = (static_cast<int>(sCmdHistory.size())) - 1;
							}
						}
					}
					else if (iKeyPress == 0xd0) // KeyDown
					{
						if (sCmdHistory.size() > 0)
						{
							iCurrentCmd--;
							if (iCurrentCmd >= 0 && sCmdHistory.size() > 0)
							{
								std::string s = sCmdHistory.at(iCurrentCmd);
								InputBox->SetWindowText(s.c_str());
							}
							else if (iCurrentCmd < 0)
							{
								iCurrentCmd = -1;
								InputBox->InputText.clear();
							}
						}
					}
				}
			}
		}
		else if (pWnd == OutputBox)
		{
			if (pChatManager && (Message == XWM_LINK || Message == XWM_SPELL_LINK
				|| Message == XWM_ACHIEVEMENTLINK || Message == XWM_DIALOGRESPONSELINK))
			{
				for (auto wnd : pChatManager->ChannelMap)
				{
					if (wnd)
					{
						wnd->WndNotification(wnd->OutputWnd, Message, data);
						break;
					}
				}
				return 0;
			}
		}

		return CSidlScreenWnd::WndNotification(pWnd, Message, data);
	};

	void SetChatFont(int size) // brainiac 12-12-2007
	{
		// get fonts structure -- this offset can be found by looking at
		// SetChatfont which is called from the /chatfontsize function

		// check font array bounds and pointers
		if (size < 0 || size >= pWndMgr->FontsArray.GetCount())
		{
			return;
		}

		CTextureFont* font = pWndMgr->FontsArray[size];
		if (!font)
		{
			return;
		}
		//DebugSpew("Setting Size: %i", size);

		// Save the text, change the font, then restore the text
		CXStr str = OutputBox->GetSTMLText();

		OutputBox->SetFont(font);
		OutputBox->SetSTMLText(str);
		OutputBox->ForceParseNow();

		// scroll to bottom of chat window
		OutputBox->SetVScrollPos(OutputBox->GetVScrollMax());

		FontSize = size;
	};

	void Clear()
	{
		if (OutputBox)
		{
			OutputBox->SetSTMLText("");
			OutputBox->ForceParseNow();
			OutputBox->SetVScrollPos(OutputBox->GetVScrollMax());
		}
	}

	int FontSize = 4;
	CEditWnd* InputBox;
	CStmlWnd* OutputBox;

private:
	std::vector<std::string> sCmdHistory;
	int iCurrentCmd;
};

CMQChatWnd* MQChatWnd = nullptr;


void LoadChatSettings()
{
	bAutoScroll = GetPrivateProfileBool("Settings", "AutoScroll", bAutoScroll, INIFileName);
	bNoCharSelect = GetPrivateProfileBool("Settings", "NoCharSelect", bNoCharSelect, INIFileName);
	bSaveByChar = GetPrivateProfileBool("Settings", "SaveByChar", bSaveByChar, INIFileName);
}

void LoadChatFromINI(CSidlScreenWnd* pWindow)
{
	char szTemp[MAX_STRING] = { 0 };

	LoadChatSettings();

	// left top right bottom
	pWindow->SetLocation({ (LONG)GetPrivateProfileInt(szChatINISection,"ChatLeft",      10,INIFileName),
		(LONG)GetPrivateProfileInt(szChatINISection,"ChatTop",       10,INIFileName),
		(LONG)GetPrivateProfileInt(szChatINISection,"ChatRight",    410,INIFileName),
		(LONG)GetPrivateProfileInt(szChatINISection,"ChatBottom",   210,INIFileName) });

	pWindow->SetLocked((GetPrivateProfileInt(szChatINISection, "Locked", 0, INIFileName) ? true : false));
	pWindow->SetFades((GetPrivateProfileInt(szChatINISection, "Fades", 0, INIFileName) ? true : false));
	pWindow->SetFadeDelay(GetPrivateProfileInt(szChatINISection, "Delay", 2000, INIFileName));
	pWindow->SetFadeDuration(GetPrivateProfileInt(szChatINISection, "Duration", 500, INIFileName));
	pWindow->SetAlpha((BYTE)GetPrivateProfileInt(szChatINISection, "Alpha", 255, INIFileName));
	pWindow->SetFadeToAlpha((BYTE)GetPrivateProfileInt(szChatINISection, "FadeToAlpha", 255, INIFileName));
	pWindow->SetBGType(GetPrivateProfileInt(szChatINISection, "BGType", 1, INIFileName));
	ARGBCOLOR col = { 0 };
	col.ARGB = pWindow->GetBGColor();
	col.A = GetPrivateProfileInt(szChatINISection, "BGTint.alpha", 255, INIFileName);
	col.R = GetPrivateProfileInt(szChatINISection, "BGTint.red", 0, INIFileName);
	col.G = GetPrivateProfileInt(szChatINISection, "BGTint.green", 0, INIFileName);
	col.B = GetPrivateProfileInt(szChatINISection, "BGTint.blue", 0, INIFileName);
	pWindow->SetBGColor(col.ARGB);
	MQChatWnd->SetChatFont(GetPrivateProfileInt(szChatINISection, "FontSize", 4, INIFileName));
	GetPrivateProfileString(szChatINISection, "WindowTitle", "MQ", szTemp, MAX_STRING, INIFileName);
	pWindow->SetWindowText(szTemp);
	pWindow->bKeepOnScreen = GetPrivateProfileBool(szChatINISection, "KeepOnScreen", true, INIFileName);
}

void SaveChatToINI(CSidlScreenWnd* pWindow)
{
	char szTemp[MAX_STRING] = { 0 };
	WritePrivateProfileString("Settings", "AutoScroll", bAutoScroll ? "on" : "off", INIFileName);
	WritePrivateProfileString("Settings", "NoCharSelect", bNoCharSelect ? "on" : "off", INIFileName);
	WritePrivateProfileString("Settings", "SaveByChar", bSaveByChar ? "on" : "off", INIFileName);

	if (pWindow->IsMinimized())
	{
		WritePrivateProfileString(szChatINISection, "ChatTop", std::to_string(pWindow->GetOldLocation().top), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatBottom", std::to_string(pWindow->GetOldLocation().bottom), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatLeft", std::to_string(pWindow->GetOldLocation().left), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatRight", std::to_string(pWindow->GetOldLocation().right), INIFileName);
	}
	else
	{
		WritePrivateProfileString(szChatINISection, "ChatTop", std::to_string(pWindow->GetLocation().top), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatBottom", std::to_string(pWindow->GetLocation().bottom), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatLeft", std::to_string(pWindow->GetLocation().left), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatRight", std::to_string(pWindow->GetLocation().right), INIFileName);
	}
	WritePrivateProfileString(szChatINISection, "Locked", std::to_string(pWindow->IsLocked()), INIFileName);
	WritePrivateProfileString(szChatINISection, "Fades", std::to_string(pWindow->GetFades()), INIFileName);
	WritePrivateProfileString(szChatINISection, "Delay", std::to_string(pWindow->GetFadeDelay()), INIFileName);
	WritePrivateProfileString(szChatINISection, "Duration", std::to_string(pWindow->GetFadeDuration()), INIFileName);
	WritePrivateProfileString(szChatINISection, "Alpha", std::to_string(pWindow->GetAlpha()), INIFileName);
	WritePrivateProfileString(szChatINISection, "FadeToAlpha", std::to_string(pWindow->GetFadeToAlpha()), INIFileName);
	ARGBCOLOR col = { 0 };
	col.ARGB = pWindow->GetBGColor();
	WritePrivateProfileString(szChatINISection, "BGType", std::to_string(pWindow->GetBGType()), INIFileName);
	WritePrivateProfileString(szChatINISection, "BGTint.alpha", std::to_string(col.A), INIFileName);
	WritePrivateProfileString(szChatINISection, "BGTint.red", std::to_string(col.R), INIFileName);
	WritePrivateProfileString(szChatINISection, "BGTint.green", std::to_string(col.G), INIFileName);
	WritePrivateProfileString(szChatINISection, "BGTint.blue", std::to_string(col.B), INIFileName);
	WritePrivateProfileString(szChatINISection, "FontSize", std::to_string(MQChatWnd->FontSize), INIFileName);
	WritePrivateProfileString(szChatINISection, "WindowTitle", pWindow->GetWindowText().c_str(), INIFileName);
	WritePrivateProfileBool(szChatINISection, "KeepOnScreen", pWindow->bKeepOnScreen, INIFileName);
}

void CreateChatWindow()
{
	if (MQChatWnd)
	{
		return;
	}

	MQChatWnd = new CMQChatWnd("ChatWindow");

	LoadChatFromINI(MQChatWnd);
	SaveChatToINI(MQChatWnd); // this creates the file if its not there
}

void DestroyChatWnd()
{
	if (MQChatWnd)
	{
		sPendingChat.clear();

		SaveChatToINI(MQChatWnd);

		delete MQChatWnd;
		MQChatWnd = nullptr;

		ulOldVScrollPos = 0;
	}
}

void Style(SPAWNINFO* pChar, char* szLine)
{
	if (!szLine || !szLine[0])
	{
		char out[256] = { 0 };
		sprintf_s(out, "Style 0x%X", MQChatWnd->GetWindowStyle());
		WriteChatColor(out);
		return;
	}

	if (szLine[0] == '!')
	{
		int TurnOff = 0;
		if (sscanf_s(&szLine[1], "%x", &TurnOff))
		{
			// well we set it anyway i guess...
		}

		if (MQChatWnd)
		{
			MQChatWnd->RemoveStyle(TurnOff);
		}
		else
		{
			s_pendingRemoveStyle |= TurnOff;
			s_pendingAddStyle &= ~TurnOff;
		}
	}
	else
	{
		int TurnOn = 0;
		if (sscanf_s(&szLine[0], "%x", &TurnOn))
		{
			// hmm can error handle i guess
		}

		if (MQChatWnd)
		{
			MQChatWnd->AddStyle(TurnOn);
		}
		else
		{
			s_pendingAddStyle |= TurnOn;
			s_pendingRemoveStyle &= ~TurnOn;
		}
	}

	WriteChatf("Style 0x%X", MQChatWnd->GetWindowStyle());
}

void MQChatFont(SPAWNINFO* pChar, char* Line)
{
	if (MQChatWnd && Line[0])
	{
		const int size = GetIntFromString(Line, -1);
		if (size < 0 || size > 10)
		{
			WriteChatf("Usage: /mqfont 0-10");
			return;
		}
		MQChatWnd->SetChatFont(size);

		SaveChatToINI(MQChatWnd);
	}
}

void MQChatMin(SPAWNINFO* pChar, char* Line)
{
	if (MQChatWnd)
	{
		MQChatWnd->Minimize(true);
	}
}

void MQChat(SPAWNINFO* pChar, char* Line)
{
	char Arg[MAX_STRING] = { 0 };
	GetArg(Arg, Line, 1);

	if (!_stricmp(Arg, "reset"))
	{
		// TODO:  This should set the ini to the defaults instead of just the positioning.
		if (MQChatWnd)
		{
			MQChatWnd->SetLocked(false);

			CXRect rc = { 300, 10, 600, 210 };
			MQChatWnd->Move(rc, false);
			MQChatWnd->SetZLayer(1);
			DestroyChatWnd();
			CreateChatWindow();
		}
		else
		{
			WriteChatf("MQ2ChatWnd must be active in order to reset.");
		}
	}
	else if (!_stricmp(Arg, "autoscroll"))
	{
		GetArg(Arg, Line, 2);
		if (Arg[0] == '\0')
		{
			WriteChatf("Autoscroll is currently: %s", (bAutoScroll ? "\agOn" : "\arOff"));
		}
		else if (!_stricmp(Arg, "on"))
		{
			// turn it on.
			bAutoScroll = true;
			WriteChatf("Autoscroll is now: \agOn.");
			WritePrivateProfileString("Settings", "AutoScroll", "on", INIFileName);
		}
		else if (!_stricmp(Arg, "off"))
		{
			// turn it off.
			bAutoScroll = false;
			WriteChatf("Autoscroll is now: \arOff.");
			WritePrivateProfileString("Settings", "AutoScroll", "off", INIFileName);
		}
		else
		{
			WriteChatf("Usage: /mqchat autoscroll [on | off]\n IE: /mqchat autoscroll on");
		}
	}
	else if (!_stricmp(Arg, "NoCharSelect"))
	{
		GetArg(Arg, Line, 2);

		if (!strlen(Arg))
		{
			WriteChatf("NoCharSelect is currently: %s", (bNoCharSelect ? "\agOn" : "\arOff"));
		}
		else if (!_stricmp(Arg, "on"))
		{
			// turn it on.
			bNoCharSelect = true;
			WriteChatf("NoCharSelect is now: \agOn.");
			WritePrivateProfileString("Settings", "NoCharSelect", "on", INIFileName);
		}
		else if (!_stricmp(Arg, "off"))
		{
			// turn it off.
			bNoCharSelect = false;
			WriteChatf("NoCharSelect is now: \arOff.");
			WritePrivateProfileString("Settings", "NoCharSelect", "off", INIFileName);
		}
		else
		{
			WriteChatf("Usage: /mqchat NoCharSelect [on | off]\n IE: /mqchat NoCharSelect on");
		}
	}
	else if (!_stricmp(Arg, "SaveByChar"))
	{
		GetArg(Arg, Line, 2);

		if (Arg[0] == '\0')
		{
			WriteChatf("SaveByChar is currently: %s", (bSaveByChar ? "\agOn" : "\arOff"));
		}
		else if (!_stricmp(Arg, "on"))
		{
			// turn it on.
			bSaveByChar = true;
			WriteChatf("SaveByChar is now: \agOn.");
			WritePrivateProfileString("Settings", "SaveByChar", "on", INIFileName);
		}
		else if (!_stricmp(Arg, "off"))
		{
			// turn it off.
			bSaveByChar = false;
			WriteChatf("SaveByChar is now: \arOff.");
			WritePrivateProfileString("Settings", "SaveByChar", "off", INIFileName);
		}
		else
		{
			WriteChatf("Usage: /mqchat SaveByChar [on | off]\n IE: /mqchat SaveByChar on");
		}
	}
	else if (!_stricmp(Arg, "ui") || !_stricmp(Arg, "gui"))
	{
		EzCommand("/mqsettings plugins/ChatWnd");
	}
	else
	{
		WriteChatf("%s was not a valid option. Valid options are: reset, autoscroll, nocharselect, and savebychar", Arg);
	}
}

void SetChatTitle(SPAWNINFO* pChar, char* Line)
{
	if (MQChatWnd)
	{
		MQChatWnd->SetWindowText(Line);
	}
}

void MQChatClear(SPAWNINFO* pChar, char* Line)
{
	if (MQChatWnd)
	{
		MQChatWnd->Clear();
		ulOldVScrollPos = 0;
	}
}

void DoMQ2ChatBind(const char* Name, bool Down)
{
	if (!Down)
	{
		if (MQChatWnd)
		{
			CXPoint pt = MQChatWnd->InputBox->GetScreenRect().CenterPoint();

			MQChatWnd->InputBox->SetWindowText("/");
			MQChatWnd->InputBox->HandleLButtonDown(pt, 0);
		}
	}
}

PLUGIN_API void OnReloadUI()
{
	// redraw window when you load/reload UI
	DebugTry(CreateChatWindow());
}

PLUGIN_API void OnCleanUI()
{
	// destroy chatwnd before server select & while reloading UI
	DestroyChatWnd();
}

PLUGIN_API void SetGameState(int GameState)
{
	DebugSpew("MQ2ChatWnd::SetGameState()");
	if (GameState == GAMESTATE_CHARSELECT)
	{
		if (bNoCharSelect)
		{
			// destroy chatwnd at charselect if NoCharSelect=on
			DestroyChatWnd();
		}
		else
		{
			strcpy_s(szChatINISection, "CharSelect");
			AddMQ2KeyBind("MQ2CSCHAT", DoMQ2ChatBind);
			KeyCombo Combo;
			ParseKeyCombo("/", Combo);
			SetMQ2KeyBind("MQ2CSCHAT", FALSE, Combo);
		}
	}
	else
	{
		if (bSaveByChar && pLocalPlayer != nullptr)
		{
			std::string strChatINISection = fmt::format("{}.{}", GetServerShortName(), pLocalPlayer->Name);

			// Only need to do anything at all if things have changed
			if (!string_equals(szChatINISection, strChatINISection))
			{
				// Destroy the window which will save the settings under the old character
				if (MQChatWnd != nullptr)
				{
					DestroyChatWnd();
				}
				// Set up for the new create below.
				strcpy_s(szChatINISection, &strChatINISection[0]);
			}
		}
		else
		{
			strcpy_s(szChatINISection, "Default");
		}
		if (GameState != GAMESTATE_CHARCREATE) RemoveMQ2KeyBind("MQ2CSCHAT");
		if (GameState == GAMESTATE_INGAME && !MQChatWnd)
		{
			// we entered the game, set up shop
			DebugTry(CreateChatWindow());
		}
	}
}

// This is called every time WriteChatColor is called by MQ2Main or any plugin,
// IGNORING FILTERS, IF YOU NEED THEM MAKE SURE TO IMPLEMENT THEM. IF YOU DONT
// CALL CEverQuest::dsp_chat MAKE SURE TO IMPLEMENT EVENTS HERE
PLUGIN_API DWORD OnWriteChatColor(char* Line, DWORD Color, DWORD Filter)
{
	if (!MQChatWnd)
	{
		if (gGameState == GAMESTATE_INGAME)
		{
			SetGameState(gGameState);
		}

		if (!MQChatWnd)
		{
			return 0;
		}
	}

	MQChatWnd->SetVisible(true);

	MQFilter* pFilter = gpFilters;
	while (pFilter)
	{
		if (!pFilter->pEnabled || (*pFilter->pEnabled))
		{
			if (!_strnicmp(Line, pFilter->FilterText, pFilter->Length))
			{
				return 0;
			}
		}
		pFilter = pFilter->pNext;
	}

	Color = pChatManager->GetRGBAFromIndex(Color);
	char* szProcessed = new char[MAX_STRING];

	int pos = MQToSTML(Line, szProcessed, MAX_STRING - 4, Color);

	CXStr text = szProcessed;
	text.append("<br>");

	ConvertItemTags(text);
	sPendingChat.push_back(text);

	delete[] szProcessed;
	return 0;
}

PLUGIN_API void OnPulse()
{
	if (GetGameState() == GAMESTATE_CHARSELECT && !MQChatWnd && !bNoCharSelect)
	{
		CreateChatWindow();
	}

	if (MQChatWnd)
	{
		switch (gGameState)
		{
		case GAMESTATE_CHARSELECT:
			if (MQChatWnd->GetZLayer() != 1)
				MQChatWnd->SetZLayer(1);
			break;

		case GAMESTATE_INGAME:
			if (MQChatWnd->GetZLayer() != 0)
				MQChatWnd->SetZLayer(0);
			break;

		default: break;
		}

		// TODO: move all this to OnProcessFrame()
		if (!sPendingChat.empty())
		{
			// set 'old' to current
			ulOldVScrollPos = MQChatWnd->OutputBox->GetVScrollPos();

			// scroll down if autoscroll enabled, or current position is the bottom of chatwnd
			bool bScrollDown = bAutoScroll || (MQChatWnd->OutputBox->GetVScrollPos() == MQChatWnd->OutputBox->GetVScrollMax());

			size_t ThisPulse = sPendingChat.size();
			if (ThisPulse > LINES_PER_FRAME)
			{
				ThisPulse = LINES_PER_FRAME;
			}

			for (size_t N = 0; N < ThisPulse; N++)
			{
				if (!sPendingChat.empty())
				{
					MQChatWnd->OutputBox->AppendSTML(*sPendingChat.begin());
					sPendingChat.pop_front();
				}
			}

			if (bScrollDown)
			{
				// set current vscroll position to bottom
				MQChatWnd->OutputBox->SetVScrollPos(MQChatWnd->OutputBox->GetVScrollMax());
			}
			else
			{
				// autoscroll is disabled and current vscroll position was not at the bottom, retain position
				// note: if the window is full (VScrollMax value between 9793 and 9835), this will not adjust with
				// the flushing of buffer that keeps window a certain max size
				MQChatWnd->OutputBox->SetVScrollPos(ulOldVScrollPos);
			}
		}

		// this lets the window draw when we are dead and "hovering"
		if (InHoverState())
		{
			MQChatWnd->DoAllDrawing();
		}
	}
}

class MQ2ChatWndType : public MQ2Type
{
public:
	enum ChatWndMembers {
		Title = 1,
	};

	MQ2ChatWndType() : MQ2Type("chatwnd")
	{
		TypeMember(Title);
	}

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		MQTypeMember* pMember = MQ2ChatWndType::FindMember(Member);
		if (!pMember)
			return false;

		switch ((ChatWndMembers)pMember->ID)
		{
		case Title:
		{
			if (MQChatWnd)
			{
				strcpy_s(DataTypeTemp, MQChatWnd->GetWindowText().c_str());

				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = datatypes::pStringType;
				return true;
			}
			break;
		}
		default:
			break;
		}
		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		Destination[0] = '\0';

		if (MQChatWnd)
		{
			strcpy_s(Destination, MAX_STRING, MQChatWnd->GetWindowText().c_str());
		}

		return true;
	}
};
MQ2ChatWndType* pChatWndType = nullptr;

bool dataChatWnd(const char* szName, MQTypeVar& Dest)
{
	Dest.DWord = 1;
	Dest.Type = pChatWndType;
	return true;
}

struct PluginCheckbox {
	const char* name;
	const char* visiblename;
	bool* value;
	const char* helptext;
};

static const PluginCheckbox checkboxes[] = {
	{ "AutoScroll", "Scroll text", &bAutoScroll, "Scroll with new text or not.\n\nINI Setting: AutoScroll" },
	{ "NoCharSelect", "Disable at char select", &bNoCharSelect, "Disable the ChatWnd at character select or not.\n\nINI Setting: NoCharSelect" },
	{ "SaveByChar", "Individual character settings", &bSaveByChar, "Use individual character settings.\n\nINI Setting: SaveByChar" },
};

void ChatWndImGuiSettingsPanel()
{
	for (const PluginCheckbox& cb : checkboxes)
	{
		// the visible name is not necessarily the name of the INI setting
		if (ImGui::Checkbox(cb.visiblename, cb.value))
		{
			WritePrivateProfileBool("Settings", cb.name, *cb.value, INIFileName);
		}
		ImGui::SameLine();
		mq::imgui::HelpMarker(cb.helptext);
	}

	ImGui::SetNextItemWidth(-125);
	if (ImGui::InputInt("Font 0 - 10", &MQChatWnd->FontSize)) {
		int iFontSize = std::clamp(MQChatWnd->FontSize, 0, 10);
		MQChatWnd->SetChatFont(iFontSize);
		WritePrivateProfileInt("Settings", "FontSize", iFontSize, INIFileName);
	}
	ImGui::SameLine();
	mq::imgui::HelpMarker("Font 0 - 10. These are 10 font faces of various styles and sizes from EQ.\n\nINISetting: FontSize");
}

PLUGIN_API void InitializePlugin()
{
	// Add commands, macro parameters, hooks, etc.
	AddMQ2Data("ChatWnd", dataChatWnd);
	pChatWndType = new MQ2ChatWndType;

	AddCommand("/style", Style, 0, 1, 0);
	AddCommand("/mqfont", MQChatFont);
	AddCommand("/mqchat", MQChat);
	AddCommand("/mqmin", MQChatMin);
	AddCommand("/mqclear", MQChatClear);
	AddCommand("/setchattitle", SetChatTitle);
	AddSettingsPanel("plugins/ChatWnd", ChatWndImGuiSettingsPanel);

	AddMQ2KeyBind("MQ2CHAT", DoMQ2ChatBind);
	LoadChatSettings();
}

PLUGIN_API void ShutdownPlugin()
{
	sPendingChat.clear();

	// Remove commands, macro parameters, hooks, etc.
	RemoveCommand("/setchattitle");
	RemoveCommand("/style");
	RemoveCommand("/mqchat");
	RemoveCommand("/mqfont");
	RemoveCommand("/mqmin");
	RemoveCommand("/mqclear");
	RemoveMQ2KeyBind("MQ2CHAT");
	RemoveMQ2KeyBind("MQ2CSCHAT");
	RemoveMQ2Data("ChatWnd");
	delete pChatWndType;
	DestroyChatWnd();
	RemoveSettingsPanel("plugins/ChatWnd");
}
