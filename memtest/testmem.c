#define TESTMEM
#include "../mq2main/MQ2DetourAPI.cpp"


extern "C" {
int __cdecl _MemChecker0(unsigned char *buffer, int count);
int __cdecl _MemChecker1(unsigned char *buffer, int count, struct mckey key);
int __cdecl _MemChecker2(unsigned char *buffer, int count, struct mckey key);
int __cdecl _MemChecker3(unsigned char *buffer, int count, struct mckey key);
int __cdecl _MemChecker4(unsigned char *buffer, int count, struct mckey key);

unsigned int myextern_array[1024];


//void AddOurDetour(DWORD EQADDR_MEMCHECK) {}

DWORD EQADDR_MEMCHECK0=0;
DWORD EQADDR_MEMCHECK1=0;
DWORD EQADDR_MEMCHECK2=0;
DWORD EQADDR_MEMCHECK3=0;
DWORD EQADDR_MEMCHECK4=0;
PBYTE EQADDR_ENCRYPTPAD0=0;
PBYTE EQADDR_ENCRYPTPAD1=0;
PBYTE EQADDR_ENCRYPTPAD2=0;
PBYTE EQADDR_ENCRYPTPAD3=0;
PBYTE EQADDR_ENCRYPTPAD4=0;
}

VOID DebugSpew(PCHAR szFormat, ...)
{
    va_list vaList;
    va_start( vaList, szFormat );
    vprintf(szFormat, vaList);
}

VOID PluginsBeginZone() {}
VOID PluginsEndZone() {}

void main()
{
    int i;
    struct mckey key;
    
    //key.x = 0x78563412;
    for(i=0;i<1024;i++)
        myextern_array[i] = -i;

    extern_array0 = myextern_array;
    extern_array1 = myextern_array;
    extern_array2 = myextern_array;
    extern_array3 = myextern_array;
    extern_array4 = myextern_array;

    key.x = 0x82848687;
    printf("0:0x%x\n", _MemChecker0((unsigned char *)main, 300));
    printf("0:0x%x\n", memcheck0((unsigned char *)main, 300));

    printf("1:0x%x\n", _MemChecker1((unsigned char *)main, 50, key));
    printf("1:0x%x\n", memcheck1((unsigned char *)main, 50, key));

    printf("2:0x%x\n", _MemChecker2((unsigned char *)main, 50, key));
    printf("2:0x%x\n", memcheck2((unsigned char *)main, 50, key));

    printf("3:0x%x\n", _MemChecker3((unsigned char *)main, 300, key));
    printf("3:0x%x\n", memcheck3((unsigned char *)main, 300, key));

    printf("4:0x%x\n", _MemChecker4((unsigned char *)main, 300, key));
    printf("4:0x%x\n", memcheck4((unsigned char *)main, 300, key));


    key.x = 0;
    printf("0:0x%x\n", _MemChecker0((unsigned char *)main, 300));
    printf("0:0x%x\n", memcheck0((unsigned char *)main, 300));

    printf("1:0x%x\n", _MemChecker1((unsigned char *)main, 300, key));
    printf("1:0x%x\n", memcheck1((unsigned char *)main, 300, key));

    printf("2:0x%x\n", _MemChecker2((unsigned char *)main, 300, key));
    printf("2:0x%x\n", memcheck2((unsigned char *)main, 300, key));

    printf("3:0x%x\n", _MemChecker3((unsigned char *)main, 300, key));
    printf("3:0x%x\n", memcheck3((unsigned char *)main, 300, key));

    printf("4:0x%x\n", _MemChecker4((unsigned char *)main, 50, key));
    printf("4:0x%x\n", memcheck4((unsigned char *)main, 50, key));

}

