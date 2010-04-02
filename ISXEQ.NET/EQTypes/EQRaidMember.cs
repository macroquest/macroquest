using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest RaidMember type.
    /// </summary>
    public class EQRaidMember : LavishScriptAPI.LavishScriptObject
    {
        public EQRaidMember(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Raid member's class (works without being in zone)
        /// </summary>
        public EQClass Class
        {
            get { return new EQClass(GetPersistentMember("Class")); }
        }

        /// <summary>
        /// Current group number (or 0)
        /// </summary>
        public int Group
        {
            get { return GetMember<int>( "Group"); }
        }

        /// <summary>
        /// Group leader?
        /// </summary>
        public bool GroupLeader
        {
            get { return GetMember<bool>( "GroupLeader"); }
        }

        /// <summary>
        /// Raid member's level (works without being in zone)
        /// </summary>
        public int Level
        {
            get { return GetMember<int>( "Level"); }
        }

        /// <summary>
        /// Allowed to loot with current loot rules and looters?
        /// </summary>
        public bool Looter
        {
            get { return GetMember<bool>( "Looter"); }
        }

        /// <summary>
        /// Allowed to loot with current loot rules and looters?
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Raid leader?
        /// </summary>
        public bool RaidLeader
        {
            get { return GetMember<bool>( "RaidLeader"); }
        }

        /// <summary>
        /// spawn object for this player if available (must be in zone)
        /// </summary>
        public EQSpawn Spawn
        {
            get { return new EQSpawn(GetPersistentMember("Spawn")); }
        }


    }
}
