using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Deity type.
    /// </summary>
    public class EQDeity : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQDeity(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Deity ID number
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// Deity name
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Deity team. For pvp servers only?
        /// </summary>
        public string Team
        {
            get { return GetMember<string>( "Team"); }
        }

    }
}
