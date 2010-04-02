using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Skill type.
    /// </summary>
    public class EQSkill : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQSkill(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Skill uses the kick/bash/slam/backstab/frenzy timer?
        /// </summary>
        public bool AltTimer
        {
            get { return GetMember<bool>( "AltTimer"); }
        }

        /// <summary>
        /// Skill number
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// Minimum level for your class
        /// </summary>
        public int MinLevel
        {
            get { return GetMember<int>( "MinLevel"); }
        }

        /// <summary>
        /// Name of the skill
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Reuse timer (what number format? ticks, seconds, deciseconds?)
        /// </summary>
        public int ReuseTime
        {
            get { return GetMember<int>( "ReuseTime"); }
        }

        /// <summary>
        /// Skill cap based on your current level and class.
        /// </summary>
        public int SkillCap
        {
            get { return GetMember<int>( "SkillCap"); }
        }

        /// <summary>
        /// Base skill level for your class
        /// </summary>
        public int StartingSkill
        {
            get { return GetMember<int>( "StartingSkill"); }
        }


    }
}
