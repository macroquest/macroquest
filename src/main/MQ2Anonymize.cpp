/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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
#include "MQDataAPI.h"

#include "mq/utils/Args.h"

#include <regex>
#include <memory>
#include <Yaml.hpp>

namespace mq {

// Variables (most of it is wrapped up in the yaml node)
static std::string anon_config_path;
static Yaml::Node anon_config;
static bool anon_enabled = false;

using MQ2Args = Args<&WriteChatf>;
using MQ2HelpArgument = HelpArgument;

enum class Anonymization
{
	None,
	Asterisk,
	Class,
	Me,
	Custom
};

static std::unordered_map<std::string_view, Anonymization> anonymization_map = {
	{"none", Anonymization::None},
	{"asterisk", Anonymization::Asterisk},
	{"class", Anonymization::Class},
	{"me", Anonymization::Me},
	{"custom", Anonymization::Custom}
};

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

enum class AnonymizationClasses
{
	None,
	Group,
	Fellowship,
	Guild,
	Raid,
	Self
};

std::unordered_map<std::string_view, AnonymizationClasses> anonymization_classes_map = {
	{"none", AnonymizationClasses::None},
	{"group", AnonymizationClasses::Group},
	{"fellowship", AnonymizationClasses::Fellowship},
	{"guild", AnonymizationClasses::Guild},
	{"raid", AnonymizationClasses::Raid},
	{"self", AnonymizationClasses::Self}
};

static AnonymizationClasses GetAnonClassFromString(std::string_view anon_class)
{
	auto it = anonymization_classes_map.find(anon_class);
	if (it != anonymization_classes_map.end())
		return it->second;

	return AnonymizationClasses::None;
}

static std::string_view GetStringFromAnonClass(AnonymizationClasses anon_class)
{
	for (auto anon_type : anonymization_classes_map)
	{
		if (anon_type.second == anon_class)
			return anon_type.first;
	}

	return "none";
}

static Anonymization anon_group;
static Anonymization anon_fellowship;
static Anonymization anon_guild;
static Anonymization anon_raid;
static Anonymization anon_self;

class anon_replacer {
public:
	const std::string name;

private:
	Anonymization strategy;
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
	anon_replacer(std::string_view name, Anonymization strategy, std::string_view target = "")
		: name(name), strategy(strategy), target(target)
	{
		build_regex();
	}

	anon_replacer(Yaml::Node& node)
		: name(node["name"].As<std::string>()),
		  strategy(GetAnonymizationFromString(node["strategy"].As<std::string>())),
		  target(node["target"].As<std::string>())
	{
		if (node["alternates"].IsSequence())
		{
			for (auto alt = node["alternates"].Begin(); alt != node["alternates"].End(); alt++)
				alternates.emplace((*alt).second.As<std::string>());
		}

		build_regex();
	}

