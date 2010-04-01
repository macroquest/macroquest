/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x510
#define DIRECTINPUT_VERSION 0x800

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW

#include "MQ2Main.h"
namespace MQ2Globals
{


/* BENCHMARKS */
DWORD bmWriteChatColor=0;
DWORD bmPluginsIncomingChat=0;
DWORD bmPluginsPulse=0;
DWORD bmPluginsOnZoned=0;
DWORD bmPluginsCleanUI=0;
DWORD bmPluginsReloadUI=0;
DWORD bmPluginsDrawHUD=0;
DWORD bmPluginsSetGameState=0;
DWORD bmParseMacroParameter=0;
DWORD bmUpdateSpawnSort=0;
DWORD bmUpdateSpawnCaptions=0;
DWORD bmCalculate=0;
DWORD bmBeginZone=0; 
DWORD bmEndZone=0;

#ifndef ISXEQ
PDATAVAR pGlobalVariables=0;
PDATAVAR pMacroVariables=0;
#endif

ePVPServer PVPServer=PVP_NONE;
CHAR gszVersion[32]=VersionString;

DWORD gGameState = 0;
DWORD gMaxSpawnCaptions=30;
BOOL gMQCaptions=TRUE;
DWORD ThreadID = 0;
BOOL g_Loaded = FALSE;

BOOL gStringTableFixed=FALSE;
PCHATBUF gDelayedCommands = 0;

HMODULE ghModule = NULL;
HINSTANCE ghInstance = NULL;
//PHOTKEY pHotkey = NULL;
BOOL gbUnload = FALSE;
DWORD gpHook = NULL;
#ifndef ISXEQ
PMACROBLOCK gMacroBlock = NULL;
PMACROSTACK gMacroStack = NULL;
map<string,PMACROBLOCK> gMacroSubLookupMap; 
PEVENTQUEUE gEventQueue = NULL;
PMACROBLOCK gEventFunc[NUM_EVENTS] = {NULL};
#endif
UCHAR gLastFind = 0;
DOUBLE gZFilter=10000.0f;
DOUBLE gFaceAngle=10000.0f;
DOUBLE gLookAngle=10000.0f;
CHAR gszEQPath[MAX_STRING] = {0};
CHAR gszMacroPath[MAX_STRING] = {0};
CHAR gszLogPath[MAX_STRING] = {0};
CHAR gszINIPath[MAX_STRING] = {0};
CHAR gszINIFilename[MAX_STRING] = {0};
CHAR gszItemDB[MAX_STRING] = {0};
CHAR gszMacroName[MAX_STRING] = {0};
CHAR szLastCommand[MAX_STRING] = {0};

CHAR gszLastNormalError[MAX_STRING] = {0};
CHAR gszLastSyntaxError[MAX_STRING] = {0};
CHAR gszLastMQ2DataError[MAX_STRING] = {0};

PSPAWNINFO pNamingSpawn=0;
CHAR gszSpawnPlayerName[5][MAX_STRING]={
"",//0
"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}",//1
"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}",//2
"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},${NamingSpawn.GuildStatus} of ,]}${NamingSpawn.Guild}>,]}",//3
"${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Trader},Trader ,]}${If[${NamingSpawn.AARank},${NamingSpawn.AATitle} ,]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length}, ${NamingSpawn.Surname},]}${If[${NamingSpawn.AFK}, AFK,]}${If[${NamingSpawn.Linkdead}, LD,]}${If[${NamingSpawn.LFG}, LFG,]}${If[${NamingSpawn.GroupLeader}, LDR,]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},${NamingSpawn.GuildStatus} of ,]}${NamingSpawn.Guild}>,]}",//4
}
;
CHAR gszSpawnNPCName[MAX_STRING]="${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Surname.Length},\n(${NamingSpawn.Surname}),]}";
CHAR gszSpawnPetName[MAX_STRING]="${If[${NamingSpawn.Mark},${NamingSpawn.Mark} - ,]}${If[${NamingSpawn.Assist},>> ,]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist}, - ${NamingSpawn.PctHPs}%<<,]}${If[${NamingSpawn.Master.Type.Equal[PC]},\n(${NamingSpawn.Master}),]}";
CHAR gszSpawnCorpseName[MAX_STRING]="${NamingSpawn.DisplayName}'s corpse";

DWORD DrawHUDParams[4]={0,0,0,0};

#ifndef ISXEQ
Blech *pMQ2Blech=0;
CHAR EventMsg[MAX_STRING]={0};
#ifdef USEBLECHEVENTS
Blech *pEventBlech = 0;
#endif
PEVENTLIST pEventList = NULL;
#endif

DWORD gEventChat = 0;
DWORD gRunning = 0;
BOOL gbMoving = FALSE;
DWORD gMaxTurbo = 10;
BOOL gInClick = FALSE;
BOOL gZoning = FALSE;
BOOL WereWeZoning = TRUE;
BOOL gbInDInput = FALSE;
BOOL gbInChat = FALSE;
BOOL gbInDState = FALSE;
BOOL gbInDAcquire = FALSE;
BOOL gFilterSkillsAll = FALSE;
BOOL gFilterSkillsIncrease = FALSE;
BOOL gFilterTarget = FALSE;
BOOL gFilterDebug = FALSE;
BOOL gFilterMoney = FALSE;
BOOL gFilterFood = FALSE;
BOOL gFilterMacro = FALSE;
BOOL gFilterMQ = FALSE;
BOOL gFilterEncumber = FALSE;
BOOL gFilterCustom = TRUE;
BOOL gSpewToFile = FALSE;
BOOL gbDoAutoRun = FALSE;
BOOL gMQPauseOnChat = FALSE;
BOOL gKeepKeys = FALSE;
SWHOFILTER gFilterSWho = {0};
EQLIB_VAR BOOL gFilterMQ2DataErrors=FALSE;

DOUBLE DegToRad = 57.295779513082320876846364344191;
DOUBLE PI = 3.1415926535;

//PKEYPRESS gKeyStack = NULL;
PMQTIMER gTimer = NULL;
LONG gDelay = 0;
CHAR gDelayCondition[MAX_STRING]={0};
BOOL bAllowCommandParse=TRUE;
LONG gDelayZoning = 0;
PALERTLIST gpAlertList = NULL;
BOOL gMacroPause = FALSE;
ACTORINFO EnviroActor = {0};
SPAWNINFO EnviroTarget = {0};
PGROUNDITEM pGroundTarget = NULL;
SPAWNINFO DoorEnviroTarget = {0};
PDOOR pDoorTarget = NULL;
PITEMDB gItemDB = NULL;
BOOL bRunNextCommand = FALSE;
BOOL gTurbo = FALSE;
PDEFINE pDefines = NULL;
CHAR gLastFindSlot[MAX_STRING]={0};
PFILTER gpFilters = NULL;

BOOL g_bInDXMouse = FALSE;
PMOUSESPOOF gMouseData = NULL;
BOOL bDetMouse = TRUE;

PGUILDS pGuildList = (PGUILDS)__Guilds;
PEQSOCIAL   pSocialList = (PEQSOCIAL)__Socials;
PBYTE pgHotkeyPage = (PBYTE)__HotkeyPage;
PINT pgCurrentSocial = (PINT)__CurrentSocial;


// EQ Functions Initialization
fEQCommand        cmdHelp        =  NULL;
fEQCommand        cmdWho         =  NULL;
fEQCommand        cmdWhoTarget   =  NULL;
fEQCommand        cmdLocation    =  NULL;
fEQCommand        cmdFace        =  NULL;
fEQCommand        cmdTarget      =  NULL;
fEQCommand        cmdCharInfo    =  NULL;
fEQCommand        cmdFilter      =  NULL;
fEQCommand        cmdDoAbility   =  NULL;
fEQCommand        cmdCast        =  NULL;

fEQNewUIINI       NewUIINI   =  (fEQNewUIINI)__NewUIINI;
fEQProcGameEvts   ProcessGameEvents = (fEQProcGameEvts)__ProcessGameEvents;
fEQSendMessage    send_message = (fEQSendMessage)__SendMessage;
fEQExecuteCmd	  ExecuteCmd = (fEQExecuteCmd)__ExecuteCmd;
fEQGetMelee    get_melee_range = (fEQGetMelee)__get_melee_range;
fGetLabelFromEQ GetLabelFromEQ = (fGetLabelFromEQ)__GetLabelFromEQ;

// EQ Address Initialization
PSKILL *SkillDict=(PSKILL*)__SkillDict;

DWORD EQADDR_HWND=__HWnd;
DWORD EQADDR_MEMCHECK0=__MemChecker0;
DWORD EQADDR_MEMCHECK2=__MemChecker2;
DWORD EQADDR_MEMCHECK3=__MemChecker3;
DWORD EQADDR_MEMCHECK4=__MemChecker4;
PCHAR EQADDR_SERVERHOST=(PCHAR)__ServerHost;
PCHAR EQADDR_SERVERNAME=(PCHAR)__ServerName;
DWORD EQADDR_CONVERTITEMTAGS=__ConvertItemTags;
PCMDLIST EQADDR_CMDLIST=(PCMDLIST)__CommandList;

PEQFRIENDSLIST pFriendsList=(PEQFRIENDSLIST)__FriendsList;
PEQFRIENDSLIST pIgnoreList=(PEQFRIENDSLIST)__IgnoreList;

PBYTE EQADDR_ATTACK=(PBYTE)__Attack;
PBYTE EQADDR_NOTINCHATMODE=(PBYTE)__InChatMode;
PBYTE EQADDR_RUNWALKSTATE=(PBYTE)__RunWalkState;
PCHAR EQADDR_LASTTELL=(PCHAR)__LastTell;
PCHAR gpbRangedAttackReady=(PCHAR)__RangeAttackReady;
PCHAR gpbShowNetStatus=(PCHAR)__NetStatusToggle;
PCHAR gpbAltTimerReady=(PCHAR)__AltTimerReady;
DWORD *g_ppDrawHandler=(DWORD*)__DrawHandler;
DWORD *gpShowNames=(DWORD*)__ShowNames;
DWORD *gpPCNames=(DWORD*)__PCNames;
PBYTE pTributeActive=(PBYTE)instTributeActive;


PVOID EQADDR_GWORLD=(PVOID)__gWorld;
PDWORD EQADDR_DOABILITYLIST=(PDWORD)__DoAbilityList;

PBYTE EQADDR_DOABILITYAVAILABLE=(PBYTE)__DoAbilityAvailable;

PMAPLABEL *ppCurrentMapLabel=(PMAPLABEL*)__CurrentMapLabel;
PCHAR *EQMappableCommandList=(PCHAR*)__BindList;
DWORD gnNormalEQMappableCommands;
PCHAR szEQMappableCommands[nEQMappableCommands];
map<string,unsigned long> ItemSlotMap;

PBYTE EQADDR_ENCRYPTPAD0=(PBYTE)__EncryptPad0;
PBYTE EQADDR_ENCRYPTPAD2=(PBYTE)__EncryptPad2;
PBYTE EQADDR_ENCRYPTPAD3=(PBYTE)__EncryptPad3;
PBYTE EQADDR_ENCRYPTPAD4=(PBYTE)__EncryptPad4;

DWORD *pScreenX=(DWORD*)__ScreenX;
DWORD *pScreenY=(DWORD*)__ScreenY;
DWORD *pScreenMode=(DWORD*)__ScreenMode;
CHAR  *pMouseLook=(CHAR*)__MouseLook;
PMOUSEINFO EQADDR_MOUSE=(PMOUSEINFO)__Mouse;
PMOUSECLICK EQADDR_MOUSECLICK=(PMOUSECLICK)__Clicks;
CHAR DataTypeTemp[MAX_STRING]={0};

map<string,PSPAWNINFO> SpawnByName;
MQRANK EQP_DistArray[3000];
DWORD gSpawnCount=0;

#ifndef ISXEQ
DWORD EQADDR_DIMAIN=DI8__Main;
IDirectInputDevice8A **EQADDR_DIKEYBOARD=(IDirectInputDevice8A **)DI8__Keyboard;
IDirectInputDevice8A **EQADDR_DIMOUSE=(IDirectInputDevice8A **)DI8__Mouse;
#endif

// Motd and Pulse's mouse variables
BOOL gMouseLeftClickInProgress = FALSE;
BOOL gMouseRightClickInProgress = FALSE;
// End of mouse variables

// Arrays  (Note:  See also EQLib_Utilities.cpp)
DIKEYID gDiKeyID[] = {
#include "dikeys.h"
    {NULL,0}
};

PCHAR gDiKeyName[256];

PCHAR szHeading[] = {
    "south",                //0
    "south by southeast",   //1
    "southeast",            //2
    "east by southeast",    //3
    "east",                 //4
    "east by northeast",    //5
    "northeast",            //6
    "north by northeast",   //7
    "north",                //8
    "north by northwest",   //9
    "northwest",            //10
    "west by northwest",    //11
    "west",                 //12
    "west by southwest",    //13
    "southwest",            //14
    "south by southwest"    //15
};

PCHAR szHeadingShort[] = {
    "S",    //0
    "SSE",  //1
    "SE",   //2
    "ESE",  //3
    "E",    //4
    "ENE",  //5
    "NE",   //6
    "NNE",  //7
    "N",    //8
    "NNW",  //9
    "NW",   //10
    "WNW",  //11
    "W",    //12
    "WSW",  //13
    "SW",   //14
    "SSW"   //15
};

PCHAR szHeadingNormal[] = {
    "north",                //0
    "north by northeast",   //1
    "northeast",            //2
    "east by northeast",    //3
    "east",                 //4
    "east by southeast",    //5
    "southeast",            //6
    "south by southeast",   //7
    "south",                //8
    "south by southwest",   //9
    "southwest",            //10
    "west by southwest",    //11
    "west",                 //12
    "west by northwest",    //13
    "northwest",            //14
    "north by northwest"    //15
};

PCHAR szHeadingNormalShort[] = {
    "N",    //0
    "NNE",  //1
    "NE",   //2
    "ENE",  //3
    "E",    //4
    "ESE",  //5
    "SE",   //6
    "SSE",  //7
    "S",    //8
    "SSW",  //9
    "SW",   //10
    "WSW",  //11
    "W",    //12
    "WNW",  //13
    "NW",   //14
    "NNW"   //15
};


PCHAR szSize[] = {
    "Tiny",
    "Small",
    "Normal",
    "Large",
    "Giant",
    "Huge", //?
    "Unknown" //?
};

PCHAR szSpawnType[] = {
    "player",
    "NPC",
    "corpse",
    "any",
	"pet",
    NULL // SuperWhoTarget
};

PCHAR szGuildStatus[] = {
	"Member",
	"Officer",
	"Leader",
	NULL
};

PCHAR szGender[] = {
    "male",
    "female",
    "neuter",
    "unknown"
};

PCHAR szDeityTeam[] = {
    "none",     //0
    "good",     //1
    "neutral",  //2
    "evil"      //3
};

PCHAR szLights[] = {
    "NONE",    // 0  - No light
    "CDL", // 1  - Candle
    "TR",  // 2  - Torch
    "TGS", // 3  - Tiny Glowing Skull
    "SL",  // 4  - Small Lantern
    "SoM", // 5  - Stein of Moggok
    "LL",  // 6  - Large Lantern
    "FL",  // 7  - Flameless lantern, Halo of Light
    "GOS", // 8  - Globe of stars
    "LG",  // 9  - Light Globe
    "LS",  // 10 - Lightstone, Burnt-out lightstone, wispstone
    "GLS", // 11 - Greater lightstone
    "FBE", // 12 - Fire Beatle Eye, Firefly Globe
    "CL"  // 13 - Coldlight
};

BYTE LightBrightness[] = {
    0,      //0
    1,      //1
    2,      //2
    3,      //3
    6,      //4
    7,      //5
    8,      //6
    9,      //7
    10,     //8
    0,      //9
    0,      //10
    0,      //11
    4,      //12
    5       //13
};

PCHAR szSkills[] = {
    #include "skills.h"
    NULL
};

PCHAR szInnates[] = {
	"Awareness",//c4c
	"Bash Door",//c50
	"Breathe Fire",//c54
	"Harmony",//c58
	"Harm Touch",//c5c
	"Infravision",//c60
	"Lay Hands",//c64
	"Lore",//c68
	"No Bash",//c6c
	"Regeneration",//c70
	"Slam",//c74
	"Surprise",//c78
	"Ultravision",//c7c
	"Inspect",//c80
	"Open",//c84
    NULL
};

PCHAR szCombineTypes[] = {
    #include "combines.h"
    NULL
};

PCHAR szItemTypes[] = {
    #include "itemtypes.h"
    NULL
};

PCHAR szZoneExpansionName[] = {
    "Original EQ",              //0
    "Kunark",                   //1
    "Velious",                  //2
    "Luclin",                   //3
    "Planes of Power",          //4
    "Legacy of Ykesha",         //5
    "Lost Dungeons of Norrath", //6
	"Gates of Discord",         //7
	"Omens of War",				//8
}; 

#include "grounds.h"
PCHAR szItemName[] = {
    #include "weapons.h"
    NULL
};

PCHAR szDmgBonusType[] = { 
    "None", 
    "Magic", 
    "Fire", 
    "Cold", 
    "Poison", 
    "Disease" 
}; 

PCHAR szBodyType[] = { 
   "Player",//0
   "Humanoid", //1
   "Lycanthrope", //2
   "Undead", //3
   "Giant", //4
   "Construct", //5   (includes confused mutations in ldon)
   "Extraplanar", //6
   "Magical", //7
   "Undead Pet", //8
   "Bane Giant", //9
   "Dain", //10
   "Untargetable", //11
   "Vampyre", //12
   "Atenha Ra", //13
   "Greater Akheva",//14
   "Khati Sha", //15
   "Seru", //16
   "*UNKNOWN BODYTYPE 17", //17
   "Draz Nurakk", //18
   "Zek", //19
   "Luggald", //20
   "Animal", //21
   "Insect", //22
   "Monster", //23
   "Elemental", //24
   "Plant", //25
   "Dragon", //26
   "Elemental", //27
   "Summoned Creature",//28
   "Dragon",//29
   "Bane Dragon",//30
   "Familiar",//31
	"Proc Pet",//32
	"Chest",//33
	"Muramite",//34
	"*UNKNOWN BODYTYPE 35",
	"*UNKNOWN BODYTYPE 36",
	"*UNKNOWN BODYTYPE 37",
	"*UNKNOWN BODYTYPE 38",
	"*UNKNOWN BODYTYPE 39",
	"*UNKNOWN BODYTYPE 40",
	"*UNKNOWN BODYTYPE 41",
	"*UNKNOWN BODYTYPE 42",
	"*UNKNOWN BODYTYPE 43",
	"*UNKNOWN BODYTYPE 44",
	"*UNKNOWN BODYTYPE 45",
	"*UNKNOWN BODYTYPE 46",
	"*UNKNOWN BODYTYPE 47",
	"*UNKNOWN BODYTYPE 48",
	"*UNKNOWN BODYTYPE 49",
	"*UNKNOWN BODYTYPE 50",
	"*UNKNOWN BODYTYPE 51",
	"*UNKNOWN BODYTYPE 52",
	"*UNKNOWN BODYTYPE 53",
	"*UNKNOWN BODYTYPE 54",
	"*UNKNOWN BODYTYPE 55",
	"*UNKNOWN BODYTYPE 56",
	"*UNKNOWN BODYTYPE 57",
	"*UNKNOWN BODYTYPE 58",
	"*UNKNOWN BODYTYPE 59",
	"*UNKNOWN BODYTYPE 60",
	"*UNKNOWN BODYTYPE 61",
	"*UNKNOWN BODYTYPE 62",
	"*UNKNOWN BODYTYPE 63",
	"*UNKNOWN BODYTYPE 64",
	"Trap",
	"Timer",
	"Trigger",
	"*UNKNOWN BODYTYPE 68",
	"*UNKNOWN BODYTYPE 69",
	"*UNKNOWN BODYTYPE 70",
}; 
/**/

PCHAR szAugRestrictions[] = { 
	"None",
	"Armor Only",
	"Weapons Only",
	"1H Weapons Only",
	"2H Weapons Only",
	"1H Slash Only",
	"1H Blunt Only",
	"Piercing Only",
	"Hand to Hand Only",
	"2H Slash Only",
	"2H Blunt Only",
	"2H Pierce Only",
	"Bows Only",
	"Shields Only"
}; 
PCHAR szItemSlot[] = {
    "charm",        // 0
    "leftear",      // 1
    "head",
    "face",
    "rightear",
    "neck",
    "shoulder",
    "arms",
    "back",
    "leftwrist",
    "rightwrist",   // 10
    "ranged",
    "hands",
    "mainhand",
    "offhand",
    "leftfinger",
    "rightfinger",
    "chest",
    "legs",
    "feet",
    "waist",        // 20
    "ammo",
	"pack1",
	"pack2",
	"pack3",
	"pack4",
	"pack5",
	"pack6",
	"pack7",
	"pack8",        // 29
    NULL            // 30
};

BOOL bAllErrorsFatal=FALSE;
BOOL bAllErrorsDumpStack=FALSE;
#ifndef DoWarp
BOOL bLaxColor=TRUE;
#else
BOOL bLaxColor=FALSE;
#endif
BOOL gbHUDUnderUI=1;
BOOL gbAlwaysDrawMQHUD=0;

DWORD nColorAdjective=0;
DWORD nColorAdjectiveYou=0;
DWORD nColorExpletive=0;
DWORD nColorSyntaxError=0;
DWORD nColorMacroError=0;
DWORD nColorMQ2DataError=0;
DWORD nColorFatalError=0;

PCHAR szColorAdjective[]=
{
	"",
	"GOD DAMN ",
	"FUCKING ",
	"MOTHER FUCKING ",
	NULL
};

PCHAR szColorAdjectiveYou[]=
{
	"",
	" FUCKER",
	" MOTHER FUCKER",
	" ASSHOLE",
	" FUCKTARD",
	" FUCKING RETARDED MONKEY",
	" GOD DAMN SHORT BUS PASSENGER",
	" ASSMONKEY",
	" PIGFUCKER",
	" PEEN",
	" FUCKING IDIOT",
	" STUPID FUCKER",
	" DUMBASS",
	" FUCKING DUMBASS",
	" STUPID FUCK",
	NULL
};

PCHAR szColorExpletive[]=
{
	"",
	"CHRIST ",
	"JESUS FUCK ",
	"GOD ",
	"JESUS FUCKING CHRIST ",
	"FUCKING CHRIST ",
	"GKFJDGJKFDGJKDF ",
	NULL
};

PCHAR szColorSyntaxError[]=
{
	"",
	"%edont you know how to use a simple %acommand%y",
	NULL
};

PCHAR szColorMacroError[]=
{
	"",
	"%ei'm pretty sure you're on %acrack%y"
	"%egood job%y, cant you do anything %aright%y",
	"%ewhatever you're %asmoking, pass it %aalong%y",
	"%e%aRTFM%y",
	"%e%aRTFM%y, until then fuck off%y",
	"%eget a %abrain%y",
	NULL
};

PCHAR szColorFatalError[]=
{
	"",
	"%eyou fucking broke it%y",
	"%egood job%y. what's next? your head on a %astick thats %awhat%y",
	NULL
};

PCHAR szColorMQ2DataError[]=
{
	"",
	"%ewhy dont you %aread the %areference%y",
	"%eget a %aclue%y",
	"%ewhatever you're %asmoking, pass it %aalong%y",
	"%e%aread the %areference%y",
	"%e%aread the %areference%y, until then fuck off%y",
	NULL
};

StringTable **ppStringTable=(StringTable**)pinstStringTable;
CDBStr **ppCDBStr = (CDBStr**)pinstCDBStr;

EQPlayer **ppEQP_IDArray=(EQPlayer**)__EQP_IDArray;

CEverQuest **ppEverQuest=(CEverQuest**)pinstCEverQuest;
CDisplay **ppDisplay=(CDisplay**)pinstCDisplay;
EQ_PC **ppPCData=(EQ_PC**)pinstPCData;
EQ_Character **ppCharData=(EQ_Character**)pinstCharData;
EQPlayer **ppCharSpawn=(EQPlayer**)pinstCharSpawn;
EQPlayer **ppActiveMerchant=(EQPlayer**)pinstActiveMerchant;
EQPlayer **ppSpawnList=(EQPlayer**)pinstSpawnList;
EQPlayer **ppLocalPlayer=(EQPlayer**)pinstLocalPlayer;
EQPlayer **ppControlledPlayer=(EQPlayer**)pinstControlledPlayer;
EQWorldData **ppWorldData=(EQWorldData**)pinstWorldData;
SpellManager **ppSpellMgr=(SpellManager**)pinstSpellManager;
CInvSlot **ppSelectedItem=(CInvSlot **)pinstSelectedItem;
EQGROUP *pGroup=(EQGROUP*)instGroup;
EQPlayer **ppTarget=(EQPlayer**)pinstTarget;
EqSwitchManager **ppSwitchMgr=(EqSwitchManager**)pinstSwitchManager;
EQItemList **ppItemList=(EQItemList**)pinstEQItemList;
SPELLFAVORITE *pSpellSets=(SPELLFAVORITE *)pinstSpellSets;
EQZoneInfo *pZoneInfo=(EQZoneInfo*)instEQZoneInfo;
AltAdvManager** ppAltAdvManager=(AltAdvManager**)pinstAltAdvManager;

EQPlayer **ppTradeTarget=(EQPlayer **)pinstTradeTarget;
EQPlayer **ppActiveBanker=(EQPlayer **)pinstActiveBanker;
EQPlayer **ppActiveGMaster=(EQPlayer **)pinstActiveGMaster;
EQPlayer **ppActiveCorpse=(EQPlayer **)pinstActiveCorpse;


/* WINDOW INSTANCES */

CContextMenuManager **ppContextMenuManager=(CContextMenuManager**)pinstCContextMenuManager;
CCursorAttachment **ppCursorAttachment=(CCursorAttachment**)pinstCCursorAttachment;
CSocialEditWnd **ppSocialEditWnd=(CSocialEditWnd**)pinstCSocialEditWnd;
CContainerMgr **ppContainerMgr=(CContainerMgr**)pinstCContainerMgr;
CChatManager **ppChatManager=(CChatManager**)pinstCChatManager;
CFacePick **ppFacePick=(CFacePick**)pinstCFacePick;
CInvSlotMgr **ppInvSlotMgr=(CInvSlotMgr**)pinstCInvSlotMgr;
//CPopupWndManager **ppPopupWndManager=(CPopupWndManager**)pinstCPopupWndManager;
CNoteWnd **ppNoteWnd=(CNoteWnd**)pinstCNoteWnd;
CTipWnd **ppTipWndOFDAY=(CTipWnd**)pinstCTipWndOFDAY;
CTipWnd **ppTipWndCONTEXT=(CTipWnd**)pinstCTipWndCONTEXT;
CBookWnd **ppBookWnd=(CBookWnd**)pinstCBookWnd;
CFriendsWnd **ppFriendsWnd=(CFriendsWnd**)pinstCFriendsWnd;
CMusicPlayerWnd **ppMusicPlayerWnd=(CMusicPlayerWnd**)pinstCMusicPlayerWnd;
CAlarmWnd **ppAlarmWnd=(CAlarmWnd**)pinstCAlarmWnd;
CLoadskinWnd **ppLoadskinWnd=(CLoadskinWnd**)pinstCLoadskinWnd;
CPetInfoWnd **ppPetInfoWnd=(CPetInfoWnd**)pinstCPetInfoWnd;
CTrainWnd **ppTrainWnd=(CTrainWnd**)pinstCTrainWnd;
CSkillsWnd **ppSkillsWnd=(CSkillsWnd**)pinstCSkillsWnd;
CSkillsSelectWnd **ppSkillsSelectWnd=(CSkillsSelectWnd**)pinstCSkillsSelectWnd;
//CCombatSkillSelectWnd **ppCombatSkillSelectWnd=(CCombatSkillSelectWnd**)pinstCCombatSkillSelectWnd;
CAAWnd **ppAAWnd=(CAAWnd**)pinstCAAWnd;
CGroupWnd **ppGroupWnd=(CGroupWnd**)pinstCGroupWnd;
//CSystemInfoDialogBox **ppSystemInfoDialogBox=(CSystemInfoDialogBox**)pinstCSystemInfoDialogBox;
CGroupSearchWnd **ppGroupSearchWnd=(CGroupSearchWnd**)pinstCGroupSearchWnd;
CGroupSearchFiltersWnd **ppGroupSearchFiltersWnd=(CGroupSearchFiltersWnd**)pinstCGroupSearchFiltersWnd;
CRaidWnd **ppRaidWnd=(CRaidWnd**)pinstCRaidWnd;
CRaidOptionsWnd **ppRaidOptionsWnd=(CRaidOptionsWnd**)pinstCRaidOptionsWnd;
CBreathWnd **ppBreathWnd=(CBreathWnd**)pinstCBreathWnd;
CMapToolbarWnd **ppMapToolbarWnd=(CMapToolbarWnd**)pinstCMapToolbarWnd;
CMapViewWnd **ppMapViewWnd=(CMapViewWnd**)pinstCMapViewWnd;
CEditLabelWnd **ppEditLabelWnd=(CEditLabelWnd**)pinstCEditLabelWnd;
COptionsWnd **ppOptionsWnd=(COptionsWnd**)pinstCOptionsWnd;
CBuffWindow **ppBuffWindowSHORT=(CBuffWindow**)pinstCBuffWindowSHORT;
CBuffWindow **ppBuffWindowNORMAL=(CBuffWindow**)pinstCBuffWindowNORMAL;
CTargetWnd **ppTargetWnd=(CTargetWnd**)pinstCTargetWnd;
CColorPickerWnd **ppColorPickerWnd=(CColorPickerWnd**)pinstCColorPickerWnd;
CHotButtonWnd **ppHotButtonWnd=(CHotButtonWnd**)pinstCHotButtonWnd;
CPlayerWnd **ppPlayerWnd=(CPlayerWnd**)pinstCPlayerWnd;
CCastingWnd **ppCastingWnd=(CCastingWnd**)pinstCCastingWnd;
CCastSpellWnd **ppCastSpellWnd=(CCastSpellWnd**)pinstCCastSpellWnd;
CSpellBookWnd **ppSpellBookWnd=(CSpellBookWnd**)pinstCSpellBookWnd;
CInventoryWnd **ppInventoryWnd=(CInventoryWnd**)pinstCInventoryWnd;
CBankWnd **ppBankWnd=(CBankWnd**)pinstCBankWnd;
CQuantityWnd **ppQuantityWnd=(CQuantityWnd**)pinstCQuantityWnd;
CTextEntryWnd **ppTextEntryWnd=(CTextEntryWnd**)pinstCTextEntryWnd;
CFileSelectionWnd **ppFileSelectionWnd=(CFileSelectionWnd**)pinstCFileSelectionWnd;
CLootWnd **ppLootWnd=(CLootWnd**)pinstCLootWnd;
CActionsWnd **ppActionsWnd=(CActionsWnd**)pinstCActionsWnd;
//CCombatAbilityWnd **ppCombatAbilityWnd=(CCombatAbilityWnd**)pinstCCombatAbilityWnd;
CMerchantWnd **ppMerchantWnd=(CMerchantWnd**)pinstCMerchantWnd;
CTradeWnd **ppTradeWnd=(CTradeWnd**)pinstCTradeWnd;
CBazaarWnd **ppBazaarWnd=(CBazaarWnd**)pinstCBazaarWnd;
CBazaarSearchWnd **ppBazaarSearchWnd=(CBazaarSearchWnd**)pinstCBazaarSearchWnd;
CGiveWnd **ppGiveWnd=(CGiveWnd**)pinstCGiveWnd;
CSelectorWnd **ppSelectorWnd=(CSelectorWnd**)pinstCSelectorWnd;
CTrackingWnd **ppTrackingWnd=(CTrackingWnd**)pinstCTrackingWnd;
CInspectWnd **ppInspectWnd=(CInspectWnd**)pinstCInspectWnd;
CFeedbackWnd **ppFeedbackWnd=(CFeedbackWnd**)pinstCFeedbackWnd;
CBugReportWnd **ppBugReportWnd=(CBugReportWnd**)pinstCBugReportWnd;
CVideoModesWnd **ppVideoModesWnd=(CVideoModesWnd**)pinstCVideoModesWnd;
CCompassWnd **ppCompassWnd=(CCompassWnd**)pinstCCompassWnd;
CPlayerNotesWnd **ppPlayerNotesWnd=(CPlayerNotesWnd**)pinstCPlayerNotesWnd;
CGemsGameWnd **ppGemsGameWnd=(CGemsGameWnd**)pinstCGemsGameWnd;
CStoryWnd **ppStoryWnd=(CStoryWnd**)pinstCStoryWnd;
//CFindLocationWnd **ppFindLocationWnd=(CFindLocationWnd**)pinstCFindLocationWnd;
//CAdventureRequestWnd **ppAdventureRequestWnd=(CAdventureRequestWnd**)pinstCAdventureRequestWnd;
//CAdventureMerchantWnd **ppAdventureMerchantWnd=(CAdventureMerchantWnd**)pinstCAdventureMerchantWnd;
//CAdventureStatsWnd **ppAdventureStatsWnd=(CAdventureStatsWnd**)pinstCAdventureStatsWnd;
//CAdventureLeaderboardWnd **ppAdventureLeaderboardWnd=(CAdventureLeaderboardWnd**)pinstCAdventureLeaderboardWnd;
//CLeadershipWindow **ppLeadershipWindow=(CLeadershipWindow**)pinstCLeadershipWindow;
CBodyTintWnd **ppBodyTintWnd=(CBodyTintWnd**)pinstCBodyTintWnd;
CGuildMgmtWnd **ppGuildMgmtWnd=(CGuildMgmtWnd**)pinstCGuildMgmtWnd;
CJournalTextWnd **ppJournalTextWnd=(CJournalTextWnd**)pinstCJournalTextWnd;
CJournalCatWnd **ppJournalCatWnd=(CJournalCatWnd**)pinstCJournalCatWnd;
//CTributeBenefitWnd **ppTributeBenefitWnd=(CTributeBenefitWnd**)pinstCTributeBenefitWnd;
//CTributeMasterWnd **ppTributeMasterWnd=(CTributeMasterWnd**)pinstCTributeMasterWnd;
CPetitionQWnd **ppPetitionQWnd=(CPetitionQWnd**)pinstCPetitionQWnd;
CSoulmarkWnd **ppSoulmarkWnd=(CSoulmarkWnd**)pinstCSoulmarkWnd;
CTimeLeftWnd **ppTimeLeftWnd=(CTimeLeftWnd**)pinstCTimeLeftWnd;

CTextOverlay **ppTextOverlay=(CTextOverlay**)pinstCTextOverlay;

CSidlManager **ppSidlMgr=(CSidlManager **)pinstCSidlManager;
CXWndManager **ppWndMgr=(CXWndManager**)pinstCXWndManager;
KeypressHandler **ppKeypressHandler=(KeypressHandler**)instKeypressHandler;
PEQRAID pRaid=(PEQRAID)instCRaid;

PMQPLUGIN pPlugins=0;
PMQXMLFILE pXMLFiles=0;
DWORD ManaGained=0;
DWORD HealthGained=0;
DWORD EnduranceGained=0;
PALIAS pAliases=0;
PSUB pSubs=0;
PMQCOMMAND pCommands=0;
};
