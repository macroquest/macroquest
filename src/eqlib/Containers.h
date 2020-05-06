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

#include "Allocator.h"
#include "Common.h"

#include <cstdint>

namespace eqlib {

//----------------------------------------------------------------------------

class CDynamicArrayBase;

struct EQLIB_OBJECT CEQException {};
struct EQLIB_OBJECT CExceptionApplication : CEQException {};

struct EQLIB_OBJECT CExceptionMemoryAllocation : public CEQException {
	int size;

	CExceptionMemoryAllocation(int size_) : size(size_) {}
};

// inherits from CExceptionApplication and CEQException
struct EQLIB_OBJECT CDynamicArrayException : public CExceptionApplication {
	const CDynamicArrayBase* obj;

	CDynamicArrayException(const CDynamicArrayBase* obj_) : obj(obj_) {}
};

// base class for the dynamic array types
class EQLIB_OBJECT CDynamicArrayBase
{
protected:
	/*0x00*/    int m_length;
	/*0x04*/

public:
	// two names for the same thing
	int GetLength() const { return m_length; }
	bool IsEmpty() const { return m_length == 0; }

	// a microsoft extension - lets us get away with changing the implementation
	__declspec(property(get = GetLength)) int Count;

protected:
	void ThrowArrayClassException() const
	{
		throw CDynamicArrayException(this);
	}
};

#pragma region ArrayClass2<T>

// split into two types - one that is read-only and does not allocate or modify
// memory, and one that can. Be careful using the ones that can modify memory,
// as you can't memcpy, memset, etc on them.

template <typename T>
class ArrayClass2_RO : public CDynamicArrayBase
{
#define GET_BIN_INDEX(x) (x >> static_cast<uint8_t>(m_binShift))
#define GET_SLOT_INDEX(x) (m_slotMask & index)

public:
	T& operator[](int index) { return Get(index); }
	const T& operator[](int index) const { return Get(index); }

	T& Get(int index) { return m_array[GET_BIN_INDEX(index)][GET_SLOT_INDEX(index)]; }
	const T& Get(int index) const { return m_array[GET_BIN_INDEX(index)][GET_SLOT_INDEX(index)]; }

	// try to get an element by index, returns pointer to the element.
	// if the index is out of bounds, returns null.
	T* SafeGet(int index)
	{
		if (index < m_length)
		{
			int bin = GET_BIN_INDEX(index);
			if (bin < m_binCount)
			{
				int slot = GET_SLOT_INDEX(index);
				if (slot < m_maxPerBin)
				{
					return &m_array[bin][slot];
				}
			}
		}

		return nullptr;
	}

	bool IsMember(const T& element) const
	{
		if (m_length <= 0)
			return false;

		for (int i = 0; i < m_length; ++i)
		{
			if (Get(i) == element)
				return true;
		}
		return false;
	}

protected:
/*0x04*/ int m_maxPerBin;
/*0x08*/ int m_slotMask;
/*0x0c*/ int m_binShift;
/*0x10*/ T** m_array;
/*0x14*/ int m_binCount;
/*0x18*/
};

#undef GET_BIN_INDEX
#undef GET_SLOT_INDEX

//----------------------------------------------------------------------------

// ArrayClass2 is a dynamic array implementation that makes use of bins
// to reduce the overhead of reallocation. This allows for faster resize
// operations as existing bins do not need to be relocated, just the
// list of bins. See Assure() for more information.

template <typename T>
class ArrayClass2 : public ArrayClass2_RO<T>
{
public:
	// constructs the array
	ArrayClass2()
	{
		m_maxPerBin = 1;
		m_binShift = 0;

		do {
			m_maxPerBin <<= 1;
			m_binShift++;
		} while (m_maxPerBin < 32);

		m_slotMask = m_maxPerBin - 1;
		m_array = nullptr;
		m_length = 0;
		m_binCount = 0;
	}

