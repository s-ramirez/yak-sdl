#pragma once
#include <yak/internal/vector2d.hpp>
#include <iostream>

namespace Yak
{
    class Transform
    {
    public:
        int x, y;

        Transform(int px = 0, int py = 0) : x(px), y(py) {}

        // Operations
        inline void TranslateX(int px) { x += px; }
        inline void TranslateY(int py) { y += py; }
        inline void Translate(yak::Vector2D v)
        {
            x += v.x;
            y += v.y;
        }
        void Log(std::string msg = "")
        {
            std::cout << msg << "(" << x << ", " << y << ")" << std::endl;
        }
    };
}