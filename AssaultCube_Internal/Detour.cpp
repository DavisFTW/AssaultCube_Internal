#include "Detour.h"

errno_t memcpyTest;

BYTE srcBackup;

BYTE detour::Detour32(BYTE* src, BYTE* dst, const std::uintptr_t len, bool hookFunction)
{
	DWORD oldProtection = 0;

	if (len < 5) return false; 
	
	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &oldProtection); 

	std::uintptr_t relativeAddr = dst - src - 5;  

	srcBackup = *src;

	if (hookFunction == true)
	{
		*src = 0xE9;

		//srcCopy = *reinterpret_cast<std::uintptr_t*>(src + 1);  
		*reinterpret_cast<std::uintptr_t*>(src + 1) = relativeAddr;

		//*src = srcBackup;
		//*reinterpret_cast<std::uintptr_t*>(src + 1) = bullshit;
		
	}
	else
	{
		*src = srcBackup;
		*reinterpret_cast<std::uintptr_t*>(src + 1) = memcpyTest;
	}

	VirtualProtect(src, len, oldProtection, 0);


	return true;

}

BYTE* detour::trampHook32(BYTE* src, BYTE* dst, const std::uintptr_t len)
{
	if (len < 5) return 0;

	//create GATEWAY
	BYTE* gateway = reinterpret_cast<BYTE*>(VirtualAlloc(0, len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));  

	//write stolen bytes to the gateawy

	memcpyTest = memcpy_s(gateway, len, src, len);
	// Get the gateway to destination address

	std::uintptr_t gatewayRelativeAddr = src - gateway - 5;

	// add the jmp opcode to the end of the gateway
	*(gateway + len) = 0xE9;

	// this stays as C code since its not looking to good with reinterpret_cast<>
	*(std::uintptr_t*)((std::uintptr_t)gateway + len + 1) = gatewayRelativeAddr;

	if(!detour::Detour32(src, dst, len, true)) return 0;

	return gateway;
}


void detour::trampUnhook32(BYTE* src, BYTE* dst, BYTE* gateway, const std::uintptr_t len)
{
	if (len > 5)
	{
		VirtualFree(gateway, len, MEM_DECOMMIT);
		detour::Detour32(src, dst, len, false);
	}

}

/*
void detour::UnDetour32(BYTE* src, BYTE* dst, BYTE memBackup, std::uintptr_t srcCopy, const std::uintptr_t len)
{
	DWORD oldProtection = 0;

	if (len > 5)
	{
		VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &oldProtection);

		*src = memBackup;

		*reinterpret_cast<std::uintptr_t*>(src + 1) = srcCopy;

		VirtualProtect(src, len, oldProtection, 0);
	}
}

*/