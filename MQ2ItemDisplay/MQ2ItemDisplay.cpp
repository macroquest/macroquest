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
#include "resource.h"
PreSetup("MQ2ItemDisplay");
#else
#include "../ISXEQClient.h"
#include "ISXEQItemDisplay.h"
#endif
using namespace std;
CHAR ConvertFrom[2048] = { 0 };
CHAR ConvertTo[2048] = { 0 };
bool bDisabledComparetip = false;
bool gCompareTip = false;
bool gLootButton = true;
bool gLucyButton = true;
typedef struct _ButtonInfo
{
	CItemDisplayWnd *ItemDisplayWnd;
	int ID;
} ButtonInfo,*PButtonInfo;

std::map<CButtonWnd *, ButtonInfo>ButtonMap;

// thanks, finally, SOE. we'll leave this here for a while and eventually remove it
#define DISABLE_TOOLTIP_TIMERS

void Comment(PSPAWNINFO pChar, PCHAR szLine);
#ifndef ISXEQ // TODO If we want GearScore under IS, this needs ported to ISXEQItemDisplay 
void DoGearScoreUserCommand(PSPAWNINFO pChar, PCHAR szLine);
template <unsigned int _Size> void AddGearScores(PCONTENTS pSlot,ITEMINFO *pItem, CHAR(&out)[_Size],char *br);
#endif
typedef struct _DISPLAYITEMSTRINGS
{
	std::string ItemInfo;////this item is placable in yards, guild yards blah blah , This item can be used in tradeskills
	std::string WindowTitle;
	std::string ItemAdvancedLoreText;
	std::string ItemMadeByText;
	std::string ItemInformationText;//Item Information: Placing this augment into blah blah, this armor can only be used in blah blah
	bool bCollected;
	bool bCollectedRecieved;
	bool bScribed;
	bool bScribedRecieved;
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
		CollectedRecieved = 5,
		Collected = 6,
		ScribedRecieved = 7,
		Scribed = 8,
		Information = 9,
		DisplayIndex = 10
	};
	enum DisplayItemMethods
	{
		AddLootFilter = 1,
	};
	MQ2DisplayItemType() :MQ2Type("DisplayItem") {
		TypeMember(Info);
		TypeMember(WindowTitle);
		TypeMember(AdvancedLore);
		TypeMember(MadeBy);
		TypeMember(CollectedRecieved);
		TypeMember(Collected);
		TypeMember(ScribedRecieved);
		TypeMember(Scribed);
		TypeMember(Information);
		TypeMember(DisplayIndex);

		TypeMethod(AddLootFilter);
	}
	bool MQ2DisplayItemType::GETMEMBER() {
		int index = VarPtr.DWord;
		PCONTENTS pCont = &g_Contents[index];
		if (!pCont)
			return false;
		PMQ2TYPEMEMBER pMethod = MQ2DisplayItemType::FindMethod(Member);
		if (pMethod) {
			Dest.DWord = 0;
			Dest.Type = pBoolType;
			switch ((DisplayItemMethods)pMethod->ID)
			{
				case AddLootFilter:
				{
#if !defined(ROF2EMU) && !defined(UFEMU)
					if (PITEMINFO pItem = GetItemFromContents(pCont)) {
						DWORD ptr = (DWORD)pLootFiltersManager;
						Sleep(0);
						pLootFiltersManager->AddItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 5);
						WriteChatf("Added %s to AG and Roll LootFilters.",pItem->Name);
						Dest.DWord = 1;
					}
#endif
					break;
				}
			}
			return true;
		}
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
			case Collected:
				Dest.DWord = contentsitemstrings[index].bCollected;
				Dest.Type = pBoolType;
				return true;
			case CollectedRecieved:
				Dest.DWord = contentsitemstrings[index].bCollectedRecieved;
				Dest.Type = pBoolType;
				return true;
			case Scribed:
				Dest.DWord = contentsitemstrings[index].bScribed;
				Dest.Type = pBoolType;
				return true;
			case ScribedRecieved:
				Dest.DWord = contentsitemstrings[index].bScribedRecieved;
				Dest.Type = pBoolType;
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
	lockit lockid(hDisplayItemLock,"dataLastItem");
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

class ICallback
{
public:

    virtual void onURIChanged( Window * ) = 0;
    virtual void onProgressChanged( Window * ) = 0;
    virtual void onStatusChanged( Window * ) = 0;
    virtual bool doValidateURI( Window *, const char * ) = 0;
};
class ItemInfoManager : public ICallback, public CObservable, public IObserver
{
	virtual void ItemInfoManager::onStatusChanged(Window *wnd);
	virtual void ItemInfoManager::onURIChanged(Window *wnd);
	virtual void ItemInfoManager::onProgressChanged(Window *wnd);
	virtual bool ItemInfoManager::doValidateURI(Window *wnd, const char *uri);

public:
	CHtmlWnd* htmlwnd;
	ItemInfoManager()
	{
		htmlwnd = 0;
		Sleep(0);
	};
	~ItemInfoManager()
	{
		ItemInfoManager *im = &this->GetInstance();
		if (im) {
			if (im->htmlwnd)
			{
				im->htmlwnd->SetClientCallbacks(NULL);
			}
		}
		//this->GetInstance().htmlwnd->SetClientCallbacks(NULL);
		//if(this->htmlwnd)
		//	this->htmlwnd->SetClientCallbacks(NULL);
		//GetInstance().htmlwnd->SetClientCallbacks(NULL);
		//this->GetInstance().htmlwnd->RemoveObserver(this);
		Sleep(0);
	};
	static ItemInfoManager& GetInstance();
	void Notify(CObservable *Src, const CNotification* const Notification);
};
ItemInfoManager& ItemInfoManager::GetInstance()
{
	static std::auto_ptr<ItemInfoManager> instance;
	if( instance.get() == NULL )
	{
		instance.reset( new ItemInfoManager );
	}
	return *instance;
}
//work in progress
enum EHTMLNotification
{
	URISelected,
	WindowClosed,
};

void ItemInfoManager::Notify(CObservable *Src, const CNotification* const Notification)
{
	if (!Src || !Notification)
		return;

	switch (Notification->Type)
	{
	case URISelected:
		{
		//stuff? need to fix
		break;
		}
		break;
	}
}
void ItemInfoManager::onStatusChanged(Window *wnd)
{
	if (const wchar_t *status = wnd->getStatus()) {
		//WriteChatf("Status changed: %s", status);
	}
}
void ItemInfoManager::onURIChanged(Window *wnd)
{
	if (const char *uri = wnd->getURI()) {
		//WriteChatf("URI changed: %s", uri);
	}
}

void ItemInfoManager::onProgressChanged(Window *wnd)
{
	bool bIsLoading;
	float pct = wnd->getProgress(bIsLoading);
	//WriteChatf("Progress %0.2f Loading is %s", pct, bIsLoading ? "TRUE":"FALSE");
	//ghettofix for resize, i need to detect this better... another detour? gah... -eqmule
	/*if (!bIsLoading) {
		ItemInfoManager& manager = ItemInfoManager::GetInstance();
		if (manager.htmlwnd) {
			//int width = manager.htmlwnd->Location.right - manager.htmlwnd->Location.left;
			//int height = manager.htmlwnd->Location.bottom - manager.htmlwnd->Location.top;
			//((CXWnd*)manager.htmlwnd)->Resize(width+1, height+1);
			//Beep(1000, 100);
		}
	}
	Sleep(0);*/
}
bool ItemInfoManager::doValidateURI(Window *wnd, const char *uri)
{
	return true;
}

// *************************************************************************** 
// Function:    ItemDisplayHook
// Description: Our Item display hook 
// *************************************************************************** 
PCONTENTS pOldCont = 0;
class CCompareTipWnd;
CCompareTipWnd *pCompareTipWnd=0;
class CCompareTipWnd : public CSidlScreenWnd
{
public:
    CCompareTipWnd(CXStr *screenpiece):CSidlScreenWnd(0,screenpiece,-1,1,0)
    {
        CreateChildrenFromSidl();
        pXWnd()->Show(1,1);
        ReplacevfTable();
        CloseOnESC=0;
    }

    CCompareTipWnd(char *screenpiece):CSidlScreenWnd(0,&CXStr(screenpiece),-1,1,0)
    {
        CreateChildrenFromSidl();
		//pXWnd()->Show(1,1);
        ReplacevfTable();
        CloseOnESC=0;
		SetWndNotification(CCompareTipWnd);
		Display=(CStmlWnd*)GetChildItem("CT_Display");
		this->Faded = true;
		this->ZLayer = 100;
		this->Alpha = 0xfa;
		this->BGColor = 0xFF000000;
		this->BGType = 1;
		#if !defined(ROF2EMU) && !defined(UFEMU)
		this->bClickThrough = 1;
		#endif
    }

    ~CCompareTipWnd()
    {
        RemovevfTable();
    }
    int WndNotification(CXWnd *pWnd, unsigned int Message, void *unknown)
    {    
		return CSidlScreenWnd::WndNotification(pWnd,Message,unknown);
    }

    void ReplacevfTable()
    {
        OldvfTable=((_CSIDLWND*)this)->pvfTable;
        PCSIDLWNDVFTABLE NewvfTable=new CSIDLWNDVFTABLE;
        memcpy(NewvfTable,OldvfTable,sizeof(CSIDLWNDVFTABLE));
        ((_CSIDLWND*)this)->pvfTable=NewvfTable;
    }

    void RemovevfTable()
    {
        PCSIDLWNDVFTABLE NewvfTable=((_CSIDLWND*)this)->pvfTable;
        ((_CSIDLWND*)this)->pvfTable=OldvfTable;
        delete NewvfTable;
    }

    void SetvfTable(DWORD index, DWORD value)
    {
        DWORD* vtable=(DWORD*)((_CSIDLWND*)this)->pvfTable;
        vtable[index]=value;
    }
/*0x218*/   CStmlWnd   *Display;
/*0x22C*/	PCSIDLWNDVFTABLE OldvfTable;
};

int CanIUseThisItem(PITEMINFO pItem)
{
	if (PCHARINFO2 pChar2 = GetCharInfo2()) {
		if (!pChar2->Class)
			return -1;
		DWORD ClassMask = (1 << (pChar2->Class - 1));
		if ((ClassMask & pItem->Classes) == 0)
			return -2;
		return 1;
	}
	return -1;
}
template <unsigned int _Size>char* GetSlots(PITEMINFO pItem,char(&_Buffer)[_Size])
{
	DWORD cmp = pItem->EquipSlots;
	for (int N = 0; N < 32; N++)
	{
		if (cmp&(1 << N))
		{
			strcat_s(_Buffer, _Size, szItemSlot[N]);
			strcat_s(_Buffer, _Size, " ");
		}
	}
	return _Buffer;
}
PCONTENTS GetEquippedSlot(PCONTENTS pCont)
{
	if (PITEMINFO pItem = GetItemFromContents(pCont))
	{
		DWORD cmp = pItem->EquipSlots;
		for (int N = 0; N < 32; N++)
		{
			if (cmp&(1 << N))
			{
				if (PCHARINFO2 pChar2 = GetCharInfo2())
				{
					if (PCONTENTS pInvSlot = pChar2->pInventoryArray->InventoryArray[N])
					{
						return pInvSlot;
					}
				}
			}
		}
	}
	return NULL;
}
class ItemDisplayHook
{
    typedef enum {None = 0, Clicky, Proc, Worn, Focus, Scroll, Focus2, Mount, Illusion, Familiar} SEffectType;

    static bool bNoSpellTramp;
    static SEffectType eEffectType;

public:
	// bool CXStrReplace(...)						- Not used so I removed it - Dewey2461
	// const char * GetRaceThreeLetterCode(...)		- Not used so I removed it - Dewey2461

    int GetDmgBonus (PCXSTR * Str)
    {
		char cTemp[MAX_STRING] = { 0 };
        INT dmgbonuspos;
        INT dmgbonus = 0;
        INT badcharpos;

        GetCXStr(*Str, cTemp, MAX_STRING);

        std::string ItemDisplay;
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

            strcpy_s(ActualDmgBonus,ItemDisplay.c_str());
            dmgbonus = atoi(ActualDmgBonus);
        }

