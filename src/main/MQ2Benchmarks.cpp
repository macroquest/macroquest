/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

std::vector<std::unique_ptr<MQBenchmark>> gBenchmarks;

uint32_t AddMQ2Benchmark(const char* Name)
{
	DebugSpew("AddMQ2Benchmark(%s)", Name);

	// find an unused index from members.
	int index = -1;
	for (int i = 0; i < (int)gBenchmarks.size(); ++i)
	{
		if (gBenchmarks[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		gBenchmarks.emplace_back();
		index = static_cast<int>(gBenchmarks.size()) - 1;
	}

	gBenchmarks[index] = std::make_unique<MQBenchmark>(Name);
	return index;
}

void RemoveMQ2Benchmark(uint32_t BMHandle)
{
	DebugSpewAlways("RemoveMQ2Benchmark()");

	if (BMHandle < gBenchmarks.size() && gBenchmarks[BMHandle])
	{
		gBenchmarks[BMHandle].reset();
	}
	else
	{
		DebugSpewAlways("RemoveMQ2Benchmark() failed.");
	}
}

void EnterMQ2Benchmark(uint32_t BMHandle)
{
	if (BMHandle < gBenchmarks.size() && gBenchmarks[BMHandle])
	{
		gBenchmarks[BMHandle]->Entry = std::chrono::steady_clock::now();
	}
}

void ExitMQ2Benchmark(uint32_t BMHandle)
{
	if (BMHandle < gBenchmarks.size() && gBenchmarks[BMHandle])
	{
		MQBenchmark& benchmark = *gBenchmarks[BMHandle];

		std::chrono::microseconds Time = std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::steady_clock::now() - benchmark.Entry);

		benchmark.LastTime += Time;
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
	if (BMHandle < gBenchmarks.size() && gBenchmarks[BMHandle])
	{
		Dest = *gBenchmarks[BMHandle]; // give them a copy of the data.
		return true;
	}

	return false;
}

void Cmd_DumpBenchmarks(SPAWNINFO* pChar, char* szLine)
{
	// Execute and time a command starting with '/'
	if (szLine && szLine[0] == '/')
	{
		uint64_t start = MQGetTickCount64();
		DoCommand(szLine, false);
		double time = (MQGetTickCount64() - start) / 1000.0;
		WriteChatf("\ay%s\ax took \at%.2f\axs", szLine, time);
		return;
	}

	// Since it doesn't start with a slash, let's check there is a benchmark name to match
	// "/benchmark mq2nav" for example
	if (szLine && szLine[0])
	{
		for (const auto& bench : gBenchmarks)
		{
			if (bench && ci_equals(bench->Name, szLine))
			{
				WriteChatf("Start %s Benchmark", szLine);
				WriteChatColor("--------------");

				float avgMs = bench->Count ? bench->TotalTime.count() / static_cast<float>(bench->Count) / 1000.f : 0;
				float totalMs = bench->TotalTime.count() / 1000.f;

				WriteChatf("[\ay%s\ax] \at%I64u\ax runs, \at%.3f\axms total, \at%.3f\axms avg",
					bench->Name.c_str(), bench->Count, totalMs, avgMs);
				WriteChatf("End %s Benchmark", szLine);
				WriteChatColor("--------------");
				return;
			}
		}

		WriteChatf("Could not find benchmark \"%s\".", szLine);
	}
	// Otherwise, show all benchmarks
	else
	{
		WriteChatColor("MQ Benchmarks");
		WriteChatColor("--------------");
		for (const auto& bench : gBenchmarks)
		{
			if (bench)
			{
				float avgMs = bench->Count ? bench->TotalTime.count() / static_cast<float>(bench->Count) / 1000.f : 0;
				float totalMs = bench->TotalTime.count() / 1000.f;

				WriteChatf("[\ay%s\ax] \at%I64u\ax runs, \at%.3f\axms total, \at%.3f\axms avg",
					bench->Name.c_str(), bench->Count, totalMs, avgMs);
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

	for (auto& pBenchmark : gBenchmarks)
	{
		if (pBenchmark)
		{
			float AvgMS = 0;
			if (pBenchmark->Count)
				AvgMS = static_cast<float>(pBenchmark->TotalTime.count()) / static_cast<float>(pBenchmark->Count) / 1000.f;
			float TotalMS = static_cast<float>(pBenchmark->TotalTime.count()) / 1000.f;

			DebugSpewAlways("%-40s  %d for %.3fms, %.3fms avg",
				pBenchmark->Name.c_str(), pBenchmark->Count, TotalMS, AvgMS);
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

	gBenchmarks.clear();
}

} // namespace mq
