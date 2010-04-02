using System;
using System.Collections.Generic;
using LavishVMAPI;

namespace ISXEQ.EQTypes
{
    /// <summary>
    /// The MacroQuest Spawn type.
    /// </summary>
    public class EQSpawn : LavishScriptAPI.LavishScriptPersistentObject
    {
        public EQSpawn(LavishScriptAPI.LavishScriptPersistentObject lavishObj)
            : base(lavishObj)
        {
        }

  
        #region Methods
        public void Target()
        {
            ExecuteMethod("Target");
        }

        public void Face()
        {
            ExecuteMethod("Face");
        }

        public void LeftClick()
        {
            ExecuteMethod("LeftClick");
        }

        public void RightClick()
        {
            ExecuteMethod("RightClick");
        } 
        #endregion


        #region Properties

        /// <summary>
        /// SpawnID
        /// </summary>
        public int ID
        {
            get { return GetMember<int>( "ID"); }
        }

        /// <summary>
        /// AA rank number
        /// </summary>
        public int AARank
        {
            get { return GetMember<int>( "AARank"); }
        }

        /// <summary>
        /// Actual AA title (e.g. Sage, Impresario, etc)
        /// </summary>
        public string AATitle
        {
            get { return GetMember<string>( "AATitle"); }
        }

        /// <summary>
        /// AFK?
        /// </summary>
        public bool AFK
        {
            get { return GetMember<bool>( "AFK"); }
        }

        /// <summary>
        /// Current animation id
        /// </summary>
        public int Animation
        {
            get { return GetMember<int>( "Animation"); }
        }

        /// <summary>
        /// Anonymous?
        /// </summary>
        public bool Anonymous
        {
            get { return GetMember<bool>( "Anonymous"); }
        }

        /// <summary>
        /// Current Raid or Group assist target?
        /// </summary>
        public bool Assist
        {
            get { return GetMember<bool>( "Assist"); }
        }

        /// <summary>
        /// Binding wounds?
        /// </summary>
        public bool Binding
        {
            get { return GetMember<bool>( "Binding"); }
        }

        /// <summary>
        /// Body type
        /// </summary>
        public EQBody Body
        {
            get { return new EQBody(GetPersistentMember("Body")); }
        }

        /// <summary>
        /// Is a buyer? (ie. Buyer in the bazaar)
        /// </summary>
        public bool Buyer
        {
            get { return GetMember<bool>( "Buyer"); }
        }

        /// <summary>
        /// Spell, if currently casting
        /// </summary>
        public EQSpell Casting
        {
            get { return new EQSpell(GetPersistentMember("Casting")); }
        }

        /// <summary>
        /// Class
        /// </summary>
        public EQClass Class
        {
            get { return new EQClass(GetPersistentMember("Class")); }
        }

        /// <summary>
        /// Class name.
        /// </summary>
        public string ClassName
        {
            get
            {
                EQClass c = this.Class;
                return c.Name;
            }
        }

        /// <summary>
        /// The "cleaned up" name
        /// </summary>
        public string CleanName
        {
            get { return GetMember<string>( "CleanName"); }
        }

        /// <summary>
        /// Current hit points
        /// </summary>
        public int CurrentHPs
        {
            get { return GetMember<int>( "CurrentHPs"); }
        }

        /// <summary>
        /// Shortcut for -Z (makes Downward positive)
        /// </summary>
        public float D
        {
            get { return GetMember<float>("D"); }
        }

        /// <summary>
        /// Deity
        /// </summary>
        public EQDeity Deity
        {
            get { return new EQDeity(GetPersistentMember("Deity")); }
        }

        /// <summary>
        /// Deity name. This is probably all you want, anyways.
        /// </summary>
        public string DeityName
        {
            get 
            {
                EQDeity deity = this.Deity;
                return deity.Name; 
            }
        }

        /// <summary>
        /// Name displayed in game (same as EQ's %T)
        /// </summary>
        public string DisplayName
        {
            get { return GetMember<string>( "DisplayName"); }
        }

