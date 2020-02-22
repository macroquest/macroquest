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
#include "MQ2Main.h"

#include <locale>
#include <codecvt>
#include <regex>
#include <args/args.hxx>
#include <memory>
#include <Yaml.hpp>

// TODO: add toggles for various commands

namespace mq {

// Variables (most of it is wrapped up in the yaml node)
static std::string anon_config_path;
static Yaml::Node anon_config;
static bool anon_enabled;

enum class Anonymization
{
	None,
	Asterisk,
	Class,
	Me
};

static std::unordered_map<std::string_view, Anonymization> anonymization_map = {
	{"none", Anonymization::None},
	{"asterisk", Anonymization::Asterisk},
	{"class", Anonymization::Class},
	{"me", Anonymization::Me}
};

// put this near the anon types to keep maintenance easy
static std::string Anonymize(std::string_view Name, Anonymization How)
{
	switch (How)
	{
	case Anonymization::Asterisk:
	{
		std::string asterisk_name(Name);
		for (size_t i = 1; i < asterisk_name.length() - 1; ++i)
			asterisk_name[i] = '*';
		return asterisk_name;
	}
	case Anonymization::Class:
		return fmt::format("[${{Spawn[pc {0}].Level}}] ${{Spawn[pc {0}].Race}} ${{Spawn[pc {0}].Class}} ${{Spawn[pc {0}].Type}}", Name);
	case Anonymization::Me:
		return "[${Me.Level}] ${Me.Race} ${Me.Class} ${Me.Type}";
	default:
		return std::string(Name);
	};
}

static Anonymization anon_group;
static Anonymization anon_guild;
static Anonymization anon_raid;

class anon_replacer {
public:
	const std::string name;

private:
	std::string target;
	std::set<std::string> alternates;
	std::regex search_string;

private:
	void build_regex()
	{
		search_string = std::regex(
			fmt::format("\\b({}{})\\b", name, std::accumulate(alternates.cbegin(), alternates.cend(), std::string(),
				[](const std::string& text, std::string_view alt) -> std::string {
					return fmt::format("{}|{}", text, alt);
				})),
			std::regex_constants::icase);
	}

public:
	anon_replacer(std::string_view name, std::string_view target)
		: name(name), target(target)
	{
		build_regex();
	}

	anon_replacer(Yaml::Node& node)
		: name(node["name"].As<std::string>()), target(node["target"].As<std::string>())
	{
		if (node["alternates"].IsSequence())
		{
			for (auto alt = node["alternates"].Begin(); alt != node["alternates"].End(); alt++)
				alternates.emplace((*alt).second.As<std::string>());
		}

		build_regex();
	}

	void add_alternate(std::string_view alternate)
	{
		alternates.emplace(std::string(alternate));
		build_regex();
	}

	void drop_alternate(std::string_view alternate)
	{
		alternates.erase(std::string(alternate));
		build_regex();
	}

	void update_target(std::string_view target)
	{
		this->target = target;
	}

	std::string_view get_target()
	{
		return target;
	}

	std::string replace_text(std::string_view text) const
	{
		std::string result;
		std::regex_replace(std::back_inserter(result), std::cbegin(text), std::cend(text), search_string, ModifyMacroString(target));
		return result;
	}

