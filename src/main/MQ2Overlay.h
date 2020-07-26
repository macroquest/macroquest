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

#pragma once

#include <cstdint>
#include <chrono>

namespace mq {

extern float gCurrentFPS;
extern float gCurrentCPU;
extern bool gbFrameLimiterEnabled;

class FrameThrottler
{
public:
	FrameThrottler() = default;

	void SetMinDuration(std::chrono::microseconds duration)
	{
		m_minDuration = duration;
		m_previous = std::chrono::steady_clock::now();
	}

	std::chrono::microseconds GetMinDuration() const
	{
		return m_minDuration;
	}

	void Prepare()
	{
		m_previous = std::chrono::steady_clock::now() - m_minDuration;
	}

	std::chrono::microseconds ThrottleFrame(std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now())
	{
		using namespace std::chrono_literals;

		auto delta = std::chrono::duration_cast<std::chrono::microseconds>(now - m_previous);

		if (delta < 0ms)
			m_previous = now;
		else if (delta < m_minDuration)
			return std::chrono::duration_cast<std::chrono::microseconds>(m_minDuration - delta);

		m_previous += m_minDuration;
		return 0ms;
	}

private:
	std::chrono::steady_clock::time_point m_previous;
	std::chrono::microseconds m_minDuration;
};

class FrameCounter
{
public:
	static const int SampleCount = 32;

	FrameCounter()
	{
		memset(m_samples, 0, sizeof(m_samples));
	}

	void AddSample(int64_t sample)
	{
		m_sum -= m_samples[m_index];
		m_sum += sample;
		m_samples[m_index++] = sample;

		if (m_index == SampleCount)
			m_index = 0;
	}

	void AddRelativeSample(int64_t relativeSample)
	{
		if (m_isFirstSample)
		{
			m_isFirstSample = false;
			m_prevSample = relativeSample;
			return;
		}

		int64_t sample = relativeSample - m_prevSample;
		m_prevSample = relativeSample;

		AddSample(sample);
	}

	double Average() const { return m_sum == 0 ? 0.0 : ((double)m_sum / SampleCount); }

	void Clear()
	{
		m_sum = 0;
		m_index = 0;
		m_prevSample = 0;
		m_isFirstSample = true;
	}

private:
	int64_t m_samples[SampleCount];
	int64_t m_sum = 0;
	int64_t m_prevSample = 0;
	int m_index = 0;
	bool m_isFirstSample = true;
};


} // namespace mq
