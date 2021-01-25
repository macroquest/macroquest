/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

#include "HotKeys.h"

#include <fmt/format.h>
#include <Windows.h>

#define HOTKEYF_SHIFT           0x01
#define HOTKEYF_CONTROL         0x02
#define HOTKEYF_ALT             0x04

namespace mq {

bool ConvertStringToModifiersAndVirtualKey(const std::string& str, uint16_t& modkey, uint16_t& virtualKey)
{
	std::string input = str;
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);

	modkey = 0;
	virtualKey = 0;
	size_t pos;

	pos = input.find("ALT+");
	if (pos != std::string::npos)
	{
		modkey |= PlatformHotkey::Alt;
		input.replace(pos, 4, "");
	}

	pos = input.find("CTRL+");
	if (pos != std::string::npos)
	{
		modkey |= PlatformHotkey::Ctrl;
		input.replace(pos, 5, "");
	}

	pos = input.find("SHIFT+");
	if (pos != std::string::npos)
	{
		modkey |= PlatformHotkey::Shift;
		input.replace(pos, 6, "");
	}

	pos = input.find("WIN+");
	if (pos != std::string::npos)
	{
		modkey |= PlatformHotkey::Win;
		input.replace(pos, 4, "");
	}

	switch (input.length())
	{
	case 1: {
		char c = input[0];
		switch (c)
		{
		case ';':
		case ':':
			virtualKey = VK_OEM_1;
			return true;
		case '/':
		case '?':
			virtualKey = VK_OEM_2;
			return true;
		case '`':
		case '~':
			virtualKey = VK_OEM_3;
			return true;
		case '{':
		case '[':
			virtualKey = VK_OEM_4;
			return true;
		case '\\':
		case '|':
			virtualKey = VK_OEM_5;
			return true;
		case '}':
		case ']':
			virtualKey = VK_OEM_6;
			return true;
		case '\'':
		case '\"':
			virtualKey = VK_OEM_7;
			return true;
		case '+':
		case '=':
			virtualKey = VK_OEM_PLUS;
			return true;
		case '-':
		case '_':
			virtualKey = VK_OEM_MINUS;
			return true;
		case '.':
		case '>':
			virtualKey = VK_OEM_PERIOD;
			return true;
		case ',':
		case '<':
			virtualKey = VK_OEM_COMMA;
			return true;

		default:
			if (!::isdigit(c) && !::isalpha(c))
				return false;
			virtualKey = c;
			return true;
		}

		break;
	}
	case 2:
	case 3: {
		int c = input[0];
		if (c != 'F')
			break;
		int i = 0;
		while (input[i + 1] != 0)
		{
			if (!::isdigit(input[i + 1]))
				return false;
			i++;
		}
		int val = atoi(&input[1]);
		if (val <= 0 || val > 24)
			return false;
		virtualKey = VK_F1 + val - 1;
		return true;
	}
	case 5:
	case 6:
		break;
	case 4:
	case 7:
		if ((input.length() == 7 && input.find("NUMPAD") == 0)
			|| input.length() == 4 && input.find("NUM") == 0)
		{
			char c = input[input.length() - 1];
			switch (c)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				virtualKey = VK_NUMPAD0 + c - '0';
				return true;
			case '+':
				virtualKey = VK_ADD;
				return true;
			case '-':
				virtualKey = VK_SUBTRACT;
				return true;
			case '*':
				virtualKey = VK_MULTIPLY;
				return true;
			case '/':
				virtualKey = VK_DIVIDE;
				return true;
			case '.':
				virtualKey = VK_DECIMAL;
				return true;
			}

			break;
		}
	}

	// misc
	if (input.length() > 1)
	{
		switch (input[0])
		{
		case 'D':
			if (input == "DELETE")
				virtualKey = VK_DELETE;
			else if (input == "DOWN")
				virtualKey = VK_DOWN;
			break;

		case 'E':
			if (input == "END")
				virtualKey = VK_END;
			else if (input == "ESCAPE")
				virtualKey = VK_ESCAPE;
			break;

		case 'H':
			if (input == "HOME")
				virtualKey = VK_HOME;
			break;

		case 'I':
			if (input == "INSERT")
				virtualKey = VK_INSERT;
			break;

		case 'L':
			if (input == "LEFT")
				virtualKey = VK_LEFT;
			break;

		case 'N':
			if (input == "NUMLOCK")
				virtualKey = VK_NUMLOCK;
			break;

		case 'P':
			if (input == "PAGEUP")
				virtualKey = VK_PRIOR;
			else if (input == "PAGEDOWN")
				virtualKey = VK_NEXT;
			break;

		case 'R':
			if (input == "RETURN")
				virtualKey = VK_RETURN;
			else if (input == "RIGHT")
				virtualKey = VK_RIGHT;
			break;

		case 'S':
			if (input == "SPACE")
				virtualKey = VK_SPACE;
			break;

		case 'U':
			if (input == "UP")
				virtualKey = VK_UP;
			break;

		default: break;
		}
	}

	return virtualKey != 0;
}

