#ifndef ELLIPSOID_GL_CAMERA_HEADER
#define ELLIPSOID_GL_CAMERA_HEADER

#define ELLIPSOID_GL_CAMERA_UBO_INDEX 0

#include "buffers/buffers.hpp"
#include "core/transform.hpp"
#include <glm/glm.hpp>

namespace ellipsoid {
namespace gl {

using namespace buffers;
using namespace core;

class Camera {
protected:
    glm::vec3 _position;
    glm::vec3 _direction;
    glm::vec3 _up;
    Transform _transform;
    UBO _ubo = makeUBO();

    static UBO makeUBO();

public:
    glm::vec3 getPosition() const { return _position; };
    glm::vec3 getDirection() const { return _direction; };
    glm::vec3 getUp() const { return _up; };
    glm::vec3 getRight() const { return glm::cross(_up, _direction); };
    Transform getTransform() const { return _transform; };

    glm::vec3 calculatePosition() const;
    glm::vec3 calculateDirection() const;
    glm::vec3 calculateUp() const;
    glm::vec3 calculateRight() const;

    void translate(const glm::vec3 target);
    void rotate(const glm::vec3 target);
    void translate(const float x, const float y, const float z);
    void rotate(const float x, const float y, const float z);

    glm::mat4 getMVP() const;
    void update();
    void updateUBO(const unsigned int index);

    virtual glm::mat4 getProjectionMatrix() const = 0;
};

class OrthographicCamera : public Camera {
private:
    float _xMin;
    float _xMax;
    float _yMin;
    float _yMax;
    float _zMin;
    float _zMax;

public:
    OrthographicCamera();
    OrthographicCamera(const float xMin, const float xMax, const float yMin,
                       const float yMax, const float zMin, const float zMax);

    OrthographicCamera& setXMin(const float xMin);
    OrthographicCamera& setXMax(const float xMax);
    OrthographicCamera& setYMin(const float yMin);
    OrthographicCamera& setYMax(const float yMax);
    OrthographicCamera& setZMin(const float zMin);
    OrthographicCamera& setZMax(const float zMax);
    OrthographicCamera& setPosition(const glm::vec3 position);
    OrthographicCamera& setDirection(const glm::vec3 direction);
    OrthographicCamera& setUp(const glm::vec3 up);

    glm::mat4 getProjectionMatrix() const override;
};

class PerspectiveCamera : public Camera {
private:
    float _xMin;
    float _xMax;
    float _yMin;
    float _yMax;
    float _zMin;
    float _zMax;

public:
    PerspectiveCamera();
    PerspectiveCamera(const float xMin, const float xMax, const float yMin,
                      const float yMax, const float zMin, const float zMax);

    PerspectiveCamera& setXMin(const float xMin);
    PerspectiveCamera& setXMax(const float xMax);
    PerspectiveCamera& setYMin(const float yMin);
    PerspectiveCamera& setYMax(const float yMax);
    PerspectiveCamera& setZMin(const float zMin);
    PerspectiveCamera& setZMax(const float zMax);
    PerspectiveCamera& setPosition(const glm::vec3 position);
    PerspectiveCamera& setDirection(const glm::vec3 direction);
    PerspectiveCamera& setUp(const glm::vec3 up);

    glm::mat4 getProjectionMatrix() const override;
};

} // namespace gl
} // namespace ellipsoid

#endif