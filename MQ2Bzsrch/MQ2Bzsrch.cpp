/*****************************************************************************
mq2bzsrch.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2003-2004 DKAA

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/

//
// MQ2Bzsrch.cpp : Bazaar Seach Plugin by DKAA
//
//
// Original MQ2Data update by CyberCide... but it didn't work like the rest of
//  MQ2Data so Lax redid it.
//

#include "../MQ2Plugin.h"

struct _BazaarSearchRequestPacket {
   /* 0x0 */   int     BSRCommand;     // should be 7
   /* 0x4 */   int     BSRTraderID;    // default 0
   /* 0x8 */   int     BSRClass;       // default -1
   /* 0xc */   int     BSRRace;        // default -1
   /* 0x10 */  int     BSRStat;        // default -1
   /* 0x14 */  int     BSRSlot;        // default -1
   /* 0x18 */  int     BSRType;        // default -1
   /* 0x1c */  char    BSRName[64];    // name
   /* 0x5c */  int     BSRPriceL;      // price floor, default 0
   /* 0x60 */  int     BSRPriceH;      // price ceiling, default 0
};

struct _BazaarSearchResponsePacket {
   /* 0x0 */   int     BSSmsg;         // should be 7
   /* 0x4 */   int     BSSQuantity;   
   /* 0x8 */   int     BSSItemID;       
   /* 0xc */   int     BSSTraderID;
   /* 0x10 */  int     BSSPrice;
   /* 0x14 */  int     BSSValue;       // double check
   /* 0x18 */  char    BSSName[0x40];  // size is 0x58
};


struct _classes {
   char *name;
   int classn;
} classes[] = {
   "any", -1,
      "bard", 8,
      "beastlord", 15,
      "berserkers", 16,
      "cleric", 2,
      "druid", 6,
      "enchanter", 14,
      "magician", 13,
      "monk", 7,
      "necromancer", 11,
      "paladin", 3,
      "ranger", 4,
      "rogue", 9,
      "shadow knight", 5,
      "shaman", 10,
      "warrior", 1,
      "wizard", 12,
};

struct _races {
   char *name;
   int race;
} races[] = {
   "any", -1,
      "barbarian", 2,
      "dark elf",6,
      "dwarf", 8,
      "erudite", 3,
      "froglok", 15,
      "gnome", 12,
      "half elf", 7,
      "halfling", 11,
      "high elf", 5,
      "human", 1,
      "iksar", 13,
      "ogre", 10,
      "troll", 9,
      "vah shir", 14,
      "wood elf", 4,
};

struct _stats {
   char *name;
   int stat;
} stats[] = {
   "any", -1,
      "armor class", 14,
      "agility", 2,
      "charisma", 6,
      "dexterity", 3,
      "intelligence", 4,
      "stamina", 1,
      "strength", 0,
      "wisdom", 5,
      "vs cold", 8,
      "vs disease", 11,
      "vs fire", 9,
      "vs magic", 7,
      "vs poison", 10,
      "hit points", 13,
      "mana", 12,
};

struct _slots {
   char *name;
   int slot;
} slots[] = {
   "any", -1,
      "ammo", 21,
      "arms", 7,
      "back", 8,
      "charm", 0,
      "chest", 17, // not 11
      "ear", 1,
      "face", 3,
      "feet", 19,
      "fingers", 15,
      "hands", 12,
      "head", 2,
      "legs", 18,
      "neck", 5,
      "primary", 13,
      "range", 11,
      "secondary", 14,
      "shoulders", 6,
      "waist", 20,
      "wrist", 9,
};

struct _types {
   char *name;
   int type;
} types[] = {
   "any", -1,
      "1h slashing", 0,
      "1h blunt", 3,
      "2h blunt", 4,
      "2h slashing", 1,
      "2h piercing", 35,
      "alcohol", 38,
      "all effects", 46,
      "armor", 10,
      "arrow", 27,
      "bandages", 18,
      "book", 31,
      "bow", 5,
      "brass instrument", 25,
      "combinable", 17,
      "drink", 15,
      "flowing thought", 48,
      "focus effect", 49,
      "food", 14,
      "haste", 47,
      "jewelry", 29,
      "key", 33,
      "light", 16,
      "martial", 45,
      "misc", 11,
      "note", 32,
      "percussion instrument", 26,
      "piercing", 2,
      "potion", 21,
      "scroll", 20,
      "shield", 8,
      "stringed instrument", 24,
      "throwing", 19,
      "wind instrument", 23,
};

