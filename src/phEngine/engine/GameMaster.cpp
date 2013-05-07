#include "stdafx.h"
#include "GameMaster.h"

#include "Component.h"

int GameMaster::Run()
{
	// pH TODO - strip this of windows specific code.
	MSG msg;
	msg.message = WM_NULL;

	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);
	float secsPerCnt = 1.0f / (float)cntsPerSec;

	__int64 prevTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage( &msg, 0, 0, 0, PM_REMOVE ))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			__int64 currTimeStamp = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);
			float dt = (currTimeStamp - prevTimeStamp) * secsPerCnt;

			Update(dt);
			renderer->DrawScene();

			prevTimeStamp = currTimeStamp;
		}
	}
	return (int)msg.wParam;
}

void GameMaster::Update(float dt)
{
	std::vector<Component*>::iterator it = components.begin();
	std::vector<Component*>::iterator end = components.end();
	for (; it != end; ++it)
	{
		(*it)->Update(dt);
	}

	renderer->Update(dt);
}

void GameMaster::RegisterComponent(Component* component)
{
	component->SetGameMaster(this);
	components.push_back(component);
}
