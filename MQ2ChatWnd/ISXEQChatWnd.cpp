//
// ISXEQChatWnd
//
#pragma warning(disable:4996)
#include "../ISXEQClient.h"
#include "ISXEQChatWnd.h"

// The mandatory pre-setup function.  Our name is "ISXEQChatWnd", and the class is ISXEQChatWnd.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQChatWnd",ISXEQChatWnd);


struct ChatBuffer
{
    CHAR Text[MAX_STRING];
    ChatBuffer *pNext;
    ChatBuffer *pPrev;
};

ISInterface *pISInterface = NULL;

HISXSERVICE hPulseService = 0;
HISXSERVICE hMemoryService = 0;
HISXSERVICE hServicesService = 0;
HISXSERVICE hConsoleService = 0;

HISXSERVICE hEQChatService = 0;
HISXSERVICE hEQUIService = 0;
HISXSERVICE hEQGamestateService = 0;

void PulseService(bool Broadcast, unsigned int MSG, void *lpData);
void MemoryService(bool Broadcast, unsigned int MSG, void *lpData) {}
void ServicesService(bool Broadcast, unsigned int MSG, void *lpData);
void ConsoleService(bool Broadcast, unsigned int MSG, void *lpData);

class CMQChatWnd *MQChatWnd = NULL;
DWORD bmStripFirstStmlLines = 0;
DWORD PendingChatLines = 0;
ChatBuffer* pPendingChat = 0;
ChatBuffer* pPendingChatTail = 0;
CSemaphore ChatS;

CHAR szChatXMLSection[MAX_STRING] = {0};

#define MAX_CHAT_SIZE 700
#define LINES_PER_FRAME 3

int CMD_MQFont(int argc, char *argv[]);
VOID DoMQ2ChatBind(PCHAR Name,BOOL Down);
void SaveChatToXML(PCSIDLWND pWindow);
void CreateChatWindow();

class CMQChatWnd : public CCustomWnd
{
public:
    CMQChatWnd() : CCustomWnd("ChatWindow")
    {
        DebugSpew("CMQChatWnd()");

        SetWndNotification(CMQChatWnd);

        InputBox = (CTextEntryWnd*)GetChildItem("CWChatInput");
        InputBox->WindowStyle |= 0x800C0;
        InputBox->UnknownCW |= 0xFFFFFFFF;
        InputBox->SetMaxChars(512);

        OutputBox = (CStmlWnd*)GetChildItem("CWChatOutput");
        OutputBox->Clickable = 1;
        *(DWORD*)&(((PCHAR)OutputBox)[EQ_CHAT_HISTORY_OFFSET])=400;

        OutBoxLines = 0;
        AutoScroll = true;

        BitOff(WindowStyle,CWS_CLOSE);
        CloseOnESC = 0;

    }

    ~CMQChatWnd()
    {
    }

    int WndNotification(CXWnd *pWnd, unsigned int Message, void *unknown)
    {   
        if (pWnd == (CXWnd*)InputBox) {
            if (Message == XWM_HITENTER) {
                char szBuffer[2048];
                GetCXStr((PCXSTR)InputBox->InputText, szBuffer, 2047);
                if (szBuffer[0]) {
                    OutputBox->AppendSTML(szBuffer);
                    SetCXStr(&InputBox->InputText, "");
                    pISInterface->ExecuteCommand(szBuffer);
                }
                ((CXWnd*)InputBox)->ClrFocus();
            }
            else {
                DebugSpew("InputBox message %Xh, value: %Xh",Message,unknown);
            }
        }
        else if (pWnd == (CXWnd*)OutputBox) {
            if (Message == XWM_NEWVALUE) {
                SaveChatToXML((PCSIDLWND)MQChatWnd);
            }
            else {
                DebugSpew("OutputBox message %Xh, value: %Xh", Message, unknown);
            }
        }
        else if (pWnd == 0) {
            if (Message == XWM_CLOSE) {
                dShow = 1;
                return 1;
            }
        } else if (Message == XWM_LINK) {
            class CChatWindow *p = (class CChatWindow *)this;
            if (OutputBox != (CStmlWnd *)pWnd) {
                CStmlWnd *tmp;
                int ret;
                DebugSpew("MQ2ChatWnd: 0x%X, Msg: 0x%X, value: %Xh", pWnd, Message, unknown);
                DebugSpew("MQ2ChatWnd: pWnd 0x%x != OutputBox 0x%x\n", pWnd, OutputBox);
                tmp = OutputBox;
                OutputBox = (CStmlWnd *)pWnd;
                ret = p->WndNotification(pWnd, Message, unknown);
                OutputBox = tmp;
                return ret;
            }
            return p->WndNotification(pWnd, Message, unknown);
        } else {
            //DebugSpew("MQ2ChatWnd: 0x%X, Msg: 0x%X, value: %Xh",pWnd,Message,unknown);
        }
        return CSidlScreenWnd::WndNotification(pWnd,Message,unknown);
    };

