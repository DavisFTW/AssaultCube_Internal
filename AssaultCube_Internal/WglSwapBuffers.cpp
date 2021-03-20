#include <Windows.h>
#include "hookManager.h"

BOOL __stdcall hookedFunctions::hk_WglSwapBuffers(HDC hdc)
{
	std::cout << "hooked" << std::endl;
	return 	funcO::o_wglSwapBuffers(hdc);
}



