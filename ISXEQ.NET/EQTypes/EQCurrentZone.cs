using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest CurrentZone type.
    /// </summary>
    public class EQCurrentZone : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQCurrentZone(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Gravity
        /// </summary>
        public float Gravity
        {
            get { return GetMember<float>("Gravity"); }
        }

        /// <summary>
        /// Zone ID
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// Maximum clip plane allowed in zone
        /// </summary>
        public float MaxClip
        {
            get { return GetMember<float>("MaxClip"); }
        }

        /// <summary>
        /// Minimum clip plane allowed in zone
        /// </summary>
        public float MinClip
        {
            get { return GetMember<float>("MinClip"); }
        }

        /// <summary>
        /// Full zone name
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Short zone name
        /// </summary>
        public string ShortName
        {
            get { return GetMember<string>( "ShortName"); }
        }

        /// <summary>
        /// Sky type
        /// </summary>
        public int SkyType
        {
            get { return GetMember<int>( "SkyType"); }
        }

        /// <summary>
        /// Zone type
        /// </summary>
        public int Type
        {
            get { return GetMember<int>( "Type"); }
        }


    }
}
