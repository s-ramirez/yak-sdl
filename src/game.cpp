#include <yak/game.hpp>

using namespace Yak;

SDL_Renderer *Game::renderer = nullptr;

Game::Game()
{
}

void Game::Init(const Config c)
{
    game_config = c;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL Initialized..." << std::endl;

        int flags = 0;

        if (game_config.fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        window = SDL_CreateWindow(game_config.name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game_config.width, game_config.height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer)
        {
            int res = SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            if (res != 0)
            {
                std::cout << "Eroor setting color" << std::endl;
                std::cout << SDL_GetError() << std::endl;
            }
            else
            {
                std::cout << "Render created..." << std::endl;
            }

            if (game_config.OnInit != nullptr)
            {
                game_config.OnInit();
            }
            game_running = true;
        }
    }
}

void Game::Run()
{
    frame_delay = 1000 / game_config.target_fps;

    while (game_running)
    {
        frame_start = SDL_GetTicks();

        HandleEvents();
        Update();
        Render();

        frame_time = SDL_GetTicks() - frame_start;

        if (frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }
}

void Game::HandleEvents()
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

void Game::Update()
{
    if (game_config.OnUpdate != nullptr)
    {
        game_config.OnUpdate();
    }
}

void Game::Render()
{
    SDL_RenderClear(renderer);
    if (game_config.OnRender != nullptr)
    {
        game_config.OnRender();
    }
    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

bool Game::Running()
{
    return game_running;
}