#ifndef ELLIPSOID_GL_RENDERER_HEADER
#define ELLIPSOID_GL_RENDERER_HEADER

#include "ellipsoid/utils/color.hpp"
#include "shape.hpp"
#include <glad/gl.h>
#include <vector>

namespace ellipsoid {
namespace gl {

using namespace ellipsoid::utils;

class Renderer2D {};

class Renderer3D {
private:
    ColorRGBA _clearColor;
    std::vector<Shape> _items;

public:
    Renderer3D();

    ColorRGBA getClearColor() const { return _clearColor; };
    Renderer3D* clearColor(ColorRGBA color);

    Renderer3D* add(const Shape item);
    void render() const;
    void draw(const Shape item) const;
    const Renderer3D* polygonMode(const GLenum face, const GLenum mode) const;

    Shape& operator[](size_t index) { return _items[index]; }

    void clear() const;
};

} // namespace gl
} // namespace ellipsoid

#endif
