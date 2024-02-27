#include <application.h>
#include <iostream>
#include <types.h>
#include <vector>
#include <filesystem>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

using namespace std;

Application::Application(string WindowTitle, int width, int height)
	: ApplicationName(WindowTitle), _width{ width }, _height{ height },
	_camera{ width, height, {-3.0f, 1.5f, -3.0f}, true }, //camera starting position (-2,1,-3 for proj?) & (1, -1, 1) for pyramid
	_cameraLookSpeed{ 0.2f, 0.2f } //mouse sensitivity amount

{}

void Application::Run() {
	//open window
	if (!openWindow()) {
		return;
	}

	setupInputs();

	_running = true;

	//run application

	setup();

	while (_running) {
		float currentTime = glfwGetTime();
		if (_lastFrameTime == -1.0f) {
			_lastFrameTime = currentTime;
		}

		auto deltaTime = currentTime - _lastFrameTime;
		_lastFrameTime = currentTime;

		if (glfwWindowShouldClose(_window)) {
			_running = false;
			continue;
		}


		update(deltaTime);
		//draw shape
		draw();

	}
	glfwTerminate();
}

bool Application::openWindow() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(800, 600, "ShiAnn Oliver", nullptr, nullptr);

	if (!_window) {
		cerr << "Failed to create GLFW window" << endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(_window);

	glfwSetWindowUserPointer(_window, (void*)this);


	glfwSetFramebufferSizeCallback(_window, [](GLFWwindow* window, int width, int height) {
		//calls when window resized
		glViewport(0, 0, width, height);

		auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

		app->_width = width;
		app->_height = height;

		app->_camera.SetSize(width, height);

		});


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cerr << "Failed to initialize GLAD" << endl;
		glfwTerminate();
		return false;
	}
	glEnable(GL_DEPTH_TEST);

	//cull back faces
	//test to see if vertices are in correct order test proj
	//glFrontFace(GL_CCW);
	//glCullFace(GL_BACK);
	//glEnable(GL_CULL_FACE);

	return true;

}

void Application::setupInputs()
{
	glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

		switch (key) {
		case GLFW_KEY_ESCAPE: { //exit window
			if (action == GLFW_PRESS) {
				app->_running = false;
			}
			break;
		}
		case GLFW_KEY_P: { //switch between orthographic and perspective view FIXME
			if (action == GLFW_PRESS) {
				cout << "Change View" << endl;
				app->_camera.SetIsPerspective(!app->_camera.IsPerspective());
			}
		}

		default: {}


		}
		});
	//mouse control
	glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xpos, double ypos) {
		auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));

		app->cursorPositionCallback(xpos, ypos);
		});

	//scroll wheel
	glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset) {;
	cout << "mouse wheel (" << xOffset << ", " << yOffset << ")" << endl;
	auto* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
	app->_camera.IncrementZoom((float)yOffset * 2.0f);

		});

	glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods) {
		switch (button) {
		case GLFW_MOUSE_BUTTON_LEFT: {
			if (action == GLFW_PRESS) {
				cout << "mouse left button pressed" << endl;
			}
			else {
			}
			break;
		}
		case GLFW_MOUSE_BUTTON_MIDDLE: {
			if (action == GLFW_PRESS) {
				cout << "mouse middle button pressed" << endl;
			}
			else {
			}
			break;
		}
		case GLFW_MOUSE_BUTTON_RIGHT: {
			if (action == GLFW_PRESS) {
				cout << "mouse right button pressed" << endl;
			}
			else {
			}
			break;
		}
		default:
			cout << "Unhandled mouse button event" << endl;
		}
		});
}

void Application::createShaders()
{
//	Path shaderPath = filesystem::current_path() / "Shaders";
//	auto texturePath = filesystem::current_path();

//	auto woodTextures = make_shared<Texture>(texturePath / "wood.jpg");
//	auto brickTexture = make_shared<Texture>(texturePath / "brick.jpg");

//	_shader = make_shared<Shader>(shaderPath / "Basic_Shader.vert", shaderPath / "Basic_Shader.frag");
//	_lightShader = make_shared<Shader>(shaderPath / "Basic_Light.vert", shaderPath / "Basic_Light.frag");
//	_cubeShader = make_shared<Shader>(shaderPath / "Basic_Light.vert", shaderPath / "Basic_Light.frag");

//	_shader->AddTexture(woodTextures);
}

