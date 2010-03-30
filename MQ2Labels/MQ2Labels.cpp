// MQ2Labels.cpp : Defines the entry point for the DLL application.
//

// MQ2 Custom Labels


#include "../MQ2Plugin.h"

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



PreSetup("MQ2Labels");


class CLabelHook {
public:
   VOID Draw_Trampoline(VOID);
   VOID Draw_Detour(VOID)
   {
      PCSIDLWND pThisLabel;
	  __asm {mov [pThisLabel], ecx};
//		  (PCSIDLWND)this;
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

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2Labels");

	// Add commands, macro parameters, hooks, etc.
	//EasyClassDetour(CLabel__Draw,CLabelHook,Draw_Detour,VOID,(VOID),Draw_Trampoline);
	EzDetour(CLabel__Draw,CLabelHook::Draw_Detour,CLabelHook::Draw_Trampoline);


// currently in testing:
//	EasyClassDetour(CGauge__Draw,CGaugeHook,Draw_Detour,VOID,(VOID),Draw_Trampoline);
//	EasyDetour(__GetGaugeValueFromEQ,GetGaugeValueFromEQ_Hook,int,(int,class CXStr *,bool *),GetGaugeValueFromEQ_Trampoline);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2Labels");

	// Remove commands, macro parameters, hooks, etc.
	RemoveDetour(CLabel__Draw);
	RemoveDetour(CGaugeWnd__Draw);
	RemoveDetour(__GetGaugeValueFromEQ);
}

