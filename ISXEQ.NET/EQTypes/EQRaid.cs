using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Raid type.
    /// </summary>
    public class EQRaid : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQRaid(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Average level of raid members (more accurate than in the window)
        /// </summary>
        public float AverageLevel
        {
            get { return GetMember<float>("AverageLevel"); }
        }

        /// <summary>
        /// Have I been invited to the raid?
        /// </summary>
        public bool Invited
        {
            get { return GetMember<bool>( "Invited"); }
        }

        /// <summary>
        /// Raid leader
        /// </summary>
        public EQRaidMember Leader
        {
            get { return new EQRaidMember(GetMember("Leader")); }
        }

        /// <summary>
        /// Is the raid locked?
        /// </summary>
        public bool Locked
        {
            get { return GetMember<bool>( "Locked"); }
        }

        /// <summary>
        /// Specified looter name by number
        /// </summary>
        public string Looter(int Number)
        {
            return GetMember<string>( "Looter", Number.ToString());
        }

        /// <summary>
        /// Number of specified looters
        /// </summary>
        public int Looters
        {
            get { return GetMember<int>( "Looters"); }
        }

        /// <summary>
        /// Loot type number (1-leader 2-leader&groupleader 3-leader&specified)
        /// </summary>
        public int LootType
        {
            get { return GetMember<int>( "LootType"); }
        }

        /// <summary>
        /// Raid member by number
        /// </summary>
        public EQRaidMember Member(int Number)
        {
            return new EQRaidMember(GetMember("Member", Number.ToString()));
        }
        /// <summary>
        /// Raid member by name
        /// </summary>
        /// <param name="Name"></param>
        /// <returns></returns>
        public EQRaidMember Member(string Name)
        {
            return new EQRaidMember(GetMember("Member", Name));
        }

        /// <summary>
        /// Total number of raid members
        /// </summary>
        public int Members
        {
            get { return GetMember<int>( "Members"); }
        }

        /// <summary>
        /// Raid target (clicked in raid window)
        /// </summary>
        public EQRaidMember Target
        {
            get { return new EQRaidMember(GetMember("Target")); }
        }

        /// <summary>
        /// Sum of all raid members' levels
        /// </summary>
        public int TotalLevels
        {
            get { return GetMember<int>( "TotalLevels"); }
        }


    }
}
