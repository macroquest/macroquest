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
/*
 * SpellEffects.h - eqmule Mar 2014
 * Picked these up from the soe forums at
 * https://forums.station.sony.com/eq/index.php?threads/enumerated-spa-list.206288/
 * Enumerated SPA list
 */
		"HP",                                   // 000
        "AC",                                   // 001
        "ATK",                                  // 002
        "Movement Rate",                        // 003
        "STR",                                  // 004
        "DEX",                                  // 005
        "AGI",                                  // 006
        "STA",                                  // 007
        "INT",                                  // 008
        "WIS",                                  // 009
        "CHA",                                  // 010
        "Melee Speed",                          // 011
        "Invisibility",                         // 012
        "See Invisible",                        // 013
        "Water Breathing",                      // 014
        "Mana",                                 // 015
        "NPC Frenzy",                           // 016
        "NPC Awareness",                        // 017
        "Pacify",                               // 018
        "NPC Faction",                          // 019
        "Blindness",                            // 020
        "Stun",                                 // 021
        "Charm",                                // 022
        "Fear",                                 // 023
        "Stamina Loss",                         // 024
        "Bind Affinity",                        // 025
        "Gate",                                 // 026
        "Dispel Magic",                         // 027
        "Invisibility Vs Undead",               // 028
        "Invisibility Vs Animals",              // 029
        "NPC Aggro Radius",                     // 030
        "Mesmerize",                            // 031
        "Summon",                               // 032
        "Summon Pet",                           // 033
        "Confuse",                              // 034
        "Disease Counter",                      // 035
        "Poison Counter",                       // 036
        "Detect Hostile",                       // 037
        "Detect Magic",                         // 038
        "Detect Poison",                        // 039
        "Invulnerability",                      // 040
        "Banish",                               // 041
        "Shadow Step",                          // 042
        "Berserk",                              // 043
        "Lycanthropy",                          // 044
        "Vampirism",                            // 045
        "Fire Resist",                          // 046
        "Cold Resist",                          // 047
        "Poison Resist",                        // 048
        "Disease Resist",                       // 049
        "Magic Resist",                         // 050
        "Detect Traps",                         // 051
        "Detect Undead",                        // 052
        "Detect Summoned",                      // 053
        "Detect Animals",                       // 054
        "Absorb Damage",                        // 055
        "True North",                           // 056
        "Levitation",                           // 057
        "Illusion",                             // 058
        "Damage Shield",                        // 059
        "Transfer Item",                        // 060
        "Identify",                             // 061
        "Item ID",                              // 062
        "Memblur",                              // 063
        "Spin Stun",                            // 064
        "Infravision",                          // 065
        "Ultravision",                          // 066
        "Eye Of Zomm",                          // 067
        "Reclaim Energy",                       // 068
        "Max HP",                               // 069
        "Corpse Bomb",                          // 070
        "Create Undead Pet",                    // 071
        "Preserve Corpse",                      // 072
        "Bind Sight",                           // 073
        "Feign Death",                          // 074
        "Ventriloquism",                        // 075
        "Sentinel",                             // 076
        "Locate Corpse",                        // 077
        "SpellShield",                          // 078
        "HP",                                   // 079
        "Enchant:Light",                        // 080
        "Resurrect",                            // 081
        "Summon Player",                        // 082
        "Teleport",                             // 083
        "Toss",                                 // 084
        "Add Proc",                             // 085
        "Reaction Radius",                      // 086
        "Magnification",                        // 087
        "Evacuate",                             // 088
        "Player Size",                          // 089
        "Ignore Pet",                           // 090
        "Summon Corpse",                        // 091
        "Hate",                                 // 092
        "Control Weather",                      // 093
        "Make Fragile",                         // 094
        "Sacrifice",                            // 095
        "Silence",                              // 096
        "Max Mana",                             // 097
        "Bard Haste",                           // 098
        "Root",                                 // 099
        "HoT Heals",                            // 100
        "Complete Heal (with duration)",        // 101
        "Pet Fearless",                         // 102
        "Summon Pet",                           // 103
        "Translocate",                          // 104
        "Anti Gate",                            // 105
        "Summon Warder",                        // 106
        "Alter NPC Level",                      // 107
        "Summon Familiar",                      // 108
        "Summon In Bag",                        // 109
        "Archery",                              // 110
        "All Resists",                          // 111
        "Casting Level",                        // 112
        "Summon Mount",                         // 113
        "Hate Multiplier",                      // 114
        "Food/Water",                           // 115
        "Curse Counter",                        // 116
        "Make Weapons Magical",                 // 117
        "Singing Skill",                        // 118
        "Melee Overhaste",                      // 119
        "Healing Effectiveness",                // 120
        "Reverse Damage Shield",                // 121
        "Reduce Skill",                         // 122
        "Immunity",                             // 123
        "Spell Damage",                         // 124
        "Healing",                              // 125
        "Spell Resist Rate",                    // 126
        "Spell Cast Time",                      // 127
        "Spell Duration",                       // 128
        "Spell Range",                          // 129
        "Spell/Bash Hate",                      // 130
        "Chance of Using Reagent",              // 131
        "Spell Mana Cost",                      // 132
        "Spell Stun Duration",                  // 133
        "Limit: Max Level",                     // 134
        "Limit: Resist",                        // 135
        "Limit: Target",                        // 136
        "Limit: Effect",                        // 137
        "Limit: SpellType",                     // 138
        "Limit: Spell",                         // 139
        "Limit: Min Duration",                  // 140
        "Limit: Instant spells only",           // 141
        "Limit: Min Level",                     // 142
        "Limit: Min Cast Time",                 // 143
        "Limit: Max Cast Time",                 // 144
        "NPC Warder Banish",                    // 145
        "Resist Electricity",                   // 146
        "HP",                                   // 147
        "Stacking: Block",                      // 148
        "Stacking: Overwrite",                  // 149
        "Death Save",                           // 150
        "Pocket Pet",                           // 151
        "Summon a Pet Swarm",                   // 152
        "Balance Party Damage",                 // 153
        "Remove Detrimental",                   // 154
        "PoP Resurrect",                        // 155
        "Mirror",                               // 156
        "Spell Damage Shield",                  // 157
        "Reflect Spell",                        // 158
        "All Stats",                            // 159
        "Drunk",                                // 160
        "Mitigate Spell Damage",                // 161
        "Mitigate Melee Damage",                // 162
        "Absorb Damage",                        // 163
        "Sense LDoN Chest",                     // 164
        "Disarm LDoN Trap",                     // 165
        "Unlock LDoN Chest",                    // 166
        "Increase Pet Power",                   // 167
        "Defensive",                            // 168
        "Chance to Critical Melee",             // 169
        "Chance to Critical Cast",              // 170
        "Chance to Crippling Blow",             // 171
        "Evasion",                              // 172
        "Riposte",                              // 173
        "Dodge",                                // 174
        "Parry",                                // 175
        "Dual Wield",                           // 176
        "Double Attack",                        // 177
        "Melee Lifetap",                        // 178
        "Instrument Modifier",                  // 179
        "Chance to Resist Spells",              // 180
        "Chance to Resist Fear Spell",          // 181
        "Melee Attack",                         // 182
        "Skill Chance",                         // 183
        "Chance to Hit",                        // 184
        "Skills Damage Modifier",               // 185
        "Skills Minimum Damage Modifier",       // 186
        "Balance Party Mana",                   // 187
        "Chance to block",                      // 188
        "Endurance",                            // 189
        "Max Endurance",                        // 190
        "Amnesia",                              // 191
        "Hate",                                 // 192
        "Skill Attack",                         // 193
        "Fade",                                 // 194
        "Stun Resist",                          // 195
        "Strikethrough",                        // 196
        "Skill Damage Taken",                   // 197
        "Instant Endurance",                    // 198
        "Taunt",                                // 199
        "Proc Chance",                          // 200
        "Ranged Proc",                          // 201
        "Illusion Other",                       // 202
        "Mass Group Buff",                      // 203
        "Group Fear Immunity",                  // 204
        "Rampage",                              // 205
        "AE Taunt",                             // 206
        "Flesh to Bone",                        // 207
        "Purge Poison",                         // 208
        "Cancel Beneficial",                    // 209
        "Pet Shield",                           // 210
        "AE Melee",                             // 211
        "Frenzied Devastation",                 // 212
        "Pet HP",                               // 213
        "Change Max HP",                        // 214
        "Pet Avoidance",                        // 215
        "Accuracy",                             // 216
        "Headshot",                             // 217
        "Pet Crit Melee",                       // 218
        "Slay Undead",                          // 219
        "Damage Bonus",                         // 220
        "Reduce Weight",                        // 221
        "Block Behind",                         // 222
        "Double Riposte",                       // 223
        "Riposte",                              // 224
        "Double Attack",                        // 225
        "2H bash",                              // 226
        "Base Refresh Timer",                   // 227
        "Reduce Fall Dmg",                      // 228
        "Cast Through Stun",                    // 229
        "Increase Shield Dist",                 // 230
        "Stun Bash Chance",                     // 231
        "Divine Save",                          // 232
        "Metabolism",                           // 233
        "Poison Mastery",                       // 234
        "Focus Channelling",                    // 235
        "Free Pet",                             // 236
        "Pet Affinity",                         // 237
        "Permanent Illusion",                   // 238
        "Stonewall",                            // 239
        "String Unbreakable",                   // 240
        "Improve Reclaim Energy",               // 241
        "Increase Chance Memwipe",              // 242
        "NoBreak Charm Chance",                 // 243
        "Root Break Chance",                    // 244
        "Trap Circumvention",                   // 245
        "Lung Capacity",                        // 246
        "Increase SkillCap",                    // 247
        "Extra Specialization",                 // 248
        "Offhand Min",                          // 249
        "Spell Proc Chance",                    // 250
        "Endless Quiver",                       // 251
        "Backstab Front",                       // 252
        "Chaotic Stab",                         // 253
        "NoSpell",                              // 254
        "Shielding Duration",                   // 255
        "Shroud Of Stealth",                    // 256
        "Give Pet Hold",                        // 257
        "Triple Backstab",                      // 258
        "AC Limit",                             // 259
        "Add Instrument",                       // 260
        "Song Cap",                             // 261
        "Cap",                                  // 262
        "Tradeskill Masteries",                 // 263
        "Reduce AATimer",                       // 264
        "No Fizzle",                            // 265
        "Add Attack Chance",                    // 266
        "Add Pet Commands",                     // 267
        "Alc Fail Rate",                        // 268
        "Bandage Perc Limit",                   // 269
        "Bard Song Range",                      // 270
        "Base Run Speed",                       // 271
        "Casting Level",                        // 272
        "Critical DoT",                         // 273
        "Critical Heal",                        // 274
        "Critical Mend",                        // 275
        "Dual Wield Amt",                       // 276
        "Extra DI Chance",                      // 277
        "Finishing Blow",                       // 278
        "Flurry Chance",                        // 279
        "Pet Flurry Chance",                    // 280
        "Give Pet Feign",                       // 281
        "Bandage Amount",                       // 282
        "Special Attack Chain",                 // 283
        "LoH Set Heal",                         // 284
        "NoMove Check Sneak",                   // 285
        "DD Bonus",                             // 286
        "Focus Combat Duration",                // 287
        "Add Proc Hit",                         // 288
        "Trigger Effect",                       // 289
        "Movement Cap",                         // 290
        "Purify",                               // 291
        "Strikethrough2",                       // 292
        "StunResist2",                          // 293
        "Spell Crit Chance",                    // 294
        "Reduce Timer Special",                 // 295
        "Incoming Spell Damage",                // 296
        "Empathy",                              // 297
        "Pet Height",                           // 298
        "Wake the Dead",                        // 299
        "Doppelganger",                         // 300
        "Range Damage",                         // 301
        "Damage Crit",                          // 302
        "Damage",                               // 303
        "Secondary Riposte",                    // 304
        "Damage Shield Mitigation",             // 305
        "Wake The Dead 2",                      // 306
        "Appraisal",                            // 307
        "Zone Suspend Minion",                  // 308
        "Gate Caster's Bindpoint",              // 309
        "Decrease Reuse Timer",                 // 310
        "Limit: Combat Skills Not Allowed",     // 311
        "Observer",                             // 312
        "Forage Master",                        // 313
        "Improved Invisibility",                // 314
        "Improved Invisibility Vs Undead",      // 315
        "Improved Invisibility Vs Animals",     // 316
        "Worn Regen Cap",                       // 317
        "Worn Mana Cap",                        // 318
        "Critical HP Regen",                    // 319
        "Shield Block Chance",                  // 320
        "Reduce Target Hate",                   // 321
        "Gate to Starting City",                // 322
        "Add Defensive Proc",                   // 323
        "HP for Mana",                          // 324
        "No Break AE Sneak",                    // 325
        "Spell Slots",                          // 326
        "Buff Slots",                           // 327
        "Negative HP Limit",                    // 328
        "Mana Shield Absorb Damage",            // 329
        "Critical Damage",                      // 330
        "Item Recovery",                        // 331
        "Summon to Corpse",                     // 332
        "Trigger Effect",                       // 333
        "HP",                                   // 334
        "Block Next Spell",                     // 335
        "Illusionary Target",                   // 336
        "Experience",                           // 337
        "Expedient Recovery",                   // 338
        "Trigger DoT",                          // 339
        "Trigger DD",                           // 340
        "Worn Attack Cap",                      // 341
        "Prevent Flee on Low Health",           // 342
        "Spell Interrupt",                      // 343
        "Item Channeling",                      // 344
        "Assassinate Max",                      // 345
        "Headshot Max",                         // 346
        "Double Ranged Attack",                 // 347
        "Limit: Min Mana",                      // 348
        "Damage With Shield",                   // 349
        "Manaburn",                             // 350
        "Persistent Effect",                    // 351
        "Trap Count",                           // 352
        "SOI Count",                            // 353
        "Deactivate All Traps",                 // 354
        "Learn Trap",                           // 355
        "Change Trigger Type",                  // 356
        "Mute",                                 // 357
        "Mana/Max Mana",                        // 358
        "Passive Sense Trap",                   // 359
        "Proc On Kill Shot",                    // 360
        "Proc On Death",                        // 361
        "Potion Belt",                          // 362
        "Bandolier",                            // 363
        "Triple Attack Chance",                 // 364
        "Trigger on Kill Shot",                 // 365
        "Group Shielding",                      // 366
        "Modify Body Type",                     // 367
        "Modify Faction",                       // 368
        "Corruption Counter",                   // 369
        "Corruption Resist",                    // 370
        "Slow",                                 // 371
        "Grant Foraging",                       // 372
        "Trigger Effect",                       // 373
        "Trigger Spell",                        // 374
        "Critical DoT Damage",                  // 375
        "Fling",                                // 376
        "Trigger Effect",                       // 377
        "Resist",                               // 378
        "Directional Shadowstep",               // 379
        "Knockback",                            // 380
        "Fling to Self",                        // 381
        "Negate",                               // 382
        "Trigger Spell",                        // 383
        "Fling to Target",                      // 384
        "Limit: SpellGroup",                    // 385
        "Trigger Effect",                       // 386
        "Trigger Effect",                       // 387
        "Summon All Corpses",                   // 388
        "Spell Gem Refresh",                    // 389
        "Fc Timer Lockout",                     // 390
        "Limit: Max Mana",                      // 391
        "Instant Heal Amt",                     // 392
        "Incoming Healing Effectiveness",       // 393
        "Incoming Healing Amt",                 // 394
        "Fc Heal % Crit",                       // 395
        "Heal Amt",                             // 396
        "Pet Amt Mitigation",                   // 397
        "Swarm Pet Duration",                   // 398
        "Twincast Chance",                      // 399
        "Healburn",                             // 400
        "Mana/HP",                              // 401
        "Endurance/HP",                         // 402
        "Limit: SpellClass",                    // 403
        "Limit: SpellSubclass",                 // 404
        "Staff Block Chance",                   // 405
        "Trigger Effect",                       // 406
        "Trigger Effect",                       // 407
        "HP Limit",                             // 408
        "Mana Limit",                           // 409
        "Endurance Limit",                      // 410
        "Limit: PlayerClass",                   // 411
        "Limit: Race",                          // 412
        "Base Damage",                          // 413
        "Limit: CastingSkill",                  // 414
        "Limit: ItemClass",                     // 415
        "AC",                                   // 416
        "Mana Regen",                           // 417
        "Skill Damage",                         // 418
        "Add Proc",                             // 419
        "Fc_Limit_Use",                         // 420
        "Fc_Limit_Use_Amt",                     // 421
        "Limit: Use Min",                       // 422
        "Limit: Use Type",                      // 423
        "Gravitate",                            // 424
        "Fly",                                  // 425
        "AddExtTargetSlots",                    // 426
        "Skill Proc",                           // 427
        "Limit Skill",                          // 428
        "Hit Limited Proc",                     // 429
        "PostEffect",                           // 430
        "PostEffectData",                       // 431
        "ExpandMaxActiveTrophyBenefits",        // 432
        "Critical DoT Chance",                  // 433
        "Critical Heal Chance",                 // 434
        "Critical HoT Chance",                  // 435
        "Beneficial Countdown Hold",            // 436
        "Teleport",                             // 437
        "Translocate",                          // 438
        "Assassinate",                          // 439
        "FinishingBlowMax",                     // 440
        "Distance Removal",                     // 441
        "Trigger Effect",                       // 442
        "Trigger Effect",                       // 443
        "Improved Taunt",                       // 444
        "Add Merc Slot",                        // 445
        "A_Stacker",                            // 446
        "B_Stacker",                            // 447
        "C_Stacker",                            // 448
        "D_Stacker",                            // 449
        "DoT Guard",                            // 450
        "Melee Threshold Guard",                // 451
        "Spell Threshold Guard",                // 452
        "Trigger Effect",                       // 453
        "Trigger Effect",                       // 454
        "Add Hate",                             // 455
        "Add Hate Over Time",                   // 456
        "Resource Tap",                         // 457
        "Faction",                              // 458