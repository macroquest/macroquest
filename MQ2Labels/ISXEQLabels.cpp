//
// ISXEQLabels

#pragma warning(disable:4996)
#include "../ISXEQClient.h"
#include "ISXEQLabels.h"

// The mandatory pre-setup function.  Our name is "ISXEQLabels", and the class is ISXEQLabels.
// This sets up a "ModulePath" variable which contains the path to this module in case we want it,
// and a "PluginLog" variable, which contains the path and filename of what we should use for our
// debug logging if we need it.  It also sets up a variable "pExtension" which is the pointer to
// our instanced class.
ISXPreSetup("ISXEQLabels",ISXEQLabels);

// PLEASE keep this array limited.  Recommend using 9999 and tooltips.
struct _ID_PMP
{ DWORD ID;PCHAR PMP; }
Id_PMP[] = {
    // 1000-1999: $char()
    {1000,   "${Me.CurrentMana}"},
    {1001,   "${Me.MaxMana}"},
    {1002,   "${Me.State}"},
    {1003,   "${Me.Speed}"},
    {1004,   "${Me.Heading}"},
    {1005,   "${Me.X}"},
    {1006,   "${Me.Y}"},
    {1007,   "${Me.Z}"},
    {1008,   "${Me.Dar}"},
    {1009,   "${Me.Cash}"},
    {1010,   "${Me.CashBank})"},
    {1011,   "${Me.PlatinumBank}"},
    {1012,   "${Me.PlatinumShared}"},
    {1013,   "${Me.GoldBank}"},
    {1014,   "${Me.SilverBank}"},
    {1015,   "${Me.CopperBank}"},

    // 2000-2999: $target()
    {2000,   "${Target.Level}"},
    {2001,   "${Target.Class}"},
    {2002,   "${Target.Race}"},
    {2003,   "${Target.Distance}"},
    {2004,   "$target(lastattacked)"},
    {2005,   "${Target.State}"},
    {2006,   "${Target.X}"},
    {2007,   "${Target.Y}"},
    {2008,   "${Target.Z}"},
    {2009,   "${Target.Heading}"},
    {2010,   "${Target.Speed}"},
    {2011,  "${Target.ID}"},

    // 3000-3999: misc
    {3000,   "${Zone}"},
    {3001,   "---"},
    {3002,   "${Me.Bound}"},
    {3003,   "${Time.Time24}"},
    {3004,   "${Time.Hour}"},
    {3005,   "${Time.Minute}"},
    {3006,   "${Time.Second}"},
    {3007,   "${Time.Date}"},
    {3008,   "${Time.Year}"},
    {3009,   "${Time.Month}"},
    {3010,   "${Time.Day}"},
    {3011,   "${If[${Spawn[gm].ID},TRUE,FALSE]}"},
    {3012,   "${Me.FreeInventory}"},

    // 9999: custom (TooltipReference)
    {9999,   "BrokenParser" },

    {-1,NULL}
}; 


// CSidlManager::CreateLabel 0x5F2470

// the tool tip is already copied out of the 
// in class CControlTemplate.  use this struct
// to mock up the class, so we don't have to
// worry about class instatiation and crap

struct _CControl {
    /*0x000*/    BYTE Fluff[0x94];
    /*0x06c*/ /* CXSTR * ToolTipReference */
    /*0x094*/    CXSTR * EQType;
};

// optimize off because the tramp looks blank to the compiler
// and it doesn't respect the fact the it will be a real routine
#pragma optimize ("g", off)

class CSidlManagerHook {
public:
    class CXWnd * CreateLabel_Trampoline(class CXWnd *, struct _CControl *);
    class CXWnd * CreateLabel_Detour(class CXWnd *CWin, struct _CControl *CControl)
    {
        CSIDLWND *p;
        class CXWnd *tmp = CreateLabel_Trampoline(CWin, CControl);
        p = (CSIDLWND *)tmp;
        if (CControl->EQType) {
            *((DWORD *)&p->SidlPiece) = atoi(CControl->EQType->Text);
        } else {
            *((DWORD *)&p->SidlPiece) = 0;
        }

        return tmp;
    }
};

DETOUR_TRAMPOLINE_EMPTY(class CXWnd * CSidlManagerHook::CreateLabel_Trampoline(class CXWnd *, struct _CControl *));

#pragma optimize ("g", on)

