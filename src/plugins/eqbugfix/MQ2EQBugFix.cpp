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

#include <mq/Plugin.h>

PreSetup("MQ2EQBugFix");

// Avoid a buffer over-read in CUnSerializeBuffer::GetString. This function will call strlen on
// a network message that may already have been read to the end, resulting in a buffer over-read.
// In some cases this will read past the end of the page boundary. If this happens, and the next
// page isn't allocated, this will result in a crash. The fix is to use strnlen instead, so that
// the strlen call is properly bounds checked.
// As of the 5/21/2020 live patch, this happens occasionally when receiving guild names, regardless
// of if MQ2 is loaded.
#define HAS_CUNSERIALIZEBUFFER_BUG IS_CLIENT_DATE(20200521)

// Not exactly sure when this issue first appeared, but it only happens in the live client. This is
// a bad condition that improperly casts a window pointer to another polymorphic type without checking
// if it is safe. This results in reading memory beyond the end of the structure. In most cases this
// goes unnoticed because there is more memory adjacent and it just reads junk. In rare cases this will
// read beyond the end of a mapped page and trigger a segmentation fault. This patches the code to
// remove the read.
//
// To make things even more interesting, the reads are inconsequential - likely remnants of debug code.
// Additionally, these reads are inside a __try block, giving the indication that somebody may have tried
// to cover this case in a clumsy way. However note, that it is _not_ any __except, only a __finally, which
// contains a block of code that writes a message about handling an error. Unfortunately, no error is ever
// handled, as there is no __except handler block, and so a read error here propogates and kills the program.
// Since this code is inside a __try block, we can use the exception handling data to locate the bytes to
// patch. We only need the offset of the function.
#define HAS_DESTROYALLWINDOWS_BUG IS_CLIENT_DATE(20221207)

// There exists a race condition where a label might refer to an item by its location, and it does not validate
// that this item still exists when it tries to render the label's string. If the item is deleted, the label
// will end up getting a null item back from the location, and it still tries to render it. So we clear out
// the field if the item location is set and the item does not exist.
#define HAS_LABEL_CASTINGDATA_BUG 1

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//

#if HAS_CUNSERIALIZEBUFFER_BUG
// This class implementation is specifically for the bug fix.
class CUnSerializeBuffer_BugFix
{
	const char* m_buffer = nullptr;
	uint32_t    m_length = 0;
	uint32_t    m_offset = 0;

public:
	DETOUR_TRAMPOLINE_DEF(bool, GetString_Trampoline, (char* dest, unsigned int destSize))
	bool GetString_Detour(char* dest, unsigned int destSize)
	{
		// Use our own implementation which does not have the bug.
		uint32_t size = (uint32_t)strnlen(m_buffer + m_offset, m_length - m_offset) + 1;
		uint32_t readAmount = std::min(static_cast<uint32_t>(destSize) - 1, size);

		if (m_offset + readAmount > m_length)
		{
			*dest = 0;
			return false;
		}

		memcpy(dest, m_buffer + m_offset, readAmount);
		dest[readAmount] = 0;
		m_offset += size;
		return true;
	}
};
#endif // HAS_CUNSERIALIZEBUFFER_BUG

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//

#if HAS_DESTROYALLWINDOWS_BUG

#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")

struct UNWIND_INFO {
	uint8_t Version : 3;
	uint8_t Flags : 5;
	uint8_t SizeOfProlog;
	uint8_t CountOfCodes;
	uint8_t FrameRegister : 4;
	uint8_t FrameOffset : 4;
	uint16_t UnwindCode[1];
};

struct C_SCOPE_TABLE {
	uint32_t Count;
	struct
	{
		uint32_t BeginAddress;
		uint32_t EndAddress;
		uint32_t HandlerAddress;
		uint32_t JumpTarget;
	} ScopeRecord[1];
};

#define GetUnwindCodeEntry(info, index) \
    ((info)->UnwindCode[index])

#define GetLanguageSpecificDataPtr(info) \
    ((void*)&GetUnwindCodeEntry((info),((info)->CountOfCodes + 1) & ~1))

#define GetExceptionHandler(base, info) \
    ((PEXCEPTION_ROUTINE)((base) + *(uint32_t*)GetLanguageSpecificDataPtr(info)))

#define GetExceptionDataPtr(info) \
    ((void*)((uint32_t*)GetLanguageSpecificDataPtr(info) + 1))

class DestroyAllWindows_BugFix_Handler
{
	enum { CopyByteSize = 10 };

public:
	DestroyAllWindows_BugFix_Handler() {}
	~DestroyAllWindows_BugFix_Handler() {}

