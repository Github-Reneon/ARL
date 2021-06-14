#include "hdd/app.h"

using namespace ARL;

// constructor
// no arguments
//
// not much reason for it being here (possible deletion?)
App::App()
{
	turns = 0;
	gamestate = 0;
}

// Render function
//
// Loops through SDL_Textures in the IMG_Manager class to draw the player or the title screen
// depending on the game state.
// called in the game loop
// 
// (temporary implementation)
// an SDL_Rect is generated for player coords and one is generated for texture coords
// and is used in the SDL_RenderCopy function

void App::Render()
{
	SDL_RenderClear(renderer);
	SDL_Rect coords;
	SDL_Rect tex_coords;

	coords.x = x;
	coords.y = y;
	coords.w = 16;
	coords.h = 16;

	tex_coords.x = 0;
	tex_coords.y = 0;
	tex_coords.w = 16;
	tex_coords.h = 16;

	switch (gamestate) {
		case 0:
			SDL_RenderCopy(renderer, img_manager.textures[img_manager.DEBUG][img_manager.TITLE], NULL, NULL);
			break;
		case 1:
			SDL_RenderCopy(renderer, img_manager.textures[img_manager.CHARACTERS][img_manager.PLAYER], &tex_coords, &coords);
			break;
	
	}
	SDL_RenderPresent(renderer);
}

// input management done in the main game loop
//
// polls for an SDL_Event (in the memory address of the e variable)
// to handle input player movement and basic state management are in there
//
// (potentially should make a input manager class?)

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
					{
						y -= 16;
						turns++;
					}
					break;
				case SDLK_s:
					if (gamestate == 1)
					{
						y += 16;
						turns++;
					}
					break;
				case SDLK_a:
					if (gamestate == 1)
					{
						x -= 16;
						turns++;
					}
					break;
				case SDLK_d:
					if (gamestate == 1)
					{
						x += 16;
						turns++;
					}
					break;
			}
		}
	}
}

// Game start
// contains the game loop
// inits SDL2
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
