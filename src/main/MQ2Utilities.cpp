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

#include "MQ2Mercenaries.h"
#include "MQ2Utilities.h"

#include <mq/api/Items.h>
#include <mq/base/WString.h>

#include <DbgHelp.h>
#include <PathCch.h>
#include <wil/resource.h>
#include <random>

#ifdef _DEBUG
#define DBG_SPEW // enable DebugSpew messages in debug builds
#endif

#define IsNaN(x) (x != x)

namespace mq {

//***************************************************************************
// Function:    DebugSpew
// Description: Outputs text to debugger, usage is same as printf ;)
//***************************************************************************

static void LogToFile(const char* szOutput)
{
	FILE* fOut = nullptr;

	const std::filesystem::path pathDebugSpew = std::filesystem::path(mq::internal_paths::Logs) / "DebugSpew.log";
	fOut = _fsopen(pathDebugSpew.string().c_str(), "at", _SH_DENYWR);

	if (!fOut)
		return;

#ifdef DBG_CHARNAME
	char Name[256] = "Unknown";
	if (pLocalPC)
	{
		strcpy_s(Name, pLocalPC->Name);
	}
	fprintf(fOut, "%s - ", Name);
#endif

	fprintf(fOut, "%s\r\n", szOutput);
	fclose(fOut);
}

static void DebugSpewImpl(bool always, bool logToFile, const char* szFormat, va_list vaList)
{
	if (!always && gFilterDebug)
		return;

	// _vscprintf doesn't count // terminating '\0'
	int len = _vscprintf(szFormat, vaList) + 1;
	size_t theLen = len + 32;

	auto out = std::make_unique<char[]>(theLen);
	char* szOutput = out.get();

	vsprintf_s(szOutput, theLen, szFormat, vaList);

	strcat_s(szOutput, theLen, "\n");
	OutputDebugString(szOutput);

	if (logToFile)
	{
		LogToFile(szOutput);
	}
}

// Outputs to debug console when gFilterDebug is false.  Does not output to file. (/filter debug or FilterDebug=0 in ini)
void DebugSpew(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	DebugSpewImpl(false, false, szFormat, vaList);
}

// Outputs to debug console always.  Outputs to file when gSpewToFile is true. (/spewfile or DebugSpewToFile=1 in ini)
void DebugSpewAlways(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	DebugSpewImpl(true, gSpewToFile, szFormat, vaList);
}

// Outputs to debug console always.  Outputs to file always.
void DebugSpewAlwaysFile(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	DebugSpewImpl(true, true, szFormat, vaList);
}

// Outputs to debug console when DBG_SPEW is defined
MQLIB_API void DebugSpewNoFile(const char* szFormat, ...)
{
#ifdef DBG_SPEW
	va_list vaList;
	va_start(vaList, szFormat);

	DebugSpewImpl(true, false, szFormat, vaList);
#endif
}

// Implemented in MQ2PluginHandler.cpp
void PluginsWriteChatColor(const char* Line, int Color, int Filter);

static void WriteChatColorMaybeDeferred(std::unique_ptr<char[]> Ptr, int Color, int Filter)
{
	if (IsMainThread())
	{
		PluginsWriteChatColor(Ptr.get(), Color, Filter);
	}

	// Queue it up to run on the main thread
	PostToMainThread(
		[Ptr = std::shared_ptr<char[]>{ std::move(Ptr) }, Color, Filter]()
	{
		PluginsWriteChatColor(Ptr.get(), Color, Filter);
	});
}

void WriteChatColor(const char* Line, int Color /* = USERCOLOR_DEFAULT */, int Filter /* = 0 */)
{
	// If we're already on the main thread, avoid copying anything and just call
	// straight to PluginsWriteChatColor

	if (IsMainThread())
	{
		PluginsWriteChatColor(Line, Color, Filter);
		return;
	}

	// we're not on the main thread, we need to copy the string and queue up a function
	// to be executed on the main thread.
	size_t length = strlen(Line) + 1;
	std::shared_ptr<char[]> Ptr{ new char[length] };
	strcpy_s(Ptr.get(), length, Line);

	// Queue it up to run on the main thread
	PostToMainThread(
		[Ptr, Color, Filter]()
	{
		PluginsWriteChatColor(Ptr.get(), Color, Filter);
	});
}

void WriteChatf(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	// _vscprintf doesn't count // terminating '\0'
	int len = _vscprintf(szFormat, vaList) + 1;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput);
}

void WriteChatfSafe(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	// _vscprintf doesn't count // terminating '\0'
	int len = _vscprintf(szFormat, vaList) + 1;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput);
}

void WriteChatColorf(const char* szFormat, int color, ...)
{
	va_list vaList;
	va_start(vaList, color);

	// _vscprintf doesn't count // terminating '\0'
	int len = _vscprintf(szFormat, vaList) + 1;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput, color);
}

//============================================================================

static void StrReplaceSection(char* szInsert, size_t InsertLen, DWORD Length, const char* szNewString)
{
	DWORD NewLength = (DWORD)strlen(szNewString);
	memmove(&szInsert[NewLength], &szInsert[Length], strlen(&szInsert[Length]) + 1);
	memcpy_s(szInsert, InsertLen - NewLength, szNewString, NewLength);
}

void ConvertCR(char* Text, size_t LineLen)
{
	// not super-efficient but this is only being called at initialization currently.
	while (char* Next = strstr(Text, "\\n"))
	{
		int len = (int)(Next - Text);
		StrReplaceSection(Next, LineLen - len, 2, "\n");
	}
}

void SyntaxError(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput, CONCOLOR_YELLOW);
	strcpy_s(gszLastSyntaxError, szOutput);
}

void MacroError(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput, CONCOLOR_RED);

	if (bAllErrorsLog) MacroLog(nullptr, "Macro Error");
	if (bAllErrorsLog) MacroLog(nullptr, szOutput);

	strcpy_s(gszLastNormalError, szOutput);

	if (gMacroBlock)
	{
		if (bAllErrorsDumpStack || bAllErrorsFatal)
			DumpStack(nullptr, nullptr);

		if (bAllErrorsFatal)
			EndMacro(pLocalPlayer, "");
	}
}

void FatalError(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	WriteChatColor(szOutput, CONCOLOR_RED);
	strcpy_s(gszLastNormalError, szOutput);

	if (bAllErrorsLog) MacroLog(nullptr, "Fatal Error");
	if (bAllErrorsLog) MacroLog(nullptr, szOutput);

	if (gMacroBlock)
	{
		DumpStack(nullptr, nullptr);
		EndMacro(pLocalPlayer, "");
	}
}

void MQ2DataError(const char* szFormat, ...)
{
	va_list vaList;
	va_start(vaList, szFormat);

	int len = _vscprintf(szFormat, vaList) + 1 + 32;

	auto out = std::make_unique<char[]>(len);
	char* szOutput = out.get();

	vsprintf_s(szOutput, len, szFormat, vaList);
	if (gFilterMQ2DataErrors)
		DebugSpew("%s", szOutput);
	else
		WriteChatColor(szOutput, CONCOLOR_RED);

	strcpy_s(gszLastMQ2DataError, szOutput);
	if (bAllErrorsLog) MacroLog(nullptr, "Data Error");
	if (bAllErrorsLog) MacroLog(nullptr, szOutput);

	if (gMacroBlock)
	{
		if (bAllErrorsDumpStack || bAllErrorsFatal)
			DumpStack(nullptr, nullptr);

		if (bAllErrorsFatal)
			EndMacro(pLocalPlayer, "");
	}
}

// ***************************************************************************
// Function:    GetNextArg
// Description: Returns a pointer to the next argument
// ***************************************************************************
const char* GetNextArg(const char* szLine, int dwNumber, bool CSV /* = false */, char Separator /* = 0 */)
{
	const char* szNext = szLine;
	bool InQuotes = false;
	bool CustomSep = Separator != 0;

	while ((!CustomSep && szNext[0] == ' ')
		|| (!CustomSep && szNext[0] == '\t')
		|| (CustomSep && szNext[0] == Separator)
		|| (!CustomSep && CSV && szNext[0] == ','))
	{
		szNext++;
	}

	if (dwNumber < 1)
		return szNext;

	for (dwNumber; dwNumber > 0; dwNumber--)
	{
		while (((CustomSep || szNext[0] != ' ')
			&& (CustomSep || szNext[0] != '\t')
			&& (!CustomSep || szNext[0] != Separator)
			&& (CustomSep || !CSV || szNext[0] != ',')
			&& szNext[0] != 0)
			|| InQuotes)
		{
			if (szNext[0] == 0 && InQuotes)
			{
				DebugSpew("GetNextArg - No matching quote, returning empty string");
				return szNext;
			}

			if (szNext[0] == '"')
				InQuotes = !InQuotes;
			szNext++;
		}

		while ((!CustomSep && szNext[0] == ' ')
			|| (!CustomSep && szNext[0] == '\t')
			|| (CustomSep && szNext[0] == Separator)
			|| (!CustomSep && CSV && szNext[0] == ','))
		{
			szNext++;
		}
	}

	return szNext;
}

// ***************************************************************************
// Function:    GetArg
// Description: Returns a pointer to the current argument in szDest
// ***************************************************************************
const char* GetArg(char* szDest, const char* szSrc, int dwNumber, bool LeaveQuotes, bool ToParen, bool CSV, char Separator, bool AnyNonAlphaNum)
{
	if (!szSrc)
		return nullptr;

	bool CustomSep = false;
	bool InQuotes = false;

	const char* szTemp = szSrc;

	if (Separator != 0) CustomSep = true;

	szTemp = GetNextArg(szTemp, dwNumber - 1, CSV, Separator);
	int i = 0;
	int j = 0;

	while ((
		(CustomSep || szTemp[i] != ' ')
		&& (CustomSep || szTemp[i] != '\t')
		&& (CustomSep || !CSV || szTemp[i] != ',')
		&& (!CustomSep || szTemp[i] != Separator)
		&& (!AnyNonAlphaNum || ((szTemp[i] >= '0' && szTemp[i] <= '9')
			|| (szTemp[i] >= 'a' && szTemp[i] <= 'z')
			|| (szTemp[i] >= 'A' && szTemp[i] <= 'Z')
			|| szTemp[i] == '_'))
		&& (szTemp[i] != 0)
		&& (!ToParen || szTemp[i] != ')'))
		|| InQuotes)
	{
		if (szTemp[i] == 0 && InQuotes)
		{
			szDest[j] = 0;

			DebugSpew("GetArg - No matching quote, returning entire string");
			DebugSpew("Source = %s", szSrc);
			DebugSpew("Dest = %s", szDest);
			return szDest;
		}

		if (szTemp[i] == '"')
		{
			InQuotes = !InQuotes;
			if (LeaveQuotes)
			{
				szDest[j] = szTemp[i];
				j++;
			}
		}
		else
		{
			szDest[j] = szTemp[i];
			j++;
		}
		i++;
	}

	if (ToParen && szTemp[i] == ')')
		szDest[j++] = ')';

	szDest[j] = 0; // null terminate

	return szDest;
}

/**
 * @fn GetMaybeQuotedArg
 *
 * @brief Gets the last argument that might or might not be quoted
 *
 * If the argument is quoted, it is returned without quotes, just like
 * it would be in a normal GetArg call.  However, if the argument is
 * unquoted, it returns the remainder of the string.  If anything goes
 * wrong, returns nullptr.
 *
 * @param szDest   Where to put the result string
 * @param sizeDest The size of szDest
 * @param szSrc    The original string to parse
 * @param expectedPos The expected position of the argument
 *
 * @return const char* The resulting string, or nullptr
*/
const char* GetMaybeQuotedArg(char* szDest, int sizeDest, const char* szSrc, int expectedPos)
{
	if (!szSrc)
		return nullptr;

	GetArg(szDest, szSrc, expectedPos, true);
	if (szDest[0] == '"')
	{
		GetArg(szDest, szSrc, expectedPos);
	}
	else
	{
		const char* szTmp = GetNextArg(szSrc, expectedPos - 1);
		if (szTmp)
		{
			strcpy_s(szDest, sizeDest, szTmp);
		}
		else
		{
			szDest = nullptr;
		}
	}

	return szDest;
}

// Deprecated
char* GetEQPath(char* szBuffer, size_t len)
{
	GetModuleFileName(nullptr, szBuffer, MAX_STRING);

	char* pSearch = nullptr;
	_strlwr_s(szBuffer, len);

	if (pSearch = strstr(szBuffer, "\\wineq\\"))
		*pSearch = 0;
	else if (pSearch = strstr(szBuffer, "\\testeqgame.exe"))
		*pSearch = 0;
	else if (pSearch = strstr(szBuffer, "\\eqgame.exe"))
		*pSearch = 0;

	return szBuffer;
}

void StripMQChat(std::string_view in, char* out)
{
	size_t i = 0;
	int o = 0;
	while (i < in.size() && in[i])
	{
		if (in[i] == '\a')
		{
			i++;
			if (in[i] == '-')
			{
				// skip 1 after -
				i++;
			}
			else if (in[i] == '#')
			{
				// skip 6 after #
				i += 6;
			}
		}
		else if (in[i] == '\n')
		{
		}
		else
			out[o++] = in[i];
		i++;
	}
	out[o] = 0;
}

void StripMQChat(const char* in, char* out)
{
	StripMQChat(std::string_view{ in }, out);
}

static bool ReplaceSafely(char** out, size_t* pchar_out_string_position, char chr, size_t maxlen)
{
	if ((*pchar_out_string_position) + 1 > maxlen)
		return false;
	(*out)[(*pchar_out_string_position)++] = chr;
	return true;
}

DWORD MQToSTML(const char* in, char* out, size_t maxlen, uint32_t ColorOverride)
{
	//DebugSpew("MQToSTML(%s)",in);
	// 1234567890123
	// <c "#123456">
	//char szCmd[MAX_STRING] = { 0 };
	//strcpy_s(szCmd, out);

#define InsertColor(text, color) sprintf(text,"<c \"#%06X\">", color); TotalColors++;
#define InsertColorSafe(text, len, color) sprintf_s(text, len, "<c \"#%06X\">", color); TotalColors++;
#define InsertStopColor(text)   sprintf(text, "</c>"); TotalColors--;
#define InsertStopColorSafe(text, len) sprintf_s(text, len, "</c>"); TotalColors--;

	size_t outlen = maxlen;
	if (maxlen > 14)
		maxlen -= 14; // make room for this: <c "#123456">

	size_t pchar_in_string_position = 0;
	size_t pchar_out_string_position = 0;
	bool bFirstColor = false;
	bool bNBSpace = false;
	ColorOverride &= 0xFFFFFF;
	uint32_t CurrentColor = ColorOverride;

	int TotalColors = 0; // this MUST be signed.

	pchar_out_string_position += InsertColorSafe(&out[pchar_out_string_position], outlen - pchar_out_string_position, CurrentColor);

	while (in[pchar_in_string_position] != 0 && pchar_out_string_position < maxlen)
	{
		if (in[pchar_in_string_position] == ' ')
		{
			if (bNBSpace)
			{
				if (!ReplaceSafely(&out, &pchar_out_string_position, '&', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'N', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'B', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'S', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'P', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, ';', maxlen))
					break;
			}
			else
			{
				if (!ReplaceSafely(&out, &pchar_out_string_position, ' ', maxlen))
					break;
			}

			bNBSpace = true;
		}
		else
		{
			bNBSpace = false;

			switch (in[pchar_in_string_position])
			{
			case '\a':
				// HANDLE COLOR
				bFirstColor = true;
				pchar_in_string_position++;

				if (in[pchar_in_string_position] == 'x')
				{
					CurrentColor = -1;
					pchar_out_string_position += InsertStopColorSafe(&out[pchar_out_string_position], outlen - pchar_out_string_position);

					if (pchar_out_string_position >= maxlen)
						break;
				}
				else
				{
					if (in[pchar_in_string_position] == '#')
					{
						pchar_in_string_position++;
						char temp[7];
						for (int x = 0; x < 6; x++)
						{
							temp[x] = in[pchar_in_string_position++];
						}
						pchar_in_string_position--;
						temp[6] = 0;
						CurrentColor = -1;
						//pchar_out_string_position += sprintf_s(&out[pchar_out_string_position],outlen-pchar_out_string_position, "<c \"#%s\">", &temp[0]);
						pchar_out_string_position += sprintf_s(&out[pchar_out_string_position], outlen - pchar_out_string_position, "<c \"#%s\">", &temp[0]);
						TotalColors++;
						if (pchar_out_string_position >= maxlen)
							break;
					}
					else
					{
						bool Dark = false;

						if (in[pchar_in_string_position] == '-')
						{
							Dark = true;
							pchar_in_string_position++;
						}

						uint32_t LastColor = CurrentColor;
						switch (in[pchar_in_string_position])
						{
						case 'y': // yellow (green/red)
							if (Dark)
								CurrentColor = 0x999900;
							else
								CurrentColor = 0xFFFF00;
							break;
						case 'o': // orange (green/red)
							if (Dark)
								CurrentColor = 0x996600;
							else
								CurrentColor = 0xFF9900;
							break;
						case 'g': // green   (green)
							if (Dark)
								CurrentColor = 0x009900;
							else
								CurrentColor = 0x00FF00;
							break;
						case 'u': // blue   (blue)
							if (Dark)
								CurrentColor = 0x000099;
							else
								CurrentColor = 0x0000FF;
							break;
						case 'r': // red     (red)
							if (Dark)
								CurrentColor = 0x990000;
							else
								CurrentColor = 0xFF0000;
							break;
						case 't': // teal (blue/green)
							if (Dark)
								CurrentColor = 0x009999;
							else
								CurrentColor = 0x00FFFF;
							break;
						case 'b': // black   (none)
							CurrentColor = 0x000000;
							break;
						case 'm': // magenta (blue/red)
							if (Dark)
								CurrentColor = 0x990099;
							else
								CurrentColor = 0xFF00FF;
							break;
						case 'p': // purple (blue/red)
							if (Dark)
								CurrentColor = 0x660099;
							else
								CurrentColor = 0x9900FF;
							break;
						case 'w': // white   (all)
							if (Dark)
								CurrentColor = 0x999999;
							else
								CurrentColor = 0xFFFFFF;
							break;
						}

						if (CurrentColor != LastColor)
						{
							//pchar_out_string_position += InsertColor(&out[pchar_out_string_position], CurrentColor);
							pchar_out_string_position += InsertColorSafe(&out[pchar_out_string_position], outlen - pchar_out_string_position, CurrentColor);
							if (pchar_out_string_position >= maxlen)
								break;
						}
					}
				}
				break;

			case '&':
				if (!ReplaceSafely(&out, &pchar_out_string_position, '&', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'A', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'M', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'P', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, ';', maxlen))
					break;
				break;

			case '%':
				if (!ReplaceSafely(&out, &pchar_out_string_position, '&', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'P', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'C', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'T', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, ';', maxlen))
					break;
				break;

			case '<':
				if (!ReplaceSafely(&out, &pchar_out_string_position, '&', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'L', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'T', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, ';', maxlen))
					break;
				break;

			case '>':
				if (!ReplaceSafely(&out, &pchar_out_string_position, '&', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'G', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'T', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, ';', maxlen))
					break;
				break;

			case '"':
				if (!ReplaceSafely(&out, &pchar_out_string_position, '&', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'Q', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'U', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'O', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'T', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, ';', maxlen))
					break;
				break;

			case '\n':
				if (!ReplaceSafely(&out, &pchar_out_string_position, '<', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'B', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, 'R', maxlen))
					break;
				if (!ReplaceSafely(&out, &pchar_out_string_position, '>', maxlen))
					break;
				break;

			default:
				out[pchar_out_string_position++] = in[pchar_in_string_position];
				break;
			}
		}

		if (pchar_out_string_position >= maxlen)
			break;
		else
			pchar_in_string_position++;
	}

	if (pchar_out_string_position > maxlen)
	{
		pchar_out_string_position = maxlen;
	}
	for (TotalColors; TotalColors > 0;)
	{
		pchar_out_string_position += InsertStopColorSafe(&out[pchar_out_string_position], outlen - pchar_out_string_position);
	}

	out[pchar_out_string_position++] = 0;
	return static_cast<DWORD>(pchar_out_string_position);

#undef InsertColor
#undef InsertColorSafe
#undef InsertStopColor
#undef InsertStopColorSafe
}

static bool ItemFitsInSlot(ItemClient* pCont, std::string_view search)
{
	// map some commonly used synonyms
	struct Mapping {
		const char* search;
		const char* replace;
	};
	static constexpr Mapping mappings[] = {
		{ "fingers",       "finger" },
		{ "power source",  "power" },
		{ "primary",       "mainhand" },
		{ "secondary",     "offhand" },
		{ "shoulders",     "shoulder" },
	};

	for (const auto& mapping : mappings)
	{
		if (ci_equals(mapping.search, search))
		{
			search = mapping.replace;
			break;
		}
	}

	int cmp = GetItemFromContents(pCont)->EquipSlots;

	for (int i = 0; i < NUM_WORN_ITEMS; ++i)
	{
		if (cmp & (1 << i))
		{
			if (ci_find_substr(szItemSlot[i], search))
			{
				return true;
			}
		}
	}

	return false;
}

int ItemHasStat(ItemClient* pCont, std::string_view search)
{
	// map stat names to accessors
	static const std::map<std::string, std::function<int(ItemDefinition*)>, ci_less> mapping = {
		{
			"armor class",
			[](ItemDefinition* pi) { return pi->AC; }
		},
		{
			"agility",
			[](ItemDefinition* pi) { return pi->AGI; }
		},
		{
			"charisma",
			[](ItemDefinition* pi) { return pi->CHA; }
		},
		{
			"dexterity",
			[](ItemDefinition* pi) { return pi->DEX; }
		},
		{
			"intelligence",
			[](ItemDefinition* pi) { return pi->INT; }
		},
		{
			"stamina",
			[](ItemDefinition* pi) { return pi->STA; }
		},
		{
			"strength",
			[](ItemDefinition* pi) { return pi->STR; }
		},
		{
			"wisdom",
			[](ItemDefinition* pi) { return pi->WIS; }
		},
		{
			"vs cold",
			[](ItemDefinition* pi) { return pi->SvCold; }
		},
		{
			"vs fire",
			[](ItemDefinition* pi) { return pi->SvFire; }
		},
		{
			"vs magic",
			[](ItemDefinition* pi) { return pi->SvMagic; }
		},
		{
			"vs poison",
			[](ItemDefinition* pi) { return pi->SvPoison; }
		},
		{
			"hit points",
			[](ItemDefinition* pi) { return pi->HP; }
		},
		{
			"mana",
			[](ItemDefinition* pi) { return pi->Mana; }
		},
		{
			"endurance",
			[](ItemDefinition* pi) { return pi->Endurance; }
		},
		{
			"attack",
			[](ItemDefinition* pi) { return pi->Attack; }
		},
		{
			"hp regen",
			[](ItemDefinition* pi) { return pi->HPRegen; }
		},
		{
			"mana regen",
			[](ItemDefinition* pi) { return pi->ManaRegen; }
		},
		{
			"haste",
			[](ItemDefinition* pi) { return pi->Haste; }
		},
		{
			"heal amount",
			[](ItemDefinition* pi) { return pi->HealAmount; }
		},
		{
			"spell damage",
			[](ItemDefinition* pi) { return pi->SpellDamage; }
		},
		{
			"clairvoyance",
			[](ItemDefinition* pi) { return pi->Clairvoyance; }
		},
		{
			"heroic agility",
			[](ItemDefinition* pi) { return pi->HeroicAGI; }
		},
		{
			"heroic charisma",
			[](ItemDefinition* pi) { return pi->HeroicCHA; }
		},
		{
			"heroic dexterity",
			[](ItemDefinition* pi) { return pi->HeroicDEX; }
		},
		{
			"heroic intelligence",
			[](ItemDefinition* pi) { return pi->HeroicINT; }
		},
		{
			"heroic stamina",
			[](ItemDefinition* pi) { return pi->HeroicSTA; }
		},
		{
			"heroic strength",
			[](ItemDefinition* pi) { return pi->HeroicSTR; }
		},
		{
			"heroic wisdom",
			[](ItemDefinition* pi) { return pi->HeroicWIS; }
		},
		{
			"backstab",
			[](ItemDefinition* pi) { return pi->BackstabDamage; }
		},
		{
			"bash",
			[](ItemDefinition* pi) { return pi->DmgBonusSkill == 10 ? pi->DmgBonusValue : 0; }
		},
		{
			"dragon punch",
			[](ItemDefinition* pi) { return pi->DmgBonusSkill == 21 ? pi->DmgBonusValue : 0; }
		},
		{
			"eagle strike",
			[](ItemDefinition* pi) { return pi->DmgBonusSkill == 23 ? pi->DmgBonusValue : 0; }
		},
		{
			"flying kick",
			[](ItemDefinition* pi) { return pi->DmgBonusSkill == 26 ? pi->DmgBonusValue : 0; }
		},
		{
			"kick",
			[](ItemDefinition* pi) { return pi->DmgBonusSkill == 30 ? pi->DmgBonusValue : 0; }
		},
		{
			"round kick",
			[](ItemDefinition* pi) { return pi->DmgBonusSkill == 38 ? pi->DmgBonusValue : 0; }
		},
		{
			"tiger claw",
			[](ItemDefinition* pi) { return pi->DmgBonusSkill == 52 ? pi->DmgBonusValue : 0; }
		},
		{
			"frenzy",
			[](ItemDefinition* pi) { return pi->DmgBonusSkill == 74 ? pi->DmgBonusValue : 0; }
		}
	};

	auto iter = mapping.find(search);
	if (iter != mapping.end())
	{
		ItemDefinition* pItem = GetItemFromContents(pCont);
		if (pItem)
		{
			return iter->second(pItem);
		}
	}

	return 0;
}

static bool ItemHasRace(ItemClient* pCont, std::string_view search)
{
	// FIXME: This code is duplicated in a multiple of places.
	int cmp = GetItemFromContents(pCont)->Races;
	for (int num = 0; num < NUM_RACES; num++)
	{
		if (cmp & (1 << num))
		{
			int tmp = num + 1;
			switch (num)
			{
			case 12:
				tmp = 128;   // IKS
				break;
			case 13:
				tmp = 130;   // VAH
				break;
			case 14:
				tmp = 330;   // FRG
				break;
			case 15:
				tmp = 522;   // DRK
				break;
			}

			if (ci_equals(pEverQuest->GetRaceDesc(tmp), search))
			{
				return true;
			}
		}
	}

	return false;
}

static bool ItemHasClass(ItemClient* pCont, std::string_view search)
{
	// FIXME: This code is duplicated in a multiple of places.
	int cmp = GetItemFromContents(pCont)->Classes;
	for (int num = 0; num < TotalPlayerClasses; num++)
	{
		if (cmp & (1 << num))
		{

			if (ci_equals(pEverQuest->GetClassDesc(num), search))
			{
				return true;
			}
		}
	}

	return false;
}

const char* GetFilenameFromFullPath(const char* Filename)
{
	while (Filename && strstr(Filename, "\\"))
		Filename = strstr(Filename, "\\") + 1;

	return Filename;
}

bool CompareTimes(char* RealTime, char* ExpectedTime)
{
	// Match everything except seconds
	// Format is: WWW MMM DD hh:mm:ss YYYY
	//            0123456789012345678901234
	//                      1         2
	if (!_strnicmp(RealTime, ExpectedTime, 17)
		&& !_strnicmp(RealTime + 19, ExpectedTime + 19, 5))
	{
		return true;
	}

	return false;
}

void AddFilter(const char* szFilter, int Length, bool& pEnabled)
{
	MQFilter* New = new MQFilter(szFilter, Length, pEnabled);

	New->pNext = gpFilters;
	gpFilters = New;
}

void DefaultFilters()
{
	AddFilter("You have become better at ", 26, gFilterSkillsIncrease);
	AddFilter("You lacked the skills to fashion the items together.", -1, gFilterSkillsAll);
	AddFilter("You have fashioned the items together to create something new!", -1, gFilterSkillsAll);
	AddFilter("You have fashioned the items together to create an alternate product.", -1, gFilterSkillsAll);
	AddFilter("You can no longer advance your skill from making this item.", -1, gFilterSkillsAll);
	AddFilter("You no longer have a target.", -1, gFilterTarget);
	AddFilter("You give ", 9, gFilterMoney);
	AddFilter("You receive ", 12, gFilterMoney);
	AddFilter("You are encumbered", 17, gFilterEncumber);
	AddFilter("You are no longer encumbered", 27, gFilterEncumber);
	AddFilter("You are low on drink", 19, gFilterFood);
	AddFilter("You are low on food", 18, gFilterFood);
	AddFilter("You are out of drink", 19, gFilterFood);
	AddFilter("You are out of food", 18, gFilterFood);
	AddFilter("You and your mount are thirsty.", -1, gFilterFood);
	AddFilter("You and your mount are hungry.", -1, gFilterFood);
	AddFilter("You are hungry", 13, gFilterFood);
	AddFilter("You are thirsty", 14, gFilterFood);
	AddFilter("You take a bite out of", 22, gFilterFood);
	AddFilter("You take a bite of", 18, gFilterFood);
	AddFilter("You take a drink from", 21, gFilterFood);
	AddFilter("Ahhh. That was tasty.", -1, gFilterFood);
	AddFilter("Ahhh. That was refreshing.", -1, gFilterFood);
	AddFilter("Chomp, chomp, chomp...", 22, gFilterFood);
	AddFilter("Glug, glug, glug...", 19, gFilterFood);
	AddFilter("You could not possibly eat any more, you would explode!", -1, gFilterFood);
	AddFilter("You could not possibly drink any more, you would explode!", -1, gFilterFood);
	AddFilter("You could not possibly consume more alcohol or become more intoxicated!", -1, gFilterFood);
}

