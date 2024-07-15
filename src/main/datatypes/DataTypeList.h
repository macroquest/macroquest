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

// This file is a trick so we can define a datatype once and use this list multiple times to do
// setup and teardown of individual data types. The basis of this trick is to define the
// DATATYPE macro to do the specific thing we need it to do (declare, setup, teardown, etc)
// and it will expand into the correct code at compile time through macro magic.

// The format of the macro is:
// DATATYPE(CLASSNAME, VARNAME, Pointer to inherited class or nullptr)

#ifndef DATATYPE
#error __FILE__ included without defining DATATYPE(_class_, _var_, _inherits_)
#endif

#pragma warning(push)
#pragma warning(disable: 4127) // warning C4127: conditional expression is constant (inside the DATATYPE macro)

DATATYPE(MQ2ArrayType, pArrayType, nullptr);
DATATYPE(MQ2BoolType, pBoolType, nullptr);
DATATYPE(MQ2ByteType, pByteType, nullptr);
DATATYPE(MQ2FloatType, pFloatType, nullptr);
DATATYPE(MQ2DoubleType, pDoubleType, nullptr);
DATATYPE(MQ2IntType, pIntType, nullptr);
DATATYPE(MQ2Int64Type, pInt64Type, nullptr);
DATATYPE(MQ2MacroType, pMacroType, nullptr);
DATATYPE(MQ2MathType, pMathType, nullptr);
DATATYPE(MQ2PluginType, pPluginType, nullptr);
DATATYPE(MQ2StringType, pStringType, nullptr);
DATATYPE(MQ2TimeType, pTimeType, nullptr);
DATATYPE(MQ2TypeType, pTypeType, nullptr);
DATATYPE(MQ2EverQuestType, pEverQuestType, nullptr);
DATATYPE(MQ2SpawnType, pSpawnType, nullptr);
DATATYPE(MQ2SpellType, pSpellType, nullptr);
DATATYPE(MQ2AlertType, pAlertType, nullptr);
DATATYPE(MQ2AlertListType, pAlertListType, nullptr);
DATATYPE(MQ2AltAbilityType, pAltAbilityType, nullptr);
DATATYPE(MQ2ArgbType, pArgbType, nullptr);
DATATYPE(MQ2BodyType, pBodyType, nullptr);
DATATYPE(MQ2BuffType, pBuffType, pSpellType);
DATATYPE(MQ2CharacterType, pCharacterType, pSpawnType);
DATATYPE(MQ2ClassType, pClassType, nullptr);
DATATYPE(MQ2CorpseType, pCorpseType, pSpawnType);
DATATYPE(MQ2CurrentZoneType, pCurrentZoneType, pZoneType);
DATATYPE(MQ2DeityType, pDeityType, nullptr);
DATATYPE(MQ2DynamicZoneType, pDynamicZoneType, nullptr);
DATATYPE(MQ2DZMemberType, pDZMemberType, nullptr);
DATATYPE(MQ2DZTimerType, pDZTimerType, nullptr);
DATATYPE(MQ2EvolvingItemType, pEvolvingItemType, nullptr);
DATATYPE(MQ2FellowshipMemberType, pFellowshipMemberType, nullptr);
DATATYPE(MQ2FellowshipType, pFellowshipType, nullptr);
DATATYPE(MQ2FriendsType, pFriendsType, nullptr);
DATATYPE(MQ2GroundType, pGroundType, nullptr);
DATATYPE(MQ2GroupMemberType, pGroupMemberType, pSpawnType);
DATATYPE(MQ2GroupType, pGroupType, nullptr);
DATATYPE(MQ2HeadingType, pHeadingType, nullptr);
DATATYPE(MQ2InvSlotType, pInvSlotType, nullptr);
DATATYPE(MQ2ItemType, pItemType, nullptr);
DATATYPE(MQ2ItemSpellType, pItemSpellType, nullptr);
DATATYPE(MQ2MacroQuestType, pMacroQuestType, pEverQuestType);
DATATYPE(MQ2MercenaryType, pMercenaryType, pSpawnType);
DATATYPE(MQ2MerchantType, pMerchantType, pSpawnType);
DATATYPE(MQ2PointMerchantType, pPointMerchantType, pSpawnType);
DATATYPE(MQ2PointMerchantItemType, pPointMerchantItemType, pSpawnType);
DATATYPE(MQ2PetType, pPetType, pSpawnType);
DATATYPE(MQ2PetBuffType, pPetBuffType, pSpellType);
DATATYPE(MQ2RaceType, pRaceType, nullptr);
DATATYPE(MQ2RaidMemberType, pRaidMemberType, pSpawnType);
DATATYPE(MQ2RaidType, pRaidType, nullptr);
DATATYPE(MQ2SkillType, pSkillType, nullptr);
DATATYPE(MQ2SwitchType, pSwitchType, nullptr);
DATATYPE(MQ2CachedBuffType, pCachedBuffType, pSpellType);
DATATYPE(MQ2TargetType, pTargetType, pSpawnType);
DATATYPE(MQ2TaskMemberType, pTaskMemberType, nullptr);
DATATYPE(MQ2TaskObjectiveType, pTaskObjectiveType, nullptr);
DATATYPE(MQ2TaskType, pTaskType, nullptr);
DATATYPE(MQ2TicksType, pTicksType, nullptr);
DATATYPE(MQ2TimeStampType, pTimeStampType, nullptr);
DATATYPE(MQ2TimerType, pTimerType, nullptr);
DATATYPE(MQ2WindowType, pWindowType, nullptr);
DATATYPE(MQ2MenuType, pMenuType, nullptr);
DATATYPE(MQ2XTargetType, pXTargetType, pSpawnType);
DATATYPE(MQ2ZoneType, pZoneType, nullptr);
DATATYPE(MQ2CharSelectListType, pCharSelectListType, nullptr);
DATATYPE(MQ2WorldLocationType, pWorldLocationType, nullptr);
DATATYPE(MQ2SolventType, pSolventType, nullptr);
DATATYPE(MQ2AugType, pAugType, nullptr);
DATATYPE(MQ2RangeType, pRangeType, nullptr);
DATATYPE(MQ2AuraType, pAuraType, nullptr);
DATATYPE(MQ2BandolierItemType, pBandolierItemType, nullptr);
DATATYPE(MQ2BandolierType, pBandolierType, nullptr);
DATATYPE(MQ2FrameLimiterType, pFrameLimiterType, nullptr);
DATATYPE(MQ2AchievementType, pAchievementType, nullptr);
DATATYPE(MQ2AchievementManagerType, pAchievementManagerType, nullptr);
DATATYPE(MQ2AchievementCategoryType, pAchievementCategoryType, nullptr);
DATATYPE(MQ2AchievementObjectiveType, pAchievementObjectiveType, nullptr);
DATATYPE(MQIniFileSectionKeyType, pIniFileSectionKeyType, nullptr);
DATATYPE(MQIniFileSectionType, pIniFileSectionType, nullptr);
DATATYPE(MQIniFileType, pIniFileType, nullptr);
DATATYPE(MQIniType, pIniType, nullptr);
DATATYPE(MQ2TradeskillDepotType, pTradeskillDepotType, nullptr);
DATATYPE(MQBankType, pBankType, nullptr);
DATATYPE(MQInventoryType, pInventoryType, nullptr);
DATATYPE(MQCursorAttachmentType, pCursorAttachmentType, nullptr);
DATATYPE(MQInvSlotWindowType, pInvSlotWindowType, nullptr);
DATATYPE(MQSocialType, pSocialType, nullptr);
DATATYPE(MQHotButtonType, pHotButtonWindowType, nullptr);

#if HAS_ADVANCED_LOOT
DATATYPE(MQ2AdvLootType, pAdvLootType, nullptr);
DATATYPE(MQ2AdvLootItemType, pAdvLootItemType, nullptr);
DATATYPE(MQ2ItemFilterDataType, pItemFilterDataType, nullptr);
#endif
#if HAS_KEYRING_WINDOW
DATATYPE(MQ2KeyRingType, pKeyRingType, nullptr);
DATATYPE(MQ2KeyRingItemType, pKeyRingItemType, nullptr);
#endif

#pragma warning(pop)
#undef DATATYPE // In case the includer forgets