DWORD BzCount = 0;
DWORD BzDone = 0;
struct _BazaarSearchResponsePacket BzArray[200];

PreSetup("MQ2Bzsrch");

void BzSrchMe(PSPAWNINFO pChar, PCHAR szLine);
void MQ2BzSrch(PSPAWNINFO pChar, PCHAR szLine);
DWORD parmBazaar(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar);
BOOL dataBazaar(PCHAR szName, MQ2TYPEVAR &Ret);
// we need to specify a class because we are hooking a class member
// function.  This should preserve ecx (*this).   We don't ever
// instanstiate this class, so we don't need constructors.
class BzSrchHook
{
public:
   void BzTrampoline(char *itemarray,int count);

   // count is byte count
   // msg must be 7 on the first item or it is not
   // an item list but a request to resort the list
   void BzDetour(char *itemarray,int count)
   {
      struct _BazaarSearchResponsePacket *ptr = (struct _BazaarSearchResponsePacket *) itemarray;

      DebugSpewAlways("count = %d\n", count);

      // future: copy these to a list that we keep here for so that
      // they may be retrieved with a $bazaar parm
      if (ptr->BSSmsg == 7) {
#if 0
         for(int i=0;(i<5) && (i<(int)(count/sizeof(struct _BazaarSearchResponsePacket)));i++, ptr++)
            DebugSpewAlways("item %d: %s msg %d n %d, itemid %d, value %d", i,
            ptr->BSSName,
            ptr->BSSmsg,
            ptr->BSSQuantity,
            ptr->BSSItemID,
            ptr->BSSValue);
#endif
         BzCount = count/sizeof(struct _BazaarSearchResponsePacket);
         memcpy(BzArray, ptr, count);
      } else {
         // this is an end of list packet but there is only 200
         // suppored now, it comes in one packet.
         BzDone = TRUE;
      }

      BzTrampoline(itemarray, count);
   };
};

DETOUR_TRAMPOLINE_EMPTY(VOID BzSrchHook::BzTrampoline(char *,int));

class MQ2BazaarType *pBazaarType=0;
class MQ2BazaarItemType *pBazaarItemType=0;


class MQ2BazaarItemType : public MQ2Type
{
public:
	enum BazaarItemMembers
	{
		Price=1,
		Quantity=2,
		ItemID=3,
		Trader=4,
		Value=5,
		Name=6,
	};

	MQ2BazaarItemType():MQ2Type("bazaaritem")
	{
		TypeMember(Price);
		TypeMember(Quantity);
		TypeMember(ItemID);
		TypeMember(Trader);
		TypeMember(Value);
		TypeMember(Name);
	}
	~MQ2BazaarItemType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		if (!VarPtr.Ptr)
			return false;
#define pBzrItem ((_BazaarSearchResponsePacket*)VarPtr.Ptr)
		PMQ2TYPEMEMBER pMember=MQ2BazaarItemType::FindMember(Member);
		if (!pMember)
			return false;
		switch((BazaarItemMembers)pMember->ID)
		{
		case Price:
			Dest.DWord=pBzrItem->BSSPrice;
			Dest.Type=pIntType;
			return true;
		case Quantity:
			Dest.DWord=pBzrItem->BSSQuantity;
			Dest.Type=pIntType;
			return true;
		case ItemID:
			Dest.DWord=pBzrItem->BSSItemID;
			Dest.Type=pIntType;
			return true;
		case Trader:
			if (Dest.Ptr=GetSpawnByID(pBzrItem->BSSTraderID))
			{
				Dest.Type=pSpawnType;
				return true;
			}
			return false;
		case Value:
			Dest.DWord=pBzrItem->BSSValue;
			Dest.Type=pIntType;
			return true;
		case Name:
			Dest.Ptr=&pBzrItem->BSSName[0];
			Dest.Type=pStringType;
			return true;
		}

