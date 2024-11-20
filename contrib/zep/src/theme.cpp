#include "pch.h"
#include "zep/editor.h"
#include "zep/syntax.h"
#include "zep/theme.h"

#include <array>

namespace Zep {

ZepTheme::ZepTheme()
{
    double golden_ratio_conjugate = 0.618033988749895;
    double h = .85f;
    for (int i = 0; i < (int)ThemeColor::UniqueColorLast; i++)
    {
        h += golden_ratio_conjugate;
        h = std::fmod(h, 1.0);
        m_uniqueColors.emplace_back(HSVToRGB(float(h) * 360.0f, 0.6f, 200.0f));
    }
    SetThemeType(ThemeType::Dark);
}

void ZepTheme::SetThemeType(ThemeType type)
{
    m_currentTheme = type;
    switch (type)
    {
    case ThemeType::Dark:
        SetDarkTheme();
        break;
    case ThemeType::Light:
        SetLightTheme();
        break;
    case ThemeType::VSCodeDefault:
        SetVSCodeDefaultTheme();
        break;
    case ThemeType::SolarizedLight:
        SetSolarizedLightTheme();
        break;
    case ThemeType::SolarizedDark:
        SetSolarizedDarkTheme();
        break;
    default:
        SetDarkTheme();
        break;
    }
}

const std::vector<ThemeName>& GetThemeNames()
{
    static std::vector<ThemeName> s_themes {
        { ThemeType::Dark, "Dark" },
        { ThemeType::Light, "Light" },
        { ThemeType::SolarizedDark, "Solarized Dark" },
        { ThemeType::SolarizedLight, "Solarized Light" },
        { ThemeType::VSCodeDefault, "VSCode Default" },
    };

    return s_themes;
}

ThemeType ZepTheme::GetThemeType() const
{
    return m_currentTheme;
}

void ZepTheme::SetDarkTheme()
{
    m_colors[ThemeColor::AirlineBackground] = ZepColor(.20f, .20f, .20f, 1.0f);
    m_colors[ThemeColor::Background] = ZepColor(0.11f, 0.11f, 0.11f, 1.0f);
    m_colors[ThemeColor::Comment] = ZepColor(0.0f, 1.0f, .1f, 1.0f);
    m_colors[ThemeColor::CursorInsert] = ZepColor(1.0f, 1.0f, 1.0f, .9f);
    m_colors[ThemeColor::CursorLineBackground] = ZepColor(.25f, .25f, .25f, 1.0f);
    m_colors[ThemeColor::CursorNormal] = ZepColor(130.0f / 255.0f, 140.0f / 255.0f, 230.0f / 255.0f, 1.0f);
    m_colors[ThemeColor::Dark] = ZepColor(0.0f, 0.0f, 0.0f, 1.0f);
    m_colors[ThemeColor::Error] = ZepColor(0.65f, .2f, .15f, 1.0f);
    m_colors[ThemeColor::FlashColor] = ZepColor(.80f, .40f, .05f, 1.0f);
    m_colors[ThemeColor::HiddenText] = ZepColor(.9f, .1f, .1f, 1.0f);
    m_colors[ThemeColor::Identifier] = ZepColor(1.0f, .75f, 0.5f, 1.0f);
    m_colors[ThemeColor::Info] = ZepColor(0.15f, .6f, .15f, 1.0f);
    m_colors[ThemeColor::Keyword] = ZepColor(0.1f, 1.0f, 1.0f, 1.0f);
    m_colors[ThemeColor::Light] = ZepColor(1.0f);
    m_colors[ThemeColor::LineNumberActive] = ZepColor(.13f, 1.0f, .13f, 1.0f);
    m_colors[ThemeColor::LineNumber] = ZepColor(.13f, 1.0f, .13f, 1.0f);
    m_colors[ThemeColor::Mode] = ZepColor(.2f, 0.8f, 0.2f, 1.0f);
    m_colors[ThemeColor::Number] = ZepColor(1.0f, 1.0f, 0.1f, 1.0f);
    m_colors[ThemeColor::String] = ZepColor(1.0f, 0.5f, 1.0f, 1.0f);
    m_colors[ThemeColor::TabActive] = ZepColor(.65f, .65f, .65f, 1.0f);
    m_colors[ThemeColor::TabBorder] = ZepColor(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::TabInactive] = ZepColor(.4f, .4f, .4f, .55f);
    m_colors[ThemeColor::TextDim] = ZepColor(.45f, .45f, .45f, 1.0f);
    m_colors[ThemeColor::Text] = ZepColor(1.0f);
    m_colors[ThemeColor::VisualSelectBackground] = ZepColor(.47f, 0.30f, 0.25f, 1.0f);
    m_colors[ThemeColor::Warning] = ZepColor(0.15f, .2f, .65f, 1.0f);
    m_colors[ThemeColor::Whitespace] = ZepColor(0.3f, .3f, .3f, 1.0f);
    m_colors[ThemeColor::WidgetBackground] = ZepColor(.2f, .2f, .2f, 1.0f);
    m_colors[ThemeColor::WidgetBorder] = ZepColor(.5f, .5f, .5f, 1.0f);

    m_colors[ThemeColor::LineNumberBackground] = m_colors[ThemeColor::Background] + ZepColor(.02f, .02f, .02f, 0.0f);
    m_colors[ThemeColor::Normal] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::Parenthesis] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::WidgetActive] = m_colors[ThemeColor::TabActive];
    m_colors[ThemeColor::WidgetInactive] = m_colors[ThemeColor::TabInactive];
}

