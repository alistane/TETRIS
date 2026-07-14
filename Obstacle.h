#ifndef OBSTACLE
#include <iostream>
#include <raylib.h>
#include <vector>

class OBSTACLE
{

    private:
        Rectangle block1, block2, block3, block4; // 4 blocks
        Color blocks_color;
        bool isPlaced = false;
        std::string obj_name;
    public:
        OBSTACLE() = default;
        OBSTACLE(std::string obj_name,int posX1, int posX2, int posX3, int posX4, 
                int posY1, int posY2, int posY3, int posY4, int width, int height);
    void draw_obstacle(Color color);        
    void set_color(Color color);
    void drop_obstacle();
    void movement();
    bool get_placementState(); // this will tell whether the obstacle has been placed.
    
    std::vector<std::vector<float>> give_position(); // returns the current position of the object
    // tells which row we are at.
    int getBlock1PosX();        
    int getBlock2PosX();
    int getBlock3PosX();
    int getBlock4PosX();

    int getBlock1PosY(); // tells which column we are at.
    int getBlock2PosY();
    int getBlock3PosY();
    int getBlock4PosY();

    std::string give_name(); // gives the name of the object

};
#endif