/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "pch.h"
#include "ImGuiUtils.h"

#include "fonts/embedded_fonts.h"
#include "fonts/IconsFontAwesome.h"
#include "fonts/IconsMaterialDesign.h"

#include <imgui.h>
#include <imgui_internal.h>

#include <filesystem>

namespace mq {
namespace imgui {

//============================================================================

ImFont* DefaultFont = nullptr;
ImFont* ConsoleFont = nullptr;
ImFont* LargeIconFont = nullptr;
ImFont* LargeTextFont = nullptr;

void ConfigureDefaultFont(ImFontAtlas* atlas)
{
	// font: Roboto Regular @ 16px
	ImFontConfig rrConfig;
	strcpy_s(rrConfig.Name, "RobotoRegular");
	rrConfig.OversampleH = rrConfig.OversampleV = 3;
	DefaultFont = atlas->AddFontFromMemoryCompressedTTF(GetRobotoRegularCompressedData(), GetRobotoRegularCompressedSize(), 16.0, &rrConfig);

	// font: FontAwesome
	ImFontConfig faConfig;
	faConfig.DstFont = DefaultFont;
	faConfig.MergeMode = true;
	strcpy_s(faConfig.Name, "FontAwesome");
	faConfig.GlyphMinAdvanceX = 14.0f;
	faConfig.GlyphOffset.x = 0.0f;
	static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	atlas->AddFontFromMemoryCompressedTTF(GetFontAwesomeCompressedData(), GetFontAwesomeCompressedSize(), 14.0f, &faConfig, icon_ranges);

	// font: Material Design Icons
	ImFontConfig mdConfig;
	mdConfig.DstFont = DefaultFont;
	mdConfig.MergeMode = true;
	mdConfig.GlyphMinAdvanceX = 16.0f;
	mdConfig.GlyphOffset.y = 3.f;
	strcpy_s(mdConfig.Name, "MaterialDesignIcons");
	static const ImWchar md_icon_ranges[] = { ICON_MIN_MD, ICON_MAX_MD, 0 };
	atlas->AddFontFromMemoryCompressedTTF(GetMaterialIconsCompressedData(), GetMaterialIconsCompressedSize(), 16.0f, &mdConfig, md_icon_ranges);

	char szWindowsPath[MAX_PATH] = { 0 };
	if (::GetWindowsDirectoryA(szWindowsPath, MAX_PATH) != 0)
	{
		// console font: Lucida Console @ 13px
		std::error_code ec;

		char szConsoleFont[MAX_PATH];
		sprintf_s(szConsoleFont, "%s\\fonts\\lucon.ttf", szWindowsPath);

		if (std::filesystem::is_regular_file(szConsoleFont, ec))
		{
			ImFontConfig consoleFontConfig;
			consoleFontConfig.OversampleH = consoleFontConfig.OversampleV = 3;
			ConsoleFont = atlas->AddFontFromFileTTF(szConsoleFont, 13.0f, &consoleFontConfig);
		}
	}

	if (!ConsoleFont)
	{
		ConsoleFont = atlas->AddFontDefault();
	}
}

void ConfigureLargeFont(ImFontAtlas* atlas)
{
	// font: Roboto Regular @ 22px
	ImFontConfig rrConfig;
	strcpy_s(rrConfig.Name, "RobotoRegular (Large)");
	LargeTextFont = atlas->AddFontFromMemoryCompressedTTF(GetRobotoRegularCompressedData(), GetRobotoRegularCompressedSize(), 22.0, &rrConfig);

	// font: FontAwesome @ 22px
	ImFontConfig faConfig;
	faConfig.DstFont = LargeTextFont;
	faConfig.MergeMode = true;
	strcpy_s(faConfig.Name, "FontAwesome (Large)");
	faConfig.GlyphOffset.x = 1.0f;
	static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	atlas->AddFontFromMemoryCompressedTTF(GetFontAwesomeCompressedData(), GetFontAwesomeCompressedSize(), 20.0f, &faConfig, icon_ranges);

	// font: Material Design Icons @ 22px
	ImFontConfig mdConfig;
	mdConfig.DstFont = LargeTextFont;
	mdConfig.MergeMode = true;
	mdConfig.GlyphMinAdvanceX = 22.0f;
	mdConfig.GlyphOffset.y = 4.f;
	strcpy_s(mdConfig.Name, "MaterialDesignIcons (Large)");
	static const ImWchar md_icon_ranges[] = { ICON_MIN_MD, ICON_MAX_MD, 0 };
	atlas->AddFontFromMemoryCompressedTTF(GetMaterialIconsCompressedData(), GetMaterialIconsCompressedSize(), 22.0f, &mdConfig, md_icon_ranges);

	LargeIconFont = LargeTextFont;
}

void ConfigureFonts(ImFontAtlas* atlas)
{
	ConfigureDefaultFont(atlas);
	ConfigureLargeFont(atlas);
}

void ConfigureStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();

	ImGui::StyleColorsDark(&style);

