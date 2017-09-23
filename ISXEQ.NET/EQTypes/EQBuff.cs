using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Buff type.
    /// </summary>
    public class EQBuff : LavishScriptAPI.LavishScriptObject
    {
        public EQBuff(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Remove the buff.
        /// </summary>
        public void Remove()
        {
            ExecuteMethod("Remove");
        }

        /// <summary>
        /// The remaining damage absorbtion of the buff (if any). This is not entirely accurate, it will only show you to the Dar of your spell when it was initially cast, or what it was when you last zoned (whichever is more recent).
        /// </summary>
        public int Dar
        {
            get { return GetMember<int>( "Dar"); }
        }

        /// <summary>
        /// The duration of the buff in ticks (time remaining, not total duration)
        /// </summary>
        public EQTicks Duration
        {
            get { return new EQTicks(GetMember("Duration")); }
        }

        /// <summary>
        /// The ID of the buff or shortbuff slot the buff is in
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// The level of the person that cast the buff on you (not the level of the spell)
        /// </summary>
        public int Level
        {
            get { return GetMember<int>( "Level"); }
        }

        /// <summary>
        /// The modifier to a bard song
        /// </summary>
        public float Mod
        {
            get { return GetMember<float>("Mod"); }
        }

        /// <summary>
        /// The spell
        /// </summary>
        public EQSpell Spell
        {
            get { return new EQSpell(GetPersistentMember("Spell")); }
        }


    }
}
