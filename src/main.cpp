#include <print>
#include <stdexcept>
#include <memory>

// #include <vulkan.h>
#include <vulkan/vulkan_raii.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

class MinecraftApp {
public:
    MinecraftApp() { Init(); }
    ~MinecraftApp() { Cleanup(); }

    void Run() {
        Loop();
    }
private:
    void Init() {
        if(int glfw_init_status = glfwInit(); !glfw_init_status)
            throw std::runtime_error{"glfwInit() failed"};

        m_Window = glfwCreateWindow(1280, 720, "mcpp", nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);

        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
            throw std::runtime_error{"failed to initialize glad"};
    }

    void Loop() {
        while(!glfwWindowShouldClose(m_Window)) {
            glfwPollEvents();

            glClearColor(0.2f, 0.5f, 0.9f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(m_Window);
        }
    }

    void Cleanup() {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    GLFWwindow* m_Window;
};

int main()
{
    MinecraftApp app;
    app.Run();
}


// int main()
// {
//     GLFWGlobalState state;
//     float main_scale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor()); // Valid on GLFW 3.3+ only

//     glfwHandlePtr window(glfwCreateWindow(1280, 720, "mcpp", nullptr, nullptr));
//     glfwMakeContextCurrent(window.get());
    
//     if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
//         printf("Couldn't initialize GLAD.\n");
//         return -1;
//     }

//     IMGUI_CHECKVERSION();
//     ImGui::CreateContext();
//     ImGuiIO& io = ImGui::GetIO(); (void)io;
//     io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
//     io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
//     io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

//     // Setup Dear ImGui style
//     ImGui::StyleColorsDark();
//     //ImGui::StyleColorsLight();

//     // Setup scaling
//     ImGuiStyle& style = ImGui::GetStyle();
//     style.ScaleAllSizes(main_scale);        // Bake a fixed style scale. (until we have a solution for dynamic style scaling, changing this requires resetting Style + calling this again)
//     style.FontScaleDpi = main_scale;        // Set initial font scale. (using io.ConfigDpiScaleFonts=true makes this unnecessary. We leave both here for documentation purpose)

//     // Setup Platform/Renderer backends
//     ImGui_ImplGlfw_InitForOpenGL(window.get(), true);

//     bool show_demo_window = true;
//     bool show_another_window = false;
//     ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

//     ImGui_ImplOpenGL3_Init("#version 130");

//     ImGuiID dockspace_id = ImGui::GetID("My Dockspace");
//     ImGuiViewport* viewport = ImGui::GetMainViewport();

//     // Create settings
//     if (ImGui::DockBuilderGetNode(dockspace_id) == nullptr)
//     {
//         ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
//         ImGui::DockBuilderSetNodeSize(dockspace_id, viewport->Size);
//         ImGuiID dock_id_left = 0;
//         ImGuiID dock_id_main = dockspace_id;
//         ImGui::DockBuilderSplitNode(dock_id_main, ImGuiDir_Left, 0.20f, &dock_id_left, &dock_id_main);
//         ImGuiID dock_id_left_top = 0;
//         ImGuiID dock_id_left_bottom = 0;
//         ImGui::DockBuilderSplitNode(dock_id_left, ImGuiDir_Up, 0.50f, &dock_id_left_top, &dock_id_left_bottom);
//         ImGui::DockBuilderDockWindow("Game", dock_id_main);
//         ImGui::DockBuilderDockWindow("Properties", dock_id_left_top);
//         ImGui::DockBuilderDockWindow("Scene", dock_id_left_bottom);
//         ImGui::DockBuilderFinish(dockspace_id);
//     }

//     while(!glfwWindowShouldClose(window.get()))
//     {
//         {
//         // Poll and handle events (inputs, window resize, etc.)
//         // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
//         // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
//         // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
//         // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
//         glfwPollEvents();
//         if (glfwGetWindowAttrib(window.get(), GLFW_ICONIFIED) != 0)
//         {
//             ImGui_ImplGlfw_Sleep(10);
//             continue;
//         }

//         ImGui_ImplOpenGL3_NewFrame();
//         ImGui_ImplGlfw_NewFrame();
//         ImGui::NewFrame();

//         ImGui::DockSpaceOverViewport(dockspace_id, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

//         // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
//         if (show_demo_window)
//             ImGui::ShowDemoWindow(&show_demo_window);

//         // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
//         {
//             static float f = 0.0f;
//             static int counter = 0;

//             ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

//             ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
//             ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
//             ImGui::Checkbox("Another Window", &show_another_window);

//             ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
//             ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

//             if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
//                 counter++;
//             ImGui::SameLine();
//             ImGui::Text("counter = %d", counter);

//             ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
//             ImGui::End();
//         }

//         // 3. Show another simple window.
//         if (show_another_window)
//         {
//             ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
//             ImGui::Text("Hello from another window!");
//             if (ImGui::Button("Close Me"))
//                 show_another_window = false;
//             ImGui::End();
//         }

//         // Rendering
//         ImGui::Render();
//         int display_w, display_h;
//         glfwGetFramebufferSize(window.get(), &display_w, &display_h);
//         glViewport(0, 0, display_w, display_h);
//         glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
//         glClear(GL_COLOR_BUFFER_BIT);
//         ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

//         glfwSwapBuffers(window.get());
//     }
//     }

//     ImGui_ImplOpenGL3_Shutdown();
//     ImGui_ImplGlfw_Shutdown();
//     ImGui::DestroyContext();
    
//     std::println("yay");
// }