        return dmgbonus;
    }

	#if defined(ROF2EMU) || defined(UFEMU)
	VOID SetSpell_Trampoline(int SpellID, bool bFullInfo);
    VOID SetSpell_Detour(int SpellID,bool bFullInfo)
	#else
	VOID SetSpell_Trampoline(int SpellID);
    VOID SetSpell_Detour(int SpellID)
	#endif
    {
        PEQSPELLINFOWINDOW This=(PEQSPELLINFOWINDOW)this;
        PCHARINFO pCharInfo = NULL;
        if (NULL == (pCharInfo = GetCharInfo())) return;
        PSPELL pSpell = GetSpellByID(SpellID);
        if (pSpell == NULL) {
            return;
        }
        CHAR out[MAX_STRING*2] = {0};
        CHAR temp[MAX_STRING] = {0};
        if (!bNoSpellTramp) {
			#if defined(ROF2EMU) || defined(UFEMU)
			SetSpell_Trampoline(SpellID,bFullInfo);
			#else
			SetSpell_Trampoline(SpellID);
			#endif
            strcat_s(out,"<BR><c \"#00FFFF\">");
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
			case Mount:
				cColour = "00FF00";
				cName = "Mount";
				break;
			case Illusion:
				cColour = "00FF00";
				cName = "Illusion";
				break;
			case Familiar:
				cColour = "00FF00";
				cName = "Familiar";
				break;
			}

            sprintf_s(temp, "<BR><c \"#%s\">Spell Info for %s effect: %s<br>", cColour, cName, pSpell->Name);
			strcat_s(out,temp);

        }

        sprintf_s(temp, "ID: %04d&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", pSpell->ID );
        strcat_s(out,temp);

        DWORD Tics=GetSpellDuration(pSpell,(PSPAWNINFO)pLocalPlayer);
        if (Tics==0xFFFFFFFF)
            strcat_s(out, "Duration: Permanent<br>" );
        else if (Tics==0xFFFFFFFE) 
            strcat_s(out, "Duration: Unknown<br>" );
        else if (Tics==0) {
            // It's "instant", who cares?
            strcat_s(out,"<br>");
        }
        else {
            sprintf_s(temp, "Duration: %1.1f minutes<br>",(float)((Tics*6.0f)/60.0f));
            strcat_s(out, temp);
        }

        sprintf_s(temp, "RecoveryTime: %1.2f&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RecastTime: %1.2f <br>", (float)(pSpell->RecoveryTime/1000.0f), (float)(pSpell->RecastTime/1000.0f) );
        strcat_s(out,temp);

        if (pSpell->Range > 0.0f ) {
            sprintf_s(temp, "Range: %1.0f", pSpell->Range );
            strcat_s(out,temp);
            if ( pSpell->PushBack == 0.0f && pSpell->AERange == 0.0f)
                strcat_s(out, "<br>");
        }

        if (pSpell->PushBack != 0.0f ) {
            if (pSpell->Range > 0.0f ) 
                strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" );
            sprintf_s(temp, "PushBack: %1.1f", pSpell->PushBack );
            strcat_s(out, temp);
            if (pSpell->AERange == 0.0f || pSpell->Range > 0.0f )
                strcat_s(out, "<br>" );
        }

        if (pSpell->AERange > 0.0f ) {
            if (pSpell->Range > 0.0f)
                strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" );
            else if (pSpell->PushBack > 0.0f )
                strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" );
            sprintf_s(temp, "AERange: %1.0f<br>", pSpell->AERange );
            strcat_s(out, temp);
        }

        if (pSpell->TargetType != 0x06 && pSpell->TargetType != 0x0e && pSpell->TargetType != 0x03 && pSpell->TargetType != 0x28 && pSpell->TargetType != 0x29) {
            if (pSpell->SpellType == 0) {   // Ziggy: Only show resist type for detrimental spells
                switch(pSpell->Resist)
                {
                case 9: strcat_s(out, "Resist: Corruption" ); break;
                case 7: strcat_s(out, "Resist: Prismatic[Avg]" ); break; // Ziggy - Added Reminder which..
                case 6: strcat_s(out, "Resist: Chromatic[Low]" ); break; // ..is what type of resist
                case 5: strcat_s(out, "Resist: Disease" ); break;
                case 4: strcat_s(out, "Resist: Poison" ); break;
                case 3: strcat_s(out, "Resist: Cold/Ice" ); break;
                case 2: strcat_s(out, "Resist: Fire" ); break;
                case 1: strcat_s(out, "Resist: Magic" ); break;
                case 0: strcat_s(out, "Resist: Unresistable"); break;
                }

                if (pSpell->ResistAdj != 0 ) {
                    sprintf_s(temp, "&nbsp;&nbsp;&nbsp;(Resist Adj.: %d)<br>", pSpell->ResistAdj );
                    strcat_s(out,temp);
                } else {
                    strcat_s(out,"<br>");
                }
            } 
        }

		if (pSpell->HateGenerated) {
            sprintf_s(temp, "Hate Generated: %d<br>", pSpell->HateGenerated);
            strcat_s(out,temp);
		}

		strcat_s(out, "<br>" );
		int outlen = strlen(out);
        ShowSpellSlotInfo(pSpell,&out[outlen],sizeof(out)-outlen);

        //show usable classes routine by Koad//
        bool bUseableClasses = false; 
        strcat_s(out, "<br>" ); 
        for (int j=Warrior; j<=Berserker; j++) {  // Ziggy - output will word wrap properly now
			if (((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j)>0 && ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j)<=MAX_PC_LEVEL) {
                if (bUseableClasses) strcat_s(out, ", ");

                sprintf_s(temp,"%s(%d)", GetClassDesc(j), ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j));
                strcat_s(out, temp);
                bUseableClasses = true;
            }
        } 
        if (bUseableClasses) strcat_s(out, "<br><br>" ); 
        if (char*str = GetSpellString(pSpell->ID,2)) { 
            sprintf_s(temp, "Cast on you: %s<br>", str); 
            strcat_s(out,temp); 
        } 

        if (char*str = GetSpellString(pSpell->ID,3)) { 
            sprintf_s(temp, "Cast on another: %s<br>", str); 
            strcat_s(out,temp); 
        } 

        if (char*str = GetSpellString(pSpell->ID,4)) { 
            sprintf_s(temp, "Wears off: %s<br>", str); 
            strcat_s(out,temp); 
        } 
		if (DWORD cat = GetSpellCategory(pSpell)) {
			if (char * ptr = pCDBStr->GetString(cat, 5, NULL)) {
				sprintf_s(temp, "Category: %s<br>", ptr);
				strcat_s(out, temp);
			}
		}
		if (DWORD cat = GetSpellSubcategory(pSpell)) {
			if (char * ptr = pCDBStr->GetString(cat, 5, NULL)) {
				sprintf_s(temp, "Subcategory: %s<br>", ptr);
				strcat_s(out, temp);
			}
		}
        if (out[0]!=17) {
            strcat_s(out,"</c>");
			#if !defined(ROF2EMU) && !defined(UFEMU)
				This->ItemInfo.Append(&out[0]);
			#else
				AppendCXStr(&This->ItemInfo, &out[0]);
			#endif
        }
    }
	#if defined(ROF2EMU) || defined(UFEMU)
    VOID ItemSetSpell_Detour(_ITEMSPELLS Effect, bool bFullInfo)
	#else
	VOID ItemSetSpell_Detour(_ITEMSPELLS Effect)
	#endif
    {
        PEQITEMWINDOW This=(PEQITEMWINDOW)this;
        PCHARINFO pCharInfo = NULL;
        if (NULL == (pCharInfo = GetCharInfo())) return;
        PSPELL pSpell = GetSpellByID(Effect.SpellID);
        if (pSpell == NULL) {
            return;
        }

        CHAR out[MAX_STRING*2] = {0};
        CHAR temp[MAX_STRING] = {0};
        if (!bNoSpellTramp) {
			#if defined(ROF2EMU) || defined(UFEMU)
			SetSpell_Trampoline(Effect.SpellID, bFullInfo);
			#else
			SetSpell_Trampoline(Effect.SpellID);
			#endif
            strcat_s(out,"<BR><c \"#00FFFF\">");
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

			CHAR aliased[MAX_STRING] = {0};
			sprintf_s(aliased, "%s%s", Effect.OtherName, " (aliased)");
            sprintf_s(temp, "<BR><c \"#%s\">Spell Info for %s effect: %s<br>", cColour, cName, Effect.OtherName[0] ? aliased : pSpell->Name);
			strcat_s(out,temp);

            if(This->ItemInfo && GetCXStr(This->ItemInfo, temp))
            {
                if(strstr(temp, out))
                {
                    return;
                }
            }
        }

        sprintf_s(temp, "ID: %04d&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", pSpell->ID );
        strcat_s(out,temp);

        DWORD Tics=GetSpellDuration(pSpell,(PSPAWNINFO)pLocalPlayer);
        if (Tics==0xFFFFFFFF)
            strcat_s(out, "Duration: Permanent<br>" );
        else if (Tics==0xFFFFFFFE) 
            strcat_s(out, "Duration: Unknown<br>" );
        else if (Tics==0) {
            // It's "instant", who cares?
            strcat_s(out,"<br>");
        }
        else {
            sprintf_s(temp, "Duration: %1.1f minutes<br>",(float)((Tics*6.0f)/60.0f));
            strcat_s(out, temp);
        }

        sprintf_s(temp, "RecoveryTime: %1.2f&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RecastTime: %1.2f <br>", (float)(pSpell->RecoveryTime/1000.0f), (float)(pSpell->RecastTime/1000.0f) );
        strcat_s(out,temp);

        if (pSpell->Range > 0.0f ) {
            sprintf_s(temp, "Range: %1.0f", pSpell->Range );
            strcat_s(out,temp);
            if ( pSpell->PushBack == 0.0f && pSpell->AERange == 0.0f)
                strcat_s(out, "<br>");
        }

        if (pSpell->PushBack != 0.0f ) {
            if (pSpell->Range > 0.0f ) 
                strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" );
            sprintf_s(temp, "PushBack: %1.1f", pSpell->PushBack );
            strcat_s(out, temp);
            if (pSpell->AERange == 0.0f || pSpell->Range > 0.0f )
                strcat_s(out, "<br>" );
        }

        if (pSpell->AERange > 0.0f ) {
            if (pSpell->Range > 0.0f)
                strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" );
            else if (pSpell->PushBack > 0.0f )
                strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" );
            sprintf_s(temp, "AERange: %1.0f<br>", pSpell->AERange );
            strcat_s(out, temp);
        }

        if (pSpell->TargetType != 0x06 && pSpell->TargetType != 0x0e && pSpell->TargetType != 0x03 && pSpell->TargetType != 0x28 && pSpell->TargetType != 0x29) {
            if (pSpell->SpellType == 0) {   // Ziggy: Only show resist type for detrimental spells
                switch(pSpell->Resist)
                {
                case 9: strcat_s(out, "Resist: Corruption" ); break;
                case 7: strcat_s(out, "Resist: Prismatic[Avg]" ); break; // Ziggy - Added Reminder which..
                case 6: strcat_s(out, "Resist: Chromatic[Low]" ); break; // ..is what type of resist
                case 5: strcat_s(out, "Resist: Disease" ); break;
                case 4: strcat_s(out, "Resist: Poison" ); break;
                case 3: strcat_s(out, "Resist: Cold/Ice" ); break;
                case 2: strcat_s(out, "Resist: Fire" ); break;
                case 1: strcat_s(out, "Resist: Magic" ); break;
                case 0: strcat_s(out, "Resist: Unresistable"); break;
                }

                if (pSpell->ResistAdj != 0 ) {
                    sprintf_s(temp, "&nbsp;&nbsp;&nbsp;(Resist Adj.: %d)<br>", pSpell->ResistAdj );
                    strcat_s(out,temp);
                } else {
                    strcat_s(out,"<br>");
                }
            } 
        }

		if (pSpell->HateGenerated) {
            sprintf_s(temp, "Hate Generated: %d<br>", pSpell->HateGenerated);
            strcat_s(out,temp);
		}

        strcat_s(out, "<br>" );
		int outlen = strlen(out);
        ShowSpellSlotInfo(pSpell,&out[outlen],sizeof(out)-outlen);

        //show usable classes routine by Koad//
        bool bUseableClasses = false; 
        strcat_s(out, "<br>" ); 
        for (int j=Warrior; j<=Berserker; j++) {  // Ziggy - output will word wrap properly now
			if (((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j)>0 && ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j)<=MAX_PC_LEVEL) {
                if (bUseableClasses) strcat_s(out, ", ");

                sprintf_s(temp,"%s(%d)", GetClassDesc(j), ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j));
                strcat_s(out, temp);
                bUseableClasses = true;
            }
        } 
        if (bUseableClasses) strcat_s(out, "<br><br>" ); 

        if (char*str = GetSpellString(pSpell->ID,2)) { 
            sprintf_s(temp, "Cast on you: %s<br>", str); 
            strcat_s(out,temp); 
        } 

        if (char*str = GetSpellString(pSpell->ID,3)) { 
            sprintf_s(temp, "Cast on another: %s<br>", str); 
            strcat_s(out,temp); 
        } 
		if (char*str = GetSpellString(pSpell->ID,4)) { 
            sprintf_s(temp, "Wears off: %s<br>", str); 
            strcat_s(out,temp); 
        } 

        if (out[0]!=17) {
            strcat_s(out,"</c>");
            //((CXStr)This->ItemInfo)+=
            AppendCXStr(&This->ItemInfo,&out[0]);   
        }
    }

    VOID UpdateStrings_Trampoline();
    VOID UpdateStrings_Detour()
    {
		PEQITEMWINDOW This=(PEQITEMWINDOW)this;
		int index = This->ItemWndIndex;
		if (index > 5 || index < 0)
		{
			index = 0;
			WriteChatf("Tell eqmule his PEQITEMWINDOW struct is wrong");
		}
        PCONTENTS item=(PCONTENTS)This->pItem;
        volatile PITEMINFO Item=GetItemFromContents(item);
        CHAR out[MAX_STRING*2] = {0};
        CHAR temp[MAX_STRING] = {0};
        PCHAR lore = NULL;

        UpdateStrings_Trampoline();
        lockit lockid(hDisplayItemLock,"UpdateStrings_Detour");

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
#if !defined(ROF2EMU) && !defined(UFEMU)
			if (This->bCollectedReceived)
			{
				contentsitemstrings[index].bCollectedRecieved = true;
				contentsitemstrings[index].bCollected = This->bCollected;
			}
			else
			{
				contentsitemstrings[index].bCollectedRecieved = false;
				contentsitemstrings[index].bCollected = false;
			}
			if (This->bScribedReceived)
			{
				contentsitemstrings[index].bScribedRecieved = true;
				contentsitemstrings[index].bScribed = This->bScribed;
			}
			else
			{
				contentsitemstrings[index].bScribedRecieved = false;
				contentsitemstrings[index].bScribed = false;
			}
#endif
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
			MessageBox(NULL,"An exception occurred in mq2itemdisplay","Error",MB_OK);
			//handle stuff
		}
        // keep a global copy of the last item displayed...
		if (index <= 5) {
			memcpy(&g_Contents[index], item, sizeof(CONTENTS));
			memcpy(&g_Item, Item, sizeof(ITEMINFO));
			g_LastIndex = index;
		}

        strcpy_s(out,"<BR><c \"#00FFFF\">");
        if ( Item->ItemNumber > 0 ) { 
            sprintf_s(temp,"Item ID: %d<br>", Item->ItemNumber); 
            strcat_s(out, temp); 
        }
		if ( Item->ItemNumber > 0 ) { 
            sprintf_s(temp,"Icon ID: %d<br>", Item->IconNumber); 
            strcat_s(out, temp); 
        }
		//work in progress i have been told this can be done.
		/*if ( Item->Collected > 0 ) { 
            sprintf_s(temp,"Collected<br>"); 
            strcat_s(out, temp); 
        }*/
