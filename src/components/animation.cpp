#include <yak/components/animation.hpp>

using namespace Yak;

Animation::Animation(GameObject &parent, const char *file_name, int sprite_row, int frame_count, int anim_speed, SDL_RendererFlip flip)
    : Component(parent), sprite_row(sprite_row), frame_count(frame_count), anim_speed(anim_speed), flip(flip)
{
    sprite = TextureManager::LoadTexture(file_name);
    TextureManager::GetTextureDimensions(sprite, &width, &height);
}

void Animation::Init()
{
}

void Animation::Update(float dt)
{
    sprite_frame = (SDL_GetTicks() / anim_speed) % frame_count;
}

void Animation::Render(int x, int y, int sprite_width, int sprite_height)
{
    TextureManager::DrawFrame(sprite, x, y, sprite_width, sprite_height, sprite_row, sprite_frame, flip);
}

void Animation::Render()
{
    Render(0, 0, width, height);
}

bool Animation::Is(const std::string &type) const
{
    return type == std::string("Animation");
}