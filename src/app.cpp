#include "hdd/app.h"

using namespace ARL;

App::App()
{

	ticks = 0;
	gamestate = -1;
}

void App::Render()
{
	surface = SDL_GetWindowSurface (window);
	SDL_FillRect( surface, NULL, SDL_MapRGB(surface->format, 0,0,0 )); 
	SDL_UpdateWindowSurface(window);
	iter++;
	if (iter > 2)
		iter = 0;

	if (running == true)
		std::cout << img_manager.testvec.size() << "\n";		

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
					img_manager.testvec.resize(img_manager.testvec.size() + 1);
					break;
				case SDLK_s:
					if (img_manager.testvec.size() > 0)
					{
						img_manager.testvec.resize(img_manager.testvec.size() - 1);
					}
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

	window = SDL_CreateWindow("default", 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, 
			SCREEN_HEIGHT, 
			SDL_WINDOW_SHOWN | SDL_RENDERER_PRESENTVSYNC);

	if (window == NULL)
	{
		printf("SDL window could not be created! Error: %s\n", SDL_GetError() ); 
	}
	else
	{
		while (running) {
			
			//rendering
			Render();
			//inputs
			Inputs();

		}
	}
	SDL_DestroyWindow(window);

	SDL_Quit();
}
