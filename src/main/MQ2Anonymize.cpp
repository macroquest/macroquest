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
static Anonymization anon_self;

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
static std::unique_ptr<anon_replacer> self_replacer;

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

static void SetAnon(bool anon_state)
{
	anon_enabled = anon_state;
	WriteChatf("MQ2Anonymize is now %s\ax.", anon_enabled ? "\agOn" : "\arOff");
	if (anon_enabled && !AreNameSpritesCustomized())
	{
		WriteChatf("\ayCustom name sprites are not turned on, set '/caption MQCaptions on' if you want to anonymize name sprites!\ax");
	}

	if (anon_enabled)
	{
		WriteChatf("\ayBe aware that Anonymization will only anonymize IN GAME! The character select screen will not be anonymized!\ax");
	}
}

static void ToggleAnon()
{
	SetAnon(!anon_enabled);
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
	anon_config["self"] = std::string(GetStringFromAnonymization(anon_self));

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
	anon_self = GetAnonymizationFromString(anon_config["self"].As<std::string>());

	// a load should reset all the temporary memoization (as a failsafe)
	group_memoization.clear();
	guild_memoization.clear();
	raid_memoization.clear();
	self_replacer.reset();
}

// process string to anonymize
CXStr& PluginAnonymize(CXStr& Text)
{
	if (anon_enabled && GetGameState() == GAMESTATE_INGAME && !Text.empty())
		Text = Anonymize(Text);

	return Text;
}