    void SetChatFont(int size) // brainiac 12-12-2007
    {
        struct FONTDATA
        {
            DWORD NumFonts;
            PCHAR* Fonts; 
        };
        FONTDATA* Fonts;    // font array structure
        DWORD* SelFont;     // selected font

        // get fonts structure
        Fonts = (FONTDATA*)&(((char*)pWndMgr)[EQ_CHAT_FONT_OFFSET]);

        // check font array bounds and pointers
        if (size < 0 || size >= Fonts->NumFonts) {
            return;
        }
        if (Fonts->Fonts == NULL || MQChatWnd == NULL) {
            return;
        }

        //int Val2 = *(DWORD*)(Val[1] + size * 4);
        SelFont = (DWORD*)Fonts->Fonts[size];

        // Save the text, change the font, then restore the text
        CXStr str(MQChatWnd->OutputBox->GetSTMLText());
        ((CXWnd*)MQChatWnd->OutputBox)->SetFont(SelFont);
        ((CStmlWnd*)MQChatWnd->OutputBox)->SetSTMLText(str, 1, 0);
        ((CStmlWnd*)MQChatWnd->OutputBox)->ForceParseNow();
        // scroll to bottom of chat window
        ((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->VScrollMax);

        MQChatWnd->FontSize = size;
    }

    CTextEntryWnd *InputBox;
    CStmlWnd *OutputBox;
    DWORD OutBoxLines;
    DWORD FontSize;
    BOOL AutoScroll;
};

// Initialize is called by Inner Space when the extension should initialize.
bool ISXEQChatWnd::Initialize(ISInterface *p_ISInterface)
{   
    pISInterface = p_ISInterface;
    pISInterface->OpenSettings(XMLFileName);

    hPulseService = pISInterface->ConnectService(this, "Pulse", PulseService);
    hMemoryService = pISInterface->ConnectService(this, "Memory", MemoryService);
    hServicesService = pISInterface->ConnectService(this, "Services", ServicesService);
    hConsoleService = pISInterface->ConnectService(this, "Console", ConsoleService);

    pISInterface->AddCommand("MQFont",CMD_MQFont,true,false);
    AddMQ2KeyBind("MQ2CHAT",DoMQ2ChatBind);

    return true;
}

// shutdown sequence
void ISXEQChatWnd::Shutdown()
{
    if (MQChatWnd) {
        SaveChatToXML((PCSIDLWND)MQChatWnd);
        delete MQChatWnd;
        MQChatWnd = NULL;
    }
    pISInterface->UnloadSettings(XMLFileName);
    if (hConsoleService != 0) {
        pISInterface->DisconnectService(this, hConsoleService);
        hConsoleService = 0;
    }
    if (hPulseService != 0) {
        pISInterface->DisconnectService(this, hPulseService);
        hPulseService = 0;
    }
    if (hMemoryService) {
        pISInterface->DisconnectService(this, hMemoryService);
        hMemoryService = 0; 
    }
    if (hServicesService != 0) {
        pISInterface->DisconnectService(this, hServicesService);
        hServicesService = 0;
    }

    pISInterface->RemoveCommand("MQFont");
    RemoveMQ2KeyBind("MQ2CHAT");

    while (pPendingChat) {
        ChatBuffer *pNext = pPendingChat->pNext;
        delete pPendingChat;
        pPendingChat = pNext;
    }
    pPendingChatTail = 0;
    PendingChatLines = 0;
}

void PulseService(bool Broadcast, unsigned int MSG, void *lpData)
{
    if (MSG == PULSE_PULSE) {
        if (GetGameState() == GAMESTATE_CHARSELECT && !MQChatWnd) {
            CreateChatWindow();
        }
        if (MQChatWnd && PendingChatLines) {
            bool doscroll = (((CXWnd*)MQChatWnd->OutputBox)->VScrollPos == (MQChatWnd->OutputBox->VScrollMax));

            DWORD ThisPulse = PendingChatLines;
            if (ThisPulse > LINES_PER_FRAME) {
                ThisPulse = LINES_PER_FRAME;
            }
            PendingChatLines -= ThisPulse;
            MQChatWnd->OutBoxLines += ThisPulse;

            if (MQChatWnd->OutBoxLines > MAX_CHAT_SIZE) {
                DWORD Diff = (MQChatWnd->OutBoxLines - MAX_CHAT_SIZE) + LINES_PER_FRAME;
                MQChatWnd->OutBoxLines -= Diff;
                Benchmark(bmStripFirstStmlLines, MQChatWnd->OutputBox->StripFirstSTMLLines(Diff));
            }
            for (DWORD N = 0 ; N < ThisPulse ; N++) {
                DebugTry(MQChatWnd->OutputBox->AppendSTML( pPendingChat->Text));
                ChatBuffer *pNext = pPendingChat->pNext;
                delete pPendingChat;
                pPendingChat = pNext;
            }
            if (!pPendingChat) {
                pPendingChatTail = 0;
            }
            if (doscroll || MQChatWnd->AutoScroll) {
                DebugTry(((CXWnd*)MQChatWnd->OutputBox)->SetVScrollPos(MQChatWnd->OutputBox->VScrollMax));
            }
        }
    }
}

void EQUIService(bool Broadcast, unsigned int MSG, void *lpData)
{
    if (MSG == UISERVICE_CLEANUP) {
        if (MQChatWnd != NULL) {
            SaveChatToXML((PCSIDLWND)MQChatWnd);
            delete MQChatWnd;
            MQChatWnd = NULL;
        }
    }
    else if (MSG == UISERVICE_RELOAD) {
        if (MQChatWnd != NULL) {
            MQChatWnd->dShow = 1;
        }
    }
}

void EQGamestateService(bool Broadcast, unsigned int MSG, void *lpData)
{
    if (MSG == GAMESTATESERVICE_CHANGED) {
        DWORD GameState = (DWORD)lpData;
        if (GameState == GAMESTATE_CHARSELECT) {
            AddMQ2KeyBind("MQ2CSCHAT", DoMQ2ChatBind);
            KeyCombo Combo;
            ParseKeyCombo("/", Combo);
            SetMQ2KeyBind("MQ2CSCHAT", 0, Combo);
        }
        else {
            RemoveMQ2KeyBind("MQ2CSCHAT");
            if (GameState == GAMESTATE_INGAME && !MQChatWnd) {
                // we entered the game, set up shop
                DebugTry(CreateChatWindow());
            }
        }
    }
}

void EQChatService(bool Broadcast, unsigned int MSG, void *lpData)
{
    if (MSG == CHATSERVICE_OUTGOING) {
        // same as OnWriteChatColor
        if (!MQChatWnd) {
            EQGamestateService(false, GAMESTATESERVICE_CHANGED, (void*)gGameState);
            if (!MQChatWnd) {
                return; 
            }
        }
        MQChatWnd->dShow = 1;
        _EQChat* pChat = (_EQChat*)lpData;

        PFILTER pFilter = gpFilters; 
        while (pFilter) { 
            if (!pFilter->pEnabled || (*pFilter->pEnabled)) { 
                if (!strnicmp(pChat->Line,pFilter->FilterText,pFilter->Length)) {
                    return;
                }
            } 
            pFilter = pFilter->pNext; 
        } 

        DWORD Color = pChatManager->GetRGBAFromIndex(pChat->Color);
        CHAR szProcessed[MAX_STRING];

        MQToSTML(pChat->Line, szProcessed, MAX_STRING, Color);
        strcat(szProcessed, "<br>");
        CXStr NewText(szProcessed);
        DebugTry(ConvertItemTags(NewText, 0));

        CLock L(&ChatS,1);
        ChatBuffer *pNewBuffer = new ChatBuffer;
        GetCXStr(NewText.Ptr, pNewBuffer->Text, MAX_STRING);
        pNewBuffer->pPrev = pPendingChatTail;
        pNewBuffer->pNext = 0;
        if (pPendingChatTail) {
            pPendingChatTail->pNext=pNewBuffer;
        } else {
            pPendingChat = pNewBuffer;
        }
        pPendingChatTail = pNewBuffer;
        PendingChatLines++;
    }
}

void ConsoleService(bool Broadcast, unsigned int MSG, void *lpData)
{
    if (MSG != CONSOLE_OUTPUT_WITHCODES) {
        return;
    }
    // same as OnWriteChatColor
    if (!MQChatWnd) {
        EQGamestateService(false, GAMESTATESERVICE_CHANGED, (void*)gGameState);
        if (!MQChatWnd) {
            return;
        }
    }
    MQChatWnd->dShow = 1;

    PCHAR pConsOutput = (PCHAR)lpData;
    PFILTER pFilter = gpFilters;

    while (pFilter) {
        if (!pFilter->pEnabled || (*pFilter->pEnabled)) {
            if (!strnicmp(pConsOutput, pFilter->FilterText, pFilter->Length)) {
                return;
            }
        }
        pFilter = pFilter->pNext;
    }
    DWORD Color = pChatManager->GetRGBAFromIndex(USERCOLOR_DEFAULT);

    CHAR szProcessed[MAX_STRING];
    MQToSTML(pConsOutput, szProcessed, MAX_STRING, Color);
    strcat(szProcessed,"<br>");
    CXStr NewText(szProcessed);
    DebugTry(ConvertItemTags(NewText, 0));

    CLock L(&ChatS,1);

    ChatBuffer *pNewBuffer = new ChatBuffer;
    GetCXStr(NewText.Ptr, pNewBuffer->Text, MAX_STRING);
    pNewBuffer->pPrev = pPendingChatTail;
    pNewBuffer->pNext = 0;
    if (pPendingChatTail) {
        pPendingChatTail->pNext = pNewBuffer;
    }
    else {
        pPendingChat = pNewBuffer;
    }
    pPendingChatTail = pNewBuffer;
    PendingChatLines++;
}

// This uses the Services service to connect to ISXEQ services
void ServicesService(bool Broadcast, unsigned int MSG, void *lpData)
{
    PCHAR Name = (PCHAR)lpData; 
    if (MSG == SERVICES_ADDED) {
        if (!stricmp(Name, "EQ UI Service")) {
            hEQUIService = pISInterface->ConnectService(pExtension, Name, EQUIService);
        }
        else if (!stricmp(Name, "EQ Gamestate Service")) {
            hEQGamestateService = pISInterface->ConnectService(pExtension, Name, EQGamestateService);
        }
        else if (!stricmp(Name, "EQ Chat Service")) {
            hEQChatService = pISInterface->ConnectService(pExtension, Name, EQChatService);
        }
    }
    else if (MSG == SERVICES_REMOVED) {
        if (!stricmp(Name,"EQ UI Service")) {
            if (hEQUIService != 0) {
                pISInterface->DisconnectService(pExtension, hEQUIService);
                hEQUIService = 0;
            }
        }
        else if (!stricmp(Name, "EQ Gamestate Service")) {
            if (hEQGamestateService != 0) {
                pISInterface->DisconnectService(pExtension, hEQGamestateService);
                hEQGamestateService = 0;
            }
        }
        else if (!stricmp(Name, "EQ Chat Service")) {
            if (hEQChatService) {
                pISInterface->DisconnectService(pExtension, hEQChatService);
                hEQChatService = 0;
            }
        }
    }
}

#define GetIntSetting(name,var,_default_) \
    if (pISInterface->GetSettingi(XMLFileName, szChatXMLSection, name, iTemp)) { \
    var = iTemp; \
    } else { \
    var = _default_; \
    pISInterface->SetSettingi(XMLFileName,szChatXMLSection, name, _default_); \
    }

void LoadChatFromXML(PCSIDLWND pWindow)
{
    sprintf(szChatXMLSection,"%s.%s", EQADDR_SERVERNAME, ((PCHARINFO)pCharData)->Name);

    char Buffer[MAX_STRING] = {0};
    int iTemp = 0;

    GetIntSetting("Top", pWindow->Location.top, 10);
    GetIntSetting("Bottom", pWindow->Location.bottom, 210);
    if (pWindow->Location.top == pWindow->Location.bottom) {
        pWindow->Location.bottom += 200;
        pISInterface->SetSettingi(XMLFileName,szChatXMLSection, "Bottom", pWindow->Location.bottom);
    }
    GetIntSetting("Left", pWindow->Location.left, 10);
    GetIntSetting("Right", pWindow->Location.right, 410);
    if (pWindow->Location.left == pWindow->Location.right) {
        pWindow->Location.right += 400;
        pISInterface->SetSettingi(XMLFileName,szChatXMLSection, "Right", pWindow->Location.right);
    }   
    GetIntSetting("Locked", pWindow->Locked, 0);
    GetIntSetting("Fades", pWindow->Fades,1);
    GetIntSetting("Delay", pWindow->TimeMouseOver, 2000);
    GetIntSetting("Duration", pWindow->FadeDuration, 500);
    GetIntSetting("Alpha", pWindow->Alpha, 255);
    GetIntSetting("FadeToAlpha", pWindow->FadeToAlpha, 255);
    GetIntSetting("BGType", pWindow->BGType, 1);
    GetIntSetting("BGTint.red", pWindow->BGColor.R, 255);
    GetIntSetting("BGTint.green", pWindow->BGColor.G, 255);
    GetIntSetting("BGTint.blue", pWindow->BGColor.B, 255);
    GetIntSetting("AutoScroll", MQChatWnd->AutoScroll, 1);

    GetIntSetting("FontSize", MQChatWnd->FontSize, 4);
    MQChatWnd->SetChatFont(MQChatWnd->FontSize);

    if (!pISInterface->GetSetting(XMLFileName, szChatXMLSection, "Title", Buffer, sizeof(Buffer))) {
        strcpy(Buffer, "ISXEQ");
        pISInterface->SetSetting(XMLFileName, szChatXMLSection, "Title", "ISXEQ");
    }
    SetCXStr(&pWindow->WindowText, Buffer);
    pISInterface->SaveSettings(XMLFileName);
}
#undef GetIntSetting

void SaveChatToXML(PCSIDLWND pWindow)
{   
    char szTemp[MAX_STRING] = {0};
    GetCXStr(pWindow->WindowText, szTemp);
    pISInterface->SetSetting(XMLFileName, szChatXMLSection, "Title", szTemp);
    if (pWindow->Minimized) {
        pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Top", pWindow->OldLocation.top);
        pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Bottom", pWindow->OldLocation.bottom);
        pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Left", pWindow->OldLocation.left);
        pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Right", pWindow->OldLocation.right);
    } else {
        pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Top", pWindow->Location.top);
        pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Bottom", pWindow->Location.bottom);
        pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Left", pWindow->Location.left);
        pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Right", pWindow->Location.right);
    }
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Locked", pWindow->Locked);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Fades", pWindow->Fades);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Delay", pWindow->TimeMouseOver);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Duration", pWindow->FadeDuration);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "Alpha", pWindow->Alpha);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "FadeToAlpha", pWindow->FadeToAlpha);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "BGType", pWindow->BGType);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "BGTint.red", pWindow->BGColor.R);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "BGTint.green", pWindow->BGColor.G);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "BGTint.blue", pWindow->BGColor.B);
    pISInterface->SetSettingi(XMLFileName, szChatXMLSection, "FontSize", MQChatWnd->FontSize);

    pISInterface->SaveSettings(XMLFileName);
}

