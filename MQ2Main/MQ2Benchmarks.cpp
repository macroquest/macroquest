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
//#define DBG_TRY

#include "MQ2Main.h"

typedef CIndex<PMQBENCH> BMIndex;
BMIndex *pBenchmarks=0;
#define Benchmarks (*pBenchmarks)

DWORD AddMQ2Benchmark(PCHAR Name)
{
    DebugSpew("AddMQ2Benchmark(%s)",Name);
    DWORD NewHandle= pBenchmarks->GetUnused();
    Benchmarks[NewHandle]=new MQBENCH;
    memset(Benchmarks[NewHandle],0,sizeof(MQBENCH));
    strcpy(Benchmarks[NewHandle]->szName,Name);
    return NewHandle;
}

VOID RemoveMQ2Benchmark(DWORD BMHandle)
{
    DebugSpew("RemoveMQ2Benchmark()");
    if (Benchmarks[BMHandle])
    {
        delete Benchmarks[BMHandle];
        Benchmarks[BMHandle]=0;
    }
}

VOID EnterMQ2Benchmark(DWORD BMHandle)
{
    if (!pBenchmarks)
        return;
    if (Benchmarks[BMHandle])
    {
        //DebugSpew("EnterMQ2Benchmark(%s)",Benchmarks[BMHandle]->szName);
        Benchmarks[BMHandle]->Entry=MQGetTickCount64();
    }
}

VOID ExitMQ2Benchmark(DWORD BMHandle)
{
    if (!pBenchmarks)
        return;
    if (Benchmarks[BMHandle])
    {
        ULONGLONG Time=MQGetTickCount64()-Benchmarks[BMHandle]->Entry;
        //DebugSpew("ExitMQ2Benchmark(%s)",Benchmarks[BMHandle]->szName);
        Benchmarks[BMHandle]->LastTime=Time;
        if (Benchmarks[BMHandle]->Count>4000000000)
        {
            Benchmarks[BMHandle]->Count=1;
            Benchmarks[BMHandle]->TotalTime=Time;
        }
        else
        {
            Benchmarks[BMHandle]->Count++;
            Benchmarks[BMHandle]->TotalTime+=Time;
        }
    }
}

BOOL GetMQ2Benchmark(DWORD BMHandle, MQBENCH &Dest)
{
    if (!pBenchmarks)
        return false;
    if (Benchmarks[BMHandle])
    {
        Dest=*Benchmarks[BMHandle]; // give them a copy of the data.
        return true;
    }
    return false;
}

#ifndef ISXEQ
VOID SpewMQ2BenchmarksToChat(PSPAWNINFO pChar, PCHAR szLine)
{
    char out[256];
    if (szLine && szLine[0]=='/')
    {
        ULONGLONG Start=MQGetTickCount64();
        HideDoCommand(pChar,szLine,0);
        ULONGLONG Time=MQGetTickCount64()-Start;
        sprintf(out,"\ay%s\ax completed in \at%.2f\axs",szLine,(double)Time/(double)1000);
        WriteChatColor(out);
    }
    else
    {
        WriteChatColor("MQ2 Benchmarks");
        WriteChatColor("--------------");
        for (unsigned long i = 0 ; i < pBenchmarks->Size ; i++)
        {
            if (Benchmarks[i])
            {
                float Avg=0;
                if (Benchmarks[i]->Count)
                    Avg=(float)Benchmarks[i]->TotalTime/(float)Benchmarks[i]->Count;
                sprintf_s(out,"[\ay%s\ax] \at%I64u\ax for \at%I64u\axms, \at%.2f\ax avg",Benchmarks[i]->szName,Benchmarks[i]->Count,Benchmarks[i]->TotalTime,Avg);
                WriteChatColor(out);
            }
        }
        WriteChatColor("--------------");
        WriteChatColor("End Benchmarks");
    }
}
#endif

VOID SpewMQ2Benchmarks()
{
    DebugSpewAlways("MQ2 Benchmarks");
    DebugSpewAlways("--------------");
    for (unsigned long i = 0 ; i < pBenchmarks->Size ; i++)
    {
        if (Benchmarks[i])
        {
            float Avg=0;
            if (Benchmarks[i]->Count)
                Avg=(float)Benchmarks[i]->TotalTime/(float)Benchmarks[i]->Count;
            DebugTry(DebugSpewAlways("%-40s  %d for %dms, %.2f avg",Benchmarks[i]->szName,Benchmarks[i]->Count,Benchmarks[i]->TotalTime,Avg));
        }
    }
    DebugSpewAlways("--------------");
    DebugSpewAlways("End Benchmarks");
}

VOID InitializeMQ2Benchmarks()
{
    DebugSpew("Initializing MQ2 Benchmarks");
    pBenchmarks=new BMIndex(10);
#ifndef ISXEQ
    AddCommand("/benchmark",SpewMQ2BenchmarksToChat,0,0);
#endif
}

VOID ShutdownMQ2Benchmarks()
{
    DebugTry(SpewMQ2Benchmarks());
    DebugSpew("Shutting down MQ2 Benchmarks");
#ifndef ISXEQ
    RemoveCommand("/benchmark");
#endif
    if (pBenchmarks)
    {
        DebugTry(pBenchmarks->Cleanup());
        DebugTry(delete pBenchmarks);
    }
    pBenchmarks=0;
}
