#include "EAThook.h"

EAThook::EAThook() 
{
}

EAThook::~EAThook()
{
}

auto EAThook::getOptionalHeader(IMAGE_NT_HEADERS*& nt_header)
{
	return &nt_header->OptionalHeader;
}

void EAThook::init(DWORD moduleBase)
{	
	//setup our headers
	dos_header = reinterpret_cast<IMAGE_DOS_HEADER*>(moduleBase);
	nt_header = reinterpret_cast<IMAGE_NT_HEADERS*>(moduleBase + dos_header->e_lfanew);

	// get required information
	exportDirectory = reinterpret_cast<PIMAGE_EXPORT_DIRECTORY>(moduleBase + getOptionalHeader(nt_header)->DataDirectory[0].VirtualAddress);
	exportFunctions = reinterpret_cast<std::uint32_t*>(moduleBase + exportDirectory->AddressOfFunctions);
	exportNames = reinterpret_cast<std::uint32_t*>(moduleBase + exportDirectory->AddressOfNames);
	exportOrdinals = reinterpret_cast<std::uint16_t*>(moduleBase + exportDirectory->AddressOfNameOrdinals);
}

std::uintptr_t* EAThook::functionByAddress(DWORD moduleBase, std::string functionName)
{
	init(moduleBase);
	for (auto i = 0; i < exportDirectory->AddressOfNames; i++)
	{
		if (functionName == reinterpret_cast<char*>(moduleBase + exportNames[i]))
		{
			std::string foundFunction = reinterpret_cast<char*>(moduleBase + exportNames[i]);
			return (std::uintptr_t*)&exportFunctions[exportOrdinals[i]]; 
		}
	}
}

std::uintptr_t EAThook::EATHook(DWORD moduleBase, std::uintptr_t* pointerToFunction, DWORD cheatFunction)
{
	DWORD oldProtection = 0;
	DWORD hkFunctionAddress = cheatFunction - moduleBase; 
	std::uintptr_t functionPointer = 0;
	VirtualProtect(pointerToFunction, 4, PAGE_READWRITE, &oldProtection);

	functionPointer = *pointerToFunction;
	*pointerToFunction = hkFunctionAddress;

	VirtualProtect(pointerToFunction, 4, oldProtection, 0);

	return (moduleBase + functionPointer);   // returns original pointer
}

void EAThook::EATUnhook(DWORD moduleBase, std::uintptr_t* pointerToFunction, DWORD function)
{
	DWORD oldProtection = 0; 
	DWORD originalFunction = function - moduleBase;
	std::uintptr_t functionPointer = 0;
	VirtualProtect(pointerToFunction, 4, PAGE_READWRITE, &oldProtection);

	functionPointer = *pointerToFunction;
	*pointerToFunction = originalFunction;

	VirtualProtect(pointerToFunction, 4, oldProtection, 0);
}

