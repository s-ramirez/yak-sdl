#pragma once
#include <yak/components/component.h>

namespace Yak
{
	class Sprite : public Component
	{
	public:
		SDL_Surface *content;
		void Load(const char *file_name);
	};
}