	Yaml::Node Serialize()
	{
		Yaml::Node node;

        node["name"] = name;
        node["target"] = target;
        for (auto alt : alternates)
            node["alternates"].PushBack() = alt;
        
        return node;
	}
};

// the source string_view is checked _after_ string parsing
// the target string is parsed before replacement
static std::vector<std::unique_ptr<anon_replacer> > replacers;
static ci_unordered::map<std::unique_ptr<anon_replacer> > group_memoization;
static ci_unordered::map<std::unique_ptr<anon_replacer> > guild_memoization;
static ci_unordered::map<std::unique_ptr<anon_replacer> > raid_memoization;

// the source string_view here will be used to index
// creating a regex that looks like `(source|all|the|alternates)`

// helper function to find a replacer by name
static std::vector<std::unique_ptr<anon_replacer> >::iterator FindReplacer(std::string_view Name)
{
	return std::find_if(std::begin(replacers), std::end(replacers),
		[&Name](const std::unique_ptr<anon_replacer>& r) { return r && ci_equals(Name, r->name); });
}

// helper function to find a name by replacer
static std::vector<std::unique_ptr<anon_replacer> >::iterator ReverseFind(std::string_view Target)
{
	return std::find_if(std::begin(replacers), std::end(replacers),
		[&Target](const std::unique_ptr<anon_replacer>& r) { return r && ci_equals(Target, r->get_target()); });
}

// helper functions for serializing anonymization type
static Anonymization GetAnonymizationFromString(std::string_view anon)
{
	auto it = anonymization_map.find(anon);
	if (it != anonymization_map.end())
		return it->second;

	return Anonymization::None;
}

static std::string_view GetStringFromAnonymization(Anonymization anon)
{
	for (auto anon_type : anonymization_map)
	{
		if (anon_type.second == anon)
			return anon_type.first;
	}

	return "none";
}

// add an anonymization rule to the map -- if the rule already exists, assume we want to update the target
static void AddAnonymization(std::string_view Name, std::string_view Replace)
{
	auto replacer_it = FindReplacer(Name);

	if (replacer_it != std::end(replacers))
		(*replacer_it)->update_target(Replace); // just change the replace text
	else
		replacers.emplace_back(std::make_unique<anon_replacer>(Name, Replace));
}

static void DropAnonymization(std::string_view Name)
{
	auto replacer_it = FindReplacer(Name);

	if (replacer_it != std::end(replacers))
		replacers.erase(replacer_it);
}

// will not add an entry if there is nothing available
static void AddAlternate(std::string_view Name, std::string_view Alternate)
{
	auto replacer_it = FindReplacer(Name);

	if (replacer_it != std::end(replacers))
		(*replacer_it)->add_alternate(Alternate);

	// don't do anything if we can't find the name
}

// will not add an entry if there is nothing available
static void DropAlternate(std::string_view Name, std::string_view Alternate)
{
	auto replacer_it = FindReplacer(Name);

	if (replacer_it != std::end(replacers))
		(*replacer_it)->drop_alternate(Alternate);
}

// let the user pass without a name
static void DropAlternate(std::string_view Alternate)
{
	std::for_each(std::begin(replacers), std::end(replacers),
		[&Alternate](const std::unique_ptr<anon_replacer>& r) { if (r) r->drop_alternate(Alternate); });
}

static void Serialize()
{
	anon_config["enabled"] = anon_enabled ? "true" : "false";

	anon_config["replacers"].Clear();
	if (!replacers.empty())
	{
		for (auto replacer = std::cbegin(replacers); replacer != std::cend(replacers); ++replacer)
			anon_config["replacers"].PushBack() = (*replacer)->Serialize();
	}
	else
		anon_config.Erase("replacers");

	anon_config["group"] = std::string(GetStringFromAnonymization(anon_group));
	anon_config["guild"] = std::string(GetStringFromAnonymization(anon_guild));
	anon_config["raid"] = std::string(GetStringFromAnonymization(anon_raid));

	Yaml::Serialize(anon_config, anon_config_path.c_str());
}

static void Deserialize()
{
	try
	{
		Yaml::Parse(anon_config, anon_config_path.c_str());
	}
	catch (const Yaml::OperationException&)
	{
		// if we can't read the file, then try to write it with an empty config
		Yaml::Serialize(anon_config, anon_config_path.c_str());
	}

	anon_enabled = anon_config["enabled"].As<bool>(false);

	if (anon_config["replacers"].IsSequence())
	{
		for (auto replacer = anon_config["replacers"].Begin(); replacer != anon_config["replacers"].End(); replacer++)
			replacers.emplace_back(std::make_unique<anon_replacer>((*replacer).second));

		anon_config["replacers"].Clear();
	}

	anon_group = GetAnonymizationFromString(anon_config["group"].As<std::string>());
	anon_guild = GetAnonymizationFromString(anon_config["guild"].As<std::string>());
	anon_raid = GetAnonymizationFromString(anon_config["raid"].As<std::string>());
}

// this is primarily a helper for one-liner memoization try_emplaces
template <class F>
struct lazy_ctor
{
	constexpr lazy_ctor(F&& f) : f(std::move(f)) {}
	constexpr operator std::invoke_result_t<const F&>() const noexcept(std::is_nothrow_invocable_v<const F&>) { return f(); }
	F f;
};

// process string to anonymize
CXStr& Anonymize(CXStr& Text)
{
	if (anon_enabled)
	{
		EnterMQ2Benchmark(bmAnonymizer);

		auto new_text = std::accumulate(std::cbegin(replacers), std::cend(replacers), std::string(Text),
			[](std::string& text, const std::unique_ptr<anon_replacer>& r) -> std::string {
				return r ? r->replace_text(text) : text;
			});

		auto pChar = GetCharInfo();
		if (anon_group != Anonymization::None && pChar && pChar->pGroupInfo)
		{
			new_text = std::accumulate(
				std::cbegin(pChar->pGroupInfo->pMember),
				std::cend(pChar->pGroupInfo->pMember),
				new_text,
				[](std::string& text, const GROUPMEMBER* g) -> std::string
				{
					if (g)
					{
						auto [it, result] = group_memoization.try_emplace(
							g->Name,
							lazy_ctor([&g] {
								return std::make_unique<anon_replacer>(g->Name, Anonymize(g->Name, anon_group));
							})
						);

						return it->second->replace_text(text);
					}

					return text;
				}
			);
		}

		if (anon_guild != Anonymization::None && pGuildList)
		{
			if (pGuild && pChar)
			{
				auto guild_name = pGuild->GetGuildName(pChar->GuildID);
				auto [it, result] = guild_memoization.try_emplace(
					guild_name,
					lazy_ctor([&guild_name] {
						return std::make_unique<anon_replacer>(guild_name, Anonymize(guild_name, anon_guild));
					})
				);

				new_text = it->second->replace_text(new_text);
			}

			// pGuildList is just "current guild"
			for (auto pMember = pGuildList->pMember; pMember; pMember = pMember->pNext)
			{
				auto [it, result] = guild_memoization.try_emplace(
					pMember->Name,
					lazy_ctor([&pMember] {
						return std::make_unique<anon_replacer>(pMember->Name, Anonymize(pMember->Name, anon_guild));
					})
				);

				new_text = it->second->replace_text(new_text);
			}
		}

		if (anon_raid != Anonymization::None && pChar && pRaid)
		{
			for (auto pMember : pRaid->RaidMember)
			{
				if (pMember.Name[0] != '\0')
				{
					auto [it, result] = raid_memoization.try_emplace(
						pMember.Name,
						lazy_ctor([&pMember] {
							return std::make_unique<anon_replacer>(pMember.Name, Anonymize(pMember.Name, anon_raid));
						})
					);

					new_text = it->second->replace_text(new_text);
				}
			}
		}

		Text = new_text;

		ExitMQ2Benchmark(bmAnonymizer);
	}

	return Text;
}

int GetGaugeValueFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*);
int GetGaugeValueFromEQ_Detour(int EQType, CXStr& out, bool* arg3, unsigned long* colorout)
{
	int ret = GetGaugeValueFromEQ_Trampoline(EQType, out, arg3, colorout);
	Anonymize(out);
	return ret;
}

int GetLabelFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*);
int GetLabelFromEQ_Detour(int EQType, CXStr& out, bool* arg3, unsigned long* colorout)
{
	int ret = GetLabelFromEQ_Trampoline(EQType, out, arg3, colorout);
	Anonymize(out);
	return ret;
}

class CListWndHook
{
public:
	int AddString_Trampoline(const CXStr& Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr);
	int AddString_Detour(const CXStr& Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr)
	{
		CXStr LineOut = Str;
		return AddString_Trampoline(Anonymize(LineOut), Color, Data, pTa, TooltipStr);
	}
};

class CAdvancedLootWndHook
{
public:
	void UpdateMasterLooter_Trampoline(const CXStr& Name, bool bChanged);
	void UpdateMasterLooter_Detour(const CXStr& Name, bool bChanged) // TODO: do we need to call this when we turn anon on and off/update the anon list?
	{
		UpdateMasterLooter_Trampoline(Name, bChanged);
		if (!pAdvancedLootWnd)
			return;

		CHARINFO* pChar = GetCharInfo();
		if (!pChar || !pChar->pGroupInfo)
			return;

		CLabelWnd* MasterLooterLabel = (CLabelWnd*)pAdvancedLootWnd->GetChildItem("ADLW_CalculatedMasterLooter");
		if (!MasterLooterLabel)
			return;

		CXStr LabelOut = MasterLooterLabel->Text;
		MasterLooterLabel->SetWindowText(Anonymize(LabelOut));
	}
};

class CComboWndHook
{
private:
public:
	CXStr GetChoiceText_Trampoline(int index) const;
	CXStr GetChoiceText_Detour(int index) const
	{
		CXStr ret = GetChoiceText_Trampoline(index);

		auto r_it = ReverseFind(ret);
		if (r_it != std::end(replacers))
			ret = (*r_it)->name;

		return ret;
	}

	int InsertChoiceAtIndex_Trampoline(const CXStr& Str, uint32_t index);
	int InsertChoiceAtIndex_Detour(const CXStr& Str, uint32_t index)
	{
		CXStr LineOut = Str;
		return InsertChoiceAtIndex_Trampoline(Anonymize(LineOut), index);
	}
};

