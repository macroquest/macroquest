using System;
using System.Collections.Generic;
using System.Text;
using ISXEQ.EQTypes;

namespace ISXEQ
{
    #region enums
    public enum eInvSlot
    {
        charm = 0,
        leftear = 1,
        head = 2,
        face = 3,
        rightear = 4,
        neck = 5,
        shoulder = 6,
        arms = 7,
        back = 8,
        leftwrist = 9,
        rightwrist = 10,
        ranged = 11,
        hands = 12,
        mainhand = 13,
        offhand = 14,
        leftfinger = 15,
        rightfinger = 16,
        chest = 17,
        legs = 18,
        feet = 19,
        waist = 20,
        powersource = 21,
        ammo = 22,
        pack1 = 23,
        pack2 = 24,
        pack3 = 25,
        pack4 = 26,
        pack5 = 27,
        pack6 = 28,
        pack7 = 29,
        pack8 = 30
    }

    public enum eBankSlot
    {
        bank1 = 2000,
        bank2 = 2001,
        bank3 = 2002,
        bank4 = 2003,
        bank5 = 2004,
        bank6 = 2005,
        bank7 = 2006,
        bank8 = 2007,
        bank9 = 2008,
        bank10 = 2009,
        bank11 = 2010,
        bank12 = 2011,
        bank13 = 2012,
        bank14 = 2013,
        bank15 = 2014,
        bank16 = 2015,
        sharedbank1 = 2500,
        sharedbank2 = 2501
    }

    public enum eTradeWindow
    {
        trade1,
        trade2,
        trade3,
        trade4,
        trade5,
        trade6,
        trade7,
        trade8
    }

    public enum eCorpseWindow
    {
        loot1,
        loot2,
        loot3,
        loot4,
        loot5,
        loot6,
        loot7,
        loot8,
        loot9,
        loot10,
        loot11,
        loot12,
        loot13,
        loot14,
        loot15,
        loot16,
        loot17,
        loot18,
        loot19,
        loot20,
        loot21,
        loot22,
        loot23,
        loot24,
        loot25,
        loot26,
        loot27,
        loot28,
        loot29,
        loot30,
        loot31,
        loot32
    }

    /// <summary>
    /// Environmental containers (forge, kiln, etc...)
    /// </summary>
    public enum eEnvironmentalWindow
    {
        enviro1,
        enviro2,
        enviro3,
        enviro4,
        enviro5,
        enviro6,
        enviro7,
        enviro8,
        enviro9,
        enviro10
    }

    /// <summary>
    /// Merchant window slots
    /// </summary>
    public enum eMerchantWindow
    {
        merchant1,
        merchant2,
        merchant3,
        merchant4,
        merchant5,
        merchant6,
        merchant7,
        merchant8,
        merchant9,
        merchant10,
        merchant11,
        merchant12,
        merchant13,
        merchant14,
        merchant15,
        merchant16,
        merchant17,
        merchant18,
        merchant19,
        merchant20,
        merchant21,
        merchant22,
        merchant23,
        merchant24,
        merchant25,
        merchant26,
        merchant27,
        merchant28,
        merchant29,
        merchant30,
        merchant31,
        merchant32,
        merchant33,
        merchant34,
        merchant35,
        merchant36,
        merchant37,
        merchant38,
        merchant39,
        merchant40,
        merchant41,
        merchant42,
        merchant43,
        merchant44,
        merchant45,
        merchant46,
        merchant47,
        merchant48,
        merchant49,
        merchant50,
        merchant51,
        merchant52,
        merchant53,
        merchant54,
        merchant55,
        merchant56,
        merchant57,
        merchant58,
        merchant59,
        merchant60,
        merchant61,
        merchant62,
        merchant63,
        merchant64,
        merchant65,
        merchant66,
        merchant67,
        merchant68,
        merchant69,
        merchant70,
        merchant71,
        merchant72,
        merchant73,
        merchant74,
        merchant75,
        merchant76,
        merchant77,
        merchant78,
        merchant79,
        merchant80
    }

