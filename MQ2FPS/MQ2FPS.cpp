// MQ2FPS.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.


//#define DEBUG_TRY 1
#include "../MQ2Plugin.h"
#include "MQ2FPS.h"

PreSetup("MQ2FPS");

#define FPS_ABSOLUTE  0
#define FPS_CALCULATE 1

DWORD MaxFPSMode=FPS_CALCULATE;

DWORD FPSIndicatorX=5;
DWORD FPSIndicatorY=25;

BOOL InMacro=false;

char *szFPSModes[]=
{
	"Absolute",
	"Calculate"
};


// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2FPS");

	// Add commands, macro parameters, hooks, etc.
	// INI Settings
    DWORD Temp=0;
    Temp = GetPrivateProfileInt("MQ2FPS","ForegroundMaxFPS",50,INIFileName);
    SetForegroundMaxFPS(Temp);
    Temp = GetPrivateProfileInt("MQ2FPS","BackgroundMaxFPS",30,INIFileName);
    SetBackgroundMaxFPS(Temp);
    MaxFPSMode = GetPrivateProfileInt("MQ2FPS","Mode",FPS_CALCULATE,INIFileName);
    FPSIndicatorX = GetPrivateProfileInt("MQ2FPS","IndicatorX",5,INIFileName);
    FPSIndicatorY = GetPrivateProfileInt("MQ2FPS","IndicatorY",25,INIFileName);

	// Commands
	AddCommand("/maxfps",MaxFPS,0,1);
	AddCommand("/fps",FPSCommand,0,1);
}
/*
PLUGIN_API VOID SetGameState(DWORD GameState)
{
	if (GameState==GAMESTATE_INGAME)
	{
		if (!pScreenX || !pScreenY)
		{
			DebugTry(WriteChatColor("MQ2FPS plugin requires ScreenX and ScreenY to function correctly"));
		}
	}
}
/**/

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2FPS");

	// Remove commands, macro parameters, hooks, etc.
	RemoveCommand("/maxfps");
	RemoveCommand("/fps");
}

DWORD gFG_MAX=0;
DWORD gBG_MAX=0;
DWORD CurMax=0;
#define FRAME_COUNT 64
DWORD FrameArray[FRAME_COUNT+1]={0};
DWORD CurrentFrame=0;
DWORD FrameTime=0;
DWORD LastSleep=0;
BOOL bFrameArrayFilled=0;
float FPS=0.0f;

VOID SetMode(DWORD Mode)
{
	if (Mode<2)
	{
		MaxFPSMode=Mode;
		if (Mode==FPS_ABSOLUTE) // i dont really want to use sprintf here, suck it
		{
			WriteChatColor("FPS Limiter mode now absolute");
			WritePrivateProfileString("MQ2FPS","Mode","0",INIFileName);
		}
		else
		{
			WriteChatColor("FPS Limiter mode now calculate");
			WritePrivateProfileString("MQ2FPS","Mode","1",INIFileName);
		}
	}
}

VOID SetForegroundMaxFPS(DWORD MaxFPS)
{
	gFG_MAX=MaxFPS;
	/*
    if (MaxFPS==0)
        gFG_SLEEP=0;
    else
        gFG_SLEEP=1000/MaxFPS;
	/**/
}

VOID SetBackgroundMaxFPS(DWORD MaxFPS)
{
	gBG_MAX=MaxFPS;
	/*
    if (MaxFPS==0)
        gBG_SLEEP=0;
    else
        gBG_SLEEP=1000/MaxFPS;
	/**/
}