	ArrayClass2(const ArrayClass2& rhs) : ArrayClass2()
	{
		this->operator=(rhs);
	}

	~ArrayClass2()
	{
		Reset();
	}

	ArrayClass2& operator=(const ArrayClass2& rhs)
	{
		if (this != &rhs)
		{
			if (m_array)
				m_length = 0;
			if (rhs.m_length)
			{
				Assure(rhs.m_length);

				for (int i = 0; i < rhs.m_length; ++i)
					Get(i) = rhs.Get(i);

				m_length = rhs.m_length;
			}
		}
		return *this;
	}

	// clear the contents of the array and make it empty
	void Reset()
	{
		for (int i = 0; i < m_binCount; ++i)
			eqVecDelete(m_array[i]);

		eqVecDelete(m_array);
		m_array = nullptr;
		m_binCount = 0;
		m_length = 0;
	}

	void Add(const T& value)
	{
		SetElementIdx(m_length, value);
	}

	void InsertElement(int index, const T& value)
	{
		if (index >= 0)
		{
			if (index < m_length)
			{
				Assure(m_length + 1);
				for (int idx = m_length; idx > index; --idx)
					Get(idx) = Get(idx - 1);
				Get(index) = value;
				++m_length;
			}
			else
			{
				SetElementIdx(index, value);
			}
		}
	}

	void SetElementIdx(int index, const T& value)
	{
		if (index >= 0)
		{
			if (index >= m_length)
			{
				Assure(index + 1);
				m_length = index + 1;
			}

			Get(index) = value;
		}
	}

	void DeleteElement(int index)
	{
		if (index >= 0 && index < m_length && m_array)
		{
			for (; index < m_length - 1; ++index)
				Get(index) = Get(index + 1);

			--m_length;
		}
	}

private:
	// Assure() makes sure that there is enough allocated space for
	// the requested size. This is the primary function used for allocating
	// memory in ArrayClass2. Because the full array is broken down into
	// a set of bins, it is more efficient at growing than ArrayClass.
	// When the array needs to be resized, it only needs to reallocate the
	// list of bins and create more bins. Existing bins do not need to be
	// reallocated, they can just be copied to the new list of bins.
	void Assure(int requestedSize)
	{
		if (requestedSize > 0)
		{
			int newBinCount = ((requestedSize - 1) >> static_cast<int8_t>(m_binShift)) + 1;

			if (newBinCount > m_binCount)
			{
				T** newArray = eqNew<T*[]>(newBinCount);
				if (newArray)
				{
					for (int i = 0; i < m_binCount; ++i)
						newArray[i] = m_array[i];
					for (int curBin = m_binCount; curBin < newBinCount; ++curBin)
					{
						T* newBin = eqNew<T[]>(m_maxPerBin);
						newArray[curBin] = newBin;
					}

					eqVecDelete(m_array);
					m_array = newArray;
					m_binCount = newBinCount;
				}
			}
		}
	}
};

#pragma endregion

#pragma region ArrayClass<T>

// simpler than ArrayClass2, ArrayClass is a simple wrapper around a dynamically
// allocated array. To grow this array requires reallocating the entire array and
// copying objects into the new array.

template <typename T>
class ArrayClass_RO : public CDynamicArrayBase
{
public:
	T& Get(int index)
	{
		if (index >= m_length || index < 0 || m_array == nullptr)
			ThrowArrayClassException();
		return m_array[index];
	}

	const T& Get(int index) const
	{
		if (index >= m_length || index < 0 || m_array == nullptr)
			ThrowArrayClassException();
		return m_array[index];
	}

	T& operator[](int index) { return Get(index); }
	const T& operator[](int index) const { return Get(index); }

	// const function that returns the element at the index *by value*
	T GetElementIdx(int index) const { return Get(index); }

protected:
	/*0x04*/    T* m_array;
	/*0x08*/    int m_alloc;
	/*0x0c*/    bool m_isValid;
	/*0x10*/
};

template <typename T>
class ArrayClass : public ArrayClass_RO<T>
{
public:
	ArrayClass()
	{
		m_length = 0;
		m_array = nullptr;
		m_alloc = 0;
		m_isValid = true;
	}