void CreateChatWindow()
{
    DebugSpew("MQ2ChatWnd::CreateChatWindow()");
    if (MQChatWnd) {
        return;
    }
    MQChatWnd = new CMQChatWnd();
    if (!MQChatWnd) {
        return;
    }
    LoadChatFromXML((PCSIDLWND)MQChatWnd);
    //  SaveChatToXML((PCSIDLWND)MQChatWnd); // A) we're masochists, B) this creates the file if its not there..
}

VOID DoMQ2ChatBind(PCHAR Name, BOOL Down)
{
    if (!Down) {
        if (MQChatWnd != NULL) {
            CXRect rect = ((CXWnd*)MQChatWnd->InputBox)->GetScreenRect();
            CXPoint pt = rect.CenterPoint();
            ((CXWnd*)MQChatWnd->InputBox)->SetWindowTextA(CXStr(""));
            ((CXWnd*)MQChatWnd->InputBox)->HandleLButtonDown(&pt, 0);
        }
    }
}

int CMD_MQFont(int argc, char *argv[])
{
    if (MQChatWnd != NULL) {
        if (argc > 1 && MQChatWnd) {
            int size = atoi(argv[1]);
            if (size < 0 || size > 10) {
                printf("Usage: %s 0-10", argv[0]);
                return 0;
            }
            MQChatWnd->SetChatFont(size);
            SaveChatToXML((PCSIDLWND)MQChatWnd);
        }
    }
    return 0;
}
