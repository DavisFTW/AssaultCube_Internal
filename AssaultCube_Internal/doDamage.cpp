#include <Windows.h>
#include "hookManager.h"

int __stdcall hookedFunctions::doDamage(int weaponIndex, int dynamicPlayerAddr, int Damage)
{
    if (dynamicPlayerAddr == *gameSetup::localPlayerPtr)
    {
        std::cout << "----------------------------------" << std::endl;
        std::cout << "weaponIndex            = " << weaponIndex << std::endl;
        std::cout << "dynamic player address = " << dynamicPlayerAddr << std::endl;
        std::cout << "Damage                 = " << Damage << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }

    return (weaponIndex, dynamicPlayerAddr, Damage);
}

__declspec(naked) void doDamageWrapper(int weaponIndex, int dynamicPlayerAddr, int Damage)
{ 
    __asm
    {
        push ebp
        mov ebp, esp // causes Damage to be ruined
        push Damage
        push dynamicPlayerAddr
        push weaponIndex
        call hookedFunctions::doDamage
        leave
        ret
    }
}