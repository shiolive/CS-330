#pragma once
#include <filesystem>
#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

using namespace std;

using Path = filesystem::path;

class Shader
{
public:
	Shader() = default;
	Shader (const string& vertexSource, const string& fragmentSource);
	Shader(const Path& vertexPath, const Path& fragmentPath);

	void Bind();

	void SetMat4(const string& uniformName, const glm::mat4& mat4);
	void SetInt(const string &uniformName, int value);

private:
	void load(const string& vertexSource, const string& fragmentSource);
	GLint getUniformLocation(const string& uniformName);

private:

	GLuint _shaderProgram;
};

