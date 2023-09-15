#include <Yunia/Yunia.h>
#include <Yunia/Core/EntryPoint.h>
#include <iostream>


class PrintMessageComponent : public Yunia::Component
{
public:
	PrintMessageComponent(const std::string& message) : m_Message(message) {}

	void OnAttach() override {
		std::cout << "PrintMessageComponent attached!" << std::endl;
	}

	void OnUpdate(float ts) override {
	}

private:
	std::string m_Message;
};

Yunia::Application* Yunia::CreateApplication(int argc, char** argv) {
	Yunia::ApplicationSpecification spec;
	spec.Name = "Yunia Example";

	Yunia::Application* app = new Yunia::Application(spec);

	PrintMessageComponent* messageComponent = new PrintMessageComponent("Hello from the component!");
	app->PushComponent(messageComponent);

	return app;
}