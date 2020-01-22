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

namespace eqlib {
namespace SoeUtil {

EQLIB_OBJECT void* Alloc(int bytes, int align = 0);
EQLIB_OBJECT void Free(void* p, int align = 0);

template <typename T>
T* Align(T* p, int align)
{
	return (T*)( ((uintptr_t)p + align - 1) & ((uintptr_t)(align - 1)) );
}

#pragma region Array<T>

// class SoeUtil::Array<unsigned char, 0, 1> `RTTI Type Descriptor'
template <typename T>
class Array
{
public:
	using ValueType = T;

	Array() = default;
	Array(const T* data, int size);
	virtual ~Array();

	Array(const Array<T>& other);
	Array(Array<T>&& other);

	Array& operator=(const Array& other);
	Array& operator=(Array&& other);

	T& at(int index);
	const T& at(int index) const;

	T& operator[](int index);
	const T& operator[](int index) const;

	int GetSize() const { return m_size; }
	bool IsEmpty() const { return m_size == 0; }

	void Swap(Array* other) { SwapInternal(other, true); }

	void Clear();
	void Resize(int count);
	void Reserve(int count);

	T* begin() { return &m_array[0]; }
	const T* begin() const { return &m_array[0]; }
	T* end() { return &m_array[0] + m_count; }
	const T* end() const { return &m_array[0] + m_count; }

protected:
	virtual T* Allocate(int amount, int* allocated, bool exact);
	virtual void Free(T* data, int);
	virtual void SwapInternal(Array* other, bool);

private:
	void CopyAppend(const T* data, int amount);
	void Copy(const T* data, int amount);

private:
	T* m_array = nullptr;
	int m_size = 0;
	int m_alloc = 0;
};

//============================================================================

template <typename T>
Array<T>::Array(const T* data, int size)
{
	CopyAppend(data, amount);
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	CopyAppend(other.m_array, other.m_size);
}

template <typename T>
Array<T>::Array(Array<T>&& other)
{
	m_array = std::exchange(other.m_array, nullptr);
	m_size = std::exchange(other.m_size, 0);
	m_alloc = std::exchange(other.m_alloc, 0);
}

template <typename T>
Array<T>::~Array()
{
	Clear();
	Free(m_array, m_alloc);
	m_array = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	Clear();
	CopyAppend(other.m_array, other.m_size);

	return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& other)
{
	Clear();
	Free(m_array, m_alloc);

	m_array = std::exchange(other.m_array, nullptr);
	m_size = std::exchange(other.m_size, 0);
	m_alloc = std::exchange(other.m_alloc, 0);

	return *this;
}

template <typename T>
T& Array<T>::at(int index)
{
	assert(index >= 0 && i < m_size);
	return m_array[i];
}

template <typename T>
const T& Array<T>::at(int index) const
{
	assert(index >= 0 && i < m_size);
	return m_array[i];
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index >= m_size)
	{
		Resize(index + 1);
	}

	return m_array[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
	return at(index);
}

template <typename T>
void Array<T>::Clear()
{
	for (int i = 0; i < m_size; ++i)
	{
		m_array[i].~T();
	}

	m_size = 0;
}

template <typename T>
void Array<T>::Reserve(int count)
{
	if (count <= m_alloc)
		return;

	// allocate new buffer
	int newSize;
	T* buffer = Allocate(count, &newSize, false);

	if (buffer != m_array)
	{
		// move array
		for (int i = 0; i < m_size; ++i)
		{
			// copy
			new (&buffer[i]) T(m_array[i]);
			m_array[i].~T();
		}

		Free(m_array, m_alloc);

		m_array = buffer;
		m_alloc = newSize;
	}
}

template <typename T>
void Array<T>::Resize(int count)
{
	if (count > m_size)
	{
		// grow bigger
		Reserve(count);

		int pos = m_size;
		m_size = std::min(m_alloc, count);
		while (pos < count)
		{
			new (&m_array[pos]) T;
		}
	}
	else
	{
		// shrink
		for (int i = count; i < m_size; ++i)
		{
			m_array[i].~T();
		}

		m_size = count;
	}
}

template <typename T>
T* Array<T>::Allocate(int amount, int* allocated, bool)
{
	int currentAlloc = m_alloc;

	if (amount > currentAlloc)
	{
		*allocated = amount * 5 / 4;
		return (T*)SoeUtil::Alloc(*allocated * sizeof(T), __alignof(T));
	}

	*allocated = m_alloc;
	return m_array;
}

template <typename T>
void Array<T>::Free(T* data, int)
{
	SoeUtil::Free(data, __alignof(T));
}

template <typename T>
void Array<T>::SwapInternal(Array* other, bool)
{
	std::swap(m_array, other->m_array);
	std::swap(m_size, other->m_size);
	std::swap(m_alloc, other->m_alloc);
}

template <typename T>
void Array<T>::CopyAppend(const T* data, int amount)
{
	Reserve(m_size + amount);

	// copy forward
	const T* src = data;
	T* dst = m_array + m_size;
	m_size += amount;
	while (amount--)
	{
		new ((void*)dst) T(*src);
		dst++;
		src++;
	}
}

template <typename T>
void Array<T>::Copy(const T* data, int amount)
{
	Resize(0);
	Reserve(amount);
	CopyAppend(data, amount);
}

template <typename T>
bool swap(Array<T>& a, Array<T>& b)
{
	a.Swap(b);
}

#pragma endregion

//----------------------------------------------------------------------------

#pragma region IString

template <typename T = char>
class IString
{
public:
	IString()
	{
	}