	style.Alpha = 1.0f;
	style.FrameRounding = 0.0f;
	style.WindowRounding = 0.0f;
	style.ChildRounding = 0.0f;
	style.ScrollbarRounding = 0.0f;
	style.GrabRounding = 0.0f;
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
}

//============================================================================

void DrawSplitter(bool split_vertically, float thickness, float* size0, float* size1,
	float min_size0, float min_size1)
{
	ImVec2 backup_pos = ImGui::GetCursorPos();
	if (split_vertically)
		ImGui::SetCursorPosY(backup_pos.y + *size0);
	else
		ImGui::SetCursorPosX(backup_pos.x + *size0);

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0));          // We don't draw while active/pressed because as we move the panes the splitter button will be 1 frame late
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.6f, 0.6f, 0.6f, 0.10f));
	ImGui::SetNextItemAllowOverlap(); // This is to allow having other buttons OVER our splitter.
	ImGui::Button("##Splitter", ImVec2(!split_vertically ? thickness : -1.0f, split_vertically ? thickness : -1.0f));
	ImGui::PopStyleColor(3);

	if (ImGui::IsItemActive())
	{
		float mouse_delta = split_vertically ? ImGui::GetIO().MouseDelta.y : ImGui::GetIO().MouseDelta.x;

		// Minimum pane size
		if (mouse_delta < min_size0 - *size0)
			mouse_delta = min_size0 - *size0;
		if (mouse_delta > * size1 - min_size1)
			mouse_delta = *size1 - min_size1;

		// Apply resize
		*size0 += mouse_delta;
		*size1 -= mouse_delta;
	}
	ImGui::SetCursorPos(backup_pos);
}

void HelpMarker(const char* desc, float width, ImFont* tooltipFont)
{
	ImGui::TextDisabled(ICON_FA_QUESTION_CIRCLE_O);

	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(width);

		if (tooltipFont)
		{
			ImGui::PushFont(tooltipFont);
		}

		ImGui::TextUnformatted(desc);

		if (tooltipFont)
		{
			ImGui::PopFont();
		}

		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void HelpMarker(const std::function<void(char*, size_t)>& getText, float width, ImFont* tooltipFont)
{
	ImGui::TextDisabled(ICON_FA_QUESTION_CIRCLE_O);

	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(width);

		if (tooltipFont)
		{
			ImGui::PushFont(tooltipFont);
		}

		char buffer[1024];
		getText(buffer, 1024);

		ImGui::TextUnformatted(buffer);

		if (tooltipFont)
		{
			ImGui::PopFont();
		}

		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

enum ImGuiAlign_
{
	ImGuiAlign_Left = 1 << 0,
	ImGuiAlign_Center = 1 << 1,
	ImGuiAlign_Right = 1 << 2,
	ImGuiAlign_Top = 1 << 3,
	ImGuiAlign_VCenter = 1 << 4,
	ImGuiAlign_Default = ImGuiAlign_Left | ImGuiAlign_Top
};

// Internal helper for generating the text overlay
static void RenderTextOverlay(ImVec2 pos, const ImVec4& color, ImGuiAlign_ alignment,
	const char* text, const char* text_end)
{
	auto& g = *ImGui::GetCurrentContext();

	if (!text_end)
		text_end = text + strlen(text); // FIXME-OPT
	const char* text_display_end = text_end;

	// if the position is negative, then make it relative to the opposite end of the screen
	if (pos.y < 0)
		pos.y = ImGui::GetIO().DisplaySize.y + pos.y;
	if (pos.x < 0)
		pos.x = ImGui::GetIO().DisplaySize.x + pos.x;

	const int text_len = (int)(text_display_end - text);

	if (text_len > 0)
	{
		if (alignment == ImGuiAlign_Center)
		{
			float displayWidth = ImGui::GetIO().DisplaySize.x;

			// if centered, figure out the text width. We want to wrap at screen edges, so use
			// the screen width minus the distance from center as the available width.
			float availableWidth = displayWidth - ((displayWidth / 2) - pos.x);

			ImVec2 size = ImGui::CalcTextSize(text, text_end, false, availableWidth);

			// subtract half of the size from the x position to center text at that point.
			pos.x -= size.x / 2;
		}
		else if (alignment == ImGuiAlign_Right)
		{
			// if right aligned, then subtract width of the string from the position.
			ImVec2 size = ImGui::CalcTextSize(text, text_end, false);

			// subtract half of the size from the x position to center text at that point.
			pos.x -= size.x;
		}

		ImGui::GetForegroundDrawList()->AddText(g.Font, g.FontSize, pos, ImGui::ColorConvertFloat4ToU32(color),
			text, text_end);
	}
}

void RenderText(const ImVec2& pos, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer.Data + ImFormatStringV(g.TempBuffer.Data, g.TempBuffer.Size, fmt, args);

	RenderTextOverlay(pos, color, ImGuiAlign_Left, g.TempBuffer.Data, text_end);
}

void RenderText(int x, int y, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer.Data + ImFormatStringV(g.TempBuffer.Data, g.TempBuffer.Size, fmt, args);

	RenderTextOverlay(ImVec2((float)x, (float)y), color, ImGuiAlign_Left, g.TempBuffer.Data, text_end);
}

void RenderTextCentered(const ImVec2& pos, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer.Data + ImFormatStringV(g.TempBuffer.Data, g.TempBuffer.Size, fmt, args);

	RenderTextOverlay(pos, color, ImGuiAlign_Center, g.TempBuffer.Data, text_end);
}

void RenderTextCentered(int x, int y, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer.Data + ImFormatStringV(g.TempBuffer.Data, g.TempBuffer.Size, fmt, args);

	RenderTextOverlay(ImVec2((float)x, (float)y), color, ImGuiAlign_Center, g.TempBuffer.Data, text_end);
}

void RenderTextRight(const ImVec2& pos, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer.Data + ImFormatStringV(g.TempBuffer.Data, g.TempBuffer.Size, fmt, args);

	RenderTextOverlay(pos, color, ImGuiAlign_Right, g.TempBuffer.Data, text_end);
}

void RenderTextRight(int x, int y, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer.Data + ImFormatStringV(g.TempBuffer.Data, g.TempBuffer.Size, fmt, args);

	RenderTextOverlay(ImVec2((float)x, (float)y), color, ImGuiAlign_Right, g.TempBuffer.Data, text_end);
}

bool CollapsingSubHeader(const char* label, bool* p_open, ImGuiTreeNodeFlags flags)
{
	ImGui::PushStyleColor(ImGuiCol_Header, (ImVec4)ImColor(96, 96, 96, 128));
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, (ImVec4)ImColor(96, 96, 96, 196));
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, (ImVec4)ImColor(96, 96, 96, 255));

	bool result = ImGui::CollapsingHeader(label, p_open, flags);

	ImGui::PopStyleColor(3);

	return result;
}

