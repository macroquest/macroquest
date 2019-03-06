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
CHAR szChatINISection[MAX_STRING]={0}; 
bool bAutoScroll=true; 
bool bNoCharSelect=false; 
bool bSaveByChar=true; 

class CMQChatWnd; 
CMQChatWnd *MQChatWnd=0; 
class CMQChatWnd : public CCustomWnd 
{
public:
	CTextEntryWnd* InputBox;
    CStmlWnd* OutputBox;
    CXWnd* OutWnd;
    struct _CSIDLWND* OutStruct;
private:
    std::vector<std::string> sCmdHistory;
    int iCurrentCmd;
public: 
    CMQChatWnd(CXStr *Template):CCustomWnd(Template) 
    { 
        DebugSpew("CMQChatWnd()");
        SetWndNotification(CMQChatWnd);

		BGColor = 0xFF000000;//black background
        InputBox=(CTextEntryWnd*)GetChildItem("CW_ChatInput"); 
        InputBox->WindowStyle|=0x800C0; 
        BitOff(WindowStyle,CWS_CLOSE); 
        BitOn(WindowStyle,CWS_TITLE); 
        BitOn(WindowStyle,CWS_CLIENTMOVABLE); 
		
        InputBox->CRNormal=0xFFFFFFFF;//we want a white cursor 
        InputBox->SetMaxChars(512); 
        OutputBox=(CStmlWnd*)GetChildItem("CW_ChatOutput"); 
        OutStruct=(_CSIDLWND*)GetChildItem("CW_ChatOutput");
		//fix for the 0 parent crash at charselect when clicking the children...
		//wow it only took us 13 years to fix that one... -eqmule
		OutStruct->pParentWindow = (_CSIDLWND *)this;
		OutputBox->pParentWindow = (_CSIDLWND *)this;
		InputBox->pParentWindow = (_CSIDLWND *)this;
        OutWnd=(CXWnd*)OutputBox;
        OutBoxLines=0;
		OutputBox->MaxLines = 0x190;
       //(DWORD*)&(((PCHAR)OutputBox)[EQ_CHAT_HISTORY_OFFSET])=0x190; 
        OutputBox->Clickable=1; 
        iCurrentCmd=-1;
		ZLayer = 1; // Make this the topmost window (we will leave it as such for charselect, and allow it to move to background ingame)
    } 
    ~CMQChatWnd() 
    { 
    } 
    int WndNotification(CXWnd *pWnd, unsigned int Message, void *data) 
    {    
        if (pWnd==(CXWnd*)InputBox) 
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
	                    DoCommand(((PCHARINFO)pCharData)->pSpawn,szBuffer); 
                    }
                    else
                    {
	                    Echo(((PCHARINFO)pCharData)->pSpawn,szBuffer); 
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
        else if (pWnd==0) 
        { 
            if (Message==XWM_CLOSE) 
            { 
                dShow=1; 
                return 1; 
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
        DebugTry(((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->VScrollMax)); 

        MQChatWnd->FontSize=size; 
    }; 
    DWORD OutBoxLines; 
    DWORD FontSize; 
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
    CHAR szTemp[MAX_STRING]={0}; 

    LoadChatSettings(); 

    sprintf_s(szChatINISection,"%s.%s",EQADDR_SERVERNAME,((PCHARINFO)pCharData)->Name); 
    if (!bSaveByChar) sprintf_s(szChatINISection,"Default"); 

    pWindow->Location.top      = GetPrivateProfileInt(szChatINISection,"ChatTop",       10,INIFileName); 
    pWindow->Location.bottom   = GetPrivateProfileInt(szChatINISection,"ChatBottom",   210,INIFileName); 
    pWindow->Location.left     = GetPrivateProfileInt(szChatINISection,"ChatLeft",      10,INIFileName); 
    pWindow->Location.right    = GetPrivateProfileInt(szChatINISection,"ChatRight",    410,INIFileName); 
    pWindow->Locked            = (GetPrivateProfileInt(szChatINISection,"Locked",         0,INIFileName) ? true:false); 
    pWindow->Fades             = (GetPrivateProfileInt(szChatINISection,"Fades",          0,INIFileName) ? true:false); 
    pWindow->FadeDelay		   = GetPrivateProfileInt(szChatINISection,"Delay",       2000,INIFileName); 
    pWindow->FadeDuration      = GetPrivateProfileInt(szChatINISection,"Duration",     500,INIFileName); 
    pWindow->Alpha             = GetPrivateProfileInt(szChatINISection,"Alpha",        255,INIFileName); 
    pWindow->FadeToAlpha       = GetPrivateProfileInt(szChatINISection,"FadeToAlpha",  255,INIFileName); 
    pWindow->BGType            = GetPrivateProfileInt(szChatINISection,"BGType",         1,INIFileName); 
	ARGBCOLOR col = { 0 };
	col.ARGB = pWindow->BGColor;
    col.A         = GetPrivateProfileInt(szChatINISection,"BGTint.alpha",     255,INIFileName); 
    col.R         = GetPrivateProfileInt(szChatINISection,"BGTint.red",     0,INIFileName); 
    col.G         = GetPrivateProfileInt(szChatINISection,"BGTint.green",   0,INIFileName); 
    col.B         = GetPrivateProfileInt(szChatINISection,"BGTint.blue",    0,INIFileName); 
	pWindow->BGColor = col.ARGB;
    MQChatWnd->SetChatFont(GetPrivateProfileInt(szChatINISection,"FontSize",4,INIFileName)); 
    GetPrivateProfileString(szChatINISection,"WindowTitle","MQ",szTemp,MAX_STRING,INIFileName); 
    SetCXStr(&pWindow->WindowText,szTemp); 
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
    CHAR szTemp[MAX_STRING]={0}; 
    WritePrivateProfileString("Settings","AutoScroll",   bAutoScroll?"on":"off",INIFileName); 
    WritePrivateProfileString("Settings","NoCharSelect", bNoCharSelect?"on":"off",INIFileName); 
    WritePrivateProfileString("Settings","SaveByChar",   bSaveByChar?"on":"off",INIFileName); 

    if (pWindow->Minimized) 
    { 
        WritePrivateProfileString(szChatINISection,"ChatTop",    SafeItoa(pWindow->OldLocation.top,    szTemp,10),INIFileName); 
        WritePrivateProfileString(szChatINISection,"ChatBottom", SafeItoa(pWindow->OldLocation.bottom, szTemp,10),INIFileName); 
        WritePrivateProfileString(szChatINISection,"ChatLeft",   SafeItoa(pWindow->OldLocation.left,   szTemp,10),INIFileName); 
        WritePrivateProfileString(szChatINISection,"ChatRight",  SafeItoa(pWindow->OldLocation.right,  szTemp,10),INIFileName); 
    } 
    else 
    { 
        WritePrivateProfileString(szChatINISection,"ChatTop",    SafeItoa(pWindow->Location.top,    szTemp,10),INIFileName); 
        WritePrivateProfileString(szChatINISection,"ChatBottom", SafeItoa(pWindow->Location.bottom, szTemp,10),INIFileName); 
        WritePrivateProfileString(szChatINISection,"ChatLeft",   SafeItoa(pWindow->Location.left,   szTemp,10),INIFileName); 
        WritePrivateProfileString(szChatINISection,"ChatRight",  SafeItoa(pWindow->Location.right,  szTemp,10),INIFileName); 
    } 
    WritePrivateProfileString(szChatINISection,"Locked",         SafeItoa(pWindow->Locked,          szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"Fades",          SafeItoa(pWindow->Fades,           szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"Delay",          SafeItoa(pWindow->FadeDelay,       szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"Duration",       SafeItoa(pWindow->FadeDuration,    szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"Alpha",          SafeItoa(pWindow->Alpha,           szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"FadeToAlpha",    SafeItoa(pWindow->FadeToAlpha,     szTemp,10),INIFileName); 
	ARGBCOLOR col = { 0 };
	col.ARGB = pWindow->BGColor;
    WritePrivateProfileString(szChatINISection,"BGType",         SafeItoa(pWindow->BGType,          szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"BGTint.alpha",    SafeItoa(col.A,       szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"BGTint.red",     SafeItoa(col.R,       szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"BGTint.green",   SafeItoa(col.G,       szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"BGTint.blue",    SafeItoa(col.B,       szTemp,10),INIFileName); 
    WritePrivateProfileString(szChatINISection,"FontSize",       SafeItoa(MQChatWnd->FontSize,      szTemp,10),INIFileName); 
    
	GetCXStr(pWindow->WindowText,szTemp, MAX_STRING);
    WritePrivateProfileString(szChatINISection,"WindowTitle",szTemp,INIFileName); 
} 

VOID CreateChatWindow() 
{ 
    DebugSpew("MQ2ChatWnd::CreateChatWindow()"); 
    if (MQChatWnd) 
    { 
        return; 
    } 
    class CXStr ChatWnd("ChatWindow"); 
    MQChatWnd = new CMQChatWnd(&ChatWnd); 
    if (!MQChatWnd) 
    { 
        return; 
    } 
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
        sprintf_s(out,"Style 0x%X",MQChatWnd->WindowStyle); 
        WriteChatColor(out); 
        return; 
    } 
    if (szLine[0]=='!') 
    { 
        int TurnOff = 0; 
        if(sscanf_s(&szLine[1],"%x",&TurnOff)) {
			//well we set it anyway i guess...
		}
		BitOff(MQChatWnd->WindowStyle, TurnOff);
    } 
    else 
    { 
        int TurnOn = 0; 
        if(sscanf_s(&szLine[0],"%x",&TurnOn)) {
			//hmm can error handle i guess
		}
        BitOn(MQChatWnd->WindowStyle,TurnOn); 
    } 
    char out[256]; 
    sprintf_s(out,"Style 0x%X",MQChatWnd->WindowStyle); 
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
        ((CXWnd*)MQChatWnd)->OnMinimizeBox(); 
    } 
} 

VOID SetChatTitle(PSPAWNINFO pChar, PCHAR Line)
{
	if (MQChatWnd) 
    {
		SetCXStr(&MQChatWnd->WindowText,Line); 
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
    DebugTry(CreateChatWindow()); 
} 

PLUGIN_API VOID OnCleanUI() 
{ 
    DebugSpewAlways("MQ2ChatWnd::OnCleanUI()"); 
    // destroy chatwnd before server select & while reloading UI 
    DestroyChatWnd(); 
} 

PLUGIN_API VOID SetGameState(DWORD GameState) 
{ 
    DebugSpew("MQ2ChatWnd::SetGameState()"); 
    if (GameState==GAMESTATE_CHARSELECT) 
    { 
        if (bNoCharSelect) 
        { 
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
            DebugTry(CreateChatWindow()); 
        } 
    } 
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
    MQChatWnd->dShow=1; 
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
    Color=pChatManager->GetRGBAFromIndex(Color); 
	CHAR szProcessed[MAX_STRING] = { 0 };
	
    int pos = MQToSTML(Line,szProcessed,MAX_STRING-4,Color); 
	try {
		strcat_s(szProcessed, "<br>");//we left room for this above...
		CXStr NewText(szProcessed);
		DebugTry(ConvertItemTags(NewText, FALSE));
		sPendingChat.push_back(NewText.Ptr->Text);
	} catch (...) {
		Sleep(0);
	}
    return 0; 
} 

PLUGIN_API VOID OnPulse() 
{ 
    if (gGameState==GAMESTATE_CHARSELECT && !MQChatWnd && !bNoCharSelect) 
    { 
        CreateChatWindow(); 
    } 
	//if (CXWnd *krwnd = FindMQ2Window("TaskOverlayWnd")) {
	//	Sleep(0);
	//}
    if (MQChatWnd) 
    { 
		switch (gGameState)
		{
			case GAMESTATE_CHARSELECT: 
			{
				if (MQChatWnd->ZLayer != 1)
					MQChatWnd->ZLayer = 1;
				break;
			}
			case GAMESTATE_INGAME:
			{
				if (MQChatWnd->ZLayer != 0)
					MQChatWnd->ZLayer = 0;
				break;
			} 
		}
        if(!sPendingChat.empty()) 
        { 
            // set 'old' to current 
            ulOldVScrollPos=MQChatWnd->OutputBox->VScrollPos; 

            // scroll down if autoscroll enabled, or current position is the bottom of chatwnd 
            bool bScrollDown=bAutoScroll?true:(MQChatWnd->OutputBox->VScrollPos==MQChatWnd->OutputBox->VScrollMax?true:false); 

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
                DebugTry(((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->VScrollMax)); 
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
						GetCXStr(MQChatWnd->WindowText, DataTypeTemp);
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
				GetCXStr(MQChatWnd->WindowText, Destination);
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
			pOptionsWnd->BGColor = 0xFF000000;
		}
		if (pTargetWnd) {
			pTargetWnd->BGColor = 0xFF000000;
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
					if (hbtn && hbtn->pButtonWnd && hbtn->pButtonWnd->DrawTemplate) {
						PCBUTTONDRAWTEMPLATE btemp = (PCBUTTONDRAWTEMPLATE)hbtn->pButtonWnd->DrawTemplate;
						Sleep(0);
					}
					//btn->DrawTemplate
					if (CXWnd*child2 = child->GetChildItem("HB_SpellGem")) {
						child2->BGColor = 0xFF000000;
					}
					if (CXWnd*child2 = child->GetChildItem("HB_InvSlot")) {
						if (CXWnd*child3 = child2->GetChildItem("A_RecessedBox")) {
							child3->BGColor = 0xFF000000;
						}
						child2->BGColor = 0xFF000000;
					}
					if (CXWnd*child2 = child->GetChildItem("A_HotButton1Normal")) {
						child2->BGColor = 0xFF000000;
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
					child->BGColor = 0xFF000000;
				}
				wnd->CRNormal = 0xFF000000;
				wnd->BGColor = 0xFF000000;
			}
			if (CXWnd*wnd = FindMQ2Window("HotButtonWnd2")) {
				if (CXWnd*child = wnd->GetChildItem("HB_Button1")) {
					child->BGColor = 0xFF000000;
				}
				wnd->CRNormal = 0xFF000000;
				wnd->BGColor = 0xFF000000;
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