	ArrayClass(int reserve) : ArrayClass()
	{
		m_array = eqNew<T[]>(reserve);
		m_alloc = reserve;
	}

	ArrayClass(const ArrayClass& rhs) : ArrayClass()
	{
		if (rhs.m_length)
		{
			AssureExact(rhs.m_length);

			if (m_array)
			{
				for (int i = 0; i < rhs.m_length; ++i)
					m_array[i] = rhs.m_array[i];
			}

			m_length = rhs.m_length;
		}
	}

	~ArrayClass()
	{
		Reset();
	}

	ArrayClass& operator=(const ArrayClass& rhs)
	{
		if (this == &rhs)
			return *this;

		Reset();

		if (rhs.m_length)
		{
			AssureExact(rhs.m_length);

			if (m_array)
			{
				for (int i = 0; i < rhs.m_length; ++i)
					m_array[i] = rhs.m_array[i];
			}

			m_length = rhs.m_length;
		}

		return *this;
	}

	void Reset()
	{
		if (m_array)
		{
			eqVecDelete(m_array);
		}

		m_array = nullptr;
		m_alloc = 0;
		m_length = 0;
	}

	void Add(const T& element)
	{
		SetElementIdx(m_length, element);
	}

	void SetElementIdx(int index, const T& element)
	{
		if (index >= 0)
		{
			if (index >= m_length)
			{
				Assure(index + 1);

				if (m_array)
				{
					m_length = index + 1;
				}
			}

			if (m_array)
			{
				m_array[index] = element;
			}
		}
	}

	void InsertElement(int index, const T& element)
	{
		if (index >= 0)
		{
			if (index < m_length)
			{
				Assure(m_length + 1);

				if (m_array)
				{
					for (int idx = m_length; idx > index; --idx)
						m_array[idx] = m_array[idx - 1];

					m_array[index] = element;
					m_length++;
				}
			}
			else
			{
				SetElementIdx(index, element);
			}
		}
	}

	void DeleteElement(int index)
	{
		if (index >= 0 && index < m_length && m_array)
		{
			for (; index < m_length - 1; ++index)
				m_array[index] = m_array[index + 1];

			m_length--;
		}
	}
	void SetLength(int size)
	{
		AssureExact(size);
		if (this->m_array)
			this->m_length = size;
	}

	int GetCount() const
	{
		return m_length;
	}

	T* begin() { return m_array; }
	const T* begin() const { return m_array; }
	const T* cbegin() const { return m_array; }
	T* end() { return m_array + m_length; }
	const T* end() const { return m_array + m_length; }
	const T* cend() const { return m_array + m_length; }

private:
	// this function will ensure that there is enough space allocated for the
	// requested size. the underlying array is one contiguous block of memory.
	// In order to grow it, we will need to allocate a new array and move
	// everything over.
	// this function will allocate 2x the amount of memory requested as an
	// optimization aimed at reducing the number of allocations that occur.
	void Assure(int requestedSize)
	{
		if (requestedSize && (requestedSize > m_alloc || !m_array))
		{
			int allocatedSize = (requestedSize + 4) << 1;
			T* newArray = eqNew<T[]>(allocatedSize);

			if (!newArray)
			{
				eqVecDelete(m_array);
				m_array = nullptr;
				m_alloc = 0;
				m_isValid = false;
				throw CExceptionMemoryAllocation{ allocatedSize };
			}

			if (m_array)
			{
				for (int i = 0; i < m_length; ++i)
					newArray[i] = m_array[i];
				eqVecDelete(m_array);
			}

			m_array = newArray;
			m_alloc = allocatedSize;
		}
	}

