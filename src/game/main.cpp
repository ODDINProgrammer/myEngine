#include <iostream>
#include "tempComponent.h"
#include <stdlib.h>

int main()
{
	std::shared_ptr<Core> defaultCore = Core::initialize();
	std::shared_ptr<Entity> defaultEntity = defaultCore->addEntity();
	std::shared_ptr<TempComponent> defaultComponent = defaultEntity->addComponent<TempComponent>();

	defaultCore->start();
	system("PAUSE");
  return 0;
};