using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest DZMember type.
    /// </summary>
    public class EQDZMember : LavishScriptAPI.LavishScriptObject
    {
        public EQDZMember(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// The name of the member
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// The status of the member - will be one of the following: Unknown, Online, Offline, In Dynamic Zone, Link Dead
        /// </summary>
        public string Status
        {
            get { return GetMember<string>( "Status"); }
        }


    }
}
