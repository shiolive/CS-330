#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <application.h>

using namespace std;

int main(int argc, char** argv) {

	Application app{ "CS-330 Assignment", 800, 600 };

	app.Run();

	return 0;
}