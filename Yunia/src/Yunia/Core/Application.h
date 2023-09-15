#pragma once
#include <string>
#include "Window.h"
#include "ComponentStack.h"

namespace Yunia {

	class ApplicationSpecification {
	public:
		// Define any specifications for your application here.
		std::string Name = "Yunia Application";
		int Width = 800;
		int Height = 600;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& spec);
		virtual ~Application();

		void PushComponent(Component* component) { m_ComponentStack.PushComponent(component); }
		void PopComponent(Component* component) { m_ComponentStack.PopComponent(component); }

		void Run();
	private:
		Window* m_Window;
		ComponentStack m_ComponentStack;
	};

	Application* CreateApplication(int argc, char** argv);
}
