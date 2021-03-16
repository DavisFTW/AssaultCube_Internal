#pragma once
#include <Windows.h>
#include <iostream>
#include "EAThook.h"
#include "gameSetup.h"

namespace hooks
{
	extern BOOL __stdcall hk_wglSwapBuffers(HDC hdc);
	extern int __cdecl hk_doDamage(int damage, void* pl, void* actor, int gu, bool gib, bool local);
	extern void inithooks(EAThook& eatObject);
	extern void initunhook(EAThook& eatObject);
}

namespace hookTemplates
{
	typedef BOOL(__stdcall* t_wglSwapBuffers)(HDC hdc);
	typedef int(__cdecl* t_doDamage)(int damage, void* pl, void* actor, int gu, bool gib, bool local);
}

struct funcPointers
{
	std::uintptr_t* wglSwapBuffers;
	std::uintptr_t* WGLCurrentPtr;
};