	// this behaves the same as Assure, except for its allocation of memory
	// is exactly how much is requested.
	void AssureExact(int requestedSize)
	{
		if (requestedSize && (requestedSize > m_alloc || !m_array))
		{
			T* newArray = eqNew<T[]>(requestedSize);
			if (!newArray)
			{
				eqVecDelete(m_array);
				m_array = nullptr;
				m_alloc = 0;
				m_isValid = false;
				throw CExceptionMemoryAllocation(requestedSize);
			}

			if (m_array)
			{
				for (int i = 0; i < m_length; ++i)
					newArray[i] = m_array[i];
				eqVecDelete(m_array);
			}

			m_array = newArray;
			m_alloc = requestedSize;
		}
	}
};

#pragma endregion

#pragma region HashTable<T>

struct HashTableStatistics
{
	int TableSize;
	int UsedSlots;
	int TotalEntries;
};

struct ResizePolicyNoShrink
{
	template <typename Hash>
	static void ResizeOnAdd(Hash& hash)
	{
		HashTableStatistics hashStats;
		hash.GetStatistics(&hashStats);
		if (hashStats.TotalEntries * 100 / hashStats.TableSize > 70)
		{
			hash.Resize(hashStats.TableSize * 2);
		}
	}
};

struct ResizePolicyNoResize {};

template <typename T, typename Key>
class HashTableEntry
{
	T obj;
	Key key;
	HashTableEntry* next;
};

template <typename T, typename Key = int, typename ResizePolicy = ResizePolicyNoResize>
class HashTable
{
public:
	using HashEntry = HashTableEntry<T, Key>;

	template <typename K>
	static unsigned HashValue(const K& key)
	{
		return key;
	}