		return false;
#undef pBzrItem
	}

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		strcpy(Destination,((_BazaarSearchResponsePacket*)VarPtr.Ptr)->BSSName);
		return true;
	}
	void InitVariable(MQ2VARPTR &VarPtr) 
	{
		VarPtr.Ptr=malloc(sizeof(_BazaarSearchResponsePacket));
		ZeroMemory(VarPtr.Ptr,sizeof(_BazaarSearchResponsePacket));
	}
	void FreeVariable(MQ2VARPTR &VarPtr) 
	{
		free(VarPtr.Ptr);
	}

	bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
	{
		if (Source.Type!=pBazaarItemType)
			return false;
		memcpy(VarPtr.Ptr,Source.Ptr,sizeof(_BazaarSearchResponsePacket));
		return true;
	}
	bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
	{
		return false;
	}
};

class MQ2BazaarType : public MQ2Type
{
public:
	enum BazaarMembers
	{
		Count=1,
		Done=2,
		Item=3,
	};

	MQ2BazaarType():MQ2Type("bazaar")
	{
		TypeMember(Count);
		TypeMember(Done);
		TypeMember(Item);
	}
	~MQ2BazaarType()
	{
	}

	bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest)
	{
		PMQ2TYPEMEMBER pMember=MQ2BazaarType::FindMember(Member);
		if (!pMember)
			return false;
		switch((BazaarMembers)pMember->ID)
		{
		case Count:
			Dest.DWord=BzCount;
			Dest.Type=pIntType;
			return true;
		case Done:
			Dest.DWord=BzDone;
			Dest.Type=pBoolType;
			return true;
		case Item:
			if (Index[0])
			{
				unsigned long N=atoi(Index)-1;
				if (N>BzCount)
					return false;
				Dest.Ptr=&BzArray[N];
				Dest.Type=pBazaarItemType;
				return true;
			}
			return false;
		}

		return false;
	}

	 bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		if (BzDone)
			strcpy(Destination,"TRUE");
		else
			strcpy(Destination,"FALSE");
		return true;
	}

	bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
	{
		return false;
	}
	bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
	{
		return false;
	}
};


// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
   DebugSpewAlways("Initializing MQ2Bzsrch");

   // Add commands, macro parameters, hooks, etc.
   AddCommand("/bzsrch",BzSrchMe);
   AddCommand("/mq2bzsrch",MQ2BzSrch);
#ifdef USEMQ2PARMS
    AddParm("bazaar",parmBazaar); // cc - removed to add MQ2Data
#else
   AddMQ2Data("Bazaar",dataBazaar); // cc - added, but not using TLO yet
#endif
   EasyClassDetour(CBazaarSearchWnd__HandleBazaarMsg,BzSrchHook,BzDetour,void,(char*,int),BzTrampoline);

   pBazaarType = new MQ2BazaarType;
   pBazaarItemType = new MQ2BazaarItemType;
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
   DebugSpewAlways("Shutting down MQ2Bzsrch");

   // Remove commands, macro parameters, hooks, etc.
   RemoveDetour(CBazaarSearchWnd__HandleBazaarMsg);
#ifdef USEMQ2PARMS
    RemoveParm("bazaar"); //cc - removed to add MQ2Data
#else
   RemoveMQ2Data("bazaar");
#endif
   RemoveCommand("/mq2bzsrch");
   RemoveCommand("/bzsrch");
   delete pBazaarType;
   delete pBazaarItemType;
}

