#pragma once

#include "zep/mcommon/math/color.h"

#include <vector>
#include <map>

namespace Zep {

enum class ThemeColor
{
    None,
    TabBorder,
    HiddenText,
    Text,
    TextDim,
    Background,
    TabInactive,
    TabActive,
    LineNumberBackground,
    LineNumber,
    LineNumberActive,
    CursorNormal,
    CursorInsert,
    Light,
    Dark,
    VisualSelectBackground,
    CursorLineBackground,
    AirlineBackground,
    Mode,
    Normal,
    Keyword,
    Identifier,
    Number,
    String,
    Comment,
    Whitespace,
    HiddenChar,
    Parenthesis,
    Error,
    Warning,
    Info,
    WidgetBorder,
    WidgetBackground,
    WidgetActive,
    WidgetInactive,
    FlashColor,
    Custom,

    // Last in the list!
    // A set of pregenerated, easy to differentiate unique colors
    UniqueColor0,
    UniqueColor1,
    UniqueColor2,
    UniqueColor3,
    UniqueColor4,
    UniqueColor5,
    UniqueColor6,
    UniqueColor7,
    UniqueColor8,
    UniqueColor9,
    UniqueColor10,
    UniqueColor11,
    UniqueColor12,
    UniqueColor13,
    UniqueColor14,
    UniqueColor15,
    UniqueColorLast,
};

enum class ThemeType
{
    Dark = 1,
    Light,
    SolarizedDark,
    SolarizedLight,
    VSCodeDefault,
};

struct ThemeName
{
    ThemeType type;
    const char* name;
};
const std::vector<ThemeName>& GetThemeNames();

class ZepTheme
{
public:
    ZepTheme();
    virtual ~ZepTheme() {}

    virtual ZepColor GetColor(ThemeColor themeColor) const;
    virtual ZepColor GetComplement(ZepColor col, ZepColor adjust = ZepColor(0u)) const;
    virtual ThemeColor GetUniqueColor(uint32_t id) const;

    void SetThemeType(ThemeType type);
    ThemeType GetThemeType() const;


private:
    void SetDarkTheme();
    void SetLightTheme();
    void SetVSCodeDefaultTheme();
    void SetSolarizedDarkTheme();
    void SetSolarizedLightTheme();

protected:
    std::vector<ZepColor> m_uniqueColors;
    std::map<ThemeColor, ZepColor> m_colors;
    ThemeType m_currentTheme = ThemeType::Dark;
};

} // namespace Zep
