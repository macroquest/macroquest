/***************************************************************************** 
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest 
Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

This program is free software; you can redistribute it and/or modify 
it under the terms of the GNU General Public License, version 2, as published by 
the Free Software Foundation. 

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
GNU General Public License for more details. 
******************************************************************************/ 

#if !defined(CINTERFACE) 
#error /DCINTERFACE 
#endif 

#define DBG_SPEW 

#include "MQ2Main.h"

//First, we map out an equivalency between the UI labels in locations.txt and
//the window we will be executing the click in.  The UI labels themselves are drawn
//from UI_Character_Server.ini.

//We need to include a couple extra files to handle our equivalency map.
#include <map>
#include <string>
//Then specify the proper namespace
using namespace std;

//Next we define the actual map itself
map<string,CSidlScreenWnd*> mWindowMap;

//And then we load the map
void InitWindowMap()
{
	mWindowMap["ConfirmationDialogBox"]	=	(CSidlScreenWnd*)pConfirmationDialog;
	mWindowMap["FacePickWindow"]		=	(CSidlScreenWnd*)pFacePick;
	mWindowMap["OptionsWindow"]			=	(CSidlScreenWnd*)pOptionsWnd;
	mWindowMap["FeedbackWindow"]		=	(CSidlScreenWnd*)pFeedbackWnd;
	mWindowMap["BugReportWindow"]		=	(CSidlScreenWnd*)pBugReportWnd;
	mWindowMap["HelpWindow"]			=	(CSidlScreenWnd*)pHelpWnd;
	mWindowMap["CastSpellWnd"]			=	(CSidlScreenWnd*)pCastSpellWnd;
	mWindowMap["TargetWindow"]			=	(CSidlScreenWnd*)pTargetWnd;
	mWindowMap["HotButtonWnd"]			=	(CSidlScreenWnd*)pHotButtonWnd;
	mWindowMap["PlayerWindow"]			=	(CSidlScreenWnd*)pPlayerWnd;
	mWindowMap["GroupWindow"]			=	(CSidlScreenWnd*)pGroupWnd;
	mWindowMap["ActionsWindow"]			=	(CSidlScreenWnd*)pActionsWnd;
	mWindowMap["SelectorWindow"]		=	(CSidlScreenWnd*)pSelectorWnd;
	mWindowMap["PetInfoWindow"]			=	(CSidlScreenWnd*)pPetInfoWnd;
	mWindowMap["CompassWindow"]			=	(CSidlScreenWnd*)pCompassWnd;
	mWindowMap["ChatManager"]			=	(CSidlScreenWnd*)pChatManager;
	mWindowMap["SocialEditWnd"]			=	(CSidlScreenWnd*)pSocialEditWnd;
	mWindowMap["InspectWnd"]			=	(CSidlScreenWnd*)pInspectWnd;
	mWindowMap["TrackingWnd"]			=	(CSidlScreenWnd*)pTrackingWnd;
	mWindowMap["BazaarWnd"]				=	(CSidlScreenWnd*)pBazaarWnd;
	mWindowMap["BazaarSearchWnd"]		=	(CSidlScreenWnd*)pBazaarSearchWnd;
	mWindowMap["TradeWnd"]				=	(CSidlScreenWnd*)pTradeWnd;
	mWindowMap["InventoryWindow"]		=	(CSidlScreenWnd*)pInventoryWnd;
	mWindowMap["GiveWnd"]				=	(CSidlScreenWnd*)pGiveWnd;
	mWindowMap["MerchantWnd"]			=	(CSidlScreenWnd*)pMerchantWnd;
	mWindowMap["LootWnd"]				=	(CSidlScreenWnd*)pLootWnd;
	mWindowMap["BankWnd"]				=	(CSidlScreenWnd*)pBankWnd;
	mWindowMap["SpellBookWnd"]			=	(CSidlScreenWnd*)pSpellBookWnd;
	mWindowMap["CastingWindow"]			=	(CSidlScreenWnd*)pCastingWnd;
	mWindowMap["CursorAttachment"]		=	(CSidlScreenWnd*)pCursorAttachment;
	mWindowMap["NoteWindow"]			=	(CSidlScreenWnd*)pNoteWnd;
	mWindowMap["BookWindow"]			=	(CSidlScreenWnd*)pBookWnd;
	mWindowMap["FriendsWindow"]			=	(CSidlScreenWnd*)pFriendsWnd;
	mWindowMap["TrainWindow"]			=	(CSidlScreenWnd*)pTrainWnd;
	mWindowMap["SkillsWindow"]			=	(CSidlScreenWnd*)pSkillsWnd;
	mWindowMap["SkillsSelectWindow"]	=	(CSidlScreenWnd*)pSkillsSelectWnd;
	mWindowMap["AAWindow"]				=	(CSidlScreenWnd*)pAAWnd;
	mWindowMap["BreathWindow"]			=	(CSidlScreenWnd*)pBreathWnd;
	mWindowMap["ColorPickerWnd"]		=	(CSidlScreenWnd*)pColorPickerWnd;
	mWindowMap["QuantityWnd"]			=	(CSidlScreenWnd*)pQuantityWnd;
	mWindowMap["TextEntryWnd"]			=	(CSidlScreenWnd*)pTextEntryWnd;
	mWindowMap["VideoModesWindow"]		=	(CSidlScreenWnd*)pVideoModesWnd;
	mWindowMap["PlayerNotesWindow"]		=	(CSidlScreenWnd*)pPlayerNotesWnd;
	mWindowMap["GemsGameWnd"]			=	(CSidlScreenWnd*)pGemsGameWnd;
	mWindowMap["AlarmWnd"]				=	(CSidlScreenWnd*)pAlarmWnd;
	mWindowMap["LoadskinWnd"]			=	(CSidlScreenWnd*)pLoadskinWnd;
	mWindowMap["RaidWindow"]			=	(CSidlScreenWnd*)pRaidWnd;
	mWindowMap["RaidOptionsWindow"]		=	(CSidlScreenWnd*)pRaidOptionsWnd;
	mWindowMap["MusicPlayerWnd"]		=	(CSidlScreenWnd*)pMusicPlayerWnd;
	mWindowMap["FileSelectionWnd"]		=	(CSidlScreenWnd*)pFileSelectionWnd;
	mWindowMap["StoryWnd"]				=	(CSidlScreenWnd*)pStoryWnd;
	mWindowMap["BodyTintWnd"]			=	(CSidlScreenWnd*)pBodyTintWnd;
	mWindowMap["GuildManagementWnd"]	=	(CSidlScreenWnd*)pGuildMgmtWnd;
	mWindowMap["GroupSearchWnd"]		=	(CSidlScreenWnd*)pGroupSearchWnd;
	mWindowMap["GroupSearchFiltersWnd"]	=	(CSidlScreenWnd*)pGroupSearchFiltersWnd;
	mWindowMap["MapViewWnd"]			=	(CSidlScreenWnd*)pMapViewWnd;
	mWindowMap["MapToolbarWnd"]			=	(CSidlScreenWnd*)pMapToolbarWnd;
	mWindowMap["EditLabelWnd"]			=	(CSidlScreenWnd*)pEditLabelWnd;
	mWindowMap["JournalNPCWnd"]			=	(CSidlScreenWnd*)pJournalCatWnd;
	mWindowMap["JournalTextWnd"]		=	(CSidlScreenWnd*)pJournalTextWnd;
	mWindowMap["BigBankWnd"]			=	(CSidlScreenWnd*)pBankWnd;
	mWindowMap["BankWnd"]				=	(CSidlScreenWnd*)pBankWnd;
}

