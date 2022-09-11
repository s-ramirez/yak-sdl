#include <yak/gameobject.hpp>

using namespace Yak;

GameObject::GameObject(int priority) : priority(priority), initialized(false) {}

GameObject::~GameObject()
{
    components.clear();
}

void GameObject::Init()
{
    std::for_each(
        components.begin(),
        components.end(),
        [](std::shared_ptr<Component> &cpt)
        { cpt->Init(); });
    initialized = true;
}

void GameObject::Update(float dt)
{
    std::for_each(
        components.begin(),
        components.end(),
        [&](std::shared_ptr<Component> &cpt)
        { cpt->Update(dt); });
}

void GameObject::Render()
{
    std::for_each(
        components.begin(),
        components.end(),
        [](std::shared_ptr<Component> &cpt)
        { cpt->Render(); });
}

void GameObject::AddComponent(Component *cpt)
{
    components.emplace_back(cpt);
    if (initialized)
    {
        cpt->Init();
    }
}

void GameObject::RemoveComponent(Component *cpt)
{
    auto found = std::find_if(
        components.begin(),
        components.end(),
        [&](std::shared_ptr<Component> &cpt2)
        { return cpt2.get() == cpt; });

    if (found != components.end())
    {
        components.erase(found);
    }
}

std::weak_ptr<Component> GameObject::GetComponent(Types type)
{
    auto found = std::find_if(
        components.begin(),
        components.end(),
        [&](std::shared_ptr<Component> &cpt)
        { return cpt->Is(type); });

    if (found == components.end())
    {
        return std::weak_ptr<Component>();
    }

    return std::weak_ptr<Component>(*found);
}