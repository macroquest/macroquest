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

#include "pch.h"
#include "Common.h"
#include "CXStr.h"
#include "Mutex.h"
#include "Globals.h"

namespace eqlib {

// CXStr has a global mutex (critical section) that it
// uses frequently. We need to be able to lock this same
// mutex so that we don't race against EQ.

// NEEDS OFFSET & INSTALLATION
CMutexSync* gCXStrMutex = nullptr;

class CXFreeList
{
public:
	size_t blockSize;
	CStrRep* repList;
};

// This is the list of free lists. Each CXStr has a pointer
// to it, so the easiest way to find it is to interact with
// an existing CXStr.
CXFreeList* gFreeLists = nullptr;

void InitializeCXStr()
{
	gFreeLists = (CXFreeList*)CXStr__gFreeLists;
	gCXStrMutex = (CMutexSync*)CXStr__gCXStrAccess;
}

void ShutdownCXStr()
{
}

// Unicode / Utf8 conversion functions
size_t CalcUnicodeToUtf8Length(wchar_t* input)
{
	int len = 0;
	for (const wchar_t* p = input; *p != 0; ++p)
	{
		if (*p < 0x80)
			len++;
		else if (*p < 0x800)
			len += 2;
		else
			len += 3;
	}

	return len;
}

size_t UnicodeToUtf8(wchar_t* unicode, char* buffer, size_t size)
{
	if (!unicode) return -2;
	if (!buffer) return -2;
	if (size == 0) return -2;

	const wchar_t* src = unicode;
	char* dest = buffer;
	char* last = buffer + size - 1;

	while (true)
	{
		if (dest > last)
		{
			break;
		}

		if (*src == 0)
		{
			*dest++ = 0;
			if (dest > last)
				break;

			return dest - buffer - 1;
		}

		if (*src < 0x80) // 1 byte value
		{
			*dest++ = (char)*src;
			++src;
		}
		else if (*src < 0x800) // 2 bytes
		{
			*dest++ = 0xc0 | (0x1f & static_cast<char>(*src >> 6));
			*dest++ = 0x80 | (0x3f & static_cast<char>(*src));
			src++;
		}
		else // 3 bytes
		{
			*dest++ = 0xe0 | (0x0f & static_cast<char>(*src >> 12));
			*dest++ = 0x80 | (0x3f & static_cast<char>(*src >> 6));
			*dest++ = 0x80 | (0x3f & static_cast<char>(*src));
			src++;
		}
	}

	return -1;
}

size_t Utf8ToUnicode(char* utf8, wchar_t* buffer, size_t size)
{
	return 0;
}

// This is to ensure we have a CStrRep block to access. it allows us to
// ensure we have an allocated buffer that we can dereference. This
// function does not force a copy.
void CXStr::AssureAccessible() const noexcept
{
	if (m_data)
		return;

	const_cast<CXStr*>(this)->AssureCopy();
}

// This is called whenever a modification is about to be made
// to "assure" we have our own copy. This implements the copy-on-write
// behavior of CXStr.
void CXStr::AssureCopy()
{
	Assure(size() + 1, GetEncoding());
}

void CXStr::Assure(size_t size, EStringEncoding encoding)
{
	if (encoding == StringEncodingUtf16)
	{
		size *= 2;
	}

	// Check the conditions for creating a new CStrRep. If the desired
	// encoding is different, if the size is larger, or if the CStrRep is
	// shared (refCount > 1) then we need to duplicate. This implements the
	// copy-on-write.
	if (m_data == nullptr)
	{
		// simple case is not having a rep yet. Just create one.
		ScopedLockedMutex lock(gCXStrMutex);

		m_data = AllocRepNoLock(size, encoding);
	}
	else if (m_data->refCount > 1
		|| m_data->encoding != encoding
		|| m_data->alloc < size)
	{
		ScopedLockedMutex lock(gCXStrMutex);

		// don't try to shrink the buffer.
		if (size < m_data->alloc)
			size = m_data->alloc;

		// If conerting from unicode to utf8 we must calculate
		// the actual byte length.
		if (m_data->encoding == StringEncodingUtf16
			&& encoding == StringEncodingUtf8)
		{
			size_t utf8Length = CalcUnicodeToUtf8Length(m_data->unicode) + 1;

			if (size < utf8Length)
				size = utf8Length;
		}

		CStrRep* rep = AllocRepNoLock(size, encoding);

		// Copy data from old rep to new
		if (rep->encoding == StringEncodingUtf8)
		{
			if (m_data->encoding == StringEncodingUtf8)
			{
				// utf8 -> utf8
				memcpy(rep->utf8, m_data->utf8, m_data->length + 1);
				rep->length = m_data->length;
			}
			else if (m_data->encoding == StringEncodingUtf16)
			{
				// utf16 -> utf8
				rep->length = UnicodeToUtf8(m_data->unicode, rep->utf8, rep->alloc);
			}
		}
		else if (rep->encoding == StringEncodingUtf16)
		{
			if (m_data->encoding == StringEncodingUtf8)
			{
				// utf8 -> utf16
				rep->length = Utf8ToUnicode(m_data->utf8, rep->unicode, rep->alloc);
			}
			else
			{
				// utf16 -> utf16
				memcpy(rep->unicode, m_data->unicode, (m_data->length + 1) * 2);
				rep->length = m_data->length;
			}
		}

		// delete old rep
		FreeRepNoLock(m_data);

		m_data = rep;
	}
}

CStrRep* CXStr::AllocRepNoLock(size_t size, EStringEncoding encoding)
{
	size_t i = 0;
	CXFreeList* freeLists = gFreeLists;

	while (freeLists[i].blockSize > 0)
	{
		CXFreeList& freeList = freeLists[i];

		if (size <= freeList.blockSize)
		{
			if (freeList.repList == nullptr)
			{
				// didn't find a free block, we'll make one with
				// the matching block size. When it is released it will
				// be returned to this free list.
				size = freeList.blockSize;
				break;
			}

			// found a free block, take it from the list
			CStrRep* rep = freeList.repList;
			freeList.repList = freeList.repList->next;

			rep->next = nullptr;
			rep->length = 0;
			rep->encoding = encoding;
			rep->refCount = 1;
			rep->freeList = gFreeLists;
			rep->alloc = freeList.blockSize;

			return rep;
		}

		++i;
	}

	if (freeLists[i].blockSize == 0)
	{
		// If we made it here it means there isn't a block thats large
		// enough to hold our string. We won't use a free list for it.

		// make the size a multiple of 8192
		size = ((((size + 0x1FFF) >> 31) & 0x1FFF) + size + 0x1FFF) & 0xFFFFE000;
	}

	// Calculate size of block. Size of the non-text data plus desired size.
	size_t newSize = sizeof(CStrRep) - sizeof(CStrRep::utf8) + size;
	CStrRep* rep = new (eqlib::eqAlloc(newSize)) CStrRep;

	rep->next = nullptr;
	rep->length = 0;
	rep->alloc = size;
	rep->encoding = encoding;
	rep->refCount = 1;
	rep->freeList = gFreeLists;

	return rep;
}

void CXStr::FreeRep(CStrRep* rep)
{
	if (!rep) return;

	ScopedLockedMutex lock(gCXStrMutex);

	FreeRepNoLock(rep);
}

void CXStr::FreeRepNoLock(CStrRep* rep)
{
	if (!rep) return;

	// only perform a free when the ref count reaches exactly zero
	if (--rep->refCount != 0) return;

	CXFreeList* freeLists = rep->freeList;
	size_t i = 0;

	while (freeLists[i].blockSize > 0)
	{
		if (rep->alloc == freeLists[i].blockSize)
		{
			rep->next = freeLists[i].repList;

			freeLists[i].repList = rep;
			return;
		}

		++i;
	}

	eqlib::eqFree(rep);
}

int CXStr::Compare(const CXStr& other, ECompareMode mode /*= CaseSensitive*/) const
{
	// Ensure both strings have utf8 encoding
	SetEncoding(StringEncodingUtf8);
	other.SetEncoding(StringEncodingUtf8);

	switch (mode)
	{
	case CaseInsensitive:
		return _stricmp(m_data->utf8, other.m_data->utf8);

	case CaseSensitive:
		return strcmp(m_data->utf8, other.m_data->utf8);
	}

	return -1;
}

int CXStr::CompareN(const CXStr& other, int len, ECompareMode mode /*= CaseSensitive*/) const
{
	// not optimized at all.
	CXStr s1 = substr(0, len);
	CXStr s2 = other.substr(0, len);

	return s1.Compare(s2, mode);
}

} // namespace eqlib