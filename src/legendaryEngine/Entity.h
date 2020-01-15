#include <vector>
#include <memory>
#include <list>

class Component;
class Core;

class Entity {
private:
	friend class Core;
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;
	std::weak_ptr<Entity> self;

	void tick();
	void display();
public:
	const std::shared_ptr<Core> getCore();
	
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

	template <class T, class A>
	std::shared_ptr<T> addComponent(A _a)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a);
		comp->entity = self;
		std::shared_ptr<Component> baseComp = comp;
		baseComp->onInit();
		components.push_back(comp);
		return comp;
	};

	template <class T, class A, class B>
	std::shared_ptr<T> addComponent(A _a, B _b)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b);
		comp->entity = self;
		std::shared_ptr<Component> baseComp = comp;
		baseComp->onInit();
		components.push_back(comp);
		return comp;
	};

	template <class T, class A, class B, class C>
	std::shared_ptr<T> addComponent(A _a, B _b, C _c)
	{
		std::shared_ptr<T> comp = std::make_shared<T>(_a, _b, _c);
		comp->entity = self;
		std::shared_ptr<Component> baseComp = comp;
		baseComp->onInit();
		components.push_back(comp);
		return comp;
	};

};