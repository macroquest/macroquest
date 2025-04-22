#pragma once

#include <algorithm>
#include <cmath>
#include <ostream>

// 2D and 4D vectors, used for area and color calculations.
// Some helpers for color conversion too.
// This just saves using a library like glm (my personal preference)
// - and it keeps the dependencies of Zep to just the source folder contents

namespace Zep {

namespace detail
{
    struct InvalidHexChar {};

    constexpr int hexToDec(const char c)
    {
        return (c >= '0' && c <= '9') ? c - '0' : ((c >= 'a' && c <= 'f') ? c - 'a' + 10 : (c >= 'A' && c <= 'F') ? c - 'A' + 10
                                                                                                                  : throw InvalidHexChar{});
    }
}

struct ZepColor
{
    // default is opaque black
    constexpr ZepColor()
        : r(0)
        , g(0)
        , b(0)
        , a(255)
    {
    }

    constexpr ZepColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
        : b(blue)
        , g(green)
        , r(red)
        , a(alpha)
    {
    }

    constexpr explicit ZepColor(uint8_t all)
        : b(all)
        , g(all)
        , r(all)
        , a(all)
    {
    }

    template <typename T, typename = typename std::enable_if_t<std::is_floating_point_v<T>>>
    constexpr ZepColor(T red, T green, T blue, T alpha = 1.f)
        : r(static_cast<uint8_t>(red * 255.f))
        , g(static_cast<uint8_t>(green * 255.f))
        , b(static_cast<uint8_t>(blue * 255.f))
        , a(static_cast<uint8_t>(alpha * 255.f))
    {
    }

    template <typename T, typename = typename std::enable_if_t<std::is_floating_point_v<T>>>
    constexpr ZepColor(T all)
        : r(static_cast<uint8_t>(all * 255.f))
        , g(static_cast<uint8_t>(all * 255.f))
        , b(static_cast<uint8_t>(all * 255.f))
        , a(static_cast<uint8_t>(all * 255.f))
    {
    }

    constexpr ZepColor(const ZepColor& other)
        : r(other.r)
        , g(other.g)
        , b(other.b)
        , a(other.a)
    {
    }

    constexpr ZepColor(const char* str)
        : r(static_cast<uint8_t>(detail::hexToDec(str[1]) << 4 | detail::hexToDec(str[2])) & 0xff)
        , g(static_cast<uint8_t>(detail::hexToDec(str[3]) << 4 | detail::hexToDec(str[4])) & 0xff)
        , b(static_cast<uint8_t>(detail::hexToDec(str[5]) << 4 | detail::hexToDec(str[6])) & 0xff)
        , a(255)
    {
        if (str[0] != '#') throw detail::InvalidHexChar();
    }

    constexpr ZepColor& operator=(uint32_t color)
    {
        ABGR = color;
        return *this;
    }

    constexpr ZepColor& operator=(const ZepColor& other)
    {
        ABGR = other.ABGR;
        return *this;
    }

    constexpr ZepColor(uint32_t color)
        : ABGR(color)
    {
    }

    constexpr operator uint32_t() const
    {
        return ABGR;
    }

    constexpr ZepColor operator+(ZepColor other) const
    {
        return ZepColor(
            static_cast<uint8_t>(r + other.r),
            static_cast<uint8_t>(g + other.g),
            static_cast<uint8_t>(b + other.b),
            static_cast<uint8_t>(a + other.a));
    }

    constexpr ZepColor& operator+=(ZepColor other)
    {
        r += other.r;
        g += other.g;
        b += other.b;
        a += other.a;
        return *this;
    }

    constexpr ZepColor operator-(ZepColor other) const
    {
        return ZepColor(
            static_cast<uint8_t>(r - other.r),
            static_cast<uint8_t>(g - other.g),
            static_cast<uint8_t>(b - other.b),
            static_cast<uint8_t>(a - other.a));
    }

