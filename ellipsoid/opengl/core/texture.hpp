#ifndef ELLIPSOID_GL_CORE_TEXTURE_HEADER
#define ELLIPSOID_GL_CORE_TEXTURE_HEADER

#include <string>

namespace ellipsoid {
namespace gl {
namespace core {

class Texture2D {
private:
    unsigned int _id;

    static void loadTexture(unsigned int& id, const unsigned int slot,
                            const unsigned int width, const unsigned int height,
                            const unsigned int channels, const char* data);

public:
    Texture2D();
    Texture2D(const std::string path);

    Texture2D* loadFromPath(const std::string path);

    void bind() const;
    void unbind() const;
};

class Texture3D {};

} // namespace core
} // namespace gl
} // namespace ellipsoid

#endif