class CLabelHook {
public:
    VOID Draw_Trampoline(VOID);
    VOID Draw_Detour(VOID)
    {
        PCSIDLWND pThisLabel;
        __asm {mov [pThisLabel], ecx};
        //          (PCSIDLWND)this;
        Draw_Trampoline();
        CHAR Buffer[MAX_STRING] = {0};
        BOOL Found=FALSE;
        DWORD index;

        if ((DWORD)pThisLabel->SidlPiece==9999) {
            if (!pThisLabel->XMLToolTip) {
                strcpy(Buffer,"BadCustom");
                Found=TRUE;
            } else {
                //strcpy(Buffer,&pThisLabel->XMLToolTip->Text[0]);
                STMLToPlainText(&pThisLabel->XMLToolTip->Text[0],Buffer);
                ParseMacroParameter(((PCHARINFO)pCharData)->pSpawn,Buffer);
                if (!strcmp(Buffer,"NULL"))
                    Buffer[0]=0;
                Found=TRUE;
            }
        } else if ((DWORD)pThisLabel->SidlPiece>=1000) {
            for (index=0;Id_PMP[index].ID>0 && !Found;index++) {
                if (Id_PMP[index].ID==(DWORD)pThisLabel->SidlPiece) {
                    strcpy(Buffer,Id_PMP[index].PMP);
                    ParseMacroParameter(((PCHARINFO)pCharData)->pSpawn,Buffer);
                    if (!strcmp(Buffer,"NULL"))
                        Buffer[0]=0;
                    Found=TRUE;
                }
            }
        }
        if (Found) SetCXStr(&(pThisLabel->WindowText),Buffer);
    }
}; 

DETOUR_TRAMPOLINE_EMPTY(VOID CLabelHook::Draw_Trampoline(VOID));

BOOL StealNextGauge=FALSE;
DWORD NextGauge=0;

DETOUR_TRAMPOLINE_EMPTY(int GetGaugeValueFromEQ_Trampoline(int,class CXStr *,bool *));
int GetGaugeValueFromEQ_Hook(int A,class CXStr *B,bool *C)
{
    if (StealNextGauge)
        return NextGauge;
    return GetGaugeValueFromEQ_Trampoline(A,B,C);
}

class CGaugeHook
{
public:
    VOID Draw_Trampoline(VOID);
    VOID Draw_Detour(VOID)
    {
        PCSIDLWND pThisGauge;
        __asm {mov [pThisGauge], ecx};
        StealNextGauge=false;
        if ((DWORD)pThisGauge->SidlPiece==9999)
        {
            StealNextGauge=true;
            CHAR Buffer[MAX_STRING]={0};
            STMLToPlainText(&pThisGauge->XMLToolTip->Text[0],Buffer);
            ParseMacroParameter(((PCHARINFO)pCharData)->pSpawn,Buffer);
            NextGauge=atoi(Buffer);
        }
        Draw_Trampoline();
    }
};
DETOUR_TRAMPOLINE_EMPTY(VOID CGaugeHook::Draw_Trampoline(VOID));

// Basic LavishScript datatypes, these get retrieved on startup by our initialize function, so we can
// use them in our Top-Level Objects or custom datatypes
LSType *pStringType=0;
LSType *pIntType=0;
LSType *pBoolType=0;
LSType *pFloatType=0;
LSType *pTimeType=0;
LSType *pByteType=0;

ISInterface *pISInterface=0;
HISXSERVICE hPulseService=0;
HISXSERVICE hMemoryService=0;
HISXSERVICE hServicesService=0;

HISXSERVICE hEQChatService=0;
HISXSERVICE hEQUIService=0;
HISXSERVICE hEQGamestateService=0;
HISXSERVICE hEQSpawnService=0;
HISXSERVICE hEQZoneService=0;

// Forward declarations of callbacks
void __cdecl PulseService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData);
void __cdecl ServicesService(bool Broadcast, unsigned int MSG, void *lpData);


