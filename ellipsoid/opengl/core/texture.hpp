#ifndef ELLIPSOID_GL_CORE_TEXTURE_HEADER
#define ELLIPSOID_GL_CORE_TEXTURE_HEADER

#include <ellipsoid/utils/image.hpp>
#include <string>

namespace ellipsoid {
namespace gl {
namespace core {

class Texture2D {
private:
    unsigned int _id;
    utils::Image* _image = nullptr;

    static void loadTexture(unsigned int& id, const unsigned int slot,
                            const unsigned int width, const unsigned int height,
                            const unsigned int channels,
                            const unsigned char* data);

public:
    Texture2D();
    Texture2D(const std::string path);
    ~Texture2D();

    Texture2D* loadFromPath(const std::string path);
    Texture2D* build();
    Texture2D* build(unsigned int slot);

    void bind() const;
    void unbind() const;
};

class Texture3D {};

} // namespace core
} // namespace gl
} // namespace ellipsoid

#endif
