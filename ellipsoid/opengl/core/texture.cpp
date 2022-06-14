#include "texture.hpp"
#include <glad/gl.h>

namespace ellipsoid {
namespace gl {
namespace core {

Texture2D::Texture2D() { _id = 0; }

Texture2D::Texture2D(const std::string path) {
    unsigned int id = 0;
}

void Texture2D::bind() const { glBindTexture(GL_TEXTURE_2D, _id); }

void Texture2D::unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }

void Texture2D::loadTexture(unsigned int& id, const unsigned int slot,
                            const unsigned int width, const unsigned int height,
                            const unsigned int channels, const char* data) {
    glGenTextures(GL_TEXTURE_2D, &id);
    glActiveTexture(slot);
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
}

} // namespace core
} // namespace gl
} // namespace ellipsoid