	IString(const IString& other)
	{
		copy(other);
	}

	IString(const char* other)
	{
		copy(other);
	}

	virtual ~IString()
	{
		decrement_ref_count();
	}

	IString& operator=(const T* other)
	{
		copy(other);
		return *this;
	}

	IString& operator=(const IString& other)
	{
		copy(other);
		return *this;
	}

	IString& operator=(const std::string_view& other)
	{
		copy(other.data(), other.length());
		return *this;
	}

	virtual void* Alloc(size_t count, size_t* actual, bool* shareable)
	{
		int size = count;
		if (m_space > 0)
		{
			size += size / 4;
			size = ((size + 15) / 16) * 16;
		}

		*shareable = true;
		*actual = size;

		return (char*)SoeUtil::Alloc(size);
	}

	virtual void Free(void* data)
	{
		SoeUtil::Free(data);
	}

	EQLIB_OBJECT void Append(char* c);

	void clear()
	{
		decrement_ref_count();

		m_data = "";
		m_space = 0;
		m_length = 0;
	}

	bool empty() const { return m_length == 0; }
	const char* data() const { return m_data; }
	const char* c_str() const { return m_data; }
	size_t size() const { return m_length; }

	operator std::string_view() const noexcept
	{
		return std::string_view(data(), size());
	}

	int ref_count() const
	{
		if (m_space <= 0)
			return 0;

		return get_ref_count_ptr()->load();
	}

private:
	void copy(const T* other)
	{
		if (other == nullptr || *other == 0)
			clear();
		else if (other != m_data || m_space <= 0)
		{
			size_t len = strlen(other);
			ensure_writable(len + 1);

			std::memcpy(m_data, other, len + 1);
			m_length = len;
		}
	}

	void copy(const T* other, size_t length)
	{
		if (len == 0)
			clear();
		else
		{
			ensure_writable(length + 1);
			std::memcpy(m_data, other, length);
			m_data[length] = 0;
			m_length = length;
		}
	}

	void copy(const IString& other)
	{
		if (this == &other)
			return;

		// I could implement ref counting here but i'm just going to always copy.
		copy(other.c_str());
	}

	void ensure_writable(size_t length)
	{
		if ((int)length > m_space || ref_count() > 1)
		{
			if (length < m_length + 1)
				length = m_length + 1;

			// data we need includes the std::atomic_int
			size_t spaceNeeded = length + sizeof(std::atomic_int);
			size_t allocated = 0;
			bool shared = false;
			uint8_t* data = (uint8_t*)Alloc(spaceNeeded, &allocated, &shared);
			new (data) std::atomic_int(shared ? 1 : 0);

			T* newData = reinterpret_cast<T*>(data + sizeof(std::atomic_int));
			int newSpace = allocated - sizeof(std::atomic_int);
			int newLength = m_length;
			std::memcpy(newData, c_str(), m_length + 1);

			decrement_ref_count();

			m_data = newData;
			m_space = newSpace;
			m_length = newLength;
		}
	}

	void increment_ref_count()
	{
		int oldRefcount = std::atomic_fetch_add(get_ref_count_ptr(), 1);
		assert(oldRefCount != 0);
	}

