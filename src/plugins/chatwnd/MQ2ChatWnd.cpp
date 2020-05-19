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

#include <mq/Plugin.h>

#include <vector>
#include <list>
#include <string>

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

void LoadChatSettings();

class CMQChatWnd : public CCustomWnd
{
public:
	CMQChatWnd(const char* Template) : CCustomWnd(Template)
	{
		SetWindowStyle(CWS_CLIENTMOVABLE | CWS_USEMYALPHA | CWS_RESIZEALL | CWS_BORDER | CWS_MINIMIZE | CWS_TITLE);
		RemoveStyle(CWS_TRANSPARENT | CWS_CLOSE);
		SetBGColor(MQColor(0, 0, 0)); // black background
		SetFaded(false);
		SetClickable(true);
		SetAlpha(255);
		SetBGType(1);
		SetZLayer(1); // Make this the topmost window (we will leave it as such for charselect, and allow it to move to background ingame)
		SetDefaultLocation(10, 10, 410, 210);
		ContextMenuID = 3;

		InputBox = (CEditWnd*)GetChildItem("CW_ChatInput");
		InputBox->SetParentWindow(this);
		InputBox->AddStyle(CWS_AUTOVSCROLL | CWS_RELATIVERECT | CWS_BORDER);
		InputBox->SetCRNormal(MQColor(255, 255, 255)); // we want a white cursor
		InputBox->SetMaxChars(512);

		OutputBox = (CStmlWnd*)GetChildItem("CW_ChatOutput");
		OutputBox->SetParentWindow(this);
		OutputBox->SetClickable(true);
		OutputBox->AddStyle(CWS_CLIENTMOVABLE);
		OutputBox->MaxLines = MAX_LINES_OUTBOX;
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
				SetVisible(true);
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
					if (m_cmdHistory.empty() || m_cmdHistory.front().compare(text.c_str()))
					{
						if (m_cmdHistory.size() > CMD_HIST_MAX)
						{
							m_cmdHistory.pop_back();
						}

						m_cmdHistory.insert(m_cmdHistory.begin(), text.c_str());
					}

					m_currentCmd = -1;
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
						if (!m_cmdHistory.empty())
						{
							m_currentCmd++;
							if (m_currentCmd < ((int)m_cmdHistory.size()) && m_currentCmd >= 0)
							{
								const std::string& s = m_cmdHistory.at(m_currentCmd);
								InputBox->SetWindowText(s.c_str());
							}
							else
							{
								m_currentCmd = ((int)m_cmdHistory.size()) - 1;
							}
						}
					}
					else if (iKeyPress == 0xd0) // KeyDown
					{
						if (!m_cmdHistory.empty())
						{
							m_currentCmd--;
							if (m_currentCmd >= 0 && !m_cmdHistory.empty())
							{
								std::string s = m_cmdHistory.at(m_currentCmd);
								InputBox->SetWindowText(s.c_str());
							}
							else if (m_currentCmd < 0)
							{
								m_currentCmd = -1;
								InputBox->InputText.clear();
							}
						}
					}
				}
			}
		}
		else if (Message == XWM_LINK)
		{
			for (auto wnd : pChatManager->ChannelMap)
			{
				if (wnd)
				{
					wnd->WndNotification(wnd->OutputWnd, Message, data);
					break;
				}
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

	virtual void LoadIniInfo() override
	{
		LoadChatSettings();
		LoadSettingsFromINI(szChatINISection, INIFileName);
	}

	virtual void LoadSettingsFromINI(const char* sectionName, const char* fileName) override
	{
		SetChatFont(GetPrivateProfileInt(sectionName, "FontSize", 4, fileName));
		SetWindowText(CXStr{ GetPrivateProfileString(sectionName, "WindowTitle", "MQ", fileName) });

		CCustomWnd::LoadSettingsFromINI(sectionName, fileName);
	}


	int FontSize = 4;
	CEditWnd* InputBox;
	CStmlWnd* OutputBox;

private:
	std::vector<std::string> m_cmdHistory;
	int m_currentCmd = -1;
};

CMQChatWnd* MQChatWnd = nullptr;

void LoadChatSettings()
{
	bSaveByChar = GetPrivateProfileBool("Settings", "SaveByChar", true, INIFileName);
	bNoCharSelect = GetPrivateProfileBool("Settings", "NoCharSelect", false, INIFileName);

	if (bSaveByChar)
		sprintf_s(szChatINISection, "%s.%s", EQADDR_SERVERNAME, ((SPAWNINFO*)pLocalPlayer)->Name);
	else
		strcpy_s(szChatINISection, "Default");

	bAutoScroll = GetPrivateProfileBool(szChatINISection, "AutoScroll", true, INIFileName);
}

void SaveChatToINI(CSidlScreenWnd* pWindow)
{
	char szTemp[MAX_STRING] = { 0 };
	WritePrivateProfileString("Settings", "AutoScroll", bAutoScroll ? "on" : "off", INIFileName);
	WritePrivateProfileString("Settings", "NoCharSelect", bNoCharSelect ? "on" : "off", INIFileName);
	WritePrivateProfileString("Settings", "SaveByChar", bSaveByChar ? "on" : "off", INIFileName);

	if (pWindow->IsMinimized())
	{
		WritePrivateProfileString(szChatINISection, "Top", std::to_string(pWindow->GetOldLocation().top), INIFileName);
		WritePrivateProfileString(szChatINISection, "Bottom", std::to_string(pWindow->GetOldLocation().bottom), INIFileName);
		WritePrivateProfileString(szChatINISection, "Left", std::to_string(pWindow->GetOldLocation().left), INIFileName);
		WritePrivateProfileString(szChatINISection, "Right", std::to_string(pWindow->GetOldLocation().right), INIFileName);
	}
	else
	{
		WritePrivateProfileString(szChatINISection, "Top", std::to_string(pWindow->GetLocation().top), INIFileName);
		WritePrivateProfileString(szChatINISection, "Bottom", std::to_string(pWindow->GetLocation().bottom), INIFileName);
		WritePrivateProfileString(szChatINISection, "Left", std::to_string(pWindow->GetLocation().left), INIFileName);
		WritePrivateProfileString(szChatINISection, "Right", std::to_string(pWindow->GetLocation().right), INIFileName);
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
}

void CreateChatWindow()
{
	if (MQChatWnd)
	{
		return;
	}

	MQChatWnd = new CMQChatWnd("ChatWindow");

	MQChatWnd->LoadIniInfo();
	//LoadChatFromINI(MQChatWnd);
	//SaveChatToINI(MQChatWnd); // this creates the file if its not there
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
		const int size = GetIntFromString(Line, -1);
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
			MQChatWnd->Move(MQChatWnd->GetDefaultLocation(), false);

			SaveChatToINI(MQChatWnd);
		}
	}

	char Arg[MAX_STRING] = { 0 };
	GetArg(Arg, Line, 1);

	// user wants to adjust autoscroll
	if (!_stricmp(Arg, "autoscroll"))
	{
		GetArg(Arg, Line, 2);

		if (!strlen(Arg))
		{
			WriteChatf("Autoscroll is currently: %s", (bAutoScroll ? "\agOn" : "\arOff"));
			return;
		}

		if (!_stricmp(Arg, "on"))
		{
			// turn it on.
			bAutoScroll = true;
			WriteChatf("Autoscroll is now: \agOn.");
		}
		else if (!_stricmp(Arg, "off"))
		{
			// turn it off.
			bAutoScroll = false;
			WriteChatf("Autoscroll is now: \arOff.");
		}
		else
		{
			WriteChatf("Usage: /mqchat autoscroll [on | off]\n IE: /mqchat autoscroll on");
		}

		WritePrivateProfileString("Settings", "AutoScroll", bAutoScroll ? "on" : "off", INIFileName);
		return;
	}

	// user wants to adjust NoCharSelect
	if (!_stricmp(Arg, "NoCharSelect"))
	{
		GetArg(Arg, Line, 2);

		if (!strlen(Arg))
		{
			WriteChatf("NoCharSelect is currently: %s", (bNoCharSelect ? "\agOn" : "\arOff"));
			return;
		}

		if (!_stricmp(Arg, "on"))
		{
			// turn it on.
			bNoCharSelect = true;
			WriteChatf("NoCharSelect is now: \agOn.");
		}
		else if (!_stricmp(Arg, "off"))
		{
			// turn it off.
			bNoCharSelect = false;
			WriteChatf("NoCharSelect is now: \arOff.");
		}
		else
		{
			WriteChatf("Usage: /mqchat NoCharSelect [on | off]\n IE: /mqchat NoCharSelect on");
		}

		WritePrivateProfileString("Settings", "NoCharSelect", bNoCharSelect ? "on" : "off", INIFileName);
		return;
	}

	// user wants to adjust SaveByChar
	if (!_stricmp(Arg, "SaveByChar"))
	{
		GetArg(Arg, Line, 2);

		if (!strlen(Arg))
		{
			WriteChatf("SaveByChar is currently: %s", (bSaveByChar ? "\agOn" : "\arOff"));
			return;
		}

		if (!_stricmp(Arg, "on"))
		{
			// turn it on.
			bSaveByChar = true;
			WriteChatf("SaveByChar is now: \agOn.");
		}
		else if (!_stricmp(Arg, "off"))
		{
			// turn it off.
			bSaveByChar = false;
			WriteChatf("SaveByChar is now: \arOff.");
		}
		else
		{
			WriteChatf("Usage: /mqchat SaveByChar [on | off]\n IE: /mqchat SaveByChar on");
		}

		WritePrivateProfileString("Settings", "SaveByChar", bSaveByChar ? "on" : "off", INIFileName);
		return;
	}

	WriteChatf("%s was not a valid option. Valid options are: reset, autoscroll, nocharselect, and savebychar", Arg);
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
