/***************************************************************************** 
eqlib.dll: MacroQuest's extension DLL for EverQuest 
Copyright (C) 2002-2003 Plazmic 

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

#include "stdafx.h" 
#include "MQ2Main.h" 


// *************************************************************************** 
// Function: ParseMouseLoc 
// Description: Parses mouseloc for /click and /mouseto 
// *************************************************************************** 
//Function used by ParseLocationXML to extract parameter
// ExtractValue - gets value between specified start and end markers
// - Parameters:
// szFile - pointer to tring to look in
// szStart - pointer to string to mark start of value
// szEnd - pointer to string to mark end of value
// szValue - pointer to string to contain the value found
// - Return Value:
// if successful, return TRUE, szValue contains the value between the start and end markers
// if unsuccessful, return FALSE
BOOL ExtractValue(PCHAR szFile, PCHAR szStart, PCHAR szEnd, PCHAR szValue)
{
	// verify we have legal pointers passed to us
	if (!szValue)
		return FALSE;

	if (!szFile || !szStart || !szEnd)
	{
		szValue[0] = 0;
		return FALSE;
	}

	PCHAR sub,sub2,fence;
	DWORD lenStart = strlen(szStart);

	fence = strstr(szFile,"ScreenID"); // needed to make sure we don't start into another element

	sub = strstr(szFile, szStart); 
	sub2 = strstr(szFile, szEnd); 
	if (!sub || !sub2 || (fence && (sub > fence))) {
		szValue[0] = 0;
		return FALSE;
	}

	memcpy(szValue,sub + lenStart, (sub2-sub) - lenStart);
	szValue[(sub2-sub) - lenStart] = 0;
	DebugSpew("Value extracted for %s was %s",szStart,szValue);
	return TRUE;
}

//start parser experiment 
// ParseLocationXML - gets the location and size of a specified UI object 
// (by Clawed) 
// 
// - Parameters: 
// szFilename - valid filename with full path to the XML file 
// szScreenID - the ScreenID of the object requested
// refW - reference width for resizable window
// refH - reference height for resizable window 
// - Return Value: 
// If successful, returns a UILOCATION structure containing the results 
// If unsuccessful (file not found, memory allocation error, object not 
// found, etc), returns a UILOCATION structure with zeroes in all values, 
// and puts an error string into the structure 
// 
// Note that this function tries to be very smart about checking for errors. 
// 
// THINGS TO KNOW ABOUT THIS FUNCTION: 
// 1) It requires a correctly-written UI XML file 
// 2) It will only give you the coordinates of objects that have a ScreenID 
// tag associated with them. 
// 3) If the object doesn't have one of the required tags i.e. <X>, this function 
// will get the <X> tag from the NEXT object, yielding an INCORRECT value (not 0) 
// 4) This function requires correctly-formed syntax: it uses both the <X> and the 
// </X> tags to parse the data; if a tag doesn't have it's </X>, the function 
// will yield an incorrect value 
// 5) If the function does not detect an error condition but still experiences 
// an error (such as one mentioned above), it will almost always return 0 in 
// the related coordinate value 
UILOCATION ParseLocationXML(PCHAR szFilename, PCHAR szScreenID, DWORD refW, DWORD refH) 
{ 
	UILOCATION loc = {0, 0, 0, 0, ""}; 
	FILE *in; 
	PCHAR buf, where, sub; 
	CHAR search[MAX_STRING], value[MAX_STRING]; 
	size_t size;
	BOOL parseError = FALSE; // check for errors in finding location elements

	// variables to handle anchoring in resizable windows
	DWORD LeftAnchorOffset = 0;
	DWORD RightAnchorOffset = 0;
	DWORD TopAnchorOffset = 0;
	DWORD BottomAnchorOffset = 0;
	UILOCATION anchor = {0,0,0,0,""};

	BOOL TopAnchorToTop = TRUE;	// default is true
	BOOL BottomAnchorToTop = TRUE;	// default is true
	BOOL LeftAnchorToLeft = TRUE;	// default is true
	BOOL RightAnchorToLeft = TRUE;	// default is true

	CHAR LA_Start[] = "<LeftAnchorOffset>";
	CHAR LA_End[] = "</LeftAnchorOffset>";
	CHAR RA_Start[] = "<RightAnchorOffset>";
	CHAR RA_End[] = "</RightAnchorOffset>";
	CHAR TA_Start[] = "<TopAnchorOffset>";
	CHAR TA_End[] = "</TopAnchorOffset>";
	CHAR BA_Start[] = "<BottomAnchorOffset>";
	CHAR BA_End[] = "</BottomAnchorOffset>";

	CHAR LL_Start[] = "<LeftAnchorToLeft>";
	CHAR LL_End[] = "</LeftAnchorToLeft>";
	CHAR RL_Start[] = "<RightAnchorToLeft>";
	CHAR RL_End[] = "</RightAnchorToLeft>";
	CHAR TT_Start[] = "<TopAnchorToTop>";
	CHAR TT_End[] = "</TopAnchorToTop>";
	CHAR BT_Start[] = "<BottomAnchorToTop>";
	CHAR BT_End[] = "</BottomAnchorToTop>";

	// operations for handleing positions in resizable windows
	// if TopAnchorToTop == true
	//	y = TopAnchorOffset
	// else
	//	y = refH - TopAnchorOffset
	//
	// if BottomAnchorToTop == true
	//	h = BottomAnchorOffset - y
	// else
	//	h = refH - BottomAnchorOffset - y
	//
	// if LeftAnchorToLeft == true
	//	x = LeftAnchorOffset
	// else
	//	x = refW - LeftAnchorOffset
	//
	// if RightAnchorToLeft == true
	//	w = RightAnchorOffset - x
	// else
	//	w = refW - RightAnchorOffset - x
	//

	// Open the file and read its entire contents into memory 
	if (!(in = fopen(szFilename, "rt"))) { 
		strcpy(loc.error, "File not found or error opening file."); 
		return loc; 
	} 
	size = _filelength(_fileno(in)); 
	if (!(buf = new char[size + 1])) { 
		fclose(in); 
		strcpy(loc.error, "Unable to allocate memory buffer."); 
		return loc; 
	} 
	fread(buf, size, 1, in); 
	buf[size] = 0; // Null-terminate the file so we can search it 
	fclose(in); 

	// Verify ScreenID is in the file 
	sprintf(search, "<ScreenID>%s</ScreenID>", szScreenID); 
	where = strstr(buf, search); 
	if (!where) { 
		delete buf; 
		sprintf(loc.error, "ScreenID (%s) not found in XML file.", szScreenID); 
		return loc; 
	}
	where += strlen(search); // start looking after the ScreenID tag

	DebugSpew("Finding ScreenID <%s> in file %s",szScreenID,szFilename);
	
	// OK, we have the file in memory, now there are 3 possibilities that we need to handle:
	// 1) the item is a relative location in a non-resizable window
	//	find the item and return the x, y, cx, cy values
	// 2) the item is an anchor location in a resizable window
	//	find the item and determine its anchor characteristics
	//	compute the relative values and return the computed location
	// 3) the item is a relative location in an anchored subwindow
	//	find the subwindow and determine its anchor characteristics
	//	compute the relative values for the subwindow
	//	find the item and get the x, y, cx, cy values
	//	compute the relative values of the subwindow and item


	strcpy(search,"<Style_Sizable>true</Style_Sizable>");
	sub = strstr(buf, search);
	if (sub)
	{ // this is a resizable window, use anchors
		if (strstr(szScreenID,"Slot"))
		{ // this is a relative item in an anchored window, get initial loc
			if (ExtractValue(where, "<X>", "</X>", value))
				loc.x = atoi(value);
			else
				parseError = TRUE;
			if (ExtractValue(where, "<Y>", "</Y>", value))
				loc.y = atoi(value);
			else
				parseError = TRUE;
			if (ExtractValue(where, "<CX>", "</CX>", value))
				loc.w = atoi(value);
			else
				parseError = TRUE;
			if (ExtractValue(where, "<CY>", "</CY>", value))
				loc.h = atoi(value);
			else
				parseError = TRUE;

			// ok we have the relative values, now we need to point the
			// search item to the containing window
			if (!strnicmp(szScreenID,"MW_Merch",8))
				strcpy(value,"MerchantSlotsWnd");
		
			else if (!strnicmp(szScreenID,"LW_Loot",7))
				strcpy(value,"LootInvWnd");

			else
			{
				// oops, a relocatable window I haven't identified yet
				DebugSpew("Parse XML - Unknown ScreenID: %s",szScreenID);
				return loc;
			}
			
			// Verify ScreenID is in the file 
			sprintf(search, "<ScreenID>%s</ScreenID>", value);
			where = strstr(buf, search); 
			if (!where) { 
				delete buf; 
				sprintf(loc.error, "ScreenID (%s) not found in XML file.", value); 
				return loc; 
			} 
			where += strlen(search); // start looking after the ScreenID tag
		}

		// ok where points to start of anchored item, get values and add to current loc
		
		if (ExtractValue(where, LA_Start, LA_End, value))
			LeftAnchorOffset = atol(value);
		else
			parseError = TRUE;
		if (ExtractValue(where, RA_Start, RA_End, value))
			RightAnchorOffset = atol(value);
		else
			parseError = TRUE;
		if (ExtractValue(where, TA_Start, TA_End, value))
			TopAnchorOffset = atol(value);
		else
			parseError = TRUE;
		if (ExtractValue(where, BA_Start, BA_End, value))
			BottomAnchorOffset = atol(value);
		else
			parseError = TRUE;

		if (ExtractValue(where, LL_Start, LL_End, value))
			if (!stricmp(value,"false"))
				LeftAnchorToLeft = FALSE;
		if (ExtractValue(where, RL_Start, RL_End, value))
			if (!stricmp(value,"false"))
				RightAnchorToLeft = FALSE;
		if (ExtractValue(where, TT_Start, TT_End, value))
			if (!stricmp(value,"false"))
				TopAnchorToTop = FALSE;
		if (ExtractValue(where, BT_Start, BT_End, value))
			if (!stricmp(value,"false"))
				BottomAnchorToTop = FALSE;

		if (TopAnchorToTop)
			anchor.y += TopAnchorOffset;
		else
			anchor.y += refH - TopAnchorOffset;

		if (LeftAnchorToLeft)
			anchor.x += LeftAnchorOffset;
		else
			anchor.x += refW - LeftAnchorOffset;

		if (BottomAnchorToTop)
			anchor.h = BottomAnchorOffset - anchor.y;
		else
			anchor.h = refH - BottomAnchorOffset - anchor.y;

		if (RightAnchorToLeft)
			anchor.w = RightAnchorOffset - anchor.x;
		else
			anchor.w = refW - RightAnchorOffset - anchor.x;

		// if there wasnt a relative offset, use w and h from anchor
		if (loc.w == 0)
		{
			loc.w = anchor.w;
			loc.h = anchor.h;
		}
		else
		{ // there was a relocatable part, see if it fits in window
			if (((loc.x + loc.w) > anchor.w) || ((loc.y + loc.h) > anchor.h))
			{
				delete buf;
				sprintf(loc.error,"resizable element not visible for ScreenID (%s)", szScreenID);
				return loc;
			}
		}

		// now add anchor to relative offsets

		loc.x += anchor.x;
		loc.y += anchor.y;

		
		if (TopAnchorToTop)
		{ // it is anchored to bottom so need to see if titlebar
			if (strstr(buf,"<Style_Titlebar>true</Style_Titlebar>"))
				loc.y += 20;
		}
	} // end resizable location parse
	else
	{ // Not resizable so just get values

		if (ExtractValue(where, "<X>", "</X>", value))
			loc.x = atoi(value);
		else
			parseError = TRUE;
		if (ExtractValue(where, "<Y>", "</Y>", value))
			loc.y = atoi(value);
		else
			parseError = TRUE;
		if (ExtractValue(where, "<CX>", "</CX>", value))
			loc.w = atoi(value);
		else
			parseError = TRUE;
		if (ExtractValue(where, "<CY>", "</CY>", value))
			loc.h = atoi(value);
		else
			parseError = TRUE;

		// check for titlebar
		if (strstr(where, "<Style_Titlebar>true</Style_Titlebar>"))
		{ // there is a title bar so offset y by 20
			loc.y += 20;
		} 

	} // end relative location parse

	if (parseError)
	{
		delete buf; 
		sprintf(loc.error, "Missing location elements for ScreenID (%s)", szScreenID); 
		return loc; 
	}		

	DebugSpew("Values found were x=%d y=%d w=%d h=%d",loc.x,loc.y,loc.w,loc.h);

	delete buf; 
	return loc; 
} 

BOOL MoveMouse(DWORD x, DWORD y) 
{ 
	if (EQADDR_MOUSE) {
		EQADDR_MOUSE->X = x; 
		EQADDR_MOUSE->Y = y; 
		DebugSpew("Moved mouse to: %d,%d", x, y); 
		return TRUE;
	}
	return FALSE;
} 


BOOL ParseMouseLoc(PCHARINFO pCharInfo, PCHAR szMouseLoc) 
{
	CHAR ClickLocation[MAX_STRING];	//the parsed named location to find
	CHAR ButtonX[MAX_STRING] = {0}; //the parsed X coordinate for the desired click location 
	CHAR ButtonY[MAX_STRING] = {0}; //the parsed Y coordinate for the desired click location 
	CHAR ButtonW[MAX_STRING] = {0}; //the parsed Width
	CHAR ButtonH[MAX_STRING] = {0}; //the Parsed Height
	PMOUSEINFO MouseInfo = EQADDR_MOUSE; //holds current mouse "state", i.e. coordinates 
	int ClickX; //actual location to click, calculated from ButtonX 
	int ClickY; //actual location to click, calculated from ButtonY 
	CHAR EQClient[MAX_STRING] = {0}; //eqclient.ini file, developed from gszEQPath 
	CHAR UIFile[MAX_STRING] = {0}; //character ui ini file for base window locations 
	CHAR Locations[MAX_STRING] = {0}; 
	FILE *input; 
	char SearchFor[] = {0}; 
	CHAR ScreenX[MAX_STRING] = {0}; //Screen resolution from eqclient.ini 
	CHAR ScreenY[MAX_STRING] = {0}; //Screen resolution from eqclient.ini 
	CHAR ScreenW[MAX_STRING] = {0}; //Window Width
	CHAR ScreenH[MAX_STRING] = {0}; //Window Height
	CHAR temp[MAX_STRING] = {0}; //needed a temp string for some diddling of strings 
	CHAR SkinName[MAX_STRING] = {0}; //Current character skin from UI ini file 
	CHAR UILabel[MAX_STRING] = {0}; //label in character UI file where window info is found 
	CHAR XMLFile[MAX_STRING] = {0}; //XML file our button/slot/whatever is found in 
	CHAR ScreenID[MAX_STRING] = {0}; //the location ID in the XML file 
	CHAR ServerID[MAX_STRING] = {0}; 
	UILOCATION XMLloc = {0, 0, 0, 0, ""}; 
	CHAR szTemp[MAX_STRING] = {0}; 
	PCHAR pSearch = NULL; 
	CHAR szSearchString[80] = "\\testeqgame.exe"; 

	CHAR szArg1[MAX_STRING] = {0};
	CHAR szArg2[MAX_STRING] = {0};
	CHAR szArg3[MAX_STRING] = {0};
	PCHAR szRest = szMouseLoc;

/*INSERTED BELOW TO FIX /CLICK LEFT/RIGHT ITEM/TARGET*/ 
   RECT LastRect = {0}; 
   RECT Rect = {0}; 
   HWND hWnd = NULL; 
   DWORD Mode = 0; 
   LONG x, y; 
   BOOL Found = FALSE; 
   DWORD ID = 0; 

   hWnd = FindWindow("EQWND",NULL); 
   if (!hWnd) hWnd = FindWindow("_EverQuestwndclass",NULL); 
   if (!hWnd) {
	   DebugSpew("ParseMouseLoc: Unable to find EQ Window!");
	   return FALSE;
   }
   GetClientRect(hWnd,&Rect); 
   if (Rect.right < 640) { 
      CopyMemory(&Rect,&LastRect,sizeof(RECT)); 
   } else { 
      CopyMemory(&LastRect,&Rect,sizeof(RECT)); 
   } 
   DebugSpew("ClientRect: %d,%d",Rect.right,Rect.bottom); 

   switch (Rect.right) { 
      case 640: 
         Mode=1; 
         break; 
      case 800: 
      case 848: 
         Mode=2; 
         break; 
      case 1024: 
         Mode=4; 
         break; 
      case 1150: 
      case 1280: 
      case 1360: 
         Mode=6; 
         break; 
      case 1600: 
         Mode=8; 
         break; 
      default: 
         Mode=2; 
         break; 
   } 