// Initialize is called by Inner Space when the extension should initialize.
bool ISXEQLabels::Initialize(ISInterface *p_ISInterface)
{    pISInterface=p_ISInterface;

// retrieve basic ISData types
pStringType=pISInterface->FindLSType("string");
pIntType=pISInterface->FindLSType("int");
pBoolType=pISInterface->FindLSType("bool");
pFloatType=pISInterface->FindLSType("float");
pTimeType=pISInterface->FindLSType("time");
pByteType=pISInterface->FindLSType("byte");


pISInterface->OpenSettings(XMLFileName);
LoadSettings();

ConnectServices();

RegisterCommands();
RegisterAliases();
RegisterDataTypes();
RegisterTopLevelObjects();
RegisterServices();

EzDetour(CLabel__Draw,&CLabelHook::Draw_Detour,&CLabelHook::Draw_Trampoline);
EzDetour(CSidlManager__CreateLabel,&CSidlManagerHook::CreateLabel_Detour,&CSidlManagerHook::CreateLabel_Trampoline);
// currently in testing:
//    EasyClassDetour(CGauge__Draw,CGaugeHook,Draw_Detour,VOID,(VOID),Draw_Trampoline);
//    EasyDetour(__GetGaugeValueFromEQ,GetGaugeValueFromEQ_Hook,int,(int,class CXStr *,bool *),GetGaugeValueFromEQ_Trampoline);
WriteChatf("ISXEQLabels Loaded");
return true;
}

// shutdown sequence
void ISXEQLabels::Shutdown()
{
    RemoveDetour(CLabel__Draw);
    RemoveDetour(CSidlManager__CreateLabel);
    //RemoveDetour(CGaugeWnd__Draw); 
    //RemoveDetour(__GetGaugeValueFromEQ); 

    // save settings, if you changed them and want to save them now.  You should normally save
    // changes immediately.
    //pISInterface->SaveSettings(XMLFileName);

    pISInterface->UnloadSettings(XMLFileName);

    DisconnectServices();

    UnRegisterServices();
    UnRegisterTopLevelObjects();
    UnRegisterDataTypes();
    UnRegisterAliases();
    UnRegisterCommands();
}


void ISXEQLabels::ConnectServices()
{
    // connect to any services.  Here we connect to "Pulse" which receives a
    // message every frame (after the frame is displayed) and "Memory" which
    // wraps "detours" and memory modifications
    hMemoryService=pISInterface->ConnectService(this,"Memory",MemoryService);
}

void ISXEQLabels::RegisterCommands()
{
    // add any commands
    //    pISInterface->AddCommand("MyCommand",MyCommand,true,false);

}

void ISXEQLabels::RegisterAliases()
{
    // add any aliases
}

void ISXEQLabels::RegisterDataTypes()
{
    // add any datatypes
    // pMyType = new MyType;
    // pISInterface->AddLSType(*pMyType);
}

void ISXEQLabels::RegisterTopLevelObjects()
{
    // add any Top-Level Objects
    //    pISInterface->AddTopLevelObject("MapSpawn",tloMapSpawn);
}

void ISXEQLabels::RegisterServices()
{
    // register any services.  Here we demonstrate a service that does not use a
    // callback
    // set up a 1-way service (broadcast only)
    //    hISXEQLabelsService=pISInterface->RegisterService(this,"ISXEQLabels Service",0);
    // broadcast a message, which is worthless at this point because nobody will receive it
    // (nobody has had a chance to connect)
    //    pISInterface->ServiceBroadcast(this,hISXEQLabelsService,ISXSERVICE_MSG+1,0);

}

void ISXEQLabels::DisconnectServices()
{
    // gracefully disconnect from services
    if (hMemoryService)
    {
        pISInterface->DisconnectService(this,hMemoryService);
        // memory modifications are automatically undone when disconnecting
        // also, since this service accepts messages from clients we should reset our handle to
        // 0 to make sure we dont try to continue using it
        hMemoryService=0; 
    }
}

void ISXEQLabels::UnRegisterCommands()
{
    // remove commands
    //    pISInterface->RemoveCommand("MyCommand");
}
void ISXEQLabels::UnRegisterAliases()
{
    // remove aliases
}
void ISXEQLabels::UnRegisterDataTypes()
{
    // remove data types
    //if (pMyType)
    //{
    //    pISInterface->RemoveLSType(*pMyType);
    //    delete pMyType;
    //}
}
void ISXEQLabels::UnRegisterTopLevelObjects()
{
    // remove Top-Level Objects
    //    pISInterface->RemoveTopLevelObject("MapSpawn");
}
void ISXEQLabels::UnRegisterServices()
{
    // shutdown our own services
    //    if (hISXEQLabelsService)
    //        pISInterface->ShutdownService(this,hISXEQLabelsService);
}

void ISXEQLabels::LoadSettings()
{
    // IS provides easy methods of reading and writing settings of all types (bool, int, string, float, etc)
}


void __cdecl MemoryService(bool Broadcast, unsigned int MSG, void *lpData)
{
    // no messages are currently associated with this service (other than
    // system messages such as client disconnect), so do nothing.
}
