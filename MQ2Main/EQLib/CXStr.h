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
#include "DynamicArray.h"

#include <algorithm>
#include <atomic>
#include <cstdint>
#include <initializer_list>
#include <string>
#include <string_view>
#include <type_traits>
#include <stdexcept>

namespace eqlib {

// initialize/shutdown the eqlib::CXStr components
void InitializeCXStr();
void ShutdownCXStr();

// This enum represents the encodings supported by CXStr. Strings can internally
// be represented as either an array of wchar_t or char, corresponding with
// "unicode" (utf16) or utf8. We primarily use utf8 here, but we need to have
// very basic support for the utf16 encoding in case we encounter a string that
// is already encoded with that encoding.
enum EStringEncoding
{
	StringEncodingUtf8,
	StringEncodingUtf16,
};

// Method of performing a string comparison
enum ECompareMode
{
	CaseSensitive,
	CaseInsensitive,
};

using Unicode16 = wchar_t;

class CXFreeList;

// This "represents" the string. This holds a reference count, and the
// allocated string itself. CXStr is a value-type wrapper that holds a
// reference to this. In then handle-body idiom, this is the body.
// See: http://www.cs.sjsu.edu/faculty/pearce/patterns/hanbod/hanbod.html
struct [[offsetcomments]] CStrRep
{
	// this isn't a std::atomic in eq, but it should have the
	// same layout in memory and thus we should be able to
	// get the same behavior from it without additional work.
/*0x00*/ std::atomic<int> refCount;
/*0x04*/ size_t alloc;
/*0x08*/ size_t length;
/*0x0c*/ EStringEncoding encoding;
/*0x10*/ CXFreeList* freeList;
	// The actual string data. Size does not matter, the length
	// is dynamic and manually allocated.
	union
	{
	/*0x14*/ char utf8[4];
	/*0x14*/ Unicode16 unicode[2];
	/*0x14*/ CStrRep* next;
	};
/*0x18*/
};

// Simple iterator traits checks
template <typename Iter>
using iter_cat_t = typename std::iterator_traits<Iter>::iterator_category;

template <typename T, class = void>
inline constexpr bool is_iterator_v = false;

template <typename T>
inline constexpr bool is_iterator_v<T, std::void_t<iter_cat_t<T>>> = true;

template <typename T>
struct is_iterator : std::bool_constant<is_iterator_v<T>> {};

// In the handle-body idiom, this is the handle. It is a value
// semantics type that holds the reference-counted CStrRep pointer.
// This class also implements copy-on-write.

// We implement lots of bonus methods on this that are not part of the EQ
// implementation, to give the string more of a std::string interface.
class EQLIB_OBJECT CXStr
{
public:
	// Types to give CXStr the qualities of a std::string
	using traits_type = std::char_traits<char>;
	using value_type = char;
	using allocator_type = eqlib::everquest_allocator<char>;
	using size_type = std::allocator_traits<allocator_type>::size_type;
	using difference_type = std::allocator_traits<allocator_type>::difference_type;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = std::allocator_traits<allocator_type>::pointer;
	using const_pointer = std::allocator_traits<allocator_type>::const_pointer;

	// iterator for immutable string.
	class ConstIterator
	{
	public:
		using iterator_category = std::random_access_iterator_tag;

		using value_type = typename CXStr::value_type;
		using difference_type = typename CXStr::difference_type;
		using pointer = typename CXStr::const_pointer;
		using reference = const value_type&;

		ConstIterator() = default;
		ConstIterator(pointer ptr) : m_ptr(ptr) {}

		[[nodiscard]] reference operator*() const
		{
			return *m_ptr;
		}

		[[nodiscard]] pointer operator->() const
		{
			return std::pointer_traits<pointer>::pointer_to(**this);
		}

		ConstIterator& operator++()
		{
			++m_ptr;
			return *this;
		}

		ConstIterator operator++(int)
		{
			auto tmp = *this;
			++*this;
			return tmp;
		}

		ConstIterator& operator--()
		{
			--m_ptr;
			return *this;
		}

		ConstIterator operator--(int)
		{
			auto tmp = *this;
			--*this;
			return tmp;
		}

		ConstIterator& operator+=(const difference_type offset)
		{
			m_ptr += offset;
			return *this;
		}

		[[nodiscard]] ConstIterator operator+(const difference_type offset) const
		{
			auto tmp = *this;
			return tmp += offset;
		}

		ConstIterator& operator-=(const difference_type offset)
		{
			return (*this += -offset);
		}

		[[nodiscard]] ConstIterator operator-(const difference_type offset) const
		{
			auto tmp = *this;
			return tmp -= offset;
		}

		[[nodiscard]] difference_type operator-(const ConstIterator& right) const
		{
			return m_ptr - right.m_ptr;
		}

		[[nodiscard]] reference operator[](const difference_type offset) const
		{
			return *(*this + offset);
		}

		[[nodiscard]] bool operator==(const ConstIterator& right) const
		{
			return m_ptr == right.m_ptr;
		}

		[[nodiscard]] bool operator!=(const ConstIterator& right) const
		{
			return !(*this == right);
		}

		[[nodiscard]] bool operator<(const ConstIterator& right) const
		{
			return m_ptr < right.m_ptr;
		}

		[[nodiscard]] bool operator>(const ConstIterator& right) const
		{
			return right < *this;
		}

		[[nodiscard]] bool operator<=(const ConstIterator& right) const
		{
			return !(right < *this);
		}

		[[nodiscard]] bool operator>=(const ConstIterator& right) const
		{
			return !(*this < right);
		}

	private:
		pointer m_ptr = nullptr;
	};

	// Iterator for mutable string
	class Iterator : public ConstIterator
	{
	public:
		using iterator_category = std::random_access_iterator_tag;

		using value_type = typename CXStr::value_type;
		using difference_type = typename CXStr::difference_type;
		using pointer = typename CXStr::pointer;
		using reference = value_type &;

		Iterator() = default;
		Iterator(pointer p) : ConstIterator(p) {}

		[[nodiscard]] reference operator*() const
		{
			return const_cast<reference>(ConstIterator::operator*());
		}

		[[nodiscard]] pointer operator->() const
		{
			return std::pointer_traits<pointer>::pointer_to(**this);
		}

