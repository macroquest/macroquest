/*****************************************************************************
    MacroQuest.exe: Injects EQLib.dll in EQGame.exe
    Copyright (C) 2002-2003 Plazmic

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#include <windows.h>
#include <stdio.h>
#include "resource.h"
#include "../MQ2Plugin.h"

// ***************************************************************************
// Constants
// ***************************************************************************
//#define MAX_STRING            1024

/*
typedef VOID	(__stdcall *FNINJECT)(VOID);
FNINJECT fnInjectEnable = NULL;
FNINJECT fnInjectDisable = NULL;
*/
// ***************************************************************************
// Function:    wmain
// Description: EXE entry point
// ***************************************************************************
#define WinClassName "__MacroQuestTray"

HWND hWnd;
HMENU hMenu;
NOTIFYICONDATA NID;
BOOL Minimized = false;

LRESULT CALLBACK WindProc(HWND hWnd, UINT MSG, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT PS;
	CHAR lpModulePath[_MAX_PATH] = {0};
	CHAR WinDir[_MAX_PATH] = {0};
	CHAR CommandLine[_MAX_PATH] = {0};
	GetCurrentDirectory(_MAX_PATH,lpModulePath);
	PROCESS_INFORMATION pInfo = {0};
	STARTUPINFO sInfo = {0};
	HDC dc = {0};

	switch(MSG) 
	{
		case WM_PAINT://Lets get the dc when we have to redraw our window
			BeginPaint(hWnd, &PS);
			dc = PS.hdc;
			EndPaint(hWnd, &PS);
			break;
		case WM_COMMAND:
			switch(wParam)
			{

				case ID_MENU_WEBSITE:
					ShellExecute(hWnd,"open","http://macroquest.sourceforge.net",NULL,lpModulePath,SW_SHOW);
					break;

				case ID_MENU_FORUMS:
					ShellExecute(hWnd,"open","http://macroquest.sourceforge.net/phpBB2",NULL,lpModulePath,SW_SHOW);
					break;

				case ID_EQSITES_ALLAKHAZAM:
					ShellExecute(hWnd,"open","http://everquest.allakhazam.com",NULL,lpModulePath,SW_SHOW);
					break;

				case ID_EQSITES_LUCY:
					ShellExecute(hWnd,"open","http://lucy.fnord.net",NULL,lpModulePath,SW_SHOW);
					break;

				case ID_EQSITES_EQMAPS:
					ShellExecute(hWnd,"open","http://www.eqmaps.com",NULL,lpModulePath,SW_SHOW);
					break;

				case ID_EQSITES_CASTERSREALM:
					ShellExecute(hWnd,"open","http://eq.castersrealm.com/",NULL,lpModulePath,SW_SHOW);
					break;

				case ID_EQSITES_EQTRADERS:
					ShellExecute(hWnd,"open","http://www.eqtraders.com/",NULL,lpModulePath,SW_SHOW);
					break;

				case ID_MENU_README:
					sprintf(CommandLine,"%s\\Readme.html",lpModulePath);
					ShellExecute(hWnd,"open",CommandLine,NULL,lpModulePath,SW_SHOW);
					break;

				case ID_MENU_INI: 
					sprintf(CommandLine,"%s\\MacroQuest.ini",lpModulePath);
					ShellExecute(hWnd,"open",CommandLine,NULL,lpModulePath,SW_SHOW);
					break;

				case ID_MENU_EXIT: 	
					PostQuitMessage(0); 
					break;
			}
			break;

		case WM_SIZE:
			if (wParam == SIZE_MINIMIZED)
				Minimized = true;
				ShowWindow(hWnd, SW_HIDE); // Hide our window just after the minimize is done.
				Shell_NotifyIcon(NIM_ADD, &NID); //Add the systray icon.
				break;
	
		case WM_SYSCOMMAND:
			switch(LOWORD(wParam)) //We capture the 'X' button :)
			{
				case SC_CLOSE:
					Minimized = false;
					ShowWindow(hWnd, SW_HIDE);
					Shell_NotifyIcon(NIM_ADD, &NID);
    				return(0);
					break;
				case WM_DESTROY:
					PostQuitMessage(0);
					break;
			}
		default:
			if (MSG == NID.uCallbackMessage) //This is where we get our SysTray Icon notifications.
			{	
				switch(lParam) 
				{
					case WM_LBUTTONDBLCLK: //Did the user double click?
						ShellExecute(hWnd,"open","http://macroquest.sourceforge.net/phpBB2",NULL,lpModulePath,SW_SHOW);
						break;

					case WM_RBUTTONUP: //Did the user right click?
						POINT mp;
						GetCursorPos(&mp);
						SetForegroundWindow(hWnd);
						TrackPopupMenu(   GetSubMenu(hMenu, 0),
							TPM_RIGHTBUTTON,
							mp.x,
							mp.y,
							0,
							hWnd,
							NULL);

						PostMessage(hWnd, WM_NULL, 0, 0); 

						break;
					case WM_LBUTTONUP: //Did the user left click?
						break;
				}
			}
	}
	return(DefWindowProc(hWnd, MSG, wParam, lParam));
}


