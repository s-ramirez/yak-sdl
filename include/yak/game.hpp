#pragma once
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <yak/managers/texture.hpp>
#include <yak/common.hpp>
#include <iostream>

namespace Yak
{
    class Game
    {
    public:
        Game();
        ~Game();

        void Init(const Config config);
        void HandleEvents();
        void Run();
        void Update();
        void Render();
        void Clean();

        bool Running();

        static SDL_Renderer *renderer;

    private:
        bool game_running;
        Config game_config;

        int frame_delay;
        Uint32 frame_start;
        int frame_time;

        SDL_Window *window;
    };
}