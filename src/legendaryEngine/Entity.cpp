#include "Entity.h"
#include "Component.h"

//Loop through list of components and update them
void Entity::tick()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++) 
	{
		(*it)->onTick();
	}
}

//Loop through list of components and put them to the screen 
void Entity::display()
{
	for (std::list<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		(*it)->onDisplay();
	}
}

const std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}
