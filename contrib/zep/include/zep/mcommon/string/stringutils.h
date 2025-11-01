#pragma once

#include <functional>
#include <ostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace Zep
{

inline size_t CountUtf8BytesFromChar(unsigned int c)
{
    if (c < 0x80)
        return 1;
    if (c < 0x800)
        return 2;
    if (c >= 0xdc00 && c < 0xe000)
        return 0;
    if (c >= 0xd800 && c < 0xdc00)
        return 4;
    return 3;
}

inline size_t Utf8Length(const char* s)
{
    size_t stringLength = 0;
    while (*s != 0)
    {
        size_t len = 1;
        while (len <= 4 && *s)
        {
            if ((*s++ & 0xc0) != 0x80)
                break;
            len++;
        }
        stringLength += len;
    }
    return stringLength;
}

std::string string_replace(std::string subject, const std::string& search, const std::string& replace);
void string_replace_in_place(std::string& subject, const std::string& search, const std::string& replace);

// trim from beginning of string (left)
inline std::string& LTrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from end of string (right)
inline std::string& RTrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from both ends of string (left & right)
inline std::string& Trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return LTrim(RTrim(s, t), t);
}

template <typename T>
std::string toString(const T& t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

template <typename T>
T fromString(const std::string& s)
{
    std::istringstream stream(s);
    T t;
    stream >> t;
    return t;
}

inline std::wstring makeWStr(const std::string& str)
{
    return std::wstring(str.begin(), str.end());
}

std::string string_from_wstring(const std::wstring& str);
std::string string_tolower(const std::string& str);

namespace detail
{
template <size_t R, class T>
static inline constexpr T rotl(const T v)
{
    static_assert(std::is_unsigned<T>::value, "Can only rotate unsigned integral types");

    return (v << (R % std::numeric_limits<T>::digits)) | (v >> (std::numeric_limits<T>::digits - (R % std::numeric_limits<T>::digits)));
}

template <class T>
struct LittleEndianIndexer
{
    static inline constexpr size_t index_of(size_t v)
    {
        return v;
    }
};

template <class T>
struct BigEndianIndexer
{
    static inline constexpr size_t index_of(size_t v)
    {
        return (sizeof(T) - v - 1);
    }
};

template <class T, template <typename> class Indexer = LittleEndianIndexer>
struct IntegralByteView
{
    static_assert(std::is_integral<T>::value, "IntegralByteView supports only integral types");

    inline constexpr IntegralByteView(const T* const p, size_t n)
        : _p(p)
        , _n(p ? n * sizeof(T) : 0)
    {
    }

    inline constexpr size_t size() const
    {
        return _n;
    }

    inline constexpr uint8_t byte_at(size_t n) const
    {
        return n < _n ? uint8_t(_p[n / sizeof(T)] >> (Indexer<T>::index_of(n % sizeof(T)) * std::numeric_limits<uint8_t>::digits)) : throw int();
    }

private:
    const T* const _p;
    size_t _n;
};

template <class T>
struct MurmurHash3;

template <>
struct MurmurHash3<uint32_t>
{
    using value_type = uint32_t;

    template <class T, template <typename> class Indexer>
    inline constexpr MurmurHash3(const IntegralByteView<T, Indexer>& s, value_type seed)
        : _value(fmix3(fmix2(fmix1(tail(body(seed, s, 0), s)))))
    {
    }

    inline constexpr operator value_type() const
    {
        return _value;
    }

private:
    static constexpr const uint32_t C1 = 0xcc9e2d51;
    static constexpr const uint32_t C2 = 0x1b873593;

    static constexpr const size_t BODY_CHUNK_SIZE = 256;

    template <class T, template <typename> class Indexer>
    static inline constexpr value_type get_block(const IntegralByteView<T, Indexer>& s, size_t offset)
    {
        return value_type(s.byte_at(offset)) | (value_type(s.byte_at(offset + 1)) << 8) | (value_type(s.byte_at(offset + 2)) << 16) | (value_type(s.byte_at(offset + 3)) << 24);
    }

    template <class T, template <typename> class Indexer>
    static inline constexpr value_type get_tail(const IntegralByteView<T, Indexer>& s, size_t offset)
    {
        return offset >= s.size() ? 0 : value_type(s.byte_at(offset)) | (s.size() - offset > 1 ? (value_type(s.byte_at(offset + 1)) << 8) : 0) | (s.size() - offset > 2 ? (value_type(s.byte_at(offset + 2)) << 16) : 0);
    }

    static inline constexpr value_type process_block(value_type k1, value_type h)
    {
        return 0xe6546b64 + (5 * rotl<13>(h ^ (rotl<15>(k1 * C1) * C2)));
    }

    static inline constexpr value_type fmix1(value_type h)
    {
        return (h ^ h >> 16) * 0x85ebca6b;
    }

    static inline constexpr value_type fmix2(value_type h)
    {
        return (h ^ (h >> 13)) * 0xc2b2ae35;
    }

    static inline constexpr value_type fmix3(value_type h)
    {
        return h ^ (h >> 16);
    }

    template <class T, template <typename> class Indexer>
    static inline constexpr value_type body_chunk(value_type h, const IntegralByteView<T, Indexer>& s, size_t offset, size_t left)
    {
        return left < 4 ? h : body_chunk(process_block(get_block(s, offset), h), s, offset + 4, left - 4);
    }

    template <class T, template <typename> class Indexer>
    static inline constexpr value_type body(value_type h, const IntegralByteView<T, Indexer>& s, size_t offset)
    {
        return (offset > s.size() || s.size() - offset < 4) ? h : body(body_chunk(h, s, offset, s.size() - offset >= BODY_CHUNK_SIZE ? BODY_CHUNK_SIZE : s.size() - offset), s, offset + BODY_CHUNK_SIZE);
    }

    template <class T, template <typename> class Indexer>
    static inline constexpr value_type tail(value_type h, const IntegralByteView<T, Indexer>& s)
    {
        return static_cast<value_type>(s.size() ^ h ^ (rotl<15>(get_tail(s, s.size() - (s.size() & 3)) * C1) * C2));
    }

    value_type _value;
};
} // namespace detail

template <class T, class U>
inline constexpr T murmur_hash3(const U* s, size_t n, const T seed = 0)
{
    return detail::MurmurHash3<T>(detail::IntegralByteView<U>(s, n), seed);
}

namespace detail
{
inline constexpr const char* _strnul_chunk(const char* s, size_t l)
{
    return (!l || !s || !*s) ? s : _strnul_chunk(s + 1, l - 1);
}
inline constexpr const char* strnul(const char* s)
{
    return (!s || !*s) ? s : strnul(_strnul_chunk(s + 1, 250));
}
inline constexpr size_t strlen(const char* s)
{
    return strnul(s) - s;
}
} // namespace detail

template <class T>
inline constexpr T murmur_hash3(const char* s, const T seed = 0)
{
    return detail::MurmurHash3<T>(detail::IntegralByteView<char>(s, detail::strlen(s)), seed);
}

struct StringId
{
    uint32_t id = 0;

    constexpr StringId() = default;

    constexpr StringId(const char* pszString)
        : id(murmur_hash3<uint32_t>(pszString))
    {
    }

    StringId(const std::string& str)
        : id(murmur_hash3<uint32_t>(str.c_str()))
    {
    }

    constexpr explicit StringId(uint32_t id_)
        : id(id_)
    {
    }

    constexpr bool operator==(const StringId& rhs) const
    {
        return id == rhs.id;
    }

    template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
    constexpr bool operator==(T rhs) const
    {
        return id == static_cast<uint32_t>(rhs);
    }

    constexpr StringId& operator=(const char* pszString)
    {
        id = murmur_hash3<uint32_t>(pszString);
        return *this;
    }

    StringId& operator=(const std::string& str)
    {
        id = murmur_hash3<uint32_t>(str.c_str());
        return *this;
    }

    constexpr bool operator<(const StringId& rhs) const
    {
        return id < rhs.id;
    }

    constexpr operator uint32_t() const
    {
        return id;
    }
};

void string_split(const std::string& text, const char* delims, std::vector<std::string>& tokens);
std::vector<std::string> string_split(const std::string& text, const char* delims);
void string_split_lines(const std::string& text, std::vector<std::string>& tokens);
void string_split_each(const std::string& text, const char* delims, std::function<bool(size_t, size_t)> fn);
void string_split_each(char* text, size_t start, size_t end, const char* delims, std::function<bool(size_t, size_t)> fn);
size_t string_first_of(const char* text, size_t start, size_t end, const char* delims);
size_t string_first_not_of(const char* text, size_t start, size_t end, const char* delims);

inline bool string_equals(const std::string& str, const std::string& str2)
{
    return str == str2;
}

inline void string_eat_char(std::string::const_iterator& itr, std::string::const_iterator& itrEnd)
{
    if (itr != itrEnd)
        itr++;
}

std::string string_slurp_if(std::string::const_iterator& itr, std::string::const_iterator itrEnd, char first, char last);
std::string string_slurp_if(std::string::const_iterator& itr, std::string::const_iterator itrEnd, std::function<bool(char)> fnIs);

inline bool utf8_is_trailing(uint8_t ch)
{
    return (ch >> 6) == 0x2;
}

inline long utf8_codepoint_length(uint8_t ch)
{
    return ((0xE5000000 >> ((ch >> 3) & 0x1e)) & 3) + 1;
}

} // namespace Zep

namespace std
{
template <>
struct hash<Zep::StringId>
{
    std::size_t operator()(const Zep::StringId& k) const
    {
        // Compute individual hash values for first,
        // second and third and combine them using XOR
        // and bit shifting:

        return std::hash<uint32_t>()(k.id);
    }
};
} // namespace std

namespace Zep
{
inline bool string_equals(const StringId lhs, const StringId rhs)
{
    return lhs.id == rhs.id;
}
} // namespace Zep
