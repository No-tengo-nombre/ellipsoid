#include "camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace ellipsoid {
namespace gl {

PerspectiveCamera::PerspectiveCamera() {
    _position = glm::vec3({0.0f, 0.0f, 0.0f});
    _direction = glm::vec3({0.0f, 0.0f, 1.0f});
    _up = glm::vec3({0.0f, 1.0f, 0.0f});
    _xMin = 0.0f;
    _xMax = 0.0f;
    _yMin = 0.0f;
    _yMax = 0.0f;
    _zMin = 0.0f;
    _zMax = 0.0f;
}

PerspectiveCamera::PerspectiveCamera(const float xMin, const float xMax,
                                     const float yMin, const float yMax,
                                     const float zMin, const float zMax) {
    _position = glm::vec3({0.0f, 0.0f, 0.0f});
    _direction = glm::vec3({0.0f, 0.0f, 1.0f});
    _up = glm::vec3({0.0f, 1.0f, 0.0f});
    _xMin = xMin;
    _xMax = xMax;
    _yMin = yMin;
    _yMax = yMax;
    _zMin = zMin;
    _zMax = zMax;
}

PerspectiveCamera& PerspectiveCamera::setXMin(const float xMin) {
    _xMin = xMin;
    return *this;
}

PerspectiveCamera& PerspectiveCamera::setXMax(const float xMax) {
    _xMax = xMax;
    return *this;
}

PerspectiveCamera& PerspectiveCamera::setYMin(const float yMin) {
    _yMin = yMin;
    return *this;
}

PerspectiveCamera& PerspectiveCamera::setYMax(const float yMax) {
    _yMax = yMax;
    return *this;
}

PerspectiveCamera& PerspectiveCamera::setZMin(const float zMin) {
    _zMin = zMin;
    return *this;
}

PerspectiveCamera& PerspectiveCamera::setZMax(const float zMax) {
    _zMax = zMax;
    return *this;
}

PerspectiveCamera& PerspectiveCamera::setPosition(const glm::vec3 position) {
    _position = position;
    return *this;
}

PerspectiveCamera& PerspectiveCamera::setDirection(const glm::vec3 direction) {
    _direction = glm::normalize(direction);
    return *this;
}

PerspectiveCamera& PerspectiveCamera::setUp(const glm::vec3 up) {
    _up = glm::normalize(up);
    return *this;
}

glm::mat4 PerspectiveCamera::getProjectionMatrix() const {
    return glm::ortho(_xMin, _xMax, _yMin, _yMax, _zMin, _zMax);
}

} // namespace gl
} // namespace ellipsoid
