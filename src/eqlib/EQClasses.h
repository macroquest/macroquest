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
#include "Items.h"
#include "PcClient.h"
#include "PlayerClient.h"
#include "Spells.h"
#include "UI.h"

#include <limits>

#undef FindWindow
#undef InsertMenuItem

namespace eqlib {

class CMemoryStream;
class CVector3;

struct TargetBuff
{
	int slot;
	int spellId;
	int duration;            // in ticks...
	int count;
	char casterName[64];

	// not actually part of this packet but we need it for cachedbuffs map
	DWORD timeStamp;         // when the buffpacket arrived.
};
using PTargetBuff [[deprecated("Use TargetBuff* Instead")]] = TargetBuff*;

struct AggroMeterListEntry
{
	void*    vfTable;
	uint16_t AggroPct;
};
using PAggroMeterListEntry = AggroMeterListEntry*;

constexpr int MAX_AGGRO_METER_SIZE = 30;

class [[offsetcomments]] AggroMeterManagerClient
{
public:
	static EQLIB_OBJECT AggroMeterManagerClient& Instance();

/*0x00*/ TSafeArrayStatic<AggroMeterListEntry, MAX_AGGRO_METER_SIZE> aggroData;
/*0xf0*/ DWORD AggroLockID;                     // this can be 0, I dont know what it is...
/*0xf4*/ DWORD AggroTargetID;                   // this is id of whoever we are fighting
/*0xf8*/ DWORD AggroSecondaryID;                // this is id of whoever the npc is fighting
/*0xfc*/
};

enum ZONE_REQ_STATUS {};
enum ZONE_REQ_REASON {};

class _EverQuestinfo
{
public:
	void EQLIB_OBJECT SetAutoAttack(bool);
};

class AltAdvManager
{
public:
	EQLIB_OBJECT AltAdvManager();

	// IsAbilityReady was checked on apr 29 2016, it looks like it has 5 arguments in IDA, but it doesnt. (it has 4)
	EQLIB_OBJECT bool IsAbilityReady(PcZoneClient*, ALTABILITY*, int* Refresh/*out*/, int* Timer/*out*/ = nullptr);
	EQLIB_OBJECT int AbilitiesByClass(int, int);
	EQLIB_OBJECT int AltSkillReqs(PcZoneClient*, int);
	EQLIB_OBJECT int CalculateDoubleAttackChance(PcZoneClient*, int, unsigned char);
	EQLIB_OBJECT int CalculateFleetOfFoot(PcZoneClient*);
	EQLIB_OBJECT int CalculateHideTimeReduce(PcZoneClient*);
	EQLIB_OBJECT int CalculateInstrumentMasteryMod(PcZoneClient*);
	EQLIB_OBJECT int CalculateLoHHarmTouchReuseTimer(PcZoneClient*, int);
	EQLIB_OBJECT int CalculateMaxHPAA(PcZoneClient*, int);
	EQLIB_OBJECT int CalculateMaxStatAA(PcZoneClient*, int);
	EQLIB_OBJECT int CalculateMitigationBoost(PcZoneClient*, int);
	EQLIB_OBJECT int CalculateNimbleEvasionChance(PcZoneClient*);
	EQLIB_OBJECT int CalculateSingingMasteryMod(PcZoneClient*, int);
	EQLIB_OBJECT int CalculateSpellCastingMastery(PcZoneClient*);
	EQLIB_OBJECT int CalculateStalwartEnduranceChance(PcZoneClient*);
	EQLIB_OBJECT bool CanTrainAbility(PcZoneClient*, CAltAbilityData*, bool, bool, bool);
	EQLIB_OBJECT bool CanSeeAbility(PcZoneClient*, CAltAbilityData*);
	EQLIB_OBJECT int GetAALevelNeeded(PcZoneClient*, int);
	EQLIB_OBJECT int GetAbilityTitle(PcZoneClient*);
	EQLIB_OBJECT int GetNextAbilityCost(int, int);
	EQLIB_OBJECT int MeetsPoPLevelReqs(PcZoneClient*, int, int);
	EQLIB_OBJECT int TotalPointsInSkill(int, int);
	EQLIB_OBJECT unsigned long GetCalculatedTimer(PcZoneClient*, ALTABILITY*);
	EQLIB_OBJECT void GetAbilityReqs(char*, int);
	EQLIB_OBJECT ALTABILITY* GetAAById(int index, int level = -1);
};

// we call this _AURAINFO
class [[offsetcomments]] AssociatedSOIData
{
public:
/*0x00*/ char         Name[0x40];
/*0x40*/ uint32_t     SpawnID;
/*0x44*/ int          Cost;
/*0x48*/ int          IconnID;
/*0x4c*/
};

// we call this _AURAMGR
class ClientSOIManager
{
public:
	ArrayClass2<AssociatedSOIData> Auras;

	static EQLIB_OBJECT ClientSOIManager* GetSingleton();
};

class [[offsetcomments]] EQGroundItem
{
public:
/*0x00*/ EQGroundItem* pPrev;
/*0x04*/ EQGroundItem* pNext;
/*0x08*/ VePointer<CONTENTS> pContents;
/*0x0c*/ DWORD         DropID;                   // unique id
/*0x10*/ DWORD         ZoneID;
/*0x14*/ DWORD         DropSubID;                // well zonefile id, but yeah...
/*0x18*/ void*         pSwitch;                  // CActorInterface
/*0x1c*/ char          Name[0x40];
/*0x5c*/ long          Expires;
/*0x60*/ float         Heading;
/*0x64*/ float         Pitch;
/*0x68*/ float         Roll;
/*0x6c*/ float         Scale;
/*0x70*/ float         Y;
/*0x74*/ float         X;
/*0x78*/ float         Z;
/*0x7c*/ int           Weight;                   // -1 means it can't be picked up
/*0x80*/
};

class EQGroundItemListManager
{
public:
	EQGroundItem*      Top;

