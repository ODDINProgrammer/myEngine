#include <memory>
#include <list>

class Keyboard;
class Entity;
class Environment;
class Resources;

class Core {
private:
	bool running;
	std::shared_ptr<Keyboard> keyboard;
	std::list<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Environment> environment;
	std::shared_ptr<Resources> resources;

public:
	Core();

	static std::shared_ptr<Core> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
};