    public enum eBazaarWindow
    {
        bazaar1,
        bazaar2,
        bazaar3,
        bazaar4,
        bazaar5,
        bazaar6,
        bazaar7,
        bazaar8,
        bazaar9,
        bazaar10,
        bazaar11,
        bazaar12,
        bazaar13,
        bazaar14,
        bazaar15,
        bazaar16,
        bazaar17,
        bazaar18,
        bazaar19,
        bazaar20,
        bazaar21,
        bazaar22,
        bazaar23,
        bazaar24,
        bazaar25,
        bazaar26,
        bazaar27,
        bazaar28,
        bazaar29,
        bazaar30,
        bazaar31,
        bazaar32,
        bazaar33,
        bazaar34,
        bazaar35,
        bazaar36,
        bazaar37,
        bazaar38,
        bazaar39,
        bazaar40,
        bazaar41,
        bazaar42,
        bazaar43,
        bazaar44,
        bazaar45,
        bazaar46,
        bazaar47,
        bazaar48,
        bazaar49,
        bazaar50,
        bazaar51,
        bazaar52,
        bazaar53,
        bazaar54,
        bazaar55,
        bazaar56,
        bazaar57,
        bazaar58,
        bazaar59,
        bazaar60,
        bazaar61,
        bazaar62,
        bazaar63,
        bazaar64,
        bazaar65,
        bazaar66,
        bazaar67,
        bazaar68,
        bazaar69,
        bazaar70,
        bazaar71,
        bazaar72,
        bazaar73,
        bazaar74,
        bazaar75,
        bazaar76,
        bazaar77,
        bazaar78,
        bazaar79,
        bazaar80
    }

    public enum eInspectWindow
    {
        inspect1,
        inspect2,
        inspect3,
        inspect4,
        inspect5,
        inspect6,
        inspect7,
        inspect8,
        inspect9,
        inspect10,
        inspect11,
        inspect12,
        inspect13,
        inspect14,
        inspect15,
        inspect16,
        inspect17,
        inspect18,
        inspect19,
        inspect20,
        inspect21,
        inspect22,
        inspect23,
        inspect24,
        inspect25,
        inspect26,
        inspect27,
        inspect28,
        inspect29,
        inspect30,
        inspect31,
        inspect32
    }

    public enum eWindowNames
    {
        AAW_ArchetypePage,
        AAW_ClassPage,
        AAW_GeneralPage,
        AAW_Page4,
        AAW_Page5,
        AAW_Page6,
        AAWindow,
        ActionsAbilitiesPage,
        ActionsCombatPage,
        ActionsMainPage,
        ActionsSocialsPage,
        ActionsWindow,
        ActorParticlesPage,
        AdventureLeaderboardWnd,
        AdventureMerchantWnd,
        AdventureRequestWnd,
        AdventureStatsWnd,
        AlarmWnd,
        AltStorageWnd,
        BazaarSearchWnd,
        BazaarWnd,
        BigBankWnd,
        BodyTintWnd,
        BookWindow,
        BreathWindow,
        BuffWindow,
        BugReportWindow,
        BZW_BazaarSlotsWnd,
        CastingWindow,
        CastSpellWnd,
        CJNPC_Layout,
        ColorPickerWnd,
        CombatAbilityWnd,
        CombatSkillSelectWnd,
        COMBW_CombineArea,
        COMBW_ComponentArea,
        COMBW_ContainerArea,
        COMBW_FavoritesArea,
        COMBW_FlagsArea,
        COMBW_LeftSideArea,
        COMBW_RecipeListArea,
        COMBW_RightSideArea,
        COMBW_SearchArea,
        CompassWindow,
        ConfirmationDialogBox,
        CursorAttachment,
        DynamicZoneWnd,
        DZLeaderSection,
        EditLabelWnd,
        EnvironmentParticlesPage,
        FacePickWindow,
        FeedbackWindow,
        FileSelectionWnd,
        FindLocationWnd,
        Friends_TimerSlider0,
        FriendsWindow,
        FW_FriendsPage,
        FW_IgnorePage,
        GemsGameWnd,
        GGW_GameView,
        GiveWnd,
        GroupInfoPage,
        GroupListPage,
        GroupSearchFiltersWnd,
        GroupSearchWnd,
        GroupWindow,
        GT_MemberPage,
        GT_NotePage,
        GuildBankWnd,
        GuildManagementWnd,
        HelpWindow,
        HotButtonWnd,
        InspectWnd,
        InventoryWindow,
        IW_CharacterView,
        JournalCatWnd,
        JournalNPCWnd,
        KnowledgeBasePage,
        LargeDialogWindow,
        LeadershipWindow,
        LEW_GroupPage,
        LEW_RaidPage,
        LoadskinWnd,
        LootWnd,
        LW_LootInvWnd,
        MapToolbarWnd,
        MapViewWnd,
        MerchantWnd,
        MusicPlayerWnd,
        MVW_MapRenderArea,
        MW_MerchantSlotsWnd,
        MW_SlotsWndThree,
        MW_SlotsWndTwo,
        NewTicketPage,
        NoteWindow,
        OpenTicketsPage,
        OptionsChatPage,
        OptionsColorPage,
        OptionsDisplayPage,
        OptionsGeneralPage,
        OptionsKeyboardPage,
        OptionsMousePage,
        OptionsWindow,
        PetInfoWindow,
        PIW_BuffWindow,
        PlayerInfoPage,
        PlayerListPage,
        PlayerNotesWindow,
        PlayerWindow,
        PvpLeaderboardWnd,
        PvPMerchantWnd,
        PvPStatsWnd,
        QuantityWnd,
        RAID_MemberPage,
        RAID_NotePage,
        RaidOptionsWindow,
        RaidWindow,
        RespawnWindow,
        SelectorWindow,
        ShortDurationBuffWindow,
        SkillsSelectWindow,
        SkillsWindow,
        SocialEditWnd,
        SpellBookWnd,
        SpellParticlesPage,
        StoryWnd,
        SystemInfoDialogBox,
        TargetOfTargetWindow,
        TargetWindow,
        TBW_LabelWnd,
        TBW_Layout,
        TextEntryWnd,
        TicketCommentWindow,
        TicketWindow,
        TipWindow,
        TMW_ActiveBenefitArea,
        TMW_BenefitMasterArea,
        TMW_DonateWnd,
        TMW_LabelWnd,
        TMW_Layout,
        TrackingWnd,
        TradeskillWnd,
        TradeWnd,
        TrainWindow,
        TributeBenefitWnd,
        TributeMasterWnd,
        VideoModesWindow
    }
    #endregion

