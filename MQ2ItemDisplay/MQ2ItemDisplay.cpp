// MQ2ItemDisplay.cpp : Defines the entry point for the DLL application.
//
////
//		This plugin will provide fast item comparisons based strictly on the base 
//		armor status. It does NOT add in augs. This makes it bad for cultural vs 
//		traditional gear.
//
//		/iScore 			; shows basic status 
//	    /iScore AC 10 		; scores AC as 10:1 
//      /iScore HP 1 		; scores HP as 1:1 
//      /iScore HeroicSTA 15; scores HeroicSTA at 15:1 
//
////
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

// thanks, finally, SOE. we'll leave this here for a while and eventually remove it
#define DISABLE_TOOLTIP_TIMERS

void Comment(PSPAWNINFO pChar, PCHAR szLine);
#ifndef ISXEQ // TODO If we want GearScore under IS, this needs ported to ISXEQItemDisplay 
void DoGearScoreUserCommand(PSPAWNINFO pChar, PCHAR szLine);
void AddGearScores(PCONTENTS pSlot,ITEMINFO *pItem,char *out,char *br);
#endif
typedef struct _DISPLAYITEMSTRINGS
{
	std::string ItemInfo;////this item is placable in yards, guild yards blah blah , This item can be used in tradeskills
	std::string WindowTitle;
	std::string ItemAdvancedLoreText;
	std::string ItemMadeByText;
	std::string ItemInformationText;//Item Information: Placing this augment into blah blah, this armor can only be used in blah blah
} DISPLAYITEMSTRINGS,*PDISPLAYITEMSTRINGS;

extern "C" {
	__declspec(dllexport) class MQ2DisplayItemType *pDisplayItemType = 0;
    __declspec(dllexport) ITEMINFO g_Item;
	__declspec(dllexport) CONTENTS g_Contents[6] = { 0 };
	__declspec(dllexport) DWORD g_LastIndex = 5;
	__declspec(dllexport) HANDLE hDisplayItemLock = 0;
	__declspec(dllexport) std::map<DWORD,DISPLAYITEMSTRINGS>contentsitemstrings;
}
class MQ2DisplayItemType : public MQ2Type {
private:
	char Temps[MAX_STRING];
public:
	enum DisplayItemMembers {
		Info = 1,
		WindowTitle = 2,
		AdvancedLore = 3,
		MadeBy = 4,
		Information = 5,
		DisplayIndex = 6
	};
	MQ2DisplayItemType() :MQ2Type("DisplayItem") {
		TypeMember(Info);
		TypeMember(WindowTitle);
		TypeMember(AdvancedLore);
		TypeMember(MadeBy);
		TypeMember(Information);
		TypeMember(DisplayIndex);
	}
	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest) {
		int index = VarPtr.DWord;
		PCONTENTS pCont = &g_Contents[index];
		PMQ2TYPEMEMBER pMember = MQ2DisplayItemType::FindMember(Member);
		if (!pMember)
		{
			
#ifndef ISXEQ
			return pItemType->GetMember(*(MQ2VARPTR*)&pCont, Member, Index, Dest);
#else
			return pItemType->GetMember(*(LSVARPTR*)&pCont, Member, argc, argv, Dest);
#endif
		}
		if (pMember) {
			switch ((DisplayItemMembers)pMember->ID) {
			case Info:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].ItemInfo.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case WindowTitle:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].WindowTitle.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case AdvancedLore:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].ItemAdvancedLoreText.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case MadeBy:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].ItemMadeByText.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case Information:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].ItemInformationText.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case DisplayIndex:
				Dest.DWord = g_LastIndex;
				Dest.Type = pIntType;
				return true;
			}
		}
		return false;
	}
	DECLAREGETMETHOD();
	INHERITDIRECT(pItemType);
	bool ToString(MQ2VARPTR VarPtr, PCHAR Destination) {
		if(PCONTENTS pCont = &g_Contents[VarPtr.DWord]) {
			if(PITEMINFO pItem = GetItemFromContents(pCont)) {
				strcpy_s(Destination,128, pItem->Name);
				return true;
			}
		}
		strcpy_s(Destination,128, contentsitemstrings[VarPtr.DWord].WindowTitle.c_str());
		return true;
	}
	bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source) {
		return false;
	}
	bool FromString(MQ2VARPTR &VarPtr, PCHAR Source) {
		return false;
	}
	~MQ2DisplayItemType() { }
};
BOOL dataLastItem(PCHAR szName, MQ2TYPEVAR &Ret)
{
	lockit lockid(hDisplayItemLock);
	if (szName[0])
	{
		if(IsNumber(szName)) {
			int index = atoi(szName);
			if (index<6 && g_Contents[index].vtable) {
				Ret.DWord = index;
				Ret.Type = pDisplayItemType;
				return true;
			}
		}
	} else {
		 if (g_Contents[g_LastIndex].vtable) {
			 Ret.DWord = g_LastIndex;
			 Ret.Type = pDisplayItemType;
			 return true;
		 }
	}
	return false;
}

// *************************************************************************** 
// Function:    ItemDisplayHook
// Description: Our Item display hook 
// *************************************************************************** 
class ItemDisplayHook
{
    typedef enum {None = 0, Clicky, Proc, Worn, Focus, Scroll, Focus2} SEffectType;

    static bool bNoSpellTramp;
    static SEffectType eEffectType;

public:
	// bool CXStrReplace(...)						- Not used so I removed it - Dewey2461
	// const char * GetRaceThreeLetterCode(...)		- Not used so I removed it - Dewey2461

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

