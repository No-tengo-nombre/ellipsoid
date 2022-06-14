#define ELLIPSOID_SINGULAR_VALUE_THRESHOLD 1e-6

#include "transform.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace ellipsoid {
namespace gl {
namespace core {

///////////////////////////////////////////////////////////////////////////////
//|=========================| Transform Components |========================|//
///////////////////////////////////////////////////////////////////////////////

//|=========================| TransformComponent |==========================|//

TransformComponent::TransformComponent() {
    _x = 0;
    _y = 0;
    _z = 0;
}

TransformComponent::TransformComponent(const float x, const float y,
                                       const float z) {
    _x = x;
    _y = y;
    _z = z;
}

TransformComponent* TransformComponent::setX(const float newX) {
    _x = newX;
    return this;
}

TransformComponent* TransformComponent::setY(const float newY) {
    _y = newY;
    return this;
}

TransformComponent* TransformComponent::setZ(const float newZ) {
    _z = newZ;
    return this;
}

//|=========================| TransformTranslate |==========================|//

glm::mat4 TransformTranslate::getTransformMatrix() const {
    return glm::translate(glm::mat4(1.0f), glm::vec3(_x, _y, _z));
}

const TransformTranslate
TransformTranslate::operator+(const TransformTranslate& rhs) {
    return TransformTranslate(_x + rhs.getX(), _y + rhs.getY(),
                              _z + rhs.getZ());
}

const TransformTranslate
TransformTranslate::operator-(const TransformTranslate& rhs) {
    return TransformTranslate(_x - rhs.getX(), _y - rhs.getY(),
                              _z - rhs.getZ());
}

TransformTranslate&
TransformTranslate::operator+=(const TransformTranslate& rhs) {
    _x += rhs.getX();
    _y += rhs.getY();
    _z += rhs.getZ();
    return *this;
}

TransformTranslate&
TransformTranslate::operator-=(const TransformTranslate& rhs) {
    _x -= rhs.getX();
    _y -= rhs.getY();
    _z -= rhs.getZ();
    return *this;
}

//|==========================| TransformRotate |============================|//

glm::mat4 TransformRotate::getTransformMatrix() const {
    glm::mat4 xMatrix =
        glm::rotate(glm::mat4(1.0f), _x, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 yMatrix = glm::rotate(xMatrix, _y, glm::vec3(0.0f, 1.0f, 0.0f));
    return glm::rotate(yMatrix, _z, glm::vec3(0.0f, 0.0f, 1.0f));
}

TransformRotate* TransformRotate::rotateAboutAxis(const float angle,
                                                  const glm::vec3 axis) {
    TransformRotate* newTrans;

    glm::vec3 rotAxis = glm::normalize(axis);

    glm::mat3 result(glm::rotate(getTransformMatrix(), angle, rotAxis));
    glm::vec3 eulerAngles = TransformRotate::eulerAnglesFromMatrix(result);
    float x = eulerAngles[0];
    float y = eulerAngles[1];
    float z = eulerAngles[2];

    return (TransformRotate*)newTrans->setX(x)->setY(y)->setZ(z);
}

glm::vec3
TransformRotate::eulerAnglesFromMatrix(const glm::mat4 rotationMatrix) {
    glm::mat3 convMatrix(rotationMatrix);
    float sy = glm::sqrt(convMatrix[0][0] * convMatrix[0][0] +
                         convMatrix[1][0] * convMatrix[1][0]);

    float x, y, z;
    if (sy >= ELLIPSOID_SINGULAR_VALUE_THRESHOLD) {
        x = glm::atan(convMatrix[2][1] / convMatrix[2][2]);
        y = glm::atan(-convMatrix[2][0] / sy);
        z = glm::atan(convMatrix[1][0] / convMatrix[0][0]);
    } else {
        x = glm::atan(-convMatrix[1][2] / convMatrix[1][1]);
        y = glm::atan(-convMatrix[2][0] / sy);
        z = 0;
    }
    return glm::vec3(x, y, z);
}

glm::vec3
TransformRotate::eulerAnglesFromMatrix(const glm::mat3 rotationMatrix) {
    float sy = glm::sqrt(rotationMatrix[0][0] * rotationMatrix[0][0] +
                         rotationMatrix[1][0] * rotationMatrix[1][0]);

    float x, y, z;
    if (sy >= ELLIPSOID_SINGULAR_VALUE_THRESHOLD) {
        x = glm::atan(rotationMatrix[2][1] / rotationMatrix[2][2]);
        y = glm::atan(-rotationMatrix[2][0] / sy);
        z = glm::atan(rotationMatrix[1][0] / rotationMatrix[0][0]);
    } else {
        x = glm::atan(-rotationMatrix[1][2] / rotationMatrix[1][1]);
        y = glm::atan(-rotationMatrix[2][0] / sy);
        z = 0;
    }
    return glm::vec3(x, y, z);
}

const TransformRotate TransformRotate::operator+(const TransformRotate& rhs) {
    return TransformRotate(_x + rhs.getX(), _y + rhs.getY(), _z + rhs.getZ());
}

const TransformRotate TransformRotate::operator-(const TransformRotate& rhs) {
    return TransformRotate(_x - rhs.getX(), _y - rhs.getY(), _z - rhs.getZ());
}

TransformRotate& TransformRotate::operator+=(const TransformRotate& rhs) {
    _x += rhs.getX();
    _y += rhs.getY();
    _z += rhs.getZ();
    return *this;
}

TransformRotate& TransformRotate::operator-=(const TransformRotate& rhs) {
    _x += rhs.getX();
    _y += rhs.getY();
    _z += rhs.getZ();
    return *this;
}

//|===========================| TransformScale |============================|//

glm::mat4 TransformScale::getTransformMatrix() const {
    return glm::scale(glm::mat4(1.0f), glm::vec3(_x, _y, _z));
}

const TransformScale TransformScale::operator+(const TransformScale& rhs) {
    return TransformScale(_x + rhs.getX(), _y + rhs.getY(), _z + rhs.getZ());
}

const TransformScale TransformScale::operator-(const TransformScale& rhs) {
    return TransformScale(_x - rhs.getX(), _y - rhs.getY(), _z - rhs.getZ());
}

TransformScale& TransformScale::operator+=(const TransformScale& rhs) {
    _x += rhs.getX();
    _y += rhs.getY();
    _z += rhs.getZ();
    return *this;
}

TransformScale& TransformScale::operator-=(const TransformScale& rhs) {
    _x += rhs.getX();
    _y += rhs.getY();
    _z += rhs.getZ();
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
//|===========================| General Transform |=========================|//
///////////////////////////////////////////////////////////////////////////////

Transform::Transform() {
    _translation = TransformTranslate();
    _rotation = TransformRotate();
    _scaling = TransformScale();
}

Transform* Transform::setTranslation(const TransformTranslate* trans) {
    _translation = *trans;
    return this;
}

Transform* Transform::setRotation(const TransformRotate* rot) {
    _rotation = *rot;
    return this;
}

Transform* Transform::setScaling(const TransformScale* scale) {
    _scaling = *scale;
    return this;
}

// (&_translation)
//     ->setX(_translation.getX() + x)
//     ->setY(_translation.getY() + y)
//     ->setZ(_translation.getZ() + z);
// return this;

Transform* Transform::translate(const float x, const float y, const float z) {
    _translation += TransformTranslate(x, y, z);
    return this;
}

Transform* Transform::rotate(const float x, const float y, const float z) {
    _rotation += TransformRotate(x, y, z);
    return this;
}

Transform* Transform::scale(const float x, const float y, const float z) {
    _scaling += TransformScale(x, y, z);
    return this;
}

glm::mat4 Transform::getTransformMatrix() const {
    return _scaling.getTransformMatrix() * _rotation.getTransformMatrix() *
           _translation.getTransformMatrix();
}

const Transform Transform::operator+(const TransformTranslate& rhs) {
    Transform copy = *this;
    copy._translation += rhs;
    return copy;
}

const Transform Transform::operator-(const TransformTranslate& rhs) {
    Transform copy = *this;
    copy._translation -= rhs;
    return copy;
}

const Transform Transform::operator+(const TransformRotate& rhs) {
    Transform copy = *this;
    copy._rotation += rhs;
    return copy;
}

const Transform Transform::operator-(const TransformRotate& rhs) {
    Transform copy = *this;
    copy._rotation -= rhs;
    return copy;
}

const Transform Transform::operator+(const TransformScale& rhs) {
    Transform copy = *this;
    copy._scaling += rhs;
    return copy;
}

const Transform Transform::operator-(const TransformScale& rhs) {
    Transform copy = *this;
    copy._scaling -= rhs;
    return copy;
}

const Transform Transform::operator+(const Transform& rhs) {
    Transform copy = *this;
    copy += rhs;
    return copy;
}

const Transform Transform::operator-(const Transform& rhs) {
    Transform copy = *this;
    copy -= rhs;
    return copy;
}

Transform& Transform::operator+=(const TransformTranslate& rhs) {
    _translation += rhs;
    return *this;
}

Transform& Transform::operator-=(const TransformTranslate& rhs) {
    _translation -= rhs;
    return *this;
}

Transform& Transform::operator+=(const TransformRotate& rhs) {
    _rotation += rhs;
    return *this;
}

Transform& Transform::operator-=(const TransformRotate& rhs) {
    _rotation -= rhs;
    return *this;
}

Transform& Transform::operator+=(const TransformScale& rhs) {
    _scaling += rhs;
    return *this;
}

Transform& Transform::operator-=(const TransformScale& rhs) {
    _scaling -= rhs;
    return *this;
}

Transform& Transform::operator+=(const Transform& rhs) {
    _translation += *rhs.getTranslation();
    _rotation += *rhs.getRotation();
    _scaling += *rhs.getScaling();
    return *this;
}

Transform& Transform::operator-=(const Transform& rhs) {
    _translation -= *rhs.getTranslation();
    _rotation -= *rhs.getRotation();
    _scaling -= *rhs.getScaling();
    return *this;
}

} // namespace core
} // namespace gl
} // namespace ellipsoid
