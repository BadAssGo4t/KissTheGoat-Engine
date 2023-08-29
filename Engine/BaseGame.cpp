#include "BaseGame.h"

void main()
{
	windowParameters window;
	window.height = 640;
	window.width = 800;
	window.windowName = "Engine KissTheGoat";

	CreateWindow(window.width, window.height, window.windowName);
}