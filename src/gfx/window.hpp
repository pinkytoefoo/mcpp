#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "glfw_context.hpp"

class Window
{
public:
    Window(int w, int h, std::string_view title);
    ~Window();
    
    GLFWwindow* handle();

private:
    struct WindowData {
        WindowData(int w, int h)
            : width{w}
            , height{h}
        {
        }
        int width;
        int height;
    };
    WindowData data_;
    GLFWwindow* handle_ = nullptr;
};