	T* FindFirst(const Key& key) const;
	int GetTotalEntries() const;
	T* WalkFirst() const;
	T* WalkNext(const T* prevRes) const;
	void GetStatistics(HashTableStatistics* stats) const;
	void Resize(int hashSize);
	void Insert(const T& obj, const Key& key);

/*0x00*/ HashEntry** Table;
/*0x04*/ int         TableSize;
/*0x08*/ int         EntryCount;
/*0x0c*/ int         StatUsedSlots;
/*0x10*/
};

template <typename T, typename Key, typename ResizePolicy>
void HashTable<T, Key, ResizePolicy>::GetStatistics(HashTableStatistics *stats) const
{
	stats->TotalEntries = EntryCount;
	stats->UsedSlots = StatUsedSlots;
	stats->TableSize = TableSize;
}

inline bool IsPrime(int value)
{
	for (int i = 2; i <= value / 2; ++i) {
		if (value % i == 0)
		return false;
	}
	return true;
}

inline int NextPrime(int value)
{
	if (value % 2 == 0)
		value++;
	while (!IsPrime(value))
		value += 2;
	return(value);
}

template <typename T, typename Key, typename ResizePolicy>
void HashTable<T, Key, ResizePolicy>::Resize(int hashSize)
{
	HashEntry** oldTable = Table;
	int oldSize = TableSize;
	TableSize = NextPrime(hashSize);

	if (TableSize != oldSize)
	{
		Table = eqNew<HashEntry*[]>(TableSize);
		memset(Table, 0, sizeof(HashEntry*) * TableSize);
		StatUsedSlots = 0;

		if (EntryCount > 0)
		{
			for (int i = 0; i < oldSize; i++)
			{
				HashEntry* next = oldTable[i];
				while (next != nullptr)
				{
					HashEntry* hold = next;
					next = next->NextEntry;
					int spot = HashValue<Key>(hold->key) % TableSize;

					if (Table[spot] == nullptr)
					{
						hold->NextEntry = nullptr;
						Table[spot] = hold;
						StatUsedSlots++;
					}
					else
					{
						hold->NextEntry = Table[spot];
						Table[spot] = hold;
					}
				}
			}
		}

		eqVecDelete(oldTable);
	}
}

template <typename T, typename Key, typename ResizePolicy>
T* HashTable<T, Key, ResizePolicy>::WalkFirst() const
{
	for (int i = 0; i < TableSize; i++)
	{
		HashEntry *entry = Table[i];
		if (entry != nullptr)
			return(&entry->obj);
	}
	return nullptr;
}

template <typename T, typename Key, typename ResizePolicy>
T* HashTable<T, Key, ResizePolicy>::WalkNext(const T* prevRes) const
{
	HashEntry *entry = (HashEntry *)(((char *)prevRes) - offsetof(HashEntry, Obj));
	int i = (HashValue<Key>(entry->key)) % TableSize;
	entry = entry->NextEntry;
	if (entry != NULL)
		return(&entry->obj);

	i++;
	for (; i < TableSize; i++)
	{
		HashEntry *entry = Table[i];
		if (entry != NULL)
			return(&entry->obj);
	}
	return NULL;
}

template <typename T, typename Key, typename ResizePolicy>
int HashTable<T, Key, ResizePolicy>::GetTotalEntries() const
{
	return EntryCount;
}

template <typename T, typename Key, typename ResizePolicy>
T* HashTable<T, Key, ResizePolicy>::FindFirst(const Key& key) const
{
	if (Table == NULL)
		return NULL;

	HashEntry* entry = Table[(HashValue<Key>(key)) % TableSize];
	while (entry != NULL)
	{
		if (entry->key == key)
			return(&entry->obj);
		entry = entry->NextEntry;
	}
	return NULL;
}

template <typename T, typename Key, typename ResizePolicy>
void HashTable<T, Key, ResizePolicy>::Insert(const T& obj, const Key& key)
{
	HashEntry *entry = new HashEntry;
	entry->obj = obj;
	entry->key = key;

	int spot = HashValue<Key>(key) % TableSize;
	if (Table[spot] == NULL)
	{
		entry->NextEntry = NULL;
		Table[spot] = entry;
		StatUsedSlots++;
	}
	else
	{
		entry->NextEntry = Table[spot];
		Table[spot] = entry;
	}
	EntryCount++;

	ResizePolicy::ResizeOnAdd(*this);
}

#pragma endregion

template <typename T, int _cnt>
class EQList;

template <typename T>
class EQList<T, -1>
{
public:
	struct Node
	{
		T Value;
		Node* pNext;
		Node* pPrev;
	};

/*0x00*/ void* vfTable;
/*0x04*/ Node* pFirst;
/*0x08*/ Node* pLast;
/*0x0c*/ int Count;
/*0x10*/
};

template <typename T, int _cnt = -1>
class EQList : public EQList<T, -1>
{};

// strings
template <typename T, unsigned int Size>
class TSafeArrayStatic
{
public:
	T& operator[](uint32_t index)
	{
		return Data[index];
	}

	const T& operator[](uint32_t index) const
	{
		return Data[index];
	}

	T Data[Size];
};

template <uint32_t _Len>
class TString : public TSafeArrayStatic<char, _Len>
{};

template <uint32_t _Len>
class TSafeString : public TString<_Len>
{};


//----------------------------------------------------------------------------

#pragma region VePointer<T>

class VeBaseReferenceCount
{
public:
	EQLIB_OBJECT void IncrementRefCount()
	{
		_InterlockedIncrement((volatile long*)&ReferenceCount);
	}

	EQLIB_OBJECT void DecrementRefCount()
	{
		if (_InterlockedDecrement((volatile long*)&ReferenceCount) == 0)
		{
			eqDelete(this);
		}
	}

	EQLIB_OBJECT int GetReferenceCount() const { return ReferenceCount; }

	virtual uint32_t getUnknown() { return 8; }

protected:
	VeBaseReferenceCount() = default;
	VeBaseReferenceCount(const VeBaseReferenceCount& other) {}
	virtual ~VeBaseReferenceCount() {}

private:
	mutable int        ReferenceCount = 0;
};

// This class implements an intrusive pointer, where T is a class that inherits from
// VeBaseReferenceCount, which implements the reference counting.
template <typename T>
class VePointer
{
public:
	VePointer() = default;

