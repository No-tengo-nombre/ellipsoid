#include "material.hpp"

namespace ellipsoid {
namespace gl {

Material::Material() {
    _shader = core::Shader();
};

Material::~Material() {
    del();
}

Material* Material::setShader(const core::Shader shader) {
    _shader = shader;
    return this;
}

Material* Material::build() {
    return this;
}

void Material::use() const {
    _shader.use();
}

void Material::del() const {
    _shader.del();
}

} // namespace gl
} // namespace ellipsoid
