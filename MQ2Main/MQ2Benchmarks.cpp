/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "MQ2Main.h"

using BMIndex = CIndex<MQBENCH*>;
BMIndex* pBenchmarks = nullptr;

uint32_t AddMQ2Benchmark(const char* Name)
{
	DebugSpew("AddMQ2Benchmark(%s)", Name);
	auto& benchmarks = *pBenchmarks;

	DWORD NewHandle = pBenchmarks->GetUnused();
	benchmarks[NewHandle] = new MQBENCH;

	memset(benchmarks[NewHandle], 0, sizeof(MQBENCH));
	strcpy_s(benchmarks[NewHandle]->szName, Name);

	return NewHandle;
}

void RemoveMQ2Benchmark(uint32_t BMHandle)
{
	DebugSpewAlways("RemoveMQ2Benchmark()");
	auto& benchmarks = *pBenchmarks;

	if (BMHandle && benchmarks[BMHandle])
	{
		delete benchmarks[BMHandle];
		benchmarks[BMHandle] = 0;
	}
	else
	{
		DebugSpewAlways("RemoveMQ2Benchmark() failed.");
	}
}

void EnterMQ2Benchmark(uint32_t BMHandle)
{
	if (!pBenchmarks)
		return;

	auto& benchmarks = *pBenchmarks;
	if (benchmarks[BMHandle])
	{
		//DebugSpew("EnterMQ2Benchmark(%s)", benchmarks[BMHandle]->szName);
		benchmarks[BMHandle]->Entry = MQGetTickCount64();
	}
}

void ExitMQ2Benchmark(uint32_t BMHandle)
{
	if (!pBenchmarks)
		return;

	auto& benchmarks = *pBenchmarks;
	if (benchmarks[BMHandle])
	{
		uint64_t Time = MQGetTickCount64() - benchmarks[BMHandle]->Entry;
		//DebugSpew("ExitMQ2Benchmark(%s)",Benchmarks[BMHandle]->szName);

		benchmarks[BMHandle]->LastTime = Time;
		if (benchmarks[BMHandle]->Count > 4000000000)
		{
			benchmarks[BMHandle]->Count = 1;
			benchmarks[BMHandle]->TotalTime = Time;
		}
		else
		{
			benchmarks[BMHandle]->Count++;
			benchmarks[BMHandle]->TotalTime += Time;
		}
	}
}

bool GetMQ2Benchmark(uint32_t BMHandle, MQBENCH& Dest)
{
	if (!pBenchmarks)
		return false;

	auto& benchmarks = *pBenchmarks;
	if (benchmarks[BMHandle])
	{
		Dest = *benchmarks[BMHandle]; // give them a copy of the data.
		return true;
	}

	return false;
}

void Cmd_DumpBenchmarks(SPAWNINFO* pChar, char* szLine)
{
	if (szLine && szLine[0] == '/')
	{
		uint64_t Start = MQGetTickCount64();
		HideDoCommand(pChar, szLine, false);

		uint64_t Time = MQGetTickCount64() - Start;
		WriteChatf("\ay%s\ax completed in \at%.2f\axs", szLine, static_cast<double>(Time) / 1000.);
	}
	else
	{
		auto& benchmarks = *pBenchmarks;

		WriteChatColor("MQ2 Benchmarks");
		WriteChatColor("--------------");

		for (unsigned long i = 0; i < pBenchmarks->Size; i++)
		{
			if (benchmarks[i])
			{
				float Avg = 0;
				if (benchmarks[i]->Count)
					Avg = static_cast<float>(benchmarks[i]->TotalTime) / static_cast<float>(benchmarks[i]->Count);

				WriteChatf("[\ay%s\ax] \at%I64u\ax for \at%I64u\axms, \at%.2f\ax avg",
					benchmarks[i]->szName, benchmarks[i]->Count, benchmarks[i]->TotalTime, Avg);
			}
		}

		WriteChatColor("--------------");
		WriteChatColor("End Benchmarks");
	}
}

void DumpBenchmarks()
{
	auto& benchmarks = *pBenchmarks;

	DebugSpewAlways("MQ2 Benchmarks");
	DebugSpewAlways("--------------");

	for (unsigned long i = 0; i < pBenchmarks->Size; i++)
	{
		if (benchmarks[i])
		{
			float Avg = 0;
			if (benchmarks[i]->Count)
				Avg = static_cast<float>(benchmarks[i]->TotalTime) / static_cast<float>(benchmarks[i]->Count);

			DebugSpewAlways("%-40s  %d for %dms, %.2f avg",
				benchmarks[i]->szName, benchmarks[i]->Count, benchmarks[i]->TotalTime, Avg);
		}
	}

	DebugSpewAlways("--------------");
	DebugSpewAlways("End Benchmarks");
}

void InitializeMQ2Benchmarks()
{
	DebugSpew("Initializing MQ2 Benchmarks");
	pBenchmarks = new BMIndex(10);

	AddCommand("/benchmark", Cmd_DumpBenchmarks, 0, 0);
}

void ShutdownMQ2Benchmarks()
{
	DebugSpew("Shutting down MQ2 Benchmarks");

	DumpBenchmarks();
	RemoveCommand("/benchmark");

	if (pBenchmarks)
	{
		pBenchmarks->Cleanup();
		delete pBenchmarks;
	}

	pBenchmarks = nullptr;
}