    VOID SetSpell_Trampoline(int SpellID,bool HasSpellDescr);
    VOID SetSpell_Detour(int SpellID,bool HasSpellDescr)
    {
        PEQSPELLINFOWINDOW This=(PEQSPELLINFOWINDOW)this;
        PCHARINFO pCharInfo = NULL;
        if (NULL == (pCharInfo = GetCharInfo())) return;
        PSPELL pSpell = GetSpellByID(SpellID);
        if (pSpell == NULL) {
            return;
        }
        CHAR out[MAX_STRING] = {0};
        CHAR temp[MAX_STRING] = {0};
        if (!bNoSpellTramp) {
            SetSpell_Trampoline(SpellID,HasSpellDescr);
            strcat(out,"<BR><c \"#00FFFF\">");
        } else {
            char * cColour = "FF0000", * cName = "Blub";

            switch (eEffectType)
            {
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
            case Focus2:
                cColour = "9F9F00";
                cName = "Focus";
                break;
            case Scroll:
                cColour = "9F9F9F";
                cName = "Scroll";
                break;
            }

            sprintf (temp, "<BR><c \"#%s\">Spell Info for %s effect: %s<br>", cColour, cName, pSpell->Name);
			strcat(out,temp);

        }

        sprintf(temp, "ID: %04d&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", pSpell->ID );
        strcat(out,temp);

        DWORD Tics=GetSpellDuration(pSpell,(PSPAWNINFO)pLocalPlayer);
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

        if (pSpell->TargetType != 0x06 && pSpell->TargetType != 0x0e && pSpell->TargetType != 0x03 && pSpell->TargetType != 0x28 && pSpell->TargetType != 0x29) {
            if (pSpell->SpellType == 0) {   // Ziggy: Only show resist type for detrimental spells
                switch(pSpell->Resist)
                {
                case 9: strcat(out, "Resist: Corruption" ); break;
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

		if (pSpell->HateGenerated) {
            sprintf(temp, "Hate Generated: %d<br>", pSpell->HateGenerated);
            strcat(out,temp);
		}

		strcat(out, "<br>" );
        ShowSpellSlotInfo(pSpell,&out[strlen(out)]);

        //show usable classes routine by Koad//
        bool bUseableClasses = false; 
        strcat(out, "<br>" ); 
        for (int j=Warrior; j<=Berserker; j++) {  // Ziggy - output will word wrap properly now
			if (((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j)>0 && ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j)<=MAX_PC_LEVEL) {
                if (bUseableClasses) strcat (out, ", ");

                sprintf(temp,"%s(%d)", GetClassDesc(j), ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j));
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
            AppendCXStr(&This->ItemInfo,&out[0]);  
        }
    }

    VOID ItemSetSpell_Detour(int SpellID,bool HasSpellDescr)
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
            SetSpell_Trampoline(SpellID,HasSpellDescr);
            strcat(out,"<BR><c \"#00FFFF\">");
        } else {
            char * cColour = "FF0000", * cName = "Blub";

            switch (eEffectType)
            {
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
            case Focus2:
                cColour = "9F9F00";
                cName = "Focus";
                break;
            case Scroll:
                cColour = "9F9F9F";
                cName = "Scroll";
                break;
            }

            sprintf (temp, "<BR><c \"#%s\">Spell Info for %s effect: %s<br>", cColour, cName, pSpell->Name);
			strcat(out,temp);

            if(This->ItemInfo && GetCXStr(This->ItemInfo, temp))
            {
                if(strstr(temp, out))
                {
                    return;
                }
            }
        }

        sprintf(temp, "ID: %04d&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", pSpell->ID );
        strcat(out,temp);

        DWORD Tics=GetSpellDuration(pSpell,(PSPAWNINFO)pLocalPlayer);
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

        if (pSpell->TargetType != 0x06 && pSpell->TargetType != 0x0e && pSpell->TargetType != 0x03 && pSpell->TargetType != 0x28 && pSpell->TargetType != 0x29) {
            if (pSpell->SpellType == 0) {   // Ziggy: Only show resist type for detrimental spells
                switch(pSpell->Resist)
                {
                case 9: strcat(out, "Resist: Corruption" ); break;
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

		if (pSpell->HateGenerated) {
            sprintf(temp, "Hate Generated: %d<br>", pSpell->HateGenerated);
            strcat(out,temp);
		}

        strcat(out, "<br>" );
        ShowSpellSlotInfo(pSpell,&out[strlen(out)]);

        //show usable classes routine by Koad//
        bool bUseableClasses = false; 
        strcat(out, "<br>" ); 
        for (int j=Warrior; j<=Berserker; j++) {  // Ziggy - output will word wrap properly now
			if (((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j)>0 && ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j)<=MAX_PC_LEVEL) {
                if (bUseableClasses) strcat (out, ", ");

                sprintf(temp,"%s(%d)", GetClassDesc(j), ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j));
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

    VOID UpdateStrings_Trampoline();
    VOID UpdateStrings_Detour()
    {
		PEQITEMWINDOW This=(PEQITEMWINDOW)this;
		int index = This->ItemWndIndex;
        PCONTENTS item=(PCONTENTS)This->pItem;
        volatile PITEMINFO Item=GetItemFromContents(item);
        CHAR out[MAX_STRING] = {0};
        CHAR temp[MAX_STRING] = {0};
        PCHAR lore = NULL;

        UpdateStrings_Trampoline();
		lockit lockid(hDisplayItemLock);
		//add the strings to our map
		try {
			if(This->ItemInformationText) {
				GetCXStr(This->ItemInformationText, temp);
				CXStr szin = temp;
				CXStr szout;
				if (CXStr *ret = STMLToText(&szout, szin, true)) {
					GetCXStr(szout.Ptr, temp);
					contentsitemstrings[index].ItemInformationText = temp;
				}
			} else {
				contentsitemstrings[index].ItemInformationText.clear();
			}
			if (This->ItemInfo) {
				GetCXStr(This->ItemInfo,temp);
				CXStr szin = temp;
				CXStr szout;
				if(CXStr *ret = STMLToText(&szout, szin,true)) {
					GetCXStr(szout.Ptr,temp);
					contentsitemstrings[index].ItemInfo = temp;
				}
			} else {
				contentsitemstrings[index].ItemInfo.clear();
			}
			if (This->ItemMadeByText) {
				GetCXStr(This->ItemMadeByText, temp);
				CXStr szin = temp;
				CXStr szout;
				if (CXStr *ret = STMLToText(&szout, szin, true)) {
					GetCXStr(szout.Ptr, temp);
					contentsitemstrings[index].ItemMadeByText = temp;
				}
			} else {
				contentsitemstrings[index].ItemMadeByText.clear();
			}
			if (This->ItemAdvancedLoreText) {
				GetCXStr(This->ItemAdvancedLoreText, temp);
				CXStr szin = temp;
				CXStr szout;
				if (CXStr *ret = STMLToText(&szout, szin, true)) {
					GetCXStr(szout.Ptr, temp);
					contentsitemstrings[index].ItemAdvancedLoreText = temp;
				}
			} else {
				contentsitemstrings[index].ItemAdvancedLoreText.clear();
			}
			if (This->WindowTitle) {
				GetCXStr(This->WindowTitle, temp);
				CXStr szin = temp;
				CXStr szout;
				if (CXStr *ret = STMLToText(&szout, szin, true)) {
					GetCXStr(szout.Ptr, temp);
					contentsitemstrings[index].WindowTitle = temp;
				}
			} else {
				contentsitemstrings[index].WindowTitle.clear();
			}
		} catch (...) {
			//handle stuff
		}
        // keep a global copy of the last item displayed...
        memcpy(&g_Contents[index], item, sizeof(CONTENTS));
        memcpy(&g_Item, Item, sizeof(ITEMINFO));
		g_LastIndex = index;

        strcpy(out,"<BR><c \"#00FFFF\">");
        if ( Item->ItemNumber > 0 ) { 
            sprintf(temp,"Item ID: %d<br>", Item->ItemNumber); 
            strcat(out, temp); 
        }

#ifndef ISXEQ
		// Dewey 2461 - user defined score 12-22-2012
		AddGearScores((PCONTENTS)This->pItem,Item,out,"<BR>");
#endif
        if ( ((EQ_Item*)item)->IsStackable() ) {
            if ( Item->StackSize > 0 ) {
                sprintf(temp,"Stackable Count: %d<br>", Item->StackSize);
                strcat(out, temp);
            }
        } 
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
        if (Item->Clicky.TimerID!=0) {
            int Secs = GetItemTimer(item);
            if (!Secs) {
                sprintf(temp,"Item Timer: <c \"#20FF20\">Ready</c><br>");
            } else {
                int Mins=(Secs/60)%60;
                int Hrs=(Secs/3600);
                Secs=Secs%60;
                if (Hrs)
                    sprintf(temp,"Item Timer: %d:%02d:%02d<br>",Hrs,Mins,Secs);
                else
                    sprintf(temp,"Item Timer: %d:%02d<br>",Mins,Secs);
            }
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

                    if (GetCharInfo2()->Level > 27 && This->ItemInfo) { //bonus is 0 for anything below 28
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
                sprintf(temp, "Procs at level 1 (Proc rate modifier: %d)<BR>", Item->Proc.ProcRate); 
            else 
                sprintf(temp,"%sProcs at level %d%s (Proc rate modifier: %d)<BR>", (Item->Proc.RequiredLevel > GetCharInfo2()->Level ? "<c \"#FF4040\">" : ""), Item->Proc.RequiredLevel, (Item->Proc.RequiredLevel > GetCharInfo2()->Level ? "</C>" : ""), Item->Proc.ProcRate); 
            strcat(out,temp); 
        } 
        /* No longer needed? 
        else if (Item->SpellId==998) { // 998 = haste 
        sprintf(temp,"%d%% Haste<BR>",Item->Level+1); 
        strcat(out,temp); 
        } 
        */ 

        // Just in case...
        if (This->ItemInfo && (!strstr(This->ItemInfo->Text,"(Combat)")) && Item->Proc.ProcRate > 0 )
        {
            sprintf(temp, "Proc rate Modifier: %d<BR>", Item->Proc.ProcRate );
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


        sprintf(temp,"%07d",Item->ItemNumber); 
#ifndef ISXEQ
        CHAR temp2[MAX_STRING] = {0};
        GetPrivateProfileString("Notes",temp,"",temp2,MAX_STRING,INIFileName); 
        if (strlen(temp2)>0) 
        { 
            sprintf(temp,"Note: %s<br>",temp2); 
            strcat(out, temp); 
        }  
#endif

        if (out[0]!=17) {
            strcat(out,"</c>");
            ((CStmlWnd*)This->DisplayWnd)->AppendSTML(&out[0]);
        }

        // Ziggy - Items showing their spell details:
        bNoSpellTramp=true;
        if (Item->Clicky.SpellID > 0 && Item->Clicky.SpellID != -1) {
            eEffectType = Clicky;
            ItemSetSpell_Detour(Item->Clicky.SpellID, false);
        }

        if (Item->Proc.SpellID > 0 && Item->Proc.SpellID != -1) {
            eEffectType = Proc;
            ItemSetSpell_Detour(Item->Proc.SpellID, false);
        }

        if (Item->Worn.SpellID > 0 && Item->Worn.SpellID != -1) {
            eEffectType = Worn;
            ItemSetSpell_Detour(Item->Worn.SpellID, false);
        }

        if (Item->Focus.SpellID > 0 && Item->Focus.SpellID != -1) {
            eEffectType = Focus;
            ItemSetSpell_Detour(Item->Focus.SpellID, false);
        }

        if (Item->Scroll.SpellID > 0 && Item->Scroll.SpellID != -1) {
            eEffectType = Scroll;
            ItemSetSpell_Detour(Item->Scroll.SpellID, false);
        }
		if (Item->Focus2.SpellID > 0 && Item->Focus2.SpellID != -1) {
            eEffectType = Focus2;
            ItemSetSpell_Detour(Item->Focus2.SpellID, false);
        }
        bNoSpellTramp=false;
        eEffectType = None;
    }
};

ItemDisplayHook::SEffectType ItemDisplayHook::eEffectType = None;
bool ItemDisplayHook::bNoSpellTramp = false;

DETOUR_TRAMPOLINE_EMPTY(VOID ItemDisplayHook::SetSpell_Trampoline(int SpellID,bool HasSpellDescr));
DETOUR_TRAMPOLINE_EMPTY(VOID ItemDisplayHook::UpdateStrings_Trampoline());

#ifndef ISXEQ
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
    if (strlen(Comment)==0 || !_stricmp(Arg,"del")) 
    { 
        sprintf(szTemp,"%07d",itemno); 
        WritePrivateProfileString("Notes",szTemp,"",INIFileName); 
        return; 
    } 

    if (!_stricmp(Arg,"add")) 
    { 
        sprintf(szTemp,"%07d",itemno); 
        WritePrivateProfileString("Notes",szTemp,Comment,INIFileName); 
        return; 
    } 
} 

void Ireset(PSPAWNINFO pChar, PCHAR szLine) 
{
    g_Item.ItemNumber = 0;
}

char  ReportChannel[MAX_STRING];
char  ReportBestStr[MAX_STRING];
char  ReportBestSlot[MAX_STRING];
char  ReportBestName[MAX_STRING];
int   ClickGroup = 0;
int   ClickGuild = 0;
int   ClickRaid = 0;
int   ClickAny = 0;
int   IniLoaded = 0;
int   BestSlot = 0;
float BestScore = 0;
float CurrScore = 0;
float CurrSlot = 0;

typedef struct
{
	char *Name;
	float Weight;
	float Val;
	float Best;
} trATR;

int      AttribMax = 26;
trATR    AttribList[] = {
	/* 00 */ { "AC",0,0},
	/* 01 */ { "HP",0,0},
	/* 02 */ { "HPReg",0,0},
	/* 03 */ { "Mana",0,0},
	/* 04 */ { "ManaReg",0,0},
	/* 05 */ { "hSTR",0,0},
	/* 06 */ { "hSTA",0,0},
	/* 07 */ { "hAGI",0,0},
	/* 08 */ { "hDEX",0,0},
	/* 09 */ { "hINT",0,0},
	/* 10 */ { "hWIS",0,0},
	/* 11 */ { "hCHR",0,0},
	/* 12 */ { "Heal",0,0},
	/* 13 */ { "Nuke",0,0},
	/* 14 */ { "Clrv",0,0},
	/* 15 */ { "Attack",0,0},
	/* 16 */ { "Accuracy",0,0},
	/* 17 */ { "CE",0,0},
	/* 18 */ { "StrikeThrough",0,0},
	/* 19 */ { "Avoidance",0,0},
	/* 20 */ { "Shielding",0,0},
	/* 21 */ { "DoTShielding",0,0},
	/* 22 */ { "SpellShield",0,0},
	/* 23 */ { "Stun",0,0},
	/* 24 */ { "DS",0,0},
	/* 25 */ { "Haste",0,0},
	/* 26 */ { "Ratio",0,0},
 };

typedef struct
{
	DWORD SlotMask;
	char *SlotName;
} tSLOTINFO;

tSLOTINFO SlotInfo[] = {
	/* 00 | 0x000001 */	{ 1			,"Charm" },
	/* 01 | 0x000002 */	{ 2         ,"Left Ear" },
	/* 02 | 0x000004 */	{ 4			,"Head" },
	/* 03 | 0x000008 */	{ 8			,"Face" },
	/* 04 | 0x000010 */	{ 16		,"Right Ear" },
	/* 05 | 0x000020 */	{ 32		,"Neck" },
	/* 06 | 0x000040 */	{ 64		,"Shoulders" },
	/* 07 | 0x000080 */	{ 128		,"Arms" },
	/* 08 | 0x000100 */	{ 256		,"Back" },
	/* 09 | 0x000200 */	{ 512		,"Left Wrist" },
	/* 10 | 0x000401 */	{ 1024		,"Right Wrist" },
	/* 11 | 0x000800 */	{ 2048		,"Range" },
	/* 12 | 0x001000 */	{ 4096		,"Hands" },
	/* 13 | 0x002000 */	{ 8192		,"Primary" },
	/* 14 | 0x004000 */	{ 16384		,"Secondary" },
	/* 15 | 0x008000 */	{ 32768		,"Left Finger" },
	/* 16 | 0x010000 */	{ 65536		,"Right Finger" },
	/* 17 | 0x020000 */	{ 131072	,"Chest" },
	/* 18 | 0x040000 */	{ 262144	,"Legs" },
	/* 19 | 0x080000 */	{ 524288	,"Feet" },
	/* 20 | 0x100000 */	{ 1048576	,"Waist" },
	/* 21 | 0x200000 */	{ 2097152	,"Power Source" },
	/* 22 | 0x400000 */	{ 4194304	,"Ammo" },
	/* 23 | 0x800000 */	{ 0			,NULL } };

// *************************************************************************** 
//	This section is methods to interact with the AttributeList 
// *************************************************************************** 

void LoadAttribListWeights(char *Section)
{
	char  szVal[MAX_STRING];

	int i;
	for (i=0; i<=AttribMax; i++)
	{
		GetPrivateProfileString(Section, AttribList[i].Name	,"0",szVal	,256,INIFileName);	
		AttribList[i].Weight = (float)atof(szVal);
	}
}

void SaveAttribListWeights(char *Section)
{
	char  szVal[MAX_STRING];

	int i;
	for (i=0; i<=AttribMax; i++)
	{
		sprintf(szVal,"%0.2f", AttribList[i].Weight);
		WritePrivateProfileString(Section,AttribList[i].Name,szVal,INIFileName);
	}
}

int  SetAttribListWeight(char *Key, char *Val)
{
	int i;
	for (i=0; i<=AttribMax; i++)
	{
		if (stricmp(AttribList[i].Name,Key)==0) 
		{
			WriteChatf("MQ2GearScore::Setting %s to %s",AttribList[i].Name,Val); 
			AttribList[i].Weight = (float)atof(Val);
			return 1;
		}
	}
	return 0;
}

void ClearAttribListWeights(void)
{
	int i;
	for (i=0; i<=AttribMax; i++)
		AttribList[i].Weight = 0;
}

void ClearAttribListScores(void)
{
	int i;
	BestSlot = 0;
	BestScore = 0;
	for (i=0; i<=AttribMax; i++)
	{
		AttribList[i].Val = 0;
		AttribList[i].Best = 0;
	}
}

void ClearAttribListVal(void)
{
	int i;
	for (i=0; i<=AttribMax; i++)
	{
		AttribList[i].Val = 0;
	}
}

#define cvtfloat(x) x / 1.0f
float CalcRatio(ITEMINFO *pItem)
{
	float dam = cvtfloat(pItem->Damage);
	float del = cvtfloat(pItem->Delay);
	if (!del) del = 1;
	return ((float) dam/del);
}

void LoadAttribListVal(ITEMINFO *pItem)
{
	AttribList[ 0].Val = cvtfloat(pItem->AC);
	AttribList[ 1].Val = cvtfloat(pItem->HP);
	AttribList[ 2].Val = cvtfloat(pItem->HPRegen);
	AttribList[ 3].Val = cvtfloat(pItem->Mana);
	AttribList[ 4].Val = cvtfloat(pItem->ManaRegen);
	AttribList[ 5].Val = cvtfloat(pItem->HeroicSTR);
	AttribList[ 6].Val = cvtfloat(pItem->HeroicSTA);
	AttribList[ 7].Val = cvtfloat(pItem->HeroicAGI);
	AttribList[ 8].Val = cvtfloat(pItem->HeroicDEX);
	AttribList[ 9].Val = cvtfloat(pItem->HeroicINT);
	AttribList[10].Val = cvtfloat(pItem->HeroicWIS);
	AttribList[11].Val = cvtfloat(pItem->HeroicCHA);
	AttribList[12].Val = cvtfloat(pItem->HealAmount);
	AttribList[13].Val = cvtfloat(pItem->SpellDamage);
	AttribList[14].Val = cvtfloat(pItem->Clairvoyance);
	AttribList[15].Val = cvtfloat(pItem->Attack);
	AttribList[16].Val = cvtfloat(pItem->Accuracy);
	AttribList[17].Val = cvtfloat(pItem->CombatEffects);
	AttribList[18].Val = cvtfloat(pItem->StrikeThrough);
	AttribList[19].Val = cvtfloat(pItem->Avoidance);
	AttribList[20].Val = cvtfloat(pItem->Shielding);
	AttribList[21].Val = cvtfloat(pItem->DoTShielding);
	AttribList[22].Val = cvtfloat(pItem->SpellShield);
	AttribList[23].Val = cvtfloat(pItem->StunResist);
	AttribList[24].Val = cvtfloat(pItem->DamageShieldMitigation);
	AttribList[25].Val = cvtfloat(pItem->Haste);
	AttribList[26].Val =		CalcRatio(pItem);
}
#undef cvtfloat

float CalcItemGearScore(ITEMINFO *pItem)
{
	int   i;
	float score = 0;
	LoadAttribListVal(pItem);
	for (i=0; i<=AttribMax; i++)
	{
		score = score + AttribList[i].Val * AttribList[i].Weight;
	}
	return score;
}

void  CheckForBest(float ItemScore,int ItemSlot) 
{
	//WriteChatf("MQ2ItemDisplay::CheckForBest(ItemScore=%6.0f, ItemSlot=%d",ItemScore,ItemSlot);
	if (ItemScore < BestScore)
	{
		int i;
		for (i=0; i<=AttribMax; i++)
		{
			AttribList[i].Best = AttribList[i].Val;
		}
		BestScore = ItemScore;
		BestSlot = ItemSlot;
		//WriteChatf("MQ2ItemDisplay::CheckForBest()::Marked this as best in slot");
	}
}

// *************************************************************************** 
//	This section is to set, save, and report global profile variables. 
// *************************************************************************** 

void ClearProfile(int Echo)
{
	sprintf(ReportChannel,"None");
	ClickGroup = 0;
	ClickGuild = 0;
	ClickRaid = 0;
	ClickAny = 0;
	ClearAttribListWeights();
	if (Echo) WriteChatf("MQ2ItemDisplay::plugin variables cleared but not saved."); 
}


void ReadProfile(char *pName,int Echo)
{
	char szVal[MAX_STRING];
	if (Echo) WriteChatf("MQ2ItemDisplay::loading settings for [%s]",pName); 
	GetPrivateProfileString(pName,"Report",		"None"	,ReportChannel	,256,INIFileName);
	GetPrivateProfileString(pName,"ClickGroup",	"0"		,szVal		,256,INIFileName);	ClickGroup	 = atoi(szVal);
	GetPrivateProfileString(pName,"ClickGuild",	"0"		,szVal		,256,INIFileName);	ClickGuild	 = atoi(szVal);
	GetPrivateProfileString(pName,"ClickRaid",	"0"		,szVal		,256,INIFileName);	ClickRaid 	 = atoi(szVal);
	GetPrivateProfileString(pName,"ClickAny",	"0"		,szVal		,256,INIFileName);	ClickAny	 = atoi(szVal);
	LoadAttribListWeights(pName);
	IniLoaded = 1;
}

void WriteProfile(char *pName,int Echo)
{
	char szKey[MAX_STRING];
									WritePrivateProfileString(pName,"Report"	 ,ReportChannel,INIFileName); 
	sprintf(szKey,"%d",ClickGroup);	WritePrivateProfileString(pName,"ClickGroup" ,szKey		,INIFileName); 
	sprintf(szKey,"%d",ClickGuild);	WritePrivateProfileString(pName,"ClickGuild" ,szKey		,INIFileName); 
	sprintf(szKey,"%d",ClickRaid);	WritePrivateProfileString(pName,"ClickRaid"	 ,szKey		,INIFileName); 
	sprintf(szKey,"%d",ClickAny);	WritePrivateProfileString(pName,"ClickAny"	 ,szKey  	,INIFileName); 
	SaveAttribListWeights(pName);

	if (Echo) WriteChatf("MQ2ItemDisplay::saving settings for [%s]",pName); 
}

void EchoProfile(int reporting,int clicking,int weights)
{
	if (reporting)
	{
		WriteChatf("MQ2GearScore::Report to [ %s ]",ReportChannel);
	}
	if (clicking)
	{
		WriteChatf("MQ2GearScore::ClickGroup = %d",ClickGroup);
		WriteChatf("MQ2GearScore::ClickGuild = %d",ClickGuild);
		WriteChatf("MQ2GearScore::ClickRaid  = %d",ClickRaid);
		WriteChatf("MQ2GearScore::ClickAny   = %d",ClickAny);
	}
	if (weights)
	{
		for (int i=AttribMax; i>=0; i--)
		{
			WriteChatf("MQ2ItemDisplay::%s = %0.0f",AttribList[i].Name,AttribList[i].Weight);
		}
	}
}

void EchoHelp(int Echo)
{
	WriteChatf("MQ2ItemDisplay::Commands :");
	WriteChatf("  /iScore clear -- resets all variables");
	WriteChatf("  /iScore click [Group|Guild|Raid|Any] -- auto click links for these sources");
	WriteChatf("  /iScore cursor -- evaluate item on cursor");
	WriteChatf("  /iScore report [Channel] -- send upgrade using this command ex: /bc ");
	WriteChatf("  /iScore load -- load settings from disk");
	WriteChatf("  /iScore save -- save current settings to disk");
	WriteChatf("  /iScore [attribute] [weight] -- sets an item weight");
}


void EchoCommands(int Echo)
{
	EchoHelp(TRUE);
	EchoProfile(FALSE,TRUE,FALSE);
	EchoProfile(TRUE,FALSE,TRUE);
}

// *************************************************************************** 
//	This section is for each of the user commands. 
// *************************************************************************** 

void DoScoreForCursor(void);

void SetReportChannel(char *pName, char *Val)
{
	strcpy(ReportChannel,Val);
	EchoProfile(TRUE,FALSE,FALSE);
}

void SetClickMode(char *pName, char *Val)
{
	if (stricmp(Val,"Group")==0) ClickGroup=!ClickGroup;
	if (stricmp(Val,"Guild")==0) ClickGuild=!ClickGuild;
	if (stricmp(Val,"Raid" )==0) ClickRaid=!ClickRaid;
	if (stricmp(Val,"Any"  )==0) ClickAny=!ClickAny;
	EchoProfile(FALSE,TRUE,FALSE);
}

// *************************************************************************** 
//	This is the actual entry point for user commands. Parse and divy up the work.
// *************************************************************************** 

void DoGearScoreUserCommand(PSPAWNINFO pChar, PCHAR szLine) 
{
    CHAR Key[MAX_STRING] = {0}; 
    CHAR Val[MAX_STRING] = {0}; 
	char *pName = GetCharInfo()->Name;
	if (!pName) return;
    GetArg(Key,szLine,1); 
    GetArg(Val,szLine,2); 

	if (stricmp(Key,"save"		)==0)	{	WriteProfile(pName,TRUE);	return; }
	if (stricmp(Key,"load"		)==0)	{	ReadProfile(pName,TRUE);	return; }
	if (stricmp(Key,"report"	)==0)   {	SetReportChannel(pName,Val);return;	}
	if (stricmp(Key,"click"		)==0)	{	SetClickMode(pName,Val);	return;	}
	if (stricmp(Key,"cursor"	)==0)   {	DoScoreForCursor();			return;	}
	if (stricmp(Key,"clear"		)==0)	{	ClearProfile(TRUE);			return;	}
	if (stricmp(Key,"help"		)==0)	{	EchoHelp(TRUE);				return;	}
	if (Key[0] == 0					)	{	EchoCommands(TRUE);			return;	}
	SetAttribListWeight(Key,Val);
}


void DoScoreForCursor(void)
{
	PITEMINFO pCursorItem = NULL;
	PCONTENTS pCursorContents = GetCharInfo2()->pInventoryArray->Inventory.Cursor;
	DWORD Class = GetCharInfo2()->Class;
	if (pCursorContents) pCursorItem = GetItemFromContents(pCursorContents);
	if (pCursorItem) 
	{
		char Temp[MAX_STRING];
		AddGearScores(pCursorContents,pCursorItem,Temp,"\n");
		WriteChatf("MQ2ItemDisplay::Cursor item %s",pCursorItem->Name);
		WriteChatf(Temp);
	}
}


class MQ2GearScoreType *pGearScoreType=0; 

class MQ2GearScoreType : public MQ2Type 
{ 
    public: 
        enum GearScoreMembers {
			Upgrade=1,
			UpgradeName=2,
			UpgradeSlot=3,
        }; 

        MQ2GearScoreType():MQ2Type("GearScore") { 
			TypeMember(Upgrade);
			TypeMember(UpgradeName);
			TypeMember(UpgradeSlot);
        } 

        ~MQ2GearScoreType() {}

        bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest) { 
            PMQ2TYPEMEMBER pMember=MQ2GearScoreType::FindMember(Member); 
            if (!pMember) 
                return false; 
			char  *pName = GetCharInfo()->Name;
			if (!pName) 
				return false;
            switch((GearScoreMembers)pMember->ID) { 
				case Upgrade:
					Dest.Type=pStringType;
					Dest.Ptr=ReportBestStr;
					return true;
	            case UpgradeName:
					Dest.Type=pStringType;
					Dest.Ptr=ReportBestName;
					return true;
				case UpgradeSlot:
					Dest.Type=pStringType;
					Dest.Ptr=ReportBestSlot;
					return true;
			} 
            return false; 
        } 

        bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)  {
			strcpy(Destination,"TRUE");
			return true;
        } 

        bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source) { 
            return false; 
        } 

        bool FromString(MQ2VARPTR &VarPtr, PCHAR Source) { 
            return false; 
        } 
}; 

BOOL dataGearScore(PCHAR szName, MQ2TYPEVAR &Dest) 
{ 
    Dest.DWord=1; 
    Dest.Type=pGearScoreType; 
    return true; 
} 

void AddGearScore_CheckAugSlot(ITEMINFO *pItem,float score,int SlotNum,char *SlotName,PCONTENTS pInvContent,ITEMINFO *pInvItem,DWORD AugType,DWORD AugSlot,char *out,char *br)
{
	if (!AugType) return;							// This worn item does not have an aug slot for [n]
	DWORD mask = (1<<(AugType-1));
	if ((mask & pItem->AugType) == 0) return ;		// Calculate a bitmask and compare to the aug we have, does it fit?

	char  temp[MAX_STRING];
	ITEMINFO *pAug = NULL;
	if (pInvContent && pInvContent->pContentsArray && pInvContent->pContentsArray->Contents[AugSlot])
		pAug = GetItemFromContents(pInvContent->pContentsArray->Contents[AugSlot]);

	if (!pAug) {
		ClearAttribListVal();
		CheckForBest(0,SlotNum);
		sprintf(temp,"%s = empty : UPGRADE%s",SlotName,br);
		strcat(out,temp);
		return;
	}
	if (pItem->ItemNumber == pInvItem->ItemNumber)
		return;

	float s2 = CalcItemGearScore(pAug);
	CheckForBest(s2,SlotNum);

	sprintf(temp,"%s = %s : %6.0f %s %s",SlotName,pAug->Name,s2,(s2>=score?"Keep ":"UPGRADE"),br);
	strcat(out,temp);
}

void AddGearScores_CheckAugs(PCONTENTS pSlot,ITEMINFO *pItem,char *out,char *br)
{
	float score = CalcItemGearScore(pItem);
	if (!score) return;

	char temp[MAX_STRING];

	sprintf(temp,"Base Aug Score : %6.0f%s",score,br);
	strcat(out,temp);

	char *name;
	int i;
	DWORD mask;
	PITEMINFO pInvItem;
    PCONTENTS pInvContent;
	float bestVal = score;

	// Loop over all the worn items
	for (i=0; i<BAG_SLOT_START-1; i++)
	{
		mask = SlotInfo[i].SlotMask;
		name = SlotInfo[i].SlotName;
		pInvItem = NULL;
		pInvContent = GetCharInfo2()->pInventoryArray->InventoryArray[i];
		if (pInvContent) pInvItem = GetItemFromContents(pInvContent);
		if (pInvItem && (pItem->EquipSlots & mask) == mask)
		{
			AddGearScore_CheckAugSlot(pItem,score,i,name,pInvContent,pInvItem,pInvItem->AugSlot1,0,out,br);
			AddGearScore_CheckAugSlot(pItem,score,i,name,pInvContent,pInvItem,pInvItem->AugSlot2,1,out,br);
			AddGearScore_CheckAugSlot(pItem,score,i,name,pInvContent,pInvItem,pInvItem->AugSlot3,2,out,br);
			AddGearScore_CheckAugSlot(pItem,score,i,name,pInvContent,pInvItem,pInvItem->AugSlot4,3,out,br);
			AddGearScore_CheckAugSlot(pItem,score,i,name,pInvContent,pInvItem,pInvItem->AugSlot5,4,out,br);
			AddGearScore_CheckAugSlot(pItem,score,i,name,pInvContent,pInvItem,pInvItem->AugSlot6,5,out,br);
		}
	}
}

//DoIHave() - pinkfloydx33 - determine if you already have an item
int DoIHave(PITEMINFO Item)
{
   DWORD ID = Item->ItemNumber;
   DWORD AugType = Item->AugType;

   int nHowMany = 0;
   DWORD nAug = 0;
	unsigned long nPack;
	unsigned long iSlot;

   //return nHowMany;

	// Normal Inventory worn slots
   for (iSlot=0 ; iSlot < NUM_INV_SLOTS ; iSlot++)
   {
      if (PCONTENTS pItem=GetCharInfo2()->pInventoryArray->InventoryArray[iSlot])
      {
         if (GetItemFromContents(pItem)->ItemNumber==ID)
         {
            if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
               (((EQ_Item*)pItem)->IsStackable() != 1)) 
            {
               nHowMany++;
            }
            else 
            {
               nHowMany+=pItem->StackCount;
            }
         }
         else // for augs
         {
            if (pItem->pContentsArray && pItem->NumOfSlots2)
            for(nAug = 0; nAug < pItem->NumOfSlots2; nAug++)
            {
               if(pItem->pContentsArray->Contents[nAug] && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Type == ITEMTYPE_NORMAL && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->AugType &&
                  GetItemFromContents(pItem->pContentsArray->Contents[nAug])->ItemNumber==ID)
                  nHowMany++;
            }
         }
      }
   }

   // Bags
   for (nPack=0 ; nPack < 10 ; nPack++)
   {
      if (PCONTENTS pPack=GetCharInfo2()->pInventoryArray->Inventory.Pack[nPack])
      {
         if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && pPack->pContentsArray)
         {
            for (unsigned long nItem=0 ; nItem < GetItemFromContents(pPack)->Slots ; nItem++)
            {
               if (PCONTENTS pItem=pPack->pContentsArray->Contents[nItem])
               {
                  if (GetItemFromContents(pItem)->ItemNumber==ID)
                  {
                     if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
                        (((EQ_Item*)pItem)->IsStackable() != 1)) 
                     {
                        nHowMany++;
                     }
                     else
                     {
                        nHowMany+=pItem->StackCount;
                     }
                  }
                  else // for augs
                  {
                     if (pItem->pContentsArray && pItem->NumOfSlots2)
                     for(nAug = 0; nAug < pItem->NumOfSlots2; nAug++)
                     {
                        if(pItem->pContentsArray->Contents[nAug] && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->Type == ITEMTYPE_NORMAL && GetItemFromContents(pItem->pContentsArray->Contents[nAug])->AugType &&
                           GetItemFromContents(pItem->pContentsArray->Contents[nAug])->ItemNumber==ID)
                           nHowMany++;
                     }
                  }
               }
            }
         }
      }
   }



   // Bank slots, not including shared
   for (nPack=0 ; nPack < NUM_BANK_SLOTS ; nPack++)
   {
      PCHARINFO pCharInfo=GetCharInfo();
      PCONTENTS pPack=NULL;
      if (pCharInfo && pCharInfo->pBankArray)
		  pPack=pCharInfo->pBankArray->Bank[nPack];
      if (pPack)
      {
         if (GetItemFromContents(pPack)->ItemNumber==ID)
         {
            if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL) ||
               (((EQ_Item*)pPack)->IsStackable() != 1))
               nHowMany++;
            else
               nHowMany+=pPack->StackCount;
         }
         if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && pPack->pContentsArray)
         {
            for (unsigned long nItem=0 ; nItem < GetItemFromContents(pPack)->Slots ; nItem++)
            {
               if (PCONTENTS pItem=pPack->pContentsArray->Contents[nItem])
               {
                  if (GetItemFromContents(pItem)->ItemNumber==ID)
                  {
                     if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
                        (((EQ_Item*)pItem)->IsStackable() != 1))
                        nHowMany++;
                     else
                        nHowMany+=pItem->StackCount;
                  }
               }
            }
         }
      }
   }

    for (nPack=0 ; nPack < NUM_SHAREDBANK_SLOTS ; nPack++)
    {
        PCHARINFO pCharInfo=GetCharInfo();
		PCONTENTS pPack=NULL;
		if (pCharInfo && pCharInfo->pSharedBankArray) pPack=pCharInfo->pSharedBankArray->SharedBank[nPack];
		if (pPack)
        {
	        if (GetItemFromContents(pPack)->ItemNumber==ID)
            {
                if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL) ||
                    (((EQ_Item*)pPack)->IsStackable() != 1))
                    nHowMany++;
                else
                    nHowMany+=pPack->StackCount;
            }
            if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && pPack->pContentsArray)
            {
                for (unsigned long nItem=0 ; nItem < GetItemFromContents(pPack)->Slots ; nItem++)
                {
                    if (PCONTENTS pItem=pPack->pContentsArray->Contents[nItem])
                    {
		                if (GetItemFromContents(pItem)->ItemNumber==ID)
                        {
                            if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
                                (((EQ_Item*)pItem)->IsStackable() != 1))
                                nHowMany++;
                            else
                                nHowMany+=pItem->StackCount;
                        }
                    }
                }
            }
        }
    }

   return nHowMany;
}

