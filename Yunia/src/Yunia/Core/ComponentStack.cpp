#include "ComponentStack.h"

namespace Yunia {

	ComponentStack::~ComponentStack()
	{
		for (Component* component : m_Components)
		{
			component->OnDetach();
			delete component;
		}
	}

	void ComponentStack::PushComponent(Component* component)
	{
		component->OnAttach();
		m_Components.push_back(component);
	}

	void ComponentStack::PopComponent(Component* component)
	{
		auto it = std::find(m_Components.begin(), m_Components.end(), component);
		if (it != m_Components.end())
		{
			(*it)->OnDetach();
			m_Components.erase(it);
			delete component;
		}
	}

	void ComponentStack::Update(float ts)
	{
		for (Component* component : m_Components)
		{
			component->OnUpdate(ts);
		}
	}

	void ComponentStack::UIRender()
	{
		for (Component* component : m_Components)
		{
			component->OnUIRender();
		}
	}

}