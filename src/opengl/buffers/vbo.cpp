#include "buffers.hpp"

namespace ellipsoid {
namespace gl {
namespace buffers {

VBO::VBO() {
    _id = 0;
    _vertices = std::vector<float>();
    _usage = GL_STATIC_DRAW;
}

VBO::~VBO() { del(); }

VBO* VBO::vertices(std::vector<float> newVertices) {
    _vertices = newVertices;
    return this;
}

VBO* VBO::usage(GLenum newUsage) {
    _usage = newUsage;
    return this;
}

VBO* VBO::build() {
    unsigned int vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    bufferData(_vertices);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    _id = vbo;
    return this;
}

void VBO::bufferData(std::vector<float> data) {
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), &data, _usage);
}

void VBO::bind() const { glBindBuffer(GL_ARRAY_BUFFER, _id); }

void VBO::unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

void VBO::del() const { glDeleteBuffers(1, &_id); }

} // namespace buffers
} // namespace gl
} // namespace ellipsoid
