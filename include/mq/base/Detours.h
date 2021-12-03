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

class DetourAny : public std::enable_shared_from_this<DetourAny>
{
public:
	uintptr_t Address() const { return m_address; }

	void Drop() { RemoveFromMap(); }

	DetourAny(const std::string_view handle, const std::string_view procedure, const std::string_view name)
		: m_module(GetModuleHandle(std::string(handle).c_str()))
		, m_address(m_module == 0 ? 0 : reinterpret_cast<uintptr_t>(GetProcAddress(m_module, std::string(procedure).c_str())))
		, m_name(name)
	{}

	DetourAny(const uintptr_t address, const std::string_view name)
		: m_module(GetModuleFromAddress(address))
		, m_address(address)
		, m_name(name)
	{}

	virtual ~DetourAny() = 0;

protected:
	void AddToMap();
	void RemoveFromMap();

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

	static void Attach(PVOID *ppPointer, PVOID pDetour);
	static void Detach(PVOID *ppPointer, PVOID pDetour);

	const HMODULE m_module;
	const uintptr_t m_address;
	const std::string m_name;
};

template <typename Sig>
class Detour : public DetourAny
{
public:
	const Sig Trampoline() const
	{
		return m_target;
	}

	static std::shared_ptr<Detour<Sig>> Add(const std::string_view handle, const std::string_view procedure, const Sig detour, const std::string_view name)
	{
		return std::make_shared<Detour<Sig>>(handle, procedure, detour, name);
	}

	static std::shared_ptr<Detour<Sig>> Add(const uintptr_t address, const Sig detour, const std::string_view name)
	{
		return std::make_shared<Detour<Sig>>(address, detour, name);
	}

	Detour(const std::string_view handle, const std::string_view procedure, const Sig detour, const std::string_view name)
		: DetourAny(handle, procedure, name)
		, m_target(*(Sig*)&m_address)
		, m_detour(detour)
	{
		Attach(&(PVOID&)m_target, *(PVOID*)&m_detour);
		AddToMap();
	}

	Detour(const uintptr_t address, const Sig detour, const std::string_view name)
		: DetourAny(address, name)
		, m_target(*(Sig*)&address)
		, m_detour(detour)
	{
		Attach(&(PVOID&)m_target, *(PVOID*)&m_detour);
		AddToMap();
	}

	virtual ~Detour()
	{
		Detach(&(PVOID&)m_target, *(PVOID*)&m_detour);
	}

private:
	const Sig m_target;
	const Sig m_detour;
};

template <typename Sig>
std::shared_ptr<Detour<Sig>> AddDetour(const uintptr_t address, const Sig detour, const std::string_view name = "")
{
	return Detour<Sig>::Add(address, detour, name);
}

MQLIB_API void RemoveDetour(uintptr_t address);

// this defines a trampoline for the user, based on the detour signature
#define DETOUR_TRAMPOLINE_DEF(ret, name, argtypes) \
ret name##_Placeholder##argtypes; \
using name##_Type = decltype(&name##_Placeholder); \
inline static Detour<name##_Type>* name##_Ptr; \
template <typename... Args> \
ret name(Args&&... args) { \
	if constexpr (std::is_member_function_pointer_v<name##_Type>) \
		return (this->*name##_Ptr->Trampoline())(std::forward<Args>(args)...); \
	else \
		return (name##_Ptr->Trampoline())(std::forward<Args>(args)...); \
}

#define DetourDef(name, ret, ...) \
static Detour<ret(__stdcall*)(__VA_ARGS__)>* name = nullptr; \
template <typename ...Args> ret __stdcall name##_Trampoline(Args&&... args) { return (name->Trampoline())(std::forward<Args>(args)...); } \
ret __stdcall name##_Detour(__VA_ARGS__)

#define DetourDef_cdecl(name, ret, ...) \
static Detour<ret(__cdecl*)(__VA_ARGS__)>* name = nullptr; \
template <typename ...Args> ret __cdecl name##_Trampoline(Args&&... args) { return (name->Trampoline())(std::forward<Args>(args)...); } \
ret __cdecl name##_Detour(__VA_ARGS__)

#define DetourClassDef(name, classname, ret, ...) \
inline static Detour<ret(classname::*)(__VA_ARGS__)>* name = nullptr; \
template <typename ...Args> ret name##_Trampoline(Args&&... args) { return (*this.*classname::name->Trampoline())(std::forward<Args>(args)...); } \
ret name##_Detour(__VA_ARGS__)

#define DetourClassDef_WINAPI(name, classname, ret, ...) \
inline static Detour<ret(WINAPI classname::*)(__VA_ARGS__)>* name = nullptr; \
template <typename ...Args> ret WINAPI name##_Trampoline(Args&&... args) { return (*this.*name->Trampoline())(std::forward<Args>(args)...); } \
ret WINAPI name##_Detour(__VA_ARGS__)

#define EasyDetour(address, name) name = AddDetour(static_cast<uintptr_t>(address), &name##_Detour, #address).get()
#define EasyClassDetour(address, classname, name) classname::name = AddDetour(static_cast<uintptr_t>(address), &classname::name##_Detour, #address).get()

// TODO: deprecate this (and DETOUR_TRAMPOLINE_EMPTY) to point to a wiki page with the new detours API
//#define EzDetour(offset, detour, trampoline) AddDetourChecked((uintptr_t)offset, detour, trampoline, STRINGIFY(offset))
#define EzDetour(offset, detour, trampoline) \
{ auto offset##_Ptr = trampoline##_Ptr; *offset##_Ptr = AddDetour(static_cast<uintptr_t>(offset), detour, STRINGIFY(offset)).get(); }

} // namespace mq
