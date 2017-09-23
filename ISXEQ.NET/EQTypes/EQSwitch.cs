using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Switch type.
    /// </summary>
    public class EQSwitch : LavishScriptAPI.LavishScriptObject
    {
        public EQSwitch(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Toggle the switch.
        /// </summary>
        public void Toggle()
        {
            ExecuteMethod("Toggle");
        }

        /// <summary>
        /// Distance from player to switch in (x,y)
        /// </summary>
        public float Distance
        {
            get { return GetMember<float>("Distance"); }
        }

        /// <summary>
        /// Switch is facing this heading
        /// </summary>
        public EQHeading Heading
        {
            get { return new EQHeading(GetMember("Heading")); }
        }

        /// <summary>
        /// Direction player must move to meet this switch
        /// </summary>
        public EQHeading HeadingTo
        {
            get { return new EQHeading(GetMember("HeadingTo")); }
        }

        /// <summary>
        /// Heading of "closed" switch
        /// </summary>
        public EQHeading DefaultHeading
        {
            get { return new EQHeading(GetMember("DefaultHeading")); }
        }

        /// <summary>
        /// Switch ID
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// Returns TRUE if the switch is in LoS
        /// </summary>
        public bool LineOfSight
        {
            get { return GetMember<bool>( "LineOfSight"); }
        }

        /// <summary>
        /// Name
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Open?
        /// </summary>
        public bool Open
        {
            get { return GetMember<bool>( "Open"); }
        }

        /// <summary>
        /// X coordinate
        /// </summary>
        public float X
        {
            get { return GetMember<float>("X"); }
        }

        /// <summary>
        /// Y coordinate
        /// </summary>
        public float Y
        {
            get { return GetMember<float>("Y"); }
        }

        /// <summary>
        /// Z coordinate
        /// </summary>
        public float Z
        {
            get { return GetMember<float>("Z"); }
        }

        /// <summary>
        /// X coordinate (Westward-positive)
        /// </summary>
        public float W
        {
            get { return GetMember<float>("W"); }
        }

        /// <summary>
        /// Y coordinate (Northward-positive)
        /// </summary>
        public float N
        {
            get { return GetMember<float>("N"); }
        }

        /// <summary>
        /// D coordinate (Upward-positive)
        /// </summary>
        public float D
        {
            get { return GetMember<float>("D"); }
        }

        /// <summary>
        /// X coordinate of "closed" switch
        /// </summary>
        public float DefaultX
        {
            get { return GetMember<float>("DefaultX"); }
        }

        /// <summary>
        /// Y coordinate of "closed" switch
        /// </summary>
        public float DefaultY
        {
            get { return GetMember<float>("DefaultY"); }
        }

        /// <summary>
        /// Z coordinate of "closed" switch
        /// </summary>
        public float DefaultZ
        {
            get { return GetMember<float>("DefaultZ"); }
        }

        /// <summary>
        /// X coordinate of "closed" switch (Westward-positive)
        /// </summary>
        public float DefaultW
        {
            get { return GetMember<float>("DefaultW"); }
        }

        /// <summary>
        /// Y coordinate of "closed" switch (Northward-positive)
        /// </summary>
        public float DefaultN
        {
            get { return GetMember<float>("DefaultN"); }
        }

        /// <summary>
        /// Z coordinate of "closed" switch (Upward-positive)
        /// </summary>
        public float DefaultU
        {
            get { return GetMember<float>("DefaultU"); }
        }


    }
}
