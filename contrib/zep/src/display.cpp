#include "pch.h"
#include "zep/display.h"
#include "zep/scroller.h"

#define UTF_CPP_CPLUSPLUS 201103L // C++ 11 or later
#include "zep/mcommon/utf8/unchecked.h"

// A 'window' is like a vim window; i.e. a region inside a tab
namespace Zep {

void ZepFont::InvalidateCharCache()
{
    m_display.SetLayoutDirty();
    m_charCacheDirty = true;
}

void ZepFont::BuildCharCache()
{
    const char chA = 'A';
    m_defaultCharSize = GetTextSize((const uint8_t*)&chA, (const uint8_t*)&chA + 1);
    for (int i = 0; i < 256; i++)
    {
        uint8_t ch = (uint8_t)i;
        m_charCacheASCII[i] = GetTextSize(&ch, &ch + 1);
    }
    m_charCacheDirty = false;

    m_dotSize = m_defaultCharSize / 8.0f;
    m_dotSize.x = std::min(m_dotSize.x, m_dotSize.y);
    m_dotSize.y = std::min(m_dotSize.x, m_dotSize.y);
    m_dotSize.x = std::max(1.0f, m_dotSize.x);
    m_dotSize.y = std::max(1.0f, m_dotSize.y);
}

const NVec2f& ZepFont::GetDefaultCharSize()
{
    if (m_charCacheDirty)
    {
        BuildCharCache();
    }

    return m_defaultCharSize;
}

const NVec2f& ZepFont::GetDotSize()
{
    return m_dotSize;
}

NVec2f ZepFont::GetCharSize(const uint8_t* pCh)
{
    if (m_charCacheDirty)
    {
        BuildCharCache();
    }

    if (utf8_codepoint_length(*pCh) == 1)
    {
        return m_charCacheASCII[*pCh];
    }

    auto ch32 = utf8::unchecked::next(pCh);

    auto itr = m_charCache.find((uint32_t)ch32);
    if (itr != m_charCache.end())
    {
        return itr->second;
    }

    auto sz = GetTextSize(pCh, pCh + utf8_codepoint_length(*pCh));
    m_charCache[(uint32_t)ch32] = sz;

    return sz;
}

ZepDisplay::ZepDisplay(const NVec2f& pixelScale)
    : m_pixelScale(pixelScale)
{
    for (size_t i = 0; i < m_fonts.size(); i++)
    {
        m_fonts[i] = nullptr;
    }
}

uint32_t ZepDisplay::GetCodePointCount(const uint8_t* pCh, const uint8_t* pEnd) const
{
    uint32_t count = 0;
    while (pCh < pEnd)
    {
        pCh += utf8_codepoint_length(*pCh);
        count++;
    }
    return count;
}

void ZepDisplay::DrawRect(const NRectf& rc, ZepColor col) const
{
    DrawLine(rc.topLeftPx, rc.BottomLeft(), col);
    DrawLine(rc.topLeftPx, rc.TopRight(), col);
    DrawLine(rc.TopRight(), rc.bottomRightPx, col);
    DrawLine(rc.BottomLeft(), rc.bottomRightPx, col);
}

bool ZepDisplay::LayoutDirty() const
{
    return m_bRebuildLayout;
}

void ZepDisplay::SetLayoutDirty(bool dirty)
{
    m_bRebuildLayout = dirty;
}

void ZepDisplay::SetFont(ZepTextType type, std::shared_ptr<ZepFont> spFont)
{
    m_fonts[static_cast<int>(type)] = spFont;
}

const NVec2f& ZepDisplay::GetPixelScale() const
{
    return m_pixelScale;
}

void ZepDisplay::DrawScroller(const Scroller& scroller, ZepTheme& theme)
{
    const auto& region = scroller.GetRegion();
    const auto& topButton = scroller.GetTopButtonRegion();
    const auto& bottomButton = scroller.GetBottomButtonRegion();

    SetClipRect(region->rect);

    auto mousePos = scroller.GetEditor().GetMousePos();
    auto activeColor = theme.GetColor(ThemeColor::WidgetActive);
    auto inactiveColor = theme.GetColor(ThemeColor::WidgetInactive);

    bool canHover = scroller.GetEditor().IsMouseCaptured(&scroller);

    // Scroller background
    DrawRectFilled(region->rect, theme.GetColor(ThemeColor::WidgetBackground));

    auto scrollState = scroller.GetState();
    bool onTop = false;
    bool onBottom = false;

    if (canHover)
    {
        onTop = topButton->rect.Contains(mousePos) && scrollState != Scroller::ScrollState::Drag;
        onBottom = bottomButton->rect.Contains(mousePos) && scrollState != Scroller::ScrollState::Drag;
    }

    if (scrollState == Scroller::ScrollState::ScrollUp)
    {
        onTop = true;
    }
    if (scrollState == Scroller::ScrollState::ScrollDown)
    {
        onBottom = true;
    }

    DrawRectFilled(topButton->rect, onTop ? activeColor : inactiveColor);
    DrawRectFilled(bottomButton->rect, onBottom ? activeColor : inactiveColor);

    auto thumbRect = scroller.ThumbRect();

    // Thumb
    bool onThumb = false;
    if (canHover)
    {
        onThumb = thumbRect.Contains(mousePos);
    }

    DrawRectFilled(thumbRect, onThumb || scrollState == Scroller::ScrollState::Drag ? activeColor : inactiveColor);
}

void ZepDisplay::Bigger()
{
    for (int i = 0; i < (int)m_fonts.size(); i++)
    {
        if (m_fonts[i] != nullptr)
        {
            switch ((ZepTextType)i)
            {
            case ZepTextType::Text:
            {
                auto& textFont = GetFont(ZepTextType(i));
                textFont.SetPixelHeight((int)std::min((float)ceil(textFont.GetPixelHeight() * 1.05), 800.0f));
            }
            default:
            break;
            }
        }
    }
}

void ZepDisplay::Smaller()
{
    for (int i = 0; i < (int)m_fonts.size(); i++)
    {
        if (m_fonts[i] != nullptr)
        {
            switch ((ZepTextType)i)
            {
            case ZepTextType::Text:
            {
                auto& textFont = GetFont(ZepTextType(i));
                textFont.SetPixelHeight((int)std::max(4.0f, (float)floor(textFont.GetPixelHeight() *.95f)));
            }
            default:
            break;
            }
        }
    }
}

void ZepDisplay::ResetFontScale()
{
    for (int i = 0; i < (int)m_fonts.size(); i++)
    {
        if (m_fonts[i] != nullptr)
        {
            switch ((ZepTextType)i)
            {
            case ZepTextType::Text:
            {
                auto& textFont = GetFont(ZepTextType(i));
                textFont.ResetPixelHeight();
            }
            default:
            break;
            }
        }
    }
}


} // namespace Zep
