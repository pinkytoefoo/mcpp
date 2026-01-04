#pragma once

#include "gfx/window.hpp"

class Gui
{
public:
    Gui(Window& w);
    ~Gui();

    void BeginFrame();
    void EndFrame();

private:
    bool m_ShowDemo = true;
};