VOID MQ2BzSrch(PSPAWNINFO pChar, PCHAR szLine)
{
   WriteChatColor("Bazaar Search Plugin by DKAA",USERCOLOR_WHO);
   WriteChatColor("",USERCOLOR_WHO);
   WriteChatColor("usage: /bzsrch [params] [name]",USERCOLOR_WHO);
   WriteChatColor("    params:",USERCOLOR_WHO);
   WriteChatColor("    [race any|barbarian|dark elf|dwarf|erudite|froglok|gnome|half elf|halfling|high elf|human|iksar|ogre|troll|vah shir|wood elf]",USERCOLOR_WHO);
   WriteChatColor("    [class any|bard|beastlord|berserkers|cleric|druid|enchanter|magician|monk|necromancer|paladin|ranger|rogue|shadow knight|shaman|warrior|wizard]", USERCOLOR_WHO);
   WriteChatColor("    [stat any|armor class|agility|charisma|dexterity|intelligence|stamina|strength|wisdom|vs cold|vs disease|vs fire|vs magic|vs poison|hit points|mana]", USERCOLOR_WHO);
   WriteChatColor("    [slot  any|ammo|arms|back|charm|chest|ear|face|feet|fingers|hands|head|legs|neck|primary|range|secondary|shoulders|waist|wrist]", USERCOLOR_WHO);
   WriteChatColor("    [type  any|1h slashing|1h blunt|2h blunt|2h slashing|2h piercing|alcohol|all effects|armor|arrow|bandages|book|bow|brass instrument|combinable|drink|flowing thought|focus effect|food|haste|jewelry|key|light|martial|misc|note|percussion instrument|piercing|potion|scroll|shield|stringed instrument|throwing|wind instrument]", USERCOLOR_WHO);
   WriteChatColor("    [price <low> <high>]", USERCOLOR_WHO);
   WriteChatColor("", USERCOLOR_WHO);
   WriteChatColor("values are returned in $bazaar variable", USERCOLOR_WHO);
   WriteChatColor("$bazaar -- TRUE if there are search results", USERCOLOR_WHO);
   WriteChatColor("$bazaar[count] -- number of search results", USERCOLOR_WHO);
   WriteChatColor("$bazaar[n,name] -- name of the nth item", USERCOLOR_WHO);
   WriteChatColor("$bazaar[n,price] -- price of the nth item", USERCOLOR_WHO);
   WriteChatColor("$bazaar[n,id] -- id of the nth item", USERCOLOR_WHO);
   WriteChatColor("$bazaar[n,trader] -- trader id of the nth item", USERCOLOR_WHO);
}

