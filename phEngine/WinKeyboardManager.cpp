#include "stdafx.h"

#include "WinKeyboardManager.h"

#include <Windows.h>

#define FIRST_VKEY	0x08		// first VKey we care about
#define NUM_KEYS	155			// number of keys we care about

void PrepState(DeviceState* outState)
{
	outState->buttons.resize(NUM_KEYS);
}

void PollKeyboard(DeviceState* outState)
{
	for (int i = 0; i < NUM_KEYS; ++i)
	{
		char keyHit = GetAsyncKeyState(i + FIRST_VKEY) ? BTN_DOWN : 0;
		outState->buttons[i] = (outState->buttons[i] >> 1) | keyHit;
	}
}