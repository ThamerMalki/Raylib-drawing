#include"Canvas.h"
#include<iostream>

Canvas::Canvas()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Canvas");
    SetTargetFPS(FRAMES);
    m_target = LoadRenderTexture(SCREEN_WIDTH,SCREEN_HEIGHT);
    
}

void Canvas::run(int radius)
{

    Vector2 circle1 = {150/2 , 55};
    Vector2 circle2 = {150/2 , 150};
    Vector2 circle3 = {150/2 , 245};
    Vector2 circle4 = {150/2 , 340};

    while (!WindowShouldClose())
    {
        // Adding drawn circles to a vector
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) || (GetGestureDetected() == GESTURE_DRAG))
        {
            BeginTextureMode(m_target);
            DrawCircleV(GetMousePosition(),radius,m_drawingColor);
            EndTextureMode();
        }

        // Clearing canvas
        if(IsKeyPressed(KEY_C))
        {
            std::cout<<"KEY PRESSED\n";
            BeginTextureMode(m_target);
            ClearBackground(RAYWHITE);
            EndTextureMode();
        }

        //Picking Colors
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if(CheckCollisionPointCircle(GetMousePosition(), circle1 ,40))
            {
                std::cout<<"Clicked 1\n";
                m_drawingColor = BLACK;
            }
            else if(CheckCollisionPointCircle(GetMousePosition(), circle2 ,40))
            {
                std::cout<<"Clicked 2\n";
                m_drawingColor = RED;
            }
            else if(CheckCollisionPointCircle(GetMousePosition(), circle3 ,40))
            {
                std::cout<<"Clicked 3\n";
                m_drawingColor = PINK;
            }
            else if(CheckCollisionPointCircle(GetMousePosition(), circle4 ,40))
            {
                std::cout<<"Clicked 4\n";
                m_drawingColor = GREEN;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTextureRec(m_target.texture, (Rectangle){0, 0, (float)m_target.texture.width, (float)-m_target.texture.height}, {0, 0}, WHITE);
        m_panel.drawPanel(SCREEN_WIDTH , SCREEN_HEIGHT);

        // Drawing Colors panel
        DrawCircle(circle1.x , circle1.y , 40 , BLACK);
        DrawCircle(circle2.x , circle2.y , 40 , RED);
        DrawCircle(circle3.x , circle3.y , 40 , PINK);
        DrawCircle(circle4.x , circle4.y , 40 , GREEN);

        EndDrawing();
        
    }

    UnloadRenderTexture(m_target);
    CloseWindow();
}