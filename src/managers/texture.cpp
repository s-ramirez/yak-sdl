#include <yak/managers/texture.hpp>

using namespace Yak;

SDL_Texture *TextureManager::LoadTexture(const char *file_name)
{
	SDL_Surface *content = IMG_Load(file_name);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, content);
	SDL_FreeSurface(content);
	return tex;
}

int TextureManager::GetTextureDimensions(SDL_Texture *texture, int *width, int *height)
{
	int return_code = SDL_QueryTexture(texture, nullptr, nullptr, width, height);
	if (return_code != 0)
	{
		throw std::runtime_error(IMG_GetError());
	}
	return return_code;
}

void TextureManager::Draw(SDL_Texture *texture, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect src_rect = {0, 0, width, height};
	SDL_Rect dest_rect = {x, y, width, height};
	int res = SDL_RenderCopyEx(Game::renderer, texture, &src_rect, &dest_rect, 0, nullptr, flip);
	if (res != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}
}

void TextureManager::DrawFrame(SDL_Texture *texture, int x, int y, int width, int height, int row, int column, SDL_RendererFlip flip)
{
	SDL_Rect src_rect = {width * column, height * row, width, height};
	SDL_Rect dest_rect = {x, y, width, height};
	int res = SDL_RenderCopyEx(Game::renderer, texture, &src_rect, &dest_rect, 0, nullptr, flip);
	if (res != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}
}