	void Install()
	{
		if (m_applied)
			return;

		auto [baseAddress, runtimeFunction] = GetRuntimeFunctionInfo(CXWndManager__DestroyAllWindows);
		if (runtimeFunction && baseAddress)
		{
			UNWIND_INFO* pUnwindInfo = (UNWIND_INFO*)(baseAddress + runtimeFunction->UnwindInfoAddress);

			// We include some validation to ensure that nothing has changed out from under us. If something changes
			// here, the bug fix may no longer be necessary, or it may need to be adjusted.
			if (pUnwindInfo->CountOfCodes == 8 && pUnwindInfo->Flags == UNW_FLAG_UHANDLER)
			{
				C_SCOPE_TABLE* scopeTable = (C_SCOPE_TABLE*)GetExceptionDataPtr(pUnwindInfo);
				if (scopeTable->Count == 2)
				{
					uint8_t* sourceAddress = (uint8_t*)(baseAddress + scopeTable->ScopeRecord[1].BeginAddress);

					// 80 B9 ?? ?? ?? ?? ??  cmp     byte ptr[rcx + 34Ah], 0
					// 74 ??                 jz      short loc_1405383A4
					if (sourceAddress[0] == 0x80 && sourceAddress[1] == 0xB9 && sourceAddress[7] == 0x74)
					{
						// Create new bytes
						uint8_t newData[CopyByteSize];
						memcpy(newData, sourceAddress, CopyByteSize);

						// Modify bytes into a sequence of nops and a jmp rel8
						for (int z = 0; z <= 6; z++)
							newData[z] = 0x90; // nop

						newData[7] = 0xEB; // JMP rel8 to replace the JZ rel8

						m_patchedAddress = (uintptr_t)sourceAddress;
						
						AddPatch(m_patchedAddress, newData, CopyByteSize, nullptr, "DestroyAllWindows_BugFix");
						m_applied = true;
						return;
					}
				}
			}
		}

		WriteChatf("\ar[EQBugFix]\ax Failed to apply DestroyAllWindows bug fix");
	}

	void Remove()
	{
		if (m_applied)
		{
			RemovePatch(m_patchedAddress);

			m_applied = false;
			m_patchedAddress = 0;
		}
	}

private:
	static std::tuple<uintptr_t, RUNTIME_FUNCTION*> GetRuntimeFunctionInfo(uintptr_t functionAddress)
	{
		// store the base address the loaded Module
		HMODULE hModule = GetModuleHandle(0);
		uint8_t* dllImageBase = (uint8_t*)hModule; //suppose hModule is the handle to the loaded Module (.exe or .dll)

		// get the address of NT Header
		IMAGE_NT_HEADERS* pNtHdr = ImageNtHeader(hModule);

		// after Nt headers comes the table of section, so get the addess of section table
		IMAGE_SECTION_HEADER* pSectionHdr = (IMAGE_SECTION_HEADER*)(pNtHdr + 1);

		RUNTIME_FUNCTION* pData = nullptr;

		// iterate through the list of all sections, and check the section name in the if conditon. etc
		for (int i = 0; i < pNtHdr->FileHeader.NumberOfSections; i++)
		{
			char* name = (char*)pSectionHdr->Name;
			if (memcmp(name, ".pdata", 6) == 0)
			{
				pData = (RUNTIME_FUNCTION*)(dllImageBase + pSectionHdr->VirtualAddress);
				break;
			}
			pSectionHdr++;
		}

		if (!pData)
			return {};

		// Search the RUNTIME_FUNCTION data for our function
		uintptr_t rva = functionAddress - (uintptr_t)dllImageBase;

		while (pData->BeginAddress != 0)
		{
			if (pData->BeginAddress == rva)
			{
				return { (uintptr_t)dllImageBase, pData };
			}
			pData++;
		}

		return {};
	}

	bool m_applied = false;
	uintptr_t m_patchedAddress = 0;
};

DestroyAllWindows_BugFix_Handler DestroyAllWindows_BugFix;

#endif // HAS_DESTROYALLWINDOWS_BUG

//============================================================================

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("Initializing MQ2EQBugFix");

#if HAS_CUNSERIALIZEBUFFER_BUG
	EzDetour(CUnSerializeBuffer__GetString, &CUnSerializeBuffer_BugFix::GetString_Detour, &CUnSerializeBuffer_BugFix::GetString_Trampoline);
#endif

#if HAS_DESTROYALLWINDOWS_BUG
	DestroyAllWindows_BugFix.Install();
#endif
}

PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("Shutting down MQ2EQBugFix");

#if HAS_CUNSERIALIZEBUFFER_BUG
	RemoveDetour(CUnSerializeBuffer__GetString);
#endif
#if HAS_DESTROYALLWINDOWS_BUG
	DestroyAllWindows_BugFix.Remove();
#endif
}

PLUGIN_API void OnPulse()
{
	if (gGameState == GAMESTATE_INGAME)
	{
#if HAS_LABEL_CASTINGDATA_BUG
		// If an ItemLocation is set on the CastingData, a Label might try to
		// render its name. If the item doesn't exist, it'll crash.
		if (pLocalPC && pLocalPC->me->CastingData.SpellID != -1)
		{
			if (pLocalPC->me->CastingData.ItemLocation.IsValidIndex()
				&& pLocalPC->GetItemByGlobalIndex(pLocalPC->me->CastingData.ItemLocation) == nullptr)
			{
				pLocalPC->me->CastingData.ItemLocation = ItemGlobalIndex();
			}
		}
#endif
	}
}