#ifndef ISXEQ
		// Dewey 2461 - user defined score 12-22-2012
		AddGearScores((PCONTENTS)This->pItem,Item,out,"<BR>");
#endif
        if ( ((EQ_Item*)item)->IsStackable() ) {
            if ( Item->StackSize > 0 ) {
                sprintf_s(temp,"Stackable Count: %d<br>", Item->StackSize);
                strcat_s(out, temp);
            }
        } 
        if (Item->Cost>0) {
            DWORD cp = Item->Cost;
            DWORD sp = cp/10; cp=cp%10;
            DWORD gp = sp/10; sp=sp%10;
            DWORD pp = gp/10; gp=gp%10;
            strcat_s(out,"Value:");
            if (pp>0) {
                sprintf_s(temp," %dpp",pp);
                strcat_s(out,temp);
            }
            if (gp>0) {
                sprintf_s(temp," %dgp",gp);
                strcat_s(out,temp);
            }
            if (sp>0) {
                sprintf_s(temp," %dsp",sp);
                strcat_s(out,temp);
            }
            if (cp>0) {
                sprintf_s(temp," %dcp",cp);
                strcat_s(out,temp);
            }
            strcat_s(out,"<BR>");
        }

        if ( Item->Favor > 0 ) {
            sprintf_s(temp,"Tribute Value: %d<br>", Item->Favor);
            strcat_s(out, temp);
        }
        if (Item->GuildFavor > 0 )  { 
            sprintf_s(temp,"Guild Tribute Value: %d<br>", Item->GuildFavor); 
            strcat_s(out, temp); 
        }
        if (Item->Clicky.TimerID!=0) {
            int Secs = GetItemTimer(item);
            if (!Secs) {
                sprintf_s(temp,"Item Timer: <c \"#20FF20\">Ready</c><br>");
            } else {
                int Mins=(Secs/60)%60;
                int Hrs=(Secs/3600);
                Secs=Secs%60;
                if (Hrs)
                    sprintf_s(temp,"Item Timer: %d:%02d:%02d<br>",Hrs,Mins,Secs);
                else
                    sprintf_s(temp,"Item Timer: %d:%02d<br>",Mins,Secs);
            }
            strcat_s(out, temp);
        }

        //Outlaw (AKA CheckinThingsOut) (02/24/2005)
        if (Item->ItemType != 27) { //Arrows..they have dmg/dly but we don't want them
            if ( Item->Delay > 0) {
                if ( Item->Damage > 0) {
                    sprintf_s(temp,"Ratio: %5.3f<br>", (float)Item->Delay / (float)Item->Damage);
                    strcat_s(out, temp);
                    //Calculate Efficiency
                    INT dmgbonus = 0;

                    if (PCHARINFO2 pChar2 = GetCharInfo2()) {
						if (pChar2->Level > 27 && This->ItemInfo) { //bonus is 0 for anything below 28
							dmgbonus = GetDmgBonus(&This->ItemInfo);
						}
                    }

                    sprintf_s(temp,"Efficiency: %3.0f<br>",((((float)Item->Damage * 2) + dmgbonus) / (float)Item->Delay) * 50);
                    strcat_s(out, temp);
                    if (Item->EquipSlots & 16384) { // Equipable In Secondary Slot
                        sprintf_s(temp,"Offhand Efficiency: %3.0f<br>",((((float)Item->Damage * 2) / (float)Item->Delay) * 50) * 0.62);
                        strcat_s(out, temp);
                    }
                    sprintf_s(temp,"<br>");
                    strcat_s(out,temp);    
                }
            }
        }
        lore=Item->LoreName;
        if (lore[0]=='*') lore++;
        if (strcmp(lore,Item->Name)) {
            sprintf_s(temp,"Item Lore: %s<BR>",Item->LoreName);
            strcat_s(out,temp);
        }
        //PCHARINFO pChar = GetCharInfo();     // Ziggy - for item level highlights 
        // Will be 0 for no effect or -1 if other effects present 
        if (Item->Proc.SpellID && Item->Proc.SpellID!=-1) { 
			if (Item->Proc.RequiredLevel == 0) {
				sprintf_s(temp, "Procs at level 1 (Proc rate modifier: %d)<BR>", Item->Proc.ProcRate);
			} else {
				if (PCHARINFO2 pChar2 = GetCharInfo2()) {
					sprintf_s(temp, "%sProcs at level %d%s (Proc rate modifier: %d)<BR>", (Item->Proc.RequiredLevel > pChar2->Level ? "<c \"#FF4040\">" : ""), Item->Proc.RequiredLevel, (Item->Proc.RequiredLevel > pChar2->Level ? "</C>" : ""), Item->Proc.ProcRate);
				}
			}
			strcat_s(out, temp);
        } 
        /* No longer needed? 
        else if (Item->SpellId==998) { // 998 = haste 
        sprintf_s(temp,"%d%% Haste<BR>",Item->Level+1); 
        strcat_s(out,temp); 
        } 
        */ 

        // Just in case...
        if (This->ItemInfo && (!strstr(This->ItemInfo->Text,"(Combat)")) && Item->Proc.ProcRate > 0 )
        {
            sprintf_s(temp, "Proc rate Modifier: %d<BR>", Item->Proc.ProcRate );
            strcat_s(out,temp);
        }

        // Teh_Ish (02/08/2004) 
		if (Item->Clicky.EffectType == 4 || Item->Clicky.EffectType == 1 || Item->Clicky.EffectType == 5) {
			if (Item->Clicky.RequiredLevel == 0) {
				sprintf_s(temp, "Clickable at level 1<br>");
			} else {
				if (PCHARINFO2 pChar2 = GetCharInfo2()) {
					sprintf_s(temp, "%sClickable at level %d%s<BR>", (Item->Clicky.RequiredLevel > pChar2->Level ? "<c \"#FF4040\">" : ""), Item->Clicky.RequiredLevel, (Item->Clicky.RequiredLevel > pChar2->Level ? "</C>" : ""));
				}
			}
			strcat_s(out, temp);
        }

        // TheColonel (12/24/2003)
        if (Item->LDType == 1) {
            if(Item->LDCost == 0)
                sprintf_s(temp,"This drops in %s dungeons<BR>", GetLDoNTheme(Item->LDTheme));
            else
				sprintf_s(temp, "LDoN Cost: %d from %s<BR>", Item->LDCost, GetLDoNTheme(Item->LDTheme));
			strcat_s(out, temp);
        }
        if (Item->LDType == 2 && Item->LDCost > 0) {
			sprintf_s(temp, "Discord Cost: %d points<BR>", Item->LDCost);
			strcat_s(out, temp);
        }
        if (Item->LDType == 4 && Item->LDCost > 0) {
			sprintf_s(temp, "DoN Cost: %d Radiant Crystals<BR>", Item->LDCost);
			strcat_s(out, temp);
        }
        if (Item->LDType == 5 && Item->LDCost > 0) {
			sprintf_s(temp, "DoN Cost: %d Ebon Crystals<BR>", Item->LDCost);
			strcat_s(out, temp);
        } 
        // TheColonel (1/18/2004)
        /*
        if (Item->InstrumentType != 0){ 
        float instrumentmod = ((float)Item->InstrumentMod)/10.0f; 
        sprintf_s(temp,"Instrument mod: %3.1f to %s.<BR>", instrumentmod, szItemTypes[Item->InstrumentType]); 
        strcat_s(out,temp);       
        } 
        /**/

        if (Item->Type == ITEMTYPE_PACK) {
			sprintf_s(temp, "Container Type: %s<BR>", szCombineTypes[Item->Combine]);
			strcat_s(out, temp);
        }


		sprintf_s(temp, "%07d", Item->ItemNumber);
#ifndef ISXEQ
		CHAR temp2[MAX_STRING] = { 0 };
		GetPrivateProfileString("Notes", temp, "", temp2, MAX_STRING, INIFileName);
		if (strlen(temp2) > 0)
        { 
			sprintf_s(temp, "Note: %s<br>", temp2);
            strcat_s(out, temp); 
        }  
