#pragma once
#include <glm/glm.hpp>

class Camera
{
public:
	enum class MoveDirection {
		Forward,
		Backward,
		Left,
		Right, 
		Up,
		Down
	};


	explicit Camera(int width, int height, glm::vec3 initialPosition = glm::vec3{0, 0, -20.f}, bool isPerspective = true);

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix() const;

	bool IsPerspective() const { return _isPerspective; }
	void SetIsPerspective(bool isPerspective) { _isPerspective = isPerspective; }
	
	void SetSize(int width, int height) {
		_width = width;
		_height = height;
	}
	void MoveCamera(MoveDirection direction, float moveAmount);
	void rotateBy(float yaw, float pitch);
	void IncrementZoom(float amount);

private:

	void recalculateVectors();

private:
	
	bool _isPerspective{ true };

	glm::vec3 _position{};
	glm::vec3 _lookDirection{};
	glm::vec3 _upDirection{ 0.0f, 1.0f, 0.0f };

	float _yaw{-90.0f};
	float _pitch{};
	float _fieldOfView{ 75.0f };
	int _width{ 0 };
	int _height{ 0 };
	float _nearClip{ 0.1f };
	float _farClip{ 100.0f };
	
};