void FormatBestStr(ITEMINFO *pItem)
{
	ReportBestStr[0] = 0;
	ReportBestSlot[0] = 0;
	ReportBestName[0] = 0;
	if (BestScore < CurrScore && BestSlot>=0 && BestSlot<=23) // We found an item to replace
	{
		char  szVerb[MAX_STRING];
		char *pSlotName = SlotInfo[ BestSlot ].SlotName;
		float v;
		if (BestScore>0) 
			v = 100.0f * (CurrScore / BestScore) - 100.0f;
		else
			v = 100.0f;
		if (CurrSlot<BAG_SLOT_START) return;
			//sprintf(szVerb,"MOVE [ %s ] To ",pItem->Name);
		if (CurrSlot<65500)
			sprintf(szVerb,"WEAR [ %s ] As ",pItem->Name);
		else
			sprintf(szVerb,"LOOT [ %s ] For ",pItem->Name);

		if (pItem->Lore && DoIHave(pItem)) 
			sprintf(szVerb,"WEAR [ %s ] As ",pItem->Name);
		
		sprintf(ReportBestStr,"%s %s = %+6.1f%%",szVerb,pSlotName,v);

		strcpy(ReportBestSlot,pSlotName);
		strcpy(ReportBestName,pItem->Name);

		CalcItemGearScore(pItem);

		int i;
		char szTmp[MAX_STRING];
		szTmp[0] = 0;
		strcat(ReportBestStr," =");
		for (i=0; i<=AttribMax; i++)
		{
			if (AttribList[i].Weight!=0 && (AttribList[i].Val != AttribList[i].Best))
			{
				sprintf(szTmp," %s %+0.0f",AttribList[i].Name, AttribList[i].Val-AttribList[i].Best);
				strcat(ReportBestStr,szTmp);
			}
		}		
	}
	//WriteChatf("MQ2ItemDisplay::%s",ReportBestStr);
}

