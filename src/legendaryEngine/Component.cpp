#include "Component.h"
#include "Entity.h"

void Component::onInit()
{
}
void Component::onBegin()
{

}
void Component::onTick()
{

}
void Component::onDisplay()
{

}

std::shared_ptr<Entity> Component::getEntity()
{
	return std::shared_ptr<Entity>();
}

std::shared_ptr<Core> Component::getCore()
{
	return entity.lock()->getCore();
}


