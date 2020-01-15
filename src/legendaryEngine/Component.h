#include <memory>

class Entity;
class Core;
class Keyboard;
class Environment;
class Resources;

class Component {
private:
	friend class Entity;
	friend class Core;
	std::weak_ptr<Entity> entity;
	virtual void onInit(); 
	virtual void onBegin(); 
	virtual void onTick();
	virtual void onDisplay();
public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();
	std::shared_ptr<Resources> getResources();
};
