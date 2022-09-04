#pragma once
#include <yak/entity.h>

namespace Yak
{
    class Component
    {
    public:
        bool active;
        bool visible;

        int x;
        int y;
    };
}