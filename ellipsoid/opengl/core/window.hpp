#ifndef ELLIPSOID_GL_CORE_WINDOW_HEADER
#define ELLIPSOID_GL_CORE_WINDOW_HEADER

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>

namespace ellipsoid {
namespace gl {
namespace core {

enum WindowMode {
    Windowed,
    FullScreen,
};

class Window {
private:
    unsigned int _width;
    unsigned int _height;
    std::string _title;
    WindowMode _mode;
    GLFWwindow* _glfwWindow = nullptr;
    unsigned int _glVersionMajor = 4;
    unsigned int _glVersionMinor = 6;
    int _glProfile = GLFW_OPENGL_CORE_PROFILE;
    bool _depthTest = true;

    bool init() const;
    void terminate() const;

public:
    Window();
    Window(const unsigned int width, const unsigned int height,
           const std::string title, const WindowMode mode);

    Window* dimensions(const unsigned int newWidth,
                       const unsigned int newHeight);
    Window* width(const unsigned int newWidth);
    Window* height(const unsigned int newHeight);
    Window* title(const std::string newTitle);
    Window* mode(const WindowMode newMode);
    Window* windowed();
    Window* fullScreen();
    Window* glVersion(const unsigned int major, const unsigned int minor);
    Window* profile(const int newProfile);
    Window* depthTest(const bool condition);
    Window* build();

    bool shouldClose() const;
    void setShouldClose(const int condition);
    void pollEvents() const;
    void swapBuffers() const;
    float getTime() const;
};

} // namespace core
} // namespace gl
} // namespace ellipsoid

#endif
