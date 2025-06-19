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

#pragma once

#include <fmt/format.h>

#include <chrono>
#include <memory>
#include <string>
#include <vector>

namespace mq {

bool AddDataVariable(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, const char* Default);
bool DeleteDataVariable(const char* Name);
void ClearDataVariables(MQDataVar** ppHead);

MQDataVar** FindVariableScope(const char* Name);

class StackFrame
{
public:
	StackFrame(std::string subroutine, std::vector<std::string> arguments);

	void AddChild(std::unique_ptr<StackFrame> child);
	void End(std::string returnValue);

	std::chrono::microseconds GetMicrosecondsInclusive() const
	{
		return std::chrono::duration_cast<std::chrono::microseconds>(m_endTime - m_startTime);
	}

	std::chrono::microseconds GetMicrosecondsExclusive() const
	{
		std::chrono::microseconds total = GetMicrosecondsInclusive();

		for (const std::unique_ptr<StackFrame>& child : m_children)
			total -= child->GetMicrosecondsInclusive();

		return total;
	}

	uint64_t GetCommandCountInclusive() const
	{
		return m_endCommandCount - m_startCommandCount;
	}

	uint64_t GetCommandCountExclusive() const
	{
		uint64_t total = GetCommandCountInclusive();

		for (const std::unique_ptr<StackFrame>& child : m_children)
			total -= child->GetCommandCountInclusive();

		return total;
	}

	std::string format_csv(int depth, std::chrono::high_resolution_clock::time_point beginTime) const;

	void format_csv(fmt::appender& buffer, int depth, std::chrono::high_resolution_clock::time_point beginTime) const;

private:
	std::string m_subroutine;
	std::vector<std::string> m_args;
	std::string m_returnValue;
	bool m_returned = false;

	uint64_t m_startCommandCount;
	uint64_t m_endCommandCount;
	std::chrono::high_resolution_clock::time_point m_startTime;
	std::chrono::high_resolution_clock::time_point m_endTime;
	std::vector<std::unique_ptr<StackFrame>> m_children;
};

//-------------------------------------------------------------------------------------------------

class ProfileSession
{
public:
	ProfileSession(std::string name);

	void Call(std::string subroutine, std::vector<std::string> args);

	void Return(std::string returnValue);

	void End();

	const std::string& GetName() const { return m_name; }
	std::string to_string() const;

private:
	std::string m_name;
	std::deque<std::unique_ptr<StackFrame>> m_callStack;

	std::chrono::high_resolution_clock::time_point m_startTime;
};

extern ProfileSession* g_pProfile;

} // namespace mq

