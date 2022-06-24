#include "camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace ellipsoid {
namespace gl {

UBO Camera::makeUBO() {
    UBO ubo = UBO().size(64).build();
    ubo.bindIndex(ELLIPSOID_GL_CAMERA_UBO_INDEX);
    return ubo;
}

glm::vec3 Camera::calculatePosition() const {
    return glm::vec3(glm::translate(glm::mat4(1.0f),
                                    _transform.getTranslation()->asVector()) *
                     glm::vec4(_position, 1.0f));
}

glm::vec3 Camera::calculateDirection() const {
    return glm::vec3(_transform.getRotation()->getTransformMatrix() *
                     glm::vec4(_direction, 1.0f));
}

glm::vec3 Camera::calculateUp() const {
    return glm::vec3(_transform.getRotation()->getTransformMatrix() *
                     glm::vec4(_up, 1.0f));
}

glm::vec3 Camera::calculateRight() const {
    return glm::cross(calculateUp(), calculateRight());
}

void Camera::translate(const glm::vec3 target) { _transform.translate(target); }

void Camera::rotate(const glm::vec3 target) { _transform.rotate(target); }

void Camera::translate(const float x, const float y, const float z) {
    _transform.translate(x, y, z);
}

void Camera::rotate(const float x, const float y, const float z) {
    _transform.rotate(x, y, z);
}

glm::mat4 Camera::getMVP() const {
    return glm::lookAt(calculatePosition(),
                       calculatePosition() - calculateDirection(),
                       calculateUp()) *
           getProjectionMatrix();
}

void Camera::update() { updateUBO(ELLIPSOID_GL_CAMERA_UBO_INDEX); }

void Camera::updateUBO(const unsigned int index) {
    _ubo.bufferData(0, getMVP());
}

} // namespace gl
} // namespace ellipsoid
