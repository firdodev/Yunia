#pragma once
#include <string>
#include "Window.h"

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

		void Run();
	private:
		Window* m_Window;
	};

	Application* CreateApplication(int argc, char** argv);
}
