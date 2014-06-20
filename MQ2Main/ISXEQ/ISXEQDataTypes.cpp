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

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW

#include "..\MQ2Main.h"

// These are the same types as in MQ2DataTypes.cpp, however ISXEQ types have method, as
// the GetMethod function takes care of here.

bool MQ2SpawnType::GETMETHOD()
{
#define pPtr ((PSPAWNINFO)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2SpawnType::FindMethod(Method);
	if (!pMethod)
		return false;
	switch((SpawnMethods)pMethod->ID)
	{
	case Target:
		*ppTarget=GetSpawnByID(pPtr->SpawnID); // this could be a variable, which is just a copy. use its ID
		return true;
   case Face: 
      { 
         PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(pPtr->SpawnID); 
         if (pSpawn->SpawnID==((PSPAWNINFO)pCharSpawn)->SpawnID)   // If it is ourself, don't do anything. 
            return true; 
         bool bfPredict=false; 
         bool bfAway=false; 
         bool bfNolook=false; 
         bool bfFast=false; 
         gFaceAngle = ( 
            atan2(pSpawn->X - ((PSPAWNINFO)pCharSpawn)->X, 
            pSpawn->Y - ((PSPAWNINFO)pCharSpawn)->Y) 
            * 256.0f / PI); 
         while (argc--) 
         { 
            if (!stricmp(argv[argc],"predict")) 
               bfPredict=true; 
            else if (!stricmp(argv[argc],"nolook")) 
               bfNolook=true; 
            else if (!stricmp(argv[argc],"away")) 
               bfAway=true; 
            else if (!stricmp(argv[argc],"fast")) 
               bfFast=true; 
         } 
         if (bfPredict) 
         { 
            DOUBLE Distance; 
            Distance = DistanceToSpawn((PSPAWNINFO)pCharSpawn, pSpawn); 
            gFaceAngle = ( 
               atan2((pSpawn->X + (pSpawn->SpeedX * Distance)) - ((PSPAWNINFO)pCharSpawn)->X, 
               (pSpawn->Y + (pSpawn->SpeedY * Distance)) - ((PSPAWNINFO)pCharSpawn)->Y) 
               * 256.0f / PI); 
         } 
         if (!bfNolook) { 
            DOUBLE Distance = DistanceToSpawn((PSPAWNINFO)pCharSpawn, pSpawn); 
            gLookAngle = ( 
               atan2(pSpawn->Z + pSpawn->AvatarHeight*StateHeightMultiplier(pSpawn->StandState) - ((PSPAWNINFO)pCharSpawn)->Z - 
               ((PSPAWNINFO)pCharSpawn)->AvatarHeight*StateHeightMultiplier(((PSPAWNINFO)pCharSpawn)->StandState), 
               (FLOAT)Distance) 
               * 256.0f / PI); 
            if (bfAway) gLookAngle = -gLookAngle; 
            if (bfFast) { 
               ((PSPAWNINFO)pCharSpawn)->CameraAngle = (FLOAT)gLookAngle; 
               gLookAngle=10000.0f; 
            } 
         } 
         if (bfAway) { 
            gFaceAngle += 256.0f; 
         } 
         if (gFaceAngle>=512.0f) gFaceAngle -= 512.0f; 
         if (gFaceAngle<0.0f) gFaceAngle += 512.0f; 
         if (bfFast) { 
            ((PSPAWNINFO)pCharSpawn)->Heading = (FLOAT)gFaceAngle; 
            gFaceAngle=10000.0f; 
         } 
      } 
      return true; 

   case LeftClick: 
      { 
      PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(pPtr->SpawnID); 
      pEverQuest->LeftClickedOnPlayer((EQPlayer *)pSpawn); 
      return true; 
      } 
   case RightClick: 
      { 
      PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(pPtr->SpawnID); 
      pEverQuest->RightClickedOnPlayer((EQPlayer *)pSpawn, 0); 
      return true; 
      } 
	case xAssist:
		return true;
	}
	return false;
#undef pPtr
}


bool MQ2BuffType::GETMETHOD()
{
#define pPtr ((PSPELLBUFF)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	if ((int)pPtr->SpellID<=0)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2BuffType::FindMethod(Method);
	if (!pMethod)
	{
		if (PSPELL pSpell=GetSpellByID(pPtr->SpellID))
		{
			LSVARPTR Temp;
			Temp.Ptr=pSpell;
			return pSpellType->GetMethod(Temp,Method,argc,argv);
		}
		return false;
	}
	switch((BuffMethods)pMethod->ID)
	{
	case Remove:
		{
			unsigned long slot;
			char Temp[16];
			if (GetBuffID(pPtr,(DWORD&)slot))
			{
				sprintf(Temp,"Buff%d",slot-1); 
				DWORD KeyboardFlags;
				KeyboardFlags=*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags;
				*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags=0;   
				SendWndClick("BuffWindow",Temp,"leftmouseup");
				*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags=KeyboardFlags; 		
				return true;
			}
			if (GetShortBuffID(pPtr,(DWORD&)slot))
			{
				sprintf(Temp,"Buff%d",slot-1); 
				DWORD KeyboardFlags;
				KeyboardFlags=*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags;
				*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags=0;   
				SendWndClick("ShortDurationBuffWindow",Temp,"leftmouseup");
				*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags=KeyboardFlags; 		
				return true;
			}
		}
		return false;
	}
	return false;
#undef pPtr
}


