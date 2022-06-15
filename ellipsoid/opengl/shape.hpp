#ifndef ELLIPSOID_GL_SHAPE_HEADER
#define ELLIPSOID_GL_SHAPE_HEADER

#include "buffers/buffers.hpp"

namespace ellipsoid {
namespace gl {

using namespace buffers;

class Shape {
private:
    VAO _vao;
    EBO _ebo;
};

} // namespace gl
} // namespace ellipsoid

#endif
