#pragma once

#include "Component.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>

#include "imgui.h"
#include "vulkan/vulkan.h"

void check_vk_result(VkResult err);

struct GLFWwindow;

namespace Yunia {

	struct ApplicationSpecification
	{
		std::string Name = "Yunia App";
		uint32_t Width = 1600;
		uint32_t Height = 900;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& applicationSpecification = ApplicationSpecification());
		~Application();

		static Application& Get();

		void Run();
		void SetMenubarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; }
		
		template<typename T>
		void PushComponent()
		{
			static_assert(std::is_base_of<Component, T>::value, "Pushed type is not subclass of Layer!");
			m_ComponentStack.emplace_back(std::make_shared<T>())->OnAttach();
		}

		void PushComponent(const std::shared_ptr<Component>& layer) { m_ComponentStack.emplace_back(layer); layer->OnAttach(); }

		void Close();

		float GetTime();
		GLFWwindow* GetWindowHandle() const { return m_WindowHandle; }

		static VkInstance GetInstance();
		static VkPhysicalDevice GetPhysicalDevice();
		static VkDevice GetDevice();

		static VkCommandBuffer GetCommandBuffer(bool begin);
		static void FlushCommandBuffer(VkCommandBuffer commandBuffer);

		static void SubmitResourceFree(std::function<void()>&& func);
	private:
		void Init();
		void Shutdown();
	private:
		ApplicationSpecification m_Specification;
		GLFWwindow* m_WindowHandle = nullptr;
		bool m_Running = false;

		float m_TimeStep = 0.0f;
		float m_FrameTime = 0.0f;
		float m_LastFrameTime = 0.0f;

		std::vector<std::shared_ptr<Component>> m_ComponentStack;
		std::function<void()> m_MenubarCallback;
	};

	// Implemented by CLIENT
	Application* CreateApplication(int argc, char** argv);
}