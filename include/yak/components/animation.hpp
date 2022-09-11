#pragma once
#include <SDL2/SDL.h>
#include <yak/managers/texture.hpp>
#include <yak/components/component.hpp>

namespace Yak
{
    class Animation : public Component
    {
    public:
        Animation(GameObject &parent, SDL_Texture *spritesheet, int sprite_row, int frame_count, int anim_speed, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void Render(int x, int y, int sprite_width, int sprite_height);
        void Init() override;
        void Update(float dt) override;
        bool Is(Types type) const override;

    private:
        int sprite_row, sprite_frame;
        int anim_speed, frame_count;
        SDL_RendererFlip flip;
        SDL_Texture *sprite;
    };
}