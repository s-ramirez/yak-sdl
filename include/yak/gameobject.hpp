#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include <yak/managers/texture.hpp>
#include <yak/internal/transform.hpp>
#include <yak/components/component.hpp>

namespace Yak
{
    class GameObject
    {
    public:
        GameObject(int priority = 1000);
        ~GameObject();

        void Init();
        void Update(float dt);
        void Render();

        void AddComponent(Component *cpt);
        void RemoveComponent(Component *cpt);
        std::weak_ptr<Component> GetComponent(Types type);

        int priority;
        SDL_Texture *texture;
        SDL_Rect src_rect, dest_rect;
        Transform transform;

    private:
        std::vector<std::shared_ptr<Component>> components;
        bool initialized;
    };
}
