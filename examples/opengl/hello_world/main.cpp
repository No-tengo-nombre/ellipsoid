#include <ellipsoid/opengl/ellipsoid.hpp>
#include <ellipsoid/utils/color.hpp>
#include <vector>
#include <iostream>

using namespace ellipsoid::gl;
using namespace ellipsoid::gl::core;
using namespace ellipsoid::utils;

int main() {
    // We make the window using a builder pattern
    Window* window = Window()
        .dimensions(1000, 1000)
        ->title("Ellipsoid Example: Hello World")
        ->windowed()
        ->build();

    // Make a 3D renderer for the scene
    Renderer3D* renderer =
        Renderer3D().clearColor(ColorRGBAfloat(0.2f, 0.2f, 0.2f, 1.0f));

    std::cout << renderer->getClearColor().getR() << std::endl;

    // Defining a shader
    Shader* shader = Shader()
        .vertex("examples/opengl/hello_world/resources/shader/hello_world.vert")
        ->fragment("examples/opengl/hello_world/resources/shader/hello_world.frag");

    // We make a material for the shape
    Material* material = Material().setShader(*shader);

    // Defining the shape
    std::vector<float> triangleVertices({
        -0.75f, -0.75f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.75f, -0.75f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.75f, 0.0f, 0.0f, 0.0f, 1.0f,
    });
    std::vector<unsigned int> triangleIndices({
        0, 1, 2,
    });
    Shape* triangle = Shape()
        .vertices(triangleVertices)
        ->indices(triangleIndices)
        ->material(*material)
        ->layouts(std::vector<unsigned int>({0, 1}))
        ->build();

    // The shape is added to the renderer
    renderer->add(*triangle);

    while (!(window->shouldClose())) {
        window->pollEvents();
        renderer->clear();
        renderer->render();
        window->swapBuffers();
    }
}
