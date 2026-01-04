#pragma once

#include <imgui.h>

class Gui
{
public:
    Gui();
    ~Gui();

    void Init();
    void Run();
    void Cleanup();
private:
    ImGuiIO& m_Io;
};