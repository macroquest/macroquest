/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#pragma once

#include <cstdint>

#pragma pack(push)
#pragma pack(4)

//----------------------------------------------------------------------------

class CDynamicArrayBase;

struct CEQException {};
struct CExceptionApplication : CEQException {};

struct CExceptionMemoryAllocation : public CEQException {
	int size;

	CExceptionMemoryAllocation(int size_) : size(size_) {}
};

// inherits from CExceptionApplication and CEQException
struct CDynamicArrayException : public CExceptionApplication {
	const CDynamicArrayBase* obj;

	CDynamicArrayException(const CDynamicArrayBase* obj_) : obj(obj_) {}
};

// base class for the dynamic array types
class CDynamicArrayBase
{
protected:
	/*0x00*/    int m_length;
	/*0x04*/

public:
	// two names for the same thing
	int GetLength() const { return m_length; }

	// a microsoft extension - lets us get away with changing the implementation
	__declspec(property(get = GetLength)) int Count;

protected:
	void ThrowArrayClassException() const
	{
		throw CDynamicArrayException(this);
	}
};

// split into two types - one that is read-only and does not allocate or modify
// memory, and one that can. Be careful using the ones that can modify memory,
// as you can't memcpy, memset, etc on them.

template <typename T>
class ArrayClass2_RO : public CDynamicArrayBase
{
#define GET_BIN_INDEX(x) (x >> static_cast<uint8_t>(m_binShift))
#define GET_SLOT_INDEX(x) (m_slotMask & index)
public:
	inline T& operator[](int index) { return Get(index); }
	inline const T& operator[](int index) const { return Get(index); }

	T& Get(int index) { return m_array[GET_BIN_INDEX(index)][GET_SLOT_INDEX(index)]; }
	inline const T& Get(int index) const { return m_array[GET_BIN_INDEX(index)][GET_SLOT_INDEX(index)]; }

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
		for (int i = 0; i < m_length; ++i) {
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
#if !defined(TEST) && !defined(LIVE)
/*0x18*/ bool m_valid;
#endif
/*0x1c*/
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
		#if !defined(TEST) && !defined(LIVE)
		m_valid = true;
		#endif
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
			if (rhs.m_length) {
				Assure(rhs.m_length);
				#if !defined(TEST) && !defined(LIVE)
				if (m_valid) {
				#else
				if (m_binCount) {
				#endif		
					for (int i = 0; i < rhs.m_length; ++i)
						Get(i) = rhs.Get(i);
				}
				m_length = rhs.m_length;
			}
		}
		return *this;
	}

	// clear the contents of the array and make it empty
	void Reset()
	{
		for (int i = 0; i < m_binCount; ++i)
			delete[] m_array[i];
		delete[] m_array;
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
		if (index >= 0) {
			if (index < m_length) {
				Assure(m_length + 1);
				for (int idx = m_length; idx > index; --idx)
					Get(idx) = Get(idx - 1);
				Get(index) = value;
				++m_length;
			}
			else {
				SetElementIdx(index, value);
			}
		}
	}

