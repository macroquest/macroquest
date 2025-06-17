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

#pragma once

#include "mq/base/Common.h"
#include "eqlib/BuildType.h"

namespace eqlib
{
	class PlayerClient;
}

namespace mq {

/* COMMANDS */
MQLIB_API void SetError                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SuperWho                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroIfCmd                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroWhileCmd                       (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Call                                (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DeclareVar                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DumpStack                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void EndMacro                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void For                                 (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Goto                                (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void KeepKeys                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Macro                               (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroPause                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Next                                (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Return                              (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Break                               (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Continue                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void ListMacros                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SquelchCommand                      (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroLog                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroBeep                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Echo                                (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void EchoClean                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void NoParseCmd                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void NoModKeyCmd                         (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Where                               (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DropCmd                             (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void CombineCmd                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void ClearErrorsCmd                      (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoTimedCmd                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoShiftCmd                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoCtrlCmd                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoAltCmd                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoCommandCmd                        (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void RangedCmd                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoMappable                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MultilineCommand                    (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Alert                               (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void AltAbility                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void BankList                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void BuyItem                             (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SelectItem                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void CharInfo                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Cast                                (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Cleanup                             (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Click                               (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DebugSpewFile                       (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Delay                               (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void EQDestroyHeldItemOrMoney            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DisplayLoginName                    (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoAbility                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoEvents                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoSocial                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Doors                               (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoorTarget                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Exec                                (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Face                                (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Filter                              (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Help                                (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Identify                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void IniOutput                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Items                               (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void ItemTarget                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void WindowState                         (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void LoadSpells                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Location                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Look                                (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void LootAll                             (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MemSpell                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MouseTo                             (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MQMsgBox                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SellItem                            (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SetAutoRun                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Skills                              (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SuperWhoTarget                      (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SWhoFilter                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Target                              (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void Unload                              (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void PopupText                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void PopupTextCustom                     (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void PopupTextEcho                       (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void UseItemCmd                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void DoHotButton                         (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void TaskQuitCmd                         (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SpellSlotInfo                       (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SetWinTitle                         (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void GetWinTitle                         (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void PetCmd                              (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MercSwitchCmd                       (eqlib::PlayerClient* pChar, const char* szLine);
#if HAS_ADVANCED_LOOT
MQLIB_API void AdvLootCmd                          (eqlib::PlayerClient* pChar, const char* szLine);
#endif
MQLIB_API void PickZoneCmd                         (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void AssistCmd                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void InvokeCmd                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void SetProcessPriority                  (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void ScreenModeCmd                       (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void ForeGroundCmd                       (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void QuitCmd                             (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void RemoveLevCmd                        (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void EngineCommand                       (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MQCopyLayout                        (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void ListModulesCommand                  (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void ListProcessesCommand                (eqlib::PlayerClient* pChar, const char* szLine);
#if HAS_ITEM_CONVERT_BUTTON
MQLIB_API void ConvertItemCmd                      (eqlib::PlayerClient* pChar, const char* szLine);
#endif
MQLIB_API void InsertAugCmd                        (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void RemoveAugCmd                        (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void ExecuteLinkCommand                  (eqlib::PlayerClient* pChar, const char* szLine);

MQLIB_API void RemoveBuff                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void RemovePetBuff                       (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void MakeMeVisible                       (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void RemoveAura                          (eqlib::PlayerClient* pChar, const char* szLine);

MQLIB_API void DeleteVarCmd                        (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void VarSetCmd                           (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void VarCalcCmd                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void VarDataCmd                          (eqlib::PlayerClient* pChar, const char* szLine);

MQLIB_API void ProfileCmd                          (eqlib::PlayerClient* pChar, const char* szLine);
MQLIB_API void ReloadUICmd                         (eqlib::PlayerClient* pChar, const char* szLine);

} // namespace mq
