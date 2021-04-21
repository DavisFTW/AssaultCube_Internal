// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <iostream>
#include <winnt.h>
#include <sstream>
#include "gameSetup.h"
#include "EAThook.h"
#include "hookManager.h"
#include "Misc.h"
#include "Detour.h"
namespace utilVars
{
    FILE* file;
}
namespace object
{
    gameSetup game;
    playerDataClass* localData;
    playerDataClass* entityData;
    EAThook eathook;
    hookManager hooks;
}

DWORD WINAPI entry(LPVOID arg)
{
    DWORD oldProtection;
    AllocConsole();
    freopen_s(&utilVars::file, "CONOUT$", "w", stdout);

   
    object::hooks.initHooks(object::eathook);
    object::game.getPlayerData(object::localData);
   // miscFunctions::entityLoop(object::entityData);
    return 0;
}
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserve)

{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);
        auto handle = CreateThread(nullptr, 0, entry, hModule, 0, nullptr);
        if (handle)
            CloseHandle(handle);

    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
