#pragma once

#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.hpp"

struct GladLoader
{
    explicit GladLoader(Window& window)
    {
        glfwMakeContextCurrent(window.handle());

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            throw std::runtime_error("Failed to load GLAD");
    }
};