void ZepTheme::SetLightTheme()
{
    m_colors[ThemeColor::AirlineBackground] = ZepColor(.80f, .80f, .80f, 1.0f);
    m_colors[ThemeColor::Background] = ZepColor(1.0f, 1.0f, 1.0f, 1.0f);
    m_colors[ThemeColor::Comment] = ZepColor(0.1f, .4f, .1f, 1.0f);
    m_colors[ThemeColor::CursorInsert] = ZepColor(1.0f, 1.0f, 1.0f, .9f);
    m_colors[ThemeColor::CursorLineBackground] = ZepColor(.85f, .85f, .85f, 1.0f);
    m_colors[ThemeColor::CursorNormal] = ZepColor(130.0f / 255.0f, 140.0f / 255.0f, 230.0f / 255.0f, 1.0f);
    m_colors[ThemeColor::Dark] = ZepColor(0.0f, 0.0f, 0.0f, 1.0f);
    m_colors[ThemeColor::Error] = ZepColor(0.89f, .2f, .15f, 1.0f);
    m_colors[ThemeColor::FlashColor] = ZepColor(0.8f, .4f, .05f, 1.0f);
    m_colors[ThemeColor::HiddenText] = ZepColor(.9f, .1f, .1f, 1.0f);
    m_colors[ThemeColor::Identifier] = ZepColor(0.2f, .2f, .1f, 1.0f);
    m_colors[ThemeColor::Info] = ZepColor(0.15f, .85f, .15f, 1.0f);
    m_colors[ThemeColor::Keyword] = ZepColor(0.1f, .2f, .3f, 1.0f);
    m_colors[ThemeColor::Light] = ZepColor(1.0f);
    m_colors[ThemeColor::LineNumberActive] = ZepColor(.13f, 0.6f, .13f, 1.0f);
    m_colors[ThemeColor::LineNumber] = ZepColor(.13f, .4f, .13f, 1.0f);
    m_colors[ThemeColor::Mode] = ZepColor(.2f, 0.8f, 0.2f, 1.0f);
    m_colors[ThemeColor::Number] = ZepColor(0.1f, .3f, .2f, 1.0f);
    m_colors[ThemeColor::String] = ZepColor(0.1f, .1f, .4f, 1.0f);
    m_colors[ThemeColor::TabActive] = ZepColor(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::TabBorder] = ZepColor(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::TabInactive] = ZepColor(.4f, .4f, .4f, .55f);
    m_colors[ThemeColor::TextDim] = ZepColor(0.55f, 0.55f, 0.55f, 1.0f);
    m_colors[ThemeColor::Text] = ZepColor(0.0f, 0.0f, 0.0f, 1.0f);
    m_colors[ThemeColor::VisualSelectBackground] = ZepColor(.49f, 0.60f, 0.45f, 1.0f);
    m_colors[ThemeColor::Warning] = ZepColor(0.15f, .2f, .89f, 1.0f);
    m_colors[ThemeColor::Whitespace] = ZepColor(0.2f, .2f, .2f, 1.0f);
    m_colors[ThemeColor::WidgetBackground] = ZepColor(.8f, .8f, .8f, 1.0f);
    m_colors[ThemeColor::WidgetBorder] = ZepColor(.5f, .5f, .5f, 1.0f);

    m_colors[ThemeColor::LineNumberBackground] = m_colors[ThemeColor::Background] - ZepColor(.02f, .02f, .02f, 0.0f);
    m_colors[ThemeColor::Normal] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::Parenthesis] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::WidgetActive] = m_colors[ThemeColor::TabActive];
    m_colors[ThemeColor::WidgetInactive] = m_colors[ThemeColor::TabInactive];
}

