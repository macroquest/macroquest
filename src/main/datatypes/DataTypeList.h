/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

// This file is a trick so we can define a datatype once and use this list multiple times to do
// setup and teardown of individual data types. The basis of this trick is to define the
// DATATYPE macro to do the specific thing we need it to do (declare, setup, teardown, etc)
// and it will expand into the correct code at compile time through macro magic.

// The format of the macro is:
// DATATYPE(CLASSNAME, VARNAME, Pointer to inherited class or nullptr, PersistentClass or 0)

#ifndef DATATYPE
#error __FILE__ included without defining DATATYPE(_class_, _var_, _inherits_, _persistentclass_)
#endif

#pragma warning(push)
#pragma warning(disable: 4127) // warning C4127: conditional expression is constant (inside the DATATYPE macro)

DATATYPE(MQ2ArrayType, pArrayType, nullptr, 0);
DATATYPE(MQ2BoolType, pBoolType, nullptr, 0);
DATATYPE(MQ2ByteType, pByteType, nullptr, 0);
DATATYPE(MQ2FloatType, pFloatType, nullptr, 0);
DATATYPE(MQ2DoubleType, pDoubleType, nullptr, 0);
DATATYPE(MQ2IntType, pIntType, nullptr, 0);
DATATYPE(MQ2Int64Type, pInt64Type, nullptr, 0);
DATATYPE(MQ2MacroType, pMacroType, nullptr, 0);
DATATYPE(MQ2MathType, pMathType, nullptr, 0);
DATATYPE(MQ2PluginType, pPluginType, nullptr, 0);
DATATYPE(MQ2StringType, pStringType, nullptr, 0);
DATATYPE(MQ2TimeType, pTimeType, nullptr, 0);
DATATYPE(MQ2TypeType, pTypeType, nullptr, 0);
DATATYPE(MQ2EverQuestType, pEverQuestType, nullptr, 0);
DATATYPE(MQ2SpawnType, pSpawnType, nullptr, PersistentPointerClass);
DATATYPE(MQ2SpellType, pSpellType, nullptr, 0);
// Define all inherited types first so that the SetInheritence works properly
DATATYPE(MQ2AdvLootType, pAdvLootType, nullptr, 0);
DATATYPE(MQ2AdvLootItemType, pAdvLootItemType, nullptr, 0);
DATATYPE(MQ2ItemFilterDataType, pItemFilterDataType, nullptr, 0);
DATATYPE(MQ2AlertType, pAlertType, nullptr, 0);
DATATYPE(MQ2AlertListType, pAlertListType, nullptr, 0);
DATATYPE(MQ2AltAbilityType, pAltAbilityType, nullptr, 0);
DATATYPE(MQ2ArgbType, pArgbType, nullptr, 0);
DATATYPE(MQ2BodyType, pBodyType, nullptr, 0);
DATATYPE(MQ2BuffType, pBuffType, pSpellType, 0);
DATATYPE(MQ2CharacterType, pCharacterType, pSpawnType, PersistentPointerClass);
DATATYPE(MQ2ClassType, pClassType, nullptr, 0);
DATATYPE(MQ2CorpseType, pCorpseType, nullptr, 0);
DATATYPE(MQ2CurrentZoneType, pCurrentZoneType, nullptr, 0);
DATATYPE(MQ2DeityType, pDeityType, nullptr, 0);
DATATYPE(MQ2DynamicZoneType, pDynamicZoneType, nullptr, 0);
DATATYPE(MQ2DZMemberType, pDZMemberType, nullptr, 0);
DATATYPE(MQ2EvolvingItemType, pEvolvingItemType, nullptr, 0);
DATATYPE(MQ2FellowshipMemberType, pFellowshipMemberType, nullptr, 0);
DATATYPE(MQ2FellowshipType, pFellowshipType, nullptr, 0);
DATATYPE(MQ2FriendsType, pFriendsType, nullptr, 0);
DATATYPE(MQ2GroundType, pGroundType, nullptr, 0);
DATATYPE(MQ2GroupMemberType, pGroupMemberType, pSpawnType, 0);
DATATYPE(MQ2GroupType, pGroupType, nullptr, 0);
DATATYPE(MQ2HeadingType, pHeadingType, nullptr, 0);
DATATYPE(MQ2InvSlotType, pInvSlotType, nullptr, 0);
DATATYPE(MQ2ItemType, pItemType, nullptr, 0);
DATATYPE(MQ2ItemSpellType, pItemSpellType, nullptr, 0);
DATATYPE(MQ2MacroQuestType, pMacroQuestType, pEverQuestType, 0);
DATATYPE(MQ2MercenaryType, pMercenaryType, pSpawnType, 0);
DATATYPE(MQ2MerchantType, pMerchantType, nullptr, 0);
DATATYPE(MQ2PointMerchantType, pPointMerchantType, nullptr, 0);
DATATYPE(MQ2PointMerchantItemType, pPointMerchantItemType, nullptr, 0);
DATATYPE(MQ2PetType, pPetType, pSpawnType, 0);
DATATYPE(MQ2RaceType, pRaceType, nullptr, 0);
DATATYPE(MQ2RaidMemberType, pRaidMemberType, pSpawnType, 0);
DATATYPE(MQ2RaidType, pRaidType, nullptr, 0);
DATATYPE(MQ2SkillType, pSkillType, nullptr, 0);
DATATYPE(MQ2SwitchType, pSwitchType, nullptr, 0);
DATATYPE(MQ2CachedBuffType, pCachedBuffType, pSpellType, 0);
DATATYPE(MQ2TargetType, pTargetType, pSpawnType, 0);
DATATYPE(MQ2TaskMemberType, pTaskMemberType, nullptr, 0);
DATATYPE(MQ2TaskObjectiveType, pTaskObjectiveType, nullptr, 0);
DATATYPE(MQ2TaskType, pTaskType, nullptr, 0);
DATATYPE(MQ2TicksType, pTicksType, nullptr, 0);
DATATYPE(MQ2TimeStampType, pTimeStampType, nullptr, 0);
DATATYPE(MQ2TimerType, pTimerType, nullptr, 0);
DATATYPE(MQ2WindowType, pWindowType, nullptr, 0);
DATATYPE(MQ2MenuType, pMenuType, nullptr, 0);
DATATYPE(MQ2XTargetType, pXTargetType, pSpawnType, 0);
DATATYPE(MQ2ZoneType, pZoneType, nullptr, 0);
DATATYPE(MQ2KeyRingType, pKeyRingType, nullptr, 0);
DATATYPE(MQ2CharSelectListType, pCharSelectListType, nullptr, 0);
DATATYPE(MQ2WorldLocationType, pWorldLocationType, nullptr, 0);
DATATYPE(MQ2SolventType, pSolventType, nullptr, 0);
DATATYPE(MQ2AugType, pAugType, nullptr, 0);
DATATYPE(MQ2RangeType, pRangeType, nullptr, 0);
DATATYPE(MQ2AuraType, pAuraType, nullptr, 0);
DATATYPE(MQ2BandolierItemType, pBandolierItemType, nullptr, 0);
DATATYPE(MQ2BandolierType, pBandolierType, nullptr, 0);

#pragma warning(pop)
#undef DATATYPE // In case the includer forgets
