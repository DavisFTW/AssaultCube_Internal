#include "Detour.h"

bool detour::Detour32(BYTE* src, BYTE* dst, const std::uintptr_t len)
{
	DWORD oldProtection = 0;

	if (len < 5) return false; // 32 bit minimum jmp size is 5 bytes, this is against errors
	
	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &oldProtection); // change the protection so we can modify it

	std::uintptr_t relativeAddr = dst - src - 5;  // why is this calculated like that?

	*src = 0xE9;   

	//*(std::uintptr_t*)(src + 1) = relativeAddr; // why is this calculated like it is ?
	*reinterpret_cast<std::uintptr_t*>(src + 1) = relativeAddr;

	VirtualProtect(src, len, oldProtection, 0);

	return true;

}

BYTE* detour::trampHook32(BYTE* src, BYTE* dst, const std::uintptr_t len)
{
	if (len < 5) return 0;

	//create GATEWAY
	BYTE* gateway = reinterpret_cast<BYTE*>(VirtualAlloc(0, len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));  

	//write stolen bytes to the gateawy

	memcpy_s(gateway, len, src, len);
	// Get the gateway to destination address

	std::uintptr_t gatewayRelativeAddr = src - gateway - 5;

	// add the jmp opcode to the end of the gateway
	*(gateway + len) = 0xE9;

	//write the adress of the gateway to jmp

	// this stays as C code since its not looking to good with reinterpret_cast<>
	*(std::uintptr_t*)((std::uintptr_t)gateway + len + 1) = gatewayRelativeAddr;

	if(!detour::Detour32(src, dst, len)) return 0;

	return gateway;
}
