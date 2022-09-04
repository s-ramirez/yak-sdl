#pragma once
#include <yak/game.h>
#include <yak/components/component.h>

namespace Yak
{
    class Entity
    {
    public:
        Entity(const char *spritesheet);
        ~Entity();

        void Update();
        void Render();

    private:
        int x;
        int y;

        SDL_Rect src_rect, dest_rect;
    };
}