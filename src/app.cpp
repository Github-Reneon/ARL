#include "hdd/app.h"

using namespace ARL;

App::App()
{
	ticks = 0;
	gamestate = 0;
}

void App::Render()
{
	SDL_RenderClear(renderer);
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.w = 16;
	rect.h = 16;
	

	switch (gamestate) {
		case 0:
			SDL_RenderCopy(renderer, img_manager.textures[img_manager.DEBUG][img_manager.TITLE], NULL, NULL);
			break;
		case 1:
			SDL_RenderCopy(renderer, img_manager.textures[img_manager.DEBUG][img_manager.ARCH], NULL, &rect);
			break;
	
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
				case SDLK_RETURN:
					if (gamestate ==0){
						gamestate = 1;
					}
					break;
				case SDLK_q:
					if (gamestate == 0){ 
						running = false;
					} else {
						gamestate = 0;
					}
					break;
				case SDLK_w:
					if (gamestate == 1)
					y -= 16;
					break;
				case SDLK_s:
					if (gamestate == 1)
					y += 16;
					break;
				case SDLK_a:
					if (gamestate == 1)
					x -= 16;
					break;
				case SDLK_d:
					if (gamestate == 1)
					x += 16;
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
	renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
		
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
