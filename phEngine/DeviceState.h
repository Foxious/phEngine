#ifndef DEVICE_STATE_H
#define DEVICE_STATE_H

#include <vector>

enum ButtonStates
{
	BTN_RELEASE = 0x01,
	BTN_DOWN = 1 << 1,
	BTN_HELD = BTN_DOWN | BTN_RELEASE,
};

struct DeviceState
{
	std::vector<unsigned char> buttons;
	std::vector<float> axes;
};

#endif