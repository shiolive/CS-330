#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Mesh.h>
#include <Shader.h>
#include <Camera.h>
#include <Texture.h>
#include <Model.h>
#include <Light.h>

class Application {
public:
	Application();
	Application(std::string WindowTitle, int width, int height);
	void Run();

private:
	bool openWindow();
	void setupInputs();
	void createShaders();

	float genColorValue();
	float* generateVertices(int sides, float height, float radius);
	unsigned int* genCylinderBody(int sides);
	unsigned int* genCylinderTopInd(int sides);
	unsigned int* genCylinderBottomInd(int sides);
	void drawCylinder(int sides, float height, float radius);

	void meshes(vector<Vertex>& vertices, vector<uint32_t>& elements);

	void setup();
	void update(float deltaTime);
	void draw();
	void handleInput(float deltaTime);
	void cursorPositionCallback(double xpos, double ypos);
	


private:
	std::string ApplicationName{};
	int _width{};
	int _height{};
	GLFWwindow* _window{ nullptr };

	GLuint _vertexBufferObject{};
	float _moveSpeed{ 5.0f };
	Camera _camera;

	vector<Mesh> _meshes;
	vector<Texture> _textures;
	vector<Shapes> _objects;
	vector<Model> _models{};
	Shapes _object;
	Shader _shader;
	Shader _lightShader;
	Shader _cubeShader;
	bool _running{ false };

	uint32_t _elementCount{ 0 };
	GLuint _vertexArrayObject{};
	GLuint _elementBufferObject{};

	bool _firstMouse{ false };
	glm::vec2 _lastCursorPosition{};
	glm::vec2 _cameraLookSpeed{};

	float _lastFrameTime{ -1.0f };

	float _ambientStrength { 0.1f };
	glm::vec3 _ambientLightColor{ 1.0f, 1.0f, 1.0f };

	glm::vec3 _lightPosition{ -2.0f, 1.75f, 0.0f };


};
