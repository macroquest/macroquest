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

#include <memory>

// Provides Alloc and Free methods that use the everquest heap. This is to allow
// us to allocate memory in a way that can later be freed by everquest later on.
// This enables us to do things like create new strings or modify existing strings,
// insert elements into containers, etc.

namespace eqlib {

// allocate memory as if by using eq's malloc.
using eqAllocFn = void* (*)(std::size_t amount);
extern EQLIB_OBJECT eqAllocFn eqAlloc;

// free memory as if by using eq's free.
using eqFreeFn = void (*)(void*);
extern EQLIB_OBJECT eqFreeFn eqFree;

// c++17 based custom allocator for creating objects on eq's heap
template <typename T>
struct everquest_allocator
{
	using value_type = T;
	using propogate_on_container_move_assignment = std::true_type;
	using is_always_equal = std::true_type;

	everquest_allocator() noexcept {}
	everquest_allocator(const everquest_allocator&) noexcept {}
	~everquest_allocator() {}

	template <class U>
	everquest_allocator(const everquest_allocator<U>&) noexcept {}

	T* allocate(std::size_t count)
	{
		return reinterpret_cast<T*>(eqAlloc(count * sizeof(T)));
	}

	void deallocate(T* p, size_t)
	{
		eqFree(p);
	}
};

template <typename T>
bool operator==(const everquest_allocator<T>&, const everquest_allocator<T>&) noexcept
{
	return true;
}

template <typename T>
bool operator!=(const everquest_allocator<T>&, const everquest_allocator<T>&) noexcept
{
	return false;
}

// tag type used to enable the eq allocator overloads of operator new/delete
// example:
// int Foo = new(eqAllocator) int;
constexpr struct EqAllocate {} eqAllocator;

} // namespace eqlib

inline void* operator new (size_t bytes, eqlib::EqAllocate)
{
	return eqlib::eqAlloc(bytes);
}

inline void* operator new[](size_t bytes, eqlib::EqAllocate)
{
	return eqlib::eqAlloc(bytes);
}

inline void operator delete(void* m, eqlib::EqAllocate)
{
	eqlib::eqFree(m);
}

inline void operator delete[](void* m, eqlib::EqAllocate)
{
	eqlib::eqFree(m);
}

namespace eqlib {

template <class T>
struct DeleterT : public T
{
	void operator delete(void* ptr)
	{
		eqlib::eqFree(ptr);
	}

	void operator delete[](void* ptr)
	{
		eqlib::eqFree(ptr);
	}
};

template <typename T, std::enable_if_t<!std::is_trivial_v<T>, int> = 0>
inline void eqDelete(T* m)
{
	delete (DeleterT<T>*)m;
}

template <typename T, std::enable_if_t<!std::is_trivial_v<T>, int> = 0>
inline void eqVecDelete(T* m)
{
	delete[](DeleterT<T>*)m;
}

template <typename T, std::enable_if_t<std::is_trivial_v<T>, int> = 0>
inline void eqDelete(T* m)
{
	eqlib::eqFree(m);
}

template <typename T, std::enable_if_t<std::is_trivial_v<T>, int> = 0>
inline void eqVecDelete(T* m)
{
	eqlib::eqFree(m);
}

template <typename T, typename... Types, std::enable_if_t<!std::is_array_v<T> && std::is_trivial_v<T>, int> = 0>
[[nodiscard]] T* eqNew()
{
	return new (eqlib::eqAlloc(sizeof(T))) T;
}

template <typename T, typename... Types, std::enable_if_t<!std::is_array_v<T> && !std::is_trivial_v<T>, int> = 0>
[[nodiscard]] T* eqNew(Types&&... args)
{
	return new (eqAllocator) T(std::forward<Types>(args)...);
}


template <typename T, std::enable_if_t<std::is_array_v<T> && std::extent_v<T> == 0, int> = 0>
[[nodiscard]] auto eqNew(size_t size)
{
	using Elem = std::remove_extent_t<T>;
	return new (eqAllocator) Elem[size];
}

template <typename T, typename... Types, std::enable_if_t<std::extent_v<T> != 0, int> = 0>
void eqNew(Types&&...) = delete;


}