bool CollapsingSubHeader(const char* label, ImGuiTreeNodeFlags flags)
{
	ImGui::PushStyleColor(ImGuiCol_Header, (ImVec4)ImColor(96, 96, 96, 128));
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, (ImVec4)ImColor(96, 96, 96, 196));
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, (ImVec4)ImColor(96, 96, 96, 255));

	bool result = ImGui::CollapsingHeader(label, flags);

	ImGui::PopStyleColor(3);

	return result;
}

//============================================================================

// Draw column headers
void ColumnHeaders(const char* columnsId, ColumnHeader* headers, int count, bool border)
{
	if (count <= 0)
		return;

	ImGuiStyle& style = ImGui::GetStyle();
	const ImVec2 firstTextSize = ImGui::CalcTextSize(headers[0].label, nullptr, true);

	ImGui::BeginChild(columnsId, ImVec2(0, firstTextSize.y + 2 * style.ItemSpacing.y), true);

	char str_id[256];
	ImFormatString(str_id, IM_ARRAYSIZE(str_id), "col_%s", columnsId);

	ImGui::Columns(count, str_id, border);

	float offset = 0.0f;

	for (int i = 0; i < count; i++)
	{
		ColumnHeader& header = headers[i];

		ImGui::SetColumnOffset(i, offset);

		if (header.size < 0 || header.sizeMIN < 0)
		{
			const ImVec2 textsize = ImGui::CalcTextSize(header.label, nullptr, true);
			const float colSizeX = (textsize.x + 2 * style.ItemSpacing.x);
			if (header.size < 0)		header.size = colSizeX;
			if (header.sizeMIN < 0)		header.sizeMIN = colSizeX;
		}

		if (header.allowResize == false)
		{
			offset += header.size;
		}
		else
		{
			if (i < (count - 1))
			{
				float curOffset = offset;
				offset = ImGui::GetColumnOffset(i + 1);
				header.size = offset - curOffset;
				if (header.size < header.sizeMIN)
				{
					header.size = header.sizeMIN;
					offset = curOffset + header.size;
				}
			}
		}

		ImGui::Text(header.label);
		ImGui::NextColumn();
	}

	ImGui::Columns(1);
	ImGui::EndChild();
}

// Synchronize with column headers
void BeginColumnHeadersSync(const char* columnsId, ColumnHeader* headers, int count, bool border)
{
	if (count <= 0)
		return;

	ImGui::BeginChild(columnsId, ImVec2(0, 0), true);
	ImGui::Columns(count, columnsId, border);

	ImGuiStyle& style = ImGui::GetStyle();

	float offset = 0.0f;
	for (int i = 0; i < count; i++)
	{
		ColumnHeader& header = headers[i];
		ImGui::SetColumnOffset(i, offset);
		offset += header.size;
	}
}

void EndColumnHeadersSync(ColumnHeader* headers, int count)
{
	if (count <= 0)
		return;

	ImGui::Columns(1);
	ImGui::EndChild();
}

}} // namespace mq::imgui
