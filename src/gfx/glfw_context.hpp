#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct GlfwContext
{
    GlfwContext();
    ~GlfwContext();

    GlfwContext(const GlfwContext&) = delete;
    GlfwContext& operator=(const GlfwContext&) = delete;
    GlfwContext(GlfwContext&&) = delete;
    void operator=(GlfwContext&&) = delete;

    static GlfwContext& GetInstance();
};
