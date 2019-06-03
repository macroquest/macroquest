	BYTE        InPvPArea;                           // are we in a PvP area?
	int         Buyer;
	CPhysicsInfo LastCollision;
	UINT        EnduranceMax;
	bool        bBetaBuffed;
	UINT        NextSwim;
	int         AFK;
	UINT        StunTimer;
	FLOAT       GetMeleeRangeVar1;                   // used by GetMeleeRange (fScaleFactor)
	UINT        LastSecondaryUseTime;
	int         ManaCurrent;
	UINT        ACounter;                            // not sure what this one is for (m_uHibernatingCount)
	UINT        CombatSkillUsed[0x2];
	UINT        LastRefresh;                         // last 18 sec tick
	UINT        LastTimeStoodStill;
	bool        bBuffTimersOnHold;                   // no you can't control this client side so unless you want to get banned leave it alone
	CHAR        Suffix[0x80];
	DWORD       Meditating;
	int         CurrIOState;
	DWORD       PotionTimer;
	int         RealEstateItemId;
	int         PrimaryTintIndex;
	BYTE        CharClass;                           // Im pretty sure this isnt working
	UINT        LastTrapDamageTime;
	bool        Sneak;
	BYTE        FD;
	int         SomethingElse;
	DWORD       LastCastTime;
	bool        bOfflineMode;
	int         NpcTintIndex;
	bool        bTempPet;
	BYTE        Type2;
	CHAR        GM;
	int         Trader;                              // found in CEverQuest__RightClickedOnPlayer_x
	void*       pTouchingSwitch;                     // need to get that in here : struct _EQSWITCH
	BYTE        LastAttack;
	BYTE        IntimidateCount;
	UINT        SitStartTime;
	int         IsAttacking;                         // need to investigate
	int         EnduranceCurrent;
	SPAWNINFO*  pViewPlayer;
	DWORD       LoginSerial;
	CHAR        LoginRelated[0x20];
	void*       pRaceGenderInfo;                     // todo this is not a void* so... map the CRaceGenderInfo class
	UINT        SpellCooldownETA;
	CHAR        DragNames[0x2][0x40];
	UINT        LastPrimaryUseTime;
	int         Dontknowyet2;
	bool        bAnimationOnPop;
	BYTE        GMRank;
	CHAR        Handle[0x20];
	FLOAT       MerchantGreed;
	int64_t     GuildID;
	UINT        TimeStamp;                           // updates all the time including when on a mount
	int         AltAttack;
	bool        bSummoned;                           // by a PC or by anyone? need to investigate
	bool        PvPFlag;
	bool        Mercenary;
	bool        bSwitchMoved;                        // true when a door moves near the spawn
	int         SomeData[0x2];
	BYTE        IsPassenger;                         // if u are on a boat or airship or whatever
	EQC_INFO*   spawneqc_info;
	CHAR        Title[0x80];
	int64_t     HPMax;
	UINT        NextIntimidateTime;
	UINT        FishingETA;
	UINT        LastResendAddPlayerPacket;
	UINT        CombatSkillTicks[0x2];
	UINT        LastRangedUsedTime;
	UINT        SpellGemETA[0xf];                    // InnateETA is now the last member in this array
	int         Anon;                                // found in EQPlayer__SetNameSpriteTint_x
	CHAR        DraggingPlayer[0x40];
	int         Stuff;
	bool        bAttackRelated;
	int         ManaMax;
	int         DoSpecialMelee;
	BYTE        Blind;
	FLOAT       RunSpeed;                            // 0.70 on runspeed 5...
	EqItemGuid  realEstateItemGuid;
	BYTE        StandState;
	int         berserker;
	int         Deity;
	FLOAT       ViewHeight;
	bool        bStationary;
	int64_t     HPCurrent;
	UINT        CorpseDragCount;
	UINT        LastMealTime;                        // last time we eat or drank
	bool        LFG;
	int         DontKnowYet;
	int         LastCastNum;
	BYTE        HoldingAnimation;                    // todo: create enum for this byte. Holding: Nothing=0 A RightHand Weapon=1 A Shield=2 Dual Wielding Two Weapons=3 A Spear=4 A LeftHand Weapon=5 A Two Handed Weapon=6 A bow=7
	UINT        MasterID;
	bool        bShowHelm;
	BYTE        FishingEvent;
	FLOAT       MissileRangeToTarget;
	FLOAT       CameraOffset;
	FLOAT       AnimationSpeedRelated;
	bool        Linkdead;
	BYTE        FindBits;
	UINT        MinuteTimer;
	DWORD       Zone;
	FLOAT       BearingToTarget;
	int         SecondaryTintIndex;
	LAUNCHSPELLDATA CastingData;                     // size: 0x58
	int         PetID;
	BYTE        TitleVisible;
	int         RealEstateID;
	int         AARank;                              // this really is the title id
	BYTE        Level;
	UINT        RespawnTimer;                        // its actually TimeOfDeath...TimeStamp of when RespawnWnd will close - 0 when you're alive
	BYTE        HmmWhat;
	DWORD**     ppUDP;                               // UdpLibrary::UdpConnection
	FLOAT       MyWalkSpeed;
	int         WarCry;
	BYTE        Light;
	int         HideMode;
	UINT        LastTick;
	bool        bAlwaysShowAura;
	FLOAT       FallingStartZ;
