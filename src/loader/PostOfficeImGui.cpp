/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#include "PostOffice.h"
#include "loader/ImGui.h"

#include <fmt/format.h>

using namespace mq::postoffice;

void ShowActorsWindow()
{
	static ImGuiTableFlags table_flags
		= ImGuiTableFlags_ScrollY
		| ImGuiTableFlags_ScrollX
		| ImGuiTableFlags_SizingFixedFit
		| ImGuiTableFlags_RowBg
		| ImGuiTableFlags_BordersOuter
		| ImGuiTableFlags_BordersV
		| ImGuiTableFlags_Resizable
		| ImGuiTableFlags_Reorderable
		| ImGuiTableFlags_Hideable;

	auto content_region = ImGui::GetContentRegionAvail();
	content_region.y -= ImGui::GetFrameHeightWithSpacing();

	if (ImGui::BeginTable("Actor Stats", 4, table_flags, content_region))
	{
		auto stats = GetPostOffice<LauncherPostOffice>().GetStats();
		size_t recv_tot = 0, send_tot = 0;
		for (const auto stat : stats)
		{
			recv_tot += stat->Received.size();
			send_tot += stat->Sent.size();
		}

		fmt::memory_buffer buf;
		const auto buf_ins = std::back_inserter(buf);

		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableSetupColumn("Identity", ImGuiTableColumnFlags_WidthFixed);

		fmt::format_to(buf_ins, "Received ({})", recv_tot);
		ImGui::TableSetupColumn(fmt::to_string(buf).c_str(), ImGuiTableColumnFlags_WidthStretch);

		buf.clear();
		fmt::format_to(buf_ins, "Sent ({})", send_tot);
		ImGui::TableSetupColumn(fmt::to_string(buf).c_str(), ImGuiTableColumnFlags_WidthStretch);

		buf.clear();
		fmt::format_to(buf_ins, "Total ({})", recv_tot + send_tot);
		ImGui::TableSetupColumn(fmt::to_string(buf).c_str(), ImGuiTableColumnFlags_WidthStretch);
		ImGui::TableHeadersRow();

		ImGuiListClipper clipper;
		clipper.Begin((int)stats.size());
		while (clipper.Step())
		{
			for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; ++row)
			{
				const auto& stat = stats.at(row);
				ImGui::TableNextRow();

				ImGui::TableSetColumnIndex(0);
				ImGui::Text(stat->Identity.ToStringLite().c_str());

				ImGui::TableSetColumnIndex(1);
				ImGui::Text("%d", stat->Received.size());

				ImGui::TableSetColumnIndex(2);
				ImGui::Text("%d", stat->Sent.size());

				ImGui::TableSetColumnIndex(3);
				ImGui::Text("%d", stat->Received.size() + stat->Sent.size());
			}
		}

		ImGui::EndTable();
	}

	static int lookback_seconds = GetPostOffice<LauncherPostOffice>().GetStatLookback();
	if (ImGui::InputInt("Lookback Seconds", &lookback_seconds))
	{
		if (lookback_seconds < 1)
			lookback_seconds = 1;

		GetPostOffice<LauncherPostOffice>().SetStatLookback(lookback_seconds);
	}
}

void InitializePostOfficeImgui()
{
	LauncherImGui::AddMainPanel("Actors", ShowActorsWindow);
}

void ShutdownPostOfficeImgui()
{
}
