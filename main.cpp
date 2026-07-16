#include <iostream>
#include <raylib.h>
#include "GameManager.h"

int main()
{

    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Tetris");
    
    
    SetTargetFPS(60);

    
    InitAudioDevice();

    Music bgm = LoadMusicStream("Tetris Main Song.wav");
    PlayMusicStream(bgm);

    // Color background = {18, 18, 18, 255};
    Color background = {15, 23, 42, 255};
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

        
      BeginDrawing();
      ClearBackground(background);

      g1.Draw();  
    //   g1.spawn();
      if(g1.approve())
      {
        g1.check_placement();
        g1.spawn();
      }
      EndDrawing();
      g1.check_filledrows();

    }

    UnloadMusicStream(bgm);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}