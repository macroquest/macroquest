// MQ2ItemDisplay.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.


#ifndef ISXEQ
#include "../MQ2Plugin.h"
PreSetup("MQ2ItemDisplay");
#else
#include "../ISXEQClient.h"
#include "ISXEQItemDisplay.h"
#endif

void Comment(PSPAWNINFO pChar, PCHAR szLine); 

extern "C" {
__declspec(dllexport) ITEMINFO g_Item;
}

// *************************************************************************** 
// Function:    ItemDisplayHook
// Description: Our Item display hook 
// *************************************************************************** 
class ItemDisplayHook
{
   typedef enum {None = 0, Clicky, Proc, Worn, Focus, Scroll} SEffectType;

   static bool bNoSpellTramp;
   static SEffectType eEffectType;
public:
	   bool CXStrReplace (PCXSTR * Str, const char * cFind, const char * cReplace)
   {
      char cTemp[2048];
      DWORD dwSize = GetCXStr (*Str, cTemp, sizeof (cTemp));
      if (dwSize > 0 && dwSize < sizeof (cTemp) - 20) {
         char * cPtr = strstr (cTemp, cFind);
         if (cPtr != NULL) {
            char * cDup = strdup (cPtr);

            strcpy (cPtr, cReplace);
            strcpy (cPtr + strlen (cReplace), cDup + strlen (cFind));

            free (cDup);

            SetCXStr (Str, cTemp);
            return true;
         }
      }

      return false;
   }

