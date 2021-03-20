#include "hookManager.h"

funcT::t_wglSwapBuffers funcO::o_wglSwapBuffers;

hookManager::hookManager()
{
	
}

hookManager::~hookManager()
{
}

void hookManager::initHooks(EAThook& eatObject)
{

	//openGL_begin
	DWORD hk_wglSwapBuffersAddr = reinterpret_cast<DWORD>(&hookedFunctions::hk_WglSwapBuffers);
	DWORD openGLModule = (DWORD)GetModuleHandleA("opengl32.dll");
	originalWglSwapBuffersPtr = eatObject.functionByAddress(openGLModule, "wglSwapBuffers");
	funcO::o_wglSwapBuffers = reinterpret_cast<t_wglSwapBuffers>(eatObject.EATHook(openGLModule, originalWglSwapBuffersPtr, hk_wglSwapBuffersAddr));
	//openGL_end

}

void hookManager::initUnhook()
{
}


