#include "EATHookManager.h"
/// <summary>
///  TODO: move all hook functions to seperate files
///  TODO: store all pointers etc so they can be accessed later
///	 TODO: FIX ALL #FIXME: 
/// </summary>

funcPointers funcPointer;
namespace functionCopies
{
	hookTemplates::t_wglSwapBuffers o_wglSwapBuffers;
	hookTemplates::t_doDamage o_doDamage;
}

/*
BOOL __stdcall hooks::hk_wglSwapBuffers(HDC hdc)
{
	std::cout << "hooked" << std::endl;
	return functionCopies::o_wglSwapBuffers(hdc);
}

int __cdecl hooks::hk_doDamage(int damage, void* pl, void* actor, int gu, bool gib, bool local)
{
	std::cout << "xd" << std::endl;
	damage = 9999;
	return functionCopies::o_doDamage(damage, pl, actor, gu, gib, local);
}
*/

void hooks::inithooks(EAThook& eatObject)
{
	// addresses to our functions
	DWORD hk_wglSwapBuffersAddr = reinterpret_cast<DWORD>(&hk_wglSwapBuffers); //#FIXME: this is not required make it so &hk_wglSwapBuffers can be passed in straight as argument and not converted to DWORD ? not sure if possible ? 

	// get modules
	DWORD openGLModule = (DWORD)GetModuleHandleA("opengl32.dll");

	// pointers
	funcPointer.wglSwapBuffers = reinterpret_cast<std::uintptr_t*>(eatObject.functionByAddress(openGLModule, "wglSwapBuffers"));
	
	// hook
	functionCopies::o_wglSwapBuffers = reinterpret_cast<hookTemplates::t_wglSwapBuffers>(eatObject.EATHook(openGLModule, funcPointer.wglSwapBuffers, hk_wglSwapBuffersAddr));
	
}


void hooks::initunhook(EAThook& eatObject)
{
	DWORD openGLModule = (DWORD)GetModuleHandleA("opengl32.dll");
	DWORD moduleTest = (DWORD)functionCopies::o_wglSwapBuffers;
	eatObject.EATUnhook(openGLModule, funcPointer.wglSwapBuffers, moduleTest);
	//eatObject.EATUnhook(openGLModule, funcPointer.wglSwapBuffers, funcPointer.WGLCurrentPtr);
}