	VePointer(nullptr_t) {}

	explicit VePointer(T* init)
	{
		m_pObject = init;

		if (m_pObject)
		{
			static_cast<VeBaseReferenceCount*>(m_pObject)->IncrementRefCount();
		}
	}

	VePointer(const VePointer& other)
	{
		m_pObject = other.m_pObject;

		if (m_pObject)
		{
			static_cast<VeBaseReferenceCount*>(m_pObject)->IncrementRefCount();
		}
	}

	~VePointer()
	{
		if (m_pObject)
		{
			static_cast<VeBaseReferenceCount*>(m_pObject)->DecrementRefCount();
		}
	}

	VePointer& operator=(const VePointer& other)
	{
		if (m_pObject != other.m_pObject)
		{
			if (other.m_pObject)
			{
				static_cast<VeBaseReferenceCount*>(other.m_pObject)->IncrementRefCount();
			}

			if (m_pObject)
			{
				static_cast<VeBaseReferenceCount*>(m_pObject)->DecrementRefCount();
			}

			m_pObject = other.m_pObject;
		}

		return *this;
	}

	template <typename U>
	VePointer(const VePointer<U>& other)
		: m_pObject(other.m_pObject)
	{
		if (m_pObject)
		{
			static_cast<VeBaseReferenceCount*>(m_pObject)->IncrementRefCount();
		}
	}

	VePointer& operator=(T* pOther)
	{
		if (m_pObject != pOther)
		{
			if (pOther)
			{
				static_cast<VeBaseReferenceCount*>(other.m_pObject)->IncrementRefCount();
			}

			if (m_pObject)
			{
				static_cast<VeBaseReferenceCount*>(m_pObject)->DecrementRefCount();
			}

			m_pObject = pOther;
		}

		return *this;
	}

	VePointer& operator=(nullptr_t)
	{
		if (m_pObject)
		{
			static_cast<VeBaseReferenceCount*>(m_pObject)->DecrementRefCount();
		}

		m_pObject = nullptr;

		return *this;
	}

	template <typename U>
	VePointer& operator=(const VePointer<U>& other)
	{
		VePointer temp(other);
		std::swap(temp.m_pObject, m_pObject);
		return *this;
	}

	T& operator*() const
	{
		return *m_pObject;
	}

	T* operator->() const
	{
		return m_pObject;
	}

	explicit operator bool() const { return m_pObject != nullptr; }

	inline bool operator<(const VePointer& other) const
	{
		return m_pObject < other.m_pObject;
	}

	inline bool operator<(const T* other) const
	{
		return m_pObject < other;
	}

	inline void reset()
	{
		if (m_pObject)
		{
			static_cast<VeBaseReferenceCount*>(m_pObject)->DecrementRefCount();
		}

		m_pObject = nullptr;
	}

	[[nodiscard]] T* get() const { return m_pObject; }

	DEPRECATE("Access pointer directly (or call .get()) instead of using pObject")
	[[nodiscard]] T* get_pObject() const { return m_pObject; }

#pragma warning(disable: 4996)
	// Access the object through the get() function.
	__declspec(property(get = get_pObject)) T* pObject;
#pragma warning(default: 4996)

private:
	T* m_pObject = nullptr;
};

template <typename T>
[[nodiscard]] bool operator==(nullptr_t, const VePointer<T> & rhs) noexcept {
	return nullptr == rhs.get();
}

template <typename T>
[[nodiscard]] bool operator==(const VePointer<T>& lhs, nullptr_t) noexcept {
	return lhs.get() == nullptr;
}

template <typename T>
[[nodiscard]] bool operator!=(nullptr_t, const VePointer<T>& rhs) noexcept {
	return nullptr != rhs.get();
}

template <typename T>
[[nodiscard]] bool operator!=(const VePointer<T>& lhs, nullptr_t) noexcept {
	return lhs.get() != nullptr;
}

#pragma endregion

#pragma region VeArray<T>

// A vector-like array container
template <typename T>
class VeArray
{
public:
	VeArray() = default;

