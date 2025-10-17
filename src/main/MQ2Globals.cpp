/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

uintptr_t baseAddress = (uintptr_t)::GetModuleHandleA(nullptr);


/* PickZone */
HANDLE ghInitializeSpellDbThread = nullptr;

/* BENCHMARKS */
uint32_t bmRenderScene = 0;
uint32_t bmUpdateSpawnSort = 0;
uint32_t bmUpdateSpawnCaptions = 0;
uint32_t bmSpellLoad = 0;
uint32_t bmSpellAccess = 0;
uint32_t bmAnonymizer = 0;

MQDataVar* pGlobalVariables = nullptr;
MQDataVar* pMacroVariables = nullptr;

ePVPServer PVPServer = PVP_NONE;
char gszVersion[32] = __ExpectedVersionDate;
char gszTime[32] = __ExpectedVersionTime;

#if defined(EMULATOR)
int gBuild = static_cast<int>(BuildTarget::Emu);                // EMU (ROF2)
#elif defined(TEST)
int gBuild = static_cast<int>(BuildTarget::Test);               // TEST
#else
int gBuild = static_cast<int>(BuildTarget::Live);               // LIVE
#endif

int gGameState = 0;
bool gAnonymize = false; // Deprecate
DWORD ThreadID = 0;
bool g_Loaded = false;
bool gbWriteAllConfig = false;

HMODULE ghModule = nullptr;
HINSTANCE ghInstance = nullptr;
HWND ghInjectorWnd = nullptr;
bool gbUnload = false;
bool gbForceUnload = false;
bool gBindInProgress = false;
bool gbLoad = true;
DWORD gpHook = 0;
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
char gUISkin[MAX_PATH] = "default";
char gPathMQRoot[MAX_PATH] = { 0 };
char gPathConfig[MAX_PATH] = { 0 };
char gPathMQini[MAX_PATH] = { 0 };
char gPathMacros[MAX_PATH] = { 0 };
char gPathLogs[MAX_PATH] = { 0 };
char gPathCrashDumps[MAX_PATH] = { 0 };
char gPathPlugins[MAX_PATH] = { 0 };
char gPathResources[MAX_PATH] = { 0 };
char gPathEverQuest[MAX_PATH] = { 0 }; // Although the working directory is EverQuest, the WIN_API calls source to %WINDIR%
std::string mq::internal_paths::MQRoot = ".";
std::string mq::internal_paths::Config = "Config";
std::string mq::internal_paths::MQini = mq::internal_paths::Config + "\\MacroQuest.ini";
std::string mq::internal_paths::Macros = "Macros";
std::string mq::internal_paths::Logs = "Logs";
std::string mq::internal_paths::CrashDumps = mq::internal_paths::Logs + "\\Dumps";
std::string mq::internal_paths::Plugins = "Plugins";
std::string mq::internal_paths::Resources = "Resources";
std::string mq::internal_paths::EverQuest = "%PUBLIC%\\Daybreak Game Company\\Installed Games\\EverQuest"; // Although the working directory is EverQuest, the WIN_API calls source to %WINDIR%

char gszLastNormalError[MAX_STRING] = { 0 };
char gszLastSyntaxError[MAX_STRING] = { 0 };
char gszLastMQ2DataError[MAX_STRING] = { 0 };

// TODO: uintptr is the biggest actual type, but this should be a struct
uintptr_t DrawHUDParams[4] = { 0, 0, 0, 0 };

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

static MQGroundObject FromGroundSpawn(const MQGroundSpawn& ground)
{
	MQGroundObject ret;

	if (ground.Type == MQGroundSpawnType::Ground)
	{
		ret.Type = GO_GroundType;
		ret.GroundItem = *ground.Get<EQGroundItem>();
	}
	else if (ground.Type == MQGroundSpawnType::Placed)
	{
		auto placed = ground.Get<EQPlacedItem>();
		ret.Type = GO_ObjectType;
		ret.ObjPtr = (void*)placed;
		ret.GroundItem.DropID = placed->RealEstateItemID;
		ret.GroundItem.DropSubID = placed->RealEstateID;
		ret.GroundItem.Expires = 0;
		ret.GroundItem.Heading = placed->Heading;
		ret.GroundItem.Item = nullptr;
		strcpy_s(ret.GroundItem.Name, GetFriendlyNameForPlacedItem(placed).c_str());
		ret.GroundItem.Pitch = placed->Angle;
		ret.GroundItem.pNext = nullptr;
		ret.GroundItem.pPrev = nullptr;
		ret.GroundItem.pActor = placed->pActor;
		ret.GroundItem.Roll = placed->Roll;
		ret.GroundItem.Scale = placed->Scale;
		ret.GroundItem.Weight = 0;
		ret.GroundItem.X = placed->X;
		ret.GroundItem.Y = placed->Y;
		ret.GroundItem.Z = placed->Z;
		ret.GroundItem.ZoneID = pLocalPlayer->GetZoneID() & 0x7FFF;
	}
	else
	{
		ret.Type = GO_None;
	}

	return ret;
}

