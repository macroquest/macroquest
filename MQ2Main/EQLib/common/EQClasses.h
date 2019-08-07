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

#include "../EQLib.h"

#include "Common.h"
#include "Items.h"
#include "SharedClasses.h"
#include "UI.h"

#include <limits>

#undef FindWindow
#undef InsertMenuItem

namespace eqlib {

class CMemoryStream;
class CVector3;

struct cTargetHeader
{
	int m_id;
	int m_timeNext;
	bool m_bComplete;
	short m_count;
};

struct cTargetBuff
{
	int slot;
	int spellId;
	int duration;            // in ticks...
	int count;
	char casterName[64];

	// not actually part of this packet but we need it for cachedbuffs map
	DWORD timeStamp;         // when the buffpacket arrived.
};
using PcTargetBuff = cTargetBuff*;

struct AggroMeterListEntry
{
	void*    vfTable;
	uint16_t AggroPct;
};
using PAggroMeterListEntry = AggroMeterListEntry*;

class AggroMeterManagerClient
{
public:
	static EQLIB_OBJECT AggroMeterManagerClient& Instance();

/*0x00*/ TSafeArrayStatic<AggroMeterListEntry, 0x1e> aggroData;
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

class CAltAbilityData
{
public:
	EQLIB_OBJECT int GetMercCurrentRank(int);
	EQLIB_OBJECT int GetMercMaxRank(int);
	EQLIB_OBJECT int GetMaxRank();
};

class AltAdvManager
{
public:
	EQLIB_OBJECT AltAdvManager();

	// IsAbilityReady was checked on apr 29 2016, it looks like it has 5 arguments in IDA, but it doesnt. (it has 4)
	EQLIB_OBJECT bool IsAbilityReady(PcZoneClient*, ALTABILITY*, int* Refresh/*out*/, int* Timer/*out*/ = 0);
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
class AssociatedSOIData
{
public:
/*0x000*/ char         Name[0x40];
/*0x040*/ uint32_t     SpawnID;
/*0x044*/ int          Cost;
/*0x048*/ int          IconnID;
/*0x04c*/
};

// we call this _AURAMGR
class ClientSOIManager
{
public:
	ArrayClass2_RO<AssociatedSOIData> Auras;

