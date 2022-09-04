#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <yak/common.h>
#include <yak/internal/renderer.h>

namespace Yak
{
    class Game
    {
    public:
        Game();
        ~Game();

        void init(const Config config);
        void handle_events();
        void run();
        void update();
        void render();
        void clean();

        bool running();

    private:
        bool game_running;
        Config game_config;
        Renderer renderer;

        int frame_delay;
        Uint32 frame_start;
        int frame_time;
    };
}