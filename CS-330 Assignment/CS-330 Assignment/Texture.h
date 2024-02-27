#pragma once
#include <filesystem>
#include <glad/glad.h>
using namespace std;

class Texture {

public:

	explicit Texture(const filesystem::path& path);
	void Bind();

private:
	GLuint _textureHandle;


};

