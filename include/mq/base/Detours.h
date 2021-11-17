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

	DetourAny(const std::string_view handle, const std::string_view procedure)
		: m_module(GetModuleHandle(std::string(handle).c_str()))
		, m_address(m_module == 0 ? 0 : reinterpret_cast<uintptr_t>(GetProcAddress(m_module, std::string(procedure).c_str())))
	{}

	DetourAny(const uintptr_t address)
		: m_module(GetModuleFromAddress(address))
		, m_address(address)
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
};

template <typename Sig>
class Detour : public DetourAny
{
public:
	const Sig Trampoline() const
	{
		return m_target;
	}

	static std::shared_ptr<Detour<Sig>> Add(const std::string_view handle, const std::string_view procedure, const Sig detour)
	{
		return std::make_shared<Detour<Sig>>(handle, procedure , detour);
	}

	static std::shared_ptr<Detour<Sig>> Add(const uintptr_t address, const Sig detour)
	{
		return std::make_shared<Detour<Sig>>(address, detour);
	}

	Detour(const std::string_view handle, const std::string_view procedure, const Sig detour)
		: DetourAny(handle, procedure)
		, m_target(*(Sig*)&m_address)
		, m_detour(detour)
	{
		Attach(&(PVOID&)m_target, *(PVOID*)&m_detour);
		AddToMap();
	}

	Detour(const uintptr_t address, const Sig detour)
		: DetourAny(address)
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
std::shared_ptr<Detour<Sig>> AddDetour(const uintptr_t address, const Sig detour)
{
	return Detour<Sig>::Add(address, detour);
}

MQLIB_API void RemoveDetour(uintptr_t address);

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

#define EasyDetour(address, name) name = AddDetour(address, &name##_Detour).get()
#define EasyClassDetour(address, classname, name) classname::name = AddDetour(address, &classname::name##_Detour).get()

// TODO: deprecate these (and DETOUR_TRAMPOLINE_EMPTY) to point to a wiki page with the new detours API
//#define EzDetour(offset, detour, trampoline) AddDetourChecked((uintptr_t)offset, detour, trampoline, STRINGIFY(offset))
//#define EzDetourwName(offset, detour, trampoline, name) AddDetourChecked((uintptr_t)offset, detour, trampoline, name)

// For those use cases where the answer is: "I know what I'm doing."
//#define EzDetourUnchecked(offset, detour, trampoline) AddDetourUnchecked((uintptr_t)offset, detour, trampoline, STRINGIFY(offset))

} // namespace mq
