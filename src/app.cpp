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
	SDL_FillRect( surface, NULL, SDL_MapRGB(surface->format, colours[iter][0], colours[iter][1], colours[iter][2] ) );
	SDL_UpdateWindowSurface(window);
	iter++;
	if (iter > 2)
		iter = 0;

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
		time_t current_time = NULL;
		time_t end_frame_time = NULL;
		while (running) {
			
			if (current_time != NULL && end_frame_time != NULL)
			{
				double diff = difftime(end_frame_time, current_time);
				printf("%f\n", diff * 1000);
			}
			//get current time
			time(&current_time);
			//rendering
			Render();
			//inputs
			Inputs();

			SDL_Delay(100);
			time(&end_frame_time);
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
}
