#include <iostream>
#include <raylib.h>
#include "GameManager.h"

int main()
{

    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tetris");
    
if (!IsWindowReady())
{
    std::cout << "Window failed to initialize\n";
    return 1;
}
    SetTargetFPS(60);

    
    InitAudioDevice();

    Music bgm = LoadMusicStream("Tetris Main Song.wav");
    PlayMusicStream(bgm);


    double last = GetTime();
    GameManager g1;
    while(!WindowShouldClose())
    {
        UpdateMusicStream(bgm);
        if(GetTime() - last >= 1.0f && !g1.approve())
        {
            g1.Dropping();
            
            last = GetTime();
        }
        else if(g1.approve())
        {
            g1.check_placement();

        }
  
      BeginDrawing();
      ClearBackground(BLUE);
      g1.Draw();  
      EndDrawing();

    }

    UnloadMusicStream(bgm);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}