char* ConvertHotkeyNameToKeyName(char* szName, size_t Namelen)
{
	if (!_stricmp(szName, "EQUALSIGN"))
		strcpy_s(szName, Namelen, "=");

	if (!_stricmp(szName, "SEMICOLON"))
		strcpy_s(szName, Namelen, ";");

	if (!_stricmp(szName, "LEFTBRACKET"))
		strcpy_s(szName, Namelen, "[");

	return szName;
}

// ***************************************************************************
// Function:    GetFullZone
// Description: Returns a full zone name from a short name
// ***************************************************************************
const char* GetFullZone(int ZoneID)
{
	ZoneID &= 0x7FFF;

	if (pWorldData && ZoneID < MAX_ZONES)
	{
		if (EQZoneInfo* pZone = pWorldData->ZoneArray[ZoneID])
			return pZone->LongName;
	}

	return "UNKNOWN_ZONE";
}

// ***************************************************************************
// Function:    GetShortZone
// Description: Returns a short zone name from a ZoneID
// ***************************************************************************
const char* GetShortZone(int ZoneID)
{
	ZoneID &= 0x7FFF;

	if (pWorldData && ZoneID < MAX_ZONES)
	{
		if (EQZoneInfo* pZone = pWorldData->ZoneArray[ZoneID])
			return pZone->ShortName;
	}

	return "UNKNOWN_ZONE";
}

// ***************************************************************************
// Function:    GetZoneID
// Description: Returns a ZoneID from a short or long zone name
// ***************************************************************************
int GetZoneID(const char* ZoneShortName)
{
	if (!pWorldData)
		return -1;

	for (int nIndex = 0; nIndex < MAX_ZONES; nIndex++)
	{
		EQZoneInfo* pZone = pWorldData->ZoneArray[nIndex];
		if (pZone)
		{
			if (!_stricmp(pZone->ShortName, ZoneShortName))
			{
				return nIndex;
			}

			if (!_stricmp(pZone->LongName, ZoneShortName))
			{
				return nIndex;
			}
		}
	}
	return -1;
}

// ***************************************************************************
// Function:    GetGameTime
// Description: Returns Current Game Time
// ***************************************************************************
void GetGameTime(int* Hour, int* Minute, int* Night)
{
	if (!pWorldData)
		return;

	int eqHour = pWorldData->Hour - 1; // Midnight = 1 in EQ time
	int eqMinute = pWorldData->Minute;

	if (Hour)
		*Hour = eqHour;
	if (Minute)
		*Minute = eqMinute;
	if (Night)
		*Night = eqHour >= 19 || eqHour < 5; // [7pm, 5am)
}

// ***************************************************************************
// Function:    GetGameDate
// Description: Returns Current Game Time
// ***************************************************************************
void GetGameDate(int* Month, int* Day, int* Year)
{
	if (!pWorldData)
		return;

	if (Month)
		*Month = pWorldData->Month;
	if (Day)
		*Day = pWorldData->Day;
	if (Year)
		*Year = pWorldData->Year;
}

// TOOD: Convert to data table
int GetLanguageIDByName(const char* szName)
{
	if (!_stricmp(szName, "Common")) return 1;
	if (!_stricmp(szName, "Common Tongue")) return 1;
	if (!_stricmp(szName, "Barbarian")) return 2;
	if (!_stricmp(szName, "Erudian")) return 3;
	if (!_stricmp(szName, "Elvish")) return 4;
	if (!_stricmp(szName, "Dark Elvish")) return 5;
	if (!_stricmp(szName, "Dwarvish")) return 6;
	if (!_stricmp(szName, "Troll")) return 7;
	if (!_stricmp(szName, "Ogre")) return 8;
	if (!_stricmp(szName, "Gnomish")) return 9;
	if (!_stricmp(szName, "Halfling")) return 10;
	if (!_stricmp(szName, "Thieves Cant")) return 11;
	if (!_stricmp(szName, "Old Erudian")) return 12;
	if (!_stricmp(szName, "Elder Elvish")) return 13;
	if (!_stricmp(szName, "Froglok")) return 14;
	if (!_stricmp(szName, "Goblin")) return 15;
	if (!_stricmp(szName, "Gnoll")) return 16;
	if (!_stricmp(szName, "Combine Tongue")) return 17;
	// Incorrect spelling, but keeping for backwards compatibility
	if (!_stricmp(szName, "Elder Tier'Dal")) return 18;
	// Correct Spelling
	if (!_stricmp(szName, "Elder Teir'Dal")) return 18;
	if (!_stricmp(szName, "Lizardman")) return 19;
	if (!_stricmp(szName, "Orcish")) return 20;
	if (!_stricmp(szName, "Faerie")) return 21;
	if (!_stricmp(szName, "Dragon")) return 22;
	if (!_stricmp(szName, "Elder Dragon")) return 23;
	if (!_stricmp(szName, "Dark Speech")) return 24;
	if (!_stricmp(szName, "Vah Shir")) return 25;
	if (!_stricmp(szName, "Alaran")) return 26;
	if (!_stricmp(szName, "Hadal")) return 27;
	return -1;
}

void UpdateCurrencyCache(std::unordered_map<std::string, int>& cache, int value, eDatabaseStringType type)
{
	constexpr std::string_view chars_to_remove = "'`";
	if (const char* ptr = pCDBStr->GetString(value, type))
	{
		const std::string currency = to_lower_copy(ptr);
		if (currency.empty())
			return;
		cache[currency] = value;
		cache[remove_chars(currency, chars_to_remove)] = value;
	}
}

int GetCurrencyIDByName(const char* szName)
{
	static std::unordered_map<std::string, int> cache;

	if (cache.empty())
	{
		for (int i = ALTCURRENCY_FIRST; i <= ALTCURRENCY_LAST; ++i)
		{
			UpdateCurrencyCache(cache, i, eAltCurrencyNamePlural);
			UpdateCurrencyCache(cache, i, eAltCurrencyName);
		}
		// Crowns are outside ALTCURRENCY_LAST
		UpdateCurrencyCache(cache, ALTCURRENCY_CROWNS, eAltCurrencyNamePlural);
		UpdateCurrencyCache(cache, ALTCURRENCY_CROWNS, eAltCurrencyName);
	}

	const auto it = cache.find(to_lower_copy(szName));
	if (it != cache.end())
	{
		return it->second;
	}

	return -1;
}

// This wrapper is here to deal with older plugins and to preserve backwards compatibility with older clients (emu)
CAltAbilityData* GetAAById(int nAbilityId, int playerLevel)
{
	return pAltAdvManager->GetAAById(nAbilityId, playerLevel);
}

SPELL* GetSpellByAAName(const char* szName)
{
	int level = pLocalPlayer ? pLocalPlayer->Level : -1;

	for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
	{
		if (CAltAbilityData* pAbility = GetAAById(nAbility, level))
		{
			if (pAbility->SpellID != -1)
			{
				if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
				{
					if (!_stricmp(szName, pName))
					{
						if (SPELL* psp = GetSpellByID(pAbility->SpellID))
						{
							return psp;
						}
					}
				}
			}
		}
	}

	return nullptr;
}

int GetDeityTeamByID(int DeityID)
{
	switch (DeityID) {
	case DEITY_ErollisiMarr:
	case DEITY_MithanielMarr:
	case DEITY_RodcetNife:
	case DEITY_Quellious:
	case DEITY_Tunare:
		return 1;
	case DEITY_BrellSerilis:
	case DEITY_Bristlebane:
	case DEITY_Karana:
	case DEITY_Prexus:
	case DEITY_SolusekRo:
	case DEITY_TheTribunal:
	case DEITY_Veeshan:
		return 2;
	case DEITY_Bertoxxulous:
	case DEITY_CazicThule:
	case DEITY_Innoruuk:
	case DEITY_RallosZek:
		return 3;
	default:
		return 0;
	}
}

const char* GetGuildByID(int64_t GuildID)
{
	if (GuildID == 0 || GuildID == -1)
		return nullptr;

	if (const char* thename = pGuild->GetGuildName(GuildID))
	{
		if (!_stricmp(thename, "Unknown Guild"))
			return nullptr;

		return thename;
	}

	return nullptr;
}

int64_t GetGuildIDByName(const char* szGuild)
{
	return pGuild->GetGuildIndex(szGuild);
}

const char* GetLightForSpawn(SPAWNINFO* pSpawn)
{
	if (pSpawn != nullptr)
	{
		uint8_t Light = pSpawn->Light;

		if (Light > LIGHT_COUNT)
			Light = 0;

		return szLights[Light];
	}

	return nullptr;
}

// ***************************************************************************
// Function:    DistanceToSpawn3D
// Description: Return the distance between two spawns, including Z
// ***************************************************************************
float DistanceToSpawn3D(SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	if (pSpawn != nullptr)
	{
		float X = pChar->X - pSpawn->X;
		float Y = pChar->Y - pSpawn->Y;
		float Z = pChar->Z - pSpawn->Z;
		return sqrtf(X * X + Y * Y + Z * Z);
	}

	return 0;
}

// ***************************************************************************
// Function:    DistanceToSpawn
// Description: Return the distance between two spawns
// ***************************************************************************
float EstimatedDistanceToSpawn(SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	if (pSpawn != nullptr)
	{
		float RDistance = DistanceToSpawn(pChar, pSpawn);
		float X = pChar->X - (pSpawn->X + pSpawn->SpeedX * RDistance);
		float Y = pChar->Y - (pSpawn->Y + pSpawn->SpeedY * RDistance);
		return sqrtf(X * X + Y * Y);
	}

	return 0;
}

// ***************************************************************************
// Function:    ConColor
// Description: Returns the con color for a spawn's level
// ***************************************************************************
int ConColor(SPAWNINFO* pSpawn)
{
	if (!pLocalPlayer || !pLocalPC || !pSpawn)
		return CONCOLOR_WHITE;

	switch (pLocalPC->GetConLevel(pSpawn))
	{
	case 0:
	case 1:
		return CONCOLOR_GREY;
	case 2:
		return CONCOLOR_GREEN;
	case 3:
		return CONCOLOR_LIGHTBLUE;
	case 4:
		return CONCOLOR_BLUE;
	case 5:
		return CONCOLOR_WHITE;
	case 6:
		return CONCOLOR_YELLOW;
	case 7:
		return CONCOLOR_RED;
	default:
		return COLOR_PURPLE;
	}
}

ItemClient* GetEnviroContainer()
{
	if (!pContainerMgr)
		return nullptr;

	return pContainerMgr->WorldContainer;
}

CContainerWnd* FindContainerForContents(ItemClient* pContents)
{
	if (!pContainerMgr)
		return nullptr;

	return pContainerMgr->GetWindowForItem(pContents);
}

// ***************************************************************************
// FindSpeed(SPAWNINFO*) - Used to find the speed of a Spawn taking a mount into
//                               consideration.
// ***************************************************************************
float FindSpeed(SPAWNINFO* pSpawn)
{
	SPAWNINFO* pMount = nullptr;
	float fRunSpeed = 0;
	pMount = FindMount(pSpawn);

	if (pMount)
		fRunSpeed = pMount->SpeedRun * 10000 / 70;

	return fRunSpeed;
}

const char* GetLoginName()
{
	if (__LoginName)
	{
		return (char*)__LoginName;
	}

	return nullptr;
}

void STMLToPlainText(char* in, char* out)
{
	uint32_t pchar_in_string_position = 0;
	uint32_t pchar_out_string_position = 0;
	uint32_t pchar_amper_string_position = 0;
	char Amper[2048] = { 0 };

	while (in[pchar_in_string_position] != 0)
	{
		switch (in[pchar_in_string_position])
		{
		case '<':
			while (in[pchar_in_string_position] != '>')
				pchar_in_string_position++;
			pchar_in_string_position++;
			break;

		case '&':
			pchar_in_string_position++;
			pchar_amper_string_position = 0;
			ZeroMemory(Amper, 2048);
			while (in[pchar_in_string_position] != ';')
			{
				Amper[pchar_amper_string_position++] = in[pchar_in_string_position++];
			}

			pchar_in_string_position++;

			if (!_stricmp(Amper, "nbsp"))
			{
				out[pchar_out_string_position++] = ' ';
			}
			else if (!_stricmp(Amper, "amp"))
			{
				out[pchar_out_string_position++] = '&';
			}
			else if (!_stricmp(Amper, "gt"))
			{
				out[pchar_out_string_position++] = '>';
			}
			else if (!_stricmp(Amper, "lt"))
			{
				out[pchar_out_string_position++] = '<';
			}
			else if (!_stricmp(Amper, "quot"))
			{
				out[pchar_out_string_position++] = '\"';
			}
			else if (!_stricmp(Amper, "pct"))
			{
				out[pchar_out_string_position++] = '%';
			}
			else
			{
				out[pchar_out_string_position++] = '?';
			}
			break;

		default:
			out[pchar_out_string_position++] = in[pchar_in_string_position++];
		}
	}

	out[pchar_out_string_position++] = 0;
}

void ClearSearchItem(MQItemSearch& SearchItem)
{
	SearchItem = MQItemSearch();
}

#define MaskSet(n) (SearchItem.FlagMask[(SearchItemFlag)n])
#define Flag(n) (SearchItem.Flag[(SearchItemFlag)n])
#define RequireFlag(flag,value) { if (MaskSet(flag) && Flag(flag) != (char)((value)!=0)) return false;}

bool ItemMatchesSearch(MQItemSearch& SearchItem, ItemClient* pContents)
{
	ItemDefinition* pItem = GetItemFromContents(pContents);

	if (SearchItem.ID && pItem->ItemNumber != SearchItem.ID)
		return false;

	RequireFlag(Lore, pItem->Lore);
	RequireFlag(NoRent, pItem->NoRent);
	RequireFlag(NoDrop, pItem->IsDroppable);
	RequireFlag(Magic, pItem->IsMagic());
	RequireFlag(Pack, pItem->Type == ITEMTYPE_PACK);
	RequireFlag(Book, pItem->Type == ITEMTYPE_BOOK);
	RequireFlag(Combinable, pItem->ItemType == 17);
	RequireFlag(Summoned, pItem->Summoned);
	RequireFlag(Instrument, pItem->InstrumentType);
	RequireFlag(Weapon, pItem->Damage && pItem->Delay);
	RequireFlag(Normal, pItem->Type == ITEMTYPE_NORMAL);

	if (SearchItem.szName[0] && ci_find_substr(pItem->Name, SearchItem.szName))
		return false;
	if (SearchItem.szSlot[0] && !ItemFitsInSlot(pContents, SearchItem.szSlot))
		return false;
	if (SearchItem.szStat[0] && ItemHasStat(pContents, SearchItem.szStat) == 0)
		return false;
	if (SearchItem.szRace[0] && !ItemHasRace(pContents, SearchItem.szRace))
		return false;
	if (SearchItem.szClass[0] && !ItemHasClass(pContents, SearchItem.szClass))
		return false;

	return true;
}

bool SearchThroughItems(MQItemSearch& SearchItem, ItemClient** pResult, DWORD* nResult)
{
	// TODO
#define DoResult(pContents, nresult) { \
	if (pResult)                       \
		*pResult = pContents;          \
	if (nResult)                       \
		*nResult = nresult;            \
	return true;                       \
}

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return false;

	if (MaskSet(Worn) && Flag(Worn))
	{
		// iterate through worn items
		for (int N = InvSlot_FirstWornItem; N <= InvSlot_LastWornItem; N++)
		{
			if (ItemClient* pContents = pProfile->GetInventorySlot(N))
			{
				if (ItemMatchesSearch(SearchItem, pContents))
					DoResult(pContents, N);
			}
		}
	}

	if (MaskSet(Inventory) && Flag(Inventory))
	{
		// iterate through inventory slots before in-pack slots
		for (int nPack = InvSlot_FirstBagSlot; nPack < GetHighestAvailableBagSlot(); nPack++)
		{
			if (ItemClient* pContents = pProfile->GetInventorySlot(nPack))
			{
				if (ItemMatchesSearch(SearchItem, pContents))
					DoResult(pContents, nPack + 21);
			}
		}

		for (int nPack = InvSlot_FirstBagSlot; nPack < GetHighestAvailableBagSlot(); nPack++)
		{
			if (ItemClient* pContents = pProfile->GetInventorySlot(nPack))
			{
				if (pContents->IsContainer())
				{
					for (int nItem = 0; nItem < pContents->GetHeldItems().GetSize(); ++nItem)
					{
						if (ItemPtr pItem = pContents->GetHeldItems().GetItem(nItem))
						{
							if (ItemMatchesSearch(SearchItem, pItem.get()))
								DoResult(pItem.get(), nPack * 100 + nItem);
						}
					}
				}
			}
		}
	}

	// TODO
	return false;
}
#undef DoResult
#undef RequireFlag
#undef Flag
#undef MaskSet

void ClearSearchSpawn(MQSpawnSearch* pSearchSpawn)
{
	if (!pSearchSpawn) return;

	*pSearchSpawn = MQSpawnSearch();

	if (pControlledPlayer)
		pSearchSpawn->zLoc = pControlledPlayer->Z;
	else if (pLocalPlayer)
		pSearchSpawn->zLoc = pLocalPlayer->Z;
}

// ***************************************************************************
// Function:    DistanceToPoint
// Description: Return the distance between a spawn and the specified point
// ***************************************************************************
float DistanceToPoint(SPAWNINFO* pSpawn, float xLoc, float yLoc)
{
	if (pSpawn != nullptr)
	{
		float X = pSpawn->X - xLoc;
		float Y = pSpawn->Y - yLoc;
		return sqrtf(X * X + Y * Y);
	}

	return 0;
}

// ***************************************************************************
// Function:    Distance3DToPoint
// Description: Return the distance between a spawn and the specified point
// ***************************************************************************
float Distance3DToPoint(SPAWNINFO* pSpawn, float xLoc, float yLoc, float zLoc)
{
	if (pSpawn != nullptr)
	{
		float dX = pSpawn->X - xLoc;
		float dY = pSpawn->Y - yLoc;
		float dZ = pSpawn->Z - zLoc;
		return sqrtf(dX * dX + dY * dY + dZ * dZ);
	}

	return 0;
}

void DisplayOverlayText(const char* szText, int dwColor, uint32_t dwTransparency, uint32_t msFadeIn, uint32_t msFadeOut, uint32_t msHold)
{
	CBroadcast* pBC = CBroadcast::Get();
	if (!pBC)
	{
		WriteChatColor(szText, dwColor);
		return;
	}

	uint32_t dwAlpha = (uint32_t)(dwTransparency * 255 / 100);
	if (dwAlpha > 255) dwAlpha = 255;

	pBC->DisplayText(
		szText,
		dwColor,
		10, // Always 10 in eqgame.exe,
			// Doesn't seem to affect anything
			// (tried 0,1,10,20,100,500)
		dwAlpha,
		msFadeIn,
		msFadeOut,
		msHold);
}

void CustomPopup(const char* szPopText, bool bPopOutput)
{
	int iArgNum = 1;
	int iMsgColor = CONCOLOR_LIGHTBLUE;
	int iMsgTime = 3000;
	char szCurArg[MAX_STRING] = { 0 };
	char szPopupMsg[MAX_STRING] = { 0 };
	char szErrorCust[MAX_STRING] = "\awUsage: /popcustom [\agcolor\ax] [\agdisplaytime\ax(in seconds)] [\agmessage\ax]";
	char szErrorEcho[MAX_STRING] = "\awUsage: /popupecho [\agcolor\ax] [\agdisplaytime\ax(in seconds)] [\agmessage\ax]";

	GetArg(szCurArg, szPopText, iArgNum++);
	if (!*szCurArg)
	{
		if (bPopOutput)
		{
			WriteChatf("%s", szErrorEcho);
		}
		else
		{
			WriteChatf("%s", szErrorCust);
		}
		return;
	}
	else
	{
		if (isdigit(szCurArg[0]))
		{
			iMsgColor = GetIntFromString(szCurArg, iMsgColor);
			GetArg(szCurArg, szPopText, iArgNum++);
			if (isdigit(szCurArg[0]))
			{
				iMsgTime = GetIntFromString(szCurArg, iMsgTime) * 1000;
				sprintf_s(szPopupMsg, "%s", GetNextArg(szPopText, 2, false, 0));
			}
			else
			{
				sprintf_s(szPopupMsg, "%s", GetNextArg(szPopText, 1, false, 0));
			}
		}
		else
		{
			strcpy_s(szPopupMsg, szPopText);
		}
	}

	DisplayOverlayText(szPopupMsg, iMsgColor, 100, 500, 500, iMsgTime);
	if (bPopOutput)
		WriteChatf("\ayPopup\aw:: %s", szPopupMsg);
}

bool ParseKeyCombo(const char* text, KeyCombo& Dest)
{
	KeyCombo Ret;

	if (!_stricmp(text, "clear"))
	{
		Dest = Ret;
		return true;
	}

	char Copy[MAX_STRING];
	strcpy_s(Copy, text);
	char* token1 = nullptr;
	char* next_token1 = nullptr;

	token1 = strtok_s(Copy, "+ ", &next_token1);
	while (token1 != nullptr)
	{
		if (token1 != nullptr)
		{
			if (!_stricmp(token1, "alt"))
				Ret.Data[0] = 1;
			else if (!_stricmp(token1, "ctrl"))
				Ret.Data[1] = 1;
			else if (!_stricmp(token1, "shift"))
				Ret.Data[2] = 1;
			else
			{
				for (int i = 0; gDiKeyID[i].Id; i++)
				{
					if (!_stricmp(token1, gDiKeyID[i].szName))
					{
						Ret.Data[3] = (char)gDiKeyID[i].Id;
						break;
					}
				}
			}
			token1 = strtok_s(nullptr, "+ ", &next_token1);
		}
	}
	if (Ret.Data[3])
	{
		Dest = Ret;
		return true;
	}
	return false;
}

char* DescribeKeyCombo(const KeyCombo& Combo, char* szDest, size_t BufferSize)
{
	int pos = 0;
	szDest[0] = 0;

	if (Combo.Data[2])
	{
		strcpy_s(&szDest[pos], BufferSize - pos, "shift");
		pos += 5;
	}

	if (Combo.Data[1])
	{
		if (pos)
		{
			szDest[pos] = '+';
			pos++;
		}
		strcpy_s(&szDest[pos], BufferSize - pos, "ctrl");
		pos += 4;
	}

	if (Combo.Data[0])
	{
		if (pos)
		{
			szDest[pos] = '+';
			pos++;
		}
		strcpy_s(&szDest[pos], BufferSize - pos, "alt");
		pos += 3;
	}

	if (pos)
	{
		szDest[pos] = '+';
		pos++;
	}

	if (Combo.Data[3])
	{
		strcpy_s(&szDest[pos], BufferSize - pos, gDiKeyName[Combo.Data[3]]);
	}
	else
	{
		strcpy_s(&szDest[pos], BufferSize - pos, "clear");
	}

	return &szDest[0];
}

bool LoadCfgFile(const char* Filename, bool Delayed)
{
	std::filesystem::path pathFilename = Filename;

	// The original search order was: Configs\Filename.cfg, root\Filename.cfg, EQ\Filename.cfg, EQ\Filename
	// The new search order is Config\Autoexec\Filename.cfg then Config\Filename.cfg.
	if (!strchr(Filename, '.'))
		pathFilename = std::string(Filename) + ".cfg";

	std::error_code ec_exists;

	if (pathFilename.is_relative())
	{
		const std::filesystem::path tmpPath = "Autoexec";
		if (std::filesystem::exists(mq::internal_paths::Config / tmpPath / pathFilename, ec_exists))
		{
			pathFilename = mq::internal_paths::Config / tmpPath / pathFilename;
		}
		else if (std::filesystem::exists(mq::internal_paths::Config / pathFilename, ec_exists))
		{
			pathFilename = mq::internal_paths::Config / pathFilename;
		}
	}

	if (std::filesystem::exists(pathFilename, ec_exists))
	{
		FILE* file = _fsopen(pathFilename.string().c_str(), "rt", _SH_DENYNO);
		if (file)
		{
			char szBuffer[MAX_STRING] = { 0 };
			while (fgets(szBuffer, MAX_STRING, file))
			{
				char* Next_Token1 = nullptr;
				char* Cmd = strtok_s(szBuffer, "\r\n", &Next_Token1);
				if (Cmd && Cmd[0] && Cmd[0] != ';')
				{
					DoCommand(Cmd, Delayed);
				}
			}

			fclose(file);
			return true;
		}
	}
	return false;
}

enum eCalcOp
{
	CO_NUMBER = 0,
	CO_OPENPARENS = 1,
	CO_CLOSEPARENS = 2,
	CO_ADD = 3,
	CO_SUBTRACT = 4,
	CO_MULTIPLY = 5,
	CO_DIVIDE = 6,
	CO_IDIVIDE = 7,
	CO_LAND = 8,
	CO_AND = 9,
	CO_LOR = 10,
	CO_OR = 11,
	CO_XOR = 12,
	CO_EQUAL = 13,
	CO_NOTEQUAL = 14,
	CO_GREATER = 15,
	CO_NOTGREATER = 16,
	CO_LESS = 17,
	CO_NOTLESS = 18,
	CO_MODULUS = 19,
	CO_POWER = 20,
	CO_LNOT = 21,
	CO_NOT = 22,
	CO_SHL = 23,
	CO_SHR = 24,
	CO_NEGATE = 25,
	CO_TOTAL = 26,
};

int CalcOpPrecedence[CO_TOTAL] =
{
	0,
	0,
	0,
	9,    // add
	9,    // subtract
	10,   // multiply
	10,   // divide
	10,   // integer divide
	2,    // logical and
	5,    // bitwise and
	1,    // logical or
	3,    // bitwise or
	4,    // bitwise xor
	6,    // equal
	6,    // not equal
	7,    // greater
	7,    // not greater
	7,    // less
	7,    // not less
	10,   // modulus
	11,   // power
	12,   // logical not
	12,   // bitwise not
	8,    // shl
	8,    // shr
	12,   // negate
};

struct CalcOp
{
	eCalcOp Op;
	double Value;
};

bool EvaluateRPN(CalcOp* pList, int Size, double& Result)
{
	if (!Size)
		return false;

	std::unique_ptr<double[]> stackPtr = std::make_unique<double[]>(Size / 2 + 2);
	double* pStack = stackPtr.get();

	int nStack = 0;

#define StackEmpty()           (nStack==0)
#define StackTop()             (pStack[nStack])
#define StackSetTop(do_assign) {pStack[nStack]##do_assign;}
#define StackPush(val)         {nStack++;pStack[nStack]=val;}
#define StackPop()             {if (!nStack) {FatalError("Illegal arithmetic in calculation"); return 0;}; nStack--;}

#define BinaryIntOp(op)        {int RightSide=(int)StackTop();StackPop();StackSetTop(=(double)(((int)StackTop())##op##RightSide));}
#define BinaryOp(op)           {double RightSide=StackTop();StackPop();StackSetTop(=StackTop()##op##RightSide);}
#define BinaryAssign(op)       {double RightSide=StackTop();StackPop();StackSetTop(##op##=RightSide);}

#define UnaryIntOp(op)         {StackSetTop(=op##((int)StackTop()));}
#define UnaryOp(op)            {StackSetTop(=op##(StackTop()));}

	for (int i = 0; i < Size; i++)
	{
		switch (pList[i].Op)
		{
		case CO_NUMBER:
			StackPush(pList[i].Value);
			break;
		case CO_ADD:
			BinaryAssign(+);
			break;
		case CO_MULTIPLY:
			BinaryAssign(*);
			break;
		case CO_SUBTRACT:
			BinaryAssign(-);
			break;
		case CO_NEGATE:
			UnaryOp(-);
			break;
		case CO_DIVIDE:
			if (StackTop())
			{
				BinaryAssign(/ );
			}
			else
			{
				//printf("Divide by zero error\n");
				FatalError("Divide by zero in calculation");
				return false;
			}
			break;

		case CO_IDIVIDE://TODO: SPECIAL HANDLING
		{
			int Right = (int)StackTop();
			if (Right)
			{
				StackPop();
				int Left = (int)StackTop();
				Left /= Right;
				StackSetTop(= Left);
			}
			else
			{
				//printf("Integer divide by zero error\n");
				FatalError("Divide by zero in calculation");
				return false;
			}
		}
		break;

		case CO_MODULUS://TODO: SPECIAL HANDLING
		{
			int Right = (int)StackTop();
			if (Right)
			{
				StackPop();
				int Left = (int)StackTop();
				Left %= Right;
				StackSetTop(= Left);
			}
			else
			{
				//printf("Modulus by zero error\n");
				FatalError("Modulus by zero in calculation");
				return false;
			}
		}
		break;

		case CO_LAND:
			BinaryOp(&&);
			break;
		case CO_LOR:
			BinaryOp(|| );
			break;
		case CO_EQUAL:
			BinaryOp(== );
			break;
		case CO_NOTEQUAL:
			BinaryOp(!= );
			break;
		case CO_GREATER:
			BinaryOp(> );
			break;
		case CO_NOTGREATER:
			BinaryOp(<= );
			break;
		case CO_LESS:
			BinaryOp(< );
			break;
		case CO_NOTLESS:
			BinaryOp(>= );
			break;
		case CO_SHL:
			BinaryIntOp(<< );
			break;
		case CO_SHR:
			BinaryIntOp(>> );
			break;
		case CO_AND:
			BinaryIntOp(&);
			break;
		case CO_OR:
			BinaryIntOp(| );
			break;
		case CO_XOR:
			BinaryIntOp(^);
			break;
		case CO_LNOT:
			UnaryIntOp(!);
			break;
		case CO_NOT:
			UnaryIntOp(~);
			break;
		case CO_POWER:
		{
			double RightSide = StackTop();
			StackPop();
			StackSetTop(= pow(StackTop(), RightSide));
		}
		break;
		}
	}

	Result = StackTop();

#undef StackEmpty
#undef StackTop
#undef StackPush
#undef StackPop

	return true;
}