	T& operator[](uint32_t i)
	{
		return m_data[i];
	}

	const T& operator[](uint32_t i) const
	{
		return m_data[i];
	}

	ALT_MEMBER_GETTER(T*, m_data, Begin);
	ALT_MEMBER_GETTER(uint32_t, m_size, Size);
	ALT_MEMBER_GETTER(uint32_t, m_capacity, Capacity);

private:
/*0x00*/ T*       m_data;
/*0x04*/ uint32_t m_size;
/*0x08*/ uint32_t m_capacity;
/*0x0c*/
};

#pragma endregion

//----------------------------------------------------------------------------

// LinkedLists
template <class T>
class LinkedListNode
{
public:
/*0x00*/ T Object;
/*0x04*/ LinkedListNode* pNext;
/*0x08*/ LinkedListNode* pPrev;
/*0x0c*/
};

template <class T>
class DoublyLinkedList
{
public:
/*0x00*/ void* vfTable;
/*0x04*/ LinkedListNode<T>* pHead;
/*0x08*/ LinkedListNode<T>* pTail;
/*0x0c*/ LinkedListNode<T>* pCurObject;
/*0x10*/ LinkedListNode<T>* pCurObjectNext;
/*0x14*/ LinkedListNode<T>* pCurObjectPrev;
/*0x18*/ int NumObjects;
/*0x1c*/ int RefCount;
/*0x20*/
};

template <typename KeyType, typename T, int _Size, int _Cnt>
class HashListMap;

template <typename KeyType, typename T, int _Size>
class HashListMap<KeyType, T, _Size, -1>
{
public:
	struct Node
	{
		T Value;
		Node* pNext;
		Node* pPrev;
		KeyType Key;
		Node *pHashNext;
	};

	Node* NodeGet(const T* cur) const
	{
		return (Node *)((byte *)cur - (size_t)((byte *)(&((Node*)1)->Value) - (byte *)1));
	}

	enum { TheSize = ((_Size == 0) ? 1 : _Size) };

	void* vfTable;
	int DynSize;
	int MaxDynSize;
	Node* pHead;
	Node* pTail;
	int Count;
	union
	{
		Node *Table[TheSize];
		Node **DynTable;
	};
};

template <typename T_KEY, typename T, int _Size, int _Cnt = -1>
class HashListMap : public HashListMap<T_KEY, T, _Size, -1>
{
};

template <typename T, int _Size, int _Cnt = -1>
class HashList : public HashListMap<int, T, _Size, _Cnt>
{
};

template <typename T, int _Size, int _Cnt>
class HashListSet;

template <typename T, int _Size>
class HashListSet<T, _Size, -1>
{
public:
	using ValueType = T;

	struct Node
	{
		T Value;
		Node* pNext;
		Node* pPrev;
		Node* pNextHash;
	};

 	enum { TheSize = ((_Size == 0) ? 1 : _Size) };

	/*0x00*/ void* vfTable;
	/*0x04*/ int DynSize;
	/*0x08*/ int MaxDynSize;
	/*0x0c*/ int Count;
	/*0x10*/
	union
	{
		Node *Table[TheSize];
		Node **DynTable;
	};
};

template <typename T, int _Size, int _Cnt = -1>
class HashListSet : public HashListSet<T, _Size, -1>
{};

template <typename T, int _Size>
class HashListSet<T, _Size, -2> : public HashListSet<T, _Size, -1>
{
	// todo: change to whatever stl replacement this it, for now we just void* it...
	void* MemPool;
};

class AtomicInt
{
public:
	volatile int Value;
};

template <typename ET>
class CircularArrayClass2 : public CDynamicArrayBase
{
public:
/*0x04*/ int HeadIndex;
/*0x08*/ int WrapIndex;
/*0x0C*/ int ArraySize;
/*0x10*/ int ChunkSize;
/*0x14*/ int ChunkMask;
/*0x18*/ int ChunkShift;
/*0x1C*/ ET** Chunks;
/*0x20*/ int ChunkAlloc;
/*0x24*/
};

template <typename TNumBitsType, typename TElementType>
class DynamicBitField
{
	using NumBitsType = TNumBitsType;
	using ElementType = TElementType;

