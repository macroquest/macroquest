#define WIN32_LEAN_AND_MEAN 
#define _WIN32_WINNT 0x510 
#define DIRECTINPUT_VERSION 0x800 

#include <windows.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include "dinput.h" 
#include <time.h> 
#include <io.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <winsock.h> 
#include "../MQ2Main/EQData.h" 
#include "../MQ2Main/EQUIStructs.h" 

#include "mqext.h" 

#define KP(X)      dprintf(#X " = %d (offset 0x%x)\n", ci.X, &pnull->X)       
#define KPs(X)      dprintf(#X " = %s (offset 0x%x)\n", ci.X, &pnull->X) 
#define KPf(X)      dprintf(#X " = %f (offset 0x%x)\n", ci.X, &pnull->X) 

#if defined(EXT_API_VERSION_NUMBER64) 
#define PARAM1 ULONG64 
#else 
#define PARAM1 ULONG 
#endif 

DECLARE_API ( pchar ) 
{ 
    CHARINFO *p, *pnull=NULL, ci; 
    DWORD cb; 
   CHAR buffer[MAX_STRING] = {0}; 
   CHAR tmp[MAX_STRING] = {0}; 
   unsigned int bitval = 1; 
   int i=0; 

    // read param from command line 
    p = (CHARINFO *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

    dprintf("\n\n\n"); 
    KPs(Name); 
    KPs(Lastname); 
    KP(Gender); 
    KP(Race); 
    KP(Class); 
    KP(Level); 
    KP(Exp); 
    KP(PracticePoints); 
    KP(Mana); 
    KP(BaseHP); 
    KP(Stunned); 
    KP(BaseSTR); 
    KP(BaseSTA); 
    KP(BaseCHA); 
    KP(BaseDEX); 
    KP(BaseINT); 
    KP(BaseAGI); 
    KP(BaseWIS); 
   KP(Face); 
   KP(languages); 
   KP(Buff); 
   KP(SpellBook); 
   KP(MemorizedSpells); 
   KPf(y); 
   KPf(x); 
   KPf(z); 
   KPf(heading); 
   KP(standstate); 
    KP(Plat); 
    KP(Gold); 
    KP(Silver); 
    KP(Copper); 
    KP(BankPlat); 
    KP(BankGold); 
    KP(BankSilver); 
    KP(BankCopper); 
   KP(BankSharedPlat); 
   KP(Skill); 
    KP(Unknown0x0ca8); 
   KPf(Unknown0x0cac); 
   KPf(Unknown0x0cb0); 
   KPf(Unknown0x0cb4); 
   KPf(Unknown0x0cb8); 
   KP(Unknown0x0cfc); 
   KP(Unknown0x0d00); 
   KP(Unknown0x0d10); 
   KP(Unknown0x0d24); 
    KP(Unknown0x0d3c); 
   KP(Unknown0x0d44); 
   KP(Unknown0x0d4c); 
   KP(hungerlevel); 
   KP(thirstlevel); 
   KP(zoneId); 
   KP(STR); 
    KP(STA); 
    KP(CHA); 
    KP(DEX); 
    KP(INT); 
    KP(AGI); 
    KP(WIS); 
   KP(Unknown0x0e44); 
    KP(SaveMagic); 
    KP(SaveFire); 
    KP(SaveCold); 
    KP(SavePoison); 
    KP(SaveDisease); 
    KP(CurrWeight); 
    KP(Unknown0x0e60); 
   KP(Unknown0x0e64); 
    KP(Unknown0x0e6c); 
    KP(Unknown0x0ea8);
	KP(Unknown0x0f0c);
   KP(Unknown0x1018); 
    KP(Unknown0x101c); 
   KP(Unknown0x1048); 
   KP(Unknown0x104c); 
   KP(Unknown0x1050); 
   KP(Unknown0x1054); 
   KP(Unknown0x10a0); 
   KP(Unknown0x10a4);
   KP(Unknown0x10ac);
   KP(Unknown0x10b0);
   KP(Unknown0x10b4);
   KP(Unknown0x10b8);
   KP(Unknown0x10d0); 
   KP(Unknown0x10d4);
   KP(Unknown0x1124);
   KP(Unknown0x1128);
   KP(Unknown0x1134);
   KP(Unknown0x1138);
   KP(Unknown0x11d4);
   KP(Unknown0x11d8);
   KP(Unknown0x11dc);
   KP(ZoneBoundId); 
   KPf(ZoneBoundY); 
   KPf(ZoneBoundX); 
   KPf(ZoneBoundZ); 
   KPf(Unknown0x1314); 
   KPf(Unknown0x1318); 
   KPf(Unknown0x131c); 
   KPf(Unknown0x1320); 
   KPf(Unknown0x1324); 
   KPf(Unknown0x1338); 
   KP(Diety); 
   KP(GuildID); 
    KPf(Unknown0x1344); 
    KPf(Unknown0x1348); 
   KP(Unknown0x134c);
   KP(Fatigue);
   KP(GuildStatus);
   KP(Unknown0x1370); 
   KP(Unknown0x1374);
   KP(Unknown0x137c);
   KP(Grouped);
   KP(AAExp);
   KP(AAPoints);
   KPs(Server); 
   KP(Bank);
   KP(Unknown0x9d98);

} 

DECLARE_API ( pspawn ) 
{ 
    SPAWNINFO *p, *pnull=NULL, ci; 
    DWORD cb; 

    // read param from command line 
    p = (SPAWNINFO *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 
   KPs(Name); 
   KPf(Y); 
   KPf(X); 
   KPf(Z); 
   KPf(SpeedY); 
   KPf(SpeedX); 
   KPf(SpeedZ); 
   KPf(SpeedRun); 
   KPf(Heading);
   KPf(Unknown0x088);
   KPf(SpeedHeading); 
   KPf(CameraAngle); 
   KP(pActorInfo); 
   KP(Linkdead);
   KP(LFG); 
   for (int i=0; i < 7; i++) 
      dprintf("ArmorColor%d = %d (offset 0x%x)\n", i+1, ci.ArmorColor[i], &pnull->ArmorColor[i]); 
   KP(Zone); 
   KP(Instance);
   KP(pNext); 
   KP(pCharInfo); 
   KP(pPrev);
   KPf(Unknownf0x158);
   KPf(Unknownf0x15c);
   KPf(Unknownf0x160);
   KPf(AvatarHeight);
   KPf(Unknownf0x168);
   KP(Type); 
   KP(Face);
   KP(BeardColor);
   KP(Eyes);
   KP(Hair);
   KP(BeardType);
   KP(Holding);
   KP(Level);
   KP(FaceHair);
   KP(Gender);
   KP(HideMode);
   KP(StandState);
   KP(Class);
   KP(Light);
   KP(InNonPCRaceIllusion);
   KP(GM);
   KP(SpawnID);
   KP(MasterID);
   KP(Race);
   KP(Anon); 
   KP(AARank); 
   KP(AFK); 
   KP(BodyType); 
   KP(HPCurrent); 
   KP(Deity); 
   KP(HPMax); 
   KP(GuildID); 
} 

DECLARE_API ( pitem ) 
{ 
    ITEMINFO *p, *pnull=NULL, ci; 
    DWORD cb; 

    // read param from command line 
    p = (ITEMINFO *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 
    KPs(Name); 
   KPs(LoreName); 
   KPs(IDFile); 
   KP(ItemNumber); 
   KP(EquipSlots); 
   KP(Cost); 
   KP(IconNumber); 
   KP(Weight); 
   KP(NoRent); 
   KP(NoDrop); 
   KP(Size); 
   KP(Type); 
   dprintf("\tNote:  The COMMON, CONTAINER, or BOOK union starts at 0xd6\n" ); 
} 

DECLARE_API ( pcommon ) 
{ 
    COMMON *p, *pnull=NULL, ci; 
    DWORD cb; 

    // read param from command line 
    p = (COMMON *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 
   KP(SvCold); 
   KP(SvFire); 
   KP(SvMagic); 
   KP(SvDisease); 
   KP(SvPoison); 
   KP(STR); 
   KP(STA); 
   KP(AGI); 
   KP(DEX); 
   KP(CHA); 
   KP(INT); 
   KP(WIS); 
   KP(HP); 
   KP(Mana); 
   KP(AC); 
   KP(SkillModType); 
   KP(RequiredLevel); 
   KP(Classes); 
   KP(Races); 
   KP(Diety); 
   KP(SpellId); 
   KP(Color); 
   KP(SkillModValue); 
   KP(Magic); 
   KP(Light); 
   KP(Delay); 
   KP(RecommendedLevel); 
   KP(Damage); 
   KP(ItemType); 
   KP(Material); 
   KPs(CharmFile); 
   KPf(QuestValue);
   KP(FocusId); 
   KP(CastTime); 
   KP(Stackable); 
   KP(EffectType); 
} 

DECLARE_API ( pcontainer ) 
{ 
    CONTAINER *p, *pnull=NULL, ci; 
    DWORD cb; 

    // read param from command line 
    p = (CONTAINER *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 
   KP(Combine); 
   KP(Slots); 
   KP(SizeCapacity); 
   KP(WeightReduction); 
} 


DECLARE_API ( pgroundspawn ) 
{ 
    GROUNDITEM *p, *pnull=NULL, ci; 
    DWORD cb; 

    // read param from command line 
    p = (GROUNDITEM *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 
   KP(pPrev); 
   KP(pNext); 
   KP(ID); 
   KP(DropID); 
   KP(Unknown0x10);
   KP(DxID); 
   KPf(Heading); 
   KPf(Z); 
   KPf(X); 
   KPf(Y); 
   KPs(Name); 
} 

DECLARE_API ( pdoor ) 
{ 
DOOR *p, *pnull=NULL, ci; 
    DWORD cb; 

    // read param from command line 
    p = (DOOR *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 

   KP(Unknown0x00); 
   KP(ID); 
   KPs(Name); 
   KP(Unknown0x0d); 
   KPf(DefaultY); 
   KPf(DefaultX); 
   KPf(DefaultZ); 
   KPf(DefaultHeading); 
   KPf(DoorAngle); 
   KPf(Y); 
   KPf(X); 
   KPf(Z); 
   KPf(Heading); 
} 

DECLARE_API ( pspellbuff ) 
{ 
    SPELLBUFF *p, *pnull=NULL, ci; 
    DWORD cb; 

    // read param from command line 
    p = (SPELLBUFF *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 

   KP(Level); 
   KP(SpellID); 
   KP(Duration); 
   KP(DamageAbsorbRemaining);
} 

//Be sure that you take into account SPELLLIST_STARTOFFSET when testing 
//this structure! 
DECLARE_API ( pspell ) 
{ 
    SPELLLIST *p, *pnull=NULL, ci; 
    DWORD cb; 
   CHAR tmp[1024]; 
   CHAR buffer[MAX_STRING] = {0}; 
   unsigned int bitval = 1; 

    // read param from command line 
    p = (SPELLLIST *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 

   KP(ID); 
   KPf(Range); 
   KP(CastTime); 
   KP(FizzleTime); 
   KP(RecastTime); 
   KP(DurationType); 
   KP(DurationValue1); 
   KP(Mana); 
   for (int i=0; i < 12; i++) 
      dprintf("Base%d = %d (offset 0x%x)\n", i+1, ci.Base[i], &pnull->Base[i]); 
   for (i=0; i < 12; i++) 
      dprintf("Max%d = %d (offset 0x%x)\n", i+1, ci.Max[i], &pnull->Max[i]); 
   KP(BookIcon); 
   KP(GemIcon); 
   for (i=0; i < 4; i++) 
      dprintf("ReagentId%d = %d (offset 0x%x)\n", i+1, ci.ReagentId[i], &pnull->ReagentId[i]); 
   for (i=0; i < 4; i++) 
      dprintf("ReagentCount%d = %d (offset 0x%x)\n", i+1, ci.ReagentCount[i], &pnull->ReagentCount[i]); 
   for (i=0; i < 12; i++) 
      dprintf("Calc%d = %d (offset 0x%x)\n", i+1, ci.Calc[i], &pnull->Calc[i]); 
   KP(Deletable); 
   for (i=0; i < 12; i++) 
      dprintf("Attrib%d = %d (offset 0x%x)\n", i+1, ci.Attrib[i], &pnull->Attrib[i]); 
   KP(Unknown0x114); 
   KP(FizzLeadj); 
   KP(Skill); 
   for (i=0; i < 15; i++) 
      dprintf("Level(Class %d) = %d (offset 0x%x)\n", i+1, ci.Level[i], &pnull->Level[i]); 
   KP(CastingAnim); 
   KP(descnum); 
   KP(Unknown0x144);
   KP(Unknown144);
   KP(Unknown145);
   KP(Unknown0x15c);
   ReadMemory((PARAM1)ci.Name, tmp, 128, &cb ); 
   dprintf("Name = %s (offset *0x%x)\n", tmp, &pnull->Name); 
   ReadMemory((PARAM1)ci.Target, tmp, 128, &cb ); 
   dprintf("Target = %s (offset *0x%x)\n", tmp, &pnull->Target); 
   ReadMemory((PARAM1)ci.CastOnYou, tmp, 256, &cb ); 
   dprintf("CastOnYou = %s (offset *0x%x)\n", tmp, &pnull->CastOnYou); 
   ReadMemory((PARAM1)ci.CastOnAnother, tmp, 256, &cb ); 
   dprintf("CastOnAnother = Someone%s (offset *0x%x)\n", tmp, &pnull->CastOnAnother); 
   ReadMemory((PARAM1)ci.WearOff, tmp, 256, &cb ); 
   dprintf("WearOff = %s (offset *0x%x)\n", tmp, &pnull->WearOff); 
   KP(spaindex); 
   KP(SpellAnim); 
   KP(Unknown130);
   KP(SpellIcon); 
} 

DECLARE_API ( pzone ) 
{ 
    ZONELIST *p, *pnull=NULL, ci; 
    DWORD cb; 
   CHAR buffer[MAX_STRING] = {0}; 
   CHAR tmp[MAX_STRING] = {0}; 
   unsigned int bitval = 1; 
   int i=0; 

    // read param from command line 
    p = (ZONELIST *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 

   KP(Header); 
   KP(Expansion); 
   KP(Id); 
   KPs(ShortName); 
   KPs(LongName); 

   i = ci.Flags; 
   while (ci.Flags > 0) 
   { 
      if ( ci.Flags & 1 ) 
      { 
         sprintf(tmp, "%d ", bitval ); 
         strcat(buffer, tmp); 
      } 
      ci.Flags >>= 1; 
      bitval <<= 1; 
   } 
   dprintf("Flags = %d [%s] (Offset: 0x%x)\n", i, buffer, &pnull->Flags ); 

   KP(Id2); 
   KP(PoPValue); 
   KP(MinLevel); 
} 

DECLARE_API ( pzoneinfo ) 
{ 
    ZONEINFO *p, *pnull=NULL, ci; 
    DWORD cb; 

    // read param from command line 
    p = (ZONEINFO *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 

   KPs(CharacterName); 
   KPs(ShortName); 
   KPs(LongName); 
   for (int i=0; i < 11; i++) 
      dprintf("Unknown0x177[%d] = %d (offset 0x%x)\n", i, ci.Unknown0x177[i], &pnull->Unknown0x177[i]); 
   KP(Unknown0x182); 
   for (i=0; i < 4; i++) 
      dprintf("Unknown0x184[%d] = %f (offset 0x%x)\n", i, ci.Unknown0x184[i], &pnull->Unknown0x184[i]); 
   for (i=0; i < 4; i++) 
      dprintf("Unknown0x194[%d] = %f (offset 0x%x)\n", i, ci.Unknown0x194[i], &pnull->Unknown0x194[i]); 
   KPf(Unknown0x1a4); 
   for (i=0; i < 15; i++) 
      dprintf("Unknown0x1ac[%d] = %d (offset 0x%x)\n", i, ci.Unknown0x1ac[i], &pnull->Unknown0x1ac[i]); 
   KPf(ZoneExpModifier); 
   for (i=0; i < 6; i++) 
      dprintf("Unknown0x208[%d] = %d (offset 0x%x)\n", i, ci.Unknown0x208[i], &pnull->Unknown0x208[i]); 
   for (i=0; i < 14; i++) 
      dprintf("Unknown0x220[%d] = %d (offset 0x%x)\n", i, ci.Unknown0x220[i], &pnull->Unknown0x220[i]); 
} 

DECLARE_API ( plootcorpse ) 
{ 
    LOOTCORPSE *p, *pnull=NULL, ci; 
    DWORD cb; 
   CHAR buffer[MAX_STRING] = {0}; 
   CHAR tmp[MAX_STRING] = {0}; 
   unsigned int bitval = 1; 
   int i=0; 

    // read param from command line 
    p = (LOOTCORPSE *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 

   KP(Unknown0x000); 
   KPs(Name); 
   KPf(Timer); 
   KPf(X); 
   KPf(Y); 
   KPf(Z); 
   i = ci.Flags; 
   while (ci.Flags > 0) 
   { 
      if ( ci.Flags & 1 ) 
      { 
         sprintf(tmp, "%d ", bitval ); 
         strcat(buffer, tmp); 
      } 
      ci.Flags >>= 1; 
      bitval <<= 1; 
   } 
   dprintf("Flags = %d [%s] (Offset: 0x%x)\n", i, buffer, &pnull->Flags ); 
   KP(Unknown0x08c); 
} 

DECLARE_API ( pactorinfo ) 
{ 
   ACTORINFO *p, *pnull=NULL, ci; 
   DWORD cb; 


    // read param from command line 
    p = (ACTORINFO *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 

   KPs(ActorDef);
   KPf(Z);
   KP(UnderWater);
   KP(FeetWet);
   KP(LeftWater);
   KP(Animation);
   KP(Mount);
   KPs(NameOfLastSuccessfulTargetHit);
   KP(InvitedToGroup);
   KP(WhoFollowing);
   KP(Trader);
} 

// This routine exports all spell information in the game (stored 
// in memory) into a tilde delimited format which works well with 
// Microsoft Excel. 
// Note:  Add "Levels" 
DECLARE_API ( exportallspells ) 
{ 
    SPELLLIST *p, *pnull=NULL, ci, *r; 
   DWORD *q, cb; 
   CHAR Name[MAX_STRING] = {0}; 
   CHAR Target[MAX_STRING] = {0}; 
   CHAR CastOnYou[MAX_STRING] = {0}; 
   CHAR CastOnAnother[MAX_STRING] = {0}; 
   CHAR WearOff[MAX_STRING] = {0}; 
   int i=1; 
   int j=0; 
   int k=0; 



   dprintf("ID~Name~Range~CastTime~FizzleTime~RecastTime~DurationType~DurationValue1~Mana~"); 
   dprintf("Target~CastOnYou~CastOnAnother~WearOff~"); 
   dprintf("BookIcon~GemIcon~SpellIcon~"); 
   dprintf("CastingAnim~SpellAnim~"); 
   for (k=0;k<4;k++) dprintf("ReagentID%d~ReagentCount%d~",k+1,k+1); 
   for (k=0;k<12;k++) dprintf("Base%d~",k+1); 
   for (k=0;k<12;k++) dprintf("Max%d~",k+1); 
   for (k=0;k<12;k++) dprintf("Calc%d~",k+1); 
   for (k=0;k<12;k++) dprintf("Attrib%d~",k+1); 
   dprintf("DescNum~FizzLeadj\n"); 

   while( i <= (TOTAL_SPELL_COUNT+2) ) 
   { 
      q = (DWORD*) GetExpression(args)+j; 
      ReadMemory((PARAM1)q, &r, sizeof(r), &cb); 

      p = (SPELLLIST * )r; 
      ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

      //Read some memory locations into buffers 
      ReadMemory((PARAM1)ci.Name,Name,256,&cb); 
      ReadMemory((PARAM1)ci.Target,Target,256,&cb); 
      ReadMemory((PARAM1)ci.CastOnYou,CastOnYou,256,&cb); 
      ReadMemory((PARAM1)ci.CastOnAnother,CastOnAnother,256,&cb); 
      ReadMemory((PARAM1)ci.WearOff,WearOff,256,&cb); 
      // 

      dprintf("%d~%s~%2f~%d~%d~%d~%d~%d~%d~", ci.ID, Name, ci.Range, ci.CastTime, ci.FizzleTime, ci.RecastTime, ci.DurationType, ci.DurationValue1, ci.Mana ); 
      dprintf("%s~%s~Someone%s~%s~", Target, CastOnYou, CastOnAnother, WearOff ); 
      dprintf("%d~%d~%d~", ci.BookIcon, ci.GemIcon, ci.SpellIcon ); 
      dprintf("%d~%d~", ci.CastingAnim, ci.SpellAnim ); 
      for (k=0;k<4;k++)  dprintf("%d~%d~", ci.ReagentId[k], ci.ReagentCount[k] ); 
      for (k=0;k<12;k++) dprintf("%d~", ci.Base[k]); 
      for (k=0;k<12;k++) dprintf("%d~", ci.Max[k]); 
      for (k=0;k<12;k++) dprintf("%d~", ci.Calc[k]); 
      for (k=0;k<12;k++) dprintf("%d~", ci.Attrib[k]); 
      dprintf("%d~%d\n", ci.descnum, ci.FizzLeadj ); 

    
      //Clean up (always better to be safe than sorry) 
      Name[0] = Target[0] = CastOnYou[0] = CastOnAnother[0] = WearOff[0] = '\0'; 
      i++; 
      j++; 
   } 
} 

