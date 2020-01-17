#include <vector>
#include <memory>
#include <list>

class Component;
class Core;

/**
  * Objects class.
  */
class Entity {
private:
	friend class Core;///< Gaining access to private and protected members of Core class 

	std::list<std::shared_ptr<Component>> components;/// < List of pointers of type Component 
	std::weak_ptr<Core> core;///< Weak pointer to Core class
	std::weak_ptr<Entity> self;/// < Weak pointer to Entity class

	/**
	  * \breif Update entity and Display entity functions
	  */
	void tick();
	void display();
public:
	const std::shared_ptr<Core> getCore();

	/**
	  * \breif Template for creating component of entity, by passing class of the object we are creating.
	  * After creating the component, it is saved as a shared pointer to component list 
	  */
	template <class T> 
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> comp = std::make_shared<T>();
		comp->entity = self;
		std::shared_ptr<Component> baseComp = comp;
		baseComp->onInit();
		components.push_back(comp);
		return comp;
	};
};