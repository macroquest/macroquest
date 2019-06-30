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

#include "Common.h"

#include <atomic>

namespace eqlib {

class CMutexSync
{
public:
	CMutexSync()
	{
		InitializeCriticalSection(&critical_section);
		count = 0;
	}

	~CMutexSync()
	{
		DeleteCriticalSection(&critical_section);
	}

	void lock()
	{
		EnterCriticalSection(&critical_section);
		++count;
	}

	void unlock()
	{
		--count;
		LeaveCriticalSection(&critical_section);
	}

private:
	CRITICAL_SECTION critical_section;
	std::atomic<int> count;
};

class ScopedLockedMutex
{
public:
	ScopedLockedMutex(CMutexSync* mutex_)
		: mutex(mutex_)
	{
		if (mutex) mutex->lock();
	}

	~ScopedLockedMutex()
	{
		if (mutex) mutex->unlock();
	}

private:
	CMutexSync* mutex = nullptr;
};

} // namespace eqlib