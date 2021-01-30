// MQ2ChatWnd.cpp : Single-window MQ Chat
//
//#define DEBUG_TRY 1
#define MAX_CHAT_SIZE 700
#define LINES_PER_FRAME 3
#include "../MQ2Plugin.h"
#include <vector>
#include <list>
#include <string>

using namespace std;

PreSetup("MQ2ChatWnd");

list<string> sPendingChat;

const unsigned int CMD_HIST_MAX=50;
DWORD ulOldVScrollPos=0;
DWORD bmStripFirstStmlLines=0;

bool bAutoScroll=true;
bool bNoCharSelect=false;
bool bSaveByChar=true;

class CMQChatWnd;
CMQChatWnd *MQChatWnd=0;
class CMQChatWnd : public CCustomWnd
{
public:
	CMQChatWnd(char *Template) :CCustomWnd(Template)
	{
		DebugSpew("CMQChatWnd()");
		SetWndNotification(CMQChatWnd);
		SetWindowStyle(CWS_CLIENTMOVABLE | CWS_USEMYALPHA | CWS_RESIZEALL | CWS_BORDER | CWS_MINIMIZE | CWS_TITLE);
		//SetWindowStyle(CWS_AUTOVSCROLL | CWS_AUTOHSCROLL | CWS_TITLE | CWS_MINIMIZE | CWS_RELATIVERECT | CWS_BORDER | CWS_RESIZEALL);
		RemoveStyle(CWS_TRANSPARENT | CWS_CLOSE);
		SetBGColor(0xFF000000);//black background
		InputBox = (CTextEntryWnd*)GetChildItem("CW_ChatInput");
		InputBox->AddStyle(CWS_AUTOVSCROLL | CWS_RELATIVERECT | CWS_BORDER);// 0x800C0;
		this->SetFaded(false);
		this->SetEscapable(false);
		this->SetClickable(true);
		this->SetAlpha(0xFF);
		this->SetFadeToAlpha(0xFF);
		this->SetBGType(1);
		this->ContextMenuID = 3;
		InputBox->SetCRNormal(0xFFFFFFFF);//we want a white cursor
		InputBox->SetMaxChars(512);
		OutputBox = (CStmlWnd*)GetChildItem("CW_ChatOutput");
		OutputBox->SetParentWindow((_CSIDLWND *)this);
		InputBox->SetParentWindow((_CSIDLWND *)this);
		OutBoxLines = 0;
		OutputBox->MaxLines = 0x190;
		OutputBox->SetClickable(true);
		OutputBox->AddStyle(CWS_CLIENTMOVABLE);
		iCurrentCmd = -1;
		SetZLayer(1); // Make this the topmost window (we will leave it as such for charselect, and allow it to move to background ingame)
		this->SetNeedsSaving(0);
		this->CSetWindowText("MQ");
		CXRect rc = { 300, 10, 600, 210 };
		((CXWnd*)this)->Move(rc, false);
		//this->SetKeepOnScreen(1);
	}
    ~CMQChatWnd()
    {
    }
    int WndNotification(CXWnd *pWnd, unsigned int Message, void *data)
    {
		//if (Message == XWM_MAXIMIZEBOX)
		//{
		//	pWnd->Minimize(true);
		//	return 1;
		//}
        if (pWnd==0)
        {
            if (Message==XWM_CLOSE)
            {
                SetVisible(1);
                return 1;
            }
        }
		else if (pWnd==(CXWnd*)InputBox)
        {
            if (Message==XWM_HITENTER)
            {
				char szBuffer[MAX_STRING] = { 0 };
                GetCXStr((PCXSTR)InputBox->InputText,szBuffer, MAX_STRING);
                if (szBuffer[0])
                {
                    if (!sCmdHistory.size() || sCmdHistory.front().compare(szBuffer))
                    {
                        if (sCmdHistory.size()>CMD_HIST_MAX)
                        {
                            sCmdHistory.pop_back();
                        }
                        sCmdHistory.insert(sCmdHistory.begin(),string(szBuffer));
                    }
                    iCurrentCmd=-1;
                    //bool bScrollDown=bAutoScroll?true:(MQChatWnd->OutputBox->VScrollPos==MQChatWnd->OutputBox->VScrollMax?true:false);
                    //char szProcessed[MAX_STRING];
                    //MQToSTML(szBuffer,szProcessed,MAX_STRING);
                    //strcat_s(szProcessed,"<br>");
                    //CXStr NewText(szProcessed);
                    //OutputBox->AppendSTML(NewText);
                    //if (bScrollDown) ((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->VScrollMax);
                    SetCXStr(&InputBox->InputText,"");
                    if (szBuffer[0]=='/')
                    {
	                    DoCommand((PSPAWNINFO)pLocalPlayer,szBuffer);
                    }
                    else
                    {
	                    Echo((PSPAWNINFO)pLocalPlayer,szBuffer);
                    }
                }
                ((CXWnd*)InputBox)->ClrFocus();
            }
            else if (Message == XWM_HISTORY)
            {
                if (data)
                {
                    int* pInt=(int*)data;
                    int iKeyPress=pInt[1];
                    if (iKeyPress==0xc8) // KeyUp
                    {
                        if (sCmdHistory.size()>0)
                        {
                            iCurrentCmd++;
                            if (iCurrentCmd<((int)sCmdHistory.size()) && iCurrentCmd>=0)
                            {
                                string s=(string)sCmdHistory.at(iCurrentCmd);
                                ((CXWnd*)InputBox)->SetWindowTextA(CXStr(s.c_str()));
                            }
                            else
                            {
                                iCurrentCmd=((int)sCmdHistory.size())-1;
                            }
                        }
                    }
                    else if (iKeyPress==0xd0) // KeyDown
                    {
                        if (sCmdHistory.size()>0)
                        {
                            iCurrentCmd--;
                            if (iCurrentCmd>=0 && sCmdHistory.size()>0)
                            {
                                string s=(string)sCmdHistory.at(iCurrentCmd);
                                ((CXWnd*)InputBox)->SetWindowTextA(CXStr(s.c_str()));
                            }
                            else if (iCurrentCmd<0)
                            {
                                iCurrentCmd=-1;
                                SetCXStr(&InputBox->InputText,"");
                            }
                        }
                    }
                }
			}
            else
            {
                DebugSpew("InputBox message %Xh, value: %Xh",Message,data);
            }
        }
        else if (Message==XWM_LINK)
        {
            class CChatWindow *p = (class CChatWindow *)this;
            if (OutputBox!=(CStmlWnd *)pWnd)
            {
                CStmlWnd *tmp;
                int ret;
                //DebugSpew("MQ2ChatWnd: 0x%X, Msg: 0x%X, value: %Xh",pWnd,Message,data);
                //DebugSpew("MQ2ChatWnd: pWnd 0x%x != OutputBox 0x%x\n",pWnd,OutputBox);
                tmp=OutputBox;
                OutputBox=(CStmlWnd*)pWnd;
                ret=p->WndNotification(pWnd,Message,data);
                OutputBox=tmp;
                return ret;
            }
            return p->WndNotification(pWnd,Message,data);
        }
        else
        {
            //DebugSpew("MQ2ChatWnd: 0x%X, Msg: 0x%X, value: %Xh",pWnd,Message,data);
        }
        return CSidlScreenWnd::WndNotification(pWnd,Message,data);
    };

