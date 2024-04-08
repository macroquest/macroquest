/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "pch.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <sol/sol.hpp>

#include <string>

namespace mq::lua::bindings {

//============================================================================

   void RegisterBindings_Constants(sol::state_view lua)
   {
      #pragma region Animations
      // Spawn Animations
      lua.new_enum("Animations",
         "Kick",                       1,
         "Melee",                      5,
         "Melee2",                     6,
         "Roundhouse",                 11,
         "Drowning",                   15,
         "Dead",                       16,
         "Walking",                    17,
         "Running",                    18,
         "Jumprun",                    19,
         "JumpInPlace",                20,
         "Falling",                    21,
         "Ducking",                    24,
         "TreadWater",                 25,
         "StandAnimated2",             26,
         "Casting1",                   27,
         "EmoteCry",                   28,
         "EmoteWwave",                 29,
         "EmoteRude",                  30,
         "Stand2",                     32,
         "Sitting",                    33,
         "Turning",                    34,
         "BindWound",                  36,
         "Swimming",                   37,
         "Casting2",                   43,
         "Casting3",                   44,
         "Kick2",                      45,
         "Tigerclaw",                  46,
         "Eaglestrike",                47,
         "EmoteNod",                   48,
         "EmoteClap",                  51,
         "EmoteBlush",                 53,
         "EmoteSnicker",               54,
         "EmoteCough",                 55,
         "EmoteDuck",                  56,
         "EmoteStare",                 57,
         "EmoteDance",                 58,
         "EmoteVeto",                  59,
         "EmoteGlare",                 60,
         "EmotePeer",                  61,
         "EmoteGrovel",                62,
         "EmoteLaugh",                 63,
         "EmotePoint",                 64,
         "EmoteShrug",                 65,
         "EmoteSalute",                67,
         "EmoteShiver",                68,
         "EmoteTap",                   69,
         "EmoteBow",                   70,
         "Stand1",                     71,
         "StandAnimated1",             72,
         "Sounted",                    74,
         "Melee3",                     80,
         "Melee4",                     82,
         "Walking2",                   104,
         "Reverse",                    105,
         "Running2",                   106,
         "TurnRight",                  107,
         "TurnLeft",                   108,
         "BindWound2",                 109,
         "Stand3",                     110,
         "StandAnimated3",             111,
         "Melee5",                     112,
         "Sitting2",                   118,
         "SitAnimation",               121,
         "Ducking2",                   122,
         "JumpRun2",                   123,
         "JumpInPlace2",               124,
         "Crawl",                      125,
         "TreadWater2",                127,
         "Swimming2",                  128,
         "Castin4",                    134,
         "Casting5",                   135,
         "YouAreHit",                  144,
         "Drowning2",                  145,
         "Dead2",                      146,
         "Falling2",                   151,
         "EmoteBow2",                  152,
         "EmoteWave2",                 154,
         "Salute2",                    155,
         "EmoteClap2",                 156,
         "EmotePoint2",                158,
         "EmoteSnicker2",              159,
         "EmoteShrug2",                160,
         "EmoteCry2",                  162,
         "EmoteRude2",                 163,
         "EmoteGrovel2",               165,
         "EmoteBlush2",                166,
         "EmoteCough2",                167,
         "EmoteDuck2",                 168,
         "EmoteShiver2",               172,
         "EmoteTap2",                  174,
         "EmoteGlare2",                177,
         "EmoteStare2",                180,
         "ZoneIn",                     254
      );
      
      #pragma endregion Animations

      // Spawn Body Types
      lua.new_enum("BodyTypes",
         "Normal",                     "Normal",
         "Lycanthrope",                "Lycanthrope",
         "Undead",                     "Undead",
         "Giant",                      "Giant",
         "Construct",                  "Construct",
         "ExtraPlanar",                "Extra Planar",
         "Monster",                    "Monster",
         "UndeadPet",                  "Undead Pet",
         "RaidGiant",                  "Raid Giant",
         "RaidColdain",                "Raid Coldain",
         "Untargetable",               "Untargetable",              
         "Vampire",                    "Vampire",
         "AtenhaRa",                   "Atenha Ra",
         "GreaterAkheva",              "Greater Akheva",
         "KhatiSha",                   "Khatia Sha",
         "Seru",                       "Seru",
         "GreigVeneficus",             "Greig Veneficus",
         "DrazNurakk",                 "Draz Nurakk",
         "God",                        "God",
         "Luggald",                    "Luggald",
         "Animal",                     "Animal",
         "Insect",                     "Insect",
         "FireCreature",               "Fire Creature",
         "Construct",                  "Construct",
         "Gargoyle",                   "Gargoyle",
         "Elemental",                  "Elemental",
         "Plant",                      "Plant",
         "Dragon",                     "Dragon",
         "SummonedCreature",           "Summoned Creature",
         "SummonedCreature2",          "Summoned Creature 2",
         "Dragon2",                    "Dragon 2",
         "VeliousDragon",              "Velious Dragon",
         "Familiar",                   "Familiar",
         "Dragon3",                    "Dragon 3",
         "Boxes",                      "Boxes",
         "Muramite",                   "Muramite",
         "Untargetable2",              "Untargetable 2",
         "SwarmPet",                   "Swarm Pet",
         "MonsterSummoning",           "Monster Summoning",
         "InvisibleMan",               "Invisible Man",
         "Special",                    "Special"
      );

      // Spawn Consider Colors
      lua.new_enum("ConsiderColors",
         "Grey",                       "GREY",
         "Green",                      "GREEN",
         "LightBlue",                  "LIGHT BLUE",
         "Blue",                       "BLUE",
         "White",                      "WHITE",
         "Yellow",                     "YELLOW",
         "Red",                        "RED"
      );

      // Spawn Diety Names
      lua.new_enum("DietyNames",
         "Agnostic",                  "Agnostic",
         "Bertoxxulous",              "Bertoxxulous",
         "BrellSerilis",              "Brell Serilis",
         "CazicThule",                "Cazic Thule",
         "ErollsiMarr",               "Erollsi Marr",
         "Bristlebane",               "Bristlebane",
         "Innoruuk",                  "Innoruuk",
         "Karana",                    "Karana",
         "MithanielMarr",             "Mithaniel Marr",
         "Prexus",                    "Prexus",
         "Quellious",                 "Quellious",
         "RallosZek",                 "Rallos Zek",
         "RodcetNife",                "RodcetNife",
         "SolusekRo",                 "Solusek Ro",
         "TheTribunal",               "The Tribunal",
         "Tunare",                    "Tunare", 
         "Veeshan",                   "Veeshan"
      );
      
      // Spawn Equipment Slot Names
      lua.new_enum("EquipmentSlots",
         "Head",                      "head",
         "Chest",                     "chest",
         "Arms",                      "arms",
         "Wrists",                    "wrists",
         "Hands",                     "hands",
         "Legs",                      "legs",
         "Feet",                      "feet",
         "Primary",                   "primary",
         "Offhand",                   "offhand"
      );

      // Spawn Gender
      lua.new_enum("Gender",
         "Male",                      "MALE",
         "Female",                    "FEMALE"
      );

      // Spawn Invis Types
      lua.new_enum("InvisTypes",
         "Any",                       0,
         "Normal",                    1,
         "Undead",                    2,
         "Animal",                    3,
         "SOS",                       4
      );

      // Spawn Player States
      lua.new_enum("PlayerStates",
         "Idle",                      0,
         "Open",                      1,
         "WeaponSheathed",            2,
         "Aggressive",                4,
         "ForcedAggressive",          8,
         "InstrumentEquipped",        0x10,
         "Stunned",                   0x20,
         "PrimaryWeaponEquipped",     0x40,
         "SecondaryWeaponEquipped",   0x80
      );

      // Spawn States
      lua.new_enum("States",
         "Stand",                     "STAND",
         "Sit",                       "SIT",
         "Duck",                      "DUCK",
         "Bind",                      "BIND",
         "Feign",                     "FEIGN",
         "Dead",                      "DEAD",
         "Stun",                      "STUN",
         "Hover",                     "HOVER",
         "Mount",                     "MOUNT",
         "Unknown",                   "UNKNOWN"
      );

      // Spawn Types
      lua.new_enum("Types",
         "PC",                        "PC",
         "NPC",                       "NPC",
         "Untargetable",              "Untargetable",
         "Mount",                     "Mount",
         "Pet",                       "Pet",
         "Courpse",                   "Corpse",
         "Chest",                     "Chest",
         "Trigger",                   "Trigger",
         "Trap",                      "Trap",
         "Timer",                     "Timer",
         "Item",                      "Item",
         "Mercenary",                 "Mercenary",
         "Aura",                      "Aura",
         "Object",                    "Object",
         "Banner",                    "Banner",
         "Campfire",                  "Campfire",
         "Flyer",                     "Flyer"
      );
   }
}