	static EQLIB_OBJECT EQGroundItemListManager& Instance();
};

// well we call this CTextOverlay but whatever should probably rename at some point...
class [[offsetcomments]] CBroadcast
{
public:
	static EQLIB_OBJECT CBroadcast* Get();
	EQLIB_OBJECT void BroadcastString(const CXStr cxStr, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
	EQLIB_OBJECT void BroadcastString(const char* Str, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
	EQLIB_OBJECT void EndBroadcast(UINT FadeOutTime);
	EQLIB_OBJECT void Draw();

/*0x00*/ CTextObjectInterface* TextObject;
/*0x04*/ bool               bBroadcastActive;
/*0x05*/ bool               bFadingOut;
/*0x06*/ bool               bFadingIn;
/*0x08*/ UINT               StartTime;
/*0x0c*/ UINT               FadeInTime;
/*0x10*/ UINT               EndTime;
/*0x14*/ UINT               FadeOutTime;
/*0x18*/ UINT               DisplayTime;
/*0x1c*/ int                BroadcastColor;
/*0x20*/ int                CurrentPriority;
/*0x24*/ int                MaxAlpha;
/*0x28*/
};


class ChatManagerClient
{
public:
	static EQLIB_OBJECT ChatManagerClient& Instance();
};

struct D3DXVECTOR3;

class CPhysicsInfo;

enum EnvironmentType
{
	ENVIRONMENT_GENERIC,                // factory default
	ENVIRONMENT_PADDEDCELL,
	ENVIRONMENT_ROOM,                   // standard environments
	ENVIRONMENT_BATHROOM,
	ENVIRONMENT_LIVINGROOM,
	ENVIRONMENT_STONEROOM,
	ENVIRONMENT_AUDITORIUM,
	ENVIRONMENT_CONCERTHALL,
	ENVIRONMENT_CAVE,
	ENVIRONMENT_ARENA,
	ENVIRONMENT_HANGAR,
	ENVIRONMENT_CARPETEDHALLWAY,
	ENVIRONMENT_HALLWAY,
	ENVIRONMENT_STONECORRIDOR,
	ENVIRONMENT_ALLEY,
	ENVIRONMENT_FOREST,
	ENVIRONMENT_CITY,
	ENVIRONMENT_MOUNTAINS,
	ENVIRONMENT_QUARRY,
	ENVIRONMENT_PLAIN,
	ENVIRONMENT_PARKINGLOT,
	ENVIRONMENT_SEWERPIPE,
	ENVIRONMENT_UNDERWATER,
	ENVIRONMENT_DRUGGED,
	ENVIRONMENT_DIZZY,
	ENVIRONMENT_PSYCHOTIC,

	ENVIRONMENT_COUNT                   // total number of environments
};

class [[offsetcomments]] CDisplay
{
public:
/*0x0000*/ bool        ErrorFlag;
/*0x0001*/ BYTE        BFog;
/*0x0002*/ BYTE        BMoveAnims;
/*0x0004*/ float       Yon;
/*0x0008*/ float       AmbientLight;
/*0x000c*/ BYTE        DragItem;
/*0x000d*/ BYTE        DragMoney;
/*0x000e*/ BYTE        DragHotButton;
/*0x000f*/ bool        bInRenderLoop;
/*0x0010*/ bool        bHideLootedCorpses;
/*0x0011*/ char        LastTeleportAreaTag[0x100];
/*0x0114*/ void*       pCamera;                  // CCameraInterface
/*0x0118*/ CVector3*   CamPos;
/*0x011c*/ CVector3*   CamOrientation;
/*0x0120*/ void*       WadFileLoadScreen;        // SWadFile
/*0x0124*/ BYTE        NewPCModelsLoaded;
/*0x0125*/ bool        bHorsesLoaded;
/*0x0128*/ void*       pActorTagManager;
/*0x012c*/ BYTE        Unknown0x130[0x24];
/*0x0150*/ DWORD       TimeStamp;
/*0x0154*/ BYTE        Unknown0x158[0x2c12];
/*0x2d66*/ BYTE        NpcNames;                 // show npc names
/*0x2d68*/

	EQLIB_OBJECT ~CDisplay();
	EQLIB_OBJECT CDisplay(HWND);
	EQLIB_OBJECT bool GenericSphereColl(float, float, float, float, float, float, float*, float*, float*, unsigned char);
	EQLIB_OBJECT bool SlideSwitchLeftRight(EQSwitch*, float, int, float);
	EQLIB_OBJECT bool const GetWorldFilePath(char*, const char*);
	EQLIB_OBJECT char* GetIniRaceName(int);
	EQLIB_OBJECT PlayerClient* GetNearestPlayerInView(float, bool);
	EQLIB_OBJECT float FindZoneTopZ(float, float, float);
	EQLIB_OBJECT float FixHeading(float);
	EQLIB_OBJECT float GetFloorHeight(float X, float Y, float F, float Radius = 0.0f, const CVector3& CollisionVector = CVector3(-1, -1, 1), CActorApplicationData* pAppData = 0, EActorType eActorType = Undefined, float ZOffset = 1.0f);
	EQLIB_OBJECT float HeadingDiff(float, float, float*);
	EQLIB_OBJECT float PlayerDistance(PlayerZoneClient*, PlayerZoneClient*, float);
	EQLIB_OBJECT float PlayerSimpleDistance(PlayerZoneClient*, PlayerZoneClient*, float);
	EQLIB_OBJECT float SetActorBoundingRadius(CActorInterface*, float, float);
	EQLIB_OBJECT float SimpleDistance(float, float, float, float, float, float, float);
	EQLIB_OBJECT float TrueDistance(float fromx, float fromy, float fromz, float tox, float toy, float toz, float zfactor);
	EQLIB_OBJECT int GetItemType(int);
	EQLIB_OBJECT int GetNewPCIniFlag(int, int);
	EQLIB_OBJECT int GetSkyTime(int*, int*);
	EQLIB_OBJECT int is_3dON();
	EQLIB_OBJECT int is_ParticleSystemON();
	EQLIB_OBJECT int MoveMissile(EQMissile*);
	EQLIB_OBJECT int ShouldLoadNewPcModel(int, int);
	EQLIB_OBJECT int TurnInfravisionEffectOff();
	EQLIB_OBJECT int TurnInfravisionEffectOn();
	EQLIB_OBJECT long SetUserRender(int);
	EQLIB_OBJECT static char* DefaultUIPath;
	EQLIB_OBJECT static char* UIPath;
	EQLIB_OBJECT static int __cdecl WriteTextHD2(const char*text, int X, int Y, int color);
	EQLIB_OBJECT static unsigned long __cdecl GetUserDefinedColor(int);
	EQLIB_OBJECT static void __cdecl SetUserDefinedColor(int, int, int, int);
	EQLIB_OBJECT CLightInterface* CreateLight(unsigned char, float, float, float, float);
	EQLIB_OBJECT CActorInterface* CreateActor(char*, float, float, float, float, float, float, bool, bool);
	EQLIB_OBJECT CActorInterface* GetClickedActor(int X, int Y, bool bFlag, CVector3& Vector1, CVector3& Vector2);
	EQLIB_OBJECT unsigned char GetEnvironment(float, float, float, int*);
	EQLIB_OBJECT unsigned char GetIntensity(unsigned char);
	EQLIB_OBJECT unsigned char LoadBMPFile();
	EQLIB_OBJECT unsigned char LoadNPCFromS3D(char*, char*, char*);
	EQLIB_OBJECT unsigned char LoadWorldFile(char*, char*, int, unsigned char);
	EQLIB_OBJECT unsigned int IsShield(int) const;
	EQLIB_OBJECT void ActivateMainUI(bool);
	EQLIB_OBJECT void ChangeVideoMode();
	EQLIB_OBJECT void CheckForScreenModeToggle();
	EQLIB_OBJECT void CleanUpDDraw();
	EQLIB_OBJECT void ClearScreen();
	EQLIB_OBJECT void CreatePlayerActor(PlayerClient*);
	EQLIB_OBJECT void DDrawUpdateDisplay();
	EQLIB_OBJECT void DeactivateMainUI();
	EQLIB_OBJECT void default_cameras();
	EQLIB_OBJECT void DefineSoloMode();
	EQLIB_OBJECT void DeleteActor(CActorInterface*);
	EQLIB_OBJECT void DeleteLight(CLightInterface*);
	EQLIB_OBJECT void GetOnActor(CActorInterface*, PlayerZoneClient*);
	EQLIB_OBJECT void HandleMaterial(PcClient*, int, EQ_Item*, EQ_Item*);
	EQLIB_OBJECT void hideGrassObjects();
	EQLIB_OBJECT void InitCharSelectUI();
	EQLIB_OBJECT void InitCommonLights();
	EQLIB_OBJECT void InitDDraw();
	EQLIB_OBJECT void InitEverQuestLocale(EQLocalizeLanguage);
	EQLIB_OBJECT void InitUserDefinedColors();
	EQLIB_OBJECT void InitWorld();
	EQLIB_OBJECT void KeyMapUpdated();
	EQLIB_OBJECT void LightningStrike();
	EQLIB_OBJECT void loadGrassObjects(char*);
	EQLIB_OBJECT void MoveLight(CLightInterface*, CPhysicsInfo*);
	EQLIB_OBJECT void MoveLocalPlayerToSafeCoords();
	EQLIB_OBJECT void NewUIProcessEscape();
	EQLIB_OBJECT void PlaySoundAtLocation(float, float, float, int);
	EQLIB_OBJECT void ProcessCloud();
	EQLIB_OBJECT void ProcessEffects();
	EQLIB_OBJECT void ProcessParticleEmitter(EQSwitch*);
	EQLIB_OBJECT void ProcessSky();
	EQLIB_OBJECT void ProcessSwitches();
	EQLIB_OBJECT void ProcessWeather();
	EQLIB_OBJECT void RealRender_World();
	EQLIB_OBJECT void ReloadUI(bool);
	EQLIB_OBJECT void Render_MinWorld();
	EQLIB_OBJECT void Render_World();
	EQLIB_OBJECT void ResetRenderWindow();
	EQLIB_OBJECT void SetActorScaleFactor(CActorInterface*, float, unsigned char);
	EQLIB_OBJECT void SetActorSpriteTint(EQRGB*, CActorInterface*);
	EQLIB_OBJECT void SetActorUserData(CActorInterface*, void*);
	EQLIB_OBJECT void SetActorYon(float);
	EQLIB_OBJECT void SetAmbientLight(float);
	EQLIB_OBJECT void SetCCreateCamera(int);
	EQLIB_OBJECT void SetDayPeriod(unsigned char);
	EQLIB_OBJECT void SetFog(bool, float, float, unsigned char, unsigned char, unsigned char);
	EQLIB_OBJECT void SetGammaCorrection(float);
	EQLIB_OBJECT void SetGenericEnvironment();
	EQLIB_OBJECT void SetPCloudDensity(int);
	EQLIB_OBJECT void SetSkyBackground();
	EQLIB_OBJECT void SetSkyLayer(int);
	EQLIB_OBJECT void SetSpecialEnvironment(EnvironmentType);
	EQLIB_OBJECT void SetSunLight();
	EQLIB_OBJECT void SetupEmitterEnvironment();
	EQLIB_OBJECT void SetupEQPlayers();
	EQLIB_OBJECT void SetViewActor(CActorInterface*);
	EQLIB_OBJECT void SetRenderWindow(int mode);
	EQLIB_OBJECT void ToggleScreenshotMode();
	EQLIB_OBJECT void SetViewActorByName(char*);
	EQLIB_OBJECT void SetViewAngle(int);
	EQLIB_OBJECT void SetYon(float);
	EQLIB_OBJECT void ShowDisplay();
	EQLIB_OBJECT void StartWeather(int, unsigned char);
	EQLIB_OBJECT void StartWorldDisplay(EQZoneIndex);
	EQLIB_OBJECT void StartWorldDisplay_Bailout(const char*);
	EQLIB_OBJECT void StopWeather(int, unsigned char);
	EQLIB_OBJECT void StopWorldDisplay();
	EQLIB_OBJECT void SwitchToDefaultCameraMode();
	EQLIB_OBJECT void ToggleCharacterNameSprites(bool);
	EQLIB_OBJECT void ToggleNpcNameSprites(bool);
	EQLIB_OBJECT void ToggleView();
	EQLIB_OBJECT void UpdateCameraAfterModeSwitch();
	EQLIB_OBJECT void updateGrassObjects();
	EQLIB_OBJECT void UpdateMobileEmitterLocations();
	EQLIB_OBJECT void FreeAllItemLists();

	// private
	EQLIB_OBJECT void CleanCharSelectUI();
	EQLIB_OBJECT void CleanGameUI();
	EQLIB_OBJECT void CleanUpNewUI();
	EQLIB_OBJECT void InitGameUI();
	EQLIB_OBJECT void InitNewUI();
};

class CDistillerInfo
{
public:
	static EQLIB_OBJECT CDistillerInfo &Instance();
	EQLIB_OBJECT int GetIDFromRecordNum(int ID, bool bWhat);
};

class UniversalChatProxy
{
public:
	EQLIB_OBJECT char* GetChannelName(int channelNumber);
};

struct [[offsetcomments]] TARGETRING
{
	FORCE_SYMBOLS;

/*0x00*/ DWORD         Gem;                      // the gem the spell below is memmed in... 0-11
/*0x04*/ PSPELL        thespell;
/*0x08*/ ItemGlobalIndex ItemLoc;
/*0x14*/ ItemSpellTypes SpellType;
/*0x18*/ float         SquaredRange;
/*0x1c*/ bool          bCursorVisible;
/*0x20*/
};
using PTARGETRING = TARGETRING*;

struct [[offsetcomments]] EQSuccessfulHit
{
/*0x00*/ uint16_t      DamagedID;                // Spawn that was hit
/*0x02*/ uint16_t      AttackerID;               // spawn who did the hit
/*0x04*/ uint8_t       Skill;                    // 1 HS etc...
/*0x05*/ uint8_t       Filler0x5[0x3];
/*0x08*/ int           SpellID;
/*0x0c*/ int           DamageCaused;
/*0x10*/ float         Force;
/*0x14*/ float         HitHeading;
/*0x18*/ float         HitPitch;
/*0x1c*/ bool          bSecondary;
/*0x1d*/ uint8_t       Filler0x1d[0x3];
/*0x20*/ int           SpecialCase;              // origin of damage? need to investigate further
/*0x24*/
};
using pEQSuccessfulHit = EQSuccessfulHit*;

struct LfgGroupStatus;
struct LfgGroupQuery;
struct LfgPlayerStatus;
struct LfgPlayerQuery;
struct connection_t;

class CEverQuest
{
public:
	EQLIB_OBJECT ~CEverQuest();
	EQLIB_OBJECT CEverQuest(HWND);
	EQLIB_OBJECT void CreateTargetIndicator(int Slot, PSPELL pSpell, const ItemGlobalIndex& ItemLoc, ItemSpellTypes spelltype);
	EQLIB_OBJECT int DeleteTargetIndicator();
	EQLIB_OBJECT bool IsInTypingMode();
	EQLIB_OBJECT bool IsOkToTransact();
	EQLIB_OBJECT bool ReadClientINIBool(char*, char*, bool);
	EQLIB_OBJECT bool ReadUIINIBool(char*, char*, bool);
	EQLIB_OBJECT char* GetBodyTypeDesc(int);
	EQLIB_OBJECT const char* GetClassDesc(int);
	EQLIB_OBJECT char* GetClassThreeLetterCode(int);
	EQLIB_OBJECT char* GetDeityDesc(int);
	EQLIB_OBJECT char* GetInnateDesc(int);
	EQLIB_OBJECT char* GetItemClassDesc(int);
	EQLIB_OBJECT char* GetLangDesc(int);
	EQLIB_OBJECT const char* GetRaceDesc(int);
	EQLIB_OBJECT char* GetSingleMessage(uint32_t, int, int*, char*);
	EQLIB_OBJECT char* GrabFirstWord(char*, char*);
	EQLIB_OBJECT char* GrabFirstWord2(char*, char*, int);
	EQLIB_OBJECT char* ReadClientINIString(char*, char*, char*, char*, int);
	EQLIB_OBJECT char* ReadUIINIString(char*, char*, char*, char*, int);
	EQLIB_OBJECT char* stripName(char*);
	EQLIB_OBJECT char* StripShipName(char*, char*);
	EQLIB_OBJECT char* trimName(char*);
	EQLIB_OBJECT PlayerClient* ClickedPlayer(int, int);
	EQLIB_OBJECT EQSwitch* ClickedSwitch(int, int);
	EQLIB_OBJECT ZONE_REQ_STATUS IsZoneAvailable(char*, EQZoneIndex, ZONE_REQ_REASON);
	EQLIB_OBJECT float GetMaxLightRadius();
	EQLIB_OBJECT float ReadClientINIFloat(char*, char*, float);
	EQLIB_OBJECT int BeingIgnored(char*);
	EQLIB_OBJECT int DoLogin(HWND, HINSTANCE);
	EQLIB_OBJECT int GetCombatSound(PlayerClient*, PlayerClient*);
	EQLIB_OBJECT int GetCurrentLanguage() const;
	EQLIB_OBJECT int HandleItems(void*, int);
	EQLIB_OBJECT int IsFriend(const char*);
	EQLIB_OBJECT int IsValidName(char*);
	EQLIB_OBJECT int LootCorpse(PlayerClient*, int);
	EQLIB_OBJECT int MoveMoney(int, int, int, int, int, bool);
	EQLIB_OBJECT int msgStartIcon(void*);
	EQLIB_OBJECT int msgStartIeq(void*);
	EQLIB_OBJECT int msgStartInotes(void*);
	EQLIB_OBJECT int ProcessMBox();
	EQLIB_OBJECT int ReadClientINIInt(char*, char*, int);
	EQLIB_OBJECT int ReadUIINIInt(char*, char*, int);
	EQLIB_OBJECT int TypingMode();
	EQLIB_OBJECT unsigned char HandleWorldMessage(connection_t*, uint32_t, char*, uint32_t);
	EQLIB_OBJECT unsigned char IFoundMyVehicle();
	EQLIB_OBJECT void DoLoadScreenProgressBar(int, const char*, ...);
	EQLIB_OBJECT void ApplyPoison(unsigned long);
	EQLIB_OBJECT void Camp();
	EQLIB_OBJECT void CancelSneakHide();
	EQLIB_OBJECT void ChatServerConnect(char*, int, char*, char*);
	EQLIB_OBJECT void ChatServerDisconnect();
	EQLIB_OBJECT void ChatServerGiveTime();
	EQLIB_OBJECT void ChatServerMessage(char*);
	EQLIB_OBJECT void ChatServerNotificationAdd(bool, char*, char*, int);
	EQLIB_OBJECT void ChatServerNotificationFlush();
	EQLIB_OBJECT void CleanupBadFiles();
	EQLIB_OBJECT void clr_chat_input();
	EQLIB_OBJECT void Consider(PlayerClient*, void*);
	EQLIB_OBJECT void CopyFirstWord(char*, char*);
	EQLIB_OBJECT void CreateDataSubdirectories();
	EQLIB_OBJECT void CreateFilenameServerCode(char*);
	EQLIB_OBJECT void CreateIniFilenames();
	EQLIB_OBJECT void CreateInitialActors();
	EQLIB_OBJECT void DeacSpellScreen();
	EQLIB_OBJECT void Disband();
	EQLIB_OBJECT void DisplayScreen(char*);
	EQLIB_OBJECT void DoCharacterSelection();
	EQLIB_OBJECT void doInspect(PlayerClient*);
	EQLIB_OBJECT void doInvite(uint32_t, char*);
	EQLIB_OBJECT void DoLoadScreen(int);
	EQLIB_OBJECT void doLoot();
	EQLIB_OBJECT void DoMainLoop(HWND);
	EQLIB_OBJECT void DoNewCharacterCreation();
	EQLIB_OBJECT void DoPercentConvert(char*line, bool bOutGoing);
	EQLIB_OBJECT void DoSplit(char*);
	EQLIB_OBJECT void DoTellWindow(char*, char*, char*, void*, int, bool);
	EQLIB_OBJECT void OutputTextToLog(const char*Text);
	EQLIB_OBJECT void doUnInvite(char*);
	EQLIB_OBJECT void DropHeldItemOnGround(int);
	EQLIB_OBJECT void DropHeldMoneyOnGround(int);
	EQLIB_OBJECT void DropItemOrMoneyOnPlayer(PlayerClient*);
	EQLIB_OBJECT void dsp_chat(const char*);
	EQLIB_OBJECT void dsp_chat(const char* line, int color = 273, bool bLogIsOk = true, bool bConvertPercent = true, char* SomeStr = NULL);
	EQLIB_OBJECT void dsp_chat(const char*, int, bool);
	EQLIB_OBJECT void Emote();
	EQLIB_OBJECT void EnterZone(HWND);
	EQLIB_OBJECT int Follow(int);
	EQLIB_OBJECT void FreeSwitches();
	EQLIB_OBJECT void GetSndDriver();
	EQLIB_OBJECT void GetZoneInfoFromNetwork(char*);
	EQLIB_OBJECT void GuildDelete();
	EQLIB_OBJECT void GuildInvite(char*, char*);
	EQLIB_OBJECT void GuildLeader(char*);
	EQLIB_OBJECT void GuildPeace(char*);
	EQLIB_OBJECT void GuildRemove(char*);
	EQLIB_OBJECT void GuildSay(char*);
	EQLIB_OBJECT void GuildStatus(char*);
	EQLIB_OBJECT void GuildWar(char*, int);
	EQLIB_OBJECT void InitCommands();
	EQLIB_OBJECT void initCustom();
	EQLIB_OBJECT void InterpretCmd(PlayerClient*, char*);
	EQLIB_OBJECT void Invite(int);
	EQLIB_OBJECT void InviteOk(char*);
	EQLIB_OBJECT void IssueLfgGroupQuery(LfgGroupQuery*);
	EQLIB_OBJECT void IssueLfgPlayerQuery(LfgPlayerQuery*);
	EQLIB_OBJECT void IssuePetCommand(ePetCommandType, int TargetID, bool bQuiet, bool bsomethingelse = 1);
	EQLIB_OBJECT void Kill(char*, char*);
	EQLIB_OBJECT void LeaveBankMode(bool);
	EQLIB_OBJECT void LeaveGuildMaster();
	EQLIB_OBJECT void LeftClickedOnPlayer(PlayerClient*);
	EQLIB_OBJECT void LMouseDown(int, int);
	EQLIB_OBJECT void LMouseUp(int, int);
	EQLIB_OBJECT void loadCustom();
	EQLIB_OBJECT void loadCustomFromINI(char*);
	EQLIB_OBJECT void loadOptions();
	EQLIB_OBJECT void loadSoundsGame();
	EQLIB_OBJECT void LoadStringTables();
	EQLIB_OBJECT void LoadSwitchesNonAvatar(EQZoneIndex);
	EQLIB_OBJECT void LocalDeath(EQPlayerDeath*, unsigned char);
	EQLIB_OBJECT void MouseWheelScrolled(int);
	EQLIB_OBJECT void MoveToZone(int, char*, int, int, float, float, float, int);
	EQLIB_OBJECT void MoveToZone(char*, char*, int, ZONE_REQ_REASON);
	EQLIB_OBJECT void MoveToZone(EQZoneIndex, char*, int, ZONE_REQ_REASON);
	EQLIB_OBJECT void PrepareLocalPCForRepop();
	EQLIB_OBJECT void ProcessControls();
	EQLIB_OBJECT void ProcessGame(HWND, HINSTANCE);
	EQLIB_OBJECT void ProcessLocalPCIni(int);
	EQLIB_OBJECT void procMouse(int);
	EQLIB_OBJECT void RemoveCharacterOptionFile(char*);
	EQLIB_OBJECT void ReportDeath(EQPlayerDeath*);
	EQLIB_OBJECT void ReportSuccessfulHit(EQSuccessfulHit*pHit, unsigned char bOutputText, int ActualHeal);
	EQLIB_OBJECT void reqChannel();
	EQLIB_OBJECT void ResetVisionRGBs();
	EQLIB_OBJECT void RightClickedOnPlayer(PlayerClient*, int);
	EQLIB_OBJECT void RMouseDown(int, int);
	EQLIB_OBJECT void RMouseUp(int, int);
	EQLIB_OBJECT void SaveCamerasToINI();
	EQLIB_OBJECT void saveCustom();
	EQLIB_OBJECT void saveOptions();
	EQLIB_OBJECT void saveOptions2();
	EQLIB_OBJECT void SavePC(int, int, unsigned char);
	EQLIB_OBJECT void SavePCForce(int);
	EQLIB_OBJECT void send_auction();
	EQLIB_OBJECT void send_broadcast();
	EQLIB_OBJECT void send_chat();
	EQLIB_OBJECT void send_gsay();
	EQLIB_OBJECT void send_ooc();
	EQLIB_OBJECT void send_petition();
	EQLIB_OBJECT void send_private();
	EQLIB_OBJECT void send_shout();
	EQLIB_OBJECT void send_social(int, char*, char*);
	EQLIB_OBJECT void send_tell(char*, char*);
	EQLIB_OBJECT void send_update_filters();
	EQLIB_OBJECT void SendLightInfo(PlayerClient*, unsigned char);
	EQLIB_OBJECT void SendNewText(int, char*, char*);
	EQLIB_OBJECT void SetDefaultDamageDescByRace(char*, int, unsigned char);
	EQLIB_OBJECT void SetDefaultGameValues();
	EQLIB_OBJECT void SetGameState(int);
	EQLIB_OBJECT void SetLfgGroupStatus(LfgGroupStatus*);
	EQLIB_OBJECT void SetLfgPlayerStatus(LfgPlayerStatus*);
	EQLIB_OBJECT void SetPlayerAppearanceFromPInfo(PlayerClient*, int, bool);
	EQLIB_OBJECT void SetTimedFog(int);
	EQLIB_OBJECT void SetupCharSelectCamera();
	EQLIB_OBJECT void Sit();
	EQLIB_OBJECT void SortSpellLoadouts();
	EQLIB_OBJECT void StartCasting(void*);
	EQLIB_OBJECT void StartNetworkGame(HWND, HINSTANCE, char*);
	EQLIB_OBJECT void Surname(char*);
	EQLIB_OBJECT void ToggleAutoSplit();
	EQLIB_OBJECT void UpdateMyAppearance();
	EQLIB_OBJECT void UseCharge(unsigned long);
	EQLIB_OBJECT void WhatTimeIsIt();
	EQLIB_OBJECT void Who(char*);
	EQLIB_OBJECT void WriteBoolToClientINI(bool, char*, char*);
	EQLIB_OBJECT void WriteBoolToUIINI(bool, char*, char*);
	EQLIB_OBJECT void WriteFloatToClientINI(float, char*, char*);
	EQLIB_OBJECT void WriteIntToClientINI(int, char*, char*);
	EQLIB_OBJECT void WriteIntToUIINI(int, char*, char*);
	EQLIB_OBJECT void WriteStringToClientINI(char*, char*, char*);
	EQLIB_OBJECT void WriteStringToUIINI(char*, char*, char*);

	// virtual
	EQLIB_OBJECT void CshOnBuddyStatusChange(char*, int BuddyStatus);
	EQLIB_OBJECT void CshOnChannelListChange();
	EQLIB_OBJECT void CshOnMessage(char*, char*, int, char*, bool);
	EQLIB_OBJECT void CshOnPlayerEntering(char*, int, char*);
	EQLIB_OBJECT void CshOnPlayerLeaving(char*, int, char*);
};

class CUnSerializeBuffer
{
public:
	const char*        m_pBuffer;
	uint32_t           m_uLength;
	uint32_t           m_uReadOffset;

	void Reset() { m_uReadOffset = 0; }

	template<typename T>
	void Read(T& r)
	{
		r = *(T*)(m_pBuffer + m_uReadOffset);
		m_uReadOffset += sizeof(T);
	}

	void ReadString(std::string& out)
	{
		int len = 0;
		while (m_pBuffer[m_uReadOffset] != '\0')
		{
			out.append(1, (char)(m_pBuffer[m_uReadOffset]));
			m_uReadOffset++;
		}

		m_uReadOffset++;
	}

	template <typename T>
	void Read(T* r, size_t size)
	{
		size_t savedSize;
		Read(savedSize);

		for (size_t i = 0; i < savedSize && i < size; i++)
		{
			Read(r[i]);
		}
	}

	template <unsigned int _Size>
	void ReadpChar(char(&_Buffer)[_Size])
	{
		_Buffer[0] = '\0';
		int len = 0;

		while(m_pBuffer[m_uReadOffset] != '\0' && len < _Size)
		{
			_Buffer[len++] = (char)(m_pBuffer[m_uReadOffset]);
			m_uReadOffset++;
		}

		// take null term into account...
		m_uReadOffset++;
	}
};

struct guildmotdSet;
struct connection_t;
struct GuildMember;

class CGuild
{
public:
	EQLIB_OBJECT CGuild();
	EQLIB_OBJECT bool ValidGuildName(int);
	EQLIB_OBJECT char* GetGuildMotd();
	EQLIB_OBJECT char* GetGuildMotdAuthor();
	EQLIB_OBJECT const char* GetGuildName(int64_t);
	EQLIB_OBJECT int64_t GetGuildIndex(char*);
	EQLIB_OBJECT GuildMember* FindMemberByName(const char*);
	EQLIB_OBJECT void DeleteAllMembers();
	EQLIB_OBJECT void DemoteMember(GuildMember*);
	EQLIB_OBJECT void HandleGuildMessage(connection_t*, uint32_t, char*, uint32_t);
	EQLIB_OBJECT void SendPublicCommentChange(char*, char*);
	EQLIB_OBJECT void SetGuildMotd(guildmotdSet*);

	// virtual
	EQLIB_OBJECT ~CGuild();

	// private
	EQLIB_OBJECT void AddGuildMember(GuildMember*);
	EQLIB_OBJECT void ChangeGuildMemberName(char*);
	EQLIB_OBJECT void HandleAddGuildMember(char*, int);
	EQLIB_OBJECT void HandleDeleteGuildResponse(char*);
	EQLIB_OBJECT void HandleGuildInvite(connection_t*, uint32_t, char*, uint32_t);
	EQLIB_OBJECT void HandleMemberLevelUpdate(char*);
	EQLIB_OBJECT void HandleRemoveGuildMember(char*, int);
	EQLIB_OBJECT void InitializeFromDump(char*);
	EQLIB_OBJECT void UpdateGuildMemberOnWindow(GuildMember*);
	EQLIB_OBJECT void UpdateMemberStatus(char*);
	EQLIB_OBJECT void UpdatePublicComment(char*);
};

class CWndDisplayManager
{
public:
	ArrayClass2_RO<CXWnd*>   pWindows;
	ArrayClass2_RO<long>     pTimes;
	int                      MaxWindows;

	EQLIB_OBJECT CWndDisplayManager();
	EQLIB_OBJECT ~CWndDisplayManager();

	EQLIB_OBJECT int FindWindow(bool bNewWnd);
	EQLIB_OBJECT bool CloseNewest();
	EQLIB_OBJECT void CloseAll();

	EQLIB_OBJECT virtual int CreateWindowInstance();
};

class CItemDisplayManager : public CWndDisplayManager
{
public:
	EQLIB_OBJECT virtual int CreateWindowInstance() override;
};

class JournalCategory;

class ConversationJournal
{
public:
	EQLIB_OBJECT ~ConversationJournal();
	EQLIB_OBJECT ConversationJournal();
	EQLIB_OBJECT JournalNPC* FindNPCByNameZone(char*, int);
	EQLIB_OBJECT JournalNPC* GetNPC(int);
	EQLIB_OBJECT int AddEntry(char*, int, long, float, float, float, char*, int);
	EQLIB_OBJECT int DeleteNPC(char*, int);
	EQLIB_OBJECT int Load(char*);
	EQLIB_OBJECT int Save(char*);
	EQLIB_OBJECT JournalCategory** GetCategoryList();
	EQLIB_OBJECT JournalCategory* AddCategory(char*, char*, int);
	EQLIB_OBJECT JournalCategory* AddCategory(int);
	EQLIB_OBJECT JournalCategory* GetCategory(char*);
	EQLIB_OBJECT JournalCategory* GetCategory(int);
	EQLIB_OBJECT void Clean();
	EQLIB_OBJECT void DeleteCategory(int);

	// protected
	EQLIB_OBJECT int FindFreeID();

	// private
	EQLIB_OBJECT JournalNPC* AddNPC(char*, int);
	EQLIB_OBJECT JournalNPC* ReadNPC(FILE*);
	EQLIB_OBJECT void AllocateCatArray();
	EQLIB_OBJECT void AllocateNPCArray();
	EQLIB_OBJECT void ReadCategory(FILE*);
};



struct RaidAddMember;
struct SCRaidMessage;
struct CreateRaidMessage;
struct RenameRaidMember;
struct RaidMember;

class CRaid
{
public:
	EQLIB_OBJECT bool IsInRaid();
	EQLIB_OBJECT bool IsInvited();
	EQLIB_OBJECT bool IsRaidGroupLeader();
	EQLIB_OBJECT bool IsRaidLeader();
	EQLIB_OBJECT bool IsRaidMember(char*);
	EQLIB_OBJECT int GetLootType();
	EQLIB_OBJECT int GetNumRaidMembers();
	EQLIB_OBJECT RaidMember* GetRaidMemberAt(int);
	EQLIB_OBJECT void AddRaidLooter();
	EQLIB_OBJECT void ClearInvitedState();
	EQLIB_OBJECT void CreateInviteRaid();
	EQLIB_OBJECT void HandleC2SRaidMessage(char*);
	EQLIB_OBJECT void HandleCreateInviteRaid(SCRaidMessage*);
	EQLIB_OBJECT void HandleS2CRaidMessage(char*);
	EQLIB_OBJECT void RemoveRaidLooter();
	EQLIB_OBJECT void RemoveRaidMember();
	EQLIB_OBJECT void ResetRaid();
	EQLIB_OBJECT void ResetWindow();
	EQLIB_OBJECT void SendInviteResponse(bool);
	EQLIB_OBJECT void SendLeadershipChange(char*);
	EQLIB_OBJECT void SendRaidChat(char*);
	EQLIB_OBJECT void SetLootType(char*);
	EQLIB_OBJECT void SetRaidLeader(char*);
	EQLIB_OBJECT void SetTargetRaidPlayer(char*);
	EQLIB_OBJECT void UpdateClassColor(int, unsigned long);
	EQLIB_OBJECT void UpdateOptionsWindow();

	// private
	EQLIB_OBJECT bool IsRaidLooter(char*);
	EQLIB_OBJECT int FindOpenIndex();
	EQLIB_OBJECT int FindPlayerIndex(char*);
	EQLIB_OBJECT int FindRaidGroupLeader(int);
	EQLIB_OBJECT void AddRaidMember(RaidAddMember*);
	EQLIB_OBJECT void ChangeLeadership(char*);
	EQLIB_OBJECT void DeleteRaidMember(SCRaidMessage*);
	EQLIB_OBJECT void DetermineRaidChanges(char*);
	EQLIB_OBJECT void HandleAddLooter(char*);
	EQLIB_OBJECT void HandlePositionChange(SCRaidMessage*);
	EQLIB_OBJECT void HandleRemoveLooter(char*);
	EQLIB_OBJECT void HandleSetLootType(int);
	EQLIB_OBJECT void InitializeRaid(char*);
	EQLIB_OBJECT void RaidCreated(CreateRaidMessage*);
	EQLIB_OBJECT void RaidGroupLeaderChange(SCRaidMessage*);
	EQLIB_OBJECT void RenameMember(RenameRaidMember*);
	EQLIB_OBJECT void SendRaidMsg(int, char*, char*, int);
	EQLIB_OBJECT void SetLootTypeResponse(SCRaidMessage*);
	EQLIB_OBJECT void UpdateLevelAverage();
};

struct ResolutionUpdateData
{
	int                Width;
	int                Height;
	int                BitsPerPixel;
	int                RefreshRate;
	bool               bFullscreen;

	void Set(int width, int height, int bitsPerPixel, int refreshRate, bool bfullscreen = false)
	{
		Width = width;
		Height = height;
		BitsPerPixel = bitsPerPixel;
		RefreshRate = refreshRate;
		bFullscreen = bfullscreen;
	}
};

struct SDeviceInfo
{
	char Name[0x80];
};

class CResolutionHandlerBase
{
public:
	EQLIB_OBJECT static bool IsFullscreenAvailable();
	EQLIB_OBJECT static int GetDesktopBitsPerPixel();
	EQLIB_OBJECT static int GetDesktopHeight();
	EQLIB_OBJECT static int GetDesktopRefreshRate();
	EQLIB_OBJECT static int GetDesktopWidth();
	EQLIB_OBJECT static int GetHeight();
	EQLIB_OBJECT static int GetWidth();
	EQLIB_OBJECT static int Init();
	EQLIB_OBJECT static void ChangeToResolution(int, int, int, int, int);
	EQLIB_OBJECT static void SaveSettings();
	EQLIB_OBJECT static void Shutdown();
	EQLIB_OBJECT static void ToggleScreenMode();
	EQLIB_OBJECT static void UpdateWindowPosition();

	DWORD              vfTable;
	bool               bIsFullscreen;
	int                FullscreenBitsPerPixel;
	int                FullscreenRefreshRate;
	int                FullscreenWidth;
	int                FullscreenHeight;
	int                WindowedWidth;
	int                WindowedHeight;
	int                WindowOffsetX;
	int                WindowOffsetY;
	int                RestoredWidth;
	int                RestoredHeight;
	int                RestoredOffsetX;
	int                RestoredOffsetY;
	SDeviceInfo        DeviceTable[0x10];
	int                DeviceCount;
	long               DeviceIndex;
	bool               bUseD3DTextureCompression;
	bool               bResizable;
	bool               bMaximized;
	bool               bAlwaysOnTop;
	bool               bActive;
	UINT               ActiveThreadID;
	HWND               ActiveWnd;
	bool               bChangingScreenResolutions;
};

class CResolutionHandler : public CResolutionHandlerBase
{
public:
	EQLIB_OBJECT void UpdateResolution(ResolutionUpdateData& data);
	EQLIB_OBJECT DWORD GetWindowedStyle() const;
};


class CTargetManager
{
public:
	EQLIB_OBJECT static CTargetManager* Get();
	EQLIB_OBJECT void Update();
};

class [[offsetcomments]] CTargetRing
{
public:
	EQLIB_OBJECT int Cast(const CVector3& pos);

/*0x00*/ DWORD         Gem;           // the gem the spell below is memmed in... 0-11
/*0x04*/ PSPELL        thespell;
/*0x08*/ ItemGlobalIndex ItemLoc;
/*0x14*/ ItemSpellTypes SpellType;
/*0x18*/ float         SquaredRange;
/*0x1c*/ bool          bCursorVisible;
/*0x20*/
};

enum TaskType
{
	cTaskTypeUnknown = -1,
	cTaskTypeNone = 0,
	cTaskTypeDeliver,
	cTaskTypeKill,
	cTaskTypeLoot,
	cTaskTypeHail,
	cTaskTypeExplore,
	cTaskTypeTradeskill,
	cTaskTypeFishing,
	cTaskTypeForaging,
	cTaskTypeCast,
	cTaskTypeUseSkill,
	cTaskTypeDZSwitch,
	cTaskTypeDestroyObject,
	cTaskTypeCollect,
	cTaskTypeDialogue,

	cTaskTypeCount,
};

enum TaskGroupType
{
	cTaskGroupTypeSolo,
	cTaskGroupTypeGroup,
	cTaskGroupTypeRaid,
};

enum TaskSystemType
{
	cTaskSystemTypeTask,
	cTaskSystemTypeSharedQuest,
	cTaskSystemTypeSoloQuest
};

struct [[offsetcomments]] CTaskElement
{
/*0x000*/ TaskType           Type;
/*0x004*/ char               TargetName[0x40];
/*0x044*/ char               ZoneID[0x40];
/*0x084*/ char               TargetZoneID[0x40];
/*0x0c4*/ int                RequiredCount;
/*0x0c8*/ bool               bOptional;
/*0x0cc*/ int                ElementGroup;
/*0x0d0*/ int                DZSwitchID;
/*0x0d4*/ char               ElementDescriptionOverride[0x80];
/*0x154*/ CXStr              ItemNameList;
/*0x158*/ CXStr              SkillIDList;
/*0x15c*/ CXStr              SpellIDList;
/*0x160*/ CXStr              TaskTitle;
/*0x164*/
};

const int MAX_TASK_ELEMENTS = 20;

struct [[offsetcomments]] CTaskEntry
{
/*0x0000*/ int               TaskID;
/*0x0004*/ float             RewardAdjustment;
/*0x0008*/ char              TaskTitle[0x40];
/*0x0048*/ int               DurationSeconds;
/*0x004c*/ char              StartText[0xFa0];
/*0x0fec*/ bool              bShowReward;
/*0x0ff0*/ int               RewardCash;
/*0x0ff4*/ int               RewardExp;
/*0x0ff8*/ int               RewardPoints;
/*0x0ffc*/ int               RewardFactionID;
/*0x1000*/ int               RewardFactionAmount;
/*0x1004*/ CXStr             RewardItemTag;
/*0x1008*/ CTaskElement      Elements[MAX_TASK_ELEMENTS];
/*0x2bd8*/ int               TaskSystem;
/*0x2bdc*/ int               PointType;
/*0x2be0*/ bool              StartTextCompiled;
/*0x2be1*/ char              RawStartText[0xFa0];
/*0x3b81*/ bool              bElementsReceived;
/*0x3b84*/ time_t            TimeCompleted;
/*0x3b88*/ ArrayClass<MonsterMissionTemplate> MonsterTemplates;
/*0x3b98*/ bool              bTemplateSelectionLocked;
/*0x3b99*/ bool              bHasRewardSet;
/*0x3b9c*/ int               Unknown1;
/*0x3ba0*/ int               Unknown2;
/*0x3ba4*/ int               Unknown3;
/*0x3ba8*/ int               Unknown4;
/*0x3bac*/
};

enum SharedTaskPlayerRole
{
	STPR_None,
	STPR_Leader
};

struct SharedTaskClientPlayerInfo
{
	char                               Name[0x40];
	int                                TemplateID;
	SharedTaskPlayerRole               m_role;
	SharedTaskClientPlayerInfo*        pNext;
};

constexpr int MAX_TASK_ENTRIES = 1;
constexpr int MAX_QUEST_ENTRIES = 29;
constexpr int MAX_UNKNOWN_ENTRIES = 12; // 29 + 12 = 41
constexpr int MAX_SHARED_TASK_ENTRIES = 1;
constexpr int MAX_QUEST_HISTORY_ENTRIES = 50;

class [[offsetcomments]] CTaskManager : public PopDialogHandler
{
public:
/*0x000004*/ CTaskEntry                TaskEntries[MAX_TASK_ENTRIES];
/*0x003bb0*/ CTaskEntry                QuestEntries[MAX_QUEST_ENTRIES];
/*0x06fe2c*/ CTaskEntry                SharedTaskEntries[MAX_SHARED_TASK_ENTRIES];
/*0x0739d8*/ CTaskEntry                UnkTaskEntries[MAX_UNKNOWN_ENTRIES];
/*0x0a05e8*/ CTaskEntry                QuestHistoryEntries[MAX_QUEST_HISTORY_ENTRIES];
/*0x15ad80*/ int                       AddPlayerID;
/*0x15ad84*/ bool                      bAddPlayerIsSwap;
/*0x15ad85*/ char                      AddPlayerSwapeeName[0x40];
/*0x15adc8*/ SharedTaskClientPlayerInfo* pFirstMember;
/*0x15adcc*/

	EQLIB_OBJECT CTaskManager(CXWnd*);

	// virtual
	EQLIB_OBJECT ~CTaskManager();
	EQLIB_OBJECT CTaskEntry* GetEntry(int Index, int System, bool bCheckEmpty = true);
	EQLIB_OBJECT PCTaskStatus* GetTaskStatus(PcClient* pMe, int Index, TaskSystemType System);
	EQLIB_OBJECT void GetElementDescription(const CTaskElement* pElement, char* Out);
};

class [[offsetcomments]] CXMLData
{
public:
	EQLIB_OBJECT CXMLData();
	EQLIB_OBJECT CXMLData& operator=(const CXMLData&);

	// virtual
	EQLIB_OBJECT ~CXMLData();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);

/*0x00*/ void*         pvfTable;
/*0x04*/ DWORD         Unknown0x04;             // always 8
/*0x08*/ UIType        Type;
/*0x0c*/ DWORD         Unknown0x0C;             // no idea yet, some number but not unique
/*0x10*/ DWORD         Unknown0x10;             // always -1
/*0x14*/ CXStr         TypeName;                // "Screen" (control type)
/*0x18*/ CXStr         Name;                    // "ChatWindow"  control name (used only for Screen)
/*0x1c*/ DWORD         Unknown0x1C;             // always null
/*0x20*/ CXStr         ScreenID;                // ScreenID (used only within Screen)
/*0x24*/
};

class CXMLDataClass
{
public:
	EQLIB_OBJECT ~CXMLDataClass();
	EQLIB_OBJECT CXMLDataClass();
	EQLIB_OBJECT int GetNumLeaf();
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&, CXMLDataManager&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CXMLDataPtr
{
public:
	EQLIB_OBJECT CXMLDataPtr();
	EQLIB_OBJECT CXMLDataPtr& operator=(const CXMLDataPtr&);
	EQLIB_OBJECT void SetNewPtr(CXMLData*);

	// virtual
	EQLIB_OBJECT ~CXMLDataPtr();

	// protected
	EQLIB_OBJECT CXMLData* AllocPtr(CXMLDataPtr&, int, const CXMLData*);
	EQLIB_OBJECT void Free();
};

class CXMLEnumInfo
{
public:
	CXStr enumTypeName;
	ArrayClass2<CXStr> enumValue;

	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CXMLSOMAttribute
{
public:
	CXStr name;
	CXStr value;
};

class CXMLSOMAttributeType
{
public:
	CXStr attributeName;
	CXStr typeRef;
	CXStr typeNameC;
	CXStr fieldNameC;
	CXStr streamNameC;
};

class CXMLSOMDocumentBase
{
public:
	EQLIB_OBJECT bool CursorFieldFind(const CXStr&);
	EQLIB_OBJECT bool CursorFind(const CXStr&);
	EQLIB_OBJECT bool CursorNextInOrder();
	EQLIB_OBJECT bool CursorNextSibling();
	EQLIB_OBJECT bool CursorPop();
	EQLIB_OBJECT bool CursorPush();
	EQLIB_OBJECT bool FieldParseClassItem(const CXStr&, CXStr&, CXStr&);
	EQLIB_OBJECT bool FieldParseItemOfClass(const CXStr&, const CXStr&, int32_t&, int32_t&);
	EQLIB_OBJECT bool GetAttrValueInt(const CXStr&, int32_t &);
	EQLIB_OBJECT bool GetAttrValueStr(const CXStr&, CXStr&);
	EQLIB_OBJECT bool GetValue(const CXStr&, int32_t &);
	EQLIB_OBJECT bool GetValue(const CXStr&, bool &);
	EQLIB_OBJECT bool GetValue(const CXStr&, CXStr&);
	EQLIB_OBJECT bool SetValue(const CXStr&, int32_t);
	EQLIB_OBJECT bool SetValue(const CXStr&, bool);
	EQLIB_OBJECT bool SetValue(const CXStr&, const CXStr&);
	EQLIB_OBJECT bool ValidateData();
	EQLIB_OBJECT bool ValidateSchema();
	EQLIB_OBJECT bool XMLMerge(CXMLSOMDocumentBase&);
	EQLIB_OBJECT bool XMLRead(const CXStr&, const CXStr&, const CXStr&);
	EQLIB_OBJECT CXStr GetAttrValueStr(const CXStr&);
	EQLIB_OBJECT CXStr GetErrorMsg() const;
	EQLIB_OBJECT int XMLReadNoValidate(const CXStr&, const CXStr&, const CXStr&);
	EQLIB_OBJECT void CursorInit();
	EQLIB_OBJECT void CursorNewChild();
	EQLIB_OBJECT void CursorNewSibling();
	EQLIB_OBJECT void CursorSetPtr(CXMLSOMNodePtr);
	EQLIB_OBJECT void Init();
	EQLIB_OBJECT void SetErrorMsg(const CXStr&);
	EQLIB_OBJECT void SetErrorMsgAtCursor(const CXStr&);
	EQLIB_OBJECT void SetErrorMsgAtLine(const CXStr&, int, const CXStr&);

