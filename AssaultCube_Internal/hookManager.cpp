#include "hookManager.h"

funcT::t_wglSwapBuffers funcO::o_wglSwapBuffers;

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
	funcO::o_wglSwapBuffers = reinterpret_cast<t_wglSwapBuffers>(eatInstance.EATHook(openGLModule, originalWglSwapBuffersPtr, hk_wglSwapBuffersAddr));
	//openGL_end

}

void hookManager::initUnhook(EAThook& eatInstance)
{
	DWORD openGLModule = (DWORD)GetModuleHandleA("opengl32.dll");
	DWORD moduleTest = (DWORD)funcO::o_wglSwapBuffers;
	//eatInstance.EATUnhook(openGLModule, originalWglSwapBuffersPtr, moduleTest);
	eatInstance.EATUnhook(openGLModule, originalWglSwapBuffersPtr, moduleTest);
}


