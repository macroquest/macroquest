// MQ2Labels.cpp : Defines the entry point for the DLL application.
//

// MQ2 Custom Labels

#include "stdafx.h"
#include "../MQ2Plugin.h"

// PLEASE keep this array limited.  Recommend using 9999 and tooltips.
struct _ID_PMP
   { DWORD ID;PCHAR PMP; }
Id_PMP[] = {
   // 1000-1999: $char()
      {1000,   "$char(mana,cur)"},
      {1001,   "$char(mana,max)"},
      {1002,   "$char(state)"},
     {1003,   "$char(speed)"},
     {1004,   "$char(heading)"},
     {1005,   "$char(x)"},
     {1006,   "$char(y)"},
     {1007,   "$char(z)"},
     {1008,   "$char(dar)"},
     {1009,   "$char(cash)"},
     {1010,   "$char(cash,bank)"},
     {1011,   "$char(plat,bank)"},
     {1012,   "$char(plat,shared)"},
     {1013,   "$char(gold,bank)"},
     {1014,   "$char(silver,bank)"},
     {1015,   "$char(copper,bank)"},
 
      // 2000-2999: $target()
      {2000,   "$target(level)"},
      {2001,   "$target(class)"},
      {2002,   "$target(race)"},
      {2003,   "$target(distance)"},
      {2004,   "$target(lastattacked)"},
      {2005,   "$target(state)"},
     {2006,   "$target(x)"},
     {2007,   "$target(y)"},
     {2008,   "$target(z)"},
     {2009,   "$target(heading)"},
     {2010,   "$target(speed)"},
	  {2011,  "$target(id)"},

      // 3000-3999: misc
      {3000,   "$zone()"},
      {3001,   "$zone(zem)"},
      {3002,   "$zone(bound)"},
     {3003,   "$time()"},
     {3004,   "$time(h)"},
     {3005,   "$time(m)"},
     {3006,   "$time(s)"},
     {3007,   "$date()"},
     {3008,   "$date(y)"},
     {3009,   "$date(m)"},
     {3010,   "$date(d)"},
     {3011,   "$gm"},
     {3012,   "$freeinv(space)"},

    // 9999: custom (TooltipReference)
     {9999,   "BrokenParser" },

   {-1,NULL}
}; 



BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call==DLL_PROCESS_ATTACH)
		DebugSpewAlways("MQ2Labels Module Loaded");
	else if (ul_reason_for_call==DLL_PROCESS_DETACH)
		DebugSpewAlways("MQ2Labels Module Unloaded");
    return TRUE;
}


class CLabelHook {
public:
   VOID Draw_Trampoline(VOID);
   VOID Draw_Detour(VOID)
   {
      PCSIDLWND pThisLabel = (PCSIDLWND)this;
      Draw_Trampoline();
      CHAR Buffer[MAX_STRING] = {0};
      BOOL Found=FALSE;
      DWORD index;

      if (pThisLabel->SlotID==9999) {
         if (!pThisLabel->XMLToolTip) {
            strcpy(Buffer,"BadCustom");
            Found=TRUE;
         } else {
            strcpy(Buffer,&pThisLabel->XMLToolTip->Text[0]);
            ParseMacroParameter(((PCHARINFO)pCharData)->pSpawn,Buffer);
			if (!strcmp(Buffer,"NULL"))
				Buffer[0]=0;
            Found=TRUE;
         }
      } else if (pThisLabel->SlotID>114) {//<--- needs updating every patch
         for (index=0;Id_PMP[index].ID>0 && !Found;index++) {
            if (Id_PMP[index].ID==pThisLabel->SlotID) {
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

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2Labels");

	// Add commands, macro parameters, hooks, etc.
   void (CLabelHook::*pfDetour)(VOID) = CLabelHook::Draw_Detour;
   void (CLabelHook::*pfTrampoline)(VOID) = CLabelHook::Draw_Trampoline;
	AddDetour(CLabel__Draw,*(PBYTE*)&pfDetour,*(PBYTE*)&pfTrampoline);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2Labels");

	// Remove commands, macro parameters, hooks, etc.
	RemoveDetour(CLabel__Draw);
}

