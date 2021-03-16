#pragma once
#include <iostream>
#include "globalAddressess.h"


struct Vector3
{
	float x, y, z;
};
class playerDataClass
{
public:
	char pad_0000[52]; //0x0000
	Vector3 cordinates; //0x0034
	char pad_0040[8]; //0x0040
	Vector3 viewAngles; //0x0048
	char pad_0054[164]; //0x0054
	int32_t health; //0x00F8
	int32_t armor; //0x00FC
	char pad_0100[20]; //0x0100
	int32_t secondaryExtra; //0x0114
	char pad_0118[16]; //0x0118
	int32_t primaryExtra; //0x0128
	char pad_012C[16]; //0x012C
	int32_t secondaryClip; //0x013C
	char pad_0140[16]; //0x0140
	int32_t primaryClip; //0x0150
	char pad_0154[4]; //0x0154
	int32_t grenade_count; //0x0158
	char pad_015C[16116]; //0x015C
}; //Size: 0x4050


class gameSetup
{
private:
	std::uintptr_t* localPlayerPtr;
public:
	gameSetup();   // we get localPlayer as soon as our gameSetup is constructed, since it wont be changing
	std::uintptr_t* getLocalPtr() { return localPlayerPtr; }
	int getHealth();
	void getLocalData(playerDataClass*& playerDataClassObject);
};

