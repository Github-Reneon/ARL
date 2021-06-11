#include "hdd/img_manager.h"

using namespace ARL;

SDL_Texture * IMG_Manager::load_texture(std::string texture)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* newSurface = IMG_Load(texture.c_str());

	if (newSurface == NULL)
	{
		printf("Unable to load image %s. Error: %s\n", texture.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface (renderer, newSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s. Error: %s\n", texture.c_str(), SDL_GetError());
		}
	}

	return newTexture;

}

bool IMG_Manager::load_media()
{

	SDL_Texture* newTexture = load_texture("img/arch.jpg");

	textures.resize(3);

	if (newTexture == NULL)
		return false;
	
	// MISC
	textures[0].resize(textures[0].size() + 1);
	textures[0][ARCH] = newTexture;

	return true;
}

IMG_Manager::IMG_Manager(SDL_Renderer* ren)
{
	printf("starting correct init\n");
	renderer = ren;
	load_media();
}

IMG_Manager::IMG_Manager()
{
}
