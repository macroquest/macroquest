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

#include "pch.h"
#include "MQ2Main.h"

namespace mq {

DWORD baseAddress = (DWORD)GetModuleHandle(nullptr);
bool InitOffsets()
{
	return true;
}

/* PickZone */
HANDLE ghInitializeSpellDbThread = nullptr;

/* BENCHMARKS */
DWORD bmWriteChatColor = 0;
DWORD bmPluginsIncomingChat = 0;
DWORD bmPluginsPulse = 0;
DWORD bmPluginsOnZoned = 0;
DWORD bmPluginsCleanUI = 0;
DWORD bmPluginsReloadUI = 0;
DWORD bmPluginsDrawHUD = 0;
DWORD bmPluginsSetGameState = 0;
DWORD bmParseMacroParameter = 0;
DWORD bmUpdateSpawnSort = 0;
DWORD bmUpdateSpawnCaptions = 0;
DWORD bmCalculate = 0;
DWORD bmBeginZone = 0;
DWORD bmEndZone = 0;

MQDataVar* pGlobalVariables = nullptr;
MQDataVar* pMacroVariables = nullptr;

ePVPServer PVPServer = PVP_NONE;
char gszVersion[32] = VersionString;
char gszTime[32] = TimeString;

#if defined(TEST)
int gBuild = 2;               // TEST
#else
int gBuild = 1;               // LIVE
#endif

bool g_bDoingModuleChecks = false;
DWORD gGameState = 0;
int gMaxSpawnCaptions = 30;
BOOL gMQCaptions = TRUE;
BOOL gAnonymize = FALSE;
DWORD gAnonymizeFlag = 0;
DWORD ThreadID = 0;
bool g_Loaded = false;

BOOL gStringTableFixed = FALSE;

HMODULE ghModule = nullptr;
HINSTANCE ghInstance = nullptr;
HWND ghInjectorWnd = nullptr;
bool gbUnload = false;
bool gBindInProgress = false;
bool gbLoad = true;
DWORD gpHook = 0;
HMODULE ghmq2ic = nullptr;
MQMacroBlockPtr gMacroBlock = nullptr;
int BlockIndex = 0;
MQMacroStack* gMacroStack = nullptr;
decltype(gMacroSubLookupMap) gMacroSubLookupMap;
decltype(gUndeclaredVars) gUndeclaredVars;
MQEventQueue* gEventQueue = nullptr;
int gEventFunc[NUM_EVENTS] = { 0 };
UCHAR gLastFind = 0;
double gZFilter = 10000.0f;
double gFaceAngle = 10000.0f;
double gLookAngle = 10000.0f;
bool gbSpelldbLoaded = false;
char gszEQPath[MAX_STRING] = { 0 };
char gszMacroPath[MAX_STRING] = { 0 };
char gszLogPath[MAX_STRING] = { 0 };
char gszINIPath[MAX_STRING] = { 0 };
char gszINIFilename[MAX_STRING] = { 0 };
char gszItemDB[MAX_STRING] = { 0 };
char gszMacroName[MAX_STRING] = { 0 };
char szLastCommand[MAX_STRING] = { 0 };

char gszLastNormalError[MAX_STRING] = { 0 };
char gszLastSyntaxError[MAX_STRING] = { 0 };
char gszLastMQ2DataError[MAX_STRING] = { 0 };

PSPAWNINFO pNamingSpawn = 0;
char gszSpawnPlayerName[8][MAX_STRING] = {
	"",//0
	"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//1
	"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//2
	"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},\"${NamingSpawn.GuildStatus} of \",]}${NamingSpawn.Guild}>,]}",//3
	"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}${If[${NamingSpawn.Guild.Length},\n<${If[${NamingSpawn.GuildStatus.NotEqual[member]},\"${NamingSpawn.GuildStatus} of \",]}${NamingSpawn.Guild}>,]}",//4
	"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//5
	"${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Trader},\"Trader \",]}${If[${NamingSpawn.AARank},\"${NamingSpawn.AATitle} \",]}${If[${NamingSpawn.Invis},(${NamingSpawn.DisplayName}),${NamingSpawn.DisplayName}]}${If[${NamingSpawn.Surname.Length},\" ${NamingSpawn.Surname}\",]}${If[${NamingSpawn.Suffix.Length},\" ${NamingSpawn.Suffix}\",]}${If[${NamingSpawn.AFK},\" AFK\",]}${If[${NamingSpawn.Linkdead},\" LD\",]}${If[${NamingSpawn.LFG},\" LFG\",]}${If[${NamingSpawn.GroupLeader},\" LDR\",]}",//6 
};
char gszSpawnNPCName[MAX_STRING] = "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Assist},\">> \",]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist},\" - ${NamingSpawn.PctHPs}%<<\",]}${If[${NamingSpawn.Surname.Length},\n(${NamingSpawn.Surname}),]}";
char gszSpawnPetName[MAX_STRING] = "${If[${NamingSpawn.Mark},\"${NamingSpawn.Mark} - \",]}${If[${NamingSpawn.Assist},\">> \",]}${NamingSpawn.DisplayName}${If[${NamingSpawn.Assist},\" - ${NamingSpawn.PctHPs}%<<\",]}${If[${NamingSpawn.Master.Type.Equal[PC]},\n(${NamingSpawn.Master}),]}";
char gszSpawnCorpseName[MAX_STRING] = "${NamingSpawn.DisplayName}'s corpse";
char gszAnonCaption[MAX_STRING] = "[${NamingSpawn.Level}] ${NamingSpawn.Race} ${NamingSpawn.Class} ${NamingSpawn.Type}";

DWORD DrawHUDParams[4] = { 0,0,0,0 };

Blech *pMQ2Blech = nullptr;
char EventMsg[MAX_STRING] = { 0 };
Blech *pEventBlech = nullptr;
MQEventList* pEventList = nullptr;

DWORD gEventChat = 0;
ULONGLONG gRunning = 0;
BOOL gbMoving = FALSE;
DWORD gMaxTurbo = 80;
DWORD gTurboLimit = 240;
BOOL gReturn = TRUE;
BOOL gInClick = FALSE;
DWORD gbAssistComplete = 0;
BOOL gTargetbuffs = FALSE;
BOOL gItemsReceived = FALSE;
bool gbInZone = false;
bool gZoning = false;
ULONGLONG OldLastEnteredZone = 0;
ULONGLONG LastEnteredZone = 0;
bool WereWeZoning = true;
bool gbInChat = false;
bool gFilterSkillsAll = false;
bool gFilterSkillsIncrease = false;
bool gFilterTarget = false;
BOOL gFilterDebug = FALSE;
bool gFilterMoney = false;
bool gFilterFood = false;
BOOL gFilterMacro = FALSE;
BOOL gFilterMQ = FALSE;
bool gFilterEncumber = false;
bool gFilterCustom = true;
BOOL gSpewToFile = FALSE;
bool gbDoAutoRun = false;
BOOL gMQPauseOnChat = FALSE;
BOOL gKeepKeys = FALSE;
bool gLClickedObject = false;
MQWhoFilter gFilterSWho = { 0 };
MQLIB_VAR BOOL gFilterMQ2DataErrors = FALSE;
BOOL gCreateMQ2NewsWindow = TRUE;
char gIfDelimiter = ',';
char gIfAltDelimiter = '~';
DWORD gNetStatusXPos = 0;
DWORD gNetStatusYPos = 0;
LONG gStackingDebug = 0;
BOOL gUseNewNamedTest = 0;
BOOL gbInForeground = FALSE;

double DegToRad = 57.295779513082320876846364344191;
double PI = 3.1415926535;

MQTimer* gTimer = nullptr;
LONG gDelay = 0;
char gDelayCondition[MAX_STRING] = { 0 };
BOOL bAllowCommandParse = TRUE;
LONG gDelayZoning = 0;
std::map<DWORD, std::list<MQSpawnSearch>> gAlertMap;

SPAWNINFO MercenarySpawn = { 0 };
SPAWNINFO PetSpawn = { 0 };
SPAWNINFO EnviroTarget = { 0 };
GROUNDOBJECT GroundObject;
PGROUNDITEM	pGroundTarget = nullptr;
SPAWNINFO DoorEnviroTarget = { 0 };
PDOOR pDoorTarget = nullptr;
PITEMDB gItemDB = nullptr;
bool bRunNextCommand = false;
bool gTurbo = false;
bool gWarning = false;
MQDefine* pDefines = nullptr;
MQBindList* pBindList = nullptr;
char gLastFindSlot[MAX_STRING] = { 0 };
MQFilter* gpFilters = nullptr;

// TODO: Remove this once the parsing engine is fully backwards compatible.
// Alternatively, move it into the macro block.
DWORD gdwParserEngineVer = 1;

MOUSESPOOF* gMouseData = nullptr;
bool bDetMouse = true;

// EQ Functions Initialization
fEQCommand        cmdHelp = nullptr;
fEQCommand        cmdWho = nullptr;
fEQCommand        cmdWhoTarget = nullptr;
fEQCommand        cmdLocation = nullptr;
fEQCommand        cmdFace = nullptr;
fEQCommand        cmdTarget = nullptr;
fEQCommand        cmdCharInfo = nullptr;
fEQCommand        cmdFilter = nullptr;
fEQCommand        cmdDoAbility = nullptr;
fEQCommand        cmdCast = nullptr;
fEQCommand        cmdUseItem = nullptr;
fEQCommand        cmdPet = nullptr;
fEQCommand        cmdMercSwitch = nullptr;
fEQCommand        cmdAdvLoot = nullptr;
fEQCommand        cmdPickZone = nullptr;
fEQCommand        cmdAssist = nullptr;
fEQCommand        cmdQuit = nullptr;

const char* szEQMappableCommands[nEQMappableCommands];
decltype(ItemSlotMap) ItemSlotMap;

char DataTypeTemp[MAX_STRING] = { 0 };
TargetBuff TargetBuffTemp = { 0 };

decltype(SpawnByName) SpawnByName;
MQRank EQP_DistArray[3000];
DWORD gSpawnCount = 0;

// Motd and Pulse's mouse variables
bool gMouseClickInProgress[8] = { false };

// End of mouse variables

const char* gDiKeyName[256];

const char* szHeading[] = {
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

const char* szHeadingShort[] = {
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

const char* szHeadingNormal[] = {
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

const char* szHeadingNormalShort[] = {
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

const char* szSize[] = {
	"Tiny",
	"Small",
	"Normal",
	"Large",
	"Giant",
	"Huge", //?
	"Unknown" //?
};

const char* szSpawnType[] = {
	"player",
	"NPC",
	"corpse",
	"any",
	"pet",
	nullptr // SuperWhoTarget
};

const char* szGuildStatus[] = {
	"",
	"Leader",
	"Senior Officer",
	"Officer",
	"Active Member",
	"Member",
	"Junior Member",
	"Initiate",
	"Recruit",
	nullptr
};

const char* szGender[] = {
	"male",
	"female",
	"neuter",
	"unknown"
};

const char* szDeityTeam[] = {
	"none",     //0
	"good",     //1
	"neutral",  //2
	"evil"      //3
};

const char* szLights[] = {
	"NONE",    // 0  - No light
	"CDL",     // 1  - Candle
	"TR",      // 2  - Torch
	"TGS",     // 3  - Tiny Glowing Skull
	"SL",      // 4  - Small Lantern
	"SoM",     // 5  - Stein of Moggok
	"LL",      // 6  - Large Lantern
	"FL",      // 7  - Flameless lantern, Halo of Light
	"GOS",     // 8  - Globe of stars
	"LG",      // 9  - Light Globe
	"LS",      // 10 - Lightstone, Burnt-out lightstone, wispstone
	"GLS",     // 11 - Greater lightstone
	"FBE",     // 12 - Fire Beatle Eye, Firefly Globe
	"CL"       // 13 - Coldlight
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

const char* szSkills[] = {
#include "../eqdata/skills.h"
	nullptr
};

const char* szInnates[] = {
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
	nullptr
};

const char* szZoneExpansionName[] = {
	"Original EQ",              //0
	"Kunark",                   //1
	"Velious",                  //2
	"Luclin",                   //3
	"Planes of Power",          //4
	"Legacy of Ykesha",         //5
	"Lost Dungeons of Norrath", //6
	"Gates of Discord",         //7
	"Omens of War",             //8
	"Dragons of Norrath",       //9
	"Depths of Darkhollow",     //10
	"Prophecy of Ro",           //11
	"Serpent's Spine",          //12
	"Buried Sea",               //13
	"Secrets of Faydwer",       //14
	"Seeds of Destruction",     //15
	"Underfoot",                //16
	"House of Thule",           //17
	"Veil of Alaris",           //18
	"Rain of Fear",             //19
	"Call of the Forsaken",     //20
	"Broken Mirror",            //21
};

const char* szDmgBonusType[] = {
	"None",
	"Magic",
	"Fire",
	"Cold",
	"Poison",
	"Disease"
};

const char* szBodyType[] = {
	"Object",//0       (catapults, tents, practice dummies, etc)
	"Humanoid", //1
	"Lycanthrope", //2
	"Undead", //3
	"Giant", //4
	"Construct", //5   (includes confused mutations in ldon, chests as of 9-19-2006)
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
	"Greig", //17
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
	"Puff Dragon",//29
	"Bane Dragon",//30
	"Familiar",//31
	"Proc Pet",//32 (NoCorpseNpc)
	"Cursed",//33  (5 as of 9-19-2006)
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
	"Swarm Pet",//63
	"Monster Summoning",//64
	"Trap",//65
	"Timer",//66
	"Trigger",//67
	"*UNKNOWN BODYTYPE 68",
	"*UNKNOWN BODYTYPE 69",
	"*UNKNOWN BODYTYPE 70",
	"*UNKNOWN BODYTYPE 71",
	"*UNKNOWN BODYTYPE 72",
	"*UNKNOWN BODYTYPE 73",
	"*UNKNOWN BODYTYPE 74",
	"*UNKNOWN BODYTYPE 75",
	"*UNKNOWN BODYTYPE 76",
	"*UNKNOWN BODYTYPE 77",
	"*UNKNOWN BODYTYPE 78",
	"*UNKNOWN BODYTYPE 79",
	"*UNKNOWN BODYTYPE 80",
	"*UNKNOWN BODYTYPE 81",
	"*UNKNOWN BODYTYPE 82",
	"*UNKNOWN BODYTYPE 83",
	"*UNKNOWN BODYTYPE 84",
	"*UNKNOWN BODYTYPE 85",
	"*UNKNOWN BODYTYPE 86",
	"*UNKNOWN BODYTYPE 87",
	"*UNKNOWN BODYTYPE 88",
	"*UNKNOWN BODYTYPE 89",
	"*UNKNOWN BODYTYPE 90",
	"*UNKNOWN BODYTYPE 91",
	"*UNKNOWN BODYTYPE 92",
	"*UNKNOWN BODYTYPE 93",
	"*UNKNOWN BODYTYPE 94",
	"*UNKNOWN BODYTYPE 95",
	"*UNKNOWN BODYTYPE 96",
	"*UNKNOWN BODYTYPE 97",
	"*UNKNOWN BODYTYPE 98",
	"*UNKNOWN BODYTYPE 99",
	"Untargetable",//100 (Property Utility)
	"Property Trap",//101
	"Property Companion",//102
	"Property Suicide",//103
};

const char* szAugRestrictions[] = {
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

const char* szEquipmentSlot[] = {
	"head",
	"chest",
	"arms",
	"wrists",
	"hands",
	"legs",
	"feet",
	"primary",
	"offhand",
	nullptr
};

const char* szItemSlot[] = {
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
	"powersource",
	"ammo",
	"pack1",
	"pack2",
	"pack3",
	"pack4",
	"pack5",
	"pack6",
	"pack7",
	"pack8",        // 30
	"pack9",
	"pack10",
	"cursor",
	nullptr            // 31
};

const char* szExpansions[] = {
	"The Ruins of Kunark",
	"The Scars of Velious",
	"The Shadows of Luclin",
	"The Planes of Power",
	"The Legacy of Ykesha",
	"Lost Dungeons of Norrath",
	"Gates of Discord",
	"Omens of War",
	"Dragons of Norrath",
	"Depths of Darkhollow",
	"Prophecy of Ro",
	"The Serpent's Spine",
	"The Buried Sea",
	"Secrets of Faydwer",
	"Seeds of Destruction",
	"Underfoot",
	"House of Thule",
	"Veil of Alaris",
	"Rain of Fear",
	"Call of the Forsaken",
	"The Darkened Sea",
	"The Broken Mirror",
	"Empires of Kunark",
	"Ring of Scale",
	"The Burning Lands",
	nullptr
};

BOOL bAllErrorsFatal = FALSE;
bool bAllErrorsDumpStack = false;
BOOL bAllErrorsLog = FALSE;
BOOL gbHUDUnderUI = 1;
BOOL gbAlwaysDrawMQHUD = 0;
BOOL gbMQ2LoadingMsg = TRUE;
BOOL gbExactSearchCleanNames = FALSE;

MQPlugin* pPlugins = nullptr;
std::map<std::string, MQDataVar*> VariableMap;
std::unordered_map<std::string, std::unique_ptr<MQDataItem>> MQ2DataMap;

size_t g_eqgameimagesize = 0;
bool gbTimeStampChat = false;
BOOL gUseTradeOnTarget = 1;
bool gbBeepOnTells = false;
bool gbFlashOnTells = false;
BOOL gbIgnoreAlertRecursion = 0;
bool gbShowCurrentCamera = true;
int  oldcameratype = -1;
char CameraText[2048] = { "Window Selector (Camera 0)" };

fEQGetMelee     get_melee_range = GetMeleeRange;
fEQW_GetDisplayWindow EQW_GetDisplayWindow = nullptr;

fICGetHashData IC_GetHashData = nullptr;
fICSetHashData IC_SetHashData = nullptr;
fLoaderSetLoaded IC_LoaderSetLoaded = nullptr;
fLoaderClearLoaded IC_LoaderClearLoaded = nullptr;
fMQ2Unload IC_MQ2Unload = nullptr;
fClassLvl IC_ClassLvl = nullptr;

#ifdef __ExecuteCmd_x
FUNCTION_AT_ADDRESS(bool EQExecuteCmd(unsigned int command, bool keyDown, void* data, const KeyCombo* combo), __ExecuteCmd);
#endif

bool ExecuteCmd(unsigned int command, bool keyDown, void* data)
{
	return EQExecuteCmd(command, keyDown, data, nullptr);
}

} // namespace mq
