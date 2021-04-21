#pragma 
#include <Windows.h>
#include <iostream>
namespace wndProcHook
{
	extern LONG_PTR oWndProc;
	extern bool keyListener[256];
	LRESULT __stdcall WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}
