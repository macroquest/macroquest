#include <stdio.h>
#include "../MQ2Plugin.h"

#define KS(x)  printf("/* 0x%04x */ " #x "\n", &p->x)

main()
{
struct _CHARINFO2 *p = NULL;
KS(Unknown0x0);
printf("\n");
KS(  Inventory);
KS(  InventoryArray);
printf("\n");
KS(  Cursor);
KS(Unknown0x8c);
KS(  Buff);
KS(  ShortBuff);
KS(Unknown0x550);
KS(SpellBook);
KS(MemorizedSpells);
KS(Skill);
KS(Unknown0x1100);
KS(Gender);
KS(Race);
KS(Class);
KS(Unknown0x11a0);
KS(Level);
KS(Mana);
KS(Endurance);
KS(BaseHP);
KS(BaseSTR);
KS(BaseSTA);
KS(BaseCHA);
KS(BaseDEX);
KS(BaseINT);
KS(BaseAGI);
KS(BaseWIS);
KS(Unknown0x11d0);
KS(Plat);
KS(Gold);
KS(Silver);
KS(Copper);
KS(CursorPlat);
KS(CursorGold);
KS(CursorSilver);
KS(CursorCopper);
KS(Unknown0x11f4);
KS(thirstlevel);
KS(hungerlevel);
KS(Unknown0x1220);
KS(ZoneBoundID);
KS(ZoneBoundX);
KS(ZoneBoundY);
KS(ZoneBoundZ);
KS(ZoneBoundHeading);
KS(Unknown0x12a0);
KS(ArmorType);
KS(AAList);
KS(BodyColor);
KS(Unknown0x1aec);
KS(CombatAbilities);
KS(Unknown0x3c7c);
KS(CombatAbilityTimes);
KS(Unknown0x3e34);
KS(Deity);
KS(Unknown0x5864);
KS(Drunkenness);
KS(Unknown0x586c);
KS(AAPoints);
KS(Unknown0x5878);
KS(AAPointsSpent);
KS(Unknown0xae74);
}
