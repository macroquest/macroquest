/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/
   // !!IMPORTANT!!
   // Be sure to update MAX_WEAPONS in MQ2Main.h when adding to this array
/*
 * weapons.h
 *
 * ShowEQ Distributed under GPL
 * http://seq.sourceforge.net/
 */
    "Something",                // 0x00
    "1H Sword",                 // 0x01
    "2H Sword",                 // 0x02
    "Axe",                      // 0x03
    "Bow",                      // 0x04
    "Dagger",                   // 0x05
    "Flute",                    // 0x06
    "Mace",                     // 0x07
    "2H Staff",                 // 0x08
    "Dwarven Axe",              // 0x09
    "Arrow",                    // 0x0a
    NULL,                       // 0x0b - Unknown Weapon
    NULL,                       // 0x0c - Unknown Weapon
    NULL,                       // 0x0d - Unknown Weapon
    "War Hammer",               // 0x0e
    "Trumpet",                  // 0x0f
    "Spear",                    // 0x10
    "Short Spear",              // 0x11
    "Club",                     // 0x12
    "Morning Star",             // 0x13
    "Rapier",                   // 0x14
    "Lute",                     // 0x15
    NULL,                       // 0x16 - Unknown Weapon
    "Halberd",                  // 0x17
    "2H Hammer",                // 0x18
    "2H Battle Axe",            // 0x19
    "Icy Blade(P)",             // 0x1a
    "Book",                     // 0x1b
    "Dark Book",                // 0x1c
    "Writhing Staff",           // 0x1d
    NULL,                       // 0x1e - Unknown Weapon
    "Spike Club",               // 0x1f
    "Broom",                    // 0x20
    "Hamm Flat",                // 0x21
    "Shortsword",               // 0x22
    "Scepter",                  // 0x23
    "Torch",                    // 0x24
    "Cudgel",                   // 0x25
    "Fishing Pole",             // 0x26
    "Scythe",                   // 0x27
    "Harvester",                // 0x28
    "Scimitar",                 // 0x29
    "Falchion",                 // 0x2a
    "Pick",                     // 0x2b
    NULL,                       // 0x2c - Unknown Weapon
    "Crystal Staff",            // 0x2d
    "Bone Wand",                // 0x2e
    "Wand",                     // 0x2f
    "Lantern",                  // 0x30
    "Maul",                     // 0x31
    "Dirk",                     // 0x32
    "Gold Scepter",             // 0x33
    "Shovel",                   // 0x34
    "Flamberge",                // 0x35
    NULL,                       // 0x36 - Unknown Weapon
    NULL,                       // 0x37 - Unknown Weapon
    "Stein",                    // 0x38
    "Broad Sword",              // 0x39
    "Bastard Sword",            // 0x3a
    "Mining Pick",              // 0x3b
    "Battle Axe",               // 0x3c
    "Whip",                     // 0x3d
    "Flame Sword",              // 0x3e
    "Generic (sm)",             // 0x3f
    "Generic (lg)",             // 0x40
    "Letter",                   // 0x41
    "Forge",                    // 0x42
    "Doll",                     // 0x43
    "Manastone",                // 0x44
    "Oven",                     // 0x45
    "Brew Barrel",              // 0x46
    "Claws",                    // 0x47
    "Stone",                    // 0x48
    "Kiln",                     // 0x49
    "Pottery Wheel",            // 0x4a
    "Wooden Crook",             // 0x4b
    "Vah Shir Sword",           // 0x4c 
    NULL,                       // 0x4d - Unknown Weapon
    NULL,                       // 0x4e - Unknown Weapon
    NULL,                       // 0x4f - Unknown Weapon
    "Executioner Axe",          // 0x50
    "Lamentation",              // 0x51
    "Fer'Esh",                  // 0x52
    "Silver 2H Axe",            // 0x53
    "Great Cleaver",            // 0x54
    "Serrated Sword",           // 0x55
    "Falchion",                 // 0x56
    "Ykesha SS",                // 0x57
    "Swarmcaller",              // 0x58
    NULL,                       // 0x59 - Unknown Weapon
    "Sword Passage",            // 0x5a
    "Ulak",                     // 0x5b
    "Wurmslayer",               // 0x5c
    NULL,                       // 0x5d - Unknown Weapon
    "Duster/Sapper",            // 0x5e
    "Ykesha TB",                // 0x5f
    NULL,                       // 0x60 - Unknown Weapon
    NULL,                       // 0x61 - Unknown Weapon
    "Tooth",                    // 0x62
    "Bladecatcher",             // 0x63
    "Sheer Blade",              // 0x64
    "Ketchata",                 // 0x65
    NULL,                       // 0x66 - Unknown Weapon
    "Partisan Spear",           // 0x67
    "KunzarKu'juch",            // 0x68
    "Shan'Tok",                 // 0x69
    NULL,                       // 0x6a - Unknown Weapon
    NULL,                       // 0x6b - Unknown Weapon
    NULL,                       // 0x6c - Unknown Weapon
    NULL,                       // 0x6d - Unknown Weapon
    "Legchopper",               // 0x6e
    NULL,                       // 0x6f - Unknown Weapon
    NULL,                       // 0x70 - Unknown Weapon
    NULL,                       // 0x71 - Unknown Weapon
    NULL,                       // 0x72 - Unknown Weapon
    "Mallet",                   // 0x73
    NULL,                       // 0x74 - Unknown Weapon
    NULL,                       // 0x75 - Unknown Weapon
    "Envy",                     // 0x76
    "Lupine Dagger",            // 0x77
    "Black Translucent Blade",  // 0x78
    "White Translucent Blade",  // 0x79
    "Velium 2H Staff",          // 0x7a
    NULL,                       // 0x7b - Unknown Weapon
    NULL,                       // 0x7c - Unknown Weapon
    "Sarnak Skull Staff",       // 0x7d
    "Wood Staff",               // 0x7e
    NULL,                       // 0x7f - Unknown Weapon
    "Loom",                     // 0x80
    NULL,                       // 0x81 - Unknown Weapon
    "Morning Star",             // 0x82
    "Defiance",                 // 0x83
    "Harpoon",                  // 0x84
    "Bowl",                     // 0x85
    NULL,                       // 0x86 - Unknown Weapon
    NULL,                       // 0x87 - Unknown Weapon
    "Claw",                     // 0x88
    NULL,                       // 0x89 - Unknown Weapon
    NULL,                       // 0x8a - Unknown Weapon
    NULL,                       // 0x8b - Unknown Weapon
    "Ragebringer",              // 0x8c
    "War Epic 1H Blue",         // 0x8d
    "War Epic 1H Red",          // 0x8e
    NULL,                       // 0x8f - Unknown Weapon
    NULL,                       // 0x90 - Unknown Weapon
    NULL,                       // 0x91 - Unknown Weapon
    NULL,                       // 0x92 - Unknown Weapon
    NULL,                       // 0x93 - Unknown Weapon
    "Bard Epic",                // 0x94
    "Ranger Epic",              // 0x95
    "Druid Epic",               // 0x96
    "Mage Epic",                // 0x97
    NULL,                       // 0x98 - Unknown Weapon
    "Necro Epic",               // 0x99
    "Shaman Epic",              // 0x9a
    "Wizard Epic",              // 0x9b
    "Cleric Epic",              // 0x9c
    "Enc Epic",                 // 0x9d
    NULL,                       // 0x9e - Unknown Weapon
    "Monk Epic",                // 0x9f
    "Paladin Epic",             // 0xa0
    NULL,                       // 0xa1 - Unknown Weapon
    NULL,                       // 0xa2 - Unknown Weapon
    "Red Jeweled Sword",        // 0xa3
    "Blue Jeweled Sword",       // 0xa4
    "Green Jeweled Sword",      // 0xa5 - Unknown Weapon
    NULL,                       // 0xa6 - Unknown Weapon
    "Jeweled Dirk",             // 0xa7
    "Velium Sword",             // 0xa8
    NULL,                       // 0xa9 - Unknown Weapon
    "Velium 2H Axe",            // 0xaa
    "Velium Axe",               // 0xab
    "Velium Spear",             // 0xac
    NULL,                       // 0xad - Unknown Weapon
    NULL,                       // 0xae - Unknown Weapon
    NULL,                       // 0xaf - Unknown Weapon
    NULL,                       // 0xb0 - Unknown Weapon
    NULL,                       // 0xb1 - Unknown Weapon
    "Velium Alt Hammer",        // 0xb2
    "Velium Hammer",            // 0xb3
    "Crystal Sword",            // 0xb4
    NULL,                       // 0xb5 - Unknown Weapon
    NULL,                       // 0xb6 - Unknown Weapon
    NULL,                       // 0xb7 - Unknown Weapon
    NULL,                       // 0xb8 - Unknown Weapon
    "Gold Hammer",              // 0xb9
    "Velium Great Staff",       // 0xba
    "Velium Spear",             // 0xbb
    "Velium Long Sword",        // 0xbc
    "Velium Morning Star",      // 0xbd
    "Velium 2H Sword",          // 0xbe
    "Velium Short Sword",       // 0xbf
    "Velium Scimitar",          // 0xc0
    "Velium Warhammer",         // 0xc1
    "Velium Dagger",            // 0xc2
    "Velium Rapier",            // 0xc3
    NULL,                       // 0xc4 - Unknown Weapon
    "Velium Lance",             // 0xc5
    "BFG",                      // 0xc6
    "Crossbow",                 // 0xc7
    "Qeynos Shield",            // 0xc8
    "Wooden Shield",            // 0xc9
    "Kite Shield",              // 0xca
    "Sm Round Shield",          // 0xcb
    "Darkwood Shield",          // 0xcc
    "Bone Shield",              // 0xcd
    "Dark Shield",              // 0xce
    "Marrs Promise",            // 0xcf
    NULL,                       // 0xd0 - Unknown Weapon
    "Shell Shield1",            // 0xd1
    "Shimmer Orb",              // 0xd2
    "Unicorn Shield",           // 0xd3
    "Nautilus Shield",          // 0xd4
    "Mistmoore Shield",         // 0xd5
    "Chitin Shield",            // 0xd6
    "Fear Shield",              // 0xd7
    "Iks Targ Shield",          // 0xd8
    "Frogskin Shield",          // 0xd9
    "Scale Shield",             // 0xda
    "Shell Shield2",            // 0xdb
    NULL,                       // 0xdc - Unknown Weapon
    "Sarnak Shield",            // 0xdd
    NULL,                       // 0xde - Unknown Weapon
    "Ornate Runed Shield",      // 0xdf
    NULL,                       // 0xe0 - Unknown Weapon
    NULL,                       // 0xe1 - Unknown Weapon
    "Grey Shield",              // 0xe2
    NULL,                       // 0xe3 - Unknown Weapon
    "Velium Round Shield",      // 0xe4
    NULL,                       // 0xe5 - Unknown Weapon
    "Vah Shir Shield",          // 0xe6
    NULL,                       // 0xe7 - Unknown Weapon
    NULL,                       // 0xe8 - Unknown Weapon
    NULL,                       // 0xe9 - Unknown Weapon
    NULL,                       // 0xea - Unknown Weapon
    NULL,                       // 0xeb - Unknown Weapon
    NULL,                       // 0xec - Unknown Weapon
    NULL,                       // 0xed - Unknown Weapon
    NULL,                       // 0xee - Unknown Weapon
    NULL,                       // 0xef - Unknown Weapon
    NULL,                       // 0xf0 - Unknown Weapon
    NULL,                       // 0xf1 - Unknown Weapon
    NULL,                       // 0xf2 - Unknown Weapon
    NULL,                       // 0xf3 - Unknown Weapon
    NULL,                       // 0xf4 - Unknown Weapon
    NULL,                       // 0xf5 - Unknown Weapon
    NULL,                       // 0xf6 - Unknown Weapon
    NULL,                       // 0xf7 - Unknown Weapon
    NULL,                       // 0xf8 - Unknown Weapon
    NULL,                       // 0xf9 - Unknown Weapon
    NULL,                       // 0xfa - Unknown Weapon
    NULL,                       // 0xfb - Unknown Weapon
    NULL,                       // 0xfc - Unknown Weapon
    NULL,                       // 0xfd - Unknown Weapon
    NULL,                       // 0xfe - Unknown Weapon
    NULL,                       // 0xff - Unknown Weapon
