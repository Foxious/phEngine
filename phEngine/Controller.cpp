#include "stdafx.h"
#include <float.h>
#include "Controller.h"

#include "InputManager.h"

#define MIN_INPUT 4000 // to catch minor fuzz as you approach 0 on the stick

// HELPERS ////////////////////////////////////////////////////////////////////
float QueryStickPosition(int input)
{
	return input < MIN_INPUT && input > -MIN_INPUT ? 0.0f : input / 32767.0f;
}

///////////////////////////////////////////////////////////////////////////////
void MapXInputToState(const XINPUT_GAMEPAD* xinput, DeviceState* state)
{
	std::vector<unsigned char>& buttons = state->buttons;
	std::vector<float>& axes = state->axes;
	for (int i = 0; i < 14; ++i)
	{
		buttons[i] = buttons[i] >> 1;
		buttons[i] |= ((xinput->wButtons >> i) & 1) << 1;
	}
	axes[0] = xinput->bLeftTrigger / 255.0f;
	axes[1] = xinput->bRightTrigger / 255.0f;

	axes[2] = QueryStickPosition(xinput->sThumbLX);
	axes[3] = QueryStickPosition(xinput->sThumbLY);
	axes[4] = QueryStickPosition(xinput->sThumbRX);
	axes[5] = QueryStickPosition(xinput->sThumbRY);
}

// PUBLIC /////////////////////////////////////////////////////////////////////
XboxController::~XboxController()
{
}

///////////////////////////////////////////////////////////////////////////////
void XboxController::PrepDeviceState(DeviceState* state)
{
	state->buttons.resize(14);
	state->axes.resize(6);
}

///////////////////////////////////////////////////////////////////////////////
void XboxController::Vibrate(int leftVal, int rightVal)
{
	XINPUT_VIBRATION vibration;
	memset(&vibration, 0, sizeof(XINPUT_VIBRATION));

	vibration.wLeftMotorSpeed = leftVal;
	vibration.wRightMotorSpeed = rightVal;

	XInputSetState(mPlayerID, &vibration);
}

///////////////////////////////////////////////////////////////////////////////
void XboxController::Poll(DeviceState* state)
{
	memset(&mState, 0, sizeof(XINPUT_STATE));
	mIsConnected = XInputGetState(mPlayerID, &mState) == ERROR_SUCCESS;
	MapXInputToState(&mState.Gamepad, state);
}