inline bool IsKeyPressed(int vKey)
{
	return (::GetKeyState(vKey) & 0x8000) != 0;
}

bool IsHotKeyModifiersPressed(const PlatformHotkey& hotkey)
{
	bool pressed = true;

	if (hotkey.modifiers & PlatformHotkey::Alt)
	{
		if (!IsKeyPressed(VK_MENU))
			return false;
	}

	if (hotkey.modifiers & PlatformHotkey::Ctrl)
	{
		if (!IsKeyPressed(VK_CONTROL))
			return false;
	}

	if (hotkey.modifiers & PlatformHotkey::Shift)
	{
		if (!IsKeyPressed(VK_SHIFT))
			return false;
	}

	if (hotkey.modifiers & PlatformHotkey::Win)
	{
		if (!IsKeyPressed(VK_LWIN) && !IsKeyPressed(VK_RWIN))
		{
			return false;
		}
	}

	return true;
}

// Get the name of the key by virtual key using our own code
const char* GetKeyNameFromVirtualKey(uint16_t virtualKey)
{
	switch (virtualKey)
	{
		// numeric
	case '0': return "0";
	case '1': return "1";
	case '2': return "2";
	case '3': return "3";
	case '4': return "4";
	case '5': return "5";
	case '6': return "6";
	case '7': return "7";
	case '8': return "8";
	case '9': return "9";

		// alpha
	case 'A': return "A";
	case 'B': return "B";
	case 'C': return "C";
	case 'D': return "D";
	case 'E': return "E";
	case 'F': return "F";
	case 'G': return "G";
	case 'H': return "H";
	case 'I': return "I";
	case 'J': return "J";
	case 'K': return "K";
	case 'L': return "L";
	case 'M': return "M";
	case 'N': return "N";
	case 'O': return "O";
	case 'P': return "P";
	case 'Q': return "Q";
	case 'R': return "R";
	case 'S': return "S";
	case 'T': return "T";
	case 'U': return "U";
	case 'V': return "B";
	case 'W': return "W";
	case 'X': return "X";
	case 'Y': return "Y";
	case 'Z': return "Z";

		// numpad
	case VK_NUMPAD0: return "NUMPAD0";
	case VK_NUMPAD1: return "NUMPAD1";
	case VK_NUMPAD2: return "NUMPAD2";
	case VK_NUMPAD3: return "NUMPAD3";
	case VK_NUMPAD4: return "NUMPAD4";
	case VK_NUMPAD5: return "NUMPAD5";
	case VK_NUMPAD6: return "NUMPAD6";
	case VK_NUMPAD7: return "NUMPAD7";
	case VK_NUMPAD8: return "NUMPAD8";
	case VK_NUMPAD9: return "NUMPAD9";
	case VK_DIVIDE: return "NUMPAD/";
	case VK_MULTIPLY: return "NUMPAD*";
	case VK_SUBTRACT: return "NUMPAD-";
	case VK_ADD: return "NUMPAD+";
	case VK_DECIMAL: return "NUMPAD.";

		// misc
	case VK_SPACE: return "SPACE";
	case VK_HOME: return "HOME";
	case VK_END: return "END";
	case VK_LEFT: return "LEFT";
	case VK_RIGHT: return "RIGHT";
	case VK_UP: return "UP";
	case VK_DOWN: return "DOWN";
	case VK_INSERT: return "INSERT";
	case VK_DELETE: return "DELETE";
	case VK_NUMLOCK: return "NUMLOCK";
	case VK_RETURN: return "RETURN";
	case VK_ESCAPE: return "ESCAPE";
	case VK_PRIOR: return "PAGEUP";
	case VK_NEXT: return "PAGEDOWN";

		// function keys
	case VK_F1: return "F1";
	case VK_F2: return "F2";
	case VK_F3: return "F3";
	case VK_F4: return "F4";
	case VK_F5: return "F5";
	case VK_F6: return "F6";
	case VK_F7: return "F7";
	case VK_F8: return "F8";
	case VK_F9: return "F9";
	case VK_F10: return "F10";
	case VK_F11: return "F11";
	case VK_F12: return "F12";
	case VK_F13: return "F13";
	case VK_F14: return "F14";
	case VK_F15: return "F15";
	case VK_F16: return "F16";
	case VK_F17: return "F17";
	case VK_F18: return "F18";
	case VK_F19: return "F19";
	case VK_F20: return "F20";
	case VK_F21: return "F21";
	case VK_F22: return "F22";
	case VK_F23: return "F23";
	case VK_F24: return "F24";

		// symbols
	case VK_OEM_1: return ";";
	case VK_OEM_2: return "/";
	case VK_OEM_3: return "`";
	case VK_OEM_4: return "[";
	case VK_OEM_5: return "\\";
	case VK_OEM_6: return "]";
	case VK_OEM_7: return "\'";
	case VK_OEM_PLUS: return "=";
	case VK_OEM_MINUS: return "-";
	case VK_OEM_PERIOD: return ".";
	case VK_OEM_COMMA: return ",";

	default: break;
	}

	return nullptr;
}