/*INSERTED ABOVE TO FIX /CLICK LEFT/RIGHT ITEM/TARGET*/

	if (!szMouseLoc) { // no mouseloc was passed - should not happen
		DebugSpew("Invalid call to ParseMouseLoc: No pointer to szMouseLoc");
		return FALSE;
	}

	// Mouse location is either specified by X and Y position or by object reference
	// [+|-]<x> [+|-]<y>
	// auto
	// destroy
	// hslider
	// corpse <slot>|done
	// merchant <slot>|buy|sell|done
	// hotkey <slot>|previous|next
	// enviro <slot>|combine|done
	// npctrade <slot>|give
	// [bank] plat|gold|silver|copper
	// [bank] inv <slot>
	// [bank] pack <num> <slot>|combine|done
	// button <ClickLocation>
	// <ClickLocation>

	// determine mouse location - x and y given
	if ((szMouseLoc[0]=='+') || (szMouseLoc[0]=='-') || ((szMouseLoc[0]>='0') && (szMouseLoc[0]<='9')))
	{ // x and y were given so lets convert them and move mouse
		GetArg(szArg1,szMouseLoc,1);
		GetArg(szArg2,szMouseLoc,2);
		ClickX = atoi(szArg1);
		ClickY = atoi(szArg2);
		if ((szArg1[0]=='+') || (szArg1[0]=='-') || (szArg2[0]=='+') || (szArg2[0]=='-'))
		{ // relative location was passed so offset from current
			ClickX += EQADDR_MOUSE->X;
			ClickY += EQADDR_MOUSE->Y;
			DebugSpew("Moving mouse by relative offset");
		} else {
			DebugSpew("Moving mouse to absolute position");
		}
		return MoveMouse(ClickX,ClickY);
		
	}

	// determine mouse location name
	CHAR szPack[MAX_STRING] = {0};
	int Bank = 0;
	int Pack = 99;
	int Slot = 99;
	int Max_Slots = 0;	// used to determine slots in pack
	int Combiner = 0;		// 0 = no, 1 = has combiner button
	int Adjust_y = 0;
	PITEMINFO pPack = 0;	// used to verify pack info

	// check for optional keyword bank
	GetArg(szArg1,szRest,1);
	if (!strnicmp(szArg1,"bank",4))
	{
		szRest = GetNextArg(szRest,1);
		if (!szRest)
		{
			DebugSpew("Invalid mouseloc: %s",szMouseLoc);
			return FALSE;
		}
		GetArg(szArg1,szRest,1);
//		DWORD BankWnd = pBankWnd;
		DWORD NumBankSlots = pBankWnd->GetNumBankSlots();
		/*
		__asm {
	        push eax;
			push ecx;
			mov ecx, dword ptr [BankWnd];
			call dword ptr [EQADDR_GETNUMBANKSLOTS];
			mov [NumBankSlots], eax;
			pop ecx;
			pop eax;
		}
		/**/
		DebugSpew("NumBankSlots = %d",NumBankSlots);
		if(NumBankSlots>=16) {
			Bank = 15;
		} else {
			Bank = 7;
		}
	}			
	GetArg(szArg2,szRest,2);
	GetArg(szArg3,szRest,3);

	if (!strnicmp(szArg1,"auto",4))
	{ // mouseloc = auto
		strcpy(ClickLocation,"auto");
		DebugSpew("Mouse moved using mouseloc: auto");
	}
	else if (!strnicmp(szArg1,"destroy",7))
	{ // mouseloc = destroy
		strcpy(ClickLocation,"destroy");
		DebugSpew("Mouse moved using mouseloc: destroy");
	}
	else if (!strnicmp(szArg1,"hslider",7))
	{ // mouseloc = hslider
		// TODO: saw this in there no idea what it's for so
		strcpy(ClickLocation,"hslider");
		DebugSpew("Mouse moved using mouseloc: hslider");
	}
	else if (!strnicmp(szArg1,"corpse",6))
	{ // mouseloc = corpse <slot>|done
		if (szArg2[0]==0)
		{
			DebugSpew("Mouseloc corpse missing arg: %s",szMouseLoc);
			return FALSE;
		}
		if (!strnicmp(szArg2,"done",4))
		{
			strcpy(ClickLocation,"corpse_done");
			DebugSpew("Mouse moved using mouseloc: corpse done");
		}
		else
		{
			Slot = atol(szArg2);
			if ((Slot < 0) || (Slot > 29))
			{ // invalid slot number for loot abort
				WriteChatColor("Invalid slot specified for corpse <slot>",USERCOLOR_DEFAULT);
				DebugSpew("Invalid corpse slot specified: %s",szMouseLoc);
				return FALSE;
			}
			sprintf(ClickLocation,"corpse_%d",Slot);
			DebugSpew("Mouse moved using mouseloc: corpse %d",Slot);
		}
	}
	else if (!strnicmp(szArg1,"merch",5))
	{ // mouseloc = merchant <slot>|buy|sell|done
		if (szArg2[0]==0)
		{
			DebugSpew("Mouseloc merchant missing arg: %s",szMouseLoc);
			return FALSE;
		}
		if (!strnicmp(szArg2,"done",4))
		{
			strcpy(ClickLocation,"merchant_done");
			DebugSpew("Mouse moved using mouseloc: merchant done");
		}
		else if (!strnicmp(szArg2,"sell",4))
		{
			strcpy(ClickLocation,"merchant_sell");
			DebugSpew("Mouse moved using mouseloc: merchant sell");
		}
		else if (!strnicmp(szArg2,"buy",3))
		{
			strcpy(ClickLocation,"merchant_buy");
			DebugSpew("Mouse moved using mouseloc: merchant buy");
		}
		else
		{ // not reserved word so use as slot number
			Slot = atol(szArg2);
			if ((Slot < 0) || (Slot > 79))
			{
				DebugSpew("Mouseloc merchant has invalid slot: %s",szMouseLoc);
				return FALSE;
			}
			sprintf(ClickLocation,"merchant_%d",Slot);
			DebugSpew("Mouse moved using mouseloc: merchant %d",Slot);
		}
	}
	else if (!strnicmp(szArg1,"hotkey",6))
	{ // mouseloc = hotkey <slot>|previous|next
		if (szArg2[0]==0)
		{
			DebugSpew("Mouseloc hotkey missing arg: %s",szMouseLoc);
			return FALSE;
		}
		if (!strnicmp(szArg2,"prev",4))
		{
			strcpy(ClickLocation,"hotkey_prev");
			DebugSpew("Mouse moved using mouseloc: hotkey previous");
		}
		else if (!strnicmp(szArg2,"next",4))
		{
			strcpy(ClickLocation,"hotkey_next");
			DebugSpew("Mouse moved using mouseloc: hotkey next");
		}
		else
		{ // not reserved word so slot number
			Slot = atol(szArg2);
			if ((Slot < 0) || (Slot > 9))
			{
				DebugSpew("Mouseloc hotkey has invalid slot: %s",szMouseLoc);
				return FALSE;
			}
			sprintf(ClickLocation,"hotkey_%d",Slot + 1);
			DebugSpew("Mouse moved using mouseloc: hotkey %d",Slot);
		}
	}
	else if (!strnicmp(szArg1,"enviro",6))
	{ // mouseloc = enviro <slot>|combine|done
		if (szArg2[0]==0)
		{
			DebugSpew("Mouseloc hotkey missing arg: %s",szMouseLoc);
			return FALSE;
		}
		if (!strnicmp(szArg2,"done",4))
		{
			strcpy(ClickLocation,"enviro_done");
			DebugSpew("Mouse moved using mouseloc: enviro done");
		}
		else if (!strnicmp(szArg2,"combine",7))
		{
			strcpy(ClickLocation,"enviro_combine");
			DebugSpew("Mouse moved using mouseloc: enviro combine");
		}
		else
		{
			Slot = atol(szArg2);
			if ((Slot < 0) || (Slot > 9))
			{ // all enviro containers are 10 slot
				DebugSpew("Mouseloc enviro has invald slot: %s",szMouseLoc);
				return FALSE;
			}
			sprintf(ClickLocation,"enviro_%d",Slot);
			DebugSpew("Mouse moved using mouseloc: enviro %d",Slot);
		}
	}
	else if (!strnicmp(szArg1,"npctrade",8))
	{ // mouseloc = npctrade <slot>|give
		if (szArg2[0]==0)
		{
			DebugSpew("Mouseloc hotkey missing arg: %s",szMouseLoc);
			return FALSE;
		}
		if (!strnicmp(szArg2,"give",4))
		{
			strcpy(ClickLocation,"npctrade_give");
			DebugSpew("Mouse moved using mouseloc: npctrade give");
		}
		else if (!strnicmp(szArg2,"plat",4))
		{
			strcpy(ClickLocation,"npctrade_plat");
			DebugSpew("Mouse moved using mouseloc: npctrade plat");
		}
		else if (!strnicmp(szArg2,"gold",4))
		{
			strcpy(ClickLocation,"npctrade_gold");
			DebugSpew("Mouse moved using mouseloc: npctrade gold");
		}
		else if (!strnicmp(szArg2,"silver",6))
		{
			strcpy(ClickLocation,"npctrade_silver");
			DebugSpew("Mouse moved using mouseloc: npctrade silver");
		}
		else if (!strnicmp(szArg2,"copper",6))
		{
			strcpy(ClickLocation,"npctrade_copper");
			DebugSpew("Mouse moved using mouseloc: npctrade copper");
		}
		else
		{
			Slot = atol(szArg2);
			if ((Slot < 0) || (Slot > 3))
			{ // give window has 4 slots
				DebugSpew("Invalid npctrade slot in mouseloc: %s",szMouseLoc);
				return FALSE;
			}
			sprintf(ClickLocation,"npctrade_%d",Slot);
			DebugSpew("Mouse moved using mouseloc: npctrade %d",Slot);
		}
	}
	else if (!strnicmp(szArg1,"plat",4))
	{ // mouseloc = [bank] plat
		if (Bank==15)
		{ // plat in bank
			strcpy(ClickLocation,"bigbank_plat");
			DebugSpew("Mouse moved using mouseloc: bank plat");
		}
		else if (Bank==7)
		{
			strcpy(ClickLocation,"bank_plat");
			DebugSpew("Mouse moved using mouseloc: bank plat");
		}
		else
		{
			strcpy(ClickLocation,"inv_plat");
			DebugSpew("Mouse moved using mouseloc: plat");
		}
	}
	else if (!strnicmp(szArg1,"shared",4))
	{ // mouseloc = [bank] shared
		if (Bank==15)
		{ // shared plat in bank
			strcpy(ClickLocation,"bigbank_shared");
			DebugSpew("Mouse moved using mouseloc: bank plat");
		}
		else if (Bank==7)
		{
			strcpy(ClickLocation,"bank_shared");
			DebugSpew("Mouse moved using mouseloc: bank plat");
		}
	}
	else if (!strnicmp(szArg1,"gold",4))
	{ // mouseloc = [bank] gold
		if (Bank==15)
		{ // plat in bank
			strcpy(ClickLocation,"bigbank_gold");
			DebugSpew("Mouse moved using mouseloc: bank gold");
		}
		else if (Bank==7)
		{
			strcpy(ClickLocation,"bank_gold");
			DebugSpew("Mouse moved using mouseloc: bank gold");
		}
		else
		{
			strcpy(ClickLocation,"inv_gold");
			DebugSpew("Mouse moved using mouseloc: gold");
		}
	}
	else if (!strnicmp(szArg1,"silver",6))
	{ // mouseloc = [bank] silver
		if (Bank==15)
		{ // plat in bank
			strcpy(ClickLocation,"bigbank_silver");
			DebugSpew("Mouse moved using mouseloc: bank silver");
		}
		else if (Bank==7)
		{
			strcpy(ClickLocation,"bank_silver");
			DebugSpew("Mouse moved using mouseloc: bank silver");
		}
		else
		{
			strcpy(ClickLocation,"inv_silver");
			DebugSpew("Mouse moved using mouseloc: silver");
		}
	}
	else if (!strnicmp(szArg1,"copper",6))
	{ // mouseloc = [bank] copper
		if (Bank==15)
		{ // plat in bank
			strcpy(ClickLocation,"bigbank_copper");
			DebugSpew("Mouse moved using mouseloc: bank copper");
		}
		else if (Bank==7)
		{
			strcpy(ClickLocation,"bank_copper");
			DebugSpew("Mouse moved using mouseloc: bank copper");
		}
		else
		{
			strcpy(ClickLocation,"inv_copper");
         DebugSpew("Mouse moved using mouseloc: copper"); 
      } 

/*INSERTED BELOW TO FIX /CLICK LEFT/RIGHT ITEM/TARGET*/ 
   } else if (!strnicmp(szArg1,"item",4)) { 
      if (EnviroTarget.Name[0]==0) return FALSE; 
      //DWORD clsItems = *(DWORD*)EQADDR_CLSITEMS; 
      for (y=0;(y<Rect.bottom) && (!Found);y+=2*(1+Mode)) { 
         for (x=0;(x<Rect.right) && (!Found);x+=2*(1+Mode)) { 
			 ID=(DWORD)pDisplay->GetClickedActor(x,y,0);
			 /*
            __asm { 
               push ecx 
               push eax 
               push 0 
               push [y] 
               push [x] 
               mov ecx, dword ptr [clsItems] 
               call dword ptr[ScreenItem] 
               mov [ID], eax 
               pop eax 
               pop ecx 
            } 
			/**/

            if (ID == EnviroTarget.GuildID) { 
               MouseInfo->X = x; 
               MouseInfo->Y = y; 
               Found=TRUE; 
            } 
         } 
      } 
      //Could probably just return Found here, and get rid of if statement... 
      if (!Found) { return FALSE; } else return TRUE; 
   } else if (!strnicmp(szArg1,"target",6)) { 
      if (!ppTarget) return FALSE; 
      if (!pTarget) return FALSE; 
      PSPAWNINFO psTarget = (PSPAWNINFO)pTarget; 
      for (y=0;(y<Rect.bottom) && (!Found);y+=2*(1+Mode)) { 
         for (x=0;(x<Rect.right) && (!Found);x+=2*(1+Mode)) { 
			 ID=(DWORD)pEverQuest->ClickedPlayer(x,y);
			 /*
            __asm { 
               push ecx 
               push eax 
               push [y] 
               push [x] 
               mov ecx, dword ptr [EQADDR_CLSSPAWNS] 
               call dword ptr[ScreenSpawn] 
               mov [ID], eax 
               pop eax 
               pop ecx 
            } 
			/**/
            if (ID == (DWORD)psTarget) { 
               MouseInfo->X = x; 
               MouseInfo->Y = y; 
               Found=TRUE; 
            } 
         } 
      } 
      //Could probably just return Found here, and get rid of if statement... 
      if (!Found) { return FALSE; } else return TRUE; 
/*INSERTED ABOVE TO FIX /CLICK LEFT/RIGHT ITEM/TARGET*/ 

   } else if (!strnicmp(szArg1,"inv",3)) 
	{ // mouseloc = [bank] inv <slot>
		if (szArg2[0]==0)
		{
			DebugSpew("Mouseloc [bank] inv missing arg: %s",szMouseLoc);
			return FALSE;
		}
		Slot = atol(szArg2);
		if ((Slot < 0) || (!Bank && (Slot > 7)) || (Bank && (Slot > Bank)))
		{
			DebugSpew("Invalid slot in mouseloc: %s",szMouseLoc);
			return FALSE;
		}
		if (Bank==15)
		{
			sprintf(ClickLocation,"bigbank_%d",Slot);
			DebugSpew("Mouse moved using mouseloc: bank inv %d",Slot);
		}
		else if (Bank==7)
		{
			sprintf(ClickLocation,"bank_%d",Slot);
			DebugSpew("Mouse moved using mouseloc: bank inv %d",Slot);
		}
		else
		{
			sprintf(ClickLocation,"inv_%d",Slot);
			DebugSpew("Mouse moved using mouseloc: inv %d",Slot);
		}
	}
	else if (!strnicmp(szArg1,"pack",4))
	{ // mouseloc = [bank] pack <pack> <slot>|combine|done
		if ((szArg2[0]==0) || (szArg3[0]==0))
		{
			DebugSpew("Mouseloc [bank] pack missing arg(s): %s",szMouseLoc);
			return FALSE;
		}
		Pack = atol(szArg2);
		if ((Pack < 0) || (!Bank && (Pack > 7)) || (Bank && (Pack > Bank)))
		{
			DebugSpew("Invalid pack in mouseloc: %s",szMouseLoc);
			return FALSE;
		}
		// TODO: find out whether pack is a combiner
		if (Bank==0)
		{
			if (!(pPack = pCharInfo->Inventory[22+Pack]->Item))
			{
				DebugSpew("No item pointer for (*pCharInfo->Inventory[%d])",22+Pack);
				return FALSE;
			}
		}
		else
		{
			if (!(pPack = pCharInfo->Bank[Pack]->Item))
			{
				DebugSpew("No item pointer for (*pCharInfo->Bank[%d])",Pack);
				return FALSE;
			}
		}
		if (pPack->Type != ITEMTYPE_PACK)
		{
			DebugSpew("Pack access attempted on nonPack in mouseloc: %s",szMouseLoc);
			return FALSE;
		}
		Max_Slots = pPack->Container.Slots;
		Combiner = pPack->Container.Combine;
		DebugSpew("Pack has %d Slots and Combiner type %d",Max_Slots,Combiner);

		if (Bank==0)
		{ // not a bank bag
			sprintf(szPack,"inv_pack%d",Pack);
		}
		else
		{ // a bank bag - both bank sizes name bags same
			sprintf(szPack,"bank_pack%d",Pack);
		}
		if (!strnicmp(szArg3,"done",4))
		{
			Adjust_y = ((10 - Max_Slots) / 2) * 40;
			sprintf(ClickLocation,"%s_done",szPack);
			DebugSpew("Pack %s Offset for Done = %d",ClickLocation,Adjust_y);
			DebugSpew("Mouse moved using mouseloc: [bank] pack %d done",Pack);
		}
		else if (!strnicmp(szArg3,"combine",7))
		{
			Adjust_y = ((10 - Max_Slots) / 2) * 40;
			sprintf(ClickLocation,"%s_combine",szPack);
			DebugSpew("Pack %s Offset for Combine = %d",ClickLocation,Adjust_y);
			DebugSpew("Mouse moved using mouseloc: [bank] pack %d combine",Pack);
		}
		else
		{
			Slot = atol(szArg3);
			if ((Slot < 0) || ((Slot + 1) > Max_Slots))
			{
				DebugSpew("Invalid Slot in pack: [bank] pack %d %d",Pack,Slot);
				return FALSE;
			}
			sprintf(ClickLocation,"%s_%d",szPack,Slot);
			DebugSpew("Mouse moved using mouseloc: pack %d %d",Pack,Slot);
		}
	}
	else if (!stricmp(szArg1,"button"))
	{ // user specified click location
		strncpy(ClickLocation,szArg2,MAX_STRING);
		DebugSpew("Mouse moved using user specified: button %s",szArg2);
	}
	else
	{ // does not follow conventions so assume user just passed button name
		strncpy(ClickLocation,szMouseLoc,MAX_STRING);
		DebugSpew("Unknown mouseloc - using as button name: %s",szMouseLoc);
	}


	//Get path to EverQuest directory 
	GetEQPath(gszEQPath);

	sprintf(Locations,"%s\\locations.txt",gszINIPath); //Locations filename 

	sprintf(EQClient, "%s\\eqclient.ini", gszEQPath); 
	GetPrivateProfileString("VideoMode","Width","800",ScreenX,MAX_STRING,EQClient); 
	GetPrivateProfileString("VideoMode","Height","600",ScreenY,MAX_STRING,EQClient); 

	//need to change ScreenX and ScreenY to fit UI ini format, for example XPos800x600 
	sprintf(temp, "%sx%s", ScreenX, ScreenY); 
	sprintf(ScreenX, "XPos%s", temp); //changed ScreenX format to fit resolution formats in UI ini file 
	sprintf(ScreenY, "YPos%s", temp); //changed ScreenY format to fit resolution formats in UI ini file 
	sprintf(ScreenW, "Width%s", temp);	//resizable windows have stored width
	sprintf(ScreenH, "Height%s", temp);	//resizable windows have stored height

	//develop full character UI ini file name 

	if (!EQADDR_SERVERNAME) 
		return FALSE;
	sprintf(UIFile,"%s\\UI_%s_%s.ini",gszEQPath,pCharInfo->Name,EQADDR_SERVERNAME); 

	//Get the current character skin. Will use that to find XML files 
	GetPrivateProfileString("Main","UISkin","default",SkinName,MAX_STRING,UIFile); 

	//Parse the locations file 
	GetPrivateProfileString(ClickLocation,"UILabel",".",UILabel,MAX_STRING,Locations); 
	GetPrivateProfileString(ClickLocation,"XMLFile",".",XMLFile,MAX_STRING,Locations); 
	GetPrivateProfileString(ClickLocation,"ScreenID",".",ScreenID,MAX_STRING,Locations); 

	//Using info from locations file, get the base X Y coordinates 
	GetPrivateProfileString(UILabel,ScreenX,"0",ButtonX,MAX_STRING,UIFile); //base window X coord 
	GetPrivateProfileString(UILabel,ScreenY,"0",ButtonY,MAX_STRING,UIFile); //base window Y coord 
	GetPrivateProfileString(UILabel,ScreenW,"0",ButtonW,MAX_STRING,UIFile); //base window width
	GetPrivateProfileString(UILabel,ScreenH,"0",ButtonH,MAX_STRING,UIFile); //base window height
	DebugSpew("Values from UIFile: X=%s  Y=%s  W=%s  H=%s",ButtonX, ButtonY, ButtonW, ButtonH);

	//Develop a path\file from XMLFile 
	sprintf(temp, "%s\\uifiles\\%s\\%s", gszEQPath, SkinName, XMLFile); 
	input = fopen(temp,"rt"); //using fopen to test for the existence of custom UI file 
	if (input == NULL) 
	{ //if input is null, the custom file doesn't exist, so we use the default file 
		sprintf(temp, "%s\\uifiles\\default\\%s",gszEQPath,XMLFile); 
	} else {fclose(input);} 
	strcpy(XMLFile, temp); 
	// XMLFile should now contain the complete path to an existing XML skin file 

	//use Clawed's parser on XMLFile, ScreenID 

	XMLloc = ParseLocationXML(XMLFile,ScreenID,atol(ButtonW),atol(ButtonH)); 

	if (XMLloc.error[0] != 0)
	{ // error parsing xml
		DebugSpew("Parsing error on MouseLoc (%s): %s",szMouseLoc,XMLloc.error);
		return FALSE;
	}

	DebugSpew("Adjust_y = %d",Adjust_y);

	//move the mouse to coordinates from above 
	ClickX = (atoi(ButtonX) + XMLloc.x + (int)(XMLloc.w/2)); 
	ClickY = (atoi(ButtonY) + XMLloc.y + (int)(XMLloc.h/2) - Adjust_y); 
	return MoveMouse(ClickX, ClickY); 

	//return to Click so we can now click on the new location 
} 

