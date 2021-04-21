#pragma once
#include <Windows.h>
#include <iostream>
namespace detour
{
	bool Detour32(BYTE* src, BYTE* dst, const std::uintptr_t len);
	BYTE* trampHook32(BYTE* src, BYTE* dst, const std::uintptr_t len);
}
