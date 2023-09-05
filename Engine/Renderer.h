#pragma once 
#include "Window.h"
#include "Entity.h"

namespace Renderer
{
	static unsigned int CompileShader(unsigned int type, const string& source);

	static unsigned int CreateShader(const string& vertexShader, const string& fragmentShader);

 string vertexShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		" gl_Position = position;\n"
		"}\n";

	 string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		" color = vec4(1.0, 0.0, 0.0, 1.0);\n"
		"}\n";
}

