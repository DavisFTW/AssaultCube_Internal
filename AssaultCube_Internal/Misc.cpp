#include "Misc.h"

void miscFunctions::noRecoil()
{
}

void miscFunctions::entityLoop(playerDataClass*& dataClassObject)
{

	//#FIXME: crashes if no other players then local
	//#FIXME: Doesn't iterate through every player

	auto baseClient = reinterpret_cast<std::uintptr_t>(GetModuleHandle(nullptr));
	auto pEntityList = reinterpret_cast<DWORD*>(baseClient + 0x10f4f8);

	for (int i = 4; i < 32; i += 4) // TESTME: do we even need to check entity == 0 ? ?  ? ?  idk it works dont touch pls
	{
		std::cout << "current itiration  = " << i << std::endl;
		auto pEntity = reinterpret_cast<std::uintptr_t*>(*pEntityList + i);
		//dataClassObject = reinterpret_cast<playerDataClass*>(*pEntity);
		

	}
	std::cout << "xd1" << std::endl;
	//auto pEntity = reinterpret_cast<DWORD*>(*pEntityList + 0x4);
	//auto pEntityHealth = reinterpret_cast<DWORD*>(*pEntity + 0xf8);
}

