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

	void Drop() { RemoveFromMap(); }

	template <typename Sig>
	const Sig Trampoline()
	{
		//return *(Sig*)&m_target;
		return *reinterpret_cast<Sig*>(&m_target);
	}

	template <typename Sig>
	static Sig Add(const std::string_view handle, const std::string_view procedure, Sig detour, const std::string_view name)
	{
		auto ptr = std::make_shared<Detour>(handle, procedure, *reinterpret_cast<void**>(&detour), name);
		ptr->AddToMap();
		return ptr->Trampoline<Sig>();
	}

	template <typename Sig>
	static Sig Add(const uintptr_t address, Sig detour, const std::string_view name)
	{
		auto ptr = std::make_shared<Detour>(address, *reinterpret_cast<void**>(&detour), name);
		ptr->AddToMap();
		return ptr->Trampoline<Sig>();
	}

	Detour(const std::string_view handle, const std::string_view procedure, void* detour, const std::string_view name)
		: m_module(GetModuleHandle(std::string(handle).c_str()))
		, m_address(m_module == 0 ? 0 : reinterpret_cast<uintptr_t>(GetProcAddress(m_module, std::string(procedure).c_str())))
		, m_name(name)
		, m_target(*(void**)&m_address)
		, m_detour(detour)
	{
		Attach(&m_target, m_detour);
	}

	Detour(const uintptr_t address, void* detour, const std::string_view name)
		: m_module(GetModuleFromAddress(address))
		, m_address(address)
		, m_name(name)
		, m_target(*(void**)&address)
		, m_detour(detour)
	{
		Attach(&m_target, m_detour);
	}

	virtual ~Detour()
	{
		Detach(&m_target, m_detour);
	}

protected:
	MQLIB_OBJECT void AddToMap();
	MQLIB_OBJECT void RemoveFromMap();

	static inline HMODULE GetModuleFromAddress(const uintptr_t address)
	{
		HMODULE mod;
		GetModuleHandleEx(
			GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
			GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			(LPCTSTR)address,
			&mod);

		return mod;
	}

	MQLIB_OBJECT static void Attach(void* *ppPointer, void* pDetour);
	MQLIB_OBJECT static void Detach(void* *ppPointer, void* pDetour);

	const HMODULE m_module;
	const uintptr_t m_address;
	const std::string m_name;

	void* m_target; // void** ?
	void* m_detour;
};

MQLIB_API void RemoveDetour(uintptr_t address);

// this defines a trampoline for the user, based on the detour signature
#define DETOUR_TRAMPOLINE_DEF(ret, name, argtypes) \
ret name##_Placeholder##argtypes; \
using name##_Type = decltype(&name##_Placeholder); \
inline static name##_Type name##_Ptr = nullptr; \
template <typename... Args> \
ret name(Args&&... args) { \
	if constexpr (std::is_member_function_pointer_v<name##_Type>) \
		return (this->*name##_Ptr)(std::forward<Args>(args)...); \
	else \
		return (name##_Ptr)(std::forward<Args>(args)...); \
}

template <typename Sig>
Sig AddDetour(const uintptr_t address, Sig detour, const std::string_view name)
{
	return Detour::Add<Sig>(address, detour, name);
}

template <typename T>
void AddDetour(uintptr_t offset, T detour, T &ptr, std::string_view name)
{
	ptr = AddDetour(offset, detour, name);
}

template <typename T>
void AddDetour(uintptr_t offset, T detour, T* ptr, std::string_view name)
{
	*ptr = AddDetour(offset, detour, name);
}

#define EzDetour(offset, detour, trampoline) AddDetour(static_cast<uintptr_t>(offset), detour, trampoline##_Ptr, STRINGIFY(offset))

// TODO: deprecate DETOUR_TRAMPOLINE_EMPTY to point to a wiki page with the new detours API

} // namespace mq
