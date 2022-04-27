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
#pragma comment(lib, "detours.lib")

namespace mq {

// 20 bytes replicates functionality of collision detection from before. It's possible this number can be tweaked or removed
constexpr uint32_t DETOUR_BYTES_COUNT = 20;

// this defines a trampoline for the user, based on the detour signature
#define DETOUR_TRAMPOLINE_DEF(ret, name, argtypes) \
ret name##_Placeholder##argtypes; \
using name##_Type = decltype(&name##_Placeholder); \
inline static decltype(&name##_Placeholder) name##_Ptr = nullptr; \
template <typename... Args> \
ret name(Args&&... args) { \
	if constexpr (std::is_member_function_pointer_v<name##_Type>) \
		return (this->*name##_Ptr)(std::forward<Args>(args)...); \
	else \
		return (name##_Ptr)(std::forward<Args>(args)...); \
}

// TODO: deprecate DETOUR_TRAMPOLINE_EMPTY to point to a wiki page with the new detours API
#define DETOUR_TRAMPOLINE_EMPTY(...) \
	static_assert(false, "DETOUR_TRAMPOLINE_EMPTY is no longer supported. Use DETOUR_TRAMPOLINE_DEF and the new Detours API instead.");


namespace detail
{
	template <typename Fn, size_t width = sizeof(Fn)>
	uintptr_t extract_fn_addr(Fn fn)
	{
		static_assert(width == 4u || width == 8u || width == 12u);

		if constexpr (width == 4u || width == 8u)
			return reinterpret_cast<uintptr_t*>(&fn)[0];

		if constexpr (width == 12u)
			return reinterpret_cast<uintptr_t*>(&fn)[1];

		return 0;
	}

	template <typename Fn, size_t width = sizeof(Fn)>
	void set_fn_ptr(Fn& fn, uintptr_t ptr)
	{
		static_assert(width == 4u || width == 8u || width == 12u);

		if constexpr (width == 4u || width == 8u)
			reinterpret_cast<uintptr_t*>(&fn)[0] = ptr;
		else // width == 12u
			reinterpret_cast<uintptr_t*>(&fn)[1] = ptr;
	}

	MQLIB_OBJECT void CreateDetour(uintptr_t address, void** target, void* detour, const std::string_view name);
	MQLIB_OBJECT void CreateDetour(uintptr_t address, std::string_view name);

	template <typename T>
	inline std::enable_if_t<!std::is_member_pointer_v<T>, void> AddDetour(uintptr_t address, T& detour, T*& target, std::string_view name)
	{
		CreateDetour(address, &(void*&)target, detour, name);
	}

	template <typename T>
	inline std::enable_if_t<std::is_member_pointer_v<T>, void> AddDetour(uintptr_t address, T& detour, T* target, std::string_view name)
	{
		CreateDetour(address, (void**)target, detour, name);
}

	template <typename T>
	inline std::enable_if_t<std::is_member_pointer_v<T>, void> AddDetour(uintptr_t address, T&& detour, T* target, std::string_view name)
	{
		CreateDetour(address, (void**)target, *(void**)&detour, name);
	}

	template <typename T>
	inline std::enable_if_t<std::is_pointer_v<T>, void> AddDetour(uintptr_t address, T&& detour, T* target, std::string_view name)
	{
		CreateDetour(address, &(void*&)*target, detour, name);
	}

	template <typename T, typename U>
	inline std::enable_if_t<!std::is_same_v<T, U>, void> AddDetour(uintptr_t address, T&& detour, U* target, std::string_view name)
	{
		static_assert(false, "Detour and Trampoline types differ in their signatures!");
	}
}

template <typename T, typename U>
inline void AddDetour(uintptr_t address, T&& target, U&& detour, std::string_view name)
{
	mq::detail::AddDetour(address, std::forward<T>(target), std::forward<U>(detour), name);
}

inline void AddDetourBytes(uintptr_t address, std::string_view name)
{
	mq::detail::CreateDetour(address, name);
}

// Helper macros for adding detours
#define EzDetour(address, detour, trampoline) \
	mq::AddDetour(static_cast<uintptr_t>(address), detour, trampoline##_Ptr, STRINGIFY(address))
#define PatchDetour(address) \
	mq::AddDetourBytes(static_cast<uintptr_t>(address), STRINGIFY(address))

MQLIB_API void RemoveDetour(uintptr_t address);

} // namespace mq
