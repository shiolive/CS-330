#include "Mesh.h"
#include <iostream>


Mesh::Mesh(vector<Vertex> &vertices, vector<uint32_t> &elements)
{

	init(vertices, elements);

}


Mesh::Mesh(vector<Vertex>& vertices, vector<uint32_t>& elements, const glm::vec3& color)
{
	for (auto& vertex : vertices) {
		vertex.Color = color;
	}

	init(vertices, elements);
}

void Mesh::Draw(){

	glBindVertexArray(_vertexArrayObject);
	
	//gl draw calls
	glDrawElements(GL_TRIANGLES, _elementCount, GL_UNSIGNED_INT, nullptr); 
}

void Mesh::init(vector<Vertex>& vertices, vector<uint32_t>& elements) {
	//create triangle
	glGenVertexArrays(1, &_vertexArrayObject);
	glGenBuffers(1, &_vertexBufferObject);
	glGenBuffers(1, &_elementBufferObject);

	glBindVertexArray(_vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(elements.size() * sizeof(uint32_t)), elements.data(), GL_STATIC_DRAW);

	//define vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Uv));


	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	_elementCount = elements.size();
}