	void decrement_ref_count()
	{
		if (m_space > 0)
		{
			auto refCount = get_ref_count_ptr();
			if (std::atomic_fetch_sub(refCount, 1) == 1)
			{
				std::destroy_at(refCount);
				Free(refCount);
			}
		}
	}

	std::atomic_int* get_ref_count_ptr()
	{
		assert(m_space > 0);

		// ref count is stored before the data.
		uint8_t* refCount = reinterpret_cast<uint8_t*>(m_data) - sizeof(std::atomic_int);
		return reinterpret_cast<std::atomic_int*>(refCount);
	}

	const std::atomic_int* get_ref_count_ptr() const
	{
		assert(m_space > 0);

		// ref count is stored before the data.
		uint8_t* refCount = reinterpret_cast<uint8_t*>(m_data) - sizeof(std::atomic_int);
		return reinterpret_cast<std::atomic_int*>(refCount);
	}

private:
/*0x04*/ T* m_data = "";
/*0x08*/ size_t m_length = 0;
/*0x0c*/ int m_space = 0;
};

using String = IString<char>;


template <typename T, int T_SIZE>
class IStringFixed : public IString<T>
{
public:
	BYTE FixedData[(T_SIZE * sizeof(T)) + sizeof(AtomicInt)];
};

template <int T_SIZE>
class StringFixed : public IStringFixed<char, T_SIZE>
{
public:
};

#pragma endregion

//----------------------------------------------------------------------------

#pragma region SharedPtr

namespace Internal
{
	// SharedData is the control block of the SoeUtil::SharedPtr
	class SharedData
	{
	public:
		SharedData() = default;

		void IncrementReferenceCount()
		{
			m_refs.fetch_add(1);
			m_strongRefs.fetch_add(1);
		}

		void DecrementReferenceCount()
		{
			m_refs.fetch_sub(1);
			m_strongRefs.fetch_sub(1);
		}

		template <typename T>
		bool is_inplace_constructed(T* p) const
		{
			return get_inplace_storage<T>() == p;
		}

		template <typename T>
		T* get_inplace_storage()
		{
			// The object is located after this object's storage aligned on m_alignment or 8.
			return Align(reinterpret_cast<uint8_t*>(this) + sizeof(this), m_alignment);
		}

	public:
		std::atomic_int32_t m_refs{ 1 };              // reference counter for SharedDaa
		std::atomic_int32_t m_strongRefs{ 1 };        // reference counter for the data
		int m_alignment = 0;
	};
}

template <typename T>
class WeakPtr;

template <typename T>
class SharedPtr
{
public:
	SharedPtr() noexcept = default;
	~SharedPtr()
	{
		decrement_ref_count();
	}

	explicit SharedPtr(T* other)
	{
		if (other)
			construct(other);
	}

	SharedPtr(nullptr_t) noexcept {}
	SharedPtr(const SharedPtr& other)
	{
		this->copy_construct_from(other);
	}

	template <typename U, std::enable_if_t<std::is_convertible<U*, T*>::type, int> = 0>
	SharedPtr(const SharedPtr<U>& other)
	{
		this->copy_construct_from(other);
	}

	SharedPtr(SharedPtr&& other)
	{
		this->move_construct_from(std::move(other));
	}

	template <typename U, std::enable_if_t<std::is_convertible<U*, T*>::type, int> = 0>
	SharedPtr(SharedPtr<U>&& other)
	{
		this->move_construct_from(std::move(other));
	}

	explicit operator bool() { return m_ptr != nullptr; }

	SharedPtr& operator=(const SharedPtr& other) noexcept
	{
		SharedPtr(other).swap(*this);
		return *this;
	}

	template <typename U, std::enable_if_t<std::is_convertible<U*, T*>::type, int> = 0>
	SharedPtr& operator=(const SharedPtr<U>& other) noexcept
	{
		SharedPtr(other).swap(*this);
		return *this;
	}

	SharedPtr& operator=(SharedPtr&& other) noexcept
	{
		SharedPtr(std::move(other)).swap(*this);
		return *this;
	}

	template <typename U, std::enable_if_t<std::is_convertible<U*, T*>::type, int> = 0>
	SharedPtr& operator=(const SharedPtr<U>&& other) noexcept
	{
		SharedPtr(std::move(other)).swap(*this);
		return *this;
	}

	T* get() const { return m_ptr; }

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

	void reset() noexcept
	{
		SharedPtr().swap(*this);
	}

