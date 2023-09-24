#pragma once
#include "Yunia/Core/Component.h"
#include "Yunia/Core/Window.h"
#include "imgui.h"

namespace Yunia {

	class ImGuiComponent : public Component
	{
	public:
		ImGuiComponent::ImGuiComponent(Window* window, ID3D11Device* device, ID3D11DeviceContext* context);  // We pass the window pointer to access native handlers
		virtual ~ImGuiComponent();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate(float ts) override;
		void OnUIRender() override;

	private:
		void InitializeImGui();
		void ShutdownImGui();

	private:
		HWND hwnd;
		ID3D11Device* device;
		ID3D11DeviceContext* context;
	};

}