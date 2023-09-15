#pragma once
#include <Windows.h>
#include <d3d11.h>

namespace Yunia {
	class Window
	{
	public:
		Window(int width, int height, const char* title);
		~Window();

		bool Initialize();
		void Shutdown();

		bool IsRunning();
		void PollEvents();

	private:
		HWND m_hWnd;
		int m_Width, m_Height;
		const char* m_Title;

		ID3D11Device* m_pDevice;
		ID3D11DeviceContext* m_pDeviceContext;
		IDXGISwapChain* m_pSwapChain;

		bool InitWindow();
		bool InitD3D11();

		static LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}
