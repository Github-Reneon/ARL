#include "hdd/img_manager.h"

using namespace ARL;


//Load texture -> ret pointer to texture -> argument of path to texture
//	will be making a texture atlas in the future, currently is being used to
//	load debug images mostly
//
//	uses the IMG_Load function from the SDL_image library
//	to save it into a surface. surface is turned into a 
//	texture using the SDL_CreateTextureFromSurface function
//	returns null if it can't load the image or create the texture.
SDL_Texture * IMG_Manager::load_texture(std::string texture)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* newSurface = IMG_Load(texture.c_str());

	if (newSurface == NULL)
	{	
		printf("Unable to load image %s. Error: %s\n", texture.c_str(), IMG_GetError());
		return nullptr;
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface (renderer, newSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s. Error: %s\n", texture.c_str(), SDL_GetError());
			return nullptr;
		}
	}

	return newTexture;

}

//load_media -> ruturns bool -> no arguments
//	loads debug textures at the moment. this needs to be rewritten
//	to be more tylesheet centric rather than stupidly loading
//	a bunch of individual images.
//
//	runs the load_texture private method to load the image into a SDL_Texture
//	memory address which is added to a multidimensional array of memory addresses
//	
//	<-- THIS NEEDS TO BE SCRAPPED AND REWRITTEN TO WORK WITH A BETTER IMAGE MANAGEMENT SYSTEM -->
//	

bool IMG_Manager::load_media()
{

	SDL_Texture* newTexture = load_texture("img/arch.jpg");
	SDL_Texture* titleScreen = load_texture("img/title.jpg");
	SDL_Texture* tileSheet = load_texture("img/tilesheet.jpg");
	textures.resize(3);

	if (newTexture == nullptr || titleScreen == nullptr || tileSheet == nullptr)
		return false;
	
	// MISC
	textures[0].resize(textures[0].size() + 2);
	textures[0][ARCH] = newTexture;
	textures[0][TITLE] = titleScreen;
	textures[CHARACTERS].resize(textures[CHARACTERS].size() + 1);
	textures[CHARACTERS][PLAYER] = tileSheet;
	return true;
}

// constructor
// adds the renderer memory address to the class
// inits media pointer arrays

IMG_Manager::IMG_Manager(SDL_Renderer* ren)
{
	renderer = ren;
	load_media();
	printf("Image manager init!");
}

// constructor no args
// does nothing

IMG_Manager::IMG_Manager()
{
}
