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

#include "ModuleSystem.h"
#include "MQ2Main.h"

using namespace eqlib;

namespace mq {

std::vector<std::unique_ptr<MQBenchmark>> gBenchmarks;

uint32_t AddBenchmark(const char* Name)
{
	SPDLOG_TRACE("AddBenchmark({})", Name);

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

void RemoveBenchmark(uint32_t BMHandle)
{
	SPDLOG_TRACE("RemoveBenchmark({})", BMHandle);

	if (BMHandle < gBenchmarks.size() && gBenchmarks[BMHandle])
	{
		gBenchmarks[BMHandle].reset();
	}
	else
	{
		SPDLOG_WARN("RemoveBenchmark({}) failed", BMHandle);
	}
}

void EnterBenchmark(uint32_t BMHandle)
{
	if (BMHandle < gBenchmarks.size() && gBenchmarks[BMHandle])
	{
		gBenchmarks[BMHandle]->Entry = std::chrono::steady_clock::now();
	}
}

void ExitBenchmark(uint32_t BMHandle)
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

bool GetBenchmark(uint32_t BMHandle, MQBenchmark& Dest)
{
	if (BMHandle < gBenchmarks.size() && gBenchmarks[BMHandle])
	{
		Dest = *gBenchmarks[BMHandle]; // give them a copy of the data.
		return true;
	}

	return false;
}

void Cmd_DumpBenchmarks(PlayerClient*, char* szLine)
{
	if (szLine && szLine[0] == '/')
	{
		uint64_t Start = MQGetTickCount64();
		DoCommand(szLine, false);

		uint64_t Time = MQGetTickCount64() - Start;
		WriteChatf("\ay%s\ax completed in \at%.2f\axs", szLine, static_cast<double>(Time) / 1000.);
	}
	else
	{
		WriteChatColor("MacroQuest Benchmarks");
		WriteChatColor("--------------");

		for (auto& pBenchmark : gBenchmarks)
		{
			if (pBenchmark)
			{
				float AvgMS = 0;
				if (pBenchmark->Count)
					AvgMS = static_cast<float>(pBenchmark->TotalTime.count()) / static_cast<float>(pBenchmark->Count) / 1000.f;
				float TotalMS = static_cast<float>(pBenchmark->TotalTime.count()) / 1000.f;

				WriteChatf("[\ay%s\ax] \at%I64u\ax for \at%.3fu\axms, \at%.3f\axms avg",
					pBenchmark->Name.c_str(), pBenchmark->Count, TotalMS, AvgMS);
			}
		}

		WriteChatColor("--------------");
		WriteChatColor("End Benchmarks");
	}
}

void DumpBenchmarks()
{
	DebugSpewAlways("MacroQuest Benchmarks");
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

//=================================================================================================

class BenchmarksModule : public MQModuleBase
{
public:
	BenchmarksModule() : MQModuleBase("Benchmarks")
	{
	}

	virtual void Initialize() override
	{
		AddCommand("/benchmark", Cmd_DumpBenchmarks, false, false);
	}

	virtual void Shutdown() override
	{
		DumpBenchmarks();

		RemoveCommand("/benchmark");

		gBenchmarks.clear();
	}
};

DECLARE_MODULE_FACTORY(BenchmarksModule);

} // namespace mq
