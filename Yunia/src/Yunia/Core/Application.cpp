#include "Application.h"
#include <iostream>

namespace Yunia {
	Application::Application(const ApplicationSpecification& spec)
	{
		m_Window = new Window(spec.Width, spec.Height, spec.Name.c_str());
		if (!m_Window->Initialize()) {
			std::cerr << "Failed to initialize the window." << std::endl;
			exit(-1);
		}
	}

	Application::~Application()
	{
		m_Window->Shutdown();
		delete m_Window;
	}

	void Application::Run()
	{
		while (m_Window->IsRunning()) {
			m_Window->PollEvents();
		}
	}
}
