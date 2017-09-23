using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Zone type.
    /// </summary>
    public class EQZone : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQZone(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Zone ID
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// Full zone name
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Short zone name
        /// </summary>
        public string ShortName
        {
            get { return GetMember<string>( "ShortName"); }
        }


    }
}