		Iterator& operator++()
		{
			++* (ConstIterator*)this;
			return *this;
		}

		Iterator operator++(int)
		{
			auto tmp = *this;
			++* this;
			return tmp;
		}

		Iterator& operator--()
		{
			--* (ConstIterator*)this;
			return *this;
		}

		Iterator operator--(int)
		{
			auto tmp = *this;
			--* this;
			return tmp;
		}

		Iterator& operator+=(const difference_type offset)
		{
			*(ConstIterator*)this += offset;
			return *this;
		}

		[[nodiscard]] Iterator operator+(const difference_type offset) const
		{
			auto tmp = *this;
			return tmp += offset;
		}

		Iterator& operator-=(const difference_type offset)
		{
			return *this += -offset;
		}

		[[nodiscard]] Iterator operator-(const difference_type offset) const
		{
			auto tmp = *this;
			return tmp -= offset;
		}

		[[nodiscard]] difference_type operator-(const ConstIterator& right) const
		{
			return *(ConstIterator*)this - right;
		}

		[[nodiscard]] reference operator[](const difference_type offset) const
		{
			return *(*this + offset);
		}
	};

	using iterator = Iterator;
	using const_iterator = ConstIterator;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	template <typename StringViewIsh>
	using is_string_view_ish = std::enable_if_t<
		std::conjunction_v<
			std::is_convertible<const StringViewIsh&, std::string_view>,
			std::negation<std::is_convertible<const StringViewIsh&, const char*>>
		>>;

	template <typename Iter>
	using is_elem_cptr = std::bool_constant<std::_Is_any_of_v<Iter, const char* const, char* const, const char*, char*>>;

	static const size_type npos = -1;

	static inline const char* const s_defaultEmptyString = "";

	// Default constructor. Constructs empty string (zero size)
	CXStr() = default;

	// Copy constructor. Constructs the string with a copy of the contents of other.
	CXStr(const CXStr& other)
	{
		m_data = other.m_data;
		if (m_data)
			++m_data->refCount;
	}

	// Constructs the string with a substring [pos, pos + count) of other.
	// If count == npos, if count is not specified, or if the requested
	// substring lasts past the end of the string, the resulting substring is
	// [pos, other.size()]
	CXStr(const CXStr& other, size_type pos)
	{
		assign(other, pos);
	}

	CXStr(const CXStr& other, size_type pos, size_type count)
	{
		assign(other, pos, count);
	}

	// Constructs the string with the contents initialized with a copy of the
	// null-terminated character string pointed to by s. The length of the string
	// is determined by the first null character. The behavior is undefined if
	// [s, s + Traits::length(s)] is not a valid range (for example, if s is a
	// null pointer).
	CXStr(const char* s)
	{
		assign(s);
	}

	// Constructs the string with the first count characters of character string
	// pointed to by s. s can contain null characters. Thelength of the string is
	// count. The behavior is undefined if [s, s + count) is not a valid range.
	CXStr(const char* s, size_type count)
	{
		assign(s, count);
	}

	// Constructs the string with count copies of character ch.
	CXStr(size_type count, char ch)
	{
		assign(count, ch);
	}

	// Constructs the string with the contents of the range [first, last).
	template <typename InputIt, typename = std::enable_if_t<is_iterator_v<InputIt>>>
	CXStr(InputIt first, InputIt last)
	{
		assign(first, last);
	}

	// Move constructor. Constructs the string with the contents of other using
	// move semantics. other is left in valid, empty state.
	CXStr(CXStr&& other) noexcept
	{
		m_data = other.m_data;
		other.m_data = nullptr;
	}

	// Constructs the string with the contents of the initializer list ilist.
	CXStr(std::initializer_list<char> ilist)
	{
		assign(ilist.begin(), static_cast<size_t>(ilist.size()));
	}

	// Implicitly converts t to a string view sv as if by std::string_view sv = t,
	// then initializes the string with the contents of sv, as if by CXStr(sv.data(),
	// sv.size()). This overload only participates in overload resolution if t is
	// convertible to std::string_view but not convertible to const char*.
	template <typename T, typename = is_string_view_ish<T>>
	explicit CXStr(const T& t)
	{
		assign(t);
	}

	// Implicitly converts t to a string_view sv as if by std::string_view sv = t;,
	// then initializes the string with the subrange [pos, pos + n) of sv as if by
	// using CXStr(sv.substr(pos, n), a). This overload only participates in overload
	// resolution if t is convertible to std::string_view.
	template <typename T, typename = is_string_view_ish<T>>
	CXStr(const T& t, size_type pos, size_type n)
	{
		assign(t, pos, n);
	}

	// Destructor. Decrements the reference count of the internal CStrRep. If the ref
	// count reaches zero, the CStrRep is destroyed.
	~CXStr()
	{
		FreeRep(m_data);
		m_data = nullptr;
	}

	// Replaces the contents with a copy of str. If *this and str are the same object,
	// this function has no effect.
	CXStr& operator=(const CXStr& str)
	{
		if (this != std::addressof(str))
		{
			// increment other first in case they both share the same rep.
			if (str.m_data)
				++str.m_data->refCount;

			FreeRep(m_data);
			m_data = str.m_data;
		}
		return *this;
	}

	// Replaces the contents with those of str using move semantics. str is in a valid
	// and empty state afterwards. References, pointers, and iterators to str may be
	// invalidated.
	CXStr& operator=(CXStr&& str) noexcept
	{
		if (this != std::addressof(str))
		{
			// If they both point to the same rep we don't want to release.
			if (str.m_data != m_data)
				FreeRep(m_data);

			m_data = str.m_data;
			str.m_data = nullptr;
		}
		return *this;
	}

	// Replaces the contents with those of null-terminated character string pointed to
	// by s as if by assign(s, Traits::length(s));
	CXStr& operator=(const char* s)
	{
		return assign(s);
	}

	// Replaces the contents with character ch as if by assign(std::addressof(ch), 1);
	CXStr& operator=(char ch)
	{
		return assign(std::addressof(ch), 1);
	}

	// Replaces the contents with those of the initializer list ilist as if by
	// assign(ilist.begin(), ilist.size());
	CXStr& operator=(std::initializer_list<char> ilist)
	{
		return assign(ilist.begin(), static_cast<size_t>(ilist.size()));
	}

