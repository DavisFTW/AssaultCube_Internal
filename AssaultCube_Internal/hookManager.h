#pragma once
#include <Windows.h>
#include "EAThook.h"
#include "wndProcHook.h"
#include "Detour.h"

void  doDamageWrapper(int weaponIndex, int dynamicPlayerAddr, int Damage);

namespace hookedFunctions
{
		BOOL __stdcall hk_WglSwapBuffers(HDC hdc);
		int __stdcall doDamage(int weaponIndex, int dynamicPlayerAddr, int damage);
}
namespace funcT
{
		typedef BOOL(__stdcall* t_wglSwapBuffers)(HDC hdc);
		typedef int(__cdecl* t_doDamage)(int weaponIndex, int dynamicPlayerAddr, int damage);
}

namespace funcO	
{
	extern funcT::t_wglSwapBuffers o_wglSwapBuffers;
	extern funcT::t_doDamage o_doDamage;
}
class hookManager
{
private:

	std::uintptr_t* originalWglSwapBuffersPtr;

public:

	hookManager();
	~hookManager();

	void initHooks(EAThook& eatInstance);
	void initUnhook(EAThook& eatInstance);

};