   const char * GetRaceThreeLetterCode (int iRace)
   {
      switch (iRace) {
         case 1: return ("HUM");
         case 2: return ("BAR");
         case 3: return ("ERU");
         case 4: return ("ELF");
         case 5: return ("HIE");
         case 6: return ("DEF");
         case 7: return ("HEF");
         case 8: return ("DWF");
         case 9: return ("TRL");
         case 10:return ("OGR");
         case 11:return ("HLF");
         case 12:return ("GNM");
         case 13:return ("IKS");
         case 14:return ("VAH");
         case 15:return ("FRG");
      }

      return ("UNKNOWN RACE");
   }
    int GetDmgBonus (PCXSTR * Str)
   {
      char cTemp[2048];
      INT dmgbonuspos;
      INT dmgbonus = 0;
      INT badcharpos;

      GetCXStr(*Str, cTemp, sizeof (cTemp));
      
      string ItemDisplay;
      ItemDisplay = cTemp;

      char ActualDmgBonus[3];

      dmgbonuspos = ItemDisplay.find("Dmg Bonus:");
      
      if (dmgbonuspos != string::npos) {
         dmgbonuspos = dmgbonuspos + 11;
         ItemDisplay = ItemDisplay.substr(dmgbonuspos,3);

         badcharpos = ItemDisplay.find(" ");

         if (badcharpos != string::npos) { //found blank
            ItemDisplay = ItemDisplay.substr(0,2);
         }else{
            //badcharpos = tmpActualDmgBonus.find("<");
            badcharpos = ItemDisplay.find("<");
            if (badcharpos != string::npos) { //found <
               ItemDisplay = ItemDisplay.substr(0,2);
            }
         }

         strcpy (ActualDmgBonus,ItemDisplay.c_str());
         dmgbonus = atoi(ActualDmgBonus);
      }

      return dmgbonus;
   }
   VOID SetItem_Trampoline(class EQ_Item *pitem,bool unknown);
   VOID SetItem_Detour(class EQ_Item *pitem,bool unknown)
   {
      PEQITEMWINDOW This=(PEQITEMWINDOW)this;
      //PITEMINFO Item=*(PITEMINFO*)pitem;
      PCONTENTS item=(PCONTENTS)pitem;
      PITEMINFO Item=(PITEMINFO)item->Item;
      CHAR out[MAX_STRING] = {0};
      CHAR temp[MAX_STRING] = {0};
      CHAR temp2[MAX_STRING] = {0};
      PCHAR lore = NULL;
      SetItem_Trampoline(pitem,unknown);

      // keep a global copy of the last item displayed...
      memcpy(&g_Item, Item, sizeof(ITEMINFO));

      strcpy(out,"<BR><c \"#00FFFF\">");
	 if (Item->Cost>0) {
		  DWORD cp = Item->Cost;
		  DWORD sp = cp/10; cp=cp%10;
		  DWORD gp = sp/10; sp=sp%10;
		  DWORD pp = gp/10; gp=gp%10;
		  strcat(out,"Value:");
		  if (pp>0) {
			  sprintf(temp," %dpp",pp);
			  strcat(out,temp);
		  }
		  if (gp>0) {
			  sprintf(temp," %dgp",gp);
			  strcat(out,temp);
		  }
		  if (sp>0) {
			  sprintf(temp," %dsp",sp);
			  strcat(out,temp);
		  }
		  if (cp>0) {
			  sprintf(temp," %dcp",cp);
			  strcat(out,temp);
		  }
		  strcat(out,"<BR>");
	 }

	 if ( Item->Favor > 0 ) {
		 sprintf(temp,"Tribute Value: %d<br>", Item->Favor);
		 strcat(out, temp);
	 }
     if (Item->GuildFavor > 0 )  { 
        sprintf(temp,"Guild Tribute Value: %d<br>", Item->GuildFavor); 
        strcat(out, temp); 
     } 
	   //Outlaw (AKA CheckinThingsOut) (02/24/2005)
   if (Item->ItemType != 27) { //Arrows..they have dmg/dly but we don't want them
      if ( Item->Delay > 0) {
         if ( Item->Damage > 0) {
            sprintf(temp,"Ratio: %5.3f<br>", (float)Item->Delay / (float)Item->Damage);
            strcat(out, temp);
            //Calculate Efficiency
            INT dmgbonus = 0;

            if (GetCharInfo2()->Level > 27) { //bonus is 0 for anything below 28
               dmgbonus = GetDmgBonus(&This->ItemInfo);
            }

            sprintf(temp,"Efficiency: %3.0f<br>",((((float)Item->Damage * 2) + dmgbonus) / (float)Item->Delay) * 50);
            strcat(out, temp);
            if (Item->EquipSlots & 16384) { // Equipable In Secondary Slot
               sprintf(temp,"Offhand Efficiency: %3.0f<br>",((((float)Item->Damage * 2) / (float)Item->Delay) * 50) * 0.62);
               strcat(out, temp);
            }
            sprintf(temp,"<br>");
            strcat(out,temp);    
         }
      }
   }
     lore=Item->LoreName;
     if (lore[0]=='*') lore++;
     if (strcmp(lore,Item->Name)) {
      sprintf(temp,"Item Lore: %s<BR>",Item->LoreName);
      strcat(out,temp);
     }
	PCHARINFO pChar = GetCharInfo();     // Ziggy - for item level highlights 
    // Will be 0 for no effect or -1 if other effects present 
    if (Item->Proc.SpellID && Item->Proc.SpellID!=-1) { 
       if (Item->Proc.RequiredLevel == 0 ) 
          sprintf(temp, "Procs at level 1 (Proc rate modifier: %d)<BR>", Item->ProcRate); 
      else 
         sprintf(temp,"%sProcs at level %d%s (Proc rate modifier: %d)<BR>", (Item->Proc.RequiredLevel > GetCharInfo2()->Level ? "<c \"#FF4040\">" : ""), Item->Proc.RequiredLevel, (Item->Proc.RequiredLevel > GetCharInfo2()->Level ? "</C>" : ""), Item->ProcRate); 
       strcat(out,temp); 
     } 
   /* No longer needed? 
    else if (Item->SpellId==998) { // 998 = haste 
      sprintf(temp,"%d%% Haste<BR>",Item->Level+1); 
      strcat(out,temp); 
     } 
   */ 
	
	 // Just in case...
	 if ( (!strstr(This->ItemInfo->Text,"(Combat)")) && Item->ProcRate > 0 )
	 {
		 sprintf(temp, "Proc rate Modifier: %d<BR>", Item->ProcRate );
		 strcat(out,temp);
	 }

	 // Teh_Ish (02/08/2004) 
     if ( Item->Clicky.EffectType==4 || Item->Clicky.EffectType==1 || Item->Clicky.EffectType==5) {
		 if ( Item->Clicky.RequiredLevel == 0 )
			 sprintf(temp, "Clickable at level 1<br>");
		else
			sprintf(temp,"%sClickable at level %d%s<BR>", (Item->Clicky.RequiredLevel > GetCharInfo2()->Level ? "<c \"#FF4040\">" : ""), Item->Clicky.RequiredLevel, (Item->Clicky.RequiredLevel > GetCharInfo2()->Level ? "</C>" : ""));  
        strcat(out,temp); 
     }

	 // TheColonel (12/24/2003)
	if (Item->LDType == 1) {
        if(Item->LDCost == 0)
           sprintf(temp,"This drops in %s dungeons<BR>", GetLDoNTheme(Item->LDTheme));
        else
           sprintf(temp,"LDoN Cost: %d from %s<BR>", Item->LDCost, GetLDoNTheme(Item->LDTheme));
        strcat(out,temp);
     }
     if (Item->LDType == 2 && Item->LDCost > 0) {
        sprintf(temp,"Discord Cost: %d points<BR>", Item->LDCost);
        strcat(out,temp);
     }
     if (Item->LDType == 4 && Item->LDCost > 0) {
        sprintf(temp,"DoN Cost: %d Radiant Crystals<BR>", Item->LDCost);
        strcat(out,temp);
     }
     if (Item->LDType == 5 && Item->LDCost > 0) {
        sprintf(temp,"DoN Cost: %d Ebon Crystals<BR>", Item->LDCost);
        strcat(out,temp); 
     } 
     // TheColonel (1/18/2004)
 /*
     if (Item->InstrumentType != 0){ 
       float instrumentmod = ((float)Item->InstrumentMod)/10.0f; 
       sprintf(temp,"Instrument mod: %3.1f to %s.<BR>", instrumentmod, szItemTypes[Item->InstrumentType]); 
       strcat(out,temp);       
     } 
 /**/

     if (Item->Type == ITEMTYPE_PACK) {
        sprintf(temp,"Container Type: %s<BR>",szCombineTypes[Item->Combine]);
        strcat(out,temp);
     }

     if ( Item->ItemNumber > 0 ) { 
        sprintf(temp,"Item ID: %d<br>", Item->ItemNumber); 
        strcat(out, temp); 
     } 

	 sprintf(temp,"%07d",Item->ItemNumber); 
     GetPrivateProfileString("Notes",temp,"",temp2,MAX_STRING,INIFileName); 
     if (strlen(temp2)>0) 
     { 
        sprintf(temp,"Note: %s<br>",temp2); 
        strcat(out, temp); 
     }  

     if (out[0]!=17) {
      strcat(out,"</c>");
	  //((CXStr)This->ItemInfo)+=
      AppendCXStr(&This->ItemInfo,&out[0]);
     }
      // Ziggy - Highlight existing item display parts.
      // eg. Required level insufficient
      //     Wrong class, race, deity etc.
      if (GetCharInfo() != NULL) {
         char cFind[256];
         char cReplace[256];

         if (Item->RequiredLevel > GetCharInfo2()->Level) {
            sprintf (cFind, "Required level of %d.", Item->RequiredLevel);
            sprintf (cReplace, "<c \"#FF4040\">%s</C>", cFind);
            CXStrReplace (&This->ItemInfo, cFind, cReplace);
         }

         if (Item->RecommendedLevel > GetCharInfo2()->Level) {
            int iEffectiveness = (100 * GetCharInfo2()->Level / Item->RecommendedLevel);
            sprintf (cFind, "Recommended level of %d.", Item->RecommendedLevel);
            sprintf (cReplace, "<c \"#FF8020\">Recommended level of %d (%d%% effective).</C>", Item->RecommendedLevel, iEffectiveness);
            CXStrReplace (&This->ItemInfo, cFind, cReplace);
         }

         if (Item->Proc.RequiredLevel > GetCharInfo2()->Level) {
            sprintf (cFind, "<BR>Required Level: %d<BR>", Item->Proc.RequiredLevel);
            sprintf (cReplace, "<BR><c \"#FF4040\">Required Level: %d</C><BR>", Item->Proc.RequiredLevel);
            CXStrReplace (&This->ItemInfo, cFind, cReplace);
         }

         if (Item->Clicky.RequiredLevel > GetCharInfo2()->Level) {
            sprintf (cFind, "<BR>Required Level: %d<BR>", Item->Clicky.RequiredLevel);
            sprintf (cReplace, "<BR><c \"#FF4040\">Required Level: %d</C><BR>", Item->Clicky.RequiredLevel);
            CXStrReplace (&This->ItemInfo, cFind, cReplace);
         }

         // Highlight good/bad class match
         int iClassBit = 1 << (GetCharInfo2()->Class - 1);
         if (!(Item->Classes & iClassBit)) {
            char cClasses[64] = {0};
            int iClass = 1;
            for (WORD i = 1; i < 20; i++) {        // Only needs 15, but it's future proof.. oh yeah
               if (Item->Classes & iClass) {
                  char * cCode = pEverQuest->GetClassThreeLetterCode(i);
                  if (cCode == NULL) {
                     break;
                  }

                  strcat (cClasses, cCode);
                  strcat (cClasses, " ");
               }
               iClass *= 2;
            }

            sprintf (cFind, "Class:%s", cClasses);
            sprintf (cReplace, "Class:<c \"#FF4040\">%s</C>", cClasses);
            CXStrReplace (&This->ItemInfo, cFind, cReplace);

         } else {
            char * cCode = pEverQuest->GetClassThreeLetterCode(GetCharInfo2()->Class);
            sprintf (cFind, "%s ", cCode);
            sprintf (cReplace, "<c \"#20FF20\">%s</C>", cFind);

            if (!CXStrReplace (&This->ItemInfo, cFind, cReplace)) {
               sprintf (cReplace, "Class:  <c \"#20FF20\">ALL</C>", cFind);
               CXStrReplace (&This->ItemInfo, "Class:  ALL", cReplace);
            }
         }

         // Highlight good/bad race match
         DWORD raceNum;
         switch(GetCharInfo2()->Race) {
            case 0x80:  raceNum = 0xc; break;
            case 0x82:  raceNum = 0xd; break;
            case 0x4a:  raceNum = 0xe; break;
            default:    raceNum = GetCharInfo2()->Race - 1;
         }
         int iRaceBit = 1 << raceNum;
         if (!(Item->Races & iRaceBit)) {
            char cRaces[64] = {0};
            int iRace = 1;
            for (WORD i = 0; i < 20; i++) {
               if (Item->Races & iRace) {
                  const char * cCode = GetRaceThreeLetterCode(i + 1);
                  if (cCode == NULL) {
                     break;
                  }

                  strcat (cRaces, cCode);
                  strcat (cRaces, " ");
               }
               iRace *= 2;
            }

            sprintf (cFind, "Race:%s", cRaces);
            sprintf (cReplace, "Race:<c \"#FF4040\">%s</C>", cRaces);
            CXStrReplace (&This->ItemInfo, cFind, cReplace);

         } else {
            const char * cCode = GetRaceThreeLetterCode (raceNum + 1);
            sprintf (cFind, "%s ", cCode);
            sprintf (cReplace, "<c \"#20FF20\">%s</C>", cFind);

            if (!CXStrReplace (&This->ItemInfo, cFind, cReplace)) {
               sprintf (cReplace, "Race:  <c \"#20FF20\">ALL</C>", cFind);
               CXStrReplace (&This->ItemInfo, "Race:  ALL", cReplace);
            }
         }

         // Highlight deity mismatch
         if (Item->Diety != 0) {
            int iDeityBit = 1 << (GetCharInfo2()->Deity - 200);
            if (GetCharInfo2()->Deity < DEITY_Bertoxxulous || GetCharInfo2()->Deity > DEITY_Veeshan) {
               iDeityBit = 0;                         // Agnostic shows as 396
            }

            char * cPlayerD = pEverQuest->GetDeityDesc (GetCharInfo2()->Deity);

            strcpy (cFind, "Deity:");
            strcpy (cReplace, "Deity:");

			//Mahull Changes			
			//bool bMatch = (Item->Diety & iDeityBit);  // Do we have required deity?
			bool bMatch;
			
			if (Item->Diety & iDeityBit) {
				bMatch = true;
			}
			else {
				bMatch = false;
			}

            if (!bMatch) {
               strcat (cReplace, "<c \"#FF4040\">");
            }
			

            int iDeity = 1;
            int iAdded = 0;
            for (int i = 0; i < 16; i++) {
               if (Item->Diety & iDeity) {
                  const char * cDeity = pEverQuest->GetDeityDesc (i + 200);
                  if (cDeity == NULL) {
                     break;
                  }

                  if (strlen (cFind) > 6) {
                     strcat (cReplace, ",");    // We comma seperate, for clarity
                  }

                  if (iAdded > 0 && iAdded % 5 == 0) {
                     strcat (cFind, "<BR>");    // They force a new-line per 5
                  }
                  iAdded++;

                  strcat (cFind, "  ");         // 2 spaces before each deity
                  strcat (cReplace, " ");       // 1 space after our comma though

                  if (strcmp (cDeity, cPlayerD) == 0) {     // Ours?
                     strcat (cReplace, "<c \"#20FF20\">");  // Green it
                  }

                  strcat (cFind, cDeity);
                  strcat (cReplace, cDeity);

                  if (strcmp (cDeity, cPlayerD) == 0) {
                     strcat (cReplace, "</C>");
                  }
               }
               iDeity *= 2;
            }

            if (!bMatch) {
               strcat (cReplace, "</C>");
            }

            CXStrReplace (&This->ItemInfo, cFind, cReplace);
         }
      }
 
      // Ziggy - Items showing their spell details:
      bNoSpellTramp=true;
      if (Item->Clicky.SpellID > 0 && Item->Clicky.SpellID != -1) {
         eEffectType = Clicky;
         SetSpell_Detour(Item->Clicky.SpellID, false, 0);
      }

      if (Item->Proc.SpellID > 0 && Item->Proc.SpellID != -1) {
         eEffectType = Proc;
         SetSpell_Detour(Item->Proc.SpellID, false, 0);
      }

      if (Item->Worn.SpellID > 0 && Item->Worn.SpellID != -1) {
         eEffectType = Worn;
         SetSpell_Detour(Item->Worn.SpellID, false, 0);
      }

      if (Item->Focus.SpellID > 0 && Item->Focus.SpellID != -1) {
         eEffectType = Focus;
         SetSpell_Detour(Item->Focus.SpellID, false, 0);
      }

      if (Item->Scroll.SpellID > 0 && Item->Scroll.SpellID != -1) {
         eEffectType = Scroll;
         SetSpell_Detour(Item->Scroll.SpellID, false, 0);
      }
      bNoSpellTramp=false;
      eEffectType = None;
   }

