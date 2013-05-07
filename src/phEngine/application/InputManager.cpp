#include "stdafx.h"
#include "InputManager.h"

#include "assert.h"


// PUBLIC ///////////////////////////////////////////////////////////////////////////////
InputManager::InputManager()
	: controller(0)
{
	controller.PrepDeviceState( &devices[X360] );
	PrepState( &devices[KEYBOARD] );
}

/////////////////////////////////////////////////////////////////////////////////////////
void InputManager::Update(float dt)
{
	controller.Poll( &devices[X360] );
	PollKeyboard( &devices[KEYBOARD] );
}

/// INPUT MAPPER ////////////////////////////////////////////////////////////////////////
InputMapper::InputMapper(InputManager* manager)
	: inputManager(manager)
{
	for (int i = 0; i < NUM_BUTTONS; ++i)
	{
		buttonMap[i] = 0;
	}

	for (int i = 0; i < NUM_AXES; ++i)
	{
		axisMap[i] = 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
char InputMapper::GetButtonState(unsigned button)
{
	return buttonMap[button] == 0 ? 0 : *buttonMap[button];
}

/////////////////////////////////////////////////////////////////////////////////////////
char InputMapper::GetButtonStateToggle(unsigned button)
{
	return buttonMap[button] == 0 ? 0 : (*buttonMap[button]) >> 1;
}

/////////////////////////////////////////////////////////////////////////////////////////
float InputMapper::GetAxisState(unsigned axis)
{
	return axisMap[axis] == 0 ? 0.0f : *axisMap[axis];
}

/////////////////////////////////////////////////////////////////////////////////////////
void InputMapper::BindButton(unsigned button, unsigned device, unsigned buttonToBind)
{
	assert(button < NUM_BUTTONS);
	buttonMap[button] = &inputManager->GetDevice(device)->buttons[buttonToBind];
}

/////////////////////////////////////////////////////////////////////////////////////////
void InputMapper::BindAxis(unsigned axis,unsigned device, unsigned axisToBind)
{
	assert(axis < NUM_AXES);
	axisMap[axis] = &inputManager->GetDevice(device)->axes[axisToBind];
}

/////////////////////////////////////////////////////////////////////////////////////////
void InputMapper::Update(float dt)
{
	inputManager->Update(dt);
}