VOID SendEQMessage(DWORD PacketType, PVOID pData, DWORD Length)
{
	if (!send_message || !EQADDR_GWORLD) 
	{
		return;
	}
	send_message(EQADDR_GWORLD,PacketType,pData,Length,TRUE);
}


// *************************************************************************** 
// Function: Click 
// Description: Our '/click' command 
// Clicks the mouse button (calls EQ's mouse up commands) 
// Usage: /click left|right [<mouseloc>] 
// *************************************************************************** 
VOID Click(PSPAWNINFO pChar, PCHAR szLine) { 
   CHAR szArg1[MAX_STRING] = {0}; 
   PCHAR szMouseLoc; 
   MOUSE_DATA_TYPES mdType = MD_Unknown; 
   DWORD RightOrLeft = 0; 

   GetArg(szArg1, szLine, 1); //left or right 
   szMouseLoc = GetNextArg(szLine, 1); //location to click 
    
   //parse location for click location (szMouseLoc) here 
   if (szMouseLoc && szMouseLoc[0]!=0) { 
      if (!strnicmp(szMouseLoc, "target", 6)) { 
         if (!strnicmp(szArg1, "left", 4)) { 
//            if(!EQADDR_LCLICKTARGET) return; 
				pEverQuest->LeftClickedOnPlayer(pTarget);
//            RightOrLeft = EQADDR_LCLICKTARGET; 
         } else if (!strnicmp(szArg1, "right", 5)) { 
//            if (!EQADDR_RCLICKTARGET) return; 
//            RightOrLeft = EQADDR_RCLICKTARGET; 
			 pEverQuest->RightClickedOnPlayer(pTarget);
         } 
		 /*
         DWORD CEverQuest = 0; 
         CEverQuest = (DWORD)*EQADDR_CLSMAINNEWUI; 
         DWORD psTarget = NULL; 
         if (ppTarget && *(DWORD *)ppTarget) { 
            psTarget = *(DWORD *)ppTarget; 
            __asm { 
               push ecx; 
               push psTarget; 
               mov ecx, dword ptr [CEverQuest]; 
               call dword ptr [RightOrLeft]; 
               pop ecx; 
            } 
         } 
		 /**/
         return; 
	  } else if (!strnicmp(szMouseLoc, "item", 4)) {
			// a right clicked ground spawn does nothing
			if (!strnicmp(szArg1, "left", 4) && EnviroTarget.Name[0]!=0 && DistanceToSpawn(pChar,&EnviroTarget)<20.0f) {
				INTERACTGROUNDITEM Data;
				Data.SpawnID = GetCharInfo()->pSpawn->SpawnID;
				Data.DropID = EnviroTarget.Race;
				SendEQMessage(EQ_INTERACTGROUNDITEM,&Data,sizeof(INTERACTGROUNDITEM));
				EnviroTarget.Name[0]=0;
				if (pTarget==(EQPlayer*)&EnviroTarget) pTarget=NULL;
				return;
			}
      } else if (!ParseMouseLoc(GetCharInfo(), szMouseLoc)) { 
         DebugSpew("Invalid mouse loc to click, aborting: %s",szMouseLoc); 
         return; 
      } 
   } 
    
   if (szArg1[0]!=0) { 
      if (!strnicmp(szArg1, "left", 4)) { 
         mdType = MD_Button0; 
         MouseClickL(pChar,szLine); 
      } else if (!strnicmp(szArg1, "right", 5)) { 
         mdType = MD_Button1; 
            MouseClickR(pChar,szLine); 
        } else { 
           WriteChatColor("Usage: /click <left|right>",USERCOLOR_DEFAULT); 
           DebugSpew("Bad command: %s",szLine); 
           return; 
        } 
        PMOUSESPOOF pData = (PMOUSESPOOF)malloc(sizeof(MOUSESPOOF)); 
        pData->mdType = mdType; 
        pData->dwData = 0x00; 
        pData->pNext = NULL; 
        if (!gMouseData) { 
           gMouseData = pData; 
        } else { 
           PMOUSESPOOF pTemp = gMouseData; 
           while (pTemp->pNext) { 
              pTemp = pTemp->pNext; 
           } 
           pTemp->pNext = pData; 
        } 
    } 
}