   VOID SetSpell_Trampoline(int SpellID,bool HasSpellDescr,int unknown_int);
   VOID SetSpell_Detour(int SpellID,bool HasSpellDescr,int unknown_int)
   {
     PEQITEMWINDOW This=(PEQITEMWINDOW)this;
     PCHARINFO pCharInfo = NULL;
     if (NULL == (pCharInfo = GetCharInfo())) return;
     PSPELL pSpell = GetSpellByID(SpellID);
     if (pSpell == NULL) {
        return;
     }

     CHAR out[MAX_STRING] = {0};
     CHAR temp[MAX_STRING] = {0};
     if (!bNoSpellTramp) {
        SetSpell_Trampoline(SpellID,HasSpellDescr,unknown_int);
        strcpy(out,"<BR><c \"#00FFFF\">");
     } else {
        char * cColour = "FF0000", * cName = "Blub";

        switch (eEffectType) {
           case Clicky:
              cColour = "00FF00";
              cName = "Clicky";
              break;
           case Proc:
              cColour = "FF00FF";
              cName = "Proc";
              break;
           case Worn:
              cColour = "FFFF00";
              cName = "Worn";
              break;
           case Focus:
              cColour = "9F9F00";
              cName = "Focus";
              break;
           case Scroll:
              cColour = "9F9F9F";
              cName = "Scroll";
              break;
        }

        sprintf (out, "<BR><c \"#%s\">Spell Info for %s effect: %s<br>", cColour, cName, pSpell->Name);
     }

	 sprintf(temp, "ID: %04d&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", pSpell->ID );
	 strcat(out,temp);

	 DWORD Tics=GetSpellDuration(pSpell,pCharInfo->pSpawn);
     if (Tics==0xFFFFFFFF)
	    strcat(out, "Duration: Permanent<br>" );
     else if (Tics==0xFFFFFFFE) 
	    strcat(out, "Duration: Unknown<br>" );
	 else if (Tics==0) {
	    // It's "instant", who cares?
		 strcat(out,"<br>");
	 }
     else {
		sprintf(temp, "Duration: %1.1f minutes<br>",(float)((Tics*6.0f)/60.0f));
		strcat(out, temp);
     }

	 sprintf(temp, "RecoveryTime: %1.2f&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RecastTime: %1.2f <br>", (float)(pSpell->FizzleTime/1000.0f), (float)(pSpell->RecastTime/1000.0f) );
	 strcat(out,temp);

	 if (pSpell->Range > 0.0f ) {
		 sprintf(temp, "Range: %1.0f", pSpell->Range );
		 strcat(out,temp);
		 if ( pSpell->PushBack == 0.0f && pSpell->AERange == 0.0f)
			 strcat(out, "<br>");
	 }

	 if (pSpell->PushBack != 0.0f ) {
		 if (pSpell->Range > 0.0f ) 
			 strcat(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" );
		 sprintf(temp, "PushBack: %1.1f", pSpell->PushBack );
		 strcat(out, temp);
		 if (pSpell->AERange == 0.0f || pSpell->Range > 0.0f )
			 strcat(out, "<br>" );
	 }

	 if (pSpell->AERange > 0.0f ) {
		 if (pSpell->Range > 0.0f)
			 strcat(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" );
		 else if (pSpell->PushBack > 0.0f )
			 strcat(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" );
		 sprintf(temp, "AERange: %1.0f<br>", pSpell->AERange );
		 strcat(out, temp);
	 }

	 if (pSpell->TargetType != 0x06 && pSpell->TargetType != 0x0e && pSpell->TargetType != 0x03 && pSpell->TargetType != 0x28 && pSpell->TargetType != 0x29 ) {
		   if (pSpell->SpellType == 0) {   // Ziggy: Only show resist type for detrimental spells
          switch(pSpell->Resist) {
             case 7: strcat(out, "Resist: Prismatic[Avg]" ); break; // Ziggy - Added Reminder which..
             case 6: strcat(out, "Resist: Chromatic[Low]" ); break; // ..is what type of resist
             case 5: strcat(out, "Resist: Disease" ); break;
             case 4: strcat(out, "Resist: Poison" ); break;
             case 3: strcat(out, "Resist: Cold/Ice" ); break;
             case 2: strcat(out, "Resist: Fire" ); break;
             case 1: strcat(out, "Resist: Magic" ); break;
             case 0: strcat(out, "Resist: Unresistable"); break;
          }

          if (pSpell->ResistAdj != 0 ) {
             sprintf(temp, "&nbsp;&nbsp;&nbsp;(Resist Adj.: %d)<br>", pSpell->ResistAdj );
             strcat(out,temp);
          } else {
             strcat(out,"<br>");
          }
       } 
	 }

	 strcat(out, "<br>" );
	 ShowSpellSlotInfo(pSpell,&out[strlen(out)]);

	 //show usable classes routine by Koad//
     bool bUseableClasses = false; 
	 strcat(out, "<br>" ); 
    for (int j=0; j<16; j++) {  // Ziggy - output will word wrap properly now
       if (pSpell->Level[j]>0 && pSpell->Level[j]<=70) {
          if (bUseableClasses) strcat (out, ", ");

          sprintf(temp,"%s(%d)", GetClassDesc(j+1), pSpell->Level[j]);
          strcat(out, temp);
          bUseableClasses = true;
       }
    } 
	 if (bUseableClasses) strcat(out, "<br><br>" ); 

     if (pSpell->CastOnYou[0]) { 
       sprintf(temp, "Cast on you: %s<br>", pSpell->CastOnYou); 
       strcat(out,temp); 
     } 

   if (pSpell->CastOnAnother[0]) { 
    sprintf(temp, "Cast on another: %s<br>", pSpell->CastOnAnother); 
    strcat(out,temp); 
   } 

   if (pSpell->WearOff[0]) { 
    sprintf(temp, "Wears off: %s<br>", pSpell->WearOff); 
    strcat(out,temp); 
   } 


	 if (out[0]!=17) {
     strcat(out,"</c>");
	 //((CXStr)This->ItemInfo)+=
	 AppendCXStr(&This->ItemInfo,&out[0]);   
     }
   }
};

ItemDisplayHook::SEffectType ItemDisplayHook::eEffectType = None;
bool ItemDisplayHook::bNoSpellTramp = false;

DETOUR_TRAMPOLINE_EMPTY(VOID ItemDisplayHook::SetItem_Trampoline(class EQ_Item *,bool)); 
DETOUR_TRAMPOLINE_EMPTY(VOID ItemDisplayHook::SetSpell_Trampoline(int SpellID,bool HasSpellDescr,int));

void Comment(PSPAWNINFO pChar, PCHAR szLine) 
{ 
   CHAR Arg[MAX_STRING] = {0}; 
   CHAR ItemNo[MAX_STRING] = {0}; 
   CHAR Comment[MAX_STRING] = {0}; 
   CHAR szTemp[MAX_STRING] = {0}; 
   GetArg(Arg,szLine,1); 
   GetArg(ItemNo,szLine,2); 
   GetArg(szTemp,szLine,3); 
   for(int i=4;strlen(szTemp);i++){ 
      strcat(Comment,szTemp); 
      strcat(Comment," "); 
      GetArg(szTemp,szLine,i); 
   } 
   int itemno = atoi(ItemNo); 
 
   if (stricmp(Arg,"add") && stricmp(Arg,"del")) 
   { 
      WriteChatColor("Use: /inote <add|del> <itemno> \"Comment\"",CONCOLOR_YELLOW); 
      return; 
   } 
   if (itemno <= 0) 
   { 
      WriteChatColor("Invalid item number"); 
      WriteChatColor("Use: /inote <add|del> <itemno> \"Comment\"",CONCOLOR_YELLOW); 
      return; 
   } 
   if (strlen(Comment)==0 || !stricmp(Arg,"del")) 
   { 
      sprintf(szTemp,"%07d",itemno); 
      WritePrivateProfileString("Notes",szTemp,"",INIFileName); 
      return; 
   } 
 
   if (!stricmp(Arg,"add")) 
   { 
      sprintf(szTemp,"%07d",itemno); 
      WritePrivateProfileString("Notes",szTemp,Comment,INIFileName); 
      return; 
   } 
} 
 

#ifndef ISXEQ
// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2ItemDisplay");

	// Add commands, macro parameters, hooks, etc.

//   EasyClassDetour(CItemDisplayWnd__SetItem,ItemDisplayHook,SetItem_Detour,void,(class EQ_Item *, bool),SetItem_Trampoline);
	EzDetour(CItemDisplayWnd__SetItem,ItemDisplayHook::SetItem_Detour,ItemDisplayHook::SetItem_Trampoline);
//   EasyClassDetour(CItemDisplayWnd__SetSpell,ItemDisplayHook,SetSpell_Detour,void,(int SpellID,bool HasSpellDescr,int),SetSpell_Trampoline);
	EzDetour(CItemDisplayWnd__SetSpell,ItemDisplayHook::SetSpell_Detour,ItemDisplayHook::SetSpell_Trampoline);

	AddCommand("/inote",Comment); 
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2ItemDisplay");

	// Remove commands, macro parameters, hooks, etc.
	RemoveDetour(CItemDisplayWnd__SetItem);
	RemoveDetour(CItemDisplayWnd__SetSpell);

	RemoveCommand("/inote");
}
#endif
