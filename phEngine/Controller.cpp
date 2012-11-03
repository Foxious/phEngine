#include "stdafx.h"
#include <float.h>
#include "Controller.h"

#define MIN_INPUT 4000 // to catch minor fuzz as you approach 0 on the stick

// HELPERS ////////////////////////////////////////////////////////////////////
float QueryStickPosition(int input)
{
	return input < MIN_INPUT && input > -MIN_INPUT ? 0.0f : input / 32767.0f;
}

// PUBLIC /////////////////////////////////////////////////////////////////////
XboxController::~XboxController()
{
	Poll();
	if (IsConnected())
	{
		Vibrate();
	}
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
void XboxController::Poll()
{
	memset(&mState, 0, sizeof(XINPUT_STATE));
	mIsConnected = XInputGetState(mPlayerID, &mState) == ERROR_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////
float XboxController::ThumbLX()
{
	if (IsConnected())
	{
		return QueryStickPosition(mState.Gamepad.sThumbLX);
	}
	return 0.0f;
}

///////////////////////////////////////////////////////////////////////////////
float XboxController::ThumbLY()
{
	if (IsConnected())
	{
		return QueryStickPosition(mState.Gamepad.sThumbLY);
	}

	return 0.0f;
}