	// virtual
	EQLIB_OBJECT ~CXMLSOMDocumentBase();

	// protected
	EQLIB_OBJECT bool ValidateDataElements(CXMLSOMElementType&);
	EQLIB_OBJECT bool ValidateSchemaCategories();
	EQLIB_OBJECT bool ValidateSchemaDefinition();
	EQLIB_OBJECT bool ValidateSchemaElementType();
	EQLIB_OBJECT bool ValidateSchemaSimpleType();
	EQLIB_OBJECT bool ValidateSchemaSimpleTypeNode(CXMLSOMSimpleType&);
	EQLIB_OBJECT bool ValidateSchemaTypeRefs();
	EQLIB_OBJECT bool XMLProcessComposite(const CXStr&, const CXStr&);
};

class CXMLSOMDocument : public CXMLSOMDocumentBase
{
public:
	EQLIB_OBJECT bool FieldParseItemOfClass(CXStr, CXStr, uint32_t&);
	EQLIB_OBJECT bool GetValueObjectId(CXStr, CXStr, uint32_t&);
	EQLIB_OBJECT bool SetValueObjectId(CXStr, CXStr, uint32_t);

	// virtual
	EQLIB_OBJECT ~CXMLSOMDocument();
};


class [[offsetcomments]] CXMLSOMElement
{
public:
/*0x00*/ CXStr elementName;
/*0x04*/ CXStr typeRef;
/*0x08*/ CXStr typeRefClassName;
/*0x0c*/ CXStr typeRefItemName;
/*0x10*/ int minOccurs;
/*0x14*/ int maxOccurs;
/*0x18*/ CXStr defaultValue;
/*0x1c*/ bool internal;

/*0x1d*/ bool isArrayC;
/*0x1e*/ bool isEnumC;
/*0x20*/ CXStr typeNameC;
/*0x24*/ CXStr fieldNameC;
/*0x28*/ CXStr streamNameC;
/*0x2c*/
};

class [[offsetcomments]] CXMLSOMElementType
{
public:
	EQLIB_OBJECT int GetItemIdx(const CXStr& itemName)
	{
		for (int i = 0; i < itemList.GetLength(); ++i)
		{
			if (itemList[i] == itemName)
				return i;
		}

		return -1;
	}

/*0x00*/ CXStr typeName;
/*0x04*/ CXStr superType;
/*0x08*/ ArrayClass2<CXMLSOMAttributeType> attributeTypes;
/*0x20*/ ArrayClass2<CXMLSOMElement> elements;
/*0x38*/ ArrayClass2<CXStr> itemList;

/*0x50*/ CXStr classNameC;
/*0x54*/ CXStr baseClassNameC;

/*0x58*/ CXStr jsName;

/*0x5c*/ CXStr sourceFile;
/*0x60*/ int sourceLine;
/*0x64*/
};

enum EXMLSOMNodeType
{
	XMLSOMNode,
	XMLSOMComment,
	XMLSOMProcess,
};

class [[offsetcomments]] CXMLSOMNode
{
public:
/*0x00*/ EXMLSOMNodeType nodeType;
/*0x04*/ CXStr nodeName;
/*0x08*/ CXStr nodeValue;
/*0x0c*/ ArrayClass2<CXMLSOMAttribute> attributeList;
/*0x24*/ ArrayClass2<CXMLSOMNodePtr> nodeList;
/*0x3c*/ CXStr sourceFile;
/*0x40*/ int sourceLine;
/*0x44*/ int refCount;
/*0x48*/
};

// this is an intrusive reference counted pointer of CXMLSOMNode
class CXMLSOMNodePtr
{
public:
	CXMLSOMNode* pNode;
};

class EmitterManager
{
public:
	EQLIB_OBJECT ~EmitterManager();
	EQLIB_OBJECT EmitterManager(SoundManager*);
	EQLIB_OBJECT float GetEffectsLevel();
	EQLIB_OBJECT float GetVolumeLevel();
	EQLIB_OBJECT void Add(SoundEmitter*);
	EQLIB_OBJECT void GetListenerLocation(float*, float*, float*, float*);
	EQLIB_OBJECT void GiveTime();
	EQLIB_OBJECT void Remove(SoundEmitter*);
	EQLIB_OBJECT void SetEffectsLevel(float);
	EQLIB_OBJECT void SetVolumeLevel(float);
};

class [[offsetcomments]] EQ_Affect
{
public:
	EQLIB_OBJECT void Reset();
	EQLIB_OBJECT int GetAffectData(int) const;

/*0x00*/ BYTE          Type;
/*0x01*/ BYTE          CasterLevel;
/*0x02*/ BYTE          ChargesRemaining;
/*0x03*/ BYTE          Activatable;
/*0x04*/ float         BaseDmgMod;
/*0x08*/ int           ID;
/*0x0c*/ int           DurationTick;
/*0x10*/ int           MaxDuration;
/*0x14*/ int           Duration3;
/*0x18*/ EqGuid        CasterGuid;
/*0x20*/ int           HitCounter;
/*0x24*/ float         HitLocationY;
/*0x28*/ float         HitLocationX;
/*0x2c*/ float         HitLocationZ;
/*0x30*/ UINT          Flags;                    // twincast
/*0x34*/ SlotData      Data[NUM_SLOTDATA];
/*0x64*/ DWORD         Unknown0x64;
/*0x68*/
};

class EQ_AltAbility
{
public:
	EQLIB_OBJECT EQ_AltAbility(int);
};

class CEQItemLocation;



class EQ_CharacterData
{
public:
	EQLIB_OBJECT void EQ_CharacterDataResetAllMembers();
};

class EQ_Container
{
public:
	EQLIB_OBJECT ~EQ_Container();
	EQLIB_OBJECT EQ_Container();
	EQLIB_OBJECT unsigned char Close();
	EQLIB_OBJECT unsigned char IsOpen();
	EQLIB_OBJECT unsigned char Open();
};

class EQ_Equipment
{
public:
	EQLIB_OBJECT EQ_Equipment();
	EQLIB_OBJECT int IsInstrument();
	EQLIB_OBJECT int IsWeapon();
	EQLIB_OBJECT void SendTextRequestMsg();
};

enum KeyRingType
{
	eMount = 0,
	eIllusion = 1,
	eFamiliar = 2,
};

enum eAugFitRet
{
	AF_FITS,
	AF_RACE_MISMATCH,
	AF_CLASS_MISMATCH,
	AF_DEITY_MISMATCH,
	AF_LOC_MISMATCH,
	AF_SLOTFULL,
	AF_INVALIDSLOT,
	AF_AUG_MISMATCH,
	AF_SKIN_MISMATCH,
	AF_AUGCLASS,
	AF_ERR_DUPLICATE,
	AF_NOTRANSFER,
	AF_ITEMRANK_MISMATCH,
	AF_APPEARANCE_MISMATCH,
	AF_ERR_STACKABLE,
	AF_ERR_NOTANAUG,
	AF_ERR_NOEQUIPPEDLOC,
};

// this is really the ItemBase class
class EQ_Item
{
public:
	EQLIB_OBJECT bool IsSpecialNoDrop();
	EQLIB_OBJECT char* ValueSBuy(float, long);
	EQLIB_OBJECT char* ValueSRent();
	EQLIB_OBJECT char* ValueSSell(float, long);
	EQLIB_OBJECT int Copper();
	EQLIB_OBJECT int Gold();
	EQLIB_OBJECT int Platinum();
	EQLIB_OBJECT int Silver();
	EQLIB_OBJECT long ValueSellMerchant(float, long) const;
	EQLIB_OBJECT bool IsStackable();
	EQLIB_OBJECT char* CreateItemTagString(char*, int, bool bFlag = true); // SwiftyMUSE 11-09-2018
	EQLIB_OBJECT bool CanDrop(bool bDisplayText = false, bool bIncludeContainedItems = true, bool bAllowOverrideNoDropCheck = false, bool bCantDropIfContainingRealEstate = true) const;
	EQLIB_OBJECT int GetImageNum() const;
	EQLIB_OBJECT static VePointer<CONTENTS> CreateItemClient(BYTE**, DWORD);
	EQLIB_OBJECT int GetItemValue(bool) const;
	EQLIB_OBJECT bool IsKeyRingItem(KeyRingType type) const;
	EQLIB_OBJECT bool CanGoInBag(CONTENTS** pCont, int OutputText = 0, bool mustbefalse = false) const;
	EQLIB_OBJECT bool IsEmpty() const;
	EQLIB_OBJECT int GetMaxItemCount() const;
	EQLIB_OBJECT int GetAugmentFitBySlot(CONTENTS** Aug, int Slot, bool bCheckSlot = true, bool bCheckDup = true) const;

