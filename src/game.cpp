#include <yak/game.h>

using namespace Yak;

namespace
{
    SDL_Texture *playerTex;
    SDL_Rect srcR, destR;
}

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const Config c)
{
    game_config = c;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL Initialized..." << std::endl;
        renderer.Init(game_config);
        game_running = true;
        if (game_config.OnInit != nullptr)
        {
            game_config.OnInit();
        }
    }
}

void Game::run()
{
    frame_delay = 1000 / game_config.target_fps;

    while (game_running)
    {
        frame_start = SDL_GetTicks();

        handle_events();
        update();
        render();

        frame_time = SDL_GetTicks() - frame_start;

        if (frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }
}

void Game::handle_events()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        game_running = false;
        break;

    default:
        break;
    }
}

void Game::update()
{

    destR.h = 24;
    destR.w = 24;

    if (game_config.OnUpdate != nullptr)
    {
        game_config.OnUpdate();
    }
}

void Game::render()
{
    renderer.Clear();
    renderer.Update();
}

void Game::clean()
{
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

bool Game::running()
{
    return game_running;
}