void RegisterShellHandlers() {
	CHAR KeyClassMac[] = "SOFTWARE\\Classes\\.mac";
	CHAR KeyClassMacName[] = "mac_auto_file";

	CHAR KeyClassMacShellNew[] = "SOFTWARE\\Classes\\.mac\\ShellNew";
	BYTE KeyClassMacShellNewFileName[] = "mqmacro.mac";

	CHAR KeyClassesMQMacro[] = "SOFTWARE\\Classes\\mac_auto_file";
	CHAR KeyClassesMQMacroName[] = "MacroQuest Macro";

	CHAR KeyClassesMQMacroShellOpenCommand[] = "SOFTWARE\\Classes\\mac_auto_file\\shell\\open\\command";
	BYTE KeyClassesMQMacroShellOpenCommandData[] = "%SystemRoot%\\system32\\NOTEPAD.EXE %1"; //{0x25,0x00,0x53,0x00,0x79,0x00,0x73,0x00,0x74,0x00,0x65,0x00,0x6d,0x00,0x52,0x00,0x6f,0x00,0x6f,0x00,0x74,0x00,0x25,0x00,0x5c,0x00,0x73,0x00,0x79,0x00,0x73,0x00,0x74,0x00,0x65,0x00,0x6d,0x00,0x33,0x00,0x32,0x00,0x5c,0x00,0x4e,0x00,0x4f,0x00,0x54,0x00,0x45,0x00,0x50,0x00,0x41,0x00,0x44,0x00,0x2e,0x00,0x45,0x00,0x58,0x00,0x45,0x00,0x20,0x00,0x25,0x00,0x31,0x00,0x00,0x00};

	CHAR ShellNewFilePreExpand[] = "%USERPROFILE%\\Templates\\mqmacro.mac";
	CHAR ShellNewFile[1024] = {0};
	CHAR ShellNewFileData[] = "#turbo\r\n\r\nSub Main\r\n\r\n   // TODO: Add macro code here\r\n\r\n/return\r\n";

	HKEY HkeyTemp = {0};
	HANDLE hFile = NULL;

	if (ERROR_SUCCESS != RegOpenKey(HKEY_LOCAL_MACHINE,KeyClassMac,&HkeyTemp)) {
		//Can't open, try to create
		if (ERROR_SUCCESS == RegCreateKey(HKEY_LOCAL_MACHINE,KeyClassMac,&HkeyTemp)) {
			RegSetValue(HkeyTemp,NULL,REG_SZ,KeyClassMacName,sizeof(KeyClassMacName));
			RegCloseKey(HkeyTemp);
		}
	} else {
		RegSetValue(HkeyTemp,NULL,REG_EXPAND_SZ,KeyClassMacName,sizeof(KeyClassMacName));
		RegCloseKey(HkeyTemp);
	}

	if (ERROR_SUCCESS != RegOpenKey(HKEY_LOCAL_MACHINE,KeyClassMacShellNew,&HkeyTemp)) {
		//Can't open, try to create
		if (ERROR_SUCCESS == RegCreateKey(HKEY_LOCAL_MACHINE,KeyClassMacShellNew,&HkeyTemp)) {
			RegSetValueEx(HkeyTemp,"FileName",0,REG_SZ,KeyClassMacShellNewFileName,sizeof(KeyClassMacShellNewFileName));
			RegCloseKey(HkeyTemp);
		}
	} else {
		RegSetValueEx(HkeyTemp,"FileName",0,REG_SZ,KeyClassMacShellNewFileName,sizeof(KeyClassMacShellNewFileName));
		RegCloseKey(HkeyTemp);
	}

	if (ERROR_SUCCESS != RegOpenKey(HKEY_LOCAL_MACHINE,KeyClassesMQMacro,&HkeyTemp)) {
		//Can't open, try to create
		if (ERROR_SUCCESS == RegCreateKey(HKEY_LOCAL_MACHINE,KeyClassesMQMacro,&HkeyTemp)) {
			RegSetValue(HkeyTemp,NULL,REG_SZ,KeyClassesMQMacroName,sizeof(KeyClassesMQMacroName));
			RegCloseKey(HkeyTemp);
		}
	} else {
		RegSetValue(HkeyTemp,NULL,REG_SZ,KeyClassesMQMacroName,sizeof(KeyClassesMQMacroName));
		RegCloseKey(HkeyTemp);
	}

	if (ERROR_SUCCESS != RegOpenKey(HKEY_LOCAL_MACHINE,KeyClassesMQMacroShellOpenCommand,&HkeyTemp)) {
		//Can't open, try to create
		if (ERROR_SUCCESS == RegCreateKey(HKEY_LOCAL_MACHINE,KeyClassesMQMacroShellOpenCommand,&HkeyTemp)) {
			RegSetValueEx(HkeyTemp,NULL,0,REG_EXPAND_SZ,KeyClassesMQMacroShellOpenCommandData,sizeof(KeyClassesMQMacroShellOpenCommandData));
			RegCloseKey(HkeyTemp);
		}
	} else {
		RegSetValueEx(HkeyTemp,NULL,0,REG_EXPAND_SZ,KeyClassesMQMacroShellOpenCommandData,sizeof(KeyClassesMQMacroShellOpenCommandData));
		RegCloseKey(HkeyTemp);
	}

	ExpandEnvironmentStrings(ShellNewFilePreExpand,ShellNewFile,1024);
	hFile = CreateFile(ShellNewFile,FILE_ALL_ACCESS,NULL,NULL,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);
	if (INVALID_HANDLE_VALUE != hFile) {
		DWORD Written = 0;
		WriteFile(hFile,ShellNewFileData,sizeof(ShellNewFileData),&Written,NULL);
		CloseHandle(hFile);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	MSG msg;
	WNDCLASS wc;
//	CHAR szVersion[_MAX_PATH] = {0};
	CHAR szWinClassName[MAX_STRING] = {0};
	CHAR szWinName[MAX_STRING] = {0};
	CHAR lpINIPath[_MAX_PATH] = {0};
//	CHAR lpModulePath[_MAX_PATH] = {0};
	GetCurrentDirectory(_MAX_PATH,lpINIPath);
	strcat(lpINIPath,"\\EQGame.ini");
//	GetCurrentDirectory(_MAX_PATH,lpModulePath);
//	strcat(lpModulePath,"\\MQ2Main.dll");
//	GetPrivateProfileString("MacroQuest","MacroQuestVersion","INI not found",szVersion,_MAX_PATH,lpINIPath);
	GetPrivateProfileString("MacroQuest","MacroQuestWinClassName", "__MacroQuestTray", szWinClassName, MAX_STRING, lpINIPath);
	GetPrivateProfileString("MacroQuest","MacroQuestWinName", "MacroQuest", szWinName, MAX_STRING, lpINIPath);

	RegisterShellHandlers();

	// Make sure a MacroQuest instance isn't already running, if one is running, exit
	HWND hWndRunning = FindWindow(szWinClassName, szWinName);
	if (hWndRunning != NULL)
		return 0;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 
	wc.lpszClassName = szWinClassName;
	wc.lpszMenuName = NULL;
	wc.hInstance = hInstance;
	if (!RegisterClass(&wc)) return(0);
	if (!(hWnd = CreateWindow(szWinClassName, szWinName, WS_OVERLAPPEDWINDOW, 0, 0, GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN), NULL, NULL, hInstance, NULL))) return(0);

	NID.cbSize = sizeof(NID); // Size of the structure duh :)
	NID.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2)); // The icon that will be shown in the systray.
	NID.uCallbackMessage = WM_USER + 1; // Our user defined message.(For notifications, Windows will send us messages when user pressed on our icon)
	NID.hWnd = hWnd; // Handle to the window we would like to get the notifications.
	NID.uID = WM_USER + 2; // Icon ID in systray...
	if (!strcmp(gszVersion,VersionString))
		sprintf(NID.szTip, "%s [%s]", szWinName, gszVersion); // The tooltip string
	else
		sprintf(NID.szTip, "%s [Need Recompile]", szWinName); // The tooltip string

	NID.uFlags = NIF_TIP | NIF_ICON | NIF_MESSAGE; // Here we say we want to get notifications about the icon, we have an icon and a tooltip.

	//ShowWindow(hWnd, SW_SHOW);
	//UpdateWindow(hWnd);

	hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1));
    Shell_NotifyIcon(NIM_ADD, &NID);

	//Let's work
	/*
	HMODULE hModule = LoadLibrary(lpModulePath);
	if (!hModule) hModule = GetModuleHandle(lpModulePath);
	if (!hModule) { Shell_NotifyIcon(NIM_DELETE, &NID); return 1;}
	fnInjectEnable = (FNINJECT)GetProcAddress(hModule,"InjectEnable");
	if (!fnInjectEnable) { Shell_NotifyIcon(NIM_DELETE, &NID); return 1;}
	fnInjectDisable = (FNINJECT)GetProcAddress(hModule,"InjectDisable");
	if (!fnInjectDisable) { Shell_NotifyIcon(NIM_DELETE, &NID); return 1;}

	(*fnInjectEnable)();
/**/
	InjectEnable();
	BOOL bRet;

	while( (bRet = GetMessage( &msg, NULL, 0, 0 )) != 0)
	{ 
	    if (bRet == -1)
	    {
			break;
		}
	    else
		{
			if (msg.message == WM_QUIT) break;
	        TranslateMessage(&msg); 
		    DispatchMessage(&msg); 
		}
	}

	Shell_NotifyIcon(NIM_DELETE, &NID);
	InjectDisable();
//	(*fnInjectDisable)();
	return(int)(msg.wParam);
}