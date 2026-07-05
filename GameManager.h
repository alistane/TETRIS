#include<iostream>
#include "Obstacle.h"
#include "Grid.h"

class GameManager
{
    private:
        GRID g1;
        OBSTACLE ob1 {50,90,50,90,150,150,110,110,40,40};
    
    public:
        void Draw();


};