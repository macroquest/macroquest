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

#include "../MQ2Plugin.h" 

#include <vector>
#include <list>
#include <string>

// MQ2ChatWnd: Single-window MQ Chat 

PreSetup("MQ2ChatWnd");

#define MAX_CHAT_SIZE        700 
#define LINES_PER_FRAME      3 

std::list<CXStr> sPendingChat;
const int CMD_HIST_MAX = 50;
DWORD ulOldVScrollPos = 0;
DWORD bmStripFirstStmlLines = 0;
char szChatINISection[MAX_STRING] = { 0 };
bool bAutoScroll = true;
bool bNoCharSelect = false;
bool bSaveByChar = true;

class CMQChatWnd;
CMQChatWnd* MQChatWnd = nullptr;

class CMQChatWnd : public CCustomWnd
{
public:
	CMQChatWnd(char* Template) : CCustomWnd(Template)
	{
		DebugSpew("CMQChatWnd()");

		SetWindowStyle(CWS_CLIENTMOVABLE | CWS_USEMYALPHA | CWS_RESIZEALL | CWS_BORDER | CWS_MINIMIZE | CWS_TITLE);
		RemoveStyle(CWS_TRANSPARENT | CWS_CLOSE);
		SetBGColor(0xFF000000); // black background

		InputBox = (CEditWnd*)GetChildItem("CW_ChatInput");
		InputBox->AddStyle(CWS_AUTOVSCROLL | CWS_RELATIVERECT | CWS_BORDER); // 0x800C0;
		SetFaded(false);
		SetEscapable(false);
		SetClickable(true);
		SetAlpha(0xFF);
		SetBGType(1);

		ContextMenuID = 3;
		InputBox->SetCRNormal(0xFFFFFFFF); // we want a white cursor 
		InputBox->SetMaxChars(512);
		OutputBox = (CStmlWnd*)GetChildItem("CW_ChatOutput");
		OutputBox->SetParentWindow(this);
		InputBox->SetParentWindow(this);
		OutputBox->MaxLines = 0x190;
		OutputBox->SetClickable(true);
		OutputBox->AddStyle(CWS_CLIENTMOVABLE);
		iCurrentCmd = -1;
		SetZLayer(1); // Make this the topmost window (we will leave it as such for charselect, and allow it to move to background ingame)
	}

