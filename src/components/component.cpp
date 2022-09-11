#include <yak/components/component.hpp>

using namespace Yak;

Component::Component(GameObject &parent) : parent(parent) {}
Component::~Component() {}

void Component::Init() {}