void AddGearScores_CheckItems(PCONTENTS pSlot,ITEMINFO *pItem,char *out,char *br)
{
	char  temp[MAX_STRING];
	DWORD mask;
	float score;
	int i;

	sprintf(temp,"This Item Score : %6.0f%s",CurrScore,br);
	strcat(out,temp);


	for (i=0; i<BAG_SLOT_START-1; i++)
	{
		mask = SlotInfo[i].SlotMask;
		if ((pItem->EquipSlots & mask) == mask) 
		{
			score = 0;
			ClearAttribListVal();
			PCONTENTS pInvSlot = GetCharInfo2()->pInventoryArray->InventoryArray[i];
			if (pInvSlot)
			{
				PITEMINFO pItemInfo = GetItemFromContents(pInvSlot);
				score = CalcItemGearScore(pItemInfo);
				if (pItemInfo && pItemInfo->ItemNumber != pItem->ItemNumber)
				{
					sprintf(temp,"Worn Item Score : %6.0f (%s%s) %s",score,(score-CurrScore>0?"Keep ":"UPGRADE for "),SlotInfo[i].SlotName,br);
					strcat(out,temp);
				}
			}
			CheckForBest(score,i);
		}
	}
}

int CanIUseThisItem(PCONTENTS pSlot, ITEMINFO *pItem)
{
	if (!GetCharInfo2()->Class) return -1;
	DWORD ClassMask = (1<<(GetCharInfo2()->Class-1));
	if ((ClassMask & pItem->Classes) == 0) return -2;
	return 1;
}



