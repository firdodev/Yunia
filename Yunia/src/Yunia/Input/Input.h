#pragma once

#include "KeyCodes.h"

#include <glm/glm.hpp>

namespace Yunia {

	class Input
	{
	public:
		static bool IsKeyDown(KeyCode keycode);
		static bool IsMouseButtonDown(MouseButton button);

		static glm::vec2 GetMousePosition();

		static void SetCursorMode(CursorMode mode);
	};

}