// *************************************************************************** 
// Function: MouseTo 
// Description: Our '/mouseto' command 
// Moves the mouse 
// Usage: /mouseto <mouseloc>
// *************************************************************************** 
VOID MouseTo(PSPAWNINFO pChar, PCHAR szLine) 
{
	if (szLine && szLine[0])
		if (ParseMouseLoc(GetCharInfo(), szLine))
			return;

	WriteChatColor("Usage: /mouseto <mouseloc>",USERCOLOR_DEFAULT); 
	DebugSpew("Help invoked or Bad MouseTo command: %s",szLine); 
}

/*
 * Motd and Pulse's mouse functions
 */

BOOL IsMouseWaitingForButtonDownL()
{
	return ((EQADDR_MOUSECLICK->LeftClick == 0x80) && (!EQADDR_MOUSECLICK->ConfirmLeftClick)) ? TRUE : FALSE;
}

BOOL IsMouseWaitingForButtonDownR()
{
	return ((EQADDR_MOUSECLICK->RightClick == 0x80) && (!EQADDR_MOUSECLICK->ConfirmRightClick)) ? TRUE : FALSE;
}

BOOL IsMouseWaitingForButtonUpL()
{
	return ((!EQADDR_MOUSECLICK->LeftClick) && (EQADDR_MOUSECLICK->ConfirmLeftClick == 0x80)) ? TRUE : FALSE;
}


