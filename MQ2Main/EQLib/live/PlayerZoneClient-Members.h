	BYTE        FishingEvent;
	BYTE        Blind;
	int         NpcTintIndex;
	UINT        LastRangedUsedTime;
	int         berserker;
	bool        bSwitchMoved;                        // true when a door moves near the spawn
	int         EnduranceCurrent;
	bool        bBetaBuffed;
	UINT        LastPrimaryUseTime;
	int         RealEstateItemId;
	DWORD       PotionTimer;
	BYTE        HoldingAnimation;                    // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
	BYTE        GMRank;
	int         Anon;                                // found in EQPlayer__SetNameSpriteTint_x
	DWORD       Zone;
	CHAR        Suffix[0x80];
	int         WarCry;
	UINT        SitStartTime;
	int         DontKnowYet;
	bool        Sneak;
	int64_t     GuildID;
	int         Stuff;
	UINT        LastSecondaryUseTime;
	CHAR        Title[0x80];
	void*       pRaceGenderInfo;                     // todo this is not a void* so... map the CRaceGenderInfo class
	int         ManaCurrent;
	int         AARank;                              // this really is the title id
	bool        bOfflineMode;
	UINT        LastTick;
	BYTE        IsPassenger;                         // if u are on a boat or airship or whatever
	int         Dontknowyet2;
	UINT        SpellGemETA[0xf];                    // InnateETA is now the last member in this array
	bool        bAnimationOnPop;
	CHAR        DraggingPlayer[0x40];
	BYTE        FD;
	bool        LFG;
	FLOAT       RunSpeed;                            // 0.70 on runspeed 5...
	UINT        MasterID;
	BYTE        FindBits;
	FLOAT       MissileRangeToTarget;
	int64_t     HPMax;
	BYTE        InPvPArea;                           // are we in a PvP area?
	CHAR        GM;
	CHAR        LoginRelated[0x20];
	UINT        RespawnTimer;                        // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
	UINT        MinuteTimer;
	int         DoSpecialMelee;
	int         IsAttacking;                         // need to investigate
	int         AFK;
	int         ManaMax;
	UINT        ACounter;                            // not sure what this one is for (m_uHibernatingCount)
	int         HideMode;
	UINT        NextSwim;
	bool        bBuffTimersOnHold;                   // no you can't control this client side so unless you want to get banned leave it alone
	int         LastCastNum;
	UINT        LastResendAddPlayerPacket;
	int         PrimaryTintIndex;
	UINT        LastMealTime;                        // last time we eat or drank
	BYTE        Light;
	UINT        StunTimer;
	BYTE        HmmWhat;
	SPAWNINFO*  pViewPlayer;
	UINT        CorpseDragCount;
	BYTE        Type2;
	bool        bTempPet;
	FLOAT       ViewHeight;
	bool        Linkdead;
	DWORD**     ppUDP;                               // UdpLibrary::UdpConnection
	CHAR        Handle[0x20];
	UINT        CombatSkillUsed[0x2];
	UINT        SpellCooldownETA;
	BYTE        IntimidateCount;
	FLOAT       CameraOffset;
	bool        Mercenary;
	BYTE        Level;
	int         SomeData[0x2];
	LAUNCHSPELLDATA CastingData;                     // size: 0x58
	DWORD       LoginSerial;
	BYTE        StandState;
	DWORD       Meditating;
	EQC_INFO*   spawneqc_info;
	bool        bStationary;
	UINT        FishingETA;
	UINT        LastTrapDamageTime;
	int         CurrIOState;
	bool        bAttackRelated;
	EqItemGuid  realEstateItemGuid;
	int         Deity;
	FLOAT       MerchantGreed;
	bool        PvPFlag;
	FLOAT       BearingToTarget;
	UINT        LastRefresh;                         // last 18 sec tick
	UINT        EnduranceMax;
	bool        bSummoned;                           // by a PC or by anyone? need to investigate
	FLOAT       MyWalkSpeed;
	int         AltAttack;
	int         Buyer;
	int         RealEstateID;
	int         PetID;
	bool        bAlwaysShowAura;
	UINT        LastTimeStoodStill;
	DWORD       LastCastTime;
	UINT        CombatSkillTicks[0x2];
	FLOAT       AnimationSpeedRelated;
	BYTE        TitleVisible;
	int         SomethingElse;
	BYTE        CharClass;                           // Im pretty sure this isnt working
	UINT        NextIntimidateTime;
	void*       pTouchingSwitch;                     // need to get that in here : struct _EQSWITCH
	int         SecondaryTintIndex;
	FLOAT       GetMeleeRangeVar1;                   // used by GetMeleeRange (fScaleFactor)
	bool        bShowHelm;
	BYTE        LastAttack;
	int         Trader;                              // found in CEverQuest__RightClickedOnPlayer_x
	CPhysicsInfo LastCollision;
	UINT        TimeStamp;                           // updates all the time including when on a mount
	int64_t     HPCurrent;
	FLOAT       FallingStartZ;
	CHAR        DragNames[0x2][0x40];
