#include "Renderer.h"

static unsigned int compileShader(const string& source, unsigned int type)
{
	unsigned int id = glCreateShader(GL_VERTEX_SHADER);
	const char* src = source.c_str();
}

static int CreateShader(const string& vertexShader, const string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
}