BOOL IsMouseWaitingForButtonUpR()
{
	return ((!EQADDR_MOUSECLICK->RightClick) && (EQADDR_MOUSECLICK->ConfirmRightClick == 0x80)) ? TRUE : FALSE;
}




VOID SetMouseButtonDownL()
{
	if (!IsMouseWaitingForButtonDownL()) EQADDR_MOUSECLICK->LeftClick = 0x80;

}

VOID SetMouseButtonDownR()
{
	if (!IsMouseWaitingForButtonDownR()) EQADDR_MOUSECLICK->RightClick = 0x80;
}


VOID SetMouseButtonUpL()
{
	if (!IsMouseWaitingForButtonUpL()) EQADDR_MOUSECLICK->LeftClick = 0x0;
}


VOID SetMouseButtonUpR()
{
	if (!IsMouseWaitingForButtonUpR()) EQADDR_MOUSECLICK->RightClick = 0x0;
}

BOOL IsMouseWaitingForButton()
{
	return ((EQADDR_MOUSECLICK->RightClick == EQADDR_MOUSECLICK->ConfirmRightClick) 
		&& (EQADDR_MOUSECLICK->LeftClick == EQADDR_MOUSECLICK->ConfirmLeftClick)) ? FALSE : TRUE;
}


BOOL IsMouseWaiting()
{
	BOOL Result = FALSE;

	if (IsMouseWaitingForButton()) Result = TRUE;
	else {
		// Here we basically force the MQ script engine to wait for the button up on mouse clicks

		if (gMouseLeftClickInProgress) {
			SetMouseButtonUpL();
			gMouseLeftClickInProgress = FALSE;
			Result = TRUE;
		}
		if (gMouseRightClickInProgress) {
			SetMouseButtonUpR();
			gMouseRightClickInProgress = FALSE;
			Result = TRUE;
		}
		
	}
	return Result;

}

