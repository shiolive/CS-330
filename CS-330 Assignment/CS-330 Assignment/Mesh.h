#pragma once
#include <vector>
#include <types.h>
#include <glad/glad.h>


using namespace std;


class Mesh{
public:
	Mesh() = default;
	Mesh(vector<Vertex> &vertices, vector<uint32_t> &elements);
	Mesh(vector<Vertex>& vertices, vector<uint32_t>& elements, const glm::vec3& color);

	void Draw();

	glm::mat4 Transform{ 1.f };

private:

	void init(vector<Vertex>& vertices, vector<uint32_t>& elements);

public:


	uint32_t _elementCount{ 0 };
	GLuint _vertexBufferObject{};
	GLuint _shaderProgram{};
	GLuint _vertexArrayObject{};
	GLuint _elementBufferObject{};
};