        /// <summary>
        /// Distance from player in (x,y)
        /// </summary>
        public float Distance
        {
            get { return GetMember<float>("Distance"); }
        }

        /// <summary>
        /// Distance from player in (x,y,z)
        /// </summary>
        public float Distance3D
        {
            get { return GetMember<float>("Distance3D"); }
        }

        /// <summary>
        /// Distance from player in Y plane (North/South)
        /// </summary>
        public float DistanceN
        {
            get { return GetMember<float>("DistanceN"); }
        }

        /// <summary>
        /// Estimated distance in (x,y), taking into account the spawn's movement speed but not the player's
        /// </summary>
        public float DistancePredict
        {
            get { return GetMember<float>("DistancePredict"); }
        }

        /// <summary>
        /// Distance from player in Z plane (Up/Down)
        /// </summary>
        public float DistanceU
        {
            get { return GetMember<float>("DistanceU"); }
        }

        /// <summary>
        /// Distance from player in X plane (East/West)
        /// </summary>
        public float DistanceW
        {
            get { return GetMember<float>("DistanceW"); }
        }

        /// <summary>
        /// Distance from player in X plane
        /// </summary>
        public float DistanceX
        {
            get { return GetMember<float>("DistanceX"); }
        }

        /// <summary>
        /// Distance from player in Y plane
        /// </summary>
        public float DistanceY
        {
            get { return GetMember<float>("DistanceY"); }
        }

        /// <summary>
        /// Distance from player in Z plane
        /// </summary>
        public float DistanceZ
        {
            get { return GetMember<float>("DistanceZ"); }
        }

        /// <summary>
        /// Ducking?
        /// </summary>
        public bool Ducking
        {
            get { return GetMember<bool>( "Ducking"); }
        }

        /// <summary>
        /// Shortcut for -X (makes Eastward positive)
        /// </summary>
        public float E
        {
            get { return GetMember<float>("E"); }
        }

        /// <summary>
        /// Feet wet/swimming?
        /// </summary>
        public bool FeetWet
        {
            get { return GetMember<bool>( "FeetWet"); }
        }

        /// <summary>
        /// Feigning?
        /// </summary>
        public bool Feigning
        {
            get { return GetMember<bool>( "Feigning"); }
        }

        /// <summary>
        /// Is your target moving away from you
        /// </summary>
        public bool Fleeing
        {
            get { return GetMember<bool>( "Fleeing"); }
        }

        /// <summary>
        /// Gender
        /// </summary>
        public string Gender
        {
            get { return GetMember<string>( "Gender"); }
        }

        /// <summary>
        /// GM or Guide?
        /// </summary>
        public bool GM
        {
            get { return GetMember<bool>( "GM"); }
        }

        /// <summary>
        /// Guild name
        /// </summary>
        public string Guild
        {
            get { return GetMember<string>( "Guild"); }
        }

        /// <summary>
        /// Guild status (Leader, Officer, Member)
        /// </summary>
        public string GuildStatus
        {
            get { return GetMember<string>( "GuildStatus"); }
        }

        /// <summary>
        /// Heading in this direction
        /// </summary>
        public EQHeading Heading
        {
            get { return new EQHeading(GetMember("Heading")); }
        }

        /// <summary>
        /// Heading player must travel in to reach this spawn
        /// </summary>
        public EQHeading HeadingTo
        {
            get { return new EQHeading(GetMember("HeadingTo")); }
        }

        /// <summary>
        /// Heading to the coordinates y,x from the spawn. Example HeadingToLoc("100,200")
        /// </summary>
        public EQHeading HeadingToLoc(double Y, double X)
        {
            return new EQHeading(GetMember("HeadingToLoc", Y.ToString(),X.ToString())); 
        }

        /// <summary>
        /// Height
        /// </summary>
        public float Height
        {
            get { return GetMember<float>("Height"); }
        }

