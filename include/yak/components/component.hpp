#pragma once
#include <string>

namespace Yak
{
    class GameObject;

    class Component
    {
    public:
        Component(GameObject &parent);

        virtual ~Component();

        virtual void Init() = 0;
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;
        virtual bool Is(const std::string &type) const = 0;

        bool active;
        bool visible;

    private:
        GameObject &parent;
    };
}