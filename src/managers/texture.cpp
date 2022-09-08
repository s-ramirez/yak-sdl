#include <yak/managers/texture.h>

using namespace Yak;

SDL_Texture *TextureManager::LoadTexture(const char *file_name)
{
	SDL_Surface *content = IMG_Load(file_name);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, content);
	SDL_FreeSurface(content);
	return tex;
}