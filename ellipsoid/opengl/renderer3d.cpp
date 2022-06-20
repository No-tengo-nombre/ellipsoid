#include "renderer.hpp"

namespace ellipsoid {
namespace gl {

Renderer3D::Renderer3D() { _clearColor = ColorRGBAfloat(0.0f, 0.0f, 0.0f); }

Renderer3D* Renderer3D::clearColor(ColorRGBAfloat color) {
    _clearColor = color;
    glClearColor(color[0], color[1], color[2], color[3]);
    return this;
}

Renderer3D* Renderer3D::clearColor(ColorRGBA255 color) {
    _clearColor = color.asRGBAfloat();
    glClearColor(_clearColor[0], _clearColor[1], _clearColor[2], _clearColor[3]);
    return this;
}

Renderer3D* Renderer3D::add(const Shape item) {
    _items.push_back(item);
    return this;
}

void Renderer3D::render() const {
    // TODO: Implement batch rendering
    for (Shape s : _items) {
        draw(s);
    }
}

void Renderer3D::draw(const Shape item) const { item.draw(); }

const Renderer3D* Renderer3D::polygonMode(const GLenum face,
                                          const GLenum mode) const {
    glPolygonMode(face, mode);
    return this;
}

void Renderer3D::clear() const {
    glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);
}

} // namespace gl
} // namespace ellipsoid
