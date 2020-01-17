#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "legendaryEngine/Core.h"
#include "legendaryEngine/Entity.h"
#include "legendaryEngine/MyRenderer.h"
#include "legendaryEngine/Component.h"

int main()
{
	srand(time(NULL));
	std::cout << "Hello, user. How is it going?" << std::endl;
	std::cout << "Please, enter the amount of cats you want to be rendered ";
	int answer;
	std::cin >> answer;
	//Initialize core
	std::shared_ptr<Core> EngineCore = Core::initialize();
	//Create entities 

	for (int i = 0; i < answer; i++)
	{
		//Pick random position and angle
		float x = (rand() % 40) - 20;
		float y = (rand() % 30) - 15;
		float z = -(rand() % 75 + 25);
		float rotation = rand() % 181;
		std::shared_ptr<Entity> CatEntity = EngineCore->addEntity();
		//Create renderer
		std::shared_ptr<legendaryRenderer> CatRenderer = CatEntity->addComponent<legendaryRenderer>();
		//Set Model location, Texture location and set position of the object on the screen
		CatRenderer->SetModel("../Assets/Models/curuthers.obj");
		//Pick a random texture
		int r = rand() % 5;
		switch (r)
		{
		case 0:
			CatRenderer->SetTexture("../Assets/Textures/curuthers.png");
			break;
		case 1:
			CatRenderer->SetTexture("../Assets/Textures/curuthers2.png");
			break;
		case 2:
			CatRenderer->SetTexture("../Assets/Textures/curuthers3.png");
			break;
		case 3:
			CatRenderer->SetTexture("../Assets/Textures/curuthers4.png");
			break;
		case 4:
			CatRenderer->SetTexture("../Assets/Textures/curuthers5.png");
			break;
		default:
			break;
		}

		CatRenderer->SetModelSettings(glm::vec3(x, y, z), rotation);

	}
	//Update core
	EngineCore->UpdateCore();

	return 0;
};