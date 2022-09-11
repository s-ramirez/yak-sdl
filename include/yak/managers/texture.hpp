#pragma once

#include <yak/game.hpp>

namespace Yak
{
	class TextureManager
	{
	public:
		static SDL_Texture *LoadTexture(const char *file_name);
		static void Draw(SDL_Texture *texture, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
		static void DrawFrame(SDL_Texture *texture, int x, int y, int width, int height, int row, int column, SDL_RendererFlip flip = SDL_FLIP_NONE);
	};
}