	// Implicitly converts t to a string_view sv as if by std::string_view sv = t;,
	// then replaces the contents with those of the sv as if by assign(sv). This
	// overload only participates in overload resolution if t is convertible to
	// string_view but not const char*.
	template <typename T, typename = is_string_view_ish<T>>
	CXStr& operator=(const T& t)
	{
		return assign(t);
	}

	// Replaces the contents with count copies of ch.
	CXStr& assign(size_type count, char ch)
	{
		FreeRep(m_data);
		m_data = nullptr;

		Assure(count + 1, StringEncodingUtf8);

		m_data->length = count;
		traits_type::assign(m_data->utf8, count, ch);
		traits_type::assign(m_data->utf8[count], value_type());

		return *this;
	}

	// Replaces the contents with a copy of str. Equivalent to *this = str;
	CXStr& assign(const CXStr& str)
	{
		*this = str;
		return *this;
	}

	// Replaces the contents with a substring [pos, pos + count) of str. If the
	// requested substring lasts past the end of the string, or if count == npos,
	// the resulting substring is [pos, str.size()). If pos > str.size(),
	// std::out_of_range is thrown.
	CXStr& assign(const CXStr& str, size_type pos, size_type count = npos)
	{
		str.CheckOffset(pos);
		count = str.ClampSuffixSize(pos, count);
		return assign(str.data() + pos, count);
	}

	// Replaces the contents with those of str using move semantics. Equivalent to
	// *this = std::move(str).
	CXStr& assign(CXStr&& str) noexcept
	{
		*this = std::move(str);
		return *this;
	}

	// Replaces the contents with copies of characters in the range [s, s + count).
	// This range can contain null characters.
	CXStr& assign(const char* s, size_type count)
	{
		FreeRep(m_data);
		m_data = nullptr;

		Assure(count + 1, StringEncodingUtf8);

		m_data->length = count;
		traits_type::move(m_data->utf8, s, count);
		traits_type::assign(m_data->utf8[count], value_type());

		return *this;
	}

	// Replaces the contents with those of null-terminated character string pointed
	// to by s. The length of the string is determined by the first null character
	// using Traits::length(s);
	CXStr& assign(const char* s)
	{
		return assign(s, static_cast<size_t>(traits_type::length(s)));
	}

	// Replaces the contents with copies of the characters in the range [first, last).
	// This overload does not participate in overload resolution if InputIt does not
	// satisfy LegacyInputIterator.
	template <typename InputIt, typename = std::enable_if_t<is_iterator_v<InputIt>>>
	CXStr& assign(InputIt first, InputIt last)
	{
		return replace(begin(), end(), first, last);
	}

	// Replaces the contents with those of the initializer list ilist.
	CXStr& assign(std::initializer_list<char> ilist)
	{
		return assign(ilist.begin(), static_cast<size_t>(ilist.size()));
	}

	// Implicitly converts t to a string_view sv as if by std::string_view sv = t;,
	// then replaces the contents with those of sv, as if by assign(sv.data(),
	// sv.size()). This overload only participate sin overload resolution if
	// t is convertible to string_view but not const char*.
	template <typename T, typename = is_string_view_ish<T>>
	CXStr& assign(const T& t)
	{
		const std::string_view sv = t;
		return assign(sv.data(), static_cast<size_t>(sv.size()));
	}

	// Implicitly converts t to a string_view sv as if by std::stirng_view sv = t;,
	// then replaces the contents with the characters from the subview [pos,
	// pos + count) of sv. If the requested subview lasts past the end of sv, or
	// if count == npos, the resulting subview is [pos, sv.size()). If pos > sv.size()
	// std::out_of_range is thrown. This overload only participates in overload
	// resolution if t is convertible to string_view but not const char*.
	template <typename T, typename = is_string_view_ish<T>>
	CXStr& assign(const T& t, size_type pos, size_type count = npos)
	{
		const std::string_view sv = t;
		return assign(sv.substr(pos, count));
	}

	// ** Element access **

	// Returns a reference to the character at specified location pos. Bounds checking
	// is performed, exception of type std::out_of_range will be thrown on invalid
	// access.
	[[nodiscard]] reference at(size_type pos)
	{
		AssureAccessible();
		CheckOffsetExclusive(pos);

		// can only interact with utf8 based strings
		SetEncoding(StringEncodingUtf8);
		return m_data->utf8[pos];
	}

	[[nodiscard]] const_reference at(size_type pos) const
	{
		AssureAccessible();
		CheckOffsetExclusive(pos);

		// We can only interact with utf8 based strings.
		SetEncoding(StringEncodingUtf8);
		return m_data->utf8[pos];
	}

	// Returns a reference to the character at specified location pos. No bounds
	// checking is performed. If pos > size(), the behavior is undefined.
	reference operator[](size_type pos)
	{
		AssureAccessible();

#if _ITERATOR_DEBUG_LEVEL >= 1
		_STL_VERIFY(pos <= m_data->length, "string subscript out of range");
#endif /* _ITERATOR_DEBUG_LEVEL >= 1 */

		// We can only interact with utf8 based strings.
		SetEncoding(StringEncodingUtf8);
		return m_data->utf8[pos];
	}
	const_reference operator[](size_type pos) const
	{
		AssureAccessible();

#if _ITERATOR_DEBUG_LEVEL >= 1
		_STL_VERIFY(pos <= m_data->length, "string subscript out of range");
#endif /* _ITERATOR_DEBUG_LEVEL >= 1 */

		// We can only interact with utf8 based strings.
		SetEncoding(StringEncodingUtf8);
		return m_data->utf8[pos];
	}

	// Returns reference to the first character in the string. The behavior is
	// undefined if empty() == true.
	reference front() { return operator[](0); }
	const_reference front() const { return operator[](0); }

	// Returns reference to the last character in the string. The behavior is
	// undefined if empty() == true.
	reference back() { return operator[](size() - 1); }
	const_reference back() const { return operator[](size() - 1); }

