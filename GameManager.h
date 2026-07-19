
#ifndef GAMEMANAGER
#include<iostream>
#include "Obstacle.h"
#include "Grid.h"
#include "raylib.h"
#include <vector>
#include <string>
#include <random>
class GameManager
{
    private:
        GRID g1;
        // OBSTACLE ob1 {50,90,130,170,150,150,150,150,40,40};
        // OBSTACLE ob2 {50,90,130,170,150,150,150,150,40,40};
        std::vector<OBSTACLE> obstacles; // bank for obstacles.
        OBSTACLE current_obstacle; // obstacle that is selected for dropping.
        int current_index = {}; // index (tells current obstacle) ,, is managed in spawn function.
        int score = {}; // user score
        Font score_font;
        Vector2 score_txt_loc {450, 200};
        std::vector<Color> obstacle_colors;
        int spawn_limit = 12;
        int spawned_objects = {}; // this keeps track of how many objects have been spawned.. this is useful in checkfilledrows function.
    public:
        GameManager();
        void initialise_obstacles();
        void spawn();
        void Draw();
        void Dropping();
        bool approve(); // this will send a signal that the current object has been placed successfully. TRUE -> Placed , FALSE -> STILL DROPPING
        void check_placement();

        void check_filledrows(); // checks every row and if it is filled then it will reward the user and it will reset rows and column cells back to 0 and delete the blocks there.

        bool approve_drop(); // this will perform collision detection and when it will return true, the object will drop.

};
#endif