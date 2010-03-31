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

COMMAND("Keypress",CMD_Keypress,true,false);
COMMAND("EQExecute",CMD_EQExecute,true,false);
COMMAND("MQ2Bind",CMD_MQ2Bind,true,false);
COMMAND("Who",CMD_Who,true,false);

/*
// TO BE CONVERTED
EQLIB_API VOID NoModKeyCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID CaptionColorCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID CaptionCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DropCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID CombineCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID ClearErrorsCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DoShiftCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DoCtrlCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DoAltCmd(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID DumpBindsCommand(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID do_ranged(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID MQ2KeyBindCommand(PSPAWNINFO pChar, PCHAR szLine);
EQLIB_API VOID Alert                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID AltAbility						   (PSPAWNINFO,PCHAR);
EQLIB_API VOID BankList                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID BuyItem                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID CharInfo                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Cast                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Cleanup                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID Click                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID DebugSpewFile                       (PSPAWNINFO,PCHAR);
EQLIB_API VOID EQDestroyHeldItemOrMoney				(PSPAWNINFO,PCHAR);
EQLIB_API VOID DisplayLoginName						(PSPAWNINFO,PCHAR);
EQLIB_API VOID DoAbility                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID DoEvents                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID DoSocial                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID Doors                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID DoorTarget                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID Exec                                (PSPAWNINFO,PCHAR); 
EQLIB_API VOID Face                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Filter                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID Help                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID Hotkey                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID Identify                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID IniOutput                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID Items                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID ItemTarget                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID WindowState							(PSPAWNINFO,PCHAR);
EQLIB_API VOID LoadSpells                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID Location                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Look                                (PSPAWNINFO,PCHAR);
EQLIB_API VOID MacroBeep                           (PSPAWNINFO,PCHAR);
EQLIB_API VOID MacroLog                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MemSpell                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID MouseTo                             (PSPAWNINFO,PCHAR);
EQLIB_API VOID MQMsgBox                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID SellItem                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID SetAutoRun                          (PSPAWNINFO,PCHAR);
EQLIB_API VOID SetError                            (PSPAWNINFO,PCHAR);
EQLIB_API VOID Skills                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID Substitute						   (PSPAWNINFO,PCHAR);
EQLIB_API VOID SuperWhoTarget                      (PSPAWNINFO,PCHAR);
EQLIB_API VOID SWhoFilter							(PSPAWNINFO,PCHAR);
EQLIB_API VOID Target                              (PSPAWNINFO,PCHAR);
EQLIB_API VOID UpdateItemInfo                      (PSPAWNINFO,PCHAR);
EQLIB_API VOID Where                               (PSPAWNINFO,PCHAR);
EQLIB_API VOID PopupText                           (PSPAWNINFO,PCHAR);
/**/

