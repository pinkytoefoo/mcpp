#include "gui.hpp"

#include <imgui.h>
#include <imgui_internal.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>

Gui::Gui() {
    Init();
}

Gui::~Gui() {
    Cleanup();
}

void Init() {
    
}

void Gui::Cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}