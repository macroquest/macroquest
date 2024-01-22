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

#include "MacroQuest.h"
#include "resource.h"
#include "HotKeyControl.h"

#include "login/Login.h"
#include "routing/PostOffice.h"

#include "ImGui.h"

#include <commdlg.h>
#include <shellapi.h>

#include <wil/resource.h>
#include <filesystem>
#include <sstream>
#include <regex> // TODO: remove this and store account/server/char as separate fields in the profile struct
#include <spdlog/spdlog.h>

#include <fmt/format.h>

#include "imgui/ImGuiFileDialog.h"
#include "imgui/misc/cpp/imgui_stdlib.h"
#include "imgui_internal.h"

namespace fs = std::filesystem;

struct ProfileInfo
{
	std::string profileName;
	std::string CharacterName;
	std::string Inifile;
	std::string Hotkey;
	std::string PlayerClass;
	bool Loaded = false;
	DWORD PID = 0;
	DWORD PlayerLevel = 0;
};

struct RawProfileRecord
{
	std::string profileName;
	std::string serverName;
	std::string characterName;

	std::string eqPath;
	std::string encryptedBlob;
	bool checked;
};

struct ExportEntry
{
	std::string profileKey;
	std::string profile;
	std::string keyName;
	std::string eqPath;
	bool checked;
	std::string blob;

};

using ProfileMap = std::map<DWORD, ProfileInfo>;
using ProfileSetMap = std::map<std::string, ProfileMap>;

ProfileSetMap LoginMap;

// profile editor dialog controls
HWND hEditProfileWnd;
HWND hProfileEdit;
HWND hLoginEdit;
HWND hPassEdit;
HWND hServerEdit;
HWND hCharEdit;
HWND hPathEdit;
HWND hSaveProfileButton;
HWND hBrowseButton;
HWND hClassCombo;
HWND hLevelEdit;
CHotKeyCtrl* pHotKeyCtrl = nullptr;

// import/export dialog controls
HWND hAskPassWnd;
HWND hAskPassEdit;

// The edit popup menu
HMENU hEditPopup;

bool bNewProfile = false;

const char* PROFILE_LOAD_ALL = "Load All";
const char* PROFILE_UNLOAD_ALL = "Unload All";

int BlobToStr(DATA_BLOB* Blob, std::string& szOut);
int StrToBlob(const std::string& szIn, DATA_BLOB* BlobOut);
bool EncryptData(DATA_BLOB* DataIn, DATA_BLOB* DataOut);
bool DecryptData(DATA_BLOB* DataIn, DATA_BLOB* DataOut);

int gMenuItemCount = 0;
HMENU hProfilesMenu = nullptr;

struct LoginInstance
{
	mutable unsigned long PID;

	std::string Server;
	std::string Character;

	mutable std::optional<std::string> ProfileGroup;
	mutable std::optional<std::string> EQPath;
	mutable std::optional<std::string> Hotkey;

	bool operator==(const LoginInstance& other) const
	{
		return ci_equals(Server, other.Server) && ci_equals(Character, other.Character);
	}

	// hash function, based on server and character
	size_t operator()(const LoginInstance& instance) const
	{
		return std::hash<std::string>()(instance.Server) ^ std::hash<std::string>()(instance.Character);
	}
};

// set of loaded instances
static std::unordered_set<LoginInstance, LoginInstance> s_loadedInstances;

postoffice::Dropbox s_dropbox;

static ImGuiFileDialog* s_eqDirDialog = nullptr;

namespace internal_paths
{
	std::string AutoLoginIni;
	std::string EQRoot;
}

// need a map of shortname to name (TODO: Use long names in the display)
// order matters here in the logic, so we need to make sure these are in the same order as MQ2
struct SClassInfo
{
	const char* Name;
	const char* UCShortName;
};

static SClassInfo ClassInfo[] =
{
	{ "",             ""    },
	{ "Warrior",      "WAR" },
	{ "Cleric",       "CLR" },
	{ "Paladin",      "PAL" },
	{ "Ranger",       "RNG" },
	{ "Shadowknight", "SHD" },
	{ "Druid",        "DRU" },
	{ "Monk",         "MNK" },
	{ "Bard",         "BRD" },
	{ "Rogue",        "ROG" },
	{ "Shaman",       "SHM" },
	{ "Necromancer",  "NEC" },
	{ "Wizard",       "WIZ" },
	{ "Mage",         "MAG" },
	{ "Enchanter",    "ENC" },
	{ "Beastlord",    "BST" },
	{ "Berserker",    "BER" },
};

const char* GetClassShortName(DWORD playerclass)
{
	return ClassInfo[playerclass].UCShortName;
}

void SelectCharacterClass(const std::string& cclass)
{
	int index = 0;

	// get the index
	for (size_t i = 0; i < lengthof(ClassInfo); ++i)
	{
		if (ci_equals(ClassInfo[i].UCShortName, cclass))
		{
			index = (int)i;
			break;
		}
	}

	// Select combo box by the class index
	int numItems = (int)::SendMessageA(hClassCombo, CB_GETCOUNT, 0, 0);
	for (int i = 0; i < numItems; ++i)
	{
		int id = (int)::SendMessageA(hClassCombo, CB_GETITEMDATA, i, 0);
		if (id == index)
		{
			::SendMessageA(hClassCombo, CB_SETCURSEL, i, 0);
		}
	}
}

std::string GetSelectedCharacterClass()
{
	int index = (int)::SendMessageA(hClassCombo, CB_GETCURSEL, 0, 0);
	if (index != 0)
	{
		size_t id = (int)::SendMessageA(hClassCombo, CB_GETITEMDATA, index, 0);
		if (id >= 0 && id < lengthof(ClassInfo))
		{
			return ClassInfo[id].UCShortName;
		}
	}

	return {};
}

const char* GetValue(const char* instr, const char* iniKey, std::string& out)
{
	size_t len = strlen(iniKey);
	if (const char* pDest = strstr(instr, iniKey))
	{
		instr += len;
		if (pDest = strchr(instr, '\n'))
		{
			out = { instr, (size_t)(pDest - instr) };
			instr += out.size();
			if (instr[0] == '\n')
				instr++;
			return instr;
		}
	}
	return nullptr;
}

int GetUnmaskedMenuId(int wParam)
{
	int menuId = wParam;

	if (wParam >= ID_MENU_PROFILE && wParam < ID_MENU_PROFILE + 1000)
		menuId = ID_MENU_PROFILE;
	else if (wParam >= ID_MENU_CHARACTER && wParam < ID_MENU_CHARACTER + 1000)
		menuId = ID_MENU_CHARACTER;
	else if (wParam >= ID_CHARACTER_EDIT && wParam <= ID_CHARACTER_TOGGLE)
		menuId = ID_CHARACTER_EDIT;

	return menuId;
}