    public class EQ
    {
        public static EQAltAbility AltAbility(int Number)
        {
            return new EQAltAbility(LavishScriptAPI.LavishScript.Objects.GetObject("AltAbility", Number.ToString()));
        }
        public static EQAltAbility AltAbility(string Name)
        {
            return new EQAltAbility(LavishScriptAPI.LavishScript.Objects.GetObject("AltAbility", Name));
        }

        public static EQCorpse Corpse
        {
            get
            {
                return new EQCorpse(LavishScriptAPI.LavishScript.Objects.GetObject("Corpse"));
            }
        }

        public static EQItem Cursor
        {
            get
            {
                return new EQItem(LavishScriptAPI.LavishScript.Objects.GetObject("Cursor"));
            }
        }

        public static EQDynamicZone DynamicZone
        {
            get
            {
                return new EQDynamicZone(LavishScriptAPI.LavishScript.Objects.GetObject("DynamicZone"));
            }
        }

        public static EQItem FindItem(string partial_name)
        {
            return new EQItem(LavishScriptAPI.LavishScript.Objects.GetObject("FindItem", partial_name));
        }
        public static EQItem FindItem(string name, bool exact)
        {
            if (exact)
                name.Insert(0, "=");
            return new EQItem(LavishScriptAPI.LavishScript.Objects.GetObject("FindItem", name));
        }

        public static EQItem FindItemBank(string partial_name)
        {
            return new EQItem(LavishScriptAPI.LavishScript.Objects.GetObject("FindItemBank", partial_name));
        }
        public static EQItem FindItemBank(string name, bool exact)
        {
            if (exact)
                name.Insert(0, "=");
            return new EQItem(LavishScriptAPI.LavishScript.Objects.GetObject("FindItemBank", name));
        }

        public static int FindItemCount(string partial_name)
        {
            return LavishScriptAPI.LavishScript.Objects.GetObject<int>("FindItemCount", partial_name);
        }
        public static int FindItemCount(string name, bool exact)
        {
            if (exact)
                name.Insert(0, "=");
            return LavishScriptAPI.LavishScript.Objects.GetObject<int>("FindItemCount", name);
        }

        public static int FindItemBankCount(string partial_name)
        {
            return LavishScriptAPI.LavishScript.Objects.GetObject<int>("FindItemBankCount", partial_name);
        }
        public static int FindItemBankCount(string name, bool exact)
        {
            if (exact)
                name.Insert(0, "=");
            return LavishScriptAPI.LavishScript.Objects.GetObject<int>("FindItemBankCount", name);
        }

        public static EQTime GameTime
        {
            get
            {
                return new EQTime(LavishScriptAPI.LavishScript.Objects.GetObject("GameTime"));
            }
        }

        public static EQGround Ground
        {
            get
            {
                return new EQGround(LavishScriptAPI.LavishScript.Objects.GetObject("Ground"));
            }
        }

