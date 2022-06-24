#ifndef ELLIPSOID_GL_BUFFERS_BUFFERS_HEADER
#define ELLIPSOID_GL_BUFFERS_BUFFERS_HEADER

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <vector>

namespace ellipsoid {
namespace gl {
namespace buffers {

class VBO {
private:
    unsigned int _id;
    std::vector<float> _vertices;
    GLenum _usage;

public:
    VBO();

    unsigned int getId() { return _id; };

    VBO& vertices(std::vector<float> newVertices);
    VBO& usage(GLenum newUsage);
    VBO& build();

    void bufferData(std::vector<float> data);

    void bind() const;
    void unbind() const;
    void del() const;
};

class VAO {
private:
    unsigned int _id;
    unsigned int _stride;
    unsigned int _size;
    std::vector<unsigned int> _sizes;

public:
    VAO();

    unsigned int getId() { return _id; };

    VAO& stride(unsigned int newStride);
    template <typename T> VAO& stride();
    VAO& size(unsigned int newSize);
    VAO& sizes(std::vector<unsigned int> newSizes);
    VAO& build();

    void linkVBO(VBO* vbo, unsigned int layout) const;

    void bind() const;
    void unbind() const;
    void del() const;
};

class EBO {
private:
    unsigned int _id;
    unsigned int _count;
    std::vector<unsigned int> _indices;
    GLenum _usage;

public:
    EBO();

    unsigned int getId() { return _id; };

    EBO& count(unsigned int newCount);
    EBO& indices(std::vector<unsigned int> newIndices);
    EBO& usage(GLenum newUsage);
    EBO& build();

    void bufferData(std::vector<unsigned int> data);

    void bind() const;
    void unbind() const;
    void del() const;
};

class UBO {
private:
    unsigned int _id;
    unsigned int _size;
    GLenum _usage;

public:
    UBO();

    unsigned int getId() { return _id; };

    UBO& size(const unsigned int newSize);
    UBO& usage(const GLenum newUsage);
    UBO& build();

    void bindIndex(const unsigned int index);
    template <typename T>
    void bufferData(const unsigned int offset, const std::vector<T> data);
    void bufferData(const unsigned int offset, const glm::mat4 data);

    void bind() const;
    void unbind() const;
    void del() const;
};

} // namespace buffers
} // namespace gl
} // namespace ellipsoid

#endif
