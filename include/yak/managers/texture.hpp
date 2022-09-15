#pragma once
#include <yak/game.hpp>
#include <SDL2_image/SDL_image.h>

namespace Yak
{
	class TextureManager
	{
	public:
		static SDL_Texture *LoadTexture(const char *file_name);
		static int GetTextureDimensions(SDL_Texture *texture, int *width, int *height);
		static void Draw(SDL_Texture *texture, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
		static void DrawFrame(SDL_Texture *texture, int x, int y, int width, int height, int row, int column, SDL_RendererFlip flip = SDL_FLIP_NONE);
	};
}