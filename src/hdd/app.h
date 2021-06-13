#ifndef APP
#define APP
#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#include "img_manager.h"

namespace ARL {
	class App {

		private:

		// CONSTANT VARS
		const int SCREEN_WIDTH = 854;
		const int SCREEN_HEIGHT = 480;

		// METADATA
		
		int gamestate = -1;
		int ticks;
		bool running = true;
		
		IMG_Manager img_manager;

		// Debug vars
		int iter = 0;
		int colours[3][3] = {
			{ 255, 0, 0},
			{ 0, 255, 0},
			{ 0, 0, 255}
		};
		
		int x = 0;
		int y = 0;

		// SDL VARS
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;	
		SDL_Event e;

		// Private methods
		void Render();
		void Inputs();

		public:

		App();
		void Start();
	};
	
}


#endif
