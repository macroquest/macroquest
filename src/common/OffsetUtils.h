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

namespace mq {
namespace offsets {

inline bool DataCompare(const uint8_t* pData, const uint8_t* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
	{
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	}
	return (*szMask) == 0;
}

inline uint32_t FindPattern(uint32_t dwAddress, uint32_t dwLen, const uint8_t* bPattern, const char* szMask)
{
	for (uint32_t i = 0; i < dwLen; i++)
	{
		if (DataCompare(reinterpret_cast<uint8_t*>(dwAddress + i), bPattern, szMask))
			return dwAddress + i;
	}

	return 0;
}

inline uint32_t GetDWordAt(uint32_t address, uint32_t numBytes)
{
	if (address)
	{
		address += numBytes;
		return *reinterpret_cast<uint32_t*>(address);
	}

	return 0;
}

inline uint32_t GetFunctionAddressAt(uint32_t address, uint32_t addressOffset, uint32_t numBytes)
{
	if (address)
	{
		uint32_t displacement = *reinterpret_cast<uint32_t*>(address + addressOffset);
		return address + displacement + numBytes;
	}

	return 0;
}

} // namespace offsets

// a Utility helper class to replace those pesky pointer defines
template <typename T>
class ForeignPointer
{
public:
	ForeignPointer() noexcept = default;
	~ForeignPointer() noexcept = default;

	ForeignPointer(uintptr_t addr) noexcept
		: m_ptr(reinterpret_cast<T**>(addr)) {}
	ForeignPointer(const ForeignPointer& other) noexcept
		: m_ptr(other.m_ptr) {}
	ForeignPointer(ForeignPointer&& other) noexcept
		: m_ptr(other.m_ptr) {}

	ForeignPointer& operator=(const ForeignPointer& other) noexcept
	{
		m_ptr = other.m_ptr;
		return *this;
	}

	ForeignPointer& operator=(ForeignPointer&& other) noexcept
	{
		m_ptr = other.m_ptr;
		return *this;
	}

	ForeignPointer& operator=(uintptr_t other) noexcept
	{
		set_offset(other);
		return *this;
	}

	T& operator*() const noexcept
	{
		assert(m_ptr != nullptr && *m_ptr != nullptr);
		return **m_ptr;
	}

	T* operator->() const noexcept
	{
		return get();
	}

	explicit operator bool() const noexcept { return is_valid(); }

	T* get() const noexcept
	{
		if (m_ptr) return *m_ptr;
		return nullptr;
	}

	bool is_valid() const noexcept { return m_ptr && *m_ptr; }

	uintptr_t get_offset() const noexcept { return reinterpret_cast<uintptr_t>(m_ptr); }
	void set_offset(uintptr_t offset) noexcept { m_ptr = reinterpret_cast<T**>(offset); }

	void reset() { m_ptr = nullptr; }

private:
	T** m_ptr = nullptr;
};

} // namespace mq
