// MQ2ItemDisplay.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"

PreSetup("MQ2ItemDisplay");



// *************************************************************************** 
// Function:    ItemDisplayHook
// Description: Our Item display hook 
// *************************************************************************** 
class ItemDisplayHook
{
public:
   VOID SetItem_Trampoline(class EQ_Item *pitem,bool unknown);
   VOID SetItem_Detour(class EQ_Item *pitem,bool unknown)
   {
      PEQITEMWINDOW This=(PEQITEMWINDOW)this;
	  PITEMINFO Item=*(PITEMINFO*)pitem;
      CHAR out[MAX_STRING] = {0};
     CHAR temp[MAX_STRING] = {0};
     PCHAR lore = NULL;
      SetItem_Trampoline(pitem,unknown);

     strcpy(out,"<BR><c \"#00FFFF\">");
	  if (Item->Cost>0) {
		  DWORD cp = Item->Cost;
		  DWORD sp = cp/10; cp=cp%10;
		  DWORD gp = sp/10; sp=sp%10;
		  DWORD pp = gp/10; gp=gp%10;
		  strcat(out,"Value:");
		  if (pp>0) {
			  sprintf(temp," %dpp",pp);
			  strcat(out,temp);
		  }
		  if (gp>0) {
			  sprintf(temp," %dgp",gp);
			  strcat(out,temp);
		  }
		  if (sp>0) {
			  sprintf(temp," %dsp",sp);
			  strcat(out,temp);
		  }
		  if (cp>0) {
			  sprintf(temp," %dcp",cp);
			  strcat(out,temp);
		  }
		  strcat(out,"<BR>");
	  }
     lore=Item->LoreName;
     if (lore[0]=='*') lore++;
     if (strcmp(lore,Item->Name)) {
      sprintf(temp,"Item Lore: %s<BR>",Item->LoreName);
      strcat(out,temp);
     }

     // This really should be a compare against some field in the item...
     if (strstr(This->ItemInfo->Text,"(Combat)")) {
      sprintf(temp,"Procs at %d<BR>",Item->Common.Level);
      strcat(out,temp);
     } else if (Item->Common.SpellId==/*Haste*/998) {
      sprintf(temp,"%d%% Haste<BR>",Item->Common.Level+1);
      strcat(out,temp);
     }

     if (Item->Type == ITEMTYPE_PACK) {
        sprintf(temp,"Container Type: %s<BR>",szCombineTypes[Item->Container.Combine]);
        strcat(out,temp);
     }

     if (out[0]!=17) {
      strcat(out,"</c>");
	  //((CXStr)This->ItemInfo)+=
      AppendCXStr(&This->ItemInfo,&out[0]);
     }
   }
};

DETOUR_TRAMPOLINE_EMPTY(VOID ItemDisplayHook::SetItem_Trampoline(class EQ_Item *,bool)); 


// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2ItemDisplay");

	// Add commands, macro parameters, hooks, etc.

	void (ItemDisplayHook::*pfDetour)(class EQ_Item *,bool) = ItemDisplayHook::SetItem_Detour; 
   void (ItemDisplayHook::*pfTrampoline)(class EQ_Item *,bool) = ItemDisplayHook::SetItem_Trampoline; 
   AddDetour(CItemDisplayWnd__SetItem,*(PBYTE*)&pfDetour,*(PBYTE*)&pfTrampoline);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2ItemDisplay");

	// Remove commands, macro parameters, hooks, etc.
	RemoveDetour(CItemDisplayWnd__SetItem);
}

