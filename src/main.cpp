#include <imgui.h>
#include <imgui_internal.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

#include "gfx/glfw_context.hpp"
#include "gfx/glad_loader.hpp"
#include "gfx/window.hpp"
#include "gui.hpp"

class MinecraftApp {
public:
    MinecraftApp()
        : window_{GlfwContext::GetInstance(), 1280, 720, "mcpp"}
        , glad_{window_}
        , gui_{window_}
    {
    }

    ~MinecraftApp() = default;

    void Run()
    {
        while(!glfwWindowShouldClose(window_.handle()))
        {
            glfwPollEvents();
            glClearColor(0.2f, 0.5f, 0.7f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // imgui
            gui_.BeginFrame();
            ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
            ImGui::ShowDemoWindow(&showdemo_);
            gui_.EndFrame();

            glfwSwapBuffers(window_.handle());
        }
    }

private:
    Window window_;
    GladLoader glad_;
    Gui gui_;

    bool showdemo_ = true;
};

int main()
{
    MinecraftApp app;
    app.Run();
}