bool FastCalculate(char* szFormula, double& Result)
{
	//DebugSpew("FastCalculate(%s)",szFormula);
	if (!szFormula || !szFormula[0])
		return false;

	int Length = (int)strlen(szFormula);
	int MaxOps = (Length + 1);

	std::unique_ptr<CalcOp[]> OpsList = std::make_unique<CalcOp[]>(MaxOps);
	CalcOp* pOpList = OpsList.get();
	memset(pOpList, 0, sizeof(CalcOp) * MaxOps);

	std::unique_ptr<eCalcOp[]> Stack = std::make_unique<eCalcOp[]>(MaxOps);
	eCalcOp* pStack = Stack.get();
	memset(pStack, 0, sizeof(eCalcOp) * MaxOps);

	int nOps = 0;
	int nStack = 0;
	char* pEnd = szFormula + Length;
	char CurrentToken[MAX_STRING] = { 0 };
	char* pToken = &CurrentToken[0];

#define OpToList(op)         { pOpList[nOps].Op = op; nOps++; }
#define ValueToList(val)     { pOpList[nOps].Value = val; nOps++; }
#define StackEmpty()         (nStack == 0)
#define StackTop()           (pStack[nStack])
#define StackPush(op)        { nStack++; pStack[nStack] = op; }
#define StackPop()           { if (!nStack) { FatalError("Illegal arithmetic in calculation"); return 0; } nStack--;}
#define HasPrecedence(a,b)   ( CalcOpPrecedence[a] >= CalcOpPrecedence[b])
#define MoveStack(op) {                                                                        \
	while (!StackEmpty() && StackTop() != CO_OPENPARENS && HasPrecedence(StackTop(), op)) {    \
		OpToList(StackTop());                                                                  \
		StackPop();                                                                            \
	}                                                                                          \
}
#define FinishString()       { if (pToken != &CurrentToken[0]) { *pToken = 0; ValueToList(GetDoubleFromString(CurrentToken, 0)); pToken = &CurrentToken[0]; *pToken=0; }}
#define NewOp(op)            { FinishString(); MoveStack(op); StackPush(op); }
#define NextChar(ch)         { *pToken = ch; pToken++; }

	bool WasParen = false;
	for (char* pCur = szFormula; pCur < pEnd; pCur++)
	{
		switch (*pCur)
		{
		case ' ':
			continue;
		case '(':
			FinishString();
			StackPush(CO_OPENPARENS);
			break;
		case ')':
			FinishString();
			while (StackTop() != CO_OPENPARENS)
			{
				OpToList(StackTop());
				StackPop();
			}
			StackPop();
			WasParen = true;
			continue;
		case '+':
			if (pCur[1] != '+')
				NewOp(CO_ADD);
			break;
		case '-':
			if (pCur[1] == '-')
			{
				pCur++;
				NewOp(CO_ADD);
			}
			else
			{
				if (CurrentToken[0] || WasParen)
				{
					NewOp(CO_SUBTRACT);
				}
				else
					NewOp(CO_NEGATE);
			}
			break;
		case '*':
			NewOp(CO_MULTIPLY);
			break;
		case '\\':
			NewOp(CO_IDIVIDE);
			break;
		case '/':
			NewOp(CO_DIVIDE);
			break;
		case '|':
			if (pCur[1] == '|')
			{
				// Logical OR
				++pCur;
				NewOp(CO_LOR);
			}
			else
			{
				// Bitwise OR
				NewOp(CO_OR);
			}
			break;
		case '%':
			NewOp(CO_MODULUS);
			break;
		case '~':
			NewOp(CO_NOT);
			break;
		case '&':
			if (pCur[1] == '&')
			{
				// Logical AND
				++pCur;
				NewOp(CO_LAND);
			}
			else
			{
				// Bitwise AND
				NewOp(CO_AND);
			}
			break;
		case '^':
			if (pCur[1] == '^')
			{
				// XOR
				++pCur;
				NewOp(CO_XOR);
			}
			else
			{
				// POWER
				NewOp(CO_POWER);
			}
			break;
		case '!':
			if (pCur[1] == '=')
			{
				++pCur;
				NewOp(CO_NOTEQUAL);
			}
			else
			{
				NewOp(CO_LNOT);
			}
			break;
		case '=':
			if (pCur[1] == '=')
			{
				++pCur;
				NewOp(CO_EQUAL);
			}
			else
			{
				//printf("Unparsable: '%c'\n",*pCur);
				// error
				return false;
			}
			break;
		case '<':
			if (pCur[1] == '=')
			{
				++pCur;
				NewOp(CO_NOTGREATER);
			}
			else if (pCur[1] == '<')
			{
				++pCur;
				NewOp(CO_SHL);
			}
			else
			{
				NewOp(CO_LESS);
			}
			break;
		case '>':
			if (pCur[1] == '=')
			{
				++pCur;
				NewOp(CO_NOTLESS);
			}
			else if (pCur[1] == '>')
			{
				++pCur;
				NewOp(CO_SHR);
			}
			else
			{
				NewOp(CO_GREATER);
			}
			break;
		case '.':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			NextChar(*pCur);
			break;
		default:
		{
			//printf("Unparsable: '%c'\n",*pCur);
			FatalError("Unparsable in Calculation: '%c'", *pCur);
			// unparsable
			return false;
		}
		}
		WasParen = false;
	}
	FinishString();

	while (!StackEmpty())
	{
		OpToList(StackTop());
		StackPop();
	}

	return EvaluateRPN(pOpList, nOps, Result);
}

bool Calculate(const char* szFormula, double& Result)
{
	char Buffer[MAX_STRING] = { 0 };
	strcpy_s(Buffer, szFormula);
	_strupr_s(Buffer);

	while (char* pNull = strstr(Buffer, "NULL"))
	{
		pNull[0] = '0';
		pNull[1] = '.';
		pNull[2] = '0';
		pNull[3] = '0';
	}

	while (char* pTrue = strstr(Buffer, "TRUE"))
	{
		pTrue[0] = '1';
		pTrue[1] = '.';
		pTrue[2] = '0';
		pTrue[3] = '0';
	}

	while (char* pFalse = strstr(Buffer, "FALSE"))
	{
		pFalse[0] = '0';
		pFalse[1] = '.';
		pFalse[2] = '0';
		pFalse[3] = '0';
		pFalse[4] = '0';
	}

	bool Ret;
	Benchmark(bmCalculate, Ret = FastCalculate(Buffer, Result));
	return Ret;
}

bool PlayerHasAAAbility(int AAIndex)
{
	for (int i = 0; i < AA_CHAR_MAX_REAL; i++)
	{
		if (pLocalPC->GetAlternateAbilityId(i) == AAIndex)
			return true;
	}
	return false;
}

int GetAAIndexByName(const char* AAName)
{
	int level = pLocalPlayer ? pLocalPlayer->Level : -1;

	// check bought aa's first
	for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
	{
		if (CAltAbilityData* pAbility = GetAAById(pLocalPC->GetAlternateAbilityId(nAbility), level))
		{
			if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
			{
				if (!_stricmp(AAName, pName))
				{
					return pAbility->Index;
				}
			}
		}
	}

	// not found? fine lets check them all then...
	for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
	{
		if (CAltAbilityData* pAbility = GetAAById(nAbility, level))
		{
			if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
			{
				if (!_stricmp(AAName, pName))
				{
					return pAbility->Index;
				}
			}
		}
	}

	return 0;
}

int GetAAIndexByID(int ID)
{
	// check our bought aa's first
	for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
	{
		if (CAltAbilityData* pAbility = GetAAById(pLocalPC->GetAlternateAbilityId(nAbility)))
		{
			if (pAbility->ID == ID)
			{
				return pAbility->Index;
			}
		}
	}

	// didnt find it? fine we go through them all then...
	for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
	{
		if (CAltAbilityData* pAbility = GetAAById(nAbility))
		{
			if (pAbility->ID == ID)
			{
				return pAbility->Index;
			}
		}
	}

	return 0;
}

bool IsPCNear(SPAWNINFO* pSpawn, float Radius)
{
	SPAWNINFO* pClose = pSpawnList;
	while (pClose)
	{
		if (!IsInGroup(pClose) && (pClose->Type == SPAWN_PLAYER))
		{
			if ((pClose != pSpawn) && (Distance3DToSpawn(pClose, pSpawn) < Radius))
				return true;
		}
		pClose = pClose->pNext;
	}
	return false;
}

/*
 * Returns group member including self
 */