	void SetElementIdx(int index, const T& value)
	{
		if (index >= 0) {
			if (index >= m_length) {
				Assure(index + 1);
				#if !defined(TEST) && !defined(LIVE)
				if (m_valid) {
				#else
				if (m_binCount) {
				#endif
					m_length = index + 1;
				}
			}
			#if !defined(TEST) && !defined(LIVE)
			if (m_valid) {
			#else
			if (m_binCount) {
			#endif
				Get(index) = value;
			}
		}
	}

	void DeleteElement(int index)
	{
		if (index >= 0 && index < m_length && m_array) {
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
		#if !defined(TEST) && !defined(LIVE)
		if (m_valid && requestedSize > 0) {
		#else
		if (m_binCount && requestedSize > 0) {
		#endif
			int newBinCount = ((requestedSize - 1) >> static_cast<int8_t>(m_binShift)) + 1;
			if (newBinCount > m_binCount) {
				T** newArray = new T*[newBinCount];
				if (newArray) {
					for (int i = 0; i < m_binCount; ++i)
						newArray[i] = m_array[i];
					for (int curBin = m_binCount; curBin < newBinCount; ++curBin) {
						T* newBin = new T[m_maxPerBin];
						newArray[curBin] = newBin;
						if (!newBin) {
							#if !defined(TEST) && !defined(LIVE)
							m_valid = false;
							#else
							m_binCount = 0;
							#endif
							break;
						}
					}
					#if !defined(TEST) && !defined(LIVE)
					if (m_valid) {
					#else
					if (m_binCount) {
					#endif
						delete[] m_array;
						m_array = newArray;
						m_binCount = newBinCount;
					}
				} else {
					#if !defined(TEST) && !defined(LIVE)
					m_valid = false;
					#else
					m_binCount = 0;
					#endif
				}
			}
			// special note about this exception: the eq function was written this way,
			// but its worth noting that new will throw if it can't allocate, which means
			// this will never be hit anyways. The behavior would not change if we removed
			// all of the checks for null returns values from new in this function.
			#if !defined(TEST) && !defined(LIVE)
			if (!m_valid) {
			#else
			if (!m_binCount) {
			#endif
				Reset();
				ThrowArrayClassException();
			}
		}
	}
};

//----------------------------------------------------------------------------

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
	//0090C580
EQLIB_OBJECT void ArrayClass_RO<T>::DeleteElement(int index);

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
		m_array = new T[size];
		m_alloc = size;
	}

	ArrayClass(const ArrayClass& rhs) : ArrayClass()
	{
		if (rhs.m_length) {
			AssureExact(rhs.m_length);
			if (m_array) {
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
		if (rhs.m_length) {
			AssureExact(rhs.m_length);
			if (m_array) {
				for (int i = 0; i < rhs.m_length; ++i)
					m_array[i] = rhs.m_array[i];
			}
			m_length = rhs.m_length;
		}
		return *this;
	}

	void Reset()
	{
		if (m_array) {
			delete[] m_array;
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
		if (index >= 0) {
			if (index >= m_length) {
				Assure(index + 1);
				if (m_array) {
					m_length = index + 1;
				}
			}
			if (m_array) {
				m_array[index] = element;
			}
		}
	}

	void InsertElement(int index, const T& element)
	{
		if (index >= 0) {
			if (index < m_length) {
				Assure(m_length + 1);
				if (m_array) {
					for (int idx = m_length; idx > index; --idx)
						m_array[idx] = m_array[idx - 1];
					m_array[index] = element;
					m_length++;
				}
			} else {
				SetElementIdx(index, element);
			}
		}
	}

	void DeleteElement(int index)
	{
		if (index >= 0 && index < m_length && m_array) {
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
private:
	// this function will ensure that there is enough space allocated for the
	// requested size. the underlying array is one contiguous block of memory.
	// In order to grow it, we will need to allocate a new array and move
	// everything over.
	// this function will allocate 2x the amount of memory requested as an
	// optimization aimed at reducing the number of allocations that occur.
	void Assure(int requestedSize)
	{
		if (requestedSize && (requestedSize > m_alloc || !m_array)) {
			int allocatedSize = (requestedSize + 4) << 1;
			T* newArray = new T[allocatedSize];
			if (!newArray) {
				delete[] m_array;
				m_array = nullptr;
				m_alloc = 0;
				m_isValid = false;
				throw CExceptionMemoryAllocation{ allocatedSize };
			}
			if (m_array) {
				for (int i = 0; i < m_length; ++i)
					newArray[i] = m_array[i];
				delete[] m_array;
			}
			m_array = newArray;
			m_alloc = allocatedSize;
		}
	}
	
	// this behaves the same as Assure, except for its allocation of memory
	// is exactly how much is requested.
	void AssureExact(int requestedSize)
	{
		if (requestedSize && (requestedSize > m_alloc || !m_array)) {
			T* newArray = new T[requestedSize];
			if (!newArray) {
				delete[] m_array;
				m_array = nullptr;
				m_alloc = 0;
				m_isValid = false;
				throw CExceptionMemoryAllocation(requestedSize);
			}
			if (m_array) {
				for (int i = 0; i < m_length; ++i)
					newArray[i] = m_array[i];
				delete[] m_array;
			}
			m_array = newArray;
			m_alloc = requestedSize;
		}
	}
};
struct HashTableStatistics
{
	int TableSize;
	int UsedSlots;
	int TotalEntries;
};

class ResizePolicyNoShrink
{
public:
	template<typename Hash>
	static void ResizeOnAdd( Hash& hash )
	{
		HashTableStatistics hashStats;
		hash.GetStatistics( &hashStats );
		if( hashStats.TotalEntries * 100 / hashStats.TableSize > 70 )
		{
			hash.Resize( hashStats.TableSize * 2 );
		}
	}
};
class ResizePolicyNoResize
{
public:
};
template<typename T, typename Key = int, typename ResizePolicy = ResizePolicyNoResize> class HashTable
{
public:
	struct HashEntry
	{
		T Obj;
		Key Key;
		HashEntry *NextEntry;
	};
	template<typename K>
	static unsigned HashValue( const K& key )
	{
		return key;
	}
	/*0x00*/	HashEntry **Table;
	/*0x04*/	int TableSize;
	/*0x08*/	int EntryCount;
	/*0x0c*/	int StatUsedSlots;
	/*0x10*/
	T *FindFirst(const Key& key) const;
	int GetTotalEntries() const;
	T *WalkFirst() const;
	T *WalkNext(const T *prevRes) const;
	void GetStatistics(HashTableStatistics *stats) const;
	void Resize(int hashSize);
	void Insert(const T& obj, const Key& key);
};
template<typename T, typename Key, typename ResizePolicy> void HashTable<T, Key, ResizePolicy>::GetStatistics(HashTableStatistics *stats) const
{
	stats->TotalEntries = EntryCount;
	stats->UsedSlots = StatUsedSlots;
	stats->TableSize = TableSize;
}
inline bool IsPrime(int value)
{
	//todo add code for this
	return(true);
}

inline int NextPrime(int value)
{
	if (value % 2 == 0)
		value++;
	while (!IsPrime(value))
		value += 2;
	return(value);
}
template<typename T, typename Key, typename ResizePolicy> void HashTable<T, Key, ResizePolicy>::Resize(int hashSize)
{
	HashEntry **oldTable = Table;
	int oldSize = TableSize;
	TableSize = NextPrime(hashSize);
	if ( TableSize != oldSize )
	{
		Table = new HashEntry*[TableSize];
		memset(Table, 0, sizeof(HashEntry *) * TableSize);
		StatUsedSlots = 0;
		if (EntryCount > 0)
		{
			for (int i = 0; i < oldSize; i++)
			{
				HashEntry* next = oldTable[i];
				while (next != NULL)
				{
					HashEntry* hold = next;
					next = next->NextEntry;
					int spot = (HashValue<Key>( hold->Key )) % TableSize;
					if (Table[spot] == NULL)
					{
						hold->NextEntry = NULL;
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
		delete[] oldTable;
	}
}
template<typename T, typename Key, typename ResizePolicy> T *HashTable<T, Key, ResizePolicy>::WalkFirst() const
{
	for (int i = 0; i < TableSize; i++)
	{
		HashEntry *entry = Table[i];
		if (entry != NULL)
			return(&entry->Obj);
	}
	return NULL;
}
template<typename T, typename Key, typename ResizePolicy> T *HashTable<T, Key, ResizePolicy>::WalkNext(const T *prevRes) const
{
	HashEntry *entry = (HashEntry *)(((char *)prevRes) - offsetof(HashEntry, Obj));
	int i = (HashValue<Key>(entry->Key)) % TableSize;
	entry = entry->NextEntry;
	if (entry != NULL)
		return(&entry->Obj);

	i++;
	for (; i < TableSize; i++)
	{
		HashEntry *entry = Table[i];
		if (entry != NULL)
			return(&entry->Obj);
	}
	return NULL;
}
template<typename T, typename Key, typename ResizePolicy> int HashTable<T, Key, ResizePolicy>::GetTotalEntries() const
{
	return EntryCount;
}
template<typename T, typename Key, typename ResizePolicy> T *HashTable<T, Key, ResizePolicy>::FindFirst( const Key& key ) const
{
	if (Table==NULL)
		return NULL;
	HashEntry *entry = Table[( HashValue<Key>(key) ) % TableSize];
	while (entry != NULL)
	{
		if (entry->Key == key)
			return(&entry->Obj);
		entry = entry->NextEntry;
	}
	return NULL;
}
template<typename T, typename Key, typename ResizePolicy> void HashTable<T, Key, ResizePolicy>::Insert(const T& obj, const Key& key)
{
	HashEntry *entry = new HashEntry;
	entry->Obj = obj;
	entry->Key = key;

	int spot = (HashValue<Key>( key )) % TableSize;
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
	ResizePolicy::ResizeOnAdd( *this );
}
//lists
template<typename T, int _cnt> class EQList;
template<typename T> class EQList<T, -1>
{
public:
	/*0x00*/    PVOID vfTable;
    class Node 
    {
        public:
            T Value;
            Node *pNext;
            Node *pPrev;
    };
	/*0x04*/    Node *pFirst;
	/*0x08*/    Node *pLast;
	/*0x0c*/    int Count;
	/*0x10*/
};
template<typename T, int _cnt = -1> class EQList : public EQList<T, -1>
{
    public:
};
//strings
template <typename TheType, unsigned int _Size> class TSafeArrayStatic
{
public:
	TheType Data[_Size];
	inline TheType& operator[](UINT index)
	{ 
		return Data[index]; 
	}
};
template <UINT _Len> class TString : public TSafeArrayStatic<CHAR, _Len>
{
public:
};
template <UINT _Len> class TSafeString : public TString<_Len>
{
public:
};

class VePointerBase
{
public:
    UINT Address;
};
template< class T > class VePointer// : public VePointerBase
{
public:
    T* pObject;
};
template< typename T > class VeArray
{
public:
    /*0x00*/    T* Begin;
	/*0x04*/    UINT Size;
	/*0x08*/    UINT Capacity;
	/*0x0c*/
	T& operator[](unsigned);
	const T& operator[](unsigned) const;
};
template< typename T >
inline const T& VeArray<T>::operator[](unsigned i) const
{
	return Begin[i];
}

template< typename T >
inline T& VeArray<T>::operator[](unsigned i)
{
	return Begin[i];
}

//LinkedLists
template<class T> class LinkedListNode
{
public:
/*0x00*/	T	Object;
/*0x04*/	LinkedListNode* pNext;
/*0x08*/	LinkedListNode* pPrev;
/*0x0c*/
};
template <class T> class DoublyLinkedList
{
public:
/*0x00*/    PVOID vfTable;
/*0x04*/    LinkedListNode<T>* pHead;
/*0x08*/    LinkedListNode<T>* pTail;
/*0x0c*/    LinkedListNode<T>* pCurObject;
/*0x10*/    LinkedListNode<T>* pCurObjectNext;
/*0x14*/    LinkedListNode<T>* pCurObjectPrev;
/*0x18*/    int NumObjects;
/*0x1c*/    int RefCount;
/*0x20*/
};
template<typename T_KEY, typename T, int _Size, int _Cnt> class HashListMap;

template<typename T_KEY, typename T, int _Size> class HashListMap<T_KEY, T, _Size, -1>
{
public:
	PVOID vfTable;
    class Node {
        public:
            T Value;
            Node *pNext;
            Node *pPrev;
            T_KEY Key;
            Node *pHashNext;
    };
    Node *NodeGet(const T *cur) const
    {
        return((Node *)(void *)((byte *)(void *)cur - (size_t)((byte *)(&((Node *)1)->Value) - (byte *)1)));
    }
	enum {
		TheSize = ((_Size == 0) ? 1 : _Size)
	};
	int DynSize;
    int MaxDynSize;
    Node *pHead;
    Node *pTail;
    int Count;
    union
    {
        Node *Table[TheSize];
        Node **DynTable;
    };
};
template<typename T_KEY, typename T, int _Size, int _Cnt = -1> class HashListMap : public HashListMap<T_KEY, T, _Size, -1>
{
    public:

};
template<typename T, int _Size, int _Cnt = -1> class HashList : public HashListMap<int, T, _Size, _Cnt>
{
    public:
};

template<typename T, int _Size, int _Cnt> class HashListSet;
template<typename T, int _Size> class HashListSet<T, _Size, -1>
{
public:
	/*0x00*/ PVOID vfTable;
    typedef T ValueType;
    class Node {
        public:
            T Value;
            Node *pNext;
            Node *pPrev;
            Node *pNextHash;
    };
 	enum {
		TheSize = ((_Size == 0) ? 1 : _Size)
	};
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

template<typename T, int _Size, int _Cnt = -1> class HashListSet : public HashListSet<T, _Size, -1>
{

};

template<typename T, int _Size> class HashListSet<T, _Size, -2> : public HashListSet<T, _Size, -1>
{
    void *MemPool;//todo: change to whatever stl replacement this it, for now we just void* it...
};
template<typename T, int _Size, bool _bGrow> class EQArray;
template<typename T, int _Size, bool _bGrow> class EQArray2;

template<typename T> class EQArray<T, 0, true>
{
public:
/*0x00*/ void* pvfTable;
/*0x04*/ T *m_array;
/*0x08*/ int m_length;
/*0x0c*/ int m_space;
/*0x10*/ 
};
template<typename T> class EQArray2<T, 0, true>
{
public:
/*0x00*/ void* pvfTable;
/*0x04*/ void* pvfTable2;
/*0x08*/ T *m_array;
/*0x0c*/ int m_length;
/*0x10*/ int m_space;
/*0x14*/
};
template<typename T> class IString
{
	//yes it has a vftable...
public:
/*0x00*/	PVOID vfTable;
/*0x04*/	T *String;
/*0x08*/	int Len;
/*0x0c*/	int Space;
/*0x10*/ //0x14? not sure.

};
class IString2
{
public:
/*0x00*/	PVOID vfTable;
/*0x04*/	char*String;
/*0x08*/	int Len;
/*0x0c*/	int Space;
/*0x10*/
EQLIB_OBJECT void Append(char *c);
};

class AtomicInt
{
public:
	volatile int Value;
};
template<typename T, int T_SIZE> class IStringFixed : public IString<T>
{
public:
	BYTE FixedData[(T_SIZE * sizeof(T)) + sizeof(AtomicInt)];
};
template<int T_SIZE> class StringFixed : public IStringFixed<char, T_SIZE>
{
public:

};
template<typename T, int _Size = 0, bool _bGrow = true> class EQArray : public EQArray<T, 0, true>
{
    public:
        enum { cTCount = _Size };
        static const bool cTGrow = _bGrow;
};
template<typename T, int _Size = 0, bool _bGrow = true> class EQArray2 : public EQArray2<T, 0, true>
{
    public:
        enum { cTCount = _Size };
        static const bool cTGrow = _bGrow;
};

template <typename ET> class CircularArrayClass2 : public CDynamicArrayBase
{
public:
	int HeadIndex;
	int WrapIndex;
	int ArraySize;
	int ChunkSize;
	int ChunkMask;
	int ChunkShift;
	ET** Chunks;
	int ChunkAlloc;
	#if !defined(TEST) && !defined(LIVE)
	bool bValid;
	#endif
};
template <typename TNumBitsType, typename TElementType> class DynamicBitField
{
	typedef TNumBitsType NumBitsType;
	typedef TElementType ElementType;
	NumBitsType NumBits;
	ElementType Element;
	ElementType* Elements;
};
#pragma pack(pop)