	template <typename U>
	void reset(U* p)
	{
		SharedPtr(p).swap(*this);
	}

	void swap(SharedPtr& other) noexcept
	{
		std::swap(m_rep, other.m_rep);
		std::swap(m_ptr, other.m_ptr);
	}

	// get the current reference count
	[[nodiscard]] int use_count() const noexcept
	{
		return m_rep ? m_rep->m_strongRefs : 0;
	}

	// Compare the address of shared control blocks
	[[nodiscard]] bool owner_before(SharedPtr& other) const noexcept
	{
		return m_rep < other.m_rep;
	}

	template <typename U, typename ... Args>
	friend SharedPtr<U> MakeShared(Args&&... args);

private:
	void construct(T* other)
	{
		m_ptr = other;
		m_rep = new (SoeUtil::Alloc(sizeof(Internal::SharedData))) Internal::SharedData();
	}

	template <typename U>
	void copy_construct_from(const SharedPtr<U>& other) noexcept
	{
		m_ptr = other.m_ptr;
		m_rep = other.m_rep;

		increment_ref_count();
	}

	template <typename U>
	void move_construct_from(const SharedPtr<U>& other) noexcept
	{
		m_ptr = other.m_ptr;
		m_rep = other.m_rep;

		other.m_ptr = nullptr;
		other.m_rep = nullptr;
	}

	void increment_ref_count() noexcept
	{
		if (m_rep)
		{
			m_rep->IncrementReferenceCount();
		}
	}

	void decrement_ref_count() noexcept
	{
		if (m_rep)
		{
			m_rep->DecrementReferenceCount();

			if (m_rep->m_strongRefs == 0)
			{
				if (m_rep->is_inplace_constructed(m_ptr))
				{
					m_ptr->~T();
				}
				else
				{
					delete m_ptr;
					m_ptr = nullptr;
				}
			}

			if (m_rep->m_refs == 0)
			{
				m_rep->~SharedData();
				SoeUtil::Free(m_rep);

				m_rep = nullptr;
			}
		}
	}

private:
	Internal::SharedData* m_rep = nullptr;
	T* m_ptr = nullptr;
};

template <typename T, typename U>
bool operator==(const SoeUtil::SharedPtr<T>& lhs, const SoeUtil::SharedPtr<U>& rhs)
{
	return lhs.get() == rhs.get();
}

template <typename T, typename U>
bool operator!=(const SoeUtil::SharedPtr<T>& lhs, const SoeUtil::SharedPtr<U>& rhs)
{
	return lhs.get() != rhs.get();
}

template <typename T>
bool operator==(const SoeUtil::SharedPtr<T>& lhs, T* rhs)
{
	return lhs.get() == rhs;
}

template <typename T>
bool operator==(T* lhs, const SoeUtil::SharedPtr<T>& rhs)
{
	return lhs == rhs.get();
}

template <typename T>
bool operator!=(const SoeUtil::SharedPtr<T>& lhs, T* rhs)
{
	return lhs.get() != rhs;
}

template <typename T>
bool operator!=(T* lhs, const SoeUtil::SharedPtr<T>& rhs)
{
	return lhs != rhs.get();
}

template <typename T>
bool operator==(const SoeUtil::SharedPtr<T>& lhs, nullptr_t)
{
	return lhs.get() == nullptr;
}

template <typename T>
bool operator==(nullptr_t, const SoeUtil::SharedPtr<T>& rhs)
{
	return rhs.get() == nullptr;
}

template <typename T>
bool operator!=(const SoeUtil::SharedPtr<T>& lhs, nullptr_t)
{
	return lhs.get() != nullptr;
}

template <typename T>
bool operator!=(nullptr_t, const SoeUtil::SharedPtr<T>& rhs)
{
	return rhs.get() != nullptr;
}

template <typename T, typename ... Args>
SharedPtr<T> MakeShared(Args&&... args)
{
	SharedPtr<T> p;
	p.m_rep = new (SoeUtil::Alloc(sizeof(Internal::SharedData) + sizeof(T) + __alignof(T))) Internal::SharedData(__alignof(T));
	p.m_ptr = new (p.m_rep->get_inplace_storage()) T(std::forward<Args>(args)...);
	return p;
}

//----------------------------------------------------------------------------

#pragma endregion

//============================================================================

} // namespace SoeUtil
} // namespace eqlib