	ITEMINFO Data;
};

class EQ_LoadingS
{
public:
	EQLIB_OBJECT ~EQ_LoadingS();
	EQLIB_OBJECT EQ_LoadingS();
	EQLIB_OBJECT void draw();
	EQLIB_OBJECT void DrawBackground();
	EQLIB_OBJECT void SetProgressBar(int, const char*);
	EQLIB_OBJECT void WriteTextHD(char*, int, int, int);

	// virtual
	EQLIB_OBJECT void Activate();
	EQLIB_OBJECT void Deactivate();
	EQLIB_OBJECT void DefineImages();
};

class EQ_Note
{
public:
	EQLIB_OBJECT ~EQ_Note();
	EQLIB_OBJECT EQ_Note();
	EQLIB_OBJECT void SendTextRequestMsg();
};

class EQ_Skill
{
public:
	EQLIB_OBJECT EQ_Skill(int);
	EQLIB_OBJECT ~EQ_Skill();
};

class EQ_Spell
{
public:
	EQLIB_OBJECT ~EQ_Spell();
	EQLIB_OBJECT EQ_Spell(char*);
	EQLIB_OBJECT bool IsStackableDot() const;
	EQLIB_OBJECT bool IsStackable() const;
	EQLIB_OBJECT int IsPermIllusionSpell() const;
	EQLIB_OBJECT int SpellUsesDragonBreathEffect();
	EQLIB_OBJECT unsigned char SpellAffects(int) const;              // this one takes an attrib(soe calls it affect) and returns the index for it...
	EQLIB_OBJECT unsigned char GetSpellLevelNeeded(int) const;       // takes a Class, druid for example is 6
	EQLIB_OBJECT int SpellAffectBase(int) const;                     // takes a SPA, returns the first matching base it finds for it
	EQLIB_OBJECT const SPELLCALCINFO* GetSpellAffectBySlot(int Slot) const;
	EQLIB_OBJECT const SPELLCALCINFO* GetSpellAffectByIndex(int Index) const;
	EQLIB_OBJECT bool IsNoRemove() const;
	EQLIB_OBJECT static bool IsDegeneratingLevelMod(int);