	anon_replacer(SPAWNINFO* pSpawn, Anonymization strategy, std::string_view target = "")
		: name(pSpawn->Lastname[0] ? fmt::format("{}\\s{}", pSpawn->Name, pSpawn->Lastname) : pSpawn->Name),
		  strategy(strategy),
		  target(target)
	{
		if (pSpawn->Lastname[0])
			add_alternate(pSpawn->Name);

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

	void update_strategy(Anonymization strategy)
	{
		this->strategy = strategy;
	}

	Anonymization get_strategy()
	{
		return strategy;
	}

	void update_target(std::string_view target)
	{
		this->target = target;
	}

	std::string_view get_target()
	{
		return target;
	}

	std::string anonymize() const
	{
		auto asterisk_name = [](std::string_view name)
		{
			std::string asterisk_name(name);
			for (size_t i = 1; i < asterisk_name.length() - 1; ++i)
				asterisk_name[i] = '*';
			return asterisk_name;
		};

		switch (strategy)
		{
		case Anonymization::Asterisk:
			return asterisk_name(name);

		case Anonymization::Class:
		{
			SPAWNINFO* spawn = GetSpawnByName(name.c_str());
			// If no spawn is found, check to see if we have regex whitespace in our name.  This can collide, but that's acceptable for our use case.
			if (spawn == nullptr)
			{
				int pos = find_substr(name, "\\s");
				if (pos != -1)
				{
					spawn = GetSpawnByName(name.substr(0, pos).c_str());
				}
			}
			if (spawn != nullptr)
			{
				return fmt::format("[{}] {}",
					spawn->Level,
					pEverQuest->GetClassThreeLetterCode(spawn->GetClass()));
				/*
				return fmt::format("[{}] {} {} {}",
					spawn->Level,
					pEverQuest->GetRaceDesc(spawn->GetRace()),
					GetClassDesc(spawn->GetClass()),
					GetTypeDesc(GetSpawnType(spawn)));
				*/
			}

			return asterisk_name(name);
		}

		case Anonymization::Me:
		{
			auto profile = GetPcProfile();
			if (profile)
				return fmt::format("[{}] {} {} PC",
					profile->Level,
					pEverQuest->GetRaceDesc(profile->Race),
					GetClassDesc(profile->Class));

			return asterisk_name(name);
		}

		case Anonymization::Custom:
			return ModifyMacroString(target);

		default:
			return std::string(name);
		}
	}

	std::string replace_text(std::string_view text) const
	{
		std::string result;
		std::regex_replace(std::back_inserter(result), std::cbegin(text), std::cend(text), search_string, anonymize());
		return result;
	}

	Yaml::Node Serialize()
	{
		Yaml::Node node;

		node["name"] = name;
		node["strategy"] = GetStringFromAnonymization(strategy).data();
		if (strategy == Anonymization::Custom)
			node["target"] = target;
		for (auto alt : alternates)
			node["alternates"].PushBack() = alt;

		return node;
	}
};

// the source string_view is checked _after_ string parsing
// the target string is parsed before replacement
static std::vector<std::unique_ptr<anon_replacer>> replacers;
static ci_unordered::map<std::string_view, std::unique_ptr<anon_replacer>> group_memoization;
static ci_unordered::map<std::string_view, std::unique_ptr<anon_replacer>> fellowship_memoization;
static ci_unordered::map<std::string_view, std::unique_ptr<anon_replacer>> guild_memoization;
static ci_unordered::map<std::string_view, std::unique_ptr<anon_replacer>> raid_memoization;
static std::unique_ptr<anon_replacer> self_replacer;

// the source string_view here will be used to index
// creating a regex that looks like `(source|all|the|alternates)`

// helper function to find a replacer by name
static std::vector<std::unique_ptr<anon_replacer>>::iterator FindReplacer(std::string_view Name)
{
	return std::find_if(std::begin(replacers), std::end(replacers),
		[&Name](const std::unique_ptr<anon_replacer>& r) { return r && ci_equals(Name, r->name); });
}

static void SetAnonymization(AnonymizationClasses AnonClass, Anonymization Strategy)
{
	switch (AnonClass)
	{
	case AnonymizationClasses::Group:
		if (Strategy != anon_group)
		{
			anon_group = Strategy;
			group_memoization.clear();
		}
		break;

	case AnonymizationClasses::Fellowship:
		if (Strategy != anon_fellowship)
		{
			anon_fellowship = Strategy;
			fellowship_memoization.clear();
		}
		break;

	case AnonymizationClasses::Guild:
		if (Strategy != anon_guild)
		{
			anon_guild = Strategy;
			guild_memoization.clear();
		}
		break;

	case AnonymizationClasses::Raid:
		if (Strategy != anon_raid)
		{
			anon_raid = Strategy;
			raid_memoization.clear();
		}
		break;

	case AnonymizationClasses::Self:
		if (Strategy != anon_self)
		{
			anon_self = Strategy;
			if (!self_replacer)
				self_replacer = std::make_unique<anon_replacer>(pLocalPlayer, anon_self);
			else
				self_replacer->update_strategy(Strategy);
		}
		break;

	default:
		WriteChatf("Could not find class \ag%s\ax, no anonymization change.", GetStringFromAnonClass(AnonClass).data());
		return;
	}

	WriteChatf("Updated \ag%s\ax anonymization to \ao%s\ax.", GetStringFromAnonClass(AnonClass).data(), GetStringFromAnonymization(Strategy).data());
}

// add an anonymization rule to the map -- if the rule already exists, assume we want to update the target
static void AddAnonymization(std::string_view Name, Anonymization Strategy, std::string_view Replace = "")
{
	auto replacer_it = FindReplacer(Name);

	if (replacer_it != std::end(replacers))
	{
		// just update things
		(*replacer_it)->update_strategy(Strategy);
		(*replacer_it)->update_target(Replace);
		WriteChatf("Updated anonymization \at%s\ax with \at%s\ax%s",
			Name.data(),
			GetStringFromAnonymization(Strategy).data(),
			Replace.empty() ? "." : fmt::format(" ({}).", Replace).c_str());
	}
	else
	{
		replacers.emplace_back(std::make_unique<anon_replacer>(Name, Strategy, Replace));
		WriteChatf("Added anonymization \at%s\ax with \at%s\ax%s",
			Name.data(),
			GetStringFromAnonymization(Strategy).data(),
			Replace.empty() ? "." : fmt::format(" ({}).", Replace).c_str());
	}
}

static void DropAnonymization(std::string_view Name)
{
	auto replacer_it = FindReplacer(Name);

	if (replacer_it != std::end(replacers))
	{
		replacers.erase(replacer_it);
		WriteChatf("Un-Anonymized \at%s\ax.", Name.data());
	}
	else
	{
		WriteChatf("Could not find \at%s\ax in anonymization filters, no name was removed.", Name.data());
	}
}

// will not add an entry if there is nothing available
static void AddAlternate(std::string_view Name, std::string_view Alternate)
{
	auto replacer_it = FindReplacer(Name);

	if (replacer_it != std::end(replacers))
	{
		(*replacer_it)->add_alternate(Alternate);
		WriteChatf("Added Alias \ay%s\ax to \at%s\ax.", Alternate.data(), Name.data());
	}
	else
	{
		WriteChatf("Could not find filter for \ay%s\ax, no alias added!", Name.data());
	}
}

// will not add an entry if there is nothing available
static void DropAlternate(std::string_view Name, std::string_view Alternate)
{
	auto replacer_it = FindReplacer(Name);

	if (replacer_it != std::end(replacers))
	{
		(*replacer_it)->drop_alternate(Alternate);
		WriteChatf("Dropped Alias \ay%s\ax from \at%s\ax.", Alternate.data(), Name.data());
	}
	else
	{
		WriteChatf("Could not find filter for \ay%s\ax, no alias removed!", Name.data());
	}
}

// let the user pass without a name
static void DropAlternate(std::string_view Alternate)
{
	bool changed = false;
	std::for_each(std::begin(replacers), std::end(replacers),
		[&Alternate, &changed](const std::unique_ptr<anon_replacer>& r)
		{
			if (r)
			{
				r->drop_alternate(Alternate);
				changed = true;
				WriteChatf("Dropped Alias \ay%s\ax from \at%s\ax.", Alternate.data(), r->name.c_str());
			}
		});

	if (!changed)
		WriteChatf("Could not find a filter that contains \ay%s\ax, no alias removed!", Alternate.data());
}

static void InstallAnonDetours();
static void RemoveAnonDetours();

static void SetAnon(bool anon_state)
{
	if (test_and_set(anon_enabled, anon_state))
	{
		if (anon_enabled)
			InstallAnonDetours();
		else
			RemoveAnonDetours();
	}

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
	WriteChatf("Saving MQ2Anonymize to config.");
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
	anon_config["fellowship"] = std::string(GetStringFromAnonymization(anon_fellowship));
	anon_config["guild"] = std::string(GetStringFromAnonymization(anon_guild));
	anon_config["raid"] = std::string(GetStringFromAnonymization(anon_raid));
	anon_config["self"] = std::string(GetStringFromAnonymization(anon_self));

	Yaml::Serialize(anon_config, anon_config_path.c_str());
	WriteChatf("Done.");
}

static void Deserialize()
{
	WriteChatf("Loading MQ2Anonymize from config.");
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
	anon_fellowship = GetAnonymizationFromString(anon_config["fellowship"].As<std::string>());
	anon_guild = GetAnonymizationFromString(anon_config["guild"].As<std::string>());
	anon_raid = GetAnonymizationFromString(anon_config["raid"].As<std::string>());
	anon_self = GetAnonymizationFromString(anon_config["self"].As<std::string>());

	// a load should reset all the temporary memoization (as a failsafe)
	group_memoization.clear();
	fellowship_memoization.clear();
	guild_memoization.clear();
	raid_memoization.clear();
	self_replacer.reset();
	WriteChatf("Done.");
}

bool IsAnonymized()
{
	return anon_enabled;
}


// process string to anonymize
CXStr& PluginAnonymize(CXStr& Text)
{
	if (MaybeAnonymize(Text))
		Text = Anonymize(Text);

	return Text;
}

CXStr Anonymize(const CXStr& Text)
{
	if (!MaybeAnonymize(Text))
		return Text;

	if (!pLocalPlayer || !pLocalPC)
		return Text;

	EnterMQ2Benchmark(bmAnonymizer);

	std::string new_text(Text);

	for (const auto& replacer : replacers)
	{
		if (replacer)
		{
			new_text = replacer->replace_text(new_text);
		}
	}

	if (anon_self != Anonymization::None)
	{
		if (!self_replacer || ci_find_substr(self_replacer->name, pLocalPlayer->Name) != 0)
			self_replacer = std::make_unique<anon_replacer>(pLocalPlayer, anon_self);

		new_text = self_replacer->replace_text(new_text);
	}

	if (anon_group != Anonymization::None && pLocalPC->Group)
	{
		for (const CGroupMember* pMember : *pLocalPC->Group)
		{
			if (pMember && pMember->Name[0] && ci_equals(new_text, pMember->Name, false))
			{
				auto memoized = group_memoization.find(pMember->Name);
				if (memoized == group_memoization.end())
				{
					memoized = group_memoization.emplace(
						pMember->Name, std::make_unique<anon_replacer>(pMember->Name, anon_group)).first;
				}

				new_text = memoized->second->replace_text(new_text);
			}
		}
	}

	if (anon_fellowship != Anonymization::None)
	{
		for (const SFellowshipMember& f : pLocalPlayer->Fellowship.FellowshipMember)
		{
			if (f.Name[0] && ci_equals(new_text, f.Name, false))
			{
				auto memoized = fellowship_memoization.find(f.Name);
				if (memoized == fellowship_memoization.end())
				{
					memoized = fellowship_memoization.emplace(
						f.Name, std::make_unique<anon_replacer>(f.Name, anon_fellowship)).first;
				}

				new_text = memoized->second->replace_text(new_text);
			}
		}
	}

	if (anon_guild != Anonymization::None && pGuild)
	{
		const char* guild_name = pGuild->GetGuildName(pLocalPC->GuildID);
		if (guild_name[0] != '\0' && ci_equals(new_text, guild_name, false))
		{
			auto memoized = guild_memoization.find(guild_name);
			if (memoized == guild_memoization.end())
				memoized = guild_memoization.emplace(
					guild_name,
					std::make_unique<anon_replacer>(guild_name, Anonymization::Asterisk)
				).first;

			new_text = memoized->second->replace_text(new_text);
		}

		for (GuildMember* pMember = pGuild->pFirstGuildMember; pMember; pMember = pMember->pNext)
		{
			if (pMember->Name[0] != '\0' && ci_equals(new_text, pMember->Name, false))
			{
				auto memoized = guild_memoization.find(pMember->Name);
				if (memoized == guild_memoization.end())
					memoized = guild_memoization.emplace(
						pMember->Name,
						std::make_unique<anon_replacer>(pMember->Name, anon_guild)
					).first;

				new_text = memoized->second->replace_text(new_text);
			}
		}
	}

	if (anon_raid != Anonymization::None)
	{
		for (RaidMember& pMember : pRaid->RaidMember)
		{
			if (pMember.Name[0] != '\0' && ci_equals(new_text, pMember.Name, false))
			{
				auto memoized = raid_memoization.find(pMember.Name);
				if (memoized == raid_memoization.end())
					memoized = raid_memoization.emplace(
						pMember.Name,
						std::make_unique<anon_replacer>(pMember.Name, anon_raid)
					).first;

				new_text = memoized->second->replace_text(new_text);
			}
		}
	}

	ExitMQ2Benchmark(bmAnonymizer);

	return CXStr(new_text);
}

DETOUR_TRAMPOLINE_DEF(float, GetGaugeValueFromEQ_Trampoline, (int, CXStr*, bool*, unsigned long*))
float GetGaugeValueFromEQ_Detour(int EQType, CXStr* Str, bool* arg3, unsigned long* Color)
{
	float ret = GetGaugeValueFromEQ_Trampoline(EQType, Str, arg3, Color);
	if (Str && MaybeAnonymize(*Str))
	{
		*Str = Anonymize(*Str);
	}
	return ret;
}

class CTextureFontHook
{
public:
	DETOUR_TRAMPOLINE_DEF(int, DrawWrappedText_Trampoline, (const CXStr&, int, int, int, const CXRect&, COLORREF, uint16_t, int))
	int DrawWrappedText_Detour(const CXStr& Str, int x, int y, int z, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0)
	{
		if (MaybeAnonymize(Str))
		{
			return DrawWrappedText_Trampoline(Anonymize(Str), x, y, z, BoundRect, Color, Flags, StartX);
		}

		return DrawWrappedText_Trampoline(Str, x, y, z, BoundRect, Color, Flags, StartX);
	}

