#ifndef IMG_MANAGER
#define IMG_MANAGER

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace ARL{
	
	class IMG_Manager {
		

		SDL_Renderer * renderer;
		SDL_Texture * load_texture(std::string texture);

		public:
		enum rows { DEBUG=0, WORLD=1, CHARACTERS=2, MONSTERS=3 };
		enum columns { ARCH=0 };
		
		std::vector<std::vector<SDL_Texture*>> textures;

		bool load_media();
		// Constructor
		IMG_Manager(SDL_Renderer* ren);
		IMG_Manager();
	};

}

#endif
