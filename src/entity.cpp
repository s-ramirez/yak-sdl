#include <yak/entity.h>
#include <yak/components/graphics/sprite.h>
using namespace Yak;

Entity::Entity(const char *sprite_path)
{
    Sprite sprite;
    sprite.Load(sprite_path);
    //  spritesheet = Renderer::DrawImage(, );
}

void Entity::Update()
{
    x = 0;
    y = 0;

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
    // SDL_RenderCopy(renderer, spritesheet, &src_rect, &dest_rect);
}