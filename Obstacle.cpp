#include "Obstacle.h"
#include <thread>
#include <chrono>
#include <algorithm>

OBSTACLE::OBSTACLE(std::string obj_name, int posX1, int posX2, int posX3, int posX4, 
int posY1, int posY2, int posY3, int posY4, int width, int height) 
{
    this->obj_name = obj_name;
    this->block1.x = posX1;
    this->block1.height = height;
    this->block1.y = posY1;
    this->block1.width = width;

    this->block2.x = posX2;
    this->block2.height = height;
    this->block2.y = posY2;
    this->block2.width = width;

    this->block3.x = posX3;
    this->block3.height = height;
    this->block3.y = posY3;
    this->block3.width = width;

    this->block4.x = posX4;
    this->block4.height = height;
    this->block4.y = posY4;
    this->block4.width = width;

}


std::string OBSTACLE::give_name()
{
    return this->obj_name;
}


void OBSTACLE::set_color(Color color)
{
    this->blocks_color = color;
}

std::vector<std::vector<float>> OBSTACLE::give_position()
{
    std::vector<std::vector<float>> pos_matrix (4, std::vector<float>(2, 0));
    
    pos_matrix = {
        {block1.x, block1.y},
        {block2.x, block2.y},
        {block3.x, block3.y},
        {block4.x, block4.y}
    };
    

    return pos_matrix;

}


void OBSTACLE::draw_obstacle(Color col)
{
    this->set_color(col);
    DrawRectangleRec(this->block1, this->blocks_color);
    // DrawRectangleLinesEx(this->block1, 1, BLACK);
    DrawLine(this->block1.x, this->block1.y,  this->block1.x + this->block1.width, this->block1.y, WHITE); // top

    // left
    DrawLine(this->block1.x, this->block1.y,  this->block1.x, this->block1.y + this->block1.height, WHITE);

    // bottom
    DrawLine(this->block1.x, this->block1.y + this->block1.height,  this->block1.x + this->block1.width, this->block1.y + this->block1.height, DARKBROWN);

    // right
    DrawLine(this->block1.x + this->block1.width , this->block1.y , this->block1.x + this->block1.width, this->block1.y + this->block1.height, DARKBROWN);

    // block 2
    DrawRectangleRec(this->block2, this->blocks_color);

    DrawLine(this->block2.x, this->block2.y,  this->block2.x + this->block2.width, this->block2.y, WHITE); // top

    // left
    DrawLine(this->block2.x, this->block2.y,  this->block2.x, this->block2.y + this->block2.height, WHITE);

    // bottom
    DrawLine(this->block2.x, this->block2.y + this->block2.height,  this->block2.x + this->block2.width, this->block2.y + this->block2.height, DARKBROWN);

    // right
    DrawLine(this->block2.x + this->block2.width , this->block2.y , this->block2.x + this->block2.width, this->block2.y + this->block2.height, DARKBROWN);


    // block 3
    DrawRectangleRec(this->block3, this->blocks_color);
        DrawLine(this->block3.x, this->block3.y,  this->block3.x + this->block3.width, this->block3.y, WHITE); // top

    // left
    DrawLine(this->block3.x, this->block3.y,  this->block3.x, this->block3.y + this->block3.height, WHITE);

    // bottom
    DrawLine(this->block3.x, this->block3.y + this->block3.height,  this->block3.x + this->block3.width, this->block2.y + this->block3.height, DARKBROWN);

    // right
    DrawLine(this->block3.x + this->block3.width , this->block3.y , this->block3.x + this->block3.width, this->block3.y + this->block3.height, DARKBROWN);

    // block 4
    DrawRectangleRec(this->block4, this->blocks_color);
    DrawLine(this->block4.x, this->block4.y,  this->block4.x + this->block4.width, this->block4.y, WHITE); // top

    // left
    DrawLine(this->block4.x, this->block4.y,  this->block4.x, this->block4.y + this->block4.height, WHITE);

    // bottom
    DrawLine(this->block4.x, this->block4.y + this->block4.height,  this->block4.x + this->block4.width, this->block4.y + this->block4.height, DARKBROWN);

    // right
    DrawLine(this->block4.x + this->block4.width , this->block4.y , this->block4.x + this->block4.width, this->block4.y + this->block4.height, DARKBROWN);


}    

void OBSTACLE::drop_obstacle()
{
   
    if(this->get_placementState() == false)
    {
        int lowest = std::max({this->block1.y, this->block2.y, this->block3.y, this->block4.y});


        if(lowest < 510)
        {
            this->block1.y += 40;
            this->block2.y += 40;
            this->block3.y += 40;
            this->block4.y += 40;
        }
    }
    else
    {
        std::cout << "The object has been placed.. cant drop further." << std::endl;
    }

    
    
}

void OBSTACLE::movement()
{
    // std::cout << "Block 1 x : " << this->block1.x << std::endl;
    // std::cout << "Block 2 x : " << this->block2.x << std::endl;
    // std::cout << "Block 3 x : " << this->block3.x << std::endl;
    // std::cout << "Block 4 x : " << this->block4.x << std::endl;

    if(this->isPlaced == false)
    {
        if(IsKeyPressed(KEY_A))
        {
            int leftest = std::min({this->block1.x, this->block2.x, this->block3.x,
            this->block4.x});
        
        
            if(this->block1.x > 50 && this->block2.x >50 
                && this->block3.x > 50 && this->block4.x > 50 )
            {
                this->block1.x -= 40;
                this->block2.x -= 40;
                this->block3.x -= 40;
                this->block4.x -= 40;
            }
        
        }
        else if(IsKeyPressed(KEY_D))
        {
            if(block1.x < 330 && block2.x < 330  && block3.x < 330 && block4.x < 330)
            {
                this->block1.x += 40;
                this->block2.x += 40;
                this->block3.x += 40;
                this->block4.x += 40; 
            }
   
        }

        if(IsKeyPressed(KEY_ENTER))
        {
            this->isPlaced = true;
        }
    }

}

bool OBSTACLE::get_placementState()
{
    return this->isPlaced;
}


int OBSTACLE::getBlock1PosX()
{
    return this->block1.x;
}        
int OBSTACLE::getBlock2PosX()
{
    return this->block2.x;
}
int OBSTACLE::getBlock3PosX()
{
    return this->block3.x;
}
int OBSTACLE::getBlock4PosX()
{
    return this->block4.x;
}

int OBSTACLE::getBlock1PosY()
{
    return this->block1.y;
}
int OBSTACLE::getBlock2PosY()
{
    return this->block2.y;
}
int OBSTACLE::getBlock3PosY()
{
    return this->block3.y;
}
int OBSTACLE::getBlock4PosY()
{
    return this->block4.y;
}