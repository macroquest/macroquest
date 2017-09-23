using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Item type.
    /// </summary>
    public class EQItem : LavishScriptAPI.LavishScriptObject
    {
        public EQItem(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Item ID
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int AC
        {
            get { return GetMember<int>( "AC"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Accuracy
        {
            get { return GetMember<int>( "Accuracy"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int AGI
        {
            get { return GetMember<int>( "AGI"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Attack
        {
            get { return GetMember<int>( "Attack"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool Attuneable
        {
            get { return GetMember<bool>( "Attuneable"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int AugRestrictions
        {
            get { return GetMember<int>( "AugRestrictions"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int AugSlot1
        {
            get { return GetMember<int>( "AugSlot1"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int AugSlot2
        {
            get { return GetMember<int>( "AugSlot2"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int AugSlot3
        {
            get { return GetMember<int>( "AugSlot3"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int AugSlot4
        {
            get { return GetMember<int>( "AugSlot4"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int AugSlot5
        {
            get { return GetMember<int>( "AugSlot5"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int AugType
        {
            get { return GetMember<int>( "AugType"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Avoidance
        {
            get { return GetMember<int>( "Avoidance"); }
        }

        /// <summary>
        /// The price to buy this item from a merchant
        /// </summary>
        public int BuyPrice
        {
            get { return GetMember<int>( "BuyPrice"); }
        }

        /// <summary>
        /// Spell effect's cast time (in seconds)
        /// </summary>
        public float CastTime
        {
            get { return GetMember<float>("CastTime"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int CHA
        {
            get { return GetMember<int>( "CHA"); }
        }

        /// <summary>
        /// Charges
        /// </summary>
        public int Charges
        {
            get { return GetMember<int>( "Charges"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Clairvoyance
        {
            get { return GetMember<int>( "Clairvoyance"); }
        }

        /// <summary>
        /// Returns the #th long class name of the listed classes on an item. Items suitable for ALL classes will effectively have all 17 classes listed.
        /// </summary>
        public EQClass Class(int Number)
        {
            return new EQClass(GetPersistentMember("Class", Number.ToString())); 
        }

        /// <summary>
        /// The number of classes that can use the item. Items suitable for ALL classes will return 16.
        /// </summary>
        public int Classes
        {
            get { return GetMember<int>( "Classes"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int CombatEffects
        {
            get { return GetMember<int>( "CombatEffects"); }
        }

        /// <summary>
        /// Number of slots, if this is a container
        /// </summary>
        public int Container
        {
            get { return GetMember<int>( "Container"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int DamageShieldMitigation
        {
            get { return GetMember<int>( "DamageShieldMitigation"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int DamShield
        {
            get { return GetMember<int>( "DamShield"); }
        }

        /// <summary>
        /// The number of deities that can use the item. Items with no deity restrictions will return 0.
        /// </summary>
        public int Deities
        {
            get { return GetMember<int>( "Deities"); }
        }

        /// <summary>
        /// Returns the #th deity of the listed deities on an item. Items with no deity restrictions will return NULL for all values of #.
        /// </summary>
        public EQDeity Deity(int Number)
        {
            return new EQDeity(GetPersistentMember("Deity", Number.ToString())); 
        }

        /// <summary>
        /// 
        /// </summary>
        public int DEX
        {
            get { return GetMember<int>( "DEX"); }
        }

        /// <summary>
        /// None, "Magic", "Fire", "Cold", "Poison" or "Disease"
        /// </summary>
        public string DMGBonusType
        {
            get { return GetMember<string>( "DMGBonusType"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int DoTShielding
        {
            get { return GetMember<int>( "DoTShielding"); }
        }

        /// <summary>
        /// Spell effect type (see below for spell effect types)
        /// </summary>
        public string EffectType
        {
            get { return GetMember<string>( "EffectType"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int EnduranceRegen
        {
            get { return GetMember<int>( "EnduranceRegen"); }
        }

        /// <summary>
        /// Does this item have Evolving experience on?
        /// </summary>
        public EQEvolvingItem Evolving
        {
            get { return new EQEvolvingItem(GetMember("Evolving")); }
        }

        /// <summary>
        /// The number of items needed to fill all the stacks of the item you have (with a stacksize of 20). If you have 3 stacks (1, 10, 20 in those stacks), you have room for 60 total and you have 31 on you, so FreeStack would return 29.
        /// </summary>
        public int FreeStack
        {
            get { return GetMember<int>( "FreeStack"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Haste
        {
            get { return GetMember<int>( "Haste"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HealAmount
        {
            get { return GetMember<int>( "HealAmount"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicAGI
        {
            get { return GetMember<int>( "HeroicAGI"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicCHA
        {
            get { return GetMember<int>( "HeroicCHA"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicDEX
        {
            get { return GetMember<int>( "HeroicDEX"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicINT
        {
            get { return GetMember<int>( "HeroicINT"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicSTA
        {
            get { return GetMember<int>( "HeroicSTA"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicSTR
        {
            get { return GetMember<int>( "HeroicSTR"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicSvCold
        {
            get { return GetMember<int>( "HeroicSvCold"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicSvCorruption
        {
            get { return GetMember<int>( "HeroicSvCorruption"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicSvDisease
        {
            get { return GetMember<int>( "HeroicSvDisease"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicSvFire
        {
            get { return GetMember<int>( "HeroicSvFire"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicSvMagic
        {
            get { return GetMember<int>( "HeroicSvMagic"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicSvPoison
        {
            get { return GetMember<int>( "HeroicSvPoison"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HeroicWIZ
        {
            get { return GetMember<int>( "HeroicWIZ"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HP
        {
            get { return GetMember<int>( "HP"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int HPRegen
        {
            get { return GetMember<int>( "HPRegen"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public float InstrumentMod
        {
            get { return GetMember<float>("InstrumentMod"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int INT
        {
            get { return GetMember<int>( "INT"); }
        }

        /// <summary>
        /// Inventory Slot Number
        /// </summary>
        public EQInvSlot InvSlot
        {
            get { return new EQInvSlot(GetPersistentMember("InvSlot")); }
        }

        /// <summary>
        /// Item in #th slot, if this is a container
        /// </summary>
        public EQItem Item(int Number)
        {
            return new EQItem(GetMember("Item", Number.ToString())); 
        }

        /// <summary>
        /// Returns the delay of the weapon
        /// </summary>
        public int ItemDelay
        {
            get { return GetMember<int>( "ItemDelay"); }
        }

        /// <summary>
        /// Number of items, if this is a container
        /// </summary>
        public int Items
        {
            get { return GetMember<int>( "Items"); }
        }

        /// <summary>
        /// Non-LDON, "Deepest Guk", "Miragul's", "Mistmoore", "Rujarkian" or "Takish"
        /// </summary>
        public string LDoNTheme
        {
            get { return GetMember<string>( "LDoNTheme"); }
        }

        /// <summary>
        /// Lore?
        /// </summary>
        public bool Lore
        {
            get { return GetMember<bool>( "Lore"); }
        }

        /// <summary>
        /// Magic?
        /// </summary>
        public bool Magic
        {
            get { return GetMember<bool>( "Magic"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Mana
        {
            get { return GetMember<int>( "Mana"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int ManaRegen
        {
            get { return GetMember<int>( "ManaRegen"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int MaxPower
        {
            get { return GetMember<int>( "MaxPower"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int MerchQuantity
        {
            get { return GetMember<int>( "MerchQuantity"); }
        }

        /// <summary>
        /// Name
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// No drop?
        /// </summary>
        public bool NoDrop
        {
            get { return GetMember<bool>( "NoDrop"); }
        }

        /// <summary>
        /// No rent?
        /// </summary>
        public bool NoRent
        {
            get { return GetMember<bool>( "NoRent"); }
        }

        /// <summary>
        /// Ammount of power on an power source?
        /// </summary>
        public int Power
        {
            get { return GetMember<int>( "Power"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Purity
        {
            get { return GetMember<int>( "Purity"); }
        }

        /// <summary>
        /// Returns the #th long race name of the listed races on an item. Items suitable for ALL races will effectively have all 15 races listed.
        /// </summary>
        public EQRace Race(int Number)
        {
            return new EQRace(GetPersistentMember("Race", Number.ToString()));
        }

        /// <summary>
        /// The number of races that can use the item. Items suitable for ALL races will return 15.
        /// </summary>
        public int Races
        {
            get { return GetMember<int>( "Races"); }
        }

        /// <summary>
        /// Returns the Required Level of an item. Items with no required level will return 0.
        /// </summary>
        public int RequiredLevel
        {
            get { return GetMember<int>( "RequiredLevel"); }
        }

        /// <summary>
        /// Price to sell this item at this merchant
        /// </summary>
        public int SellPrice
        {
            get { return GetMember<int>( "SellPrice"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Shielding
        {
            get { return GetMember<int>( "Shielding"); }
        }

        /// <summary>
        /// Item size: 1 SMALL, 2 MEDIUM, 3 LARGE, 4 GIANT
        /// </summary>
        public int Size
        {
            get { return GetMember<int>( "Size"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int SizeCapacity
        {
            get { return GetMember<int>( "SizeCapacity"); }
        }

        /// <summary>
        /// Spell effect
        /// </summary>
        public EQSpell Spell
        {
            get { return new EQSpell(GetPersistentMember("Spell")); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int SpellDamage
        {
            get { return GetMember<int>( "SpellDamage"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int SpellShield
        {
            get { return GetMember<int>( "SpellShield"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int STA
        {
            get { return GetMember<int>( "STA"); }
        }

        /// <summary>
        /// Number of items in the stack
        /// </summary>
        public int Stack
        {
            get { return GetMember<int>( "Stack"); }
        }

        /// <summary>
        /// Stackable?
        /// </summary>
        public bool Stackable
        {
            get { return GetMember<bool>( "Stackable"); }
        }

        /// <summary>
        /// The total number of the stackable item in your inventory
        /// </summary>
        public int StackCount
        {
            get { return GetMember<int>( "StackCount"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Stacks
        {
            get { return GetMember<int>( "Stacks"); }
        }

        /// <summary>
        /// Maximum number if items that can be in the stack
        /// </summary>
        public int StackSize
        {
            get { return GetMember<int>( "StackSize"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int STR
        {
            get { return GetMember<int>( "STR"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int StrikeThrough
        {
            get { return GetMember<int>( "StrikeThrough"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int StunResist
        {
            get { return GetMember<int>( "StunResist"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int svCold
        {
            get { return GetMember<int>( "svCold"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int svCorruption
        {
            get { return GetMember<int>( "svCorruption"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int svDisease
        {
            get { return GetMember<int>( "svDisease"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int svFire
        {
            get { return GetMember<int>( "svFire"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int svMagic
        {
            get { return GetMember<int>( "svMagic"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int svPoison
        {
            get { return GetMember<int>( "svPoison"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public EQTicks Timer
        {
            get { return new EQTicks(GetMember("Timer")); }
        }

        /// <summary>
        /// Returns the number of ticks left on an item recast timer
        /// </summary>
        public int TimerReady
        {
            get { return GetMember<int>( "TimerReady"); }
        }

        /// <summary>
        /// Tribute value of the item
        /// </summary>
        public int Tribute
        {
            get { return GetMember<int>( "Tribute"); }
        }

        /// <summary>
        /// Type
        /// </summary>
        public string Type
        {
            get { return GetMember<string>( "Type"); }
        }

        /// <summary>
        /// Item value in coppers
        /// </summary>
        public int Value
        {
            get { return GetMember<int>( "Value"); }
        }

        /// <summary>
        /// Item weight
        /// </summary>
        public int Weight
        {
            get { return GetMember<int>( "Weight"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int WIS
        {
            get { return GetMember<int>( "WIS"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public EQInvSlot WornSlot(int Number)
        {
            return new EQInvSlot(GetPersistentMember("WornSlot", Number.ToString())); 
        }

        /// <summary>
        /// The number of invslots this item can be worn in (fingers/ears count as 2 slots)
        /// </summary>
        public int WornSlots
        {
            get { return GetMember<int>( "WornSlots"); }
        }



    }
}