	EQLIB_OBJECT static bool IsSPAStacking(int Spa);
	EQLIB_OBJECT static bool IsSPAIgnoredByStacking(int Spa);

	EQLIB_OBJECT bool IsNoDispell() const { return Data.NoDisspell; }
	EQLIB_OBJECT bool IsStackableOnAnyone() const { return SpellAffects(424) != 0; }
	EQLIB_OBJECT int GetNoOverwrite() const { return Data.NoOverwrite; }
	EQLIB_OBJECT bool IsBeneficialSpell() const { return Data.SpellType >= 1; }
	EQLIB_OBJECT bool IsDetrimentalSpell() const { return Data.SpellType == 0; }
	EQLIB_OBJECT bool IsShortEffectDuration() const { return Data.DurationWindow; }
	EQLIB_OBJECT bool GetIsSkillSpell() const { return Data.IsSkill; }
	EQLIB_OBJECT bool IsDoTSpell() const
	{
		return SpellAffects(0) || SpellAffects(20) || SpellAffects(69) || SpellAffects(114) || SpellAffects(125);
	}

	SPELL Data;
};

class EQAnimation
{
public:
	EQLIB_OBJECT EQAnimation();
	EQLIB_OBJECT ~EQAnimation();
};

class EQEffect
{
public:
	static EQEffect* top;

	EQLIB_OBJECT ~EQEffect();
	EQLIB_OBJECT EQEffect(EQEffect*, char*, int, EQLOC*, PlayerZoneClient*, EQMissile*, EQRGB*, float, int, int, float, float);
};

class EqEmitterData
{
public:
	EQLIB_OBJECT EqEmitterData();
	EQLIB_OBJECT void SetLoadString(char*);
};

class EQItemList
{
public:
	static class EQItemList* top;

	EQLIB_OBJECT ~EQItemList();
	EQLIB_OBJECT EQItemList();
	EQLIB_OBJECT EQItemList* get_item(long);
	EQLIB_OBJECT EQItemList* is_item_actor(CActorInterface*);
};

class EQMissile
{
public:
	static EQMissile* top;

	EQLIB_OBJECT ~EQMissile();
	EQLIB_OBJECT EQMissile(EQ_Equipment*, PlayerZoneClient*, EQMissile*, char*, unsigned char, unsigned int);
	EQLIB_OBJECT EQMissile* is_missile_actor(CActorInterface*);
	EQLIB_OBJECT void CleanUpMyEffects();
	EQLIB_OBJECT void HitActor(CActorInterface*, bool);
	EQLIB_OBJECT void LeaveTrail();
	EQLIB_OBJECT void MissileAI();
	EQLIB_OBJECT void ProcessMissile();
};

class EqMobileEmitter
{
public:
	EQLIB_OBJECT ~EqMobileEmitter();
	EQLIB_OBJECT EqMobileEmitter(EqSoundManager*);
	EQLIB_OBJECT void Move(float, float, float);
	EQLIB_OBJECT void SetNpcHeight(float);
	EQLIB_OBJECT void SetWave(int, char*);
};

class EQMoneyList
{
public:
	EQLIB_OBJECT EQMoneyList();
	EQLIB_OBJECT ~EQMoneyList();
	EQLIB_OBJECT EQMoneyList* get_money(long);

	static EQMoneyList* top;
};

class EQObject
{
public:
	EQLIB_OBJECT EQObject(EQObject*, PlayerZoneClient*, char*, char*);
	EQLIB_OBJECT ~EQObject();

	static EQObject* top;
};

enum ePlacementType
{
	PLACEMENT_TYPE_FLOOR,
	PLACEMENT_TYPE_WALL,
	PLACEMENT_TYPE_CEILING,
};

class [[offsetcomments]] EQPlacedItem
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ EQPlacedItem* pPrev;
/*0x08*/ EQPlacedItem* pNext;
/*0x0c*/ int           RecordNum;
/*0x10*/ EqItemGuid    ItemGuid;
/*0x24*/ int           RealEstateID;
/*0x28*/ int           RealEstateItemID;
/*0x2c*/ bool          bIsNPC;
/*0x30*/ unsigned int  PlacingItemNpcID;
/*0x34*/ CLightInterface* pLight;
/*0x38*/ CActorInterface* pActor;
/*0x3c*/ char          Name[0x40];
/*0x7c*/ int           Unknown0x7c;
/*0x80*/ int           Unknown0x80;
/*0x84*/ float         Scale;
/*0x88*/ float         Heading;
/*0x8c*/ float         Angle;
/*0x90*/ float         Roll;
/*0x94*/ float         Y;
/*0x98*/ float         X;
/*0x9c*/ float         Z;
/*0xa0*/ bool          bIgnoreCollisions;
/*0xa1*/ bool          bDisablePlacementRotation;
/*0xa2*/ bool          bDisableFreePlacement;
/*0xa4*/ ePlacementType PlacementType;
/*0xa8*/ float         ScaleRangeMin;
/*0xac*/ float         ScaleRangeMax;
/*0xb0*/ float         DefaultScale;
/*0xb4*/ float         DefaultHeading;
/*0xb8*/ float         DefaultAngle;
/*0xbc*/ float         DefaultRoll;
/*0xc0*/ int           LightType;
/*0xc4*/ float         NPCHeight;
/*0xc8*/
};

class EQPlacedItemManager
{
public:
	EQLIB_OBJECT static EQPlacedItemManager& Instance();
	EQLIB_OBJECT EQPlacedItem* GetItemByGuid(const EqItemGuid& ItemGuid);
	EQLIB_OBJECT EQPlacedItem* GetItemByRealEstateAndRealEstateItemIds(int RealEstateID, int RealEstateItemID);

	EQPlacedItem*      Top;
};

class [[offsetcomments]] RealEstateItemIds
{
public:
/*0x00*/ int                RealEstateID;
/*0x04*/ int                RealEstateItemID;
/*0x08*/
};

class [[offsetcomments]] RealEstateItemState
{
public:
/*0x00*/ bool               bPlaced;
/*0x04*/ __time32_t         UpkeepExpiredTime;
/*0x08*/
};

class [[offsetcomments]] RealEstateItemPosition
{
public:
/*0x00*/ float              Heading;
/*0x04*/ float              Pitch;
/*0x08*/ float              Roll;
/*0x0c*/ float              Scale;
/*0x10*/ float              X;
/*0x14*/ float              Y;
/*0x18*/ float              Z;
/*0x1c*/
};

class [[offsetcomments]] RealEstateItemOwnerInfo
{
public:
/*0x00*/ CXStr              OwnerName;
/*0x04*/ CXStr              OwnerHandle;
/*0x08*/ int                OwnerNameHashKey;
/*0x0c*/
};

class [[offsetcomments]] RealEstateItemObject
{
public:
/*0x00*/ VePointer<CONTENTS> pItemBase;
/*0x04*/
};

class [[offsetcomments]] RealEstateItem
{
public:
/*0x00*/ RealEstateItemState                State;
/*0x08*/ RealEstateItemPosition             Position;
/*0x24*/ RealEstateItemOwnerInfo            OwnerInfo;
/*0x30*/ RealEstateItemObject               Object;
/*0x34*/
};

class [[offsetcomments]] RealEstateItemClient : public RealEstateItem
{
public:
/*0x34*/ RealEstateItemIds IDs;
/*0x3c*/
};

enum eRealEstateType
{
	RET_None = 0,
	RET_Zone,
	RET_GuildHall,
	RET_PlayerHousing,
	RET_PlayerPlot,
	RET_Neighborhood,
	RET_Town,
	RET_MovingCrate,
	RET_GuildPlot,
	RET_Count,
	RET_Unknown,
	RET_Any
};

class [[offsetcomments]] RealEstateManagerClient
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ BYTE          Stuff[0xb4];
/*0xb8*/ UINT          lastRefreshTime;
/*0xbc*/ int           ZoneRealEstateId;
/*0xc0*/ eRealEstateType ZoneRealEstateType;
/*0xc4*/ int           CurrentRealEstateID;
/*0xc8*/ int           CurrentYardID;
/*0xcc*/ int           CurrentHouseID;
/*0xd0*/ int           CurrentMovingCrateID;
/*0xd4*/ bool          bRequestPending;
/*0xd8*/ UINT          RequestTime;
/*0xdc*/ bool          bPrintRequestTimes;
/*0xe0*/

	EQLIB_OBJECT static RealEstateManagerClient& Instance();
	EQLIB_OBJECT const RealEstateItemClient* GetItemByRealEstateAndItemIds(int RealEstateID, int RealEstateItemID) const;
};

class [[offsetcomments]] FactionManagerClient
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ // todo: map it

	EQLIB_OBJECT static FactionManagerClient& Instance();
	EQLIB_OBJECT void HandleFactionMessage(UINT MessageID, char* pData, unsigned int DataLength);
};

enum eParcelStatus
{
	ePS_NoParcels,
	ePS_HasParcels,
	ePS_OverParcelsLimit,
};

class [[offsetcomments]] CGroupMemberBase
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ CXStr         Name;
/*0x08*/ short         Type;
/*0x0c*/ CXStr         OwnerName;
/*0x10*/ int           Level;
/*0x14*/ bool          bIsOffline;
/*0x18*/ UINT          UniquePlayerID;
/*0x1c*/ bool          bRoleStates[6];
/*0x24*/ UINT          CurrentRoleBits;
/*0x28*/ UINT          OnlineTimestamp;
/*0x2c*/
};

class [[offsetcomments]] CGroupMemberClient : public CGroupMemberBase
{
	FORCE_SYMBOLS;

public:
/*0x2c*/ CharacterZoneClient* pCharacter;
/*0x30*/ SPAWNINFO*           pSpawn;
/*0x34*/ int                  GroupIndex;
/*0x38*/
};

class [[offsetcomments]] CGroupBase
{
	FORCE_SYMBOLS;

public:
/*0x00*/ void*         vftable;
/*0x04*/ CGroupMemberClient* pMembers[6];
/*0x1c*/ CGroupMemberClient* pGroupLeader;
/*0x20*/ uint32_t      ID;
/*0x24*/
};

class [[offsetcomments]] CGroupClient : public CGroupBase
{
	FORCE_SYMBOLS;

public:
/*0x24*/ int          GroupSelectID;
/*0x28*/
};

EQLIB_OBJECT char* build_token_string_PARAM(char* pBuffer, int token,
	const char* param0 = nullptr,
	const char* param1 = nullptr,
	const char* param2 = nullptr,
	const char* param3 = nullptr,
	const char* param4 = nullptr,
	const char* param5 = nullptr,
	const char* param6 = nullptr,
	const char* param7 = nullptr,
	const char* param8 = nullptr);


class EQPMInfo
{
public:
	EQLIB_OBJECT ~EQPMInfo();
	EQLIB_OBJECT EQPMInfo(char*);
	EQLIB_OBJECT void SetApplyGravity(bool);
};

enum SpeakerType
{
	SpeakerTypeNormal                  = 0, // AIL_3D_2_SPEAKER
	SpeakerTypeHeadphone               = 1, // AIL_3D_HEADPHONE
	SpeakerTypeSurround                = 2, // AIL_3D_SURROUND
	SpeakerTypeFour                    = 3, // AIL_3D_4_SPEAKER
	SpeakerTypeDolby51                 = 4, // AIL_3D_51_SPEAKER
	SpeakerTypeDolby71                 = 5, // AIL_3D_71_SPEAKER
};

