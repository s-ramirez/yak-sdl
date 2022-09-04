#include <yak/components/graphics/sprite.h>

using namespace Yak;

void Sprite::Load(const char *file_name)
{
	content = IMG_Load(file_name);
}