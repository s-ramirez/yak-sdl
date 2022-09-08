#include <yak/entity.h>
#include <yak/managers/texture.h>

using namespace Yak;

Entity::Entity(const char *sprite_path, int xpos, int ypos)
{
    texture = TextureManager::LoadTexture(sprite_path);

    x = xpos;
    y = ypos;
}

void Entity::Update()
{
    // x++;
    // y++;

    src_rect.h = 24;
    src_rect.w = 24;
    src_rect.x = 0;
    src_rect.y = 0;

    dest_rect.x = x;
    dest_rect.y = y;
    dest_rect.w = src_rect.w * 2;
    dest_rect.h = src_rect.h * 2;
}

void Entity::Render()
{
    int res = SDL_RenderCopy(Game::renderer, texture, &src_rect, &dest_rect);
    if (res != 0)
    {
        std::cout << SDL_GetError() << std::endl;
    }
}