    void SetChatFont(int size) // brainiac 12-12-2007
    {
        struct FONTDATA
        {
            DWORD NumFonts;
            PCHAR* Fonts;
        };
        FONTDATA* Fonts;            // font array structure
        DWORD* SelFont;             // selected font

        // get fonts structure -- this offset can be found by looking at
        // SetChatfont which is called from the /chatfontsize function
        Fonts = (FONTDATA*)&(((char*)pWndMgr)[EQ_CHAT_FONT_OFFSET]);

        // check font array bounds and pointers
        if (size<0 || size>=(int)Fonts->NumFonts)
        {
            return;
        }
        if (!Fonts->Fonts || !MQChatWnd)
        {
            return;
        }
        //DebugSpew("Setting Size: %i", size);

        SelFont = (DWORD*)Fonts->Fonts[size];

        // Save the text, change the font, then restore the text
        CXStr str(((CStmlWnd*)MQChatWnd->OutputBox)->GetSTMLText());
        ((CXWnd*)MQChatWnd->OutputBox)->SetFont(SelFont);
        ((CStmlWnd*)MQChatWnd->OutputBox)->SetSTMLText(str,1,0);
        ((CStmlWnd*)MQChatWnd->OutputBox)->ForceParseNow();
        // scroll to bottom of chat window
        DebugTry(((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->GetVScrollMax()));

        MQChatWnd->FontSize=size;
    };
	CTextEntryWnd* InputBox;
    CStmlWnd* OutputBox;
    //CXWnd* OutWnd;
    //struct _CSIDLWND* OutStruct;
    DWORD OutBoxLines;
    DWORD FontSize;
	DWORD GameState;
	std::string IniSection;
private:
    std::vector<std::string> sCmdHistory;
    int iCurrentCmd;
};

VOID LoadChatSettings()
{
    CHAR szTemp[MAX_STRING]={0};
    GetPrivateProfileString("Settings","AutoScroll",bAutoScroll?"on":"off",szTemp,MAX_STRING,INIFileName);
    bAutoScroll=(!_strnicmp(szTemp,"on",3));
    GetPrivateProfileString("Settings","NoCharSelect",bNoCharSelect?"on":"off",szTemp,MAX_STRING,INIFileName);
    bNoCharSelect=(!_strnicmp(szTemp,"on",3));
    GetPrivateProfileString("Settings", "SaveByChar",bSaveByChar?"on":"off",szTemp,MAX_STRING,INIFileName);
    bSaveByChar=(!_strnicmp(szTemp,"on",3));
}

VOID LoadChatFromINI(PCSIDLWND pWindow)
{
	if (!pLocalPlayer)
		return;
	if (!MQChatWnd)
		return;
	int gs = MQChatWnd->GameState;
	if (gs != GAMESTATE_INGAME && gs != GAMESTATE_CHARSELECT)
		return;
    CHAR szTemp[MAX_STRING]={0};
	CHAR szChatINISection[MAX_STRING]={0};
    LoadChatSettings();
	sprintf_s(szChatINISection, "%s", MQChatWnd->IniSection.c_str());
	//left top right bottom
	int left = GetPrivateProfileInt(szChatINISection, "ChatLeft", 10, INIFileName);
	if (left == 2000)
	{
		left = 10;
	}
	pWindow->SetLocation({ (LONG)left,
		(LONG)GetPrivateProfileInt(szChatINISection,"ChatTop",       10,INIFileName),
		(LONG)GetPrivateProfileInt(szChatINISection,"ChatRight",    410,INIFileName),
		(LONG)GetPrivateProfileInt(szChatINISection,"ChatBottom",   210,INIFileName) });

    pWindow->SetLocked((GetPrivateProfileInt(szChatINISection,"Locked",         0,INIFileName) ? true:false));
    pWindow->SetFades((GetPrivateProfileInt(szChatINISection,"Fades",          0,INIFileName) ? true:false));
    pWindow->SetFadeDelay(GetPrivateProfileInt(szChatINISection,"Delay",       2000,INIFileName));
    pWindow->SetFadeDuration(GetPrivateProfileInt(szChatINISection,"Duration",     500,INIFileName));
    pWindow->SetAlpha((BYTE)GetPrivateProfileInt(szChatINISection,"Alpha",        255,INIFileName));
    pWindow->SetFadeToAlpha((BYTE)GetPrivateProfileInt(szChatINISection,"FadeToAlpha",  255,INIFileName));
    pWindow->SetBGType(GetPrivateProfileInt(szChatINISection,"BGType",         1,INIFileName));
	ARGBCOLOR col = { 0 };
	col.ARGB = pWindow->GetBGColor();
    col.A         = GetPrivateProfileInt(szChatINISection,"BGTint.alpha",     255,INIFileName);
    col.R         = GetPrivateProfileInt(szChatINISection,"BGTint.red",     0,INIFileName);
    col.G         = GetPrivateProfileInt(szChatINISection,"BGTint.green",   0,INIFileName);
    col.B         = GetPrivateProfileInt(szChatINISection,"BGTint.blue",    0,INIFileName);
	pWindow->SetBGColor(col.ARGB);
    MQChatWnd->SetChatFont(GetPrivateProfileInt(szChatINISection,"FontSize",4,INIFileName));
    GetPrivateProfileString(szChatINISection,"WindowTitle","MQ",szTemp,MAX_STRING,INIFileName);
	pWindow->CSetWindowText(szTemp);
	pWindow->SetKeepOnScreen(GetPrivateProfileInt(szChatINISection,"KeepOnScreen",         0,INIFileName));
}
template <unsigned int _Size>LPSTR SafeItoa(int _Value,char(&_Buffer)[_Size], int _Radix)
{
	errno_t err = _itoa_s(_Value, _Buffer, _Radix);
	if (!err) {
		return _Buffer;
	}
	return "";
}
VOID SaveChatToINI(PCSIDLWND pWindow)
{
 	if (!pLocalPlayer)
		return;
	if (!MQChatWnd)
		return;
	int gs = MQChatWnd->GameState;
	if (gs != GAMESTATE_INGAME && gs != GAMESTATE_CHARSELECT)
		return;
	CHAR szTemp[MAX_STRING]={0};
	CHAR szChatINISection[MAX_STRING]={0};
	sprintf_s(szChatINISection, "%s", MQChatWnd->IniSection.c_str());

    WritePrivateProfileString("Settings","AutoScroll",   bAutoScroll?"on":"off",INIFileName);
    WritePrivateProfileString("Settings","NoCharSelect", bNoCharSelect?"on":"off",INIFileName);
    WritePrivateProfileString("Settings","SaveByChar",   bSaveByChar?"on":"off",INIFileName);

    if (pWindow->IsMinimized())
    {
        WritePrivateProfileString(szChatINISection,"ChatTop",    SafeItoa(pWindow->GetOldLocation().top,    szTemp,10),INIFileName);
        WritePrivateProfileString(szChatINISection,"ChatBottom", SafeItoa(pWindow->GetOldLocation().bottom, szTemp,10),INIFileName);
        WritePrivateProfileString(szChatINISection,"ChatLeft",   SafeItoa(pWindow->GetOldLocation().left,   szTemp,10),INIFileName);
        WritePrivateProfileString(szChatINISection,"ChatRight",  SafeItoa(pWindow->GetOldLocation().right,	szTemp,10),INIFileName);
    }
    else
    {
        WritePrivateProfileString(szChatINISection,"ChatTop",    SafeItoa(pWindow->GetLocation().top,		szTemp,10),INIFileName);
        WritePrivateProfileString(szChatINISection,"ChatBottom", SafeItoa(pWindow->GetLocation().bottom,	szTemp,10),INIFileName);
        WritePrivateProfileString(szChatINISection,"ChatLeft",   SafeItoa(pWindow->GetLocation().left,		szTemp,10),INIFileName);
        WritePrivateProfileString(szChatINISection,"ChatRight",  SafeItoa(pWindow->GetLocation().right,		szTemp,10),INIFileName);
    }
    WritePrivateProfileString(szChatINISection,"Locked",         SafeItoa(pWindow->IsLocked(),				szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"Fades",          SafeItoa(pWindow->GetFades(),				szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"Delay",          SafeItoa(pWindow->GetFadeDelay(),			szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"Duration",       SafeItoa(pWindow->GetFadeDuration(),		szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"Alpha",          SafeItoa(pWindow->GetAlpha(),				szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"FadeToAlpha",    SafeItoa(pWindow->GetFadeToAlpha(),		szTemp,10),INIFileName);
	ARGBCOLOR col = { 0 };
	col.ARGB = pWindow->GetBGColor();
    WritePrivateProfileString(szChatINISection,"BGType",         SafeItoa(pWindow->GetBGType(),				szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"BGTint.alpha",   SafeItoa(col.A,							szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"BGTint.red",     SafeItoa(col.R,							szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"BGTint.green",   SafeItoa(col.G,							szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"BGTint.blue",    SafeItoa(col.B,							szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"FontSize",       SafeItoa(MQChatWnd->FontSize,				szTemp,10),INIFileName);
    WritePrivateProfileString(szChatINISection,"KeepOnScreen",	 SafeItoa(pWindow->GetKeepOnScreen(),		szTemp,10),INIFileName);
	
	GetCXStr(pWindow->CGetWindowText(),szTemp, MAX_STRING);
	//GetCXStr(pWindow->WindowText,szTemp, MAX_STRING);
    WritePrivateProfileString(szChatINISection,"WindowTitle",szTemp,INIFileName);
}
void UpdateGameState(DWORD GameState);
VOID CreateChatWindow()
{
    if (MQChatWnd)
    {
        return;
    }
    MQChatWnd = new CMQChatWnd("ChatWindow");
    if (!MQChatWnd)
    {
        return;
    }
	UpdateGameState(GetGameState());
	LoadChatFromINI((PCSIDLWND)MQChatWnd);
	SaveChatToINI((PCSIDLWND)MQChatWnd); // A) we're masochists, B) this creates the file if its not there..
}

VOID DestroyChatWnd()
{
    if (MQChatWnd)
    {
        sPendingChat.clear();
		SaveChatToINI((PCSIDLWND)MQChatWnd);
        delete MQChatWnd;
        MQChatWnd=0;
        ulOldVScrollPos=0;
    }
}

VOID Style(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!szLine || !szLine[0])
    {
		char out[256] = { 0 };
        sprintf_s(out,"Style 0x%X",MQChatWnd->GetWindowStyle());
        WriteChatColor(out);
        return;
    }
    if (szLine[0]=='!')
    {
        int TurnOff = 0;
        if(sscanf_s(&szLine[1],"%x",&TurnOff)) {
			//well we set it anyway i guess...
		}
		MQChatWnd->RemoveStyle(TurnOff);
		//BitOff(MQChatWnd->WindowStyle, TurnOff);
    }
    else
    {
        int TurnOn = 0;
        if(sscanf_s(&szLine[0],"%x",&TurnOn)) {
			//hmm can error handle i guess
		}
        MQChatWnd->AddStyle(TurnOn);
        //BitOn(MQChatWnd->WindowStyle,TurnOn);
    }
    char out[256];
    sprintf_s(out,"Style 0x%X",MQChatWnd->GetWindowStyle());
    WriteChatColor(out);
}

VOID MQChatFont(PSPAWNINFO pChar, PCHAR Line)
{
    if (MQChatWnd)
    {
        if (Line[0])
        {
            int size=atoi(Line);
            if (size<0 || size>10)
            {
                WriteChatf("Usage: /mqfont 0-10");
                return;
            }
            MQChatWnd->SetChatFont(size);
            SaveChatToINI((PCSIDLWND)MQChatWnd);
        }
    }
}

VOID MQChatMin(PSPAWNINFO pChar, PCHAR Line)
{
    if (MQChatWnd)
    {
        ((CXWnd*)MQChatWnd)->Minimize(true);
    }
}
VOID MQChat(PSPAWNINFO pChar, PCHAR Line)
{
	if (MQChatWnd)
	{
		if (!_stricmp(Line, "reset"))
		{
			MQChatWnd->SetLocked(false);
			CXRect rc = { 300, 10, 600, 210 };
			((CXWnd*)MQChatWnd)->Move(rc, false);
			SaveChatToINI((PCSIDLWND)MQChatWnd);
			MQChatWnd->GameState = GAMESTATE_CHARSELECT;
			MQChatWnd->IniSection = "CharSelect";
			SaveChatToINI((PCSIDLWND)MQChatWnd);
			UpdateGameState(GetGameState());

            return;
		}

    }

    char Arg[MAX_STRING] = { 0 };
    GetArg(Arg, Line, 1);

    //user wants to adjust autoscroll
    if (!_stricmp(Arg, "autoscroll")) {
        GetArg(Arg, Line, 2);
        if (!strlen(Arg)) {
            WriteChatf("Autoscroll is currently: %s", (bAutoScroll ? "\agOn" : "\arOff"));
            return;
        }

        //turn it on.
        if (!_stricmp(Arg, "on")) {
            bAutoScroll = true;
            WriteChatf("Autoscroll is now: \agOn.");
        }//turn it off.
        else if (!_stricmp(Arg, "off")) {
            bAutoScroll = false;
            WriteChatf("Autoscroll is now: \arOff.");
        }
        else {
            WriteChatf("Usage: /mqchat autoscroll [on | off]\n IE: /mqchat autoscroll on");
        }

        WritePrivateProfileString("Settings", "AutoScroll", bAutoScroll ? "on" : "off", INIFileName);
        return;
    }

    //user wants to adjust NoCharSelect
    if (!_stricmp(Arg, "NoCharSelect")) {
        GetArg(Arg, Line, 2);
        if (!strlen(Arg)) {
            WriteChatf("NoCharSelect is currently: %s", (bNoCharSelect ? "\agOn" : "\arOff"));
            return;
        }

        //turn it on.
        if (!_stricmp(Arg, "on")) {
            bNoCharSelect = true;
            WriteChatf("NoCharSelect is now: \agOn.");
        }//turn it off.
        else if (!_stricmp(Arg, "off")) {
            bNoCharSelect = false;
            WriteChatf("NoCharSelect is now: \arOff.");
        }
        else {
            WriteChatf("Usage: /mqchat NoCharSelect [on | off]\n IE: /mqchat NoCharSelect on");
        }

        WritePrivateProfileString("Settings", "NoCharSelect", bNoCharSelect ? "on" : "off", INIFileName);
        return;
    }

    //user wants to adjust SaveByChar
    if (!_stricmp(Arg, "SaveByChar")) {
        GetArg(Arg, Line, 2);
        if (!strlen(Arg)) {
            WriteChatf("SaveByChar is currently: %s", (bSaveByChar ? "\agOn" : "\arOff"));
            return;
        }

        //turn it on.
        if (!_stricmp(Arg, "on")) {
            bSaveByChar = true;
            WriteChatf("SaveByChar is now: \agOn.");
        }//turn it off.
        else if (!_stricmp(Arg, "off")) {
            bSaveByChar = false;
            WriteChatf("SaveByChar is now: \arOff.");
        }
        else {
            WriteChatf("Usage: /mqchat SaveByChar [on | off]\n IE: /mqchat SaveByChar on");
        }

        WritePrivateProfileString("Settings", "SaveByChar", bSaveByChar ? "on" : "off", INIFileName);
        return;
    }

    WriteChatf("%s was not a valid option. Valid options are Reset, Autoscroll, NoCharSelect, and SaveByChar", Arg);
}

VOID SetChatTitle(PSPAWNINFO pChar, PCHAR Line)
{
	if (MQChatWnd)
    {
		MQChatWnd->CSetWindowText(Line);
		//SetCXStr(&MQChatWnd->WindowText,Line);
    }
}
VOID MQChatClear(PSPAWNINFO pChar, PCHAR Line)
{
	//int sizeofCXWnd = sizeof(CXWnd);
	//int sizeofCSidlScreenWnd = sizeof(CSidlScreenWnd);
    if(MQChatWnd)
    {
		//PEQCHATWINDOW pChatw = (PEQCHATWINDOW)MQChatWnd;
		CChatWindow*chatwnd = (CChatWindow*)MQChatWnd;
        chatwnd->Clear();
        ulOldVScrollPos=0;
        MQChatWnd->OutBoxLines=0;
    }
}

VOID DoMQ2ChatBind(PCHAR Name, BOOL Down)
{
    if (!Down)
    {
        if (MQChatWnd)
        {
            CXRect rect=((CXWnd*)MQChatWnd->InputBox)->GetScreenRect();
            CXPoint pt=rect.CenterPoint();
            ((CXWnd*)MQChatWnd->InputBox)->SetWindowTextA(CXStr("/"));
            ((CXWnd*)MQChatWnd->InputBox)->HandleLButtonDown(&pt,0);
        }
    }
}

PLUGIN_API VOID OnReloadUI()
{
    DebugSpewAlways("MQ2ChatWnd::OnReloadUI()");
    // redraw window when you load/reload UI
	DebugSpewAlways("OnReloadUI called %d loading chat", GetGameState());
	DebugTry(CreateChatWindow());
}

PLUGIN_API VOID OnCleanUI()
{
    DebugSpewAlways("MQ2ChatWnd::OnCleanUI()");
    // destroy chatwnd before server select & while reloading UI
	DebugSpewAlways("OnCleanUI called %d saving chat", GetGameState());
    DestroyChatWnd();
}
void UpdateGameState(DWORD GameState)
{
	if (MQChatWnd)
	{
		if (GameState == GAMESTATE_CHARSELECT || GameState == GAMESTATE_INGAME)
		{
			MQChatWnd->GameState = GameState;
			MQChatWnd->IniSection = "CharSelect";
			if (GameState == GAMESTATE_INGAME)
			{
				CHAR szChatINISection[128];
				sprintf_s(szChatINISection, "%s.%s", EQADDR_SERVERNAME, ((PSPAWNINFO)pLocalPlayer)->Name);
				MQChatWnd->IniSection = szChatINISection;
				if (!bSaveByChar)
					MQChatWnd->IniSection = "Default";
			}
			LoadChatFromINI((PCSIDLWND)MQChatWnd);
		}
	}
}
PLUGIN_API VOID SetGameState(DWORD GameState)
{
    //DebugSpew("MQ2ChatWnd::SetGameState()");
	UpdateGameState(GameState);
    if (GameState==GAMESTATE_CHARSELECT)
    {
        if (bNoCharSelect)
        {
			DebugSpewAlways("Gamestate changed to %d saving chat", GameState);
            // destroy chatwnd at charselect if NoCharSelect=on
            DestroyChatWnd();
        }
        else
        {
            AddMQ2KeyBind("MQ2CSCHAT",DoMQ2ChatBind);
            KeyCombo Combo;
            ParseKeyCombo("/",Combo);
            SetMQ2KeyBind("MQ2CSCHAT",FALSE,Combo);
        }
    }
    else
    {
        if (GameState!=GAMESTATE_CHARCREATE) RemoveMQ2KeyBind("MQ2CSCHAT");
        if (GameState==GAMESTATE_INGAME && !MQChatWnd)
        {
            // we entered the game, set up shop
			DebugSpewAlways("Gamestate changed to %d loading chat", GameState);
            DebugTry(CreateChatWindow());
		}
    }
	UpdateGameState(GameState);
}

// This is called every time WriteChatColor is called by MQ2Main or any plugin,
// IGNORING FILTERS, IF YOU NEED THEM MAKE SURE TO IMPLEMENT THEM. IF YOU DONT
// CALL CEverQuest::dsp_chat MAKE SURE TO IMPLEMENT EVENTS HERE
PLUGIN_API DWORD OnWriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
    //DebugSpewAlways("MQ2ChatWnd::OnWriteChatColor(%s)",Line);

	if (!MQChatWnd)
    {
        if (gGameState==GAMESTATE_INGAME)
        {
            SetGameState(gGameState);
        }
        if (!MQChatWnd)
        {
            return 0;
        }
    }
    MQChatWnd->SetVisible(true);
    PFILTER pFilter=gpFilters;
    while (pFilter)
    {
        if (!pFilter->pEnabled || (*pFilter->pEnabled))
        {
            if (!_strnicmp(Line,pFilter->FilterText,pFilter->Length))
            {
                return 0;
            }
        }
        pFilter = pFilter->pNext;
    }
	if (gAnonymize) {
		int len = strlen(Line);
		char *Name = new char[MAX_STRING];
		char *NameAddr = Name;
		strcpy_s(Name, MAX_STRING, "*");
		int namelen = 0;
		//check for group members (in case they aren't in the zone with me)
		if (PCHARINFO pChar = GetCharInfo()) {
			DWORD n = 0;
			if (pChar->pGroupInfo) {
				for (int i = 1; i < 6; i++) {
					if (GetCharInfo()->pGroupInfo->pMember[i])
						n++;
				}
				if (n) {
					n++;
					for (DWORD i = 1; i <= n; i++)
					{
						if (pChar->pGroupInfo->pMember[i])
						{
							GetCXStr(pChar->pGroupInfo->pMember[i]->pName, Name, MAX_STRING);//Get the group members name from the group info, not the pSpawn, they might not be in the zone.
							namelen = strlen(Name);
							if (namelen) {
								if (strstr(Line, Name)) {
									int EntEnd = (int)(strstr(Line, Name) - Line + strlen(Name));
									int EntStart = (int)(strstr(Line, Name) - Line);
									if (Anonymize(Name, namelen, 2)) {
										char *firsthalf = new char[MAX_STRING];
										char*firsthalfaddr = firsthalf;
										strncpy_s(firsthalf,MAX_STRING, &Line[0], EntStart);//copy the first half of the string and store it here.
										char *secondhalf = new char[MAX_STRING];
										char *secondhalfaddr = secondhalf;
										strncpy_s(secondhalf,MAX_STRING, &Line[EntEnd], strlen(Line));//copy the part after the word and store it here.
										strcat_s(firsthalf, MAX_STRING, Name);//concatinate the word to the first half
										strcat_s(firsthalf, MAX_STRING, secondhalf);//concatinate the second half to the end of the firsthalf+word.
										strcpy_s(Line, MAX_STRING, firsthalf);//store the newly built string as the line to output.
										delete firsthalfaddr;
										delete secondhalfaddr;
									}
								}
							}
						}
					}
				}
			}
			//Anonymize my name, and any other spawn in the zone.
			PSPAWNINFO pSpawn = (PSPAWNINFO)pSpawnList;
			char *word = new char[MAX_STRING];
			char *wordaddr = word;
			while (pSpawn) {
				if (pSpawn->Type != SPAWN_NPC || (pSpawn->Type == SPAWN_NPC && pSpawn->MasterID)) {
					while (strstr(Line, pSpawn->DisplayedName)) {
						int EntEnd = (int)(strstr(Line, pSpawn->DisplayedName) - Line + strlen(pSpawn->DisplayedName));
						int EntStart = (int)(strstr(Line, pSpawn->DisplayedName) - Line);
						int namelen = EntEnd - EntStart;
						strncpy_s(word, MAX_STRING, &Line[EntStart], EntEnd - EntStart);
						if (!Anonymize(word, MAX_STRING, 2)) {//try to anonymize word, if I fail, then replace the word with asterix.
							for (int i = EntStart + 1; i < EntEnd - 1; i++) {
								Line[i] = '*';
							}
						}
						else {//if the word gets anonymized, lets build the new output string, nessesary for Anonymize where AnonymizeFlag=1
							char firsthalf[MAX_STRING] = "";
							strncpy_s(firsthalf, &Line[0], EntStart);//copy the first half of the string and store it here.
							char secondhalf[MAX_STRING] = "";
							strncpy_s(secondhalf, &Line[EntEnd], strlen(Line));//copy the part after the word and store it here.
							strcat_s(firsthalf, MAX_STRING, word);//concatinate the word to the first half
							strcat_s(firsthalf, MAX_STRING, secondhalf);//concatinate the second half to the end of the firsthalf+word.
							strcpy_s(Line, MAX_STRING, firsthalf);//store the newly built string as the line to output.
						}
					}
				}
				pSpawn = pSpawn->pNext;
			}
			delete wordaddr;
		}
		delete NameAddr;
	}
    Color=pChatManager->GetRGBAFromIndex(Color);
	CHAR *szProcessed = new CHAR[MAX_STRING];

    int pos = MQToSTML(Line,szProcessed,MAX_STRING-4,Color);
	try {
		strcat_s(szProcessed,MAX_STRING, "<br>");//we left room for this above...
		CXStr NewText(szProcessed);
		DebugTry(ConvertItemTags(NewText, FALSE));
		sPendingChat.push_back(NewText.Ptr->Text);
	} catch (...) {
		Sleep(0);
	}
	delete szProcessed;
    return 0;
}
int savecounter = 0;
PLUGIN_API VOID OnPulse()
{
    if (gGameState==GAMESTATE_CHARSELECT && !MQChatWnd && !bNoCharSelect)
    {
        CreateChatWindow();
    }
    if (MQChatWnd)
    {
		/*if (savecounter++ > 100)//we dont need to check this a million times per second...
		{
			if (MQChatWnd->GetNeedsSaving())
			{
				SaveChatToINI((PCSIDLWND)MQChatWnd);
				MQChatWnd->SetNeedsSaving(0);
				//WriteChatf("Saved ChatWindow Position");
			}
			savecounter = 0;
		}*/
		switch (gGameState)
		{
			case GAMESTATE_CHARSELECT:
			{
				if (MQChatWnd->GetZLayer() != 1)
					MQChatWnd->SetZLayer(1);
				break;
			}
			case GAMESTATE_INGAME:
			{
				if (MQChatWnd->GetZLayer() != 0)
					MQChatWnd->SetZLayer(0);
				break;
			}
		}
        if(!sPendingChat.empty())
        {
            // set 'old' to current
			ulOldVScrollPos = MQChatWnd->OutputBox->GetVScrollPos();

            // scroll down if autoscroll enabled, or current position is the bottom of chatwnd
            bool bScrollDown=bAutoScroll?true:(MQChatWnd->OutputBox->GetVScrollPos()==MQChatWnd->OutputBox->GetVScrollMax()?true:false);

            DWORD ThisPulse = sPendingChat.size();
            if (ThisPulse>LINES_PER_FRAME)
            {
                ThisPulse=LINES_PER_FRAME;
            }

            MQChatWnd->OutBoxLines+=ThisPulse;
            if (MQChatWnd->OutBoxLines>MAX_CHAT_SIZE)
            {
                DWORD Diff=(MQChatWnd->OutBoxLines-MAX_CHAT_SIZE)+LINES_PER_FRAME;
                MQChatWnd->OutBoxLines-=Diff;
                Benchmark(bmStripFirstStmlLines,MQChatWnd->OutputBox->StripFirstSTMLLines(Diff));
            }
            for (DWORD N=0 ; N<ThisPulse ; N++)
            {
				if(!sPendingChat.empty())
                {
					DebugTry(MQChatWnd->OutputBox->AppendSTML( sPendingChat.begin()->c_str() ));
                    sPendingChat.pop_front();
				}
                //DebugSpew("NEW: max %u - pos: %u",MQChatWnd->OutputBox->VScrollMax,MQChatWnd->OutputBox->VScrollPos);
            }

            if(bScrollDown)
            {
                // set current vscroll position to bottom
                DebugTry(((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->GetVScrollMax()));
            }
            else
            {
                // autoscroll is disabled and current vscroll position was not at the bottom, retain position
                // note: if the window is full (VScrollMax value between 9793 and 9835), this will not adjust with
                // the flushing of buffer that keeps window a certain max size
                DebugTry(((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(ulOldVScrollPos));
            }
        }

        if(InHoverState())
        {
            ((CXWnd*)MQChatWnd)->DoAllDrawing();
        }
    }
}

class MQ2ChatWndType *pChatWndType=0;

class MQ2ChatWndType : public MQ2Type
{
    public:
        enum ChatWndMembers {
            Title=1,
        };

        MQ2ChatWndType():MQ2Type("chatwnd") {
            TypeMember(Title);
        }

        ~MQ2ChatWndType() {}

        bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest) {
            PMQ2TYPEMEMBER pMember=MQ2ChatWndType::FindMember(Member);
            if (!pMember)
                return false;
            switch((ChatWndMembers)pMember->ID) {
                case Title:
				{
					if (MQChatWnd)
					{
						GetCXStr(MQChatWnd->CGetWindowText(),DataTypeTemp);
						//GetCXStr(MQChatWnd->WindowText, DataTypeTemp);
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

        bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)  {
			if (MQChatWnd)
			{
				GetCXStr(MQChatWnd->CGetWindowText(), Destination);
			}
			else {
				strcpy_s(Destination, MAX_STRING, "");
			}
            return true;
        }

        bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source) {
            return false;
        }

        bool FromString(MQ2VARPTR &VarPtr, PCHAR Source) {
            return false;
        }
};

BOOL dataChatWnd(PCHAR szName, MQ2TYPEVAR &Dest)
{
    Dest.DWord=1;
    Dest.Type=pChatWndType;
    return true;
}
typedef struct _CBUTTONDRAWTEMPLATE {
/*0x238*/	PCXSTR Name;
/*0x23c*/	void   *pNormal;//CTextureAnimation
/*0x240*/	void   *pPressed;//CTextureAnimation
/*0x244*/	void   *pFlyby;//CTextureAnimation
/*0x248*/	void   *pDisabled;//CTextureAnimation
/*0x24c*/	void   *pPressedFlyby;//CTextureAnimation
/*0x250*/	void   *pPressedDisabled;//CTextureAnimation
/*0x254*/	void   *pNormalDecal;//CTextureAnimation
/*0x258*/	void   *pPressedDecal;//CTextureAnimation
/*0x25c*/	void   *pFlybyDecal;//CTextureAnimation
/*0x260*/	void   *pDisabledDecal;//CTextureAnimation
/*0x264*/	void   *pPressedFlybyDecal;//CTextureAnimation
/*0x268*/	void   *pPressedDisabledDecal;//CTextureAnimation
/*0x26c*/
} CBUTTONDRAWTEMPLATE, *PCBUTTONDRAWTEMPLATE;


void MuleUI(PSPAWNINFO pSpawn, PCHAR szLine)
{
	if (GetGameState() == GAMESTATE_INGAME) {
		if (pOptionsWnd) {
			pOptionsWnd->SetBGColor(0xFF000000);
		}
		if (pTargetWnd) {
			pTargetWnd->SetBGColor(0xFF000000);
		}
		if (pOptionsWnd) {
			if (CButtonWnd*check = (CButtonWnd*)pOptionsWnd->GetChildItem("OGP_UseTellWindowsCheckbox")) {
				if (!check->Checked) {
					SendWndClick2(check, "leftmouseup");
					WriteChatf("Use Tell Windows set to ON");
				}
			}
			if (CButtonWnd*check = (CButtonWnd*)pOptionsWnd->GetChildItem("OGP_AutoConsentGroupCheckbox")) {
				if (!check->Checked) {
					SendWndClick2(check, "leftmouseup");
					WriteChatf("AutoConsentGroup set to ON");
				}
			}
			if (CButtonWnd*check = (CButtonWnd*)pOptionsWnd->GetChildItem("OGP_AutoConsentRaidCheckbox")) {
				if (!check->Checked) {
					SendWndClick2(check, "leftmouseup");
					WriteChatf("AutoConsentRaid set to ON");
				}
			}
			if (CButtonWnd*check = (CButtonWnd*)pOptionsWnd->GetChildItem("OGP_AutoConsentGuildCheckbox")) {
				if (!check->Checked) {
					SendWndClick2(check, "leftmouseup");
					WriteChatf("AutoConsentGuild set to ON");
				}
			}
			if (CButtonWnd*check = (CButtonWnd*)pOptionsWnd->GetChildItem("ODP_ShowHelmCheckbox")) {
				if (check->Checked) {
					SendWndClick2(check, "leftmouseup");
					WriteChatf("ShowHelm set to OFF");
				}
			}
			if (CSliderWnd*check = (CSliderWnd*)pOptionsWnd->GetChildItem("ODP_FadeToAlphaSlider")) {
				check->SetValue(100);
				SendWndNotification("Optionswindow", "ODP_FadeToAlphaSlider", 14, (void*)255);
				WriteChatf("FadeToAlpha set to 100%%");
			}
			if (CSliderWnd*check = (CSliderWnd*)pOptionsWnd->GetChildItem("ODP_WindowAlphaSlider")) {
				check->SetValue(74);
				SendWndNotification("Optionswindow", "ODP_WindowAlphaSlider", 14, (void*)229);
				WriteChatf("WindowAlpha set to 100%%");
			}
			if (CListWnd*check = (CListWnd*)pOptionsWnd->GetChildItem("OptionsChatFilterPage")) {
				int color = 25;// /who color to green
				SaveColors(color, 0, 255, 0);
				SaveColors(1, 0, 255, 0);//tells
				SaveColors(70, 0, 255, 0);//item links
				SaveColors(31, 255, 50, 255);//my dice
				SaveColors(103, 240, 127, 0);//others dice
				SaveColors(104, 240, 127, 0);//group/raid dice
				pOptionsWnd->FillChatFilterList();
				WriteChatf("Who Color set to green");
			}
			if (CXWnd*wnd = FindMQ2Window("HotButtonWnd")) {
				if (CXWnd*child = wnd->GetChildItem("HB_Button1")) {
					CHotButton *hbtn = (CHotButton*)child;
					if (hbtn && hbtn->pButtonWnd && hbtn->pButtonWnd->GetDrawTemplate()) {
						PCBUTTONDRAWTEMPLATE btemp = (PCBUTTONDRAWTEMPLATE)hbtn->pButtonWnd->GetDrawTemplate();
						Sleep(0);
					}
					//btn->DrawTemplate
					if (CXWnd*child2 = child->GetChildItem("HB_SpellGem")) {
						child2->SetBGColor(0xFF000000);
					}
					if (CXWnd*child2 = child->GetChildItem("HB_InvSlot")) {
						if (CXWnd*child3 = child2->GetChildItem("A_RecessedBox")) {
							child3->SetBGColor(0xFF000000);
						}
						child2->SetBGColor(0xFF000000);
					}
					if (CXWnd*child2 = child->GetChildItem("A_HotButton1Normal")) {
						child2->SetBGColor(0xFF000000);
					}
					/*A_HotButton1Normal</Normal>
			<Pressed>A_HotButton1Pressed</Pressed>
			<Flyby>A_HotButton1Flyby</Flyby>
			<Disabled>A_HotButton1Disabled</Disabled>
			<PressedFlyby>A_HotButton1PressedFlyby</PressedFlyby>*/
					CScreenPieceTemplate *btntemplate = pSidlMgr->FindScreenPieceTemplate("A_RecessedBox");
					if (btntemplate) {
						btntemplate->BackgroundTextureTint = 0xFF000000;
					}
					child->SetBGColor(0xFF000000);
				}
				wnd->SetCRNormal(0xFF000000);
				wnd->SetBGColor(0xFF000000);
			}
			if (CXWnd*wnd = FindMQ2Window("HotButtonWnd2")) {
				if (CXWnd*child = wnd->GetChildItem("HB_Button1")) {
					child->SetBGColor(0xFF000000);
				}
				wnd->SetCRNormal(0xFF000000);
				wnd->SetBGColor(0xFF000000);
			}
		}
	}
}
PLUGIN_API VOID InitializePlugin()
{
    DebugSpewAlways("Initializing MQ2ChatWnd");
    // Add commands, macro parameters, hooks, etc.
	AddMQ2Data("ChatWnd",dataChatWnd);
    pChatWndType = new MQ2ChatWndType;

    AddCommand("/style",Style,0,1,0);
    AddCommand("/mqfont",MQChatFont);
    AddCommand("/mqchat",MQChat);
    AddCommand("/mqmin",MQChatMin);
    AddCommand("/mqclear",MQChatClear);
    AddCommand("/setchattitle",SetChatTitle);
    AddCommand("/muleui",MuleUI);
    AddMQ2KeyBind("MQ2CHAT",DoMQ2ChatBind);
    bmStripFirstStmlLines=AddMQ2Benchmark("StripFirstStmlLines");
    LoadChatSettings();
}

PLUGIN_API VOID ShutdownPlugin()
{
    DebugSpewAlways("Shutting down MQ2ChatWnd");
    sPendingChat.clear();

    // Remove commands, macro parameters, hooks, etc.
    RemoveCommand("/muleui");
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