#endif

		if (out[0] != 17) {
			strcat_s(out, "</c>");
			((CStmlWnd*)This->Description)->AppendSTML(&out[0]);
        }
    }
	virtual void onURIChanged(void *);
	virtual void onProgressChanged(void *);
	virtual void onStatusChanged(void *);
	virtual bool doValidateURI(void *, const char *);

	int WndNotification_Trampoline(CXWnd*, unsigned __int32, void*);
	int WndNotification_Detour(CXWnd* pWnd, unsigned __int32 Message, void* pData)
    {
#if !defined(ROF2EMU) && !defined(UFEMU)
		if (Message == XWM_LCLICK)
		{
			std::map<CButtonWnd*, ButtonInfo>::iterator i = ButtonMap.find((CButtonWnd*)pWnd);
			if (i != ButtonMap.end()) {
				switch (i->second.ID)
				{
					case 2://Toggle the Need Loot Filter
					{
						if (i->first->Checked) {//check need
							//uncheck 3 and 4
							for (std::map<CButtonWnd*, ButtonInfo>::iterator j = ButtonMap.begin(); j != ButtonMap.end(); j++) {
								if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd) {
									if (j->second.ID == 3 || j->second.ID == 4) {
										j->first->Checked = false;
									}
								}
							}
							if (PITEMINFO pItem = GetItemFromContents(i->second.ItemDisplayWnd->pCurrentItem)) {
								if (pLootFiltersManager) {
									pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 2, true, true);
								}
							}
						}
						else {//uncheck need
							bool bAutoRollisChecked = false;
							for (std::map<CButtonWnd*, ButtonInfo>::iterator j = ButtonMap.begin(); j != ButtonMap.end(); j++) {
								if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd) {
									if (j->second.ID == 5) {
										bAutoRollisChecked = j->first->Checked;
										break;
									}
								}
							}
							if (PITEMINFO pItem = GetItemFromContents(i->second.ItemDisplayWnd->pCurrentItem)) {
								if (pLootFiltersManager) {
									if (PItemFilterData pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber)) {
										bool bAutoRoll = ( pData->Types & ( 1<<0 ) ) != 0;
										if (bAutoRoll) {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 2);
										}
										else {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
										}
									}
									else {
										//its not currently in lootfilters
										if (bAutoRollisChecked) {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 2);
										}
										else {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
										}
									}
								}
							}
						}
						return 0;
					}
					case 3://Toggle the Greed Loot Filter
					{
						if (i->first->Checked) {//check greed
							//uncheck 2 and 4
							bool bAutoRollisChecked = false;
							for (std::map<CButtonWnd*, ButtonInfo>::iterator j = ButtonMap.begin(); j != ButtonMap.end(); j++) {
								if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd) {
									if (j->second.ID == 2 || j->second.ID == 4) {
										j->first->Checked = false;
									}
									else if (j->second.ID == 5) {
										bAutoRollisChecked = j->first->Checked;
									}
								}
							}
							if (PITEMINFO pItem = GetItemFromContents(i->second.ItemDisplayWnd->pCurrentItem)) {
								if (pLootFiltersManager) {
									pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 4, true, true);
								}
							}
						}
						else {//uncheck greed
							bool bAutoRollisChecked = false;
							for (std::map<CButtonWnd*, ButtonInfo>::iterator j = ButtonMap.begin(); j != ButtonMap.end(); j++) {
								if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd) {
									if (j->second.ID == 5) {
										bAutoRollisChecked = j->first->Checked;
										break;
						}
					}
							}
							if (PITEMINFO pItem = GetItemFromContents(i->second.ItemDisplayWnd->pCurrentItem)) {
								if (pLootFiltersManager) {
									if (PItemFilterData pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber)) {
										bool bAutoRoll = (pData->Types & (1 << 0)) != 0;
										if (bAutoRoll) {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 4);
										}
										else {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
										}
									}
									else {
										//its not currently in lootfilters
										if (bAutoRollisChecked) {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 4);
										}
										else {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
										}
									}
								}
							}	
						}
						return 0;
					}
					case 4://Toggle the Never Loot Filter
					{
						if (i->first->Checked) {//check never
							//uncheck 2 and 3
							bool bAutoRollisChecked = false;
							for (std::map<CButtonWnd*, ButtonInfo>::iterator j = ButtonMap.begin(); j != ButtonMap.end(); j++) {
								if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd) {
									if (j->second.ID == 2 || j->second.ID == 3) {
										j->first->Checked = false;
									}
									else if (j->second.ID == 5) {
										bAutoRollisChecked = j->first->Checked;
									}
								}
							}
							if (PITEMINFO pItem = GetItemFromContents(i->second.ItemDisplayWnd->pCurrentItem)) {
								if (pLootFiltersManager) {
									pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 8, true, true);
								}
							}
						}
						else {//uncheck never
							bool bAutoRollisChecked = false;
							for (std::map<CButtonWnd*, ButtonInfo>::iterator j = ButtonMap.begin(); j != ButtonMap.end(); j++) {
								if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd) {
									if (j->second.ID == 5) {
										bAutoRollisChecked = j->first->Checked;
					break;
				}
			}
		}
							if (PITEMINFO pItem = GetItemFromContents(i->second.ItemDisplayWnd->pCurrentItem)) {
								if (pLootFiltersManager) {
									if (PItemFilterData pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber)) {
										bool bAutoRoll = (pData->Types & (1 << 0)) != 0;
										if (bAutoRoll) {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 8);
										}
										else {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
										}
									}
									else {
										//its not currently in lootfilters
										if (bAutoRollisChecked) {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 8);
										}
										else {
											pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
										}
									}
								}
							}
						}
						return 0;
					}
					case 5://Toggle the Auto Roll Loot Filter
					{
						if (i->first->Checked) {//check autoroll
							if (PITEMINFO pItem = GetItemFromContents(i->second.ItemDisplayWnd->pCurrentItem)) {
								if (pLootFiltersManager) {
									if (PItemFilterData pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber)) {
										bool bNeed = (pData->Types & (1 << 1)) != 0;
										bool bGreed = (pData->Types & (1 << 2)) != 0;
										bool bNever = (pData->Types & (1 << 3)) != 0;
										if (bNeed) {
											pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 3, false, true);
										}
										else  if (bGreed) {
											pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 5, false, true);
										}
										else  if (bNever) {
											pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 9, false, true);
										}
										else {
											pLootFiltersManager->AddItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 1);
										}
									}
									else {
										pLootFiltersManager->AddItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 1);
									}
								}
							}
						}
						else {//uncheck autoroll
							if (PITEMINFO pItem = GetItemFromContents(i->second.ItemDisplayWnd->pCurrentItem)) {
								pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 1);
							}
						}
						return 0;
					}			
					case 6://open in lucy
					{
						if (PITEMINFO pItem = GetItemFromContents(i->second.ItemDisplayWnd->pCurrentItem)) {
							std::string url = "http://lucy.allakhazam.com/item.html?id=";
							CHAR szID[64] = { 0 };
							_itoa_s(pItem->ItemNumber, szID, 10);
							url.append(szID);
							if (CHtmlWnd *ItemHtmlwnd = pCWebManager->CreateHtmlWnd(url.c_str(), pItem->Name, NULL, true, pItem->Name))
							{
								ItemHtmlwnd->MinClientSize.cx = 0;
								ItemHtmlwnd->MinClientSize.cy = 0;
								ItemHtmlwnd->bMaximizable = true;
								ItemHtmlwnd->WindowStyle = CWS_USEMYALPHA | CWS_RESIZEBORDER | CWS_MAXIMIZE | CWS_CLOSE | CWS_TITLE | CWS_MINIMIZE;
								int oldwidth = ItemHtmlwnd->Location.right - ItemHtmlwnd->Location.left;
								int oldheight = ItemHtmlwnd->Location.bottom - ItemHtmlwnd->Location.top;
								ItemHtmlwnd->Location.right = ItemHtmlwnd->Location.left + 759;
								ItemHtmlwnd->Location.bottom = ItemHtmlwnd->Location.top + 539;
								ItemInfoManager& manager = ItemInfoManager::GetInstance();
								manager.htmlwnd = ItemHtmlwnd;
								int width = manager.htmlwnd->Location.right - manager.htmlwnd->Location.left;
								int height = manager.htmlwnd->Location.bottom - manager.htmlwnd->Location.top;
								CXWnd*cxwnd = (CXWnd*)ItemHtmlwnd;
								cxwnd->Resize(width+1, height+1);
								ItemHtmlwnd->SetClientCallbacks(&manager);
								//maybe later im not 100% sure what observers are for
								//ItemHtmlwnd->AddObserver(&manager);
								Sleep(0);
							}
						}
						return 0;
					}
				}
			}
		}
#endif
        return WndNotification_Trampoline(pWnd, Message, pData);
    };

	bool AboutToShow_Trampoline(void);
	bool AboutToShow_Detour(void)
	{
		PEQITEMWINDOW This = (PEQITEMWINDOW)this;
		int index = This->ItemWndIndex;
		if (index > 5 || index < 0)
		{
			index = 0;
			WriteChatf("Tell eqmule his PEQITEMWINDOW struct is wrong");
		}
		PCONTENTS item = (PCONTENTS)This->pItem;
		volatile PITEMINFO Item = GetItemFromContents(item);

		// Ziggy - Items showing their spell details:
		bNoSpellTramp = true;
		if (Item->Clicky.SpellID > 0 && Item->Clicky.SpellID != -1) {
			eEffectType = Clicky;
#if defined(ROF2EMU) || defined(UFEMU)
			ItemSetSpell_Detour(Item->Clicky, false);
#else
			ItemSetSpell_Detour(Item->Clicky);
#endif
		}

		if (Item->Proc.SpellID > 0 && Item->Proc.SpellID != -1) {
			eEffectType = Proc;
#if defined(ROF2EMU) || defined(UFEMU)
			ItemSetSpell_Detour(Item->Proc, false);
#else
			ItemSetSpell_Detour(Item->Proc);
#endif
		}

		if (Item->Worn.SpellID > 0 && Item->Worn.SpellID != -1) {
			eEffectType = Worn;
#if defined(ROF2EMU) || defined(UFEMU)
			ItemSetSpell_Detour(Item->Worn, false);
#else
			ItemSetSpell_Detour(Item->Worn);
#endif
		}

		if (Item->Focus.SpellID > 0 && Item->Focus.SpellID != -1) {
			eEffectType = Focus;
#if defined(ROF2EMU) || defined(UFEMU)
			ItemSetSpell_Detour(Item->Focus, false);
#else
			ItemSetSpell_Detour(Item->Focus);
#endif
		}

		if (Item->Scroll.SpellID > 0 && Item->Scroll.SpellID != -1) {
			eEffectType = Scroll;
#if defined(ROF2EMU) || defined(UFEMU)
			ItemSetSpell_Detour(Item->Scroll, false);
#else
			ItemSetSpell_Detour(Item->Scroll);
#endif
		}
		if (Item->Focus2.SpellID > 0 && Item->Focus2.SpellID != -1) {
			eEffectType = Focus2;
#if defined(ROF2EMU) || defined(UFEMU)
			ItemSetSpell_Detour(Item->Focus2, false);
#else
			ItemSetSpell_Detour(Item->Focus2);
#endif
		}
#if !defined(ROF2EMU) && !defined(UFEMU)
		if (Item->Mount.SpellID > 0 && Item->Mount.SpellID != -1) {
			eEffectType = Mount;
			ItemSetSpell_Detour(Item->Mount);
		}
		if (Item->Illusion.SpellID > 0 && Item->Illusion.SpellID != -1) {
			eEffectType = Illusion;
			ItemSetSpell_Detour(Item->Illusion);
		}
		if (Item->Familiar.SpellID > 0 && Item->Familiar.SpellID != -1) {
			eEffectType = Familiar;
			ItemSetSpell_Detour(Item->Familiar);

		}
#endif
		bNoSpellTramp = false;
		eEffectType = None;

		if (CItemDisplayWnd *pWnd = (CItemDisplayWnd*)this) {
			bool doit = false;
			//get rid of old buttons. we really should destroy them in abouttohide but i dont want another detour.
			for (std::map<CButtonWnd*, ButtonInfo>::iterator i = ButtonMap.begin(); i != ButtonMap.end();) {
				if (i->second.ItemDisplayWnd == pWnd) {
					i->first->Destroy();
					std::map<CButtonWnd*, ButtonInfo>::iterator next = i;
					next++;
					ButtonMap.erase(i);		
					i = next;
				}
				else {
					i++;
				}
			}
			//create add to loot filters button
#if !defined(ROF2EMU) && !defined(UFEMU)
			if (gLootButton) {
				CControlTemplate *btntemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("LF_CheckBoxTemplate");
				CControlTemplate *labeltemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButtonLabel");
				if (btntemplate && labeltemplate) {
					UINT oldfont = labeltemplate->Font;
					labeltemplate->Font = 1;
					//labeltemplate->TextColor = 0xFF0094FF;
					CLabelWnd *pheader = (CLabelWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)this, labeltemplate);
					pheader->CRNormal = 0xFF0094FF;
					CButtonWnd *pAlwaysNeedBtn = (CButtonWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)this, btntemplate);
					CButtonWnd *pAlwaysGreedBtn = (CButtonWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)this, btntemplate);
					CButtonWnd *pNeverBtn = (CButtonWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)this, btntemplate);
					CButtonWnd *pAutoRollBtn = (CButtonWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)this, btntemplate);
					if (pAlwaysNeedBtn && pAlwaysGreedBtn && pNeverBtn && pAutoRollBtn && pheader) {
						SetCXStr(&pheader->WindowText, "AN | AG | NV | AR");
						SetCXStr(&pAlwaysNeedBtn->Tooltip, "Always roll need on this item");
						SetCXStr(&pAlwaysGreedBtn->Tooltip, "Always roll greed on this item");
						SetCXStr(&pNeverBtn->Tooltip, "Never loot this item");
						SetCXStr(&pAutoRollBtn->Tooltip, "Always roll on this item");
						ButtonInfo bi;
						bi.ItemDisplayWnd = pWnd;	
						if (CXWnd*orgbutton = pWnd->GetChildItem("IDW_ModButtonLabel")) {
							int spacing = 22;
							//header
							pheader->Location.top = orgbutton->Location.top + 22;
							pheader->Location.bottom = pheader->Location.top + 12;
							pheader->Location.left = orgbutton->Location.left;
							pheader->Location.left += 80;
							pheader->Location.right += 160;
							//always need
							pAlwaysNeedBtn->Location.top = orgbutton->Location.top + 36;
							pAlwaysNeedBtn->Location.bottom = pAlwaysNeedBtn->Location.top + 14;
							pAlwaysNeedBtn->Location.left = orgbutton->Location.left;
							pAlwaysNeedBtn->Location.left += 80;
							pAlwaysNeedBtn->Location.right = pAlwaysNeedBtn->Location.left + 14;
							//always greed
							pAlwaysGreedBtn->Location.top = pAlwaysNeedBtn->Location.top;
							pAlwaysGreedBtn->Location.bottom = pAlwaysNeedBtn->Location.bottom;
							pAlwaysGreedBtn->Location.left = pAlwaysNeedBtn->Location.left + spacing;
							pAlwaysGreedBtn->Location.right = pAlwaysNeedBtn->Location.right + spacing;
							//never
							pNeverBtn->Location.top = pAlwaysGreedBtn->Location.top;
							pNeverBtn->Location.bottom = pAlwaysGreedBtn->Location.bottom;
							pNeverBtn->Location.left = pAlwaysGreedBtn->Location.left + spacing;
							pNeverBtn->Location.right = pAlwaysGreedBtn->Location.right + spacing;
							//autoroll
							pAutoRollBtn->Location.top = pNeverBtn->Location.top;
							pAutoRollBtn->Location.bottom = pNeverBtn->Location.bottom;
							pAutoRollBtn->Location.left = pNeverBtn->Location.left + spacing;
							pAutoRollBtn->Location.right = pNeverBtn->Location.right + spacing;
						}
						bi.ID = 1;
						pheader->Data = bi.ID;
						ButtonMap[(CButtonWnd*)pheader] = bi;
						bi.ID = 2;
						pAlwaysNeedBtn->Data = bi.ID;
						ButtonMap[pAlwaysNeedBtn] = bi;
						bi.ID = 3;
						pAlwaysGreedBtn->Data = bi.ID;
						ButtonMap[pAlwaysGreedBtn] = bi;
						bi.ID = 4;
						pNeverBtn->Data = bi.ID;
						ButtonMap[pNeverBtn] = bi;
						bi.ID = 5;
						pAutoRollBtn->Data = bi.ID;
						ButtonMap[pAutoRollBtn] = bi;
						if (PITEMINFO pItem = GetItemFromContents(pWnd->pCurrentItem)) {
							if (pLootFiltersManager) {
								if (PItemFilterData pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber)) {
									bool bAutoRoll = ( pData->Types & ( 1<<0 ) ) != 0;
									bool bNeed = ( pData->Types & ( 1<<1 ) ) != 0;
									bool bGreed = ( pData->Types & ( 1<<2 ) ) != 0;
									bool bNever = ( pData->Types & ( 1<<3 ) ) != 0;
									if (bNeed) {
										pAlwaysNeedBtn->Checked = true;
									}
									if (bGreed) {
										pAlwaysGreedBtn->Checked = true;
									}
									if (bNever) {
										pNeverBtn->Checked = true;
									}
									if (bAutoRoll) {
										pAutoRollBtn->Checked = true;
									}
								}
								else {
									pAlwaysNeedBtn->Checked = false;
									pAlwaysGreedBtn->Checked = false;
									pNeverBtn->Checked = false;
									pAutoRollBtn->Checked = false;
								}
							}
						}
					}
					labeltemplate->Font = oldfont;
				}
			}