	DETOUR_TRAMPOLINE_DEF(int, DrawWrappedText1_Trampoline, (const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int))
	int DrawWrappedText1_Detour(const CXStr& Str, const CXRect& Rect, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0)
	{
		if (MaybeAnonymize(Str))
		{
			return DrawWrappedText1_Trampoline(Anonymize(Str), Rect, BoundRect, Color, Flags, StartX);
		}

		return DrawWrappedText1_Trampoline(Str, Rect, BoundRect, Color, Flags, StartX);
	}

	DETOUR_TRAMPOLINE_DEF(int, DrawWrappedText2_Trampoline, (CTextObjectInterface*, const CXStr&, const CXRect&, const CXRect&, COLORREF, uint16_t, int))
	int DrawWrappedText2_Detour(CTextObjectInterface* Interface, const CXStr& Str, const CXRect& Rect, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0)
	{
		if (MaybeAnonymize(Str))
		{
			return DrawWrappedText2_Trampoline(Interface, Anonymize(Str), Rect, BoundRect, Color, Flags, StartX);
		}

		return DrawWrappedText2_Trampoline(Interface, Str, Rect, BoundRect, Color, Flags, StartX);
	}
};


// ***************************************************************************
// Function:    MQAnon
// Description: Our '/mqanon' command
//              Controls the anonymization filtering of text
// ***************************************************************************

void MQAnon(SPAWNINFO* pChar, char* szLine)
{
	if (!pChar)
		return;

	MQ2Args arg_parser("Anonymization tool: filters specific text from display output.");
	arg_parser.Prog("/mqanon");
	arg_parser.RequireCommand(false);
	args::Group commands(arg_parser, "", args::Group::Validators::AtMostOne);

	args::Command asterisk(commands, "asterisk", "add a filter to replace with asterisks",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name to anonymize");
			parser.Parse();
			if (name) AddAnonymization(name.Get(), Anonymization::Asterisk);
		});

