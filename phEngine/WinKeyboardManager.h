#ifndef WIN_KB_MANAGER_H
#define WIN_KB_MANAGER_H

#include "DeviceState.h"

void PrepState(DeviceState* outState);
void PollKeyboard(DeviceState* outState);

#endif