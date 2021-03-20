#pragma once
#include <iostream>
#include <Windows.h>
#include <winnt.h>
#include <sstream>

class EAThook
{
private:
	IMAGE_OPTIONAL_HEADER* header = new IMAGE_OPTIONAL_HEADER();
	IMAGE_NT_HEADERS* nt_header = nullptr;
	IMAGE_DOS_HEADER* dos_header = nullptr;

	 PIMAGE_EXPORT_DIRECTORY exportDirectory = 0;
	 std::uint32_t* exportFunctions = nullptr;
	 std::uint32_t* exportNames	 = nullptr;
	 std::uint16_t* exportOrdinals = nullptr;

	 auto getOptionalHeader(IMAGE_NT_HEADERS*& nt_header);
	 void init(DWORD moduleBase); // #FIXME: Move this to constructor, since we need it as soon as our object is init...
public:
	EAThook();
	~EAThook();

	std::uintptr_t* functionByAddress(DWORD moduleBase, std::string functionName);
	std::uintptr_t EATHook(DWORD moduleBase, std::uintptr_t* pointerToFunction, DWORD cheatFunction);
	void EATUnhook(DWORD moduleBase, std::uintptr_t* pointerToFunction, DWORD function);
};