	// Returns a pointer to the underlying array serving as character storage. The
	// pointer is such that the range [data(), data() + size()) is valid and the
	// values correspond to the values stored in the string.
	// The returned array is null-terminated. That is, data() and c_str() perform
	// the same function. If empty() returns true, the pointer points to a single
	// null character.
	pointer mutable_data() noexcept
	{
		AssureCopy();

		SetEncoding(StringEncodingUtf8);
		return m_data->utf8;
	}

	const_pointer data() const noexcept
	{
		if (!m_data)
			return s_defaultEmptyString;

		SetEncoding(StringEncodingUtf8);
		return m_data->utf8;
	}

	// Returns a pointer to a null-terminated character array with data equivalent
	// to those stored in the string. See data()
	const_pointer c_str() const noexcept
	{
		return data();
	}

	// Returns a std::string_view, constructed as if by string_view(data(), size())
	operator std::string_view() const noexcept
	{
		return std::string_view(data(), size());
	}

#if 0
	// dangerous conversion operators.
	operator const void*() const
	{
		return data();
	}
	operator const void*()
	{
		return data();
	}

	operator const char*() const
	{
		return data();
	}
	operator const char*()
	{
		return data();
	}
#endif

	// ** Iterators **

	// Returns an iterator to the first character of the string.
	iterator begin() noexcept
	{
		AssureAccessible();
		return iterator(m_data->utf8);
	}

	const_iterator begin() const noexcept
	{
		AssureAccessible();
		return const_iterator(m_data->utf8);
	}

	const_iterator cbegin() const noexcept
	{
		return begin();
	}

	// Returns an iterator to the character following the last character of the
	// string. This character acts as a placeholder, attempting to access it
	// results in undefined behavior.
	iterator end() noexcept
	{
		AssureAccessible();
		return iterator(m_data->utf8 + m_data->length);
	}

	const_iterator end() const noexcept
	{
		AssureAccessible();
		return const_iterator(m_data->utf8 + m_data->length);
	}

	const_iterator cend() const noexcept
	{
		return end();
	}

	// Returns a reverse iterator to the first characer of the reversed string.
	// It corresponds to the last character of the non-reversed string.
	reverse_iterator rbegin() noexcept
	{
		return reverse_iterator{ end() };
	}

	const_reverse_iterator rbegin() const noexcept
	{
		return const_reverse_iterator{ end() };
	}

	const_reverse_iterator crbegin() const noexcept
	{
		return rbegin();
	}

	// Returns a reverse iterator to the character following the last character of
	// the reversed string. It corresponds to the character preceding the first
	// character of the non-reversed string. This character acts as a placeholder,
	// attempting to access it results in undefined behavior.
	reverse_iterator rend() noexcept
	{
		return reverse_iterator{ begin() };
	}

	const_reverse_iterator rend() const noexcept
	{
		return const_reverse_iterator{ begin() };
	}

	const_reverse_iterator crend() const noexcept
	{
		return rend();
	}

	// ** Capacity **

	// Checks if the string has no characters
	[[nodiscard]] bool empty() const noexcept { return length() == 0; }

	// Returns the number of char elements in the string.
	size_type size() const noexcept { return m_data ? m_data->length : 0; }
	size_type length() const noexcept { return m_data ? m_data->length : 0; }

	// Informs a CXStr object of a planned change in size, so that it can manage
	// the storage allocation appropriately. If new_cap is greater than the current
	// capacity(), new storage is allocated, and capacity() is made equal or greater
	// than new_cap.
	// If new_cap is less than the current capacity(), there is no effect.
	// A call to reserve with no argument is a non-binding shrink-to-fit request.
	// After this call, capacity() has an unspecified value greater than or equal
	// to size().
	void reserve(size_type new_cap)
	{
		if (new_cap <= capacity())
			return;

		Assure(new_cap, GetEncoding());
	}

	void reserve()
	{
	}

	// Returns the number of characters that the string has currentlly allocated
	// space for.
	size_type capacity() const noexcept { return m_data ? m_data->alloc : 0; }

	// ** Operations **

	// Removes all characters from the string as if by executing erase(begin(), end()).
	// All pointers, references, and iterators are invalidated.
	void clear() noexcept
	{
		FreeRep(m_data);
		m_data = nullptr;
	}

	// Inserts count copies of character ch at the position index
	CXStr& insert(size_type index, size_type count, char ch)
	{
		CheckOffset(index);
		Assure(size() + count + 1, StringEncodingUtf8);

		size_t oldSize = m_data->length;
		m_data->length = oldSize + count;
		char* ptr = m_data->utf8;
		char* insertPos = ptr + index;

		// Move suffix + null byte to end
		traits_type::move(insertPos + count, insertPos, oldSize - index + 1);

		// Fill hole
		traits_type::assign(insertPos, count, ch);

		return *this;
	}

	// Inserts null-terminated character string pointed to by s at the position index.
	// The length of the string is determined by the first null character using
	// Traits::length(s).
	CXStr& insert(size_type index, const char* s)
	{
		return insert(index, s, traits_type::length(s));
	}

	// Inserts the characters in the range [s, s + count) at the position index. The
	// range can contain null characters.
	CXStr& insert(size_type index, const char* s, size_type count)
	{
		CheckOffset(index);
		Assure(size() + count + 1, StringEncodingUtf8);

		size_t oldSize = m_data->length;
		m_data->length = oldSize + count;
		char* ptr = m_data->utf8;
		char* insertPos = ptr + index;

		// handle case where s may be aliasing data that is shifting.
		size_t shifted;
		if (s + count <= insertPos || s > ptr + oldSize)
		{
			// inserted content is before the shifted region or doesn't alias
			shifted = count;
		}
		else if (insertPos <= s)
		{
			// all of [s, s + count) shifts
			shifted = 0;
		}
		else
		{
			// [s, s + count) contains insertPos, so only part after insertPos shifts.
			shifted = static_cast<size_t>(insertPos - s);
		}

		traits_type::move(insertPos + count, insertPos, oldSize - index + 1); // move suffix + null
		traits_type::copy(insertPos, s, shifted);
		traits_type::copy(insertPos + shifted, s + count + shifted, count - shifted);

		return *this;
	}

	// Inserts string str at the position index.
	CXStr& insert(size_type index, const CXStr& str)
	{
		if (str.empty())
			return *this;

		return insert(index, str.data(), str.size());
	}