void Application::meshes(vector<Vertex>& vertices, vector<uint32_t>& elements)
{
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

float Application::genColorValue()
{
	return (float)rand() / RAND_MAX;
}

float* Application::generateVertices(int sides, float height, float radius)
{
	float* vertices = new float[6 * 2 * sides]; //create 6 indices per side

	float angle = (2.0f * glm::radians(180.0f));

	for (int i = 0; i < sides; i++) {
		int top = 6 * 2 * i;
		auto base = top + 6;

		vertices[top + 0] = cos(angle * i) * radius;

		vertices[top + 0] = cos(angle * i) * radius;
		vertices[top + 1] = height;
		vertices[top + 2] = sin(angle * i) * radius;
		vertices[top + 3] = genColorValue();
		vertices[top + 4] = genColorValue();
		vertices[top + 5] = genColorValue();

		vertices[base + 0] = cos(angle * i) * radius;
		vertices[base + 1] = -(height);
		vertices[base + 2] = sin(angle * i) * radius;
		vertices[base + 3] = genColorValue();
		vertices[base + 4] = genColorValue();
		vertices[base + 5] = genColorValue();

	}

	return vertices;
}

unsigned int* Application::genCylinderBody(int sides)
{

	unsigned int* indices = new unsigned int[6 * sides];

	for (int i = 0; i < sides; i++) {
		int tri = 6 * i;
		int ver1 = 2 * i;
		int ver2 = ver1 + 2;

		if (i == sides - 1)
		{
			ver2 = 0;
		}

		indices[tri + 0] = ver1 + 0;
		indices[tri + 1] = ver1 + 1;
		indices[tri + 2] = ver2 + 0;
		indices[tri + 3] = ver1 + 1;
		indices[tri + 4] = ver2 + 0;
		indices[tri + 5] = ver2 + 1;
	}

	return indices;
}

unsigned int* Application::genCylinderTopInd(int sides)
{
	unsigned int* cylTopIndices = new unsigned int[3 * sides];

	int ver1 = 0;

	for (int i = 0; i < sides - 2; i++) {
		int tri = 3 * i;
		ver1 += 2;
		int ver2 = ver1 + 2;

		cylTopIndices[tri + 0] = 0;
		cylTopIndices[tri + 1] = ver1;
		cylTopIndices[tri + 2] = ver2;
	}

	return cylTopIndices;

}

unsigned int* Application::genCylinderBottomInd(int sides)
{
	unsigned int* cylBotIndices = new unsigned int[3 * sides];

	int ver1 = 0;

	for (int i = 0; i < sides - 2; i++) {
		int tri = 3 * i;
		ver1 += 2;
		int ver2 = ver1 + 2;

		cylBotIndices[tri + 0] = 1;
		cylBotIndices[tri + 1] = ver1 + 1;
		cylBotIndices[tri + 2] = ver2 + 1;
	}

	return cylBotIndices;

}

void Application::drawCylinder(int sides, float height, float radius)
{
	float* cylVertices1 = generateVertices(sides, height, radius);
	unsigned int* cylBodyIndices1 = genCylinderBody(sides);
	unsigned int* cylTopIndices1 = genCylinderTopInd(sides);
	unsigned int* cylBotIndices1 = genCylinderBottomInd(sides);

	unsigned int VBOs[3], VAOs[3], EBOs[7];
	glGenVertexArrays(3, VAOs);
	glGenBuffers(3, VBOs);
	glGenBuffers(7, EBOs);

	// VBO of cylinder
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sides * sizeof(float), cylVertices1, GL_STATIC_DRAW);

	// EBOs of cylinder
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sides * sizeof(unsigned int), cylBodyIndices1, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * (sides - 2) * sizeof(unsigned int), cylTopIndices1, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * (sides - 2) * sizeof(unsigned int), cylBotIndices1, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

}