class [[offsetcomments]] EqSoundManager
{
public:
	EQLIB_OBJECT ~EqSoundManager();
	EQLIB_OBJECT EqSoundManager(bool, bool, SpeakerType);
	EQLIB_OBJECT bool EmitterLoad(char*);
	EQLIB_OBJECT bool WaveIsPlaying(int);
	EQLIB_OBJECT SoundAsset* EqWaveGet(int);
	EQLIB_OBJECT EnvironmentType GetListenerEnvironment();
	EQLIB_OBJECT void EmitterAdd(EqEmitterData*);
	EQLIB_OBJECT void EmitterSetIndoors(bool);
	EQLIB_OBJECT void EmitterSetNight(bool);
	EQLIB_OBJECT void EmitterSetRaining(bool);
	EQLIB_OBJECT void EmitterSetUserDisabled(bool);
	EQLIB_OBJECT void EmitterSetWind(bool);
	EQLIB_OBJECT void GiveTime();
	EQLIB_OBJECT void SetCurrentZone(char*);
	EQLIB_OBJECT void SetEffectsLevel(float);
	EQLIB_OBJECT void SetListenerEnvironment(EnvironmentType);
	EQLIB_OBJECT void SetListenerEnvironmentHigh();
	EQLIB_OBJECT void SetListenerEnvironmentLow();
	EQLIB_OBJECT void SetListenerEnvironmentOutside();
	EQLIB_OBJECT void SetListenerLocation(float, float, float, float);
	EQLIB_OBJECT void SetMixAhead(int);
	EQLIB_OBJECT void SetMusicSelection(int, bool);
	EQLIB_OBJECT void SetMusicVolume(float);
	EQLIB_OBJECT void SetWaveVolume(float);
	EQLIB_OBJECT void WaveLoad(char*, int, bool);
	EQLIB_OBJECT void WavePlay(int, SoundControl*);
	EQLIB_OBJECT void WaveStop(int);

	// private
	EQLIB_OBJECT SoundAsset* GetAsset(char*);
	EQLIB_OBJECT SoundAsset* OldMp3GetSelection(int);
	EQLIB_OBJECT SoundEmitter* CreateOldEmitter(int, float, float, float, int, int, int, float, int, int, int);
	EQLIB_OBJECT int GetMusicId();
	EQLIB_OBJECT void LoadGlobalEmitters();
	EQLIB_OBJECT void LoadGlobalMusic();
	EQLIB_OBJECT void LoadGlobalWaves();
	EQLIB_OBJECT void LoadListOfWaveFiles(char**, int);
	EQLIB_OBJECT void LoadOldEmitters();
	EQLIB_OBJECT void OldMp3ClearSelections();
	EQLIB_OBJECT void OldMp3Init();
	EQLIB_OBJECT void OldMp3Terminate();
	EQLIB_OBJECT void PlayScriptMp3(char* Name, float Vol = 1.00f);
	EQLIB_OBJECT void ReleaseZoneSpecificEmitters();
	EQLIB_OBJECT void ReleaseZoneSpecificMidi();
	EQLIB_OBJECT void ReleaseZoneSpecificWaves();
	EQLIB_OBJECT void UpdateEmitterStates();

/*0x000*/ Mp3Manager*        pMp3Manager;
/*0x004*/ SoundManager*      pSoundManager;
/*0x008*/ EmitterManager*    pEmitterManager;
/*0x00c*/ MusicManager*      pMusicManager;
/*0x010*/ SoundAsset*        pGlobalMidiAsset;
/*0x014*/ SoundAsset*        pOpenerMidiAsset;
/*0x018*/ SoundAsset*        pOpenerMp3Asset;
/*0x01c*/ SoundAsset*        pDeathMp3Asset;
/*0x020*/ SoundAsset*        pCombatMp3Asset;
/*0x024*/ SoundAsset*        pMerchantMp3Asset;
/*0x028*/ SoundAsset*        pZoneMidiAsset;
/*0x02c*/ SoundAsset*        pScriptMp3Asset;
/*0x030*/ bool               bDisabled;
/*0x034*/ int                NextMusicID;
/*0x038*/ SoundEmitter*      pEmitters[1000];
/*0xfd8*/ int                EmittersCount;
/*0xfdc*/ SoundEmitter*      pRainEmitter;
/*0xfe0*/ SoundEmitter*      pWindEmitter;
/*0xfe4*/ int                EnvironmentHigh;
/*0xfe8*/ int                EnvironmentLow;
/*0xfec*/ int                EnvironmentOutside;
/*0xff0*/ float              fEffectsLevel;
/*0xff4*/ float              fWaveVolumeLevel;
/*0xff8*/ // more here but i only need volume for now so...
};

struct EQClientSwitch;
struct OldDiskSwitch;

class EQSwitch
{
public:
	EQLIB_OBJECT ~EQSwitch();
	EQLIB_OBJECT EQSwitch(char*, bool);
	EQLIB_OBJECT EQSwitch(EQClientSwitch*);
	EQLIB_OBJECT EQSwitch(OldDiskSwitch*, bool);
	EQLIB_OBJECT float GetCustomMoveDistance();
	EQLIB_OBJECT float TopSpeed(float*);
	EQLIB_OBJECT int GetSwitchDamage();
	EQLIB_OBJECT unsigned char SwitchIsNotUsable(int);
	EQLIB_OBJECT unsigned char SwitchWasOpened(int, int, PlayerClient*, bool*);
	EQLIB_OBJECT unsigned char SwitchWasOpenedActual(int, int, PlayerClient*, bool*);
	EQLIB_OBJECT unsigned int RepopFrequency();
	EQLIB_OBJECT void ChangeState(unsigned char, PlayerClient*, bool);
	EQLIB_OBJECT void LoadSwitchSounds(int);
	EQLIB_OBJECT void PostInit();
	EQLIB_OBJECT void PreInit();
	EQLIB_OBJECT void RepopSwitch();
	EQLIB_OBJECT void ResetSwitchState(unsigned char);
	EQLIB_OBJECT void UseSwitch(UINT SpawnID, int KeyID, int PickSkill, const CVector3* hitloc = 0);
};

class EqSwitchManager
{
public:
	EQLIB_OBJECT ~EqSwitchManager();
	EQLIB_OBJECT EqSwitchManager();
	EQLIB_OBJECT EQSwitch* GetSwitch(int);
	EQLIB_OBJECT EQSwitch* GetSwitchByActor(CActorInterface*);
	EQLIB_OBJECT EQSwitch* GetSwitchById(int, bool);
	EQLIB_OBJECT int GetCount();
	EQLIB_OBJECT void AddSwitch(EQSwitch*);
	EQLIB_OBJECT void DeleteAll();
	EQLIB_OBJECT void Load(char*, bool);

	// protected
	EQLIB_OBJECT void LoadOld(char*, bool);
};

class EQUtil
{
public:
	EQLIB_OBJECT static char* FormatCharName(char*, char*, int);
};

class EQWorldData
{
public:
	EQLIB_OBJECT EQWorldData();
	EQLIB_OBJECT bool GetGeometryNameFromIndex(EQZoneIndex, char*) const;
	EQLIB_OBJECT bool IsFlagSet(EQZoneIndex, unsigned long) const;
	EQLIB_OBJECT bool IsNewbieZone(EQZoneIndex) const;
	EQLIB_OBJECT bool IsNoAirZone(EQZoneIndex) const;
	EQLIB_OBJECT bool IsNoBindZone(EQZoneIndex) const;
	EQLIB_OBJECT bool const AddZone(EQExpansion, EQZoneIndex, const char*, const char*, int, unsigned long, int, int);
	EQLIB_OBJECT EQExpansion ExpansionZone(EQZoneIndex) const;
	EQLIB_OBJECT EQZoneIndex GetIndexFromZoneName(const char*);
	EQLIB_OBJECT int GetMinLevel(EQZoneIndex) const;
	EQLIB_OBJECT void AdvanceTime(unsigned int);
	EQLIB_OBJECT void CurrentGameTime(char*);
	EQLIB_OBJECT void GetFullZoneName(EQZoneIndex, char*);

	// virtual
	EQLIB_OBJECT ~EQWorldData();
};

// TODO: Map to ZONEINFO
class EQZoneInfo
{
public:
	EQLIB_OBJECT EQZoneInfo(EQExpansion, EQZoneIndex, const char*, const char*, int, uint64_t flags, int, int);

	// virtual
	EQLIB_OBJECT ~EQZoneInfo();
};

enum eIconCacheType
{
	eit_Items,
	eit_Spells,
	eit_Menus,
	eit_Vivox,
};

class [[offsetcomments]] IconCache
{
public:
/*0x00*/ HashTable<CTextureAnimation*> IconTextures;
/*0x10*/ CXStr              pAnimationName;
/*0x14*/ int                Offset;
/*0x18*/ int                MinValue;
/*0x1c*/ int                MaxValue;
/*0x20*/

	EQLIB_OBJECT CTextureAnimation* GetIcon(int);
};

struct JournalEntry;

class JournalNPC
{
public:
	EQLIB_OBJECT ~JournalNPC();
	EQLIB_OBJECT JournalNPC();
	EQLIB_OBJECT int AddEntry(long, float, float, float, char*, int);
	EQLIB_OBJECT int AddEntry(long, float, float, float, int, int);
	EQLIB_OBJECT int DeleteEntryByHash(int);
	EQLIB_OBJECT int DeleteEntryByIndex(int);
	EQLIB_OBJECT int FindThisText(char*, bool, int);
	EQLIB_OBJECT int ReadEntry(FILE*);
	EQLIB_OBJECT static char* GetText(int);
	EQLIB_OBJECT JournalEntry* FindEntryByCategory(int, int);
	EQLIB_OBJECT JournalEntry* FindEntryByHash(int);
	EQLIB_OBJECT JournalEntry* GetEntry(int);
	EQLIB_OBJECT void ConvertCategory(int, int);

	// private
	EQLIB_OBJECT void AllocateArray();
	EQLIB_OBJECT void CleanEntries();
	EQLIB_OBJECT void ComputeLatestTime();
};

class KeyCombo
{
public:
	EQLIB_OBJECT KeyCombo(int);

	EQLIB_OBJECT KeyCombo(unsigned char keycode, bool alt, bool ctrl, bool shift)
	{
		Data[0] = alt;
		Data[1] = ctrl;
		Data[2] = shift;
		Data[3] = keycode;
	}

	EQLIB_OBJECT KeyCombo(unsigned int, unsigned int, bool, bool, bool);

	EQLIB_OBJECT KeyCombo()
	{
		Data[0] = 0;
		Data[1] = 0;
		Data[2] = 0;
		Data[3] = 0;
	}

	EQLIB_OBJECT void Clear()
	{
		Data[0] = 0;
		Data[1] = 0;
		Data[2] = 0;
		Data[3] = 0;
	}

	EQLIB_OBJECT bool UsesAlt() const
	{
		return Data[0] != 0;
	}

	EQLIB_OBJECT bool UsesCtrl() const
	{
		return Data[1] != 0;
	}

	EQLIB_OBJECT bool UsesShift() const
	{
		return Data[2] != 0;
	}

	EQLIB_OBJECT uint8_t GetKey() const
	{
		return Data[3];
	}

	EQLIB_OBJECT int operator==(const KeyCombo& Combo)
	{
		return *(uint32_t*)&Data == *(uint32_t*)&Combo.Data;
	}

	EQLIB_OBJECT CXStr GetTextDescription() const;

	EQLIB_OBJECT const KeyCombo& operator=(int);

	EQLIB_OBJECT operator int() const;
	EQLIB_OBJECT bool GetPrintableLetter(unsigned short*) const;

	// private
	EQLIB_OBJECT bool GetPrintableLetterFromScanCode(unsigned char, bool, bool, unsigned short*) const;
	EQLIB_OBJECT bool GetPrintableLetterFromVirtualKey(unsigned int, unsigned int, bool, bool, unsigned short*) const;
	EQLIB_OBJECT bool GetScanCodeFromVirtualKey(unsigned int, unsigned int, unsigned char*) const;
	EQLIB_OBJECT bool GetVirtualKeyFromScanCode(unsigned char, int*) const;

	uint8_t Data[4];

	// actually:
	// bool Alt;
	// bool Ctrl;
	// bool Shift;
	// uint8_t KeyCode;
};

class [[offsetcomments]] KeypressHandler
{
public:
	static KeypressHandler& Get();

	EQLIB_OBJECT KeypressHandler();
	EQLIB_OBJECT ~KeypressHandler();
	EQLIB_OBJECT bool AttachAltKeyToEqCommand(const KeyCombo&, unsigned int);
	EQLIB_OBJECT bool AttachKeyToEqCommand(const KeyCombo&, unsigned int);
	EQLIB_OBJECT bool HandleKeyDown(const KeyCombo&);
	EQLIB_OBJECT bool HandleKeyUp(const KeyCombo&);
	EQLIB_OBJECT const KeyCombo& GetAltKeyAttachedToEqCommand(unsigned int) const;
	EQLIB_OBJECT const KeyCombo& GetKeyAttachedToEqCommand(unsigned int) const;
	EQLIB_OBJECT void ResetKeysToEqDefaults();

	// private
	EQLIB_OBJECT bool IsReservedKey(const KeyCombo&) const;
	EQLIB_OBJECT bool LoadAndConvertOldKeymappingFormat(unsigned int, int, KeyCombo*);
	EQLIB_OBJECT bool LoadKeymapping(unsigned int, int, KeyCombo*);
	EQLIB_OBJECT bool MapKeyToEqCommand(const KeyCombo&, int, unsigned int);
	EQLIB_OBJECT CXStr GetEqCommandSaveName(unsigned int, int) const;
	EQLIB_OBJECT void ClearCommandStateArray();
	EQLIB_OBJECT void LoadAndSetKeymappings();
	EQLIB_OBJECT void SaveKeymapping(unsigned int, const KeyCombo&, int);

/*0x0000*/ KeyCombo     NormalKey[nEQMappableCommands];
/*0x0884*/ KeyCombo     AltKey[nEQMappableCommands];
/*0x1108*/ char         CommandState[nEQMappableCommands];
/*0x132c*/
};

struct [[offsetcomments]] ItemFilterData
{
/*0x00*/ int           Types;
/*0x04*/ int           ID;
/*0x08*/ int           Icon;
/*0x0c*/ char          Name[0x40];
/*0x4c*/
};

class LootFiltersManager
{
public:
	EQLIB_OBJECT bool AddItemLootFilter(int ItemID, int IconID, const char* ItemName, int FilterTypes, bool bFromFile = false);
	EQLIB_OBJECT const ItemFilterData* GetItemFilterData(int ItemID);
	EQLIB_OBJECT bool RemoveItemLootFilter(int ItemID, int FilterTypes);
	EQLIB_OBJECT bool SetItemLootFilter(int ItemID, int IconID, const char* ItemName, int FilterTypes, bool bKeepRndSetting, bool bScrollToIt);
};

class [[offsetcomments]] MercenaryAbilityReq
{
public:
/*0x00*/ int           ReqGroupID;
/*0x04*/ int           ReqGroupRank;
/*0x08*/
};

class [[offsetcomments]] MercenaryAbilitiesData
{
public:
/*0x00*/ int           AbilityID;
/*0x04*/ int           nName;
/*0x08*/ int           nDesc;
/*0x0c*/ int           Cost;
/*0x10*/ int           GroupID;
/*0x14*/ int           GroupRank;
/*0x18*/ int           Type;
/*0x1c*/ int           MinPlayerLevel;           // min level to purchase...
/*0x20*/ int           RequirementAssociationID;
/*0x24*/ int           Refund;
/*0x28*/ int           BetaOnly;
/*0x2c*/ int           QuestAbility;
/*0x30*/ ArrayClass<MercenaryAbilityReq> AbilityReqs;
/*0x40*/
};

