#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "DeviceState.h"

// pH TODO - abstract this away
#include "Controller.h"
#include "WinKeyboardManager.h"

enum Devices
{
	X360,
	KEYBOARD,
	NUM_DEVICES
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

	InputMapper(InputManager* manager);

	char GetButtonState(unsigned button);
	char GetButtonStateToggle(unsigned button);
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