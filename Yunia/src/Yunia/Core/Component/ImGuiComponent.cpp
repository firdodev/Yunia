#include "ImGuiComponent.h"
#include "backends/imgui_impl_win32.h"
#include "backends/imgui_impl_dx11.h"
namespace Yunia {

	ImGuiComponent::ImGuiComponent(Window* window, ID3D11Device* d, ID3D11DeviceContext* c)
		: device(d), context(c)
	{
		hwnd = window->GetHWND();  // Assuming Window has a method to get the HWND.
		InitializeImGui();
	}

	ImGuiComponent::~ImGuiComponent()
	{
		ShutdownImGui();
	}

	void ImGuiComponent::InitializeImGui()
	{
		// Initialize ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		// Setup Platform/Renderer bindings
		// NOTE: You will need to pass in actual hwnd, device, and context pointers here
		ImGui_ImplWin32_Init(hwnd);
		ImGui_ImplDX11_Init(device, context);

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	}

	void ImGuiComponent::ShutdownImGui()
	{
		// Cleanup
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiComponent::OnAttach()
	{
		// Optional: Set any additional ImGui states
	}

	void ImGuiComponent::OnDetach()
	{
		// Optional: Any ImGui-related cleanup that is not in the destructor
	}

	void ImGuiComponent::OnUpdate(float ts)
	{
		// New ImGui frame
		ImGui::NewFrame();
	}

	void ImGuiComponent::OnUIRender()
	{
		// Start a new ImGui frame
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		// Main docking space
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
		window_flags |= ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

		const float dockspace_spacing = 0.0f;
		const ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode;

		// Begin the main dockspace
		ImGui::Begin("DockSpace Demo", nullptr, window_flags);
		ImGui::DockSpace(ImGui::GetID("MyDockSpace"), ImVec2(0.0f, 0.0f), dockspace_flags);
		ImGui::End();

		// Sample floating window
		ImGui::Begin("My Panel");
		ImGui::Text("Hello from My Panel!");
		ImGui::End();

		// Rendering
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

}