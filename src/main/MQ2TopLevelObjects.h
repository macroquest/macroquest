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

#pragma once

namespace mq {

/* DATA ITEMS */
MQLIB_API bool dataSpawn(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataTarget(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataCharacter(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataSwitch(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataGroundItem(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataGroundItemCount(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataMercenary(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataPet(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataMerchant(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataPointMerchant(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataWindow(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataMenu(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataMacro(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataEverQuest(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataMacroQuest(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataMath(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataZone(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataGroup(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataFloat(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataCorpse(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataIf(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataCursor(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataNearestSpawn(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataGameTime(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataTime(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataIni(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataHeading(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataDefined(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataSubDefined(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataLastSpawn(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataInvSlot(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataFindItem(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataSelectedItem(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataFindItemBank(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataFindItemCount(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataFindItemBankCount(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataSkill(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataAltAbility(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataRaid(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataNamingSpawn(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataSpawnCount(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataLineOfSight(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataPlugin(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataSelect(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataDoorTarget(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataItemTarget(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataDynamicZone(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataFriends(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataMount(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataIllusion(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataFamiliar(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataAlias(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataAdvLoot(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataAlert(const char* szIndex, MQTypeVar& Ret);
MQLIB_API bool dataRange(const char* szIndex, MQTypeVar& Ret);

} // namespace mq
