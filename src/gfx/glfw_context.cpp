#include <stdexcept>
#include <format>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "glfw_context.hpp"

GlfwContext::GlfwContext()
{
    if(!glfwInit())
        throw std::runtime_error{std::format("glfwInit() failed!\nfile {}, line {}", __FILE__, __LINE__)};
}

GlfwContext::~GlfwContext()
{
    glfwTerminate();
}

GlfwContext& GlfwContext::GetInstance()
{
    static GlfwContext instance;
    return instance;
}
