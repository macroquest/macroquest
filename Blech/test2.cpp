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

        eventid[i++] = b.AddEvent( "[MQ2] New MTHealPoint #1#", MyEvent, (void *)22);
        eventid[i++] = b.AddEvent( "[MQ2] New TargetDAPoint #1#", MyEvent, (void *)23);
        eventid[i++] = b.AddEvent( "[MQ2] New TankHealPoint #1#", MyEvent, (void *)24);
        eventid[i++] = b.AddEvent( "[MQ2] New TopOffRange #1#", MyEvent, (void *)34);

	nevent = 0;
	b.Feed("[MQ2] New MTHealPoint 55");
	CheckOne(22);

    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!!!!!!!!!!! SUCCESS !!!!!!!!!!!!!!!!!!!\n");
}
