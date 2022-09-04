#include <yak/internal/renderer.h>

using namespace Yak;

Renderer::Renderer()
{
}

void Renderer::Init(const Config &config)
{
    int flags = 0;

    if (config.fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(config.name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.width, config.height, flags);
    if (window)
    {
        std::cout << "Window created..." << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        std::cout << "Render created..." << std::endl;
    }
}

bool Renderer::DrawImage(SDL_Surface *content, const SDL_Rect &src, const SDL_Rect &dest)
{

    SDL_Texture *t = SDL_CreateTextureFromSurface(renderer, content);
    bool success = true;

    if (t != NULL)
    {
        if (SDL_RenderCopy(renderer, t, &src, &dest) != 0)
        {
            success = false;
        }

        SDL_DestroyTexture(t);
    }
    else
    {
        success = false;
    }

    return success;
}

void Renderer::Clear()
{
    SDL_RenderClear(renderer);
}

void Renderer::Update()
{
    SDL_RenderPresent(renderer);
}

void Renderer::Destroy()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}