class CEverQuestHook
{
public:
	char* TrimName_Trampoline(const char*);
	char* TrimName_Detour(const char* arg1)
	{
		char* ret = TrimName_Trampoline(arg1);

		CXStr LineOut = ret;
		LineOut = Anonymize(LineOut);

		// ret has been allocated 2112 (2048 + 64, I guess?) bytes, so we gotta limit to that
		strncpy_s(ret, 2112U, LineOut.c_str(), LineOut.length() + 1);
		return ret;
	}
};

class CTextureFontHook
{
public:
	int DrawWrappedText_Trampoline(const CXStr&, int, int, int, const CXRect&, COLORREF, uint16_t, int) const;
	int DrawWrappedText_Detour(const CXStr& Str, int x, int y, int Width, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0) const
	{
		CXStr StrOut = Str;
		return DrawWrappedText_Trampoline(Anonymize(StrOut), x, y, Width, BoundRect, Color, Flags, StartX);
	}

	//int DrawWrappedText_Trampoline(const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int) const;
	//int DrawWrappedText_Detour(const CXStr& Str, const CXRect& Rect, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0) const
	//{
	//	CXStr StrOut = Str;
	//	return DrawWrappedText_Trampoline(Anonymize(StrOut), Rect, BoundRect, Color, Flags, StartX);
	//}
};

DETOUR_TRAMPOLINE_EMPTY(int CTextureFontHook::DrawWrappedText_Trampoline(const CXStr&, int, int, int, const CXRect&, COLORREF, uint16_t, int) const);
//DETOUR_TRAMPOLINE_EMPTY(int CTextureFontHook::DrawWrappedText_Trampoline(const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int) const);
DETOUR_TRAMPOLINE_EMPTY(int GetGaugeValueFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*));
DETOUR_TRAMPOLINE_EMPTY(int GetLabelFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*));
DETOUR_TRAMPOLINE_EMPTY(int CListWndHook::AddString_Trampoline(const CXStr& Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr));
DETOUR_TRAMPOLINE_EMPTY(void CAdvancedLootWndHook::UpdateMasterLooter_Trampoline(const CXStr& Name, bool bChanged));
DETOUR_TRAMPOLINE_EMPTY(CXStr CComboWndHook::GetChoiceText_Trampoline(int index) const);
DETOUR_TRAMPOLINE_EMPTY(int CComboWndHook::InsertChoiceAtIndex_Trampoline(const CXStr& Str, uint32_t index));
DETOUR_TRAMPOLINE_EMPTY(char* CEverQuestHook::TrimName_Trampoline(const char*));

// ***************************************************************************
// Function:    MQAnon
// Description: Our '/mqanon' command
//              Controls the anonymization filtering of text
// Usage:       /mqanon [add|drop|alias|unalias]
// ***************************************************************************

