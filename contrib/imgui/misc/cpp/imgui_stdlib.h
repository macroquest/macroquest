// dear imgui: wrappers for C++ standard library (STL) types (std::string, etc.)

// This is also an example of how you may wrap your own similar types.
// TL;DR; this is using the ImGuiInputTextFlags_CallbackResize facility,
// which also demonstrated in 'Dear ImGui Demo->Widgets->Text Input->Resize Callback'.

// Changelog:
// - v0.10: Initial version. Added InputText() / InputTextMultiline() calls with std::string

// Usage:
// {
//   #include "misc/cpp/imgui_stdlib.h"
//   #include "misc/cpp/imgui_stdlib.cpp" // <-- If you want to include implementation without messing with your project/build.
//   [...]
//   std::string my_string;
//   ImGui::InputText("my string", &my_string);
// }

// See more C++ related extension (fmt, RAII, syntaxis sugar) on Wiki:
//   https://github.com/ocornut/imgui/wiki/Useful-Extensions#cness

#pragma once

#ifndef IMGUI_DISABLE

#include <imgui.h>

#include <string>

namespace ImGui {

// Clang warnings with -Weverything
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"    // warning: implicit conversion changes signedness
#endif

namespace stdlib
{
    struct InputTextCallback_UserData
    {
        std::string*            Str;
        ImGuiInputTextCallback  ChainCallback;
        void*                   ChainCallbackUserData;
    };

    // This is declared inline because str->resize can re-allocate the memory in a string, and we
    // need that to occur in the module that runs this code, not in imgui.dll

    inline int InputTextCallback(ImGuiInputTextCallbackData* data)
    {
        InputTextCallback_UserData* user_data = (InputTextCallback_UserData*)data->UserData;
        if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
        {
            // Resize string callback
            // If for some reason we refuse the new length (BufTextLen) and/or capacity (BufSize) we need to set them back to what we want.
            std::string* str = user_data->Str;
            IM_ASSERT(data->Buf == str->c_str());
            str->resize(data->BufTextLen);
            data->Buf = (char*)str->c_str();
        }
        else if (user_data->ChainCallback)
        {
            // Forward to user callback, if any
            data->UserData = user_data->ChainCallbackUserData;
            return user_data->ChainCallback(data);
        }
        return 0;
    }

} // namespace stdlib

// ImGui::InputText() with std::string
// Because text input needs dynamic resizing, we need to setup a callback to grow the capacity
inline bool InputText(const char* label, std::string* str, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = nullptr, void* user_data = nullptr)
{
    IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
    flags |= ImGuiInputTextFlags_CallbackResize;

    stdlib::InputTextCallback_UserData cb_user_data;
    cb_user_data.Str = str;
    cb_user_data.ChainCallback = callback;
    cb_user_data.ChainCallbackUserData = user_data;
    return InputText(label, (char*)str->c_str(), str->capacity() + 1, flags, stdlib::InputTextCallback, &cb_user_data);
}

inline bool InputTextMultiline(const char* label, std::string* str, const ImVec2& size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = nullptr, void* user_data = nullptr)
{
    IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
    flags |= ImGuiInputTextFlags_CallbackResize;

    stdlib::InputTextCallback_UserData cb_user_data;
    cb_user_data.Str = str;
    cb_user_data.ChainCallback = callback;
    cb_user_data.ChainCallbackUserData = user_data;
    return InputTextMultiline(label, (char*)str->c_str(), str->capacity() + 1, size, flags, stdlib::InputTextCallback, &cb_user_data);
}

inline bool InputTextWithHint(const char* label, const char* hint, std::string* str, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = nullptr, void* user_data = nullptr)
{
    IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
    flags |= ImGuiInputTextFlags_CallbackResize;

    stdlib::InputTextCallback_UserData cb_user_data;
    cb_user_data.Str = str;
    cb_user_data.ChainCallback = callback;
    cb_user_data.ChainCallbackUserData = user_data;
    return InputTextWithHint(label, hint, (char*)str->c_str(), str->capacity() + 1, flags, stdlib::InputTextCallback, &cb_user_data);
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

} // namespace ImGui

#endif // #ifndef IMGUI_DISABLE