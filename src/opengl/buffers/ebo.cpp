#include "buffers.hpp"
#include <glad/glad.h>

namespace ellipsoid {
namespace gl {
namespace buffers {

EBO::EBO() {
    _id = 0;
    _count = 0;
    _indices = std::vector<unsigned int>();
    _usage = GL_STATIC_DRAW;
}

EBO::~EBO() { del(); }

EBO& EBO::count(unsigned int newCount) {
    _count = newCount;
    return *this;
}

EBO& EBO::indices(std::vector<unsigned int> newIndices) {
    _indices = newIndices;
    return *this;
}

EBO& EBO::usage(GLenum newUsage) {
    _usage = newUsage;
    return *this;
}

EBO& EBO::build() {
    unsigned int ebo = 0;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    bufferData(_indices);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    _id = ebo;
    return *this;
}

void EBO::bufferData(std::vector<unsigned int> data) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * data.size(), &data, _usage);
}

void EBO::bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); }

void EBO::unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

void EBO::del() const { glDeleteBuffers(1, &_id); }

} // namespace buffers
} // namespace gl
} // namespace ellipsoid
