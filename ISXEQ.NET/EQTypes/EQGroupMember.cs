using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest GroupMember type.
    /// </summary>
    public class EQGroupMember : LavishScriptAPI.LavishScriptObject
    {
        public EQGroupMember(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// The name of the group member. This works even if they are not in the same zone as you.
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Accesses the group member's spawn directly. This is only really needed to access Spawn.Name, instead of GroupMember.Name, as spawn is inherited automatically.
        /// </summary>
        public EQSpawn Spawn
        {
            get { return new EQSpawn(GetPersistentMember("Spawn")); }
        }

        /// <summary>
        /// TRUE if the member is the group's leader, FALSE otherwise
        /// </summary>
        public bool Leader
        {
            get { return GetMember<bool>( "Leader"); }
        }


    }
}
