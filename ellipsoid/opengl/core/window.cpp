#include "window.hpp"
#include <iostream>
#include <stdexcept>

namespace ellipsoid {
namespace gl {
namespace core {

bool Window::init() const {
    int glfw = glfwInit();
    int glad = gladLoadGL((GLADloadfunc)glfwGetProcAddress);
    return glfw && glad;
}

void Window::terminate() const {
    glfwTerminate();
}

Window::Window() {
    _width = 640;
    _height = 480;
    _title = "Hello World!";
    _mode = WindowMode::Windowed;
}

// Window::~Window() {
//     std::cout << "DESTROYING WINDOW" << std::endl;
// }

Window::Window(const unsigned int width, const unsigned int height,
               const std::string title, const WindowMode mode) {
    _width = width;
    _height = height;
    _title = title;
    _mode = mode;
}

Window& Window::width(const unsigned int newWidth) {
    _width = newWidth;
    return *this;
}

Window& Window::height(const unsigned int newHeight) {
    _height = newHeight;
    return *this;
}

Window& Window::dimensions(const unsigned int newWidth,
                           const unsigned int newHeight) {
    _width = newWidth;
    _height = newHeight;
    return *this;
}

Window& Window::title(const std::string newTitle) {
    _title = newTitle;
    return *this;
}

Window& Window::mode(const WindowMode newMode) {
    _mode = newMode;
    return *this;
}

Window& Window::windowed() {
    _mode = WindowMode::Windowed;
    return *this;
}

Window& Window::fullScreen() {
    _mode = WindowMode::FullScreen;
    return *this;
}

Window& Window::glVersion(const unsigned int major, const unsigned int minor) {
    _glVersionMajor = major;
    _glVersionMinor = minor;
    return *this;
}

Window& Window::profile(const int newProfile) {
    _glProfile = newProfile;
    return *this;
}

Window& Window::depthTest(const bool condition) {
    _depthTest = condition;
    return *this;
}

Window& Window::build() {
    init();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _glVersionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _glVersionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, _glProfile);

    GLFWwindow* window =
        glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);

    if (!window) {
        terminate();
        throw std::runtime_error("Failed to create window.");
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(
        window, [](GLFWwindow* win, int w, int h) { glViewport(0, 0, w, h); });

    /*
    We have to call init twice because I'm an idiot :)
    My init function initializes both GLFW and GLAD at the same time, but to initialize
    GLAD you need to have a context in the running thread, which means you have to
    initialize GLFW before GLAD. I could separate init into 2 separate functions, but
    then the software would depend on the rendering API that is being used (something
    which I don't want to happen, as I want this piece of software to be API agnostic).

    TODO: Think of a better way of doing this thing.
    */

    if (!init()) {
        throw std::runtime_error("Failed to initialize the necessary modules.");
    }

    if (_depthTest)
        glEnable(GL_DEPTH_TEST);

    _glfwWindow = window;
    return *this;
}

bool Window::shouldClose() const { return glfwWindowShouldClose(_glfwWindow); }

void Window::setShouldClose(const int condition) {
    glfwSetWindowShouldClose(_glfwWindow, condition);
}

void Window::pollEvents() const { glfwPollEvents(); }

void Window::swapBuffers() const { glfwSwapBuffers(_glfwWindow); }

float Window::getTime() const { return glfwGetTime(); }

} // namespace core
} // namespace gl
} // namespace ellipsoid
