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

/*

/**/

VOID CheckChatForEvent(PCHAR szMsg)
{
	IS_CheckTriggers(pExtension,pISInterface,hTriggerService,szMsg);
	char *argv[]=
	{
		szMsg
	};
	pISInterface->ExecuteEvent(ChatEventID,0,1,argv);
}

unsigned long ParseSearchSpawnArg(int arg, int argc, char *argv[], SEARCHSPAWN &SearchSpawn)
{
   if (arg>=argc)
      return 0;
   unsigned long ExtraUsed=0;
   {
        if (!stricmp(argv[arg],"pc")) {
            SearchSpawn.SpawnType = PC;
        } else if (!stricmp(argv[arg],"npc")) {
            SearchSpawn.SpawnType = NPC;
        } else if (!stricmp(argv[arg],"mount")) {
            SearchSpawn.SpawnType = MOUNT;
        } else if (!stricmp(argv[arg],"pet")) {
            SearchSpawn.SpawnType = PET;
        } else if (!stricmp(argv[arg],"nopet")) { 
            SearchSpawn.bNoPet = TRUE; 
        } else if (!stricmp(argv[arg],"corpse")) {
            SearchSpawn.SpawnType = CORPSE;
      } else if (!stricmp(argv[arg],"npccorpse")) {
            SearchSpawn.SpawnType = NPCCORPSE;
      } else if (!stricmp(argv[arg],"pccorpse")) {
            SearchSpawn.SpawnType = PCCORPSE;
      } else if (!stricmp(argv[arg],"trigger")) {
            SearchSpawn.SpawnType = TRIGGER;
        } else if (!stricmp(argv[arg],"untargetable")) {
            SearchSpawn.SpawnType = UNTARGETABLE;
        } else if (!stricmp(argv[arg],"trap")) {
            SearchSpawn.SpawnType = TRAP;
        } else if (!stricmp(argv[arg],"chest")) {
            SearchSpawn.SpawnType = CHEST;
        } else if (!stricmp(argv[arg],"timer")) {
            SearchSpawn.SpawnType = TIMER;
        } else if (!stricmp(argv[arg],"aura")) {
            SearchSpawn.SpawnType = AURA;
        } else if (!stricmp(argv[arg],"object")) {
            SearchSpawn.SpawnType = OBJECT;
        } else if (!stricmp(argv[arg],"banner")) {
            SearchSpawn.SpawnType = BANNER;
        } else if (!stricmp(argv[arg],"campfire")) {
            SearchSpawn.SpawnType = CAMPFIRE;
        } else if (!stricmp(argv[arg],"mercenary")) {
            SearchSpawn.SpawnType = MERCENARY;
        } else if (!stricmp(argv[arg],"flyer")) {
            SearchSpawn.SpawnType = FLYER;
        } else if (!stricmp(argv[arg],"any")) {
            SearchSpawn.SpawnType = NONE;
        } else if (!stricmp(argv[arg],"next")) {
            SearchSpawn.bTargNext = TRUE;
        } else if (!stricmp(argv[arg],"prev")) {
            SearchSpawn.bTargPrev = TRUE;
        } else if (!stricmp(argv[arg],"lfg")) {
            SearchSpawn.bLFG = TRUE;
        } else if (!stricmp(argv[arg],"gm")) {
            SearchSpawn.bGM = TRUE;
        } else if (!stricmp(argv[arg],"group")) {
            SearchSpawn.bGroup = TRUE;
        } else if (!stricmp(argv[arg],"noguild")) {
            SearchSpawn.bNoGuild = TRUE;
        } else if (!stricmp(argv[arg],"trader")) {
            SearchSpawn.bTrader = TRUE;
      } else if (!stricmp(argv[arg],"named")) {
         SearchSpawn.bNamed = TRUE;
      } else if (!stricmp(argv[arg],"merchant")) {
         SearchSpawn.bMerchant = TRUE;
      } else if (!stricmp(argv[arg],"tribute")) {
         SearchSpawn.bTributeMaster = TRUE;
      } else if (!stricmp(argv[arg],"knight")) {
         SearchSpawn.bKnight = TRUE;
      } else if (!stricmp(argv[arg],"tank")) {
         SearchSpawn.bTank = TRUE;
      } else if (!stricmp(argv[arg],"healer")) {
         SearchSpawn.bHealer = TRUE;
      } else if (!stricmp(argv[arg],"dps")) {
         SearchSpawn.bDps = TRUE;
      } else if (!stricmp(argv[arg],"slower")) {
         SearchSpawn.bSlower = TRUE;
        } else if (!stricmp(argv[arg],"los")) { 
            SearchSpawn.bLoS = TRUE; 
      } else if (!stricmp(argv[arg],"targetable")) {
            SearchSpawn.bTargetable = TRUE;
        } else if (!stricmp(argv[arg],"range")) {
         if (arg+2<argc)
         {
            SearchSpawn.MinLevel = atoi(argv[arg+1]);
            SearchSpawn.MaxLevel = atoi(argv[arg+2]);
         }
         ExtraUsed=2;
        } else if (!stricmp(argv[arg],"loc")) {
         if (arg+2<argc)
         {
            SearchSpawn.bKnownLocation = TRUE;
            SearchSpawn.xLoc = (FLOAT)atof(argv[arg+1]);
            SearchSpawn.yLoc = (FLOAT)atof(argv[arg+2]);
         }
         ExtraUsed=2;
        } else if (!stricmp(argv[arg],"id")) {
            SearchSpawn.bSpawnID = TRUE;
         if (arg+1<argc)
            SearchSpawn.SpawnID = atoi(argv[arg+1]);
         ExtraUsed=1;
        } else if (!stricmp(argv[arg],"radius")) {
         if (arg+1<argc)
               SearchSpawn.FRadius = atof(argv[arg+1]);
            ExtraUsed=1;
        } else if (!stricmp(argv[arg],"body")) {
         if (arg+1<argc)
            strcpy(SearchSpawn.szBodyType,argv[arg+1]);
         ExtraUsed=1;
        } else if (!stricmp(argv[arg],"class")) {
         if (arg+1<argc)
            strcpy(SearchSpawn.szClass,argv[arg+1]);
         ExtraUsed=1;
      } else if (!stricmp(argv[arg],"race")) {
         if (arg+1<argc)
            strcpy(SearchSpawn.szRace,argv[arg+1]);
         ExtraUsed=1;
        } else if (!stricmp(argv[arg],"light")) {
         // TODO
            DWORD Light = -1;
         DWORD i=0;
         if (arg+1<argc)
         {
            for (i=0;i<LIGHT_COUNT;i++) 
               if (!stricmp(szLights[i],argv[arg])) 
                  Light=i;
         }
            if (Light != -1) {
                strcpy(SearchSpawn.szLight,szLights[Light]);
            } else {
                SearchSpawn.szLight[0]=0;
            }
         ExtraUsed=1;
         SearchSpawn.bLight=TRUE;
        } else if (!strcmp(argv[arg],"GUILD")) {
         SearchSpawn.GuildID=GetCharInfo()->pSpawn->GuildID;
        } else if (!stricmp(argv[arg],"guild")) {
         if (arg+1<argc)
         {
            DWORD GuildID=0xFFFF;
            GuildID=GetGuildIDByName(argv[arg+1]);
            if (GuildID!=0xFFFF)
            {
               ExtraUsed=1;
               SearchSpawn.GuildID=GuildID;
            }
         }
         else {
                SearchSpawn.GuildID = GetCharInfo()->pSpawn->GuildID;
            }
        } else if (!stricmp(argv[arg],"alert")) {
         if (arg+1<argc)
            SearchSpawn.AlertList=atoi(argv[arg+1]);
         ExtraUsed=1;
         SearchSpawn.bAlert=TRUE;
        } else if (!stricmp(argv[arg],"noalert")) {
         if (arg+1<argc)
            SearchSpawn.NoAlertList=atoi(argv[arg+1]);
         ExtraUsed=1;
            SearchSpawn.bNoAlert = TRUE;
        } else if (!stricmp(argv[arg],"notnearalert")) {
         if (arg+1<argc)
            SearchSpawn.NotNearAlertList = atoi(argv[arg+1]);
         ExtraUsed=1;
            SearchSpawn.bNotNearAlert = TRUE;
        } else if (!stricmp(argv[arg],"nearalert")) {
         if (arg+1<argc)
            SearchSpawn.NearAlertList = atoi(argv[arg+1]);
         ExtraUsed=1;
            SearchSpawn.bNearAlert = TRUE;
        } else if (!stricmp(argv[arg],"zradius")) {
         if (arg+1<argc)
            SearchSpawn.ZRadius=atof(argv[arg+1]);
         ExtraUsed=1;
        } else if (!stricmp(argv[arg],"notid")) {
         if (arg+1<argc)
            SearchSpawn.NotID=atoi(argv[arg+1]);
         ExtraUsed=1;
        } else if (!stricmp(argv[arg],"nopcnear")) {
         SearchSpawn.Radius=0.0f;
         if (arg+1<argc)
            SearchSpawn.Radius=(FLOAT)atof(argv[arg+1]);
         if (SearchSpawn.Radius==0.0f)
            SearchSpawn.Radius=200.0f;
         ExtraUsed=1;
      } else if (IsNumber(argv[arg])) {
         SearchSpawn.MinLevel=atoi(argv[arg]);
         SearchSpawn.MaxLevel=SearchSpawn.MinLevel;
        } else {
         for (DWORD N=1;N<17;N++)
         {
            if (!stricmp(argv[arg],ClassInfo[N].Name) || !stricmp(argv[arg],ClassInfo[N].ShortName))
            {
               strcpy(SearchSpawn.szClass,pEverQuest->GetClassDesc(N));
               return ExtraUsed;
            }
         }
         strlwr(strcpy(SearchSpawn.szName,argv[arg]));
        }
    }
    return ExtraUsed;
}

PCHAR ParseMacroParameter(PSPAWNINFO pChar, PCHAR szOriginal)
{// PMP is bad, mmmkay
	pISInterface->DataParse(szOriginal,szOriginal,4096);
	return szOriginal;
}
