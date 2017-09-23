using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Group type.
    /// </summary>
    public class EQGroup : LavishScriptAPI.LavishScriptObject
    {
        public EQGroup(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Accesses #th member of your group; 0 is you, 1 is the first person in the group list, etc.
        /// </summary>
        public EQGroupMember Member(int Number)
        {
            return new EQGroupMember(GetMember("Member", Number.ToString()));
        }

        /// <summary>
        /// Which number in the group the PC with name is
        /// </summary>
        public int MemberNumber(string Name)
        {
            return GetMember<int>( "Member", Name);
        }

        /// <summary>
        /// Total number of group members, excluding yourself
        /// </summary>
        public int Members
        {
            get { return GetMember<int>( "Members"); }
        }

        /// <summary>
        /// The leader of your group
        /// </summary>
        public EQGroupMember Leader
        {
            get { return new EQGroupMember(GetMember("Leader")); }
        }


    }
}
