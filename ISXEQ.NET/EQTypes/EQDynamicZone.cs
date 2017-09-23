using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest DynamicZone type.
    /// </summary>
    public class EQDynamicZone : LavishScriptAPI.LavishScriptObject
    {
        public EQDynamicZone(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// The leader of the dynamic zone
        /// </summary>
        public EQDZMember Leader
        {
            get { return new EQDZMember(GetMember("Leader")); }
        }

        /// <summary>
        /// Maximum number of characters that can enter this dynamic zone
        /// </summary>
        public int MaxMembers
        {
            get { return GetMember<int>( "MaxMembers"); }
        }

        /// <summary>
        /// The dynamic zone member #
        /// </summary>
        public EQDZMember Member(int Number)
        {
            return new EQDZMember(GetMember("Member", Number.ToString()));
        }
        /// <summary>
        /// The dynamic zone member name
        /// </summary>
        public EQDZMember Member(string Name)
        {
            return new EQDZMember(GetMember("Member", Name));
        }

        /// <summary>
        /// Current number of characters in the dynamic zone
        /// </summary>
        public int Members
        {
            get { return GetMember<int>( "Members"); }
        }

        /// <summary>
        /// The full name of the dynamic zone
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }


    }
}
