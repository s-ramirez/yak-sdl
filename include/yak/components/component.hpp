#pragma once

namespace Yak
{
    class GameObject;

    enum Types
    {
        Animation
    };

    class Component
    {
    public:
        Component(GameObject &parent);

        virtual ~Component();

        virtual void Init();
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;
        virtual bool Is(Types type) const = 0;

        bool active;
        bool visible;

    private:
        GameObject &parent;
    };
}