VOID ProcessFrame()
{
	// Update frame array
	DWORD Now=FrameArray[CurrentFrame]=GetTickCount();

	DWORD FirstFrame=0;
	DWORD Frames=CurrentFrame;
	if (bFrameArrayFilled)
	{
		FirstFrame=CurrentFrame+1;
		if (FirstFrame>FRAME_COUNT)
		{
			FirstFrame=FRAME_COUNT;
		}
		Frames=FRAME_COUNT;
	}
	// Calculate time this frame
	DWORD LastFrame=CurrentFrame-1;
	if (LastFrame>FRAME_COUNT)
	{
		if (bFrameArrayFilled)
		{
			LastFrame=FRAME_COUNT;
			FrameTime=Now-FrameArray[LastFrame];
		}
		else
			FrameTime=0;
	}
	else
		FrameTime=Now-FrameArray[LastFrame];

	// Calculate FPS
	// Get amount of time between first frame and now
	DWORD Elapsed=Now-FrameArray[FirstFrame];


	if (Elapsed)
	{
		// less than one second?
		if (Elapsed<1000)
		{
			// elapsed 150 ms
			// extrapolate. how many frame arrays would fit in one second?
			FPS=(float)(1000.0f/(float)Elapsed); 
			// 6.66667=1000/150
			// now multiply by the number of frames we've gone through
			// Frames 10
			FPS*=(float)Frames;
			// 66.6667= FPS * 10
	//		FPS=
		}
		else
		{
			// Frames = 100
			// Elapsed = 2000ms
			// FPS = 100 / (2000/1000) = 50

			// interpolate. how many seconds did it take for our frame array?
			FPS=(float)Frames/(float)((float)Elapsed/1000.0f); // Frames / number of seconds
		}
	}
	else
		FPS=999.0f;
	// advance frame count
	if (++CurrentFrame>FRAME_COUNT)
	{
		CurrentFrame=0;
		bFrameArrayFilled=1;
	}
}

// This is called every time MQ pulses
PLUGIN_API VOID OnPulse(VOID)
{
	// DONT leave in this debugspew, even if you leave in all the others
//	DebugSpewAlways("MQ2FPS::OnPulse()");
	DebugTry(ProcessFrame());
	if (gGameState!=GAMESTATE_INGAME || gZoning || IsMouseWaiting())
		return;


	if (!gDelay && !gMacroPause && (!gMQPauseOnChat || *EQADDR_NOTINCHATMODE) &&
        gMacroBlock && gMacroStack) {
		InMacro=true;
		Sleep(0);
    }
	else
	{ 
		InMacro=false;
		HWND EQhWnd=*(HWND*)EQADDR_HWND;
		HMODULE hMod=GetModuleHandle("eqw.dll");
		if (hMod)
		{
			DWORD GetEQWHWND=(DWORD)hMod+0x12C0;
			__asm
			{
				push eax;
				call [GetEQWHWND];
				mov [EQhWnd], eax;
				pop eax;
			};
		}
		
		if (GetForegroundWindow()==EQhWnd)
		{
			CurMax=gFG_MAX;
			if (gFG_MAX)
			{
				int SleepTime=(int)(1000.0f/(float)gFG_MAX);
				if (MaxFPSMode==FPS_CALCULATE)
				{
					// assume last frame time is constant, so a 30ms frame = 33 fps
					// 
					
					SleepTime-=(FrameTime-LastSleep);
					/**/
					if (SleepTime<0)
						SleepTime=0;
					else if (SleepTime>300)
						SleepTime=300;
					Sleep(SleepTime);
					LastSleep=SleepTime;
				}
				else
				{
					Sleep(SleepTime);
					LastSleep=SleepTime;
				}
			}
			else
				Sleep(0);
		}
		else
		{
			CurMax=gBG_MAX;
			if (gBG_MAX)
			{
				int SleepTime=(int)(1000.0f/(float)gBG_MAX);
				if (MaxFPSMode==FPS_CALCULATE)
				{
					SleepTime-=(FrameTime-LastSleep);
					/**/
					if (SleepTime<0)
						SleepTime=0;
					else if (SleepTime>300)
						SleepTime=300;
					Sleep(SleepTime);
					LastSleep=SleepTime;
				}
				else
				{
					Sleep(SleepTime);
					LastSleep=SleepTime;
				}
			}
			else
				Sleep(0);
		}
	}

}



// Called every frame that the "HUD" is drawn -- e.g. net status / packet loss bar
PLUGIN_API VOID OnDrawHUD(VOID)
{
	// DONT leave in this debugspew, even if you leave in all the others
//	DebugSpewAlways("MQ2Template::OnDrawHUD()");
	if (!pDisplay)
		return; // even though its 100% impossible to call this without there being a pDisplay..
	CHAR szBuffer[MAX_STRING];

	
	// Display
	DWORD SX=0;
	DWORD SY=0;
	if (pScreenX && pScreenY)
	{
		SX=ScreenX;
		SY=ScreenY;
	}
	
	if (InMacro)
		sprintf(szBuffer,"%d/MACRO FPS",(DWORD)FPS);
	else
	{
		if (MaxFPSMode==FPS_ABSOLUTE)
		{
			sprintf(szBuffer,"%d/%d* FPS",(DWORD)FPS,CurMax);
		}
		else
		{
			sprintf(szBuffer,"%d/%d FPS",(DWORD)FPS,CurMax);
		}
	}



	DebugTry(pDisplay->WriteTextHD2(szBuffer,SX+FPSIndicatorX,SY+FPSIndicatorY,0x0d));

}

