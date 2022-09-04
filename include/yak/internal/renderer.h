#pragma once
#include <iostream>
#include <SDL2_image/SDL_image.h>
#include <yak/common.h>

namespace Yak
{
    class Renderer
    {
    public:
        Renderer();
        void Init(const Config &config);
        void Update();
        void Destroy();
        void Clear();
        void SetRenderer(SDL_Renderer *ren);

        bool DrawImage(SDL_Surface *content, const SDL_Rect &src, const SDL_Rect &dest);

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
    };
}