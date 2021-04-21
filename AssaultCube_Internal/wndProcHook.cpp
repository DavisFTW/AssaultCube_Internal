#include "wndProcHook.h"

LONG_PTR wndProcHook::oWndProc = 0;
bool wndProcHook::keyListener[256] = {};

LRESULT __stdcall wndProcHook::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	std::cout << "wndProc xd " << std::endl;
	MessageBox(0, L"test", L"test!", MB_OK);
	/*
	switch (uMsg) // Each keystroke will PostMessage with uMsg down and wParam the key.
	{
	case WM_LBUTTONDOWN:
		wndProcHook::keyListener[VK_LBUTTON] = true;
		break;
	case WM_LBUTTONUP:
		wndProcHook::keyListener[VK_LBUTTON] = false;
		break;
	case WM_RBUTTONDOWN:
		wndProcHook::keyListener[VK_RBUTTON] = true;
		break;
	case WM_RBUTTONUP:
		wndProcHook::keyListener[VK_RBUTTON] = false;
		break;
	case WM_MBUTTONDOWN:
		wndProcHook::keyListener[VK_MBUTTON] = true;
		break;
	case WM_MBUTTONUP:
		wndProcHook::keyListener[VK_MBUTTON] = false;
		break;
	case WM_XBUTTONDOWN:
	{
		if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1)
		{
			wndProcHook::keyListener[VK_XBUTTON1] = true;
		}
		else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON2)
		{
			wndProcHook::keyListener[VK_XBUTTON2] = true;
		}
		break;
	}
	case WM_XBUTTONUP:
	{
		if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1)
		{
			wndProcHook::keyListener[VK_XBUTTON1] = false;
		}
		else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON2)
		{
			wndProcHook::keyListener[VK_XBUTTON2] = false;
		}
		break;
	}
	case WM_KEYDOWN:
		wndProcHook::keyListener[wParam] = false;
		break; 
	case WM_KEYUP:
		wndProcHook::keyListener[wParam] = false;
		break;
	default:
		break;
	}

	*/
	return CallWindowProcW((WNDPROC)wndProcHook::oWndProc, hwnd, uMsg, wParam, lParam);
}
