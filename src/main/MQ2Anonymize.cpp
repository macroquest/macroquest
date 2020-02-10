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

namespace mq {

// Variables (most of it is wrapped up in the yaml node)
std::string anon_config_path;
Yaml::Node anon_config;
bool anon_enabled;

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

	// this is designed to be used with an accumulate that returns a string, so move the old text in
	std::string replace_text(std::string&& text) const
	{
		return std::regex_replace(std::move(text), search_string, ModifyMacroString(target));
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

// TODO List:
//  - add save and load commands
//  - add adders/removers/replacers for guild/group/raid
//    - needs to be dynamic
//    - include the guild name in the guild replacer
//  - add helper for the "Class" replacer and the "Asterisk" replacer

// the source string_view is checked _after_ string parsing
// the target string is parsed before replacement
static std::vector<std::unique_ptr<anon_replacer> > replacers;

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
}

// process string to anonymize
CXStr& Anonymize(CXStr& Text)
{
	if (anon_enabled)
	{
		Text = std::accumulate(std::cbegin(replacers), std::cend(replacers), std::string(Text),
			[](std::string text, const std::unique_ptr<anon_replacer>& r) -> std::string {
				return  r ? r->replace_text(std::move(text)) : text;
			}).c_str();
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
		args::Positional<std::string> replace(arguments, "replace", "the text to replace the name with");

		args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
		args::HelpFlag h(flags, "help", "help", { 'h', "help" });
		parser.Parse();

		AddAnonymization(name.Get(), replace.Get());
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
		//anon_config["enabled"] = anon_config["enabled"].As<bool>(false) ? "false" : "true";
}

void InitializeAnonymizer()
{
	EzDetour(__GetGaugeValueFromEQ, GetGaugeValueFromEQ_Detour, GetGaugeValueFromEQ_Trampoline);
	EzDetour(__GetLabelFromEQ, GetLabelFromEQ_Detour, GetLabelFromEQ_Trampoline);
	EzDetour(CListWnd__AddString, &CListWndHook::AddString_Detour, &CListWndHook::AddString_Trampoline);
	EzDetour(CAdvancedLootWnd__UpdateMasterLooter, &CAdvancedLootWndHook::UpdateMasterLooter_Detour, &CAdvancedLootWndHook::UpdateMasterLooter_Trampoline);
	EzDetour(CComboWnd__GetChoiceText, &CComboWndHook::GetChoiceText_Detour, &CComboWndHook::GetChoiceText_Trampoline);
	EzDetour(CComboWnd__InsertChoiceAtIndex, &CComboWndHook::InsertChoiceAtIndex_Detour, &CComboWndHook::InsertChoiceAtIndex_Trampoline);
	EzDetour(CEverQuest__trimName, &CEverQuestHook::TrimName_Detour, &CEverQuestHook::TrimName_Trampoline);

	anon_config_path = mq::internal_paths::Config + "\\MQ2Anonymize.yaml";
	Deserialize();

	AddCommand("/mqanon", MQAnon, false, false, false);
}

void ShutdownAnonymizer()
{
	RemoveCommand("/mqanon");

	Serialize();

	RemoveDetour(__GetGaugeValueFromEQ);
	RemoveDetour(__GetLabelFromEQ);
	RemoveDetour(CListWnd__AddString);
	RemoveDetour(CAdvancedLootWnd__UpdateMasterLooter);
	RemoveDetour(CComboWnd__GetChoiceText);
	RemoveDetour(CComboWnd__InsertChoiceAtIndex);
	RemoveDetour(CEverQuest__trimName);
}
}
