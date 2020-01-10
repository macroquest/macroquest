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

namespace eqlib {

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

// Variadic expansion of bases for ForeignPointer allow us to specify multiple allowable types for
// conversion. For example:
//
//     ForeignPointer<StringTable, EQSTRINGTABLE> pStringTable;
//
// This allows us to implicitly convert into StringTable or EQSTRINGTABLE.
//
// Both are valid:
//     EQSTRINGTABLE* pTable = pStringTable;
//     StringTable* pTable = pStringTable;
//
template <typename... Args>
struct ForeignPointer_StorageBase;

template <typename T>
struct ForeignPointer_StorageBase<T>
{
	operator T* () const noexcept
	{
		return get();
	}

	void set(T* value) noexcept
	{
		if (m_ptr)
		{
			*m_ptr = value;
		}
	}

	T* get() const noexcept
	{
		return m_ptr ? *m_ptr : nullptr;
	}

protected:
	template <typename U>
	U* coerced_get() const noexcept
	{
		return (U*)get();
	}

	T** m_ptr = 0;
};

template <typename T, typename U, typename... Rest>
struct ForeignPointer_StorageBase<T, U, Rest...> : public ForeignPointer_StorageBase<T, Rest...>
{
	operator U* () const noexcept
	{
		return this->coerced_get<U>();
	}

	using ForeignPointer_StorageBase<T, Rest...>::set;

	void set(U* value) noexcept
	{
		if (m_ptr)
		{
			*m_ptr = reinterpret_cast<T*>(value);
		}
	}
};

// a Utility helper class to replace those pesky pointer defines
template <typename T, typename... Conversions>
class ForeignPointer : public ForeignPointer_StorageBase<T, Conversions...>
{
public:
	ForeignPointer() noexcept = default;
	~ForeignPointer() noexcept = default;

	ForeignPointer(uintptr_t addr) noexcept
	{ m_ptr = reinterpret_cast<T**>(addr); }
	ForeignPointer(const ForeignPointer& other) noexcept
	{ m_ptr = other.m_ptr; }
	ForeignPointer(ForeignPointer&& other) noexcept
	{ m_ptr = other.m_ptr; }

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

	ForeignPointer& operator=(nullptr_t) noexcept
	{
		if (m_ptr)
		{
			*m_ptr = nullptr;
		}

		return *this;
	}

	template <typename U>
	ForeignPointer& operator=(U* other)
	{
		this->set(other);
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

	explicit operator bool() const noexcept
	{
		return is_valid();
	}

	operator void* () const noexcept
	{
		return get();
	}

	template <typename U>
	U* get_as() const noexcept { return (U*)m_ptr; }

	bool is_valid() const noexcept { return m_ptr && *m_ptr; }

	uintptr_t get_offset() const noexcept { return reinterpret_cast<uintptr_t>(m_ptr); }
	void set_offset(uintptr_t offset) noexcept { m_ptr = reinterpret_cast<T**>(offset); }

	void reset() { m_ptr = nullptr; }
};

template <typename T>
class ForeignReference
{
public:
	ForeignReference() noexcept = default;
	~ForeignReference() noexcept = default;

	ForeignReference(uintptr_t addr) noexcept
		: m_ptr(reinterpret_cast<T*>(addr)) {}
	ForeignReference(const ForeignReference& other) noexcept
		: m_ptr(other.m_ptr) {}
	ForeignReference(ForeignReference&& other) noexcept
		: m_ptr(other.m_ptr) {}
	ForeignReference(T* other) noexcept
		: m_ptr(other) {}

	ForeignReference& operator=(const ForeignReference& other) noexcept
	{
		m_ptr = other.m_ptr;
		return *this;
	}

	ForeignReference& operator=(ForeignReference&& other) noexcept
	{
		m_ptr = other.m_ptr;
		return *this;
	}

	ForeignReference& operator=(uintptr_t other) noexcept
	{
		set_offset(other);
		return *this;
	}

	ForeignReference& operator=(T* other) noexcept
	{
		m_ptr = other;
		return *this;
	}

	operator T* () const noexcept
	{
		return get();
	}

	T& operator* () const noexcept
	{
		assert(m_ptr != nullptr);
		return *m_ptr;
	}

	T* operator->() const noexcept
	{
		return get();
	}

	explicit operator bool() const noexcept { return is_valid(); }

	T* get() const noexcept
	{
		return m_ptr;
	}

	bool is_valid() const noexcept { return m_ptr; }

	uintptr_t get_offset() const noexcept { return reinterpret_cast<uintptr_t>(m_ptr); }
	void set_offset(uintptr_t offset) noexcept { m_ptr = reinterpret_cast<T*>(offset); }

	void reset() { m_ptr = nullptr; }

private:
	T* m_ptr = nullptr;
};


} // namespace eqlib
