#ifndef ELLIPSOID_GL_SHADER_HEADER
#define ELLIPSOID_GL_SHADER_HEADER

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>

#define ELLIPSOID_GL_SHADER_LOG_LEN 1024

namespace ellipsoid {
namespace gl {

/* Class for a shader program */
class Shader {
private:
    unsigned int _id;

    static void verifyShader(unsigned int shader, std::string message);
    static void verifyShader(unsigned int shader, std::string message,
                             GLenum status);
    static void verifyVertexShader(unsigned int shader) {
        verifyShader(shader, "VERTEX compile error");
    }
    static void verifyVertexShader(unsigned int shader, GLenum status) {
        verifyShader(shader, "VERTEX compile error", status);
    }
    static void verifyFragmentShader(unsigned int shader) {
        verifyShader(shader, "FRAGMENT compile error");
    }
    static void verifyFragmentShader(unsigned int shader, GLenum status) {
        verifyShader(shader, "FRAGMENT compile error", status);
    }

    static unsigned int makeShader(std::string content, GLenum shader_type);
    static unsigned int makeVertexShader(std::string content) {
        return makeShader(content, GL_VERTEX_SHADER);
    }
    static unsigned int makeFragmentShader(std::string content) {
        return makeShader(content, GL_FRAGMENT_SHADER);
    }

public:
    Shader();
    ~Shader();

    Shader* vertex(std::string path);
    Shader* fragment(std::string path);

    void use() const;
    void del() const;

    // Bunch of methods to set uniforms
    // TODO: Figure out a way to make this easier to work with
    Shader const* setUniform(std::string name, int v1) const;
    Shader const* setUniform(std::string name, int v1, int v2) const;
    Shader const* setUniform(std::string name, int v1, int v2, int v3) const;
    Shader const* setUniform(std::string name, int v1, int v2, int v3, int v4) const;

    Shader const* setUniform(std::string name, float v1) const;
    Shader const* setUniform(std::string name, float v1, float v2) const;
    Shader const* setUniform(std::string name, float v1, float v2, float v3) const;
    Shader const* setUniform(std::string name, float v1, float v2, float v3,
                    float v4) const;

    Shader const* setUniform(std::string name, glm::mat4 v1) const;
};

} // namespace gl
} // namespace ellipsoid

#endif
