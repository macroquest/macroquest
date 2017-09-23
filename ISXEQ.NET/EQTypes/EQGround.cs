using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Ground type.
    /// </summary>
    public class EQGround : LavishScriptAPI.LavishScriptObject
    {
        public EQGround(LavishScriptAPI.LavishScriptObject lavishObj)
            : base(lavishObj)
        {
        }

        /// <summary>
        /// Grab the item.
        /// </summary>
        public void Grab()
        {
            ExecuteMethod("Grab");
        }

        /// <summary>
        /// Ground item ID (not the same as item ID, this is like spawn ID)
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// Distance from player to ground item in (x,y)
        /// </summary>
        public float Distance
        {
            get { return GetMember<float>("Distance"); }
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
        /// Z coordinate (Upward-positive)
        /// </summary>
        public float U
        {
            get { return GetMember<float>("U"); }
        }

        /// <summary>
        /// Ground item is facing this heading
        /// </summary>
        public EQHeading Heading
        {
            get { return new EQHeading(GetMember("Heading")); }
        }

        /// <summary>
        /// Direction player must move to meet this ground item
        /// </summary>
        public EQHeading HeadingTo
        {
            get { return new EQHeading(GetMember("HeadingTo")); }
        }

        /// <summary>
        /// Returns if ground spawn is in Line of Sight
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


    }
}
