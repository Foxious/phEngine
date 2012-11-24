#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

enum Devices
{
	X360,
	NUM_DEVICES
};

struct DeviceState
{
	std::vector<bool> buttons;
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