#include "camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace ellipsoid {
namespace gl {

OrthographicCamera::OrthographicCamera() {
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

OrthographicCamera::OrthographicCamera(const float xMin, const float xMax,
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

OrthographicCamera* OrthographicCamera::setXMin(const float xMin) {
    _xMin = xMin;
    return this;
}

OrthographicCamera* OrthographicCamera::setXMax(const float xMax) {
    _xMax = xMax;
    return this;
}

OrthographicCamera* OrthographicCamera::setYMin(const float yMin) {
    _yMin = yMin;
    return this;
}

OrthographicCamera* OrthographicCamera::setYMax(const float yMax) {
    _yMax = yMax;
    return this;
}

OrthographicCamera* OrthographicCamera::setZMin(const float zMin) {
    _zMin = zMin;
    return this;
}

OrthographicCamera* OrthographicCamera::setZMax(const float zMax) {
    _zMax = zMax;
    return this;
}

OrthographicCamera* OrthographicCamera::setPosition(const glm::vec3 position) {
    _position = position;
    return this;
}

OrthographicCamera*
OrthographicCamera::setDirection(const glm::vec3 direction) {
    _direction = glm::normalize(direction);
    return this;
}

OrthographicCamera* OrthographicCamera::setUp(const glm::vec3 up) {
    _up = glm::normalize(up);
    return this;
}

glm::mat4 OrthographicCamera::getProjectionMatrix() const {
    return glm::ortho(_xMin, _xMax, _yMin, _yMax, _zMin, _zMax);
}

} // namespace gl
} // namespace ellipsoid