        /// <summary>
        /// Represents what the pc/npc is holding
        /// </summary>
        public int Holding
        {
            get { return GetMember<int>( "Holding"); }
        }

        /// <summary>
        /// Invisible? (also includes both successful and failed hides as well as shroud of stealth)
        /// </summary>
        public bool Invis
        {
            get { return GetMember<bool>( "Invis"); }
        }

        /// <summary>
        /// Invited to group?
        /// </summary>
        public bool Invited
        {
            get { return GetMember<bool>( "Invited"); }
        }

        /// <summary>
        /// Level
        /// </summary>
        public int Level
        {
            get { return GetMember<int>( "Level"); }
        }

        /// <summary>
        /// Levitating?
        /// </summary>
        public bool Levitating
        {
            get { return GetMember<bool>( "Levitating"); }
        }

        /// <summary>
        /// LFG?
        /// </summary>
        public bool LFG
        {
            get { return GetMember<bool>( "LFG"); }
        }

        /// <summary>
        /// Name of the light class this spawn has
        /// </summary>
        public string Light
        {
            get { return GetMember<string>( "Light"); }
        }

        /// <summary>
        /// Linkdead?
        /// </summary>
        public bool Linkdead
        {
            get { return GetMember<bool>( "Linkdead"); }
        }

        /// <summary>
        /// Looking this angle
        /// </summary>
        public float Look
        {
            get { return GetMember<float>("Look"); }
        }

        /// <summary>
        /// Current Raid or Group marked npc mark number (raid first)
        /// </summary>
        public int Mark
        {
            get { return GetMember<int>( "Mark"); }
        }

        /// <summary>
        /// Master, if it is charmed or a pet
        /// </summary>
        public EQSpawn Master
        {
            get { return new EQSpawn(GetPersistentMember("Master")); }
        }

        /// <summary>
        /// Maximum hit points
        /// </summary>
        public int MaxHPs
        {
            get { return GetMember<int>( "MaxHPs"); }
        }

        /// <summary>
        /// The Max distance from this spawn for it to hit you
        /// </summary>
        public float MaxRange
        {
            get { return GetMember<float>("MaxRange"); }
        }

        /// <summary>
        /// The Max distance from this spawn for you to hit it
        /// </summary>
        public float MaxRangeTo
        {
            get { return GetMember<float>("MaxRangeTo"); }
        }

        /// <summary>
        /// Mount
        /// </summary>
        public EQSpawn Mount
        {
            get { return new EQSpawn(GetPersistentMember("Mount")); }
        }

        /// <summary>
        /// 
        /// </summary>
        public bool Moving
        {
            get { return GetMember<bool>( "Moving"); }
        }

        /// <summary>
        /// Y, the Northward-positive coordinate
        /// </summary>
        public float N
        {
            get { return GetMember<float>("N"); }
        }

        /// <summary>
        /// Name
        /// </summary>
        public string Name
        {
            get { return GetMember<string>( "Name"); }
        }

        /// <summary>
        /// Is this spawn named?
        /// </summary>
        public bool Named
        {
            get { return GetMember<bool>( "Named"); }
        }

        /// <summary>
        /// Find the nearest spawn matching this search, to this spawn (most efficient on yourself)
        /// </summary>
        public EQSpawn NearestSpawn
        {
            get { return new EQSpawn(GetPersistentMember("NearestSpawn")); }
        }

        /// <summary>
        /// Next spawn in the list
        /// </summary>
        public EQSpawn Next
        {
            get { return new EQSpawn(GetPersistentMember("Next")); }
        }

        /// <summary>
        /// Percent hit points
        /// </summary>
        public int PctHPs
        {
            get { return GetMember<int>( "PctHPs"); }
        }

        /// <summary>
        /// Pet
        /// </summary>
        public EQSpawn Pet
        {
            get { return new EQSpawn(GetPersistentMember("Pet")); }
        }