        public static EQGroup Group
        {
            get
            {
                return new EQGroup(LavishScriptAPI.LavishScript.Objects.GetObject("Group"));
            }
        }

        public static EQHeading Heading(int degrees_clockwise)
        {
            return new EQHeading(LavishScriptAPI.LavishScript.Objects.GetObject("Heading", degrees_clockwise.ToString()));
        }
        public static EQHeading Heading(float Y, float X)
        {
            return new EQHeading(LavishScriptAPI.LavishScript.Objects.GetObject("Heading", Y.ToString(),X.ToString()));
        }

        public static EQInvSlot InvSlot(eInvSlot slot)
        {
            return new EQInvSlot(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("InvSlot", slot.ToString()));
        }        
        public static EQInvSlot InvSlot(string Name)
        {
            return new EQInvSlot(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("InvSlot", Name));
        }
        public static EQInvSlot InvSlot(int Number)
        {
            return new EQInvSlot(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("InvSlot", Number.ToString()));
        }

        public static EQSpawn LastSpawn(int Number)
        {
            return new EQSpawn(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("LastSpawn", Number.ToString()));
        }

        public static bool LineOfSight(float from_Y, float from_X, float from_Z, float to_Y, float to_X, float to_Z)
        {
            return LavishScriptAPI.LavishScript.Objects.GetObject<bool>("LineOfSight", from_Y.ToString(), from_X.ToString(), from_Z.ToString(), to_Y.ToString(), to_X.ToString(), to_Z.ToString());
        }

        public static EQMacroQuest MacroQuest
        {
            get
            {
                return new EQMacroQuest(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("MacroQuest"));
            }
        }

        public static EQCharacter Me
        {
            get
            {
                return new EQCharacter(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Me"));
            }
        }

        public static EQMerchant Merchant
        {
            get
            {
                return new EQMerchant(LavishScriptAPI.LavishScript.Objects.GetObject("Merchant"));
            }
        }

        public static EQSpawn NearestSpawn()
        {
            return new EQSpawn(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("NearestSpawn", "1"));
        }
        public static EQSpawn NearestSpawn(int Nth)
        {
            return new EQSpawn(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("NearestSpawn", Nth.ToString()));
        }
        public static EQSpawn NearestSpawn(params string[] Search_args)
        {
            return new EQSpawn(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("NearestSpawn", Search_args));
        }

        public static EQRaid Raid
        {
            get
            {
                return new EQRaid(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Raid"));
            }
        }

        public static EQItem SelectedItem
        {
            get
            {
                return new EQItem(LavishScriptAPI.LavishScript.Objects.GetObject("SelectedItem"));
            }
        }

        public static EQSkill Skill(int Number)
        {
            return new EQSkill(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Skill",Number.ToString()));
        }
        public static EQSkill Skill(string Name)
        {
            return new EQSkill(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Skill", Name));
        }

        public static EQSpawn Spawn(int ID)
        {
            return new EQSpawn(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Spawn", ID.ToString()));
        }
        public static EQSpawn Spawn(params string[] Search_args)
        {
            return new EQSpawn(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("NearestSpawn", Search_args));
        }

        public static int SpawnCount()
        {
            return LavishScriptAPI.LavishScript.Objects.GetObject<int>("SpawnCount");
        }
        public static int SpawnCount(params string[] Search_args)
        {
            return LavishScriptAPI.LavishScript.Objects.GetObject<int>("SpawnCount", Search_args);
        }

        public static EQSpell Spell(int ID)
        {
            return new EQSpell(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Spell", ID.ToString()));
        }
        public static EQSpell Spell(string name)
        {
            return new EQSpell(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Spell", name));
        }

        public static EQSwitch Switch
        {
            get { return new EQSwitch(LavishScriptAPI.LavishScript.Objects.GetObject("Switch")); }
        }

        public static EQSpawn Target
        {
            get { return new EQSpawn(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Target")); }
        }


        public static EQWindow Window(eWindowNames name)
        {
            return new EQWindow(LavishScriptAPI.LavishScript.Objects.GetObject("Window", name.ToString()));
        }
        public static EQWindow Window(string name)
        {
            return new EQWindow(LavishScriptAPI.LavishScript.Objects.GetObject("Window", name));
        }

        public static EQCurrentZone CurrentZone
        {
            get { return new EQCurrentZone(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Zone")); }
        }
        public static EQZone Zone(string short_name)
        {
            return new EQZone(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Zone",short_name));
        }
        public static EQZone Zone(int ID)
        {
            return new EQZone(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Zone",ID.ToString()));
        }
    }
}