	// Inserts a string, obtained by str.substr(index_str, count) at the position index
	CXStr& insert(size_type index, const CXStr& str, size_type index_str, size_type count = npos)
	{
		std::string_view sv = str;
		return insert(index, sv.substr(index_str, count));
	}

	// Inserts a character ch before the character pointed by pos.
	iterator insert(const_iterator pos, char ch)
	{
		const difference_type offset = pos - begin();
		insert(static_cast<size_t>(offset), 1, ch);
		return begin() + offset;
	}

	// Inserts count copies of character ch before the element (if any) pointed by pos.
	iterator insert(const_iterator pos, size_type count, char ch)
	{
		const difference_type offset = pos - begin();
		insert(static_cast<size_t>(offset), count, ch);
		return begin() + offset;
	}

	// Inserts characters from the range [first, last) before the element (if any)
	// pointed by pos. This overload does not participate in overload resolution if
	// InputIt does not satisfy LegacyInputIterator.
	template <typename InputIt, typename = std::enable_if_t<is_iterator_v<InputIt>>>
	iterator insert(const_iterator pos, InputIt first, InputIt last)
	{
		const difference_type offset = pos - begin();
		replace(pos, pos, first, last);
		return begin() + offset;
	}

	// Inserts elements from initializer_list ilist before the element (if any) pointed
	// by pos.
	iterator insert(const_iterator pos, std::initializer_list<char> ilist)
	{
		const difference_type offset = pos - begin();
		insert(static_cast<size_t>(offset), ilist.begin(), static_cast<size_t>(ilist.size()));
		return begin() + offset;
	}

	// Implicitly converts t to a string_view sv as if by std::string_view sv = t;,
	// then inserts the elements from sv before the element (if any) pointed by pos,
	// as if by insert(pos, sv.data(), sv.size()). This overload only participates in
	// overload resolution if t is convertible to string_view but not const char*.
	template <typename T, typename = is_string_view_ish<T>>
	CXStr& insert(size_type pos, const T& t)
	{
		std::string_view sv = t;
		return insert(pos, sv.data(), static_cast<size_t>(sv.size()));
	}

	// Implicitly converts t to a string_view sv as if by std::string_view sv = t;,
	// then inserts, before the element (if any) pointed by pos, the characters from
	// the subview [index_str, index_str + count) of sv. If the requested subview lasts
	// past the end of sv, or if count == npos, the resulting subview is [index_str,
	// sv.size()). If index_str > sv.size(), or if index > size(), std::out_of_range is
	// thrown. This overload only participates in overload resolution if t is
	// convertible to string_view but not const char*.
	template <typename T, typename = is_string_view_ish<T>>
	CXStr& insert(size_type pos, const T& t, size_type index_str, size_type count = npos)
	{
		std::string_view sv = t;
		return insert(pos, sv.substr(index_str, count));
	}

	// Erases [index, ...) from the string
	CXStr& erase(size_type index = 0)
	{
		if (index == 0)
			clear();
		else
		{
			CheckOffset(index);
			Assure(size() + 1, StringEncodingUtf8);

			traits_type::assign(m_data->utf8[m_data->length = index], value_type());
		}

		return *this;
	}

	// Removes min(count(), size() - index) characters from the string, starting at index.
	CXStr& erase(size_type index, size_type count)
	{
		CheckOffset(index);
		Assure(size() + 1, StringEncodingUtf8);

		count = ClampSuffixSize(index, count);
		const size_type oldSize = m_data->length;
		char* ptr = m_data->utf8;
		char* eraseAt = ptr + index;
		const size_type newSize = oldSize - count;
		m_data->length = newSize;
		traits_type::move(eraseAt, eraseAt + count, newSize - index + 1); // move suffix and null up

		return *this;
	}

	// Removes the character at the specified position from the string
	iterator erase(const_iterator position)
	{
		const difference_type offset = position - begin();
		erase(static_cast<size_type>(offset), 1);
		return begin() + offset;
	}

	// Removes the characters in the range [first, last) from the string.
	iterator erase(const_iterator first, const_iterator last)
	{
		const difference_type offset = first - begin();
		erase(static_cast<size_type>(offset), static_cast<size_type>(last - first));
		return begin() + offset;
	}

	// Appends the given character ch to the end of the string.
	void push_back(char ch)
	{
		Assure(size() + 2, StringEncodingUtf8);

		size_type oldSize = m_data->length++;
		traits_type::assign(m_data->utf8[oldSize], ch);
		traits_type::assign(m_data->utf8[oldSize + 1], value_type());
	}

	// Removes the last character frmo the string. Equivalent to erase(end() - 1). The
	// behavior is undefined if the string is empty.
	void pop_back()
	{
		erase(size() - 1);
	}

	// Appends count copies of character ch
	CXStr& append(size_type count, char ch)
	{
		Assure(size() + count + 1, StringEncodingUtf8);

		const size_type oldSize = m_data->length;
		m_data->length = oldSize + count;

		traits_type::assign(m_data->utf8 + oldSize, count, ch);
		traits_type::assign(m_data->utf8[oldSize + count], value_type());

		return *this;
	}

	// Appends string str
	CXStr& append(const CXStr& str)
	{
		return append(str.data(), str.size());
	}

	// Appends a substring [pos, pos + count) of str. If the requested substring lasts past
	// the end of the string, or if count == npos, the appended substring is [pos, size()). If
	// pos > str.size(), std::out_of_range is thrown.
	CXStr& append(const CXStr& str, size_type pos, size_type count = npos)
	{
		std::string_view sv = str;
		return append(sv.substr(pos, count));
	}

	// Appends characters in the range [s, s + count). This range can contain null characters.
	CXStr& append(const char* s, size_type count)
	{
		Assure(size() + count + 1, StringEncodingUtf8);

		const size_type oldSize = m_data->length;
		m_data->length = oldSize + count;

		traits_type::move(m_data->utf8 + oldSize, s, count);
		traits_type::assign(m_data->utf8[oldSize + count], value_type());

		return *this;
	}

	// Appends the null-terminated character string pointed to by s. The length of the string is
	// determined by the first null character.
	CXStr& append(const char* s)
	{
		return append(s, static_cast<size_type>(traits_type::length(s)));
	}

