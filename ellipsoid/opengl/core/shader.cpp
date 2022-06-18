#include "shader.hpp"
#include <fstream>
#include <glm/glm.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace ellipsoid {
namespace gl {
namespace core {

void Shader::verifyProgram(const std::string message) const {
    int success = 0;
    std::cout << success << std::endl;
    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    std::cout << success << std::endl;
    if (!success) {
        char log[ELLIPSOID_GL_SHADER_LOG_LEN];
        int logLen = 0;
        glGetProgramInfoLog(_id, ELLIPSOID_GL_SHADER_LOG_LEN, NULL, log);

        std::string out_msg = log;
        throw std::runtime_error(message + "\n" + out_msg);
    }
}

void Shader::verifyShader(unsigned int shader, std::string message) {
    Shader::verifyShader(shader, message, GL_COMPILE_STATUS);
}

void Shader::verifyShader(unsigned int shader, std::string message,
                          GLenum status) {
    int success = 0;
    glGetShaderiv(shader, status, &success);
    if (!success) {
        char log[ELLIPSOID_GL_SHADER_LOG_LEN];
        int logLen = 0;
        glGetShaderInfoLog(shader, ELLIPSOID_GL_SHADER_LOG_LEN, NULL, log);

        std::string out_msg = log;
        throw std::runtime_error(message + "\n" + out_msg);
    }
}

unsigned int Shader::makeShader(std::string content, GLenum shader_type) {
    unsigned int shader = glCreateShader(shader_type);
    const char* content_char = content.c_str();
    glShaderSource(shader, 1, &content_char, NULL);
    glCompileShader(shader);
    return shader;
}

Shader::Shader() { _id = 0; }

Shader::~Shader() { del(); }

Shader* Shader::vertex(std::string path) {
    std::ifstream file;
    std::stringstream stream;
    std::string code;
    try {
        file.open(path);
        stream << file.rdbuf();
        file.close();
        code = stream.str();
    } catch (const std::ifstream::failure& e) {
        std::cout << "ERROR: Shader file " << path << " not found" << std::endl;
        throw;
    }

    unsigned int shader = Shader::makeVertexShader(code);
    Shader::verifyVertexShader(shader);

    glAttachShader(_id, shader);
    glLinkProgram(_id);

    Shader::verifyProgram("VERTEX Link status");
    glDeleteShader(shader);
    return this;
}

Shader* Shader::fragment(std::string path) {
    std::ifstream file;
    std::stringstream stream;
    std::string code;
    try {
        file.open(path);
        stream << file.rdbuf();
        file.close();
        code = stream.str();
    } catch (const std::ifstream::failure& e) {
        std::cout << "ERROR: Shader file " << path << " not found" << std::endl;
        throw;
    }

    unsigned int shader = Shader::makeFragmentShader(code);
    Shader::verifyFragmentShader(shader);

    glAttachShader(_id, shader);
    glLinkProgram(_id);

    Shader::verifyProgram("FRAGMENT Link status");
    glDeleteShader(shader);
    return this;
}

void Shader::use() const { glUseProgram(_id); }

void Shader::del() const { glDeleteShader(_id); }

// Setting uniforms

Shader const* Shader::setUniform(std::string name, int v1) const {
    glUniform1i(glGetUniformLocation(_id, name.c_str()), v1);
    return this;
}

Shader const* Shader::setUniform(std::string name, int v1, int v2) const {
    glUniform2i(glGetUniformLocation(_id, name.c_str()), v1, v2);
    return this;
}

Shader const* Shader::setUniform(std::string name, int v1, int v2,
                                 int v3) const {
    glUniform3i(glGetUniformLocation(_id, name.c_str()), v1, v2, v3);
    return this;
}

Shader const* Shader::setUniform(std::string name, int v1, int v2, int v3,
                                 int v4) const {
    glUniform4i(glGetUniformLocation(_id, name.c_str()), v1, v2, v3, v4);
    return this;
}

Shader const* Shader::setUniform(std::string name, float v1) const {
    glUniform1f(glGetUniformLocation(_id, name.c_str()), v1);
    return this;
}

Shader const* Shader::setUniform(std::string name, float v1, float v2) const {
    glUniform2f(glGetUniformLocation(_id, name.c_str()), v1, v2);
    return this;
}

Shader const* Shader::setUniform(std::string name, float v1, float v2,
                                 float v3) const {
    glUniform3f(glGetUniformLocation(_id, name.c_str()), v1, v2, v3);
    return this;
}

Shader const* Shader::setUniform(std::string name, float v1, float v2, float v3,
                                 float v4) const {
    glUniform4f(glGetUniformLocation(_id, name.c_str()), v1, v2, v3, v4);
    return this;
}

Shader const* Shader::setUniform(std::string name, glm::mat4 v1) const {
    glUniformMatrix4fv(glGetUniformLocation(_id, name.c_str()), 1, GL_FALSE,
                       (float*)&v1);
    return this;
}

} // namespace core
} // namespace gl
} // namespace ellipsoid