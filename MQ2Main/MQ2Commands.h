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
LEGACY_API VOID SetError                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID SuperWho                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID NewIf                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID WhileCmd                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID PluginCommand                       (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Call                                (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DeclareVar                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DumpStack                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID EditMacro                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID EndMacro                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID For                                 (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Goto                                (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID KeepKeys                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Macro                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MacroPause                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Next                                (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Return                              (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Break                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Continue                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID ListMacros                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID SquelchCommand                      (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MacroLog                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MacroBeep                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Echo                                (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID NoParseCmd                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID NoModKeyCmd                         (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Where                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID CaptionColorCmd                     (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID CaptionCmd                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID HudCmd                              (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DropCmd                             (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID CombineCmd                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID ClearErrorsCmd                      (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoTimedCmd                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoShiftCmd                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoCtrlCmd                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoAltCmd                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoCommandCmd                        (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DumpBindsCommand                    (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID LoadCfgCommand                      (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID do_ranged                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoMappable                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MQ2KeyBindCommand                   (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MultilineCommand                    (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Alert                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Alias                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID AltAbility                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID BankList                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Breakin                             (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID BuyItem                             (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID SelectItem                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID CharInfo                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Cast                                (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Cleanup                             (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Click                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DebugSpewFile                       (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Delay                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID EQDestroyHeldItemOrMoney            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DisplayLoginName                    (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoAbility                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoEvents                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoSocial                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Doors                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID DoorTarget                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Exec                                (PSPAWNINFO pChar, PCHAR szLine); 
LEGACY_API VOID Face                                (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Filter                              (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Help                                (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Hotkey                              (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Identify                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID IniOutput                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Items                               (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID ItemTarget                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID WindowState                         (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID LoadSpells                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Location                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Look                                (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID LootAll                             (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MemSpell                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MouseTo                             (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MQMsgBox                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID SellItem                            (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID SetAutoRun                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Skills                              (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Substitute                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID SuperWhoTarget                      (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID SWhoFilter                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Target                              (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID Unload                              (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID UpdateItemInfo                      (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID ZapVars                             (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID PopupText                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID PopupTextCustom                     (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID PopupTextEcho                       (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID UseItemCmd                          (PSPAWNINFO pChar, PCHAR szLine);

LEGACY_API VOID SpellSlotInfo                       (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID SetWinTitle                         (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID GetWinTitle                         (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID PetCmd                              (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MercSwitchCmd                       (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID AdvLootCmd                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID PickZoneCmd                         (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID AssistCmd                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID InvokeCmd                           (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID SetProcessPriority                  (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID ScreenModeCmd                       (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID UserCameraCmd                       (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID MapZoomCmd                          (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID ForeGroundCmd                       (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID QuitCmd                             (PSPAWNINFO pChar, PCHAR szLine);
LEGACY_API VOID PluginCmdSort                       (VOID);
#endif