bool IsInGroup(SPAWNINFO* pSpawn, bool bCorpse /* = false */)
{
	if (pSpawn == nullptr)
		return false;

	if (!pLocalPC->Group)
		return false;
	if (pSpawn == pLocalPC->pSpawn)
		return true;

	for (int i = 1; i < MAX_GROUP_SIZE; i++)
	{
		if (CGroupMember* pMember = pLocalPC->Group->GetGroupMember(i))
		{
			if (!bCorpse)
			{
				if (!_stricmp(pMember->GetName(), pSpawn->Name))
				{
					return true;
				}
			}
			else
			{
				char szSearch[256] = { 0 };
				strcpy_s(szSearch, pMember->GetName());
				strcat_s(szSearch, "'s corpse");

				if (!_strnicmp(pSpawn->Name, szSearch, strlen(szSearch)))
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool IsInRaid(SPAWNINFO* pSpawn, bool bCorpse)
{
	if (pSpawn == nullptr)
		return false;
	if (pSpawn == pLocalPlayer)
		return true;

	size_t l = strlen(pSpawn->Name);

	for (auto& member : pRaid->RaidMember)
	{
		if (!bCorpse)
		{
			if (!_strnicmp(member.Name, pSpawn->Name, l + 1)
				&& member.nClass == pSpawn->GetClass())
			{
				return true;
			}
		}
		else
		{
			char szSearch[256] = { 0 };
			strcpy_s(szSearch, member.Name);
			strcat_s(szSearch, "'s corpse");

			size_t l = strlen(szSearch);
			if (!_strnicmp(szSearch, pSpawn->Name, l)
				&& member.nClass == pSpawn->GetClass())
			{
				return true;
			}
		}
	}

	return false;
}

bool IsInFellowship(SPAWNINFO* pSpawn, bool bCorpse)
{
	if (pSpawn == nullptr)
		return false;

	if (!pLocalPlayer)
		return false;

	SFellowship& Fellowship = pLocalPlayer->Fellowship;

	for (int i = 0; i < Fellowship.Members; i++)
	{
		if (!bCorpse)
		{
			if (!_stricmp(Fellowship.FellowshipMember[i].Name, pSpawn->Name))
			{
				return true;
			}
		}
		else
		{
			char szSearch[256] = { 0 };
			strcpy_s(szSearch, Fellowship.FellowshipMember[i].Name);
			strcat_s(szSearch, "'s corpse");

			if (!_strnicmp(szSearch, pSpawn->Name, strlen(szSearch))
				&& Fellowship.FellowshipMember[i].Class == pSpawn->GetClass())
			{
				return true;
			}
		}
	}

	return false;
}

bool IsNamed(SPAWNINFO* pSpawn)
{
	if (pSpawn)
	{
		char szTemp[MAX_STRING] = { 0 };

		if (GetSpawnType(pSpawn) != NPC)
			return false;
		if (!IsTargetable(pSpawn))
			return false;
		if (pSpawn->GetClass() >= GM_First && pSpawn->GetClass() <= GM_Last)
			return false;

		switch (pSpawn->GetClass())
		{
		case Class_Banker:
		case Class_Merchant:
		case Class_PointMerchant:
		case Class_Adventure:
		case Class_AdventureMerchant:
		case Class_Object:
		case Class_TributeMaster:
		case Class_GuildTributeMaster:
		case Class_TributeMaster2:
		case Class_GuildBanker:
		case Class_GoodPointMerchant:
		case Class_EvilPointMerchant:
		case Class_FellowshipMaster:
		case Class_MercenaryMerchant:
		case Class_LoyaltyMerchant:
		case Class_RealEstateMerchant:
		case Class_TaskMerchant:
		case Class_PvPMerchant:
			return false;
		}

		strcpy_s(szTemp, pSpawn->Name);
		char* Next_Token1 = nullptr;

		if (char* Cmd = strtok_s(szTemp, " ", &Next_Token1))
		{
			// Checking for mobs that have 'A' or 'An' as their first name
			if (Cmd[0] == 'A')
			{
				if (Cmd[1] == '_')
					return false;
				else if (Cmd[1] == 'n')
					if (Cmd[2] == '_')
						return false;
			}

			if (!gUseNewNamedTest)
			{
				if (!_strnicmp(Cmd, "Guard", 5)
					|| !_strnicmp(Cmd, "Defender", 8)
					|| !_strnicmp(Cmd, "Soulbinder", 10)
					|| !_strnicmp(Cmd, "Aura", 4)
					|| !_strnicmp(Cmd, "Sage", 4)
					//|| !_strnicmp(szTemp,"High_Priest", 11)
					|| !_strnicmp(Cmd, "Ward", 4)
					//|| !_strnicmp(szTemp,"Shroudkeeper", 12)
					|| !_strnicmp(Cmd, "Eye of", 6)
					|| !_strnicmp(Cmd, "Imperial_Crypt", 14)
					|| !_strnicmp(Cmd, "Diaku", 5))
				{
					return false;
				}
			}

			if (Cmd[0] == '#' && (!gUseNewNamedTest || (gUseNewNamedTest && !pSpawn->Lastname[0])))
				return true;

			if (isupper(Cmd[0]) && (!gUseNewNamedTest || (gUseNewNamedTest && !pSpawn->Lastname[0])))
				return true;
		}
	}

	return false;
}

char* FormatSearchSpawn(char* Buffer, size_t BufferSize, MQSpawnSearch* pSearchSpawn)
{
	if (!Buffer)
		return nullptr;

	char szTemp[MAX_STRING] = { 0 };

	if (!pSearchSpawn)
	{
		strcpy_s(Buffer, BufferSize, "None");
		return Buffer;
	}

	const char* pszSpawnType = nullptr;
	switch (pSearchSpawn->SpawnType)
	{
	case NONE:
	default:
		pszSpawnType = "any";
		break;
	case PC:
		pszSpawnType = "pc";
		break;
	case MOUNT:
		pszSpawnType = "mount";
		break;
	case PET:
		pszSpawnType = "pet";
		break;
	case PCPET:
		pszSpawnType = "pcpet";
		break;
	case NPCPET:
		pszSpawnType = "npcpet";
		break;
	case XTARHATER:
		pszSpawnType = "xtarhater";
		break;
	case NPC:
		pszSpawnType = "npc";
		break;
	case CORPSE:
		pszSpawnType = "corpse";
		break;
	case TRIGGER:
		pszSpawnType = "trigger";
		break;
	case TRAP:
		pszSpawnType = "trap";
		break;
	case CHEST:
		pszSpawnType = "chest";
		break;
	case TIMER:
		pszSpawnType = "timer";
		break;
	case UNTARGETABLE:
		pszSpawnType = "untargetable";
		break;
	case MERCENARY:
		pszSpawnType = "mercenary";
		break;
	case FLYER:
		pszSpawnType = "flyer";
		break;
	}

	sprintf_s(Buffer, BufferSize, "(%d-%d) %s", pSearchSpawn->MinLevel, pSearchSpawn->MaxLevel, pszSpawnType);

	if (pSearchSpawn->szName[0] != 0)
	{
		if (pSearchSpawn->bExactName)
		{
			sprintf_s(szTemp, " whose name exactly matches %s", pSearchSpawn->szName);
		}
		else
		{
			sprintf_s(szTemp, " whose name contains %s", pSearchSpawn->szName);
		}
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->szRace[0] != 0)
	{
		sprintf_s(szTemp, " Race:%s", pSearchSpawn->szRace);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->szClass[0] != 0)
	{
		sprintf_s(szTemp, " Class:%s", pSearchSpawn->szClass);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->szBodyType[0] != 0)
	{
		sprintf_s(szTemp, " Body:%s", pSearchSpawn->szBodyType);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->GuildID != -1 && pSearchSpawn->GuildID != 0)
	{
		const char* szGuild = GetGuildByID(pSearchSpawn->GuildID);
		sprintf_s(szTemp, " Guild:%s", szGuild ? szGuild : "Unknown");
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->bKnownLocation)
	{
		sprintf_s(szTemp, " at %1.2f,%1.2f", pSearchSpawn->yLoc, pSearchSpawn->xLoc);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->FRadius < 10000.0f)
	{
		sprintf_s(szTemp, " Radius:%1.2f", pSearchSpawn->FRadius);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->ZRadius < 10000.0f)
	{
		sprintf_s(szTemp, " Z:%1.2f", pSearchSpawn->ZRadius);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->Radius > 0.0f)
	{
		sprintf_s(szTemp, " NoPC:%1.2f", pSearchSpawn->Radius);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->SpawnID)
	{
		sprintf_s(szTemp, " ID:%d", pSearchSpawn->SpawnID);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->NotID)
	{
		sprintf_s(szTemp, " NotID:%d", pSearchSpawn->NotID);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->bAlert)
	{
		sprintf_s(szTemp, " Alert:%d", pSearchSpawn->AlertList);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->bNoAlert)
	{
		sprintf_s(szTemp, " NoAlert:%d", pSearchSpawn->NoAlertList);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->bNearAlert)
	{
		sprintf_s(szTemp, " NearAlert:%d", pSearchSpawn->NearAlertList);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->bNotNearAlert)
	{
		sprintf_s(szTemp, " NotNearAlert:%d", pSearchSpawn->NotNearAlertList);
		strcat_s(Buffer, BufferSize, szTemp);
	}

	if (pSearchSpawn->bGM && pSearchSpawn->SpawnType != NPC)
		strcat_s(Buffer, BufferSize, " GM");
	if (pSearchSpawn->bTrader)
		strcat_s(Buffer, BufferSize, " Trader");
	if (pSearchSpawn->bXTarHater)
		strcat_s(Buffer, BufferSize, " XTarHater");
	if (pSearchSpawn->bLFG)
		strcat_s(Buffer, BufferSize, " LFG");

	if (pSearchSpawn->bLight)
	{
		strcat_s(Buffer, BufferSize, " Light");
		if (pSearchSpawn->szLight[0])
		{
			strcat_s(Buffer, BufferSize, ":");
			strcat_s(Buffer, BufferSize, pSearchSpawn->szLight);
		}
	}

	if (pSearchSpawn->bLoS)
		strcat_s(Buffer, BufferSize, " LoS");

	return Buffer;
}

SPAWNINFO* NthNearestSpawn(MQSpawnSearch* pSearchSpawn, int Nth, SPAWNINFO* pOrigin, bool IncludeOrigin)
{
	if (!pSearchSpawn || Nth == 0 || !pOrigin)
		return nullptr;

	std::vector<MQSpawnArrayItem> spawnSet;
	spawnSet.reserve(gSpawnsArray.size());

	for (const MQSpawnArrayItem& item : gSpawnsArray)
	{
		SPAWNINFO* pSpawn = item.GetSpawn();

		if (!IncludeOrigin && pSpawn == pOrigin)
			continue;

		if (SpawnMatchesSearch(pSearchSpawn, pOrigin, pSpawn))
		{
			float distSq = Get3DDistanceSquared(pOrigin->X, pOrigin->Y, pOrigin->Z,
				pSpawn->X, pSpawn->Y, pSpawn->Z);

			// Spawn matches our search, add it to our set.
			spawnSet.emplace_back(pSpawn, distSq);
		}
	}

	if (Nth > static_cast<int>(spawnSet.size()))
	{
		return nullptr;
	}

	// sort our list
	std::sort(std::begin(spawnSet), std::end(spawnSet), MQRankFloatCompare);

	// get our Nth nearest
	return spawnSet[Nth - 1].GetSpawn();
}

int CountMatchingSpawns(MQSpawnSearch* pSearchSpawn, SPAWNINFO* pOrigin, bool IncludeOrigin)
{
	if (!pSearchSpawn || !pOrigin)
		return 0;

	int TotalMatching = 0;
	SPAWNINFO* pSpawn = pSpawnList;

	if (IncludeOrigin)
	{
		while (pSpawn)
		{
			if (SpawnMatchesSearch(pSearchSpawn, pOrigin, pSpawn))
			{
				TotalMatching++;
			}
			pSpawn = pSpawn->pNext;
		}
	}
	else
	{
		while (pSpawn)
		{
			if (pSpawn != pOrigin && SpawnMatchesSearch(pSearchSpawn, pOrigin, pSpawn))
			{
				// matches search, add to our set
				TotalMatching++;
			}
			pSpawn = pSpawn->pNext;
		}
	}
	return TotalMatching;
}

SPAWNINFO* SearchThroughSpawns(MQSpawnSearch* pSearchSpawn, SPAWNINFO* pChar)
{
	SPAWNINFO* pFromSpawn = nullptr;

	if (pSearchSpawn->FromSpawnID > 0 && (pSearchSpawn->bTargNext || pSearchSpawn->bTargPrev))
	{
		pFromSpawn = GetSpawnByID(pSearchSpawn->FromSpawnID);
		if (!pFromSpawn) return nullptr;
		for (int index = 0; index < (int)gSpawnsArray.size(); index++)
		{
			const MQSpawnArrayItem& item = gSpawnsArray[index];

			if (item.GetSpawn() == pFromSpawn)
			{
				if (pSearchSpawn->bTargPrev)
				{
					index--;
					for (; index >= 0; index--)
					{
						SPAWNINFO* pPrevSpawn = gSpawnsArray[index].GetSpawn();

						if (pPrevSpawn
							&& SpawnMatchesSearch(pSearchSpawn, pFromSpawn, pPrevSpawn))
						{
							return pPrevSpawn;
						}
					}
				}
				else
				{
					index++;
					for (; index < (int)gSpawnsArray.size(); index++)
					{
						SPAWNINFO* pNextSpawn = gSpawnsArray[index].GetSpawn();

						if (pNextSpawn
							&& SpawnMatchesSearch(pSearchSpawn, pFromSpawn, pNextSpawn))
						{
							return pNextSpawn;
						}
					}
				}
				return nullptr;
			}
		}
	}

	return NthNearestSpawn(pSearchSpawn, 1, pChar, true);
}

bool SearchSpawnMatchesSearchSpawn(MQSpawnSearch* pSearchSpawn1, MQSpawnSearch* pSearchSpawn2)
{
	if (pSearchSpawn1->AlertList != pSearchSpawn2->AlertList)
		return false;
	if (pSearchSpawn1->SpawnType != pSearchSpawn2->SpawnType)
		return false;
	if (pSearchSpawn1->FRadius != pSearchSpawn2->FRadius)
		return false;
	if (pSearchSpawn1->FromSpawnID != pSearchSpawn2->FromSpawnID)
		return false;
	if (pSearchSpawn1->GuildID != pSearchSpawn2->GuildID)
		return false;
	if (pSearchSpawn1->MaxLevel != pSearchSpawn2->MaxLevel)
		return false;
	if (pSearchSpawn1->MinLevel != pSearchSpawn2->MinLevel)
		return false;
	if (pSearchSpawn1->NearAlertList != pSearchSpawn2->NearAlertList)
		return false;
	if (pSearchSpawn1->NoAlertList != pSearchSpawn2->NoAlertList)
		return false;
	if (pSearchSpawn1->NotID != pSearchSpawn2->NotID)
		return false;
	if (pSearchSpawn1->NotNearAlertList != pSearchSpawn2->NotNearAlertList)
		return false;
	if (pSearchSpawn1->Radius != pSearchSpawn2->Radius)
		return false;
	if (pSearchSpawn1->SortBy != pSearchSpawn2->SortBy)
		return false;
	if (pSearchSpawn1->SpawnID != pSearchSpawn2->SpawnID)
		return false;
	if (_stricmp(pSearchSpawn1->szBodyType, pSearchSpawn2->szBodyType))
		return false;
	if (_stricmp(pSearchSpawn1->szClass, pSearchSpawn2->szClass))
		return false;
	if (_stricmp(pSearchSpawn1->szLight, pSearchSpawn2->szLight))
		return false;
	if (_stricmp(pSearchSpawn1->szName, pSearchSpawn2->szName))
		return false;
	if (_stricmp(pSearchSpawn1->szRace, pSearchSpawn2->szRace))
		return false;
	if (pSearchSpawn1->xLoc != pSearchSpawn2->xLoc)
		return false;
	if (pSearchSpawn1->yLoc != pSearchSpawn2->yLoc)
		return false;
	if (pSearchSpawn1->ZRadius != pSearchSpawn2->ZRadius)
		return false;
	if (pSearchSpawn1->bAlert != pSearchSpawn2->bAlert)
		return false;
	if (pSearchSpawn1->bAura != pSearchSpawn2->bAura)
		return false;
	if (pSearchSpawn1->bBanner != pSearchSpawn2->bBanner)
		return false;
	if (pSearchSpawn1->bCampfire != pSearchSpawn2->bCampfire)
		return false;
	if (pSearchSpawn1->bDps != pSearchSpawn2->bDps)
		return false;
	if (pSearchSpawn1->bExactName != pSearchSpawn2->bExactName)
		return false;
	if (pSearchSpawn1->bGM != pSearchSpawn2->bGM)
		return false;
	if (pSearchSpawn1->bGroup != pSearchSpawn2->bGroup)
		return false;
	if (pSearchSpawn1->bFellowship != pSearchSpawn2->bFellowship)
		return false;
	if (pSearchSpawn1->bKnight != pSearchSpawn2->bKnight)
		return false;
	if (pSearchSpawn1->bKnownLocation != pSearchSpawn2->bKnownLocation)
		return false;
	if (pSearchSpawn1->bLFG != pSearchSpawn2->bLFG)
		return false;
	if (pSearchSpawn1->bLight != pSearchSpawn2->bLight)
		return false;
	if (pSearchSpawn1->bLoS != pSearchSpawn2->bLoS)
		return false;
	if (pSearchSpawn1->bMerchant != pSearchSpawn2->bMerchant)
		return false;
	if (pSearchSpawn1->bBanker != pSearchSpawn2->bBanker)
		return false;
	if (pSearchSpawn1->bNamed != pSearchSpawn2->bNamed)
		return false;
	if (pSearchSpawn1->bNearAlert != pSearchSpawn2->bNearAlert)
		return false;
	if (pSearchSpawn1->bNoAlert != pSearchSpawn2->bNoAlert)
		return false;
	if (pSearchSpawn1->bNoGroup != pSearchSpawn2->bNoGroup)
		return false;
	if (pSearchSpawn1->bNoGuild != pSearchSpawn2->bNoGuild)
		return false;
	if (pSearchSpawn1->bNoPet != pSearchSpawn2->bNoPet)
		return false;
	if (pSearchSpawn1->bNotNearAlert != pSearchSpawn2->bNotNearAlert)
		return false;
	if (pSearchSpawn1->bRaid != pSearchSpawn2->bRaid)
		return false;
	if (pSearchSpawn1->bSlower != pSearchSpawn2->bSlower)
		return false;
	if (pSearchSpawn1->bSpawnID != pSearchSpawn2->bSpawnID)
		return false;
	if (pSearchSpawn1->bTank != pSearchSpawn2->bTank)
		return false;
	if (pSearchSpawn1->bTargetable != pSearchSpawn2->bTargetable)
		return false;
	if (pSearchSpawn1->bTargNext != pSearchSpawn2->bTargNext)
		return false;
	if (pSearchSpawn1->bTargPrev != pSearchSpawn2->bTargPrev)
		return false;
	if (pSearchSpawn1->bTrader != pSearchSpawn2->bTrader)
		return false;
	if (pSearchSpawn1->bTributeMaster != pSearchSpawn2->bTributeMaster)
		return false;
	if (pSearchSpawn1->bXTarHater != pSearchSpawn2->bXTarHater)
		return false;

	return true;
}

bool SpawnMatchesSearch(MQSpawnSearch* pSearchSpawn, SPAWNINFO* pChar, SPAWNINFO* pSpawn)
{
	if (pSearchSpawn == nullptr || pChar == nullptr || pSpawn == nullptr || !pLocalPC)
		return false;

	eSpawnType SpawnType = GetSpawnType(pSpawn);

	if (SpawnType == PET)
	{
		if (pSearchSpawn->bNoPet)
			return false;

		if (pSearchSpawn->SpawnType == NPCPET || pSearchSpawn->SpawnType == PCPET || pSearchSpawn->SpawnType == NPC)
		{
			if (SPAWNINFO* pTheMaster = GetSpawnByID(pSpawn->MasterID))
			{
				if (pTheMaster->Type != SPAWN_PLAYER)
				{
					if (pSearchSpawn->SpawnType == PCPET)
						return false;
				}
				else if (pSearchSpawn->SpawnType != PCPET)
				{
					return false;
				}
			}
			else if (pSearchSpawn->SpawnType == PCPET)
			{
				return false;
			}

			SpawnType = pSearchSpawn->SpawnType;
		}
	}

	if (pSearchSpawn->SpawnType != SpawnType && pSearchSpawn->SpawnType != NONE)
	{
		if (pSearchSpawn->SpawnType == NPCCORPSE)
		{
			if (SpawnType != CORPSE || pSpawn->Deity)
			{
				return false;
			}
		}
		else if (pSearchSpawn->SpawnType == PCCORPSE)
		{
			if (SpawnType != CORPSE || !pSpawn->Deity)
			{
				return false;
			}
		}
		else if (pSearchSpawn->SpawnType == NPC && SpawnType == UNTARGETABLE)
		{
			return false;
		}

		// if the search type is not npc or the mob type is UNT, continue?
		// stupid /who

		else if (pSearchSpawn->SpawnType != NPC || SpawnType != UNTARGETABLE)
		{
			return false;
		}
	}

	if (pSearchSpawn->MinLevel && pSpawn->Level < pSearchSpawn->MinLevel)
		return false;
	if (pSearchSpawn->MaxLevel && pSpawn->Level > pSearchSpawn->MaxLevel)
		return false;
	if (pSearchSpawn->NotID == pSpawn->SpawnID)
		return false;
	if (pSearchSpawn->bSpawnID && pSearchSpawn->SpawnID != pSpawn->SpawnID)
		return false;
	if (pSearchSpawn->GuildID != -1 && pSearchSpawn->GuildID != pSpawn->GuildID)
		return false;

	if (pSearchSpawn->bGM && pSearchSpawn->SpawnType != NPC)
	{
		if (!pSpawn->GM)
			return false;
	}

	if (pSearchSpawn->bGM && pSearchSpawn->SpawnType == NPC)
	{
		if (pSpawn->GetClass() < 20 || pSpawn->GetClass() > 35)
			return false;
	}

	if (pSearchSpawn->bNamed && !IsNamed(pSpawn))
		return false;
	if (pSearchSpawn->bMerchant && pSpawn->GetClass() != 41)
		return false;
	if (pSearchSpawn->bBanker && pSpawn->GetClass() != 40)
		return false;
	if (pSearchSpawn->bTributeMaster && pSpawn->GetClass() != 63)
		return false;
	if (pSearchSpawn->bNoGuild && (pSpawn->GuildID != -1 && pSpawn->GuildID != 0))
		return false;

	if (pSearchSpawn->bKnight && pSearchSpawn->SpawnType != NPC)
	{
		if (pSpawn->GetClass() != Paladin
			&& pSpawn->GetClass() != Shadowknight)
		{
			return false;
		}
	}

	if (pSearchSpawn->bTank && pSearchSpawn->SpawnType != NPC)
	{
		if (pSpawn->GetClass() != Paladin
			&& pSpawn->GetClass() != Shadowknight
			&& pSpawn->GetClass() != Warrior)
		{
			return false;
		}
	}

	if (pSearchSpawn->bHealer && pSearchSpawn->SpawnType != NPC)
	{
		if (pSpawn->GetClass() != Cleric
			&& pSpawn->GetClass() != Druid
			&& pSpawn->GetClass() != Shaman)
		{
			return false;
		}
	}

	if (pSearchSpawn->bDps && pSearchSpawn->SpawnType != NPC)
	{
		if (pSpawn->GetClass() != Ranger
			&& pSpawn->GetClass() != Rogue
			&& pSpawn->GetClass() != Wizard
			&& pSpawn->GetClass() != Berserker)
		{
			return false;
		}
	}

	if (pSearchSpawn->bSlower && pSearchSpawn->SpawnType != NPC)
	{
		if (pSpawn->GetClass() != Shaman
			&& pSpawn->GetClass() != Enchanter
			&& pSpawn->GetClass() != Beastlord
			&& pSpawn->GetClass() != Bard)
		{
			return false;
		}
	}

	if (pSearchSpawn->bLFG && !pSpawn->LFG)
		return false;
	if (pSearchSpawn->bTrader && !pSpawn->Trader)
		return false;

	if (pSearchSpawn->bXTarHater)
	{
		bool foundhater = false;

		for (const ExtendedTargetSlot& xts : *pLocalPC->pExtendedTargetList)
		{
			if (xts.xTargetType == XTARGET_AUTO_HATER
				&& xts.XTargetSlotStatus != eXTSlotEmpty
				&& xts.SpawnID != 0)
			{
				SPAWNINFO* pXTargetSpawn = GetSpawnByID(xts.SpawnID);
				if (pXTargetSpawn != nullptr
					&& pXTargetSpawn->SpawnID == pSpawn->SpawnID)
				{
					foundhater = true;
				}
			}
		}

		if (!foundhater)
		{
			return false;
		}
	}

	if (pSearchSpawn->bNoGroup && IsInGroup(pSpawn))
	{
		return false;
	}

	if (pSearchSpawn->bGroup && !IsInGroup(pSpawn, pSearchSpawn->SpawnType == PCCORPSE || pSpawn->Type == SPAWN_CORPSE))
	{
		return false;
	}

	if (pSearchSpawn->bFellowship && !IsInFellowship(pSpawn, pSearchSpawn->SpawnType == PCCORPSE || pSpawn->Type == SPAWN_CORPSE))
	{
		return false;
	}

	if (pSearchSpawn->bRaid && !IsInRaid(pSpawn, pSearchSpawn->SpawnType == PCCORPSE || pSpawn->Type == SPAWN_CORPSE))
	{
		return false;
	}

	if (pSearchSpawn->bKnownLocation)
	{
		if ((pSearchSpawn->xLoc != pSpawn->X || pSearchSpawn->yLoc != pSpawn->Y))
		{
			if (pSearchSpawn->FRadius < 10000.0f
				&& Distance3DToPoint(pSpawn, pSearchSpawn->xLoc, pSearchSpawn->yLoc, pSearchSpawn->zLoc)>pSearchSpawn->FRadius)
			{
				return false;
			}
		}
	}
	else if (pSearchSpawn->FRadius < 10000.0f && Distance3DToSpawn(pChar, pSpawn)>pSearchSpawn->FRadius)
	{
		return false;
	}

	if (pSearchSpawn->Radius > 0.0f && IsPCNear(pSpawn, pSearchSpawn->Radius))
		return false;
	if (gZFilter < 10000.0f && ((pSpawn->Z > pSearchSpawn->zLoc + gZFilter) || (pSpawn->Z < pSearchSpawn->zLoc - gZFilter)))
		return false;
	if (pSearchSpawn->ZRadius < 10000.0f && (pSpawn->Z > pSearchSpawn->zLoc + pSearchSpawn->ZRadius || pSpawn->Z < pSearchSpawn->zLoc - pSearchSpawn->ZRadius))
		return false;
	if (pSearchSpawn->bLight)
	{
		const char* pLight = GetLightForSpawn(pSpawn);
		if (!_stricmp(pLight, "NONE"))
			return false;
		if (pSearchSpawn->szLight[0] && _stricmp(pLight, pSearchSpawn->szLight))
			return false;
	}
	if ((pSearchSpawn->bAlert) && CAlerts.AlertExist(pSearchSpawn->AlertList))
	{
		if (!IsAlert(pChar, pSpawn, pSearchSpawn->AlertList))
			return false;
	}
	if ((pSearchSpawn->bNoAlert) && CAlerts.AlertExist(pSearchSpawn->NoAlertList))
	{
		if (IsAlert(pChar, pSpawn, pSearchSpawn->NoAlertList))
			return false;
	}
	if (pSearchSpawn->bNotNearAlert && GetClosestAlert(pSpawn, pSearchSpawn->NotNearAlertList))
		return false;
	if (pSearchSpawn->bNearAlert && !GetClosestAlert(pSpawn, pSearchSpawn->NearAlertList))
		return false;
	if (pSearchSpawn->szClass[0] && _stricmp(pSearchSpawn->szClass, GetClassDesc(pSpawn->GetClass())))
		return false;
	if (pSearchSpawn->szBodyType[0] && _stricmp(pSearchSpawn->szBodyType, GetBodyTypeDesc(GetBodyType(pSpawn))))
		return false;
	if (pSearchSpawn->szRace[0] && _stricmp(pSearchSpawn->szRace, pEverQuest->GetRaceDesc(pSpawn->GetRace())))
		return false;
	if (pSearchSpawn->bLoS && !pControlledPlayer->CanSee(*pSpawn))
		return false;
	if (pSearchSpawn->bTargetable && !IsTargetable(pSpawn))
		return false;
	if (pSearchSpawn->PlayerState && !(pSpawn->PlayerState & pSearchSpawn->PlayerState)) // if player state isn't 0 and we have that bit set
		return false;

	if (pSearchSpawn->szName[0] && pSpawn->Name[0])
	{
		if (ci_find_substr(pSpawn->Name, pSearchSpawn->szName) == -1)
		{
			char szCleanName[EQ_MAX_NAME] = { 0 };
			strcpy_s(szCleanName, pSpawn->Name);
			CleanupName(szCleanName, sizeof(szCleanName), false);

			if (ci_find_substr(szCleanName, pSearchSpawn->szName) == -1)
				return false;
		}

		if (pSearchSpawn->bExactName)
		{
			char szCleanName[EQ_MAX_NAME] = { 0 };
			strcpy_s(szCleanName, pSpawn->Name);
			CleanupName(szCleanName, sizeof(szCleanName), false, !gbExactSearchCleanNames);

			if (!ci_equals(szCleanName, pSearchSpawn->szName))
				return false;
		}
	}

	return true;
}

const char* ParseSearchSpawnArgs(char* szArg, const char* szRest, MQSpawnSearch* pSearchSpawn)
{
	if (szArg && pSearchSpawn)
	{
		if (!_stricmp(szArg, "pc"))
		{
			pSearchSpawn->SpawnType = PC;
		}
		else if (!_stricmp(szArg, "npc"))
		{
			pSearchSpawn->SpawnType = NPC;
		}
		else if (!_stricmp(szArg, "mount"))
		{
			pSearchSpawn->SpawnType = MOUNT;
		}
		else if (!_stricmp(szArg, "pet"))
		{
			pSearchSpawn->SpawnType = PET;
		}
		else if (!_stricmp(szArg, "pcpet"))
		{
			pSearchSpawn->SpawnType = PCPET;
		}
		else if (!_stricmp(szArg, "npcpet"))
		{
			pSearchSpawn->SpawnType = NPCPET;
		}
		else if (!_stricmp(szArg, "xtarhater"))
		{
			pSearchSpawn->bXTarHater = true;
		}
		else if (!_stricmp(szArg, "nopet"))
		{
			pSearchSpawn->bNoPet = true;
		}
		else if (!_stricmp(szArg, "corpse"))
		{
			pSearchSpawn->SpawnType = CORPSE;
		}
		else if (!_stricmp(szArg, "npccorpse"))
		{
			pSearchSpawn->SpawnType = NPCCORPSE;
		}
		else if (!_stricmp(szArg, "pccorpse"))
		{
			pSearchSpawn->SpawnType = PCCORPSE;
		}
		else if (!_stricmp(szArg, "trigger"))
		{
			pSearchSpawn->SpawnType = TRIGGER;
		}
		else if (!_stricmp(szArg, "untargetable"))
		{
			pSearchSpawn->SpawnType = UNTARGETABLE;
		}
		else if (!_stricmp(szArg, "trap"))
		{
			pSearchSpawn->SpawnType = TRAP;
		}
		else if (!_stricmp(szArg, "chest"))
		{
			pSearchSpawn->SpawnType = CHEST;
		}
		else if (!_stricmp(szArg, "timer"))
		{
			pSearchSpawn->SpawnType = TIMER;
		}
		else if (!_stricmp(szArg, "aura"))
		{
			pSearchSpawn->SpawnType = AURA;
		}
		else if (!_stricmp(szArg, "object"))
		{
			pSearchSpawn->SpawnType = OBJECT;
		}
		else if (!_stricmp(szArg, "banner"))
		{
			pSearchSpawn->SpawnType = BANNER;
		}
		else if (!_stricmp(szArg, "campfire"))
		{
			pSearchSpawn->SpawnType = CAMPFIRE;
		}
		else if (!_stricmp(szArg, "mercenary"))
		{
			pSearchSpawn->SpawnType = MERCENARY;
		}
		else if (!_stricmp(szArg, "flyer"))
		{
			pSearchSpawn->SpawnType = FLYER;
		}
		else if (!_stricmp(szArg, "any"))
		{
			pSearchSpawn->SpawnType = NONE;
		}
		else if (!_stricmp(szArg, "next"))
		{
			pSearchSpawn->bTargNext = true;
		}
		else if (!_stricmp(szArg, "prev"))
		{
			pSearchSpawn->bTargPrev = true;
		}
		else if (!_stricmp(szArg, "lfg"))
		{
			pSearchSpawn->bLFG = true;
		}
		else if (!_stricmp(szArg, "gm"))
		{
			pSearchSpawn->bGM = true;
		}
		else if (!_stricmp(szArg, "group"))
		{
			pSearchSpawn->bGroup = true;
		}
		else if (!_stricmp(szArg, "fellowship"))
		{
			pSearchSpawn->bFellowship = true;
		}
		else if (!_stricmp(szArg, "nogroup"))
		{
			pSearchSpawn->bNoGroup = true;
		}
		else if (!_stricmp(szArg, "raid"))
		{
			pSearchSpawn->bRaid = true;
		}
		else if (!_stricmp(szArg, "noguild"))
		{
			pSearchSpawn->bNoGuild = true;
		}
		else if (!_stricmp(szArg, "trader"))
		{
			pSearchSpawn->bTrader = true;
		}
		else if (!_stricmp(szArg, "named"))
		{
			pSearchSpawn->bNamed = true;
		}
		else if (!_stricmp(szArg, "merchant"))
		{
			pSearchSpawn->bMerchant = true;
		}
		else if (!_stricmp(szArg, "banker"))
		{
			pSearchSpawn->bBanker = true;
		}
		else if (!_stricmp(szArg, "tribute"))
		{
			pSearchSpawn->bTributeMaster = true;
		}
		else if (!_stricmp(szArg, "knight"))
		{
			pSearchSpawn->bKnight = true;
		}
		else if (!_stricmp(szArg, "tank"))
		{
			pSearchSpawn->bTank = true;
		}
		else if (!_stricmp(szArg, "healer"))
		{
			pSearchSpawn->bHealer = true;
		}
		else if (!_stricmp(szArg, "dps"))
		{
			pSearchSpawn->bDps = true;
		}
		else if (!_stricmp(szArg, "slower"))
		{
			pSearchSpawn->bSlower = true;
		}
		else if (!_stricmp(szArg, "los"))
		{
			pSearchSpawn->bLoS = true;
		}
		else if (!_stricmp(szArg, "targetable"))
		{
			pSearchSpawn->bTargetable = true;
		}
		else if (!_stricmp(szArg, "range"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->MinLevel = GetIntFromString(szArg, pSearchSpawn->MinLevel);
			GetArg(szArg, szRest, 2);
			pSearchSpawn->MaxLevel = GetIntFromString(szArg, pSearchSpawn->MaxLevel);
			szRest = GetNextArg(szRest, 2);
		}
		else if (!_stricmp(szArg, "loc"))
		{
			pSearchSpawn->bKnownLocation = true;
			GetArg(szArg, szRest, 1);
			pSearchSpawn->xLoc = GetFloatFromString(szArg, 0);
			GetArg(szArg, szRest, 2);
			pSearchSpawn->yLoc = GetFloatFromString(szArg, 0);
			GetArg(szArg, szRest, 3);
			pSearchSpawn->zLoc = GetFloatFromString(szArg, 0);
			if (pSearchSpawn->zLoc == 0.0)
			{
				pSearchSpawn->zLoc = pControlledPlayer->Z;
				szRest = GetNextArg(szRest, 2);
			}
			else
			{
				szRest = GetNextArg(szRest, 3);
			}
		}
		else if (!_stricmp(szArg, "id"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->bSpawnID = true;
			pSearchSpawn->SpawnID = GetIntFromString(szArg, pSearchSpawn->SpawnID);
			szRest = GetNextArg(szRest, 1);
		}
		else if (!_stricmp(szArg, "radius"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->FRadius = GetDoubleFromString(szArg, 0);
			szRest = GetNextArg(szRest, 1);
		}
		else if (!_stricmp(szArg, "body"))
		{
			GetArg(szArg, szRest, 1);
			strcpy_s(pSearchSpawn->szBodyType, szArg);
			szRest = GetNextArg(szRest, 1);
		}
		else if (!_stricmp(szArg, "class"))
		{
			GetArg(szArg, szRest, 1);
			strcpy_s(pSearchSpawn->szClass, szArg);
			szRest = GetNextArg(szRest, 1);
		}
		else if (!_stricmp(szArg, "race"))
		{
			GetArg(szArg, szRest, 1);
			strcpy_s(pSearchSpawn->szRace, szArg);
			szRest = GetNextArg(szRest, 1);
		}
		else if (!_stricmp(szArg, "light"))
		{
			GetArg(szArg, szRest, 1);
			int Light = -1;
			if (szArg[0] != 0)
			{
				for (int i = 0; i < LIGHT_COUNT; i++)
				{
					if (!_stricmp(szLights[i], szArg))
						Light = i;
				}
			}

			if (Light != -1)
			{
				strcpy_s(pSearchSpawn->szLight, szLights[Light]);
				szRest = GetNextArg(szRest, 1);
			}
			else
			{
				pSearchSpawn->szLight[0] = 0;
			}
			pSearchSpawn->bLight = true;
		}
		else if (!_stricmp(szArg, "guild"))
		{
			pSearchSpawn->GuildID = pLocalPC->GuildID;
		}
		else if (!_stricmp(szArg, "guildname"))
		{
			int64_t GuildID = -1;
			GetArg(szArg, szRest, 1);
			if (szArg[0] != 0)
				GuildID = GetGuildIDByName(szArg);
			if (GuildID != -1 && GuildID != 0)
			{
				pSearchSpawn->GuildID = GuildID;
				szRest = GetNextArg(szRest, 1);
			}
			else if (pLocalPlayer)
			{
				GuildID = pLocalPlayer->GuildID;
			}
		}
		else if (!_stricmp(szArg, "alert"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->AlertList = GetIntFromString(szArg, pSearchSpawn->AlertList);
			szRest = GetNextArg(szRest, 1);
			pSearchSpawn->bAlert = true;
		}
		else if (!_stricmp(szArg, "noalert"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->NoAlertList = GetIntFromString(szArg, pSearchSpawn->NoAlertList);
			szRest = GetNextArg(szRest, 1);
			pSearchSpawn->bNoAlert = true;
		}
		else if (!_stricmp(szArg, "notnearalert"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->NotNearAlertList = GetIntFromString(szArg, pSearchSpawn->NotNearAlertList);
			szRest = GetNextArg(szRest, 1);
			pSearchSpawn->bNotNearAlert = true;
		}
		else if (!_stricmp(szArg, "nearalert"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->NearAlertList = GetIntFromString(szArg, pSearchSpawn->NearAlertList);
			szRest = GetNextArg(szRest, 1);
			pSearchSpawn->bNearAlert = true;
		}
		else if (!_stricmp(szArg, "zradius"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->ZRadius = GetDoubleFromString(szArg, 0);
			szRest = GetNextArg(szRest, 1);
		}
		else if (!_stricmp(szArg, "notid"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->NotID = GetIntFromString(szArg, pSearchSpawn->NotID);
			szRest = GetNextArg(szRest, 1);
		}
		else if (!_stricmp(szArg, "nopcnear"))
		{
			GetArg(szArg, szRest, 1);
			if ((szArg[0] == 0) || (0.0f == (pSearchSpawn->Radius = GetFloatFromString(szArg, 0))))
			{
				pSearchSpawn->Radius = 200.0f;
			}
			else
			{
				szRest = GetNextArg(szRest, 1);
			}
		}
		else if (!_stricmp(szArg, "playerstate"))
		{
			GetArg(szArg, szRest, 1);
			pSearchSpawn->PlayerState |= GetIntFromString(szArg, 0); // This allows us to pass multiple playerstate args
			szRest = GetNextArg(szRest, 1);
		}
		else if (IsNumber(szArg))
		{
			pSearchSpawn->MinLevel = GetIntFromString(szArg, pSearchSpawn->MinLevel);
			pSearchSpawn->MaxLevel = pSearchSpawn->MinLevel;
		}
		else
		{
			for (int index = 1; index < (int)lengthof(ClassInfo) - 1; index++)
			{
				if (!_stricmp(szArg, ClassInfo[index].Name) || !_stricmp(szArg, ClassInfo[index].ShortName))
				{
					strcpy_s(pSearchSpawn->szClass, pEverQuest->GetClassDesc(index));
					return szRest;
				}
			}

			if (pSearchSpawn->szName[0])
			{
				// multiple word name
				strcat_s(pSearchSpawn->szName, " ");
				strcat_s(pSearchSpawn->szName, szArg);
			}
			else
			{
				if (szArg[0] == '=')
				{
					pSearchSpawn->bExactName = true;
					szArg++;
				}
				strcpy_s(pSearchSpawn->szName, szArg);
			}
		}
	}

	return szRest;
}

void ParseSearchSpawn(const char* Buffer, MQSpawnSearch* pSearchSpawn)
{
	bRunNextCommand = true;
	const char* szFilter = Buffer;

	char szArg[MAX_STRING] = { 0 };

	while (true)
	{
		GetArg(szArg, szFilter, 1);

		szFilter = GetNextArg(szFilter, 1);
		if (szArg[0] == 0)
		{
			break;
		}

		szFilter = ParseSearchSpawnArgs(szArg, szFilter, pSearchSpawn);
	}
}

bool GetClosestAlert(SPAWNINFO* pChar, uint32_t id)
{
	if (!pSpawnManager) return false;
	if (!pSpawnList) return false;

	SPAWNINFO* pClosest = nullptr;

	float ClosestDistance = 50000.0f;

	std::vector<MQSpawnSearch> search;
	if (CAlerts.GetAlert(id, search))
	{
		for (auto& s : search)
		{
			if (SPAWNINFO* pSpawn = SearchThroughSpawns(&s, pChar))
			{
				const float SpawnDistance = Distance3DToSpawn(pChar, pSpawn);
				if (SpawnDistance < ClosestDistance)
				{
					ClosestDistance = SpawnDistance;
					pClosest = pSpawn;
				}
			}
		}
	}

	return pClosest != nullptr;
}

bool IsAlert(SPAWNINFO* pChar, SPAWNINFO* pSpawn, uint32_t id)
{
	if (pSpawn == nullptr)
		return false;

	MQSpawnSearch SearchSpawn;

	std::vector<MQSpawnSearch> alerts;
	if (CAlerts.GetAlert(id, alerts))
	{
		for (auto& search : alerts)
		{
			if (search.SpawnID > 0 && search.SpawnID != pSpawn->SpawnID)
				continue;

			// FIXME
			memcpy(&SearchSpawn, &search, sizeof(MQSpawnSearch));
			SearchSpawn.SpawnID = pSpawn->SpawnID;

			// if this spawn matches, it's true. This is an implied logical or
			if (SpawnMatchesSearch(&SearchSpawn, pChar, pSpawn))
				return true;
		}
	}

	return false;
}

// FIXME: This function is broken, and doesn't actually check against the CAlerts list.
bool CheckAlertForRecursion(MQSpawnSearch* pSearchSpawn, uint32_t id)
{
	if (gbIgnoreAlertRecursion)
		return false;

	if (!pSearchSpawn)
		return false;

	std::vector<MQSpawnSearch> ss;
	if (CAlerts.GetAlert(id, ss))
	{
		for (auto i = ss.begin(); i != ss.end(); i++)
		{
			if (pSearchSpawn->bAlert)
			{
				if (pSearchSpawn->AlertList == id)
				{
					return true;
				}

				if (CheckAlertForRecursion(pSearchSpawn, pSearchSpawn->AlertList))
				{
					return true;
				}
			}

			if (pSearchSpawn->bNoAlert)
			{
				if (pSearchSpawn->NoAlertList == id)
				{
					return true;
				}

				if (CheckAlertForRecursion(pSearchSpawn, pSearchSpawn->NoAlertList))
				{
					return true;
				}
			}

			if (pSearchSpawn->bNearAlert)
			{
				if (pSearchSpawn->NearAlertList == id)
				{
					return true;
				}

				if (CheckAlertForRecursion(pSearchSpawn, pSearchSpawn->NearAlertList))
				{
					return true;
				}
			}

			if (pSearchSpawn->bNotNearAlert)
			{
				if (pSearchSpawn->NotNearAlertList == id)
				{
					return true;
				}

				if (CheckAlertForRecursion(pSearchSpawn, pSearchSpawn->NotNearAlertList))
				{
					return true;
				}
			}
		}
	}

	return false;
}

// ***************************************************************************
// Function:    CleanupName
// Description: Cleans up NPC names
//              an_iksar_marauder23 = iksar marauder, an
// ***************************************************************************
char* CleanupName(char* szName, size_t BufferSize, bool Article, bool ForWhoList)
{
	char szTemp[MAX_STRING] = { 0 };
	int j = 0;

	for (size_t i = 0; i < strlen(szName); i++)
	{
		switch (szName[i])
		{
		case '_':
			szTemp[j++] = ' ';
			break;
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
			break;
		case '#':
			if (!ForWhoList)
				break;
		default:
			szTemp[j++] = szName[i];
		}
	}

	strcpy_s(szName, BufferSize, szTemp);

	if (!Article) return szName;

	if (!_strnicmp(szName, "a ", 2))
	{
		sprintf_s(szTemp, "%s, a", szName + 2);
		strcpy_s(szName, BufferSize, szTemp);
	}
	else if (!_strnicmp(szName, "an ", 3))
	{
		sprintf_s(szTemp, "%s, an", szName + 3);
		strcpy_s(szName, BufferSize, szTemp);
	}
	else if (!_strnicmp(szName, "the ", 4))
	{
		sprintf_s(szTemp, "%s, the", szName + 4);
		strcpy_s(szName, BufferSize, szTemp);
	}

	return szName;
}

// ***************************************************************************
// Function:    SuperWhoDisplay
// Description: Displays our SuperWho / SuperWhoTarget
// ***************************************************************************
void SuperWhoDisplay(SPAWNINFO* pSpawn, DWORD Color)
{
	if (pSpawn == nullptr)
		return;

	char szName[MAX_STRING] = { 0 };
	char szMsg[MAX_STRING] = { 0 };
	char szMsgL[MAX_STRING] = { 0 };
	char szTemp[MAX_STRING] = { 0 };

	strcpy_s(szName, pSpawn->DisplayedName);

	if (pSpawn->Type == SPAWN_PLAYER)
	{
		if (gFilterSWho.Lastname && strlen(pSpawn->Lastname) > 0)
		{
			strcat_s(szName, " ");
			strcat_s(szName, pSpawn->Lastname);
		}

		if (gFilterSWho.Guild && pSpawn->GuildID != -1 && pSpawn->GuildID != 0)
		{
			strcat_s(szName, " <");
			const char* szGuild = GetGuildByID(pSpawn->GuildID);
			strcat_s(szName, szGuild ? szGuild : "Unknown Guild");
			strcat_s(szName, ">");
		}
	}
	else
	{
		if (gFilterSWho.Lastname && strlen(pSpawn->Lastname) > 0)
		{
			strcat_s(szName, " (");
			strcat_s(szName, pSpawn->Lastname);
			strcat_s(szName, ")");
		}
	}

	char GM[MAX_STRING] = { 0 };

	if (gFilterSWho.GM && pSpawn->GM)
	{
		if (pSpawn->Level >= 50)
		{
			strcpy_s(GM, "\ay*GM*\ax");
		}
		else if (pSpawn->Level == 20)
		{
			strcpy_s(GM, "\a-y*Guide Applicant*\ax");
		}
		else
		{
			strcpy_s(GM, "\a-y*Guide*\ax");
		}
	}

	szMsg[0] = '\a';
	szMsg[2] = 0;

	if (Color || gFilterSWho.ConColor)
	{
		switch (ConColor(pSpawn))
		{
		case CONCOLOR_WHITE:
			szMsg[1] = 'w';
			break;
		case CONCOLOR_YELLOW:
			szMsg[1] = 'y';
			break;
		case CONCOLOR_RED:
			szMsg[1] = 'r';
			break;
		case CONCOLOR_BLUE:
			szMsg[1] = 'u';
			break;
		case CONCOLOR_LIGHTBLUE:
			szMsg[1] = 't';
			break;
		case CONCOLOR_GREEN:
			szMsg[1] = 'g';
			break;
		case CONCOLOR_GREY:
			szMsg[1] = '-';
			szMsg[2] = 'w';
			break;
		default:
			szMsg[1] = 'm';
			break;
		}
	}
	else
	{
		szMsg[1] = 'w';
	}

	if (gFilterSWho.GM)
		strcat_s(szMsg, GM);

	if (gFilterSWho.Level || gFilterSWho.Race || gFilterSWho.Body || gFilterSWho.Class)
	{
		strcat_s(szMsg, "\a-u[\ax");

		if (gFilterSWho.Level)
		{
			_itoa_s(pSpawn->Level, szTemp, 10);
			strcat_s(szMsg, szTemp);
			strcat_s(szMsg, " ");
		}

		if (gFilterSWho.Race)
		{
			strcat_s(szMsg, pEverQuest->GetRaceDesc(pSpawn->GetRace()));
			strcat_s(szMsg, " ");
		}

		if (gFilterSWho.Body)
		{
			strcat_s(szMsg, GetBodyTypeDesc(GetBodyType(pSpawn)));
			strcat_s(szMsg, " ");
		}

		if (gFilterSWho.Class)
		{
			strcat_s(szMsg, GetClassDesc(pSpawn->GetClass()));
			strcat_s(szMsg, " ");
		}

		szMsg[strlen(szMsg) - 1] = 0;
		strcat_s(szMsg, "\a-u]\ax");
	}

	strcat_s(szMsg, " ");
	strcat_s(szMsg, szName);

	if (pSpawn->Type == SPAWN_PLAYER)
	{
		if (gFilterSWho.Anon && pSpawn->Anon > 0)
		{
			if (pSpawn->Anon == 2)
			{
				strcat_s(szMsg, " \ag*RP*\ax");
			}
			else {
				strcat_s(szMsg, " \ag*Anon*\ax");
			}
		}

		if (gFilterSWho.LD && pSpawn->Linkdead) strcat_s(szMsg, " \ag<LD>\ax");
		if (gFilterSWho.Sneak && pSpawn->Sneak) strcat_s(szMsg, " \ag<Sneak>\ax");
		if (gFilterSWho.AFK && pSpawn->AFK) strcat_s(szMsg, " \ag<AFK>\ax");
		if (gFilterSWho.LFG && pSpawn->LFG) strcat_s(szMsg, " \ag<LFG>\ax");
		if (gFilterSWho.Trader && pSpawn->Trader) strcat_s(szMsg, " \ag<Trader>\ax");
	}
	else if (gFilterSWho.NPCTag && pSpawn->Type == SPAWN_NPC)
	{
		if (pSpawn->MasterID != 0)
		{
			strcat_s(szMsg, " <PET>");
		}
		else
		{
			strcat_s(szMsg, " <NPC>");
		}
	}

	if (gFilterSWho.Light)
	{
		const char* szLight = GetLightForSpawn(pSpawn);
		if (_stricmp(szLight, "NONE"))
		{
			strcat_s(szMsg, " (");
			strcat_s(szMsg, szLight);
			strcat_s(szMsg, ")");
		}
	}

	strcpy_s(szMsgL, szMsg);

	if (gFilterSWho.Distance)
	{
		int Angle = static_cast<int>((atan2f(pLocalPlayer->X - pSpawn->X, pLocalPlayer->Y - pSpawn->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;
		sprintf_s(szTemp, " \a-u(\ax%1.2f %s\a-u,\ax %1.2fZ\a-u)\ax", GetDistance(pLocalPlayer, pSpawn), szHeadingShort[Angle], pSpawn->Z - pLocalPlayer->Z);
		strcat_s(szMsg, szTemp);
	}

	if (gFilterSWho.SpawnID)
	{
		strcat_s(szMsg, " \a-u(\axID:");
		_itoa_s(pSpawn->SpawnID, szTemp, 10);
		strcat_s(szMsg, szTemp);
		strcat_s(szMsg, "\a-u)\ax");
	}

	if (gFilterSWho.Holding && (pSpawn->Equipment.Primary.ID || pSpawn->Equipment.Offhand.ID))
	{
		strcat_s(szMsg, " \a-u(\ax");

		if (pSpawn->Equipment.Primary.ID)
		{
			_itoa_s(pSpawn->Equipment.Primary.ID, szTemp, 10);
			strcat_s(szMsg, "Pri: ");
			strcat_s(szMsg, szTemp);
			if (pSpawn->Equipment.Offhand.ID)
				strcat_s(szMsg, " ");
		}

		if (pSpawn->Equipment.Offhand.ID)
		{
			_itoa_s(pSpawn->Equipment.Offhand.ID, szTemp, 10);
			strcat_s(szMsg, "Off: ");
			strcat_s(szMsg, szTemp);
		}

		strcat_s(szMsg, "\a-u)\ax");
	}

	switch (GetSpawnType(pSpawn))
	{
	case CHEST:
		strcat_s(szMsg, " \ar*CHEST*\ax");
		break;
	case TRAP:
		strcat_s(szMsg, " \ar*TRAP*\ax");
		break;
	case TRIGGER:
		strcat_s(szMsg, " \ar*TRIGGER*\ax");
		break;
	case TIMER:
		strcat_s(szMsg, " \ar*TIMER*\ax");
		break;
	case UNTARGETABLE:
		strcat_s(szMsg, " \ar*UNTARGETABLE*\ax");
		break;
	}

	WriteChatColor(szMsg, USERCOLOR_WHO);
}

struct SuperWhoSortPredicate
{
	SuperWhoSortPredicate(SearchSortBy sortBy, SPAWNINFO* pSeachOrigin)
		: m_sortBy(sortBy)
		, m_pOrigin(pSeachOrigin)
	{
	}

	bool operator()(SPAWNINFO* SpawnA, SPAWNINFO* SpawnB)
	{
		switch (m_sortBy)
		{
		case SearchSortBy::Level:
			return SpawnA->Level < SpawnB->Level;

		case SearchSortBy::Name:
			return _stricmp(SpawnA->DisplayedName, SpawnB->DisplayedName) < 0;

		case SearchSortBy::Race:
			return _stricmp(SpawnA->GetRaceString(), SpawnB->GetRaceString()) < 0;

		case SearchSortBy::Class:
			return _stricmp(SpawnA->GetClassString(), SpawnB->GetClassString()) < 0;

		case SearchSortBy::Distance:
			return GetDistanceSquared(m_pOrigin, SpawnA) < GetDistanceSquared(m_pOrigin, SpawnB);

		case SearchSortBy::Guild:
		{
			char szGuild1[256] = { "" };
			char szGuild2[256] = { "" };
			const char* pDest1 = GetGuildByID(SpawnA->GuildID);
			const char* pDest2 = GetGuildByID(SpawnB->GuildID);

			if (pDest1)
			{
				strcpy_s(szGuild1, pDest1);
			}

			if (pDest2)
			{
				strcpy_s(szGuild2, pDest2);
			}

			return _stricmp(szGuild1, szGuild2) < 0;
		}

		case SearchSortBy::Id:
		default:
			return SpawnA->SpawnID < SpawnB->SpawnID;
		}
	}

private:
	SearchSortBy m_sortBy;
	SPAWNINFO* m_pOrigin;
};

void SuperWhoDisplay(SPAWNINFO* pChar, MQSpawnSearch* pSearchSpawn, DWORD Color)
{
	if (!pSearchSpawn)
		return;

	std::vector<SPAWNINFO*> SpawnSet;

	SPAWNINFO* pSpawn = pSpawnList;
	SPAWNINFO* pOrigin = nullptr;

	if (pSearchSpawn->FromSpawnID)
		pOrigin = GetSpawnByID(pSearchSpawn->FromSpawnID);
	if (!pOrigin)
		pOrigin = pChar;

	while (pSpawn)
	{
		if (SpawnMatchesSearch(pSearchSpawn, pOrigin, pSpawn))
		{
			// matches search, add to our set
			SpawnSet.push_back(pSpawn);
		}

		pSpawn = pSpawn->pNext;
	}

	if (!SpawnSet.empty())
	{
		if (SpawnSet.size() > 1)
		{
			// sort our list
			std::sort(std::begin(SpawnSet), std::end(SpawnSet),
				SuperWhoSortPredicate{ pSearchSpawn->SortBy, pOrigin });
		}

		WriteChatColor("List of matching spawns", USERCOLOR_WHO);
		WriteChatColor("--------------------------------", USERCOLOR_WHO);

		for (SPAWNINFO* spawn : SpawnSet)
		{
			SuperWhoDisplay(spawn, Color);
		}

		char* pszSpawnType = nullptr;
		switch (pSearchSpawn->SpawnType)
		{
		case NONE:
		default:
			pszSpawnType = "any";
			break;
		case PC:
			pszSpawnType = "pc";
			break;
		case MOUNT:
			pszSpawnType = "mount";
			break;
		case PET:
			pszSpawnType = "pet";
			break;
		case PCPET:
			pszSpawnType = "pcpet";
			break;
		case NPCPET:
			pszSpawnType = "npcpet";
			break;
		case XTARHATER:
			pszSpawnType = "xtarhater";
			break;
		case NPC:
			pszSpawnType = "npc";
			break;
		case CORPSE:
			pszSpawnType = "corpse";
			break;
		case TRIGGER:
			pszSpawnType = "trigger";
			break;
		case TRAP:
			pszSpawnType = "trap";
			break;
		case CHEST:
			pszSpawnType = "chest";
			break;
		case TIMER:
			pszSpawnType = "timer";
			break;
		case UNTARGETABLE:
			pszSpawnType = "untargetable";
			break;
		case MERCENARY:
			pszSpawnType = "mercenary";
			break;
		case FLYER:
			pszSpawnType = "flyer";
			break;
		}

		if (pLocalPC)
		{
			size_t count = SpawnSet.size();

			WriteChatf("There %s \ag%d\ax %s%s in %s.",
				(count == 1) ? "is" : "are", count, pszSpawnType, (count == 1) ? "" : "s", GetFullZone(pLocalPC->zoneId));
		}
	}
	else
	{
		WriteChatColor("List of matching spawns", USERCOLOR_WHO);
		WriteChatColor("--------------------------------", USERCOLOR_WHO);

		char szMsg[MAX_STRING] = { 0 };
		WriteChatColorf("%s was not found.", USERCOLOR_WHO, FormatSearchSpawn(szMsg, sizeof(szMsg), pSearchSpawn));
	}
}

float StateHeightMultiplier(DWORD StandState)
{
	switch (StandState) {
	case STANDSTATE_BIND:
	case STANDSTATE_DUCK:
		return 0.5f;
	case STANDSTATE_SIT:
		return 0.3f;
	case STANDSTATE_FEIGN:
	case STANDSTATE_DEAD:
		return 0.1f;
	case STANDSTATE_STAND:
	default:
		return 0.9f;
	}
}

int FindSpellListByName(const char* szName)
{
	for (int Index = 0; Index < NUM_SPELL_SETS; Index++)
	{
		if (!_stricmp(pSpellSets[Index].Name, szName))
			return Index;
	}

	return -1;
}

void WriteFilterNames()
{
	char szBuffer[MAX_STRING] = { 0 };
	int filternumber = 1;

	MQFilter* pFilter = gpFilters;
	WritePrivateProfileSection("Filter Names", szBuffer, mq::internal_paths::MQini);

	while (pFilter)
	{
		if (pFilter->pEnabled == &gFilterCustom)
		{
			sprintf_s(szBuffer, "Filter%d", filternumber++);
			WritePrivateProfileString("Filter Names", szBuffer, pFilter->FilterText, mq::internal_paths::MQini);
		}
		pFilter = pFilter->pNext;
	}
}

#define IS_SET(flag, bit)   ((flag) & (bit))

const char* GetLDoNTheme(int LDTheme)
{
	if (LDTheme == 31) return "All";
	if (IS_SET(LDTheme, LDON_DG)) return "Deepest Guk";
	if (IS_SET(LDTheme, LDON_MIR)) return "Miragul's";
	if (IS_SET(LDTheme, LDON_MIS)) return "Mistmoore";
	if (IS_SET(LDTheme, LDON_RUJ)) return "Rujarkian";
	if (IS_SET(LDTheme, LDON_TAK)) return "Takish";
	return "Unknown";
}

uint32_t GetItemTimer(ItemClient* pItem)
{
	uint32_t Timer = pLocalPC->GetItemRecastTimer(pItem, ItemSpellType_Clicky);

	if (Timer < GetFastTime())
		return 0;

	return Timer - GetFastTime();
}

ItemClient* GetItemContentsByName(const char* ItemName)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return nullptr;

	for (const ItemPtr& pItem : pProfile->InventoryContainer)
	{
		if (pItem)
		{
			if (!_stricmp(ItemName, pItem->GetItemDefinition()->Name))
			{
				return pItem.get();
			}

			if (pItem->GetItemDefinition()->Type == ITEMTYPE_PACK)
			{
				for (const ItemPtr& pItem2 : pItem->GetHeldItems())
				{
					if (pItem2)
					{
						if (!_stricmp(ItemName, pItem2->GetItemDefinition()->Name))
						{
							return pItem2.get();
						}
					}
				}
			}
		}
	}

	return nullptr;
}

CXWnd* GetParentWnd(CXWnd* pWnd)
{
	while (pWnd)
	{
		if (!pWnd->GetParentWindow())
			return pWnd;

		pWnd = pWnd->GetParentWindow();
	}

	return nullptr;
}

bool LoH_HT_Ready()
{
	if (!pLocalPlayer) return false;
	unsigned int i = pLocalPlayer->SpellGemETA[InnateETA];
	unsigned int j = i - pDisplay->TimeStamp;
	return i < j;
}

int GetSkillIDFromName(const char* name)
{
	for (int i = 0; i < NUM_SKILLS; i++)
	{
		if (EQ_Skill* pSkill = pSkillMgr->pSkill[i])
		{
			if (!_stricmp(name, pStringTable->getString(pSkill->nName)))
				return i;
		}
	}

	return 0;
}

bool InHoverState()
{
	return pLocalPC && pLocalPC->Stunned == 3;
}

int GetGameState()
{
	return pEverQuest ? pEverQuest->GameState : -1;
}

int GetWorldState()
{
	return pEverQuest ? pEverQuest->WorldState : -1;
}

// ***************************************************************************
// Function:    LargerEffectTest
// Description: Return boolean true if the spell effect is to be ignored
//              for stacking purposes
// ***************************************************************************
bool LargerEffectTest(SPELL* aSpell, SPELL* bSpell, int i, bool bTriggeredEffectCheck)
{
	int aAttrib = GetSpellNumEffects(aSpell) > i ? GetSpellAttrib(aSpell, i) : SPA_NOSPELL;
	int bAttrib = GetSpellNumEffects(bSpell) > i ? GetSpellAttrib(bSpell, i) : SPA_NOSPELL;
	if (aAttrib == bAttrib) // verify they are the same, we can do fewer checks this way
		return (abs(GetSpellBase(aSpell, i)) >= abs(GetSpellBase(bSpell, i)) || (bTriggeredEffectCheck && (aSpell->SpellGroup == bSpell->SpellGroup)));
	return false;
}

// ***************************************************************************
// Function:    TriggeringEffectSpell
// Description: Return boolean true if the spell effect is to be ignored
//              for stacking purposes
// ***************************************************************************
bool TriggeringEffectSpell(SPELL* aSpell, int i)
{
	int aAttrib = GetSpellNumEffects(aSpell) > i ? GetSpellAttrib(aSpell, i) : 254;
	return (aAttrib == SPA_MELEE_PROC      // Add Proc
		|| aAttrib == SPA_TRIGGER_SPELL    // Trigger Spell
		|| aAttrib == SPA_PROC_EFFECT_2);  // Contact_Ability_2
}

// ***************************************************************************
// Function:    SpellEffectTest
// Description: Return boolean true if the spell effect is to be ignored
//              for stacking purposes
// ***************************************************************************
bool SpellEffectTest(SPELL* aSpell, SPELL* bSpell, int i, bool bIgnoreTriggeringEffects, bool bTriggeredEffectCheck = false)
{
	int aAttrib = GetSpellNumEffects(aSpell) > i ? GetSpellAttrib(aSpell, i) : 254;
	int bAttrib = GetSpellNumEffects(bSpell) > i ? GetSpellAttrib(bSpell, i) : 254;
	return ((aAttrib == SPA_LEVITATION || bAttrib == SPA_LEVITATION)
		|| (aAttrib == SPA_FOCUS_LEVEL_MAX || bAttrib == SPA_FOCUS_LEVEL_MAX)           // Limit: Max Level
		|| (aAttrib == SPA_FOCUS_RESIST_TYPE || bAttrib == SPA_FOCUS_RESIST_TYPE)       // Limit: Resist
		|| (aAttrib == SPA_FOCUS_TARGET_TYPE || bAttrib == SPA_FOCUS_TARGET_TYPE)       // Limit: Target
		|| (aAttrib == SPA_FOCUS_WHICH_SPA || bAttrib == SPA_FOCUS_WHICH_SPA)           // Limit: Effect
		|| (aAttrib == SPA_FOCUS_BENEFICIAL || bAttrib == SPA_FOCUS_BENEFICIAL)         // Limit: SpellType
		|| (aAttrib == SPA_FOCUS_WHICH_SPELL || bAttrib == SPA_FOCUS_WHICH_SPELL)       // Limit: Spell
		|| (aAttrib == SPA_FOCUS_DURATION_MIN || bAttrib == SPA_FOCUS_DURATION_MIN)     // Limit: Min Duraction
		|| (aAttrib == SPA_FOCUS_INSTANT_ONLY || bAttrib == SPA_FOCUS_INSTANT_ONLY)     // Limit: Instant
		|| (aAttrib == SPA_FOCUS_LEVEL_MIN || bAttrib == SPA_FOCUS_LEVEL_MIN)           // Limit: Min Level
		|| (aAttrib == SPA_FOCUS_CASTTIME_MIN || bAttrib == SPA_FOCUS_CASTTIME_MIN)     // Limit: Min Cast Time
		|| (aAttrib == SPA_FOCUS_CASTTIME_MAX || bAttrib == SPA_FOCUS_CASTTIME_MAX)	    // Limit: Max Cast Time
		|| (aAttrib == SPA_NOSPELL || bAttrib == SPA_NOSPELL)                           // Placeholder
		|| (aAttrib == SPA_FOCUS_COMBAT_SKILL || bAttrib == SPA_FOCUS_COMBAT_SKILL)     // Limit: Combat Skills not Allowed
		|| (aAttrib == SPA_FOCUS_CASTING_PROC || bAttrib == SPA_FOCUS_CASTING_PROC)     // Trigger DoT on cast
		|| (aAttrib == SPA_CHANCE_SPELL || bAttrib == SPA_CHANCE_SPELL)                 // Trigger DD on cast
		|| (aAttrib == SPA_FOCUS_MANA_MIN || bAttrib == SPA_FOCUS_MANA_MIN)             // Limit: Min Mana
//		|| (aAttrib == SPA_TRIGGER_SPELL || bAttrib == SPA_TRIGGER_SPELL)               // Add Effect: xxx
		|| (aAttrib == SPA_FOCUS_WHICH_GROUP || bAttrib == SPA_FOCUS_WHICH_GROUP)       // Limit: SpellGroup
		|| (aAttrib == SPA_FOCUS_MANA_MAX || bAttrib == SPA_FOCUS_MANA_MAX)             // Limit: Max Mana
		|| (aAttrib == SPA_FOCUS_SPELL_CLASS || bAttrib == SPA_FOCUS_SPELL_CLASS)       // Limit: SpellClass
		|| (aAttrib == SPA_FOCUS_SPELL_SUBCLASS || bAttrib == SPA_FOCUS_SPELL_SUBCLASS)	// Limit: SpellSubclass
		|| (aAttrib == SPA_FOCUS_LIMIT_CLASS || bAttrib == SPA_FOCUS_LIMIT_CLASS)       // Limit: PlayerClass
		|| (aAttrib == SPA_FOCUS_LIMIT_RACE || bAttrib == SPA_FOCUS_LIMIT_RACE)         // Limit: Race
		|| (aAttrib == SPA_FOCUS_LIMIT_SKILL || bAttrib == SPA_FOCUS_LIMIT_SKILL)       // Limit: CastingSkill
		|| (aAttrib == SPA_FOCUS_LIMIT_USE_MIN || bAttrib == SPA_FOCUS_LIMIT_USE_MIN)   // Limit: Use Min
		|| (aAttrib == SPA_FOCUS_LIMIT_USE_TYPE || bAttrib == SPA_FOCUS_LIMIT_USE_TYPE) // Limit: Use Type
		|| (aAttrib == SPA_PROC_SKILL_MODIFIER || bAttrib == SPA_PROC_SKILL_MODIFIER)   // Skill_Proc_Modifier
		|| (LargerEffectTest(aSpell, bSpell, i, bTriggeredEffectCheck))	                // Ignore if the new effect is greater than the old effect
		|| (bIgnoreTriggeringEffects && (TriggeringEffectSpell(aSpell, i) || TriggeringEffectSpell(bSpell, i))) // Ignore triggering effects validation
		|| ((aSpell->SpellType == ItemSpellType_Proc || aSpell->SpellType == ItemSpellType_Worn) && (bSpell->SpellType == ItemSpellType_Proc || bSpell->SpellType == ItemSpellType_Worn) && !(aSpell->DurationWindow == bSpell->DurationWindow)));
}

template <typename ...Args>
inline void StackingDebugLog(const char* string, Args&& ...args)
{
	if (gStackingDebug != STACKINGDEBUG_OFF)
	{
		DebugSpewAlwaysFile(string, args...);

		if (gStackingDebug == STACKINGDEBUG_OUTPUT)
		{
			WriteChatColorf(string, USERCOLOR_CHAT_CHANNEL, args...);
		}
	}
}

// ***************************************************************************
// Function:    BuffStackTest
// Description: Return boolean true if the two spells will stack
// Usage:       Used by ${Spell[xxx].Stacks}, ${Spell[xxx].StacksPet},
//                ${Spell[xxx].WillStack[yyy]}, ${Spell[xxx].StacksWith[yyy]}
// Author:      Pinkfloydx33
// ***************************************************************************
bool BuffStackTest(SPELL* aSpell, SPELL* bSpell, bool bIgnoreTriggeringEffects, bool bTriggeredEffectCheck)
{
	if (!pLocalPlayer)
		return true;
	if (GetGameState() != GAMESTATE_INGAME)
		return true;
	if (gZoning)
		return true;
	if (!aSpell || !bSpell)
		return false;
	if (aSpell->ID == bSpell->ID)
		return true;

	StackingDebugLog("aSpell->Name=%s(%d) bSpell->Name=%s(%d)",
		aSpell->Name, aSpell->ID, bSpell->Name, bSpell->ID);

	// We need to loop over the largest of the two, this may seem silly but one could have stacking command blocks
	// which we will always need to check.
	int effects = std::max(GetSpellNumEffects(aSpell), GetSpellNumEffects(bSpell));
	for (int i = 0; i < effects; i++)
	{
		// Compare 1st Buff to 2nd. If Attrib[i]==254 its a place holder. If it is 10 it
		// can be 1 of 3 things: PH(Base=0), CHA(Base>0), Lure(Base=-6). If it is Lure or
		// Placeholder, exclude it so slots don't match up. Now Check to see if the slots
		// have equal attribute values. If the do, they don't stack.

		int aAttrib = SPA_NOSPELL, bAttrib = SPA_NOSPELL; // Default to placeholder ...
		int64_t aBase = 0, bBase = 0, aBase2 = 0, bBase2 = 0;

		if (GetSpellNumEffects(aSpell) > i)
		{
			aAttrib = GetSpellAttrib(aSpell, i);
			aBase = GetSpellBase(aSpell, i);
			aBase2 = GetSpellBase2(aSpell, i);
		}

		if (GetSpellNumEffects(bSpell) > i)
		{
			bAttrib = GetSpellAttrib(bSpell, i);
			bBase = GetSpellBase(bSpell, i);
			bBase2 = GetSpellBase2(bSpell, i);
		}

		StackingDebugLog("Slot %d: bSpell->Attrib=%d, bSpell->Base=%d, bSpell->TargetType=%d, aSpell->Attrib=%d, aSpell->Base=%d, aSpell->TargetType=%d",
			i, bAttrib, bBase, bSpell->TargetType, aAttrib, aBase, aSpell->TargetType);

		bool bTriggerA = TriggeringEffectSpell(aSpell, i);
		bool bTriggerB = TriggeringEffectSpell(bSpell, i);

		if (bTriggerA || bTriggerB)
		{
			SPELL* pRetSpellA = GetSpellByID(bTriggerA ? (aAttrib == SPA_TRIGGER_SPELL ? (int)aBase2 : (int)aBase) : aSpell->ID);
			SPELL* pRetSpellB = GetSpellByID(bTriggerB ? (bAttrib == SPA_TRIGGER_SPELL ? (int)bBase2 : (int)bBase) : bSpell->ID);

			if (!pRetSpellA || !pRetSpellB)
			{
				StackingDebugLog("BuffStackTest ERROR: aSpell[%d]:%s%s, bSpell[%d]:%s%s",
					aSpell->ID, aSpell->Name, pRetSpellA ? "" : "is null", bSpell->ID, bSpell->Name, pRetSpellB ? "" : "is null");
			}

			if (!((bTriggerA && (aSpell->ID == pRetSpellA->ID)) || (bTriggerB && (bSpell->ID == pRetSpellB->ID))))
			{
				if (!BuffStackTest(pRetSpellA, pRetSpellB, bIgnoreTriggeringEffects, true))
				{
					StackingDebugLog("returning false #1");
					return false;
				}
			}
		}

		if (bAttrib == aAttrib && !SpellEffectTest(aSpell, bSpell, i, bIgnoreTriggeringEffects, bTriggeredEffectCheck))
		{
			StackingDebugLog("Inside IF");

			// TODO: Add constant for target type
			// SPA_CHA was used as a blocker if it had a base of 0 in the old days.
			if (!((bAttrib == SPA_CHA && (bBase == -6 || bBase == 0))
				|| (aAttrib == SPA_CHA && (aBase == -6 || aBase == 0))
				|| (bAttrib == SPA_INSTANT_HP && bBase > 0 && bSpell->TargetType == 6) // targetType 6 = self
				|| (aAttrib == SPA_INSTANT_HP && aBase > 0 && aSpell->TargetType == 6)
				|| (bAttrib == SPA_HP && bBase < 0)
				|| (aAttrib == SPA_HP && aBase < 0)
				|| (bAttrib == SPA_STACKING_BLOCK || bAttrib == SPA_STRIP_VIRTUAL_SLOT)
				|| (aAttrib == SPA_STACKING_BLOCK || aAttrib == SPA_STRIP_VIRTUAL_SLOT)))
			{
				StackingDebugLog("returning false #2");
				return false;
			}
		}

		// Check to see if second buffs blocks first buff:
		// 148: Stacking: Block new spell if slot %d is effect
		// 149: Stacking: Overwrite existing spell if slot %d is effect
		if (bAttrib == SPA_STACKING_BLOCK || bAttrib == SPA_STRIP_VIRTUAL_SLOT)
		{
			// in this branch we know bSpell has enough slots
			int tmpSlot = (bAttrib == SPA_STACKING_BLOCK ? (int)(bBase2 - 1) : (int)(GetSpellCalc(bSpell, i) - 200 - 1));
			int tmpAttrib = (int)bBase;

			if (GetSpellNumEffects(aSpell) > tmpSlot)
			{
				StackingDebugLog("aSpell->Attrib[%d]=%d, aSpell->Base[%d]=%lld, tmpAttrib=%d, tmpVal=%lld",
					tmpSlot, GetSpellAttrib(aSpell, tmpSlot), tmpSlot, GetSpellBase(aSpell, tmpSlot), tmpAttrib, abs(GetSpellMax(bSpell, i)));

				// verify aSpell has that slot
				if (GetSpellMax(bSpell, i) > 0)
				{
					int64_t tmpVal = abs(GetSpellMax(bSpell, i));
					if (GetSpellAttrib(aSpell, tmpSlot) == tmpAttrib && GetSpellBase(aSpell, tmpSlot) < tmpVal)
					{
						StackingDebugLog("returning false #3");
						return false;
					}
				}
				else if (GetSpellAttrib(aSpell, tmpSlot) == tmpAttrib)
				{
					StackingDebugLog("returning false #4");
					return false;
				}
			}
		}
	}

	StackingDebugLog("returning true");
	return true;
}

/**
 * @fn WillStackWith
 *
 * @brief tests if testSpell will stack with existingSpell
 *
 * Takes two spells in order to test if they will stack. Any null checking should be
 * done before this function is called, assumes all values are non-null.
 *
 * @param testSpell The spell that would hypothetically be cast (non-null)
 * @param existingSpell The spell that would hypothetically already exist (non-null)
 *
 * @return bool A boolean that is true if the spell would hypothetically land if cast
 **/
bool WillStackWith(const EQ_Spell* testSpell, const EQ_Spell* existingSpell)
{
	// if there is no local player, then the hypothetical situation fails anyway
	if (!pLocalPlayer || !pLocalPC)
		return false;

	EQ_Affect buff;
	buff.Level = pLocalPlayer->Level;
	buff.CasterGuid = pLocalPC->Guid;

	buff.PopulateFromSpell(existingSpell);

	int SlotIndex = -1;
	EQ_Affect* ret = pLocalPC->FindAffectSlot(testSpell->ID, pLocalPlayer, &SlotIndex, true, pLocalPlayer->Level, &buff, 1);

	return ret && SlotIndex != -1;
}

bool IsSpellTooPowerful(PlayerClient* caster, PlayerClient* target, EQ_Spell* spell)
{
	if (!caster || !target || !spell)
		return true;

	if (caster->Type > 0 && !caster->Mercenary)
		return false;

	if (caster == target)
		return false;

	if (spell->TargetType == TargetType_Self || spell->SpellType == SpellType_Detrimental || spell->DurationType == 0)
		return false;

	uint8_t spellLevel = spell->GetSpellLevelNeeded(caster->GetClass());
	if (spellLevel == 0 || spellLevel > MAX_PC_LEVEL)
		return false;

	uint8_t targetLevel = target->GetLevel();
	if (target->Type == 1 && target->MasterID != 0)
	{
		auto master = GetSpawnByID(target->MasterID);
		if (master)
			targetLevel = master->GetLevel();
	}

	if (spellLevel > 65 && targetLevel < 61)
		return true;

	if (spellLevel > 50 && targetLevel < floor(spellLevel / 2) + 15)
		return true;

	return false;
}

float GetMeleeRange(PlayerClient* pSpawn1, PlayerClient* pSpawn2)
{
	if (pSpawn1 && pSpawn2)
	{
		float f = pSpawn1->GetMeleeRangeVar1 * pSpawn1->MeleeRadius;
		float g = pSpawn2->GetMeleeRangeVar1 * pSpawn2->MeleeRadius;

		float h = abs(pSpawn1->AvatarHeight - pSpawn2->AvatarHeight);

		f = (f + g) * 0.75f;

		if (f < 14.0f)
			f = 14.0f;

		g = f + 2 + h;

		if (g > 75.0f)
			return 75.0f;
		else
			return g;
	}
	return 14.0f;
}

inline bool IsValidSpellSlot(int nGem)
{
	return nGem >= 0 && nGem < 16;
}

// testing new cooldown code... -eqmule work in progress
uint32_t GetSpellGemTimer2(int nGem)
{
	bool bValidSlot = IsValidSpellSlot(nGem);

	if (bValidSlot)
	{
		int memspell = GetMemorizedSpell(nGem);
		if (SPELL* pSpell = GetSpellByID(memspell))
		{
			int ReuseTimerIndex = pSpell->ReuseTimerIndex;
			unsigned int linkedtimer = pLocalPC->GetLinkedSpellReuseTimer(ReuseTimerIndex);

			__time32_t RecastTime = ReuseTimerIndex > 0 && ReuseTimerIndex < 25 ? linkedtimer : 0;
			unsigned int RecastDuration = 0;
			unsigned int LinkedDuration = 0;
			unsigned int gemeta = pLocalPlayer->SpellGemETA[nGem];
			DWORD now = pDisplay->TimeStamp;
			if (gemeta > now)
			{
				RecastDuration = gemeta - now;
			}
			__time32_t fasttime = (__time32_t)GetFastTime();
			if (RecastTime > fasttime)
			{
				LinkedDuration = (RecastTime - fasttime) * 1000;
			}
			CSpellGemWnd* gem = pCastSpellWnd->SpellSlots[nGem];
			unsigned int Timer = std::max(RecastDuration, LinkedDuration);
			unsigned int timeremaining = gem->GetCoolDownTimeRemaining();
			unsigned int totaldur = gem->GetCoolDownTotalDuration();

			bool TimerChanged = !(abs(long(Timer - timeremaining)) < 1000);
			if (Timer > 0 && (totaldur == 0 || TimerChanged))
			{
				int TotalDuration = Timer;
				if (RecastDuration > LinkedDuration)
				{
					ItemPtr pFocusItem;
					int ReuseMod = pLocalPC->GetFocusReuseMod(pSpell, pFocusItem);
					TotalDuration = pSpell->RecastTime - ReuseMod;
				}
				//do stuff
				return TotalDuration;
			}
			return Timer;
		}
	}

	return 0;
}

// todo: check manually
uint32_t GetSpellGemTimer(int nGem)
{
	return GetSpellGemTimer2(nGem);
}

uint32_t GetSpellBuffTimer(int SpellID)
{
	if (auto buffInfo = pBuffWnd->GetBuffInfoBySpellID(SpellID))
	{
		return buffInfo.GetBuffTimer();
	}

	if (auto buffInfo = pSongWnd->GetBuffInfoBySpellID(SpellID))
	{
		return buffInfo.GetBuffTimer();
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Functions that were built into commands and people used DoCommand to execute                  //

void AttackRanged(PlayerClient* pRangedTarget)
{
	if (pRangedTarget && pEverQuestInfo->PrimaryAttackReady)
	{
		pLocalPlayer->DoAttack(InvSlot_Range, 0, pRangedTarget);
		pEverQuestInfo->PrimaryAttackReady = 0;
	}
}

void UseAbility(const char* sAbility)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return;

	if (!cmdDoAbility)
		return;

	char szBuffer[MAX_STRING] = { 0 };
	strcpy_s(szBuffer, sAbility);

	if (GetIntFromString(szBuffer, 0))
	{
		cmdDoAbility(pLocalPlayer, szBuffer);
		return;
	}

	// check combat abilities (7-10)
	for (int i = 0; i < (int)lengthof(pEverQuestInfo->combatSkill); ++i)
	{
		if (pEverQuestInfo->combatSkill[i] == -1)
			continue;

		const char* skillName = szSkills[pEverQuestInfo->combatSkill[i]];
		if (!_strnicmp(szBuffer, skillName, strlen(skillName)))
		{
			_itoa_s(i + 7, szBuffer, 10);
			cmdDoAbility(pLocalPlayer, szBuffer);
			return;
		}
	}

	// check abilities (1-6)
	for (int i = 0; i < (int)lengthof(pEverQuestInfo->abilities); ++i)
	{
		if (pEverQuestInfo->abilities[i] == -1)
			continue;

		const char* skillName = szSkills[pEverQuestInfo->abilities[i]];
		if (!_strnicmp(szBuffer, skillName, strlen(skillName)))
		{
			_itoa_s(i + 1, szBuffer, 10);
			cmdDoAbility(pLocalPlayer, szBuffer);
			return;
		}
	}

	for (int Index = 0; Index < NUM_COMBAT_ABILITIES; ++Index)
	{
		if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(Index))
		{
			EQ_Spell* pCA = GetSpellByID(pProfile->CombatAbilities[Index]);
			if (pCA && !_stricmp(pCA->Name, szBuffer))
			{
				// We got the cookie, let's try and do it
				pLocalPC->DoCombatAbility(pCA->ID);
				return;
			}
		}
	}

	WriteChatf("You do not seem to have that ability available");
}

// Function to check if the account has a given expansion enabled.
// Pass expansion macros from EQData.h to it -- e.g. HasExpansion(EXPANSION_RoF)
bool HasExpansion(int64_t nExpansion)
{
#if !IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TOB)
	// ExpansionFlags was expanded to 64 bits in TOB. If this client is not using TOB or later, we
	// can short circuit the check if the request exceeds the LS expansion level.
	if (nExpansion > EXPANSION_LS)
		return false;
#endif

	using FlagsType = std::make_unsigned_t<decltype(pLocalPC->ExpansionFlags)>;

	return pLocalPC && (pLocalPC->ExpansionFlags & static_cast<FlagsType>(nExpansion)) != 0;
}

int GetAvailableBagSlots()
{
	return GetHighestAvailableBagSlot() - InvSlot_Bag1 + 1;
}

int GetHighestAvailableBagSlot()
{
	// If no char info, return smallest number available.
	if (!pLocalPC)
		return InvSlot_Bag8;

	int highestInvSlot = InvSlot_LastBonusBagSlot;

	// GM accounts do not hide inventory slots based on expansion
	// This is (most likely) only valid for Emu
	if (pLocalPC->bGM)
		return highestInvSlot;

	// If no HoT, subtract two slots.
	if (!HasExpansion(EXPANSION_HoT))
		highestInvSlot -= 2;

#if HAS_MERCHANTS_PERK
	// If no merchant perk, subtract two more bag slots.
	if (!pLocalPC->ConsumableFeatures.CanConsumeFeature(EQFeature_MerchantPerk))
		highestInvSlot -= 2;
#endif

	return highestInvSlot;
}

int GetAvailableBankSlots()
{
	return HasExpansion(EXPANSION_PoR) ? 24 : 16;
}

int GetAvailableSharedBankSlots()
{
	return HasExpansion(EXPANSION_TBL) ? 6 : HasExpansion(EXPANSION_CotF) ? 4 : 2;
}

ItemContainer* GetItemContainerByType(ItemContainerInstance type)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return nullptr;

	switch (type)
	{
	case eItemContainerPossessions:
		return &pProfile->InventoryContainer;
	case eItemContainerBank:
		return &pLocalPC->BankItems;
	case eItemContainerSharedBank:
		return &pLocalPC->SharedBankItems;
	case eItemContainerTrade:
		return &pTradeWnd->GetTradeItems();
	case eItemContainerWorld:
		return pContainerMgr->GetWorldContainerItem() ? &pContainerMgr->GetWorldContainerItem()->GetHeldItems() : nullptr;
	case eItemContainerLimbo:
		return &pLocalPC->LimboBufferItems;
	case eItemContainerTribute:
		return &pProfile->TributeBenefitItems;
	case eItemContainerTrophyTribute:
		return &pProfile->TrophyTributeBenefitItems;
	case eItemContainerGuildTribute:
		return &pProfile->GuildTributeBenefitItems;
	case eItemContainerGuildTrophyTribute:
		return &pProfile->GuildTrophyTributeBenefitItems;
	case eItemContainerCorpse:
		return &pLootWnd->GetLootItems();
	case eItemContainerBazaar:
		return &pBazaarWnd->GetBazaarItems();
	case eItemContainerInspect:
		return &pInspectWnd->GetInspectItems();
	case eItemContainerAltStorage:
		return &pLocalPC->AltStorageItems;
	case eItemContainerArchived:
		return &pLocalPC->ArchivedDeletedItems;
	case eItemContainerMail:
		return &pLocalPC->MailItems;
#if HAS_MERCENARY_INVENTORY
	case eItemContainerMercenaryItems:
		return &pLocalPC->MercenaryItems;
#endif
#if HAS_KEYRING_WINDOW
	case eItemContainerMountKeyRingItems:
		return &pLocalPC->MountKeyRingItems;
	case eItemContainerIllusionKeyRingItems:
		return &pLocalPC->IllusionKeyRingItems;
	case eItemContainerFamiliarKeyRingItems:
		return &pLocalPC->FamiliarKeyRingItems;
	case eItemContainerHeroForgeKeyRingItems:
		return &pLocalPC->HeroForgeKeyRingItems;
#endif
#if HAS_TELEPORTATION_KEYRING
	case eItemContainerTeleportationKeyRingItems:
		return &pLocalPC->TeleportationKeyRingItems;
#endif
#if HAS_ACTIVATED_ITEM_KEYRING
	case eItemContainerActivatedKeyRingItems:
		return &pLocalPC->ActivatedKeyRingItems;
#endif
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF) // not exactly sure when this was added.
	case eItemContainerOverflow:
		return &pLocalPC->OverflowBufferItems;
#endif
#if HAS_DRAGON_HOARD
	case eItemContainerDragonHoard:
		return pDragonHoardWnd ? &pDragonHoardWnd->Items : nullptr;
#endif
#if HAS_TRADESKILL_DEPOT
	case eItemContainerTradeskillDepot:
		return pTradeskillDepotWnd ? &pTradeskillDepotWnd->Items : nullptr;
#endif

	case eItemContainerRealEstate:   // todo
	case eItemContainerKrono:        // this is a special value and doesn't actually exist as a container
	case eItemContainerOther:        // can't do lookup by "other"
	case eItemContainerMerchant:     // merchant window doesn't use item container
	case eItemContainerDeleted:      // merchant buyback doesn't use item container
	default:
		break;
	}

	return nullptr;
}

// Validates that this index points to something that makes sense.
bool IsValidGlobalIndex(const ItemGlobalIndex& globalIndex)
{
	if (!globalIndex.IsValidIndex())
		return false;

	// For this index to be valid, all depths of this index must have valid containers.
	int depth = 0;

	int curSlot = globalIndex.GetIndex().GetSlot(depth++);
	ItemBaseContainer* curContainer = GetItemContainerByGlobalIndex(globalIndex);

	while (curSlot != -1 && curContainer != nullptr)
	{
		// If the slot is out of range, its a bust.
		if (curSlot < -1 || curSlot >= curContainer->GetSize())
			return false;

		// get this item. We'll check if it is a container if there is
		// more depth to this index.
		ItemPtr pItem = curContainer->GetItem(curSlot);

		// increment to the next depth.
		curSlot = globalIndex.GetIndex().GetSlot(depth++);

		if (curSlot == -1)
		{
			// this was the last depth. The previous one was good to this point,
			// so the index is valid.
			return true;
		}

		// setup container for next iteration
		curContainer = pItem ? pItem->GetChildItemContainer() : nullptr;
	}

	// didn't reach something valid. This index is no good.
	return false;
}


ItemClient* FindItemBySlot(int InvSlot, int BagSlot, ItemContainerInstance location)
{
	return FindItemByGlobalIndex(ItemGlobalIndex(location, InvSlot, BagSlot));
}

ItemClient* FindItemByGlobalIndex(const ItemGlobalIndex& idx)
{
	ItemPtr pItem;
	ItemContainer* pContainer = GetItemContainerByType(idx.GetLocation());

	if (pContainer)
	{
		pItem = pContainer->GetItem(idx.GetIndex());
	}

	return pItem.get();
}

template <typename T>
static ItemClient* FindItem(T&& callback, bool checkKeyRings = true, int fromSlot = -1, int toSlot = -1)
{
	auto pProfile = GetPcProfile();
	if (!pProfile) return nullptr;
	if (!pLocalPC) return nullptr;

	ItemPtr foundItem;
	auto itemVisitor = [&](const ItemPtr& itemPtr, const ItemIndex& itemIndex)
	{
		if (callback(itemPtr, itemIndex))
		{
			foundItem = itemPtr;
			return true;
		}
		return false;
	};

	if (InvSlot_Cursor >= fromSlot && (InvSlot_Cursor <= toSlot || toSlot == -1))
	{
		// Prioritize checking the cursor slot first.
		pProfile->InventoryContainer.FindItem(InvSlot_Cursor, InvSlot_Cursor, -1, itemVisitor);
	}

	if (!foundItem)
	{
		pProfile->InventoryContainer.FindItem(fromSlot, toSlot, -1, itemVisitor);
	}

#if HAS_KEYRING_WINDOW
	if (!foundItem && checkKeyRings)
	{
		// Check the different keyrings
		for (
			auto keyRingType = eKeyRingTypeFirst; keyRingType <= eKeyRingTypeLast;
			keyRingType = static_cast<KeyRingType>(keyRingType + 1))
		{
			pLocalPC->GetKeyRingItems(keyRingType).FindItem(0, itemVisitor);

			if (foundItem) break;
		}
	}
#endif

	return foundItem.get();
}

ItemClient* FindItemByName(const char* pName, bool bExact)
{
	return FindItem([pName, bExact](const ItemPtr& pItem, const ItemIndex&)
		{ return ci_equals(pItem->GetName(), pName, bExact); });
}

ItemClient* FindItemByID(int ItemID)
{
	return FindItem([ItemID](const ItemPtr& pItem, const ItemIndex&)
		{ return ItemID == pItem->GetID(); });
}

template <typename T>
int CountInventoryItems(T& checkItem, int minSlot, int maxSlot)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return 0;

	return CountContainerItems(pProfile->InventoryContainer, minSlot, maxSlot, checkItem);
}

template <typename T>
int CountKeyringItems(T& checkItem)
{
#if HAS_KEYRING_WINDOW
	if (!pLocalPC) return 0;
	int count = 0;

	for (auto keyRingType = eKeyRingTypeFirst;
		keyRingType <= eKeyRingTypeLast;
		keyRingType = static_cast<KeyRingType>(keyRingType + 1))
	{
		count += CountContainerItems(pLocalPC->GetKeyRingItems(keyRingType), -1, -1, checkItem);
	}

	return count;
#else
	UNUSED(checkItem);

	return 0;
#endif
}

template <typename T>
int CountItems(T&& checkItem)
{
	return CountInventoryItems(checkItem, -1, -1) + CountKeyringItems(checkItem);
}

int FindInventoryItemCountByName(const char* pName, StringMatchType matchType, int slotBegin, int slotEnd)
{
	return CountInventoryItems(
		[pName, matchType](const ItemPtr& pItem) { return StringCompare(pItem->GetName(), pName, matchType); },
		slotBegin, slotEnd);
}

ItemClient* FindInventoryItemByName(const char* pName, StringMatchType matchType, int slotBegin, int slotEnd)
{
	return FindItem([pName, matchType](const ItemPtr& pItem, const ItemIndex&)
		{ return StringCompare(pItem->GetName(), pName, matchType); }, false, slotBegin, slotEnd);
}

int FindInventoryItemCountByID(int ItemID, int slotBegin, int slotEnd)
{
	return CountInventoryItems(
		[ItemID](const ItemPtr& pItem) { return pItem->GetID() == ItemID; },
		slotBegin, slotEnd);
}

int FindItemCountByName(const char* pName)
{
	return CountItems([pName](const ItemPtr& pItem)
		{ return MaybeExactCompare(pItem->GetName(), pName); });
}

int FindItemCountByID(int ItemID)
{
	return CountItems([ItemID](const ItemPtr& pItem)
		{ return pItem->GetID() == ItemID; });
}

template <typename T>
static ItemClient* FindBankItem(T&& checkItem)
{
	if (!pLocalPC) return nullptr;

	// Check bank slots
	ItemIndex bankIndex = pLocalPC->BankItems.FindItem(checkItem);
	if (bankIndex.IsValid())
	{
		return pLocalPC->BankItems.GetItem(bankIndex).get();
	}

	// Check shared bank slots
	ItemIndex sharedBankIndex = pLocalPC->SharedBankItems.FindItem(checkItem);
	if (sharedBankIndex.IsValid())
	{
		return pLocalPC->SharedBankItems.GetItem(sharedBankIndex).get();
	}

	return nullptr;
}

ItemClient* FindBankItemByName(const char* pName, bool bExact)
{
	return FindBankItem([pName, bExact](const ItemPtr& pItem, const ItemIndex&)
		{ return ci_equals(pItem->GetItemDefinition()->Name, pName, bExact); });
}

ItemClient* FindBankItemByID(int ItemID)
{
	return FindBankItem([ItemID](const ItemPtr& pItem, const ItemIndex&)
		{ return pItem->GetItemDefinition()->ItemNumber == ItemID; });
}

template <typename T>
int CountBankItems(T&& checkItem)
{
	if (!pLocalPC) return 0;

	// Check bank slots
	int count = CountContainerItems(pLocalPC->BankItems, -1, -1, checkItem);

	// Check shared bank slots
	count += CountContainerItems(pLocalPC->SharedBankItems, -1, -1, checkItem);

	return count;
}

int FindBankItemCountByName(const char* pName, bool bExact)
{
	return CountBankItems([pName, bExact](const ItemPtr& pItem)
		{ return ci_equals(pItem->GetItemDefinition()->Name, pName, bExact); });
}

int FindBankItemCountByID(int ItemID)
{
	return CountBankItems([ItemID](const ItemPtr& pItem)
		{ return pItem->GetItemDefinition()->ItemNumber == ItemID; });
}

// Gets the CInvSlot for a given index.
CInvSlot* GetInvSlot(const ItemGlobalIndex& index)
{
	if (!pInvSlotMgr)
		return nullptr;

	return pInvSlotMgr->FindInvSlot(index, false);
}

int FindInvSlotForContents(ItemClient* pContents)
{
	CInvSlot* invSlot = GetInvSlot(pContents->GetItemLocation());
	return invSlot ? invSlot->Index : -1;
}

bool IsItemInsideContainer(ItemClient* pItem)
{
	if (!pItem)
		return false;

	return !pItem->GetItemLocation().GetIndex().IsBase();
}

// opens the container. Returns true if the container was already open.
bool OpenContainer(ItemClient* pItem, bool hidden, bool bAllowTradeskill)
{
	if (!pItem)
		return false;

	if (pItem->IsContainer())
	{
		if (pItem->Open)
			return true;

		if (CInvSlot* pSlot = GetInvSlot(pItem->GetItemLocation()))
		{
			pContainerMgr->OpenContainer(pItem, pSlot->pInvSlotWnd->ItemLocation, bAllowTradeskill);
		}
	}

	return false;
}

// closes the container. Returns true if the container was originally open.
bool CloseContainer(ItemClient* pItem)
{
	if (!pItem)
		return false;

	if (!pItem->Open)
		return false;

	if (pItem->IsContainer())
	{
		pContainerMgr->CloseContainer(pItem, true);
		return true;
	}

	return false;
}

bool ItemOnCursor()
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return false;

	return pProfile->InventoryContainer.GetItem(InvSlot_Cursor) != nullptr;
}

static bool CanUseMultiItemManager(const ItemGlobalIndex& globalIndex)
{
	switch (globalIndex.GetLocation())
	{
	case eItemContainerPossessions:
	case eItemContainerBank:
	case eItemContainerSharedBank:
		return true;

	default:
		return false;
	}
}

bool PickupItem(const ItemGlobalIndex& globalIndex)
{
	if (!pInvSlotMgr) return false;
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return false;

	if (!globalIndex.IsValidIndex())
	{
		WriteChatf("Could not pick up item: index is invalid");
		return false;
	}

	ItemPtr pItem = FindItemByGlobalIndex(globalIndex);
	if (!pItem)
	{
		WriteChatf("Could not pick up item: no item found.");
		return false;
	}

	if (pMerchantWnd && pMerchantWnd->IsVisible())
	{
		// If this is merchant selection, we cannot do it anywhere other than our inventory.
		if (globalIndex.GetLocation() != eItemContainerPossessions)
		{
			WriteChatf("Can only select items in inventory.");
			return false;
		}

		// if the merchant window is open, we dont actually drop anything we just select the slot
		if (CInvSlot* pSlot = GetInvSlot(globalIndex))
		{
			pInvSlotMgr->SelectSlot(pSlot);
		}

		pMerchantWnd->SelectBuySellSlot(globalIndex);
		return true;
	}

	switch (globalIndex.GetLocation())
	{
	case eItemContainerPossessions:
		if (globalIndex.GetTopSlot() == InvSlot_Cursor)
		{
			WriteChatf("Cannot pick up an item from the cursor slot!");
			return false;
		}
		break;

	case eItemContainerBank:
	case eItemContainerSharedBank:
	case eItemContainerDragonHoard:
	case eItemContainerTradeskillDepot:
		if (!pBankWnd || !pBankWnd->IsVisible())
		{
			WriteChatf("Can only interact with bank items if the bank window is open");
			return false;
		}
		break;

	case eItemContainerTrade:
		WriteChatf("Cannot pick up items from trade slots");
		return false;

	default: break;
	}

	// Make sure we're not trying to pick up an augment in a socket.
	ItemGlobalIndex parentIndex = globalIndex.GetParent();
	if (parentIndex.IsValidIndex())
	{
		if (ItemPtr pParentItem = FindItemByGlobalIndex(parentIndex))
		{
			if (!pParentItem->IsContainer())
			{
				// We're not trying to pick up an item from a bag, we're trying to pick up
				// an augment from an item
				WriteChatf("Cannot pick up an augment socketed in an item");
				return false;
			}
		}
	}

	bool isCtrl = pWndMgr->GetKeyboardFlags() & KeyboardFlags_Ctrl;

#if HAS_MULTIPLE_ITEM_MOVE_MANAGER
	if (CanUseMultiItemManager(globalIndex))
	{
		MultipleItemMoveManager::MoveItemArray moveArray;
		MultipleItemMoveManager::MoveItem moveItem;
		moveItem.from = globalIndex;
		moveItem.to = pLocalPC->CreateItemGlobalIndex(InvSlot_Cursor);
		moveItem.flags = MultipleItemMoveManager::MoveItemFlagSwapEnabled;
		moveItem.count = isCtrl ? 1 : 0;
		moveArray.Add(moveItem);

		auto result = MultipleItemMoveManager::ProcessMove(pLocalPC, moveArray);

		if (result != MultipleItemMoveManager::ErrorOk)
		{
			char indexStr[64] = {};
			WriteChatf("Failed to move item from cursor to %s[%s]: %d", GetNameForContainerInstance(globalIndex.GetLocation()),
				globalIndex.GetIndex().FormatItemIndex(indexStr, 64), static_cast<int>(result));
			return false;
		}

		return true;
	}
#endif

#if HAS_KEYRING_WINDOW
	// If this is a keyring slot, we need to use a different method to pick up the item.
	if (globalIndex.IsKeyRingLocation())
	{
#if 0
		if (pCursorAttachment->IsActive())
		{
			WriteChatf("Cannot pick up an item from a keyring while something else is on the cursor");
			return false;
		}

		KeyRingType keyRingType = CKeyRingWnd::GetKeyRingType(globalIndex.GetLocation());
		ECursorAttachmentType linkType = CKeyRingWnd::GetLinkType(keyRingType);
		if (linkType == eCursorAttachment_None)
		{
			WriteChatf("Cannot interact with keyring container: %s", GetNameForContainerInstance(globalIndex.GetLocation()));
			return false;
		}

		if (!pCursorAttachment->IsOkToActivate(linkType))
		{
			WriteChatf("Failed to pick up keyring item");
			return false;
		}

		// Note: The item is not in the held slot, it is only attached to the cursor until we move it somewhere else.
		pCursorAttachment->AttachToCursor(nullptr, nullptr, linkType, -1, pItem->ItemGUID, pItem->ID, "", nullptr, -1, -1);
		return true;
#else
		WriteChatf("Cannot pick up items from keyrings");
		return false;
#endif
	}
#endif // HAS_KEYRING_WINDOW

	// We don't have the MultipleItemMoveManager available to use, so do this the old-fashioned way.

	ItemGlobalIndex To = pLocalPC->CreateItemGlobalIndex(InvSlot_Cursor);
	ItemGlobalIndex From = globalIndex;

	// This is just a top level slot. We should have invslots for all of these.
	if (globalIndex.GetIndex().GetSlot(1) == -1)
	{
		// If ctrl was pressed, and its a stackable item, we need to use the InvSlot in order to
		// perform the move, otherwise we would need to know more about how to transfer partial stacks.
		if (pItem->GetItemCount() > 1 && isCtrl)
		{
			CInvSlot* pInvSlot = pInvSlotMgr->FindInvSlot(From, false);

			// This ctrl keypress will propogate through to the InvSlot and QuantityWnd that it will
			// spawn, ultimiately leading to a transfer of a single item.
			if (!pInvSlot || !pInvSlot->pInvSlotWnd || !SendWndClick2(pInvSlot->pInvSlotWnd, "leftmouseup"))
			{
				WriteChatf("Could not pick up '%s'", pItem->GetName());
				return false;
			}

			return true;
		}

		// just move it from the slot to the cursor
		return pInvSlotMgr->MoveItem(From, To, true, true);
	}

	// We're dealing with an item inside of a bag from this point forward.
	if (pItem->GetItemCount() > 1 && isCtrl)
	{
		// We need an invslot to handle this case.
		CInvSlot* pInvSlot = pInvSlotMgr->FindInvSlot(globalIndex, false);
		ItemClient* pBag = nullptr;
		bool needToClose = false;

		if (!pInvSlot)
		{
			// Get index to parent container
			if (pBag = FindItemByGlobalIndex(globalIndex.GetParent()))
			{
				needToClose = OpenContainer(pBag, true);
				pInvSlot = pInvSlotMgr->FindInvSlot(globalIndex, false);
			}
		}

		if (!pInvSlot || !pInvSlot->pInvSlotWnd || !SendWndClick2(pInvSlot->pInvSlotWnd, "leftmouseup"))
		{
			WriteChatf("Could not pick up '%s'", pItem->GetName());
			return false;
		}

		if (needToClose)
		{
			CloseContainer(pBag);
		}

		return true;
	}

	// ctrl is not pressed, so this will move the whole stack.

	pInvSlotMgr->MoveItem(From, To);

	// Do we have an item in the cursor still? 
	if (ItemPtr pCursorItem = pLocalPC->GetItemByGlobalIndex(To))
	{
		pCursorAttachment->AttachToCursor(nullptr, nullptr, eCursorAttachment_Item, -1,
			pCursorItem->ItemGUID, pCursorItem->GetID(), nullptr, nullptr);
	}
	else
	{
		pCursorAttachment->Deactivate();
	}

	return true;
}

bool DropItem(const ItemGlobalIndex& globalIndex)
{
	if (!pInvSlotMgr)
		return false;
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	ItemPtr pItem = pProfile->GetInventorySlot(InvSlot_Cursor);
	if (!pItem)
	{
		// TODO: Handle case where item link is on the cursor
		WriteChatf("Cannot drop item into inventory slot: no item is on the cursor.");
		return false;
	}

	if (!globalIndex.IsValidIndex())
	{
		WriteChatf("Could not drop item: index is invalid");
		return false;
	}

	if (pMerchantWnd && pMerchantWnd->IsVisible())
	{
		// If this is merchant selection, we cannot do it anywhere other than our inventory.
		if (globalIndex.GetLocation() != eItemContainerPossessions)
		{
			WriteChatf("Can only select items in inventory.");
			return false;
		}

		// if the merchant window is open, we dont actually drop anything we just select the slot
		if (CInvSlot* pSlot = GetInvSlot(globalIndex))
		{
			pInvSlotMgr->SelectSlot(pSlot);
		}

		pMerchantWnd->SelectBuySellSlot(globalIndex);
		return true;
	}

	switch (globalIndex.GetLocation())
	{
	case eItemContainerPossessions:
		if (globalIndex.GetTopSlot() == InvSlot_Cursor)
		{
			WriteChatf("Cannot top an item into the cursor slot!");
			return false;
		}
		break;

	case eItemContainerBank:
	case eItemContainerSharedBank:
	case eItemContainerDragonHoard:
	case eItemContainerTradeskillDepot:
		if (!pBankWnd || !pBankWnd->IsVisible())
		{
			WriteChatf("Can only interact with bank items if the bank window is open");
			return false;
		}
		break;

	default: break;
	}

#if HAS_MULTIPLE_ITEM_MOVE_MANAGER
	if (CanUseMultiItemManager(globalIndex))
	{
		MultipleItemMoveManager::MoveItemArray moveArray;
		MultipleItemMoveManager::MoveItem moveItem;
		moveItem.from = pLocalPC->CreateItemGlobalIndex(InvSlot_Cursor);
		moveItem.to = globalIndex;
		moveItem.flags = MultipleItemMoveManager::MoveItemFlagSwapEnabled;
		moveItem.count = 0;
		moveArray.Add(moveItem);

		// Deactivate the cursor attachment. This will ensure that the new item (if any)
		// will replace it on the cursor.
		pCursorAttachment->Deactivate();

		auto result = MultipleItemMoveManager::ProcessMove(pLocalPC, moveArray);
		if (result != MultipleItemMoveManager::ErrorOk)
		{
			char indexStr[64] = {};
			WriteChatf("Failed to move item from cursor to %s[%s]: %d", GetNameForContainerInstance(globalIndex.GetLocation()),
				globalIndex.GetIndex().FormatItemIndex(indexStr, 64), static_cast<int>(result));
			return false;
		}

		return true;
	}
#endif // HAS_MULTIPLE_ITEM_MOVE_MANAGER

#if HAS_KEYRING_WINDOW
	// If this is a keyring slot, we need to use a different method to pick up the item.
	if (globalIndex.IsKeyRingLocation())
	{
		WriteChatf("Dropping items into keyring slots is not currently supported");
		return false;
	}
#endif // HAS_KEYRING_WINDOW

	// We don't have the MultipleItemMoveManager available to use, so do this the old-fashioned way.

	ItemContainerInstance type = globalIndex.GetLocation();
	short ToInvSlot = globalIndex.GetTopSlot();

	// This is just a top level slot. We should have invslots for all of these.
	if (globalIndex.GetSlot(1) == -1)
	{
		// they want to drop it to a toplevelslot
		CInvSlot* pSlot = GetInvSlot(type, ToInvSlot);
		if (!pSlot || !pSlot->pInvSlotWnd)
		{
			WriteChatf("Could not find the %d itemslot", ToInvSlot);
			return false;
		}
		
		// just move it from cursor to the slot
		pInvSlotMgr->MoveItem(pLocalPC->CreateItemGlobalIndex(InvSlot_Cursor), globalIndex);

		return true;
	}

	// BagSlot is NOT -1 so they want to drop it INSIDE a bag
	ItemGlobalIndex From = pLocalPC->CreateItemGlobalIndex(InvSlot_Cursor);
	ItemGlobalIndex To = globalIndex;

	pInvSlotMgr->MoveItem(From, To);

	// Do we have an item in the cursor still? 
	if (ItemPtr pCursorItem = pLocalPC->GetItemByGlobalIndex(From))
	{
		pCursorAttachment->AttachToCursor(nullptr, nullptr, eCursorAttachment_Item, -1,
			pCursorItem->ItemGUID, pCursorItem->GetID(), nullptr, nullptr);
	}
	else
	{
		pCursorAttachment->Deactivate();
	}

	return true;
}

bool StripQuotes(char* str)
{
	bool bRet = false;
	if (strchr(str, '"'))
		bRet = true;
	char* s,* d;
	for (s = d = str; *d = *s; d += (*s++ != '"'));
	return bRet;
}

//.text:00638049                 mov     ecx, pinstPCData_x
//.text:0063804F                 push    0
//.text:00638051                 push    0
//.text:00638053                 add     ecx, 1FE0h
//.text:00638059                 call    ?MakeMeVisible@CharacterZoneClient@@QAEXH_N@Z ; CharacterZoneClient::MakeMeVisible(int,bool)
void MakeMeVisible(PlayerClient* pChar, const char* szLine)
{
	if (pLocalPC)
	{
		pLocalPC->MakeMeVisible(0, false);
	}
}

// ***************************************************************************
// Function:    RemoveAura
// Description: Removes auras
// Usage:       /removeaura <name> or <partial name>
// ***************************************************************************
void RemoveAura(PlayerClient* pChar, const char* szLine)
{
	if (!pAuraWnd)
		return;

	if (!szLine || (szLine[0] == 0))
	{
		WriteChatColor("Usage: /removeaura <auraname> or <aurapartialname>", CONCOLOR_LIGHTBLUE);
		return;
	}

	if (CListWnd* clist = (CListWnd*)pAuraWnd->GetChildItem("AuraList"))
	{
		for (int i = 0; i < clist->ItemsArray.Count; i++)
		{
			CXStr Str = clist->GetItemText(i, 1);

			if (ci_find_substr(Str, szLine) != -1)
			{
				clist->SetCurSel(i);
				pAuraWnd->WndNotification(clist, XWM_MENUSELECT, (void*)1);
			}
		}
	}
}

std::vector<MercDesc> GetAllMercDesc()
{
	if (!pMercManager)
		return {};

	std::vector<MercDesc> mercDescs;
	mercDescs.reserve(pMercManager->mercenaries.GetCount());

	for (const MercenaryInfo& mercInfo : pMercManager->mercenaries)
	{
		MercDesc outDesc;

		int descIdx = mercInfo.subtypeStringId;
		std::string_view subcatDesc = pCDBStr->GetString(descIdx, eMercenarySubCategoryDescription);
		size_t pos = 0;

		if ((pos = subcatDesc.find("Race: ")) != std::string::npos)
		{
			outDesc.Race = subcatDesc.substr(pos + 6);
			if ((pos = outDesc.Race.find("<br>")) != std::string::npos)
			{
				outDesc.Race.erase(pos);
			}
		}

		if ((pos = subcatDesc.find("Type: ")) != std::string::npos)
		{
			outDesc.Type = subcatDesc.substr(pos + 6);
			if ((pos = outDesc.Type.find("<br>")) != std::string::npos)
			{
				outDesc.Type.erase(pos);
			}
		}

		if ((pos = subcatDesc.find("Confidence: ")) != std::string::npos)
		{
			outDesc.Confidence = subcatDesc.substr(pos + 12);
			if ((pos = outDesc.Confidence.find("<br>")) != std::string::npos)
			{
				outDesc.Confidence.erase(pos);
			}
		}

		if ((pos = subcatDesc.find("Proficiency: ")) != std::string::npos)
		{
			outDesc.Proficiency = subcatDesc.substr(pos + 13);
			if ((pos = outDesc.Proficiency.find("<br>")) != std::string::npos)
			{
				outDesc.Proficiency.erase(pos);
			}
		}

		mercDescs.push_back(std::move(outDesc));
	}

	return mercDescs;
}

bool IsActiveAA(const char* pSpellName)
{
	int level = pLocalPlayer ? pLocalPlayer->Level : -1;

	for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
	{
		if (CAltAbilityData* pAbility = GetAAById(pLocalPC->GetAlternateAbilityId(nAbility), level))
		{
			if (!_stricmp(pSpellName, pDBStr->GetString(pAbility->nName, eAltAbilityName)))
			{
				if (pAbility->SpellID <= 0)
				{
					return true;
				}
			}
		}
	}

	return false;
}

struct Personal_Loot
{
	CButtonWnd* NPC_Name = nullptr;
	CButtonWnd* Item = nullptr;
	CButtonWnd* Loot = nullptr;
	CButtonWnd* Leave = nullptr;
	CButtonWnd* AN = nullptr;
	CButtonWnd* AG = nullptr;
	CButtonWnd* Never = nullptr;
};

CXWnd* GetAdvLootPersonalListItem(DWORD ListIndex, DWORD type)
{
#if HAS_ADVANCED_LOOT
	if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_PLLList"))
	{
		Personal_Loot pPAdvLoot;
		bool bFound = false;
		int listindex = -1;

		CXWnd* pFirstWnd = clist->GetFirstChildWnd();
		CXWnd* pNextWnd = pFirstWnd;

		for (int i = 0; i < clist->ItemsArray.Count; i++)
		{
			if (pNextWnd)
			{
				pPAdvLoot.NPC_Name = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pPAdvLoot.Item = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pPAdvLoot.Loot = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pPAdvLoot.Leave = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pPAdvLoot.Never = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pPAdvLoot.AN = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pPAdvLoot.AG = (CButtonWnd*)pNextWnd->GetFirstChildWnd();

				if (pNextWnd && pNextWnd->GetNextSiblingWnd())
				{
					pNextWnd = pNextWnd->GetNextSiblingWnd();
				}
			}

			if (ListIndex == i)
			{
				bFound = true;
				break;
			}
		}

		if (bFound)
		{
			CXWnd* ptr = nullptr;

			switch (type)
			{
			case 0:
				ptr = pPAdvLoot.NPC_Name;
				break;
			case 1:
				ptr = pPAdvLoot.Item;
				break;
			case 2:
				ptr = pPAdvLoot.Loot;
				break;
			case 3:
				ptr = pPAdvLoot.Leave;
				break;
			case 4:
				ptr = pPAdvLoot.Never;
				break;
			case 5:
				ptr = pPAdvLoot.AN;
				break;
			case 6:
				ptr = pPAdvLoot.AG;
				break;
			}

			return ptr;
		}
	}
#endif

	return nullptr;
}

struct Shared_Loot
{
	CButtonWnd* NPC_Name = nullptr;
	CButtonWnd* Item = nullptr;
	CButtonWnd* Status = nullptr;
	CButtonWnd* Action = nullptr;
	CButtonWnd* Manage = nullptr;
	CButtonWnd* AutoRoll = nullptr;
	CButtonWnd* ND = nullptr;
	CButtonWnd* GD = nullptr;
	CButtonWnd* NO = nullptr;
	CButtonWnd* AN = nullptr;
	CButtonWnd* AG = nullptr;
	CButtonWnd* NV = nullptr;
};

CXWnd* GetAdvLootSharedListItem(DWORD ListIndex, DWORD type)
{
#if HAS_ADVANCED_LOOT
	if (CListWnd* clist = (CListWnd*)pAdvancedLootWnd->GetChildItem("ADLW_CLLList"))
	{
		Shared_Loot pSAdvLoot;
		bool bFound = false;

		CXWnd* pFirstWnd = clist->GetFirstChildWnd();
		CXWnd* pNextWnd = pFirstWnd;

		for (int i = 0; i < clist->ItemsArray.Count; i++)
		{
			if (pNextWnd)
			{
				pSAdvLoot.NPC_Name = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.Item = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.Status = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.Action = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.Manage = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.AN = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.AG = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.AutoRoll = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.NV = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.ND = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.GD = (CButtonWnd*)pNextWnd->GetFirstChildWnd();
				pNextWnd = pNextWnd->GetNextSiblingWnd();
				pSAdvLoot.NO = (CButtonWnd*)pNextWnd->GetFirstChildWnd();

				if (pNextWnd && pNextWnd->GetNextSiblingWnd())
				{
					pNextWnd = pNextWnd->GetNextSiblingWnd();
				}
			}
			if (ListIndex == i)
			{
				bFound = true;
				break;
			}
		}

		// NPC_Name,Item,Status,Action,Manage,AN,AG,AutoRoll,NV,ND,GD,NO
		if (bFound)
		{
			CXWnd* ptr = nullptr;
			switch (type)
			{
			case 0:
				ptr = pSAdvLoot.NPC_Name;
				break;
			case 1:
				ptr = pSAdvLoot.Item;
				break;
			case 2:
				ptr = pSAdvLoot.Status;
				break;
			case 3:
				ptr = pSAdvLoot.Action;
				break;
			case 4:
				ptr = pSAdvLoot.Manage;
				break;
			case 5:
				ptr = pSAdvLoot.AN;
				break;
			case 6:
				ptr = pSAdvLoot.AG;
				break;
			case 7:
				ptr = pSAdvLoot.AutoRoll;
				break;
			case 8:
				ptr = pSAdvLoot.NV;
				break;
			case 9:
				ptr = pSAdvLoot.ND;
				break;
			case 10:
				ptr = pSAdvLoot.GD;
				break;
			case 11:
				ptr = pSAdvLoot.NO;
				break;
			case 12: // root
				ptr = pSAdvLoot.Item;
				break;
			}

			return ptr;
		}
	}
#endif

	return nullptr;
}

bool LootInProgress(CAdvancedLootWnd* pAdvLoot, CListWnd* pPersonalList, CListWnd* pSharedList)
{
#if HAS_ADVANCED_LOOT
	if (pPersonalList)
	{
		for (int i = 0; i < pPersonalList->ItemsArray.Count; i++)
		{
			int listindex = (int)pPersonalList->GetItemData(i);
			if (listindex != -1)
			{
				AdvancedLootItem& lootItem = pAdvLoot->pPLootList->Items[listindex];
				if (lootItem.PLootInProgress || lootItem.CLootInProgress)
				{
					return true;
				}
			}
		}
	}

	if (pSharedList)
	{
		for (int i = 0; i < pSharedList->ItemsArray.Count; i++)
		{
			int listindex = (int)pSharedList->GetItemData(i);
			if (listindex != -1)
			{
				AdvancedLootItem& lootItem = pAdvLoot->pCLootList->Items[listindex];
				if (lootItem.PLootInProgress || lootItem.CLootInProgress)
				{
					return true;
				}
			}
		}
	}
#endif 

	return false;
}

void WeDidStuff()
{
	gbCommandEvent = 1;
	gMouseEventTime = GetFastTime();
}

int GetFreeInventory(int nSize)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return 0;

	int freeSlots = 0;
	for (int slot = InvSlot_FirstBagSlot; slot <= GetHighestAvailableBagSlot(); slot++)
	{
		if (ItemPtr pItem = pProfile->InventoryContainer.GetItem(slot))
		{
			if (pItem->IsContainer()
				&& (nSize == 0 || pItem->GetItemDefinition()->SizeCapacity >= nSize))
			{
				freeSlots += pItem->GetHeldItems().GetSize() - pItem->GetHeldItems().GetCount();
			}
		}
		else
		{
			freeSlots++;
		}
	}

	return freeSlots;
}

int GetFreeStack(ItemClient* pContents)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile || !pContents) return 0;

	if (!pContents->IsStackable())
		return 0;

	int freeStack = 0;
	int findId = pContents->GetID();

	for (int slot = InvSlot_FirstBagSlot; slot <= GetHighestAvailableBagSlot(); slot++)
	{
		ItemPtr pCurrentItem = pProfile->GetInventorySlot(slot);
		if (!pCurrentItem) continue;

		if (pCurrentItem->IsContainer())
		{
			for (const ItemPtr& pChildItem : pCurrentItem->GetHeldItems())
			{
				if (!pChildItem) continue;

				if (pChildItem->GetID() == findId)
				{
					freeStack += pChildItem->GetMaxItemCount() - pChildItem->GetItemCount();
				}
			}
		}
		else
		{
			if (pCurrentItem->GetID() == findId)
			{
				freeStack += pCurrentItem->GetMaxItemCount() - pCurrentItem->GetItemCount();
			}
		}
	}

	return freeStack;
}

bool CanItemMergeInPack(ItemClient* pPack, ItemClient* pItem)
{
	if (!pPack || !pItem) return false;
	int findId = pItem->GetID();

	for (const ItemPtr& pSlot : pPack->GetHeldItems())
	{
		if (!pSlot) continue;

		// If its the same item, check if it has stack space left for
		// the requested item.
		if (findId == pSlot->GetID())
		{
			if (pSlot->GetItemCount() + pItem->GetItemCount() <= pSlot->GetMaxItemCount())
				return true;
		}
	}

	return false;
}

bool CanItemGoInPack(ItemClient* pPack_, ItemClient* pItem)
{
	// so CanGoInBag doesn't actually check if there is any room, all it checks
	// is IF there were room, could the item fit in it.
	const ItemPtr pPack{ pPack_ };

	if (!pItem->CanGoInBag(pPack))
		return false;

	const ItemContainer& heldItems = pPack->GetHeldItems();
	if (heldItems.IsEmpty())
	{
		return true;
	}

	for (const ItemPtr& pItemInBag : heldItems)
	{
		// If this slot is empty, then the bag has room.
		if (!pItemInBag)
		{
			return true;
		}
	}

	return false;
}

static bool WillItemFitInSlot(const ItemPtr& pItemSlot, const ItemPtr& itemToFit)
{
	// If there is nothing in this slot then it will fit there.
	if (!pItemSlot) return true;

	if (pItemSlot->IsContainer())
	{
		// Check if the item can go into this bag.
		if (CanItemMergeInPack(pItemSlot.get(), itemToFit.get()))
			return true;

		if (CanItemGoInPack(pItemSlot.get(), itemToFit.get()))
			return true;
	}
	else if (pItemSlot->GetID() == itemToFit->GetID() && pItemSlot->IsStackable())
	{
		// Its the same item and the item is stackable, see if the slot has room to spare
		if (pItemSlot->GetItemCount() + itemToFit->GetItemCount() <= pItemSlot->GetMaxItemCount())
			return true;
	}

	return false;
}

bool WillFitInBank(ItemClient* pContent)
{
	if (!pContent) return false;
	if (!pLocalPC) return false;

	ItemPtr pItemToFit{ pContent };

	for (const ItemPtr& pBankSlot : pLocalPC->BankItems)
	{
		if (WillItemFitInSlot(pBankSlot, pItemToFit))
			return true;
	}

	return false;
}

bool WillFitInInventory(ItemClient* pContent)
{
	if (!pContent) return false;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return false;

	ItemPtr pItemToFit{ pContent };

	for (int slot = InvSlot_FirstBagSlot; slot != GetHighestAvailableBagSlot(); ++slot)
	{
		ItemPtr pInvSlot = pProfile->InventoryContainer.GetItem(slot);

		if (WillItemFitInSlot(pInvSlot, pItemToFit))
			return true;
	}

	return false;
}

int GetGroupMemberClassByIndex(int index)
{
	if (!pLocalPC || !pLocalPC->Group)
		return 0;

	CGroupMember* pMember = pLocalPC->Group->GetGroupMember(index);

	if (pMember && pMember->GetPlayer())
	{
		return pMember->GetPlayer()->GetClass();
	}

	return 0;
}

int GetRaidMemberClassByIndex(int index)
{
	if (pRaid && pRaid->Invited == RaidStateInRaid)
	{
		if (pRaid->RaidMemberUsed[index])
			return pRaid->RaidMember[index].nClass;
	}

	return 0;
}


struct random_number_generator {
	random_number_generator()
		: mt(random_device()) {}

	~random_number_generator() {}

	template <typename T> T generate(T min, T max) const {
		std::uniform_int_distribution<T> dist(min, max);

		return dist(mt);
	}

	std::random_device random_device;
	mutable std::mt19937 mt;
};
static random_number_generator s_rng;

int RangeRandom(int min, int max)
{
	return s_rng.generate(min, max);
}

//============================================================================

ItemDefinition* GetItemFromContents(ItemClient* c)
{
	if (!c)
		return nullptr;

	return c->GetItemDefinition();
}

struct EnumWindowsData
{
	HWND outHWnd;
	DWORD processId;
};

static BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	EnumWindowsData* enumData = reinterpret_cast<EnumWindowsData*>(lParam);

	// Get the process id for the window.
	DWORD dwProcessId = 0;
	GetWindowThreadProcessId(hWnd, &dwProcessId);

	// Only check windows in the current process
	if (enumData->processId == dwProcessId)
	{
		char szClass[24] = { 0 };
		::GetClassNameA(hWnd, szClass, 23);

		// If its the EverQuest window class, return it.
		if (strcmp(szClass, "_EverQuestwndclass") == 0)
		{
			enumData->outHWnd = hWnd;
			return false;
		}
	}

	return true;
}

MQLIB_API HWND GetEQWindowHandle()
{
	DWORD dwProcessId = GetCurrentProcessId();

	EnumWindowsData enumData;
	enumData.outHWnd = nullptr;
	enumData.processId = dwProcessId;

	EnumWindows(EnumWindowsProc, (LPARAM)&enumData);

	return enumData.outHWnd;
}

// ***************************************************************************
// Function:    GetCharMaxBuffSlots
// Description: Returns the max number of buff slots available for a character
// ***************************************************************************
int GetCharMaxBuffSlots()
{
	int NumBuffs = 15;

	if (pLocalPC)
	{
		NumBuffs += pLocalPC->TotalEffect(SPA_ADD_BUFF_SLOTS, true, 0, true, true);

		if (pLocalPlayer)
		{
			if (pLocalPlayer->Level > 70)
				NumBuffs++;
			if (pLocalPlayer->Level > 74)
				NumBuffs++;
		}
	}

	return NumBuffs;
}

int GetCharMaxLevel()
{
	int MaxLevel = 50;

	if (HasExpansion(EXPANSION_LS) || HasExpansion(EXPANSION_TOB))
	{
		MaxLevel = 125;
	}
	else if (HasExpansion(EXPANSION_TOL) || HasExpansion(EXPANSION_NOS))
	{
		MaxLevel = 120;
	}
	else if (HasExpansion(EXPANSION_COV) || HasExpansion(EXPANSION_TOV))
	{
		MaxLevel = 115;
	}
	else if (HasExpansion(EXPANSION_TBL) || HasExpansion(EXPANSION_RoS))
	{
		MaxLevel = 110;
	}
	else if (HasExpansion(EXPANSION_EoK) || HasExpansion(EXPANSION_TBM) || HasExpansion(EXPANSION_TDS))
	{
		MaxLevel = 105;
	}
	else if (HasExpansion(EXPANSION_CotF) || HasExpansion(EXPANSION_RoF))
	{
		MaxLevel = 100;
	}
	else if (HasExpansion(EXPANSION_VoA))
	{
		MaxLevel = 95;
	}
	else if (HasExpansion(EXPANSION_HoT))
	{
		MaxLevel = 90;
	}
	else if (HasExpansion(EXPANSION_UFT) || HasExpansion(EXPANSION_SoD))
	{
		MaxLevel = 85;
	}
	else if (HasExpansion(EXPANSION_SoF))
	{
		MaxLevel = 80;
	}
	else if (HasExpansion(EXPANSION_TBS) || HasExpansion(EXPANSION_TSS))
	{
		MaxLevel = 75;
	}
	else if (HasExpansion(EXPANSION_PoR) || HasExpansion(EXPANSION_DoD) || HasExpansion(EXPANSION_DoN) || HasExpansion(EXPANSION_OoW))
	{
		MaxLevel = 70;
	}
	else if (HasExpansion(EXPANSION_GoD) || HasExpansion(EXPANSION_LDoN) || HasExpansion(EXPANSION_LoY) || HasExpansion(EXPANSION_PoP))
	{
		MaxLevel = 65;
	}
	else if (HasExpansion(EXPANSION_SoL) || HasExpansion(EXPANSION_SoV) || HasExpansion(EXPANSION_RoK))
	{
		MaxLevel = 60;
	}

	return MaxLevel;
}


int GetBodyType(SPAWNINFO* pSpawn)
{
	if (pSpawn != nullptr && pSpawn->BodyType != nullptr)
	{
		for (int i = 0; i < CharacterProperty_Last; i++)
		{
			if (pSpawn->HasProperty(i))
			{
				if (i == CharacterProperty_Utility)
				{
					if (pSpawn->HasProperty(i, CharacterProperty_Trap))
						return CharacterProperty_Trap;
					if (pSpawn->HasProperty(i, CharacterProperty_Companion))
						return CharacterProperty_Companion;
					if (pSpawn->HasProperty(i, CharacterProperty_Suicide))
						return CharacterProperty_Suicide;
				}
				return i;
			}
		}
	}

	return 0;
}

eSpawnType GetSpawnType(SPAWNINFO* pSpawn)
{
	if (pSpawn == nullptr)
		return NONE;

	switch (pSpawn->Type)
	{
	case SPAWN_PLAYER:
		return PC;

	case SPAWN_NPC:
		// Sometimes mounts can be spawned without a rider. Sometimes a user can have
		// multiple mounts due to bugs! Check the display name which will have the same
		// suffix for all mounts.
		if (pSpawn->Rider || mq::ends_with(pSpawn->DisplayedName, "`s Mount"))
			return MOUNT;

		if (pSpawn->MasterID)
			return PET;
		if (pSpawn->Mercenary)
			return MERCENARY;

		// some type of controller spawn for flying mobs - locations, speed, heading, all NaN
		if (IsNaN(pSpawn->Y) && IsNaN(pSpawn->X) && IsNaN(pSpawn->Z))
			return FLYER;

		switch (GetBodyType(pSpawn))
		{
		case CharacterProperty_None: // Object
			if (pSpawn->GetClass() == Class_Object)
				return OBJECT;
			return NPC;

		case CharacterProperty_Construct:
			// "Invisible Man" Race containing "Aura" / "Circle_of" / "Guardian_Circle" / "Earthen_Strength" / "Pact_of_the_Wolf" in the Name
			if ((pSpawn->GetRace() == EQR_INVISIBLE_MAN) &&
				(strstr(pSpawn->Name, "Aura") || strstr(pSpawn->Name, "Circle_of") || strstr(pSpawn->Name, "Guardian_Circle") || strstr(pSpawn->Name, "Earthen_Strength") || strstr(pSpawn->Name, "Pact_of_the_Wolf")))
				return AURA;
			// "Spike Trap" Race containing "Poison" in the Name
			if ((pSpawn->GetRace() == EQR_SPIKE_TRAP) && (strstr(pSpawn->Name, "poison") || strstr(pSpawn->Name, "Poison")))
				return AURA;
			// Contains "Rune" in the Name
			if (strstr(pSpawn->Name, "Rune"))
				return AURA;
			// Object Class
			if (pSpawn->GetClass() == Class_Object)
				return OBJECT;
			return NPC;

		case CharacterProperty_Magical:
			// "Campfire" Race
			if (pSpawn->GetRace() == EQR_CAMPSITE)
				return CAMPFIRE;
			// "Banner" Race(s)
			if (pSpawn->GetRace() == EQR_BANNER || (pSpawn->GetRace() >= EQR_BANNER0 && pSpawn->GetRace() <= EQR_BANNER4) || pSpawn->GetRace() == EQR_TCGBANNER)
				return BANNER;
			// "Totem" Race containing "Idol" in the Name
			if ((pSpawn->GetRace() == EQR_TOTEM) && strstr(pSpawn->Name, "Idol"))
				return AURA;
			// Object Class
			if (pSpawn->GetClass() == Class_Object)
				return OBJECT;
			return NPC;

		case CharacterProperty_Untargetable:
			return UNTARGETABLE;

		case CharacterProperty_Cursed:
			return CHEST;

		case CharacterProperty_Utility:
			return UNTARGETABLE;

		case CharacterProperty_Trap:
			return TRAP;

		case CharacterProperty_Companion:
			return TIMER;

		case CharacterProperty_Suicide:
			return TRIGGER;

		default: break;
		}
		return NPC;

	case SPAWN_CORPSE:
		return CORPSE;

	default: break;
	}

	return ITEM;
}

bool IsRaidMember(const char* SpawnName)
{
	if (pRaid->Invited == RaidStateInRaid)
	{
		for (int index = 0; index < MAX_RAID_SIZE; index++)
		{
			if (pRaid->RaidMemberUsed[index] && !_stricmp(SpawnName, pRaid->RaidMember[index].Name))
				return true;
		}
	}

	return false;
}

int GetRaidMemberIndex(const char* SpawnName)
{
	if (pRaid->Invited == RaidStateInRaid)
	{
		for (int index = 0; index < MAX_RAID_SIZE; index++)
		{
			if (pRaid->RaidMemberUsed[index] && !_stricmp(SpawnName, pRaid->RaidMember[index].Name))
				return index;
		}
	}

	return -1;
}

bool IsRaidMember(SPAWNINFO* pSpawn)
{
	if (pSpawn != nullptr)
	{
		for (int index = 0; index < MAX_RAID_SIZE; index++)
		{
			if (pRaid->RaidMemberUsed[index] && !_stricmp(pSpawn->Name, pRaid->RaidMember[index].Name))
				return true;
		}
	}

	return false;
}

int GetRaidMemberIndex(SPAWNINFO* pSpawn)
{
	if (pSpawn != nullptr)
	{
		for (int index = 0; index < MAX_RAID_SIZE; index++)
		{
			if (pRaid->RaidMemberUsed[index] && !_stricmp(pSpawn->Name, pRaid->RaidMember[index].Name))
				return index;
		}
	}

	return -1;
}

bool IsGroupMember(const char* SpawnName)
{
	if (!pLocalPC || !pLocalPC->Group)
		return false;

	for (int index = 1; index < MAX_GROUP_SIZE; index++)
	{
		if (CGroupMember* pMember = pLocalPC->Group->GetGroupMember(index))
		{
			char Name[MAX_STRING] = { 0 };
			strcpy_s(Name, pMember->GetName());

			CleanupName(Name, sizeof(Name), false, false);

			if (!_stricmp(SpawnName, Name))
				return true;
		}
	}

	return false;
}

/*
 * Returns Group Member that is not self
 */
bool IsGroupMember(SPAWNINFO* pSpawn)
{
	if (!pLocalPC || !pLocalPC->Group)
		return false;

	for (int index = 1; index < MAX_GROUP_SIZE; index++)
	{
		if (CGroupMember* pMember = pLocalPC->Group->GetGroupMember(index))
		{
			char Name[MAX_STRING] = { 0 };
			strcpy_s(Name, pMember->GetName());

			//CleanupName(Name, sizeof(Name), false, false);

			if (!_stricmp(pSpawn->Name, Name))
				return true;
		}
	}

	return false;
}

bool IsFellowshipMember(const char* SpawnName)
{
	SPAWNINFO* pSpawn = pLocalPlayer;
	if (!pSpawn)
		return false;

	for (int i = 0; i < pSpawn->Fellowship.Members; ++i)
	{
		if (ci_equals(SpawnName, pSpawn->Fellowship.FellowshipMember[i].Name))
			return true;
	}

	return false;
}

bool IsGuildMember(const char* SpawnName)
{
	if (!pLocalPC || pLocalPC->GuildID == 0 || !pGuild)
		return false;

	GuildMember* mem = pGuild->FindMemberByName(SpawnName);
	return mem && _stricmp(SpawnName, mem->Name) == 0;
}

int GetGroupMercenaryCount(uint32_t ClassMASK)
{
	if (!pLocalPC || !pLocalPC->Group)
		return 0;

	int count = 0;

	for (int index = 1; index < MAX_GROUP_SIZE; index++)
	{
		if (CGroupMember* pMember = pLocalPC->Group->GetGroupMember(index))
		{
			if (pMember->Type == EQP_NPC && pMember->GetPlayer()
				&& (ClassMASK & (1 << (pMember->GetPlayer()->GetClass() - 1))))
			{
				count++;
			}
		}
	}

	return count;
}

SPAWNINFO* GetRaidMember(int index)
{
	if (index >= MAX_RAID_SIZE)
		return nullptr;

	EQRAIDMEMBER* pRaidMember = &pRaid->RaidMember[index];

	if (!pRaidMember)
		return nullptr;

	return GetSpawnByName(pRaidMember->Name);
}

inline SPAWNINFO* GetGroupMember(int index)
{
	if (index >= MAX_GROUP_SIZE || index <= 0)
		return nullptr;

	if (!pLocalPC || !pLocalPC->Group)
		return nullptr;

	for (int i = 1; i < MAX_GROUP_SIZE; i++)
	{
		if (CGroupMember* pMember = pLocalPC->Group->GetGroupMember(i))
		{
			index--;

			if (index == 0)
			{
				// FIXME: GroupMember - use GetPlayer()
				return GetSpawnByName(pMember->GetName());
			}
		}
	}

	return nullptr;
}

uint32_t GetGroupMarkedTargetID(int index)
{
	if (!pLocalPlayer || !pLocalPC->Group) return 0;

	if (index < 0 || index >= (int)lengthof(pLocalPlayer->GroupMarkNPC))
		return 0;

	return pLocalPlayer->GroupMarkNPC[index];
}

uint32_t GetRaidMarkedTargetID(int index)
{
	if (!pLocalPlayer) return 0;

	if (index < 0 || index >= (int)lengthof(pLocalPlayer->RaidMarkNPC))
		return 0;

	return pLocalPlayer->RaidMarkNPC[index];
}

void DoFace(SPAWNINFO* pChar, CVector3 Position)
{
	gFaceAngle = atan2(Position.X - pChar->X, Position.Y - pChar->Y) * 256.f / PI;

	gLookAngle = atan2(
		Position.Z - pChar->Z - pChar->AvatarHeight * StateHeightMultiplier(pChar->StandState),
		Distance3DToPoint(pChar, Position.X, Position.Y, Position.Z)) * 256.f / PI;

	if (gFaceAngle >= 512.0f)
		gFaceAngle -= 512.0f;
	if (gFaceAngle < 0.0f)
		gFaceAngle += 512.0f;
}

void PrettifyNumber(char* string, size_t bufferSize, int decimals /* = 0 */)
{
	if (strlen(string) >= 64)
		return;
	char temp[64];
	strcpy_s(temp, string);

	static char decimalSep[] = ".";
	static char thousandSep[] = ",";

	if (decimals < 0)
		decimals = 0;
	else if (decimals > 9)
		decimals = 9;

	NUMBERFMTA fmt;
	fmt.Grouping = 3;                    // group every 3 digits to the left of the decimal
	fmt.NumDigits = decimals;            // display N digits after the decimal point
	fmt.LeadingZero = decimals ? 1 : 0;  // display zeroes after the decimal point
	fmt.lpDecimalSep = decimalSep;       // character to use for decimal separator.
	fmt.lpThousandSep = thousandSep;     // use a comma for thousands separator
	fmt.NegativeOrder = 1;               // Negative sign, number: -1.1

	GetNumberFormatA(
		LOCALE_INVARIANT,
		0,
		temp,
		&fmt,
		string,
		static_cast<int>(bufferSize));
}

//============================================================================

MQColor GetColorForChatColor(uint32_t chatColor)
{
	if (chatColor > 255)
	{
		chatColor -= 256;

		if (chatColor >= NUM_USER_COLORS)
			chatColor = 0;

		// Ensure that alpha is set to fully opaque
		MQColor color{ MQColor::format_bgr, CDisplay::GetUserDefinedColor(chatColor) };
		if (gGameState != GAMESTATE_CHARCREATE
			|| gGameState != GAMESTATE_CHARSELECT
			|| gGameState != GAMESTATE_INGAME
			|| (color.ARGB & 0x00ffffff) == 0x00ffffff)
		{
			// Hasn't been set yet. Use defaults.
			color = gDefaultUserDefinedColors[chatColor];
		}
		color.Alpha = 255;
		return color;
	}

	switch (chatColor)
	{
	case COLOR_DEFAULT:       // 0
		return MQColor(240, 240, 240);

	case COLOR_DARKGREEN:     // 2 - CONCOLOR_GREEN
		return MQColor(0,   128, 0);

	case CONCOLOR_BLUE:       // 4
		return MQColor(0,   64,  255);
	case COLOR_PURPLE:        // 5
		return MQColor(240, 0,   240);
	case COLOR_LIGHTGREY:     // 6 - CONCOLOR_GREY
		return MQColor(128, 128, 128);
	case 7: // light gray
		return MQColor(224, 224, 224);

	case CONCOLOR_WHITE:      // 10
		return MQColor(240, 240, 240);

	case 12: // light gray
		return MQColor(160, 160, 160);
	case CONCOLOR_RED:        // 13
		return MQColor(240, 0,   0);
	case 14: // light green
		return MQColor(0,   240, 0);
	case CONCOLOR_YELLOW:     // 15
		return MQColor(240, 240, 0);
	case 16: // blue
		return MQColor(0,   0,   240);
	case 17: // dark blue
		return MQColor(0,   0,   175);
	case CONCOLOR_LIGHTBLUE:  // 18
		return MQColor(0,   240, 240);

	case CONCOLOR_BLACK:      // 20
		return MQColor(0,   0,   0);
	case 21: // orange
		return MQColor(240, 160, 0);
	case 22: // brown
		return MQColor(128, 96,  32);

	default:
		return MQColor(96,  96,  96);
	}
}

uint32_t mqGetColorForChatColor(uint32_t chatColor)
{
	return GetColorForChatColor(chatColor).ARGB;
}

// TODO: We should move library code to its own tree
std::string to_string(MQColor color)
{
	if (color.Alpha != 255)
	{
		return fmt::format("RGBA({}, {}, {}, {})",
			static_cast<int>(color.Red), static_cast<int>(color.Green), static_cast<int>(color.Blue), static_cast<int>(color.Alpha));
	}

	return fmt::format("RGB({}, {}, {})",
		static_cast<int>(color.Red), static_cast<int>(color.Green), static_cast<int>(color.Blue));
}

// TODO: Rewrite this using string_view
uint64_t GetMoneyFromString(const char* str, GetMoneyFromStringFormat format)
{
	char szLabel1[50];
	strcpy_s(szLabel1, str);

	uint64_t pp = 0;
	uint64_t gp = 0;
	uint64_t sp = 0;
	uint64_t cp = 0;

	if (format == GetMoneyFromStringFormat::Long)
	{
		if (char* pDest = strstr(szLabel1, "pp"))
		{
			pDest[0] = '\0';
			pp = GetInt64FromString(szLabel1, pp);
			strcpy_s(szLabel1, &pDest[2]);
		}

		if (char* pDest = strstr(szLabel1, "gp"))
		{
			pDest[0] = '\0';
			gp = GetInt64FromString(szLabel1, gp);
			strcpy_s(szLabel1, &pDest[2]);
		}

		if (char* pDest = strstr(szLabel1, "sp"))
		{
			pDest[0] = '\0';
			sp = GetInt64FromString(szLabel1, sp);
			strcpy_s(szLabel1, &pDest[2]);
		}

		if (char* pDest = strstr(szLabel1, "cp"))
		{
			pDest[0] = '\0';
			cp = GetInt64FromString(szLabel1, cp);
			strcpy_s(szLabel1, &pDest[2]);
		}
	}
	else if (format == GetMoneyFromStringFormat::Short)
	{
		if (char* pDest = strstr(szLabel1, "p"))
		{
			pDest[0] = '\0';
			pp = GetInt64FromString(szLabel1, pp);
			strcpy_s(szLabel1, &pDest[1]);
		}

		if (char* pDest = strstr(szLabel1, "g"))
		{
			pDest[0] = '\0';
			gp = GetInt64FromString(szLabel1, gp);
			strcpy_s(szLabel1, &pDest[1]);
		}

		if (char* pDest = strstr(szLabel1, "s"))
		{
			pDest[0] = '\0';
			sp = GetInt64FromString(szLabel1, sp);
			strcpy_s(szLabel1, &pDest[1]);
		}

		if (char* pDest = strstr(szLabel1, "c"))
		{
			pDest[0] = '\0';
			cp = GetInt64FromString(szLabel1, cp);
			strcpy_s(szLabel1, &pDest[1]);
		}
	}

	uint64_t total = (pp * 1000) + (gp * 100) + (sp * 10) + cp;
	return total;
}

void FormatMoneyString(char* szBuffer, size_t bufferLength, uint64_t moneyAmount, GetMoneyFromStringFormat format)
{
	szBuffer[0] = 0;

	if (moneyAmount == 0)
	{
		if (format == GetMoneyFromStringFormat::Long)
			strcat_s(szBuffer, bufferLength, "0cp");
		else if (format == GetMoneyFromStringFormat::Short)
			strcat_s(szBuffer, bufferLength, "0c");

		return;
	}

	uint64_t cp = moneyAmount;
	uint64_t sp = cp / 10; cp = cp % 10;
	uint64_t gp = sp / 10; sp = sp % 10;
	uint64_t pp = gp / 10; gp = gp % 10;

	char szTemp[64];

	if (pp > 0)
	{
		if (format == GetMoneyFromStringFormat::Long)
			sprintf_s(szTemp, "%I64dpp", pp);
		else if (format == GetMoneyFromStringFormat::Short)
			sprintf_s(szTemp, "%I64dp", pp);
		strcat_s(szBuffer, bufferLength, szTemp);
	}

	if (gp > 0)
	{
		if (szBuffer[0] != 0)
			strcat_s(szBuffer, bufferLength, " ");
		if (format == GetMoneyFromStringFormat::Long)
			sprintf_s(szTemp, "%I64dgp", gp);
		else if (format == GetMoneyFromStringFormat::Short)
			sprintf_s(szTemp, "%I64dg", gp);
		strcat_s(szBuffer, bufferLength, szTemp);
	}

	if (sp > 0)
	{
		if (szBuffer[0] != 0)
			strcat_s(szBuffer, bufferLength, " ");
		if (format == GetMoneyFromStringFormat::Long)
			sprintf_s(szTemp, "%I64dsp", sp);
		else if (format == GetMoneyFromStringFormat::Short)
			sprintf_s(szTemp, "%I64ds", sp);
		strcat_s(szBuffer, bufferLength, szTemp);
	}

	if (cp > 0)
	{
		if (szBuffer[0] != 0)
			strcat_s(szBuffer, bufferLength, " ");
		if (format == GetMoneyFromStringFormat::Long)
			sprintf_s(szTemp, "%I64dcp", cp);
		else if (format == GetMoneyFromStringFormat::Short)
			sprintf_s(szTemp, "%I64dc", cp);
		strcat_s(szBuffer, bufferLength, szTemp);
	}
}

bool HasBuffCastByPlayer(SPAWNINFO* pBuffOwner, const char* szBuffName, const char* casterName)
{
	auto predicate = [szBuffName, casterName](const CachedBuff& buff)
	{
		return MaybeExactCompare(GetSpellNameByID(buff.spellId), szBuffName)
			&& _stricmp(buff.casterName, casterName) == 0;
	};

	int slot = GetCachedBuff(pBuffOwner, predicate);
	return slot != -1;
}

bool TargetBuffCastByMe(const char* szBuffName)
{
	if (!pLocalPlayer || !pTarget)
		return false;

	return HasBuffCastByPlayer(pTarget, szBuffName, pLocalPlayer->Name);
}

//----------------------------------------------------------------------------

MQGameObject ToGameObject(const EQGroundItem& groundItem)
{
	MQGameObject temp;

	temp.type = eGameObjectType::GroundItem;
	temp.id = groundItem.DropID;
	temp.subId = groundItem.DropSubID;
	temp.name = groundItem.Name;

	temp.displayName = GetFriendlyNameForGroundItem(&groundItem);
	temp.y = groundItem.Y;
	temp.x = groundItem.X;
	temp.z = groundItem.Z;
	temp.heading = groundItem.Heading * 0.703125f;
	temp.actor = groundItem.pActor;

	return temp;
}

MQGameObject ToGameObject(const EQPlacedItem& placedItem)
{
	MQGameObject temp;

	temp.type = eGameObjectType::PlaceableItem;
	temp.id = placedItem.RealEstateItemID;
	temp.subId = placedItem.RealEstateID;
	temp.name = placedItem.Name;

	temp.displayName = GetFriendlyNameForPlacedItem(&placedItem);
	temp.y = placedItem.Y;
	temp.x = placedItem.X;
	temp.z = placedItem.Z;
	temp.heading = placedItem.Heading * 0.703125f;
	temp.actor = placedItem.pActor;

	return temp;
}

MQGameObject ToGameObject(const MQGroundSpawn& groundSpawn)
{
	if (EQGroundItem* pEQGroundItem = groundSpawn.Get<EQGroundItem>())
	{
		return ToGameObject(*pEQGroundItem);
	}

	if (EQPlacedItem* pEQPlacedItem = groundSpawn.Get<EQPlacedItem>())
	{
		return ToGameObject(*pEQPlacedItem);
	}

	return MQGameObject();
}

MQGameObject ToGameObject(const SPAWNINFO* pSpawn)
{
	MQGameObject temp;

	if (pSpawn)
	{
		temp.type = eGameObjectType::Spawn;
		temp.id = pSpawn->SpawnID;
		temp.name = pSpawn->Name;

		temp.y = pSpawn->Y;
		temp.x = pSpawn->X;
		temp.z = pSpawn->Z;
		temp.heading = pSpawn->Heading;
		temp.displayName = pSpawn->DisplayedName;
		temp.velocityY = pSpawn->SpeedY;
		temp.velocityX = pSpawn->SpeedX;
		temp.velocityZ = pSpawn->SpeedZ;
		temp.height = pSpawn->AvatarHeight * StateHeightMultiplier(pSpawn->StandState);
		temp.actor = (CActorInterface*)&pSpawn->mActorClient;
		temp.valid = true;
	}

	return temp;
}

MQGameObject ToGameObject(float y, float x, float z)
{
	MQGameObject temp;

	temp.type = eGameObjectType::Location;
	temp.name = "location";
	temp.y = y;
	temp.x = x;
	temp.z = z;
	temp.valid = true;

	return temp;
}

MQGameObject ToGameObject(const EQSwitch* pSwitch)
{
	MQGameObject temp;

	temp.type = eGameObjectType::Switch;
	temp.id = pSwitch->ID;
	temp.name = pSwitch->Name;
	temp.y = pSwitch->Y;
	temp.x = pSwitch->X;
	temp.z = pSwitch->Z;
	temp.heading = pSwitch->Heading;
	temp.actor = pSwitch->pActor;
	temp.valid = true;

	return temp;
}

void SetSwitchTarget(EQSwitch* pSwitch)
{
#pragma warning(suppress: 4996)
	pDoorTarget = pSwitch;
	pSwitchTarget = pSwitch;
}

EQSwitch* GetSwitchByID(int ID)
{
	for (int Count = 0; Count < pSwitchMgr->NumEntries; Count++)
	{
		EQSwitch* pSwitch = pSwitchMgr->Switches[Count];

		if (pSwitch->ID == ID)
		{
			return pSwitch;
		}
	}

	return nullptr;
}

EQSwitch* FindSwitchByName(const char* szName)
{
	if (!pSwitchMgr)
		return nullptr;

	EQSwitch* closestSwitch = nullptr;
	float cDistance = FLT_MAX;

	for (int Count = 0; Count < pSwitchMgr->NumEntries; Count++)
	{
		EQSwitch* pSwitch = pSwitchMgr->Switches[Count];

		// Match against the name if it is within the z filter (or if the z filter is disabled)
		if ((!szName || szName[0] == 0 || ci_find_substr(pSwitch->Name, szName) == 0)
			&& (gZFilter >= 10000.0f || (pSwitch->Z <= pLocalPlayer->Z + gZFilter && pSwitch->Z >= pLocalPlayer->Z - gZFilter)))
		{
			float Distance = Get3DDistanceSquared(pLocalPlayer->X, pLocalPlayer->Y, pLocalPlayer->Z,
				pSwitch->X, pSwitch->Y, pSwitch->Z);
			if (Distance < cDistance)
			{
				closestSwitch = pSwitch;
				cDistance = Distance;
			}
		}
	}

	return closestSwitch;
}

//----------------------------------------------------------------------------

std::set<HMODULE> g_knownModules;
std::vector<std::string> s_launcherExtras;
static wchar_t s_macroQuestDirW[MAX_PATH] = { 0 };

bool IsMacroQuestModule(HMODULE hModule, bool getMacroQuestModules)
{
	if (g_knownModules.count(hModule))
		return getMacroQuestModules;

	if (s_macroQuestDirW[0] == 0)
	{
		::GetModuleFileNameW(ghModule, s_macroQuestDirW, MAX_PATH);
		PathCchRemoveFileSpec(s_macroQuestDirW, MAX_PATH);
	}

	// Get the path to this module and then check if it is in the same folder as
	// our main module.

	wchar_t szModulePath[MAX_PATH];
	::GetModuleFileNameW(hModule, szModulePath, MAX_PATH);

	if (getMacroQuestModules)
	{
		if (ci_find_substr(szModulePath, s_macroQuestDirW) == 0)
		{
			g_knownModules.insert(hModule);
			return true;
		}
	}
	else if (ci_find_substr(szModulePath, s_macroQuestDirW) == -1)
	{
		return true;
	}

	return false;
}

static void UpdateLauncherExtras()
{
	std::vector<std::string> keys = GetPrivateProfileKeys("LauncherExtras", internal_paths::MQini);
	s_launcherExtras.clear();

	std::transform(keys.begin(), keys.end(), std::back_inserter(s_launcherExtras), [](const std::string& key)
		{
			auto path = std::filesystem::path(GetPrivateProfileString("LauncherExtras", key.c_str(), "", internal_paths::MQini));
			if (path.has_filename())
				return path.filename().string();

			return std::string();
		});

	s_launcherExtras.erase(
		std::remove_if(s_launcherExtras.begin(), s_launcherExtras.end(),
			[](const std::string& extra) { return extra.empty(); }), s_launcherExtras.end());
}

static bool IsLauncherExtra(std::string_view path)
{
	std::string basename = std::filesystem::path(path).filename().string();

	if (std::find_if(s_launcherExtras.begin(), s_launcherExtras.end(),
		[&basename](const std::string& extra) -> bool
		{
			return ci_equals(basename, extra);
		}) != s_launcherExtras.end())
	{
		return true;
	}

	static std::vector<std::string_view> s_otherNames = {
		"MacroQuest",
		"MQ2",
		"MySEQ",
		"ShowEQ",
		"EQBC",
		"RedGuides",
		"MMOBugs",
		"EQEmu",
		"\\ida.exe"
	};

	for (std::string_view otherName : s_otherNames)
	{
		if (ci_find_substr(path, otherName) != -1)
		{
			return true;
		}
	}

	return false;
}

bool IsMacroQuestProcess(std::string_view path, bool getMacroQuestProcesses)
{
	if (s_macroQuestDirW[0] == 0)
	{
		::GetModuleFileNameW(ghModule, s_macroQuestDirW, MAX_PATH);
		PathCchRemoveFileSpec(s_macroQuestDirW, MAX_PATH);
	}

	std::wstring wpath = mq::utf8_to_wstring(path);
	int substr_pos = ci_find_substr(wpath, s_macroQuestDirW);

	bool inList = IsLauncherExtra(path);
	return !getMacroQuestProcesses ? (substr_pos == -1 && !inList) : (substr_pos == 0 || inList);
}

bool IsMacroQuestProcess(DWORD dwProcessID, bool getMacroQuestProcesses)
{
	wil::unique_process_handle hProcess(::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, dwProcessID));
	if (hProcess)
	{
		char process_name[MAX_PATH] = "";
		DWORD size = MAX_PATH;

		if (!QueryFullProcessImageNameA(hProcess.get(), 0, process_name, &size))
		{
			return false;
		}

		return IsMacroQuestProcess(process_name, getMacroQuestProcesses);
	}

	return false;
}

bool IsModuleSubstring(HMODULE hModule, std::wstring_view searchString)
{
	if (searchString.empty()) return true;

	wchar_t szModulePath[MAX_PATH];
	::GetModuleFileNameW(hModule, szModulePath, MAX_PATH);

	return ci_find_substr(szModulePath, searchString) != -1;
}

bool GetFilteredModules(HANDLE hProcess, HMODULE* hModule, DWORD cb, DWORD* lpcbNeeded,
	const std::function<bool(HMODULE)>& filter)
{
	BOOL result = ((BOOL(WINAPI*)(HANDLE, HMODULE*, DWORD, DWORD*))__ModuleList)(hProcess, hModule, cb, lpcbNeeded);

	if (result)
	{
		DWORD size = std::min(cb, *lpcbNeeded);

		auto a1 = hModule;
		auto a2 = hModule + (size / sizeof(HMODULE));     // end of items
		auto a3 = hModule + (cb / sizeof(HMODULE));       // end of container

		auto iter = std::remove_if(a1, a2, [&filter](HMODULE hModule) { return filter(hModule); });
		if (iter != a2)
		{
			a2 = iter;
			*lpcbNeeded = static_cast<DWORD>(std::distance(a1, a2)) * sizeof(HMODULE);
			std::fill(a2, a3, nullptr);
		}
	}

	return result;
}

bool GetFilteredProcesses(DWORD* lpidProcess, DWORD cb, DWORD* lpcbNeeded, const std::function<bool(std::string_view)>& filter)
{
	BOOL result = ((BOOL(WINAPI*)(DWORD*, DWORD, DWORD*))__ProcessList)(lpidProcess, cb, lpcbNeeded);

	if (result)
	{
		DWORD size = std::min(cb, *lpcbNeeded);

		auto a1 = lpidProcess;
		auto a2 = lpidProcess + (size / sizeof(DWORD));
		auto a3 = lpidProcess + (cb / sizeof(DWORD));
		UpdateLauncherExtras();

		auto iter = std::remove_if(a1, a2, [&filter](DWORD lpidProcess)
			{
				if (lpidProcess == 0)
					return false;

				wil::unique_process_handle hProcess(::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, lpidProcess));
				if (hProcess)
				{
					char process_name[MAX_PATH] = "";
					DWORD size = MAX_PATH;

					if (QueryFullProcessImageNameA(hProcess.get(), 0, process_name, &size))
					{
						return filter(process_name);
					}
				}

				return true;
			});

		if (iter != a2)
		{
			a2 = iter;
			*lpcbNeeded = static_cast<DWORD>(std::distance(a1, a2)) * sizeof(DWORD);
			std::fill(a2, a3, 0);
		}
	}

	return result;
}

std::string GetProcessName(DWORD processID)
{
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processID);
	if (hProcess != NULL)
	{
		char process_name[MAX_PATH] = "";
		DWORD size = MAX_PATH;
		BOOL result = QueryFullProcessImageNameA(hProcess, 0, process_name, &size);

		CloseHandle(hProcess);

		return std::string(process_name);
	}

	return "";
}

const char* GetTeleportName(DWORD id)
{
	DWORD TableSize = *(DWORD*)Teleport_Table_Size;
	tp_coords* tp = (tp_coords*)Teleport_Table;

	if (id < TableSize)
	{
		DWORD zoneId = tp[id].ZoneId & 0x7fff;

		return GetShortZone(zoneId);
	}

	return "UNKNOWN";
}

MembershipLevel GetMembershipLevel()
{
	FreeToPlayClient& client = FreeToPlayClient::Instance();

	return client.MembershipLevel;
}

std::string GetCurrentUI()
{
	if (pEQSuiteTextureLoader)
	{
		const std::string CurrentUI = pEQSuiteTextureLoader->UIPath[cUIDirectory].data();
		if (CurrentUI.length() > 2)
		{
			std::error_code ec;
			if (std::filesystem::is_directory(fmt::format("{}\\{}", mq::internal_paths::EverQuest, CurrentUI), ec))
			{
				const std::size_t rpos = CurrentUI.rfind('\\', CurrentUI.length() - 2);
				if (rpos != std::string::npos)
				{
					return CurrentUI.substr(rpos + 1, CurrentUI.length() - rpos - 2);
				}
			}
		}
	}
	return "Default";
}

void FormatBytes(char* szBuffer, size_t bufferLength, uint64_t bytes)
{
	if (bytes < 1024)
	{
		sprintf_s(szBuffer, bufferLength, "%d Bytes", static_cast<int>(bytes));
	}
	else if (bytes < 1024 * 1024)
	{
		sprintf_s(szBuffer, bufferLength, "%.2f KB", static_cast<float>(bytes) / 1024);
	}
	else if (bytes < 1024 * 1024 * 1024)
	{
		sprintf_s(szBuffer, bufferLength, "%.2f MB", static_cast<float>(bytes) / (1024 * 1024));
	}
	else
	{
		sprintf_s(szBuffer, bufferLength, "%.2f GB", static_cast<float>(bytes) / (1024 * 1024 * 1024));
	}
}

} // namespace mq