void AddGearScores(PCONTENTS pSlot,ITEMINFO *pItem,char *out,char *br)
{
	static ULONGLONG lastTick = 0;
	ReportBestStr[0] = 0;
	ReportBestSlot[0] = 0;
	ReportBestName[0] = 0;
	if (CanIUseThisItem(pSlot,pItem)<1) return ;

	ClearAttribListScores();
	CurrScore = CalcItemGearScore(pItem);
	if (CurrScore == 0) return;

	CurrSlot = pSlot->ItemSlot;
	BestScore=CurrScore;
	BestSlot =0;
	if (pItem->ItemType == ITEMITEMTYPE_AUGUMENT)
		AddGearScores_CheckAugs(pSlot,pItem,out,br);
	else
		AddGearScores_CheckItems(pSlot,pItem,out,br);

	FormatBestStr(pItem);
	if (BestScore<CurrScore && ReportBestStr[0]!=0)
	{
		strcat(out,ReportBestStr);
		strcat(out,br);
	}
	// Trap the 3x call back stuff. 
	if (MQGetTickCount64()-lastTick > 1000 && ReportBestStr[0]!=0 && ReportChannel[0] == '/')
	{
		char szCmd[MAX_STRING];
		lastTick = MQGetTickCount64();
		sprintf(szCmd,"%s %s",ReportChannel,ReportBestStr);
		EzCommand(szCmd);
		//WriteChatf("AddGearScores::Reporting Cmd = %s",szCmd);
	}
}

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
    DebugSpewAlways("Initializing MQ2ItemDisplay");
	hDisplayItemLock = CreateMutex(NULL, FALSE, NULL);
	if(!hDisplayItemLock) {
		MessageBox(NULL,"Could not initialize hDisplayItemLock Mutex","MQ2ItemDisplay not initialized",MB_OK);
		return;
	}
	//lockit lockid(hDisplayItemLock);
    //memset(&g_Contents[g_LastIndex], 0, sizeof(g_Contents));
    //g_Contents[g_LastIndex].Item1 = NULL;
    //g_Contents[g_LastIndex].Item2 = &g_Item;
    //g_Item.ItemNumber = 0;
	pGearScoreType = new MQ2GearScoreType;

    EzDetour(CItemDisplayWnd__SetSpell,&ItemDisplayHook::SetSpell_Detour,&ItemDisplayHook::SetSpell_Trampoline);
    EzDetour(CItemDisplayWnd__UpdateStrings, &ItemDisplayHook::UpdateStrings_Detour, &ItemDisplayHook::UpdateStrings_Trampoline);

    AddCommand("/inote",Comment); 
    AddCommand("/ireset",Ireset); 
    AddCommand("/iScore" ,DoGearScoreUserCommand); 
	AddCommand("/GearScore" ,DoGearScoreUserCommand); 
	pDisplayItemType = new MQ2DisplayItemType;
    AddMQ2Data("DisplayItem", dataLastItem);
	AddMQ2Data("GearScore",dataGearScore);
	if (gGameState == GAMESTATE_INGAME)
		ReadProfile(GetCharInfo()->Name,FALSE);
}

