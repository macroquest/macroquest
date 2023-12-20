#pragma once

inline ImVec4 ImVec4::FromImU32(ImU32 u32)
{
    return ImGui::ColorConvertU32ToFloat4(u32);
}

inline ImU32 ImVec4::ToImU32() const
{
    return ImGui::ColorConvertFloat4ToU32(*this);
}
