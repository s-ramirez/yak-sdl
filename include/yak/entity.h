#pragma once
#include <yak/game.h>
#include <yak/components/component.h>

namespace Yak
{
    class Entity : public Component
    {
    public:
        Entity(const char *spritesheet, int xpos, int ypos);
        ~Entity();

        void Update();
        void Render();

        SDL_Texture *texture;
        SDL_Rect src_rect, dest_rect;
    };
}