PLUGIN_API VOID SetGameState(DWORD GameState) 
{
	if(GameState==GAMESTATE_INGAME && IniLoaded==0) 
		ReadProfile(GetCharInfo()->Name,FALSE);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down MQ2ItemDisplay");

    // Remove commands, macro parameters, hooks, etc.
    RemoveDetour(CItemDisplayWnd__SetSpell);
    RemoveDetour(CItemDisplayWnd__UpdateStrings);
	delete pGearScoreType;
	pGearScoreType = 0;

    RemoveMQ2Data("DisplayItem");
	RemoveMQ2Data("GearScore");
    RemoveCommand("/ireset"); 
    RemoveCommand("/inote");
	RemoveCommand("/iScore");
	RemoveCommand("/GearScore");
	delete pDisplayItemType;
	if (hDisplayItemLock) {
		ReleaseMutex(hDisplayItemLock);
		CloseHandle(hDisplayItemLock);
		hDisplayItemLock = 0;
	}
}

#define LINK_LEN 55

PLUGIN_API DWORD OnIncomingChat(PCHAR Line, DWORD Color) 
{
	if (ClickGroup || ClickGuild || ClickRaid || ClickAny) 
	{
		char szText[MAX_STRING];
		char szStart[MAX_STRING];
		char szCommand[MAX_STRING];
		char *p;
		int  doLink = 0;

		
		sprintf(szStart,"%c%c",0x12,0x30);
		p = strstr(Line,szStart);
		if (!p) return 0;

		if (ClickAny) doLink = 1;
		if (!doLink && ClickGroup && ( strstr(Line,"tells the group") || strstr(Line,"tell your party"))) doLink = 1;
		if (!doLink && ClickGuild && ( strstr(Line,"tells the guild") || strstr(Line,"to your guild")  )) doLink = 1;
		if (!doLink && ClickRaid  && ( strstr(Line,"tells the raid")  || strstr(Line,"tell your raid") )) doLink = 1;

		if (doLink && p && strlen(p)>LINK_LEN+2)
		{
			memset(szText,0,100);
			strncpy(szText,p+2,LINK_LEN);
			sprintf(szCommand, "/notify ChatWindow CW_ChatOutput link %s", szText);
			DoCommand(((PSPAWNINFO)pLocalPlayer), szCommand);
			
			/* 
			WriteChatf("OnIncomingChat::Cmd = %s",Line);
			int i;
			for (i=0; Line[i]; i++)
				WriteChatf("Line[%d] = 0x%02X = %c ",i,Line[i],Line[i]);
			WriteChatf("OnIncomingChat::Cmd = %s",szCommand);
			for (i=0; szText[i]; i++)
				WriteChatf("szText[%d] = 0x%02X = %c ",i,szText[i],szText[i]);
			*/
		}
	}
    return 0; 
} 
#endif