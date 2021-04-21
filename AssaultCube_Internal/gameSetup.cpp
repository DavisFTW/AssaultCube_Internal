#include "gameSetup.h"

std::uintptr_t* gameSetup::localPlayerPtr = nullptr;

void gameSetup::getPlayerData(playerDataClass*& playerDataClassObject)
{
	localPlayerPtr = reinterpret_cast<std::uintptr_t*>(gameAddress::localPlayer);

	if (localPlayerPtr)
	{
		playerDataClassObject = reinterpret_cast<playerDataClass*>(*localPlayerPtr);

		std::cout << "your health = " << playerDataClassObject->health << std::endl;
		std::cout << (VOID*)*localPlayerPtr << std::endl;
	}
}