#endif
			//ok now create the lucy button
			if (gLucyButton) {
				if (CControlTemplate *btntemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButton")) {
					UINT oldfont = btntemplate->Font;
					btntemplate->Font = 1;
					//btntemplate->TextColor = 0xFFFFFF00;
					if (CButtonWnd *pBtn = (CButtonWnd *)pSidlMgr->CreateXWndFromTemplate((CXWnd*)this, btntemplate)) {
						pBtn->CRNormal = 0xFFFFFF00;
						//pBtn->dShow = true;
						pBtn->Location.top = 10;
						pBtn->Location.bottom = 30;
						pBtn->Location.left = 20;
						pBtn->Location.right = 60;
						((CXWnd*)pBtn)->SetWindowTextA(CXStr("Lucy"));
						ButtonInfo bi;
						bi.ItemDisplayWnd = pWnd;
						bi.ID = 6;
						#if !defined(UFEMU)
						pBtn->Data = bi.ID;
						#endif
						ButtonMap[pBtn] = bi;
						pBtn->BGColor = 0xFF0000FF;
						pBtn->DecalTint = 0xFF00FFFF;
					}
					btntemplate->Font = oldfont;
				}
			}
		}
		return AboutToShow_Trampoline();
	}
	
	static void PrintItem(PCONTENTS pCont,PCONTENTS pEquipped)
	{
		if (PITEMINFO pItem = GetItemFromContents(pCont))
		{
			if (CanIUseThisItem(pItem))
			{
				if (PITEMINFO pItem2 = GetItemFromContents(pEquipped))
				{
					CXPoint pt;
					pt.X = EQADDR_MOUSE->X + 5;
					pt.Y = EQADDR_MOUSE->Y + 5;
					((CXWnd *)pCompareTipWnd)->Move(pt);
					pCompareTipWnd->ZLayer = 0;

					((CStmlWnd*)pCompareTipWnd->Display)->SetSTMLText("", 1, 0);
					((CStmlWnd*)pCompareTipWnd->Display)->ForceParseNow();
					CHAR szTemp[MAX_STRING] = { 0 };
					CHAR szTemp2[MAX_STRING] = { 0 };
					DWORD realcolor = 0xFF00FF00;// ConColorToARGB(argbcolor) & 0x00FFFFFF;
					sprintf_s(szTemp, "<c \"#FFFF00\">%s<br></c><c \"#FFFFFF\">%s %s </c><br>", pItem->Name, pItem->Lore ? "[Lore]" : "", pItem->NoDrop ? "" : "[No Drop]");
					((CStmlWnd*)pCompareTipWnd->Display)->SetSTMLText(szTemp, 1, 0);
					
					sprintf_s(szTemp, "<c \"#FFFF00\">%s<br></c>", GetSlots(pItem, szTemp2));
					((CStmlWnd*)pCompareTipWnd->Display)->AppendSTML(szTemp);
					DWORD color = 0xFF0000;
					int ACStat = pItem->AC - pItem2->AC;
					if (ACStat > 0)
						color = 0x00FF00;
					sprintf_s(szTemp, "<c \"#FFFFFF\">Rec Level: </c><c \"#00FF00\">%d</c><c \"#FFFFFF\">&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;AC: </c><c \"#%06X\">%d</c><br>", pItem->RequiredLevel,color, ACStat);
					((CStmlWnd*)pCompareTipWnd->Display)->AppendSTML(szTemp);

					((CStmlWnd*)pCompareTipWnd->Display)->ForceParseNow();
					pCompareTipWnd->dShow = 1;
				}
			}
		}
	}
	int CInvSlotWnd_DrawTooltipTramp(const CXWnd *pwnd) const;
	int CInvSlotWnd_DrawTooltipDetour(const CXWnd *pwnd) const
	{
		if (gCompareTip)
		{
			if (CInvSlotWnd*wnd = (CInvSlotWnd*)this)
			{
				PCONTENTS pCont = 0;
				if (wnd->pEQInvSlot) {
					wnd->pEQInvSlot->GetItemBase(&pCont);
				}
				if (pCont && pCont != pOldCont) {
					pOldCont = pCont;
					if (PITEMINFO pItem = GetItemFromContents(pCont))
					{
						if (pCompareTipWnd && pCompareTipWnd->Display)
						{
							if (PCONTENTS pEquipped = GetEquippedSlot(pCont))
							{
								PrintItem(pCont, pEquipped);
							}
						}
						//WriteChatf("CInvSlotWnd_DrawTooltipDetour called for %s", pItem->Name);
					}
				}
			}
		}
		return CInvSlotWnd_DrawTooltipTramp(pwnd);
	}
};

ItemDisplayHook::SEffectType ItemDisplayHook::eEffectType = None;
bool ItemDisplayHook::bNoSpellTramp = false;

DETOUR_TRAMPOLINE_EMPTY(int ItemDisplayHook::CInvSlotWnd_DrawTooltipTramp(const CXWnd *pwnd) const);
DETOUR_TRAMPOLINE_EMPTY(int ItemDisplayHook::WndNotification_Trampoline(CXWnd*, unsigned __int32, void*));
DETOUR_TRAMPOLINE_EMPTY(bool ItemDisplayHook::AboutToShow_Trampoline(void));
#if defined(ROF2EMU) || defined(UFEMU)
DETOUR_TRAMPOLINE_EMPTY(VOID ItemDisplayHook::SetSpell_Trampoline(int SpellID,bool bFullInfo));
#else
DETOUR_TRAMPOLINE_EMPTY(VOID ItemDisplayHook::SetSpell_Trampoline(int SpellID));
#endif
DETOUR_TRAMPOLINE_EMPTY(VOID ItemDisplayHook::UpdateStrings_Trampoline());
enum eAugTypes
{
	AT_1 = 0x00000001,
	AT_2 = 0x00000002,
	AT_3 = 0x00000004,
	AT_4 = 0x00000008,
	AT_5 = 0x00000010,
	AT_6 = 0x00000020,
	AT_7 = 0x00000040,
	AT_8 = 0x00000080,
	AT_9 = 0x00000100,
	AT_10 = 0x00000200,
	AT_11 = 0x00000400,
	AT_12 = 0x00000800,
	AT_13 = 0x00001000,
	AT_14 = 0x00002000,
	AT_15 = 0x00004000,
	AT_16 = 0x00008000,
	AT_17 = 0x00010000,
	AT_18 = 0x00020000,
	AT_19 = 0x00040000,
	AT_20 = 0x00080000,
	AT_21 = 0x00100000,
	AT_22 = 0x00200000,
	AT_23 = 0x00400000,
	AT_24 = 0x00800000,
	AT_25 = 0x01000000,
	AT_26 = 0x02000000,
	AT_27 = 0x04000000,
	AT_28 = 0x08000000,
	AT_29 = 0x10000000,
	AT_30 = 0x20000000,
	AT_31 = 0x40000000,
	AT_32 = 0x80000000
};
#ifndef ISXEQ

void ItemDisplayCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (szLine && szLine[0] == '\0') {
		WriteChatf("Usage: /itemdisplay LootButton optional:off/on");
		WriteChatf("Usage: /itemdisplay LucyButton optional:off/on");
		return;
	}

	CHAR szArg1[MAX_STRING] = { 0 };
	CHAR szArg2[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);
	bool bon = true;
	bool bToggle = true;
	if (szArg2 && szArg2[0] != '\0') {	
		if (!_stricmp(szArg2, "off")) {
			bToggle = false;
			bon = false;
		} else if (!_stricmp(szArg2, "on")) {
			bToggle = false;
		}
	}
	if (!_stricmp(szArg1, "LootButton")) {
		if (bToggle) {
			gLootButton = !gLootButton;
		}
		else {
			gLootButton = bon;
		}
		WriteChatf("Display of the %s is now \ay%s\ax.",szArg1, (gLootButton ? "Enabled" : "Disabled"));
		_itoa_s(gLootButton, szArg1, 10);
		WritePrivateProfileString("Settings","LootButton",szArg1,INIFileName);
		for (std::map<CButtonWnd*, ButtonInfo>::iterator i = ButtonMap.begin(); i != ButtonMap.end();) {
			if (i->second.ID == 1) {
				i->first->Destroy();
				std::map<CButtonWnd*, ButtonInfo>::iterator next = i;
				next++;
				ButtonMap.erase(i);
				i = next;
			}
			else {
				i++;
			}
		}
	} else if (!_stricmp(szArg1, "LucyButton")) {
		if (bToggle) {
			gLucyButton = !gLucyButton;
		}
		else {
			gLucyButton = bon;
		}
		WriteChatf("Display of the %s is now \ay%s\ax.",szArg1, (gLucyButton ? "Enabled" : "Disabled"));
		_itoa_s(gLucyButton, szArg1, 10);
		WritePrivateProfileString("Settings","LucyButton",szArg1,INIFileName);
		for (std::map<CButtonWnd*, ButtonInfo>::iterator i = ButtonMap.begin(); i != ButtonMap.end();) {
			if (i->second.ID == 2) {
				i->first->Destroy();
				std::map<CButtonWnd*, ButtonInfo>::iterator next = i;
				next++;
				ButtonMap.erase(i);
				i = next;
			}
			else {
				i++;
			}
		}
	}
	else if (!_stricmp(szArg1, "Compare")) {
		if (bToggle) {
			gCompareTip = !gCompareTip;
		}else {
			gCompareTip = bon;
		}
		WriteChatf("Display of Compare Tip is now \ay%s\ax.", (gCompareTip ? "Enabled" : "Disabled"));
		_itoa_s(gCompareTip, szArg1, 10);
		WritePrivateProfileString("Settings","CompareTip",szArg1,INIFileName);
	}
}

