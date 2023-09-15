#pragma once

namespace Yunia {

	class Component
	{
	public:
		virtual ~Component() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}

		virtual void OnUpdate(float ts) {}
		virtual void OnUIRender() {}
	};

}