class [[offsetcomments]] MercenaryAlternateAdvancementManagerClient
{
public:
	EQLIB_OBJECT static MercenaryAlternateAdvancementManagerClient& Instance();

/*0x000*/ HashList<int, 5>                             MercenaryTypes;
/*0x02c*/ HashList<MercenaryAbilitiesData, 0x40>       MercenaryAbilities;
/*0x144*/ HashList<int, 0x40>                          MercenaryAbilitiesByGroupID;
/*0x25c*/ HashList<int, 0x40>                          MercenaryAbilitiesOwnedByGroupID;
/*0x374*/ HashList<HashList<int, 0x10>, 0x40>          MercenaryAbilityGroups;
/*0x48c*/
};

enum eSpellStringType
{
	SpellStringCastByMe,
	SpellStringCastByOther,
	SpellStringCastOnYou,
	SpellStringCastOnAnother,
	SpellStringWearOff,
};

class EQSpellStrings
{
public:
	EQLIB_OBJECT const char* GetString(int SpellID, int StrIndex);
};

enum InstanceType
{
	InstanceTypeWave,
	InstanceTypeWave3d,
	InstanceTypeMidi,
};

class MidiInstance
{
public:
	EQLIB_OBJECT MidiInstance(SoundManager*);
	EQLIB_OBJECT virtual ~MidiInstance();

	// virtual
	EQLIB_OBJECT bool GiveTime();
	EQLIB_OBJECT InstanceType GetType();
	EQLIB_OBJECT void AdjustVolume(float, int);
	EQLIB_OBJECT void GuaranteeStopped();
	EQLIB_OBJECT void Move(float, float, float);
	EQLIB_OBJECT void Play(SoundControl*);
};

enum StreamingStatus
{
	StreamingStatusDone,
	StreamingStatusPlaying,
	StreamingStatusStopped,
};

class Mp3Manager
{
public:
	class Entry
	{
	public:
		Entry(char*, char*, int, int);
		~Entry();
	};

	enum SortOrder
	{
		SortOrderNormal,
		SortOrderRandom,
	};

	EQLIB_OBJECT Mp3Manager(SoundManager*, MusicManager*);
	EQLIB_OBJECT ~Mp3Manager();

	EQLIB_OBJECT char* GetName(int);
	EQLIB_OBJECT SortOrder GetSort();
	EQLIB_OBJECT StreamingStatus Status();
	EQLIB_OBJECT float GetVolumeLevel();
	EQLIB_OBJECT int Add(char*);
	EQLIB_OBJECT int Count();
	EQLIB_OBJECT int GetPosition();
	EQLIB_OBJECT int GetSongLength();
	EQLIB_OBJECT int GetSongPosition();
	EQLIB_OBJECT void Back();
	EQLIB_OBJECT void Delete(int);
	EQLIB_OBJECT void DeleteAll();
	EQLIB_OBJECT void GiveTime();
	EQLIB_OBJECT void Next();
	EQLIB_OBJECT void Pause();
	EQLIB_OBJECT void Play();
	EQLIB_OBJECT void SaveList(char*);
	EQLIB_OBJECT void SetPosition(int);
	EQLIB_OBJECT void SetSongPosition(int);
	EQLIB_OBJECT void SetVolumeLevel(float);
	EQLIB_OBJECT void Sort(SortOrder);
	EQLIB_OBJECT void Stop();

	// private
	EQLIB_OBJECT int InternalAdd(char*, char*, int);
};

class MusicManager
{
public:
	class MusicEntry
	{
	public:
		EQLIB_OBJECT MusicEntry(int, SoundAsset*, int, float, int, int, int, int, int, int);
		EQLIB_OBJECT ~MusicEntry();

		EQLIB_OBJECT void AdjustVolume(float);
		EQLIB_OBJECT void FadeIn(float);
		EQLIB_OBJECT void FadeOut(bool);
	};

	EQLIB_OBJECT ~MusicManager();
	EQLIB_OBJECT MusicManager();
	EQLIB_OBJECT void Clear(SoundAsset*);
	EQLIB_OBJECT void Clear(int);
	EQLIB_OBJECT void Enable(bool);
	EQLIB_OBJECT void GiveTime();
	EQLIB_OBJECT void Play(int);
	EQLIB_OBJECT void Set(int, SoundAsset*, int, float, int, int, int, int, int, int);
	EQLIB_OBJECT void SetVolumeLevel(float);
	EQLIB_OBJECT void Stop(int);
};

enum AssetType
{
	cAssetTypeUnknown,
	cAssetTypeWave,
	cAssetTypeMp3,
	cAssetTypeOgg,
	cAssetTypeMidi
};

class [[offsetcomments]] SoundObject
{
public:
	SoundObject();
	virtual ~SoundObject();

	void AddRef();
	void Release();

/*0x04*/ int refCount = 1;
/*0x08*/
};

class [[offsetcomments]] SoundAsset : public SoundObject
{
public:
	EQLIB_OBJECT SoundAsset(SoundManager*, char*, char*, int);
	EQLIB_OBJECT bool IsPlaying();
	EQLIB_OBJECT char* GetName();
	EQLIB_OBJECT SoundInstance* Play(SoundControl*);

	EQLIB_OBJECT enum AssetType GetType();
	EQLIB_OBJECT void AdjustVolume(float, int);
	EQLIB_OBJECT void GiveTime();
	EQLIB_OBJECT void Stop();

	// protected
	EQLIB_OBJECT virtual ~SoundAsset();
	EQLIB_OBJECT void YourManagerDeleted();

/*0x008*/ char szName[512];
/*0x208*/ char* rawData;
/*0x20c*/ int rawDataLen;
/*0x210*/ AssetType assetType;
/*0x214*/ SoundManager* soundManager;
/*0x218*/ SoundInstance* soundInstance;
/*0x21c*/ SoundAsset* pNext;
/*0x220*/
};

struct [[offsetcomments]] SoundControl
{
/*0x00*/ float volumeLevel = 1.0f;
/*0x04*/ int fadeInTime = 0;
/*0x08*/ int loops = 1;
/*0x0c*/ int sequence = 0;
/*0x10*/ float x = 0.f;
/*0x14*/ float y = 0.f;
/*0x18*/ float z = 0.f;
/*0x1c*/ float minDistance = 0.f;
/*0x20*/ float maxDistance = 0.f;
/*0x24*/ float effectsLevel = 1.f;
/*0x28*/ int poolNumber = 0;
/*0x2c*/ bool fireOnce = true;
/*0x2d*/ bool startUp = false;
/*0x30*/
};

class SoundEmitter
{
public:
	EQLIB_OBJECT SoundEmitter(EmitterManager*, MusicManager*, int);
	EQLIB_OBJECT SoundEmitter(EmitterManager*, SoundAsset*, int);
	EQLIB_OBJECT void Enable(bool);
	EQLIB_OBJECT void GiveTime();
	EQLIB_OBJECT void Move(float, float, float);
	EQLIB_OBJECT void SetAsset(SoundAsset*);

	// protected
	EQLIB_OBJECT virtual ~SoundEmitter();
	EQLIB_OBJECT void Init();
	EQLIB_OBJECT void ReleaseLoopingSound();
	EQLIB_OBJECT void ResetTimer();
};

class SoundInstance : public SoundObject
{
public:
	EQLIB_OBJECT SoundInstance(SoundManager*);

	// virtual
	EQLIB_OBJECT void SetPoolNumber(int);
	EQLIB_OBJECT void SetSoundAsset(SoundAsset*);

	// protected
	EQLIB_OBJECT virtual ~SoundInstance();
	EQLIB_OBJECT void YourManagerDeleted();
};

class SoundManager
{
public:
	EQLIB_OBJECT ~SoundManager();
	// EQLIB_OBJECT SoundManager(int, int, bool, int, int, bool, enum SpeakerType);
	EQLIB_OBJECT SoundAsset* AssetGet(char*);
	// EQLIB_OBJECT SoundInstance* BorrowInstance(enum InstanceType, int);
	// EQLIB_OBJECT enum EnvironmentType GetListenerEnvironment();
	// EQLIB_OBJECT enum StreamingStatus StreamingStatus();
	EQLIB_OBJECT float StreamingGetVolumeLevel();
	EQLIB_OBJECT int StreamingGetSongLength();
	EQLIB_OBJECT int StreamingGetSongPosition();
	// EQLIB_OBJECT void AddPool(enum InstanceType, int, int);
	EQLIB_OBJECT void GetListenerLocation(float*, float*, float*, float*);
	EQLIB_OBJECT void GiveTime();
	EQLIB_OBJECT void ReturnInstance(SoundInstance*);
	// EQLIB_OBJECT void SetListenerEnvironment(enum EnvironmentType);
	EQLIB_OBJECT void SetListenerLocation(float, float, float, float);
	EQLIB_OBJECT void SetMixAhead(int);
	EQLIB_OBJECT void StreamingPause();
	EQLIB_OBJECT void StreamingPlay(char*);
	EQLIB_OBJECT void StreamingSetSongPosition(int);
	EQLIB_OBJECT void StreamingSetVolumeLevel(float);
	EQLIB_OBJECT void StreamingStop();

	// protected
	EQLIB_OBJECT void AssetAdd(SoundAsset*);
	EQLIB_OBJECT void AssetGiveTime();
	EQLIB_OBJECT void AssetRemove(SoundAsset*);
};

class [[offsetcomments]] FileStatMgr
{
public:
	struct FileStat
	{
		struct _stat32 Stats;
		CXStr          Filename;
		CXStr          Key;
	};

/*0x00*/ HashTable<FileStat*> FileStats;
/*0x10*/
};

enum ReqType
{
	RT_None,
	RT_Sex,
	RT_MinLevel,
	RT_MaxLevel,
	RT_LevelRange,
	RT_Class,
	RT_Race,
	// there are like 72 more of these I dont have time to add them all now.
};

class [[offsetcomments]] RequirementAssociationManager : public FileStatMgr
{
public:
/*0x010*/ void*              vfTable;
/*0x014*/ HashTable<HashTable<DoublyLinkedList<int>*>*> Requirements;
/*0x024*/ char               AssocFilename[512];
/*0x224*/ ReqType            LastFailReason;
/*0x228*/ int                LastFailGroupID;
/*0x22c*/ int                LastFailReqID;
/*0x230*/
};

class [[offsetcomments]] SpellRequirementAssociationManager : public RequirementAssociationManager
{
public:
/*0x0230*/ HashList<HashList<HashList<int, 10>, 10>, 1000> ReqAssData;
/*0x11e8*/
};

struct [[offsetcomments]] StageType
{
/*0x000*/ char               BlitSprite[3][0x20];
/*0x060*/ char               AttachTag[0x20];
/*0x080*/ int                DAGnum[3];
/*0x08c*/ int                pcloud[3];
/*0x098*/ char               SpriteTAG[0xc][0x20];
/*0x218*/ int                SpritEffect;
/*0x21c*/ int                SoundNum;
/*0x220*/ ARGBCOLOR          Tint[3];
/*0x22c*/ float              Gravity[3];
/*0x238*/ float              NormalX1;
/*0x23c*/ float              NormalY1;
/*0x240*/ float              NormalZ1;
/*0x244*/ float              NormalX2;
/*0x248*/ float              NormalY2;
/*0x24c*/ float              NormalZ2;
/*0x250*/ float              NormalX3;
/*0x254*/ float              NormalY3;
/*0x258*/ float              NormalZ3;
/*0x25c*/ float              Radius[3];
/*0x268*/ float              Angle[3];
/*0x274*/ ULONG              Lifespan[3];
/*0x280*/ float              Velocity[3];
/*0x28c*/ ULONG              Rate[3];
/*0x298*/ float              Scale[3];
/*0x2a4*/ EQRGB              SpriteRGB[0xc];
/*0x2c8*/ float              RollRate[0xc];
/*0x2f8*/ short              HdgOffset[0xc];
/*0x310*/ short              PitchOffset[0xc];
/*0x328*/ float              Distance[0xc];
/*0x358*/ short              EffectType[12];
/*0x370*/ float              ScaleFactor[12];
/*0x3a0*/
};

struct [[offsetcomments]] OldSpellEffect
{
/*0x000*/ int                Tgts;
/*0x004*/ int                Perm;
/*0x008*/ StageType          stages[3];
/*0xae8*/
};

enum EEffectActor
{
	EEA_None,
	EEA_Caster,
	EEA_Missile,
	EEA_Target,
	EEA_COUNT,
};

enum EAttachPoint
{
	EAP_None,
	EAP_Default,
	EAP_Chest,
	EAP_Head,
	EAP_LeftHand,
	EAP_RightHand,
	EAP_LeftFoot,
	EAP_RightFoot,
	EAP_Weapon,
	EAP_LeftEye,
	EAP_RightEye,
	EAP_Mouth,
	EAP_Ground,
	EAP_Cnt,
};

struct [[offsetcomments]] SpellEffectEmitter
{
/*0x00*/ int DefIndex;
/*0x04*/ int RequiredLevel;
/*0x08*/ EEffectActor EffectActor;
/*0x0c*/ EAttachPoint AttachPoint;
/*0x10*/
};

struct [[offsetcomments]] SpellEffectStage
{
/*0x00*/ int                SoundNum;
/*0x04*/ SpellEffectEmitter Emitters[4];
/*0x44*/
};

struct [[offsetcomments]] NewSpellEffect
{
/*0x000*/ char               szSpellEffectName[0x40];
/*0x040*/ SpellEffectStage   Stages[3];
/*0x10c*/
};

class [[offsetcomments]] EQSpellExtra
{
public:
/*0x00*/ OldSpellEffect*    OldSpellEff;
/*0x04*/ NewSpellEffect*    NewSpellEff;
/*0x08*/
};

//Matching stack group ID rules
enum ESpellStackingRules
{
	ESSR_None,                                   // default
	ESSR_SingleCaster,
	ESSR_AllCasters,
	ESSR_SingleCasterOnlyGreater,
	ESSR_AllCastersOnlyGreater,
	ESSR_SingleCasterNeverOverwrite,
	ESSR_AllCastersNeverOverwrite,
	ESSR_SingleCasterAlwaysOverwrite,
	ESSR_AllCastersAlwaysOverwrite,
	ESSR_Invalid,
};

struct [[offsetcomments]] StackingGroupData
{
/*0x00*/ int StackingGroupID;
/*0x04*/ int StackingGroupRank;
/*0x08*/ ESpellStackingRules StackingGroupRuleType;
/*0x0c*/
};

// really would like to get this to work and align but its kinda complicated, maybe another day.
class [[offsetcomments]] SpellManager : public FileStatMgr
{
public:
/*0x00014*/ int      SpellsCrc32[TOTAL_SPELL_COUNT+1];
/*0x3c8d8*/ PSPELL   MissingSpell;
/*0x3c8dc*/ PSPELLCALCINFO* MissingSpellAffect;
/*0x3c8e0*/ PSPELLCALCINFO* MissingSpellAffectAC;
/*0x3c8e4*/ int      MissingSpellCrc32;
/*0x3c8e8*/ int      SpellFileCRC;
/*0x3c8ec*/ int      SpellAssocFileCRC;
/*0x3c8f0*/ int      SpellStackingFileCRC;
/*0x3c8f4*/ SpellRequirementAssociationManager ReqAssocManager;
/*0x3dadc*/ HashTable<int, int, ResizePolicyNoShrink> SpellGroups;
/*0x3daec*/

SpellManager(char*);
	virtual ~SpellManager() {}

	EQLIB_OBJECT const EQ_Spell* GetSpellByGroupAndRank(int Group, int SubGroup, int Rank = -1, bool bLesserRanksOk = false);
};

