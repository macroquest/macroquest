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
        "Attack Power",                         // 002
        "Movement Rate",                        // 003
        "STR",                                  // 004
        "DEX",                                  // 005
        "AGI",                                  // 006
        "STA",                                  // 007
        "INT",                                  // 008
        "WIS",                                  // 009
        "CHA",                                  // 010
        "Melee Speed",                          // 011
        "Invis",                                // 012
        "See Invis",                            // 013
        "Enduring Breath",                      // 014
        "Mana",                                 // 015
        "NPC-Frenzy",                           // 016
        "NPC-Awareness",                        // 017
        "NPC Aggro",                            // 018
        "NPC Faction",                          // 019
        "Blindness",                            // 020
        "Stun",                                 // 021
        "Charm",                                // 022
        "Fear",                                 // 023
        "Fatigue",                              // 024
        "Bind Affinity",                        // 025
        "Gate",                                 // 026
        "Dispel Magic",                         // 027
        "Invis Vs Undead",                      // 028
        "Invis Vs Animals",                     // 029
        "NPC-ReactRange",                       // 030
        "Enthrall (Mez)",                       // 031
        "Create Item",                          // 032
        "Spawn NPC",                            // 033
        "Confuse",                              // 034
        "Disease",                              // 035
        "Poison",                               // 036
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
        "Stoneskin (Absorb Damage)",            // 055
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
        "InstantHP",                            // 079
        "Enchant:Light",                        // 080
        "Resurrect",                            // 081
        "Summon Player",                        // 082
        "Teleport",                             // 083
        "Toss",                                 // 084
        "Add Proc",                             // 085
        "NPC-Help-Radius",                      // 086
        "Magnification",                        // 087
        "Evacuate",                             // 088
        "Player Size",                          // 089
        "Ignore Pet",                           // 090
        "Summon Corpse",                        // 091
        "Instant Hate",                         // 092
        "Control Weather",                      // 093
        "Make Fragile",                         // 094
        "Sacrifice",                            // 095
        "Silence",                              // 096
        "Max Mana",                             // 097
        "Bard Haste",                           // 098
        "Root",                                 // 099
        "DOT Heals",                            // 100
        "Complete Heal",                        // 101
        "Pet No Fear",                          // 102
        "Summon Pet",                           // 103
        "Translocate",                          // 104
        "Anti-Gate",                            // 105
        "Summon BeastLord Pet",                 // 106
        "Alter NPC Level",                      // 107
        "Summon Familiar",                      // 108
        "Create Item In Bag",                   // 109
        "Increase Archery",                     // 110
        "All Resists",                          // 111
        "Casting Level",                        // 112
        "Summon Mount",                         // 113
        "Hate Multiplier",                      // 114
        "Food/Water",                           // 115
        "Curse Counter",                        // 116
        "HitMagic",                             // 117
        "Singing Skill",                        // 118
        "Melee Overhaste",                      // 119
        "Healing Effectiveness",                // 120
        "Reverse Damage Shield",                // 121
        "Reduce Skill",                         // 122
        "Immunity",                             // 123
        "Spell Damage",                         // 124
        "Heal Mod",                             // 125
        "Spell Resist Rate",                    // 126
        "Spell Cast Time",                      // 127
        "Spell Duration",                       // 128
        "Spell Range",                          // 129
        "Spell/Bash Hate",                      // 130
        "Decrease Chance of Using Reagent",     // 131
        "Spell Mana Cost",                      // 132
        "Spell Stun Duration",                  // 133
        "Limit: Max Level",                     // 134
        "Limit: Resist",                        // 135
        "Limit: Target",                        // 136
        "Limit: Effect",                        // 137
        "Limit: SpellType",                     // 138
        "Limit: Spell",                         // 139
        "Limit: Min Duraction",                 // 140
        "Limit: Instant",                       // 141
        "Limit: Min Level",                     // 142
        "Limit: Min Cast Time",                 // 143
        "Limit: Max Cast Time",                 // 144
        "NPC Warder Banish",                    // 145
        "Resist Electricity",                   // 146
        "Heal Percent",                         // 147
        "Stacking: Block",                      // 148
        "Stacking: Overwrite",                  // 149
        "Death Pact",                           // 150
        "Pocket Pet",                           // 151
        "Summon a Pet Swarm",                   // 152
        "Balance Party Damage",                 // 153
        "Cancel Negative",                      // 154
        "PoP Resurrect",                        // 155
        "Mirror",                               // 156
        "Feedback",                             // 157
        "Reflect",                              // 158
        "All Stats",                            // 159
        "Sober",                                // 160
        "Mitigate Spell Damage",                // 161
        "Mitigate Melee Damage",                // 162
        "Absorb Damage",                        // 163
        "Object - Sense Trap",                  // 164
        "Object - Disarm Trap",                 // 165
        "Object - Picklock",                    // 166
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
        "Increase Chance to Resist Fear Spell", // 181
        "Hundred Hands Effect",                 // 182
        "Skill Increase Chance",                // 183
        "Increase Chance to Hit",               // 184
        "All Skills Damage Modifier",           // 185
        "All Skills Minimum Damage Modifier",   // 186
        "Balance Party Mana",                   // 187
        "Chance to block",                      // 188
        "Endurance",                            // 189
        "Max Endurance",                        // 190
        "Amnesia",                              // 191
        "Hate",                                 // 192
        "Skill Attack",                         // 193
        "Fade Memories",                        // 194
        "Stun Resist",                          // 195
        "Strikethrough",                        // 196
        "Skill Damage Taken",                   // 197
        "Instant Endurance",                    // 198
        "Taunt",                                // 199
        "Increase Proc Chance",                 // 200
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
        "Skill Damage Amt",                     // 220
        "Reduce Weight",                        // 221
        "Block Behind",                         // 222
        "Double Riposte",                       // 223
        "Add Riposte",                          // 224
        "Give Dbl Atk",                         // 225
        "2h bash",                              // 226
        "Reduce Skill Timer",                   // 227
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
        "Shielding Duration Mod",               // 255
        "Shroud Of Stealth",                    // 256
        "Give Pet Hold",                        // 257
        "Triple Backstab",                      // 258
        "AC Limit Mod",                         // 259
        "Add Instrument Mod",                   // 260
        "Song Mod Cap",                         // 261
        "Stats Cap",                            // 262
        "Tradeskill Masteries",                 // 263
        "Reduce AATimer",                       // 264
        "No Fizzle",                            // 265
        "Add Extra Attack Chance (2h)",         // 266
        "Add Pet Commands",                     // 267
        "Alc Fail Rate",                        // 268
        "Bandage Perc Limit",                   // 269
        "Bard Song Range",                      // 270
        "BaseRunMod",                           // 271
        "CastingLevel",                         // 272
        "Critical DoT",                         // 273
        "Critical Heal",                        // 274
        "Critical Mend",                        // 275
        "Dual Wield Amt",                       // 276
        "Extra DI Chance",                      // 277
        "Finishing Blow",                       // 278
        "Flurry Chance",                        // 279
        "Pet Flurry Chance",                    // 280
        "Give Pet Feign",                       // 281
        "Increase Bandage Amt",                 // 282
        "Special Attack Chain",                 // 283
        "LoH Set Heal",                         // 284
        "NoMove Check Sneak",                   // 285
        "Additional Damage to Spell",           // 286
        "Fc_DurationMod (static)",              // 287
        "Add Proc Hit",                         // 288
        "Doom Effect",                          // 289
        "Increase Movement Cap",                // 290
        "Purify",                               // 291
        "Strikethrough2",                       // 292
        "StunResist2",                          // 293
        "Spell Crit Chance",                    // 294
        "Reduce Timer Special",                 // 295
        "Increase Incoming Spell Damage",       // 296
        "Fc_Damage_Amt_Incoming",               // 297
        "Height (Small)",                       // 298
        "Wake the Dead",                        // 299
        "Doppelganger",                         // 300
        "Increase Range Damage",                // 301
        "Fc_Damage_%_Crit",                     // 302
        "Fc_Damage_Amt_Crit",                   // 303
        "Secondary Riposte Mod",                // 304
        "Mitigate Damage Shield",               // 305
        "Wake The Dead 2",                      // 306
        "Appraisal",                            // 307
        "Zone Suspend Minion",                  // 308
        "Gate Caster's Bindpoint",              // 309
        "Decrease Reuse Timer",                 // 310
        "Limit: Combat Skills Not Allowed",     // 311
        "Observer",                             // 312
        "Forage Master",                        // 313
        "Improved Invis",                       // 314
        "Improved Invis Undead",                // 315
        "Improved Invis Animals",               // 316
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
        "Mana Absorb pct Damage",               // 329
        "Critical Melee Damage Mod",            // 330
        "Alchemy Item Recovery",                // 331
        "Summon to Corpse",                     // 332
        "Trigger",                              // 333
        "HP No Move",                           // 334
        "Fc_Immunity_Focus",                    // 335
        "Illusionary Target",                   // 336
        "Increase Exp",                         // 337
        "Expedient Recovery",                   // 338
        "Cast DoT as Well",                     // 339
        "Cast DD as Well",                      // 340
        "Worn Attack Cap",                      // 341
        "No Panic",                             // 342
        "Spell Interrupt",                      // 343
        "Item Channeling",                      // 344
        "Assassinate Max",                      // 345
        "Headshot Max",                         // 346
        "Double Ranged Attack",                 // 347
        "Limit: Min Mana",                      // 348
        "Increase Damage With Shield",          // 349
        "Manaburn",                             // 350
        "Spawn Interactive Object",             // 351
        "Increase Trap Count",                  // 352
        "Increase SOI Count",                   // 353
        "Deactivate All Traps",                 // 354
        "Learn Trap",                           // 355
        "Change Trigger Type",                  // 356
        "Fc_Mute",                              // 357
        "Instant Mana",                         // 358
        "Passive Sense Trap",                   // 359
        "Proc On Kill Shot",                    // 360
        "Proc On Death",                        // 361
        "Potion Belt",                          // 362
        "Bandolier",                            // 363
        "AddTripleAttackChance",                // 364
        "Proc On Spell Kill Shot",              // 365
        "Group Shielding",                      // 366
        "Modify Body Type",                     // 367
        "Modify Faction",                       // 368
        "Corruption Counter",                   // 369
        "Corruption Resist",                    // 370
        "Slow",                                 // 371
        "Grant Foraging",                       // 372
        "Doom Always",                          // 373
        "Trigger Spell",                        // 374
        "Critical DoT Damage Mod",              // 375
        "Fling",                                // 376
        "Doom Entity",                          // 377
        "Resist Other SPA",                     // 378
        "Directional Shadowstep",               // 379
        "Knockback Explosive",                  // 380
        "Fling to Self",                        // 381
        "Suppression",                          // 382
        "Fc_CastProcNormalized",                // 383
        "Fling to Target",                      // 384
        "Limit: SpellGroup",                    // 385
        "Doom Dispeller",                       // 386
        "Doom Dispellee",                       // 387
        "Summon All Corpses",                   // 388
        "Fc_Timer_Refresh",                     // 389
        "Fc_Timer_Lockout",                     // 390
        "Limit: Max Mana",                      // 391
        "Fc_Heal_Amt",                          // 392
        "Fc_Heal_%_Incoming",                   // 393
        "Fc_Heal_Amt_Incoming",                 // 394
        "Fc_Heal_%_Crit",                       // 395
        "Fc_Heal_Amt_Crit",                     // 396
        "Pet_Amt_Mitigation",                   // 397
        "Fc_Swarm_Pet_Duration",                // 398
        "Fc_Twincast",                          // 399
        "Healburn",                             // 400
        "Mana Ignite",                          // 401
        "Endurance Ignite",                     // 402
        "Limit: SpellClass",                    // 403
        "Limit: SpellSubclass",                 // 404
        "Staff Block Chance",                   // 405
        "Doom Limit Use",                       // 406
        "Doom Focus Used",                      // 407
        "Limit HP",                             // 408
        "Limit Mana",                           // 409
        "Limit Endurance",                      // 410
        "Limit: PlayerClass",                   // 411
        "Limit: Race",                          // 412
        "Fc_BaseEffects",                       // 413
        "Limit: CastingSkill",                  // 414
        "Limit: ItemClass",                     // 415
        "AC",                                   // 416
        "Mana Regen",                           // 417
        "Increased_Skill_Damage_2",             // 418
        "Contact_Ability_2",                    // 419
        "Fc_Limit_Use",                         // 420
        "Fc_Limit_Use_Amt",                     // 421
        "Limit: Use Min",                       // 422
        "Limit: Use Type",                      // 423
        "Gravitate",                            // 424
        "Fly",                                  // 425
        "AddExtTargetSlots",                    // 426
        "Skill_Proc",                           // 427
        "Skill_Proc_Modifier",                  // 428
        "Skill_Proc_Success",                   // 429
        "PostEffect",                           // 430
        "PostEffectData",                       // 431
        "ExpandMaxActiveTrophyBenefits",        // 432
        "CriticalDotDecay",                     // 433
        "CriticalHealDecay",                    // 434
        "CriticalRegenDecay",                   // 435
        "Beneficial Countdown Hold",            // 436
        "Teleport to Anchor",                   // 437
        "Translocate to Anchor",                // 438
        "Assassinate",                          // 439
        "FinishingBlowMax",                     // 440
        "Distance Removal",                     // 441
        "Doom Req Target",                      // 442
        "Doom Req Caster",                      // 443
        "Improved Taunt",                       // 444
        "Add Merc Slot",                        // 445
        "A_Stacker",                            // 446
        "B_Stacker",                            // 447
        "C_Stacker",                            // 448
        "D_Stacker",                            // 449
        "DoT Guard",                            // 450
        "Melee Threshold Guard",                // 451
        "Spell Threshold Guard",                // 452
        "Doom Melee Threshold",                 // 453
        "Doom Spell Threshold",                 // 454
        "Add Hate %",                           // 455
        "Add Hate Over Time %",                 // 456
        "Resource Tap",                         // 457
        "Faction Mod %",                        // 458