Property<MQGroundObject> GroundObject = Property<MQGroundObject>(
	[]() -> MQGroundObject
	{
		return FromGroundSpawn(CurrentGroundSpawn());
	},
	[](const MQGroundObject& other) -> MQGroundObject
	{
		return FromGroundSpawn(GetGroundSpawnByID(other.GroundItem.DropID));
	});

Property<GROUNDITEM*> pGroundTarget = Property<GROUNDITEM*>(
	[]() -> GROUNDITEM*
	{
		auto ground = CurrentGroundSpawn();
		if (ground.Type == MQGroundSpawnType::Ground)
			return ground.Get<EQGroundItem>();

		return nullptr;
	},
	[](GROUNDITEM* other) -> GROUNDITEM*
	{
		if (!other)
			return nullptr;

		return GetGroundSpawnByID(other->DropID).Get<EQGroundItem>();
	});

EQSwitch* pSwitchTarget = nullptr;
ITEMDB* gItemDB = nullptr;
bool bRunNextCommand = false;
bool gTurbo = false;
bool gWarning = false;
MQDefine* pDefines = nullptr;
MQBindList* pBindList = nullptr;
char gLastFindSlot[MAX_STRING] = { 0 };
MQFilter* gpFilters = nullptr;

// Deprecated
int PetSpawn = 0;
int MercenarySpawn = 0;
int DoorEnviroTarget = 0;
int EnviroTarget = 0;

EQSwitch* pDoorTarget = nullptr;

// TODO: Remove this once the parsing engine is fully backwards compatible.
// Alternatively, move it into the macro block.
int gParserVersion = 1;

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
fEQCommand cmdTaskQuit = nullptr;
fEQCommand cmdPet = nullptr;
fEQCommand cmdMercSwitch = nullptr;
#if HAS_ADVANCED_LOOT
fEQCommand cmdAdvLoot = nullptr;
#endif
fEQCommand cmdPickZone = nullptr;
fEQCommand cmdAssist = nullptr;
fEQCommand cmdQuit = nullptr;

const char* szEQMappableCommands[nEQMappableCommands];
decltype(ItemSlotMap) ItemSlotMap;

SGlobalBuffer DataTypeTemp;

MQRank* EQP_DistArray = nullptr;
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
#include "eqdata/skills.h"
	nullptr
};

const char* szInnates[] = {
	nullptr,          // 0
	"Awareness",      // 1
	"Bash Door",      // 2
	"Breathe Fire",   // 3
	"Harmony",        // 4
	"Harm Touch",     // 5
	"Infravision",    // 6
	"Lay Hands",      // 7
	"Lore",           // 8
	"No Bash",        // 9
	"Regeneration",   // 10
	"Slam",           // 11
	"Surprise",       // 12
	"Ultravision",    // 13
	"Inspect",        // 14
	"Open",           // 15
	"Reveal Trap",    // 16
	nullptr,          // 17
	nullptr,          // 18
	nullptr,          // 19
	nullptr,          // 20
	nullptr,          // 21
	nullptr,          // 22
	nullptr,          // 23
	nullptr,          // 24
};

[[deprecated("Use GetZoneExpansionName or GetExpansionNumber")]]
const char* szZoneExpansionName[] = {
	"Original EQ",              // 0
	"Kunark",                   // 1
	"Velious",                  // 2
	"Luclin",                   // 3
	"Planes of Power",          // 4
	"Legacy of Ykesha",         // 5
	"Lost Dungeons of Norrath", // 6
	"Gates of Discord",         // 7
	"Omens of War",             // 8
	"Dragons of Norrath",       // 9
	"Depths of Darkhollow",     // 10
	"Prophecy of Ro",           // 11
	"Serpent's Spine",          // 12
	"Buried Sea",               // 13
	"Secrets of Faydwer",       // 14
	"Seeds of Destruction",     // 15
	"Underfoot",                // 16
	"House of Thule",           // 17
	"Veil of Alaris",           // 18
	"Rain of Fear",             // 19
	"Call of the Forsaken",     // 20
	"The Darkened Sea",         // 21
	"The Broken Mirror",        // 22
	"Empires of Kunark",        // 23
	"Ring of Scale",            // 24
	"The Burning Lands",        // 25
	"Torment of Velious",       // 26
	"Claws of Veeshan",         // 27
	"Terror of Luclin",         // 28
	"Night of Shadows",         // 29
	"Laurion's Song",           // 30
	"The Outer Brood",          // 31
};

