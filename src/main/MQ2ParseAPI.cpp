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

#include "pch.h"
#include "MQ2Main.h"

using namespace mq::datatypes;
namespace mq {

void InitializeParser()
{
	DebugSpewNoFile("InitializeParser()");

	InitializeMQ2DataTypes();
	InitializeMQ2Data();

	bmParseMacroParameter = AddMQ2Benchmark("ParseMacroParameter");
}

void ShutdownParser()
{
	DebugSpewNoFile("ShutdownParser()");

	ShutdownMQ2Data();
	ShutdownMQ2DataTypes();
}

char* ParseMacroParameter(PSPAWNINFO pChar, char* szOriginal, size_t BufferSize)
{
	EnterMQ2Benchmark(bmParseMacroParameter);

	ParseMacroData(szOriginal, BufferSize);

	ExitMQ2Benchmark(bmParseMacroParameter);
	return (szOriginal);
}

} // namespace mq
