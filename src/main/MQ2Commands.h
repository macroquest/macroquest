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

#include "MQ2Main.h"

namespace mq {

/* COMMANDS */
MQLIB_API void SetError                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void SuperWho                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroIfCmd                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroWhileCmd                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void Call                                (PlayerClient* pChar, const char* szLine);
MQLIB_API void DeclareVar                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void DumpStack                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void EndMacro                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void For                                 (PlayerClient* pChar, const char* szLine);
MQLIB_API void Goto                                (PlayerClient* pChar, const char* szLine);
MQLIB_API void KeepKeys                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void Macro                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroPause                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void Next                                (PlayerClient* pChar, const char* szLine);
MQLIB_API void Return                              (PlayerClient* pChar, const char* szLine);
MQLIB_API void Break                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void Continue                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void ListMacros                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void SquelchCommand                      (PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroLog                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void MacroBeep                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void Echo                                (PlayerClient* pChar, const char* szLine);
MQLIB_API void EchoClean                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void NoParseCmd                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void NoModKeyCmd                         (PlayerClient* pChar, const char* szLine);
MQLIB_API void Where                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void HudCmd                              (PlayerClient* pChar, const char* szLine);
MQLIB_API void DropCmd                             (PlayerClient* pChar, const char* szLine);
MQLIB_API void CombineCmd                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void ClearErrorsCmd                      (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoTimedCmd                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoShiftCmd                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoCtrlCmd                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoAltCmd                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoCommandCmd                        (PlayerClient* pChar, const char* szLine);
MQLIB_API void DumpBindsCommand                    (PlayerClient* pChar, const char* szLine);
MQLIB_API void LoadCfgCommand                      (PlayerClient* pChar, const char* szLine);
MQLIB_API void RangedCmd                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoMappable                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void MQ2KeyBindCommand                   (PlayerClient* pChar, const char* szLine);
MQLIB_API void MultilineCommand                    (PlayerClient* pChar, const char* szLine);
MQLIB_API void Alert                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void Alias                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void AltAbility                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void BankList                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void BuyItem                             (PlayerClient* pChar, const char* szLine);
MQLIB_API void SelectItem                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void CharInfo                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void Cast                                (PlayerClient* pChar, const char* szLine);
MQLIB_API void Cleanup                             (PlayerClient* pChar, const char* szLine);
MQLIB_API void Click                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void DebugSpewFile                       (PlayerClient* pChar, const char* szLine);
MQLIB_API void Delay                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void EQDestroyHeldItemOrMoney            (PlayerClient* pChar, const char* szLine);
MQLIB_API void DisplayLoginName                    (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoAbility                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoEvents                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoSocial                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void Doors                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoorTarget                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void Exec                                (PlayerClient* pChar, const char* szLine);
MQLIB_API void Face                                (PlayerClient* pChar, const char* szLine);
MQLIB_API void Filter                              (PlayerClient* pChar, const char* szLine);
MQLIB_API void Help                                (PlayerClient* pChar, const char* szLine);
MQLIB_API void Identify                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void IniOutput                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void Items                               (PlayerClient* pChar, const char* szLine);
MQLIB_API void ItemTarget                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void WindowState                         (PlayerClient* pChar, const char* szLine);
MQLIB_API void LoadSpells                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void Location                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void Look                                (PlayerClient* pChar, const char* szLine);
MQLIB_API void LootAll                             (PlayerClient* pChar, const char* szLine);
MQLIB_API void MemSpell                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void MouseTo                             (PlayerClient* pChar, const char* szLine);
MQLIB_API void MQMsgBox                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void SellItem                            (PlayerClient* pChar, const char* szLine);
MQLIB_API void SetAutoRun                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void Skills                              (PlayerClient* pChar, const char* szLine);
MQLIB_API void SuperWhoTarget                      (PlayerClient* pChar, const char* szLine);
MQLIB_API void SWhoFilter                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void Target                              (PlayerClient* pChar, const char* szLine);
MQLIB_API void Unload                              (PlayerClient* pChar, const char* szLine);
MQLIB_API void PopupText                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void PopupTextCustom                     (PlayerClient* pChar, const char* szLine);
MQLIB_API void PopupTextEcho                       (PlayerClient* pChar, const char* szLine);
MQLIB_API void UseItemCmd                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void DoHotButton                         (PlayerClient* pChar, const char* szLine);
MQLIB_API void TaskQuitCmd                         (PlayerClient* pChar, const char* szLine);
MQLIB_API void SpellSlotInfo                       (PlayerClient* pChar, const char* szLine);
MQLIB_API void SetWinTitle                         (PlayerClient* pChar, const char* szLine);
MQLIB_API void GetWinTitle                         (PlayerClient* pChar, const char* szLine);
MQLIB_API void PetCmd                              (PlayerClient* pChar, const char* szLine);
MQLIB_API void MercSwitchCmd                       (PlayerClient* pChar, const char* szLine);
#if HAS_ADVANCED_LOOT
MQLIB_API void AdvLootCmd                          (PlayerClient* pChar, const char* szLine);
#endif
MQLIB_API void PickZoneCmd                         (PlayerClient* pChar, const char* szLine);
MQLIB_API void AssistCmd                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void InvokeCmd                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void SetProcessPriority                  (PlayerClient* pChar, const char* szLine);
MQLIB_API void ScreenModeCmd                       (PlayerClient* pChar, const char* szLine);
MQLIB_API void UserCameraCmd                       (PlayerClient* pChar, const char* szLine);
MQLIB_API void ForeGroundCmd                       (PlayerClient* pChar, const char* szLine);
MQLIB_API void QuitCmd                             (PlayerClient* pChar, const char* szLine);
MQLIB_API void RemoveLevCmd                        (PlayerClient* pChar, const char* szLine);
MQLIB_API void EngineCommand                       (PlayerClient* pChar, const char* szLine);
MQLIB_API void CachedBuffsCommand                  (PlayerClient* pChar, const char* szLine);
MQLIB_API void MQCopyLayout                        (PlayerClient* pChar, const char* szLine);
MQLIB_API void ListModulesCommand                  (PlayerClient* pChar, const char* szLine);
MQLIB_API void ListProcessesCommand                (PlayerClient* pChar, const char* szLine);
#if HAS_ITEM_CONVERT_BUTTON
MQLIB_API void ConvertItemCmd                      (PlayerClient* pChar, const char* szLine);
#endif
MQLIB_API void InsertAugCmd                        (PlayerClient* pChar, const char* szLine);
MQLIB_API void RemoveAugCmd                        (PlayerClient* pChar, const char* szLine);
MQLIB_API void ExecuteLinkCommand                  (PlayerClient* pChar, const char* szLine);

MQLIB_API void RemoveBuff                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void RemovePetBuff                       (PlayerClient* pChar, const char* szLine);
MQLIB_API void MakeMeVisible                       (PlayerClient* pChar, const char* szLine);
MQLIB_API void RemoveAura                          (PlayerClient* pChar, const char* szLine);

MQLIB_API void DeleteVarCmd                        (PlayerClient* pChar, const char* szLine);
MQLIB_API void VarSetCmd                           (PlayerClient* pChar, const char* szLine);
MQLIB_API void VarCalcCmd                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void VarDataCmd                          (PlayerClient* pChar, const char* szLine);

MQLIB_API void ProfileCmd                          (PlayerClient* pChar, const char* szLine);
MQLIB_API void ReloadUICmd                         (PlayerClient* pChar, const char* szLine);

} // namespace mq
