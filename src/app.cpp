#include "hdd/app.h"

using namespace ARL;

App::App()
{
	ticks = 0;
	gamestate = -1;
}

void App::Render()
{
	SDL_RenderClear(renderer);
	for (int i = 0; i < img_manager.textures[img_manager.DEBUG].size(); i++)
	{
		SDL_RenderCopy(renderer, img_manager.textures[img_manager.DEBUG][i], NULL, NULL);
	}
	SDL_RenderPresent(renderer);
}

void App::Inputs()
{
	//inputs
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			running = false;
		}
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
				case SDLK_q:
					running = false;
					break;
				case SDLK_w:
					break;
				case SDLK_s:
					break;
			}
		}
	}
}

void App::Start()
{

	if (SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
		printf("SDL could not be initialised! Error: %s\n", SDL_GetError());
	}


	// INIT WINDOW
	window = SDL_CreateWindow("default", 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, 
			SCREEN_HEIGHT, 
			SDL_WINDOW_SHOWN | SDL_RENDERER_PRESENTVSYNC);

	if (window == NULL)
	{
		printf("SDL window could not be created! Error: %s\n", SDL_GetError() ); 
		return;
	}

	// INIT RENDERER
	renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED);
		
	if (renderer == NULL)
	{
		printf("SDL renderer could not be created! Error: %s\n", SDL_GetError());
		return;
	}
	
	img_manager = IMG_Manager(renderer);

	while (running) {
		//rendering
		Render();
		//inputs
		Inputs();
	}
	
	SDL_DestroyWindow(window);

	SDL_Quit();
}