CSidlScreenWnd *FindContainerWnd(struct _CONTENTS *pContents)
{
	if (!pContents)
		return 0;

	for (int i = 0 ; i < 0x19 ; i++)
	{
		if (PEQCONTAINERWINDOW pWnd=((PEQ_CONTAINERWND_MANAGER)pContainerMgr)->pPCContainers[i])
		{
			if (pWnd->pContents==pContents)
				return (CSidlScreenWnd*)pWnd;
		}
	}

	return 0;
}

//*************************************************************************** 
// Function: NewParseMouseLoc 
// Uses locations.txt as a roadmap to interpret click locations, translating
//   the desired location to a window name (szUILabel) and a screen ID (szScreenID)
//**************************************************************************** 
CSidlScreenWnd *NewParseMouseLoc(PCHAR szMouseLoc, PCHAR szOut) 
{ 
	CHAR Locations[MAX_STRING] = {0};
	PCHAR szUILabel= {0};
	PCHAR szScreenID = {0};
	PCHAR szArg1 = {0};
	CHAR szArg2[MAX_STRING] = {0};
	CHAR szArg3[MAX_STRING] = {0};
	CHAR szArg4[MAX_STRING] = {0};
	PCHAR szTemp = {0};

	//pull the first argument from szMouseLoc so that we can deal with special cases
	GetArg(szArg1,szMouseLoc,1);

	//pack   szArg2 is the pack number, szArg3 is the slot number.
	if (!strncmp(szArg1,"pack",4)) {
		GetArg(szArg2,szMouseLoc,2);
		if (!szArg2) {
			WriteChatColor("Invalid pack.",CONCOLOR_RED);
			return 0;
		}
		unsigned long Pack=atoi(szArg2);
		Pack = Pack;
		if (Pack>7)
		{
			WriteChatColor("Invalid pack.",CONCOLOR_RED);
			return 0;
		}
		CSidlScreenWnd *pWindow = FindContainerWnd(((PCHARINFO)pCharData)->Inventory.Pack[Pack+1]);
		pWindow->Show = 1;  //Open the pack if it's not open???
		if (!pWindow)
		{
			char out[256];
			sprintf(out,"Pack %d not open.",Pack);
			WriteChatColor(out,CONCOLOR_RED);
			return 0;
		}

		GetArg(szArg3,szMouseLoc,3);
		if (!szArg3) {
			WriteChatColor("Invalid location in pack.",CONCOLOR_RED);
			return 0;
		} else if (!strncmp(szArg3,"done",4)) {
			sprintf(szScreenID,"DoneButton");
		} else if (!strncmp(szArg3,"combine",7)) {
			sprintf(szScreenID,"Container_%s",szArg3);
		} else {
			int SlotTest = atoi(szArg3);
			if (SlotTest>9) {        //need to check this against actual slots, not "9"
				WriteChatColor("Valid slots are 0-9.",CONCOLOR_RED);
				return 0;
			} else {
			//	szTemp = itoa((SlotTest+1),szArg3,10);
				sprintf(szScreenID,"ContainerSlot%d",(SlotTest+1));
			}
		}

		//set szOut to the ScreenID, then return to the click function
		strcpy(szOut,szScreenID);
		return pWindow;  //success
	}

	//enviro
	//szArg2 is either a slot number, combine, or done
	if (!strncmp(szArg1,"enviro",6)) {

		//first check if the environmental container is open
		//any way to hijack the parmEnvOpen code so we don't have to repeat it here?
		PEQ_CONTAINERWND_MANAGER ContainerMgr = 0;
		if(!ppContainerMgr || !pContainerMgr) return 0;
		ContainerMgr = (PEQ_CONTAINERWND_MANAGER)pContainerMgr;
		if(!ContainerMgr->pWorldContents) {
			WriteChatColor("Enviro not open!",CONCOLOR_RED);
			return 0;
		}
		if(!*(DWORD *)ContainerMgr->pWorldContents)  {
			WriteChatColor("Enviro not open!",CONCOLOR_RED);
			return 0;
		}

		//we have an open enviro, so set our window pointer to it
		CSidlScreenWnd *pWindow = FindContainerWnd(((PEQ_CONTAINERWND_MANAGER)ContainerMgr)->pWorldContents);

		//now parse out the rest of the command to get a slot or button
		GetArg(szArg2,szMouseLoc,2);
		if (!szArg2) {
			WriteChatColor("Invalid location in enviro.",CONCOLOR_RED);
			return 0;
		} else if (!strncmp(szArg2,"done",4)) {
			sprintf(szScreenID,"DoneButton");
		} else if (!strncmp(szArg2,"combine",7)) {
			sprintf(szScreenID,"Container_%s",szArg2);
		} else {
			int SlotTest = atoi(szArg2);
			if (SlotTest>9) {        //need to check this against actual slots, not "9"
				WriteChatColor("Valid slots are 0-9.",CONCOLOR_RED);
				return 0;
			} else {
				//szTemp = itoa((SlotTest+1),szArg2,10);
				sprintf(szScreenID,"ContainerSlot%d",(SlotTest+1));
			}
		}
		return pWindow;  //success
	}

	//corpse, merchant, inv
	if ((!strncmp(szArg1,"corpse",6)) || (!strncmp(szArg1,"merchant",8)) || (!strncmp(szArg2,"inv",3))) {
		GetArg(szArg2,szMouseLoc,2);
		sprintf(szTemp,"%s_%s",szArg1,szArg2);
		szMouseLoc = szTemp;
	}

	//bank, shared
	//szArg1 is bank
	//szArg2 is either pack or shared.  Shared packs are pack 16/17, not shared pack 0/1
	//szArg3 is either a pack number, or a money slot or a shared slot (not pack)
	//szArg4 is a slot in a pack
	if (!strncmp(szArg1,"bank",4)) {
		DWORD BankSlots = pBankWnd->GetNumBankSlots();
		if (BankSlots>=16) {
			sprintf(szTemp,"bigbank");
			szArg1 = szTemp;
		} else {
			sprintf(szTemp,"bank");
			szArg1 = szTemp;
		}
		GetArg(szArg2,szMouseLoc,2);
		if (!strncmp(szArg2,"pack",4)) {
			GetArg(szArg3,szMouseLoc,3);
			unsigned long Pack=atoi(szArg3);
			if (Pack>17) { //16 + 2 shared
				WriteChatColor("Invalid pack.",CONCOLOR_RED);
				return 0;
			}
			CSidlScreenWnd *pWindow = FindContainerWnd(((PCHARINFO)pCharData)->Bank[Pack+1]);
			pWindow->Show = 1;  //open the pack if it's not open???
			if (!pWindow) {
				char out[256];
				sprintf(out,"Bank pack %d not open.",Pack);
				WriteChatColor(out,CONCOLOR_RED);
				return 0;
			}
			GetArg(szArg4,szMouseLoc,4);
			if (!szArg4) {
				WriteChatColor("Invalid location in pack.",CONCOLOR_RED);
				return 0;
			} else if (!strncmp(szArg4,"done",4) || !strncmp(szArg4,"combine",7)) {
				sprintf(szScreenID,"Container_%s",szArg4);
			} else {
				int SlotTest = atoi(szArg4);
				if (SlotTest>9) {        //need to check this against actual slots, not "9"
					WriteChatColor("Valid slots are 0-9.",CONCOLOR_RED);
					return 0;
				} else {
					//szTemp = itoa((SlotTest+1),szArg4,10);
					sprintf(szScreenID,"ContainerSlot%d",(SlotTest+1));
				}
			}
			//set szOut to the ScreenID, then return to the click function
			strcpy(szOut,szScreenID);
			return pWindow;
		} else if (!strncmp(szArg2,"shared",6)) {  //note: shared packs are bank pack 17 and 18, not bank shared pack 0 and 1
			GetArg(szArg3,szMouseLoc,3);
			sprintf(szTemp,"%s_shared_%s",szArg1,szArg3);
		} else {
			sprintf(szTemp,"%s_%s",szArg1,szArg2);
		}
		szMouseLoc = szTemp;
	}


	// from szMouseLoc, get our UILabel and ScreenID from locations.txt
	sprintf(Locations,"%s\\locations.txt",gszINIPath); //Locations filename
	GetPrivateProfileString(szMouseLoc,"UILabel",".",szUILabel,MAX_STRING,Locations); 
	GetPrivateProfileString(szMouseLoc,"ScreenID",".",szScreenID,MAX_STRING,Locations);


	// check to see if we have a valid location, if not return an error
	if (!szUILabel || (szUILabel=".") || !szScreenID || (szScreenID=".")) {
		WriteChatColor("Location not found in locations.txt, can't click.",USERCOLOR_DEFAULT);
		return 0;
	}

	// get the CSidlScreenWnd pointer from our equivalency map 
	CSidlScreenWnd *pWindow=mWindowMap[(string)szUILabel];
	if (!pWindow) 
		return 0; 
	if (!strncmp(szArg1,"inv",3)) {  //auto-open inventory window???
		pWindow->Show = 1;
	}
	// now set szOut to the ScreenID from locations.txt 
	strcpy(szOut,szScreenID); 
	return pWindow; // success 
} 

