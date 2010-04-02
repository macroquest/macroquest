using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Spell type.
    /// </summary>
    public class EQSpell : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQSpell(int ID)
            : base(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Spell", ID.ToString()))
        {
        }
        public EQSpell(string Name)
            : base(LavishScriptAPI.LavishScript.Objects.GetPersistentObject("Spell", Name))
        {
        }
        public EQSpell(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// AE range
        /// </summary>
        public float AERange
        {
            get { return GetMember<float>("AERange"); }
        }

        /// <summary>
        /// Message when cast on others
        /// </summary>
        public string CastOnAnother
        {
            get { return GetMember<string>( "CastOnAnother"); }
        }

        /// <summary>
        /// Message when cast on yourself
        /// </summary>
        public string CastOnYou
        {
            get { return GetMember<string>( "CastOnYou"); }
        }

        /// <summary>
        /// Cast time (unadjusted)
        /// </summary>
        public float CastTime
        {
            get { return GetMember<float>("CastTime"); }
        }

        /// <summary>
        /// Duration of the spell if any
        /// </summary>
        //public ticks Duration
        //{
        //    get { return GetMember<ticks>("Duration"); }
        //}

        /// <summary>
        /// Time to recover after fizzle
        /// </summary>
        public float FizzleTime
        {
            get { return GetMember<float>("FizzleTime"); }
        }

        /// <summary>
        /// Spell ID
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// Name
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Level
        /// </summary>
        public int Level
        {
            get { return GetMember<int>( "Level"); }
        }

        /// <summary>
        /// Mana cost (unadjusted)
        /// </summary>
        public int Mana
        {
            get { return GetMember<int>( "Mana"); }
        }

        /// <summary>
        /// Adjusted cast time
        /// </summary>
        public float MyCastTime
        {
            get { return GetMember<float>("MyCastTime"); }
        }

        /// <summary>
        /// Push back amount
        /// </summary>
        public float PushBack
        {
            get { return GetMember<float>("PushBack"); }
        }

        /// <summary>
        /// Maximum range to target
        /// </summary>
        public float Range
        {
            get { return GetMember<float>("Range"); }
        }

        /// <summary>
        /// This is YOUR actual cast range, including extended range from focus effects.
        /// </summary>
        public int MyRange
        {
            get { return GetMember<int>( "MyRange"); }
        }

        /// <summary>
        /// Time to recast after successful cast
        /// </summary>
        public float RecastTime
        {
            get { return GetMember<float>("RecastTime"); }
        }

        /// <summary>
        /// Same as FizzleTime
        /// </summary>
        public float RecoveryTime
        {
            get { return GetMember<float>("RecoveryTime"); }
        }

        /// <summary>
        /// Resist adjustment
        /// </summary>
        public int ResistAdj
        {
            get { return GetMember<int>( "ResistAdj"); }
        }

        /// <summary>
        /// Chromatic Disease Poison Cold Fire Magic Unresistable Unknown
        /// </summary>
        public string ResistType
        {
            get { return GetMember<string>( "ResistType"); }
        }

        /// <summary>
        /// Skill name
        /// </summary>
        public string Skill
        {
            get { return GetMember<string>( "Skill"); }
        }

        /// <summary>
        /// Beneficial(Group) Beneficial Detrimental Unknown
        /// </summary>
        public string SpellType
        {
            get { return GetMember<string>( "SpellType"); }
        }

        /// <summary>
        /// Does the selected spell stack with your current buffs
        /// </summary>
        public bool Stacks
        {
            get { return GetMember<bool>( "Stacks"); }
        }

        /// <summary>
        /// Does the selected spell stack with the specific buff
        /// </summary>
        public bool StacksWith(string Name)
        {
            return GetMember<bool>( "StacksWith",Name); 
        }

        /// <summary>
        /// Group v2 AE PC v2 etc
        /// </summary>
        public string TargetType
        {
            get { return GetMember<string>( "TargetType"); }
        }


    }
}
