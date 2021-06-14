#ifndef OBJECT
#define OBJECT

#include <SDL2/SDL.h>
#include <string>

namespace ARL {
	class Object {
		
		private:

		std::string name;
		std::string description;
		
		public:
		
		int x;
		int y;
		int location_id;
		SDL_Texture* texture;

		//setters and getters
		std::string* Get_Name();
		void Set_Name(std::string new_name);
		
		std::string* Get_Description();
		void Set_Description(std::string new_description);
		void Mod_Description(std::string description_mod);
	};
}

#endif
