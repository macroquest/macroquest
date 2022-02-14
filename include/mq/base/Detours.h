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
#pragma comment(lib, "detours.lib")

namespace mq {

// 20 bytes replicates functionality of collision detection from before. It's possible this number can be tweaked or removed
#define DETOUR_COUNT 20

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
}

class Detour : public std::enable_shared_from_this<Detour>
{
public:
	uintptr_t Address() const { return m_address; }
	uint8_t* Bytes() { return reinterpret_cast<uint8_t*>(m_bytes); }

	void Add() { AddToMap(); }
	void Drop() { RemoveFromMap(); }

	template <typename T>
	static std::enable_if_t<!std::is_member_pointer_v<T>, void> Add(uintptr_t address, T& detour, T*& target, std::string_view name)
	{
		auto ptr = std::make_shared<Detour>(address, &(void*&)target, detour, name);
		ptr->AddToMap();
	}

	template <typename T>
	static std::enable_if_t<std::is_member_pointer_v<T>, void> Add(uintptr_t address, T& detour, T* target, std::string_view name)
	{
		auto ptr = std::make_shared<Detour>(address, (void**)target, detour, name);
		ptr->AddToMap();
	}

	template <typename T>
	static std::enable_if_t<std::is_member_pointer_v<T>, void> Add(uintptr_t address, T&& detour, T* target, std::string_view name)
	{
		auto ptr = std::make_shared<Detour>(address, (void**)target, *(void**)&detour, name);
		ptr->AddToMap();
	}

	template <typename T>
	static std::enable_if_t<std::is_pointer_v<T>, void> Add(uintptr_t address, T&& detour, T* target, std::string_view name)
	{
		auto ptr = std::make_shared<Detour>(address, &(void*&)*target, detour, name);
		ptr->AddToMap();
	}

	template <typename T, typename U>
	static std::enable_if_t<!std::is_same_v<T, U>, void> Add(uintptr_t address, T&& detour, U* target, std::string_view name)
	{
		static_assert(false, "Detour and Trampoline types differ in their signatures!");
	}

	MQLIB_OBJECT Detour(uintptr_t address, void** target, void* detour, const std::string_view name);
	MQLIB_OBJECT virtual ~Detour();

protected:
	MQLIB_OBJECT void AddToMap();
	MQLIB_OBJECT void RemoveFromMap();

	static inline uintptr_t GetAddressFromProc(const char* handle, const char* procedure)
	{
		auto mod = ::GetModuleHandleA(handle);
		if (mod != 0)
			return reinterpret_cast<uintptr_t>(GetProcAddress(mod, procedure));

		return {};
	}

	static inline HMODULE GetModuleFromAddress(const uintptr_t address)
	{
		HMODULE mod;
		::GetModuleHandleExA(
			GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
			GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			(const char*)address,
			&mod);

		return mod;
	}

private:
	const uintptr_t m_address;
	const std::string_view m_name;
	uint8_t m_bytes[DETOUR_COUNT];

	void** m_target;
	void*  m_detour;
};


MQLIB_API void RemoveDetour(uintptr_t address);

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

#define EzDetour(address, detour, trampoline) Detour::Add(static_cast<uintptr_t>(address), detour, trampoline##_Ptr, STRINGIFY(offset))

// TODO: deprecate DETOUR_TRAMPOLINE_EMPTY to point to a wiki page with the new detours API
#define DETOUR_TRAMPOLINE_EMPTY(...) \
	static_assert(false, "DETOUR_TRAMPOLINE_EMPTY is no longer supported. Use DETOUR_TRAMPOLINE_DEF and the new Detours API instead.");

} // namespace mq
