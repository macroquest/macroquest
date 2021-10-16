/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

MQLIB_API bool AddDetour(uintptr_t address,
	uint8_t* pfDetour = nullptr,
	uint8_t* pfTrampoline = nullptr,
	uint32_t dwSize = 20,
	const char* szName = nullptr);

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
}

template <typename Detour, typename Trampoline>
void AddDetourUnchecked(uintptr_t address, Detour detour, Trampoline trampoline, const char* name = nullptr) {
	AddDetour(address,
		(uint8_t*)detail::extract_fn_addr(detour),
		(uint8_t*)detail::extract_fn_addr(trampoline), 20, name);
}

template <typename Detour, typename Trampoline>
void AddDetourChecked(uintptr_t address, Detour detour, Trampoline trampoline, const char* name = nullptr) {
	static_assert(std::is_same_v<Detour, Trampoline>, "AddDetour: Detour and Trampoline types must match!");
	AddDetourUnchecked(address, detour, trampoline, name);
}

template <typename Detour, typename Trampoline>
void AddDetourf(uintptr_t address, Detour detour, Trampoline trampoline, const char* name = nullptr) {
	AddDetourChecked(address, detour, trampoline, name);
}


MQLIB_API void RemoveDetour(uintptr_t address);
MQLIB_API void DeleteDetour(uintptr_t address);

#define EzDetour(offset, detour, trampoline) AddDetourChecked((uintptr_t)offset, detour, trampoline, STRINGIFY(offset))
#define EzDetourwName(offset, detour, trampoline, name) AddDetourChecked((uintptr_t)offset, detour, trampoline, name)

// For those use cases where the answer is: "I know what I'm doing."
#define EzDetourUnchecked(offset, detour, trampoline) AddDetourUnchecked((uintptr_t)offset, detour, trampoline, STRINGIFY(offset))

} // namespace mq
