#include "Yunia/Application.h"
#include "Yunia/EntryPoint.h"

#include "Yunia/Image.h"

class ExampleComponent : public Yunia::Component
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		ImGui::Button("Button");
		ImGui::End();

		ImGui::ShowDemoWindow();
	}
};

Yunia::Application* Yunia::CreateApplication(int argc, char** argv)
{
	Yunia::ApplicationSpecification spec;
	spec.Name = "Yunia Example";

	Yunia::Application* app = new Yunia::Application(spec);
	app->PushComponent<ExampleComponent>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}