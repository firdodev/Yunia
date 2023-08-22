#pragma once
#include <string>

namespace Yunia {

	class ApplicationSpecification {
	public:
		// Define any specifications for your application here.
		std::string Name = "Yunia Application";
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& spec);
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication(int argc, char** argv);
}

