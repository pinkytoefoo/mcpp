#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_internal.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

#include "gfx/glfw_context.hpp"
#include "gfx/glad_loader.hpp"
#include "gfx/window.hpp"
#include "gui.hpp"

void GLDebugMessageCallback(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message, const void *userParam)
{
    std::cout << message << '\n';
}

// void ProcessInput(GLFWwindow* window, float deltaTime) {
//     if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//         rotationAngle.x -= glm::radians(90.0f) * deltaTime;
//     if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//         rotationAngle.x += glm::radians(90.0f) * deltaTime;
//     if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//         rotationAngle.y -= glm::radians(90.0f) * deltaTime;
//     if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//         rotationAngle.y += glm::radians(90.0f) * deltaTime;
// }

class MinecraftApp {
public:
    MinecraftApp()
        // : glfw_{}
        : window_{1280, 720, "mcpp"}
        , glad_{window_}
        , gui_{window_}
    {
        glfwSetFramebufferSizeCallback(window_.handle(), [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });
        glEnable(GL_DEPTH_TEST);
    }

    void Run()
    {
        while(!glfwWindowShouldClose(window_.handle()))
        {
            glfwPollEvents();
            glClearColor(0.2f, 0.5f, 0.7f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);



            gui_.BeginFrame();
            ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
            ImGui::ShowDemoWindow(&showdemo_);
            gui_.EndFrame();

            glfwSwapBuffers(window_.handle());
        }
    }

private:
    [[no_unique_address]] GlfwContext glfw_;
    Window window_;
    GladLoader glad_;
    Gui gui_;

    bool showdemo_ = true;
};

int main()
{
    std::cout << sizeof(MinecraftApp) << '\n';
    MinecraftApp app;
    app.Run();
}
