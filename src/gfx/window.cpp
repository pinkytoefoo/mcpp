#include <string>
#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.hpp"
#include "glfw_context.hpp"

Window::Window(GlfwContext&, int w, int h, std::string_view title)
    : handle_{glfwCreateWindow(w, h, title.data(), nullptr, nullptr)}
{
    if(!handle_)
        throw std::runtime_error("glfwCreateWindow(...) failed!");

    glfwMakeContextCurrent(handle_);
}

Window::~Window()
{
    glfwDestroyWindow(handle_);
}

GLFWwindow* Window::handle()
{
    return handle_;
}
