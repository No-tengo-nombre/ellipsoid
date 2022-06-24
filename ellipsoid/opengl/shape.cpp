#include "shape.hpp"
#include <iostream>

namespace ellipsoid {
namespace gl {

Shape::Shape() {
    _vao = VAO();
    _ebo = EBO();
    _material = Material();
    _texture = Texture2D();
    _vertices = std::vector<float>();
    _indices = std::vector<unsigned int>();
    _layouts = std::vector<unsigned int>();
    _vertSizes = std::vector<unsigned int>();
    _count = 0;
}

Shape& Shape::material(const Material material) {
    _material = material;
    return *this;
}

Shape& Shape::texture(const Texture2D texture) {
    _texture = texture;
    return *this;
}

Shape& Shape::vertices(const std::vector<float> verts) {
    _vertices = verts;
    return *this;
}

Shape& Shape::indices(const std::vector<unsigned int> inds) {
    _indices = inds;
    return *this;
}

Shape& Shape::layouts(const std::vector<unsigned int> lays) {
    _layouts = lays;
    return *this;
}

Shape& Shape::vertSizes(const std::vector<unsigned int> sizes) {
    _vertSizes = sizes;
    return *this;
}

Shape& Shape::count(const unsigned int newCount) {
    _count = newCount;
    return *this;
}

Shape& Shape::usage(const GLenum newUsage) {
    _usage = newUsage;
    return *this;
}

Shape& Shape::drawMode(const GLenum newDrawMode) {
    _drawMode = newDrawMode;
    return *this;
}

Shape& Shape::build() {
    VAO vao = VAO().stride<float>().sizes(_vertSizes).build();
    vao.bind();
    VBO vbo = VBO().vertices(_vertices).usage(_usage).build();
    vbo.bind();
    EBO ebo = EBO().indices(_indices).count(_count).usage(_usage).build();

    for (unsigned int l : _layouts) {
        vao.linkVBO(&vbo, l);
    }

    vao.unbind();
    vbo.unbind();
    ebo.unbind();
    _vao = vao;
    _ebo = ebo;

    return *this;
}

void Shape::useMaterial() const {
    _material.use();
}

void Shape::bindVAO() const {
    _vao.bind();
}

void Shape::bindEBO() const {
    _ebo.bind();
}

void Shape::bindTexture() const {
    _texture.bind();
}

void Shape::unbindVAO() const {
    _vao.unbind();
}

void Shape::unbindEBO() const {
    _ebo.unbind();
}

void Shape::unbindTexture() const {
    _texture.unbind();
}

void Shape::del() const {
    _vao.del();
    _ebo.del();
    _material.del();
    std::cout << "FASDF SD SF" << std::endl;
}

void Shape::draw() const {
    useMaterial();
    bindVAO();
    bindEBO();
    bindTexture();

    glDrawElements(_drawMode, _count, GL_UNSIGNED_INT, 0);

    unbindVAO();
    unbindEBO();
    unbindTexture();
}

} // namespace gl
} // namespace ellipsoid
