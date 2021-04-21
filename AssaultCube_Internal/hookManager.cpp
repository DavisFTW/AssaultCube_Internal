#include "hookManager.h"

funcT::t_wglSwapBuffers funcO::o_wglSwapBuffers;
funcT::t_doDamage funcO::o_doDamage;

hookManager::hookManager()
{
	
}

hookManager::~hookManager()
{
}

void hookManager::initHooks(EAThook& eatInstance)
{
	//openGL_begin
	DWORD hk_wglSwapBuffersAddr = reinterpret_cast<DWORD>(&hookedFunctions::hk_WglSwapBuffers);
	DWORD openGLModule = (DWORD)GetModuleHandleA("opengl32.dll");

	originalWglSwapBuffersPtr = eatInstance.functionByAddress(openGLModule, "wglSwapBuffers");
	funcO::o_wglSwapBuffers = reinterpret_cast<funcT::t_wglSwapBuffers>(eatInstance.EATHook(openGLModule, originalWglSwapBuffersPtr, hk_wglSwapBuffersAddr));
	//openGL_end

	//doDamage_begin
	DWORD hk_doDamageWrapperAddr = reinterpret_cast<DWORD>(&doDamageWrapper);

	funcO::o_doDamage = reinterpret_cast<funcT::t_doDamage>(detour::trampHook32((BYTE*)0x429C20, (BYTE*)doDamageWrapper, 6));  //#FIXME: store the doDamage original address another way :-)
	//doDamage_end

	//wndProc_begin
	//HWND hwnd = FindWindow(0, L"AssaultCube");
	//wndProcHook::oWndProc = SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)wndProcHook::WndProc);
	//std::cout << GetLastError() << std::endl;
}

void hookManager::initUnhook(EAThook& eatInstance)
{

	//openGL_begin
	DWORD openGLModule = (DWORD)GetModuleHandleA("opengl32.dll");
	DWORD originalWglFunction = (DWORD)funcO::o_wglSwapBuffers;
	
	eatInstance.EATUnhook(openGLModule, originalWglSwapBuffersPtr, originalWglFunction);

	//openGL_end

	//doDamage_begin
	// TODO: implement unhooking for doDamage
	//doDamage_end

}

