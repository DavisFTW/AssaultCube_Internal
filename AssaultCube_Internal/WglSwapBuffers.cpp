#include <Windows.h>
#include "EATHookManager.h"

BOOL __stdcall hooks::hk_wglSwapBuffers(HDC hdc)
{
	std::cout << "hooked" << std::endl;
	return functionCopies::o_wglSwapBuffers(hdc);
}