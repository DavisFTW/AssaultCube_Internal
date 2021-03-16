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

void gameSetup::getLocalData(playerDataClass*& playerDataClassObject)
{
	playerDataClassObject = reinterpret_cast<playerDataClass*>(*localPlayerPtr);
}

