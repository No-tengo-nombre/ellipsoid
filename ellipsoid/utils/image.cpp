#define STB_IMAGE_IMPLEMENTATION

#include "image.hpp"
#include <stb_image.h>

namespace ellipsoid {
namespace utils {

Image::Image() {
    _width = 0;
    _height = 0;
    _channels = 0;
    _data = nullptr;
}

Image::Image(const int width, const int height, const int channels,
             unsigned char* data) {
    _width = width;
    _height = height;
    _channels = channels;
    _data = data;
}

void Image::load(const int width, const int height, const int channels,
                 unsigned char* data) {
    _width = width;
    _height = height;
    _channels = channels;
    _data = data;
}

// Image::~Image() { stbi_image_free(_data); }

Image loadImage(const std::string path) {
    int width;
    int height;
    int channels;
    unsigned char* data =
        stbi_load(path.c_str(), &width, &height, &channels, 0);
    return Image(width, height, channels, data);
}

} // namespace utils
} // namespace ellipsoid