void RequestConvertItem(PSPAWNINFO pSpawn, PCHAR szLine)
{
#if defined(ROF2EMU) || defined(UFEMU)
	WriteChatf("This is not supported on EMUs");
#else
	if (szLine && szLine[0] != '\0')
	{
		GetArg(ConvertFrom, szLine, 1);
		//GetArg(ConvertTo, szLine, 3);
		if (PCONTENTS pCont = FindItemByName(ConvertFrom))
		{
			if (PITEMINFO pItem = GetItemFromContents(pCont))
			{
				//if (ConvertTo[0]) {
				//	WriteChatf("Trying to convert %s to %s", pItem->Name, ConvertTo);
				//}
				if (CItemDisplayManager*mgr = pItemDisplayManager) {
					int index = mgr->FindWindowA(true);
					if (index == -1) {
						index = mgr->CreateWindowInstance();
					}
					if (index > -1 && index < mgr->pWindows.Count) {
						if (PEQITEMWINDOW itemdis = (PEQITEMWINDOW)mgr->pWindows[index]) {
							CItemDisplayWnd*citemdisp = (CItemDisplayWnd*)itemdis;
							citemdisp->SetItem(&pCont, 0);
							citemdisp->RequestConvertItem();
						}
					}
				}
			}
			return;
		}
	}
	WriteChatf("\agUSAGE:\ax /convertitem \ay\"<item name>\"\ax");
	WriteChatf("\agEaxmple:\ax /convertitem \ay\"Wishing Lamp:\"\ax");
#endif
}
void AddLootFilter(PSPAWNINFO pChar, PCHAR szLine)
{
#if defined(ROF2EMU) || defined(UFEMU)
	WriteChatf("This is not supported on EMUs");
#else
	if (!pLootFiltersManager)
		return;
	if (szLine[0] == '\0') {
		WriteChatf("AddLootFilter Usage: /AddLootFilter <itemID> <ItemIconID> \"Item Name\"");
		return;
	}
	CHAR szArg1[MAX_STRING] = { 0 };
	CHAR szArg2[MAX_STRING] = { 0 };
	CHAR szArg3[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);
	GetArg(szArg3, szLine, 3);
	if (szArg1[0] == '\0' || szArg2[0] == '\0' || szArg3[0] == '\0') {
		WriteChatf("AddLootFilter Usage: /AddLootFilter <itemID> <ItemIconID> \"Item Name\"");
		return;
	}
	int itemid = atoi(szArg1);
	int itemicon = atoi(szArg2);
	pLootFiltersManager->AddItemLootFilter(itemid, itemicon, szArg3, 5);
	WriteChatf("Added %s to AG and Roll LootFilters.",szArg3);
#endif
}
void InsertAug(PSPAWNINFO pChar, PCHAR szLine)
{
#if !defined(UFEMU)//todo: check manually
	try {
		CHAR szArg1[MAX_STRING] = { 0 };
		CHAR szArg2[MAX_STRING] = { 0 };
		GetArg(szArg1, szLine, 1);
		GetArg(szArg2, szLine, 2);

		PCONTENTS pCont = 0;
		if (szArg1[0] != '\0' && IsNumber(szArg1)) {
			if (szArg2[0] == '\0') {
				//its an itemid...
				int iID = atoi(szArg1);
				pCont = FindItemByID(iID);
			} else {
				//it must be a slot then...
				int slot1 = atoi(szArg1);
				int slot2 = -1;
				if (szArg2[0] != '\0') {
					slot2 = atoi(szArg2);
				}
				pCont = FindItemBySlot(slot1, slot2);
			}
		} else if (szArg1[0] != '\0') {
			//its a itemname....
			pCont = FindItemByName(szArg1);
		}
		if (!pCont) {
			WriteChatColor("/insertaug USAGE: /insertaug \ay#######\ax where ####### is the itemid OR \ay\"Item Name in Quotes\"\ax OR \ay## ##\ax where ## ## are slotnumbers the item is in.", CONCOLOR_WHITE);
			WriteChatColor("Example1: /insertaug \ay41302\ax", CONCOLOR_WHITE);
			WriteChatColor("Example2: /insertaug \ay\"Darkened Thick Banded Belt\"\ax", CONCOLOR_WHITE);
			WriteChatColor("Example3: /insertaug \ay20 -1\ax", CONCOLOR_WHITE);
			return;
		}
		if (PCHARINFO2 pMe = GetCharInfo2()) {
			if (pMe->pInventoryArray) {
				if (PCONTENTS pCursor = pMe->pInventoryArray->Inventory.Cursor) {
					int Slot = 0;
					bool bFits = false;
					for (; Slot < 6; Slot++) {
						int fit = ((EQ_Item*)pCont)->GetAugmentFitBySlot(&pCursor, Slot);
						if (fit == 0) {
							bFits = true;
							break;
						}
					}
					/*int TheAugType = pCursor->Item2->AugType;
					int TheType1 = pCont->Item2->AugData.Sockets[0].Type;
					int TheType2 = pCont->Item2->AugData.Sockets[1].Type;
					int Check = (1 << (TheType1 - 1));
					if ((TheAugType & Check) == 0)
					{
						Sleep(0);
						//its a mismatch; 
					}*/
					if (bFits) {
						if (CItemDisplayManager*mgr = pItemDisplayManager) {
							int index = mgr->FindWindowA(true);
							if (index == -1) {
								index = mgr->CreateWindowInstance();
							}
							if (index > -1 && index < mgr->pWindows.Count) {
								if (PEQITEMWINDOW itemdis = (PEQITEMWINDOW)mgr->pWindows[index]) {
									CItemDisplayWnd*citemdisp = (CItemDisplayWnd*)itemdis;
									citemdisp->SetItem(&pCont, 0);
									if (PITEMINFO ptheAug = GetItemFromContents(pCursor)) {
										//hack to bypass popupdialog...
										int oldsolv = ptheAug->SolventItemID;
										bool oldattn = ptheAug->Attuneable;
										ptheAug->SolventItemID = 0;
										ptheAug->Attuneable = false;
										//now the actual function call...
										citemdisp->InsertAugmentRequest(Slot);
										//ok so lets restore the org values...
										ptheAug->SolventItemID = oldsolv;
										ptheAug->Attuneable = oldattn;
									}
									Sleep(0);
								}
							}
						}
					} else {
						if (PITEMINFO ptheAug = GetItemFromContents(pCursor)) {
							if (PITEMINFO ptheItem = GetItemFromContents(pCont)) {
								WriteChatf("\ayCould NOT insert the\ax \at%s\ax into the \ag%s\ax", ptheAug->Name, ptheItem->Name);
							}
						}
					}
				}
			}
		}
	}
	catch (...) {
		Sleep(0);
	}
#endif
}
void RemoveAug(PSPAWNINFO pChar, PCHAR szLine)
{
#if !defined(UFEMU)//todo: check manually
	try {
		if (PCHARINFO2 pMe = GetCharInfo2()) {
			if (pMe->pInventoryArray) {
				if (PCONTENTS pCursor = pMe->pInventoryArray->Inventory.Cursor) {
					if (PCHAR pError = pStringTable->getString(5478, NULL)) {
						WriteChatColor(pError, CONCOLOR_YELLOW);
					}
					return;

				}
			}
		}
		CHAR szArg1[MAX_STRING] = { 0 };
		CHAR szArg2[MAX_STRING] = { 0 };
		GetArg(szArg1, szLine, 1);
		GetArg(szArg2, szLine, 2);

		PCONTENTS pCont = 0;
		if (szArg2[0] != '\0' && IsNumber(szArg2)) {
			//its an id
			int iID = atoi(szArg2);
			pCont = FindItemByID(iID);
		} else if(szArg2[0] != '\0') {
			//its a name...
			pCont = FindItemByName(szArg2,true);
		}
		if (!pCont || szArg1[0] == '\0') {
			WriteChatColor("/removeaug USAGE: /removeaug \ay<augid>\ax <#####> OR \ay<augname>\ax \"Name in quotes\" \ay<itemid>\ax <#####> OR \ay<itemname>\ax \"Name in quotes\"", CONCOLOR_WHITE);
			WriteChatColor("NOTE! /removeaug \ayIS A CASE SENSITIVE FUNCTION\ax", CONCOLOR_WHITE);
			WriteChatColor("Example1: /removeaug \ay50502\ax \ay41302\ax", CONCOLOR_WHITE);
			WriteChatColor("Example2: /removeaug \ay\"Crude Defiant Ruby Shard\"\ax \"Darkened Thick Banded Belt\"", CONCOLOR_WHITE);
			WriteChatColor("Example2: /removeaug \ay\"Crude Defiant Ruby Shard\"\ax \ay41302\ax", CONCOLOR_WHITE);
			WriteChatColor("Example2: /removeaug \ay50502\ax \"Darkened Thick Banded Belt\"", CONCOLOR_WHITE);
			return;
		}
		int Slot = 0;
		bool bFound = false;
		int iID = 0;
		if (IsNumber(szArg1)) {
			//its an id
			iID = atoi(szArg1);
		}
		PITEMINFO ptheAug = 0;
		if (iID) {
			for (; Slot < 6; Slot++) {
				if (PCONTENTS pAug = pCont->GetContent(Slot)) {
					if (iID == pAug->ID) {
						if (ptheAug = GetItemFromContents(pAug)) {
							//found it...
							bFound = true;
							break;
						}
					}
				}
			}
		} else {
			for (; Slot < 6; Slot++) {
				if (PCONTENTS pAug = pCont->GetContent(Slot)) {
					if (ptheAug = GetItemFromContents(pAug)) {
						if (!_stricmp(ptheAug->Name, szArg1)) {
							bFound = true;
							break;
						}
					}
				}
			}
		}
		if (bFound) {
			if (CItemDisplayManager*mgr = pItemDisplayManager) {
				int index = mgr->FindWindowA(true);
				if (index == -1) {
					index = mgr->CreateWindowInstance();
				}
				if (index > -1 && index < mgr->pWindows.Count) {
					if (PEQITEMWINDOW itemdis = (PEQITEMWINDOW)mgr->pWindows[index]) {
						CItemDisplayWnd*citemdisp = (CItemDisplayWnd*)itemdis;
						citemdisp->SetItem(&pCont, 0);
						if (ptheAug) {
							ItemIndex ii = { 0 };
							PCONTENTS contout = 0;
							PCONTENTS *pContsolv = 0;
							int realID = 0;
							//we need to check for all distillers
							#if !defined(ROF2EMU) && !defined(UFEMU)
							int minreqid = ptheAug->SolventItemID;
							if (pDistillerInfo)
							{
								for (int i = minreqid; i <= 21; i++)
								{
									realID = pDistillerInfo->GetIDFromRecordNum(i, 0);
									pContsolv = ((PcZoneClient*)pPCData)->GetItemByID(&contout, realID, &ii);
									if (contout) {
										//found a distiller that will work...
										break;
									}
								}
							}
							#else
								pContsolv = ((PcZoneClient*)pPCData)->GetItemByID(&contout, ptheAug->SolventItemID, &ii);
							#endif
							if (!contout) {
								pContsolv = ((PcZoneClient*)pPCData)->GetItemByItemClass(&contout, 64/*Universal Augment Solvent... aka perfect distiller...*/, &ii);
							}
							if (contout) {
								//we shouldnt do the solvent thing for removals, people who macro this can click the ok button on the confirmation window...
								citemdisp->RemoveAugmentRequest(Slot);
							} else {
								if (PCHAR pError = pStringTable->getString(5474, NULL)) {
									WriteChatColor(pError, CONCOLOR_YELLOW);
								}
								return;
							}
						}
					}
				}
			}
		} else {
			if (ptheAug) {
				if (PITEMINFO ptheItem = GetItemFromContents(pCont)) {
					WriteChatf("\ayCould NOT remove the\ax \at%s\ax from the \ag%s\ax", ptheAug->Name, ptheItem->Name);
				}
			}
		}
	}
	catch (...) {
		Sleep(0);
	}
#endif
}
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
        strcat_s(Comment,szTemp); 
        strcat_s(Comment," "); 
        GetArg(szTemp,szLine,i); 
    } 
    int itemno = atoi(ItemNo); 

    if (_stricmp(Arg,"add") && _stricmp(Arg,"del")) 
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
        sprintf_s(szTemp,"%07d",itemno); 
        WritePrivateProfileString("Notes",szTemp,"",INIFileName); 
        return; 
    } 

    if (!_stricmp(Arg,"add")) 
    { 
        sprintf_s(szTemp,"%07d",itemno); 
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
		sprintf_s(szVal,"%0.2f", AttribList[i].Weight);
		WritePrivateProfileString(Section,AttribList[i].Name,szVal,INIFileName);
	}
}

