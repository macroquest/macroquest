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
	KP(Unknown0x0084);
    KP(Gender); 
    KP(Race); 
    KP(Class); 
	KP(Unknown0x0094);
    KP(Level); 
    KP(Exp); 
    KP(PracticePoints); 
    KP(Mana); 
	KP(Unknown0x00a8);
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
    KP(SaveMagic); 
    KP(SaveFire); 
    KP(SaveCold); 
    KP(SavePoison); 
    KP(SaveDisease); 
    KP(CurrWeight); 
	KP(HPBonus);
	KP(ManaBonus);
    KP(ShortBuff);
    KP(ZoneBoundId); 
    KPf(ZoneBoundY); 
    KPf(ZoneBoundX); 
    KPf(ZoneBoundZ); 
    KP(Diety); 
    KP(GuildID); 
	KP(GuildStatus);
	KP(Drunkedness);
    KP(Grouped);
	KP(AAExp);
	KP(PercentEXPtoAA);
	KP(AAPoints);
    KPs(Server); 
	KP(GukEarned);
	KP(MirEarned);
	KP(MMEarned);
	KP(RujEarned);
	KP(TakEarned);
	KP(LDoNPoints);
    KP(Bank);
} 

DECLARE_API ( pspawn ) 
{ 
    SPAWNINFO *p, *pnull=NULL, ci; 
    DWORD cb; 

    // read param from command line 
    p = (SPAWNINFO *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 
   KPs(Lastname);
   KPf(Y); 
   KPf(X); 
   KPf(Z); 
   KPf(SpeedY); 
   KPf(SpeedX); 
   KPf(SpeedZ); 
   KPf(SpeedRun); 
   KPf(Heading);
   KPf(CameraAngle); 
   KPs(Name); 
   KPs(DisplayedName);
   KPf(SpeedHeading); 
   KP(pActorInfo); 
   KP(Sneak);
   KP(Linkdead);
   KP(LFG); 
   for (int i=0; i < 7; i++) 
      dprintf("ArmorColor%d = %d (offset 0x%x)\n", i+1, ci.ArmorColor[i], &pnull->ArmorColor[i]); 
   KP(Zone); 
   KP(Instance);
   KP(pNext); 
   KP(pCharInfo); 
   KP(pPrev);
   KPf(Unknownf0x198);
   KPf(Unknownf0x19c);
   KPf(Unknownf0x1a0);
   KPf(AvatarHeight);
   KPf(Unknownf0x1a8);
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
   KP(PvPFlag);
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
   KP(AFK); 
   KP(BodyType); 
   KP(HPCurrent); 
   KP(AARank); 
   KP(Deity); 
   KP(HPMax); 
   KP(GuildID); 
   KP(Levitate);
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
   KP(BaneDMGType);
   KP(RequiredLevel);
   KP(InstrumentType);
   KP(InstrumentMod);
   KP(Classes); 
   KP(Races); 
   KP(Diety); 
   KP(SpellId); 
   KP(Color); 
   KP(SkillModValue); 
   KP(BaneDMG);
   KP(Magic); 
   KP(Light); 
   KP(Delay); 
   KP(RecommendedLevel); 
   KP(DmgBonusType);
   KP(DmgBonusVal);
   KP(Range);
   KP(Damage); 
   KP(ItemType); 
   KP(Material); 
   KP(AugSlot1);
   KP(AugSlot2);
   KP(AugSlot3);
   KP(AugSlot4);
   KP(AugSlot5);
   KP(AugType);
   KP(AugRestrictions);
   KP(LDTheme);
   KP(LDCost);
   KPs(CharmFile); 
   KPf(QuestValue);
   KP(CombatEffects);
   KP(Shielding);
   KP(StunResist);
   KP(StrikeThrough);
   KP(SpellShield);
   KP(Avoidance);
   KP(FocusId); 
   KP(CastTime); 
   KP(Stackable); 
   KP(EffectType); 
   KPs(BookFile);
   KP(Skill);
   KP(Combine); 
   KP(Slots); 
   KP(SizeCapacity); 
   KP(WeightReduction); 
   KP(Favor);
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
   SPELL *p, *pnull=NULL, ci; 
   DWORD cb; 
   CHAR tmp[1024]; 
   CHAR buffer[MAX_STRING] = {0}; 
   unsigned int bitval = 1; 

    // read param from command line 
    p = (SPELL *)GetExpression(args); 

    ReadMemory((PARAM1)p,&ci,sizeof(ci),&cb); 

   dprintf("\n\n\n"); 

   KP(ID); 
   KPf(Range); 
   KPf(AERange);
   KPf(PushBack);
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
   KP(LightType);
   KP(SpellType);
   KP(Resist);
   for (i=0; i < 12; i++) 
      dprintf("Attrib%d = %d (offset 0x%x)\n", i+1, ci.Attrib[i], &pnull->Attrib[i]); 
   KP(TargetType);
   KP(FizzleAdj); 
   KP(Skill); 
   KP(Location);
   KP(Environment);
   KP(TimeOfDay);
   for (i=0; i < 16; i++) 
      dprintf("Level(Class %d) = %d (offset 0x%x)\n", i+1, ci.Level[i], &pnull->Level[i]); 
   KP(CastingAnim); 
   KP(descnum);
   KP(Uninterruptable);
   KP(Deletable);
   KP(Autocast);
   KP(DurationWindow);
   KP(Unknown144);
   KP(Unknown145);
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
   KP(ResistAdj);
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
   KP(ZoneType);
   KP(FogRed);
   KP(FogGreen);
   KP(FogBlue);
   for (int i=0; i < 4; i++) 
      dprintf("Unknown0x184[%d] = %f (offset 0x%x)\n", i, ci.Unknown0x184[i], &pnull->Unknown0x184[i]); 
   for (i=0; i < 4; i++) 
      dprintf("Unknown0x194[%d] = %f (offset 0x%x)\n", i, ci.Unknown0x194[i], &pnull->Unknown0x194[i]); 
   KPf(ZoneGravity);
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
   KP(TimeStamp);
   KP(LastTick);
   KP(UnderWater);
   KP(FeetWet);
   KP(LeftWater);
   KP(SpellETA);
   KP(Animation);
   KP(Mount);
   KPs(NameOfLastSuccessfulTargetHit);
   KP(InvitedToGroup);
   KP(CastingSpellID);
   KP(Model);
   KP(WhoFollowing);
   KP(Trader);
} 

// This routine exports all spell information in the game (stored 
// in memory) into a tilde delimited format which works well with 
// Microsoft Excel. 
// Note:  Add "Levels" 
DECLARE_API ( exportallspells ) 
{ 
   SPELL *p, *pnull=NULL, ci, *r; 
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

      p = (SPELL *)r; 
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
      dprintf("%d~%d\n", ci.descnum, ci.FizzleAdj ); 

    
      //Clean up (always better to be safe than sorry) 
      Name[0] = Target[0] = CastOnYou[0] = CastOnAnother[0] = WearOff[0] = '\0'; 
      i++; 
      j++; 
   } 
} 

