#include <Yunia/Application.h>
#include <Yunia/EntryPoint.h>

Yunia::Application* Yunia::CreateApplication(int argc, char** argv) {
	Yunia::ApplicationSpecification spec;
	spec.Name = "Yunia Example";

	Yunia::Application* app = new Yunia::Application(spec);

	return app;
}