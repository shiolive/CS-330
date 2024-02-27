#pragma once
#include <application.h>
#include <shader.h>
#include <mesh.h>
#include <Model.h>
#include <glm/gtc/type_ptr.hpp>

class Light
{
public:
	Light();

	void Init();

	void Update(float deltaTime);
	void Draw(const glm::mat4& view, const glm::mat4& projection);

private:
	void createShader();
	void createMesh();
	
private:
	std::shared_ptr<Shader> _basicUnlitShader{};
	std::shared_ptr<Mesh> _shape{};

	std::vector<Model> _models{};
	vector<Mesh> _meshes;
	Shader _shader;
	glm::mat4 Transform{ 1.0f };
};