void ZepTheme::SetVSCodeDefaultTheme()
{
    m_colors[ThemeColor::AirlineBackground] = ZepColor(.20f, .20f, .20f, 1.0f);
    m_colors[ThemeColor::Background] = ZepColor("#1f1f1f");
    m_colors[ThemeColor::Comment] = ZepColor("#6A9955");
    m_colors[ThemeColor::CursorInsert] = ZepColor(1.0f, 1.0f, 1.0f, .9f);
    m_colors[ThemeColor::CursorLineBackground] = ZepColor(.25f, .25f, .25f, 1.0f);
    m_colors[ThemeColor::CursorNormal] = ZepColor(130.0f / 255.0f, 140.0f / 255.0f, 230.0f / 255.0f, 1.0f);
    m_colors[ThemeColor::Dark] = ZepColor(0.0f, 0.0f, 0.0f, 1.0f);
    m_colors[ThemeColor::Error] = ZepColor(0.65f, .2f, .15f, 1.0f);
    m_colors[ThemeColor::FlashColor] = ZepColor(.80f, .40f, .05f, 1.0f);
    m_colors[ThemeColor::HiddenText] = ZepColor(.9f, .1f, .1f, 1.0f);
    m_colors[ThemeColor::Identifier] = ZepColor("#9CDCFE");
    m_colors[ThemeColor::Info] = ZepColor(0.15f, .6f, .15f, 1.0f);
    m_colors[ThemeColor::Keyword] = ZepColor("#569CD6");
    m_colors[ThemeColor::Light] = ZepColor(1.0f);
    m_colors[ThemeColor::LineNumberActive] = ZepColor(.13f, 1.0f, .13f, 1.0f);
    m_colors[ThemeColor::LineNumber] = ZepColor(.13f, 1.0f, .13f, 1.0f);
    m_colors[ThemeColor::Mode] = ZepColor(.2f, 0.8f, 0.2f, 1.0f);
    m_colors[ThemeColor::Number] = ZepColor("#B5CEA8");
    m_colors[ThemeColor::String] = ZepColor("#CE9178");
    m_colors[ThemeColor::TabActive] = ZepColor(.65f, .65f, .65f, 1.0f);
    m_colors[ThemeColor::TabBorder] = ZepColor(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::TabInactive] = ZepColor(.4f, .4f, .4f, .55f);
    m_colors[ThemeColor::TextDim] = ZepColor(.45f, .45f, .45f, 1.0f);
    m_colors[ThemeColor::Text] = ZepColor(1.0f);
    m_colors[ThemeColor::VisualSelectBackground] = ZepColor(.47f, 0.30f, 0.25f, 1.0f);
    m_colors[ThemeColor::Warning] = ZepColor(0.15f, .2f, .65f, 1.0f);
    m_colors[ThemeColor::Whitespace] = ZepColor(0.3f, .3f, .3f, 1.0f);
    m_colors[ThemeColor::WidgetBackground] = ZepColor(.2f, .2f, .2f, 1.0f);
    m_colors[ThemeColor::WidgetBorder] = ZepColor(.5f, .5f, .5f, 1.0f);

    m_colors[ThemeColor::LineNumberBackground] = m_colors[ThemeColor::Background] + ZepColor(.02f, .02f, .02f, 0.0f);
    m_colors[ThemeColor::Normal] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::Parenthesis] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::WidgetActive] = m_colors[ThemeColor::TabActive];
    m_colors[ThemeColor::WidgetInactive] = m_colors[ThemeColor::TabInactive];
}

