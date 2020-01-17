#ifndef MyComponent
#define MyComponent
#include <memory>

class Entity;
class Core;
/**
  * Represents a Component of the CES system
  */
class Component
{
private:
	friend class Entity; ///< Gaining access to private and protected members of Entity class 
	friend class Core; ///< Gaining access to private and protected members of Core class 
	std::weak_ptr<Entity> entity; ///< Weak pointer to entity object

	/**
	  * \brief Set of reusable functions in different code parts. You can reuse them by overriding them by the derived class
	  */
	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();
public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
};
#endif