void GetModifiersName(uint16_t modifiers, char* szTemp, size_t length)
{
	if (modifiers & MOD_CONTROL)
		strcat_s(szTemp, length, "CTRL");
	if (modifiers & MOD_SHIFT)
		strcat_s(szTemp, length, szTemp[0] ? "+SHIFT" : "SHIFT");
	if (modifiers & MOD_ALT)
		strcat_s(szTemp, length, szTemp[0] ? "+ALT" : "ALT");
	if (modifiers & MOD_WIN)
		strcat_s(szTemp, length, szTemp[0] ? "+WIN" : "WIN");
}

// Get the name of the modifiers
std::string GetModifiersName(uint16_t modifiers)
{
	char szTemp[64] = { 0 };
	GetModifiersName(modifiers, szTemp, 64);
	return szTemp;
}


// Convert modifiers used by Hotkey control to modifiers
// used by RegisterHotKey
uint16_t ConvertHotKeyModifiersFromControl(uint16_t inModifiers)
{
	uint16_t outModifiers = 0;

	if (inModifiers & HOTKEYF_ALT)
		outModifiers |= MOD_ALT;
	if (inModifiers & HOTKEYF_CONTROL)
		outModifiers |= MOD_CONTROL;
	if (inModifiers & HOTKEYF_SHIFT)
		outModifiers |= MOD_SHIFT;

	return outModifiers;
}

// Convert modifiers used by RegisterHotKey to those used by
// the hotkey control.
uint16_t ConvertHotKeyModifiersToControl(uint16_t inModifiers)
{
	uint16_t outModifiers = 0;

	if (inModifiers & MOD_ALT)
		outModifiers |= HOTKEYF_ALT;
	if (inModifiers & MOD_CONTROL)
		outModifiers |= HOTKEYF_CONTROL;
	if (inModifiers & MOD_SHIFT)
		outModifiers |= HOTKEYF_SHIFT;

	return outModifiers;
}

bool ConvertModifiersAndVirtualKeyToString(uint16_t modkey, uint16_t virtualKey, std::string& str)
{
	const char* key = GetKeyNameFromVirtualKey(virtualKey);

	if (!key)
		return false;

	std::string modifiers = GetModifiersName(modkey);

	if (!modifiers.empty())
		str = fmt::format("{}+{}", modifiers, key);
	else
		str = key;
	return true;
}

// Convert data from hotkey control into a string
std::string GetKeyNameFromHotKeyControl(uint32_t hotkey)
{
	uint8_t vKey = LOBYTE(hotkey);
	uint8_t mod = HIBYTE(hotkey);

	std::string modifiers = GetModifiersName(ConvertHotKeyModifiersFromControl(mod));
	const char* key = nullptr;

	if (vKey)
	{
		key = GetKeyNameFromVirtualKey(vKey);
	}

	if (!modifiers.empty() && key)
		return fmt::format("{}+{}", modifiers, key);
	if (!modifiers.empty())
		return modifiers;
	if (key)
		return key;

	return "";
}

} // namespace mq
