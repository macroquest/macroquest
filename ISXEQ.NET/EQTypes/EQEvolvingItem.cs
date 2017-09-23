using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest EvolvingItem type.
    /// </summary>
    public class EQEvolvingItem : LavishScriptAPI.LavishScriptObject
    {
        public EQEvolvingItem(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// 
        /// </summary>
        public float ExpPct
        {
            get { return GetMember<float>("ExpPct"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool ExpOn
        {
            get { return GetMember<bool>( "ExpOn"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int Level
        {
            get { return GetMember<int>( "Level"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int MaxLevel
        {
            get { return GetMember<int>( "MaxLevel"); }
        }


    }
}