    constexpr ZepColor& operator-=(ZepColor other)
    {
        r -= other.r;
        g -= other.g;
        b -= other.b;
        a -= other.a;
        return *this;
    }

    constexpr uint32_t ToPackedRGBA() const
    {
        uint32_t col = 0;
        col |= uint32_t(a) << 24;
        col |= uint32_t(g) << 16;
        col |= uint32_t(g) << 8;
        col |= uint32_t(r);
        return col;
    }

    constexpr uint32_t ToPackedBGRA(uint32_t val) const
    {
        uint32_t col = 0;
        col |= uint32_t(a) << 8;
        col |= uint32_t(r) << 16;
        col |= uint32_t(g) << 24;
        col |= uint32_t(b);
        return col;
    }

    constexpr uint32_t ToPackedARGB() const
    {
        uint32_t col = 0;
        col |= uint32_t(a) << 24;
        col |= uint32_t(r) << 16;
        col |= uint32_t(g) << 8;
        col |= uint32_t(b);
        return col;
    }

    constexpr uint32_t ToPackedABGR() const
    {
        return ABGR;
    }

    template <typename T>
    constexpr ZepColor operator*(T val) const
    {
        return ZepColor(
            static_cast<uint8_t>(r * val),
            static_cast<uint8_t>(g * val),
            static_cast<uint8_t>(b * val),
            static_cast<uint8_t>(a * val));
    }

    template <typename T>
    constexpr ZepColor& operator*=(T val)
    {
        r = static_cast<uint8_t>(r * val);
        g = static_cast<uint8_t>(g * val);
        b = static_cast<uint8_t>(b * val);
        a = static_cast<uint8_t>(a * val);
        return *this;
    }

    union
    {
        struct
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        };

        uint32_t ABGR = 0;
    };
};

inline bool operator==(const ZepColor& left, const ZepColor& right)
{
    return left.ABGR == right.ABGR;
}

inline bool operator!=(const ZepColor& left, const ZepColor& right)
{
    return left.ABGR != right.ABGR;
}

inline ZepColor Clamp(ZepColor val, ZepColor min, ZepColor max)
{
    return ZepColor(std::min(max.r, std::max(min.r, val.r)),
        std::min(max.g, std::max(min.g, val.g)),
        std::min(max.b, std::max(min.b, val.b)),
        std::min(max.a, std::max(min.a, val.a)));
}

inline float Luminosity(ZepColor intensity)
{
    return (0.2126f * intensity.r + 0.7152f * intensity.g + 0.0722f * intensity.b);
}

inline ZepColor Mix(ZepColor c1, ZepColor c2, float factor)
{
    ZepColor ret = c1 * (1.0f - factor);
    ret = ret + (c2 * factor);
    return ret;
}

inline uint32_t HSVToRGB(float h, float s, float v)
{
    auto r = 0.0f, g = 0.0f, b = 0.0f;

    if (s == 0)
    {
        r = v;
        g = v;
        b = v;
    }
    else
    {
        int i;
        float f, p, q, t;

        if (h == 360)
            h = 0;
        else
            h = h / 60.0f;

        i = (int)trunc(h);
        f = h - i;

        p = v * (1.0f - s);
        q = v * (1.0f - (s * f));
        t = v * (1.0f - (s * (1.0f - f)));

        switch (i)
        {
        case 0:
            r = v;
            g = t;
            b = p;
            break;

        case 1:
            r = q;
            g = v;
            b = p;
            break;

        case 2:
            r = p;
            g = v;
            b = t;
            break;

        case 3:
            r = p;
            g = q;
            b = v;
            break;

        case 4:
            r = t;
            g = p;
            b = v;
            break;

        default:
            r = v;
            g = p;
            b = q;
            break;
        }
    }

    return ZepColor(r, g, b);
}

template <class T>
inline std::ostream& operator<<(std::ostream& str, ZepColor color)
{
    str << "(" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")";
    return str;
}

} // namespace Zep