int  SetAttribListWeight(char *Key, char *Val)
{
	int i;
	for (i=0; i<=AttribMax; i++)
	{
		if (_stricmp(AttribList[i].Name,Key)==0) 
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
#if !defined(ROF2EMU) && !defined(UFEMU)
   AttribList[16].Val = 0;//FIX THIS cvtfloat(pItem->Accuracy);
   AttribList[17].Val = 0;//FIX THIS cvtfloat(pItem->CombatEffects);
   AttribList[18].Val = 0;//FIX THIS cvtfloat(pItem->StrikeThrough);
   AttribList[19].Val = 0;//FIX THIS cvtfloat(pItem->Avoidance);
   AttribList[20].Val = 0;//FIX THIS cvtfloat(pItem->Shielding);
   AttribList[21].Val = 0;//FIX THIS cvtfloat(pItem->DoTShielding);
   AttribList[22].Val = 0;//FIX THIS cvtfloat(pItem->SpellShield);
   AttribList[23].Val = 0;//FIX THIS cvtfloat(pItem->StunResist);
   AttribList[24].Val = 0;//FIX THIS cvtfloat(pItem->DamageShieldMitigation);
#else
   AttribList[16].Val = cvtfloat(pItem->Accuracy);
   AttribList[17].Val = cvtfloat(pItem->CombatEffects);
   AttribList[18].Val = cvtfloat(pItem->StrikeThrough);
   AttribList[19].Val = cvtfloat(pItem->Avoidance);
   AttribList[20].Val = cvtfloat(pItem->Shielding);
   AttribList[21].Val = cvtfloat(pItem->DoTShielding);
   AttribList[22].Val = cvtfloat(pItem->SpellShield);
   AttribList[23].Val = cvtfloat(pItem->StunResist);
   AttribList[24].Val = cvtfloat(pItem->DamageShieldMitigation);
#endif
   AttribList[25].Val = cvtfloat(pItem->Haste);
   AttribList[26].Val =      CalcRatio(pItem);
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
	sprintf_s(ReportChannel,"None");
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
	sprintf_s(szKey,"%d",ClickGroup);	WritePrivateProfileString(pName,"ClickGroup" ,szKey		,INIFileName); 
	sprintf_s(szKey,"%d",ClickGuild);	WritePrivateProfileString(pName,"ClickGuild" ,szKey		,INIFileName); 
	sprintf_s(szKey,"%d",ClickRaid);	WritePrivateProfileString(pName,"ClickRaid"	 ,szKey		,INIFileName); 
	sprintf_s(szKey,"%d",ClickAny);	WritePrivateProfileString(pName,"ClickAny"	 ,szKey  	,INIFileName); 
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
	strcpy_s(ReportChannel,Val);
	EchoProfile(TRUE,FALSE,FALSE);
}

void SetClickMode(char *pName, char *Val)
{
	if (_stricmp(Val,"Group")==0) ClickGroup=!ClickGroup;
	if (_stricmp(Val,"Guild")==0) ClickGuild=!ClickGuild;
	if (_stricmp(Val,"Raid" )==0) ClickRaid=!ClickRaid;
	if (_stricmp(Val,"Any"  )==0) ClickAny=!ClickAny;
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

	if (_stricmp(Key,"save"		)==0)	{	WriteProfile(pName,TRUE);	return; }
	if (_stricmp(Key,"load"		)==0)	{	ReadProfile(pName,TRUE);	return; }
	if (_stricmp(Key,"report"	)==0)   {	SetReportChannel(pName,Val);return;	}
	if (_stricmp(Key,"click"		)==0)	{	SetClickMode(pName,Val);	return;	}
	if (_stricmp(Key,"cursor"	)==0)   {	DoScoreForCursor();			return;	}
	if (_stricmp(Key,"clear"		)==0)	{	ClearProfile(TRUE);			return;	}
	if (_stricmp(Key,"help"		)==0)	{	EchoHelp(TRUE);				return;	}
	if (Key[0] == 0					)	{	EchoCommands(TRUE);			return;	}
	SetAttribListWeight(Key,Val);
}


void DoScoreForCursor(void)
{
	if (PCHARINFO2 pChar2 = GetCharInfo2()) {
		if (pChar2->pInventoryArray) {
			if (PCONTENTS pCursorContents = pChar2->pInventoryArray->Inventory.Cursor) {
				if (PITEMINFO pCursorItem = GetItemFromContents(pCursorContents)) {
					char Temp[MAX_STRING];
					AddGearScores(pCursorContents, pCursorItem, Temp, "\n");
					WriteChatf("MQ2ItemDisplay::Cursor item %s", pCursorItem->Name);
					WriteChatf("%s", Temp);
				}
			}
		}
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
		bool MQ2GearScoreType::GETMEMBER() { 
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
			strcpy_s(Destination,MAX_STRING,"TRUE");
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

template <unsigned int _Size> void AddGearScore_CheckAugSlot(ITEMINFO *pItem,float score,int SlotNum,char *SlotName,PCONTENTS pInvContent,ITEMINFO *pInvItem,DWORD AugType,DWORD AugSlot, CHAR(&out)[_Size],char *br)
{
	if (!AugType) return;							// This worn item does not have an aug slot for [n]
	DWORD mask = (1<<(AugType-1));
	if ((mask & pItem->AugType) == 0) return ;		// Calculate a bitmask and compare to the aug we have, does it fit?

	char  temp[MAX_STRING];
	ITEMINFO *pAug = NULL;
	if (pInvContent && pInvContent->Contents.ContainedItems.pItems && pInvContent->Contents.ContainedItems.pItems->Item[AugSlot])
		pAug = GetItemFromContents(pInvContent->Contents.ContainedItems.pItems->Item[AugSlot]);

	if (!pAug) {
		ClearAttribListVal();
		CheckForBest(0,SlotNum);
		sprintf_s(temp,"%s = empty : UPGRADE%s",SlotName,br);
		strcat_s(out,temp);
		return;
	}
	if (pItem->ItemNumber == pInvItem->ItemNumber)
		return;

	float s2 = CalcItemGearScore(pAug);
	CheckForBest(s2,SlotNum);

	sprintf_s(temp,"%s = %s : %6.0f %s %s",SlotName,pAug->Name,s2,(s2>=score?"Keep ":"UPGRADE"),br);
	strcat_s(out,temp);
}

template <unsigned int _Size> void AddGearScores_CheckAugs(PCONTENTS pSlot,ITEMINFO *pItem, CHAR(&out)[_Size],char *br)
{
	float score = CalcItemGearScore(pItem);
	if (!score) return;

	char temp[MAX_STRING];

	sprintf_s(temp,"Base Aug Score : %6.0f%s",score,br);
	strcat_s(out,temp);

	char *name;
	int i;
	DWORD mask;
	if (PCHARINFO2 pChar2 = GetCharInfo2()) {
		if (pChar2->pInventoryArray) {
			PITEMINFO pInvItem;
			PCONTENTS pInvContent;
			float bestVal = score;

			// Loop over all the worn items
			for (i = 0; i < BAG_SLOT_START - 1; i++)
			{
				mask = SlotInfo[i].SlotMask;
				name = SlotInfo[i].SlotName;
				pInvItem = NULL;
				pInvContent = pChar2->pInventoryArray->InventoryArray[i];
				if (pInvContent)
					pInvItem = GetItemFromContents(pInvContent);
				if (pInvItem && (pItem->EquipSlots & mask) == mask)
				{
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[0].Type, 0, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[1].Type, 1, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[2].Type, 2, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[3].Type, 3, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[4].Type, 4, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[5].Type, 5, out, br);
				}
			}
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
	if (PCHARINFO2 pChar2 = GetCharInfo2()) {
		if (pChar2->pInventoryArray) {
			// Normal Inventory worn slots
			for (iSlot = 0; iSlot < NUM_INV_SLOTS; iSlot++)
			{
				if (PCONTENTS pItem = pChar2->pInventoryArray->InventoryArray[iSlot])
				{
					if (GetItemFromContents(pItem)->ItemNumber == ID)
					{
						if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
							(((EQ_Item*)pItem)->IsStackable() != 1))
						{
							nHowMany++;
						}
						else
						{
							nHowMany += pItem->StackCount;
						}
					}
					else // for augs
					{
						if (pItem->Contents.ContainedItems.pItems && pItem->Contents.ContainedItems.Size)
							for (nAug = 0; nAug < pItem->Contents.ContainedItems.Size; nAug++)
							{
								if (pItem->Contents.ContainedItems.pItems->Item[nAug] && GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->Type == ITEMTYPE_NORMAL && GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->AugType &&
									GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->ItemNumber == ID)
									nHowMany++;
							}
					}
				}
			}
			// Bags
			for (nPack = 0; nPack < 10; nPack++)
			{
				if (PCONTENTS pPack = pChar2->pInventoryArray->Inventory.Pack[nPack])
				{
					if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->Contents.ContainedItems.pItems)
					{
						for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
						{
							if (PCONTENTS pItem = pPack->Contents.ContainedItems.pItems->Item[nItem])
							{
								if (GetItemFromContents(pItem)->ItemNumber == ID)
								{
									if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
										(((EQ_Item*)pItem)->IsStackable() != 1))
									{
										nHowMany++;
									}
									else
									{
										nHowMany += pItem->StackCount;
									}
								}
								else // for augs
								{
									if (pItem->Contents.ContainedItems.pItems && pItem->Contents.ContainedItems.Size)
										for (nAug = 0; nAug < pItem->Contents.ContainedItems.Size; nAug++)
										{
											if (pItem->Contents.ContainedItems.pItems->Item[nAug] && GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->Type == ITEMTYPE_NORMAL && GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->AugType &&
												GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->ItemNumber == ID)
												nHowMany++;
										}
								}
							}
						}
					}
				}
			}



			// Bank slots, not including shared
			for (nPack = 0; nPack < NUM_BANK_SLOTS; nPack++)
			{
				PCHARINFO pCharInfo = GetCharInfo();
				PCONTENTS pPack = NULL;
#ifdef NEWCHARINFO
				if (pCharInfo && pCharInfo->BankItems.Items.Size > nPack)
					pPack = pCharInfo->BankItems.Items[nPack].pObject;
#else
				if (pCharInfo && pCharInfo->pBankArray)
					pPack = pCharInfo->pBankArray->Bank[nPack];
#endif
				if (pPack)
				{
					if (GetItemFromContents(pPack)->ItemNumber == ID)
					{
						if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL) ||
							(((EQ_Item*)pPack)->IsStackable() != 1))
							nHowMany++;
						else
							nHowMany += pPack->StackCount;
					}
					if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->Contents.ContainedItems.pItems)
					{
						for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
						{
							if (PCONTENTS pItem = pPack->Contents.ContainedItems.pItems->Item[nItem])
							{
								if (GetItemFromContents(pItem)->ItemNumber == ID)
								{
									if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
										(((EQ_Item*)pItem)->IsStackable() != 1))
										nHowMany++;
									else
										nHowMany += pItem->StackCount;
								}
							}
						}
					}
				}
			}

			for (nPack = 0; nPack < NUM_SHAREDBANK_SLOTS; nPack++)
			{
				PCHARINFO pCharInfo = GetCharInfo();
				PCONTENTS pPack = NULL;
#ifdef NEWCHARINFO
				if (pCharInfo && pCharInfo->SharedBankItems.Items.Size > nPack)
					pPack = pCharInfo->SharedBankItems.Items[nPack].pObject;
#else
				if (pCharInfo && pCharInfo->pSharedBankArray)
					pPack = pCharInfo->pSharedBankArray->SharedBank[nPack];
#endif
				if (pPack)
				{
					if (GetItemFromContents(pPack)->ItemNumber == ID)
					{
						if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL) ||
							(((EQ_Item*)pPack)->IsStackable() != 1))
							nHowMany++;
						else
							nHowMany += pPack->StackCount;
					}
					if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->Contents.ContainedItems.pItems)
					{
						for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
						{
							if (PCONTENTS pItem = pPack->Contents.ContainedItems.pItems->Item[nItem])
							{
								if (GetItemFromContents(pItem)->ItemNumber == ID)
								{
									if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) ||
										(((EQ_Item*)pItem)->IsStackable() != 1))
										nHowMany++;
									else
										nHowMany += pItem->StackCount;
								}
							}
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
			//sprintf_s(szVerb,"MOVE [ %s ] To ",pItem->Name);
		if (CurrSlot<65500)
			sprintf_s(szVerb,"WEAR [ %s ] As ",pItem->Name);
		else
			sprintf_s(szVerb,"LOOT [ %s ] For ",pItem->Name);

		if (pItem->Lore && DoIHave(pItem)) 
			sprintf_s(szVerb,"WEAR [ %s ] As ",pItem->Name);
		
		sprintf_s(ReportBestStr,"%s %s = %+6.1f%%",szVerb,pSlotName,v);

		strcpy_s(ReportBestSlot,pSlotName);
		strcpy_s(ReportBestName,pItem->Name);

		CalcItemGearScore(pItem);

		int i;
		char szTmp[MAX_STRING];
		szTmp[0] = 0;
		strcat_s(ReportBestStr," =");
		for (i=0; i<=AttribMax; i++)
		{
			if (AttribList[i].Weight!=0 && (AttribList[i].Val != AttribList[i].Best))
			{
				sprintf_s(szTmp," %s %+0.0f",AttribList[i].Name, AttribList[i].Val-AttribList[i].Best);
				strcat_s(ReportBestStr,szTmp);
			}
		}		
	}
	//WriteChatf("MQ2ItemDisplay::%s",ReportBestStr);
}

template <unsigned int _Size> void AddGearScores_CheckItems(PCONTENTS pSlot,ITEMINFO *pItem, CHAR(&out)[_Size],char *br)
{
	char  temp[MAX_STRING];
	DWORD mask;
	float score;
	int i;

	sprintf_s(temp,"This Item Score : %6.0f%s",CurrScore,br);
	strcat_s(out,temp);

	if (PCHARINFO2 pChar2 = GetCharInfo2()) {
		if (pChar2->pInventoryArray) {
			for (i = 0; i < BAG_SLOT_START - 1; i++)
			{
				mask = SlotInfo[i].SlotMask;
				if ((pItem->EquipSlots & mask) == mask)
				{
					score = 0;
					ClearAttribListVal();
					PCONTENTS pInvSlot = pChar2->pInventoryArray->InventoryArray[i];
					if (pInvSlot)
					{
						PITEMINFO pItemInfo = GetItemFromContents(pInvSlot);
						score = CalcItemGearScore(pItemInfo);
						if (pItemInfo && pItemInfo->ItemNumber != pItem->ItemNumber)
						{
							sprintf_s(temp, "Worn Item Score : %6.0f (%s%s) %s", score, (score - CurrScore>0 ? "Keep " : "UPGRADE for "), SlotInfo[i].SlotName, br);
							strcat_s(out, temp);
						}
					}
					CheckForBest(score, i);
				}
			}
		}
	}
}

