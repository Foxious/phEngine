#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <vector>

// pH TODO - abstract this away
#include "Controller.h"

enum Devices
{
	X360,
	NUM_DEVICES
};

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

class InputManager
{
public:
	InputManager();
	void Update(float dt);
	DeviceState* GetDevice(unsigned int deviceID) { return &devices[deviceID]; }
private:
	DeviceState devices[NUM_DEVICES];
	XboxController controller;
};

class InputMapper
{
public:
	enum ButtonMap
	{
		atkBtn,
		runBtn,
		leftBtn,
		rightBtn,
		upBtn,
		downBtn,

		NUM_BUTTONS
	};

	enum AxisMap
	{
		lrAxis,
		duAxis,

		NUM_AXES
	};

	InputMapper(InputManager* manager)
		: inputManager(manager)
	{
	}

	char GetButtonState(unsigned button);
	float GetAxisState(unsigned axis);

	void BindButton(unsigned button, unsigned device, unsigned buttonToBind);
	void BindAxis(unsigned axis, unsigned device, unsigned axisToBind);

	void Update(float dt);

private:
	InputManager* inputManager;
	unsigned char* buttonMap[NUM_BUTTONS];
	float* axisMap[NUM_AXES];
};

#endif