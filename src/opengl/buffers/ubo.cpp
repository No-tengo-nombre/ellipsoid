#include "buffers.hpp"

namespace ellipsoid {
namespace gl {
namespace buffers {

UBO::UBO() {
    _id = 0;
    _size = 0;
    _usage = GL_STATIC_DRAW;
}

UBO::~UBO() { del(); }

UBO* UBO::size(unsigned int newSize) {
    _size = newSize;
    return this;
}

UBO* UBO::usage(GLenum newUsage) {
    _usage = newUsage;
    return this;
}

UBO* UBO::build() {
    unsigned int ubo = 0;
    glGenBuffers(1, &ubo);
    glBindBuffer(GL_UNIFORM_BUFFER, ubo);
    glBufferData(GL_UNIFORM_BUFFER, _size, (void*)0, _usage);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    _id = ubo;
    return this;
}

template <typename T>
void UBO::bufferData(unsigned int offset, std::vector<T> data) {
    bind();
    glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(T) * data.size(), &data);
    unbind();
}

void UBO::bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); }

void UBO::unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

void UBO::del() const { glDeleteBuffers(1, &_id); }

} // namespace buffers
} // namespace gl
} // namespace ellipsoid
