#include <yak/components/animation.hpp>

using namespace Yak;

Animation::Animation(GameObject &parent, SDL_Texture *sprite, int sprite_row, int frame_count, int anim_speed, SDL_RendererFlip flip)
    : Component(parent), sprite(sprite), sprite_row(sprite_row), frame_count(frame_count), anim_speed(anim_speed), flip(flip) {}

void Animation::Update(float dt)
{
    sprite_frame = (SDL_GetTicks() / anim_speed) % frame_count;
}

void Animation::Render(int x, int y, int sprite_width, int sprite_height)
{
    TextureManager::DrawFrame(sprite, x, y, sprite_width, sprite_height, sprite_row, sprite_frame, flip);
}