bool MQ2CharacterType::GETMETHOD()
{
#define pPtr ((PCHARINFO)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2CharacterType::FindMethod(Method);
	if (!pMethod)
	{
		LSVARPTR Temp;
		Temp.Ptr=pPtr->pSpawn;
		return pSpawnType->GetMethod(Temp,Method,argc,argv);
	}
   switch((CharacterMethods)pMethod->ID)
   {
      case Stand:
      {
         EzCommand("/stand");
         return true;
      }
      case Sit:
      {
         EzCommand("/sit");
         return true;
      }
      case Dismount:
      {
         EzCommand("/dismount");
         return true;
      }
   } 
	return false;
#undef pPtr
}


bool MQ2SpellType::GETMETHOD()
{
#define pPtr ((PSPELL)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2SpellType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((SpellMethods)pMethod->ID)
//	{
//	}
	return false;
#undef pPtr
}


bool MQ2ItemType::GETMETHOD()
{
#define pPtr ((PCONTENTS)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2ItemType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((ItemMethods)pMethod->ID)
//	{
//	}
	return false;
#undef pPtr
}


bool MQ2WindowType::GETMETHOD()
{
#define pPtr ((CXWnd*)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2WindowType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	CXRect rect= pPtr->GetScreenRect();
	CXPoint pt=rect.CenterPoint();
	switch((WindowMethods)pMethod->ID)
	{
	case LeftMouseDown:
		pPtr->HandleLButtonDown(&pt,0);
		return true;
	case LeftMouseUp:
		pPtr->HandleLButtonDown(&pt,0);
		pPtr->HandleLButtonUp(&pt,0);
		return true;
	case LeftMouseHeldDown:
				pPtr->HandleLButtonDown(&pt,0);
				pPtr->HandleLButtonHeld(&pt,0);
		return true;
	case LeftMouseHeldUp:
				pPtr->HandleLButtonDown(&pt,0);
				pPtr->HandleLButtonHeld(&pt,0);
				pPtr->HandleLButtonUpAfterHeld(&pt,0);
		return true;
	case RightMouseDown:
				pPtr->HandleRButtonDown(&pt,0);
		return true;
	case RightMouseUp:
				pPtr->HandleRButtonDown(&pt,0);
				pPtr->HandleRButtonUp(&pt,0);
		return true;
	case RightMouseHeldDown:
				pPtr->HandleRButtonDown(&pt,0);
				pPtr->HandleRButtonHeld(&pt,0);
		return true;
	case RightMouseHeldUp:
				pPtr->HandleRButtonDown(&pt,0);
				pPtr->HandleRButtonHeld(&pt,0);
				pPtr->HandleRButtonUpAfterHeld(&pt,0);
		return true;
	case ListSelect:
		if (argc)
		{
			DWORD Value=atoi(argv[0])-1;
			if (pPtr->GetType()==UI_Listbox)
				((CListWnd *)pPtr)->SetCurSel(Value);
			else if (pPtr->GetType()==UI_Combobox)
				((CComboWnd*)pPtr)->SetChoice(Value);
			else
				return false;
		}
		return true;
	}
	return false;
#undef pPtr
}


bool MQ2SwitchType::GETMETHOD()
{
#define pPtr ((PDOOR)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2SwitchType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	return false;
#undef pPtr
}


bool MQ2GroundType::GETMETHOD()
{
#define pPtr ((PGROUNDITEM)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2GroundType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	return false;
#undef pPtr
}


bool MQ2EverQuestType::GETMETHOD()
{
	PMQ2TYPEMETHOD pMethod=MQ2EverQuestType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((EverQuestMethods)pMethod->ID)
//	{
//	}
	return false;
}

bool MQ2MacroQuestType::GETMETHOD()
{
	PMQ2TYPEMETHOD pMethod=MQ2MacroQuestType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((MacroQuestMethods)pMethod->ID)
//	{
//	}
	return false;
}

bool MQ2HeadingType::GETMETHOD()
{
	PMQ2TYPEMETHOD pMethod=MQ2HeadingType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((HeadingMethods)pMethod->ID)
//	{
//	}
	return false;
}


