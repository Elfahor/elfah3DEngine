#include "CApp.h"

int CApp::OnExecute()
{
	if (OnInitialize() == false)
	{
		return -1;
	}

	SDL_Event event;

	while (Running)
	{
		while (SDL_PollEvent(&event))
		{
			OnEvent(&event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}