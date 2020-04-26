/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "Common.h"

namespace eqlib {

//----------------------------------------------------------------------------

// Types used by the frontend a.k.a. eqmain.dll

class [[offsetcomments]] LoginController
{
public:
	EQLIB_OBJECT LoginController(HINSTANCE hInstance, HWND hWnd);
	EQLIB_OBJECT ~LoginController();

	EQLIB_OBJECT void Startup();
	EQLIB_OBJECT void Shutdown();
	EQLIB_OBJECT void GiveTime();

	EQLIB_OBJECT int ProcessKeyboardEvents();
	EQLIB_OBJECT int ProcessMouseEvents();
	EQLIB_OBJECT int FlushDxKeyboard();


/*0x00*/ IDirectInput8A*          pDI;
/*0x04*/ IDirectInputDevice8A*    pDIKeyboard;
/*0x08*/ IDirectInputDevice8A*    pDIMouse;
/*0x0c*/ HWND                     hWnd;
/*0x10*/ HINSTANCE                hInstance;
/*0x14*/ bool                     bIsKeyboardActive;
/*0x15*/ bool                     bIsMouseActive;
/*0x18*/ uint32_t                 Unknown0x18;
/*0x1c*/ int                      LastInputKey;
/*0x20*/
};

class CLoginViewManager
{
public:
	EQLIB_OBJECT int SendLMouseClick(CXPoint&);
};

class LoginServerAPI
{
public:
	//see 100129F0 in eqmain.dll dated jul 13 2017 - eqmule
	EQLIB_OBJECT unsigned int EnterGame(int serverID, void* userdata = 0, int timeoutseconds = 10);
};

struct [[offsetcomments]] DateStruct
{
/*0x18*/ char      Hours;
/*0x19*/ char      Minutes;
/*0x1a*/ char      Seconds;
/*0x1b*/ char      Month;
/*0x1c*/ char      Day;
/*0x1e*/ WORD      Year;
/*0x20*/ CXStr     Unknown0x08;
/*0x24*/ CXStr     Unknown0x0c;
/*0x28*/ CXStr     Unknown0x10;
/*0x30*/ int64_t   TimeStamp;
/*0x38*/
};

enum eServerStatus : uint32_t
{
	eServerStatus_Down = 1,
	eServerStatus_Locked = 4
};

// EQClientServerData
struct [[offsetcomments]] SERVERINFO
{
/*0x00*/ int           ID;
/*0x04*/ CXStr         ServerName;
/*0x08*/ CXStr         HostName;
/*0x0C*/ CXStr         ServerIP;
/*0x10*/ int           ExternalPort;
/*0x14*/ int           InternalPort;
/*0x18*/ DateStruct    DateCreated;
/*0x38*/ int           Flags;
/*0x3C*/ int           ServerType;
/*0x40*/ CXStr         LanguageCode;
/*0x44*/ CXStr         CountryCode;
/*0x48*/ eServerStatus StatusFlags;
/*0x4C*/ int           PopulationRanking;
/*0x50*/
};

struct [[offsetcomments]] SERVERLIST
{
/*0x00*/ SERVERINFO* Info;
/*0x04*/ SERVERLIST* Prev;
/*0x08*/ SERVERLIST* Next;
/*0x0C*/ DWORD     Unknown0x0C;
/*0x10*/ DWORD     Unknown0x10;
/*0x14*/ DWORD     Unknown0x14;
/*0x18*/
};

// LoginClient
struct [[offsetcomments]] SERVERSTUFF
{
/*0x000*/ BYTE     Unknown0x000[0x8];
/*0x008*/ void*    GFXENGINE;
/*0x00C*/ BYTE     Unknown0x00C[0x9C];
/*0x0A8*/ DWORD    CurrentServerID;
/*0x0AC*/ DWORD    Unknown0x0AC;
/*0x0B0*/ CXStr    LoginName;
/*0x0B4*/ CXStr    Password;
/*0x0B8*/ CXStr    LoginNameCopy;
/*0x0BC*/ CXStr    PasswordCopy;
/*0x0C0*/ CXStr    AccountKey;
/*0x0C4*/ BYTE     Unknown0x0C4[0x14];
/*0x0D8*/ SERVERINFO** FirstServer;
/*0x0DC*/ SERVERINFO** LastServer;
/*0x0E0*/ BYTE     Unknown0x0E0[0x8];
/*0x0E8*/ SERVERLIST* pServerList;
/*0x0EC*/ DWORD    ServerListSize;
/*0x0F0*/ BYTE     Unknown0x0F0[0x8];
/*0x0F8*/ DWORD    QuickConnectServerID;
/*0x0FC*/ CXStr    QuickConnectServerName;
/*0x100*/ CXStr    QuickConnectIPAddress;
/*0x104*/
};

struct [[offsetcomments]] HOST
{
	CXStr* Name;
	int Port;
};

struct [[offsetcomments]] EQDEVICE
{
	char Name[0x40];
};

struct [[offsetcomments]] EQLOGIN
{
	EQDEVICE  Devices[0x10];
	int       NumDevices;
	HWND      hEQWnd;
	int       ReturnCode; // -1 = failed login
	char      Login[0x80];
	char      PW[0x80];
	char      PW2[0x80];
	char      ServerLong[0x80];
	int       ServerPort;
	char      AccountKey[0x80];
	int       ActiveDeviceIndex;
	char      LastZoneEntered[0x20];
	char      StationName[0x20];
	char      ExeName[0x20];
	char      CommandLine[0x1c0];
	char      ServerShort[0x80];
	char      Session[0x40];
	char      Character[0x40];
	// more below I don't need atm
};

// work in progress to get short servername... -eqmule
class [[offsetcomments]] LoginClient// : public A_Callback?, public ChannelServerHandler?
{
public:
	void*     A_Callback_vfTable;
	void*     ChannelServerHandler_vfTable;
	EQLOGIN*  pLoginData;
	DoublyLinkedList<HOST*> Hosts;
	HOST*     pHost;
	bool      bRetryConnect;
	// more below don't need right now
};


//----------------------------------------------------------------------------

} // namespace eqlib
