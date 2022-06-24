#ifndef ELLIPSOID_GL_CORE_TRANSFORM_HEADER
#define ELLIPSOID_GL_CORE_TRANSFORM_HEADER

#include <glm/glm.hpp>

namespace ellipsoid {
namespace gl {
namespace core {

class TransformComponent {
protected:
    float _x;
    float _y;
    float _z;

public:
    TransformComponent();
    TransformComponent(const glm::vec3 vector);
    TransformComponent(const float x, const float y, const float z);

    float getX() const { return _x; }
    float getY() const { return _y; }
    float getZ() const { return _z; }

    TransformComponent& setX(const float newX);
    TransformComponent& setY(const float newY);
    TransformComponent& setZ(const float newZ);

    glm::vec3 asVector() const;

    virtual glm::mat4 getTransformMatrix() const = 0;
};

/* Translation component of a transform */
class TransformTranslate : public TransformComponent {
public:
    TransformTranslate() : TransformComponent() {}
    TransformTranslate(const glm::vec3 vector) : TransformComponent(vector) {}
    TransformTranslate(const float x, const float y, const float z)
        : TransformComponent(x, y, z) {}

    glm::mat4 getTransformMatrix() const override;

    const TransformTranslate operator+(const TransformTranslate& rhs);
    const TransformTranslate operator-(const TransformTranslate& rhs);
    TransformTranslate& operator+=(const TransformTranslate& rhs);
    TransformTranslate& operator-=(const TransformTranslate& rhs);
};

/* Rotation component of a transform */
class TransformRotate : public TransformComponent {
public:
    TransformRotate() : TransformComponent() {}
    TransformRotate(const glm::vec3 vector) : TransformComponent(vector) {}
    TransformRotate(const float x, const float y, const float z)
        : TransformComponent(x, y, z) {}

    glm::mat4 getTransformMatrix() const override;

    TransformRotate& rotateAboutAxis(const float angle, const glm::vec3 axis);
    static glm::vec3 eulerAnglesFromMatrix(const glm::mat4 rotationMatrix);
    static glm::vec3 eulerAnglesFromMatrix(const glm::mat3 rotationMatrix);

    const TransformRotate operator+(const TransformRotate& rhs);
    const TransformRotate operator-(const TransformRotate& rhs);
    TransformRotate& operator+=(const TransformRotate& rhs);
    TransformRotate& operator-=(const TransformRotate& rhs);
};

/* Scaling component of a transform */
class TransformScale : public TransformComponent {
public:
    TransformScale() : TransformComponent() {}
    TransformScale(const glm::vec3 vector) : TransformComponent(vector) {}
    TransformScale(const float x, const float y, const float z)
        : TransformComponent(x, y, z) {}

    glm::mat4 getTransformMatrix() const override;

    const TransformScale operator+(const TransformScale& rhs);
    const TransformScale operator-(const TransformScale& rhs);
    TransformScale& operator+=(const TransformScale& rhs);
    TransformScale& operator-=(const TransformScale& rhs);
};

/* General transform for an object */
class Transform {
private:
    TransformTranslate _translation;
    TransformRotate _rotation;
    TransformScale _scaling;

public:
    Transform();

    TransformTranslate const* getTranslation() const { return &_translation; }
    TransformRotate const* getRotation() const { return &_rotation; }
    TransformScale const* getScaling() const { return &_scaling; }

    Transform& setTranslation(const TransformTranslate& trans);
    Transform& setRotation(const TransformRotate& rot);
    Transform& setScaling(const TransformScale& scale);

    Transform& translate(const glm::vec3 vector);
    Transform& rotate(const glm::vec3 vector);
    Transform& scale(const glm::vec3 vector);
    Transform& translate(const float x, const float y, const float z);
    Transform& rotate(const float x, const float y, const float z);
    Transform& scale(const float x, const float y, const float z);

    glm::mat4 getTransformMatrix() const;

    const Transform operator+(const TransformTranslate& rhs);
    const Transform operator-(const TransformTranslate& rhs);
    const Transform operator+(const TransformRotate& rhs);
    const Transform operator-(const TransformRotate& rhs);
    const Transform operator+(const TransformScale& rhs);
    const Transform operator-(const TransformScale& rhs);
    const Transform operator+(const Transform& rhs);
    const Transform operator-(const Transform& rhs);
    Transform& operator+=(const TransformTranslate& rhs);
    Transform& operator-=(const TransformTranslate& rhs);
    Transform& operator+=(const TransformRotate& rhs);
    Transform& operator-=(const TransformRotate& rhs);
    Transform& operator+=(const TransformScale& rhs);
    Transform& operator-=(const TransformScale& rhs);
    Transform& operator+=(const Transform& rhs);
    Transform& operator-=(const Transform& rhs);
};

} // namespace core
} // namespace gl
} // namespace ellipsoid

#endif