void Application::setup()
{
	Path shaderPath = filesystem::current_path() / "Shaders";
	_shader = Shader(shaderPath / "Basic_Shader.vert", shaderPath / "Basic_Shader.frag");

//	glGenVertexArrays(2, &_vertexArrayObject);
//	glGenBuffers(2, &_vertexBufferObject);
//	glGenBuffers(2, &_elementBufferObject);

	auto texturePath = filesystem::current_path();
	_textures.emplace_back(texturePath / "wood.jpg"); //apply texture
	auto& Desk = _meshes.emplace_back(Shapes::deskVertices, Shapes::deskElements); //draw desk
	auto& Panes = _meshes.emplace_back(Shapes::planeVertices, Shapes::planeElements); //draw floor/wall planes
	Panes.Transform = glm::translate(Panes.Transform, glm::vec3(1.0f, 1.0f, 0.0f));

	auto& Pyramid = _meshes.emplace_back(Shapes::shapeVertices, Shapes::shapeElements, glm::vec3(0.400f, 0.804f, 0.667f)); //draw pyramid
	Pyramid.Transform = glm::translate(Pyramid.Transform, glm::vec3(-0.15f, -0.045f, 0.65f));
	Pyramid.Transform = glm::scale(Pyramid.Transform, glm::vec3(0.1f, 0.1f, 0.1f));

	auto& Cup = _meshes.emplace_back(Shapes::stoolVertices, Shapes::stoolElements, glm::vec3(0.184f, 0.310f, 0.310f)); //draw pen cup
	Cup.Transform = glm::translate(Cup.Transform, glm::vec3(0.3f, 0.15f, 0.7f));
	Cup.Transform = glm::scale(Cup.Transform, glm::vec3(0.25f, 0.25f, 0.25f));
	auto& Lamp = _meshes.emplace_back(Shapes::lampVertices, Shapes::lampElements); //draw lamp
	Lamp.Transform = glm::translate(Lamp.Transform, glm::vec3(0.1f, 0.0f, 0.1f));

	auto& Stool = _meshes.emplace_back(Shapes::stoolVertices, Shapes::stoolElements, glm::vec3(1.000f, 1.000f, 0.941f)); //draw stool
	Stool.Transform = glm::translate(Stool.Transform, glm::vec3(0.0f, 0.0f, -0.5f));

//	drawCylinder(20, .25, .15);

//	auto &Pyramid = _meshes.emplace_back(Shapes::shapeVertices, Shapes::shapeElements, glm::vec3(0.5f, 0.5f, 0.5f)); //draw pyramid 
//	auto &LightCube = _meshes.emplace_back(Shapes::cubeVertices, Shapes::cubeElements, glm::vec3(1.0f, 1.0f, 1.0f)); //draw cube
//	LightCube.Transform = glm::translate(LightCube.Transform, glm::vec3(-2.0f, 1.5f, 0.0f)); //move light cube 
//	LightCube.Transform = glm::scale(LightCube.Transform, glm::vec3(0.5f, 0.5f, 0.5f)); //move light cube 


//	auto texturePath = filesystem::current_path();
//	_textures.emplace_back(texturePath / "wood.jpg"); //apply texture

}

void Application::update(float deltaTime)
{
	handleInput(deltaTime);
	glfwPollEvents();

}

void Application::draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//camera
	glm::mat4 view = _camera.GetViewMatrix();
	glm::mat4 projection = _camera.GetProjectionMatrix();

	//glm::mat4 model = glm::mat4{ 1.f }; //not used

	_shader.Bind();
	_shader.SetMat4("projection", projection);
	_shader.SetMat4("view", view);

	_shader.SetInt("tex0", 0);
	_shader.SetInt("tex1", 1); //to use multiple textures


	for (auto i = 0; i < _textures.size(); i++) {
		glActiveTexture(GL_TEXTURE0 + i);
		_textures[i].Bind();
	}


	for (auto& mesh : _meshes) {
		//mesh.Transform = glm::rotate(mesh.Transform, glm::radians(0.1f), glm::vec3(0, 1, 0)); //rotate objects continuous
		//mesh.Transform = glm::rotate(mesh.Transform, glm::radians(0.1f), glm::vec3(1, 0, 0));

		_shader.SetMat4("model", mesh.Transform);
	
		mesh.Draw();
	}


	glfwSwapBuffers(_window);
}

void Application::handleInput(float deltaTime)
{
	auto moveAmount = _moveSpeed * deltaTime;

	if (glfwGetKey(_window, GLFW_KEY_W)) {
		_camera.MoveCamera(Camera::MoveDirection::Forward, moveAmount);
		cout << "forward" << endl;
	}
	if (glfwGetKey(_window, GLFW_KEY_A)) {
		_camera.MoveCamera(Camera::MoveDirection::Left, moveAmount);
		cout << "left" << endl;
	}
	if (glfwGetKey(_window, GLFW_KEY_S)) {
		_camera.MoveCamera(Camera::MoveDirection::Backward, moveAmount);
		cout << "back" << endl;
	}
	if (glfwGetKey(_window, GLFW_KEY_D)) {
		_camera.MoveCamera(Camera::MoveDirection::Right, moveAmount);
		cout << "right" << endl;
	}
	if (glfwGetKey(_window, GLFW_KEY_Q)) {
		_camera.MoveCamera(Camera::MoveDirection::Up, moveAmount);
		cout << "Up" << endl;
	}
	if (glfwGetKey(_window, GLFW_KEY_E)) {
		_camera.MoveCamera(Camera::MoveDirection::Down, moveAmount);
		cout << "Down" << endl;
	}

	double xpos, ypos;
	glfwGetCursorPos(_window, &xpos, &ypos);
	cursorPositionCallback(xpos, ypos);
}

void Application::cursorPositionCallback(double xpos, double ypos)
{
	if (!_firstMouse) {
		_lastCursorPosition.x = static_cast<float>(xpos);
		_lastCursorPosition.y = static_cast<float>(ypos);
		_firstMouse = true;
	}
	glm::vec2 moveAmount{
		xpos - _lastCursorPosition.x,
		_lastCursorPosition.y - ypos

	};

	_lastCursorPosition.x = static_cast<float>(xpos);
	_lastCursorPosition.y = static_cast<float>(ypos);

	_camera.rotateBy(moveAmount.x * _cameraLookSpeed.x, moveAmount.y * _cameraLookSpeed.y);
}

