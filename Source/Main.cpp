#include <SDL.h>

#include "App/CApp.h"

#undef main

int main(int argc, char* argv[])
{
	CApp MainApp;
	return MainApp.OnExecute();
}