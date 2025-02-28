// dear imgui, v1.86 WIP
// (stack layout headers)

/*

Index of this file:
// [SECTION] Stack Layout Internal API

*/

#pragma once

#include "imgui_internal.h"
#include "imgui_stacklayout.h"

#ifndef IMGUI_DISABLE

//-----------------------------------------------------------------------------
// [SECTION] Stack Layout Internal API
//-----------------------------------------------------------------------------

namespace ImGuiInternal
{
    IMGUI_API ImGuiLayoutType GetCurrentLayoutType(ImGuiID window_id);
    IMGUI_API void            UpdateItemRect(ImGuiID window_id, const ImVec2& min, const ImVec2& max);

} // namespace ImGuiInternal


#endif // #ifndef IMGUI_DISABLE
