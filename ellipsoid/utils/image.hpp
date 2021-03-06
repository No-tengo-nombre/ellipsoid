#ifndef ELLIPSOID_UTILS_IMAGE_HEADER
#define ELLIPSOID_UTILS_IMAGE_HEADER

#include <string>

namespace ellipsoid {
namespace utils {

struct Image {
public:
    int _width;
    int _height;
    int _channels;
    unsigned char* _data;

    Image();
    Image(const int width, const int height, const int channels,
          unsigned char* data);
//     ~Image();

    void load(const int width, const int height, const int channels,
              unsigned char* data);
};

Image loadImage(const std::string path);

} // namespace utils
} // namespace ellipsoid

#endif
