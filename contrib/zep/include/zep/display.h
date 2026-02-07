#pragma once

#include <array>
#include "buffer.h"

namespace Zep
{

class Scroller;
class ZepTabWindow;

// A region inside the text for selections
struct SelectRegion
{
    // For vertical select, we will have a list of spans...
    GlyphIterator start;
    GlyphIterator end;
    bool visible = true;
    bool vertical = false; // Not yet supported
};

using ZepFontHandle = uint32_t;

enum class ZepTextType
{
    UI,
    Text,
    Count
};

class ZepFont
{
public:
    ZepFont(ZepDisplay& display, int pixelHeight)
        : m_display(display)
        , m_pixelHeight(pixelHeight)
        , m_origPixelHeight(pixelHeight)
    {
    }

    virtual ~ZepFont() {}

    // Implemented in API specific ways
    virtual void SetPixelHeight(int pixelHeight)
    {
        InvalidateCharCache();
        m_pixelHeight = pixelHeight;
    }

    virtual NVec2f GetTextSize(const uint8_t* pBegin, const uint8_t* pEnd = nullptr) const = 0;

    virtual int GetPixelHeight() const
    {
        return m_pixelHeight;
    }

    virtual void ResetPixelHeight()
    {
        SetPixelHeight(m_origPixelHeight);
    }

    virtual const NVec2f& GetDefaultCharSize();
    virtual const NVec2f& GetDotSize();
    virtual void BuildCharCache();
    virtual void InvalidateCharCache();
    virtual NVec2f GetCharSize(const uint8_t* pChar);

protected:
    int m_pixelHeight;
    const int m_origPixelHeight;
    std::string m_filePath;
    bool m_charCacheDirty = true;
    std::unordered_map<uint32_t, NVec2f> m_charCache;
    NVec2f m_charCacheASCII[256];
    NVec2f m_dotSize;
    NVec2f m_defaultCharSize;
    ZepDisplay& m_display;
};

// Display interface
class ZepDisplay
{
public:
    virtual ~ZepDisplay(){};
    ZepDisplay(const NVec2f& pixelScale);

    // Renderer specific overrides
    // Implement these to draw the buffer using whichever system you prefer
    virtual void DrawLine(const NVec2f& start, const NVec2f& end, ZepColor color = ZepColor(255u), float width = 1.0f) const = 0;
    virtual void DrawChars(ZepFont& font, const NVec2f& pos, ZepColor col, const uint8_t* text_begin, const uint8_t* text_end = nullptr) const = 0;
    virtual void DrawRectFilled(const NRectf& rc, ZepColor col = ZepColor(255u)) const = 0;
    virtual void SetClipRect(const NRectf& rc) = 0;

    virtual uint32_t GetCodePointCount(const uint8_t* pCh, const uint8_t* pEnd) const;
    virtual void DrawRect(const NRectf& rc, ZepColor color = ZepColor(255u)) const;
    virtual bool LayoutDirty() const;
    virtual void SetLayoutDirty(bool changed = true);

    virtual void SetFont(ZepTextType type, std::shared_ptr<ZepFont> spFont);
    virtual ZepFont& GetFont(ZepTextType type) = 0;
    //virtual void SetFontSize(ZepTextType type, int fontSize);
    //virtual int GetFontSize(ZepTextType type);
    const NVec2f& GetPixelScale() const;

    virtual void DrawScroller(const Scroller& scroller, ZepTheme& theme);

    void Bigger();
    void Smaller();
    void ResetFontScale();

protected:
    bool m_bRebuildLayout = false;
    std::array<std::shared_ptr<ZepFont>, (int)ZepTextType::Count> m_fonts;
    std::shared_ptr<ZepFont> m_spDefaultFont;
    NVec2f m_pixelScale;
};

class ZepFontNull : public ZepFont
{
public:
    ZepFontNull(ZepDisplay& display)
        : ZepFont(display, 0)
    {
    }

    virtual void SetPixelHeight(int val) override
    {
        ZEP_UNUSED(val);
    }

    virtual NVec2f GetTextSize(const uint8_t* pBegin, const uint8_t* pEnd = nullptr) const override
    {
        return NVec2f(float(pEnd - pBegin), 10.0f);
    }
};

// A NULL renderer, used for testing
// Discards all drawing, and returns text fixed_size of 1 pixel per char, 10 height!
// This is the only work you need to do to make a new renderer type for the editor
class ZepDisplayNull : public ZepDisplay
{
public:
    ZepDisplayNull(const NVec2f& pixelScale)
        : ZepDisplay(pixelScale)
    {
    }

    virtual void DrawLine(const NVec2f& start, const NVec2f& end, ZepColor color = ZepColor(255u), float width = 1.0f) const override
    {
        (void)start;
        (void)end;
        (void)color;
        (void)width;
    };

    virtual void DrawChars(ZepFont&, const NVec2f& pos, Zep::ZepColor col, const uint8_t* text_begin, const uint8_t* text_end = nullptr) const override
    {
        (void)pos;
        (void)col;
        (void)text_begin;
        (void)text_end;
    }

    virtual void DrawRectFilled(const NRectf& a, Zep::ZepColor col = ZepColor(255u)) const override
    {
        (void)a;
        (void)col;
    };

    virtual void SetClipRect(const NRectf& rc) override
    {
        (void)rc;
    }

    virtual ZepFont& GetFont(ZepTextType type) override
    {
        if (m_fonts[(int)type] == nullptr)
        {
            if (m_spDefaultFont == nullptr)
            {
                m_spDefaultFont = std::make_shared<ZepFontNull>(*this);
            }
            return *m_spDefaultFont;
        }
        return *m_fonts[(int)type];
    }

};

} // namespace Zep
