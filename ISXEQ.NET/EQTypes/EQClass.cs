using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Class type.
    /// </summary>
    public class EQClass : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQClass(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// 
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public string ShortName
        {
            get { return GetMember<string>( "ShortName"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool PureCaster
        {
            get { return GetMember<bool>( "PureCaster"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool CanCast
        {
            get { return GetMember<bool>( "CanCast"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool DruidType
        {
            get { return GetMember<bool>( "DruidType"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool NecromancerType
        {
            get { return GetMember<bool>( "NecromancerType"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool ShamanType
        {
            get { return GetMember<bool>( "ShamanType"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool ClericType
        {
            get { return GetMember<bool>( "ClericType"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool PetClass
        {
            get { return GetMember<bool>( "PetClass"); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool HealerType
        {
            get { return GetMember<bool>( "HealerType"); }
        }

    }
}