namespace Solarized
{
    constexpr ZepColor base03 { "#002b36" };
    constexpr ZepColor base02 { "#073642" };
    constexpr ZepColor base01 { "#586e75" };
    constexpr ZepColor base00 { "#657b83" };

    constexpr ZepColor base0  { "#839496" };
    constexpr ZepColor base1  { "#93a1a1" };
    constexpr ZepColor base2  { "#eee8d5" };
    constexpr ZepColor base3  { "#fdf6e3" };

    constexpr ZepColor yellow { "#b58900" };
    constexpr ZepColor orange { "#cb4b16" };
    constexpr ZepColor red    { "#dc322f" };
    constexpr ZepColor magenta{ "#d33682" };
    constexpr ZepColor violet { "#6c71c4" };
    constexpr ZepColor blue   { "#268bd2" };
    constexpr ZepColor cyan   { "#2aa198" };
    constexpr ZepColor green  { "#859900" };
}

void ZepTheme::SetSolarizedDarkTheme()
{
    using namespace Solarized;

    constexpr std::array<ZepColor, 8> base {
        base3, base2, base1, base0, base00, base01, base02, base03
    };

    m_colors[ThemeColor::Text] = base[3];
    m_colors[ThemeColor::TextDim] = base[5];
    m_colors[ThemeColor::Background] = base[7];
    m_colors[ThemeColor::AirlineBackground] = base[7];
    m_colors[ThemeColor::LineNumberBackground] = base[6];
    m_colors[ThemeColor::LineNumber] = base[1];
    m_colors[ThemeColor::LineNumberActive] = blue;
    m_colors[ThemeColor::CursorNormal] = base[3];
    m_colors[ThemeColor::CursorInsert] = base[4];
    m_colors[ThemeColor::CursorLineBackground] = base[6];
    m_colors[ThemeColor::VisualSelectBackground] = base[6];

    m_colors[ThemeColor::Comment] = base[5];
    m_colors[ThemeColor::Whitespace] = base[5];
    m_colors[ThemeColor::Keyword] = yellow;
    m_colors[ThemeColor::Identifier] = blue;
    m_colors[ThemeColor::Number] = cyan;
    m_colors[ThemeColor::String] = cyan;
    m_colors[ThemeColor::Error] = red;
    m_colors[ThemeColor::Warning] = orange;
    m_colors[ThemeColor::Info] = blue;

    m_colors[ThemeColor::HiddenText] = ZepColor(.9f, .1f, .1f, 1.0f);
    m_colors[ThemeColor::TabBorder] = ZepColor(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::TabInactive] = ZepColor(.4f, .4f, .4f, .55f);
    m_colors[ThemeColor::TabActive] = ZepColor(.65f, .65f, .65f, 1.0f);
    m_colors[ThemeColor::Mode] = ZepColor(.2f, 0.8f, 0.2f, 1.0f);
    m_colors[ThemeColor::WidgetBorder] = ZepColor(.5f, .5f, .5f, 1.0f);
    m_colors[ThemeColor::WidgetBackground] = ZepColor(.2f, .2f, .2f, 1.0f);
    m_colors[ThemeColor::FlashColor] = ZepColor(0.8f, .4f, .05f, 1.0f);

    m_colors[ThemeColor::Normal] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::Parenthesis] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::WidgetActive] = m_colors[ThemeColor::TabActive];
    m_colors[ThemeColor::WidgetInactive] = m_colors[ThemeColor::TabInactive];
}