//**************************************************************************** 
// Function: NewClick 
//**************************************************************************** 
VOID NewClick(PSPAWNINFO pChar, PCHAR szLine) 
{ 
	CHAR szLeftRight[MAX_STRING] = {0}; 
	CHAR szScreenID[MAX_STRING] = {0}; 
	PCHAR szMouseLoc; 
	unsigned int ButtonToClick; 
	CSidlScreenWnd* pWindow=0; 

	GetArg(szLeftRight, szLine, 1); //left or right 
	szMouseLoc = GetNextArg(szLine, 1); //location to click 

	if (szMouseLoc && szMouseLoc[0]!=0) { 
		//Deal with target and item first, since those don't need to be parsed
		if (!strnicmp(szMouseLoc, "target", 6)) {      
			if (!pTarget) { 
				WriteChatColor("You must have a target selected for /click x target.",CONCOLOR_RED); 
				return; 
			} 
			if (!strnicmp(szLeftRight, "left", 4)) { 
				pEverQuest->LeftClickedOnPlayer(pTarget); 
			} else if (!strnicmp(szLeftRight, "right", 5)) { 
				pEverQuest->RightClickedOnPlayer(pTarget); 
			} 
			return; 
		} else if (!strnicmp(szMouseLoc, "item", 4)) {
			// a right clicked ground spawn does nothing
			if (!strnicmp(szLeftRight, "left", 4) && EnviroTarget.Name[0]!=0 && DistanceToSpawn(pChar,&EnviroTarget)<20.0f) {
				INTERACTGROUNDITEM Data;
				Data.SpawnID = GetCharInfo()->pSpawn->SpawnID;
				Data.DropID = EnviroTarget.Race;
				if (send_message || EQADDR_GWORLD) {
					send_message(EQADDR_GWORLD,EQ_INTERACTGROUNDITEM,&Data,sizeof(INTERACTGROUNDITEM),TRUE);
				}				
				EnviroTarget.Name[0]=0;
				if (pTarget==(EQPlayer*)&EnviroTarget) pTarget=NULL;
				return;
			}
			//Now we actually need to parse szMouseLoc
		} else if (!(pWindow=NewParseMouseLoc(szMouseLoc,szScreenID))) { 
			WriteChatColor("Invalid location, can't click!",USERCOLOR_DEFAULT); 
			return; 
		} 
	} 

	if (szLeftRight[0]!=0) { 
		if (!strnicmp(szLeftRight, "left", 4)) {ButtonToClick=XWM_LCLICK;} 
		else if (!strnicmp(szLeftRight, "right", 5)) {ButtonToClick=XWM_RCLICK;} 
		else { 
			WriteChatColor("Usage: /click <left|right>",USERCOLOR_DEFAULT); 
			DebugSpew("Bad command: %s",szLine); 
			return; 
		} 
	} 

	CXWnd *button=pWindow->GetChildItem(CXStr(szScreenID)); 
	pWindow->WndNotification(button,ButtonToClick,0);
} 
