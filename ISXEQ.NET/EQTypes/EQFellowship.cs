using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Fellowship type.
    /// </summary>
    public class EQFellowship : LavishScriptAPI.LavishScriptObject
    {
        public EQFellowship(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// fellowship ID
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// leader's name
        /// </summary>
        public string Leader
        {
            get { return GetMember<string>( "Leader"); }
        }

        /// <summary>
        /// number of members in fellowship
        /// </summary>
        public string MotD
        {
            get { return GetMember<string>( "MotD"); }
        }

        /// <summary>
        /// TRUE if campfire is up, FALSE if not
        /// </summary>
        public int Members
        {
            get { return GetMember<int>( "Members"); }
        }

        /// <summary>
        /// member info by index (1-9) or name
        /// </summary>
        public EQFellowshipMember Member
        {
            get { return new EQFellowshipMember(GetMember("Member")); }
        }

        /// <summary>
        /// how much time is left on campfire
        /// </summary>
        public EQTicks CampfireDuration
        {
            get { return new EQTicks(GetMember("CampfireDuration")); }
        }

        /// <summary>
        /// self explanatory
        /// </summary>
        public float CampfireY
        {
            get { return GetMember<float>("CampfireY"); }
        }

        /// <summary>
        /// self explanatory
        /// </summary>
        public float CampfireX
        {
            get { return GetMember<float>("CampfireX"); }
        }

        /// <summary>
        /// self explanatory
        /// </summary>
        public float CampfireZ
        {
            get { return GetMember<float>("CampfireZ"); }
        }

        /// <summary>
        /// zoneinfo for the campfire
        /// </summary>
        public EQZone CampfireZone
        {
            get { return new EQZone(GetPersistentMember("CampfireZone")); }
        }

        /// <summary>
        /// TRUE if campfire is up, FALSE if not
        /// </summary>
        public bool Campfire
        {
            get { return GetMember<bool>( "Campfire"); }
        }


    }
}
