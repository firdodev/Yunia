#include "Application.h"
#include <iostream>

namespace Yunia {
	Application::Application(const ApplicationSpecification& spec)
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		std::cout << "Hello YuniaApp" << std::endl;
	}
}