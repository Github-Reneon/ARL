#ifndef APP
#define APP
#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

namespace ARL {
	class App {

		private:

		// CONSTANT VARS
		const int SCREEN_WIDTH = 1280;
		const int SCREEN_HEIGHT = 720;

		// METADATA
		
		int gamestate;
		int ticks;
		bool running = true;

		// Debug vars
		int iter = 0;
		int colours[3][3] = {
			{ 255, 0, 0},
			{ 0, 255, 0},
			{ 0, 0, 255}
		};
	
		// SDL VARS
		SDL_Window* window = NULL;
		SDL_Surface* surface = NULL;	
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