CXStr Anonymize(const CXStr& Text)
{
	if (anon_enabled && GetGameState() == GAMESTATE_INGAME && !Text.empty())
	{
		EnterMQ2Benchmark(bmAnonymizer);

		auto new_text = std::accumulate(std::cbegin(replacers), std::cend(replacers), std::string(Text),
			[](std::string& text, const std::unique_ptr<anon_replacer>& r) -> std::string {
				return r ? r->replace_text(text) : text;
			});

		auto pChar = GetCharInfo();

		if (anon_self != Anonymization::None && pChar)
		{
			if (!self_replacer || !ci_equals(self_replacer->name, pChar->Name))
				self_replacer = std::make_unique<anon_replacer>(pChar->Name, Anonymize(pChar->Name, anon_self));

			new_text = self_replacer->replace_text(new_text);
		}

		if (anon_group != Anonymization::None && pChar && pChar->pGroupInfo)
		{
			new_text = std::accumulate(
				std::cbegin(pChar->pGroupInfo->pMember),
				std::cend(pChar->pGroupInfo->pMember),
				new_text,
				[](std::string& text, const GROUPMEMBER* g) -> std::string
				{
					if (g && g->Name[0] != '\0' && ci_equals(text, g->Name, false))
					{
						auto memoized = group_memoization.find(g->Name);
						if (memoized == group_memoization.end())
							memoized = group_memoization.emplace(
								g->Name,
								std::make_unique<anon_replacer>(g->Name, Anonymize(g->Name, anon_group))
							).first;

						return memoized->second->replace_text(text);
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
				if (guild_name[0] != '\0' && ci_equals(new_text, guild_name, false))
				{
					auto memoized = guild_memoization.find(guild_name);
					if (memoized == guild_memoization.end())
						memoized = guild_memoization.emplace(
							guild_name,
							std::make_unique<anon_replacer>(guild_name, Anonymize(guild_name, Anonymization::Asterisk))
						).first;

					new_text = memoized->second->replace_text(new_text);
				}
			}

			// pGuildList is just "current guild"
			for (auto pMember = pGuildList->pMember; pMember; pMember = pMember->pNext)
			{
				if (pMember->Name[0] != '\0' && ci_equals(new_text, pMember->Name, false))
				{
					auto memoized = guild_memoization.find(pMember->Name);
					if (memoized == guild_memoization.end())
						memoized = guild_memoization.emplace(
							pMember->Name,
							std::make_unique<anon_replacer>(pMember->Name, Anonymize(pMember->Name, anon_guild))
						).first;

					new_text = memoized->second->replace_text(new_text);
				}
			}
		}

		if (anon_raid != Anonymization::None && pChar && pRaid)
		{
			for (auto pMember : pRaid->RaidMember)
			{
				if (pMember.Name[0] != '\0' && ci_equals(new_text, pMember.Name, false))
				{
					auto memoized = raid_memoization.find(pMember.Name);
					if (memoized == raid_memoization.end())
						memoized = raid_memoization.emplace(
							pMember.Name,
							std::make_unique<anon_replacer>(pMember.Name, Anonymize(pMember.Name, anon_raid))
						).first;

					new_text = memoized->second->replace_text(new_text);
				}
			}
		}

		return CXStr(new_text);

		ExitMQ2Benchmark(bmAnonymizer);
	}

	return Text;
}

int GetGaugeValueFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*);
int GetGaugeValueFromEQ_Detour(int EQType, CXStr& Str, bool* arg3, unsigned long* Color)
{
	int ret = GetGaugeValueFromEQ_Trampoline(EQType, Str, arg3, Color);
	Str = Anonymize(Str);
	return ret;
}

class CTextureFontHook
{
public:
	int DrawWrappedText_Trampoline(const CXStr&, int, int, int, const CXRect&, COLORREF, uint16_t, int) const;
	int DrawWrappedText_Detour(const CXStr& Str, int x, int y, int Width, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0) const
	{
		return DrawWrappedText_Trampoline(Anonymize(Str), x, y, Width, BoundRect, Color, Flags, StartX);
	}

	int DrawWrappedText1_Trampoline(const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int) const;
	int DrawWrappedText1_Detour(const CXStr& Str, const CXRect& Rect, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0) const
	{
		return DrawWrappedText1_Trampoline(Anonymize(Str), Rect, BoundRect, Color, Flags, StartX);
	}

	int DrawWrappedText2_Trampoline(CTextObjectInterface*, const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int) const;
	int DrawWrappedText2_Detour(CTextObjectInterface* Interface, const CXStr& Str, const CXRect& Rect, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0) const
	{
		return DrawWrappedText2_Trampoline(Interface, Anonymize(Str), Rect, BoundRect, Color, Flags, StartX);
	}
};

DETOUR_TRAMPOLINE_EMPTY(int GetGaugeValueFromEQ_Trampoline(int, CXStr&, bool*, unsigned long*));
DETOUR_TRAMPOLINE_EMPTY(int CTextureFontHook::DrawWrappedText_Trampoline(const CXStr&, int, int, int, const CXRect&, COLORREF, uint16_t, int) const);
DETOUR_TRAMPOLINE_EMPTY(int CTextureFontHook::DrawWrappedText1_Trampoline(const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int) const);
DETOUR_TRAMPOLINE_EMPTY(int CTextureFontHook::DrawWrappedText2_Trampoline(CTextObjectInterface*, const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int) const);

bool dataAnon(const char* szName, MQTypeVar& Ret)
{
	Ret.DWord = anon_enabled;
	Ret.Type = datatypes::pBoolType;
	return true;
}

// ***************************************************************************
// Function:    MQAnon
// Description: Our '/mqanon' command
//              Controls the anonymization filtering of text
// ***************************************************************************

void MQAnon(SPAWNINFO* pChar, char* szLine)
{
	if (!pChar)
		return;

	args::ArgumentParser arg_parser("Anonymization tool: filters specific text from display output.");
	arg_parser.Prog("/mqanon");
	arg_parser.RequireCommand(false);
	args::Group commands(arg_parser, "commands", args::Group::Validators::AtMostOne);

	args::Command asterisk(commands, "asterisk", "anonymize with asterisks",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name to anonymize");

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (name)
			{
				auto anonymization = Anonymize(name.Get(), Anonymization::Asterisk);
				AddAnonymization(name.Get(), anonymization);
				WriteChatf("Anonymized \at%s\ax with \at%s\ax.", name.Get().c_str(), anonymization.c_str());
			}
		});

	args::Command clas(commands, "class", "anonymize by class attributes",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name to anonymize");

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (name)
			{
				auto anonymization = Anonymize(name.Get(), Anonymization::Class);
				AddAnonymization(name.Get(), anonymization);
				WriteChatf("Anonymized \at%s\ax with \at%s\ax.", name.Get().c_str(), anonymization.c_str());
			}
		});

	args::Command custom(commands, "custom", "anonymize with custom string",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name to anonymize");
			args::PositionalList<std::string> replacers(arguments, "replacers", "the text to anonymize with");

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (name && replacers)
			{
				auto anonymization = join(replacers.Get(), " ");
				AddAnonymization(name.Get(), anonymization);
				WriteChatf("Anonymized \at%s\ax with \at%s\ax.", name.Get().c_str(), anonymization.c_str());
			}
		});

	args::Command drop(commands, "drop", "drops anonymization name from list of filtered names",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name to de-anonymize");

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (name)
			{
				DropAnonymization(name.Get());
				WriteChatf("Un-Anonymized \at%s\ax.", name.Get().c_str());
			}
		});

	args::Command alias(commands, "alias", "adds an alias for a name in the list of filtered names",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name entry to alias");
			args::Positional<std::string> alias(arguments, "alias", "the alias to also search for when replacing the name");

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (name && alias)
			{
				AddAlternate(name.Get(), alias.Get());
				WriteChatf("Added Alias \ay%s\ax to \at%s\ax.", alias.Get().c_str(), name.Get().c_str());
			}
		});

	args::Command unalias(commands, "unalias", "drops an alias for a name in the list of filtered names",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::AtLeastOne);
			args::Positional<std::string> name(arguments, "[name]", "the name entry to unalias");
			args::Positional<std::string> alias(arguments, "alias", "the alias to also stop searching for when replacing the name");

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (name && alias)
			{
				DropAlternate(name.Get(), alias.Get());
				WriteChatf("Dropped Alias \ay%s\ax from \at%s\ax.", alias.Get().c_str(), name.Get().c_str());
			}
			else if (name)
			{
				DropAlternate(name.Get());
				WriteChatf("Dropped Alias \ay%s\ax.", name.Get().c_str());
			}
		});

	args::Command group(commands, "group", "sets group anonymization",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::AtMostOne);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (anon_type)
			{
				auto a = anon_type.Get();
				if (a != anon_group)
				{
					anon_group = a;
					group_memoization.clear();
				}

				WriteChatf("Group Anonymization is now \ao%s\ax.", GetStringFromAnonymization(anon_group));
			}
		});

	args::Command guild(commands, "guild", "sets guild anonymization",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::AtMostOne);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (anon_type)
			{
				auto a = anon_type.Get();
				if (a != anon_guild)
				{
					anon_guild = a;
					guild_memoization.clear();
				}

				WriteChatf("Guild Anonymization is now \ao%s\ax.", GetStringFromAnonymization(anon_guild));
			}
		});

	args::Command raid(commands, "raid", "sets raid anonymization",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::AtMostOne);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (anon_type)
			{
				auto a = anon_type.Get();
				if (a != anon_raid)
				{
					anon_raid = a;
					raid_memoization.clear();
				}

				WriteChatf("Raid Anonymization is now \ao%s\ax.", GetStringFromAnonymization(anon_raid));
			}
		});

	args::Command me(commands, "me", "sets me anonymization",
		[](args::Subparser& parser) {
			args::Group command(parser, "command", args::Group::Validators::AtMostOne);

			args::Group arguments(command, "arguments", args::Group::Validators::AtMostOne);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);

			args::Group flags(command, "flags", args::Group::Validators::AtLeastOne);
			args::HelpFlag h(flags, "help", "help", { 'h', "help" });
			parser.Parse();

			if (anon_type)
			{
				auto a = anon_type.Get();
				if (a != anon_self)
				{
					anon_self = a;
					self_replacer.reset();
				}
			}
			else if (anon_self != Anonymization::Me)
			{
				anon_self = Anonymization::Me;
				self_replacer.reset();
			}

			WriteChatf("Self Anonymization is now \ao%s\ax.", GetStringFromAnonymization(anon_self));
		});

	me.RequireCommand(false);

	args::Command save(commands, "save", "saves the configuration to file, completely rewriting data",
		[](args::Subparser& parser) {
			parser.Parse();
			WriteChatf("Saving MQ2Anonymize to config.");
			Serialize();
			WriteChatf("Done.");
		});

	args::Command load(commands, "load", "loads the configuration from file, overwriting and current settings or data",
		[](args::Subparser& parser) {
			parser.Parse();
			WriteChatf("Loading MQ2Anonymize from config.");
			Deserialize();
			WriteChatf("Done.");
		});

	args::Command on(commands, "on", "turns anonymization on",
		[](args::Subparser& parser) {
			parser.Parse();
			SetAnon(true);
		});

	args::Command off(commands, "off", "turns anonymization off",
		[](args::Subparser& parser) {
			parser.Parse();
			SetAnon(false);
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
	{
		WriteChatf("Toggling anonymization state, use \ay/mqanon -h\ax for a list of commands.");
		ToggleAnon();
	}
}

void InitializeAnonymizer()
{
	EzDetour(__GetGaugeValueFromEQ, &GetGaugeValueFromEQ_Detour, &GetGaugeValueFromEQ_Trampoline);
	EzDetour(CTextureFont__DrawWrappedText, &CTextureFontHook::DrawWrappedText_Detour, &CTextureFontHook::DrawWrappedText_Trampoline);
	EzDetour(CTextureFont__DrawWrappedText1, &CTextureFontHook::DrawWrappedText1_Detour, &CTextureFontHook::DrawWrappedText1_Trampoline);
	EzDetour(CTextureFont__DrawWrappedText2, &CTextureFontHook::DrawWrappedText2_Detour, &CTextureFontHook::DrawWrappedText2_Trampoline);

	bmAnonymizer = AddMQ2Benchmark("Anonymizer");

	anon_config_path = mq::internal_paths::Config + "\\MQ2Anonymize.yaml";
	Deserialize(); // always load on initialization

	AddMQ2Data("MQAnon", dataAnon);
	AddCommand("/mqanon", MQAnon, false, false, false);
}

void ShutdownAnonymizer()
{
	RemoveCommand("/mqanon");
	RemoveMQ2Data("MQAnon");

	RemoveMQ2Benchmark(bmAnonymizer);

	RemoveDetour(__GetGaugeValueFromEQ);
	RemoveDetour(CTextureFont__DrawWrappedText);
	RemoveDetour(CTextureFont__DrawWrappedText1);
	RemoveDetour(CTextureFont__DrawWrappedText2);
}
}