	// Appends characters in the range [first, last).
	template <typename InputIt, typename = std::enable_if_t<is_iterator_v<InputIt>>>
	CXStr& append(InputIt first, InputIt last)
	{
		return replace(end(), end(), first, last);
	}

	// Appends characters from the initializer list ilist.
	CXStr& append(std::initializer_list<char> ilist)
	{
		return append(ilist.begin(), static_cast<size_t>(ilist.size()));
	}

	// Implicitly converts to to a string view sv as if by string_view sv = t;, then appends all
	// characters from sv as if by append(sv.data(), sv.size()). This only participates in overload
	// resolution if t is convertible to string_view but not const char*.
	template <typename T, typename = is_string_view_ish<T>>
	CXStr& append(const T& t)
	{
		std::string_view sv = t;
		return append(sv.data(), static_cast<size_type>(sv.size()));
	}

	// Implicitly converts t to a string view sv as if by string_view sv = t;, then appends the
	// characters from the subview [pos, pos + count) of sv. If the requested subview extends past
	// the end of sv,or if count == npos, the appended subview is [pos, sv.size()). If pos >= sv.size(),
	// std::out_of_range is thrown. This overload only participates in overload resolution if t is
	// convertible to string view but not const char*.
	template <typename T, typename = is_string_view_ish<T>>
	CXStr& append(const T& t, size_type pos, size_type count = npos)
	{
		std::string_view sv = t;
		return append(sv.substr(pos, count));
	}

	// Appends string str
	CXStr& operator+=(const CXStr& str)
	{
		return append(str);
	}

	// Appends character ch
	CXStr& operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	// Appends the null-terminated character string pointed to by s
	CXStr& operator+=(const char* s)
	{
		return append(s);
	}

	// Appends characters in the initializer list ilist
	CXStr& operator+=(std::initializer_list<char> ilist)
	{
		return append(ilist.begin(), static_cast<size_t>(ilist.size()));
	}

	// Appends characters in the string_view-like type t
	template <typename T, typename = is_string_view_ish<T>>
	CXStr& operator+=(const T& t)
	{
		return append(t);
	}

	// Compares this string to str.
	int compare(const CXStr& str) const noexcept
	{
		return std::string_view{ *this }.compare(std::string_view{ str });
	}

	// Compares a [pos1, pos1+count1) substring of this string to str
	int compare(size_type pos1, size_type count1, const CXStr& str) const
	{
		return std::string_view{ *this }.compare(pos1, count1, std::string_view{ str });
	}

	// Compares a [pos1, pos1+count1) substring of this string to a substring [pos2, pos2+count2)
	// of str. If either string is count > size() - pos, the substring is [pos, size()).
	int compare(size_type pos1, size_type count1, const CXStr& str,
		size_type pos2, size_type count2 = npos) const
	{
		return std::string_view{ *this }.compare(pos1, count1, std::string_view{ str }, pos2, count2);
	}

	int compare(const char* s) const
	{
		return std::string_view{ *this }.compare(s);
	}

	int compare(size_type pos1, size_type count1, const char* s) const
	{
		return std::string_view{ *this }.compare(pos1, count1, s);
	}

	int compare(size_type pos1, size_type count1, const char* s, size_type count2) const
	{
		return std::string_view{ *this }.compare(pos1, count1, s, count2);
	}

	template <typename T, typename = is_string_view_ish<T>>
	int compare(const T& t) const noexcept
	{
		return std::string_view{ *this }.compare(t);
	}

	template <typename T>
	int compare(size_type pos1, size_type count1, const T& t) const
	{
		return std::string_view{ *this }.compare(pos1, count1, t);
	}

	template <typename T>
	int compare(size_type pos1, size_type count1, const T& t,
		size_type pos2, size_type count2 = npos) const
	{
		return std::string_view{ *this }.compare(pos1, count1, 2, pos2, count2);
	}

	// Checks if the string begins with the given prefix.
	bool starts_with(std::string_view x) const noexcept
	{
		return size() >= x.size() && std::string_view{ *this }.compare(0, x.size(), x) == 0;
	}

	bool starts_with(char x) const noexcept
	{
		return size() >= 1 && at(0) == x;
	}

	bool starts_with(const char* x) const
	{
		return starts_with(std::string_view{ x });
	}

	// Checks if the string ends with the given suffix.
	bool ends_with(std::string_view x) const noexcept
	{
		return size() >= x.size() && std::string_view{ *this }.compare(
			size() - x.size(), x.size(), x) == 0;
	}

	bool ends_with(char x) const noexcept
	{
		return size() >= 1 && at(size() - 1) == x;
	}

	bool ends_with(const char* x) const
	{
		return ends_with(std::string_view{ x });
	}

	// Replaces the part of the string indicated by either [pos, pos + count) or
	// [first, last) with a new string.
	CXStr& replace(size_type pos, size_type count, const CXStr& str)
	{
		std::string_view sv = str;
		return replace(pos, count, sv.data(), static_cast<size_type>(sv.size()));
	}

	CXStr& replace(const_iterator first, const_iterator last, const CXStr& str)
	{
		return replace(static_cast<size_type>(first - begin()), static_cast<size_type>(last - first), str);
	}

	CXStr& replace(size_type pos, size_type count, const CXStr& str, size_type pos2, size_type count2 = npos)
	{
		std::string_view sv = str;
		return replace(pos, count, sv.substr(pos2, count2));
	}

	template <typename InputIt, typename = std::enable_if_t<is_iterator_v<InputIt>>>
	CXStr& replace(const_iterator first, const_iterator last,
		InputIt first2, InputIt last2)
	{
		return replace_range(first, last, first2, last2, is_elem_cptr<decltype(first2)>());
	}

	CXStr& replace(size_type pos, size_type count, const char* cstr, size_type count2)
	{
		CheckOffset(pos);
		count = ClampSuffixSize(pos, count);

		const size_type oldSize = size();
		const size_type newSize = oldSize - (count - count2);

		Assure(newSize + 1, StringEncodingUtf8);

		if (count == count2)
		{
			traits_type::move(m_data->utf8 + pos, cstr, count2);
			return *this;
		}

		m_data->length = newSize;
	}

