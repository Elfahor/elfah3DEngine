#ifndef CAPP_H
#define CAPP_H

#include <SDL.h>
#include <iostream>
#include <Rendering/Renderer3D.h>

class CApp
{
private:
	bool Running;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Renderer3D* renderer3d;
public:
	CApp();
	int OnExecute();

private:
	bool OnInitialize();
	void OnEvent(SDL_Event* event);
	void OnLoop();
	void OnRender();
	void OnCleanup();
};

#endif // CAPP_H
