#include "image.hpp"

namespace ellipsoid {
namespace utils {

Image::Image(int width, int height, int channels, unsigned char* data) {
    _width = width;
    _height = height;
    _channels = channels;
    _data = data;
}

Image loadImage(std::string path) {
    int width;
    int height;
    int channels;
    unsigned char* data =
        stbi_load(path.c_str(), &width, &height, &channels, 0);
    return Image(width, height, channels, data);
}

} // namespace utils
} // namespace ellipsoid