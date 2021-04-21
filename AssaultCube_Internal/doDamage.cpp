#include <Windows.h>
#include "hookManager.h"

int __stdcall hookedFunctions::doDamage(int weaponIndex, int dynamicPlayerAddr, int Damage)
{
    //FIXME: add some sort of a localplayer check 
    std::cout << "----------------------------------" << std::endl;
    std::cout << "weaponIndex            = " << weaponIndex << std::endl;
    std::cout << "dynamic player address = " << dynamicPlayerAddr << std::endl;
    std::cout << "Damage                 = " << Damage << std::endl;
    std::cout << "----------------------------------" << std::endl;

    return (weaponIndex, dynamicPlayerAddr, Damage);
}

__declspec(naked) void doDamageWrapper(int weaponIndex, int dynamicPlayerAddr, int Damage)
{

    std::cout << "----------------------------------" << std::endl;
    std::cout << "weaponIndex            = " << weaponIndex << std::endl;
    std::cout << "dynamic player address = " << dynamicPlayerAddr << std::endl;
    std::cout << "Damage                 = " << Damage << std::endl;
    std::cout << "----------------------------------" << std::endl;
   
    __asm
    {
        push ebp
        mov ebp, esp
        push Damage
        push dynamicPlayerAddr
        push weaponIndex
        call hookedFunctions::doDamage
        leave
        ret
    }
}