#pragma once

namespace Zep
{

namespace WindowFlags
{
    enum
    {
        None                   = 0,
        ShowWhiteSpace         = 0x0001,
        ShowCR                 = 0x0002,
        ShowLineNumbers        = 0x0004,
        ShowIndicators         = 0x0008,
        HideScrollBar          = 0x0010,
        Modal                  = 0x0020,
        WrapText               = 0x0040, // Warning: this is not for general use yet. Has issues
        HideSplitMark          = 0x0080,
        GridStyle              = 0x0200,
        ShowLineBackground     = 0x0400,
        ShowWrappedLineNumbers = 0x0800,
        ShowAirLine            = 0x1000,
        HideTrailingNewline    = 0x2000, // Don't show blank line at bottom of window
    };
}

} // namespace Zep