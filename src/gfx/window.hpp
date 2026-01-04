#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "glfw_context.hpp"

class Window
{
public:
    Window(GlfwContext&, int w, int h, std::string_view title);
    ~Window();
    
    GLFWwindow* handle();

private:
    GLFWwindow* handle_ = nullptr;
};