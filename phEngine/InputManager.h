#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

enum Devices
{
	X360,
	NUM_DEVICES
};

enum ButtonStates
{
	BTN_RELEASE = 0x01,
	BTN_DOWN = 0x10,
	BTN_HELD = 0x11,
};

struct DeviceState
{
	std::vector<char> buttons;
	std::vector<float> axes;
};

class InputManager
{
public:
	InputManager();
	void Update(float dt);
	DeviceState* GetDevice(unsigned int deviceID);
private:
	DeviceState devices[NUM_DEVICES];
};

#endif