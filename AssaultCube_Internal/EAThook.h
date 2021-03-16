#pragma once
#include <iostream>
#include <Windows.h>
#include <winnt.h>
#include <sstream>

class EAThook
{
private:
	IMAGE_OPTIONAL_HEADER* header = new IMAGE_OPTIONAL_HEADER();
	IMAGE_NT_HEADERS* nt_header;
	IMAGE_DOS_HEADER* dos_header;

	 PIMAGE_EXPORT_DIRECTORY exportDirectory = 0;
	 std::uint32_t* exportFunctions = nullptr;
	 std::uint32_t* exportNames	 = nullptr;
	 std::uint16_t* exportOrdinals = nullptr;
	 DWORD oldProtection = 0;

public:

	typedef BOOL(__stdcall* t_wglSwapBuffers)(HDC hdc);    // for wglSwapBuffers hook

	EAThook();
	~EAThook();

	void init(std::uintptr_t moduleBase);
	std::uintptr_t* functionByAddress(DWORD moduleBase, std::string functionName);
	std::uintptr_t EATHook(DWORD moduleBase, std::uintptr_t* pointerToFunction, DWORD cheatFunction);
	void EATUnhook(DWORD moduleBase, std::uintptr_t* pointerToFunction, DWORD function);
	auto getOptionalHeader(IMAGE_NT_HEADERS*& nt_header);
};

