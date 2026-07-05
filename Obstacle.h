#ifndef OBSTACLE
#include <iostream>
#include <raylib.h>
class OBSTACLE
{

    private:
        Rectangle block1, block2, block3, block4; // 4 blocks
        Color blocks_color;
        bool isPlaced = false;
    public:
        OBSTACLE(int posX1, int posX2, int posX3, int posX4, 
                int posY1, int posY2, int posY3, int posY4, int width, int height);
    void draw_obstacle(Color color);        
    void set_color(Color color);
    void drop_obstacle();
    void movement();
    bool get_placementState(); // this will tell whether the obstacle has been placed.
};
#endif