	NumBitsType NumBits;
	ElementType Element;
	ElementType* Elements;
};

// Linked List classes

#pragma region TList<T>

template <typename T> class TList;

template <typename T>
class TListNode
{
	// pointers to previous and next node
	T* m_pPrev = nullptr;
	T* m_pNext = nullptr;
	TList<T>* m_pList = nullptr;  // pointer to the list this node belongs to

public:
	TListNode() {}

	TListNode(const TListNode&) = delete;
	TListNode& operator=(const TListNode&) = delete;

	bool IsLinked() const { return m_pList != nullptr; }
	TList<T>* GetList() { return m_pList; }

	T* GetPrevious() { return m_pPrev; }
	const T* GetPrevious() const { return m_pPrev; }
	T* GetNext() { return m_pNext; }
	const T* GetNext() const { return m_pNext; }
};

template <typename T>
class TList
{
	T* m_pFirstNode;
	T* m_pLastNode;

	TListNode<T>* GetNodePtr(T* ptr) const
	{
		return static_cast<TListNode<T>*>(ptr);
	}
	const TListNode<T>* GetNodePtr(const T* ptr) const
	{
		return static_cast<const TListNode<T>*>(ptr);
	}

public:
	TList()
		: m_pFirstNode(nullptr)
		, m_pLastNode(nullptr)
	{}

	bool IsEmpty() const { return m_pFirstNode == nullptr; }

	T* GetFirstNode() { return m_pFirstNode; }
	const T* GetFirstNode() const { return m_pFirstNode; }
	T* GetLastNode() { return m_pLastNode; }
	const T* GetLastNode() const { return m_pLastNode; }

	// count the number of nodes in the list
	uint32_t GetNodeCount() const
	{
		uint32_t count = 0;
		T* pNode = m_pFirstNode;
		while (pNode)
		{
			pNode = GetNodePtr(pNode)->GetNext();
			count++;
		}

		return count;
	}

	// get the specified Nth node
	T* GetNode(uint32_t index)
	{
		uint32_t pos = 0;
		T* pNode = m_pFirstNode;

		while (pos < index)
		{
			if (!pNode) return nullptr;

			pNode = GetNodePtr(pNode)->GetNext();
			count++;
		}

		return pNode;
	}

	const T* GetNode(uint32_t index) const
	{
		uint32_t pos = 0;
		T* pNode = m_pFirstNode;

		while (pos < index)
		{
			if (!pNode) return nullptr;

			pNode = GetNodePtr(pNode)->GetNext();
			count++;
		}

		return pNode;
	}

};

#pragma endregion

// we dont need a fully implemented version. this does the job just fine
template <typename T, uint32_t _Len>
class TCircularBuffer
{
public:
	T       Type[_Len];
	UINT    Len;
	UINT    Index;
};


struct CKeyUInt32ValueInt32
{
	uint32_t key;
	int      value;
};

class CHashCXStrInt32
{
public:
	ArrayClass2_RO<ArrayClass2_RO<CKeyUInt32ValueInt32>> HashData;

	EQLIB_OBJECT ~CHashCXStrInt32();
	EQLIB_OBJECT CHashCXStrInt32();
	EQLIB_OBJECT bool Insert(CXStr const&, int);
	EQLIB_OBJECT bool LookUp(CXStr const&, int&) const;
	EQLIB_OBJECT void Reset();

	// private
	EQLIB_OBJECT int KeyToBin(CXStr const&) const;
};

//----------------------------------------------------------------------------

} // namespace eqlib
