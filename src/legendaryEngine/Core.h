#include <memory>
#include <sr1/memory>
#include <list>
#include <SDL2/SDL.h>
#include <rend/rend.h>
#include "GL/glew.h"

using namespace rend;

class Entity;

/**
 * Represents the Core of the Engine
 * Everything runs through this class including the game loop
 */
class Core {
private:
	bool running;///<boolean to continue running program in Update() loop
	std::list<std::shared_ptr<Entity>> Entities_List; ///<list of shared pointers of type Entity
	std::weak_ptr<Core> self;///<Weak pointer of Core pointing at itself.
	std::sr1::shared_ptr<Context> context;///<Shared pointer to container of object's data
	SDL_Window *window;///<Variable name for SDL Window. Used in the Initialize function to create a window
public:
	~Core();
	/**
	  * \breif Main loop of this program.
	  * Updates and displays game objects/Entities.
	  */
	void UpdateCore();
	/**
	  * \breif Used to return running status to caller.
	  * Used in Update() loop for knowing, if program should continue to run
	  */
	bool returnCoreStatus() { return running; };
	/**
	  * \breif Accessor to boolean running. Sets value for running.
	  */
	void setCoreStatus(bool _status) { running = _status; }
	/**
	  * \breif Initialize the Engine
	  * Upon initializing, core creates a SDL window
	  */
	static std::shared_ptr<Core> initialize();
	/**
	  * \brief This function adds a pointer to the entity object to the list of entities
	  */
	std::shared_ptr<Entity> addEntity();
	/**
	  * \brief Returns data of object to caller.
	  */
	std::sr1::shared_ptr<Context> getContext();
};