	args::Command clas(commands, "class", "add a filter to replace by class attributes",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name to anonymize");
			parser.Parse();
			if (name) AddAnonymization(name.Get(), Anonymization::Class);
		});

	args::Command custom(commands, "custom", "add a filter to replace with custom string",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name to anonymize");
			args::PositionalList<std::string> replacers(arguments, "replacers", "the text to anonymize with");
			parser.Parse();
			if (name && replacers) AddAnonymization(name.Get(), Anonymization::Custom, join(replacers.Get(), " "));
		});

	args::Command drop(commands, "drop", "drops anonymization name from list of filtered names",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name to de-anonymize");
			parser.Parse();
			if (name) DropAnonymization(name.Get());
		});

	args::Command alias(commands, "alias", "adds an alias for a name in the list of filtered names",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::Positional<std::string> name(arguments, "name", "the name entry to alias");
			args::Positional<std::string> alias(arguments, "alias", "the alias to also search for when replacing the name");
			parser.Parse();
			if (name && alias) AddAlternate(name.Get(), alias.Get());
		});

	args::Command unalias(commands, "unalias", "drops an alias for a name in the list of filtered names",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::AtLeastOne);
			args::Positional<std::string> name(arguments, "name", "the name entry to unalias");
			args::Positional<std::string> alias(arguments, "alias", "the alias to also stop searching for when replacing the name");
			parser.Parse();
			if (name && alias) DropAlternate(name.Get(), alias.Get()); else if (name) DropAlternate(name.Get());
		});

	args::Command group(commands, "group", "sets group anonymization",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);
			parser.Parse();
			if (anon_type) SetAnonymization(AnonymizationClasses::Group, anon_type.Get());
		});

	args::Command fellowship(commands, "fellowship", "sets fellowship anonymization",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);
			parser.Parse();
			if (anon_type) SetAnonymization(AnonymizationClasses::Fellowship, anon_type.Get());
		});

	args::Command guild(commands, "guild", "sets guild anonymization",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);
			parser.Parse();
			if (anon_type) SetAnonymization(AnonymizationClasses::Guild, anon_type.Get());
		});

	args::Command raid(commands, "raid", "sets raid anonymization",
		[](args::Subparser& parser) {
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);
			parser.Parse();
			if (anon_type) SetAnonymization(AnonymizationClasses::Raid, anon_type.Get());
		});

	args::Command all(commands, "all", "sets me/group/fellowship/guild/raid anonymization in one command",
		[](args::Subparser& parser) {
			args::Group arguments(parser, "", args::Group::Validators::All);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);
			parser.Parse();
			if (anon_type)
			{
				SetAnonymization(AnonymizationClasses::Self, anon_type.Get());
				SetAnonymization(AnonymizationClasses::Group, anon_type.Get());
				SetAnonymization(AnonymizationClasses::Fellowship, anon_type.Get());
				SetAnonymization(AnonymizationClasses::Guild, anon_type.Get());
				SetAnonymization(AnonymizationClasses::Raid, anon_type.Get());
			}
		});

	args::Command me(commands, "me", "sets me anonymization",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::DontCare);
			args::MapPositional<std::string_view, Anonymization> anon_type(arguments, "anon_type", "Anonymization type", anonymization_map);
			parser.Parse();
			if (anon_type) SetAnonymization(AnonymizationClasses::Self, anon_type.Get()); else SetAnonymization(AnonymizationClasses::Self, Anonymization::Me);
		});
	me.RequireCommand(false);

	args::Command save(commands, "save", "saves the configuration to file, completely rewriting data",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::DontCare);
			parser.Parse();
			Serialize();
		});

	args::Command load(commands, "load", "loads the configuration from file, overwriting and current settings or data",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::DontCare);
			parser.Parse();
			Deserialize();
		});

	args::Command on(commands, "on", "turns anonymization on",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::DontCare);
			parser.Parse();
			SetAnon(true);
		});

	args::Command off(commands, "off", "turns anonymization off",
		[](args::Subparser& parser)
		{
			args::Group arguments(parser, "", args::Group::Validators::DontCare);
			parser.Parse();
			SetAnon(false);
		});

	MQ2HelpArgument h(commands);

	auto args = allocate_args(szLine);

	try
	{
		arg_parser.ParseArgs(args);
	}
	catch (const args::Help&)
	{
		arg_parser.Help();
	}
	catch (const args::ValidationError&)
	{
		arg_parser.Help();
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

static void InstallAnonDetours()
{
	EzDetour(__GetGaugeValueFromEQ, &GetGaugeValueFromEQ_Detour, &GetGaugeValueFromEQ_Trampoline);
	EzDetour(CTextureFont__DrawWrappedText, &CTextureFontHook::DrawWrappedText_Detour, &CTextureFontHook::DrawWrappedText_Trampoline);
	EzDetour(CTextureFont__DrawWrappedText1, &CTextureFontHook::DrawWrappedText1_Detour, &CTextureFontHook::DrawWrappedText1_Trampoline);
	EzDetour(CTextureFont__DrawWrappedText2, &CTextureFontHook::DrawWrappedText2_Detour, &CTextureFontHook::DrawWrappedText2_Trampoline);
}

static void RemoveAnonDetours()
{
	RemoveDetour(__GetGaugeValueFromEQ);
	RemoveDetour(CTextureFont__DrawWrappedText);
	RemoveDetour(CTextureFont__DrawWrappedText1);
	RemoveDetour(CTextureFont__DrawWrappedText2);
}

void InitializeAnonymizer()
{
	bmAnonymizer = AddMQ2Benchmark("Anonymizer");

	anon_config_path = mq::internal_paths::Config + "\\MQ2Anonymize.yaml";
	Deserialize(); // always load on initialization

	AddCommand("/mqanon", MQAnon, false, false, false);

	if (anon_enabled)
	{
		InstallAnonDetours();
	}
}

void ShutdownAnonymizer()
{
	if (anon_enabled)
	{
		RemoveAnonDetours();
	}

	RemoveCommand("/mqanon");

	RemoveMQ2Benchmark(bmAnonymizer);
}

} // namespace mq
