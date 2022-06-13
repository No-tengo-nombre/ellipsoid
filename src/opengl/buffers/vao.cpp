#include "buffers.hpp"
#include <glad/glad.h>

namespace ellipsoid {
namespace gl {
namespace buffers {

VAO::VAO() {
    _id = 0;
    _stride = 0;
    _size = 0;
    _sizes = std::vector<unsigned int>();
}

VAO::~VAO() { del(); }

VAO* VAO::stride(unsigned int newStride) {
    _stride = newStride;
    return this;
}

template <typename T> VAO* VAO::stride() {
    _stride = sizeof(T);
    return this;
}

VAO* VAO::size(unsigned int newSize) {
    _size = newSize;
    return this;
}

VAO* VAO::sizes(std::vector<unsigned int> newSizes) {
    _sizes = newSizes;
    return this;
}

VAO* VAO::build() {
    unsigned int vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    _id = vao;
    return this;
}

void VAO::linkVBO(VBO* vbo, unsigned int layout) const {
    vbo->bind();
    if (_sizes.empty()) {
        glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, _stride,
                              (void*)(3 * _size * layout));
    } else {
        glVertexAttribPointer(layout, _sizes[layout], GL_FLOAT, GL_FALSE,
                              _stride,
                              (void*)(_sizes[layout] * _size * layout));
    }
    glEnableVertexAttribArray(layout);
    vbo->unbind();
}

void VAO::bind() const { glBindVertexArray(_id); }

void VAO::unbind() const { glBindVertexArray(0); }

void VAO::del() const { glDeleteBuffers(1, &_id); }

} // namespace buffers
} // namespace gl
} // namespace ellipsoid
