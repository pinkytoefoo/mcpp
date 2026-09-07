#include <string>
#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.hpp"
#include "glfw_context.hpp"

Window::Window(int w, int h, std::string_view title)
    : data_{w, h}
    , handle_{glfwCreateWindow(w, h, title.data(), nullptr, nullptr)}
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    if(!handle_)
        throw std::runtime_error("glfwCreateWindow(...) failed!");

    glfwSetWindowUserPointer(handle_, &data_);
    glfwSetWindowSizeCallback(handle_, [](GLFWwindow* window, int w, int h) -> void {
        WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
        if(!data)
            throw std::runtime_error("glfwSetWindowSizeCallback() -> glfwGetWindowUserPointer(...) failed!");
        
        data->width = w;
        data->height = h;
        glViewport(0, 0, data->width, data->height);
    });

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
