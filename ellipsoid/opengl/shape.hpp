#ifndef ELLIPSOID_GL_SHAPE_HEADER
#define ELLIPSOID_GL_SHAPE_HEADER

#include "buffers/buffers.hpp"
#include "core/texture.hpp"
#include "material.hpp"
#include <glad/gl.h>
#include <vector>

namespace ellipsoid {
namespace gl {

using namespace ellipsoid::gl::buffers;
using namespace ellipsoid::gl::core;

class Shape {
private:
    VAO _vao;
    EBO _ebo;
    Material _material;
    Texture2D _texture;
    std::vector<float> _vertices;
    std::vector<unsigned int> _indices;
    std::vector<unsigned int> _layouts;
    std::vector<unsigned int> _vertSizes;
    unsigned int _count;
    GLenum _usage = GL_STATIC_DRAW;
    GLenum _drawMode = GL_TRIANGLES;

public:
    Shape();

    GLenum getDrawMode() const { return _drawMode; };

    Shape& material(const Material material);
    Shape& texture(const Texture2D texture);
    Shape& vertices(const std::vector<float> verts);
    Shape& indices(const std::vector<unsigned int> inds);
    Shape& layouts(const std::vector<unsigned int> lays);
    Shape& vertSizes(const std::vector<unsigned int> sizes);
    Shape& count(const unsigned int newCount);
    Shape& usage(const GLenum newUsage);
    Shape& drawMode(const GLenum newDrawMode);

    Shape& build();

    void useMaterial() const;
    void bindVAO() const;
    void bindEBO() const;
    void bindTexture() const;
    void unbindVAO() const;
    void unbindEBO() const;
    void unbindTexture() const;

    void del() const;

    void draw() const;
};

} // namespace gl
} // namespace ellipsoid

#endif