bool MQ2CorpseType::GETMETHOD()
{
	if (!pActiveCorpse || !pLootWnd)
		return false;
#define pPtr ((PEQLOOTWINDOW)pLootWnd)
	PMQ2TYPEMETHOD pMethod=MQ2CorpseType::FindMethod(Method);
	if (!pMethod)
	{
		LSVARPTR Temp;
		Temp.Ptr=pActiveCorpse;
		return pSpawnType->GetMethod(Temp,Method,argc,argv);
	}
	// TODO
//	switch((CorpseMethods)pMethod->ID)
//	{
//	}
	return false;
#undef pPtr
}


bool MQ2MerchantType::GETMETHOD()
{
	if (!pActiveMerchant || !pMerchantWnd)
		return false;
#define pPtr ((PEQMERCHWINDOW)pMerchantWnd)
	PMQ2TYPEMETHOD pMethod=MQ2MerchantType::FindMethod(Method);
	if (!pMethod)
	{
		LSVARPTR Temp;
		Temp.Ptr=pActiveMerchant;
		return pSpawnType->GetMethod(Temp,Method,argc,argv);
	}
	// TODO
//	switch((MerchantMethods)pMethod->ID)
//	{
//	}
	return false;
#undef pPtr
}


bool MQ2InvSlotType::GETMETHOD()
{
#define nInvSlot (VarPtr.Int)
	PMQ2TYPEMETHOD pMethod=MQ2InvSlotType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((InvSlotMethods)pMethod->ID)
//	{
//	}
	return false;
#undef nInvSlot
}



bool MQ2TimerType::GETMETHOD()
{
#define pPtr ((PMQTIMER)VarPtr.Ptr)
   if (!VarPtr.Ptr)
      return false;
   PMQ2TYPEMETHOD pMethod=MQ2TimerType::FindMethod(Method);
   if (!pMethod)
   {
      return false;
   }
   switch((TimerMethods)pMethod->ID)
   {
   case Reset:
      pPtr->Current=pPtr->Original;
      return true;
   case Expire:
      pPtr->Current=1;  // Will expire in a 10th of a second
      return true;
   case Set:
      if (argc)
      {
         MQ2TimerType::FromString(VarPtr,argv[0]);
         return true;
      }
   }
   return false;
#undef pPtr
} 


bool MQ2SkillType::GETMETHOD()
{
	if (!VarPtr.Ptr)
		return false;
	PSKILL pSkill=*(PSKILL*)VarPtr.Ptr;
	if (!pSkill)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2SkillType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((SkillMethods)pMethod->ID)
//	{
//	}
	return false;
}


bool MQ2AltAbilityType::GETMETHOD()
{
	if (!VarPtr.Ptr)
		return false;
	PALTABILITY pAbility=*(PALTABILITY*)VarPtr.Ptr;
	PMQ2TYPEMETHOD pMethod=MQ2AltAbilityType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((AltAbilityMethods)pMethod->ID)
//	{
//	}
	return false;
}


bool MQ2RaidType::GETMETHOD()
{
	if (!pRaid)
		return false;
	PMQ2TYPEMETHOD pMethod=MQ2RaidType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((RaidMethods)pMethod->ID)
//	{
//	}
	return false;
}


bool MQ2RaidMemberType::GETMETHOD()
{
	DWORD nRaidMember=VarPtr.DWord-1;
	if (VarPtr.DWord>=72)
		return false;
	if (!pRaid->RaidMemberUsed[nRaidMember])
		return false;
	PEQRAIDMEMBER pRaidMember=&pRaid->RaidMember[nRaidMember];
	PMQ2TYPEMETHOD pMethod=MQ2RaidMemberType::FindMethod(Method);
	if (!pMethod)
	{
		LSVARPTR Temp;
		Temp.Ptr=SpawnByName[pRaidMember->Name];
		return pSpawnType->GetMethod(Temp,Method,argc,argv);
	}
	// TODO
//	switch((RaidMemberMethods)pMethod->ID)
//	{
//	}
	return false;
}

bool MQ2FriendsType::GETMETHOD()
{
	PMQ2TYPEMETHOD pMethod=MQ2FriendsType::FindMethod(Method);
	if (!pMethod)
	{
		return false;
	}
	// TODO
//	switch((FriendsMethods)pMethod->ID)
//	{
//	}
	return false;
}

bool MQ2TargetType::GETMETHOD()
{
#define pPtr ((PSPAWNINFO)VarPtr.Ptr)
   if (!VarPtr.Ptr)
      return false;
   PMQ2TYPEMETHOD pMethod=MQ2TargetType::FindMethod(Method);
   if (!pMethod)
      return false;
   else
      return true;
#undef pPtr
}

bool MQ2XTargetType::GETMETHOD()
{
#define pPtr ((PSPAWNINFO)VarPtr.Ptr)
   if (!VarPtr.Ptr)
      return false;
   PMQ2TYPEMETHOD pMethod=MQ2XTargetType::FindMethod(Method);
   if (!pMethod)
      return false;
   else
      return true;
#undef pPtr
}
