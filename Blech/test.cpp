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


main()
{
    Blech b('#');
    int j = 0, i = 0, eventid[200];

    for (int x = 0; x < 2; x++) {

	eventid[i++] = b.AddEvent("Text with #variable# portion", MyEvent, (void *) 0);
	eventid[i++] = b.AddEvent("#*#Text with #variable# portion", MyEvent, (void *) 1);
	eventid[i++] = b.AddEvent("thisshouldnevertrigger", MyEvent, (void *) 2);
	eventid[i++] = b.AddEvent("#*#while stunned#*#", MyEvent, (void *) 3);
	eventid[i++] = b.AddEvent("#*#has been slain#*#", MyEvent, (void *) 4);
	eventid[i++] = b.AddEvent("#*#gain experience!#*#", MyEvent, (void *) 5);
	eventid[i++] = b.AddEvent("#*#Insufficient mana#*#", MyEvent, (void *) 6);
	eventid[i++] = b.AddEvent("[MQ2] getout", MyEvent, (void *) 7);
	eventid[i++] = b.AddEvent("#*#target is out of range#*#", MyEvent, (void *) 8);
	eventid[i++] = b.AddEvent("You cannot see#*#", MyEvent, (void *) 9);
	eventid[i++] =
	    b.AddEvent("#*#Returning to home point, please wait...#*#", MyEvent, (void *) 10);
	eventid[i++] = b.AddEvent("#*#you have been slain#*#", MyEvent, (void *) 11);
	eventid[i++] = b.AddEvent("#*#You have entered#*#", MyEvent, (void *) 12);
	eventid[i++] = b.AddEvent("The shield fades away.", MyEvent, (void *) 13);
	eventid[i++] = b.AddEvent("The maelstrom dissipates.", MyEvent, (void *) 14);
	eventid[i++] = b.AddEvent("You have been summoned!", MyEvent, (void *) 15);
	eventid[i++] = b.AddEvent("#*# YOU for #*#", MyEvent, (void *) 16);
	eventid[i++] = b.AddEvent("#*# YOU, but #*#", MyEvent, (void *) 17);
	eventid[i++] = b.AddEvent("[MQ2] nuke1 #1#", MyEvent, (void *) 18);
	eventid[i++] = b.AddEvent("[MQ2] nuke2 #1#", MyEvent, (void *) 19);
	eventid[i++] = b.AddEvent("[MQ2] domodrod", MyEvent, (void *) 20);
	eventid[i++] = b.AddEvent("[MQ2] conc", MyEvent, (void *) 21);
	eventid[i++] = b.AddEvent("[MQ2] concnum #1#", MyEvent, (void *) 22);
	eventid[i++] = b.AddEvent("[MQ2] myfamiliar #1#", MyEvent, (void *) 23);
	eventid[i++] = b.AddEvent("[MQ2] mainnukenum #1#", MyEvent, (void *) 24);
	eventid[i++] = b.AddEvent("[MQ2] endnukenum #1#", MyEvent, (void *) 25);
	eventid[i++] = b.AddEvent("[MQ2] maxbuffs #1#", MyEvent, (void *) 26);
	eventid[i++] = b.AddEvent("[MQ2] mobhealth #1#", MyEvent, (void *) 27);
	eventid[i++] = b.AddEvent("[MQ2] staffhealth #1#", MyEvent, (void *) 28);
	eventid[i++] = b.AddEvent("[MQ2] stopnuke #1#", MyEvent, (void *) 29);
	eventid[i++] = b.AddEvent("[MQ2] stopnuke2 #1#", MyEvent, (void *) 30);
	eventid[i++] = b.AddEvent("[MQ2] engagedistance #1#", MyEvent, (void *) 31);
	eventid[i++] = b.AddEvent("[MQ2] assist", MyEvent, (void *) 32);
	eventid[i++] = b.AddEvent("[MQ2] doxuzl", MyEvent, (void *) 33);
	eventid[i++] = b.AddEvent("[MQ2] manarobe", MyEvent, (void *) 34);
	eventid[i++] = b.AddEvent("[MQ2] xuzlperc #1#", MyEvent, (void *) 35);
	eventid[i++] = b.AddEvent("[MQ2] temp", MyEvent, (void *) 36);
	eventid[i++] = b.AddEvent("[MQ2] dosnare", MyEvent, (void *) 37);
	eventid[i++] = b.AddEvent("[MQ2] snareperc #1#", MyEvent, (void *) 38);
	eventid[i++] = b.AddEvent("[MQ2] ss", MyEvent, (void *) 39);
	eventid[i++] = b.AddEvent("[MQ2] mw", MyEvent, (void *) 40);
	eventid[i++] = b.AddEvent("[MQ2] timewand", MyEvent, (void *) 41);
	eventid[i++] = b.AddEvent("[MQ2] epic", MyEvent, (void *) 42);
	eventid[i++] = b.AddEvent("[MQ2] forceshield", MyEvent, (void *) 43);
	eventid[i++] = b.AddEvent("[MQ2] autosit", MyEvent, (void *) 44);
	eventid[i++] = b.AddEvent("[MQ2] som", MyEvent, (void *) 45);
	eventid[i++] = b.AddEvent("[MQ2] ma #1#", MyEvent, (void *) 46);
	eventid[i++] = b.AddEvent("[MQ2] sa #1#", MyEvent, (void *) 47);
	eventid[i++] = b.AddEvent("[MQ2] ta #1#", MyEvent, (void *) 48);
	eventid[i++] = b.AddEvent("[MQ2] cycle", MyEvent, (void *) 49);
	eventid[i++] = b.AddEvent("The magical barrier fades #*#", MyEvent, (void *) 50);
	eventid[i++] = b.AddEvent("The blue aura fades #*#", MyEvent, (void *) 51);
	eventid[i++] = b.AddEvent("[MQ2] exclude #*#", MyEvent, (void *) 52);
	eventid[i++] = b.AddEvent("[MQ2] include #*#", MyEvent, (void *) 53);
	eventid[i++] = b.AddEvent("[MQ2] addmaster #*#", MyEvent, (void *) 54);
	eventid[i++] = b.AddEvent("[MQ2] delmaster #*#", MyEvent, (void *) 55);
	eventid[i++] = b.AddEvent("[MQ2] addjunk #*#", MyEvent, (void *) 56);
	eventid[i++] = b.AddEvent("[MQ2] deljunk #*#", MyEvent, (void *) 57);
	eventid[i++] = b.AddEvent("[MQ2] pause", MyEvent, (void *) 58);
	eventid[i++] = b.AddEvent("[MQ2] itemset #1# #2# #3#", MyEvent, (void *) 59);
	eventid[i++] = b.AddEvent("[MQ2] itembounce #1# #2#", MyEvent, (void *) 60);
	eventid[i++] = b.AddEvent("[MQ2] itemcast #1#", MyEvent, (void *) 61);
	eventid[i++] = b.AddEvent("[MQ2] leash#*#", MyEvent, (void *) 62);
	eventid[i++] = b.AddEvent("[MQ2] autofollow#*#", MyEvent, (void *) 63);
	eventid[i++] = b.AddEvent("[MQ2] stopfollow#*#", MyEvent, (void *) 64);
	eventid[i++] = b.AddEvent("[MQ2] afhelp", MyEvent, (void *) 65);
	eventid[i++] = b.AddEvent("[MQ2] nukepause #*#", MyEvent, (void *) 66);
	eventid[i++] = b.AddEvent("[MQ2] doharvest", MyEvent, (void *) 67);
	eventid[i++] = b.AddEvent("[MQ2] harvestperc #1#", MyEvent, (void *) 68);
	eventid[i++] = b.AddEvent("[MQ2] medtoggle", MyEvent, (void *) 69);
	eventid[i++] = b.AddEvent("[MQ2] dopreconc", MyEvent, (void *) 70);
	eventid[i++] = b.AddEvent("[MQ2] dopreconcxxxxx", MyEvent, (void *) 71);
	eventid[i++] = b.AddEvent("[MQ2] preconcnum #1#", MyEvent, (void *) 72);
	eventid[i++] = b.AddEvent("[MQ2] tlocate #*#", MyEvent, (void *) 73);
	eventid[i++] = b.AddEvent("[MQ2] getout", MyEvent, (void *) 74);
	eventid[i++] = b.AddEvent("You gain#*#", MyEvent, (void *) 75);
	eventid[i++] = b.AddEvent("[MQ2] SetPCRadius#*#", MyEvent, (void *) 76);
	eventid[i++] = b.AddEvent("[MQ2] SetNPCRadius#*#", MyEvent, (void *) 77);
	eventid[i++] = b.AddEvent("[MQ2] Autoassist#*#", MyEvent, (void *) 78);
	eventid[i++] = b.AddEvent("[MQ2] AutoTargetSwitch#*#", MyEvent, (void *) 79);
	eventid[i++] = b.AddEvent("[MQ2] AutoTraps#*#", MyEvent, (void *) 80);
	eventid[i++] = b.AddEvent("#1# begins to cast a spell.", MyEvent, (void *) 81);
	eventid[i++] = b.AddEvent("#1# hits you for #2# damage.", MyEvent, (void *) 82);

	nevent = 0;
	b.Feed("[MQ2] Autoassist your mom");
	CheckOne(78);

	nevent = 0;
	b.Feed("Text with extra bits of portion");
	if (nevent != 2) {
	    printf("bad event count %d != 2\n", nevent);
	    exit(1);
	}
	if ((eventarray[0].id != 0) && (eventarray[0].id != 1)) {
	    printf("wrong events triggerd %d -- not 0 or 1\n", eventarray[0].id);
	    exit(1);
	}

	nevent = 0;
	b.Feed("notText with extra bits of portion");
	CheckOne(1);

	nevent = 0;
	b.Feed("[MQ2] maxbuffs 145");
	CheckOne(26);
	if (eventarray[0].nvalues != 1) {
	    printf("bad value count %d != 1\n", eventarray[0].nvalues);
	    exit(1);
	}
	if (strcmp(eventarray[0].name[0], "1")) {
	    printf("bad value name '%s' != 1\n", eventarray[0].name[0]);
	    exit(1);
	}
	if (strcmp(eventarray[0].value[0], "145")) {
	    printf("bad value value '%s' != 145\n", eventarray[0].value[0]);
	    exit(1);
	}

	nevent = 0;
	b.Feed("The magical barrier fades yourmoma");
	CheckOne(50);
	if (eventarray[0].nvalues != 1) {
	    printf("bad value count %d != 1\n", eventarray[0].nvalues);
	    exit(1);
	}
	if (strcmp(eventarray[0].name[0], "*")) {
	    printf("bad value name '%s' != *\n", eventarray[0].name[0]);
	    exit(1);
	}
	if (strcmp(eventarray[0].value[0], "yourmoma")) {
	    printf("bad value value '%s' != yourmoma\n", eventarray[0].value[0]);
	    exit(1);
	}


	nevent = 0;
	b.Feed("[MQ2] afhelp");
	CheckOne(65);

	nevent = 0;
	b.Feed("[MQ2] ma 1");
	CheckOne(46);

	nevent = 0;
	b.Feed("You can use the ability Fellstrike Discipline again in 20 minute(s) 19 seconds.");
	if (nevent != 0) {
	    printf("bad event count %d != 0\n", nevent);
	    exit(1);
	}

	nevent = 0;
	b.Feed("[MQ2] SetPCRadius");
	CheckOne(76);

	nevent = 0;
	b.Feed("[MQ2] SetNPCRadius");
	CheckOne(77);

	nevent = 0;
	b.Feed("[MQ2] itemset 3 2 1");
	CheckOne(59);
	if (eventarray[0].nvalues != 3) {
	    printf("bad value count %d != 3\n", eventarray[0].nvalues);
	    exit(1);
	}
	if (strcmp(eventarray[0].name[0], "1")) {
	    printf("bad value name0 '%s' != 1\n", eventarray[0].name[0]);
	    exit(1);
	}
	if (strcmp(eventarray[0].value[0], "3")) {
	    printf("bad value value '%s' != 3\n", eventarray[0].value[0]);
	    exit(1);
	}
	if (strcmp(eventarray[0].name[1], "2")) {
	    printf("bad value name1 '%s' != 2\n", eventarray[0].name[1]);
	    exit(1);
	}
	if (strcmp(eventarray[0].value[1], "2")) {
	    printf("bad value value '%s' != 2\n", eventarray[0].value[1]);
	    exit(1);
	}
	if (strcmp(eventarray[0].name[2], "3")) {
	    printf("bad value name2 '%s' != 3\n", eventarray[0].name[2]);
	    exit(1);
	}
	if (strcmp(eventarray[0].value[2], "1")) {
	    printf("bad value value '%s' != 1\n", eventarray[0].value[2]);
	    exit(1);
	}
	nevent = 0;
	b.Feed("a mob with space in name begins to cast a spell.");
	CheckOne(81);
	if (eventarray[0].nvalues != 1) {
	    printf("bad value count %d != 1\n", eventarray[0].nvalues);
	    exit(1);
	}
	if (strcmp(eventarray[0].name[0], "1")) {
	    printf("bad value name '%s' != 1\n", eventarray[0].name[0]);
	    exit(1);
	}
	if (strcmp(eventarray[0].value[0], "a mob with space in name")) {
	    printf("bad value value '%s' != 'a mob with space in name'\n", eventarray[0].value[0]);
	    exit(1);
	}
	nevent = 0;
	b.Feed("a mob hits you for lots of damage.");
	if (nevent != 2) {
	    printf("bad event count %d != 2\n", nevent);
	    exit(1);
	}
	if (strcmp(eventarray[1].name[0], "1")) {
	    printf("bad value name0 '%s' != 1\n", eventarray[1].name[0]);
	    exit(1);
	}
	if (strcmp(eventarray[1].value[0], "a mob")) {
	    printf("bad value value '%s' != a mob\n", eventarray[1].value[0]);
	    exit(1);
	}
	if (strcmp(eventarray[1].name[1], "2")) {
	    printf("bad value name1 '%s' != 2\n", eventarray[1].name[1]);
	    exit(1);
	}
	if (strcmp(eventarray[1].value[1], "lots of")) {
	    printf("bad value value '%s' != lots of\n", eventarray[1].value[1]);
	    exit(1);
	}

	nevent = 0;
	b.Feed("A bat hits you for 4 damage.");
	if (nevent != 2) {
	    printf("bad event count %d != 2\n", nevent);
	    exit(1);
	}
	if (eventarray[1].nvalues != 2) {
	    printf("bad value count %d != 2\n", eventarray[1].nvalues);
	    exit(1);
	}
	if (strcmp(eventarray[1].name[0], "1")) {
	    printf("bad value name0 '%s' != 1\n", eventarray[1].name[0]);
	    exit(1);
	}
	if (strcmp(eventarray[1].value[0], "A bat")) {
	    printf("bad value value '%s' != A bat\n", eventarray[1].value[0]);
	    exit(1);
	}
	if (strcmp(eventarray[1].name[1], "2")) {
	    printf("bad value name1 '%s' != 2\n", eventarray[1].name[1]);
	    exit(1);
	}
	if (strcmp(eventarray[1].value[1], "4")) {
	    printf("bad value value '%s' != 4\n", eventarray[1].value[1]);
	    exit(1);
	}

	// watch j is not initialized here
	for (; j < i; j++) {
	    if (eventid[j]) {
		if (!b.RemoveEvent(eventid[j])) {
		    printf("removal failed %d\n", j);
		    exit(1);
		}
	    } else {
		printf("no event for %d\n", j);
	    }
	}
    }
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
}
