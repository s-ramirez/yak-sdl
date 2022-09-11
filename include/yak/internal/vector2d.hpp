#pragma once
#include <iostream>

namespace yak
{
    class Vector2D
    {
    public:
        float x, y;

        Vector2D(float px = 0, float py = 0) : x(px), y(py) {}
        // Operations
        inline Vector2D operator+(const Vector2D &v2) const
        {
            return Vector2D(x + v2.x, y + v2.y);
        }

        inline Vector2D operator-(const Vector2D &v2) const
        {
            return Vector2D(x - v2.x, y - v2.y);
        }

        inline Vector2D operator*(const float scaler) const
        {
            return Vector2D(x * scaler, y * scaler);
        }

        void Log(std::string msg = "")
        {
            std::cout << msg << "(" << x << ", " << y << ")" << std::endl;
        }
    };
}