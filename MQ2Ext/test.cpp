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
#include "../eqlib/mq.h"

main()
{
    PCHARINFO p = NULL;

    printf("offset Plat 0x%x\n", &p->Plat);
    printf("offset GuildID 0x%x\n", &p->GuildID);
    printf("offset BankCopper 0x%x\n", &p->BankCopper);
    printf("offset AutoSplit 0x%x\n", &p->AutoSplit);
    printf("offset hungerlevel 0x%x\n", &p->hungerlevel);
    printf("offset AAExp 0x%x\n", &p->AAExp);
}
