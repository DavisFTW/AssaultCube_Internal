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

	//static functionT::t_wglSwapBuffers o_wglSwapBuffers;

	void initHooks(EAThook& eatObject);
	void initUnhook();

};
