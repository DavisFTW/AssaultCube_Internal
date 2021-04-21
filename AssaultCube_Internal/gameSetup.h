#pragma once
#include <iostream>
#include "globalAddressess.h"



/*  # Offsets #
Player Base:"ac_client.exe"+0x109B74/0x509B74
Player Health:0xF8
Player Primary:0x128
Player Primary Clip:0x150
Player Secondary:0x114
Player SecondaryClip:0x13C
Player Grenade Ammo:0x158
Player Armor:0xFC
Player Position XY:0x4
Player Position XY:0x8
Player Position Z:0xC
Player View Angle Verticle:0x44
Player View Angle Horizontal:0x40
Time Between Knifes:0x160
Pistol Timer:0x164
Primary Timer:0x178
Grenade Timer(?):0x180
Mouse Button Down:0x224
Entity Base:"ac_client.exe"+0x110D90/0x510D90
TeamOffset1:0x204
TeamOffset2:0x32C
*/
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

class offsets
{
public:
	DWORD ViewAngleVer = 0x44;
	DWORD ViewAngleHor = 0x40;
};
namespace gameSetup
{
	extern std::uintptr_t* localPlayerPtr;
	void getPlayerData(playerDataClass*& playerDataClassObject);
}

/*
class gameSetup
{
private:
	std::uintptr_t* localPlayerPtr;
public:
	gameSetup();   // we get localPlayer as soon as our gameSetup is constructed, since it wont be changing
	std::uintptr_t* getLocalPtr() { return localPlayerPtr; }
	int getHealth();
	void getPlayerData(playerDataClass*& playerDataClassObject);
	void localPlayerMods(playerDataClass*& playerDataClassObject);
};
*/
