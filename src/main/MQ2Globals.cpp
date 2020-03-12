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

const double DegToRad = 57.295779513082320876846364344191;
const double PI = 3.1415926535;

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
DWORD bmPluginsUpdateImGui = 0;
DWORD bmParseMacroParameter = 0;
DWORD bmUpdateSpawnSort = 0;
DWORD bmUpdateSpawnCaptions = 0;
DWORD bmCalculate = 0;
DWORD bmBeginZone = 0;
DWORD bmEndZone = 0;
DWORD bmSpellLoad = 0;
DWORD bmSpellAccess = 0;
DWORD bmAnonymizer = 0;

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
bool gAnonymize = false; // Deprecate
DWORD ThreadID = 0;
bool g_Loaded = false;
bool gbWriteAllConfig = false;
bool gStringTableFixed = false;

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
char gszEQPath[MAX_STRING] = { 0 }; // Deprecate
char gszMacroPath[MAX_STRING] = { 0 }; // Deprecate
char gszLogPath[MAX_STRING] = { 0 }; // Deprecate
char gszINIPath[MAX_STRING] = { 0 }; // Deprecate
char gszINIFilename[MAX_STRING] = { 0 }; // Deprecate
char gszItemDB[MAX_STRING] = { 0 }; // Deprecate
char gszMacroName[MAX_STRING] = { 0 };
char szLastCommand[MAX_STRING] = { 0 };
char gPathMQRoot[MAX_PATH] = { 0 };
char gPathConfig[MAX_PATH] = { 0 };
char gPathMQini[MAX_PATH] = { 0 };
char gPathMacros[MAX_PATH] = { 0 };
char gPathLogs[MAX_PATH] = { 0 };
char gPathCrashDumps[MAX_PATH] = { 0 };
char gPathPlugins[MAX_PATH] = { 0 };
char gPathResources[MAX_PATH] = { 0 };
std::string mq::internal_paths::MQRoot = ".";
std::string mq::internal_paths::Config = "Config";
std::string mq::internal_paths::MQini = mq::internal_paths::Config + "\\MacroQuest.ini";
std::string mq::internal_paths::Macros = "Macros";
std::string mq::internal_paths::Logs = "Logs";
std::string mq::internal_paths::CrashDumps = mq::internal_paths::Logs + "\\Dumps";
std::string mq::internal_paths::Plugins = "Plugins";
std::string mq::internal_paths::Resources = "Resources";

char gszLastNormalError[MAX_STRING] = { 0 };
char gszLastSyntaxError[MAX_STRING] = { 0 };
char gszLastMQ2DataError[MAX_STRING] = { 0 };

// TODO: This is a rect, for drawing the hud.
DWORD DrawHUDParams[4] = { 0, 0, 0, 0 };

Blech *pMQ2Blech = nullptr;
char EventMsg[MAX_STRING] = { 0 };
Blech *pEventBlech = nullptr;
MQEventList* pEventList = nullptr;

DWORD gEventChat = 0;
uint64_t gRunning = 0;
bool gbMoving = false;
int gMaxTurbo = 80;
int gTurboLimit = 240;
bool gReturn = true;
bool gTargetbuffs = false;
bool gItemsReceived = false;
bool gbInZone = false;
bool gZoning = false;
uint64_t OldLastEnteredZone = 0;
uint64_t LastEnteredZone = 0;
bool WereWeZoning = true;
bool gbInChat = false;
bool gFilterSkillsAll = false;
bool gFilterSkillsIncrease = false;
bool gFilterTarget = false;
bool gFilterDebug = false;
bool gFilterMoney = false;
bool gFilterFood = false;
eFilterMacro gFilterMacro = FILTERMACRO_ALL;
bool gFilterMQ = false;
bool gFilterEncumber = false;
bool gFilterCustom = true;
bool gSpewToFile = false;
bool gbDoAutoRun = false;
bool gMQPauseOnChat = false;
bool gKeepKeys = true;
bool gLClickedObject = false;
MQWhoFilter gFilterSWho;
bool gFilterMQ2DataErrors = false;
bool gCreateMQ2NewsWindow = true;
char gIfDelimiter = ',';
char gIfAltDelimiter = '~';
int gNetStatusXPos = 0;
int gNetStatusYPos = 0;
eStackingDebug gStackingDebug = STACKINGDEBUG_OFF;
bool gUseNewNamedTest = false;
bool gbInForeground = false;
eAssistStage gbAssistComplete = AS_None;