// TODO: Make sure to add this command with `Parse = false`!
void MQAnon(SPAWNINFO* pChar, char* szLine)
{
	if (!pChar)
		return;

	args::ArgumentParser arg_parser("mqanon parser");
	arg_parser.Prog("/mqanon");
	arg_parser.RequireCommand(false);
	args::Group commands(arg_parser, "commands", args::Group::Validators::AtMostOne);

	args::Command add(commands, "add", "adds anonymization name and replacement text", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::All);
		args::Positional<std::string> name(arguments, "name", "the name to anonymize");
		args::Group replacer(arguments, "replacer", args::Group::Validators::AtMostOne);
		
		args::Command asterisk(replacer, "asterisk", "anonymize with asterisks",
			[&name](args::Subparser&) { AddAnonymization(name.Get(), Anonymize(name.Get(), Anonymization::Asterisk)); });
		args::Command clas(replacer, "class", "anonymize by class attributes",
			[&name](args::Subparser&) { AddAnonymization(name.Get(), Anonymize(name.Get(), Anonymization::Class)); });
		args::Command me(replacer, "me", "anonymize with my class attributes",
			[&name](args::Subparser&) { AddAnonymization(name.Get(), Anonymize(name.Get(), Anonymization::Me)); });
		args::Command with(replacer, "with", "anonymize with specific macro string",
			[&name](args::Subparser& parser) {
				args::Group with(parser, "with", args::Group::Validators::AtLeastOne);
				args::Positional<std::string> replace(with, "replace", "the text to replace the name with");
				parser.Parse();
				AddAnonymization(name.Get(), replace.Get());
			});

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();
	});

	args::Command drop(commands, "drop", "drops anonymization name from list of filtered names", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::All);
		args::Positional<std::string> name(arguments, "name", "the name to de-anonymize");

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		DropAnonymization(name.Get());
	});

	args::Command alias(commands, "alias", "adds an alias for a name in the list of filtered names", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::All);
		args::Positional<std::string> name(arguments, "name", "the name entry to alias");
		args::Positional<std::string> alias(arguments, "alias", "the alias to also search for when replacing the name");

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		AddAlternate(name.Get(), alias.Get());
	});

	args::Command unalias(commands, "unalias", "drops an alias for a name in the list of filtered names", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::AtLeastOne);
		args::Positional<std::string> name(arguments, "[name]", "the name entry to unalias");
		args::Positional<std::string> alias(arguments, "alias", "the alias to also stop searching for when replacing the name");

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		if (alias)
			DropAlternate(name.Get(), alias.Get());
		else
			DropAlternate(name.Get());
	});

	args::Command group(commands, "group", "sets group anonymization", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::AtMostOne);
		args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		anon_group = anon_type.Get();
	});

	group.RequireCommand(false);

	args::Command guild(commands, "guild", "sets guild anonymization", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::AtMostOne);
		args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		anon_guild = anon_type.Get();
	});

	guild.RequireCommand(false);

	args::Command raid(commands, "raid", "sets raid anonymization", [](args::Subparser& parser) {
		args::Group command(parser, "command", args::Group::Validators::AtMostOne);

		args::Group arguments(command, "arguments", args::Group::Validators::AtMostOne);
		args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		anon_raid = anon_type.Get();
	});

	raid.RequireCommand(false);

	args::Command save(commands, "save", "saves the configuration to file, completely rewriting data",
		[](args::Subparser&) { Serialize(); });
	args::Command load(commands, "load", "loads the configuration from file, overwriting and current settings or data",
		[](args::Subparser&) { Deserialize(); });

	args::HelpFlag h(commands, "help", "help", { 'h', "help" });

	auto args = allocate_args(szLine);

	try
	{
		arg_parser.ParseArgs(args);
	}
	catch (const args::Help&)
	{
		WriteChatColor(arg_parser.Help().c_str());
	}
	catch (const args::Error& e)
	{
		WriteChatColor(e.what());
	}

	if (args.empty())
		anon_enabled = !anon_enabled;
}

void InitializeAnonymizer()
{
	EzDetour(CTextureFont__DrawWrappedText, &CTextureFontHook::DrawWrappedText_Detour, &CTextureFontHook::DrawWrappedText_Trampoline);
	//EzDetour(__GetGaugeValueFromEQ, GetGaugeValueFromEQ_Detour, GetGaugeValueFromEQ_Trampoline);
	//EzDetour(__GetLabelFromEQ, GetLabelFromEQ_Detour, GetLabelFromEQ_Trampoline);
	//EzDetour(CListWnd__AddString, &CListWndHook::AddString_Detour, &CListWndHook::AddString_Trampoline);
	//EzDetour(CAdvancedLootWnd__UpdateMasterLooter, &CAdvancedLootWndHook::UpdateMasterLooter_Detour, &CAdvancedLootWndHook::UpdateMasterLooter_Trampoline);
	//EzDetour(CComboWnd__GetChoiceText, &CComboWndHook::GetChoiceText_Detour, &CComboWndHook::GetChoiceText_Trampoline);
	//EzDetour(CComboWnd__InsertChoiceAtIndex, &CComboWndHook::InsertChoiceAtIndex_Detour, &CComboWndHook::InsertChoiceAtIndex_Trampoline);
	//EzDetour(CEverQuest__trimName, &CEverQuestHook::TrimName_Detour, &CEverQuestHook::TrimName_Trampoline);

	bmAnonymizer = AddMQ2Benchmark("Anonymizer");

	anon_config_path = mq::internal_paths::Config + "\\MQ2Anonymize.yaml";
	Deserialize(); // always load on initialization

	AddCommand("/mqanon", MQAnon, false, false, false);
}

void ShutdownAnonymizer()
{
	RemoveCommand("/mqanon");

	RemoveMQ2Benchmark(bmAnonymizer);

	RemoveDetour(CTextureFont__DrawWrappedText);
	//RemoveDetour(__GetGaugeValueFromEQ);
	//RemoveDetour(__GetLabelFromEQ);
	//RemoveDetour(CListWnd__AddString);
	//RemoveDetour(CAdvancedLootWnd__UpdateMasterLooter);
	//RemoveDetour(CComboWnd__GetChoiceText);
	//RemoveDetour(CComboWnd__InsertChoiceAtIndex);
	//RemoveDetour(CEverQuest__trimName);
}
}
