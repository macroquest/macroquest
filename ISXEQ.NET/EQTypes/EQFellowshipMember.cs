using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest FellowshipMember type.
    /// </summary>
    public class EQFellowshipMember : LavishScriptAPI.LavishScriptObject
    {
        public EQFellowshipMember(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Player Name
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// zoneinfo for this player
        /// </summary>
        public EQZone Zone
        {
            get { return new EQZone(GetPersistentMember("Zone")); }
        }

        /// <summary>
        /// this player's level
        /// </summary>
        public int Level
        {
            get { return GetMember<int>( "Level"); }
        }

        /// <summary>
        /// class info for this player
        /// </summary>
        public EQClass Class
        {
            get { return new EQClass(GetPersistentMember("Class")); }
        }

        /// <summary>
        /// when this player was last online
        /// </summary>
        public EQTicks LastOn
        {
            get { return new EQTicks(GetMember("LastOn")); }
        }


    }
}
