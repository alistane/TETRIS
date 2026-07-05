#include "Grid.h"
#include <iostream>
#include <raylib.h>
#include "Obstacle.h"
int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    GRID g1;
    OBSTACLE ob1 {50,90,50,90,150,150,110,110,40,40};

    double last = GetTime();

    while(!WindowShouldClose())
    {
        if(GetTime() - last >= 1.0f && !ob1.get_placementState())
        {
            ob1.drop_obstacle();
            last = GetTime();
        }
  
      BeginDrawing();
      ClearBackground(BLUE);
      g1.draw_grid(); 
      ob1.draw_obstacle(ORANGE);
      ob1.movement();

      EndDrawing();

    }

    CloseWindow();

    return 0;
}