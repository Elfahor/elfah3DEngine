#include "CApp.h"

CApp::CApp()
{
	Running = true;
	window = NULL;
	renderer = NULL;
	renderer3d = &Renderer3D(800, 600, 0.001, 1000, 90);
	renderer3d->scene = Scene();
	renderer3d->scene.AddMesh(&Mesh());
}

bool CApp::OnInitialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	
	if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &window, &renderer) != 0)
	{
		std::cout << "Error at creating window: " << SDL_GetError() << std::endl;
		return false;
	}
	SDL_SetWindowTitle(window, "Elfah's 3D");

	return true;
}

void CApp::OnEvent(SDL_Event* event)
{
	if (event->type == SDL_QUIT)
	{
		Running = false;
		return;
	}
}

void CApp::OnLoop()
{

}

void CApp::OnRender()
{
	SDL_RenderClear(renderer);

	renderer3d->Render(renderer);

	SDL_RenderPresent(renderer);
}

void CApp::OnCleanup()
{
	renderer = NULL;
	window = NULL;
	SDL_Quit();
}
