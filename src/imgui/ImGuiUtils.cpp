/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "pch.h"
#include "ImGuiUtils.h"

#include "fonts/font_roboto_regular_ttf.h"
#include "fonts/font_fontawesome_ttf.h"
#include "fonts/font_materialicons_ttf.h"

#include "fonts/IconsFontAwesome.h"
#include "fonts/IconsMaterialDesign.h"

#include <imgui.h>
#include <imgui_internal.h>


namespace mq {
namespace imgui {

//============================================================================

ImFont* DefaultFont = nullptr;
ImFont* ConsoleFont = nullptr;
ImFont* LargeIconFont = nullptr;
ImFont* LargeTextFont = nullptr;

void ConfigureFonts()
{
	ImGuiIO& io = ImGui::GetIO();

	// font: Roboto Regular @ 16px
	DefaultFont = io.Fonts->AddFontFromMemoryCompressedTTF(GetRobotoRegularCompressedData(),
		GetRobotoRegularCompressedSize(), 16.0);

	// font: FontAwesome
	ImFontConfig faConfig;
	faConfig.MergeMode = true;
	faConfig.GlyphMinAdvanceX = 14.0f;
	static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	io.Fonts->AddFontFromMemoryCompressedTTF(GetFontAwesomeCompressedData(),
		GetFontAwesomeCompressedSize(), 13.0f, &faConfig, icon_ranges);

	// font: Material Design Icons
	ImFontConfig mdConfig;
	mdConfig.MergeMode = true;
	mdConfig.GlyphMinAdvanceX = 13.0f;
	static const ImWchar md_icon_ranges[] = { ICON_MIN_MD, ICON_MAX_MD, 0 };
	io.Fonts->AddFontFromMemoryCompressedTTF(GetMaterialIconsCompressedData(),
		GetMaterialIconsCompressedSize(), 13.0f, &mdConfig, md_icon_ranges);

	// font: Material Design Icons (Large)
	ImFontConfig mdConfig2;
	mdConfig2.GlyphMinAdvanceX = 16.0f;
	LargeIconFont = io.Fonts->AddFontFromMemoryCompressedTTF(GetMaterialIconsCompressedData(),
		GetMaterialIconsCompressedSize(), 16.0f, &mdConfig2, md_icon_ranges);

	mdConfig2.DstFont = LargeIconFont;
	mdConfig2.MergeMode = true;

	io.Fonts->AddFontFromMemoryCompressedTTF(GetRobotoRegularCompressedData(),
		GetRobotoRegularCompressedSize(), 16.0, &mdConfig2);

	// add default proggy clean font as a secondary font
	ConsoleFont = io.Fonts->AddFontDefault();

	// a large text font for headings.
	LargeTextFont = io.Fonts->AddFontFromMemoryCompressedTTF(GetRobotoRegularCompressedData(),
		GetRobotoRegularCompressedSize(), 22);
}

void ConfigureStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();

	ImGui::StyleColorsDark(&style);

	style.Alpha = 1.0f;
	style.FrameRounding = 3.0f;
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
	ImGui::Button("##Splitter", ImVec2(!split_vertically ? thickness : -1.0f, split_vertically ? thickness : -1.0f));
	ImGui::PopStyleColor(3);

	ImGui::SetItemAllowOverlap(); // This is to allow having other buttons OVER our splitter.

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
	const char* text_end = g.TempBuffer + ImFormatStringV(g.TempBuffer, IM_ARRAYSIZE(g.TempBuffer), fmt, args);

	RenderTextOverlay(pos, color, ImGuiAlign_Left, g.TempBuffer, text_end);
}

void RenderText(int x, int y, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer + ImFormatStringV(g.TempBuffer, IM_ARRAYSIZE(g.TempBuffer), fmt, args);

	RenderTextOverlay(ImVec2((float)x, (float)y), color, ImGuiAlign_Left, g.TempBuffer, text_end);
}

void RenderTextCentered(const ImVec2& pos, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer + ImFormatStringV(g.TempBuffer, IM_ARRAYSIZE(g.TempBuffer), fmt, args);

	RenderTextOverlay(pos, color, ImGuiAlign_Center, g.TempBuffer, text_end);
}

void RenderTextCentered(int x, int y, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer + ImFormatStringV(g.TempBuffer, IM_ARRAYSIZE(g.TempBuffer), fmt, args);

	RenderTextOverlay(ImVec2((float)x, (float)y), color, ImGuiAlign_Center, g.TempBuffer, text_end);
}

void RenderTextRight(const ImVec2& pos, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer + ImFormatStringV(g.TempBuffer, IM_ARRAYSIZE(g.TempBuffer), fmt, args);

	RenderTextOverlay(pos, color, ImGuiAlign_Right, g.TempBuffer, text_end);
}

void RenderTextRight(int x, int y, const ImVec4& color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	auto& g = *ImGui::GetCurrentContext();
	const char* text_end = g.TempBuffer + ImFormatStringV(g.TempBuffer, IM_ARRAYSIZE(g.TempBuffer), fmt, args);

	RenderTextOverlay(ImVec2((float)x, (float)y), color, ImGuiAlign_Right, g.TempBuffer, text_end);
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