void ZepTheme::SetSolarizedLightTheme()
{
    using namespace Solarized;

    constexpr std::array<ZepColor, 8> base {
        base03, base02, base01, base00, base0, base1, base2, base3
    };

    m_colors[ThemeColor::Text] = base[3];
    m_colors[ThemeColor::TextDim] = base[5];
    m_colors[ThemeColor::Background] = base[7];
    m_colors[ThemeColor::AirlineBackground] = base[7];
    m_colors[ThemeColor::LineNumberBackground] = base[6];
    m_colors[ThemeColor::LineNumber] = base[1];
    m_colors[ThemeColor::LineNumberActive] = blue;
    m_colors[ThemeColor::CursorNormal] = base[3];
    m_colors[ThemeColor::CursorInsert] = base[4];
    m_colors[ThemeColor::CursorLineBackground] = base[6];
    m_colors[ThemeColor::VisualSelectBackground] = base[6];

    m_colors[ThemeColor::Comment] = base[5];
    m_colors[ThemeColor::Whitespace] = base[5];
    m_colors[ThemeColor::Keyword] = yellow;
    m_colors[ThemeColor::Identifier] = blue;
    m_colors[ThemeColor::Number] = cyan;
    m_colors[ThemeColor::String] = cyan;
    m_colors[ThemeColor::Error] = red;
    m_colors[ThemeColor::Warning] = orange;
    m_colors[ThemeColor::Info] = blue;

    m_colors[ThemeColor::HiddenText] = ZepColor(.9f, .1f, .1f, 1.0f);
    m_colors[ThemeColor::TabBorder] = ZepColor(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::TabInactive] = ZepColor(.4f, .4f, .4f, .55f);
    m_colors[ThemeColor::TabActive] = ZepColor(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::Mode] = ZepColor(.2f, 0.8f, 0.2f, 1.0f);
    m_colors[ThemeColor::WidgetBorder] = ZepColor(.5f, .5f, .5f, 1.0f);
    m_colors[ThemeColor::WidgetBackground] = ZepColor(.8f, .8f, .8f, 1.0f);
    m_colors[ThemeColor::FlashColor] = ZepColor(0.8f, .4f, .05f, 1.0f);

    m_colors[ThemeColor::Normal] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::Parenthesis] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::WidgetActive] = m_colors[ThemeColor::TabActive];
    m_colors[ThemeColor::WidgetInactive] = m_colors[ThemeColor::TabInactive];
}


ThemeColor ZepTheme::GetUniqueColor(uint32_t index) const
{
    return ThemeColor((uint32_t)ThemeColor::UniqueColor0 + (uint32_t)(index % (uint32_t)ThemeColor::UniqueColorLast));
}

ZepColor ZepTheme::GetColor(ThemeColor themeColor) const
{
    if (themeColor >= ThemeColor::UniqueColor0)
    {
        // Return the unique color
        return m_uniqueColors[((uint32_t)themeColor - (uint32_t)ThemeColor::UniqueColor0) % (uint32_t)ThemeColor::UniqueColorLast];
    }

    auto itr = m_colors.find(themeColor);
    if (itr == m_colors.end())
    {
        return ZepColor(255, 255, 255, 255);
    }
    return itr->second;
}

ZepColor ZepTheme::GetComplement(ZepColor col, ZepColor adjust) const
{
    auto lum = Luminosity(col);
    if (lum > 0.5f)
        return GetColor(ThemeColor::Dark) + adjust;
    return GetColor(ThemeColor::Light) - adjust;
}

} // namespace Zep