template <unsigned int _Size> void AddGearScores(PCONTENTS pSlot,PITEMINFO pItem, CHAR(&out)[_Size],char *br)
{
	static ULONGLONG lastTick = 0;
	ReportBestStr[0] = 0;
	ReportBestSlot[0] = 0;
	ReportBestName[0] = 0;
	if (CanIUseThisItem(pItem)<1)
		return;

	ClearAttribListScores();
	CurrScore = CalcItemGearScore(pItem);
	if (CurrScore == 0) return;

	CurrSlot = pSlot->GetGlobalIndex().Index.Slot1;
	BestScore=CurrScore;
	BestSlot =0;
	if (pItem->ItemType == ITEMITEMTYPE_AUGUMENT)
		AddGearScores_CheckAugs(pSlot,pItem,out,br);
	else
		AddGearScores_CheckItems(pSlot,pItem,out,br);

	FormatBestStr(pItem);
	if (BestScore<CurrScore && ReportBestStr[0]!=0)
	{
		strcat_s(out,ReportBestStr);
		strcat_s(out,br);
	}
	// Trap the 3x call back stuff. 
	if (MQGetTickCount64()-lastTick > 1000 && ReportBestStr[0]!=0 && ReportChannel[0] == '/')
	{
		char szCmd[MAX_STRING];
		lastTick = MQGetTickCount64();
		sprintf_s(szCmd,"%s %s",ReportChannel,ReportBestStr);
		EzCommand(szCmd);
		//WriteChatf("AddGearScores::Reporting Cmd = %s",szCmd);
	}
}

VOID DestroyCompareTipWnd() 
{ 
    if (pCompareTipWnd) 
    { 
		//SaveWindowSettings((PCSIDLWND)pCompareTipWnd);
        delete pCompareTipWnd; 
        pCompareTipWnd=0;  
    } 
}

void CreateCompareTipWnd()
{
	try {
		if (pCompareTipWnd || bDisabledComparetip) {
			return; 
		}
		HMODULE hMe = 0;
		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)CreateCompareTipWnd, &hMe);
		void* pMyBinaryData = 0;
		CHAR szEQPath[MAX_PATH] = { "C:\\Users\\Public\\Daybreak Game Company\\Installed Games\\EverQuest\\eqgame.exe" };
		CHAR szMQUI_CompareTipWndPath[MAX_PATH] = { 0 };
		GetModuleFileName(NULL, szEQPath, MAX_PATH);
		if (char *pDest = strstr(szEQPath,"eqgame.exe"))
		{
			pDest[0] = '\0';
			strcpy_s(szMQUI_CompareTipWndPath, szEQPath);
			strcat_s(szMQUI_CompareTipWndPath, "UIFiles\\Default\\MQUI_CompareTipWnd.xml");
		}
		WIN32_FIND_DATA FindFile = { 0 };
		HANDLE hSearch = FindFirstFile(szMQUI_CompareTipWndPath, &FindFile);
		if (hSearch != INVALID_HANDLE_VALUE) {
			FindClose(hSearch);
			if (pSidlMgr && pSidlMgr->FindScreenPieceTemplate("CompareTipWnd")) {
				if (pCompareTipWnd = new CCompareTipWnd("CompareTipWnd")) {
					Sleep(0);
					//LoadWindowSettings((PCSIDLWND)pCompareTipWnd);
				}
			}
			else
			{
				bDisabledComparetip = true;
				WriteChatf("Could not find CompareTipWnd\nPlease do /loadskin default");
			}
		}
		else {
			bDisabledComparetip = true;
			MessageBox(NULL, "MQUI_CompareTipWnd.xml not Found in UIFiles\\default\nI will disable this feature for now.\nYou can retry again by /plugin mq2itemdisplay unload and then /plugin mq2itemdisplay", "MQ2ItemDisplay", MB_OK | MB_SYSTEMMODAL);
		}
	} 
	catch(...) { 
		MessageBox(NULL,"CRAP! in CreateCompareTipWnd","An exception occured",MB_OK);
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
	pGearScoreType = new MQ2GearScoreType;
	gLootButton = 1==GetPrivateProfileInt("Settings","LootButton",1,INIFileName);
	gLucyButton = 1==GetPrivateProfileInt("Settings","LucyButton",1,INIFileName);
	gCompareTip = 1==GetPrivateProfileInt("Settings","CompareTip",0,INIFileName);

	#if !defined(ROF2EMU) && !defined(UFEMU)
	EzDetourwName(CItemDisplayWnd__WndNotification,&ItemDisplayHook::WndNotification_Detour,&ItemDisplayHook::WndNotification_Trampoline,"CItemDisplayWnd__WndNotification");
	EzDetourwName(CItemDisplayWnd__AboutToShow,&ItemDisplayHook::AboutToShow_Detour,&ItemDisplayHook::AboutToShow_Trampoline,"CItemDisplayWnd__AboutToShow");
	#endif
	EzDetourwName(CItemDisplayWnd__SetSpell,&ItemDisplayHook::SetSpell_Detour,&ItemDisplayHook::SetSpell_Trampoline,"CItemDisplayWnd__SetSpell");
    EzDetourwName(CItemDisplayWnd__UpdateStrings, &ItemDisplayHook::UpdateStrings_Detour, &ItemDisplayHook::UpdateStrings_Trampoline,"CItemDisplayWnd__UpdateStrings");

	
    AddCommand("/itemdisplay",ItemDisplayCmd); 
    AddCommand("/convertitem",RequestConvertItem); 
    AddCommand("/addlootfilter",AddLootFilter); 
    AddCommand("/insertaug",InsertAug); 
    AddCommand("/removeaug",RemoveAug); 
    AddCommand("/inote",Comment); 
    AddCommand("/ireset",Ireset); 
    AddCommand("/iScore" ,DoGearScoreUserCommand); 
	AddCommand("/GearScore" ,DoGearScoreUserCommand); 
	pDisplayItemType = new MQ2DisplayItemType;
    AddMQ2Data("DisplayItem", dataLastItem);
	AddMQ2Data("GearScore",dataGearScore);
	//MessageBox(NULL, "inject", "", MB_SYSTEMMODAL | MB_OK);
	HMODULE hMe = 0;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)InitializePlugin, &hMe);
	void* pMyBinaryData = 0;
	CHAR szEQPath[2048] = { "C:\\Users\\Public\\Daybreak Game Company\\Installed Games\\EverQuest\\eqgame.exe" };
	CHAR szMQUI_CompareTipWndPath[2048] = { 0 };
	GetModuleFileName(NULL, szEQPath, 2048);
	if (char *pDest = strstr(szEQPath,"eqgame.exe"))
	{
		pDest[0] = '\0';
		strcpy_s(szMQUI_CompareTipWndPath, szEQPath);
		strcat_s(szMQUI_CompareTipWndPath, "UIFiles\\Default\\MQUI_CompareTipWnd.xml");
	}
	WIN32_FIND_DATA FindFile = { 0 };
	HANDLE hSearch = FindFirstFile(szMQUI_CompareTipWndPath, &FindFile);
	if (hSearch == INVALID_HANDLE_VALUE) {
		//need to unpack our resource.
		if (HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_XML1), "XML")) {
			if (HGLOBAL bin = LoadResource(hMe, hRes)) {
				BOOL bResult = 0;
				if (pMyBinaryData = LockResource(bin)) {
					//save it...
					DWORD ressize = SizeofResource(hMe, hRes);
					FILE *File = 0;
					errno_t err = fopen_s(&File, szMQUI_CompareTipWndPath, "wb");
					if (!err) {
						fwrite(pMyBinaryData, ressize, 1, File);
						fclose(File);
					}
					bResult = UnlockResource(hRes);
				}
				bResult = FreeResource(hRes);
			}
		}
	} else {
		FindClose(hSearch);
	}
	AddXMLFile("MQUI_CompareTipWnd.xml");
    EzDetourwName(CInvSlotWnd__DrawTooltip, &ItemDisplayHook::CInvSlotWnd_DrawTooltipDetour, &ItemDisplayHook::CInvSlotWnd_DrawTooltipTramp,"CInvSlotWnd__DrawTooltip");

	if (gGameState == GAMESTATE_INGAME)
	{
		ReadProfile(GetCharInfo()->Name, FALSE);
		CreateCompareTipWnd();
	}
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
	RemoveDetour(CInvSlotWnd__DrawTooltip);
    RemoveDetour(CItemDisplayWnd__SetSpell);
    RemoveDetour(CItemDisplayWnd__UpdateStrings);
#if !defined(ROF2EMU) && !defined(UFEMU)
	RemoveDetour(CItemDisplayWnd__AboutToShow);
	RemoveDetour(CItemDisplayWnd__WndNotification);
	for (std::map<CButtonWnd*, ButtonInfo>::iterator i = ButtonMap.begin(); i != ButtonMap.end(); i++) {
		i->first->Destroy();
	}
	ButtonMap.clear();
#endif
	delete pGearScoreType;
	pGearScoreType = 0;
	
    RemoveMQ2Data("InsertAug");
    RemoveMQ2Data("RemoveAug");
    RemoveMQ2Data("DisplayItem");
	RemoveMQ2Data("GearScore");
    RemoveCommand("/ireset"); 
    RemoveCommand("/inote");
	RemoveCommand("/iScore");
	RemoveCommand("/GearScore");
	RemoveCommand("/addlootfilter");
	RemoveCommand("/convertitem");
	RemoveCommand("/itemdisplay");
	
	delete pDisplayItemType;
	if (hDisplayItemLock) {
		ReleaseMutex(hDisplayItemLock);
		CloseHandle(hDisplayItemLock);
		hDisplayItemLock = 0;
	}
	DestroyCompareTipWnd();
}
PLUGIN_API void OnCleanUI()
{
#if !defined(ROF2EMU) && !defined(UFEMU)
	for (std::map<CButtonWnd*, ButtonInfo>::iterator i = ButtonMap.begin(); i != ButtonMap.end(); i++) {
		i->first->Destroy();
	}
	ButtonMap.clear();
#endif
	DestroyCompareTipWnd();
}

PLUGIN_API void OnReloadUI()
{
#if !defined(ROF2EMU) && !defined(UFEMU)
	for (std::map<CButtonWnd*, ButtonInfo>::iterator i = ButtonMap.begin(); i != ButtonMap.end(); i++) {
		i->first->Destroy();
	}
	ButtonMap.clear();
#endif
	if (GetGameState() == GAMESTATE_INGAME && pCharSpawn) {
		bDisabledComparetip = false;
		CreateCompareTipWnd();
	}
}
#if !defined(ROF2EMU) && !defined(UFEMU)
// starting position of link text found in MQ2Web__ParseItemLink_x
#define LINK_LEN 0x5A
#else
#define LINK_LEN 0x37
#endif

PLUGIN_API DWORD OnIncomingChat(PCHAR Line, DWORD Color) 
{
	if (ClickGroup || ClickGuild || ClickRaid || ClickAny) 
	{
		char *szStart = new char[MAX_STRING];
		sprintf_s(szStart,MAX_STRING,"%c%c",0x12,0x30);
		char *p = strstr(Line,szStart);
		delete szStart;
		if (!p) {
			return 0;
		}
		int  doLink = 0;	

		if (ClickAny) doLink = 1;
		if (!doLink && ClickGroup && ( strstr(Line,"tells the group") || strstr(Line,"tell your party"))) doLink = 1;
		if (!doLink && ClickGuild && ( strstr(Line,"tells the guild") || strstr(Line,"to your guild")  )) doLink = 1;
		if (!doLink && ClickRaid  && ( strstr(Line,"tells the raid")  || strstr(Line,"tell your raid") )) doLink = 1;

		if (doLink && p && strlen(p)>LINK_LEN+2)
		{
			char *szText = new char[MAX_STRING];
			memset(szText,0,100);
			strncpy_s(szText,MAX_STRING,p+2,LINK_LEN);
			char *szCommand = new char[MAX_STRING];
			sprintf_s(szCommand,MAX_STRING, "/notify ChatWindow CW_ChatOutput link %s", szText);
			delete szText;
			DoCommand(((PSPAWNINFO)pLocalPlayer), szCommand);
			delete szCommand;
		}
	}
    return 0; 
}
PLUGIN_API VOID OnPulse(VOID)
{
	if (GetGameState() == GAMESTATE_INGAME)
	{
		CreateCompareTipWnd();
	}
}
PLUGIN_API VOID OnBeginZone(VOID)
{
	memset(&g_Contents, 0x0, sizeof(CONTENTS)*6);
}
#endif