class [[offsetcomments]] ClientSpellManager : public SpellManager
{
public:
	EQLIB_OBJECT virtual ~ClientSpellManager();
	EQLIB_OBJECT bool LoadSpells(const char* FileName, const char* AssocFilename, const char* StackingFileName);
	EQLIB_OBJECT bool LoadSpellStackingData(const char* StackingFileName);
	EQLIB_OBJECT bool DoesMeetRequirement(PlayerZoneClient* pPlayer, int SpellAssocID);
	EQLIB_OBJECT void PrintFailedRequirementString(int StrToken, int StringID);
	EQLIB_OBJECT int GetSpellStackingGroupID(int SpellID);
	EQLIB_OBJECT int GetSpellStackingGroupRank(int SpellID);
	EQLIB_OBJECT ESpellStackingRules GetSpellStackingGroupRule(int SpellID);
	EQLIB_OBJECT PSPELL GetSpellByID(int SpellID);
	EQLIB_OBJECT SPELLCALCINFO* GetSpellAffect(int index);
	EQLIB_OBJECT bool GetSpellAffectEmpty(bool);

/*0x03daec*/ SPELL*                       Spells[TOTAL_SPELL_COUNT+1];         // 60001 last one is the unknown spell...
/*0x07a3b0*/ SPELLCALCINFO*               CalcInfo[CalcInfoSize];              // 175000
/*0x143670*/ EQSpellExtra                 SpellExtraData[TOTAL_SPELL_COUNT+1];
/*0x1bc7f8*/ HashTable<StackingGroupData> StackingData;
/*0x1bc808*/
};

class StringTable
{
public:
	EQLIB_OBJECT const char* getString(unsigned long ID, bool* bFound = nullptr);
};

class Wave3dInstance : public SoundInstance
{
public:
	EQLIB_OBJECT Wave3dInstance(SoundManager*);

	// virtual
	EQLIB_OBJECT bool GiveTime();
	EQLIB_OBJECT enum InstanceType GetType();
	EQLIB_OBJECT void AdjustVolume(float, int);
	EQLIB_OBJECT void GuaranteeStopped();
	EQLIB_OBJECT void Move(float, float, float);
	EQLIB_OBJECT void Play(SoundControl*);

	// protected
	EQLIB_OBJECT virtual ~Wave3dInstance();
};

class WaveInstance : public SoundInstance
{
public:
	EQLIB_OBJECT WaveInstance(SoundManager*);

	// virtual
	EQLIB_OBJECT bool GiveTime();
	// enum InstanceType GetType();
	EQLIB_OBJECT void AdjustVolume(float, int);
	EQLIB_OBJECT void GuaranteeStopped();
	EQLIB_OBJECT void Move(float, float, float);
	EQLIB_OBJECT void Play(SoundControl*);

	// protected
	EQLIB_OBJECT virtual ~WaveInstance();
};

class CTextOverlay
{
public:
	EQLIB_OBJECT void DisplayText(const char* Str, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
};

enum eDatabaseStringType
{
	eDefaultStringType = 0,
	eAltAbilityName = 1,
	eAltAbilityDescription = 4,
	eSpellCategory = 5,
	eSpellDescription = 6,

	eMercenarySubCategoryDescription = 23,
	eMercenaryStanceName = 24,

	eMercenaryAbilityName = 37,
};

class DatabaseStringTable
{
public:
	EQLIB_OBJECT const char* GetString(int id, eDatabaseStringType type, bool* found = nullptr);

	[[deprecated("Use eDatabaseStringType enum")]] const char* GetString(int id, int type)
	{
		return GetString(id, static_cast<eDatabaseStringType>(type), nullptr);
	}
};
using CDBStr = DatabaseStringTable;



class EQMisc
{
public:
	EQLIB_OBJECT int GetActiveFavorCost();
};

class CSkillMgr
{
public:
	EQLIB_OBJECT int GetNameToken(int);
	EQLIB_OBJECT unsigned long GetSkillCap(PcZoneClient*, int, int, int, bool, bool, bool); // TODO: CharacterZoneClient or PcZoneClient ?
	EQLIB_OBJECT unsigned long SkillAvailableAtLevel(int, int);
	EQLIB_OBJECT bool IsActivatedSkill(int);
	EQLIB_OBJECT unsigned long GetBaseDamage(int);
	EQLIB_OBJECT unsigned long GetReuseTime(int);
	EQLIB_OBJECT bool IsAvailable(int);
	EQLIB_OBJECT bool IsCombatSkill(int);
};

class CChatService
{
public:
	EQLIB_OBJECT int GetNumberOfFriends();
	EQLIB_OBJECT const char* GetFriendName(int);

	// TODO: Merge with _CHATSERVICE
};

class PlayerPointManager
{
public:
	EQLIB_OBJECT unsigned long GetAltCurrency(unsigned long, unsigned long b = 1);
};

enum eKeyboardMode
{
	Typing,
	KBM_Command,
};

#pragma pack(push)
#pragma pack(4)

struct [[offsetcomments]] EVERQUESTINFO
{
/*0x000*/ HWND       Wnd;
/*0x004*/ HINSTANCE  hInst;
/*0x008*/ int        Render_MinX;
/*0x00c*/ int        Render_MinY;
/*0x010*/ int        Render_MaxX;
/*0x014*/ int        Render_MaxY;
/*0x018*/ int        Render_XScale;
/*0x01c*/ int        Render_YScale;
/*0x020*/ int        Render_WidthScale;
/*0x024*/ int        Render_HeightScale;
/*0x028*/ int        ReadyEnterWorld;
/*0x02c*/ bool       InsideDoMainWhileLoop;
/*0x030*/ int        Hidden;
/*0x034*/ DWORD      Displayflags;
/*0x038*/ DWORD      Command;
/*0x03c*/ BYTE       Unknown0x0003c;
/*0x040*/ int        ScreenXRes;
/*0x044*/ int        ScreenYRes;
/*0x048*/ int        WindowXOffset;
/*0x04c*/ int        WindowYOffset;
/*0x050*/ bool       FullscreenMode;
/*0x054*/ eKeyboardMode KeyboardMode;
/*0x058*/ BYTE       Runmode;                  // dont EVER set this to something > 1 unless you WANT to get banned.
/*0x059*/ BYTE       Unknown0x00059;
/*0x05a*/ BYTE       Unknown0x0005a;
/*0x05b*/ BYTE       MouseCntrl;
/*0x05c*/ BYTE       MouseActive;
/*0x05d*/ BYTE       ForceCrouch;
/*0x060*/ UINT       ForceCrouchTimer;
/*0x064*/ float      Unknown0x00064;
/*0x068*/ float      Unknown0x00068;
/*0x06c*/ int        MouseX;
/*0x070*/ int        MouseY;
/*0x074*/ int        MouseZ;
/*0x078*/ int        Lastmx;
/*0x07c*/ int        Lastmy;
/*0x080*/ bool       MouseInClientRect;
/*0x084*/ int        MXSensitivity;
/*0x088*/ int        MYSensitivity;
/*0x08c*/ int        MousePointerSpeedMod;
/*0x090*/ bool       ServerFilter;
/*0x094*/ int        IsTrader;
/*0x098*/ BYTE       CurrentChan;
/*0x09c*/ int        CurrentLang;
/*0x0a0*/ char       TellTarget[0x40];
/*0x0e0*/ UINT       LastMinute;
/*0x0e4*/ UINT       LastLocal;
/*0x0e8*/ UINT       LastControlled;
/*0x0ec*/ BYTE       MInverse;
/*0x0ed*/ BYTE       Unknown0x000ed;
/*0x0ee*/ BYTE       MouseLook;
/*0x0ef*/ bool       bDefaultMouseLook;
/*0x0f0*/ BYTE       Strafe;
/*0x0f1*/ bool       bNetstat;
/*0x0f2*/ BYTE       ModInventory;
/*0x0f4*/ UINT       LastHitter;
/*0x0f8*/ BYTE       Harmless;
/*0x0f9*/ BYTE       Silenced;
/*0x0fc*/ UINT       JumpTimer;
/*0x100*/ UINT       EventJump;
/*0x104*/ UINT       LastJump;
/*0x108*/ UINT       FrameTime;
/*0x10c*/ int        AutoRun;
/*0x110*/ UINT       PoisonTimer;
/*0x114*/ ItemGlobalIndex PoisonGI;
/*0x120*/ int        OldX;
/*0x124*/ int        OldY;
/*0x128*/ BYTE       OldMouseButtons[8];
/*0x130*/ BYTE       MouseButtons[8];
/*0x138*/ bool       bIsMouseRightHanded;
/*0x13c*/ int        Unknown0x0013c;
/*0x140*/ int        CharStatePending;
/*0x144*/ char       PendingCharacterName[0x40];
/*0x184*/ int        TutorialMode;
/*0x188*/ int        RMouseSecond;
/*0x18c*/ int        LMouseSecond;
/*0x190*/ UINT       RMouseDown;
/*0x194*/ UINT       LMouseDown;
/*0x198*/ char       Unknown0x00198[0x40];
/*0x1d8*/ UINT       DuelTarget;
/*0x1dc*/ UINT       DuelMe;
/*0x1e0*/ BYTE       DuelOn;
/*0x1e4*/ UINT       AutoHelp;
/*0x1e8*/ BYTE       OldMouseLook;
/*0x1ec*/ UINT       LastLocalUpdate;
/*0x1f0*/ UINT       LastControlledUpdate;
/*0x1f4*/ UINT       DataRate;
/*0x1f8*/ int        SavedPC;
/*0x1fc*/ int        InfraRed;
/*0x200*/ int        InfraGreen;
/*0x204*/ int        InfraBlue;
/*0x208*/ int        UltraRed;
/*0x20c*/ int        UltraGreen;
/*0x210*/ int        UltraBlue;
/*0x214*/ int        Unknown0x00214;
/*0x218*/ int        IOLines;
/*0x21c*/ int        IOLineSpacing;
/*0x220*/ char       ObjTag[0x14];
/*0x234*/ long       NumObjects;
/*0x238*/ long       NumLights;
/*0x23c*/ long       DecrTime[0xa];
/*0x264*/ long       DecrMsg[0xa];
/*0x28c*/ long       DecrIndex;
/*0x290*/ BYTE       AffectsOn;
/*0x291*/ BYTE       InspectMode;
/*0x292*/ BYTE       UpMouseAnim;
/*0x294*/ UINT       ExitCounter;
/*0x298*/ UINT       ExitStart;
/*0x29c*/ UINT       ForcedExitCounter;
/*0x2a0*/ UINT       OfflineModeRequestTime;
/*0x2a4*/ int        SwimJump;
/*0x2a8*/ BYTE       DisplayCamp;
/*0x2ac*/ int        PolysOff;
/*0x2b0*/ float      CampY;
/*0x2b4*/ float      CampX;
/*0x2b8*/ float         CampZ;
/*0x2bc*/ int        Hits;
/*0x2c0*/ int        Bandage;
/*0x2c4*/ UINT       BackSpace;
/*0x2c8*/ long       StartBandage;
/*0x2cc*/ long       MyY;
/*0x2d0*/ long       MyX;
/*0x2d4*/ long       MyZ;
/*0x2d8*/ long       TargetY;
/*0x2dc*/ long       TargetX;
/*0x2e0*/ long       TargetZ;
/*0x2e4*/ ZONEINFO   ZoneInfo;
/*0x684*/ BYTE       ZDefined;
/*0x688*/ int        TrackTimer;
/*0x68c*/ long       StartTrack;
/*0x690*/ int        bTrackPlayers;
/*0x694*/ bool       bTrackMercs;
/*0x695*/ bool       bTrackPets;
/*0x698*/ int        iTrackSortType;
/*0x69c*/ int        iTrackFilterType;
/*0x6a0*/ UINT       MouseTimer;
/*0x6a4*/ int        SoundUpdate;
/*0x6a8*/ bool       MouseOn;
/*0x6ac*/ USINGSKILL UsingSkill;
/*0x6b4*/ int        Unknown0x006bc[4];
/*0x6c4*/ BYTE       ClickThroughMask;
/*0x6c8*/ int        ShowSpellDescriptions;
/*0x6cc*/ bool       ReceivedWorldObjects;
/*0x6cd*/ BYTE       Unknown0x006d5;
/*0x6ce*/ bool       Unknown0x006d6;
/*0x6d0*/ float      SavedViewPitch;
/*0x6d4*/ int        SendPcReceived;
/*0x6d8*/ int        WeatherReceived;
/*0x6dc*/ int        PixelInit;
/*0x6e0*/ bool       bIsPressedShift;
/*0x6e1*/ bool       bIsPressedControl;
/*0x6e2*/ bool       bIsPressedAlt;
/*0x6e3*/ bool       bIsPressedLShift;
/*0x6e4*/ bool       bIsPressedLControl;
/*0x6e5*/ bool       bIsPressedLAlt;
/*0x6e6*/ bool       bIsPressedRShift;
/*0x6e7*/ bool       bIsPressedRControl;
/*0x6e8*/ bool       bIsPressedRAlt;
/*0x6ec*/ int        Currkeypress;
/*0x6f0*/ int        Lastkeypress;
/*0x6f4*/ int        Rateup;
/*0x6f8*/ int        Ratedown;
/*0x6fc*/ int        Rateforward;
/*0x700*/ int        Rateback;
/*0x704*/ int        Rateleft;
/*0x708*/ int        Rateright;
/*0x70c*/ int        RaceWar;
/*0x710*/ int        Ruleset;
/*0x714*/ bool       bRpServer;
/*0x715*/ bool       bAcceleratedServer;
/*0x716*/ bool       bProgressionServer;
/*0x718*/ int        ProgressionOpenExpansions;
/*0x71c*/ bool       bIsDevServer;
/*0x71d*/ bool       bIsBetaServer;
/*0x71e*/ bool       bIsTestServer;
/*0x71f*/ bool       bIsStageServer;
/*0x720*/ bool       bUseMailSystem;
/*0x721*/ bool       bIsEscapeServer;
/*0x722*/ bool       bIsTutorialEnabled;
/*0x723*/ bool       bCanCreateHeadStartCharacter;
/*0x724*/ bool       bCanCreateHeroicCharacter;
/*0x728*/ int        HeroicSlots;
/*0x72c*/ bool       bAutoIdentify;
/*0x72d*/ bool       bNameGen;
/*0x72e*/ bool       bGibberish;
/*0x730*/ int        Locale;
/*0x734*/ BYTE       UpdateControlled;
/*0x735*/ BYTE       UpdateLocal;
/*0x736*/ BYTE       EnterZone;
/*0x737*/ BYTE       ExitGame;
/*0x738*/ int        EnterZoneReason;
/*0x73c*/ bool       UseVoiceMacros;
/*0x740*/ int        Deltax;
/*0x744*/ int        Deltay;
/*0x748*/ int        OldRate1;
/*0x74c*/ int        OldRate2;
/*0x750*/ float      StrafeRate;
/*0x754*/ int        SaveIndex;
/*0x758*/ float      Unknown0x00760;
/*0x75c*/ // plus more ...
};
#pragma pack(pop)
using PEVERQUESTINFO = EVERQUESTINFO*;

// size 0x20 -- brainiac 11/14/2016
struct [[offsetcomments]] tp_coords
{
	FORCE_SYMBOLS;

/*0x00*/ int           Index;
/*0x04*/ float         Y;
/*0x08*/ float         X;
/*0x0c*/ float         Z;
/*0x10*/ float         Heading;
/*0x14*/ int           ZoneId;
/*0x18*/ int           FilterID;
/*0x1c*/ UINT          VehicleID;
/*0x20*/
};

} // namespace eqlib
