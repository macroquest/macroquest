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
VOID MouseButtonUp(DWORD x, DWORD y, PCHAR szButton);
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
	HRESULT GetViewport(LPVOID This,LPVOID pViewport);
	HRESULT GetTransform(LPVOID This,DWORD State,LPVOID pMatrix);
	void SetCursorPosition(LPVOID This, int X,int Y,DWORD Flags);//0x2c
	BOOL ShowCursor(LPVOID This,BOOL bShow); // 0x30
	/*0x000*/ BYTE Unknown0x0[0xf08];
    /*0xf08*/ LPVOID pDevice; // device pointer
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

//#ifndef ISXEQ

BOOL MoveMouse(DWORD x, DWORD y,BOOL bClick) 
{ 
	if (EQADDR_MOUSE) {
		POINT pt = {0};
		pt.x = x;
		pt.y = y;
		if(HWND eqhwnd = *(HWND*)EQADDR_HWND) {
			ClientToScreen(eqhwnd,&pt);
			//mouse_event(MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE,200,200,NULL,NULL);
			//DWORD pid;
			//GetWindowThreadProcessId(eqhwnd,&pid);
			//AttachThreadInput(pid,)
			//SendMessage(eqhwnd,WM_MOUSEMOVE,0,MAKELPARAM(pt.x,pt.y));
			//if(!bClick) {
				//if(((PCXWNDMGR)pWndMgr)->CurrWindowUnderMouse==0) {
			//SetCursor(NULL);
					SetCursorPos(pt.x,pt.y);
					
				//}
			//}
			EQADDR_DIMOUSECOPY->y = y;
			EQADDR_DIMOUSECOPY->x = x;
			EQADDR_MOUSE->Y = EQADDR_DIMOUSECOPY->y;
			EQADDR_DIMOUSECHECK->y = EQADDR_DIMOUSECOPY->y;
			EQADDR_MOUSE->X = EQADDR_DIMOUSECOPY->x;
			EQADDR_DIMOUSECHECK->x = EQADDR_DIMOUSECOPY->x;
			PCXWNDMGR px = (PCXWNDMGR)pWndMgr;
			px->ScreenMouseX=pt.x;
			px->ScreenMouseY=pt.y;
			px->ScreenMouseXCopy=pt.x;
			px->ScreenMouseYCopy=pt.y;
			if(bClick) {
				MouseButtonUp(x,y,"left");
			}
			WeDidStuff();
			DebugSpew("Moved mouse to: %d,%d", x, y); 
			return TRUE;
		}
	}
	return FALSE;
} 

