#pragma once
#include <vector>
#include "Component.h"

namespace Yunia {

	class ComponentStack
	{
	public:
		ComponentStack() = default;
		~ComponentStack();

		void PushComponent(Component* component);
		void PopComponent(Component* component);

		void Update(float ts);
		void UIRender();

	private:
		std::vector<Component*> m_Components;
	};

}
