#pragma once

#include <mesh.h>
#include <Shader.h>
class Model
{

public:
	Model();
	Model(std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader);
	Shader* GetShader() { return _shader.get(); }
	Mesh* GetMesh() { return _mesh.get(); }

private:
	std::shared_ptr<Shader> _shader;
	std::shared_ptr<Mesh> _mesh;
};