BOOL ParseMouseLoc(PCHARINFO pCharInfo, PCHAR szMouseLoc) 
{
	CHAR szArg1[MAX_STRING] = {0};
	CHAR szArg2[MAX_STRING] = {0};
	int ClickX; //actual location to click, calculated from ButtonX 
	int ClickY; //actual location to click, calculated from ButtonY 
	if (!strnicmp(szMouseLoc, "target", 6)) {
        if (!pTarget) { 
            WriteChatColor("You must have a target selected for /mouseto target.",CONCOLOR_RED); 
            return FALSE; 
        }
		//insert code here to move mouse to target
		//work in progress -eqmule july 18 2015
		//this is comming in next zip, they ninja patched on me so im
		//gonna have to add this like tomorrow...
		WeDidStuff();
		return TRUE;
    }
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
// TODO: Expand this to support mouse buttons 3->8
VOID ClickMouse(DWORD button)
{
   if (button > 1)
      return;
   DWORD mdType = (DWORD)MD_Button0 + button;

   if (!((EQADDR_MOUSECLICK->Click[button] == 0x80) && (!EQADDR_MOUSECLICK->Confirm[button])))
      EQADDR_MOUSECLICK->Click[button] = 0x80;

   gMouseClickInProgress[button] = TRUE;

   WeDidStuff();
   if(PMOUSESPOOF pData = (PMOUSESPOOF)malloc(sizeof(MOUSESPOOF))) {
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
//#endif

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

#ifdef ISXEQ
int Click(int argc, char *argv[])
{
	PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
	CHAR szTemp[MAX_STRING] = { 0 };
	PCHAR szLine = ISXEQArgToMQ2Arg(argc, argv, szTemp, MAX_STRING);
#else
VOID Click(PSPAWNINFO pChar, PCHAR szLine)
{
#endif
	if(GetGameState()!=GAMESTATE_INGAME) {
		WriteChatf("Dont /click stuff(%s) when not in game... Gamestate is %d",szLine,GetGameState());
		RETURN(0);
	} 
    PCHAR szMouseLoc = NULL; 
    MOUSE_DATA_TYPES mdType = MD_Unknown; 
    DWORD RightOrLeft = 0; 
	CHAR szArg1[MAX_STRING] = { 0 };
    GetArg(szArg1, szLine, 1); //left or right 
    szMouseLoc = GetNextArg(szLine, 1); //location to click 

    //parse location for click location (szMouseLoc) here 
    if (szMouseLoc && szMouseLoc[0]!=0) { 
        if (!strnicmp(szMouseLoc, "target", 6)) {
            if (!pTarget) { 
                WriteChatColor("You must have a target selected for /click x target.",CONCOLOR_RED); 
				RETURN(0);
            } 
            if (!strnicmp(szArg1, "left", 4)) { 
                pEverQuest->LeftClickedOnPlayer(pTarget); 
                WeDidStuff();
            } else if (!strnicmp(szArg1, "right", 5)) { 
                pEverQuest->RightClickedOnPlayer(pTarget, 0); 
                WeDidStuff();
            } 
			RETURN(0);
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
			RETURN(0);
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
							RETURN(0);
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
			RETURN(0);
		} 
        ClickMouseLoc(szMouseLoc, szArg1);
		RETURN(0);
    }

    if (szArg1[0]!=0) { 
        if (!strnicmp(szArg1, "left", 4)) { 
            ClickMouse(0);
        } else if (!strnicmp(szArg1, "right", 5)) { 
            ClickMouse(1);
        } else { 
            WriteChatColor("Usage: /click <left|right>",USERCOLOR_DEFAULT); 
            DebugSpew("Bad command: %s",szLine); 
			RETURN(0);
        } 
    } 
	RETURN(0);
}
// *************************************************************************** 
// Function: MouseTo 
// Description: Our '/mouseto' command 
// Moves the mouse 
// Usage: /mouseto <mouseloc>
// *************************************************************************** 
VOID MouseTo(PSPAWNINFO pChar, PCHAR szLine) 
{
	if (szLine && szLine[0]) {
		if (ParseMouseLoc(GetCharInfo(), szLine)) {
			return;
		}
	}

	WriteChatColor("Usage: /mouseto <mouseloc>",USERCOLOR_DEFAULT); 
	DebugSpew("Help invoked or Bad MouseTo command: %s",szLine); 
}

//ok here goes... this is our custom directx implementation to allow us to
//mess with directx functions without having to include d3d9.lib or any d3d9 headers
//it was just easier than adding another dependency to the project and i dont like dependencies -eqmule
/******************SUPA DUPA CODE AND CUSTOM DIRECTX STUFF BELOW*****************/
//first some defines
#define EQD3DTS_VIEW 2
#define EQD3DTS_PROJECTION 3
#define EQD3DTS_WORLD  256


//Jul 18 2015 -eqmule
typedef struct _EqViewPort9 {
    DWORD       X;
    DWORD       Y;            /* Viewport Top left */
    DWORD       Width;
    DWORD       Height;       /* Viewport Dimensions */
    float       MinZ;         /* Min/max of clip Volume */
    float       MaxZ;
} EqViewPort9;
//our D3DMATRIX implementation
typedef struct _EQD3DMATRIX9
{
    union {
        struct {
            float        _11, _12, _13, _14;
            float        _21, _22, _23, _24;
            float        _31, _32, _33, _34;
            float        _41, _42, _43, _44;

        };
        float m[4][4];
    };
} EQD3DMATRIX9, *LPEQD3DMATRIX9;
//we are gonna need some pointers now for translating world coords to screen coords...
FakeCDisplay *pRender = 0;
LPVOID pD3Ddevice = 0;
ScreenVector3 g_vWorldLocation,v3ScreenCoord;
EqViewPort9 g_viewPort;
EQD3DMATRIX9 g_projection, g_view, g_world;

//we also need a couple virtual functions defined and we can just put them FakeCDisplay 
FUNCTION_AT_VIRTUAL_ADDRESS(void FakeCDisplay::SetCursorPosition(LPVOID This, int X,int Y,DWORD Flags),0x2c);
FUNCTION_AT_VIRTUAL_ADDRESS(BOOL FakeCDisplay::ShowCursor(LPVOID This,BOOL bShow),0x30);
FUNCTION_AT_VIRTUAL_ADDRESS(HRESULT FakeCDisplay::GetViewport(LPVOID,LPVOID pViewport),0xc0);
FUNCTION_AT_VIRTUAL_ADDRESS(HRESULT FakeCDisplay::GetTransform(LPVOID,DWORD State,LPVOID pMatrix),0xB4);

//ok magictime!
EQD3DMATRIX9* WINAPI EQD3DXMatrixMultiply(EQD3DMATRIX9 *pout, CONST EQD3DMATRIX9 *pm1, CONST EQD3DMATRIX9 *pm2)
{
	int i,j;
	for (i=0; i<4; i++)	{
		for (j=0; j<4; j++)	{
			pout->m[i][j] = pm1->m[i][0] * pm2->m[0][j] + pm1->m[i][1] * pm2->m[1][j] + pm1->m[i][2] * pm2->m[2][j] + pm1->m[i][3] * pm2->m[3][j];
		}
	}
	return pout;
}

ScreenVector3* WINAPI EQD3DXVec3TransformCoord(ScreenVector3 *pout, CONST ScreenVector3 *pv, CONST EQD3DMATRIX9 *pm)
{
	FLOAT norm;
	norm = pm->m[0][3] * pv->x + pm->m[1][3] * pv->y + pm->m[2][3] *pv->z + pm->m[3][3];
	if ( norm )	{
		pout->x = (pm->m[0][0] * pv->x + pm->m[1][0] * pv->y + pm->m[2][0] * pv->z + pm->m[3][0]) / norm;
		pout->y = (pm->m[0][1] * pv->x + pm->m[1][1] * pv->y + pm->m[2][1] * pv->z + pm->m[3][1]) / norm;
		pout->z = (pm->m[0][2] * pv->x + pm->m[1][2] * pv->y + pm->m[2][2] * pv->z + pm->m[3][2]) / norm;
	} else {
		pout->x = 0.0f;
		pout->y = 0.0f;
		pout->z = 0.0f;
	}
	return pout;
}

ScreenVector3* WINAPI EQD3DXVec3Project(ScreenVector3 *pout, CONST ScreenVector3 *pv, CONST EqViewPort9 *pviewport,
	CONST EQD3DMATRIX9 *pprojection, CONST EQD3DMATRIX9 *pview, CONST EQD3DMATRIX9 *pworld)
{
	EQD3DMATRIX9 m1, m2;
	ScreenVector3 vec;

	EQD3DXMatrixMultiply(&m1, pworld, pview);
	EQD3DXMatrixMultiply(&m2, &m1, pprojection);
	EQD3DXVec3TransformCoord(&vec, pv, &m2);
	pout->x = pviewport->X +  ( 1.0f + vec.x ) * pviewport->Width / 2.0f;
	pout->y = pviewport->Y +  ( 1.0f - vec.y ) * pviewport->Height / 2.0f;
	pout->z = pviewport->MinZ + vec.z * ( pviewport->MaxZ - pviewport->MinZ );
	return pout;
}

//ok now the function that use all the stuff above
bool  MouseToPlayer(EQPlayer*pPlayer,DWORD position,BOOL bClick)
{
	if(pPlayer) {
		if(pRender = (FakeCDisplay*)g_pDrawHandler)
		{
			g_vWorldLocation.x = ((PSPAWNINFO)pPlayer)->Y;
			g_vWorldLocation.y = ((PSPAWNINFO)pPlayer)->X;
			g_vWorldLocation.z = ((PSPAWNINFO)pPlayer)->Z;//smack in the middle...
			if(position==1) {//head
				g_vWorldLocation.z = ((PSPAWNINFO)pPlayer)->Feet+((PSPAWNINFO)pPlayer)->AvatarHeight;
			}
			if(position==2) {//feet
				g_vWorldLocation.z = ((PSPAWNINFO)pPlayer)->Feet;
			}

			ScreenVector3 v3ScreenCoord = {0};
			pD3Ddevice = pRender->pDevice;
			((FakeCDisplay*)pD3Ddevice)->GetTransform(pD3Ddevice,EQD3DTS_VIEW, &g_view);
			((FakeCDisplay*)pD3Ddevice)->GetTransform(pD3Ddevice,EQD3DTS_PROJECTION, &g_projection);
			((FakeCDisplay*)pD3Ddevice)->GetTransform(pD3Ddevice,EQD3DTS_WORLD, &g_world);
			((FakeCDisplay*)pD3Ddevice)->GetViewport(pD3Ddevice,&g_viewPort);
			EQD3DXVec3Project(&v3ScreenCoord, &g_vWorldLocation, &g_viewPort, &g_projection, &g_view, &g_world);
			if(v3ScreenCoord.z >= 1) {
				WriteChatf("%s is not within view %.2f",((PSPAWNINFO)pPlayer)->DisplayedName,v3ScreenCoord.z);
				return false;
			}
			WriteChatf("%s is at %.2f, %.2f, %.2f before adjustment",((PSPAWNINFO)pPlayer)->DisplayedName,v3ScreenCoord.x,v3ScreenCoord.y,v3ScreenCoord.z);
			POINT pt = {0};
			pt.x = (int)v3ScreenCoord.x;
			pt.y = (int)v3ScreenCoord.y;
			//((FakeCDisplay*)pD3Ddevice)->ShowCursor(pD3Ddevice,1);
			//((FakeCDisplay*)pD3Ddevice)->SetCursorPosition(pD3Ddevice,pt.x,pt.y,1);//D3DCURSOR_IMMEDIATE_UPDATE
			
			MoveMouse(pt.x,pt.y,bClick);
			WriteChatf("%s is at %d, %d, %.2f after adjustment and mouse is at %d, %d",((PSPAWNINFO)pPlayer)->DisplayedName,pt.x,pt.y,v3ScreenCoord.z,EQADDR_MOUSE->X,EQADDR_MOUSE->Y);
		}
	}
	return false;
}
//#endif
