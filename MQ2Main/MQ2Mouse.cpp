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
	CHAR szArg1[MAX_STRING] = {0};
	CHAR szArg2[MAX_STRING] = {0};
	int ClickX; //actual location to click, calculated from ButtonX 
	int ClickY; //actual location to click, calculated from ButtonY 

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
	MacroError("'%s' mouse click is either invalid or should be done using /notify",szMouseLoc);
	return FALSE;
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
			//SetMouseButtonUpL();
			if (!((!EQADDR_MOUSECLICK->LeftClick) && (EQADDR_MOUSECLICK->ConfirmLeftClick == 0x80))) EQADDR_MOUSECLICK->LeftClick = 0x0;
			gMouseLeftClickInProgress = FALSE;
			Result = TRUE;
		}
		if (gMouseRightClickInProgress) {
			//SetMouseButtonUpR();
			if (!((!EQADDR_MOUSECLICK->RightClick) && (EQADDR_MOUSECLICK->ConfirmRightClick == 0x80))) EQADDR_MOUSECLICK->RightClick = 0x0;
			gMouseRightClickInProgress = FALSE;
			Result = TRUE;
		}
		
	}
	return Result;
}

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
      if (!pTarget) { 
        WriteChatColor("You must have a target selected for /click x target.",CONCOLOR_RED); 
        return; 
      } 
         if (!strnicmp(szArg1, "left", 4)) { 
             pEverQuest->LeftClickedOnPlayer(pTarget); 
         } else if (!strnicmp(szArg1, "right", 5)) { 
          pEverQuest->RightClickedOnPlayer(pTarget); 
         } 
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
         //SetMouseButtonDownL();
		 if (!((EQADDR_MOUSECLICK->LeftClick == 0x80) && (!EQADDR_MOUSECLICK->ConfirmLeftClick))) EQADDR_MOUSECLICK->LeftClick = 0x80;
         gMouseLeftClickInProgress = TRUE; 
      } else if (!strnicmp(szArg1, "right", 5)) { 
         mdType = MD_Button1;
         //SetMouseButtonDownR();
		 if (!((EQADDR_MOUSECLICK->RightClick == 0x80) && (!EQADDR_MOUSECLICK->ConfirmRightClick))) EQADDR_MOUSECLICK->RightClick = 0x80;
         gMouseRightClickInProgress = TRUE;
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
