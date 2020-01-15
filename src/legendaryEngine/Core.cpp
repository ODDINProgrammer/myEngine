#include "Core.h"
#include "Component.h"
#include "Entity.h"

Core::Core()
{
}

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> core = std::make_shared<Core>();
	return core;
}

void Core::start()
{
	for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		(*it)->tick();
		
	}
	for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		(*it)->display();
	}
	
}

void Core::stop()
{
}

std::shared_ptr<Entity> Core::addEntity()
{
	//initialize 3D Entity before pushing to the list of entities
	std::shared_ptr<Entity> tempEntity = std::make_shared<Entity>();
	tempEntity->self = tempEntity;
	entities.push_back(tempEntity);
	return tempEntity;
}
