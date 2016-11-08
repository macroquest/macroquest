// MQ2Labels.cpp : Defines the entry point for the DLL application.
//
// 2.0 - May 14 2016 - Added code to allow anonymizing labels, for streaming/video recording. - eqmule
// MQ2 Custom Labels


#include "../MQ2Plugin.h"
PLUGIN_VERSION(2.0);
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

    {(DWORD)-1,NULL}
}; 



PreSetup("MQ2Labels");

// CSidlManager::CreateLabel 0x5F2470

// the tool tip is already copied out of the 
// in class CControlTemplate.  use this struct
// to mock up the class, so we don't have to
// worry about class instatiation and crap

struct _CControl {
    /*0x000*/    BYTE Fluff[0x94]; // if this changes update ISXEQLabels.cpp too
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
        CLABELWND *p;
        class CXWnd *tmp = CreateLabel_Trampoline(CWin, CControl);
        p = (CLABELWND *)tmp;
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

bool Anonymize(char *name)
{
	if(GetGameState()!=GAMESTATE_INGAME || !pLocalPlayer)
		return 0;
	BOOL bisTarget = false;
	BOOL isRmember = false;
	BOOL isGmember = false;
	bool bChange = false;
	int ItsMe = _stricmp(((PSPAWNINFO)pLocalPlayer)->Name, name);
	if(ItsMe!=0)//well if it is me, then there is no point in checking if its a group member
		isGmember = IsGroupMember(name);
	if(!isGmember && ItsMe!=0)//well if it is me or a groupmember, then there is no point in checking if its a raid member
		isRmember = IsRaidMember(name);
	if (ItsMe != 0 && !isGmember && !isRmember) {
		//my target?
		if (pTarget && ((PSPAWNINFO)pTarget)->Type!=SPAWN_NPC) {
			if (!_stricmp(((PSPAWNINFO)pTarget)->Name, name)) {
				bisTarget = true;
			}
		}
	}
	if (ItsMe==0 || isGmember || isRmember || bisTarget) {
		int len = strlen(name);
		bChange = true;
		for (int i = 1; i < len - 1; i++) {
			name[i] = '*';
		}
	}
	return bChange;
}
int __cdecl GetGaugeValueFromEQ_Trampoline(int, class CXStr *, bool *, unsigned long *);
int __cdecl GetGaugeValueFromEQ_Detour(int EQType, class CXStr *out, bool *arg3, unsigned long *colorout)
{
	int ret = GetGaugeValueFromEQ_Trampoline(EQType,out,arg3,colorout);
	if (gAnonymize) {
		if (out && out->Ptr) {
			CHAR szOut[MAX_STRING] = { 0 };
			GetCXStr(out->Ptr, szOut);
			if (Anonymize(szOut)) {
				SetCXStr(&out->Ptr, szOut);
			}
		}
	}
	return ret;
}
int __cdecl GetLabelFromEQ_Trampoline(int, class CXStr *, bool *, unsigned long *);
int __cdecl GetLabelFromEQ_Detour(int EQType, class CXStr *out, bool *arg3, unsigned long *colorout)
{
	int ret = GetLabelFromEQ_Trampoline(EQType,out,arg3,colorout);
	if (gAnonymize) {
		if (out && out->Ptr) {
			CHAR szOut[MAX_STRING] = { 0 };
			GetCXStr(out->Ptr, szOut);
			if (Anonymize(szOut)) {
				SetCXStr(&out->Ptr, szOut);
			}
		}
	}
	return ret;
}

BOOL bTrimnames = 0;
// CLabelHook::Draw_Detour
class CLabelHook {
public:
	char *CEverQuest__trimName_Trampoline(char *);
	char *CEverQuest__trimName_Detour(char *arg1)
	{
		char *ret = CEverQuest__trimName_Trampoline(arg1);
		if (gAnonymize) {
			Anonymize(ret);
		}
		return ret;
	}
    VOID Draw_Trampoline(VOID);
    VOID Draw_Detour(VOID)
    {
        PCLABELWND pThisLabel = (PCLABELWND)this;
        CHAR Buffer[MAX_STRING] = {0};
        BOOL Found=FALSE;
        DWORD index;
		if (gAnonymize) {
			if (!bTrimnames) {
				EzDetourwName(CEverQuest__trimName, &CLabelHook::CEverQuest__trimName_Detour, &CLabelHook::CEverQuest__trimName_Trampoline,"CEverQuest__trimName");
				EzDetourwName(__GetGaugeValueFromEQ, GetGaugeValueFromEQ_Detour, GetGaugeValueFromEQ_Trampoline,"__GetGaugeValueFromEQ");
				EzDetourwName(__GetLabelFromEQ, GetLabelFromEQ_Detour, GetLabelFromEQ_Trampoline,"__GetLabelFromEQ");
				bTrimnames = 1;
			}
			if (pThisLabel && pThisLabel->Wnd.WindowText) {
				GetCXStr(pThisLabel->Wnd.WindowText, Buffer);
				Anonymize(Buffer);
			}
		} else {
			if (bTrimnames) {
				bTrimnames = 0;
				RemoveDetour(CEverQuest__trimName);
				RemoveDetour(__GetGaugeValueFromEQ);
				RemoveDetour(__GetLabelFromEQ);
			}
		}
		Draw_Trampoline();
       if ((DWORD)pThisLabel->SidlPiece==9999) {
            if (!pThisLabel->Wnd.XMLToolTip) {
                strcpy_s(Buffer,"BadCustom");
                Found=TRUE;
            } else {
                //strcpy_s(Buffer,&pThisLabel->XMLToolTip->Text[0]);
                STMLToPlainText(&pThisLabel->Wnd.XMLToolTip->Text[0],Buffer);
                ParseMacroParameter(((PCHARINFO)pCharData)->pSpawn,Buffer);
                if (!strcmp(Buffer,"NULL"))
                    Buffer[0]=0;
                Found=TRUE;
            }
        } else if ((DWORD)pThisLabel->SidlPiece>=1000) {
            for (index=0;Id_PMP[index].ID>0 && !Found;index++) {
                if (Id_PMP[index].ID==(DWORD)pThisLabel->SidlPiece) {
                    strcpy_s(Buffer,Id_PMP[index].PMP);
                    ParseMacroParameter(((PCHARINFO)pCharData)->pSpawn,Buffer);
                    if (!strcmp(Buffer,"NULL"))
                        Buffer[0]=0;
                    Found=TRUE;
                }
            }
        }
        if (Found)
			SetCXStr(&(pThisLabel->Wnd.WindowText),Buffer);
    }
}; 

DETOUR_TRAMPOLINE_EMPTY(VOID CLabelHook::Draw_Trampoline(VOID));
DETOUR_TRAMPOLINE_EMPTY(char *CLabelHook::CEverQuest__trimName_Trampoline(char *));
DETOUR_TRAMPOLINE_EMPTY(int __cdecl GetGaugeValueFromEQ_Trampoline(int, class CXStr *, bool *, unsigned long *));
DETOUR_TRAMPOLINE_EMPTY(int __cdecl GetLabelFromEQ_Trampoline(int, class CXStr *, bool *, unsigned long *));

BOOL StealNextGauge=FALSE;
DWORD NextGauge=0;

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
    DebugSpewAlways("Initializing MQ2Labels");

