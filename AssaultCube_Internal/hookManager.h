#pragma once
#include <Windows.h>
#include "EAThook.h"


class hookManager
{
private:
	// store all the shit we need

public:

	hookManager();
	~hookManager();


	void initHooks();
	void initUnhook();
};