VOID BzSrchMe(PSPAWNINFO pChar, PCHAR szLine)
{
   struct _BazaarSearchRequestPacket bsrp;
   CHAR szArg[MAX_STRING] = {0};
   PCHARINFO pCharInfo = GetCharInfo();
   BOOL bArg = TRUE;
   int i, first = 1;

   // clear out the old list or the new entries will be
   // added to them
   class CListWnd *ptr = *(class CListWnd **) ((char *)pBazaarSearchWnd+0x39B0);
   ptr->DeleteAll();


   // default to current race and class
   bsrp.BSRCommand = 7;
   bsrp.BSRTraderID = 0;
   bsrp.BSRClass = pCharInfo->Class;
   bsrp.BSRRace = pCharInfo->Race;
   bsrp.BSRStat = -1;
   bsrp.BSRSlot = -1;
   bsrp.BSRType = -1;
   memset(bsrp.BSRName, 0, 60);
   bsrp.BSRPriceH = 0;
   bsrp.BSRPriceL = 0;

   while(bArg) {
      GetArg(szArg,szLine,1);
      szLine = GetNextArg(szLine, 1);
      if (szArg[0]==0) {
         bArg = FALSE;
      } else if (!strcmp(szArg, "class")) {
         GetArg(szArg,szLine,1);
         szLine = GetNextArg(szLine, 1);
         if (szArg[0]==0) {
            MacroError("Bad class name.");
            goto error_out;
         }
         if (isdigit(szArg[0])) {
            bsrp.BSRClass = atoi(szArg);
            continue;
         }
         for(i=0;i<sizeof(classes)/sizeof(classes[0]);i++) {
            if (!strcmp(szArg, classes[i].name)) {
               bsrp.BSRClass = classes[i].classn;
               break;
            }
         }
         if (i==sizeof(classes)/sizeof(classes[0])) {
            MacroError("Bad class name.");
            goto error_out;
         }
      } else if (!strcmp(szArg, "race")) {
         GetArg(szArg,szLine,1);
         szLine = GetNextArg(szLine, 1);
         if (szArg[0]==0) {
            MacroError("Bad race name.");
            goto error_out;
         }
         if (isdigit(szArg[0])) {
            bsrp.BSRRace = atoi(szArg);
            continue;
         }
         for(i=0;i<sizeof(races)/sizeof(races[0]);i++) {
            if (!strcmp(szArg, races[i].name)) {
               bsrp.BSRRace = races[i].race;
               break;
            }
         }
         if (i==sizeof(races)/sizeof(races[0])) {
            MacroError("Bad race name.");
            goto error_out;
         }
      } else if (!strcmp(szArg, "stat")) {
         GetArg(szArg,szLine,1);
         szLine = GetNextArg(szLine, 1);
         if (szArg[0]==0) {
            MacroError("Bad stat name.");
            goto error_out;
         }
         if (isdigit(szArg[0])) {
            bsrp.BSRStat = atoi(szArg);
            continue;
         }
         for(i=0;i<sizeof(stats)/sizeof(stats[0]);i++) {
            if (!strcmp(szArg, stats[i].name)) {
               bsrp.BSRStat = stats[i].stat;
               break;
            }
         }
         if (i==sizeof(stats)/sizeof(stats[0])) {
            MacroError("Bad stat name.");
            goto error_out;
         }
      } else if (!strcmp(szArg, "slot")) {
         GetArg(szArg,szLine,1);
         szLine = GetNextArg(szLine, 1);
         if (szArg[0]==0) {
            MacroError("Bad slot name.");
            goto error_out;
         }
         if (isdigit(szArg[0])) {
            bsrp.BSRSlot = atoi(szArg);
            continue;
         }
         for(i=0;i<sizeof(slots)/sizeof(slots[0]);i++) {
            if (!strcmp(szArg, slots[i].name)) {
               bsrp.BSRSlot = slots[i].slot;
               break;
            }
         }
         if (i==sizeof(slots)/sizeof(slots[0])) {
            MacroError("Bad slot name.");
            goto error_out;
         }
      } else if (!strcmp(szArg, "type")) {
         GetArg(szArg,szLine,1);
         szLine = GetNextArg(szLine, 1);
         if (szArg[0]==0) {
            MacroError("Bad type name.");
            goto error_out;
         }
         if (isdigit(szArg[0]) && szArg[1]!='h') {
            bsrp.BSRType = atoi(szArg);
            continue;
         }
         for(i=0;i<sizeof(types)/sizeof(types[0]);i++) {
            if (!strcmp(szArg, types[i].name)) {
               bsrp.BSRType = types[i].type;
               break;
            }
         }
         if (i==sizeof(types)/sizeof(types[0])) {
            MacroError("Bad type name.");
            goto error_out;
         }
      } else if (!strcmp(szArg, "price")) {
         GetArg(szArg,szLine,1);
         szLine = GetNextArg(szLine, 1);
         if (szArg[0]==0) {
            MacroError("Bad price low.");
            goto error_out;
         }
         bsrp.BSRPriceL = atoi(szArg);

         GetArg(szArg,szLine,1);
         szLine = GetNextArg(szLine, 1);
         if (szArg[0]==0) {
            MacroError("Bad price high.");
            goto error_out;
         }
         bsrp.BSRPriceH = atoi(szArg);
      } else { // it's a name
         if (first) {
            first = 0;
         } else {
            strcat(bsrp.BSRName, " ");
         }
         strcat(bsrp.BSRName, szArg);
      }
   }

   BzCount = 0;
   BzDone = 0;
   send_message(EQADDR_GWORLD,0x1e9, &bsrp, sizeof(bsrp), TRUE);
   return;

error_out:
   return;
}

