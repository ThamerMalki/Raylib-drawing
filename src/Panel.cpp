#include"Panel.h"

Panel::Panel()
{
    m_rectangle = {0 , 0 , 150 , 400};
}

void Panel::drawPanel(const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
{
    DrawRectangleLinesEx(m_rectangle, 4, BLACK);
}

int Panel::getRectX() const
{
    return m_rectangle.x;
}

int Panel::getRectY() const
{
    return m_rectangle.y;
}

int Panel::getRectWidth() const
{
    return m_rectangle.width;
}

int Panel::getRectHeight() const
{
    return m_rectangle.height;
}