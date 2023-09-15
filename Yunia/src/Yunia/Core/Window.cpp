#include "Window.h"
#include <string>

namespace Yunia {

	Window::Window(int width, int height, const char* title)
		: m_Width(width), m_Height(height), m_Title(title)
		, m_pDevice(nullptr), m_pDeviceContext(nullptr), m_pSwapChain(nullptr)
	{
	}

	bool Window::Initialize() {
		return InitWindow() && InitD3D11();
	}

	bool Window::InitWindow() {
		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = L"YuniaWindowClass";

		RegisterClass(&wc);

		int size_needed = MultiByteToWideChar(CP_UTF8, 0, m_Title, -1, NULL, 0);
		std::wstring wstrTitle(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, m_Title, -1, &wstrTitle[0], size_needed);

		m_hWnd = CreateWindowEx(
			0,
			L"YuniaWindowClass",
			wstrTitle.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, m_Width, m_Height,
			NULL,
			NULL,
			GetModuleHandle(NULL),
			NULL
		);

		if (!m_hWnd) {
			return false;
		}

		ShowWindow(m_hWnd, SW_SHOW);

		return true;
	}

	bool Window::InitD3D11() {
		D3D_FEATURE_LEVEL featureLevel;
		HRESULT hr = D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			0,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			&m_pDevice,
			&featureLevel,
			&m_pDeviceContext
		);

		if (FAILED(hr)) {
			return false;
		}

		// Swap chain creation
		DXGI_SWAP_CHAIN_DESC scDesc = {};
		scDesc.BufferDesc.Width = m_Width;
		scDesc.BufferDesc.Height = m_Height;
		scDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		scDesc.BufferDesc.RefreshRate.Numerator = 60;
		scDesc.BufferDesc.RefreshRate.Denominator = 1;
		scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		scDesc.BufferCount = 1;
		scDesc.OutputWindow = m_hWnd;
		scDesc.SampleDesc.Count = 1;
		scDesc.SampleDesc.Quality = 0;
		scDesc.Windowed = TRUE;

		IDXGIDevice* dxgiDevice = nullptr;
		m_pDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice);

		IDXGIAdapter* dxgiAdapter = nullptr;
		dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&dxgiAdapter);

		IDXGIFactory* dxgiFactory = nullptr;
		dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&dxgiFactory);

		dxgiFactory->CreateSwapChain(m_pDevice, &scDesc, &m_pSwapChain);

		dxgiFactory->Release();
		dxgiAdapter->Release();
		dxgiDevice->Release();

		return true;
	}

	Window::~Window() {
		Shutdown();
	}

	void Window::Shutdown() {
		m_pSwapChain->Release();
		m_pDeviceContext->Release();
		m_pDevice->Release();
	}

	bool Window::IsRunning() {
		return m_hWnd && IsWindow(m_hWnd);
	}

	void Window::PollEvents() {
		MSG msg = {};
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		switch (uMsg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}
}
