/***************************************************************************** 
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest 
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

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
// EqMule Mar 08 2014
// Adding a detour here
// All it does is check if EnviroTarget.StandState==STANDSTATE_STAND
// if it is, we know the user issued a /click left item
// so we force the return of the correct switch...
// That will have the effect of actually "clicking" it...
// ***************************************************************************
class FakeCDisplay
{
public:
	struct T3D_tagACTORINSTANCE *GetClickedActor_Tramp(unsigned long,unsigned long,unsigned long,void *,void *);
	struct T3D_tagACTORINSTANCE *GetClickedActor_Detour(unsigned long X,unsigned long Y,unsigned long Flag,void *Vector1,void *Vector2)
	{
		if(pGroundTarget && EnviroTarget.Name[0]!=0 && (EnviroTarget.StandState==STANDSTATE_STAND || EnviroTarget.StandState==STANDSTATE_SIT)) {
			//we do this to take both mousedown and mouseup into account
			if(EnviroTarget.StandState==STANDSTATE_STAND) {
				EnviroTarget.StandState=STANDSTATE_SIT;
			} else if(EnviroTarget.StandState==STANDSTATE_SIT) {
				EnviroTarget.StandState=STANDSTATE_DEAD;
			}
			return (T3D_tagACTORINSTANCE*)pGroundTarget->pSwitch;
		} else {
			return GetClickedActor_Tramp(X,Y,Flag,Vector1,Vector2);
		}
	}
};
DETOUR_TRAMPOLINE_EMPTY(struct T3D_tagACTORINSTANCE *FakeCDisplay::GetClickedActor_Tramp(unsigned long,unsigned long,unsigned long,void *,void *)); 

void MQ2MouseHooks(BOOL bFlag)
{
	if(bFlag) {
		EzDetour(CDisplay__GetClickedActor,&FakeCDisplay::GetClickedActor_Detour,&FakeCDisplay::GetClickedActor_Tramp);
	} else {
		RemoveDetour(CDisplay__GetClickedActor);
	}
}
// *************************************************************************** 
// Function: ParseMouseLoc 
// Description: Parses mouseloc for /click and /mouseto 
// *************************************************************************** 
//Function used by ParseLocationXML to extract parameter
// ExtractValue - gets value between specified start and end markers
// - Parameters:
// szFile - pointer to string to look in
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

#ifndef ISXEQ

// TODO: Expand this to support mouse buttons 3->8
VOID ClickMouse(DWORD button)
{
   if (button > 1)
      return;
   DWORD mdType = (DWORD)MD_Button0 + button;

   if (!((EQADDR_MOUSECLICK->Click[button] == 0x80) && (!EQADDR_MOUSECLICK->Confirm[button])))
      EQADDR_MOUSECLICK->Click[button] = 0x80;

   gMouseClickInProgress[button] = TRUE;

   gMouseEventTime = GetFastTime();
   PMOUSESPOOF pData = (PMOUSESPOOF)malloc(sizeof(MOUSESPOOF));
   pData->mdType = (MOUSE_DATA_TYPES)mdType;
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

VOID MouseButtonUp(DWORD x, DWORD y, PCHAR szButton)
{
    float c[3];
    gLClickedObject=false;
    
    if(!strnicmp(szButton,"left",4))
    {
        // click will fail if this isn't set to a time less than TimeStamp minus 750ms
        *((DWORD*)__LMouseHeldTime)=((PCDISPLAY)pDisplay)->TimeStamp-0x45;
        pEverQuest->LMouseUp(x,y);

        if(((CDisplay*)pDisplay)->GetClickedActor(x,y,0,&c,&c))
        {
            gLClickedObject=true;
            EnviroTarget.Name[0]=0;
        }
    }

    /* i don't think there's any use for this currently - ieatacid
    else if(!strnicmp(szButton,"right",5))
    {
        // click will fail if this isn't set to a time less than TimeStamp minus 500ms
        *((DWORD*)__RMouseHeldTime)=((PCDISPLAY)pDisplay)->TimeStamp-0x45;
        pEverQuest->RMouseUp(x,y);
    }*/
}

VOID ClickMouseLoc(PCHAR szMouseLoc, PCHAR szButton) 
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
            DebugSpew("Clicking mouse by relative offset");
        } else {
            DebugSpew("Clicking mouse at absolute position");
        }
        MouseButtonUp(ClickX,ClickY,szButton);
    }
    else
    {
        MacroError("'%s' mouse click is either invalid or should be done using /notify",szMouseLoc);
    }
}
#endif

#ifndef ISXEQ_LEGACY

// *************************************************************************** 
// Function: Click 
// Description: Our '/click' command 
// Clicks the mouse button (calls EQ's mouse up commands) 
// Usage: /click left|right [<mouseloc>] 
// *************************************************************************** 
BOOL IsMouseWaitingForButton()
{
    return ((EQADDR_MOUSECLICK->Click[1] == EQADDR_MOUSECLICK->Confirm[1])
        && (EQADDR_MOUSECLICK->Click[0] == EQADDR_MOUSECLICK->Confirm[0])) ? FALSE : TRUE;
}

