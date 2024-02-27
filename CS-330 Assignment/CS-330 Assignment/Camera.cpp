#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

Camera::Camera(int width, int height, glm::vec3 initialPosition, bool isPerspective)
	: _isPerspective{ isPerspective }, 
	_position{ initialPosition }, _lookDirection{ 1.0f, 0.0f, 1.0f },
	_width{ width }, _height{ height } {

	recalculateVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(_position, _position + _lookDirection, _upDirection);
	//z axis position of camera aka how close is camera
	//x axis where camera is looking
	//which way is up direction y axis
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	auto aspectRatio = (float)_width / (float)_height;

	if (_isPerspective) {
		return glm::perspective(glm::radians(_fieldOfView), aspectRatio, _nearClip, _farClip);

	}


	return glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, _nearClip, _farClip);
}

void Camera::MoveCamera(MoveDirection direction, float moveAmount) //controls camera direction movement
{
	glm::vec3 moveDirection{};

	switch (direction) {
	case MoveDirection::Forward: {
		moveDirection = _lookDirection;
		break;
	}
	case MoveDirection::Backward: {
		moveDirection = -_lookDirection;
		break;
	}
	case MoveDirection::Left: {
		moveDirection = -glm::normalize(glm::cross(_lookDirection, _upDirection));
		break;
	}
	case MoveDirection::Right: {
		moveDirection = glm::normalize(glm::cross(_lookDirection, _upDirection));
		break;
	}
	case MoveDirection::Up: {
		moveDirection = _upDirection;
		break;
	}
	case MoveDirection::Down: {
		moveDirection = -_upDirection;
		break;
	}
	}

	_position += moveDirection * moveAmount;
}

void Camera::rotateBy(float yaw, float pitch)
{
	_yaw += yaw;
	_pitch += pitch;

	_pitch = std::clamp(_pitch, -89.0f, 89.0f);

	recalculateVectors();
}
void Camera::recalculateVectors()
{
	_lookDirection = glm::normalize(
		glm::vec3{
			std::cos(glm::radians(_yaw)) * std::cos(glm::radians(_pitch)),
			std::sin(glm::radians(_pitch)),
			std::sin(glm::radians(_yaw)) * std::cos(glm::radians(_pitch))
		}
	);

	glm::vec3 rightDirection = glm::normalize(glm::cross(_lookDirection, glm::vec3(0.0f, 1.0f, 0.0f)));
	_upDirection = glm::normalize(glm::cross(rightDirection, _lookDirection));
}


void Camera::IncrementZoom(float amount)
{
	_fieldOfView -= amount;

	_fieldOfView = std::clamp(_fieldOfView, 1.0f, 75.0f);
}
