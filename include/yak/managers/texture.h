#pragma once
#include <yak/game.h>

namespace Yak
{
	class TextureManager
	{
	public:
		static SDL_Texture *LoadTexture(const char *file_name);
	};
}