	CXStr& replace(const_iterator first, const_iterator last,
		const char* cstr, size_type count2)
	{
		return replace(static_cast<size_type>(first - begin()), static_cast<size_type>(last - first), cstr, count2);
	}

	CXStr& replace(size_type pos, size_type count, const char* cstr)
	{
		return replace(pos, count, cstr, static_cast<size_type>(traits_type::length(cstr)));
	}
	CXStr& replace(const_iterator first, const_iterator last, const char* cstr)
	{
		return replace(static_cast<size_type>(first - begin()), static_cast<size_type>(last - first), cstr);
	}

	CXStr& replace(size_type pos, size_type count, size_type count2, char ch)
	{
		CheckOffset(pos);
		count = ClampSuffixSize(pos, count);

		const size_type oldSize = size();
		size_type newSize = oldSize + count2 - count;

		Assure(newSize + 1, StringEncodingUtf8);

		if (count == count2)
		{
			// no resize, just assign
			traits_type::assign(m_data->utf8 + pos, count, ch);
			return *this;
		}

		m_data->length = newSize;
		char* insertAt = m_data->utf8 + pos;

		traits_type::move(insertAt + count2, insertAt + count, oldSize - count - pos + 1);
		traits_type::assign(insertAt, count2, ch);

		return *this;
	}

	CXStr& replace(const_iterator first, const_iterator last, size_type count2, char ch)
	{
		return replace(static_cast<size_type>(first - begin()), static_cast<size_type>(last - first), count2, ch);
	}

	CXStr& replace(const_iterator first, const_iterator last, std::initializer_list<char> ilist)
	{
		return replace(static_cast<size_type>(first - begin()), static_cast<size_type>(last - first),
			ilist.begin(), static_cast<size_type>(ilist.size()));
	}

	template <typename T, typename = is_string_view_ish<T>>
	CXStr& replace(size_type pos, size_type count, const T& t)
	{
		std::string_view sv = t;
		return replace(pos, count, sv.data(), static_cast<size_type>(sv.size()));
	}

	template <typename T, typename = is_string_view_ish<T>>
	CXStr& replace(const_iterator first, const_iterator last, const T& t)
	{
		return replace(static_cast<size_type>(first - begin()), static_cast<size_type>(last - first), t);
	}

	template <typename T, typename = is_string_view_ish<T>>
	CXStr& replace(size_type pos, size_type count, const T& t, size_type pos2, size_type count2 = npos)
	{
		std::string_view sv = t;
		return replace(pos, count, sv.substr(pos2, count2));
	}

	// Returns a substring [pos, pos + count). If the requested substring extends
	// past the end of the string, or if count == npos, the returned substring is
	// [pos, size()). Throws std::out_of_range if pos > size()
	CXStr substr(size_type pos = 0, size_type count = npos) const
	{
		return CXStr(std::string_view{ *this }, pos, count);
	}

	// Copies a substring [pos, pos + count) to character string pointed to by dest.
	// If the requested substring lasts past the end of the string, or if
	// count == npos, the copied substring is [pos, size()). The resulting string
	// is not null-terminated. if pos > size(), std::out_of_range is thrown.
	size_type copy(char* dest, size_type count, size_type pos = 0) const
	{
		CheckOffset(pos);
		count = ClampSuffixSize(pos, count);

		if (size() > 0)
		{
			traits_type::copy(dest, m_data->utf8 + pos, count);
		}
	}

	// Resizes the string to contain count characters. If the current size is less
	// than count, additional characters are appended. If the current size is
	// greater than count, the string is reduced to its first count elements. The
	// first version initializes new characters to char(), the second version
	// initializes new characters to ch.
	void resize(size_type count)
	{
		resize(count, char());
	}

	void resize(size_type count, char ch)
	{
		if (count == size())
			return;

		if (count > size())
		{
			append(size() - count, ch);
		}
		else
		{
			// shrink
			Assure(count + 1, StringEncodingUtf8);

			m_data->utf8[m_data->length = count] = char();
		}
	}

	// Exchanges the contents of the string with those of the other. All iterators
	// and references may be invalidated.
	void swap(CXStr& other) noexcept
	{
		std::swap(m_data, other.m_data);
	}

	// ** EQ functions **

	EStringEncoding GetEncoding() const
	{
		return m_data ? m_data->encoding : StringEncodingUtf8;
	}

	void SetEncoding(EStringEncoding encoding)
	{
		if (encoding == GetEncoding())
			return;

		if (m_data)
			Assure(m_data->length + 1, encoding);
		else
			Assure(2, encoding);
	}

	void SetEncoding(EStringEncoding encoding) const // only const for hacky reasons
	{
		const_cast<CXStr*>(this)->SetEncoding(encoding);
	}

	int Compare(const CXStr& other, ECompareMode mode = CaseSensitive) const;
	int CompareN(const CXStr& other, int len, ECompareMode mode = CaseSensitive) const;

private:
	mutable CStrRep* m_data = nullptr;

	template <typename Ptr>
	CXStr& replace_range(const const_iterator first, const const_iterator last,
		const Ptr first2, const Ptr last2, std::false_type)
	{
		// replace [first, last) with [first2, last2) using input_iterators
		const CXStr right(first2, last2);
		replace(first, last, right);
		return *this;
	}

	template <typename Ptr>
	CXStr& replace_range(const const_iterator first, const const_iterator last,
		const Ptr first2, const Ptr last2, std::true_type)
	{
		// replace [first, last) with [first2, last2) using pointers
		return replace(static_cast<size_type>(first - cbegin()), static_cast<size_type>(last - first),
			first2, static_cast<size_type>(last2 - first2));
	}

	void AssureAccessible() const noexcept;
	void Assure(size_type size, EStringEncoding encoding);
	void AssureCopy();
	CStrRep* AllocRepNoLock(size_type size, EStringEncoding encoding);
	void FreeRep(CStrRep* rep);
	void FreeRepNoLock(CStrRep* rep);

	[[noreturn]] void CheckOffset(const size_t offset) const
	{
		if (size() < offset)
		{
			throw std::out_of_range("invalid string position");
		}
	}

	[[noreturn]] void CheckOffsetExclusive(const size_t offset) const
	{
		if (size() <= offset)
		{
			throw std::out_of_range("invalid string position");
		}
	}

