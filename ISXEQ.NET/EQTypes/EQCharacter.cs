using System;
using System.Collections.Generic;
using LavishVMAPI;
using IS = InnerSpaceAPI.InnerSpace;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Character type.
    /// 
    /// Here is a list of members that are inside the MQ2CharacterType but are not
    /// implemented:
    /// BaseAGI
    /// BaseCHA
    /// BaseDEX
    /// BaseINT
    /// BaseSTA
    /// BaseSTR
    /// BaseWIS
    /// GukEarned
    /// LDoNPoints
    /// MirEarned
    /// MMEarned
    /// RujEarned
    /// TakEarned
    /// PracticePoints
    /// </summary>
    public class EQCharacter : EQSpawn
    {
        public EQCharacter()
            : base(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Me"))
        {
        }

        public EQCharacter(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }


        #region Methods
        public void Stand()
        {
            ExecuteMethod("Stand");
        }

        public void Sit()
        {
            ExecuteMethod("Sit");
        }

        public void Dismount()
        {
            ExecuteMethod("Dismount");
        } 
        #endregion

        #region Properties

        /// <summary>
        /// AA exp as a raw number
        /// </summary>
        public int AAExp
        {
            get { return GetMember<int>( "AAExp"); }
        }

        /// <summary>
        /// Unused AA points
        /// </summary>
        public int AAPoints
        {
            get { return GetMember<int>( "AAPoints"); }
        }

        /// <summary>
        /// The number of points you have spent on AA abilities
        /// </summary>
        public int AAPointsSpent
        {
            get { return GetMember<int>( "AAPointsSpent"); }
        }

        /// <summary>
        /// The total number of AA points you have
        /// </summary>
        public int AAPointsTotal
        {
            get { return GetMember<int>( "AAPointsTotal"); }
        }

        /// <summary>
        /// Doability button number this skill name is on
        /// </summary>
        public int Ability(int Slot)
        {
            return GetMember<int>( "Ability", Slot.ToString());
        }
        /// <summary>
        /// Doability button number this skill name is on
        /// </summary>
        public int Ability(string Name)
        {
            return GetMember<int>("Ability", Name);
        }

        /// <summary>
        /// Ability with this name ready?
        /// </summary>
        public bool AbilityReady(string Name)
        {
            return GetMember<bool>( "AbilityReady", Name);
        }
        /// <summary>
        /// Ability with this slot ready?
        /// </summary>
        public bool AbilityReady(int Slot)
        {
            return GetMember<bool>("AbilityReady", Slot.ToString());
        }

        /// <summary>
        /// Accuracy bonus from gear/spells
        /// </summary>
        public int AccuracyBonus
        {
            get { return GetMember<int>( "AccuracyBonus"); }
        }

        /// <summary>
        /// Returns a string of your group members (excluding you)
        /// Note: The MQ2 source indicates this isn't working as intended. I have doctored it to work correctly.
        /// </summary>
        public int ActiveFavorCost
        {
            get
            {
                int i = 0;

                try
                {
                    i = GetMember<int>( "ActiveFavorCost");
                }
                catch { }

                return i;
            }
        }

        /// <summary>
        /// Returns the total number of points you have spent in ability n
        /// </summary>
        public EQAltAbility AltAbility(int Number)
        {
            return new EQAltAbility(GetMember("AltAbility", Number.ToString()));
        }
        /// <summary>
        /// Returns the total number of points you have spent in ability name
        /// </summary>
        public EQAltAbility AltAbility(string Name)
        {
            return new EQAltAbility(GetMember("AltAbility", Name));
        }

        /// <summary>
        /// Alt ability readiness of ability name
        /// </summary>
        public bool AltAbilityReady(string Name)
        {
            return GetMember<bool>( "AltAbilityReady", Name);
        }
        public bool AltAbilityReady(int Number)
        {
            return GetMember<bool>("AltAbilityReady", Number.ToString());
        }

        /// <summary>
        /// Alt ability reuse time (seconds) left of ability name
        /// </summary>
        public int AltAbilityTimer(string Name)
        {
            return GetMember<int>( "AltAbilityTimer", Name);
        }
        /// <summary>
        /// Alt ability reuse time (seconds) left of ability n
        /// </summary>
        public int AltAbilityTimer(int Number)
        {
            return GetMember<int>("AltAbilityTimer", Number.ToString());
        }


        /// <summary>
        /// Alternate timer ready? (Bash/Slam/Frenzy/Backstab. Note that AbilityReady works fine with most of these)
        /// </summary>
        public bool AltTimerReady
        {
            get { return GetMember<bool>( "AltTimerReady"); }
        }

        /// <summary>
        /// Character Agility
        /// </summary>
        public int AGI
        {
            get { return GetMember<int>( "AGI"); }
        }

        /// <summary>
        /// Group Leader?
        /// </summary>
        public bool AmIGroupLeader
        {
            get 
            { 
                //This member returns a string. We need to convert it to bool.
                const string True = "TRUE";
                string s = GetMember<string>( "AmIGroupLeader");
                return (s==True); 
            }
        }

        /// <summary>
        /// Attack bonus from gear/spells
        /// </summary>
        public int AttackBonus
        {
            get { return GetMember<int>( "AttackBonus"); }
        }

        /// <summary>
        /// Your Attack Speed %
        /// </summary>
        public int AttackSpeed
        {
            get { return GetMember<int>( "AttackSpeed"); }
        }

        /// <summary>
        /// Returns an EQSpell object of your aura.
        /// </summary>
        public EQSpell Aura()
        {
            return new EQSpell(GetPersistentMember("Aura"));
        }

        /// <summary>
        /// TRUE if AutoFire is activated.
        /// </summary>
        public bool AutoFire
        {
            get { return GetMember<bool>( "AutoFire"); }
        }

        /// <summary>
        /// Avoidance bonus from gear/spells
        /// </summary>
        public int AvoidanceBonus
        {
            get { return GetMember<int>( "AvoidanceBonus"); }
        }

        /// <summary>
        /// Item in this slot (1-18)
        /// </summary>
        public EQItem Bank(int Slot)
        {
            return new EQItem(GetMember("Bank", Slot.ToString())); 
        }

        /// <summary>
        /// Spell slot the spell with this name is assigned to in your spellbook
        /// </summary>
        public int Book_Slot(string Name)
        {
            return GetMember<int>( "Book", Name);
        }

        /// <summary>
        /// Returns Spell assigned to this slot in your spellbook
        /// </summary>
        public EQSpell Book_Spell(int Slot)
        {
            return new EQSpell(GetPersistentMember("Book", Slot.ToString()));
        }

        /// <summary>
        /// Finds buff with this name
        /// </summary>
        public EQBuff Buff(string Name)
        {
            return new EQBuff(GetMember("Buff", Name)); 
        }
        public EQBuff Buff(int Slot)
        {
            return new EQBuff(GetMember("Buff", Slot.ToString()));
        }

        /// <summary>
        /// Career favor
        /// </summary>
        public int CareerFavor
        {
            get { return GetMember<int>( "CareerFavor"); }
        }

        /// <summary>
        /// Total cash on your character, expressed in coppers (eg. if you are carrying 100pp, Cash will return 100000)
        /// </summary>
        public int Cash
        {
            get { return GetMember<int>( "Cash"); }
        }

        /// <summary>
        /// Banked cash in copper
        /// </summary>
        public int CashBank
        {
            get { return GetMember<int>( "CashBank"); }
        }

        /// <summary>
        /// Character Charisma
        /// </summary>
        public int CHA
        {
            get { return GetMember<int>( "CHA"); }
        }

        /// <summary>
        /// In combat?
        /// </summary>
        public bool Combat
        {
            get { return GetMember<bool>( "Combat"); }
        }

        /// <summary>
        /// Combat Effects bonus from gear/spells
        /// </summary>
        public int CombatEffectsBonus
        {
            get { return GetMember<int>( "CombatEffectsBonus"); }
        }

        /// <summary>
        /// Copper
        /// </summary>
        public int Copper
        {
            get { return GetMember<int>( "Copper"); }
        }

        /// <summary>
        /// Copper in bank
        /// </summary>
        public int CopperBank
        {
            get { return GetMember<int>( "CopperBank"); }
        }

        /// <summary>
        /// Number of buffs you have, not including short duration buffs
        /// </summary>
        public int CountBuffs
        {
            get { return GetMember<int>( "CountBuffs"); }
        }

        /// <summary>
        /// Combat ability by number in your list 
        /// </summary>
        public EQSpell CombatAbilitySpell(int Number)
        {
            return new EQSpell(GetPersistentMember("CombatAbility", Number.ToString())); 
        }

        /// <summary>
        /// Combat ability number in your list by name 
        /// </summary>
        public int CombatAbilityNumber(string Name)
        {
            return GetMember<int>( "CombatAbility", Name);
        }

        public bool CombatAbilityReady(string Name)
        {
            return GetMember<bool>( "CombatAbilityReady", Name);
        }
        public bool CombatAbilityReady(int Number)
        {
            return GetMember<bool>("CombatAbilityReady", Number.ToString());
        }

        /// <summary>
        /// Returns the time remaining before the Combat Ability is usable
        /// </summary>
        public int CombatAbilityTimer(string Name)
        {
            return GetMember<int>( "CombatAbilityTimer", Name);
        }

        /// <summary>
        /// Current Endurance
        /// </summary>
        public int CurrentEndurance
        {
            get { return GetMember<int>( "CurrentEndurance"); }
        }

        /// <summary>
        /// Current favorCurrentEndurance
        /// </summary>
        public int CurrentFavor
        {
            get { return GetMember<int>( "CurrentFavor"); }
        }

        /// <summary>
        /// Current mana
        /// </summary>
        public int CurrentMana
        {
            get { return GetMember<int>( "CurrentMana"); }
        }

        /// <summary>
        /// Character current weight
        /// </summary>
        public int CurrentWeight
        {
            get { return GetMember<int>( "CurrentWeight"); }
        }

        /// <summary>
        /// Damage Shield bonus from gear/spells
        /// </summary>
        public int DamageShieldBonus
        {
            get { return GetMember<int>( "DamageShieldBonus"); }
        }

        /// <summary>
        /// Damage absorption remaining
        /// </summary>
        public int Dar
        {
            get { return GetMember<int>( "Dar"); }
        }

        /// <summary>
        /// Character Dexterity
        /// </summary>
        public int DEX
        {
            get { return GetMember<int>( "DEX"); }
        }

        /// <summary>
        /// DoT Shield bonus from gear/spells
        /// </summary>
        public int DoTShieldBonus
        {
            get { return GetMember<int>( "DoTShieldBonus"); }
        }

        /// <summary>
        /// Doubloons character has
        /// </summary>
        public int Doubloons
        {
            get { return GetMember<int>( "Doubloons"); }
        }

        /// <summary>
        /// Returns current downtime.
        /// </summary>
        public EQTicks Downtime
        {
            get { return new EQTicks(GetMember("Downtime")); }
        }

        /// <summary>
        /// Gets your drunkness level
        /// </summary>
        public int Drunk
        {
            get { return GetMember<int>( "Drunk"); }
        }

        /// <summary>
        /// Returns how many of this crystal you have in your inventory
        /// </summary>
        public int EbonCrystals
        {
            get { return GetMember<int>( "EbonCrystals"); }
        }

        /// <summary>
        /// Current endurance. Grandfathered, CurrentEndurance should be used instead.
        /// </summary>
        public int Endurance
        {
            get { return GetMember<int>( "Endurance"); }
        }

        /// <summary>
        /// Endurance bonus from gear/spells
        /// </summary>
        public int EnduranceBonus
        {
            get { return GetMember<int>( "EnduranceBonus"); }
        }

        /// <summary>
        /// Endurance regen from the last tick
        /// </summary>
        public int EnduranceRegen
        {
            get { return GetMember<int>( "EnduranceRegen"); }
        }

        /// <summary>
        /// Experience (of 330)
        /// </summary>
        public int Exp
        {
            get { return GetMember<int>( "Exp"); }
        }

        /// <summary>
        /// Info about Fellowship.
        /// </summary>
        public EQFellowship Fellowship
        {
            get { return new EQFellowship(GetMember("Fellowship")); }
        }

        /// <summary>
        /// Number of open buff slots (not counting the bard buff slots)
        /// </summary>
        public int FreeBuffSlots
        {
            get { return GetMember<int>( "FreeBuffSlots"); }
        }

        /// <summary>
        /// Count of free inventory spaces
        /// </summary>
        public int FreeInventory
        {
            get { return GetMember<int>( "FreeInventory"); }
        }

        /// <summary>
        /// Count of free inventory spaces of at least n size (giant=4)
        /// </summary>
        public int FreeInventoryOfSize(int Size)
        {
            return GetMember<int>( "FreeInventory", Size.ToString());
        }

        /// <summary>
        /// The slot # with this spell name
        /// </summary>
        public int Gem(string Name)
        {
            return GetMember<int>( "Gem", Name);
        }

        /// <summary>
        /// The spell in this slot #
        /// </summary>
        public EQSpell GemSpell(int Slot)
        {
            return new EQSpell(GetPersistentMember("Gem", Slot.ToString()));
        }

        /// <summary>
        /// Gold on character
        /// </summary>
        public int Gold
        {
            get { return GetMember<int>( "Gold"); }
        }

        /// <summary>
        /// Gold in bank
        /// </summary>
        public int GoldBank
        {
            get { return GetMember<int>( "GoldBank"); }
        }

        /// <summary>
        /// Current group assist target
        /// </summary>
        public EQSpawn GroupAssistTarget
        {
            get { return new EQSpawn(GetPersistentMember("GroupAssistTarget")); }
        }

        /// <summary>
        /// Grouped?
        /// </summary>
        public bool Grouped
        {
            get { return GetMember<bool>( "Grouped"); }
        }

        /// <summary>
        /// Group leadership exp
        /// </summary>
        public float GroupLeaderExp
        {
            get { return GetMember<float>("GroupLeaderExp"); }
        }

        /// <summary>
        /// Group leadership points
        /// </summary>
        public int GroupLeaderPoints
        {
            get { return GetMember<int>( "GroupLeaderPoints"); }
        }

        /// <summary>
        /// Returns a string of your group members (excluding you)
        /// Note: The MQ2 source indicates this isn't working as intended. Looks fine to me.
        /// </summary>
        public string GroupList
        {
            get 
            {
                string s = "";

                try
                {
                    s = GetMember<string>( "GroupList");
                }
                catch { }
                return s;
            }
        }

        /// <summary>
        /// Current group marked NPC (1-3)
        /// </summary>
        public EQSpawn GroupMarkNPC(int Number)
        {
            return new EQSpawn(GetPersistentMember("GroupMarkNPC", Number.ToString()));
        }

        /// <summary>
        /// How many people are in your group
        /// </summary>
        public int GroupSize
        {
            get { return GetMember<int>( "GroupSize"); }
        }

        /// <summary>
        /// Total LDoN points earned in Guk
        /// </summary>
        //public int GukEarned
        //{
        //    get { return GetMember<int>( "GukEarned"); }
        //}

        /// <summary>
        /// Hit point bonus from gear/spells
        /// </summary>
        public int HPBonus
        {
            get { return GetMember<int>( "HPBonus"); }
        }

        /// <summary>
        /// Hit point regeneration
        /// </summary>
        public int HPRegen
        {
            get { return GetMember<int>( "HPRegen"); }
        }

        /// <summary>
        /// HP regen bonus from gear/spells
        /// </summary>
        public int HPRegenBonus
        {
            get { return GetMember<int>( "HPRegenBonus"); }
        }

        /// <summary>
        /// Gets your Hunger level
        /// </summary>
        public int Hunger
        {
            get { return GetMember<int>( "Hunger"); }
        }

        /// <summary>
        /// Character Intelligence
        /// </summary>
        public int INT
        {
            get { return GetMember<int>( "INT"); }
        }

        /// <summary>
        /// Item in this slot name or number
        /// </summary>
        public EQItem Inventory(int Slot)
        {
            return new EQItem(GetMember("Inventory", Slot.ToString())); 
        }
        public EQItem Inventory(string Name)
        {
            return new EQItem(GetMember("Inventory", Name));
        }

        /// <summary>
        /// Level of Delegate MA
        /// </summary>
        public int LADelegateMA
        {
            get { return GetMember<int>( "LADelegateMA"); }
        }

        /// <summary>
        /// Level of Delegate Mark NPC
        /// </summary>
        public int LADelegateMarkNPC
        {
            get { return GetMember<int>( "LADelegateMarkNPC"); }
        }

        /// <summary>
        /// Level of Find Path PC
        /// </summary>
        public int LAFindPathPC
        {
            get { return GetMember<int>( "LAFindPathPC"); }
        }

        /// <summary>
        /// Level of Health Enhancement
        /// </summary>
        public int LAHealthEnhancement
        {
            get { return GetMember<int>( "LAHealthEnhancement"); }
        }

        /// <summary>
        /// Level of Health Regen
        /// </summary>
        public int LAHealthRegen
        {
            get { return GetMember<int>( "LAHealthRegen"); }
        }

        /// <summary>
        /// Level of HoTT
        /// </summary>
        public int LAHoTT
        {
            get { return GetMember<int>( "LAHoTT"); }
        }

        /// <summary>
        /// Level of Inspect Buffs
        /// </summary>
        public int LAInspectBuffs
        {
            get { return GetMember<int>( "LAInspectBuffs"); }
        }

        /// <summary>
        /// Level of Mana Enhancement
        /// </summary>
        public int LAManaEnhancement
        {
            get { return GetMember<int>( "LAManaEnhancement"); }
        }

        /// <summary>
        /// Level of Mark NPC
        /// </summary>
        public int LAMarkNPC
        {
            get { return GetMember<int>( "LAMarkNPC"); }
        }

        /// <summary>
        /// Level of NPC Health
        /// </summary>
        public int LANPCHealth
        {
            get { return GetMember<int>( "LANPCHealth"); }
        }

        /// <summary>
        /// Level of Offense Enhancement
        /// </summary>
        public int LAOffenseEnhancement
        {
            get { return GetMember<int>( "LAOffenseEnhancement"); }
        }

        /// <summary>
        /// Level of Spell Awareness
        /// </summary>
        public int LASpellAwareness
        {
            get { return GetMember<int>( "LASpellAwareness"); }
        }


        /// <summary>
        /// The language you are currently using
        /// </summary>
        public string Language
        {
            get { return GetMember<string>( "Language"); }
        }

        /// <summary>
        /// Your skill in the selected language
        /// </summary>
        public int LanguageSkill(string Name)
        {
            return GetMember<int>( "LanguageSkill", Name);
        }

        /// <summary>
        /// Size of largest free inventory space
        /// </summary>
        public int LargestFreeInventory
        {
            get { return GetMember<int>( "LargestFreeInventory"); }
        }

        /// <summary>
        /// Available LDoN points
        /// </summary>
        //public int LDoNPoints
        //{
        //   get { return GetMember<int>( "LDoNPoints"); }
        //}

        /// <summary>
        /// Mana bonus from gear/spells
        /// </summary>
        public int ManaBonus
        {
            get { return GetMember<int>( "ManaBonus"); }
        }

        /// <summary>
        /// Mana regeneration
        /// </summary>
        public int ManaRegen
        {
            get { return GetMember<int>( "ManaRegen"); }
        }

        /// <summary>
        /// Mana regen bonus from gear/spells
        /// </summary>
        public int ManaRegenBonus
        {
            get { return GetMember<int>( "ManaRegenBonus"); }
        }

        /// <summary>
        /// Max endurance
        /// </summary>
        public int MaxEndurance
        {
            get { return GetMember<int>( "MaxEndurance"); }
        }

        /// <summary>
        /// Max mana
        /// </summary>
        public int MaxMana
        {
            get { return GetMember<int>( "MaxMana"); }
        }

        /// <summary>
        /// Total ldon points earned in Miragul
        /// </summary>
        //public int MirEarned
        //{
        //    get { return GetMember<int>( "MirEarned"); }
        //}

        /// <summary>
        /// Total ldon points earned in MM
        /// </summary>
        //public int MMEarned
        //{
        //    get { return GetMember<int>( "MMEarned"); }
        //}

        /// <summary>
        /// Orux character has
        /// </summary>
        public int Orux
        {
            get { return GetMember<int>( "Orux"); }
        }

        /// <summary>
        /// AA exp as a %
        /// </summary>
        public float PctAAExp
        {
            get { return GetMember<float>("PctAAExp"); }
        }

        /// <summary>
        /// Percent endurance. Yes, it's really an int.
        /// </summary>
        public int PctEndurance
        {
            get { return GetMember<int>( "PctEndurance"); }
        }

        /// <summary>
        /// Experience as a %
        /// </summary>
        public float PctExp
        {
            get { return GetMember<float>("PctExp"); }
        }

        /// <summary>
        /// ExpGroup leadership exp as a %
        /// </summary>
        public float PctGroupLeaderExp
        {
            get { return GetMember<float>("PctGroupLeaderExp"); }
        }

        /// <summary>
        /// Percent mana. Yes, it's really an int.
        /// </summary>
        public int PctMana
        {
            get { return GetMember<int>( "PctMana"); }
        }

        /// <summary>
        /// Raid leadership exp as a %
        /// </summary>
        public float PctRaidLeaderExp
        {
            get { return GetMember<float>("PctRaidLeaderExp"); }
        }

        /// <summary>
        /// The spell in this slot (1-29)
        /// </summary>
        public EQSpell PetBuffSpell(int Slot)
        {
            return new EQSpell(GetPersistentMember("PetBuff", Slot.ToString()));
        }

        /// <summary>
        /// Finds slot with this spell name
        /// </summary>
        public int PetBuffSlot(string Name)
        {
            return GetMember<int>( "PetBuff", Name);
        }

        /// <summary>
        /// Phosphenes character has
        /// </summary>
        public int Phosphenes
        {
            get { return GetMember<int>( "Phosphenes"); }
        }

        /// <summary>
        /// Phosphites character has
        /// </summary>
        public int Phosphites
        {
            get { return GetMember<int>( "Phosphites"); }
        }

        /// <summary>
        /// Platinum on your character
        /// </summary>
        public int Platinum
        {
            get { return GetMember<int>( "Platinum"); }
        }

        /// <summary>
        /// Platinum in bank
        /// </summary>
        public int PlatinumBank
        {
            get { return GetMember<int>( "PlatinumBank"); }
        }

        /// <summary>
        /// Shared-bank platinum
        /// </summary>
        public int PlatinumShared
        {
            get { return GetMember<int>( "PlatinumShared"); }
        }

        /// <summary>
        /// Returns COMBAT, DEBUFFED, COOLDOWN, ACTIVE, RESTING, UNKNOWN
        /// 
        /// Note: This is called PlayerState in the MQ2 manual, but is actually
        /// called CombatState inside macroquest.
        /// </summary>
        public string PlayerState
        {
            get { return GetMember<string>( "CombatState"); }
        }

        /// <summary>
        /// Returns COMBAT, DEBUFFED, COOLDOWN, ACTIVE, RESTING, UNKNOWN
        /// 
        /// Note: This is called PlayerState in the MQ2 manual, but is actually
        /// called CombatState inside macroquest.
        /// </summary>
        public string CombatState
        {
            get { return GetMember<string>( "CombatState"); }
        }

        /// <summary>
        /// 
        /// </summary>
        //public int PracticePoints
        //{
        //    get { return GetMember<int>( "PracticePoints"); }
        //}

        /// <summary>
        /// Returns how many of this crystal you have in your inventory
        /// </summary>
        public int RadiantCrystals
        {
            get { return GetMember<int>( "RadiantCrystals"); }
        }

        /// <summary>
        /// Current raid assist target (1-3)
        /// </summary>
        public EQSpawn RaidAssistTarget(int Number)
        {
            return new EQSpawn(GetPersistentMember("RaidAssistTarget", Number.ToString())); 
        }

        /// <summary>
        /// Raid leadership exp
        /// </summary>
        public float RaidLeaderExp
        {
            get { return GetMember<float>("RaidLeaderExp"); }
        }

        /// <summary>
        /// Raid leadership points
        /// </summary>
        public int RaidLeaderPoints
        {
            get { return GetMember<int>( "RaidLeaderPoints"); }
        }

        /// <summary>
        /// Current raid marked NPC (1-3)
        /// </summary>
        public EQSpawn RaidMarkNPC(int Number)
        {
            return new EQSpawn(GetPersistentMember("RaidMarkNPC", Number.ToString())); 
        }

        /// <summary>
        /// Ranged attack ready?
        /// </summary>
        public bool RangedReady
        {
            get { return GetMember<bool>( "RangedReady"); }
        }

        /// <summary>
        /// Total ldon points earned in ruj
        /// </summary>
        //public int RujEarned
        //{
        //    get { return GetMember<int>( "RujEarned"); }
        //}

        /// <summary>
        /// Returns TRUE or FALSE
        /// </summary>
        public bool Running
        {
            get { return GetMember<bool>( "Running"); }
        }

        /// <summary>
        /// Shielding bonus from gear/spells
        /// </summary>
        public int ShieldingBonus
        {
            get { return GetMember<int>( "ShieldingBonus"); }
        }

        /// <summary>
        /// Are you shrouded?
        /// </summary>
        public bool Shrouded
        {
            get { return GetMember<bool>( "Shrouded"); }
        }

        /// <summary>
        /// Silver on your character
        /// </summary>
        public int Silver
        {
            get { return GetMember<int>( "Silver"); }
        }

        /// <summary>
        /// Silver in bank
        /// </summary>
        public int SilverBank
        {
            get { return GetMember<int>( "SilverBank"); }
        }

        /// <summary>
        /// Skill level of skill with this name or ID
        /// </summary>
        public int Skill(int Number)
        {
            return GetMember<int>( "Skill", Number.ToString());
        }
        public int Skill(string Name)
        {
            return GetMember<int>("Skill", Name);
        }

        /// <summary>
        /// Finds song with this name or slot number
        /// </summary>
        public EQBuff Song(string Name)
        {
            return new EQBuff(GetMember("Song", Name)); 
        }
        public EQBuff Song(int Slot)
        {
            return new EQBuff(GetMember("Song", Slot.ToString()));
        }

        /// <summary>
        /// The character's spawn
        /// </summary>
        public EQSpawn Spawn
        {
            get { return new EQSpawn(GetPersistentMember("Spawn")); }
        }

        /// <summary>
        /// Gem with this spell name ready for cast?
        /// </summary>
        public bool SpellReady(string Name)
        {
            return GetMember<bool>( "SpellReady", Name);
        }
        public bool SpellReady(int Slot)
        {
            return GetMember<bool>("SpellReady", Slot.ToString());
        }

        /// <summary>
        /// Spell Shield bonus from gear/spells
        /// </summary>
        public int SpellShieldBonus
        {
            get { return GetMember<int>( "SpellShieldBonus"); }
        }

        /// <summary>
        /// Character Stamina
        /// </summary>
        public int STA
        {
            get { return GetMember<int>( "STA"); }
        }

        /// <summary>
        /// Character Strength
        /// </summary>
        public int STR
        {
            get { return GetMember<int>( "STR"); }
        }

        /// <summary>
        /// Strikethrough bonus from gear/spells
        /// </summary>
        public int StrikeThroughBonus
        {
            get { return GetMember<int>( "StrikeThroughBonus"); }
        }

        /// <summary>
        /// Stunned?
        /// </summary>
        public bool Stunned
        {
            get { return GetMember<bool>( "Stunned"); }
        }

        /// <summary>
        /// Stun Resist bonus from gear/spells
        /// </summary>
        public int StunResistBonus
        {
            get { return GetMember<int>( "StunResistBonus"); }
        }

        /// <summary>
        /// This returns your lowest save out of cold, magic, fire, poison, and disease.
        /// </summary>
        public int svChromatic
        {
            get { return GetMember<int>( "svChromatic"); }
        }

        /// <summary>
        /// Character Cold Resist
        /// </summary>
        public int svCold
        {
            get { return GetMember<int>( "svCold"); }
        }

        /// <summary>
        /// Character Corruption Resist
        /// </summary>
        public int svCorruption
        {
            get { return GetMember<int>( "svCorruption"); }
        }

        /// <summary>
        /// Character Disease Resist
        /// </summary>
        public int svDisease
        {
            get { return GetMember<int>( "svDisease"); }
        }

        /// <summary>
        /// Character Fire Resist
        /// </summary>
        public int svFire
        {
            get { return GetMember<int>( "svFire"); }
        }

        /// <summary>
        /// Character Magic Resist
        /// </summary>
        public int svMagic
        {
            get { return GetMember<int>( "svMagic"); }
        }

        /// <summary>
        /// Character Poison Resist
        /// </summary>
        public int svPoison
        {
            get { return GetMember<int>( "svPoison"); }
        }

        /// <summary>
        /// This returns the average of your cold, magic, fire, poison, and disease saves.
        /// </summary>
        public int svPrismatic
        {
            get { return GetMember<int>( "svPrismatic"); }
        }

        /// <summary>
        /// Total ldon points earned in tak
        /// </summary>
        //public int TakEarned
        //{
        //    get { return GetMember<int>( "TakEarned"); }
        //}

        /// <summary>
        /// Target of target (moved to character type)
        /// </summary>
        public EQSpawn TargetOfTarget
        {
            get { return new EQSpawn(GetPersistentMember("TargetOfTarget")); }
        }

        /// <summary>
        /// Gets your Thirst level
        /// </summary>
        public int Thirst
        {
            get { return GetMember<int>( "Thirst"); }
        }

        /// <summary>
        /// IS TributeActive?
        /// </summary>
        public bool TributeActive
        {
            get { return GetMember<bool>( "TributeActive"); }
        }

        /// <summary>
        /// Shows the remaining time of the 10 minute timer
        /// </summary>
        public EQTicks TributeTimer
        {
            get { return new EQTicks(GetMember("TributeTimer")); }
        }

        /// <summary>
        /// Character Wisdom
        /// </summary>
        public int WIS
        {
            get { return GetMember<int>( "WIS"); }
        }
        
        #endregion

    }
}
