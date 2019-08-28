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

#if defined(ISXEQ_LEGACY) || !defined(ISXDK_VERSION)

/* COMMANDS */
EQLIB_API void SetError                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void SuperWho                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void NewIf                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void WhileCmd                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void PluginCommand                       (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Call                                (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DeclareVar                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DumpStack                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void EditMacro                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void EndMacro                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void For                                 (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Goto                                (PSPAWNINFO pChar, char* szLine);
EQLIB_API void KeepKeys                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Macro                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MacroPause                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Next                                (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Return                              (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Break                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Continue                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void ListMacros                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void SquelchCommand                      (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MacroLog                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MacroBeep                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Echo                                (PSPAWNINFO pChar, char* szLine);
EQLIB_API void NoParseCmd                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void NoModKeyCmd                         (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Where                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void CaptionColorCmd                     (PSPAWNINFO pChar, char* szLine);
EQLIB_API void CaptionCmd                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void HudCmd                              (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DropCmd                             (PSPAWNINFO pChar, char* szLine);
EQLIB_API void CombineCmd                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void ClearErrorsCmd                      (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoTimedCmd                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoShiftCmd                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoCtrlCmd                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoAltCmd                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoCommandCmd                        (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DumpBindsCommand                    (PSPAWNINFO pChar, char* szLine);
EQLIB_API void LoadCfgCommand                      (PSPAWNINFO pChar, char* szLine);
EQLIB_API void do_ranged                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoMappable                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MQ2KeyBindCommand                   (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MultilineCommand                    (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Alert                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Alias                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void AltAbility                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void BankList                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Breakin                             (PSPAWNINFO pChar, char* szLine);
EQLIB_API void BuyItem                             (PSPAWNINFO pChar, char* szLine);
EQLIB_API void SelectItem                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void CharInfo                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Cast                                (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Cleanup                             (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Click                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DebugSpewFile                       (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Delay                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void EQDestroyHeldItemOrMoney            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DisplayLoginName                    (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoAbility                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoEvents                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoSocial                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Doors                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void DoorTarget                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Exec                                (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Face                                (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Filter                              (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Help                                (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Hotkey                              (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Identify                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void IniOutput                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Items                               (PSPAWNINFO pChar, char* szLine);
EQLIB_API void ItemTarget                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void WindowState                         (PSPAWNINFO pChar, char* szLine);
EQLIB_API void LoadSpells                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Location                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Look                                (PSPAWNINFO pChar, char* szLine);
EQLIB_API void LootAll                             (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MemSpell                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MouseTo                             (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MQMsgBox                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void SellItem                            (PSPAWNINFO pChar, char* szLine);
EQLIB_API void SetAutoRun                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Skills                              (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Substitute                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void SuperWhoTarget                      (PSPAWNINFO pChar, char* szLine);
EQLIB_API void SWhoFilter                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Target                              (PSPAWNINFO pChar, char* szLine);
EQLIB_API void Unload                              (PSPAWNINFO pChar, char* szLine);
EQLIB_API void UpdateItemInfo                      (PSPAWNINFO pChar, char* szLine);
EQLIB_API void ZapVars                             (PSPAWNINFO pChar, char* szLine);
EQLIB_API void PopupText                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void PopupTextCustom                     (PSPAWNINFO pChar, char* szLine);
EQLIB_API void PopupTextEcho                       (PSPAWNINFO pChar, char* szLine);
EQLIB_API void UseItemCmd                          (PSPAWNINFO pChar, char* szLine);

EQLIB_API void SpellSlotInfo                       (PSPAWNINFO pChar, char* szLine);
EQLIB_API void SetWinTitle                         (PSPAWNINFO pChar, char* szLine);
EQLIB_API void GetWinTitle                         (PSPAWNINFO pChar, char* szLine);
EQLIB_API void PetCmd                              (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MercSwitchCmd                       (PSPAWNINFO pChar, char* szLine);
EQLIB_API void AdvLootCmd                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void PickZoneCmd                         (PSPAWNINFO pChar, char* szLine);
EQLIB_API void AssistCmd                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void InvokeCmd                           (PSPAWNINFO pChar, char* szLine);
EQLIB_API void SetProcessPriority                  (PSPAWNINFO pChar, char* szLine);
EQLIB_API void ScreenModeCmd                       (PSPAWNINFO pChar, char* szLine);
EQLIB_API void UserCameraCmd                       (PSPAWNINFO pChar, char* szLine);
EQLIB_API void MapZoomCmd                          (PSPAWNINFO pChar, char* szLine);
EQLIB_API void ForeGroundCmd                       (PSPAWNINFO pChar, char* szLine);
EQLIB_API void QuitCmd                             (PSPAWNINFO pChar, char* szLine);
EQLIB_API void EngineCommand                       (PSPAWNINFO pChar, char* szLine);
#endif