std::string ReadEncryptedFile(const std::string& filename, const std::string& password)
{
	// Derived from example code found at:
	// https://docs.microsoft.com/en-us/windows/win32/seccrypto/example-c-program-decrypting-a-file

	if (password.empty())
		return {};

	// Get handle to crypto provider
	wil::unique_hcryptprov hCryptProv;
	if (!CryptAcquireContext(&hCryptProv, nullptr, MS_ENHANCED_PROV, PROV_RSA_FULL, 0))
	{
		if (!CryptAcquireContext(&hCryptProv, nullptr, MS_ENHANCED_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
		{
			DWORD lasterr = GetLastError();

			// FIXME: Logging instead
			char szErr[MAX_STRING] = { 0 };
			if (lasterr == NTE_BAD_KEYSET)
			{
				strcpy_s(szErr, "CryptAcquireContext: Access denied");
			}
			else
			{
				sprintf_s(szErr, "CryptAcquireContext returned: %x", lasterr);
			}
			MessageBox(nullptr, szErr, "Unexpected Error", MB_SYSTEMMODAL | MB_OK);
		}
	}

	wil::unique_hcrypthash hHash;
	if (!CryptCreateHash(hCryptProv.get(), CALG_MD5, 0, 0, &hHash))
		return {};

	char passwordBuffer[MAX_STRING];
	strcpy_s(passwordBuffer, password.c_str());

	if (!CryptHashData(hHash.get(), (uint8_t*)passwordBuffer, (DWORD)strlen(passwordBuffer), 0))
		return {};

	wil::unique_hcryptkey hKey;
	if (!CryptDeriveKey(hCryptProv.get(), ENCRYPT_ALGORITHM, hHash.get(), KEYLENGTH, &hKey))
		return {};

	// Open the source file
	wil::unique_hfile hSourceFile(
		::CreateFileA(filename.c_str(), FILE_READ_DATA, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr));
	if (!hSourceFile.is_valid())
		return {};

	//----------------------------------------------------------------------------
	// The decryption key is now available, either having been imported from a BLOB
	// read in from the source file or having been created by using the password.
	// This point in the program is not reached if the decryption key is not available.

	DWORD dwBlockLen = 1000 - 1000 % ENCRYPT_BLOCK_SIZE;
	DWORD dwBufferLen = dwBlockLen;

	// Allocate memory for the file read buffer.
	std::unique_ptr<uint8_t[]> pbBuffer = std::make_unique<uint8_t[]>(dwBufferLen);
	std::string outString;

	// Decrypt the source file, and write to the buffer.
	bool bEOF = false;
	do
	{
		DWORD dwCount = 0;

		// Read up to dwBlockLen bytes from the source file.
		if (!::ReadFile(hSourceFile.get(), pbBuffer.get(), dwBlockLen, &dwCount, nullptr))
		{
			// FIXME: Report error, do something better
			return {};
		}

		if (dwCount < dwBlockLen)
		{
			bEOF = true;
		}

		// Decrypt the block of data
		if (!CryptDecrypt(hKey.get(), 0, bEOF, 0, pbBuffer.get(), &dwCount))
		{
			// FIXME: Report error, do something better
			return {};
		}

		outString.append(reinterpret_cast<const char*>(pbBuffer.get()), dwCount);

	} while (!bEOF);

	return outString;
}

bool SaveBlob(const std::string& Profile, const std::string& Login, const std::string& Pass, const std::string& Server, const std::string& CharName,
	const std::string& Path, const std::string& Hotkey, const std::string& CharClass, const int CharLevel, bool Checked, const std::string& lpINIPath);
void FillProfile(const std::string& Profile, const std::string& Server, const std::string& Character, const std::string& Inifile, const std::string& Hotkey,
	const std::string& CharClass, const int CharLevel, bool bCheck, const std::string& Login);

void DoImport(const std::string& password)
{
	if (password.empty())
		return;

	// Ask user for a path to read the import from
	char Currdir[_MAX_PATH] = { 0 };
	GetCurrentDirectory(_MAX_PATH, Currdir);
	strcat_s(Currdir, "\\config");
	char filename[_MAX_PATH] = { "MQ2AutoLogin.mpd" };

	OPENFILENAMEA ofn = { sizeof(OPENFILENAMEA) };
	ofn.hwndOwner = hAskPassWnd;
	ofn.lpstrFilter = "MQ2AutoLogin Profiles Data\0*.mpd;*.dat\0Any File\0*.*\0";
	ofn.lpstrFile = filename;
	ofn.lpstrInitialDir = Currdir;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "Select the file you would like to import autologin profiles from.";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

	if (!::GetOpenFileNameA(&ofn))
		return;

	std::string decryptedFile = ReadEncryptedFile(filename, password);

	if (decryptedFile.empty())
	{
		// FIXME: Report an error
		return;
	}

	// Select output file
	char szIniPath[MAX_PATH] = { 0 };
	strcpy_s(szIniPath, internal_paths::AutoLoginIni.c_str());
	ofn.hwndOwner = hAskPassWnd;
	ofn.lpstrFilter = "Ini Files\0*.ini\0Any File\0*.*\0";
	ofn.lpstrFile = &szIniPath[0];
	ofn.lpstrInitialDir = Currdir;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "Select the file you would like to save the imported autologin profiles to.";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

	if (!GetSaveFileName(&ofn))
	{
		MessageBox(hAskPassWnd, "You need to select a valid output file.", "Import Canceled.", MB_OK | MB_SYSTEMMODAL);
	}

	// Hide the password prompt dialog because why not.
	ShowWindow(hAskPassWnd, SW_HIDE);

	const char* szBuffer = &decryptedFile[0];

	while (szBuffer[0] != 0)
	{
		szBuffer += 4;
		std::string ProfileNum;
		szBuffer = GetValue(szBuffer, "ProfileNum=", ProfileNum);
		std::string Blob;
		szBuffer = GetValue(szBuffer, "Blob=", Blob);
		std::string Checked;
		szBuffer = GetValue(szBuffer, "Checked=", Checked);
		std::string Key;
		szBuffer = GetValue(szBuffer, "Key=", Key);
		std::string Path;
		szBuffer = GetValue(szBuffer, "Path=", Path);
		std::string szProfileSection;
		szBuffer = GetValue(szBuffer, "szProfileSection=", szProfileSection);

		std::string profile = szProfileSection;

		std::string server = Key;
		int pos = (int)server.find(":");
		if (pos != std::string::npos)
		{
			server = server.substr(0, pos);
		}

		std::string path = Path;

		std::vector<std::string> data = split(Blob, ':');
		std::string login;
		std::string charName;
		std::string pass;
		std::string hotkey;
		int characterLevel = 0;
		std::string characterClass;

		switch (data.size())
		{
		default:
		case 6:
			characterLevel = atoi(data[5].c_str());
			// fallthrough
		case 5:
			characterClass = data[4];
			// fallthrough
		case 4:
			hotkey = data[3];
			// fallthrough
		case 3:
			pass = data[2];
			// fallthrough
		case 2:
			charName = data[1];
			// fallthrough
		case 1:
			login = data[0];
			// fallthrough
		case 0:
			break;
		}

		bool bCheck = (Checked == "1");

		if (SaveBlob(profile, login, pass, server, charName, path, hotkey, characterClass, characterLevel, bCheck, szIniPath))
		{
			std::string newChar = fmt::format("{}->{}", server, charName);

			FillProfile(profile, server, newChar, szIniPath, hotkey, characterClass, characterLevel, bCheck, login);

			WritePrivateProfileBool("Settings", "UseMQ2Login", true, szIniPath);
			WritePrivateProfileString("Profiles", "DefaultEQPath", path, szIniPath);
		}
	}

	char szMessage[MAX_STRING] = { 0 };
	sprintf_s(szMessage, "The Import was Successful.\nYou can find your new profiles in:\n%s", szIniPath);
	MessageBox(hAskPassWnd, szMessage, "AutoLogin Profile Import/Export", MB_OK | MB_SYSTEMMODAL);
}

void ShowImportDialog()
{
	ShowWindow(hAskPassWnd, SW_SHOW);
}

bool WriteToFileEncrypted(const std::string& data, const std::string& filename, const std::string& password)
{
	//----------------------------------------------------------------------------
	// loosely based on example code from microsoft:
	// https://docs.microsoft.com/en-us/windows/win32/seccrypto/example-c-program-encrypting-a-file

	if (password.empty() || filename.empty() || data.empty())
		return false;

	// Get handle to crypto provider.
	wil::unique_hcryptprov hCryptProv;
	if (!CryptAcquireContext(&hCryptProv, nullptr, MS_ENHANCED_PROV, PROV_RSA_FULL, 0))
	{
		if (!CryptAcquireContext(&hCryptProv, nullptr, MS_ENHANCED_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
		{
			char szMessage[MAX_STRING] = { 0 };
			auto lasterr = GetLastError();
			if (lasterr == NTE_BAD_KEYSET)
			{
				strcpy_s(szMessage, "CryptAcquireContext: Access denied");
			}
			else
			{
				sprintf_s(szMessage, "CryptAcquireContext returned: %x", lasterr);
			}

			MessageBox(hAskPassWnd, szMessage, "Unexpected Error", MB_OK | MB_SYSTEMMODAL);

			return false;
		}
	}

	wil::unique_hcrypthash hHash;
	if (!CryptCreateHash(hCryptProv.get(), CALG_MD5, 0, 0, &hHash))
		return false;

	char passwordBuffer[MAX_STRING];
	strcpy_s(passwordBuffer, password.c_str());

	if (!CryptHashData(hHash.get(), (uint8_t*)passwordBuffer, (DWORD)strlen(passwordBuffer), 0))
		return false;

	wil::unique_hcryptkey hKey;
	if (!CryptDeriveKey(hCryptProv.get(), ENCRYPT_ALGORITHM, hHash.get(), KEYLENGTH, &hKey))
		return false;

	// open the destination file
	wil::unique_hfile hDestinationFile(
		::CreateFileA(filename.c_str(), FILE_WRITE_DATA, FILE_SHARE_READ, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr));
	if (!hDestinationFile.is_valid())
		return false;

	size_t dwBlockSize = 1000 - 1000 % ENCRYPT_BLOCK_SIZE;
	size_t dwBufferLen = dwBlockSize + ((ENCRYPT_BLOCK_SIZE > 1) ? ENCRYPT_BLOCK_SIZE : 0);

	// Allocate memory for the file write buffer
	std::unique_ptr<uint8_t[]> pbBuffer = std::make_unique<uint8_t[]>(dwBufferLen);

	bool bEOF = false;
	const uint8_t* pbSource = reinterpret_cast<const uint8_t*>(data.c_str());
	size_t dwSourceLen = data.size();
	size_t dwCount = 0;

	do
	{
		size_t dwCount = std::min(dwSourceLen, dwBlockSize);

		// move data to the buffer.
		memcpy_s(pbBuffer.get(), dwBufferLen, pbSource, dwCount);

		dwSourceLen -= dwCount;
		pbSource += dwCount;
		bEOF = !(dwSourceLen > 0);

		if (!::CryptEncrypt(hKey.get(), 0, bEOF, 0, pbBuffer.get(), (DWORD*)&dwCount, (DWORD)dwBufferLen))
		{
			return false;
		}

		if (!::WriteFile(hDestinationFile.get(), pbBuffer.get(), (DWORD)dwCount, (DWORD*)&dwCount, nullptr))
		{
			return false;
		}
	} while (!bEOF);

	return true;
}

void DoExport(const std::string& password)
{
	if (password.empty())
		return;

	// Ask user for a path to store the export at
	char Currdir[_MAX_PATH] = { 0 };
	GetCurrentDirectory(_MAX_PATH, Currdir);
	strcat_s(Currdir, "\\config");
	char filename[_MAX_PATH] = { "MQ2AutoLogin.mpd" };

	OPENFILENAMEA ofn = { sizeof(OPENFILENAMEA) };
	ofn.hwndOwner = hAskPassWnd;
	ofn.lpstrFilter = "MQ2AutoLogin Profiles Data\0*.mpd;*.dat\0Any File\0*.*\0";
	ofn.lpstrFile = filename;
	ofn.lpstrInitialDir = Currdir;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "Select a file you would like to save the exported autologin profiles to.";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

	if (!::GetSaveFileNameA(&ofn))
	{
		MessageBox(hAskPassWnd, "Profile Export was canceled.", "AutoLogin Profile Import/Export", MB_OK | MB_SYSTEMMODAL);
		return;
	}

	std::vector<ExportEntry> ExportList;
	std::error_code ec;

	if (fs::exists(internal_paths::AutoLoginIni, ec))
	{
		int NumProfiles = GetPrivateProfileInt("Profiles", "NumProfiles", 0, internal_paths::AutoLoginIni);
		for (int i = 0; i < NumProfiles; i++)
		{
			std::string profileKey = fmt::format("Profile{:d}", i + 1);
			std::string sectionName = GetPrivateProfileString("Profiles", profileKey, "", internal_paths::AutoLoginIni);
			if (sectionName.empty())
				continue;

			// Get the EQPath saved for this profile
			std::string eqPath = GetPrivateProfileString(sectionName, "EQPath", "", internal_paths::AutoLoginIni);

			// Get list of keys for this profile
			std::vector<std::string> keyNames = GetPrivateProfileKeys(sectionName, internal_paths::AutoLoginIni);
			for (const auto& keyName : keyNames)
			{
				// FIXME: Use RawProfileRecord & ReadBlob
				// FIXME: Also, why are we loading from ini every time we want to do something???
				if (keyName.find("_Blob") == std::string::npos)
					continue;

				std::string blob = GetPrivateProfileString(sectionName, keyName, "", internal_paths::AutoLoginIni);
				if (blob.empty())
					continue;

				// the blob has an =0 or =1 appended at the end.
				bool checked = true;
				size_t pos = blob.find("=");
				if (pos != std::string::npos)
				{
					checked = blob.substr(pos + 1) != "0";
					blob = blob.substr(0, pos);
				}

				DATA_BLOB DataIn;
				StrToBlob(blob.c_str(), &DataIn);

				DATA_BLOB DataOut;
				if (DecryptData(&DataIn, &DataOut))
				{
					// we should parse out Login, CharName, Pass
					ExportEntry ee;
					ee.profile = sectionName;
					ee.eqPath = eqPath;
					ee.checked = checked;
					ee.blob = (char*)DataOut.pbData;
					ee.keyName = keyName;
					ee.profileKey = profileKey;
					ExportList.push_back(ee);

					LocalFree(DataOut.pbData);
				}

				LocalFree(DataIn.pbData);
			}
		}
	}

	std::string contents;

	for (size_t i = 0; i < ExportList.size(); ++i)
	{
		ExportEntry& ee = ExportList[i];

		std::string entry = fmt::format(
			"[{:d}]\n"
			"ProfileNum={}\n"
			"Blob={}\n"
			"Checked={:d}\n"
			"Key={}\n"
			"Path={}\n"
			"szProfileSection={}\n",
			i,
			ee.profileKey,
			ee.blob,
			ee.checked ? 1 : 0,
			ee.keyName,
			ee.eqPath,
			ee.profile);

		contents.append(entry);
	}

	if (WriteToFileEncrypted(contents, filename, password))
	{
		char szMessage[MAX_STRING] = { 0 };
		sprintf_s(szMessage, "Your Profiles have been successfully exported to:\n%s", filename);

		MessageBox(hAskPassWnd, szMessage, "AutoLogin Profile Import/Export", MB_OK | MB_SYSTEMMODAL);
	}
}

bool BlobFound(char* Profile, char* Server, char* Blobstr, char* CharName, char* lpINIPath)
{
	DATA_BLOB BlobIn = { 0 };
	DATA_BLOB BlobOut = { 0 };
	DATA_BLOB BlobOut2 = { 0 };
	DATA_BLOB BlobIn2 = { 0 };
	StrToBlob(Blobstr, &BlobIn);
	DecryptData(&BlobIn, &BlobOut);

	std::string decrypted;
	BlobToStr(&BlobOut, decrypted);

	char szBlobs[MAX_STRING] = { 0 };
	char szBlob[MAX_STRING] = { 0 };

	char szNumLogins[MAX_STRING] = { 0 };
	sprintf_s(szBlobs, "%s:%s_Blob", Server, CharName);
	int NumLogins = GetPrivateProfileString(Profile, szBlobs, "", szBlob, sizeof(szBlob), lpINIPath);

	if (NumLogins && szBlob[0])
	{
		if (char* pDest = strrchr(szBlob, '='))
		{
			pDest[0] = '\0';
		}

		StrToBlob(szBlob, &BlobIn2);
		DecryptData(&BlobIn2, &BlobOut2);

		std::string decrypted2;
		BlobToStr(&BlobOut2, decrypted2);

		return ci_equals(decrypted, decrypted2);
	}
	return false;
}

void ParseProfileMenuItem(const std::string menuItem, std::string& server, std::string& characterName)
{
	// menuItem is in the form "[accountname] servername->charactername" 
	// TODO: move all of this into ProfileInfo as separate fields and drop regex
	auto reg = std::regex("\\[(.*)\\] (.*)->(.*)");
	std::smatch matches;
	std::regex_search(menuItem, matches, reg);
	if (matches.size() < 4)
	{
		MessageBox(nullptr, fmt::format("Malformed menu item string: {}, cannot parse", menuItem).c_str(), nullptr, MB_SYSTEMMODAL | MB_OK);
		return;
	}

	server = matches[2].str();
	characterName = matches[3].str();
}

bool ReadBlob(const std::string& profileName, const std::string& serverName, const std::string& characterName, RawProfileRecord& record)
{
	std::error_code ec;

	if (std::filesystem::exists(internal_paths::AutoLoginIni, ec))
	{
		std::string blobKey = fmt::format("{}:{}_Blob", serverName, characterName);
		std::string encryptedBlob = GetPrivateProfileString(profileName, blobKey, "", internal_paths::AutoLoginIni);

		if (!encryptedBlob.empty())
		{
			record.profileName = profileName;
			record.serverName = serverName;
			record.characterName = characterName;
			record.checked = false;

			size_t pos = encryptedBlob.find("=");
			if (pos != std::string::npos)
			{
				record.checked = encryptedBlob.substr(pos + 1) != "0";
				encryptedBlob = encryptedBlob.substr(0, pos);
			}

			record.encryptedBlob = std::move(encryptedBlob);
			record.eqPath = GetPrivateProfileString(profileName, "EQPath", "", internal_paths::AutoLoginIni);
			return true;
		}
	}

	return false;
}

bool SaveBlob(const std::string& Profile, const std::string& Login, const std::string& Pass, const std::string& Server, const std::string& CharName,
	const std::string& Path, const std::string& Hotkey, const std::string& CharClass, const int CharLevel, bool Checked, const std::string& lpINIPath)
{
	std::string szBlobIn = fmt::format("{}:{}:{}:{}:{}:{:d}", Login, CharName, Pass, Hotkey, CharClass, CharLevel);

	DATA_BLOB DataIn, BlobOut;
	DataIn.pbData = (BYTE*)szBlobIn.c_str();
	DataIn.cbData = (DWORD)szBlobIn.length() + 1;
	EncryptData(&DataIn, &BlobOut);

	std::string out;

	BlobToStr(&BlobOut, out);
	LocalFree(BlobOut.pbData);

	WritePrivateProfileString(Profile, "EQPath", Path, lpINIPath);

	// Find the matching profile and create it if it doesn't exist.
	int NumProfiles = GetPrivateProfileInt("Profiles", "NumProfiles", 0, lpINIPath);

	// Find the matching profile by searching the ini for an entry that matches the
	// one we are trying to save. This works if there are no profiles, too.
	bool bProfileFound = false;
	for (int i = 0; i < NumProfiles; i++)
	{
		std::string profileLabel = GetPrivateProfileString("Profiles", fmt::format("Profile{:d}", i + 1), "", lpINIPath);
		if (ci_equals(profileLabel, Profile))
		{
			bProfileFound = true;
			break;
		}
	}

	if (!bProfileFound)
	{
		// Increase the number of profiles by 1 in the ini
		NumProfiles++;
		WritePrivateProfileInt("Profiles", "NumProfiles", NumProfiles, lpINIPath);

		// Write the new profile section name
		WritePrivateProfileString("Profiles", fmt::format("Profile{:d}", NumProfiles), Profile, lpINIPath);
	}

	std::string key = fmt::format("{}:{}_Blob", Server, CharName);
	out.append(Checked ? "=1" : "=0");

	WritePrivateProfileString(Profile, key, out, lpINIPath);

	return true;
}

template <typename F>
static void ActOnPid(DWORD pid, F func)
{
	for (auto& login : LoginMap)
	{
		for (auto& profile : login.second)
		{
			auto& pi = profile.second;
			if (!pi.CharacterName.empty() && pi.PID == pid)
			{
				func(profile.first, pi);
			}
		}
	}
}

void ResetLoaded(ProfileInfo pi, int id, HMENU hmenuPopup)
{
	std::string label;

	if (!pi.PlayerClass.empty())
		label = fmt::format("{} [{:d} {}] {}", pi.CharacterName, pi.PlayerLevel, pi.PlayerClass, pi.Hotkey);
	else
		label = fmt::format("{} {}", pi.CharacterName, pi.Hotkey);

	MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
	mi.cch = (DWORD)label.length() + 1;
	mi.dwTypeData = &label[0];
	mi.fMask = MIIM_STRING;
	SetMenuItemInfo(hmenuPopup, id, FALSE, &mi);
}

void LoadCharacter(const LoginInstance& instance_template)
{
	auto login_it = s_loadedInstances.find(instance_template);
	if (login_it != s_loadedInstances.end())
	{
		// already mapped into our loaded instances
		if (!IsEQGameProcessId(login_it->PID))
		{
			// somehow we have a PID in our map that isn't EQ
			if (login_it->Hotkey) UnregisterGlobalHotkey(*login_it->Hotkey);
			s_loadedInstances.erase(login_it);
		}
		else
		{
			// trying to load an already loaded instance, update hotkey and reinject
			// assume the provided hotkey is absolute truth to allow for clearing of hotkey
			if (login_it->Hotkey != instance_template.Hotkey)
			{
				if (login_it->Hotkey)
					UnregisterGlobalHotkey(*login_it->Hotkey);

				login_it->Hotkey = instance_template.Hotkey;

				if (login_it->Hotkey)
					RegisterGlobalHotkey(GetEQWindowHandleForProcessId(login_it->PID), *login_it->Hotkey);
			}

			if (login_it->ProfileGroup != instance_template.ProfileGroup)
				login_it->ProfileGroup = instance_template.ProfileGroup;

			// specifically do not update EQ path because we launched this instance with the existing value

			Inject(login_it->PID);
		}
	}
	else
	{
		// character is not loaded, so load it -- we can assume that it's not already running (with MQ anyway)
		// because we got a list at startup of the current running instances

		std::string eq_path = instance_template.EQPath.value_or(instance_template.ProfileGroup ? 
			login::db::GetEQPath(*instance_template.ProfileGroup, instance_template.Server, instance_template.Character) :
			login::db::ReadEQPath());

		if (!eq_path.empty())
		{
			SHELLEXECUTEINFOA sei = { sizeof(SHELLEXECUTEINFOA) };
			sei.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_WAITFORINPUTIDLE;
			sei.lpVerb = "open";
			sei.nShow = SW_SHOW;

			std::string arg;
			if (instance_template.ProfileGroup)
			{
				arg = fmt::format("{}_{}:{}",
					*instance_template.ProfileGroup,
					instance_template.Server,
					instance_template.Character);
			}
			else
			{
				ProfileRecord record;
				record.serverName = instance_template.Server;
				record.characterName = instance_template.Character;

				if (login::db::ReadAccount(record))
				{
					// password was read successfully
					if (!instance_template.Character.empty())
					{
						arg = fmt::format("{}^{}^{}^{}",
							record.serverName, record.accountName,
							record.characterName, record.accountPassword);
					}
					else
					{
						arg = fmt::format("{}^{}^{}",
							record.serverName, record.accountName, record.accountPassword);
					}
				}
				else
				{
					arg = fmt::format("{}:{}", record.serverName, record.characterName);
				}
			}

			auto params = fmt::format("patchme /login:{}", arg);
			sei.lpParameters = params.c_str();
			sei.lpDirectory = eq_path.c_str();

			auto file = fmt::format("{}\\eqgame.exe", eq_path);
			sei.lpFile = file.c_str();

			if (ShellExecuteEx(&sei) && sei.hProcess != 0)
			{
				auto [it, _] = s_loadedInstances.emplace(instance_template);
				it->PID = GetProcessId(sei.hProcess);
				//Inject(it->PID);
			}
		}
		else
		{
			SPDLOG_ERROR("No eq_path found for %s : %s (profile group %s)",
				instance_template.Server, instance_template.Character,
				instance_template.ProfileGroup ? *instance_template.ProfileGroup : "<None>");
		}
	}
}

void LoadProfileGroup(std::string_view group)
{
	for (const auto& profile : login::db::GetProfiles(group))
	{
		if (profile.checked)
		{
			LoginInstance instance;
			instance.ProfileGroup = group;
			instance.Server = profile.serverName;
			instance.Character = profile.characterName;
			if (!profile.hotkey.empty()) instance.Hotkey = profile.hotkey;

			LoadCharacter(instance);
		}
	}
}

void SetLoaded(ProfileInfo pi, int id, HMENU hmenuPopup)
{
	std::string label;

	if (!pi.PlayerClass.empty())
		label = fmt::format("{} [{:d} {}] (Loaded) {}", pi.CharacterName, pi.PlayerLevel, pi.PlayerClass, pi.Hotkey);
	else
		label = fmt::format("{} (Loaded) {}", pi.CharacterName, pi.Hotkey);

	MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
	mi.cch = (DWORD)label.length() + 1;
	mi.dwTypeData = &label[0];
	mi.fMask = MIIM_STRING;
	SetMenuItemInfo(hmenuPopup, id, FALSE, &mi);

	std::string server, characterName0;
	ParseProfileMenuItem(pi.CharacterName, server, characterName0);

	RawProfileRecord rawRecord;
	ReadBlob(pi.profileName, server, characterName0, rawRecord);

	if (!pi.PlayerLevel || (pi.PlayerLevel && pi.PlayerClass.length()))
	{
		ProfileRecord record = ProfileRecord::FromBlob(rawRecord.encryptedBlob);
		record.hotkey = pi.Hotkey;
		record.characterClass = pi.PlayerClass;
		record.characterLevel = pi.PlayerLevel;

		SaveBlob(pi.profileName, record.accountName, record.accountPassword,
			server, record.characterName, rawRecord.eqPath, record.hotkey, record.characterClass,
			record.characterLevel, rawRecord.checked, pi.Inifile);
	}
}

void LoadIt(ProfileInfo& pi, int id)
{
	if (pi.Loaded)
	{
		if (pi.PID == 0 || !IsEQGameProcessId(pi.PID))
		{
			// this isn't a valid eq process, so let's unload it from our map
			ActOnPid(pi.PID, [](const DWORD id, ProfileInfo& pi) {
				SendMessageA(hMainWnd, WM_USER_UNREGISTER_HK, id, pi.PID);
				SendMessageA(hMainWnd, WM_USER_RESETLOADED, id, pi.PID);
				});
		}
		else
		{
			// do nothing if it is already loaded
			return;
		}
	}

	if (pi.PID != 0 && IsEQGameProcessId(pi.PID)) // TODO: do we need to check for 0 here first?
	{
		// the PID already exists, just need to add to the map
		Inject(pi.PID);
		LoginMap[pi.profileName][id].Loaded = true;
		LoginMap[pi.profileName][id].PID = pi.PID;
	}
	else
	{
		// pi.CharacterName is in the form "[accountname] servername->charactername" 
		// TODO: move all of this into ProfileInfo as separate fields and drop regex
		auto reg = std::regex("\\[(.*)\\] (.*)->(.*)");
		std::smatch matches;
		std::regex_search(pi.CharacterName, matches, reg);
		if (matches.size() < 4)
		{
			MessageBox(nullptr, fmt::format("Malformed login string: {}, cannot log in", pi.CharacterName).c_str(), nullptr, MB_SYSTEMMODAL | MB_OK);
			return;
		}

		auto account = matches[1].str();
		auto server = matches[2].str();
		auto character = matches[3].str();

		for (auto pid : GetAllEqGameSessions())
		{
			if (IsInjected(pid))
			{
				// GetLocalPlayer requires MQ2 to be injected
				auto name = GetLocalPlayer(pid);
				if (name == character)
				{
					// we have found a process that matches
					// TODO: need to check against account more than name -- can have multiple characters with the same name on different servers/accounts
					SetLoaded(pi, id, hProfilesMenu);
					LoginMap[pi.profileName][id].Loaded = true;
					LoginMap[pi.profileName][id].PID = pid;
					return; // early out here, don't want to spawn a new EQ process
				}
			}
		}

		const auto& eqpath = GetPrivateProfileString(pi.profileName, "EQPath", "", pi.Inifile);
		if (!eqpath.empty())
		{
			SHELLEXECUTEINFOA sei = { sizeof(SHELLEXECUTEINFOA) };
			sei.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_WAITFORINPUTIDLE;
			sei.lpVerb = "open";
			sei.nShow = SW_SHOW;

			// Format login param and add quotes if necessary.
			std::string arg = fmt::format("{}_{}:{}", pi.profileName, server, character);
			if (arg.find(" ") != std::string::npos)
			{
				arg = fmt::format("\"{}\"", arg);
			}

			auto params = fmt::format("patchme /login:{}", arg);
			sei.lpParameters = params.c_str();
			sei.lpDirectory = eqpath.c_str();
			auto file = fmt::format("{}\\eqgame.exe", eqpath);
			sei.lpFile = file.c_str();

			if (ShellExecuteEx(&sei))
			{
				LoginMap[pi.profileName][id].Loaded = true;
				LoginMap[pi.profileName][id].PID = GetProcessId(sei.hProcess);
			}
		}
		else
		{
			MessageBox(nullptr, fmt::format("No EQPath set in {} under profile {}, aborting login", pi.Inifile, pi.profileName).c_str(), nullptr, MB_SYSTEMMODAL | MB_OK);
		}
	}
}

void DoPlainLogin(std::string_view Server, std::string_view Login, std::string_view Pass, std::string_view CharName)
{
	//server^stationname^charname^pass

	char szParameters[MAX_STRING] = { 0 };
	if (!CharName.empty())
	{
		sprintf_s(
			szParameters,
			"%s\\eqgame.exe patchme /login:%s^%s^%s^%s",
			internal_paths::EQRoot.c_str(),
			std::string(Server).c_str(),
			std::string(Login).c_str(),
			std::string(CharName).c_str(),
			std::string(Pass).c_str()
		);
	}
	else
	{
		sprintf_s(
			szParameters,
			"%s\\eqgame.exe patchme /login:%s^%s^%s",
			internal_paths::EQRoot.c_str(),
			std::string(Server).c_str(),
			std::string(Login).c_str(),
			std::string(Pass).c_str()
		);
	}

	STARTUPINFOA sei = { sizeof(STARTUPINFOA) };
	char szWinTitle[64] = { 0 };
	strcpy_s(szWinTitle, fmt::format("EverQuest {}.{}", CharName, Server).c_str());
	sei.lpTitle = szWinTitle;
	sei.wShowWindow = SW_SHOWNORMAL;
	sei.dwFlags = STARTF_USESHOWWINDOW;

	wil::unique_process_information pi;
	::CreateProcessA(nullptr, szParameters, nullptr, nullptr, FALSE, 0, nullptr, internal_paths::EQRoot.c_str(), &sei, &pi);
}

// Note that this function blindly assumes its related to autologin in the else case
LRESULT HandleAutoLoginMenuRightclick(HMENU hSubMenu, int menuId, LPARAM lParam)
{
	int unmaskedMenuId = GetUnmaskedMenuId(menuId);

	if (unmaskedMenuId == ID_CHARACTER_EDIT || unmaskedMenuId == ID_MENU_CHARACTER)
	{
		// Get the name and check status of the menu id.
		char szProfile[64] = { 0 };
		bool bChecked = false;

		{
			MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
			mi.fMask = MIIM_DATA | MIIM_STATE;
			GetMenuItemInfo((HMENU)lParam, menuId, MF_BYCOMMAND, &mi);

			bChecked = (mi.fState & MF_CHECKED) != 0;
			if (mi.dwItemData != 0)
			{
				strcpy_s(szProfile, (char*)mi.dwItemData);
			}
		}

		// display popup menu with Edit, Delete and Check/Uncheck
		if (szProfile[0])
		{
			auto& popupMap = LoginMap["Popups"];

			popupMap[ID_CHARACTER_EDIT].CharacterName = szProfile;
			popupMap[ID_CHARACTER_EDIT].PID = menuId;
			popupMap[ID_CHARACTER_DELETE].CharacterName = szProfile;
			popupMap[ID_CHARACTER_DELETE].PID = menuId;
			popupMap[ID_CHARACTER_TOGGLE].CharacterName = szProfile;
			popupMap[ID_CHARACTER_TOGGLE].PID = menuId;

			char szText[64] = { 0 };
			strcpy_s(szText, bChecked ? "&Uncheck" : "&Check");
			bChecked = !bChecked;

			MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
			mi.dwTypeData = szText;
			mi.cch = 64;
			mi.fMask = MIIM_STRING;
			SetMenuItemInfo(hEditPopup, ID_CHARACTER_TOGGLE, FALSE, &mi);

			popupMap[ID_CHARACTER_TOGGLE].profileName = bChecked ? "Uncheck" : "Check";

			POINT point = { 0 };
			GetCursorPos(&point);

			TrackPopupMenuEx(hEditPopup, TPM_LEFTBUTTON | TPM_RECURSE, point.x, point.y, hMainWnd, nullptr);
		}
	}

	return 0;
}

void LaunchCleanSession()
{
	// Get path to the login server data file
	fs::path eqlsPlayerDataIni = fs::path{ internal_paths::EQRoot } / "eqlsPlayerData.ini";

	// Get default username from eqlsPlayerData.ini
	std::string username = GetPrivateProfileString("PLAYER", "Username", "<>", eqlsPlayerDataIni.string());

	// create command line arguments
	std::string parameters = fmt::format("{}\\eqgame.exe patchme /login:{}", internal_paths::EQRoot, username);

	STARTUPINFOA si = { sizeof(STARTUPINFOA) };
	si.wShowWindow = SW_SHOWNORMAL;
	si.dwFlags = STARTF_USESHOWWINDOW;

	wil::unique_process_information pi;
	::CreateProcessA(nullptr, &parameters[0], nullptr, nullptr, FALSE, 0, nullptr, internal_paths::EQRoot.c_str(), &si, &pi);
}

#pragma region ImGui

bool ToggleSlider(const char* label, bool* v)
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	ImVec2 position = ImGui::GetCursorScreenPos();
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	float height = ImGui::GetFrameHeight();
	float width = height * 1.55f;
	float radius = height * 0.5f;

	bool ret = ImGui::InvisibleButton(label, ImVec2(width, height));
	if (ImGui::IsItemClicked()) *v = !*v;

	float t = *v ? 1.f : 0.f;

	ImGuiContext* g = ImGui::GetCurrentContext();
	float animation_speed = 8.5f;
	if (g->LastActiveId == g->CurrentWindow->GetID(label))
	{
		float t_anim = ImSaturate(g->LastActiveIdTimer * animation_speed);
		t = *v ? t_anim : (1.f - t_anim);
	}

	ImU32 bg_color = ImGui::GetColorU32(colors[ImGuiCol_Text]);

	ImU32 fg_color;
	if (ImGui::IsItemClicked())
		fg_color = ImGui::GetColorU32(colors[ImGuiCol_ButtonActive]);
	else if (ImGui::IsItemHovered())
		fg_color = ImGui::GetColorU32(colors[ImGuiCol_ButtonHovered]);
	else
		fg_color = ImGui::GetColorU32(colors[ImGuiCol_Button]);

	draw_list->AddRectFilled(position, ImVec2(position.x + width, position.y + height), bg_color, height * 0.5f);
	draw_list->AddCircleFilled(ImVec2(position.x + radius + t * (width - radius * 2.f), position.y + radius), radius - 1.5f, fg_color);

	return ret;
}

float ButtonWidth(const char* text)
{
	return ImGui::GetStyle().FramePadding.x * 2 + ImGui::CalcTextSize(text).x + ImGui::GetStyle().WindowPadding.x;
}

void SetEQDir(std::optional<std::string>& eq_path)
{
	auto eqDir = eq_path.value_or(login::db::ReadEQPath());
	ImGui::InputText("EQ Dir", &eqDir[0], eqDir.size(), ImGuiInputTextFlags_ReadOnly);

	if (!s_eqDirDialog)
		s_eqDirDialog = IGFD_Create();

	if (ImGui::Button("Choose##eqdir"))
	{
		IGFD_OpenDialog2(s_eqDirDialog, "ChooseEQDirKey", "Choose Default EverQuest Directory",
			nullptr, (internal_paths::EQRoot + "/").c_str(), 1, nullptr, ImGuiFileDialogFlags_None);
	}

	if (IGFD_DisplayDialog(s_eqDirDialog, "ChooseEQDirKey", ImGuiFileDialogFlags_None, ImVec2(350, 350), ImVec2(FLT_MAX, FLT_MAX)))
	{
		if (IGFD_IsOk(s_eqDirDialog))
		{
			std::shared_ptr<char> selected_path(IGFD_GetCurrentPath(s_eqDirDialog), IGFD_DestroyString);
			std::error_code ec;
			if (selected_path && std::filesystem::exists(selected_path.get(), ec))
			{
				eq_path = std::filesystem::canonical(std::filesystem::path(selected_path.get()), ec).string();
			}
		}

		IGFD_CloseDialog(s_eqDirDialog);
	}
}

void ShowAccountWindow(std::optional<std::string>& selected)
{
	// declare account statics
	static bool show_password = false;
	static std::string password;
	static std::string account_name;

	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
	if (ImGui::BeginListBox("##accountslist"))
	{
		for (const auto& account : login::db::ListAccounts())
		{
			const bool is_selected = selected && ci_equals(account, *selected);
			if (ImGui::Selectable(account.c_str(), is_selected))
				selected = account;

			if (is_selected) ImGui::SetItemDefaultFocus();
		}

		ImGui::EndListBox();
	}

	if (selected)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_Delete)) ImGui::OpenPopup("Delete Account");

		if (ImGui::IsKeyPressed(ImGuiKey_Enter))
		{
			ProfileRecord profile;
			profile.accountName = *selected;
			if (auto pass = login::db::ReadAccount(profile))
				password = *pass;

			ImGui::OpenPopup("Edit Account");
		}

		if (ImGui::IsKeyPressed(ImGuiKey_Escape)) selected = {};
	}

	if (ImGui::BeginPopupModal("Delete Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Are you sure you want to delete account '%s'? All associated characters and profiles will also be removed.", selected->c_str());
		ImGui::Spacing();

		if (ImGui::Button("Yes##deleteaccount", ImVec2(120, 0)))
		{
			login::db::DeleteAccount(*selected);
			selected = {};
			ImGui::CloseCurrentPopup();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("No##deleteaccount", ImVec2(120, 0)))
		{
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}

	if (ImGui::BeginPopupModal("Edit Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Set password for account '%s':", selected->c_str());
		ImGui::Spacing();

		ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
		if (!show_password) flags |= ImGuiInputTextFlags_Password;
		ImGui::InputText("##password##editaccount", &password, flags);
		ImGui::Spacing();

		ImGui::Checkbox("Show password##editaccount", &show_password);
		ImGui::Spacing();

		if (ImGui::Button("OK##editaccount", ImVec2(120, 0)))
		{
			ProfileRecord record;
			record.accountName = *selected;
			record.accountPassword = password;
			login::db::UpdateAccount(*selected, record);
			ImGui::CloseCurrentPopup();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel##editaccount", ImVec2(120, 0)))
		{
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}

	if (ImGui::BeginPopupModal("Create Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Create a new account, or update existing account.");
		ImGui::Spacing();

		ImGui::InputText("Account Name##createaccount", &account_name);
		ImGui::Spacing();

		ImGuiInputTextFlags flags = ImGuiInputTextFlags_None;
		if (!show_password) flags |= ImGuiInputTextFlags_Password;
		ImGui::InputText("##password##createaccount", &password, flags);
		ImGui::Spacing();

		ImGui::Checkbox("Show password##createaccount", &show_password);
		ImGui::Spacing();

		if (ImGui::Button("OK##createaccount", ImVec2(120, 0)))
		{
			ProfileRecord record;
			record.accountName = account_name;
			record.accountPassword = password;
			login::db::CreateAccount(record);
			selected = account_name;
			ImGui::CloseCurrentPopup();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel##createaccount", ImVec2(120, 0)))
		{
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}

	if (ImGui::Button("Add Account"))
	{
		account_name = selected ? *selected : "";
		ImGui::OpenPopup("Create Account");
	}

	ImGui::SameLine();
	if (ImGui::Button("Edit Account") && selected)
	{
		ProfileRecord profile;
		profile.accountName = *selected;
		if (auto pass = login::db::ReadAccount(profile))
			password = *pass;

		ImGui::OpenPopup("Edit Account");
	}

	ImGui::SameLine();
	if (ImGui::Button("Remove Account") && selected) ImGui::OpenPopup("Delete Account");
}

void ShowCharacterWindow(std::string_view account, std::optional<std::pair<std::string, std::string>>& selected, std::string& preview)
{
	auto set_selection = [&selected, &preview](const std::pair<std::string, std::string> character)
		{
			selected = character;
			preview = fmt::format("{} : {}", character.first, character.second);
		};

	static std::string accountName;
	static std::string serverName;
	static std::string characterName;

	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
	if (ImGui::BeginListBox("##characterslist"))
	{
		// this avoids a buffer allocation
		static auto buf = [](size_t size)
			{
				fmt::memory_buffer buf;
				buf.reserve(size);

				return buf;
			}(256);

		static auto buf_ins = std::back_inserter(buf);

		for (const auto& character : login::db::ListCharacters(account))
		{
			ImGui::PushID(character.first.c_str());
			ImGui::PushID(character.second.c_str());

			const bool is_selected = selected &&
				ci_equals(character.first, selected->first) &&
				ci_equals(character.second, selected->second);

			fmt::format_to(buf_ins, "{} : {}", character.first, character.second);

			if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
				set_selection(character);

			if (is_selected)
				ImGui::SetItemDefaultFocus();

			ImGui::SameLine();
			ImGui::Text("%.*s", buf.size(), buf.data());

			buf.clear();

			ImGui::PopID();
			ImGui::PopID();
		}

		ImGui::EndListBox();
	}

	if (selected)
	{
		if (ImGui::IsKeyPressed(ImGuiKey_Delete)) ImGui::OpenPopup("Delete Character");

		if (ImGui::IsKeyPressed(ImGuiKey_Enter))
		{
			accountName = account;
			serverName = selected->first;
			characterName = selected->second;

			ImGui::OpenPopup("Edit Character");
		}

		if (ImGui::IsKeyPressed(ImGuiKey_Escape)) selected = {};
	}

	if (ImGui::BeginPopupModal("Delete Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::TextWrapped("Are you sure you want to delete character '%s : %s'? All associated profiles will also be removed.", selected->first.c_str(), selected->second.c_str());
		ImGui::Spacing();

		if (ImGui::Button("Yes##deletecharacter", ImVec2(120, 0)))
		{
			login::db::DeleteCharacter(selected->first, selected->second);
			selected = {};
			preview = "";
			ImGui::CloseCurrentPopup();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("No##deletecharacter", ImVec2(120, 0)))
		{
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}

	if (ImGui::BeginPopupModal("Edit Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Account##editcharacter", &accountName);
		ImGui::Spacing();

		ImGui::InputText("Server##editcharacter", &serverName);
		ImGui::Spacing();

		ImGui::InputText("Name##editcharacter", &characterName);
		ImGui::Spacing();

		if (ImGui::Button("OK##editcharacter", ImVec2(120, 0)))
		{
			if (selected)
			{
				ProfileRecord record;
				record.accountName = accountName;
				record.serverName = serverName;
				record.characterName = characterName;

				login::db::UpdateCharacter(selected->first, selected->second, record);
				set_selection(std::make_pair(serverName, characterName));
			}

			ImGui::CloseCurrentPopup();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel##editcharacter", ImVec2(120, 0)))
		{
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}

	if (ImGui::BeginPopupModal("Create Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::InputText("Account##createcharacter", &accountName);
		ImGui::Spacing();

		ImGui::InputText("Server##createcharacter", &serverName);
		ImGui::Spacing();

		ImGui::InputText("Name##createcharacter", &characterName);
		ImGui::Spacing();

		if (ImGui::Button("OK##createcharacter", ImVec2(120, 0)))
		{
			ProfileRecord record;
			record.accountName = accountName;
			record.serverName = serverName;
			record.characterName = characterName;

			login::db::CreateCharacter(record);
			set_selection(std::make_pair(serverName, characterName));

			ImGui::CloseCurrentPopup();
		}

		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel##createcharacter", ImVec2(120, 0)))
		{
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}

	if (ImGui::Button("Add Character"))
	{
		accountName = account;
		if (selected)
		{
			serverName = selected->first;
			characterName = selected->second;
		}
		else
		{
			serverName.clear();
			characterName.clear();
		}
		ImGui::OpenPopup("Create Character");
	}

	ImGui::SameLine();
	if (ImGui::Button("Edit Character") && selected)
	{
		accountName = account;
		serverName = selected->first;
		characterName = selected->second;

		ImGui::OpenPopup("Edit Character");
	}

	ImGui::SameLine();
	if (ImGui::Button("Remove Character") && selected) ImGui::OpenPopup("Delete Character");
}

static const std::unordered_map<ImGuiKey, std::string> s_hotkeyMap = {
	{ ImGuiKey_LeftArrow, "LEFT" },
	{ ImGuiKey_RightArrow, "RIGHT" },
	{ ImGuiKey_UpArrow, "UP" },
	{ ImGuiKey_DownArrow, "DOWN" },
	{ ImGuiKey_PageUp, "PAGEUP" },
	{ ImGuiKey_PageDown, "PAGEDOWN" },
	{ ImGuiKey_Home, "HOME" },
	{ ImGuiKey_End, "END" },
	{ ImGuiKey_Insert, "INSERT" },
	{ ImGuiKey_Delete, "DELETE" },
	{ ImGuiKey_Space, "SPACE" },
	{ ImGuiKey_Enter, "RETURN" },
	{ ImGuiKey_Escape, "ESCAPE" },
	{ ImGuiKey_0, "0" }, { ImGuiKey_1, "1" }, { ImGuiKey_2, "2" }, { ImGuiKey_3, "3" }, { ImGuiKey_4, "4" }, { ImGuiKey_5, "5" }, { ImGuiKey_6, "6" }, { ImGuiKey_7, "7" }, { ImGuiKey_8, "8" }, { ImGuiKey_9, "9" },
	{ ImGuiKey_A, "A" }, { ImGuiKey_B, "B" }, { ImGuiKey_C, "C" }, { ImGuiKey_D, "D" }, { ImGuiKey_E, "E" }, { ImGuiKey_F, "F" }, { ImGuiKey_G, "G" }, { ImGuiKey_H, "H" }, { ImGuiKey_I, "I" }, { ImGuiKey_J, "J" },
	{ ImGuiKey_K, "K" }, { ImGuiKey_L, "L" }, { ImGuiKey_M, "M" }, { ImGuiKey_N, "N" }, { ImGuiKey_O, "O" }, { ImGuiKey_P, "P" }, { ImGuiKey_Q, "Q" }, { ImGuiKey_R, "R" }, { ImGuiKey_S, "S" }, { ImGuiKey_T, "T" },
	{ ImGuiKey_U, "U" }, { ImGuiKey_V, "V" }, { ImGuiKey_W, "W" }, { ImGuiKey_X, "X" }, { ImGuiKey_Y, "Y" }, { ImGuiKey_Z, "Z" },
	{ ImGuiKey_F1, "F1" }, { ImGuiKey_F2, "F2" }, { ImGuiKey_F3, "F3" }, { ImGuiKey_F4, "F4" }, { ImGuiKey_F5, "F5" }, { ImGuiKey_F6, "F6" },
	{ ImGuiKey_F7, "F7" }, { ImGuiKey_F8, "F8" }, { ImGuiKey_F9, "F9" }, { ImGuiKey_F10, "F10" }, { ImGuiKey_F11, "F11" }, { ImGuiKey_F12, "F12" },
	{ ImGuiKey_F13, "F13" }, { ImGuiKey_F14, "F14" }, { ImGuiKey_F15, "F15" }, { ImGuiKey_F16, "F16" }, { ImGuiKey_F17, "F17" }, { ImGuiKey_F18, "F18" },
	{ ImGuiKey_F19, "F19" }, { ImGuiKey_F20, "F20" }, { ImGuiKey_F21, "F21" }, { ImGuiKey_F22, "F22" }, { ImGuiKey_F23, "F23" }, { ImGuiKey_F24, "F24" },
	{ ImGuiKey_Apostrophe, "'" },
	{ ImGuiKey_Comma, "," },
	{ ImGuiKey_Minus, "-" },
	{ ImGuiKey_Period, "." },
	{ ImGuiKey_Slash, "/" },
	{ ImGuiKey_Semicolon, ";" },
	{ ImGuiKey_Equal, "=" },
	{ ImGuiKey_LeftBracket, "[" },
	{ ImGuiKey_Backslash, "\\" },
	{ ImGuiKey_RightBracket, "]" },
	{ ImGuiKey_GraveAccent, "`" },
	{ ImGuiKey_NumLock, "NUMLOCK" },
	{ ImGuiKey_Keypad0, "NUMPAD0" }, { ImGuiKey_Keypad1, "NUMPAD1" }, { ImGuiKey_Keypad2, "NUMPAD2" }, { ImGuiKey_Keypad3, "NUMPAD3" }, { ImGuiKey_Keypad4, "NUMPAD4" },
	{ ImGuiKey_Keypad5, "NUMPAD5" }, { ImGuiKey_Keypad6, "NUMPAD6" }, { ImGuiKey_Keypad7, "NUMPAD7" }, { ImGuiKey_Keypad8, "NUMPAD8" }, { ImGuiKey_Keypad9, "NUMPAD9" },
	{ ImGuiKey_KeypadDecimal, "NUMPAD." },
	{ ImGuiKey_KeypadDivide, "NUMPAD/" },
	{ ImGuiKey_KeypadMultiply, "NUMPAD*" },
	{ ImGuiKey_KeypadSubtract, "NUMPAD-" },
	{ ImGuiKey_KeypadAdd, "NUMPAD+" },
	{ ImGuiKey_KeypadEqual, "NUMPAD=" },
};

void ShowHotkeyWindow(std::optional<std::string>& hotkey)
{
	fmt::memory_buffer buf;
	auto buf_ins = std::back_inserter(buf);

	if (ImGui::IsKeyDown(ImGuiMod_Ctrl))
		fmt::format_to(buf_ins, "CTRL+");

	if (ImGui::IsKeyDown(ImGuiMod_Shift))
		fmt::format_to(buf_ins, "SHIFT+");

	if (ImGui::IsKeyDown(ImGuiMod_Alt))
		fmt::format_to(buf_ins, "ALT+");

	if (ImGui::IsKeyDown(ImGuiMod_Super))
		fmt::format_to(buf_ins, "WIN+");

	for (const auto& [key, name] : s_hotkeyMap)
	{
		if (ImGui::IsKeyDown(key))
		{
			fmt::format_to(buf_ins, name);
			hotkey = fmt::to_string(buf);
			break;
		}
	}

	ImGui::Text("Pressed: %.*s", buf.size(), buf.data());
	ImGui::Text("Current: %s", hotkey ? hotkey->c_str() : "<None>");
}

struct InterimProfileRecord
{
	std::optional<std::string> current_account = {};
	std::optional<std::pair<std::string, std::string>> current_character = {};
	std::optional<std::string> hotkey = {};
	std::optional<std::string> eq_path = {};
	std::string char_preview = "";

	bool finalize = false;
};

void ShowAddProfile(std::string_view profile_group, InterimProfileRecord& profile)
{
	ImGui::PushID("addprofilewindow");

	// drop down for account or create new
	if (ImGui::BeginCombo("##chooseaccount", profile.current_account ? profile.current_account->c_str() : ""))
	{
		for (const auto& account : login::db::ListAccounts())
		{
			bool is_selected = profile.current_account && ci_equals(account, *profile.current_account);
			if (ImGui::Selectable(account.c_str(), is_selected))
				profile.current_account = account;

			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}

	ImGui::SameLine();
	if (ImGui::Button("...##account"))
		ImGui::OpenPopup("Select or Create Account");

	if (ImGui::BeginPopupModal("Select or Create Account", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ShowAccountWindow(profile.current_account);

		ImGui::Separator();
		if (ImGui::Button("OK"))
			ImGui::CloseCurrentPopup();

		ImGui::EndPopup();
	}

	// drop down for character or create new, only show this if an account has been selected
	if (profile.current_account)
	{
		if (ImGui::BeginCombo("##choosecharacter", profile.char_preview.c_str()))
		{
			// this avoids a buffer allocation
			static auto buf = [](size_t size)
				{
					fmt::memory_buffer buf;
					buf.reserve(size);

					return buf;
				}(256);

				static auto buf_ins = std::back_inserter(buf);

				for (const auto& character : login::db::ListCharacters(*profile.current_account))
				{
					const bool is_selected = profile.current_character &&
						ci_equals(character.first, profile.current_character->first) &&
						ci_equals(character.second, profile.current_character->second);

					fmt::format_to(buf_ins, "{} : {}", character.first, character.second);

					if (ImGui::Selectable("", is_selected, ImGuiSelectableFlags_SpanAvailWidth))
					{
						profile.current_character = character;
						profile.char_preview = fmt::to_string(buf);
					}

					if (is_selected)
						ImGui::SetItemDefaultFocus();

					ImGui::Text("%.*s", buf.size(), buf.data());

					buf.clear();
				}
				ImGui::EndCombo();
		}

		ImGui::SameLine();
		if (ImGui::Button("...##character"))
			ImGui::OpenPopup("Select or Create Character");

		if (ImGui::BeginPopupModal("Select or Create Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ShowCharacterWindow(*profile.current_account, profile.current_character, profile.char_preview);

			ImGui::Separator();
			if (ImGui::Button("OK"))
			{
				ProfileRecord record;
				record.profileName = profile_group;
				record.serverName = profile.current_character->first;
				record.characterName = profile.current_character->second;

				login::db::ReadProfile(record);
				if (!record.hotkey.empty())
					profile.hotkey = record.hotkey;

				profile.eq_path = record.eqPath;

				ImGui::CloseCurrentPopup();
			}

			ImGui::EndPopup();
		}
	}
	else if (profile.current_character)
		profile.current_character = {};

	if (profile.current_account && profile.current_character)
	{
		// input box for hotkey (optional)
		if (ImGui::Button("Hotkey"))
			ImGui::OpenPopup("Input Hotkey");

		ImGui::SameLine();
		ImGui::Text("%s", profile.hotkey ? profile.hotkey->c_str() : "<None>");

		if (ImGui::BeginPopupModal("Input Hotkey", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ShowHotkeyWindow(profile.hotkey);

			ImGui::Separator();
			if (ImGui::Button("OK"))
				ImGui::CloseCurrentPopup();

			ImGui::EndPopup();
		}

		// input for eq path override (optional)
		if (ImGui::Button("EQ Path"))
			ImGui::OpenPopup("Input EQ Path");

		ImGui::SameLine();
		ImGui::Text("%s", profile.eq_path ? profile.eq_path->c_str() : "<Default>");

		if (ImGui::BeginPopupModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
		{
			SetEQDir(profile.eq_path);

			ImGui::Separator();
			if (ImGui::Button("OK"))
				ImGui::CloseCurrentPopup();

			ImGui::EndPopup();
		}
	}

	if (ImGui::Button("Cancel"))
	{
		ImGui::CloseCurrentPopup();
	}


	ImGui::SameLine();
	ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - ButtonWidth("Cancel"));
	if (ImGui::Button("OK", ImVec2(ButtonWidth("Cancel"), ImGui::GetStyle().FramePadding.y * 2 + ImGui::CalcTextSize("Cancel").y)))
	{
		if (profile.current_character)
			profile.finalize = true;

		ImGui::CloseCurrentPopup();
	}

	ImGui::PopID();
}

void ShowAutoLoginWindow()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);

	if (ImGui::BeginTabBar("##maintabbar", ImGuiTabBarFlags_FittingPolicyResizeDown))
	{
		ImGui::PushID("profile");
		ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x * 0.5f);
		if (ImGui::BeginTabItem("Profiles"))
		{
			static std::optional<std::string> current_group;
			// Code goes into this scope for selecting and modifying profiles/groups
			ImGui::BeginChild("##mainchild", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

			ImGui::PushID("menubar");
			if (ImGui::BeginMenuBar())
			{
				static std::string new_group;
				static std::optional<std::string> new_group_path;
				if (ImGui::SmallButton("Create"))
				{
					new_group = "";
					new_group_path = {};
					ImGui::OpenPopup("Create Profile Group");
				}

				if (ImGui::BeginPopupModal("Create Profile Group", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
				{
					ImGui::InputText("Group Name", &new_group);

					ImGui::Spacing();
					if (ImGui::Button("EQ Path"))
						ImGui::OpenPopup("Input EQ Path");

					ImGui::SameLine();
					ImGui::Text("%s", new_group_path ? new_group_path->c_str() : "<Default>");

					if (ImGui::BeginPopupModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
					{
						SetEQDir(new_group_path);

						ImGui::Separator();
						if (ImGui::Button("OK"))
							ImGui::CloseCurrentPopup();

						ImGui::EndPopup();
					}

					ImGui::Separator();
					if (ImGui::Button("Cancel"))
					{
						ImGui::CloseCurrentPopup();
					}

					ImGui::SameLine();
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - ButtonWidth("Cancel"));
					if (ImGui::Button("OK", ImVec2(ButtonWidth("Cancel"), ImGui::GetStyle().FramePadding.y * 2 + ImGui::CalcTextSize("Cancel").y)))
					{
						if (!new_group.empty())
						{
							ProfileGroup group;
							group.profileName = new_group;
							group.eqPath = new_group_path;

							login::db::CreateProfileGroup(group);
						}

						current_group = new_group;
						new_group = {};
						new_group_path = {};

						ImGui::CloseCurrentPopup();
					}

					ImGui::EndPopup();
				}

				if (ImGui::SmallButton("Remove") && current_group)
					ImGui::OpenPopup("Delete Profile Group");

				if (ImGui::BeginPopupModal("Delete Profile Group", nullptr, ImGuiWindowFlags_AlwaysAutoResize) && current_group)
				{
					ImGui::TextWrapped("Are you sure you want to delete profile group '%s'? All associated profiles will also be removed.", current_group->c_str());
					ImGui::Spacing();

					if (ImGui::Button("Yes##deletegroup", ImVec2(120, 0)))
					{
						login::db::DeleteProfileGroup(*current_group);
						current_group = {};
						ImGui::CloseCurrentPopup();
					}

					ImGui::SetItemDefaultFocus();
					ImGui::SameLine();
					if (ImGui::Button("No##deletegroup", ImVec2(120, 0)))
					{
						ImGui::CloseCurrentPopup();
					}

					ImGui::EndPopup();
				}

				constexpr const char* label = "Profiles";
				ImGui::SameLine(ImGui::GetContentRegionMax().x - ImGui::CalcTextSize(label).x - 5.f);
				ImGui::Text(label);

				ImGui::EndMenuBar();
			}
			ImGui::PopID();

			ImGui::PushID("profilecombo");
			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - ButtonWidth("Add Profile") - ButtonWidth("Launch Group"));
			if (ImGui::BeginCombo("##profilegroups", current_group ? current_group->c_str() : ""))
			{
				for (const auto& group : login::db::ListProfileGroups())
				{
					bool is_selected = current_group && ci_equals(group, *current_group);
					if (ImGui::Selectable(group.c_str(), is_selected))
						current_group = group;

					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}
			ImGui::PopID();

			ImGui::SameLine();
			static InterimProfileRecord interim_profile;
			static bool edit_profile = false;

			if (ImGui::Button("Add Profile"))
			{
				// reset to defaults
				interim_profile = {};
				ImGui::OpenPopup("Add Profile");
			}

			if (current_group && ImGui::BeginPopupModal("Add Profile", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				ShowAddProfile(*current_group, interim_profile);
				ImGui::EndPopup();
			}

			if (!edit_profile && current_group && interim_profile.finalize && interim_profile.current_character)
			{
				ProfileRecord record;
				record.profileName = *current_group;
				record.serverName = interim_profile.current_character->first;
				record.characterName = interim_profile.current_character->second;
				record.hotkey = interim_profile.hotkey ? *interim_profile.hotkey : "";
				record.eqPath = interim_profile.eq_path;
				record.checked = true;

				interim_profile = {};

				login::db::CreateProfile(record);
			}

			ImGui::SameLine();
			if (ImGui::Button("Launch Group") && current_group)
			{
				LoadProfileGroup(*current_group);
			}

			ImGui::PushID("mainlist");
			if (ImGui::BeginTable("##maintable", 6, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBody))
			{
				if (current_group)
				{
					ImGui::TableSetupColumn("Account");
					ImGui::TableSetupColumn("Server");
					ImGui::TableSetupColumn("Character");
					ImGui::TableSetupColumn("Persona");
					ImGui::TableSetupColumn("Hotkey");
					ImGui::TableSetupColumn("##play");
					ImGui::TableHeadersRow();

					for (auto& profile : login::db::GetProfiles(*current_group))
					{
						ImGui::PushID(profile.serverName.c_str());
						ImGui::PushID(profile.characterName.c_str());

						ImGui::TableNextRow();
						ImGui::TableNextColumn();
						if (ImGui::Selectable("##rowselect", &profile.checked, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap))
							login::db::UpdateProfile(profile);

						if (ImGui::IsItemHovered() && ImGui::IsItemClicked(ImGuiMouseButton_Right))
							ImGui::OpenPopup("row_popup");

						if (ImGui::BeginPopup("row_popup"))
						{
							if (ImGui::Selectable("Edit"))
							{
								interim_profile.current_character = std::make_pair(profile.serverName, profile.characterName);
								interim_profile.current_account = profile.accountName;
								interim_profile.hotkey = profile.hotkey;
								interim_profile.eq_path = profile.eqPath;
								interim_profile.char_preview = fmt::format("{} : {}", profile.serverName, profile.characterName);
								
								interim_profile.finalize = false;

								edit_profile = true;
							}

							if (ImGui::Selectable("Remove"))
								login::db::DeleteProfile(profile.serverName, profile.characterName, *current_group);

							ImGui::EndPopup();
						}

						ImGui::SameLine();
						ImGui::Text(profile.accountName.c_str());

						ImGui::TableNextColumn();
						ImGui::Text(profile.serverName.c_str());

						ImGui::TableNextColumn();
						ImGui::Text(profile.characterName.c_str());

						ImGui::TableNextColumn();
						if (profile.characterClass.empty())
							ImGui::Text("<None>");
						else
							ImGui::Text("%s %d", profile.characterClass.c_str(), profile.characterLevel);

						ImGui::TableNextColumn();
						ImGui::Text(profile.hotkey.c_str());

						ImGui::TableNextColumn();
						if (ImGui::SmallButton("Play"))
						{
							LoginInstance instance;
							instance.ProfileGroup = current_group;
							instance.Server = profile.serverName;
							instance.Character = profile.characterName;
							if (!profile.hotkey.empty()) instance.Hotkey = profile.hotkey;

							LoadCharacter(instance);
						}

						ImGui::PopID();
						ImGui::PopID();
					}

					if (edit_profile && interim_profile.current_character)
						ImGui::OpenPopup("Edit Profile");

					if (ImGui::BeginPopupModal("Edit Profile", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
					{
						ShowAddProfile(*current_group, interim_profile);
						ImGui::EndPopup();
					}

					if (interim_profile.finalize && interim_profile.current_character)
					{
						ProfileRecord record;
						record.profileName = *current_group;
						record.serverName = interim_profile.current_character->first;
						record.characterName = interim_profile.current_character->second;
						record.hotkey = interim_profile.hotkey ? *interim_profile.hotkey : "";
						record.eqPath = interim_profile.eq_path;
						record.checked = true;

						interim_profile = {};
						edit_profile = false;

						login::db::UpdateProfile(record);
					}
				}

				ImGui::EndTable();
			}
			ImGui::PopID();

			ImGui::EndChild();
			ImGui::EndTabItem();
		}

		ImGui::PopID();

		ImGui::PushID("character");
		ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
		if (ImGui::BeginTabItem("Characters"))
		{
			ImGui::BeginChild("##mainchild", ImVec2(0, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_MenuBar);

			static std::string search;
			static auto matches = login::db::ListCharacterMatches(search);
			static ProfileRecord interim_profile;
			static std::optional<std::pair<std::string, std::string>> selected;

			ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - ButtonWidth("Add Character"));
			if (ImGui::InputText("##searchbar", &search, ImGuiInputTextFlags_EscapeClearsAll))
			{
				matches = login::db::ListCharacterMatches(search);
			}

			ImGui::SameLine();
			if (ImGui::Button("Add Character"))
			{
				// reset to defaults
				interim_profile = {};
				ImGui::OpenPopup("Add Character");
			}

			if (ImGui::BeginPopupModal("Add Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
			{
				ImGui::InputText("Account##createcharacter", &interim_profile.accountName);
				ImGui::Spacing();

				ImGui::InputText("Server##createcharacter", &interim_profile.serverName);
				ImGui::Spacing();

				ImGui::InputText("Name##createcharacter", &interim_profile.characterName);
				ImGui::Spacing();

				if (ImGui::Button("OK##createcharacter", ImVec2(120, 0)))
				{
					login::db::CreateCharacter(interim_profile);
					ImGui::CloseCurrentPopup();
				}

				ImGui::SetItemDefaultFocus();
				ImGui::SameLine();
				if (ImGui::Button("Cancel##createcharacter", ImVec2(120, 0)))
				{
					ImGui::CloseCurrentPopup();
				}

				ImGui::EndPopup();
			}

			ImGui::PushID("mainlist");
			if (ImGui::BeginTable("##maintable", 5, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_Borders | ImGuiTableFlags_NoBordersInBody))
			{
				ImGui::TableSetupColumn("Account");
				ImGui::TableSetupColumn("Server");
				ImGui::TableSetupColumn("Character");
				ImGui::TableSetupColumn("Persona");
				ImGui::TableSetupColumn("##buttons");
				ImGui::TableHeadersRow();

				for (const auto& match : matches)
				{
					ImGui::PushID(match.serverName.c_str());
					ImGui::PushID(match.characterName.c_str());

					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					// this allows right clicking
					bool is_selected = false;
					ImGui::Selectable("##rowselect", &is_selected, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap);
					if (ImGui::IsItemHovered() && ImGui::IsItemClicked(ImGuiMouseButton_Right))
						ImGui::OpenPopup("row_popup");

					if (ImGui::BeginPopup("row_popup"))
					{
						if (ImGui::Selectable("Edit"))
						{
							interim_profile = {};
							interim_profile.serverName = match.serverName;
							interim_profile.characterName = match.characterName;
							login::db::ReadCharacter(interim_profile);

							selected = std::make_pair(match.serverName, match.characterName);
						}

						if (ImGui::Selectable("Remove"))
							login::db::DeleteCharacter(match.serverName, match.characterName);

						ImGui::EndPopup();
					}

					ImGui::SameLine();
					ImGui::Text(match.accountName.c_str());

					ImGui::TableNextColumn();
					ImGui::Text(match.serverName.c_str());

					ImGui::TableNextColumn();
					ImGui::Text(match.characterName.c_str());

					ImGui::TableNextColumn();
					if (match.characterClass.empty())
						ImGui::Text("<None>");
					else
						ImGui::Text("%s %d", match.characterClass.c_str(), match.characterLevel);

					ImGui::TableNextColumn();
					if (ImGui::SmallButton("Play"))
					{
						LoginInstance instance;
						instance.Server = match.serverName;
						instance.Character = match.characterName;

						LoadCharacter(instance);
					}

					ImGui::SameLine();
					// this needs to be here to handle the fact that hotkey isn't optional
					static std::optional<std::string> hotkey;
					if (ImGui::SmallButton("...##playwithparams"))
					{
						interim_profile = {};
						interim_profile.serverName = match.serverName;
						interim_profile.characterName = match.characterName;
						hotkey = {};
						ImGui::OpenPopup("Play With Params");
					}

					if (ImGui::BeginPopupModal("Play With Params", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
					{
						// input box for hotkey (optional)
						if (ImGui::Button("Hotkey"))
							ImGui::OpenPopup("Input Hotkey");

						ImGui::SameLine();
						ImGui::Text("%s", hotkey ? hotkey->c_str() : "<None>");

						if (ImGui::BeginPopupModal("Input Hotkey", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
						{
							ShowHotkeyWindow(hotkey);

							ImGui::Separator();
							if (ImGui::Button("OK"))
								ImGui::CloseCurrentPopup();

							ImGui::EndPopup();
						}

						// input for eq path override (optional)
						if (ImGui::Button("EQ Path"))
							ImGui::OpenPopup("Input EQ Path");

						ImGui::SameLine();
						ImGui::Text("%s", interim_profile.eqPath ? interim_profile.eqPath->c_str() : "<Default>");

						if (ImGui::BeginPopupModal("Input EQ Path", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
						{
							SetEQDir(interim_profile.eqPath);

							ImGui::Separator();
							if (ImGui::Button("OK"))
								ImGui::CloseCurrentPopup();

							ImGui::EndPopup();
						}

						if (ImGui::Button("Cancel"))
							ImGui::CloseCurrentPopup();


						ImGui::SameLine();
						ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetContentRegionAvail().x - ButtonWidth("Cancel"));
						if (ImGui::Button("OK", ImVec2(ButtonWidth("Cancel"), ImGui::GetStyle().FramePadding.y * 2 + ImGui::CalcTextSize("Cancel").y)))
						{
							LoginInstance instance;
							instance.Server = interim_profile.serverName;
							instance.Character = interim_profile.characterName;
							instance.Hotkey = hotkey;
							instance.EQPath = interim_profile.eqPath;

							LoadCharacter(instance);

							ImGui::CloseCurrentPopup();
						}

						ImGui::EndPopup();
					}

					ImGui::PopID();
					ImGui::PopID();
				}

				if (selected)
					ImGui::OpenPopup("Edit Character");

				if (ImGui::BeginPopupModal("Edit Character", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
				{
					ImGui::InputText("Account##editcharacter", &interim_profile.accountName);
					ImGui::Spacing();

					ImGui::InputText("Server##editcharacter", &interim_profile.serverName);
					ImGui::Spacing();

					ImGui::InputText("Name##editcharacter", &interim_profile.characterName);
					ImGui::Spacing();

					if (ImGui::Button("OK##editcharacter", ImVec2(120, 0)))
					{
						if (selected)
							login::db::UpdateCharacter(selected->first, selected->second, interim_profile);

						selected = {};
						interim_profile = {};
						ImGui::CloseCurrentPopup();
					}

					ImGui::SetItemDefaultFocus();
					ImGui::SameLine();
					if (ImGui::Button("Cancel##editcharacter", ImVec2(120, 0)))
					{
						ImGui::CloseCurrentPopup();
					}

					ImGui::EndPopup();
				}

				ImGui::EndTable();
			}
			ImGui::PopID();

			ImGui::EndChild();
			ImGui::EndTabItem();
		}

		ImGui::PopID();

		ImGui::EndTabBar();
	}

	ImGui::PopStyleVar();
}

struct SizedProfileRecord
{
	ProfileRecord profile;
	std::string level_text;
	float level_size;
	float class_size;
};
void ShowAutoLoginMenu()
{
	ImGui::PushID("contextmenu");

	bool is_paused = false;
	if (auto raw_pause = login::db::ReadSetting("is_paused"))
		is_paused = GetBoolFromString(*raw_pause, false);

	ImGui::PushItemFlag(ImGuiItemFlags_SelectableDontClosePopup, true);
	if (ImGui::MenuItem(fmt::format("AutoLogin is {}", is_paused ? "Paused" : "Running").c_str()))
		login::db::WriteSetting("is_paused", !is_paused ? "true" : "false");
	ImGui::PopItemFlag();

	if (ImGui::BeginMenu("Quick Launch"))
	{
		if (ImGui::MenuItem("Without Login"))
			LaunchCleanSession();

		if (ImGui::BeginMenu("Profiles"))
		{
			for (const auto& group : login::db::ListProfileGroups())
			{
				ImGui::PushID(group.c_str());

				if (ImGui::BeginMenu(group.c_str()))
				{
					std::vector<SizedProfileRecord> profiles;
					float largest_level = 0.f;
					float largest_class = 0.f;

					for (auto& profile : login::db::GetProfiles(group))
					{
						auto level_text = fmt::format("{}", profile.characterLevel);
						auto level_size = ImGui::CalcTextSize(level_text.c_str()).x;
						if (level_size > largest_level) largest_level = level_size;

						auto class_size = ImGui::CalcTextSize(profile.characterClass.c_str()).x;
						if (class_size > largest_class) largest_class = class_size;

						profiles.emplace_back(SizedProfileRecord{
							std::move(profile),
							std::move(level_text),
							level_size,
							class_size
							});
					}

					for (auto& sized_profile : profiles)
					{
						auto& profile = sized_profile.profile;
						ImGui::PushID(profile.characterName.c_str());
						ImGui::PushID(profile.serverName.c_str());

						if (ImGui::SmallCheckbox("##checked", &profile.checked))
							login::db::UpdateProfile(profile);

						ImGui::SameLine();
						constexpr ImGuiSelectableFlags selectable_flags = ImGuiSelectableFlags_SelectOnRelease | ImGuiSelectableFlags_NoSetKeyOwner | ImGuiSelectableFlags_SetNavIdOnHover | ImGuiSelectableFlags_SpanAvailWidth;
						if (ImGui::Selectable("[", false, selectable_flags))
						{
							LoginInstance instance;
							instance.ProfileGroup = group;
							instance.Server = profile.serverName;
							instance.Character = profile.characterName;
							if (!profile.hotkey.empty()) instance.Hotkey = profile.hotkey;

							LoadCharacter(instance);
						}

						ImGui::SameLine(0, largest_level - ImGui::CalcTextSize(sized_profile.level_text.c_str()).x);
						ImGui::TextUnformatted(sized_profile.level_text.c_str());

						ImGui::SameLine(); ImGui::TextUnformatted(" ");

						ImGui::SameLine(0, largest_class - ImGui::CalcTextSize(profile.characterClass.c_str()).x);
						ImGui::TextUnformatted(profile.characterClass.c_str());

						ImGui::SameLine(0, 0); ImGui::Text("] %s ", profile.characterName.c_str());

						ImGui::PopID();
						ImGui::PopID();
					}

					ImGui::EndMenu();
				}

				if (ImGui::IsItemClicked(ImGuiMouseButton_Left))
					LoadProfileGroup(group);

				ImGui::PopID();
			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Characters"))
		{
			for (const auto& server : login::db::ListServers())
			{
				ImGui::PushID(server.c_str());

				if (ImGui::BeginMenu(server.c_str()))
				{
					std::vector<SizedProfileRecord> profiles;
					float largest_level = 0.f;
					float largest_class = 0.f;

					for (auto& profile : login::db::ListCharactersOnServer(server))
					{
						auto level_text = fmt::format("{}", profile.characterLevel);
						auto level_size = ImGui::CalcTextSize(level_text.c_str()).x;
						if (level_size > largest_level) largest_level = level_size;

						auto class_size = ImGui::CalcTextSize(profile.characterClass.c_str()).x;
						if (class_size > largest_class) largest_class = class_size;

						profiles.emplace_back(SizedProfileRecord{
							std::move(profile),
							std::move(level_text),
							level_size,
							class_size
							});
					}

					for (auto& sized_profile : profiles)
					{
						auto& profile = sized_profile.profile;
						ImGui::PushID(profile.characterName.c_str());
						ImGui::PushID(profile.serverName.c_str());

						constexpr ImGuiSelectableFlags selectable_flags = ImGuiSelectableFlags_SelectOnRelease | ImGuiSelectableFlags_NoSetKeyOwner | ImGuiSelectableFlags_SetNavIdOnHover | ImGuiSelectableFlags_SpanAvailWidth;
						if (ImGui::Selectable("[", false, selectable_flags))
						{
							LoginInstance instance;
							instance.Server = profile.serverName;
							instance.Character = profile.characterName;

							LoadCharacter(instance);
						}

						ImGui::SameLine(0, largest_level - ImGui::CalcTextSize(sized_profile.level_text.c_str()).x);
						ImGui::TextUnformatted(sized_profile.level_text.c_str());

						ImGui::SameLine(); ImGui::TextUnformatted(" ");

						ImGui::SameLine(0, largest_class - ImGui::CalcTextSize(profile.characterClass.c_str()).x);
						ImGui::TextUnformatted(profile.characterClass.c_str());

						ImGui::SameLine(0, 0); ImGui::Text("] %s ", profile.characterName.c_str());

						ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.25f);
						ImGui::SameLine(); ImGui::Text(profile.accountName.c_str());
						ImGui::PopStyleVar();

						ImGui::PopID();
						ImGui::PopID();
					}

					ImGui::EndMenu();
				}

				ImGui::PopID();
			}

			ImGui::EndMenu();
		}

		ImGui::EndMenu();
	}

	ImGui::PopID();
}

#pragma endregion

bool HandleAutoLoginMenuCommand(WPARAM wParam, LPARAM lParam)
{
	int menuId = GetUnmaskedMenuId(static_cast<int>(wParam));

	switch (menuId)
	{
	case ID_MENU_MQ2AUTOLOGIN:
		break;

	case ID_PROFILES_LAUNCH_CLEAN:
		LaunchCleanSession();
		break;

	case ID_FILE_MQ2LOGINIS:
	{
		HMENU hSubMenu = GetSubMenu(hMenu, 0);
		//MENUITEMINFOA mi2 = { sizeof(MENUITEMINFOA) };

		//char Title[64];
		//mi2.dwTypeData = Title;
		//mi2.cch = 64;
		//mi2.fMask = MIIM_DATA | MIIM_SUBMENU | MIIM_ID | MIIM_STATE | MIIM_STRING;
		//GetMenuItemInfo(hSubMenu, (UINT)wParam, MF_BYCOMMAND, &mi2);

		//char szText[64] = { 0 };
		//mi2.fMask = MIIM_STRING | MIIM_STATE;
		//if (mi2.fState & MF_CHECKED)
		//{
		//	mi2.fState = MF_UNCHECKED;
		//	strcpy_s(szText, "MQ2Login is: Disabled");
		//	WritePrivateProfileBool("Settings", "UseMQ2Login", false, internal_paths::AutoLoginIni.c_str());
		//}
		//else
		//{
		//	mi2.fState = MF_CHECKED;
		//	strcpy_s(szText, "MQ2Login is: Enabled");
		//	WritePrivateProfileBool("Settings", "UseMQ2Login", true, internal_paths::AutoLoginIni.c_str());
		//}

		//mi2.cch = (UINT)strlen(szText) + 1;
		//mi2.dwTypeData = szText;
		//SetMenuItemInfo(hSubMenu, (UINT)wParam, false, &mi2);

		MENUITEMINFOA mi2 = { sizeof(MENUITEMINFOA) };
		GetMenuItemInfo(hSubMenu, (UINT)wParam, MF_BYCOMMAND, &mi2);

		// Update enabled state
		if (mi2.fState & MF_CHECKED)
		{
			mi2.fState = MF_UNCHECKED;
			login::db::WriteSetting("is_paused", "false");
		}
		else
		{
			mi2.fState = MF_CHECKED;
			login::db::WriteSetting("is_paused", "true");
		}

		SetMenuItemInfo(hSubMenu, ID_FILE_MQ2LOGINIS, FALSE, &mi2);
		break;
	}

	case ID_CHARACTER_EDIT:
	{
		auto loginIter = LoginMap.find("Popups");
		if (loginIter != LoginMap.end())
		{
			auto& popupMap = loginIter->second;

			auto popupIter = popupMap.find((DWORD)wParam);
			if (popupIter != popupMap.end())
			{
				const ProfileInfo& pPopupinfo = popupIter->second;
				char szCharName[128] = { 0 };
				bool bChecked = false;

				{
					MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
					mi.fMask = MIIM_DATA | MIIM_SUBMENU | MIIM_ID | MIIM_STATE | MIIM_STRING;
					mi.cch = 128;
					mi.dwTypeData = szCharName;
					GetMenuItemInfo(hProfilesMenu, pPopupinfo.PID, MF_BYCOMMAND, &mi);

					bChecked = (mi.fState & MF_CHECKED) != 0;
				}

				// szCharName = 0x00196694 "luclin->naeru (Loaded)"
				if (char* pDest = strstr(szCharName, "->"))
				{
					if (char* pDest2 = strstr(pDest, " "))
					{
						pDest2[0] = '\0';
					}
				}

				if (!szCharName[0])
					break;

				auto iter = LoginMap.find(pPopupinfo.CharacterName);
				if (iter != LoginMap.end())
				{
					auto& piMap = iter->second;

					auto piIter = piMap.find(pPopupinfo.PID);
					if (piIter != piMap.end())
					{
						const ProfileInfo& pi = piIter->second;

						//drinal:shadowchick_Blob
						if (char* pDest = strchr(szCharName, ']'))
						{
							pDest[0] = '\0';
							pDest += 2;
							strcpy_s(szCharName, pDest);
						}

						char szServer[64] = { 0 };
						if (char* pDest = strchr(szCharName, '-'))
						{
							pDest[0] = '\0';
							strcpy_s(szServer, szCharName);
							pDest += 2;
							strcpy_s(szCharName, pDest);
						}

						const std::string& ini = pi.Inifile;
						std::string keyName = fmt::format("{}:{}_Blob", szServer, szCharName);

						if (pPopupinfo.profileName == "Check" || pPopupinfo.profileName == "Uncheck")
						{
							bChecked = !bChecked;

							// Toggle check
							MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
							mi.fMask = MIIM_STATE;
							mi.fState = bChecked ? MF_CHECKED : MF_UNCHECKED;
							SetMenuItemInfo(hProfilesMenu, pPopupinfo.PID, MF_BYCOMMAND, &mi);

							std::string blob = GetPrivateProfileString(pPopupinfo.CharacterName, keyName, "", ini);
							if (!blob.empty())
							{
								// strip off the =0 or =1
								size_t pos = blob.find("=");
								if (pos != std::string::npos)
								{
									blob = blob.substr(0, pos);
								}
								blob.append(bChecked ? "=1" : "=0");

								WritePrivateProfileString(pPopupinfo.CharacterName, keyName, blob, ini);
							}
						}
						else if (pPopupinfo.profileName == "Delete")
						{
							::WritePrivateProfileStringA(pPopupinfo.CharacterName.c_str(), keyName.c_str(), nullptr, ini.c_str());
							DeleteMenu(hProfilesMenu, pPopupinfo.PID, MF_BYCOMMAND);

							piMap.erase(piIter);

							// FIXME: No constants!
							// If there are only 3 items left, those are the load all/unload all/break items. Remove them all.
							if (piMap.size() == 3)
							{
								char szMenuName[64];

								// Delete the profile sub menu. Gotta find it first.
								int menuCount = GetMenuItemCount(hProfilesMenu);
								for (int i = 0; i < menuCount; ++i)
								{
									// Get the title of this menu item
									MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
									mi.fMask = MIIM_DATA | MIIM_SUBMENU | MIIM_ID | MIIM_STRING;
									mi.dwTypeData = szMenuName;
									mi.cch = 64;
									GetMenuItemInfo(hProfilesMenu, i, TRUE, &mi);

									if (ci_equals(szMenuName, pPopupinfo.CharacterName))
									{
										DeleteMenu(hProfilesMenu, i, MF_BYPOSITION);
										break;
									}
								}

								// delete the piMap too.
								LoginMap.erase(iter);
							}
						}
						else if (pPopupinfo.profileName == "Edit")
						{
							std::string blob = GetPrivateProfileString(pPopupinfo.CharacterName, keyName, "", ini);
							size_t pos = blob.find("=");
							if (pos != std::string::npos)
							{
								blob = blob.substr(0, pos);
							}

							std::string path = GetPrivateProfileString(pPopupinfo.CharacterName, "EQPath", "", ini);

							ProfileRecord record = ProfileRecord::FromBlob(blob);
							bNewProfile = false;

							SetWindowText(hProfileEdit, pPopupinfo.CharacterName.c_str());
							SetWindowText(hLoginEdit, record.accountName.c_str());
							SetWindowText(hPassEdit, record.accountPassword.c_str());
							SetWindowText(hServerEdit, szServer);
							SetWindowText(hCharEdit, record.characterName.c_str());
							pHotKeyCtrl->SetHotKey(record.hotkey);
							SetWindowText(hPathEdit, path.c_str());

							// Set character level
							std::string levelText = std::to_string(record.characterLevel);
							SetWindowText(hLevelEdit, levelText.c_str());

							// Select character class
							SelectCharacterClass(record.characterClass);

							ShowWindow(hEditProfileWnd, SW_SHOWNORMAL);
						}
					}
				}
			}
		}
		break;
	}

	case ID_MENU_CHARACTER:
	{
		MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
		mi.fMask = MIIM_DATA;
		GetMenuItemInfo(hProfilesMenu, (UINT)wParam, FALSE, &mi);

		char szServer[64] = { 0 };
		strcpy_s(szServer, (char*)mi.dwItemData);

		bool loadAll = false;
		bool unloadAll = false;

		auto iter = LoginMap.find(szServer);
		if (iter != LoginMap.end())
		{
			auto& piMap = iter->second;

			auto iter2 = piMap.find((DWORD)wParam);
			if (iter2 != piMap.end())
			{
				const ProfileInfo& pi = iter2->second;

				if (pi.CharacterName == PROFILE_LOAD_ALL)
				{
					loadAll = true;
				}
				else if (pi.CharacterName == PROFILE_UNLOAD_ALL)
				{
					unloadAll = true;
				}
			}
		}

		if (loadAll || unloadAll)
		{
			// Load/Unload all profiles that are checked
			auto iter = LoginMap.find(szServer);
			if (iter != LoginMap.end())
			{
				auto& piMap = iter->second;

				for (auto& pPi : piMap)
				{
					DWORD dwId = pPi.first;
					ProfileInfo& pi = pPi.second;

					UINT state = GetMenuState((HMENU)hProfilesMenu, dwId, MF_BYCOMMAND);
					bool bChecked = (state & MF_CHECKED);

					if (bChecked && pi.Loaded != loadAll)
					{
						LoadIt(pi, dwId);
					}
				}
			}
		}
		else
		{
			iter = LoginMap.find(szServer);
			if (iter != LoginMap.end())
			{
				auto& piMap = iter->second;

				auto iter2 = piMap.find((DWORD)wParam);
				if (iter2 != piMap.end())
				{
					ProfileInfo& pi = iter2->second;
					LoadIt(pi, (int)wParam);
				}
			}
		}
		break;
	}

	case ID_PROFILES_CREATENEW:
		bNewProfile = true;
		ShowWindow(hEditProfileWnd, SW_SHOW);
		break;

	case ID_OPEN_MQ2AUTOLOGIN_INI:
	{
		std::string iniDir = fs::path{ internal_paths::AutoLoginIni }.parent_path().string();

		::ShellExecuteA(nullptr, "open", internal_paths::AutoLoginIni.c_str(), nullptr, iniDir.c_str(), SW_SHOW);
		break;
	}

	case ID_PROFILES_IMPORT:
		ShowImportDialog();
		break;

	// something we don't handle, bail out
	default:
		return false;
	}

	return true;
}

bool HandleAutoLoginWindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* result)
{
	*result = 0;

	DWORD pid = (DWORD)lParam;

	switch (msg)
	{
	case WM_MENURBUTTONUP:
	{
		HMENU hMenu = (HMENU)lParam;
		int nPos = (int)wParam;

		// This function doesn't validate that we're only right click on profile menus.
		return HandleAutoLoginMenuRightclick(hMenu, GetMenuItemID(hMenu, nPos), lParam);
	}

	case WM_COMMAND:
		return HandleAutoLoginMenuCommand(wParam, lParam);

	case WM_USER_REGISTER_HK:
		ActOnPid(pid, [](const DWORD id, ProfileInfo& pi) { RegisterGlobalHotkey(GetEQWindowHandleForProcessId(pi.PID), pi.Hotkey); });
		break;

	case WM_USER_UNREGISTER_HK:
		ActOnPid(pid, [](const DWORD id, ProfileInfo& pi) { UnregisterGlobalHotkey(pi.Hotkey); });
		break;

	case WM_USER_RESETLOADED:
		ActOnPid(pid, [&wParam](const DWORD id, ProfileInfo& pi) {
			ResetLoaded(pi, id, hProfilesMenu);
			if (wParam)
			{
				pi.Loaded = false;
				pi.PID = 0;
			}});
		break;

	case WM_USER_SETLOADED:
		ActOnPid(pid, [&wParam, &pid](const DWORD id, ProfileInfo& pi) {
			SetLoaded(pi, id, hProfilesMenu);
			if (wParam)
			{
				pi.Loaded = true;
				pi.PID = pid;
			}});
		break;

	case WM_USER_UPDATECLASS:
		ActOnPid(pid, [&wParam](const DWORD id, ProfileInfo& pi) {
			DWORD classId = (DWORD)wParam;
			pi.PlayerClass = GetClassShortName(classId);
			SetLoaded(pi, id, hProfilesMenu);
		});
		break;

	case WM_USER_UPDATELEVEL:
		ActOnPid(pid, [&wParam](const DWORD id, ProfileInfo& pi) {
			pi.PlayerLevel = (DWORD)wParam;
			SetLoaded(pi, id, hProfilesMenu);
		});
		break;

	default:
		return false;
	}

	if (InSendMessage()) ReplyMessage(true);

	return true;
}

bool EncryptData(DATA_BLOB* DataIn, DATA_BLOB* DataOut)
{
	return CryptProtectData(DataIn, nullptr, nullptr, nullptr, nullptr, 0, DataOut) != 0;
}


int BlobToStr(DATA_BLOB* Blob, std::string& outString)
{
	uint8_t* pb = Blob->pbData;
	char out[MAX_STRING];
	char* szOut = out;

	for (size_t i = 0; i < Blob->cbData; i++, pb++)
	{
		int b = (*pb & 0xF0) >> 4;
		*szOut++ = (char)((b <= 9) ? b + '0' : (b - 10) + 'A');

		b = *pb & 0x0F;
		*szOut++ = (char)((b <= 9) ? b + '0' : (b - 10) + 'A');
	}
	*szOut++ = 0;

	outString = out;
	return Blob->cbData;
}

void FillProfile(const std::string& Profile, const std::string& Server, const std::string& Character, const std::string& Inifile, const std::string& Hotkey,
	const std::string& CharClass, const int CharLevel, bool bCheck, const std::string& Login)
{
	char szStuff[MAX_STRING] = { 0 };
	sprintf_s(szStuff, "[%s] %s", Login.c_str(), Character.c_str());

	bool bAddNewProfile = true;
	auto szMenuDataBuffer = std::make_unique<char[]>(2048);

	HMENU hAddMenu = nullptr;

	int menuCount = GetMenuItemCount(hProfilesMenu);
	for (int j = 0; j < menuCount; j++)
	{
		// Get the title of this menu item
		std::string menuTitle;

		{
			MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
			mi.fMask = MIIM_DATA | MIIM_SUBMENU | MIIM_ID | MIIM_STRING;
			mi.dwTypeData = szMenuDataBuffer.get();
			mi.cch = 2048;
			GetMenuItemInfo(hProfilesMenu, j, TRUE, &mi);

			menuTitle = mi.dwTypeData ? mi.dwTypeData : "";
		}

		// check if we found the menu we're looking for
		if (ci_equals(menuTitle, Profile))
		{
			// Found the matching profile
			bAddNewProfile = false;

			// Look for matching character name
			HMENU hMenuPopup2 = GetSubMenu(hProfilesMenu, j);
			if (!hMenuPopup2)
				continue;

			// Search submenus for matching character menu
			int subMenuCount = GetMenuItemCount(hMenuPopup2);
			for (int i = 0; i < subMenuCount; i++)
			{
				MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
				mi.dwTypeData = szMenuDataBuffer.get();
				mi.fMask = MIIM_DATA | MIIM_SUBMENU | MIIM_ID | MIIM_STRING;
				mi.cch = 2048;
				GetMenuItemInfo(hMenuPopup2, i, TRUE, &mi);

				const char* pMenuTitle2 = mi.dwTypeData;

				// Check if the menu title starts with the expected prefix. If this matches it means the
				// character menu item already exists.
				if (pMenuTitle2 && pMenuTitle2[0] && _strnicmp(pMenuTitle2, szStuff, strlen(szStuff)) == 0)
				{
					// Update profile
					ProfileInfo& pi = LoginMap[menuTitle][mi.wID];
					pi.Hotkey = Hotkey;
					pi.PlayerClass = CharClass;
					pi.PlayerLevel = CharLevel;

					if (pi.Loaded)
						SetLoaded(pi, mi.wID, hMenuPopup2);
					else
						ResetLoaded(pi, mi.wID, hMenuPopup2);

					return;
				}
			}

			// Profile exists but character doesn't. We'll add character to this menu
			hAddMenu = hMenuPopup2;
			break;
		}
	}

	if (bAddNewProfile)
	{
		HMENU hSubMenu = CreatePopupMenu();
		hAddMenu = hSubMenu;
		int parentMenuId = ID_MENU_PROFILE + gMenuItemCount;
		AppendMenuA(hProfilesMenu, MF_STRING, parentMenuId, Profile.c_str());

		// Set this new submenu to the profile menu item
		{
			MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
			mi.fMask = MIIM_SUBMENU;
			mi.hSubMenu = hSubMenu;
			SetMenuItemInfo(hProfilesMenu, parentMenuId, FALSE, &mi);
		}

		// add "Load All" menu item
		{
			int menuId = ID_MENU_CHARACTER + gMenuItemCount;

			ProfileInfo pi;
			pi.CharacterName = PROFILE_LOAD_ALL;
			pi.profileName = Profile;
			pi.Inifile = Inifile;

			AppendMenuA(hSubMenu, MF_STRING, menuId, pi.CharacterName.c_str());
			LoginMap[Profile][menuId] = pi;

			MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
			mi.fMask = MIIM_DATA;
			mi.dwItemData = (ULONG_PTR)LoginMap[Profile][menuId].profileName.c_str();
			SetMenuItemInfo(hSubMenu, menuId, FALSE, &mi);

			gMenuItemCount++;
		}

		// add "Unload All" menu item
		{
			int menuId = ID_MENU_CHARACTER + gMenuItemCount;

			ProfileInfo pi;
			pi.CharacterName = PROFILE_UNLOAD_ALL;
			pi.profileName = Profile;
			pi.Inifile = Inifile;

			AppendMenuA(hSubMenu, MF_STRING, menuId, pi.CharacterName.c_str());
			LoginMap[Profile][menuId] = pi;

			MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
			mi.fMask = MIIM_DATA;
			mi.dwItemData = (ULONG_PTR)LoginMap[Profile][menuId].profileName.c_str();
			SetMenuItemInfo(hSubMenu, menuId, FALSE, &mi);

			gMenuItemCount++;
		}

		// add separator

		{
			int menuId = ID_MENU_CHARACTER + gMenuItemCount;

			ProfileInfo pi;
			pi.CharacterName = "Menu Break";
			pi.profileName = Profile;
			pi.Inifile = Inifile;

			AppendMenu(hSubMenu, MF_MENUBARBREAK, menuId, nullptr);
			LoginMap[Profile][menuId] = pi;

			gMenuItemCount++;
		}
	}

	// If we have a menu to add the character to, do it.
	if (hAddMenu)
	{
		std::string label;

		if (!CharClass.empty())
			label = fmt::format("{} [{:d} {}] {}", szStuff, CharLevel, CharClass, Hotkey);
		else
			label = fmt::format("{} {}", szStuff, Hotkey);

		int menuId = ID_MENU_CHARACTER + gMenuItemCount;
		AppendMenuA(hAddMenu, (bCheck ? MF_STRING | MF_CHECKED : MF_STRING | MF_UNCHECKED), menuId, label.c_str());

		gMenuItemCount++;

		ProfileInfo pi;
		pi.CharacterName = szStuff;
		pi.profileName = Profile;
		pi.Inifile = Inifile;
		pi.Hotkey = Hotkey;
		pi.PlayerClass = CharClass;
		pi.PlayerLevel = CharLevel;

		LoginMap[Profile][menuId] = pi;

		MENUITEMINFOA mi = { sizeof(MENUITEMINFOA) };
		mi.fMask = MIIM_DATA;
		mi.dwItemData = (ULONG_PTR)LoginMap[Profile][menuId].profileName.c_str();
		SetMenuItemInfo(hAddMenu, menuId, FALSE, &mi);
	}
}

void LoadProfiles()
{
	auto profiles = LoadAutoLoginProfiles(internal_paths::AutoLoginIni);

	for (ProfileGroup& pg : profiles)
	{
		for (ProfileRecord& record : pg.records)
		{
			// add server name to character name
			if (!record.serverName.empty())
				record.characterName = fmt::format("{}->{}", record.serverName, record.characterName);

			FillProfile(record.profileName, record.serverName, record.characterName,
				internal_paths::AutoLoginIni, record.hotkey,
				record.characterClass, record.characterLevel, record.checked, record.accountName);
		}
	}
}

// ideally we don't need to leak this function into Eventsink.
void AutoLoginRemoveProcess(DWORD processId)
{
	// eqgame terminated...
	for (auto& i : LoginMap)
	{
		for (auto& j : i.second)
		{
			if (!j.second.CharacterName.empty())
			{
				if (j.second.PID == processId)
				{
					SendMessageA(hMainWnd, WM_USER_UNREGISTER_HK, 0, j.second.PID);
					SendMessageA(hMainWnd, WM_USER_RESETLOADED, 0, j.second.PID);

					j.second.Loaded = false;
					j.second.PID = 0;
					break;
				}
			}
		}
	}
}

INT_PTR CALLBACK ExportProc(HWND hWnd, UINT MSG, WPARAM wParam, LPARAM lParam)
{
	switch (MSG)
	{
	case WM_INITDIALOG:
	{
		hAskPassEdit = GetDlgItem(hWnd, IDC_ASKPASSEDIT_PATH);

		// Default position is centered on the screen
		RECT rect;
		::GetWindowRect(hWnd, &rect);

		::SetWindowPos(hWnd, nullptr, ::GetSystemMetrics(SM_CXFULLSCREEN) / 2 - (rect.right - rect.left) / 2,
			::GetSystemMetrics(SM_CYFULLSCREEN) / 2 - (rect.bottom - rect.top) / 2, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
		::SendMessageA(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)::LoadIconA(g_hInst, MAKEINTRESOURCE(IDI_ICON1)));

		return TRUE;
	}

	case WM_SHOWWINDOW:
		SetWindowText(hAskPassEdit, "");
		CheckRadioButton(hAskPassWnd, IDC_RADIO_IMPORT, IDC_RADIO_EXPORT, IDC_RADIO_IMPORT);
		break;

	case WM_COMMAND:
	{
		switch (wParam)
		{
		case IDC_ASKPASSBUTTON_BROWSE:
		{
			char szPass[MAX_STRING] = { 0 };
			GetWindowText(hAskPassEdit, szPass, sizeof(szPass));

			if (strlen(szPass) < 4)
			{
				MessageBox(hAskPassWnd, "Password must be at least 4 characters", "AutoLogin Profile Import/Export", MB_OK | MB_SYSTEMMODAL);
				break;
			}

			UINT Import = IsDlgButtonChecked((HWND)hAskPassWnd, IDC_RADIO_IMPORT);
			ShowWindow(hAskPassWnd, SW_HIDE);

			if (Import)
				DoImport(szPass);
			else
				DoExport(szPass);

			return TRUE;
		}
		case IDC_BUTTON_BROWSE: {
			BROWSEINFO bi;
			LPITEMIDLIST pidl;
			char mydir[MAX_PATH];

			bi.hwndOwner = hWnd;
			bi.pidlRoot = nullptr;
			bi.pszDisplayName = mydir;
			bi.lpszTitle = "Select a folder";
			bi.ulFlags = BIF_RETURNONLYFSDIRS;
			bi.lpfn = nullptr;
			bi.lParam = 0;

			//Call the directory browse dialog and assign it to a ITEMIDLIST
			if (pidl = ::SHBrowseForFolderA(&bi)) {

				//Return the selected path
				if (SHGetPathFromIDList(pidl, mydir)) {
					SetWindowText(hPathEdit, mydir);
				}
				CoTaskMemFree(pidl);
			}

			return TRUE;
		}

		default: break;
		}
	}

	case WM_SYSCOMMAND:
		switch (LOWORD(wParam))
		{
		case SC_CLOSE:
		case WM_DESTROY:
			ShowWindow(hWnd, SW_HIDE);
			return TRUE;
		}
	default:
		break;
	}

	return FALSE;
}

INT_PTR CALLBACK SettingsProc(HWND hWnd, UINT MSG, WPARAM wParam, LPARAM lParam)
{
	switch (MSG)
	{
	case WM_INITDIALOG:
	{
		hProfileEdit = ::GetDlgItem(hWnd, IDC_EDIT_PROFILE);
		hLoginEdit = ::GetDlgItem(hWnd, IDC_EDIT_LOGIN);
		hPassEdit = ::GetDlgItem(hWnd, IDC_EDIT_PASS);
		hServerEdit = ::GetDlgItem(hWnd, IDC_EDIT_SERVER);
		hCharEdit = ::GetDlgItem(hWnd, IDC_EDIT_CHAR);
		HWND hHotkeyEdit = ::GetDlgItem(hWnd, IDC_EDIT_HOTKEY);
		hPathEdit = ::GetDlgItem(hWnd, IDC_EDIT_PATH);
		hBrowseButton = ::GetDlgItem(hWnd, IDC_BUTTON_BROWSE);
		hSaveProfileButton = ::GetDlgItem(hWnd, IDC_BUTTON_SAVE_PROFILE);
		hClassCombo = ::GetDlgItem(hWnd, IDC_COMBO_CCLASS);
		hLevelEdit = ::GetDlgItem(hWnd, IDC_EDIT_CLEVEL);

		// Make the hotkey control
		pHotKeyCtrl = new CHotKeyCtrl();
		pHotKeyCtrl->ConvertEditToHotKeyCtrl(hHotkeyEdit);

		// Default position is centered on the screen
		RECT rect;
		::GetWindowRect(hWnd, &rect);

		::SetWindowPos(hWnd, nullptr, ::GetSystemMetrics(SM_CXFULLSCREEN) / 2 - (rect.right - rect.left) / 2,
			::GetSystemMetrics(SM_CYFULLSCREEN) / 2 - (rect.bottom - rect.top) / 2, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
		::SendMessageA(hWnd, WM_SETICON, ICON_SMALL, (LPARAM)::LoadIconA(g_hInst, MAKEINTRESOURCE(IDI_ICON1)));

		::SetWindowTextA(hPathEdit, internal_paths::EQRoot.c_str());

		// Add the classes to the class combo
		int i = 0;
		for (auto& ci : ClassInfo)
		{
			// Set the string to the full name of the class, and the data to the index
			int index = (int)::SendMessageA(hClassCombo, CB_ADDSTRING, 0, (LPARAM)ci.Name);
			::SendMessageA(hClassCombo, CB_SETITEMDATA, index, i);

			i++;
		}

		return TRUE;
	}

	case WM_COMMAND:
	{
		uint16_t nCommand = HIWORD(wParam);
		int controlId = LOWORD(wParam);

		switch (controlId)
		{
		case IDC_BUTTON_BROWSE:
		{
			BROWSEINFO bi;
			LPITEMIDLIST pidl;
			char mydir[MAX_PATH];

			bi.hwndOwner = hWnd;
			bi.pidlRoot = nullptr;
			bi.pszDisplayName = mydir;
			bi.lpszTitle = "Select a folder";
			bi.ulFlags = BIF_RETURNONLYFSDIRS;
			bi.lpfn = nullptr;
			bi.lParam = 0;

			//Call the directory browse dialog and assign it to a ITEMIDLIST
			if (pidl = ::SHBrowseForFolderA(&bi))
			{
				//Return the selected path
				if (SHGetPathFromIDList(pidl, mydir))
				{
					SetWindowText(hPathEdit, mydir);
				}
				CoTaskMemFree(pidl);
			}

			return TRUE;
		}

		case IDC_BUTTON_SAVE_PROFILE:
		{
			char szTemp[1024] = { 0 };

			GetWindowText(hProfileEdit, szTemp, sizeof(szTemp));
			std::string profileName(szTemp);

			GetWindowText(hLoginEdit, szTemp, sizeof(szTemp));
			std::string login(szTemp);

			GetWindowText(hPassEdit, szTemp, sizeof(szTemp));
			std::string pass(szTemp);

			GetWindowText(hServerEdit, szTemp, sizeof(szTemp));
			std::string server(szTemp);

			GetWindowText(hCharEdit, szTemp, sizeof(szTemp));
			std::string charName(szTemp);

			GetWindowText(hLevelEdit, szTemp, sizeof(szTemp));
			int charLevel = GetIntFromString(szTemp, -1);

			std::string charClass = GetSelectedCharacterClass();

			GetWindowText(pHotKeyCtrl->GetHWnd(), szTemp, sizeof(szTemp));
			std::string hotkey(szTemp);

			GetWindowText(hPathEdit, szTemp, sizeof(szTemp));
			std::string eqPath(szTemp);

			if (login.empty() || pass.empty() || server.empty() || charName.empty() || eqPath.empty())
			{
				MessageBox(hEditProfileWnd, "Required fields:\n"
					" * Login\n"
					" * Password\n"
					" * Server\n"
					" * Character Name\n"
					" * EQ Path\n"
					"\n"
					"If Profile Set is empty, Server will be used as the Profile Set.",
					"Validation Error", MB_SYSTEMMODAL | MB_OK);
				break;
			}

			if (profileName.find(" ") != std::string::npos)
			{
				MessageBox(hEditProfileWnd, "Profile Set: can not contain any Spaces", "Create Profile Error", MB_SYSTEMMODAL | MB_OK);
				break;
			}

			if (profileName.empty())
			{
				profileName = server;
			}

			std::string savedName = fmt::format("{}->{}", server, charName);
			if (SaveBlob(profileName, login, pass, server, charName, eqPath, hotkey, charClass, charLevel, true, internal_paths::AutoLoginIni))
			{
				FillProfile(profileName, server, savedName, internal_paths::AutoLoginIni, hotkey, charClass, charLevel, true, login);

				WritePrivateProfileBool("Settings", "UseMQ2Login", true, internal_paths::AutoLoginIni);
				WritePrivateProfileString("Profiles", "DefaultEQPath", eqPath, internal_paths::AutoLoginIni);

				WritePrivateProfileString("Plugins", "mq2autologin", "1", internal_paths::MQini);

				if (bNewProfile)
				{
					sprintf_s(szTemp,
						"Login Profile Created for %s as \"%s\"\n"
						"\n"
						"You can launch this character now from the Profiles Menu.\n"
						"\n"
						"Additionally:\n"
						" * Right click the name of the character to mark it or unmark it for the Load All feature.\n"
						" * Left clicking a individual character name will either Load or unload it, its a toggle.",
						profileName.c_str(), savedName.c_str());

					MessageBox(hEditProfileWnd, szTemp, "AutoLogin Profile Editor", MB_SYSTEMMODAL | MB_OK);
				}
			}
			else
			{
				sprintf_s(szTemp, "Login Profile Already Existed for %s as \"%s\"", profileName.c_str(), savedName.c_str());
				MessageBox(hEditProfileWnd, szTemp, "AutoLogin Profile Editor", MB_SYSTEMMODAL | MB_OK);
			}

			return TRUE;
		}

		case IDC_BUTTON_CANCEL:
			ShowWindow(hWnd, SW_HIDE);
			return TRUE;

		default: break;
		}
	}

	case WM_SYSCOMMAND:
		switch (LOWORD(wParam))
		{
		case WM_DESTROY:
			delete pHotKeyCtrl;

		case SC_CLOSE:
			ShowWindow(hWnd, SW_HIDE);
			return TRUE;
		}
	default:
		break;
	}

	return FALSE;
}

void ReceivedMessageHandler(ProtoMessagePtr&& message)
{
	// TODO: This needs to handle identify messages (to fill loaded instance set)
	auto login_message = message->Parse<proto::login::LoginMessage>();
	switch (login_message.id())
	{
	case proto::login::MessageId::ProfileLoaded:
		if (login_message.has_payload())
		{
			proto::login::ProfileMethod profile;
			profile.ParseFromString(login_message.payload());

			if (profile.has_target() && profile.target().has_character() && message->GetSender() && message->GetSender()->has_pid())
			{
				ProfileMap& login = LoginMap[profile.profile()];

				std::string charString = fmt::format("[{}] {}->{}", profile.account(), profile.target().server(), profile.target().character());
				auto login_it = std::find_if(login.begin(), login.end(),
					[&charString](const auto& l) { return l.second.CharacterName == charString; });

				if (login_it != login.end() && message->GetSender())
				{
					login_it->second.Loaded = true;
					login_it->second.PID = message->GetSender()->pid();
					SendMessageA(hMainWnd, WM_USER_REGISTER_HK, login_it->first, login_it->second.PID);
					SendMessageA(hMainWnd, WM_USER_SETLOADED, login_it->first, login_it->second.PID);
				}
			}
		}

		break;

	case proto::login::MessageId::ProfileUnloaded:
		if (login_message.has_payload())
		{
			proto::login::ProfileMethod profile;
			profile.ParseFromString(login_message.payload());

			if (message->GetSender() && message->GetSender()->has_pid())
			{
				uint32_t pid = message->GetSender()->pid();

				ProfileMap& login = LoginMap[profile.profile()];
				auto login_it = std::find_if(login.begin(), login.end(),
					[&pid](const auto& l) { return l.second.PID == pid; });

				if (login_it != login.end())
				{
					SendMessageA(hMainWnd, WM_USER_UNREGISTER_HK, login_it->first, login_it->second.PID);
					SendMessageA(hMainWnd, WM_USER_RESETLOADED, login_it->first, login_it->second.PID);
				}
			}
		}

		break;

	case proto::login::MessageId::ProfileCharInfo:
		if (login_message.has_payload())
		{
			proto::login::CharacterInfoMissive charinfo;
			charinfo.ParseFromString(login_message.payload());

			if (message->GetSender() && message->GetSender()->has_pid())
			{
				uint32_t pid = message->GetSender()->pid();

				for (const auto& [profileKey, profile] : LoginMap)
				{
					for (const auto& [id, profileInfo] : profile)
					{
						if (profileInfo.PID == pid)
						{
							SendMessageA(hMainWnd, WM_USER_UPDATELEVEL, charinfo.level(), profileInfo.PID);
							SendMessageA(hMainWnd, WM_USER_UPDATECLASS, charinfo.class_(), profileInfo.PID);
							return;
						}
					}
				}
			}
		}

		break;

	case proto::login::MessageId::StartInstance:
		if (login_message.has_payload())
		{
			proto::login::StartInstanceMissive start;
			start.ParseFromString(login_message.payload());

			switch (start.method_case())
			{
			case proto::login::StartInstanceMissive::MethodCase::kDirect:
				if (start.direct().has_target())
				{
					DoPlainLogin(
						start.direct().target().server(),
						start.direct().login(),
						start.direct().password(),
						start.direct().target().has_character() ? start.direct().target().character() : ""
					);
				}
				break;

			case proto::login::StartInstanceMissive::MethodCase::kProfile:
				if (start.profile().has_target() && start.profile().target().has_character())
				{
					ProfileMap& login = LoginMap[start.profile().profile()];

					std::string charString = fmt::format("{}->{}", start.profile().target().server(), start.profile().target().character());
					auto login_it = std::find_if(login.begin(), login.end(),
						[&charString](const auto& login)
						{
							// CharacterName is `[account] server->char` -- assume none of the things have spaces, and grab only the server->char portion
							auto s = login.second.CharacterName.substr(login.second.CharacterName.find_first_of(' ') + 1);
							return s == charString;
						});

					if (login_it != login.end())
					{
						LoadIt(login_it->second, login_it->first);
					}
				}
				break;

			default:
				break;
			}

			break;
		}

		break;

	default:
		break;
	}
}

void InitializeAutoLogin()
{
	s_dropbox = postoffice::GetPostOffice().RegisterAddress("autologin", ReceivedMessageHandler);
	// TODO: build list of logged in instances from the list of registered clients in the post office
	// TODO: figure out how to determine hotkeys from that list

	// Get path to mq2autologin.ini
	fs::path pathAutoLoginIni = fs::path{ internal_paths::Config }  / "MQ2AutoLogin.ini";
	internal_paths::AutoLoginIni = pathAutoLoginIni.string();
	auto load_ini = login::db::InitDatabase((fs::path(internal_paths::Config) / "login.db").string());

	// do absolutely nothing until a master pass is set
	auto pass = login::db::ReadMasterPass();
	if (!pass)
	{
		LauncherImGui::OpenWindow(
			[&pass]() {
				bool is_open = true;
				if (ImGui::Begin("Enter Master Password", &is_open))
				{
					static const char* label = "Please Enter Master Password";
					ImGui::Text(label);
					ImGui::Spacing();

					// TODO: This can be a lot nicer -- also the hashing can take a bit so it should
					// probably happen in a thread to prevent the UI from hanging on slower computers
					static bool show_password = false;
					static std::string password;

					ImGuiInputTextFlags flags = ImGuiInputTextFlags_EnterReturnsTrue;
					if (!show_password) flags |= ImGuiInputTextFlags_Password;


					if (ImGui::InputText("##password", &password, flags))
					{
						if (login::db::ValidatePass(password, true))
						{
							login::db::CreateMasterPass(password);
							pass = password;
							is_open = false;
							label = "Please Enter Master Password";
						}
						else
						{
							label = "Incorrect Password, Please Enter Master Password";
						}
					}
					ImGui::Spacing();

					ImGui::Checkbox("Show password", &show_password);
					ImGui::Spacing();
				}

				ImGui::End();
				return is_open;
			},
			"Enter Master Password"
		);
	}

	if (pass)
	{
		if (load_ini) login::db::WriteProfileGroups(LoadAutoLoginProfiles(internal_paths::AutoLoginIni));

		// Initialize path to EQ
		internal_paths::EQRoot = login::db::ReadEQPath();
		if (internal_paths::EQRoot.empty())
		{
			internal_paths::EQRoot = GetPrivateProfileString("Profiles", "DefaultEQPath", "", internal_paths::AutoLoginIni);
			if (internal_paths::EQRoot.empty())
			{
				SPDLOG_ERROR("AutoLogin Error no EQ path specified, AutoLogin will not work.");
			}
			else
			{
				// update the path to the db
				login::db::CreateEQPath(internal_paths::EQRoot);
			}
		}

		HMENU hMainMenu = GetSubMenu(hMenu, 0);
		int menuItemCount = GetMenuItemCount(hMainMenu);
		for (int i = 0; i < menuItemCount; ++i)
		{
			char text[256];

			if (GetMenuStringA(hMainMenu, i, text, 256, MF_BYPOSITION))
			{
				if (!strcmp(text, "Profiles"))
				{
					hProfilesMenu = GetSubMenu(hMainMenu, i);
					break;
				}
			}
		}

		// create the profile editor window
		hEditProfileWnd = ::CreateDialogParamA(g_hInst, MAKEINTRESOURCE(IDD_PROFILE_EDIT),
			nullptr, SettingsProc, 0);

		hAskPassWnd = ::CreateDialogParamA(g_hInst, MAKEINTRESOURCE(IDD_PROFILE_EXPORT),
			nullptr, ExportProc, 0);

		// make the editmenu
		hEditPopup = CreatePopupMenu();

		ProfileMap& popupMap = LoginMap["Popups"];
		AppendMenuA(hEditPopup, MF_STRING, ID_CHARACTER_EDIT, "&Edit");
		popupMap[ID_CHARACTER_EDIT].profileName = "Edit";
		AppendMenuA(hEditPopup, MF_STRING, ID_CHARACTER_DELETE, "&Delete");
		popupMap[ID_CHARACTER_DELETE].profileName = "Delete";
		AppendMenuA(hEditPopup, MF_STRING, ID_CHARACTER_TOGGLE, "&Uncheck");
		popupMap[ID_CHARACTER_TOGGLE].profileName = "Uncheck";

		LoadProfiles();

		// Update enabled state
		//int ichecked = GetPrivateProfileInt("Settings", "UseMQ2Login", 0, internal_paths::AutoLoginIni);

		//char szText[64] = { 0 };
		//MENUITEMINFOA mi2 = { sizeof(MENUITEMINFOA) };
		//mi2.fMask = MIIM_STRING | MIIM_STATE;
		//if (!ichecked)
		//{
		//	mi2.fState = MF_UNCHECKED;
		//	strcpy_s(szText, "AutoLogin is: Disabled");
		//}
		//else
		//{
		//	mi2.fState = MF_CHECKED;
		//	strcpy_s(szText, "AutoLogin is: Enabled");
		//}

		//mi2.cch = (UINT)strlen(szText) + 1;
		//mi2.dwTypeData = szText;

		MENUITEMINFOA mi2 = { sizeof(MENUITEMINFOA) };
		//char Title[64];
		//mi2.dwTypeData = Title;
		//mi2.cch = 64;
		//mi2.fMask = MIIM_DATA | MIIM_SUBMENU | MIIM_ID | MIIM_STATE | MIIM_STRING;
		//GetMenuItemInfoA(hMainMenu, (UINT)wParam, MF_BYCOMMAND, &mi2);
		char paused_text[64] = { 0 };
		strcpy_s(paused_text, "Pause Login on Startup");
		mi2.cch = (UINT)strlen(paused_text) + 1;
		mi2.dwTypeData = paused_text;
		mi2.fMask = MIIM_STRING | MIIM_STATE;

		// Update enabled state
		if (GetBoolFromString(login::db::ReadSetting("is_paused").value_or("false"), false))
			mi2.fState = MF_CHECKED;
		else
			mi2.fState = MF_UNCHECKED;
		SetMenuItemInfoA(hMainMenu, ID_FILE_MQ2LOGINIS, FALSE, &mi2);

		LauncherImGui::AddMainPanel("AutoLogin", ShowAutoLoginWindow);
		LauncherImGui::AddContextGroup("AutoLogin Menu", ShowAutoLoginMenu);
	}
}

void ShutdownAutoLogin()
{
	s_dropbox.Remove();

	if (s_eqDirDialog != nullptr)
		IGFD_Destroy(s_eqDirDialog);
}
