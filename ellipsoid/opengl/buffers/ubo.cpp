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

UBO* UBO::size(const unsigned int newSize) {
    _size = newSize;
    return this;
}

UBO* UBO::usage(const GLenum newUsage) {
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

void UBO::bindIndex(const unsigned int index) {
    glBindBufferBase(GL_UNIFORM_BUFFER, index, _id);
}

template <typename T>
void UBO::bufferData(const unsigned int offset, const std::vector<T> data) {
    bind();
    glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(T) * data.size(), &data);
    unbind();
}

template void UBO::bufferData<float>(const unsigned int offset,
                                     const std::vector<float> data);
template void
UBO::bufferData<unsigned int>(const unsigned int offset,
                              const std::vector<unsigned int> data);

void UBO::bufferData(const unsigned int offset, const glm::mat4 data) {
    bind();
    glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(glm::mat4), &data);
}

void UBO::bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id); }

void UBO::unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

void UBO::del() const { glDeleteBuffers(1, &_id); }

} // namespace buffers
} // namespace gl
} // namespace ellipsoid
