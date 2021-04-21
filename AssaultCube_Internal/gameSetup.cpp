#include "gameSetup.h"

gameSetup::gameSetup()
{
	localPlayerPtr = reinterpret_cast<std::uintptr_t*>(gameAddress::localPlayer);
}

int gameSetup::getHealth()
{
	int* health = reinterpret_cast<int*>(*localPlayerPtr + 0xf8);
	return *health;
}

void gameSetup::getPlayerData(playerDataClass*& playerDataClassObject)
{
	playerDataClassObject = reinterpret_cast<playerDataClass*>(*localPlayerPtr);

	std::cout << "your health = " << playerDataClassObject->health << std::endl;
}