    // Add commands, macro parameters, hooks, etc.
    //EasyClassDetour(CLabel__Draw,CLabelHook,Draw_Detour,VOID,(VOID),Draw_Trampoline);
    EzDetourwName(CLabel__Draw,&CLabelHook::Draw_Detour,&CLabelHook::Draw_Trampoline,"CLabel__Draw");
    EzDetourwName(CSidlManager__CreateLabel,&CSidlManagerHook::CreateLabel_Detour,&CSidlManagerHook::CreateLabel_Trampoline,"CSidlManager__CreateLabel");
	if (gAnonymize) {
		EzDetourwName(CEverQuest__trimName, &CLabelHook::CEverQuest__trimName_Detour, &CLabelHook::CEverQuest__trimName_Trampoline,"CEverQuest__trimName");
		EzDetourwName(__GetGaugeValueFromEQ, GetGaugeValueFromEQ_Detour, GetGaugeValueFromEQ_Trampoline,"__GetGaugeValueFromEQ");
		EzDetourwName(__GetLabelFromEQ, GetLabelFromEQ_Detour, GetLabelFromEQ_Trampoline,"__GetLabelFromEQ");
		bTrimnames = 1;
	}
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down MQ2Labels");
	
    // Remove commands, macro parameters, hooks, etc.
	if (bTrimnames) {
		bTrimnames = 0;
		RemoveDetour(CEverQuest__trimName);
		RemoveDetour(__GetGaugeValueFromEQ);
		RemoveDetour(__GetLabelFromEQ);
	}
    RemoveDetour(CSidlManager__CreateLabel);
    RemoveDetour(CLabel__Draw);
    //RemoveDetour(CGaugeWnd__Draw);
    //RemoveDetour(__GetGaugeValueFromEQ);
}

