#include "Shader.h"
#include <iostream>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const string& vertexSource, const string& fragmentSource)
{
	load(vertexSource, fragmentSource);
}

Shader::Shader(const Path& vertexPath,const Path& fragmentPath)
{



	try {
		ifstream vShaderFile;
		ifstream fShaderFile;

		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		//load shader
		load(vShaderStream.str(), fShaderStream.str());
	}
	catch (ifstream::failure& e) {
		cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << endl;
	}

}
 
void Shader::Bind()
{
	glUseProgram(_shaderProgram);
}

void Shader::load(const string& vertexSource, const string& fragmentSource)
{
	const char* vShaderCode = vertexSource.c_str();
	const char* fShaderCode = fragmentSource.c_str();
	//vertex shader
	auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
	glCompileShader(vertexShader);

	int success;
	char infolog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, nullptr, infolog);
		cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << endl;

	}

	//fragment shader
	auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infolog);
		cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infolog << endl;

	}

	_shaderProgram = glCreateProgram();
	glAttachShader(_shaderProgram, vertexShader);
	glAttachShader(_shaderProgram, fragmentShader);
	glLinkProgram(_shaderProgram);

	glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infolog);
		cerr << "ERROR::SHADER::FRAGMENT::LINK_FAILED\n" << infolog << endl;

	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

GLint Shader::getUniformLocation(const string& uniformName)
{
	return glGetUniformLocation(_shaderProgram, uniformName.c_str());
}


void Shader::SetMat4(const string& uniformName, const glm::mat4& mat4)
{
	auto uniformLoc = getUniformLocation(uniformName);

	if (uniformLoc != -1) {
		glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(mat4));

	}
}

void Shader::SetInt(const string &uniformName, int value)
{
	auto uniformLoc = getUniformLocation(uniformName);

	if (uniformLoc != -1) {
		glUniform1i(uniformLoc, value);

	}
}
