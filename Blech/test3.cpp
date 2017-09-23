#include "Blech.h"

#define CheckOne(ID) \
    if (nevent != 1) { \
        printf("bad event count %d != 1\n", nevent); \
        exit(1); \
    } \
    if (eventarray[0].id != ID) { \
        printf("bad event %d != " #ID "\n", eventarray[0].id); \
        exit(1); \
    }

struct {
    int id, nvalues;
    char name[50][100];
    char value[50][100];
} eventarray[20];

int nevent = 0;

void __stdcall MyEvent(unsigned long ID, void *pData, PBLECHVALUE pValues)
{
    int i = 0;
    printf("MyEvent(%d,%d,%X)\n", ID, pData, pValues);
    eventarray[nevent].id = (int) pData;
    while (pValues) {
	printf("\t'%s'=>'%s'\n", pValues->Name, pValues->Value);
	strcpy(eventarray[nevent].name[i], pValues->Name);
	strcpy(eventarray[nevent].value[i], pValues->Value);
	i++;
	pValues = pValues->pNext;
    }
    eventarray[nevent].nvalues = i;
    printf("\n");
    nevent++;
}

unsigned long   __stdcall BlechVariableValue(char * VarName, char * Value)
{
    strcpy(Value, "F");
    return strlen(Value);
}


main()
{
    Blech b('#','|', BlechVariableValue);
    int j = 0, i = 0, eventid[200];

eventid[i++] = b.AddEvent("You begin casting#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your gate is too unstable, and collapses.#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("|${Me.Name}| has fallen to the ground.", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your spell fizzles#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your target is immune to changes in its attack speed#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your target is immune to changes in its run speed#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your target cannot be mesmerized#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your casting has been interrupted#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your spell is interrupted#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your spell did not take hold#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("You cannot see your target.#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("You must first select a target for this spell!#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Spell recast time not yet met.#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Insufficient Mana to cast this spell!#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your target is out of range, get closer!#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("You haven't recovered yet...#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Spell recovery time not yet met#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("Your target resisted the #1# spell#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("You resist the #1# spell#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] SetAoRBeg#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] SetAvatarBeg#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] SetBSSBeg#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] SetBuffBeg#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] SetDSBeg#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] SetGoDBeg#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] SetFerocityBeg#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("#*#may not loot this corpse#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("#*#Returning to home point#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("#*#You gained raid experience#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("#*#You gain party experience#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("#*#hits for#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("You can only cast this spell in the outdoors#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("You can not summon a mount#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("You need to be in a more open area to summon a mount#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("You can only summon a mount on dry land#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("This spell does not work here#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("You have entered#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("#*#goes on a RAMPAGE#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] RDPause#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] ResetTanks#*#", MyEvent, (void *) i);
eventid[i++] = b.AddEvent("[MQ2] SetAEHeal#*#", MyEvent, (void *) i);

	nevent = 0;
	b.Feed("[MQ2] Uber Raid Druid Macro Online, hold onto your seatbelt!");

    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
}