BOOL dataBazaar(PCHAR szName, MQ2TYPEVAR &Ret)
{
	Ret.DWord=1;
	Ret.Type=pBazaarType;
	return true;
	/*
   DWORD i=0;
   if (strlen(szName) == 0) {
      if (!BzDone) {
         Ret.Int=0;
         Ret.Type=pBoolType;
         return true;
      } else {
         Ret.Int=1;
         Ret.Type=pBoolType;
         return true;
      }
   } else
   if (!strncmp("count", szName, 5)) {
      CHAR szTemp[MAX_STRING] = {0};
      i+=12;
      Ret.DWord=BzCount;
      Ret.Type=pIntType;
      return true;
   } else {
      DWORD index = atoi(szName);
      PCHAR tmp = strstr(szName, ",");
      CHAR szOutput[64] = {0};
      tmp++;
      char *ptr;
      strcpy(szOutput, BzArray[index].BSSName);
      if (ptr = strrchr(szOutput,'('))
            *ptr = '\0';
      
      if (!strncmp("name", tmp, 4)) {
         Ret.Ptr=&szOutput;
         Ret.Type=pStringType;
         return true;
      }
      if (!strncmp("price", tmp, 5)) {
         Ret.Int=BzArray[index].BSSPrice;
         Ret.Type=pIntType;
         return true;
      }
      if (!strncmp("itemid", tmp, 6)) {
         Ret.Int=BzArray[index].BSSItemID;
         Ret.Type=pIntType;
         return true;
      }
      if (!strncmp("msg", tmp, 3)) {
         Ret.Int=BzArray[index].BSSmsg;
         Ret.Type=pIntType;
         return true;
      }
      if (!strncmp("quantity", tmp, 8)) {
         Ret.Int=BzArray[index].BSSQuantity;
         Ret.Type=pIntType;
         return true;
      }
      if (!strncmp("traderid", tmp, 8)) {
         Ret.Int=BzArray[index].BSSTraderID;
         Ret.Type=pIntType;
         return true;
      }
      if (!strncmp("value", tmp, 5)) {
         Ret.Int=BzArray[index].BSSValue;
         Ret.Type=pIntType;
         return true;
      }
   }
   return false;
   /**/
}

DWORD parmBazaar(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
   DWORD i=0;

   if (!strncmp("bazaar()", szVar, 8)) {
      i+=7;
      if (!BzDone) {
         strcat(szOutput,"FALSE");
      } else {
         strcat(szOutput,"TRUE");
      }
   } else if (!strncmp("bazaar(count)", szVar, 13)) {
      CHAR szTemp[MAX_STRING] = {0};
      i+=12;
      itoa(BzCount, szTemp, 10);
      strcat(szOutput, szTemp);
   } else if (!strncmp("bazaar(", szVar, 7)) {
      CHAR szTemp[MAX_STRING] = {0};
      DWORD index = atoi(szVar+7);
      PCHAR tmp = strstr(szVar, ",");
      if (index >= 200 || index >= BzCount || !tmp) {
         DebugSpewNoFile("parmBazaar -- Bad $bazaar() '%s'",szVar);
         return PMP_ERROR_BADPARM;
      }
      tmp++;
      if (!strncmp("name",tmp,4)) {
         char *ptr;
         strcat(szOutput, BzArray[index].BSSName);
         if (ptr = strrchr(szOutput,'('))
            *ptr = '\0';
      } else if (!strncmp("price",tmp,5)) {
         itoa(BzArray[index].BSSPrice, szTemp, 10);
         strcat(szOutput, szTemp);
      } else if (!strncmp("id",tmp,2)) {
         itoa(BzArray[index].BSSItemID, szTemp, 10);
         strcat(szOutput, szTemp);
      } else if (!strncmp("trader",tmp,6)) {
         itoa(BzArray[index].BSSTraderID, szTemp, 10);
         strcat(szOutput, szTemp);
      } else if (!strncmp("quantity",tmp,8)) {
         itoa(BzArray[index].BSSQuantity, szTemp, 10);
         strcat(szOutput, szTemp);
      } else {
         DebugSpewNoFile("parmBazaar -- Bad $bazaar() '%s'",szVar);
         return PMP_ERROR_BADPARM;
      }
      tmp = strstr(szVar,")");
      if (!tmp)  {
         DebugSpewNoFile("parmBazaar -- Bad $bazaar() '%s'",szVar);
         return PMP_ERROR_BADPARM;
      } else {
         i = (tmp - szVar);
      }
   }

   return i;
}
