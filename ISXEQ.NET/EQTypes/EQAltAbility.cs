using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest AltAbility type.
    /// </summary>
    public class EQAltAbility : LavishScriptAPI.LavishScriptObject
    {
        public EQAltAbility(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Rank required to train
        /// </summary>
        public int AARankRequired
        {
            get { return GetMember<int>( "AARankRequired"); }
        }

        /// <summary>
        /// Base cost to train
        /// </summary>
        public int Cost
        {
            get { return GetMember<int>( "Cost"); }
        }

        /// <summary>
        /// Basic description
        /// </summary>
        public string Description
        {
            get { return GetMember<string>( "Description"); }
        }

        /// <summary>
        /// ID number
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// Max rank available in this ability
        /// </summary>
        public int MaxRank
        {
            get { return GetMember<int>( "MaxRank"); }
        }

        /// <summary>
        /// Minimum level to train
        /// </summary>
        public int MinLevel
        {
            get { return GetMember<int>( "MinLevel"); }
        }

        /// <summary>
        /// Name of the alt ability
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Required ability (if any)
        /// </summary>
        public EQAltAbility RequiresAbility
        {
            get { return new EQAltAbility(GetMember("RequiresAbility")); }
        }

        /// <summary>
        /// Points required to buy ability
        /// </summary>
        public int RequiresAbilityPoints
        {
            get { return GetMember<int>( "RequiresAbilityPoints"); }
        }

        /// <summary>
        /// Total reuse time in seconds. See MyReuseTime for an active timer.
        /// </summary>
        public int ReuseTime
        {
            get { return GetMember<int>( "ReuseTime"); }
        }

        /// <summary>
        /// Short name
        /// </summary>
        public string ShortName
        {
            get { return GetMember<string>( "ShortName"); }
        }

        /// <summary>
        /// Spell used by the ability (if any). 
        /// </summary>
        public EQSpell Spell
        {
            get { return new EQSpell(GetPersistentMember("Spell")); }
        }

        /// <summary>
        /// Type (1-6, this may change to string eventually)
        /// </summary>
        public int Type
        {
            get { return GetMember<int>( "Type"); }
        }

        /// <summary>
        /// The reuse time of the ability before you can use it.
        /// </summary>
        public int MyReuseTime
        {
            get { return GetMember<int>( "MyReuseTime"); }
        }

        public static EQAltAbility AltAbility(int Number)
        {
            return new EQAltAbility(LavishScriptAPI.LavishScript.Objects.GetObject("AltAbility", Number.ToString()));
        }
        public static EQAltAbility AltAbility(string Name)
        {
            return new EQAltAbility(LavishScriptAPI.LavishScript.Objects.GetObject("AltAbility", Name));
        }
    }     
}
