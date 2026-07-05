#include <iostream>
#include <raylib.h>
#include "GameManager.h"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    

    double last = GetTime();
    GameManager g1;
    while(!WindowShouldClose())
    {
        if(GetTime() - last >= 1.0f && !g1.approve())
        {
            g1.Dropping();
            last = GetTime();
        }
  
      BeginDrawing();
      ClearBackground(BLUE);
      g1.Draw();  
      EndDrawing();

    }

    CloseWindow();

    return 0;
}