BOOL IsMouseWaiting()
{
    BOOL Result = FALSE;

    if (IsMouseWaitingForButton()) Result = TRUE;
    else {
        // Here we basically force the MQ script engine to wait for the button up on mouse clicks

        if (gMouseClickInProgress[0]) {
            //SetMouseButtonUpL();
            if (!((!EQADDR_MOUSECLICK->Click[0]) && (EQADDR_MOUSECLICK->Confirm[0] == 0x80))) EQADDR_MOUSECLICK->Click[0] = 0x0;
            gMouseClickInProgress[0] = FALSE;
            Result = TRUE;
        }
        if (gMouseClickInProgress[1]) {
            //SetMouseButtonUpR();
            if (!((!EQADDR_MOUSECLICK->Click[1]) && (EQADDR_MOUSECLICK->Confirm[1] == 0x80))) EQADDR_MOUSECLICK->Click[1] = 0x0;
            gMouseClickInProgress[1] = FALSE;
            Result = TRUE;
        }
    }
    return Result;
}
#endif

#ifndef ISXEQ

VOID Click(PSPAWNINFO pChar, PCHAR szLine) 
{ 
	if(GetGameState()!=GAMESTATE_INGAME) {
		MacroError("Dont /click stuff(%s) when not in game... Gamestate is %d",szLine,GetGameState());
		return;
	}
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
                gMouseEventTime = GetFastTime();
            } else if (!strnicmp(szArg1, "right", 5)) { 
                pEverQuest->RightClickedOnPlayer(pTarget, 0); 
                gMouseEventTime = GetFastTime();
            } 
            return;
        } else if(!strnicmp(szMouseLoc,"center",6)) {
            sprintf(szMouseLoc,"%d %d",ScreenXMax/2,ScreenYMax/2);
        } else if (!strnicmp(szMouseLoc, "item", 4)) {
			if(pGroundTarget) {
				if (!strnicmp(szArg1, "left", 4)) {
					if(EnviroTarget.Name[0]!=0) {
						if(DistanceToSpawn(pChar,&EnviroTarget)<=20.0f) {
							//do stuff
							if(PEQSWITCH pSwitch = (PEQSWITCH)pGroundTarget->pSwitch) {
								*((DWORD*)__LMouseHeldTime)=((PCDISPLAY)pDisplay)->TimeStamp-0x45;
								//we "click" at -1000,-1000 because we know the user doesnt have any windows there...
								//if its possible, i would like to figure out a pixel
								//on the users screen that isnt covered by a window...
								//the click need to be issued on the main UI...
								//but for now this will work -eqmule 8 mar 2014
								pEverQuest->LMouseUp(-1000,-1000);
							}
						} else {
							WriteChatf("You are to far away from the item, please move closer before issuing the /click left item command.");
						}
					} else {
						WriteChatf("No Item targeted, use /itemtarget <theid> before issuing a /click left item command.");
					}
				} else {
					WriteChatf("Invalid click args, use \"/click left item\", aborting: %s",szMouseLoc);
				}
			} else {
				WriteChatf("No Item targeted, use /itemtarget <theid> before issuing a /click left item command.");
			}
			return;
        } else if (!strnicmp(szMouseLoc, "door", 4)) {
			// a right clicked door spawn does nothing
			if(pDoorTarget) {
				if (!strnicmp(szArg1, "left", 4)) {
					if(DoorEnviroTarget.Name[0]!=0) {
						if(DistanceToSpawn(pChar,&DoorEnviroTarget)<20.0f) {
							EQSwitch *pSwitch = (EQSwitch *)pDoorTarget;
							srand((unsigned int)time(0));
							int randclickY = rand() % 5;
							int randclickX = rand() % 5;
							int randclickZ = rand() % 5;
							PSWITCHCLICK pclick = new SWITCHCLICK;
							if(pclick) {
								pclick->Y=pDoorTarget->Y+randclickY;
								pclick->X=pDoorTarget->X+randclickX;
								pclick->Z=pDoorTarget->Z+randclickZ;
								randclickY = rand() % 5;
								randclickX = rand() % 5;
								randclickZ = rand() % 5;
								pclick->Y1=pclick->Y+randclickY;
								pclick->X1=pclick->X+randclickX;
								pclick->Z1=pclick->Z+randclickZ;
								pSwitch->UseSwitch(GetCharInfo()->pSpawn->SpawnID,0xFFFFFFFF,0,(DWORD)pclick);
								delete pclick;
							}
							//DoorEnviroTarget.Name[0]='\0';
							if (pTarget==(EQPlayer*)&DoorEnviroTarget) {//this should NEVER happen
								pTarget=NULL;
							}
							return;
						} else {
							WriteChatf("You are to far away from the door, please move closer before issuing the /click left door command.");
						}
					} else {
						WriteChatf("No Door targeted, use /doortarget <theid> before issuing a /click left door command.");
					}
				} else {
					WriteChatf("Invalid click args, use \"/click left door\", aborting: %s",szMouseLoc);
				}
			} else {
				WriteChatf("No Door targeted, use /doortarget <theid> before issuing a /click left door command.");
			}
			return;;
		} 
        ClickMouseLoc(szMouseLoc, szArg1);
        return;
    }

    if (szArg1[0]!=0) { 
        if (!strnicmp(szArg1, "left", 4)) { 
            ClickMouse(0);
        } else if (!strnicmp(szArg1, "right", 5)) { 
            ClickMouse(1);
        } else { 
            WriteChatColor("Usage: /click <left|right>",USERCOLOR_DEFAULT); 
            DebugSpew("Bad command: %s",szLine); 
            return; 
        } 
    } 
}

#endif