VOID MouseClickL(PSPAWNINFO pChar, PCHAR szLine)
{
	SetMouseButtonDownL();
	gMouseLeftClickInProgress = TRUE;

}

VOID MouseClickR(PSPAWNINFO pChar, PCHAR szLine)
{
	SetMouseButtonDownR();
	gMouseRightClickInProgress = TRUE;

}


VOID LClickDown (PSPAWNINFO pChar, PCHAR szLine)
{

	CHAR szMsg[MAX_STRING] = {0};
	
	SetMouseButtonDownL();

	sprintf(szMsg,"Sending mouse left button down");
	WriteChatColor(szMsg,CONCOLOR_RED);
}

VOID LClickUp (PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szMsg[MAX_STRING] = {0};
	
	SetMouseButtonUpL();

	sprintf(szMsg,"Sending mouse left button up");
	WriteChatColor(szMsg,CONCOLOR_RED);

}

VOID RClickDown (PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szMsg[MAX_STRING] = {0};
	
	SetMouseButtonDownR();

	sprintf(szMsg,"Sending mouse right button down");
	WriteChatColor(szMsg,CONCOLOR_RED);

}

VOID RClickUp (PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szMsg[MAX_STRING] = {0};
	
	SetMouseButtonUpR();

	sprintf(szMsg,"Sending mouse left button down");
	WriteChatColor(szMsg,CONCOLOR_RED);

}

