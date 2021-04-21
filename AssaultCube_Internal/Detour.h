#pragma once
#include <Windows.h>
#include <iostream>
namespace detour
{
	BYTE  Detour32(BYTE* src, BYTE* dst, const std::uintptr_t len, bool hookStatus);

	BYTE* trampHook32(BYTE* src, BYTE* dst, const std::uintptr_t len);
	void trampUnhook32(BYTE* src, BYTE* dst, BYTE* gateway, const std::uintptr_t len);
}
