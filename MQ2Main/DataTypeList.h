/*
    The format of this file is:
    DATATYPE(CLASSNAME, VARNAME, Pointer to inherited class or nullptr, PersistentClass or 0)
*/
#ifndef DATATYPE
#error __FILE__ included without defining DATATYPE(_class_, _var_, _inherits_, _persistentclass_)
#endif
#pragma warning( push )
#pragma warning( disable:4127 ) // warning C4127: conditional expression is constant  (inside the DATATYPE macro)

#ifndef ISXEQ
// These datatypes are specific to MQ2 only
DATATYPE(MQ2ArrayType,  pArrayType,  nullptr, 0);
DATATYPE(MQ2BoolType,   pBoolType,   nullptr, 0);
DATATYPE(MQ2ByteType,   pByteType,   nullptr, 0);
DATATYPE(MQ2FloatType,  pFloatType,  nullptr, 0);
DATATYPE(MQ2DoubleType, pDoubleType, nullptr, 0);
DATATYPE(MQ2IntType,    pIntType,    nullptr, 0);
DATATYPE(MQ2Int64Type,  pInt64Type,  nullptr, 0);
DATATYPE(MQ2MacroType,  pMacroType,  nullptr, 0);
DATATYPE(MQ2MathType,   pMathType,   nullptr, 0);
DATATYPE(MQ2PluginType, pPluginType, nullptr, 0);
DATATYPE(MQ2StringType, pStringType, nullptr, 0);
DATATYPE(MQ2TimeType,   pTimeType,   nullptr, 0);
DATATYPE(MQ2TypeType,   pTypeType,   nullptr, 0);
#endif

// These are all datatypes common to both MQ2 and ISXEQ
DATATYPE(MQ2EverQuestType,        pEverQuestType,        nullptr, 0);
DATATYPE(MQ2SpawnType,            pSpawnType,            nullptr, PersistentPointerClass);
DATATYPE(MQ2SpellType,            pSpellType,            nullptr, 0);
// Define all inherited types first so that the SetInheritence works properly
DATATYPE(MQ2AltAbilityType,       pAltAbilityType,       nullptr, 0);
DATATYPE(MQ2ArgbType,             pArgbType,             nullptr, 0);
DATATYPE(MQ2BodyType,             pBodyType,             nullptr, 0);
DATATYPE(MQ2BuffType,             pBuffType,             pSpellType, 0);
DATATYPE(MQ2CharacterType,        pCharacterType,        pSpawnType, PersistentPointerClass);
DATATYPE(MQ2ClassType,            pClassType,            nullptr, 0);
DATATYPE(MQ2CorpseType,           pCorpseType,           nullptr, 0);
DATATYPE(MQ2CurrentZoneType,      pCurrentZoneType,      nullptr, 0);
DATATYPE(MQ2DeityType,            pDeityType,            nullptr, 0);
DATATYPE(MQ2DynamicZoneType,      pDynamicZoneType,      nullptr, 0);
DATATYPE(MQ2DZMemberType,         pDZMemberType,         nullptr, 0);
DATATYPE(MQ2EvolvingItemType,     pEvolvingItemType,     nullptr, 0);
DATATYPE(MQ2FellowshipMemberType, pFellowshipMemberType, nullptr, 0);
DATATYPE(MQ2FellowshipType,       pFellowshipType,       nullptr, 0);
DATATYPE(MQ2FriendsType,          pFriendsType,          nullptr, 0);
DATATYPE(MQ2GroundType,           pGroundType,           nullptr, 0);
DATATYPE(MQ2GroupMemberType,      pGroupMemberType,      pSpawnType, 0);
DATATYPE(MQ2GroupType,            pGroupType,            nullptr, 0);
DATATYPE(MQ2HeadingType,          pHeadingType,          nullptr, 0);
DATATYPE(MQ2InvSlotType,          pInvSlotType,          nullptr, 0);
DATATYPE(MQ2ItemType,             pItemType,             nullptr, 0);
DATATYPE(MQ2MacroQuestType,       pMacroQuestType,       pEverQuestType, 0);
DATATYPE(MQ2MercenaryType,        pMercenaryType,        pSpawnType, 0);
DATATYPE(MQ2MerchantType,         pMerchantType,         nullptr, 0);
DATATYPE(MQ2PetType,              pPetType,              pSpawnType, 0);
DATATYPE(MQ2RaceType,             pRaceType,             nullptr, 0);
DATATYPE(MQ2RaidMemberType,       pRaidMemberType,       pSpawnType, 0);
DATATYPE(MQ2RaidType,             pRaidType,             nullptr, 0);
DATATYPE(MQ2SkillType,            pSkillType,            nullptr, 0);
DATATYPE(MQ2SwitchType,           pSwitchType,           nullptr, 0);
DATATYPE(MQ2TargetBuffType,       pTargetBuffType,       pSpellType, 0);
DATATYPE(MQ2TargetType,           pTargetType,           pSpawnType, 0);
DATATYPE(MQ2TaskMemberType,       pTaskMemberType,       nullptr, 0);
DATATYPE(MQ2TaskType,             pTaskType,             nullptr, 0);
DATATYPE(MQ2TicksType,            pTicksType,            nullptr, 0);
DATATYPE(MQ2TimeStampType,        pTimeStampType,        nullptr, 0);
DATATYPE(MQ2TimerType,            pTimerType,            nullptr, 0);
DATATYPE(MQ2WindowType,           pWindowType,           nullptr, 0);
DATATYPE(MQ2XTargetType,          pXTargetType,          pSpawnType, 0);
DATATYPE(MQ2ZoneType,             pZoneType,             nullptr, 0);
DATATYPE(MQ2MountType,			  pMountType,			 nullptr, 0);
DATATYPE(MQ2AdvLootType,		  pAdvLootType,			 nullptr, 0);
DATATYPE(MQ2AdvLootItemType,      pAdvLootItemType,      nullptr, 0);

#pragma warning( pop )
#undef DATATYPE // In case the includer forgets