	~CMQChatWnd()
	{
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
						DoCommand(((CHARINFO*)pCharData)->pSpawn, text.c_str());
					}
					else
					{
						Echo(((CHARINFO*)pCharData)->pSpawn, (char*)text.c_str());
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
							if (iCurrentCmd < ((int)sCmdHistory.size()) && iCurrentCmd >= 0)
							{
								const std::string& s = sCmdHistory.at(iCurrentCmd);
								InputBox->SetWindowText(s.c_str());
							}
							else
							{
								iCurrentCmd = ((int)sCmdHistory.size()) - 1;
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
			else
			{
				DebugSpew("InputBox message %Xh, value: %Xh", Message, data);
			}
		}
		else if (Message == XWM_LINK)
		{
			CChatWindow* p = (CChatWindow*)this;
			if (OutputBox != pWnd)
			{
				//DebugSpew("MQ2ChatWnd: 0x%X, Msg: 0x%X, value: %Xh",pWnd,Message,data); 
				//DebugSpew("MQ2ChatWnd: pWnd 0x%x != OutputBox 0x%x\n",pWnd,OutputBox); 

				// FIXME: wtf is this doing?
				CStmlWnd* tmp = OutputBox;
				OutputBox = (CStmlWnd*)pWnd;
				int ret = p->WndNotification(pWnd, Message, data);
				OutputBox = tmp;
				return ret;
			}
			return p->WndNotification(pWnd, Message, data);
		}
		else
		{
			//DebugSpew("MQ2ChatWnd: 0x%X, Msg: 0x%X, value: %Xh",pWnd,Message,data); 
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
		if (!font || !MQChatWnd)
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

	int OutBoxLines = 0;
	int FontSize = 4;
	CEditWnd* InputBox;
	CStmlWnd* OutputBox;

private:
	std::vector<std::string> sCmdHistory;
	int iCurrentCmd;
};

void LoadChatSettings()
{
	char szTemp[MAX_STRING] = { 0 };

	GetPrivateProfileString("Settings", "AutoScroll", bAutoScroll ? "on" : "off", szTemp, MAX_STRING, INIFileName);
	bAutoScroll = (!_strnicmp(szTemp, "on", 3));
	GetPrivateProfileString("Settings", "NoCharSelect", bNoCharSelect ? "on" : "off", szTemp, MAX_STRING, INIFileName);
	bNoCharSelect = (!_strnicmp(szTemp, "on", 3));
	GetPrivateProfileString("Settings", "SaveByChar", bSaveByChar ? "on" : "off", szTemp, MAX_STRING, INIFileName);
	bSaveByChar = (!_strnicmp(szTemp, "on", 3));
}

void LoadChatFromINI(CSidlScreenWnd* pWindow)
{
	char szTemp[MAX_STRING] = { 0 };

	LoadChatSettings();

	sprintf_s(szChatINISection, "%s.%s", EQADDR_SERVERNAME, ((CHARINFO*)pCharData)->Name);
	if (!bSaveByChar) sprintf_s(szChatINISection, "Default");

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
}

template <unsigned int _Size>
char* SafeItoa(int _Value, char(&_Buffer)[_Size], int _Radix)
{
	errno_t err = _itoa_s(_Value, _Buffer, _Radix);
	if (!err) {
		return _Buffer;
	}
	return "";
}

void SaveChatToINI(CSidlScreenWnd* pWindow)
{
	char szTemp[MAX_STRING] = { 0 };
	WritePrivateProfileString("Settings", "AutoScroll", bAutoScroll ? "on" : "off", INIFileName);
	WritePrivateProfileString("Settings", "NoCharSelect", bNoCharSelect ? "on" : "off", INIFileName);
	WritePrivateProfileString("Settings", "SaveByChar", bSaveByChar ? "on" : "off", INIFileName);

	if (pWindow->IsMinimized())
	{
		WritePrivateProfileString(szChatINISection, "ChatTop", SafeItoa(pWindow->GetOldLocation().top, szTemp, 10), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatBottom", SafeItoa(pWindow->GetOldLocation().bottom, szTemp, 10), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatLeft", SafeItoa(pWindow->GetOldLocation().left, szTemp, 10), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatRight", SafeItoa(pWindow->GetOldLocation().right, szTemp, 10), INIFileName);
	}
	else
	{
		WritePrivateProfileString(szChatINISection, "ChatTop", SafeItoa(pWindow->GetLocation().top, szTemp, 10), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatBottom", SafeItoa(pWindow->GetLocation().bottom, szTemp, 10), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatLeft", SafeItoa(pWindow->GetLocation().left, szTemp, 10), INIFileName);
		WritePrivateProfileString(szChatINISection, "ChatRight", SafeItoa(pWindow->GetLocation().right, szTemp, 10), INIFileName);
	}
	WritePrivateProfileString(szChatINISection, "Locked", SafeItoa(pWindow->IsLocked(), szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "Fades", SafeItoa(pWindow->GetFades(), szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "Delay", SafeItoa(pWindow->GetFadeDelay(), szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "Duration", SafeItoa(pWindow->GetFadeDuration(), szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "Alpha", SafeItoa(pWindow->GetAlpha(), szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "FadeToAlpha", SafeItoa(pWindow->GetFadeToAlpha(), szTemp, 10), INIFileName);
	ARGBCOLOR col = { 0 };
	col.ARGB = pWindow->GetBGColor();
	WritePrivateProfileString(szChatINISection, "BGType", SafeItoa(pWindow->GetBGType(), szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "BGTint.alpha", SafeItoa(col.A, szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "BGTint.red", SafeItoa(col.R, szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "BGTint.green", SafeItoa(col.G, szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "BGTint.blue", SafeItoa(col.B, szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "FontSize", SafeItoa(MQChatWnd->FontSize, szTemp, 10), INIFileName);
	WritePrivateProfileString(szChatINISection, "WindowTitle", pWindow->GetWindowText().c_str(), INIFileName);
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

		MQChatWnd->RemoveStyle(TurnOff);
	}
	else
	{
		int TurnOn = 0;
		if (sscanf_s(&szLine[0], "%x", &TurnOn))
		{
			// hmm can error handle i guess
		}

		MQChatWnd->AddStyle(TurnOn);
	}

	WriteChatf("Style 0x%X", MQChatWnd->GetWindowStyle());
}

void MQChatFont(SPAWNINFO* pChar, char* Line)
{
	if (MQChatWnd && Line[0])
	{
		int size = atoi(Line);
		if (size < 0 || size>10)
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
	if (MQChatWnd)
	{
		if (!_stricmp(Line, "reset"))
		{
			MQChatWnd->SetLocked(false);

			CXRect rc = { 300, 10, 600, 210 };
			MQChatWnd->Move(rc, false);
		}
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

PLUGIN_API void SetGameState(DWORD GameState)
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
			AddMQ2KeyBind("MQ2CSCHAT", DoMQ2ChatBind);
			KeyCombo Combo;
			ParseKeyCombo("/", Combo);
			SetMQ2KeyBind("MQ2CSCHAT", FALSE, Combo);
		}
	}
	else
	{
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

	// TODO: Use shared code in MQ2Main
	if (gAnonymize)
	{
		int len = strlen(Line);
		char Name[MAX_STRING] = { "*" };
		int namelen = 0;

		if (pLocalPlayer)
		{
			strcpy_s(Name, ((SPAWNINFO*)pLocalPlayer)->Name);
			namelen = strlen(Name);

			while (strstr(Line, Name))
			{
				if (char* p = strstr(Line, Name))
				{
					for (int i = 1; i < namelen - 1; i++)
					{
						p[i] = '*';
					}
				}
			}
		}

		// check for group members??
		if (CHARINFO* pChar = GetCharInfo())
		{
			int n = 0;
			if (pChar->pGroupInfo)
			{
				for (int i = 1; i < 6; i++)
				{
					if (GetCharInfo()->pGroupInfo->pMember[i])
						n++;
				}

				if (n)
				{
					n++;
					for (int i = 1; i <= n; i++)
					{
						if (pChar->pGroupInfo->pMember[i] && pChar->pGroupInfo->pMember[i]->pSpawn)
						{
							strcpy_s(Name, pChar->pGroupInfo->pMember[i]->pSpawn->Name);
							namelen = strlen(Name);
							while (strstr(Line, Name))
							{
								if (char* p = strstr(Line, Name))
								{
									for (int i = 1; i < namelen - 1; i++) {
										p[i] = '*';
									}
								}
							}
						}
					}
				}
			}
		}
	}

	Color = pChatManager->GetRGBAFromIndex(Color);
	char szProcessed[MAX_STRING] = { 0 };

	int pos = MQToSTML(Line, szProcessed, MAX_STRING - 4, Color);

	CXStr text = szProcessed;
	text += "<br>";

	ConvertItemTags(text);
	sPendingChat.push_back(text);

	return 0;
}

PLUGIN_API void OnPulse()
{
	if (gGameState == GAMESTATE_CHARSELECT && !MQChatWnd && !bNoCharSelect)
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

			MQChatWnd->OutBoxLines += ThisPulse;

			if (MQChatWnd->OutBoxLines > MAX_CHAT_SIZE)
			{
				DWORD Diff = (MQChatWnd->OutBoxLines - MAX_CHAT_SIZE) + LINES_PER_FRAME;
				MQChatWnd->OutBoxLines -= Diff;
				Benchmark(bmStripFirstStmlLines, MQChatWnd->OutputBox->StripFirstSTMLLines(Diff));
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

	~MQ2ChatWndType() {}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override
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
				Dest.Type = pStringType;
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
		Destination[0] = 0;

		if (MQChatWnd)
		{
			strcpy_s(Destination, MAX_STRING, MQChatWnd->GetWindowText().c_str());
		}

		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		return false;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		return false;
	}
};
MQ2ChatWndType* pChatWndType = nullptr;

bool dataChatWnd(const char* szName, MQTypeVar& Dest)
{
	Dest.DWord = 1;
	Dest.Type = pChatWndType;
	return true;
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

	AddMQ2KeyBind("MQ2CHAT", DoMQ2ChatBind);
	bmStripFirstStmlLines = AddMQ2Benchmark("StripFirstStmlLines");
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
	RemoveMQ2Data("ChatWnd");
	delete pChatWndType;
	RemoveMQ2Benchmark(bmStripFirstStmlLines);
	bmStripFirstStmlLines = 0;
	DestroyChatWnd();
}