	static EQLIB_OBJECT ClientSOIManager* GetSingleton();
};

class EQGroundItem
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
class CBroadcast
{
public:
	static EQLIB_OBJECT CBroadcast* Get();
	EQLIB_OBJECT void BroadcastString(const CXStr cxStr, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
	EQLIB_OBJECT void BroadcastString(const char* Str, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
	EQLIB_OBJECT void EndBroadcast(UINT FadeOutTime);
	EQLIB_OBJECT void Draw();

	CTextObjectInterface* TextObject;
	bool               bBroadcastActive;
	bool               bFadingOut;
	bool               bFadingIn;
	UINT               StartTime;
	UINT               FadeInTime;
	UINT               EndTime;
	UINT               FadeOutTime;
	UINT               DisplayTime;
	int                BroadcastColor;
	int                CurrentPriority;
	int                MaxAlpha;
};

class CButtonTemplate
{
public:
	EQLIB_OBJECT CButtonTemplate(CParamButton*);

	// virtual
	EQLIB_OBJECT ~CButtonTemplate();
};

class ChatManagerClient
{
public:
	static EQLIB_OBJECT ChatManagerClient& Instance();
};


class CComboboxTemplate
{
public:
	EQLIB_OBJECT CComboboxTemplate(CParamCombobox*);
	// virtual
	EQLIB_OBJECT ~CComboboxTemplate();
};

class CScreenPieceTemplate
{
public:
/*0x00*/ void*         vfTable;
/*0x04*/ ArrayClass2_RO<uint32_t> RuntimeTypes;
/*0x20*/ CXStr         Name;
/*0x24*/ uint32_t      ParamObjectID;
/*0x28*/ CXStr         ScreenID;
/*0x2c*/ uint32_t      Font;
/*0x30*/ bool          bRelativePosition;
/*0x31*/ bool          bAutoStretchVertical;
/*0x32*/ bool          bAutoStretchHorizontal;
/*0x33*/ bool          bTopAnchorToTop;
/*0x34*/ bool          bBottomAnchorToTop;
/*0x35*/ bool          bLeftAnchorToLeft;
/*0x36*/ bool          bRightAnchorToLeft;
/*0x38*/ int           TopOffset;
/*0x3c*/ int           BottomOffset;
/*0x40*/ int           LeftOffset;
/*0x44*/ int           RightOffset;
/*0x48*/ int           MinVSize;
/*0x4c*/ int           MinHSize;
/*0x50*/ int           MaxVSize;
/*0x54*/ int           MaxHSize;
/*0x58*/ RECT          Rect;
/*0x68*/ CXStr         Text;
/*0x6c*/ D3DCOLOR      TextColor;
/*0x70*/ D3DCOLOR      DisabledColor;
/*0x74*/ D3DCOLOR      EnabledColor;
/*0x78*/ bool          bUseInLayoutHorizontal;
/*0x79*/ bool          bUseInLayoutVertical;
/*0x7c*/ D3DCOLOR      BackgroundTextureTint;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x80*/ D3DCOLOR      DisabledBackgroundTextureTint;
#endif
/*0x84*/

	EQLIB_OBJECT CScreenPieceTemplate(CParamScreenPiece*);
	EQLIB_OBJECT bool IsType(uint32_t) const;
	EQLIB_OBJECT CXStr GetName() const;

	// virtual
	EQLIB_OBJECT ~CScreenPieceTemplate();
};

class CControlTemplate : public CScreenPieceTemplate
{
public:
/*0x84*/ uint32_t      StyleBits;
/*0x88*/ BYTE          SizableMask;
/*0x89*/ bool          bEscapable;
/*0x8c*/ CXStr         Tooltip;
/*0x90*/ CXWndDrawTemplate* pDrawTemplate;
/*0x94*/ CXStr         Controller;
/*0x98*/ void*         pLayoutStrategyTemplate;  // CLayoutStrategyTemplate
/*0x9c*/

	EQLIB_OBJECT CControlTemplate(CParamControl*);

	// virtual
	EQLIB_OBJECT ~CControlTemplate();
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

class CDisplay
{
public:
/*0x0000*/ bool        ErrorFlag;
/*0x0004*/ BYTE        BFog;
/*0x0005*/ BYTE        BMoveAnims;
/*0x0008*/ float       Yon;
/*0x000c*/ float       AmbientLight;
/*0x0010*/ BYTE        DragItem;
/*0x0011*/ BYTE        DragMoney;
/*0x0012*/ BYTE        DragHotButton;
/*0x0013*/ bool        bInRenderLoop;
/*0x0014*/ bool        bHideLootedCorpses;
/*0x0015*/ char        LastTeleportAreaTag[0x100];
/*0x0118*/ void*       pCamera;                  // CCameraInterface
/*0x011c*/ CVector3*   CamPos;
/*0x0120*/ CVector3*   CamOrientation;
/*0x0124*/ void*       WadFileLoadScreen;        // SWadFile
/*0x0128*/ BYTE        NewPCModelsLoaded;
/*0x0129*/ bool        bHorsesLoaded;
/*0x012c*/ void*       pActorTagManager;
/*0x0130*/ BYTE        Unknown0x130[0x24];
/*0x0154*/ DWORD       TimeStamp;
/*0x0158*/ BYTE        Unknown0x158[0x2c12];
/*0x2d6a*/ BYTE        NpcNames;                 // show npc names

	EQLIB_OBJECT ~CDisplay();
	EQLIB_OBJECT CDisplay(HWND);
	EQLIB_OBJECT bool GenericSphereColl(float, float, float, float, float, float, float*, float*, float*, unsigned char);
	EQLIB_OBJECT bool SlideSwitchLeftRight(EQSwitch*, float, int, float);
	EQLIB_OBJECT bool const GetWorldFilePath(char*, const char*);
	EQLIB_OBJECT char* GetIniRaceName(int);
	EQLIB_OBJECT PlayerClient* GetNearestPlayerInView(float, bool);
	EQLIB_OBJECT float FindZoneTopZ(float, float, float);
	EQLIB_OBJECT float FixHeading(float);
	EQLIB_OBJECT float GetFloorHeight(float X, float Y, float F, float Radius = 0.0f, CVector3& CollisionVector = CVector3(-1, -1, 1), CActorApplicationData* pAppData = 0, EActorType eActorType = Undefined, float ZOffset = 1.0f);
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
	EQLIB_OBJECT void HandleMaterial(EQ_PC*, int, EQ_Item*, EQ_Item*);
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

class CEditboxTemplate
{
public:
	EQLIB_OBJECT CEditboxTemplate(class CParamEditbox*);
	// virtual
	EQLIB_OBJECT ~CEditboxTemplate();
};

class UniversalChatProxy
{
public:
	EQLIB_OBJECT char* GetChannelName(int channelNumber);
};

struct TARGETRING
{
/*0x00*/ DWORD         Gem;                      // the gem the spell below is memmed in... 0-11
/*0x04*/ PSPELL        thespell;
/*0x08*/ ItemGlobalIndex ItemLoc;
/*0x14*/ ItemSpellTypes SpellType;
/*0x18*/ float         SquaredRange;
/*0x1c*/ bool          bCursorVisible;
/*0x20*/
};
using PTARGETRING = TARGETRING*;

struct EQSuccessfulHit
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
	EQLIB_OBJECT char* GetClassDesc(int);
	EQLIB_OBJECT char* GetClassThreeLetterCode(int);
	EQLIB_OBJECT char* GetDeityDesc(int);
	EQLIB_OBJECT char* GetInnateDesc(int);
	EQLIB_OBJECT char* GetItemClassDesc(int);
	EQLIB_OBJECT char* GetLangDesc(int);
	EQLIB_OBJECT char* GetRaceDesc(int);
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
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT void dsp_chat(const char *line, int color = 273, bool bLogIsOk = true, bool bConvertPercent = true, char*SomeStr = NULL);
#else
	EQLIB_OBJECT void dsp_chat(const char *line, int color, bool bLogIsOk, bool bConvertPercent);
#endif
	EQLIB_OBJECT void dsp_chat(const char*, int, bool);
	EQLIB_OBJECT void Emote();
	EQLIB_OBJECT void EnterZone(HWND);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT int Follow(int);
#else
	EQLIB_OBJECT int Follow();
#endif
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
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT void IssuePetCommand(ePetCommandType, int TargetID, bool bQuiet, bool bsomethingelse = 1);
#else
	EQLIB_OBJECT void IssuePetCommand(ePetCommandType, int TargetID, bool bQuiet);
#endif
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

class CGaugeTemplate
{
public:
	EQLIB_OBJECT CGaugeTemplate(CParamGauge*);

	// virtual
	EQLIB_OBJECT ~CGaugeTemplate();
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
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT char* GetGuildName(int64_t);
	EQLIB_OBJECT int64_t GetGuildIndex(char*);
#else
	EQLIB_OBJECT char* GetGuildName(DWORD);
	EQLIB_OBJECT int  GetGuildIndex(char*);
#endif
	EQLIB_OBJECT GuildMember* FindMemberByName(char*);
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


struct CompAttr;

class CInvSlotTemplate
{
public:
	EQLIB_OBJECT CInvSlotTemplate(CParamInvSlot*);

	// virtual
	EQLIB_OBJECT ~CInvSlotTemplate();
};



class CLabelTemplate : public CControlTemplate
{
public:
	EQLIB_OBJECT CLabelTemplate(CParamLabel*);
	// virtual
	EQLIB_OBJECT ~CLabelTemplate();
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

class CListboxColumnTemplate
{
public:
	EQLIB_OBJECT CListboxColumnTemplate(CParamListboxColumn*);
	EQLIB_OBJECT ~CListboxColumnTemplate();
};

class CListboxTemplate
{
public:
	EQLIB_OBJECT CListboxTemplate(CParamListbox*);

	// virtual
	EQLIB_OBJECT ~CListboxTemplate();
};


struct sell_msg;





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


class CPageTemplate
{
public:
	EQLIB_OBJECT CPageTemplate(CParamPage*);

	// virtual
	EQLIB_OBJECT ~CPageTemplate();
};



class CParam
{
public:
	EQLIB_OBJECT CParam& operator=(const CParam&);

	// virtual
	EQLIB_OBJECT ~CParam();
};

class CParamButton
{
public:
	EQLIB_OBJECT CParamButton();
	EQLIB_OBJECT CParamButton& operator=(const CParamButton&);

	// virtual
	EQLIB_OBJECT ~CParamButton();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamButtonDrawTemplate
{
public:
	EQLIB_OBJECT CParamButtonDrawTemplate();
	EQLIB_OBJECT CParamButtonDrawTemplate& operator=(const CParamButtonDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamButtonDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamClass
{
public:
	EQLIB_OBJECT CParamClass();
	EQLIB_OBJECT CParamClass& operator=(const CParamClass&);

	// virtual
	EQLIB_OBJECT ~CParamClass();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamCombobox
{
public:
	EQLIB_OBJECT CParamCombobox();
	EQLIB_OBJECT CParamCombobox& operator=(const CParamCombobox&);

	// virtual
	EQLIB_OBJECT ~CParamCombobox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamControl
{
public:
	EQLIB_OBJECT CParamControl();
	EQLIB_OBJECT CParamControl& operator=(const CParamControl&);

	// virtual
	EQLIB_OBJECT ~CParamControl();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamEditbox
{
public:
	EQLIB_OBJECT CParamEditbox();
	EQLIB_OBJECT CParamEditbox& operator=(const CParamEditbox&);

	// virtual
	EQLIB_OBJECT ~CParamEditbox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamFrame
{
public:
	EQLIB_OBJECT CParamFrame();

	// virtual
	EQLIB_OBJECT ~CParamFrame();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamFrameTemplate
{
public:
	EQLIB_OBJECT CParamFrameTemplate();
	EQLIB_OBJECT CParamFrameTemplate& operator=(const CParamFrameTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamFrameTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamGauge
{
public:
	EQLIB_OBJECT CParamGauge();
	EQLIB_OBJECT CParamGauge& operator=(const CParamGauge&);

	// virtual
	EQLIB_OBJECT ~CParamGauge();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamGaugeDrawTemplate
{
public:
	EQLIB_OBJECT CParamGaugeDrawTemplate();
	EQLIB_OBJECT CParamGaugeDrawTemplate& operator=(const CParamGaugeDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamGaugeDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamInvSlot
{
public:
	EQLIB_OBJECT CParamInvSlot();
	EQLIB_OBJECT CParamInvSlot& operator=(const CParamInvSlot&);

	// virtual
	EQLIB_OBJECT ~CParamInvSlot();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamLabel
{
public:
	EQLIB_OBJECT CParamLabel();
	EQLIB_OBJECT CParamLabel& operator=(const CParamLabel&);

	// virtual
	EQLIB_OBJECT ~CParamLabel();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamListbox
{
public:
	EQLIB_OBJECT CParamListbox();
	EQLIB_OBJECT CParamListbox& operator=(const CParamListbox&);

	// virtual
	EQLIB_OBJECT ~CParamListbox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamListboxColumn
{
public:
	EQLIB_OBJECT CParamListboxColumn();
	EQLIB_OBJECT CParamListboxColumn& operator=(const CParamListboxColumn&);

	// virtual
	EQLIB_OBJECT ~CParamListboxColumn();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamPage
{
public:
	EQLIB_OBJECT CParamPage();
	EQLIB_OBJECT CParamPage& operator=(const CParamPage&);

	// virtual
	EQLIB_OBJECT ~CParamPage();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamPoint
{
public:
	EQLIB_OBJECT CParamPoint();
	EQLIB_OBJECT CParamPoint& operator=(const CParamPoint&);

	// virtual
	EQLIB_OBJECT ~CParamPoint();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamRGB
{
public:
	EQLIB_OBJECT CParamRGB();
	EQLIB_OBJECT CParamRGB& operator=(const CParamRGB&);

	// virtual
	EQLIB_OBJECT ~CParamRGB();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamScreen
{
public:
	EQLIB_OBJECT CParamScreen();
	EQLIB_OBJECT CParamScreen& operator=(const CParamScreen&);

	// virtual
	EQLIB_OBJECT ~CParamScreen();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamScreenPiece
{
public:
	EQLIB_OBJECT CParamScreenPiece();
	EQLIB_OBJECT CParamScreenPiece& operator=(const CParamScreenPiece&);

	// virtual
	EQLIB_OBJECT ~CParamScreenPiece();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamLayoutStrategy;

class CParamScrollbarDrawTemplate
{
public:
	EQLIB_OBJECT CParamScrollbarDrawTemplate();
	EQLIB_OBJECT CParamScrollbarDrawTemplate& operator=(const CParamScrollbarDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamScrollbarDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSize
{
public:
	EQLIB_OBJECT CParamSize();
	EQLIB_OBJECT CParamSize& operator=(const CParamSize&);

	// virtual
	EQLIB_OBJECT ~CParamSize();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSlider
{
public:
	EQLIB_OBJECT CParamSlider();
	EQLIB_OBJECT CParamSlider& operator=(const CParamSlider&);

	// virtual
	EQLIB_OBJECT ~CParamSlider();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSliderDrawTemplate
{
public:
	EQLIB_OBJECT CParamSliderDrawTemplate();
	EQLIB_OBJECT CParamSliderDrawTemplate& operator=(const CParamSliderDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamSliderDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSpellGem
{
public:
	EQLIB_OBJECT CParamSpellGem();
	EQLIB_OBJECT CParamSpellGem& operator=(const CParamSpellGem&);

	// virtual
	EQLIB_OBJECT ~CParamSpellGem();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSpellGemDrawTemplate
{
public:
	EQLIB_OBJECT CParamSpellGemDrawTemplate();
	EQLIB_OBJECT CParamSpellGemDrawTemplate& operator=(const CParamSpellGemDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamSpellGemDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticAnimation
{
public:
	EQLIB_OBJECT CParamStaticAnimation();
	EQLIB_OBJECT CParamStaticAnimation& operator=(const CParamStaticAnimation&);

	// virtual
	EQLIB_OBJECT ~CParamStaticAnimation();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticFrame
{
public:
	EQLIB_OBJECT CParamStaticFrame();
	EQLIB_OBJECT CParamStaticFrame& operator=(const CParamStaticFrame&);

	// virtual
	EQLIB_OBJECT ~CParamStaticFrame();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticHeader
{
public:
	EQLIB_OBJECT CParamStaticHeader();
	EQLIB_OBJECT CParamStaticHeader& operator=(const CParamStaticHeader&);

	// virtual
	EQLIB_OBJECT ~CParamStaticHeader();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticScreenPiece
{
public:
	EQLIB_OBJECT CParamStaticScreenPiece();

	// virtual
	EQLIB_OBJECT ~CParamStaticScreenPiece();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticText
{
public:
	EQLIB_OBJECT CParamStaticText();
	EQLIB_OBJECT CParamStaticText& operator=(const CParamStaticText&);

	// virtual
	EQLIB_OBJECT ~CParamStaticText();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSTMLbox
{
public:
	EQLIB_OBJECT CParamSTMLbox();

	// virtual
	EQLIB_OBJECT ~CParamSTMLbox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSuiteDefaults
{
public:
	EQLIB_OBJECT CParamSuiteDefaults();
	EQLIB_OBJECT CParamSuiteDefaults& operator=(const CParamSuiteDefaults&);

	// virtual
	EQLIB_OBJECT ~CParamSuiteDefaults();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamTabBox
{
public:
	EQLIB_OBJECT CParamTabBox();
	EQLIB_OBJECT CParamTabBox& operator=(const CParamTabBox&);


	// virtual
	EQLIB_OBJECT ~CParamTabBox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamTextureInfo
{
public:
	EQLIB_OBJECT CParamTextureInfo();

	// virtual
	EQLIB_OBJECT ~CParamTextureInfo();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamUi2DAnimation
{
public:
	EQLIB_OBJECT CParamUi2DAnimation();

	// virtual
	EQLIB_OBJECT ~CParamUi2DAnimation();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamWindowDrawTemplate
{
public:
	EQLIB_OBJECT CParamWindowDrawTemplate();

	// virtual
	EQLIB_OBJECT ~CParamWindowDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

struct RaidAddMember;
struct SCRaidMessage;
struct CreateRaidMessage;
struct RenameRaidMember;
struct RaidMember;

class CRaid
{
public:
	EQLIB_OBJECT ~CRaid();
	EQLIB_OBJECT CRaid();
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

class CScreenTemplate
{
public:
	EQLIB_OBJECT CScreenTemplate(CParamScreen*);

	// virtual
	EQLIB_OBJECT ~CScreenTemplate();
};

class CScrollbarTemplate
{
public:
	EQLIB_OBJECT ~CScrollbarTemplate();
	EQLIB_OBJECT CScrollbarTemplate(const CScrollbarTemplate&);
	EQLIB_OBJECT CScrollbarTemplate();
	EQLIB_OBJECT CScrollbarTemplate& operator=(const CScrollbarTemplate&);
};







class CSliderDrawTemplate
{
public:
	EQLIB_OBJECT ~CSliderDrawTemplate();
};

class CSliderTemplate
{
public:
	EQLIB_OBJECT CSliderTemplate(CParamSlider*);

	// virtual
	EQLIB_OBJECT ~CSliderTemplate();
};


class CSpellGemTemplate
{
public:
	EQLIB_OBJECT CSpellGemTemplate(CParamSpellGem*);
	// virtual
	EQLIB_OBJECT ~CSpellGemTemplate();
};

class CStaticAnimationTemplate
{
public:
	EQLIB_OBJECT CStaticAnimationTemplate(CParamStaticAnimation*);

	// virtual
	EQLIB_OBJECT ~CStaticAnimationTemplate();
};

class CStaticFrameTemplate
{
public:
	EQLIB_OBJECT CStaticFrameTemplate(CParamStaticFrame*);

	// virtual
	EQLIB_OBJECT ~CStaticFrameTemplate();
};

class CStaticHeaderTemplate
{
public:
	EQLIB_OBJECT CStaticHeaderTemplate(CParamStaticHeader*);

	// virtual
	EQLIB_OBJECT ~CStaticHeaderTemplate();
};

class CStaticScreenPieceTemplate
{
public:
	EQLIB_OBJECT CStaticScreenPieceTemplate(CParamStaticScreenPiece*);

	// virtual
	EQLIB_OBJECT ~CStaticScreenPieceTemplate();
};

class CStaticTextTemplate
{
public:
	EQLIB_OBJECT CStaticTextTemplate(CParamStaticText*);
	EQLIB_OBJECT const CXStr& SetText(const CXStr&);

	// virtual
	EQLIB_OBJECT ~CStaticTextTemplate();
};

class CSTMLboxTemplate
{
public:
	EQLIB_OBJECT CSTMLboxTemplate(CParamSTMLbox*);

	// virtual
	EQLIB_OBJECT ~CSTMLboxTemplate();
};


class CTabBoxTemplate
{
public:
	EQLIB_OBJECT CTabBoxTemplate(CParamTabBox*);

	// virtual
	EQLIB_OBJECT ~CTabBoxTemplate();
};




class CTargetManager
{
public:
	EQLIB_OBJECT static CTargetManager* Get();
	EQLIB_OBJECT void Update();
};

class CTargetRing
{
public:
	EQLIB_OBJECT int Cast(CVector3* pos);

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

struct CTaskElement
{
/*0x000*/ TaskType           Type;
/*0x004*/ TaskGroupType      GroupType;
/*0x008*/ char               TargetName[0x40];
/*0x048*/ char               ZoneID[0x40];
/*0x088*/ char               TargetZoneID[0x40];
/*0x0c8*/ int                RequiredCount;
/*0x0cc*/ bool               bOptional;
/*0x0d0*/ int                ElementGroup;
/*0x0d4*/ int                DZSwitchID;
/*0x0d8*/ char               ElementDescriptionOverride[0x80];
/*0x158*/ CXStr              ItemNameList;
/*0x15c*/ CXStr              SkillIDList;
/*0x160*/ CXStr              SpellIDList;
/*0x164*/ CXStr              TaskTitle;
/*0x168*/
};

struct CTaskEntry
{
/*0x0000*/ int               TaskID;
/*0x0004*/ float             RewardAdjustment;
/*0x0008*/ char              TaskTitle[0x40];
/*0x0048*/ int               DurationSeconds;
/*0x004C*/ int               DurCode;
/*0x0050*/ char              StartText[0xFa0];
/*0x0FF0*/ bool              bShowReward;
/*0x0FF4*/ int               RewardCash;
/*0x0FF8*/ int               RewardExp;
/*0x0FFC*/ int               RewardPoints;
/*0x1000*/ int               RewardFactionID;
/*0x1004*/ int               RewardFactionAmount;
/*0x1008*/ CXStr             RewardItemTag;
/*0x100C*/ CTaskElement      Elements[0x14];
/*0x2C2C*/ int               TaskSystem;
/*0x2C30*/ int               PointType;
/*0x2C34*/ bool              StartTextCompiled;
/*0x0000*/ char              RawStartText[0xFa0];
/*0x0000*/ bool              bElementsReceived;
/*0x0000*/ __time32_t        TimeCompleted;
/*0x3BDC*/ ArrayClass_RO<MonsterMissionTemplate> MonsterTemplates;
/*0x3BEC*/ bool              bTemplateSelectionLocked;
/*0x3BED*/ bool              bHasRewardSet;
/*0x3BF0*/
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

class CTaskManager : public PopDialogHandler
{
public:
/*0x000004*/ CTaskEntry                TaskEntries[1];
/*0x003BF4*/ CTaskEntry                QuestEntries[0x1d];
/*0x070624*/ CTaskEntry                SharedTaskEntries[1];
/*0x074214*/ CTaskEntry                QuestHistoryEntries[0x32];
/*0x12F6F4*/ int                       AddPlayerID;
/*0x12F6F8*/ bool                      bAddPlayerIsSwap;
/*0x12F6FC*/ char                      AddPlayerSwapeeName[0x40];
/*0x12F73C*/ SharedTaskClientPlayerInfo* pFirstMember;
/*0x12F740*/

	EQLIB_OBJECT CTaskManager(CXWnd*);

	// virtual
	EQLIB_OBJECT ~CTaskManager();
	EQLIB_OBJECT CTaskEntry* GetEntry(int Index, int System, bool bCheckEmpty = true);
};

class CXMLData
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
/*0x0C*/ DWORD         Unknown0x0C;             // no idea yet, some number but not unique
/*0x10*/ DWORD         Unknown0x10;             // always -1
/*0x14*/ CXStr         TypeName;                // "Screen" (control type)
/*0x18*/ CXStr         Name;                    // "ChatWindow"  control name (used only for Screen)
/*0x1C*/ DWORD         Unknown0x1C;             // always null
/*0x20*/ CXStr         ScreenID;                // ScreenID (used only within Screen)
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


class CXMLSOMElement
{
public:
	CXStr elementName;
	CXStr typeRef;
	CXStr typeRefClassName;
	CXStr typeRefItemName;
	int minOccurs;
	int maxOccurs;
	CXStr defaultValue;
	bool internal;

	bool isArrayC;
	bool isEnumC;
	CXStr typeNameC;
	CXStr fieldNameC;
	CXStr streamNameC;
};

class CXMLSOMElementType
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

	CXStr typeName;
	CXStr superType;
	ArrayClass2<CXMLSOMAttributeType> attributeTypes;
	ArrayClass2<CXMLSOMElement> elements;
	ArrayClass2<CXStr> itemList;

	CXStr classNameC;
	CXStr baseClassNameC;

	CXStr jsName;

	CXStr sourceFile;
	int sourceLine;
};

enum EXMLSOMNodeType
{
	XMLSOMNode,
	XMLSOMComment,
	XMLSOMProcess,
};

class CXMLSOMNode
{
public:
	EXMLSOMNodeType nodeType;
	CXStr nodeName;
	CXStr nodeValue;
	ArrayClass2<CXMLSOMAttribute> attributeList;
	ArrayClass2<CXMLSOMNodePtr> nodeList;
	CXStr sourceFile;
	int sourceLine;
	int refCount;
};

// this is an intrusive reference counted pointer of CXMLSOMNode
class CXMLSOMNodePtr
{
public:
	CXMLSOMNode* pNode;
};

class CXMLSOMParser
{
public:
	EQLIB_OBJECT ~CXMLSOMParser();
	EQLIB_OBJECT bool ParseFile(CXStr);

	// protected
	EQLIB_OBJECT bool ParseDocument();
	EQLIB_OBJECT bool ParseEndTag(CXStr);
	EQLIB_OBJECT bool ParseNameSpaceToken(CXStr&);
	EQLIB_OBJECT bool ParseNode();
	EQLIB_OBJECT bool ParseNodeList();
	EQLIB_OBJECT bool ParseProcess();
	EQLIB_OBJECT bool ParseStartTag(bool &);
};

class CXMLSOMSchema
{
public:
	EQLIB_OBJECT ~CXMLSOMSchema();
	EQLIB_OBJECT CXMLSOMSchema();
	EQLIB_OBJECT bool AddItem(CXStr, CXStr);
	EQLIB_OBJECT bool FindElementType(CXStr);
	EQLIB_OBJECT bool FindItem(CXStr, CXStr);
	EQLIB_OBJECT bool FindSimpleType(CXStr);
	EQLIB_OBJECT bool IsDerivedFrom(CXStr, CXStr);
	EQLIB_OBJECT int GetElementTypeIdx(CXStr);
};

class CXMLSOMSimpleType
{
public:
	CXStr simpleName;
	CXStr baseRef;
	ArrayClass2<CXStr> allowedValues;

	CXStr typeNameC;
	CXStr streamNameC;
};

class CXWndDrawTemplate
{
public:
	EQLIB_OBJECT ~CXWndDrawTemplate();
	EQLIB_OBJECT CXWndDrawTemplate(const CXWndDrawTemplate&);
	EQLIB_OBJECT CXWndDrawTemplate();
	EQLIB_OBJECT CXWndDrawTemplate& operator=(const CXWndDrawTemplate&);
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

class EQ_Affect
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
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x10*/ int           MaxDuration;
/*0x14*/ int           Duration3;
/*0x18*/ EqGuid        CasterGuid;
#else
/*0x10*/ int           CasterID;
#endif
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

// This is also CharacterZoneClient
class EQ_Character1
{
public:
	EQLIB_OBJECT int GetEnduranceRegen(bool bIncItemsAndBuffs, bool bCombat);
	EQLIB_OBJECT int GetHPRegen(bool bIncItemsAndBuffs, bool*bIsBleeding/*no you shouldnt set this, its an OUT value.*/, bool bCombat);
	EQLIB_OBJECT int GetManaRegen(bool bIncItemsAndBuffs, bool bCombat);
	EQLIB_OBJECT int Cur_HP(int Spawntype/*PC = 0 NPC=1 and so on*/, bool bCapAtMax=true);
	EQLIB_OBJECT int Max_Endurance(bool bCapAtMax=true);
	EQLIB_OBJECT int Max_HP(int SpawnType, bool bCapAtMax=true);
	EQLIB_OBJECT int Max_Mana(bool bCapAtMax=true);
	EQLIB_OBJECT const int GetCastingTimeModifier(const EQ_Spell* pSpell);//used to get aa modifiers
	EQLIB_OBJECT const int GetFocusCastingTimeModifier(const EQ_Spell*pSpell, VePointer<CONTENTS>&pItemOut, bool bEvalOnly = false);
	// int const GetFocusCastingTimeModifier(class EQ_Spell const*, class EQ_Equipment**, int);
	EQLIB_OBJECT unsigned char CastSpell(unsigned char gemid, int spellid, EQ_Item**ppItem, CEQItemLocation* ppitemloc, ItemSpellTypes slot, unsigned char spell_loc, int arg7, int arg8, int arg9, bool arg10);
	EQLIB_OBJECT void SetEffectId(unsigned char, unsigned int);
	EQLIB_OBJECT void StopSpellCast(unsigned char);
	EQLIB_OBJECT void StopSpellCast(unsigned char, int);
	EQLIB_OBJECT void StunMe(unsigned int, bool, bool, bool);
	EQLIB_OBJECT void UnStunMe();
	EQLIB_OBJECT void UseSkill(unsigned char skill, PlayerZoneClient* Target, bool bAuto = false);
	EQLIB_OBJECT const int GetFocusRangeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut);
	EQLIB_OBJECT int IsExpansionFlag(int);
	EQLIB_OBJECT int TotalEffect(int spaID, bool bIncludeItems = true, int subindex = 0, bool bIncludeAA = true, bool bincludeBuffs = true);
	EQLIB_OBJECT int GetAdjustedSkill(int);
	EQLIB_OBJECT int GetBaseSkill(int);
	EQLIB_OBJECT bool CanUseItem(PCONTENTS*pItem, bool bUseRequiredLvl, bool bOutput);
};

class HateListEntry;

// This is CharacterZoneClient now
class EQ_Character
{
public:
	EQLIB_OBJECT ~EQ_Character();
	EQLIB_OBJECT EQ_Character();
	EQLIB_OBJECT bool DoesSpellMatchFocusFilters(EQ_Spell const*, EQ_Spell const*);
	EQLIB_OBJECT bool IsSpellTooPowerfull(EQ_Spell*, EQ_Character*);
	EQLIB_OBJECT bool CanUseMemorizedSpellSlot(int gem);
	EQLIB_OBJECT bool IsValidAffect(int);
	EQLIB_OBJECT char* Class(int);
	EQLIB_OBJECT char* KunarkClass(int, int, int, bool);
	EQLIB_OBJECT char* Race(int);
	EQLIB_OBJECT EQ_Affect& GetEffect(int);
	EQLIB_OBJECT EQ_Affect* GetPCSpellAffect(int theaffect, int*slotnum, int*spaslot = NULL) const;
	EQLIB_OBJECT EQ_Equipment* GetFocusItem(EQ_Spell const*, int);
	EQLIB_OBJECT EQ_Spell* GetFocusEffect(EQ_Spell const*, int);
	EQLIB_OBJECT PlayerClient* FindClosest(int, int, int, int, int);
	EQLIB_OBJECT PlayerClient* GetMyPetPlayer();
	EQLIB_OBJECT float encum_factor();
	EQLIB_OBJECT int ac(bool);
	EQLIB_OBJECT int Agi();
	EQLIB_OBJECT int AntiTwinkAdj(EQ_Equipment*, int, int);
	EQLIB_OBJECT int ApplyDamage(int, EQMissileHitinfo*, bool, HateListEntry*, bool);
	EQLIB_OBJECT int ApplyFatigue(int);
	EQLIB_OBJECT int AutoEat(unsigned char);
	EQLIB_OBJECT int BaneDamage(EQ_Equipment*);
	EQLIB_OBJECT int BardCastBard(EQ_Spell const*, int) const;
	EQLIB_OBJECT int basesave_cold();
	EQLIB_OBJECT int basesave_disease();
	EQLIB_OBJECT int basesave_fire();
	EQLIB_OBJECT int basesave_magic();
	EQLIB_OBJECT int basesave_poison();
	EQLIB_OBJECT int CalculateBardSongMod(int);
	EQLIB_OBJECT int CapStat(int, int);
	EQLIB_OBJECT int Cha();
	EQLIB_OBJECT int CheckFoodAndWater();
	EQLIB_OBJECT int compute_defense();
	EQLIB_OBJECT int compute_tohit(unsigned char);
	EQLIB_OBJECT int cur_encumbrance();
	EQLIB_OBJECT int Cur_Mana(bool bCapAtMax = true);
	EQLIB_OBJECT int defense_agility_bonus();
	EQLIB_OBJECT int Dex();
	EQLIB_OBJECT int ElementResistDmg(EQ_Equipment*, int);
	EQLIB_OBJECT int eqspa_change_form(EQ_Spell*, int, int, EQ_Affect*);
	EQLIB_OBJECT int eqspa_hp(unsigned int, EQ_Affect*, int, EQ_Spell*);
	EQLIB_OBJECT int GetBardInstrumentMod(int);
	EQLIB_OBJECT int GetClassACBonus(int);
	EQLIB_OBJECT int GetFirstEffectSlot(bool);
	EQLIB_OBJECT int GetHPFromStamina(int);
	EQLIB_OBJECT int GetIndexSkillMinDamageMod(int);
	EQLIB_OBJECT int GetLastEffectSlot(bool);
	EQLIB_OBJECT int GetOpenEffectSlot(bool, int);
	EQLIB_OBJECT int HasInnateSkill(unsigned char, int);
	EQLIB_OBJECT int HasSkill(unsigned char);
	EQLIB_OBJECT int HasSpell(int);
	EQLIB_OBJECT int IHaveSkill(unsigned char);
	EQLIB_OBJECT int InSpecialBindSpot(PlayerZoneClient*);
	EQLIB_OBJECT int Int();
	EQLIB_OBJECT int IsMage();
	EQLIB_OBJECT int IsSpecialBazaarSpot(PlayerZoneClient*);
	EQLIB_OBJECT int IsSpellcaster();
	EQLIB_OBJECT int ItemSpellAffects(int);
	EQLIB_OBJECT int max_encumbrance();
	EQLIB_OBJECT int NoBashMe(int);
	EQLIB_OBJECT int NoMezMe(int, PlayerZoneClient*, EQ_Spell*);
	EQLIB_OBJECT int offense(unsigned char);
	EQLIB_OBJECT int ProcessAffects();
	EQLIB_OBJECT int save_bash(int);
	EQLIB_OBJECT int save_cold();
	EQLIB_OBJECT int save_disease();
	EQLIB_OBJECT int save_fire();
	EQLIB_OBJECT int save_magic();
	EQLIB_OBJECT int save_poison();
	EQLIB_OBJECT int SetLocalVar(char*, int);
	EQLIB_OBJECT int Skill(int);
	EQLIB_OBJECT int SpellDuration(EQ_Spell const*, unsigned char, unsigned char);
	EQLIB_OBJECT int Sta();
	EQLIB_OBJECT int Str();
	EQLIB_OBJECT int TakeFallDamage(float);
	EQLIB_OBJECT int TotalSpellAffects(unsigned char, bool, int*);
	EQLIB_OBJECT int Wis();
	EQLIB_OBJECT int const GetFocusConserveRegChance(const EQ_Spell*, EQ_Equipment**);
	EQLIB_OBJECT long TotalOnPerson();
	EQLIB_OBJECT static int normal_to_special(int);
	EQLIB_OBJECT unsigned char BarbarianCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char BaseAttr(int, unsigned char);
	EQLIB_OBJECT unsigned char CanDoubleAttack(PlayerZoneClient*, unsigned char);
	EQLIB_OBJECT unsigned char CanIBreathe();
	EQLIB_OBJECT unsigned char CanISeeInvis();
	EQLIB_OBJECT unsigned char CanMedOnHorse();
	EQLIB_OBJECT unsigned char CanSecondaryAttack(PlayerZoneClient*);
	EQLIB_OBJECT unsigned char CanWorship(int, int, unsigned char);
	EQLIB_OBJECT unsigned char CastingRequirementsMet(int);
	EQLIB_OBJECT unsigned char CheckClass(int, int);
	EQLIB_OBJECT unsigned char CityCanStart(int, int, int, int);
	EQLIB_OBJECT unsigned char ClassMin(int, int, unsigned char);
	EQLIB_OBJECT unsigned char DarkElfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char DwarfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char ElfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char EruditeCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char ExpendItemCharge(int, int);
	EQLIB_OBJECT unsigned char FindItemByClass(int, int*, int*);
	EQLIB_OBJECT unsigned char FindItemQty(int, int);
	EQLIB_OBJECT unsigned char FroglockCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char GetSkillBaseDamage(unsigned char, PlayerZoneClient*);
	EQLIB_OBJECT unsigned char GnomeCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char HalfElfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char HalflingCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char HighElfCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char HumanCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char IksarCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char IsSpellAffectingPC(int, int);
	EQLIB_OBJECT unsigned char LaunchSpell(unsigned char, int, EQ_Item**);
	EQLIB_OBJECT unsigned char OgreCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char SpellFizzled(unsigned char, EQ_Spell*);
	EQLIB_OBJECT unsigned char TrollCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT unsigned char VahShirCanWorship(unsigned char, unsigned char);
	EQLIB_OBJECT void CalcFoodDrinkBonus(int);
	EQLIB_OBJECT void DoFishingEvent();
	EQLIB_OBJECT void DoIntimidationEvent();
	EQLIB_OBJECT void DoLight(unsigned char);
	EQLIB_OBJECT void DoMeditation();
	EQLIB_OBJECT void DoPassageOfTime();
	EQLIB_OBJECT void EQ_CharacterResetAllMembers();
	EQLIB_OBJECT void EQSPA_Feign_Death(int);
	EQLIB_OBJECT void eqspa_levitation();
	EQLIB_OBJECT void eqspa_locate_corpse();
	EQLIB_OBJECT void eqspa_movement_rate(int);
	EQLIB_OBJECT void HandleSpecialPCAffects(int);
	EQLIB_OBJECT void HitBySpell(EQMissileHitinfo*);
	EQLIB_OBJECT void IAmDead(EQMissileHitinfo*, int);
	EQLIB_OBJECT void InitInnates(unsigned int, unsigned int);
	EQLIB_OBJECT void InitMyLanguages();
	EQLIB_OBJECT void InitSkills(unsigned char, unsigned int);
	EQLIB_OBJECT void ItemSold(long);
#if defined(ROF2EMU) || defined(UFEMU)
	EQLIB_OBJECT void ModifyCurHP(int modification, PlayerZoneClient* resposibleplayer, int skilltype);
#else
	EQLIB_OBJECT void ModifyCurHP(int64_t modification, PlayerZoneClient* resposibleplayer, int skilltype);
#endif
	EQLIB_OBJECT void NotifyPCAffectChange(int, int);
	EQLIB_OBJECT void ProcessAllStats();
	EQLIB_OBJECT void ProcessEnvironment();
	EQLIB_OBJECT void ProcessHungerandThirst(unsigned int);
	EQLIB_OBJECT void RemovePCAffect(EQ_Affect*);
	EQLIB_OBJECT void RemovePCAffectex(EQ_Affect*, int);
	EQLIB_OBJECT void ResetCur_HP(int);
	EQLIB_OBJECT void UpdateMyVisibleStatus();
	EQLIB_OBJECT bool DoCombatAbility(int spellID, int dummy=1);

	// PcClient::ConsiderTarget
	EQLIB_OBJECT unsigned long GetConLevel(const PlayerClient*);

	// private
	EQLIB_OBJECT int GetCachEQSPA(int);
	EQLIB_OBJECT void ReCachItemEffects();
	EQLIB_OBJECT void ReCachSpellEffects();
};

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
	eMount,
	eIllusion,
	eFamiliar,
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
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT char* CreateItemTagString(char*, int, bool bFlag = true); // SwiftyMUSE 11-09-2018
#else
	EQLIB_OBJECT char* CreateItemTagString(char*, int); // Lax 11-14-2003
#endif
	EQLIB_OBJECT bool CanDrop(bool bDisplayText = false, bool bIncludeContainedItems = true, bool bAllowOverrideNoDropCheck = false, bool bCantDropIfContainingRealEstate = true) const;
	EQLIB_OBJECT int GetImageNum() const;
	EQLIB_OBJECT static VePointer<CONTENTS> CreateItemClient(PBYTE*, DWORD);
	EQLIB_OBJECT int GetItemValue(bool) const;
	EQLIB_OBJECT bool IsKeyRingItem(KeyRingType type) const;
	EQLIB_OBJECT bool CanGoInBag(PCONTENTS*pCont, int OutputText = 0, bool mustbefalse = false) const;
	EQLIB_OBJECT bool IsEmpty() const;
	EQLIB_OBJECT int GetMaxItemCount() const;
	EQLIB_OBJECT int GetAugmentFitBySlot(PCONTENTS* Aug, int Slot, bool bCheckSlot = true, bool bCheckDup = true) const;

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

struct ItemContainingRealEstate
{
	int                RealEstateID;
	ItemGlobalIndex    ItemLocation;
};

// This is now PcZoneClient. Most of this class is defunct
class EQ_PC
{
public:
	EQLIB_OBJECT ~EQ_PC();
	EQLIB_OBJECT EQ_PC(EQ_PC*);
	EQLIB_OBJECT int BitchCanTrain(int, int, int);
	EQLIB_OBJECT int CheckDupLoreItems();
	EQLIB_OBJECT int checkLang(int);
	EQLIB_OBJECT int CostToTrain(int, float, int);
	EQLIB_OBJECT int DelLoreItemDup(int, int, int, EQ_Item*);
	// GetAlternateAbilityId checked on May 1 2016 only reason why it looks like it takes 2 args(which it doesnt) is cause it pushes another which is meant for AltAdvManager__GetAAById_x see 43BBB7 in eqgame 21 apr 2016 live for an example.
	EQLIB_OBJECT int GetAlternateAbilityId(int);
	EQLIB_OBJECT int GetArmorType(int);
	EQLIB_OBJECT int GetCombatAbility(int);
	EQLIB_OBJECT PcZoneClient* GetPcZoneClient() const;
	EQLIB_OBJECT int HandleMoney(long);
	EQLIB_OBJECT int IsAGroupMember(char*);
	EQLIB_OBJECT int MaxAirSupply();
	EQLIB_OBJECT int numInParty();
	EQLIB_OBJECT static EQ_PC* top;
	EQLIB_OBJECT unsigned char AtSkillLimit(int);
	EQLIB_OBJECT unsigned char RemoveMyAffect(int);
	EQLIB_OBJECT unsigned long GetArmorTint(int);
	EQLIB_OBJECT unsigned long GetBodyTint(int);
	EQLIB_OBJECT void CheckForGroupChanges();
	EQLIB_OBJECT void CheckForLanguageImprovement(unsigned char, unsigned char);
	EQLIB_OBJECT void CheckSkillImprove(int, float);
	EQLIB_OBJECT void ClearSharedVault();
	EQLIB_OBJECT void DestroyHeldItemOrMoney();
	EQLIB_OBJECT void DetermineQuestExpGained(int);
	EQLIB_OBJECT void EmptyPossessionSlots();
	EQLIB_OBJECT void InitializeNewPCVariables(int);
	EQLIB_OBJECT void InitPlayerStart(unsigned int, unsigned char, int);
	EQLIB_OBJECT void PrepareForRepop(int);
	EQLIB_OBJECT void ProcessAirSupply();
	EQLIB_OBJECT void ProcessFatigue();
	EQLIB_OBJECT void RefitNewbieEQ();
	EQLIB_OBJECT void RefreshMe(int);
	EQLIB_OBJECT void SetAltAbilityIndex(int, int);
	EQLIB_OBJECT void SetArmorTint(int, unsigned long);
	EQLIB_OBJECT void SetArmorType(int, int);
	EQLIB_OBJECT void SetFatigue(int);
	EQLIB_OBJECT void UnpackMyNetPC(char*, int);
	EQLIB_OBJECT void AlertInventoryChanged();
	// EQLIB_OBJECT GetCombatAbilityTimer has 2 parameters confirmed apr 21 2016 eqgame.exe (live)
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT unsigned long GetCombatAbilityTimer(int, int);
	EQLIB_OBJECT unsigned long GetItemRecastTimer(EQ_Item* item, ItemSpellTypes etype);
#else
	EQLIB_OBJECT unsigned long GetCombatAbilityTimer(int);
	EQLIB_OBJECT unsigned long GetItemRecastTimer(class EQ_Item*item);
#endif
	EQLIB_OBJECT bool HasLoreItem(EQ_Item*, int, int, int, int);
	EQLIB_OBJECT void GetItemContainedRealEstateIds(ArrayClass<ItemContainingRealEstate> &Out, bool bCurrentProfileOnly = false, bool bIncludeAltStorage = true, bool bIncludeArchived = true);
	EQLIB_OBJECT void GetNonArchivedOwnedRealEstates(ArrayClass<int>& output);
};

class ProfileManager
{
public:
	EQLIB_OBJECT BaseProfile* GetCurrentProfile();
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
#if !defined(ROF2EMU)
	EQLIB_OBJECT const SPELLCALCINFO* GetSpellAffectByIndex(int Index) const;
#endif
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

class EQPlacedItem
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ EQPlacedItem* pPrev;
/*0x08*/ EQPlacedItem* pNext;
/*0x0c*/ int           RecordNum;
/*0x10*/ EqItemGuid    ItemGuid;
/*0x22*/
/*0x24*/ int           RealEstateID;
/*0x28*/ int           RealEstateItemID;
/*0x2C*/ bool          bIsNPC;
/*0x30*/ UINT          PlacingItemNpcID;
/*0x34*/ CLightInterface* pLight;
/*0x38*/ CActorInterface* pActor;
/*0x3c*/ char          Name[0x40];
/*0x7c*/ float         Scale;
/*0x80*/ float         Heading;
/*0x84*/ float         Angle;
/*0x88*/ float         Roll;
/*0x8c*/ float         Y;
/*0x90*/ float         X;
/*0x94*/ float         Z;
/*0x98*/ bool          bIgnoreCollisions;
/*0x98*/ bool          bDisablePlacementRotation;
/*0x98*/ bool          bDisableFreePlacement;
/*0x9c*/ ePlacementType PlacementType;
/*0xa0*/ float         ScaleRangeMin;
/*0xa4*/ float         ScaleRangeMax;
/*0xa8*/ float         DefaultScale;
/*0xac*/ float         DefaultHeading;
/*0xb0*/ float         DefaultAngle;
/*0xb4*/ float         DefaultRoll;
/*0xb8*/ int           LightType;
/*0xbc*/ float         NPCHeight;
/*0xC0*/
};

class EQPlacedItemManager
{
public:
	EQLIB_OBJECT static EQPlacedItemManager& Instance();
	EQLIB_OBJECT EQPlacedItem* GetItemByGuid(const EqItemGuid& ItemGuid);
	EQLIB_OBJECT EQPlacedItem* GetItemByRealEstateAndRealEstateItemIds(int RealEstateID, int RealEstateItemID);

	EQPlacedItem*      Top;
};

class RealEstateItemIds
{
public:
	int                RealEstateID;
	int                RealEstateItemID;
};

class RealEstateItemState
{
public:
	bool               bPlaced;
	__time32_t         UpkeepExpiredTime;
};

class RealEstateItemPosition
{
public:
	float              Heading;
	float              Pitch;
	float              Roll;
	float              Scale;
	float              X;
	float              Y;
	float              Z;
};

class RealEstateItemOwnerInfo
{
public:
	CXStr              OwnerName;
	CXStr              OwnerHandle;
	int                OwnerNameHashKey;
};

class RealEstateItemObject
{
public:
	VePointer<CONTENTS> pItemBase;
};

class RealEstateItem
{
public:
	RealEstateItemState                State;
	RealEstateItemPosition             Position;
	RealEstateItemOwnerInfo            OwnerInfo;
	RealEstateItemObject               Object;
};

class RealEstateItemClient : public RealEstateItem
{
public:
	RealEstateItemIds IDs;
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

class RealEstateManagerClient
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
/*0xa0*/ int           CurrentMovingCrateID;
/*0xa4*/ bool          bRequestPending;
/*0xa8*/ UINT          RequestTime;
/*0xac*/ bool          bPrintRequestTimes;

	EQLIB_OBJECT static RealEstateManagerClient& Instance();
	EQLIB_OBJECT const RealEstateItemClient* GetItemByRealEstateAndItemIds(int RealEstateID, int RealEstateItemID) const;
};

class FactionManagerClient
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ // todo: map it

	EQLIB_OBJECT static FactionManagerClient& Instance();
	EQLIB_OBJECT void HandleFactionMessage(UINT MessageID, char* pData, unsigned int DataLength);
};

struct chngForm;

class ExtendedTargetListClient : public ExtendedTargetList
{
public:
	int CurrentSlot;
	int ContextSlot;
};

enum eParcelStatus
{
	ePS_NoParcels,
	ePS_HasParcels,
	ePS_OverParcelsLimit,
};

class CGroupMemberBase
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
};

class CGroupMemberClient : public CGroupMemberBase
{
public:
	CharacterZoneClient* pCharacter;
	SPAWNINFO*           pSpawn;
	int                  GroupIndex;
};

class CGroupBase
{
public:
/*0x00*/ void*         vftable;
/*0x04*/ CGroupMemberClient* pMembers[6];
/*0x1c*/ CGroupMemberClient* pGroupLeader;
/*0x20*/ uint32_t      ID;
};

class CGroupClient : public CGroupBase
{
public:
/*0x024*/ int          GroupSelectID;
};

#define EQR_GNOME           0xc        // 5A1511 in rof2
#define EQR_IKSAR           0x80       // 5A1516 in rof2
#define EQR_VAHSHIR         0x82       // 5A151D in rof2
#define EQR_FROGLOCK        0x14a      // 5A1524 in rof2
#define EQR_DRAKKIN         0x20a      // 5A152B in rof2
#define EQR_SKELETON        0x3c
#define EQR_SKELETON_NEW    0x16f
#define EQR_OEQ_SKELETON    0x322
#define EQR_SOL_SKELETON    0x323

enum GILocationOption
{
	Bag_Or_Base,
	Socket
};

class CharacterBase
{
public:
/*0x0000*/ void*                       CharacterBase_vftable;
/*0x0004*/ CProfileManager             ProfileManager;
/*0x000C*/ TSafeArrayStatic<BYTE, 0x20> languages;
/*0x002C*/ float                       X;
/*0x0030*/ float                       Y;
/*0x0034*/ float                       Z;
/*0x0038*/ float                       Heading;
/*0x003c*/ TSafeString<0x40>           Name;
/*0x007c*/ TSafeString<0x20>           Lastname;
/*0x009c*/ TSafeString<0x80>           Title;
/*0x011c*/ TSafeString<0x40>           VehicleName;
/*0x015c*/ char                        Stunned;                      // well status really
/*0x0160*/ EQZoneIndex                 zoneId;
/*0x0164*/ BYTE                        standstate;
/*0x0168*/ RaidData                    raidData;
/*0x0244*/ int                         ExpansionFlags;
/*0x0248*/ bool                        bSuperPKILL;
/*0x024a*/ bool                        bUnclone;
/*0x024b*/ bool                        bDead;
/*0x024C*/ int                         LD_Timer;
/*0x0250*/ int                         SpellInterruptCount;
/*0x0254*/ bool                        bAutoSplit;
/*0x0255*/ bool                        bTellsOff;
/*0x0256*/ bool                        bGmInvis;
/*0x0258*/ int                         KillMe;
/*0x025c*/ bool                        CheaterLdFlag;                // likely this is int SoulMarkCount instead.
/*0x025d*/ bool                        NoRent;
/*0x025e*/ bool                        Corpse;
/*0x025f*/ bool                        ClientGmFlagSet;
/*0x0260*/ int                         BankSharedPlat;               // 31e4 CharBaseBegin+488
/*0x0264*/ int                         BankSharedGold;               // CharBaseBegin+48c
/*0x0268*/ int                         BankSharedSilver;             // CharBaseBegin+490
/*0x026c*/ int                         BankSharedCopper;             // CharBaseBegin+494
/*0x0270*/ int                         BankPlat;                     // CharBaseBegin+498
/*0x0274*/ int                         BankGold;                     // CharBaseBegin+49c
/*0x0278*/ int                         BankSilver;                   // CharBaseBegin+4a0
/*0x027c*/ int                         BankCopper;                   // CharBaseBegin+4a4
/*0x0280*/ int                         STR;                          // CharBaseBegin+4a8
/*0x0284*/ int                         STA;                          // CharBaseBegin+4ac
/*0x0288*/ int                         CHA;                          // CharBaseBegin+4b0
/*0x028c*/ int                         DEX;                          // CharBaseBegin+4b4
/*0x0290*/ int                         INT;                          // CharBaseBegin+4b8
/*0x0294*/ int                         AGI;                          // CharBaseBegin+4bc
/*0x0298*/ int                         WIS;                          // CharBaseBegin+4c0
/*0x029c*/ int                         SavePoison;                   // CharBaseBegin+4c4
/*0x02a0*/ int                         SaveMagic;                    // CharBaseBegin+4c8
/*0x02a4*/ int                         SaveDisease;                  // CharBaseBegin+4cc
/*0x02a8*/ int                         SaveCorruption;               // CharBaseBegin+4d0
/*0x02ac*/ int                         SaveFire;                     // CharBaseBegin+4d4
/*0x02b0*/ int                         SaveCold;                     // CharBaseBegin+4d8
/*0x02b4*/ int                         SavePhysical;
/*0x02b8*/ int                         UncappedStr;
/*0x02bc*/ int                         UncappedSta;
/*0x02c0*/ int                         UncappedCha;
/*0x02c4*/ int                         UncappedDex;
/*0x02c8*/ int                         UncappedInt;
/*0x02cc*/ int                         UncappedAgi;
/*0x02d0*/ int                         UncappedWis;
/*0x02d4*/ int                         UncappedResistPoison;
/*0x02d8*/ int                         UncappedResistMagic;
/*0x02dc*/ int                         UncappedResistDisease;
/*0x02e0*/ int                         UncappedResistCorruption;
/*0x02e4*/ int                         UncappedResistFire;
/*0x02e8*/ int                         UncappedResistCold;
/*0x02ec*/ int                         NoBuffStr;
/*0x02f0*/ int                         NoBuffSta;
/*0x02f4*/ int                         NoBuffCha;
/*0x02f8*/ int                         NoBuffDex;
/*0x02fc*/ int                         NoBuffInt;
/*0x0300*/ int                         NoBuffAgi;
/*0x0304*/ int                         NoBuffWis;
/*0x0308*/ int                         NoBuffResistPoison;
/*0x030c*/ int                         NoBuffResistMagic;
/*0x0310*/ int                         NoBuffResistDisease;
/*0x0314*/ int                         NoBuffResistCorruption;
/*0x0318*/ int                         NoBuffResistFire;
/*0x031c*/ int                         NoBuffResistCold;
/*0x0320*/ int                         NoBuffResistPhysical;
/*0x0320*/ int                         NoBuffResistPhysical2;
/*0x0320*/ int                         NoBuffResistPhysical3;
/*0x0324*/

	EQLIB_OBJECT unsigned int GetEffectId(int index);

	EQLIB_OBJECT LONG GetMemorizedSpell(int gem);             // 0-0xf this func returns the spellid for whatever is in the gem

	EQLIB_OBJECT ItemGlobalIndex CreateItemGlobalIndex(int Slot0, int Slot1 = -1, int Slot2 = -1);
	EQLIB_OBJECT ItemIndex CreateItemIndex(int Slot0, int Slot1 = -1, int Slot2 = -1);

	EQLIB_OBJECT const BaseProfile& GetCurrentBaseProfile() const
	{
		return *ProfileManager.GetCurrentProfile();
	}

	EQLIB_OBJECT BYTE GetLanguageSkill(int) const;
	EQLIB_OBJECT VePointer<CONTENTS> GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex) const;
	EQLIB_OBJECT VePointer<CONTENTS> GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex, GILocationOption Option) const;
	EQLIB_OBJECT VePointer<CONTENTS> GetItemPossession(const ItemIndex& lIndex) const;
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

class CharacterZoneClient : virtual public CharacterBase
{
public:
	union {
/*0x2424*/ PlayerClient*               me;                 // just here for comparing the 2, todo: fix
/*0x2424*/ PSPAWNINFO                  me2;
	};
/*0x242c*/ bool                        bUpdateStuff;
/*0x242d*/ bool                        bZoningStatProcessing;
/*0x2430*/ DWORD                       ArmorClassBonus;              // vtable2+10
/*0x2434*/ DWORD                       CurrWeight;                   // vtable2+14
/*0x2438*/ int                         LastHitPointSendPercent;
/*0x243c*/ int                         LastManaPointSendPercent;
/*0x2440*/ int                         LastEndurancePointSendPercent;
/*0x2444*/ DWORD                       HPBonus;                      // vtable2+24
/*0x2448*/ DWORD                       ManaBonus;                    // vtable2+28
/*0x244c*/ DWORD                       EnduranceBonus;               // vtable2+2c
/*0x2450*/ BYTE                        Unknown0x2450[0x4];
/*0x2454*/ DWORD                       CombatEffectsBonus;           // vtable2+34 Combat Effects in UI
/*0x2458*/ DWORD                       ShieldingBonus;               // vtable2+38 Melee Shielding in UI
/*0x245c*/ DWORD                       SpellShieldBonus;             // vtable2+3c Spell Shielding in UI
/*0x2460*/ DWORD                       AvoidanceBonus;               // vtable2+40 Avoidance in UI
/*0x2464*/ DWORD                       AccuracyBonus;                // vtable2+44 Accuracy in UI
/*0x2468*/ DWORD                       StunResistBonus;              // vtable2+48 Stun Resist in UI
/*0x246c*/ DWORD                       StrikeThroughBonus;           // vtable2+4c Strike Through in UI
/*0x2470*/ DWORD                       DoTShieldBonus;               // vtable2+50 Dot Shielding in UI
/*0x2474*/ DWORD                       DamageShieldMitigationBonus;  // vtable2+54 Damage Shield Mitig in UI
/*0x2478*/ DWORD                       DamageShieldBonus;            // vtable2+58 Damage Shielding in UI
/*0x247c*/ TSafeArrayStatic<int, 9>    ItemSkillMinDamageMod;
/*0x24a0*/ TSafeArrayStatic<int, 9>    SkillMinDamageModBonus;
/*0x24c4*/ DWORD                       HeroicSTRBonus;               // vtable2+a4
/*0x24c8*/ DWORD                       HeroicINTBonus;               // vtable2+a8
/*0x24cc*/ DWORD                       HeroicWISBonus;               // vtable2+ac
/*0x24d0*/ DWORD                       HeroicAGIBonus;               // vtable2+b0
/*0x24d4*/ DWORD                       HeroicDEXBonus;               // vtable2+b4
/*0x24d8*/ DWORD                       HeroicSTABonus;               // vtable2+b8
/*0x24dc*/ DWORD                       HeroicCHABonus;               // vtable2+bc
/*0x24e0*/ DWORD                       HeroicSvMagicBonus;           // vtable2+c0
/*0x24e4*/ DWORD                       HeroicSvFireBonus;            // vtable2+c4
/*0x24e8*/ DWORD                       HeroicSvColdBonus;            // vtable2+c8
/*0x24ec*/ DWORD                       HeroicSvDiseaseBonus;         // vtable2+cc
/*0x24f0*/ DWORD                       HeroicSvPoisonBonus;          // vtable2+d0
/*0x24f4*/ DWORD                       HeroicSvCorruptionBonus;      // vtable2+d4
/*0x24f8*/ DWORD                       HealAmountBonus;              // vtable2+d8
/*0x24fc*/ DWORD                       SpellDamageBonus;             // vtable2+dc
/*0x2500*/ int                         ItemHealAmountDotMod;
/*0x2504*/ int                         ItemSpellDamageDotMod;
/*0x2508*/ DWORD                       ClairvoyanceBonus;            // vtable2+e8
/*0x250c*/ DWORD                       AttackBonus;                  // vtable2+ec
/*0x2510*/ DWORD                       HPRegenBonus;                 // vtable2+f0
/*0x2514*/ DWORD                       ManaRegenBonus;               // vtable2+f4
/*0x2518*/ DWORD                       EnduranceRegenBonus;          // vtable2+f8
/*0x251c*/ DWORD                       AttackSpeed;                  // vtable2+fc
/*0x2520*/ //int                         ItemPotionBelt;
/*0x2520*/ int                         NoBuffItemHitpointAdjustment;
/*0x2524*/ int                         NoBuffItemManaAdjustment;
/*0x2528*/ int                         NoBuffItemEnduranceAdjustment;
/*0x252c*/ int                         NoBuffItemBaseChanceProc;
/*0x2530*/ int                         NoBuffItemMinDamageMod;
/*0x2534*/ int                         NoBuffItemInnateSpellRune;
/*0x2538*/ int                         NoBuffItemAvoidance;
/*0x253c*/ int                         NoBuffItemToHit;
/*0x2540*/ int                         NoBuffItemResistStunChance;
/*0x2544*/ int                         NoBuffItemDotShieldingEffect;
/*0x2548*/ int                         NoBuffItemStrikeThroughChance;
/*0x254c*/ int                         NoBuffItemAttack;
/*0x2550*/ int                         NoBuffItemHitPointRegen;
/*0x2554*/ int                         NoBuffItemManaRegen;
/*0x2558*/ int                         NoBuffItemEnduranceRegen;
/*0x255c*/ int                         NoBuffItemDamageShield;
/*0x2560*/ int                         NoBuffItemDamageShieldMitigation;
/*0x2564*/ int                         NoBuffItemHaste;
/*0x256c*/ //int                         NoBuffItemPotionBelt;
/*0x2568*/ TSafeArrayStatic<int, 9>    NoBuffItemSkillMinDamageMod;  // size 0x24
/*0x258c*/ bool                        bOutputHpRegen;
/*0x258d*/ bool                        bInvulnerable;
/*0x258e*/ bool                        bOnAVehicle;
/*0x2590*/ SpellCache                  spellCache;                   // size 0x58
/*0x25e8*/ HashListSet<int, 0x80>      DoomEffectsBySlot;            // size 0x10 + (0x80* 4)
/*0x27f8*/ UINT                        LastHitEval;
/*0x27fc*/

	EQLIB_OBJECT CharacterZoneClient();
	EQLIB_OBJECT int CalcAffectChange(const EQ_Spell* spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect* theAffect, int EffectIndex = 0, PlayerZoneClient* pCaster = NULL, bool overrideChangeVal = false, int ChangeVal = -1, bool bCap = true);
	EQLIB_OBJECT int CalcAffectChangeGeneric(const EQ_Spell* spell, BYTE casterLevel, BYTE affextIndex, const EQ_Affect* theAffect, int EffectIndex, bool bCap = true);
	EQLIB_OBJECT void MakeMeVisible(int, bool);
	EQLIB_OBJECT int GetItemCountWorn(int);
	EQLIB_OBJECT int GetItemCountInInventory(int);
	EQLIB_OBJECT int GetCursorItemCount(int);
	EQLIB_OBJECT bool HasSkill(int);
	EQLIB_OBJECT EQ_Affect* FindAffectSlot(int SpellID, SPAWNINFO* Caster, int* slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
	EQLIB_OBJECT EQ_Affect* FindAffectSlotMine(int SpellID, SPAWNINFO* Caster, int* slindex, bool bJustTest, int CasterLevel = -1, EQ_Affect* BuffArray = NULL, int BuffArraySize = 0, bool bFailAltAbilities = true);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT bool IsStackBlocked(const EQ_Spell* pSpell, SPAWNINFO* pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0, bool bMessageOn = false);
#else
	EQLIB_OBJECT bool IsStackBlocked(const EQ_Spell* pSpell, SPAWNINFO* pCaster, EQ_Affect* pEffecs = NULL, int EffectsSize = 0);
#endif
	EQLIB_OBJECT int BardCastBard(const EQ_Spell* pSpell, signed int caster_class) const;
	EQLIB_OBJECT unsigned char GetMaxEffects() const;
	EQLIB_OBJECT EQ_Affect& GetEffect(int) const;
	EQLIB_OBJECT int GetOpenEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, int Index = -1);
	EQLIB_OBJECT int GetFirstEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill);
	EQLIB_OBJECT int GetLastEffectSlot(bool bIsShortBuff, bool bIsMeleeSkill, bool bIsDisplay = false);
	EQLIB_OBJECT const int GetFocusReuseMod(const EQ_Spell* pSpell, VePointer<CONTENTS>& pOutItem);
	EQLIB_OBJECT bool FindItemByGuid(const EqItemGuid& ItemGuid, int* pos_slot, int* con_slot);
	EQLIB_OBJECT BYTE FindItemByRecord(int ItemNumber, int* pos_slot, int* con_slot, bool bReverseLookup);
};

// work in progres
class PcBase : virtual public CharacterBase
{
public:
/*0x0008*/ // void*    vfTable_CharacterZoneClient;
/*0x0008*/ // void*    vfTable_CharacterBase;
/*0x000C*/ // void*    vfTable_PcBase;
//last one changed
/*0x000C*/ virtual void vftableph() {};

/*0x0010*/ TSafeArrayStatic<int, 0xa>            RecentTasks;
/*0x0038*/ TSafeArrayStatic<PCTaskStatus, 1>     Tasks;
/*0x00A8*/ TSafeArrayStatic<PCTaskStatus, 0x1d>  Quests;
/*0x0D58*/ TSafeArrayStatic<BYTE, 6400 / 8>      BitFlags;
/*0x1078*/ TSafeArrayStatic<BenefitSelection, 5> ActiveTributeBenefits;
/*0x10A0*/ TSafeArrayStatic<BenefitSelection, 10> ActiveTrophyTributeBenefits;
/*0x10f0*/ TSafeArrayStatic<BYTE, 0x320>         BitFlags2;
/*0x10f0*/ ItemBaseContainer                     BankItems;
/*0x110c*/ ItemBaseContainer                     SharedBankItems;
/*0x1128*/ ItemBaseContainer                     OverflowBufferItems;
/*0x1144*/ ItemBaseContainer                     LimboBufferItems;
/*0x1160*/ ItemBaseContainer                     MercenaryItems;
/*0x117c*/ ItemBaseContainer                     MountKeyRingItems;
/*0x1198*/ ItemBaseContainer                     IllusionKeyRingItems;
/*0x11b4*/ ItemBaseContainer                     FamiliarKeyRingItems;
/*0x11d0*/ ItemBaseContainer                     AltStorageItems;
/*0x11ec*/ ItemBaseContainer                     ArchivedDeletedItems;
/*0x1208*/ ItemBaseContainer                     MailItems;
/*0x1224*/ HashTable<MailItemData, EqItemGuid, ResizePolicyNoShrink> MailItemsData;
/*0x1234*/ TSafeArrayStatic<UINT, 1>             RecentMoves;
//fine to this point
/*0x1238*/ HashTable<DynamicZoneData>            CurrentDynamicZones;
/*0x1248*/ HashTable<int>                        LearnedRecipes;
/*0x1258*/ EQList<TradeskillRecipeCount*>        QualifyingRecipeCounts;
/*0x1268*/ HashTable<int>                        NonrepeatableQuests;
/*0x1278*/ HashTable<int>                        CompletedTasks;
/*0x1288*/ HashTable<int>                        CompletedTasks2;
/*0x1298*/ UINT                                  AlchemyTimestamp;
/*0x129c*/ bool                                  bWhat;
/*0x12a0*/ bool                                  bSomethingHome;
/*0x12a4*/ DWORD                                 LoginTime;
/*0x12a8*/ int64_t                               GuildID;                      // GuildID_0
/*0x12b0*/ int64_t                               FellowshipID;
/*0x12b8*/ PFELLOWSHIPINFO                       pFellowship;
/*0x12bc*/ int                                   GuildStatus;
/*0x12c0*/ int                                   GuildFlags;
/*0x12c4*/ bool                                  GuildShowSprite;
/*0x12c8*/ UINT                                  CreationTime;
/*0x12cc*/ UINT                                  AccountCreationTime;
/*0x12d0*/ UINT                                  LastPlayedTime;
/*0x12d4*/ DWORD                                 MinutesPlayed;
/*0x12d8*/ BYTE                                  Anonymous;
/*0x12d9*/ bool                                  bGM;
/*0x12da*/ bool                                  bGMStealth;
/*0x12dc*/ DWORD                                 AAExp;
/*0x12e0*/ BYTE                                  NobilityRank;
/*0x12e1*/ BYTE                                  PercentEXPtoAA;
/*0x12e4*/ int                                   AirSupply;
/*0x12e8*/ int                                   SerialNum;
/*0x12ec*/ bool                                  bNewCharacter;
/*0x12f0*/ int                                   TasksAssigned;
/*0x12f4*/ int                                   TasksCompleted;
/*0x12f8*/ long                                  TaskRequestTimer;
/*0x12fc*/ unsigned int                          UniquePlayerID;
/*0x1300*/ WorldLocation                         DynamicZoneSafeReturnLocation;
/*0x1314*/ DynamicZoneTimerData*                 pDZTimerRoot;
/*0x1318*/ DWORD                                 TributeTimer;
/*0x131c*/ DWORD                                 BenefitTimer;
/*0x1320*/ int64_t                               CareerFavor;
/*0x1328*/ int64_t                               CurrFavor;
/*0x1330*/ bool                                  bBenefitsActive;
/*0x1331*/ bool                                  bTrophyBenefitsActive;
/*0x1332*/ bool                                  bHasResetStartingCity;
/*0x1333*/ bool                                  bIsHeadStartCharacter;
/*0x1334*/ int                                   PvPKills;
/*0x1338*/ int                                   PvPDeaths;
/*0x133c*/ int                                   PvPCurrentPoints;
/*0x1340*/ int                                   PvPTotalPointsEarned;
/*0x1344*/ int                                   PvPKillStreak;
/*0x1348*/ int                                   PvPDeathStreak;
/*0x134c*/ int                                   PvPCurrentStreak;
/*0x1350*/ PvPKill                               LastKill;
/*0x13a8*/ PvPDeath                              LastDeath;
/*0x1400*/ HashTable<PvPKill24HourData>          PvPLast24HoursKillHash;
/*0x1410*/ int                                   PvPInfamyLevel;
/*0x1414*/ int                                   PvPVitality;
/*0x1418*/ UINT                                  PvPLastInfamyTime;
/*0x141c*/ int                                   LastLastNameChange;
/*0x1420*/ int                                   LastNameChangePriv;
/*0x1424*/ UINT                                  PvPLastVitalityTime;
/*0x1428*/ bool                                  bKeepItemsOnDeath;
/*0x1429*/ bool                                  bResetSpecializationSkills;
/*0x142c*/ int                                   CharityPointsAvailable;
/*0x1430*/ int                                   CharityTotalPointsEarned;
/*0x1434*/ int                                   GoodPointsAvailable;
/*0x1438*/ int                                   GoodTotalPointsEarned;
/*0x143c*/ int                                   EvilPointsAvailable;
/*0x1440*/ int                                   EvilTotalPointsEarned;
/*0x1444*/ bool                                  bCanRequestNameChange;
/*0x1445*/ bool                                  bCanRequestNameChange2;
/*0x1446*/ bool                                  bCanRequestServerTransfer;
/*0x1447*/ bool                                  bIsCopied;
/*0x1448*/ int                                   ServerTransferGrantTime;
/*0x144c*/ bool                                  bCanRequestRaceChange;
/*0x1450*/ UINT                                  LastAAResetTime;
/*0x1454*/ UINT                                  LastMercAAResetTime;
/*0x1458*/ EQZoneIndex                           NewZoneID;
/*0x145c*/ int                                   NewAreaID;
/*0x1460*/ EAreaCorner                           eNewAreaCorner;
/*0x1464*/ EQZoneIndex                           PreviousZoneID;
/*0x1468*/ int                                   RealEstateZoneID;
/*0x146c*/ char                                  ServerCreated[0x20];
/*0x1470*/ PCAdventureData                       AdventureData;
/*0x14xx*/ PCSharedTaskData                      SharedTaskData;
/*0x14xx*/ TaskTimerData*                        pTaskTimerData;
/*0x14xx*/ PCQuestHistoryData                    QuestHistoryData;
/*0x14xx*/ PCStatistics                          PcStatistics;
/*0x1954*/ GroupMemberStats                      GroupStats;
/*0x1aa4*/ bool                                  bIsLfg;
/*0x1aa8*/ int64_t                               RaidId;
/*0x1ab0*/ int64_t                               GroupID;
/*0x1ab8*/ int64_t                               Exp;
/*0x1ac0*/ int                                   DaysEntitled;
/*0x1ac4*/ int                                   SpentVeteranRewards;
/*0x1ac8*/ bool                                  bVeteranRewardEntitled;
/*0x1ac9*/ bool                                  bAutoConsentGroup;
/*0x1aca*/ bool                                  bAutoConsentRaid;
/*0x1acb*/ bool                                  bAutoConsentGuild;
/*0x1acc*/ bool                                  bPrivateForEqPlayers;
/*0x1ad0*/ long                                  AchievementFilesModificationTime;
/*0x1ad4*/ char                                  StationID[0x20];
/*0x1af8*/ EqGuid                                Guid;
/*0x1b00*/ bool                                  bBetaBuffed;
/*0x1b04*/ int                                   Unknown0x1ad4;
/*0x1b08*/ int                                   StartingCity;
/*0x1b0c*/ int                                   MainLevel;
/*0x1b10*/ bool                                  bShowHelm;
/*0x1b18*/ int64_t                               LastTestCopyTime;
/*0x1b20*/ CPlayerPointManager                   PointManager;
/*0x1b34*/ PointSystemBase                       PointSystem;
/*0x1B48*/ UINT                                  LoyaltyVelocity;
/*0x1B4c*/ UINT                                  LoyaltyTokens;
/*0x1B50*/ bool                                  bHasLoyaltyInfo;
/*0x1B54*/ ArrayClass_RO<int>                    OwnedRealEstates;
/*0x1B64*/ ArrayClass_RO<int>                    OwnedItemRealEstates;
/*0x1B74*/ ArrayClass_RO<int>                    ArchivedRealEstates;
/*0x1B84*/ char                                  OverridePetName[0x40];
/*0x1Bc4*/ bool                                  bCanRequestPetNameChange;
/*0x1Bc5*/ char                                  OverrideFamiliarName[0x40];
/*0x1c05*/ bool                                  bCanRequestFamiliarNameChange;
/*0x1c08*/ CXStr                                 OverrideMercName[0xb];
/*0x1c34*/ bool                                  bCanRequestMercNameChange;
/*0x1c38*/ PendingRewardList                     PendingRewards;
/*0x1c64*/ UINT                                  DowntimeReductionTime;
/*0x1c68*/ UINT                                  DowntimeTimerStart;
/*0x1c6c*/ float                                 ActivityValue;
/*0x1c70*/ UINT                                  NextItemId;
/*0x1c74*/ CXStr                                 SharedBank;
/*0x1c78*/ CXStr                                 BankBuffer;
/*0x1c7c*/ CXStr                                 OverflowBuffer;
/*0x1c80*/ CXStr                                 LimboBuffer;
/*0x1c84*/ CXStr                                 MercenaryBuffer;
/*0x1c88*/ CXStr                                 KeyRingBuffer[3];
/*0x1c94*/ CXStr                                 AltStorageBuffer;
/*0x1c98*/ UINT                                  AltStorageTimestamp;
/*0x1c9c*/ ELockoutCharacterReason               LCR;
/*0x1ca0*/ HashTable<ProgressionExperience>      ProgressionExp;
/*0x1cb0*/ CXStr                                 ArchivedStorageBuffer;
/*0x1cb4*/ CXStr                                 MailItemsBuffer;
/*0x1cb8*/ CXStr                                 MailItemsDataBuffer;
/*0x1cbc*/ int                                   MailItemsOverCapWarningCount;
/*0x1cc0*/ ItemIndex                             StatKeyRingItemIndex[3];
/*0x1cd2*/ bool                                  UseAdvancedLooting;
/*0x1cd3*/ bool                                  MasterLootCandidate;
/*0x1cd4*/ bool                                  bIsCorrupted;
/*0x1cd8*/ char*                                 pCorruptionReport;
/*0x1cdc*/ TString<0x100>                        InspectText;
/*0x1ddc*/ HashTable<int>                        BlockedSpellsHash;
/*0x1dec*/ int                                   BlockedSpell[0x28];
/*0x1e8c*/ HashTable<int>                        BlockedPetSpellsHash;
/*0x1e9c*/ int                                   BlockedPetSpell[0x28];
/*0x1f3c*/ ClaimDataCollection                   ConsumableFeatures;
/*0x1f4c*/ bool                                  bGrantItemsRegistered;
/*0x1f50*/ uint64_t                              CreatedGuildID;
/*0x1f58*/ UINT                                  GuildCreateTime;
/*0x1f5c*/ CXStr                                 GuildCreateCharacter;
/*0x1f60*/ bool                                  bInventoryUnserialized;
/*0x1f61*/ bool                                  bAltStorageUnserialized;
/*0x1f62*/ bool                                  bArchivedStorageUnserialized;
/*0x1f63*/ bool                                  bMailUnserialized;
/*0x1f64*/ bool                                  bPendingInventorySerialization;
/*0x1f68*/ CXStr                                 BuyLines;
/*0x1f6c*/ ArrayClass_RO<CXStr>                  OfflineTraderSoldItems;
/*0x1f7c*/ ArrayClass_RO<CXStr>                  OfflineBuyerBoughtItems;
/*0x1f8c*/ UINT                                  Krono;
/*0x1f90*/ UINT                                  CursorKrono;
/*0x1f98*/ int64_t                               MercAAExp;                    // divide this with 3.30f and you get the percent
/*0x1fa0*/ DWORD                                 MercAAPoints;                 // number of unspent merc AA points
/*0x1fa4*/ DWORD                                 MercAAPointsSpent;            // number of spent merc AA points
/*0x1fa8*/ ArrayClass_RO<MercenaryAbilityInfo*>  MercenaryAbilities;
/*0x1fb8*/ HashTable<CompletedAchievementData, int, ResizePolicyNoShrink>         CompletedAchievements;
/*0x1fc8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> CompletedEventBasedSubComponents;
/*0x1fd8*/ HashTable<AchievementSubComponentCountData, int, ResizePolicyNoShrink> OpenEventBasedSubComponents;
/*0x1fe8*/ int                                   LastFellowshipJoin;
/*0x1ff0*/ int64_t                               Vitality;
/*0x1ff8*/ int                                   AAVitality;
/*0x1ffc*/ int                                   Unknown0x1ffc;
/*0x2000*/ int                                   FPStuff[0x1c];
/*0x2070*/ //CharacterZoneClient
};

class DebugText
{
public:
	EQLIB_OBJECT virtual void SendDebugText(const char* text, int color);
};

class PcZoneClient : public PcBase, public CharacterZoneClient, public DebugText
{
public:
/*0x245c*/ void*       vfTable_PcZoneClient;
/*0x2460*/ TSafeArrayStatic<unsigned long, 3> Flags;
/*0x246C*/ uint32_t    TransfersReceived;
/*0x2470*/ int         LastLanguageSpoken;
/*0x2474*/ int         CurPowerSourceDrain;
/*0x2478*/ EQList<ALCHEMYBONUSSKILLDATA*> AlchemyBaseSkillBonusList;
/*0x2488*/ UINT        MomentumBalance;
/*0x248C*/ UINT        LoyaltyRewardBalance;
/*0x2490*/

	EQLIB_OBJECT int GetPcSkillLimit(int);
	EQLIB_OBJECT bool HasCombatAbility(int);
	EQLIB_OBJECT void RemovePetEffect(int);
	EQLIB_OBJECT bool CanEquipItem(CONTENTS** pCont, int slotid, bool bOutputDebug, bool bUseRequiredLevel);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT bool HasAlternateAbility(int aaindex, int*, bool, bool);
#else
	EQLIB_OBJECT bool HasAlternateAbility(int aaindex, int*, bool);
#endif
	EQLIB_OBJECT int GetCurrentMod(int index);
#if !defined(ROF2EMU) && !defined(UFEMU)
	int GetModCap(int index, bool bToggle = false);
#else
	EQLIB_OBJECT int GetModCap(int index);
#endif
	EQLIB_OBJECT void RemoveBuffEffect(int Index, int SpawnID);
	EQLIB_OBJECT CONTENTS** GetItemByID(CONTENTS** contOut, int itemid, ItemIndex* itemindex = nullptr);
	EQLIB_OBJECT CONTENTS** GetItemByItemClass(CONTENTS** contOut, int itemclass, ItemIndex* itemindex = nullptr);
	EQLIB_OBJECT void BandolierSwap(int index);
	EQLIB_OBJECT UINT GetLinkedSpellReuseTimer(int index);
};

class PcClient : public PcZoneClient
{
	// has a vftable but we get it from PcZoneClient
public:
	EQLIB_OBJECT PcClient();

	BYTE Filler[0x2b10];
};

// A.k.a. PlayerManagerClient
class EQPlayerManager
{
public:
	EQLIB_OBJECT PlayerClient* GetSpawnByID(int);
	EQLIB_OBJECT PlayerClient* GetSpawnByName(char*);
	EQLIB_OBJECT PlayerClient* GetPlayerFromPartialName(const char*, PlayerBase*);

	SPAWNMANAGER Data;
};

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

class EqSoundManager
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

	Mp3Manager*        pMp3Manager;
	SoundManager*      pSoundManager;
	EmitterManager*    pEmitterManager;
	MusicManager*      pMusicManager;
	SoundAsset*        pGlobalMidiAsset;
	SoundAsset*        pOpenerMidiAsset;
	SoundAsset*        pOpenerMp3Asset;
	SoundAsset*        pDeathMp3Asset;
	SoundAsset*        pCombatMp3Asset;
	SoundAsset*        pMerchantMp3Asset;
	SoundAsset*        pZoneMidiAsset;
	SoundAsset*        pScriptMp3Asset;
	bool               bDisabled;
	int                NextMusicID;
	SoundEmitter*      pEmitters[1000];
	int                EmittersCount;
	SoundEmitter*      pRainEmitter;
	SoundEmitter*      pWindEmitter;
	int                EnvironmentHigh;
	int                EnvironmentLow;
	int                EnvironmentOutside;
	float              fEffectsLevel;
	float              fWaveVolumeLevel;
	// more here but i only need volume for now so...
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

class IconCache
{
public:
	HashTable<CTextureAnimation*> IconTextures;
	CXStr              pAnimationName;
	int                Offset;
	int                MinValue;
	int                MaxValue;

	EQLIB_OBJECT ~IconCache();
	EQLIB_OBJECT IconCache();
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

class KeypressHandler
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

/*0x000*/ KeyCombo     NormalKey[nEQMappableCommands];
/*0x2 4*/ KeyCombo     AltKey[nEQMappableCommands];
/*0x5C8*/ char         CommandState[nEQMappableCommands];
};

struct ItemFilterData
{
/*0x00*/ int           Types;
/*0x04*/ int           ID;
/*0x08*/ int           Icon;
/*0x0c*/ char          Name[0x40];
};

class LootFiltersManager
{
public:
	EQLIB_OBJECT bool AddItemLootFilter(int ItemID, int IconID, const char* ItemName, int FilterTypes, bool bFromFile = false);
	EQLIB_OBJECT const ItemFilterData* GetItemFilterData(int ItemID);
	EQLIB_OBJECT bool RemoveItemLootFilter(int ItemID, int FilterTypes);
	EQLIB_OBJECT bool SetItemLootFilter(int ItemID, int IconID, const char* ItemName, int FilterTypes, bool bKeepRndSetting, bool bScrollToIt);
};

class MercenaryAbilityReq
{
public:
/*0x00*/ int           ReqGroupID;
/*0x04*/ int           ReqGroupRank;
};

class MercenaryAbilitiesData
{
public:
/*0x00*/ int           AbilityID;
/*0x00*/ int           nName;
/*0x00*/ int           nDesc;
/*0x00*/ int           Cost;
/*0x00*/ int           GroupID;
/*0x00*/ int           GroupRank;
/*0x00*/ int           Type;
/*0x00*/ int           MinPlayerLevel;           // min level to purchase...
/*0x00*/ int           RequirementAssociationID;
/*0x00*/ int           Refund;
/*0x00*/ int           BetaOnly;
/*0x00*/ int           QuestAbility;
/*0x00*/ ArrayClass<MercenaryAbilityReq> AbilityReqs;
};

class MercenaryAlternateAdvancementManagerClient
{
public:
	EQLIB_OBJECT static MercenaryAlternateAdvancementManagerClient& Instance();

	HashList<int, 5>                             MercenaryTypes;
	HashList<MercenaryAbilitiesData, 0x40>       MercenaryAbilities;
	HashList<int, 0x40>                          MercenaryAbilitiesByGroupID;
	HashList<int, 0x40>                          MercenaryAbilitiesOwnedByGroupID;
	HashList<HashList<int, 0x10>, 0x40>          MercenaryAbilityGroups;
};

class EQSpellStrings
{
public:
	EQLIB_OBJECT char* GetString(int SpellID, int StrIndex);
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

class SListWndSortInfo
{
public:
/*0x00*/ int           SortCol;
/*0x04*/ const SListWndLine& ListWndLine1;
/*0x08*/ CXStr         StrLabel1;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x10*/ uint64_t      Data1;
#else
/*0x0c*/ uint32_t      Data1;
#endif
/*0x18*/ const SListWndLine& ListWndLine2;
/*0x1c*/ CXStr         StrLabel2;
#if !defined(ROF2EMU) && !defined(UFEMU)
/*0x20*/ uint64_t      Data2;
#else
/*0x18*/ uint32_t      Data2;
#endif
/*0x28*/ int           SortResult;
/*0x2c*/
	~SListWndSortInfo();
};

enum AssetType
{
	cAssetTypeUnknown,
	cAssetTypeWave,
	cAssetTypeMp3,
	cAssetTypeOgg,
	cAssetTypeMidi
};

class SoundObject
{
public:
	SoundObject();
	virtual ~SoundObject();

	void AddRef();
	void Release();

	int refCount = 1;
};

class SoundAsset : public SoundObject
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

	char szName[512];
	char* rawData;
	int rawDataLen;
	AssetType assetType;
	SoundManager* soundManager;
	SoundInstance* soundInstance;

	SoundAsset* pNext;
};

struct SoundControl
{
	float volumeLevel = 1.0f;
	int fadeInTime = 0;
	int loops = 1;
	int sequence = 0;
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
	float minDistance = 0.f;
	float maxDistance = 0.f;
	float effectsLevel = 1.f;
	int poolNumber = 0;
	bool fireOnce = true;
	bool startUp = false;
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

class FileStatMgr
{
public:
	struct FileStat
	{
		struct _stat32 Stats;
		CXStr          Filename;
		CXStr          Key;
	};

	HashTable<FileStat*> FileStats;
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

class RequirementAssociationManager : public FileStatMgr
{
public:
	void*              vfTable;
	HashTable<HashTable<DoublyLinkedList<int>*>*> Requirements;
	char               AssocFilename[512];
	ReqType            LastFailReason;
	int                LastFailGroupID;
	int                LastFailReqID;
};

class SpellRequirementAssociationManager : public RequirementAssociationManager
{
public:
	HashList<HashList<HashList<int, 10>, 10>, 1000> ReqAssData;
};

struct StageType
{
	char               BlitSprite[3][0x20];
	char               AttachTag[0x20];
	int                DAGnum[3];
	int                pcloud[3];
	char               SpriteTAG[0xc][0x20];
	int                SpritEffect;
	int                SoundNum;
	ARGBCOLOR          Tint[3];
	float              Gravity[3];
	float              NormalX1;
	float              NormalY1;
	float              NormalZ1;
	float              NormalX2;
	float              NormalY2;
	float              NormalZ2;
	float              NormalX3;
	float              NormalY3;
	float              NormalZ3;
	float              Radius[3];
	float              Angle[3];
	ULONG              Lifespan[3];
	float              Velocity[3];
	ULONG              Rate[3];
	float              Scale[3];
	EQRGB              SpriteRGB[0xc];
	float              RollRate[0xc];
	short              HdgOffset[0xc];
	short              PitchOffset[0xc];
	float              Distance[0xc];
	short              EffectType[12];
	float              ScaleFactor[12];
};

struct OldSpellEffect
{
	int                Tgts;
	int                Perm;
	StageType          stages[3];
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

struct SpellEffectEmitter
{
	int DefIndex;
	int RequiredLevel;
	EEffectActor EffectActor;
	EAttachPoint AttachPoint;
};

struct SpellEffectStage
{
	int                SoundNum;
	SpellEffectEmitter Emitters[4];
};

struct NewSpellEffect
{
	char               szSpellEffectName[0x40];
	SpellEffectStage   Stages[3];
};

class EQSpellExtra
{
public:
	OldSpellEffect*    OldSpellEff;
	NewSpellEffect*    NewSpellEff;
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

struct StackingGroupData
{
	int StackingGroupID;
	int StackingGroupRank;
	ESpellStackingRules StackingGroupRuleType;
};

// really would like to get this to work and align but its kinda complicated, maybe another day.
class SpellManager : public FileStatMgr
{
public:
/*0x000004*/ int      SpellsCrc32[TOTAL_SPELL_COUNT+1];
/*0x03A988*/ PSPELL   MissingSpell;
/*0x03A98c*/ PSPELLCALCINFO* MissingSpellAffect;
/*0x03A990*/ PSPELLCALCINFO* MissingSpellAffectAC;
/*0x03A994*/ int      MissingSpellCrc32;
/*0x03A998*/ int      SpellFileCRC;
/*0x03A99c*/ int      SpellAssocFileCRC;
/*0x03A9A0*/ int      SpellStackingFileCRC;
/*0x03A9A4*/ SpellRequirementAssociationManager ReqAssocManager;
/*0x03BB8C*/ HashTable<int, int, ResizePolicyNoShrink> SpellGroups;
/*0x03BB9C*/

	EQLIB_OBJECT SpellManager(char*);
	EQLIB_OBJECT virtual ~SpellManager();
	EQLIB_OBJECT const EQ_Spell* GetSpellByGroupAndRank(int Group, int SubGroup, int Rank = -1, bool bLesserRanksOk = false);
};

class ClientSpellManager : public SpellManager
{
public:
	EQLIB_OBJECT virtual ~ClientSpellManager();
	EQLIB_OBJECT bool LoadSpells(const char* FileName, const char* AssocFilename, const char* StackingFileName);
	EQLIB_OBJECT bool LoadSpellStackingData(const char* StackingFileName);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT bool DoesMeetRequirement(PlayerZoneClient* pPlayer, int SpellAssocID);
#endif
	EQLIB_OBJECT void PrintFailedRequirementString(int StrToken, int StringID);
	EQLIB_OBJECT int GetSpellStackingGroupID(int SpellID);
	EQLIB_OBJECT int GetSpellStackingGroupRank(int SpellID);
	EQLIB_OBJECT ESpellStackingRules GetSpellStackingGroupRule(int SpellID);
	EQLIB_OBJECT PSPELL GetSpellByID(int SpellID);
	EQLIB_OBJECT SPELLCALCINFO* GetSpellAffect(int index);
	EQLIB_OBJECT bool GetSpellAffectEmpty(bool);

	SPELL*                       Spells[TOTAL_SPELL_COUNT+1];         // 60001 last one is the unknown spell...
	SPELLCALCINFO*               CalcInfo[CalcInfoSize];              // 175000
	EQSpellExtra                 SpellExtraData[TOTAL_SPELL_COUNT+1];
	HashTable<StackingGroupData> StackingData;
};

class StringTable
{
public:
	EQLIB_OBJECT char* getString(unsigned long ID, bool* bFound = nullptr);
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

class DatabaseStringTable
{
public:
	EQLIB_OBJECT const char* GetString(int id, int type, bool* found = nullptr);
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
	EQLIB_OBJECT unsigned long GetNameToken(int);
	EQLIB_OBJECT unsigned long GetSkillCap(EQ_Character*, int, int, int, bool, bool, bool);
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
	EQLIB_OBJECT char* GetFriendName(int);
};

class PlayerPointManager
{
public:
	EQLIB_OBJECT unsigned long GetAltCurrency(unsigned long, unsigned long b = 1);
};

enum eZoneGuideConnectionsView
{
	eZGCV_None,
	eZGCV_Selected,
	eZGCV_PreviewPath,
	eZGCV_ActivePath,
	eZGCV_Disabled,
};

class ZoneGuideConnection
{
public:
	EQZoneIndex        DestZone;
	int                TransferTypeIndex;
	int                RequiredExpansions;       // EQExpansionOwned
	bool               bDisabled;
};

class ZoneGuideZone
{
public:
/*0x00*/ EQZoneIndex   ID;
/*0x04*/ CXStr         Name;
/*0x08*/ int           ContinentIndex;
/*0x0C*/ int           MinLevel;
/*0x10*/ int           MaxLevel;
/*0x14*/ DynamicBitField<unsigned short, short> Types;
/*0x1C*/ ArrayClass_RO<ZoneGuideConnection> ZoneConnections;
/*0x2C*/ // see 8E87D6 in Apr 15 2019 exe
};

class ZoneGuideContinent
{
public:
	int                ID;
	int                DisplaySequence;
	CXStr              Name;
};

class ZoneGuideZoneType
{
public:
	int                ID;
	int                DisplaySequence;
	CXStr              Name;
};

class ZoneGuideTransferType
{
public:
	int                ID;
	CXStr              Description;
};

// see 8D35C1 in may 10 2018 exe
// see 8E87D1 in Apr 15 2019 exe
#if defined(ROF2EMU) || defined(UFEMU)
// see 7FEC8D
#define ZONE_COUNT 768
#else
#define ZONE_COUNT 836
#endif

class ZoneGuideManagerBase
{
public:
/*0x0000*/ void*       vfTable;
/*0x0004*/ ZoneGuideZone Zones[ZONE_COUNT];
/*0x8FB4*/ ArrayClass_RO<ZoneGuideContinent> Continents;
/*0x8FC4*/ ArrayClass_RO<ZoneGuideZoneType> ZoneTypes;
/*0x8FD4*/ ArrayClass_RO<ZoneGuideTransferType> TransferTypes;
/*0x8FE4*/
};

struct ZonePathData
{
	EQZoneIndex        ZoneID;
	int                TransferTypeIndex;
};
using PZonePathData = ZonePathData*;

// size: 0x9010 see 6AB098 in Apr 15 2019 exe
// todo: fix this for the rof2 emu client...
class ZoneGuideManagerClient : public ZoneGuideManagerBase
{
public:
/*0x8FE4*/ ArrayClass_RO<ZonePathData> ActivePath;
/*0x8FF4*/ ArrayClass_RO<ZonePathData> PreviewPath;
/*0x9004*/ EQZoneIndex CurrZone;
/*0x9008*/ int         HerosJourneyIndex;
/*0x900C*/ bool        bZoneGuideDataSet;
/*0x900D*/ bool        bIncludeBindZoneInPath;
/*0x900E*/ bool        bAutoFindActivePath;
/*0x900F*/ bool        bFindActivePath;
/*0x9010*/

	static ZoneGuideManagerClient& Instance();
};

class CZoneGuideWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	void*              VerticalLayout;           // CVerticalLayoutWnd
	CButtonWnd*        FilterMyLevelButton;
	CButtonWnd*        FilterAllLevelsButton;
	CButtonWnd*        FilterZonesActiveButton;
	CButtonWnd*        FilterZonesInactiveButton;
	CButtonWnd*        ZoneRunSearchButton;
	CButtonWnd*        ZoneClearSearchButton;
	CButtonWnd*        SelectCurrentZoneButton;
	CEditWnd*          LevelFilterEdit;
	CEditWnd*          ZoneSearchEdit;
	CComboWnd*         TypeFilterCombo;
	CComboWnd*         ContinentFilterCombo;
	CListWnd*          ZonesList;
	CLabelWnd*         ViewZoneConnectionsSelectedZoneLabel;
	CLabelWnd*         ViewZoneConnectionsPreviewPathLabel;
	CLabelWnd*         ViewZoneConnectionsActivePathLabel;
	CLabelWnd*         ViewZoneConnectionsDisabledLabel;
	CButtonWnd*        ViewZoneConnectionsSelectedZoneButton;
	CButtonWnd*        ViewZoneConnectionsPreviewPathButton;
	CButtonWnd*        ViewZoneConnectionsActivePathButton;
	CButtonWnd*        ViewZoneConnectionsDisabledButton;
	CButtonWnd*        DisableConnectionTemplateButton;
	CListWnd*          ZoneConnectionsList;
	CButtonWnd*        ResetPathStartZoneButton;
	CButtonWnd*        SetPathStartZoneButton;
	CButtonWnd*        SetPathEndZoneButton;
	CButtonWnd*        ShowPathWndButton;
	CButtonWnd*        HidePathWndButton;
	CButtonWnd*        FindPathButton;
	CButtonWnd*        EndFindButton;
	CButtonWnd*        ClearPathWndButton;
	CButtonWnd*        ActivatePathButton;
	CButtonWnd*        IncludeBindZoneInPathGenerationButton;
	CButtonWnd*        ShowPathWndOnPathActivationButton;
	CButtonWnd*        AutoFindActivePathButton;
	CEditWnd*          PathStartZoneEdit;
	CEditWnd*          PathEndZoneEdit;
	UINT               NextButtonRefreshTime;
	EQZoneIndex        eCurrentZone;
	bool               bFilterActive;
	int                FilterLevel;
	int                FilterContinentIndex;
	int                FilterZoneTypeIndex;
	bool               bSelectCurrentZone;
	CXStr              ZoneSearchString;
	eZoneGuideConnectionsView eCurrConnectionsView;
	EQZoneIndex        CurrConnectionsViewSelectedZone;
	bool               bCurrentConnectionsViewPreviewPathChanged;
	bool               bCurrentConnectionsViewActivePathChanged;
	bool               bSetPathStartZoneToCurrentZone;
	EQZoneIndex        StartZone;
	EQZoneIndex        EndZone;
	bool               bZoneGuideDataChanged;
	bool               bZoneListChanged;
	bool               bZoneConnectionsListChanged;
	bool               bPathStartZoneChanged;
	int                RightClickMenuID;
};

enum eKeyboardMode
{
	Typing,
	KBM_Command,
};

#pragma pack(push)
#pragma pack(4)

struct EVERQUESTINFO
{
/*0x00000*/	HWND       Wnd;
/*0x00004*/ HINSTANCE  hInst;
/*0x00008*/	int        Render_MinX;
/*0x0000c*/	int        Render_MinY;
/*0x00010*/	int        Render_MaxX;
/*0x00014*/	int        Render_MaxY;
/*0x00018*/	int        Render_XScale;
/*0x0001c*/	int        Render_YScale;
/*0x00020*/	int        Render_WidthScale;
/*0x00024*/	int        Render_HeightScale;
/*0x00028*/	int        ReadyEnterWorld;
/*0x0002c*/	bool       InsideDoMainWhileLoop;
/*0x00030*/	int        Hidden;
/*0x00034*/ DWORD      Displayflags;
/*0x00038*/ DWORD      Command;
/*0x0003c*/	BYTE       Unknown0x0003c;
/*0x00040*/	int        ScreenXRes;
/*0x00044*/	int        ScreenYRes;
/*0x00048*/	int        WindowXOffset;
/*0x0004c*/	int        WindowYOffset;
/*0x00050*/	bool       FullscreenMode;
/*0x00054*/	eKeyboardMode KeyboardMode;
/*0x00058*/	BYTE       Runmode;                  // dont EVER set this to something > 1 unless you WANT to get banned.
/*0x00059*/	BYTE       Unknown0x00059;
/*0x0005a*/	BYTE       Unknown0x0005a;
/*0x0005b*/	BYTE       MouseCntrl;
/*0x0005c*/	BYTE       MouseActive;
/*0x0005d*/	BYTE       ForceCrouch;
/*0x00060*/	UINT       ForceCrouchTimer;
/*0x00064*/	float      Unknown0x00064;
/*0x00068*/	float      Unknown0x00068;
/*0x0006c*/	int        MouseX;
/*0x00070*/	int        MouseY;
/*0x00074*/	int        MouseZ;
/*0x00078*/	int        Lastmx;
/*0x0007c*/	int        Lastmy;
/*0x00080*/	bool       MouseInClientRect;
/*0x00084*/ int        MXSensitivity;
/*0x00088*/ int        MYSensitivity;
/*0x0008c*/	int        MousePointerSpeedMod;
/*0x00090*/	bool       ServerFilter;
/*0x00094*/	int        IsTrader;
/*0x00098*/	BYTE       CurrentChan;
/*0x0009c*/	int        CurrentLang;
/*0x000a0*/	char       TellTarget[0x40];
/*0x000e0*/	UINT       LastMinute;
/*0x000e4*/	UINT       LastLocal;
/*0x000e8*/	UINT       LastControlled;
/*0x000ec*/	BYTE       MInverse;
/*0x000ed*/	BYTE       Unknown0x000ed;
/*0x000ee*/	BYTE       MouseLook;
/*0x000ef*/	bool       bDefaultMouseLook;
/*0x000f0*/	BYTE       Strafe;
/*0x000f1*/	bool       bNetstat;
/*0x000f2*/	BYTE       ModInventory;
/*0x000f4*/	UINT       LastHitter;
/*0x000f8*/	BYTE       Harmless;
/*0x000f9*/	BYTE       Silenced;
/*0x000fc*/	UINT       JumpTimer;
/*0x00100*/	UINT       EventJump;
/*0x00104*/	UINT       LastJump;
/*0x00108*/	UINT       FrameTime;
/*0x0010c*/	int        AutoRun;
/*0x00110*/	UINT       PoisonTimer;
/*0x00114*/	ItemGlobalIndex PoisonGI;
/*0x00120*/	int        OldX;
/*0x00124*/	int        OldY;
/*0x00128*/	BYTE       OldMouseButtons[8];
/*0x00130*/	BYTE       MouseButtons[8];
/*0x00138*/	bool       bIsMouseRightHanded;
/*0x0013c*/	int        Unknown0x0013c;
/*0x00140*/	int        CharStatePending;
/*0x00144*/	char       PendingCharacterName[0x40];
/*0x00184*/	int        TutorialMode;
/*0x00188*/	int        RMouseSecond;
/*0x0018c*/	int        LMouseSecond;
/*0x00190*/	UINT       RMouseDown;
/*0x00194*/	UINT       LMouseDown;
/*0x00198*/	char       Unknown0x00198[0x40];
/*0x001d8*/	UINT       DuelTarget;
/*0x001dc*/	UINT       DuelMe;
/*0x001e0*/	BYTE       DuelOn;
/*0x001e4*/	UINT       AutoHelp;
/*0x001e8*/	BYTE       OldMouseLook;
/*0x001ec*/	UINT       LastLocalUpdate;
/*0x001f0*/	UINT       LastControlledUpdate;
/*0x001f4*/	UINT       DataRate;
/*0x001f8*/	int        SavedPC;
/*0x001fc*/	int        InfraRed;
/*0x00200*/	int        InfraGreen;
/*0x00204*/	int        InfraBlue;
/*0x00208*/	int        UltraRed;
/*0x0020c*/	int        UltraGreen;
/*0x00210*/	int        UltraBlue;
/*0x00214*/	int        Unknown0x00214;
/*0x00218*/	int        IOLines;
/*0x0021c*/	int        IOLineSpacing;
/*0x00220*/	char       ObjTag[0x14];
/*0x00234*/	long       NumObjects;
/*0x00238*/	long       NumLights;
/*0x0023c*/	long       DecrTime[0xa];
/*0x00264*/	long       DecrMsg[0xa];
/*0x0028c*/	long       DecrIndex;
/*0x00290*/	BYTE       AffectsOn;
/*0x00291*/	BYTE       InspectMode;
/*0x00292*/	BYTE       UpMouseAnim;
/*0x00294*/	UINT       ExitCounter;
/*0x00298*/	UINT       ExitStart;
/*0x0029c*/	UINT       ForcedExitCounter;
/*0x002a0*/	UINT       OfflineModeRequestTime;
/*0x002a4*/	int        SwimJump;
/*0x002a8*/	BYTE       DisplayCamp;
/*0x002ac*/	int        PolysOff;
/*0x002b0*/	float      CampY;
/*0x002b4*/	float      CampX;
/*0x002b8*/	float         CampZ;
/*0x002bc*/ int        Hits;
/*0x002c0*/	int        Bandage;
/*0x002c4*/	UINT       BackSpace;
/*0x002c8*/	long       StartBandage;
/*0x002cc*/	long       MyY;
/*0x002d0*/	long       MyX;
/*0x002d4*/	long       MyZ;
/*0x002d8*/	long       TargetY;
/*0x002dc*/	long       TargetX;
/*0x002e0*/	long       TargetZ;
/*0x002e4*/	ZONEINFO   ZoneInfo;
/*0x0068c*/	BYTE       ZDefined;
/*0x00690*/	int        TrackTimer;
/*0x00694*/	long       StartTrack;
/*0x00698*/	int        bTrackPlayers;
/*0x0069c*/ bool       bTrackMercs;
/*0x0069d*/ bool       bTrackPets;
/*0x006a0*/	int        iTrackSortType;
/*0x006a4*/	int        iTrackFilterType;
/*0x006a8*/	UINT       MouseTimer;
/*0x006ac*/	int        SoundUpdate;
/*0x006b0*/	bool       MouseOn;
/*0x006b4*/	USINGSKILL UsingSkill;
/*0x006bc*/	int        Unknown0x006bc[4];
/*0x006cc*/ BYTE       ClickThroughMask;
/*0x006d0*/	int        ShowSpellDescriptions;
/*0x006d4*/	bool       ReceivedWorldObjects;
/*0x006d5*/	BYTE       Unknown0x006d5;
/*0x006d6*/	bool       Unknown0x006d6;
/*0x006d8*/	float      SavedViewPitch;
/*0x006dc*/	int        SendPcReceived;
/*0x006e0*/	int        WeatherReceived;
/*0x006e4*/	int        PixelInit;
/*0x006e8*/	bool       bIsPressedShift;
/*0x006e9*/	bool       bIsPressedControl;
/*0x006ea*/	bool       bIsPressedAlt;
/*0x006eb*/	bool       bIsPressedLShift;
/*0x006ec*/	bool       bIsPressedLControl;
/*0x006ed*/	bool       bIsPressedLAlt;
/*0x006ee*/	bool       bIsPressedRShift;
/*0x006ef*/	bool       bIsPressedRControl;
/*0x006f0*/	bool       bIsPressedRAlt;
/*0x006f4*/	int        Currkeypress;
/*0x006f8*/	int        Lastkeypress;
/*0x006fc*/	int        Rateup;
/*0x00700*/	int        Ratedown;
/*0x00704*/	int        Rateforward;
/*0x00708*/	int        Rateback;
/*0x0070c*/	int        Rateleft;
/*0x00710*/	int        Rateright;
/*0x00714*/	int        RaceWar;
/*0x00718*/	int        Ruleset;
/*0x0071c*/	bool       bRpServer;
/*0x0071d*/	bool       bAcceleratedServer;
/*0x0071e*/	bool       bProgressionServer;
/*0x00720*/	int        ProgressionOpenExpansions;
/*0x00724*/ bool       bIsDevServer;
/*0x00725*/ bool       bIsBetaServer;
/*0x00726*/ bool       bIsTestServer;
/*0x00727*/ bool       bIsStageServer;
/*0x00728*/	bool       bUseMailSystem;
/*0x00729*/	bool       bIsEscapeServer;
/*0x0072a*/	bool       bIsTutorialEnabled;
/*0x0072b*/	bool       bCanCreateHeadStartCharacter;
/*0x0072c*/ bool       bCanCreateHeroicCharacter;
/*0x00730*/ int        HeroicSlots;
/*0x00734*/	bool       bAutoIdentify;
/*0x00735*/	bool       bNameGen;
/*0x00736*/	bool       bGibberish;
/*0x00738*/	int        Locale;
/*0x0073c*/	BYTE       UpdateControlled;
/*0x0073d*/	BYTE       UpdateLocal;
/*0x0073e*/	BYTE       EnterZone;
/*0x0073f*/	BYTE       ExitGame;
/*0x00740*/ int        EnterZoneReason;
/*0x00744*/	bool       UseVoiceMacros;
/*0x00748*/	int        Deltax;
/*0x0074c*/	int        Deltay;
/*0x00750*/	int        OldRate1;
/*0x00754*/	int        OldRate2;
/*0x00758*/	float      StrafeRate;
/*0x0075c*/	int        SaveIndex;
/*0x00760*/	float      Unknown0x00760;
/*0x00764*/ // plus more ...
};
#pragma pack(pop)
using PEVERQUESTINFO = EVERQUESTINFO*;

// size 0x20 -- brainiac 11/14/2016
struct tp_coords
{
/*0x00*/ int           Index;
/*0x04*/ float         Y;
/*0x08*/ float         X;
/*0x0C*/ float         Z;
/*0x10*/ float         Heading;
/*0x14*/ int           ZoneId;
/*0x18*/ int           FilterID;
/*0x1C*/ UINT          VehicleID;
/*0x20*/
};

} // namespace eqlib

using namespace eqlib;
