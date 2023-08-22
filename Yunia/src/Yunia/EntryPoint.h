#pragma once

#ifdef YU_PLATFORM_WINDOWS

extern Yunia::Application* Yunia::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Yunia {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			Yunia::Application* app = Yunia::CreateApplication(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}

}

#ifdef YU_DIST

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return Yunia::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return Yunia::Main(argc, argv);
}

#endif // YU_DIST

#endif // YU_PLATFORM_WINDOWS