VOID FPSCommand(PSPAWNINFO pChar, PCHAR szLine)
{
   bRunNextCommand = TRUE;
   CHAR szCmd[MAX_STRING] = {0};
    CHAR Arg1[MAX_STRING] = {0};
    GetArg(Arg1,szLine,1);
   if (Arg1[0]==0) {
        WriteChatColor("Usage: /fps <mode|absolute|calculate|x,y>",USERCOLOR_DEFAULT);
        return;
   }

	if (!strnicmp(Arg1,"absolute",strlen(Arg1)))
	{
		CurrentFrame=0;
		bFrameArrayFilled=0;
		SetMode(FPS_ABSOLUTE);
		return;
	}
	else
	if (!strnicmp(Arg1,"calculate",strlen(Arg1)))
	{
		CurrentFrame=0;
		bFrameArrayFilled=0;
		SetMode(FPS_CALCULATE);
		return;
	}
	else
	if (!strnicmp(Arg1,"mode",strlen(Arg1)))
	{
		CurrentFrame=0;
		bFrameArrayFilled=0;
		SetMode(MaxFPSMode==0);
		return;
	}

	if (strchr(szLine,','))
	{
		sscanf(szLine,"%d,%d",&FPSIndicatorX,&FPSIndicatorY);
//		itoa(FPSIndicatorX,szCmd,10);
		WritePrivateProfileString("MQ2FPS","IndicatorX",itoa(FPSIndicatorX,szCmd,10),INIFileName);
		WritePrivateProfileString("MQ2FPS","IndicatorY",itoa(FPSIndicatorY,szCmd,10),INIFileName);
		return;
	}
        WriteChatColor("Usage: /fps <mode|absolute|calculate|x,y>",USERCOLOR_DEFAULT);
}


// ***************************************************************************
// Function:      MaxFPS
// Description:   Our /MaxFPS command. Sets or displays the max fps setting for
//                foreground or background
// 2003-11-01     Lax
// ***************************************************************************
VOID MaxFPS(PSPAWNINFO pChar, PCHAR szLine)
{
   bRunNextCommand = TRUE;
   CHAR szCmd[MAX_STRING] = {0};
    CHAR Arg1[MAX_STRING] = {0};
    CHAR Arg2[MAX_STRING] = {0};
    GetArg(Arg1,szLine,1);
    GetArg(Arg2,szLine,2);


   if (Arg1[0]==0 || Arg2[0]==0) {
	    sprintf(szCmd,"\aw\ayMaxFPS\ax\a-u:\ax \a-u[\ax\at%d\ax Foreground\a-u]\ax \a-u[\ax\at%d\ax Background\a-u]\ax \a-u[\ax%s Mode\a-u]\ax",gFG_MAX,gBG_MAX,szFPSModes[MaxFPSMode]);
        WriteChatColor(szCmd,USERCOLOR_DEFAULT);
        WriteChatColor("Usage: /maxfps <fg|bg> <#>",USERCOLOR_DEFAULT);
        return;
   }
   DWORD NewMax=atoi(Arg2);
   if (NewMax>200)
   {
       WriteChatColor("MaxFPS: Please use a number between 0 and 200, 0 being absolute fastest, 1-200 being that many frames per second.",USERCOLOR_DEFAULT);
       return;
   }

   if (!stricmp(Arg1,"fg"))
   {
     SetForegroundMaxFPS(NewMax);
       WritePrivateProfileString("MQ2FPS","ForegroundMaxFPS",Arg2,INIFileName);
   }
   else if (!stricmp(Arg1,"bg"))
   {
       SetBackgroundMaxFPS(NewMax);
       WritePrivateProfileString("MQ2FPS","BackgroundMaxFPS",Arg2,INIFileName);
   }
    sprintf(szCmd,"\aw\ayMaxFPS\ax\a-u:\ax \a-u[\ax\at%d\ax Foreground\a-u]\ax \a-u[\ax\at%d\ax Background\a-u]\ax \a-u[\ax%s Mode\a-u]\ax",gFG_MAX,gBG_MAX,szFPSModes[MaxFPSMode]);
    WriteChatColor(szCmd,USERCOLOR_DEFAULT);
}
