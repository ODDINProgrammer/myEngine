#include "Core.h"
#include "Component.h"
#include "Entity.h"

#include <ctime>

const int Window_W = 1280;
const int Window_H = 720;

Core::~Core()
{
	//On program shutdown, make sure to clean everything 
	//Clear entities list
	Entities_List.clear();
	//Set context to null
	context = 0;
	//Destroy window and quit program
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Core::UpdateCore()
{
	SDL_Event event = { 0 };
	while (returnCoreStatus() == true)
	{
		//Check for the events 
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
		//Draw background

		glClearColor(0, 0.6, 0.4, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Loop through entity list and update them
		for (std::list<std::shared_ptr<Entity>>::iterator it = Entities_List.begin(); it != Entities_List.end(); it++)
		{
			(*it)->tick();

		}

		//Loop through entity list and put them on the screen
		for (std::list<std::shared_ptr<Entity>>::iterator it = Entities_List.begin(); it != Entities_List.end(); it++)
		{
			(*it)->display();
		}
		//Render updated window
		SDL_GL_SwapWindow(window);
	}
}

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> core = std::make_shared<Core>();
	//set running to true, to keep updating the game
	//core->setCoreStatus(true);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	//Creating SDL window 
	core->window = SDL_CreateWindow("GO GO POWER CURUTHERS!",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		Window_W, Window_H, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	//Check if something went wrong 
	if (!SDL_GL_CreateContext(core->window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	core->context = rend::Context::initialize();

	core->self = core;
	core->setCoreStatus(true);
	return core;
}

//Add entity to entity list
std::shared_ptr<Entity> Core::addEntity()
{
	//Creating pointer to entity and storying this pointer in list of entities 
	std::shared_ptr<Entity> _entity = std::make_shared<Entity>();
	_entity->self = _entity;
	_entity->core = self;
	Entities_List.push_back(_entity);
	return _entity;
}

std::sr1::shared_ptr<rend::Context> Core::getContext()
{
	return context;
}
