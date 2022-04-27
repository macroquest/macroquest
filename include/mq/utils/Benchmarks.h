/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

#pragma once

#include <mq/base/Common.h>

namespace mq {

//----------------------------------------------------------------------------
// Benchmarks are used to measure the amount of time spent doing something. When
// entering a benchmark, the current time is taken, and when leaving, the elapsed
// time spent in the benchmark is added to the total.

struct MQBenchmark
{
	std::string Name;
	std::chrono::steady_clock::time_point Entry;
	std::chrono::microseconds LastTime = std::chrono::microseconds::zero();
	std::chrono::microseconds TotalTime = std::chrono::microseconds::zero();
	uint64_t Count = 0;

	MQBenchmark(const std::string& name) : Name(name) {}
	MQBenchmark() {}
};

//----------------------------------------------------------------------------
// Benchmarking API

// Create a new benchmark. Returns the benchmark id.
MQLIB_API uint32_t AddMQ2Benchmark(const char* Name);

// Destroy a benchmark by its id.
MQLIB_API void RemoveMQ2Benchmark(uint32_t BMHandle);

// Returns a reference to a benchmark by looking up its id.
MQLIB_API bool GetMQ2Benchmark(uint32_t BMHandle, MQBenchmark& Dest);

// Enter the benchmark and start adding time.
MQLIB_API void EnterMQ2Benchmark(uint32_t BMHandle);

// Leave the benchmark.
MQLIB_API void ExitMQ2Benchmark(uint32_t BMHandle);

//----------------------------------------------------------------------------
// Scoped benchmark object, enters the benchmark at creation and leaves the benchmark at the end
// of the current scope.
//
// Usage:
//     MQScopedBenchmark bm(benchmarkId);
//     // ... do things that take time
struct MQScopedBenchmark
{
	MQScopedBenchmark(uint32_t bmId) : m_benchmark(bmId) { EnterMQ2Benchmark(m_benchmark); }
	~MQScopedBenchmark() { ExitMQ2Benchmark(m_benchmark); }

private:
	uint32_t m_benchmark;
};


//----------------------------------------------------------------------------
// Old-style benchmark macro. Prefer using MQScopedBenchmark instead.
#ifdef DISABLE_BENCHMARKS
    #define Benchmark(BMHandle, code) code
#else
    #define Benchmark(BMHandle, code) { EnterMQ2Benchmark(BMHandle); code; ExitMQ2Benchmark(BMHandle); }
#endif

} // namespace mq