MQTimer* gTimer = nullptr;
int gDelay = 0;
char gDelayCondition[MAX_STRING] = { 0 };
bool bAllowCommandParse = true;
std::map<DWORD, std::list<MQSpawnSearch>> gAlertMap;

SPAWNINFO MercenarySpawn = { 0 };
SPAWNINFO PetSpawn = { 0 };
SPAWNINFO EnviroTarget = { 0 };
MQGroundObject GroundObject;
GROUNDITEM* pGroundTarget = nullptr;
SPAWNINFO DoorEnviroTarget = { 0 };
DOOR* pDoorTarget = nullptr;
ITEMDB* gItemDB = nullptr;
bool bRunNextCommand = false;
bool gTurbo = false;
bool gWarning = false;
MQDefine* pDefines = nullptr;
MQBindList* pBindList = nullptr;
char gLastFindSlot[MAX_STRING] = { 0 };
MQFilter* gpFilters = nullptr;

// TODO: Remove this once the parsing engine is fully backwards compatible.
// Alternatively, move it into the macro block.
int gParserVersion = 1;

MOUSESPOOF* gMouseData = nullptr;
bool bDetMouse = true;

// EQ Functions Initialization
fEQCommand cmdHelp = nullptr;
fEQCommand cmdWho = nullptr;
fEQCommand cmdWhoTarget = nullptr;
fEQCommand cmdLocation = nullptr;
fEQCommand cmdFace = nullptr;
fEQCommand cmdTarget = nullptr;
fEQCommand cmdCharInfo = nullptr;
fEQCommand cmdFilter = nullptr;
fEQCommand cmdDoAbility = nullptr;
fEQCommand cmdCast = nullptr;
fEQCommand cmdUseItem = nullptr;
fEQCommand cmdHotbutton = nullptr;
fEQCommand cmdPet = nullptr;
fEQCommand cmdMercSwitch = nullptr;
fEQCommand cmdAdvLoot = nullptr;
fEQCommand cmdPickZone = nullptr;
fEQCommand cmdAssist = nullptr;
fEQCommand cmdQuit = nullptr;

const char* szEQMappableCommands[nEQMappableCommands];
decltype(ItemSlotMap) ItemSlotMap;

char DataTypeTemp[MAX_STRING] = { 0 };
TargetBuff TargetBuffTemp = { 0 };

std::map<std::string, SPAWNINFO*> SpawnByName;
MQRank EQP_DistArray[3000];
int gSpawnCount = 0;

// Motd and Pulse's mouse variables
bool gMouseClickInProgress[8] = { false };

// End of mouse variables

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
	nullptr         // 34
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
	"Torment of Velious",
	nullptr
};

bool bAllErrorsFatal = false;
bool bAllErrorsDumpStack = true;
bool bAllErrorsLog = false;
bool gbHUDUnderUI = true;
bool gbAlwaysDrawMQHUD = false;
bool gbMQ2LoadingMsg = true;
bool gbExactSearchCleanNames = false;

std::map<std::string, MQDataVar*> VariableMap;
std::unordered_map<std::string, std::unique_ptr<MQDataItem>> MQ2DataMap;

size_t g_eqgameimagesize = 0;
bool gUseTradeOnTarget = true;
bool gbBeepOnTells = false;
bool gbFlashOnTells = true;
bool gbIgnoreAlertRecursion = false;
bool gbShowCurrentCamera = false;
int  gOldCameraType = -1;

fEQGetMelee get_melee_range = GetMeleeRange;
fEQW_GetDisplayWindow EQW_GetDisplayWindow = nullptr;

fICGetHashData IC_GetHashData = nullptr;
fICSetHashData IC_SetHashData = nullptr;
fLoaderSetLoaded IC_LoaderSetLoaded = nullptr;
fLoaderClearLoaded IC_LoaderClearLoaded = nullptr;
fMQ2Unload IC_MQ2Unload = nullptr;
fClassLvl IC_ClassLvl = nullptr;

bool ExecuteCmd(unsigned int command, bool keyDown, void* data)
{
	return eqlib::EQExecuteCmd(command, keyDown, data, nullptr);
}

} // namespace mq
