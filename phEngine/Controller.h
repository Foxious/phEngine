#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Windows.h>
#include <XInput.h>

#pragma comment(lib, "XInput.lib")

class XboxController
{
public:
	XboxController(unsigned int playerID) : mPlayerID(playerID) {}
	~XboxController();
	inline bool IsConnected() { return mIsConnected; }
	void Vibrate(int leftval =0, int rightval = 0);

	float ThumbLX();
	float ThumbLY();

	void Poll();

private:
	XINPUT_STATE mState;
	int mPlayerID;
	bool mIsConnected;

};


#endif
