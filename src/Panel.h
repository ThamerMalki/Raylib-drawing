#pragma once
#include"raylib.h"
class Panel
{

    Rectangle m_rectangle;

public:

    Panel();
    void drawPanel(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
    int getRectX() const;
    int getRectY() const;
    int getRectWidth() const;
    int getRectHeight() const;

};