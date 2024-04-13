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

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <sol/sol.hpp>

#include <string>
#include <cctype>

namespace mq::lua::bindings {

   // Adds a space at a capital letter, or a number found in the string
   std::string formatDisplayName(const std::string& input) {
      std::string formatted;
      formatted.reserve(input.size() * 2);

      for (size_t i = 0; i < input.length(); ++i) {
         if (i > 0 && (std::isupper(input[i]) || std::isdigit(input[i]))) {
            formatted += ' ';
         }
         formatted += input[i];
      }
      return formatted;
   }

//============================================================================

   const char* szAnimations[] = {
      #include "eqdata/animations.h"
      nullptr
   }

   const char* szBodyTypes[] = {
      #include "eqdata/bodyTypes.h"
      nullptr
   }

   const char* szDieties[] = {
      #include "eqdata/dieties.h"
      nullptr
   }

   const char* szSpawnTypes[] = {
      #include "eqdata/spawnTypes.h"
      nullptr
   }

   void RegisterBindings_Constants(sol::state_view lua) {

      lua.create_named_table("Animations");
      for (int i = 0; szAnimations[i] != nullptr; ++i) {
        if (szAnimations[i] != nullptr) {
            lua["Animations"][szAnimations[i]] = i + 1;
      }
    
      lua.create_named_table("BodyTypes");
      for (int i = 0; szBodyTypes[i] != nullptr; ++i) {
         std::string key = szBodyTypes[i];
         std::string value = formatDisplayName(key);
         lua["BodyTypes"][key] = value;
      }

      lua.create_named_table("DietyNames");
      for (int i = 0; szDeityNames[i] != nullptr; ++i) {
         std::string key = szDeityNames[i];
         std::string value = formatDisplayName(key);
         lua["DietyNames"][key] = value;
      }
      
      lua.create_named_table("EquipmentSlots");
      for (int i = 0; szEquipmentSlots[i] != nullptr; ++i) {
         std::string key = szEquipmentSlots[i];
         std::string value = formatDisplayName(key);
         lua["EquipmentSlots"][key] = value;
      }
      
      lua.create_named_table("Gender");
      for (int i = 0; szGender[i] != nullptr; ++i) {
         std::string key = std::toupper(szGender[i][0]);
         std::string value = (std::transform(key.begin(), key.end(), key.begin(), ::toupper));
         lua["Gender"][key] = value;

      lua.create_named_table("SpawnTypes");
      for (int i = 0; szSpawnTypes[i] != nullptr; ++i) {
         std::string key = szSpawnTYpes[i];
         lua["SpawnTypes"][key] = key;
      }
    
   }
}