        /// <summary>
        /// Previous spawn in the list
        /// </summary>
        public EQSpawn Prev
        {
            get { return new EQSpawn(GetPersistentMember("Prev")); }
        }

        /// <summary>
        /// Race
        /// </summary>
        public EQRace Race
        {
            get { return new EQRace(GetPersistentMember("Race")); }
        }

        /// <summary>
        /// Race name.
        /// </summary>
        public string RaceName
        {
            get
            {
                EQRace c = this.Race;
                return c.Name;
            }
        }

        /// <summary>
        /// Roleplaying?
        /// </summary>
        public bool Roleplaying
        {
            get { return GetMember<bool>( "Roleplaying"); }
        }

        /// <summary>
        /// Shortcut for -Y (makes Southward positive)
        /// </summary>
        public float S
        {
            get { return GetMember<float>("S"); }
        }

        /// <summary>
        /// Sitting?
        /// </summary>
        public bool Sitting
        {
            get { return GetMember<bool>( "Sitting"); }
        }

        /// <summary>
        /// Sneaking?
        /// </summary>
        public bool Sneaking
        {
            get { return GetMember<bool>( "Sneaking"); }
        }

        /// <summary>
        /// Speed
        /// </summary>
        public float Speed
        {
            get { return GetMember<float>("Speed"); }
        }

        /// <summary>
        /// Standing?
        /// </summary>
        public bool Standing
        {
            get { return GetMember<bool>( "Standing"); }
        }

        /// <summary>
        /// STAND SIT DUCK BIND FEIGN DEAD STUN UNKNOWN
        /// </summary>
        public int StandState
        {
            get { return GetMember<int>( "StandState"); }
        }

        /// <summary>
        /// Suffix attached to name, such as: of <servername>
        /// </summary>
        public string State
        {
            get { return GetMember<string>( "State"); }
        }

        /// <summary>
        /// Suffix attached to name, such as: of &lt;servername&gt;
        /// </summary>
        public string Suffix
        {
            get { return GetMember<string>( "Suffix"); }
        }

        /// <summary>
        /// Swimming?
        /// </summary>
        public string Surname
        {
            get { return GetMember<string>( "Surname"); }
        }

        /// <summary>
        /// Thirst level
        /// </summary>
        public string Title
        {
            get { return GetMember<string>( "Title"); }
        }

        /// <summary>
        /// Trader?
        /// </summary>
        public bool Trader
        {
            get { return GetMember<bool>( "Trader"); }
        }

        /// <summary>
        /// PC NPC Untargetable Mount Pet Corpse Chest Trigger Trap Timer Item
        /// </summary>
        public string Type
        {
            get { return GetMember<string>( "Type"); }
        }

        /// <summary>
        /// Z, the Upward-positive coordinate
        /// </summary>
        public float U
        {
            get { return GetMember<float>("U"); }
        }

        /// <summary>
        /// Underwater?
        /// </summary>
        public bool Underwater
        {
            get { return GetMember<bool>( "Underwater"); }
        }

        /// <summary>
        /// X, the Westward-positive coordinate
        /// </summary>
        public float W
        {
            get { return GetMember<float>("W"); }
        }

        /// <summary>
        /// X coordinate
        /// </summary>
        public float X
        {
            get { return GetMember<float>("X"); }
        }

        /// <summary>
        /// GREY, GREEN, LIGHT BLUE, BLUE, WHITE, YELLOW, RED
        /// </summary>
        public string ConColor
        {
            get { return GetMember<string>( "ConColor"); }
        }

        /// <summary>
        /// Current Raid or Group marked npc mark number (raid first)
        /// </summary>
        public bool GroupLeader
        {
            get { return GetMember<bool>( "GroupLeader"); }
        }

        /// <summary>
        /// Returns TRUE if spawn is in LoS
        /// </summary>
        public bool LineOfSight
        {
            get { return GetMember<bool>( "LineOfSight"); }
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
        #endregion

    }
}
