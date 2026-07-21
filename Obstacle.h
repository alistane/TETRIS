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

        bool block1_active = true, block2_active = true,
         block3_active = true, block4_active = true ;

    public:
        OBSTACLE() = default;
        OBSTACLE(std::string obj_name,int posX1, int posX2, int posX3, int posX4, 
                int posY1, int posY2, int posY3, int posY4, int width, int height);
    void draw_obstacle(Color color);        
    void set_color(Color color);
    void drop_obstacle();
    void movement(bool can_move_left, bool can_move_right);
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

    // arbituary fix -> we are just disabling the rendering of the blocks ill find a better way to handle this
    
    bool get_block1_state();
    bool get_block2_state();
    bool get_block3_state();
    bool get_block4_state();


    void set_block1_state(bool state);
    void set_block2_state(bool state);
    void set_block3_state(bool state);
    void set_block4_state(bool state);

    void add_to_y(); // this will add value 40 to current position, this function is used in arrange function.s
    void move_block(int x, int y); // moves one vertical.
    void add_to_block1();
    void add_to_block2();
    void add_to_block3();
    void add_to_block4();


    std::string give_name(); // gives the name of the object

};
#endif