	size_t ClampSuffixSize(const size_t offset, const size_t size) const noexcept
	{
		size_t mySize = length();
		return std::min<size_t>(size, mySize - offset);
	}
};

[[nodiscard]] inline CXStr::ConstIterator operator+(typename CXStr::ConstIterator::difference_type offset,
	CXStr::ConstIterator next)
{
	return next += offset;
}

[[nodiscard]] inline CXStr::Iterator operator+(typename CXStr::Iterator::difference_type offset,
	CXStr::Iterator next)
{
	return next += offset;
}

inline void swap(CXStr& lhs, CXStr& rhs) noexcept
{
	lhs.swap(rhs);
}

// Comparison operator implementations. We provide all comparison operations
// in terms of CXStr::compare, supporting comparison between CXStr and const char*
// without conversion.

// Check for equality (comparison == 0)
[[nodiscard]] inline bool operator==(const CXStr& lhs, const CXStr& rhs)
{
	return lhs.compare(rhs) == 0;
}

[[nodiscard]] inline bool operator==(const CXStr& lhs, const char* rhs)
{
	return lhs.compare(rhs) == 0;
}

[[nodiscard]] inline bool operator==(const char* lhs, const CXStr& rhs)
{
	return rhs.compare(lhs) == 0;
}

// Check for inequality
[[nodiscard]] inline bool operator!=(const CXStr& lhs, const CXStr& rhs)
{
	return lhs.compare(rhs) != 0;
}

[[nodiscard]] inline bool operator!=(const CXStr& lhs, const char* rhs)
{
	return lhs.compare(rhs) != 0;
}

[[nodiscard]] inline bool operator!=(const char* lhs, const CXStr& rhs)
{
	return rhs.compare(lhs) != 0;
}

// Check for less-than
[[nodiscard]] inline bool operator<(const CXStr& lhs, const CXStr& rhs)
{
	return lhs.compare(rhs) < 0;
}

[[nodiscard]] inline bool operator<(const CXStr& lhs, const char* rhs)
{
	return lhs.compare(rhs) < 0;
}

[[nodiscard]] inline bool operator<(const char* lhs, const CXStr& rhs)
{
	return !(rhs.compare(lhs) < 0);
}

// Check for less-than-or-equal
[[nodiscard]] inline bool operator<=(const CXStr& lhs, const CXStr& rhs)
{
	return lhs.compare(rhs) <= 0;
}

[[nodiscard]] inline bool operator<=(const CXStr& lhs, const char* rhs)
{
	return lhs.compare(rhs) <= 0;
}

[[nodiscard]] inline bool operator<=(const char* lhs, const CXStr& rhs)
{
	return !(rhs.compare(lhs) <= 0);
}

// Check for greater-than
[[nodiscard]] inline bool operator>(const CXStr& lhs, const CXStr& rhs)
{
	return lhs.compare(rhs) > 0;
}

[[nodiscard]] inline bool operator>(const CXStr& lhs, const char* rhs)
{
	return lhs.compare(rhs) > 0;
}

[[nodiscard]] inline bool operator>(const char* lhs, const CXStr& rhs)
{
	return !(rhs.compare(lhs) > 0);
}

// Check for greater-than-or-equal
[[nodiscard]] inline bool operator>=(const CXStr& lhs, const CXStr& rhs)
{
	return lhs.compare(rhs) >= 0;
}

[[nodiscard]] inline bool operator>=(const CXStr& lhs, const char* rhs)
{
	return lhs.compare(rhs) >= 0;
}

[[nodiscard]] inline bool operator>=(const char* lhs, const CXStr& rhs)
{
	return !(rhs.compare(lhs) >= 0);
}

// Concatenation
[[nodiscard]] inline CXStr operator+(const CXStr& lhs, const CXStr& rhs)
{
	CXStr result;
	result.reserve(lhs.size() + rhs.size());
	result += lhs;
	result += rhs;
	return result;
}

[[nodiscard]] inline CXStr operator+(const CXStr& lhs, const char* rhs)
{
	CXStr result;
	result.reserve(lhs.size() + CXStr::traits_type::length(rhs));
	result += lhs;
	result += rhs;
	return result;
}

[[nodiscard]] inline CXStr operator+(const CXStr& lhs, char rhs)
{
	CXStr result;
	result.reserve(lhs.size() + 1);
	result += lhs;
	result += rhs;
	return result;
}

[[nodiscard]] inline CXStr operator+(const char* lhs, const CXStr& rhs)
{
	CXStr result;
	result.reserve(CXStr::traits_type::length(lhs) + rhs.size());
	result += lhs;
	result += rhs;
	return result;
}

[[nodiscard]] inline CXStr operator+(char lhs, const CXStr& rhs)
{
	CXStr result;
	result.reserve(1 + rhs.size());
	result += lhs;
	result += rhs;
	return result;
}

[[nodiscard]] inline CXStr operator+(CXStr&& lhs, CXStr&& rhs)
{
	if (rhs.size() <= lhs.capacity() - lhs.size()
		|| rhs.capacity() - rhs.size() < lhs.size())
		return std::move(lhs.append(rhs));
	else
		return std::move(rhs.insert(0, lhs));
}

[[nodiscard]] inline CXStr operator+(CXStr&& lhs, const CXStr& rhs)
{
	return std::move(lhs.append(rhs));
}

[[nodiscard]] inline CXStr operator+(CXStr&& lhs, const char* rhs)
{
	return std::move(lhs.append(rhs));
}

[[nodiscard]] inline CXStr operator+(CXStr&& lhs, char rhs)
{
	lhs.push_back(rhs);
	return std::move(lhs);
}

[[nodiscard]] inline CXStr operator+(const CXStr& lhs, CXStr&& rhs)
{
	return std::move(rhs.insert(0, lhs));
}

[[nodiscard]] inline CXStr operator+(const char* lhs, CXStr&& rhs)
{
	return std::move(rhs.insert(0, lhs));
}

[[nodiscard]] inline CXStr operator+(char lhs, CXStr&& rhs)
{
	return std::move(rhs.insert(static_cast<size_t>(0), static_cast<size_t>(1), lhs));
}

} // namespace eqlib