const char* GetZoneExpansionName(int expansion)
{
	if (expansion >= 0 && expansion <= NUM_EXPANSIONS)
	{
		if (const char* ptr = pCDBStr->GetString(expansion, eExpansionName, nullptr))
			return ptr;
	}

	return "Unknown";
}

uint32_t GetExpansionNumber(std::string_view expansionName)
{
	for (int i = 0; i <= NUM_EXPANSIONS; ++i)
	{
		if (const char* ptr = pCDBStr->GetString(i, eExpansionName, nullptr))
			if (ci_equals(ptr, expansionName))
				return i;
	}

	return 0;
}

const char* GetHighestExpansionOwnedName(EQExpansionOwned expansionOwned)
{
	if (expansionOwned == EQExpansionNoneOwned)
		return GetZoneExpansionName(0);

	for (int num = NUM_EXPANSIONS; num >= 1; --num)
	{
		if ((EQ_EXPANSION(num) & expansionOwned) != 0)
			return GetZoneExpansionName(num);
	}

	return "Unknown";
}

const char* szDmgBonusType[] = {
	"None",
	"Magic",
	"Fire",
	"Cold",
	"Poison",
	"Disease"
};

const char* szBodyType[] = {
	"Object",                //  0    not a real body type. (catapults, tents, practice dummies, etc)
	"Humanoid",              //  1
	"Lycanthrope",           //  2
	"Undead",                //  3
	"Giant",                 //  4
	"Construct",             //  5
	"Extraplanar",           //  6
	"Magical",               //  7
	"Undead Pet",            //  8
	"Bane Giant",            //  9
	"Dain",                  // 10
	"Untargetable",          // 11
	"Vampyre",               // 12
	"Atenha Ra",             // 13
	"Greater Akheva",        // 14
	"Khati Sha",             // 15
	"Seru",                  // 16
	"Greig",                 // 17
	"Draz Nurakk",           // 18
	"Zek",                   // 19
	"Luggald",               // 20
	"Animal",                // 21
	"Insect",                // 22
	"Monster",               // 23
	"Elemental",             // 24
	"Plant",                 // 25
	"Dragon",                // 26
	"Elemental",             // 27
	"Summoned Creature",     // 28
	"Puff Dragon",           // 29
	"Bane Dragon",           // 30
	"Familiar",              // 31
	"No Corpse",             // 32
	"Cursed",                // 33
	"Muramite",              // 34
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
	"Monster Summoning",     // 64
	"*UNKNOWN BODYTYPE 65",
	"*UNKNOWN BODYTYPE 66",
	"*UNKNOWN BODYTYPE 67",
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
	"*UNKNOWN BODYTYPE 99",  // Seen in characterpropertysets.txt
	"Utility",               // 100
	"Property Trap",         // 101
	"Property Companion",    // 102
	"Property Suicide",      // 103
	"*UNKNOWN BODYTYPE 104", // Seen on player pets
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

const char* szItemSlot[InvSlot_Max + 1] = {
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
#if HAS_MERCHANTS_PERK
	"pack11",
	"pack12",
#endif
	"cursor",
	nullptr         // 34
};

bool bAllErrorsFatal = false;
bool bAllErrorsDumpStack = true;
bool bAllErrorsLog = false;
bool gbHUDUnderUI = true;
bool gbAlwaysDrawMQHUD = false;
bool gbMQ2LoadingMsg = true;
bool gbExactSearchCleanNames = false;

std::map<std::string, MQDataVar*> VariableMap;

size_t g_eqgameimagesize = 0;
bool gUseTradeOnTarget = true;
bool gbBeepOnTells = false;
bool gbFlashOnTells = true;
bool gbIgnoreAlertRecursion = false;
bool gbShowCurrentCamera = false;
int  gOldCameraType = -1;

fEQGetMelee get_melee_range = GetMeleeRange;
fEQW_GetDisplayWindow EQW_GetDisplayWindow = nullptr;

bool ExecuteCmd(unsigned int command, bool keyDown, void* data)
{
	if (!pLocalPC)
		return false;
	return eqlib::EQExecuteCmd(command, keyDown, data, nullptr);
}

int gbGroundDeprecateCount = -1;

} // namespace mq

#if __has_include("../private/MQ2Globals-private.cpp")
#include "../private/MQ2Globals-private.cpp"
#endif
