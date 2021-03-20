#pragma once
#include <Windows.h>
#include "EAThook.h"

namespace hookedFunctions
{
		BOOL __stdcall hk_WglSwapBuffers(HDC hdc);
}
namespace funcT
{
		typedef BOOL(__stdcall* t_wglSwapBuffers)(HDC hdc);
}

namespace funcO	
{
	extern funcT::t_wglSwapBuffers o_wglSwapBuffers;
}
class hookManager
{
private:

		// typedefs for functions
	typedef BOOL(__stdcall* t_wglSwapBuffers)(HDC hdc);

		// wglSwapBuffers variables
	std::uintptr_t* originalWglSwapBuffersPtr;

public:
	static t_wglSwapBuffers o_wglSwapBuffers;
	  
	hookManager();
	~hookManager();


	void initHooks(EAThook& eatInstance);
	void initUnhook(EAThook& eatInstance);

};


/*
int __cdecl hooks::hk_doDamage(int damage, void* pl, void* actor, int gu, bool gib, bool local)
{
	std::cout << "xd" << std::endl;
	damage = 9999;
	return functionCopies::o_doDamage(damage, pl, actor, gu, gib, local);
}
*/
