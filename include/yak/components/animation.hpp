#pragma once
#include <SDL2/SDL.h>
#include <yak/managers/texture.hpp>
#include <yak/components/component.hpp>

namespace Yak
{
    class Animation : public Component
    {
    public:
        Animation(GameObject &parent, const char *file_name, int sprite_row, int frame_count, int anim_speed, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void Init() override;
        void Update(float dt) override;
        void Render() override;
        bool Is(const std::string &type) const override;

        void Render(int x, int y, int sprite_width, int sprite_height);

    private:
        int sprite_row, sprite_frame;
        int anim_speed, frame_count;
        int width, height;
        SDL_RendererFlip flip;
        SDL_Texture *sprite;
    };
}