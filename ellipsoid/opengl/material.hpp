#ifndef ELLIPSOID_GL_MATERIAL_HEADER
#define ELLIPSOID_GL_MATERIAL_HEADER

#include "core/shader.hpp"

namespace ellipsoid {
namespace gl {

class Material {
private:
    core::Shader _shader;

public:
    Material();

    Material& setShader(const core::Shader shader);
    Material& build();

    void use() const;
    void del() const;
};

} // namespace gl
} // namespace ellipsoid

#endif
