#include <Light.h>
#include <shader.h>
#include <glm/glm.hpp>

Light::Light()
{
	createShader();
	createMesh();
}

void Light::Init()
{
}

void Light::Update(float deltaTime)
{
}

void Light::Draw(const glm::mat4& view, const glm::mat4& projection)
{
	for (auto& model : _models) {
		auto* shader = model.GetShader();
		auto* mesh = model.GetMesh();
		shader->Bind();
		shader->SetMat4("projection", projection);
		shader->SetMat4("view", view);
		shader->SetMat4("model", Transform * mesh->Transform);

		mesh->Draw();
	}

}

void Light::createShader()
{
	Path shaderPath = filesystem::current_path() / "Shaders";
	_shader = Shader(shaderPath / "Basic_Shader.vert", shaderPath / "Basic_Shader.frag");
}

void Light::createMesh()
{
	auto& LightCube = _meshes.emplace_back(Shapes::cubeVertices, Shapes::cubeElements, glm::vec3(1.0f, 1.0f, 1.0f)); //draw cube
	LightCube.Transform = glm::translate(LightCube.Transform, glm::vec3(-2.0f, 1.5f, 0.0f)); //move light cube 

//	auto cube = std::make_shared<Mesh>(Shapes::cubeVertices, Shapes::cubeElements, glm::vec3(1.0f, 1.0f, 1.0f));
//	auto& cubeModel = _models.emplace_back(cube, _basicUnlitShader);
//	cubeModel.GetMesh()->Transform = glm::scale(cubeModel.GetMesh()->Transform, glm::vec3(0.5f, 0.5f, 0.5f));
}
