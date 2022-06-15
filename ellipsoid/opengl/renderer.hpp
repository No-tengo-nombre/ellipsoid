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
    Renderer3D* setClearColor(const ColorRGBA color);

    void render() const;
    Renderer3D* add(const Shape item);
    Renderer3D* add(const Shape item, const GLenum drawMode);
    void draw(const Shape item) const;
    void draw(const Shape item, const GLenum drawMode) const;
    Renderer3D polygonMode(const GLenum mode) const;

    Shape& operator[](size_t index) { return _items[index]; }

    void clear() const;
};

} // namespace gl
} // namespace ellipsoid

#endif
