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

#include "pch.h"
#include "MQ2Main.h"

namespace mq {

static std::vector<std::unique_ptr<MQBenchmark>> s_benchmarks;

uint32_t AddMQ2Benchmark(const char* Name)
{
	DebugSpew("AddMQ2Benchmark(%s)", Name);

	// find an unused index from members.
	int index = -1;
	for (size_t i = 0; i < s_benchmarks.size(); ++i)
	{
		if (s_benchmarks[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		s_benchmarks.emplace_back();
		index = s_benchmarks.size() - 1;
	}

	s_benchmarks[index] = std::make_unique<MQBenchmark>(Name);
	return index;
}

void RemoveMQ2Benchmark(uint32_t BMHandle)
{
	DebugSpewAlways("RemoveMQ2Benchmark()");

	if (BMHandle && s_benchmarks[BMHandle])
	{
		s_benchmarks[BMHandle].reset();
	}
	else
	{
		DebugSpewAlways("RemoveMQ2Benchmark() failed.");
	}
}

void EnterMQ2Benchmark(uint32_t BMHandle)
{
	if (s_benchmarks[BMHandle])
	{
		s_benchmarks[BMHandle]->Entry = MQGetTickCount64();
	}
}

void ExitMQ2Benchmark(uint32_t BMHandle)
{
	if (s_benchmarks[BMHandle])
	{
		MQBenchmark& benchmark = *s_benchmarks[BMHandle];

		uint64_t Time = MQGetTickCount64() - benchmark.Entry;

		benchmark.LastTime = Time;
		if (benchmark.Count > 4000000000)
		{
			benchmark.Count = 1;
			benchmark.TotalTime = Time;
		}
		else
		{
			benchmark.Count++;
			benchmark.TotalTime += Time;
		}
	}
}

bool GetMQ2Benchmark(uint32_t BMHandle, MQBenchmark& Dest)
{
	if (s_benchmarks[BMHandle])
	{
		Dest = *s_benchmarks[BMHandle]; // give them a copy of the data.
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
		WriteChatColor("MQ2 Benchmarks");
		WriteChatColor("--------------");

		for (auto& pBenchmark : s_benchmarks)
		{
			if (pBenchmark)
			{
				float Avg = 0;
				if (pBenchmark->Count)
					Avg = static_cast<float>(pBenchmark->TotalTime) / static_cast<float>(pBenchmark->Count);

				WriteChatf("[\ay%s\ax] \at%I64u\ax for \at%I64u\axms, \at%.2f\ax avg",
					pBenchmark->Name.c_str(), pBenchmark->Count, pBenchmark->TotalTime, Avg);
			}
		}

		WriteChatColor("--------------");
		WriteChatColor("End Benchmarks");
	}
}

void DumpBenchmarks()
{
	DebugSpewAlways("MQ2 Benchmarks");
	DebugSpewAlways("--------------");

	for (auto& pBenchmark : s_benchmarks)
	{
		if (pBenchmark)
		{
			float Avg = 0;
			if (pBenchmark->Count)
				Avg = static_cast<float>(pBenchmark->TotalTime) / static_cast<float>(pBenchmark->Count);

			DebugSpewAlways("%-40s  %d for %dms, %.2f avg",
				pBenchmark->Name.c_str(), pBenchmark->Count, pBenchmark->TotalTime, Avg);
		}
	}

	DebugSpewAlways("--------------");
	DebugSpewAlways("End Benchmarks");
}

void InitializeMQ2Benchmarks()
{
	DebugSpew("Initializing MQ2 Benchmarks");;

	AddCommand("/benchmark", Cmd_DumpBenchmarks, false, false);
}

void ShutdownMQ2Benchmarks()
{
	DebugSpew("Shutting down MQ2 Benchmarks");

	DumpBenchmarks();
	RemoveCommand("/benchmark");

	s_benchmarks.clear();
}

} // namespace mq
