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

#include "mq/base/Common.h"
#include "mq/base/Traits.h"

#include "eqlib/MemoryPatcher.h"

namespace mq {

class MemoryPatcher;
class MemoryPatcherImpl;

namespace detail
{
	bool CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name);
	bool CreateDetour(uintptr_t address, size_t width, std::string_view name);

	template <typename T>
	std::enable_if_t<!std::is_member_pointer_v<T>, bool> AddDetour(uintptr_t address, T& detour, T*& target, std::string_view name)
	{
		return CreateDetour(address, &(void*&)target, detour, name);
	}

	template <typename T>
	std::enable_if_t<std::is_member_pointer_v<T>, bool> AddDetour(uintptr_t address, T& detour, T* target, std::string_view name)
	{
		return CreateDetour(address, (void**)target, detour, name);
}

	template <typename T>
	std::enable_if_t<std::is_member_pointer_v<T>, bool> AddDetour(uintptr_t address, T&& detour, T* target, std::string_view name)
	{
		return CreateDetour(address, (void**)target, *(void**)&detour, name);
	}

	template <typename T>
	std::enable_if_t<std::is_pointer_v<T>, bool> AddDetour(uintptr_t address, T&& detour, T* target, std::string_view name)
	{
		return CreateDetour(address, &(void*&)*target, detour, name);
	}

	template <typename T, typename U>
	std::enable_if_t<!std::is_same_v<T, U>, bool> AddDetour(uintptr_t, T&& detour, U*, std::string_view)
	{
		static_assert(mq::always_false<T>::value, "Detour and Trampoline types differ in their signatures!");

		return false;
	}
}

/**
 * Add a detour
 *
 * @param address Address to be detoured
 * @param target The target of the detour
 * @param detour The detour
 * @param name Name of thhe detour
 * @return True if the address was detoured
 */
template <typename T, typename U>
bool AddDetour(uintptr_t address, T&& target, U&& detour, std::string_view name)
{
	return mq::detail::AddDetour(address, std::forward<T>(target), std::forward<U>(detour), name);
}

/**
 * Remove a detour.
 *
 * @param address Address of the detour to remove.
 * @return True if the detour was removed
 */
bool RemoveDetour(uintptr_t address);

/**
 * Mark a region of memory as patched.
 *
 * The original bytes at this location will be recorded but the memory will not be modified. Use this
 * function if you intend to modify the memory yourself.
 *
 * @param address Address that was patched
 * @param numBytes The number of bytes that were patched
 * @param name Name of the address that was patched
 * @return True if the operation was successful.
 */
bool AddPatch(uintptr_t address, size_t numBytes, std::string_view name = "");

/**
 * Patch a region of memory.
 *
 * The original bytes at this location will be saved, and will be restored when the patch is removed. The
 * bytes in `newBytes` will be written to the memory at the specified address. If `expectedBytes` is provided,
 * the original bytes will be validated against the expected bytes before applying the patch. If the original bytes do not match
 * then the patch will not be applied.
 *
 * @param address Address to apply the patch
 * @param newBytes Pointer to array of `numBytes` bytes to write to the memory at the specified address.
 * @param numBytes Length of `newBytes` and `expectedBytes`
 * @param expectedBytes Optional. The expected bytes at the address. If this is provided and the original bytes
 * do not match `expectedBytes`, then the patch will not be applied
 * @param name Name of the patch
 * @return Pointer to a MemoryPatch object representing the patch at the address
 */
bool AddPatch(uintptr_t address, const uint8_t* newBytes, size_t numBytes,
	const uint8_t* expectedBytes = nullptr, std::string_view name = "");

/**
 * Patch a region of memory.
 *
 * The original bytes at this location will be saved, and will be restored when the patch is removed. The
 * bytes in `newBytes` will be written to the memory at the specified address. If `expectedBytes` is provided,
 * the original bytes will be validated against the expected bytes before applying the patch. If the original bytes do not match
 * then the patch will not be applied.
 * 
 * @param address Address to apply the patch
 * @param newBytes initializer-list containing raw bytes to write to the memory at the specified address.
 * @param expectedBytes Optional. The expected bytes at the address. If this is provided and the original bytes
 * do not match `expectedBytes`, then the patch will not be applied
 * @param name Name of the patch
 * @return Pointer to a MemoryPatch object representing the patch at the address.
 */
inline bool AddPatch(uintptr_t address, std::initializer_list<uint8_t> newBytes,
	const uint8_t* expectedBytes = nullptr, std::string_view name = "")
{
	return AddPatch(address, newBytes.begin(), newBytes.size(), expectedBytes, name);
}

/**
 * Remove a patch
 *
 * @param address Address of the patch to remove.
 * @return True if the patch was removed
 */
bool RemovePatch(uintptr_t address);


// Helper macros for adding detours

#define EzDetour(address, detour, trampoline) \
	mq::AddDetour(static_cast<uintptr_t>(address), detour, trampoline##_Ptr, STRINGIFY(address))

#define PatchDetour(address) \
	mq::AddDetourBytes(static_cast<uintptr_t>(address), STRINGIFY(address))

// Deprecated functions. Use their replacements.

DEPRECATE("Use AddPatch instead of AddDetourBytes")
inline bool AddDetourBytes(uintptr_t address, std::string_view name)
{
	return AddPatch(address, eqlib::DETOUR_BYTES_COUNT, name);
}


/**
 * A stub for the old trampoline macro. This produces a compile time error if it is still used.
 */
#define DETOUR_TRAMPOLINE_EMPTY(...) \
	static_assert(false, "DETOUR_TRAMPOLINE_EMPTY is no longer supported. Use DETOUR_TRAMPOLINE_DEF and the new Detours API instead.");


} // namespace mq
