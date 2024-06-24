#pragma once
#include"raylib.h"
#include"Panel.h"

class Canvas
{
    const int SCREEN_WIDTH  = 950;
    const int SCREEN_HEIGHT = 850;
    const int FRAMES        = 60;
    Panel     m_panel;
    RenderTexture2D m_target;
    Color m_drawingColor = BLACK;

public:

    Canvas();
    void run(int radius);
};