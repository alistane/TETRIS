#include "GameManager.h"


void GameManager::Dropping()
{
    this->obstacles[this->current_index].drop_obstacle();

}


void GameManager::Draw()
{

    this->g1.draw_grid();
    for(int i = 0; i <= this->current_index ; i++)
    {
        
        this->obstacles[i].draw_obstacle(this->obstacle_colors[i]);

    }
    this->obstacles[this->current_index].movement();
    DrawTextEx(this->score_font, TextFormat("Score : %d" , this->score), score_txt_loc , 30, 2, WHITE);

    // this->ob1.draw_obstacle(ORANGE);
    // this->ob1.movement();

}

bool GameManager::approve()
{
    return this->obstacles[this->current_index].get_placementState();
    // return this->ob1.get_placementState();
}


void GameManager::check_placement()
{
    

    std::vector<std::vector<float>>  final_placement;
   
    final_placement = this->obstacles[this->current_index].give_position();

    // now we will run a for loop and ask the grid to give us coordinates of visual rects and if the position of object blocks is equal to visual rect, then we will turn grid_logic variable grid cells equal to 1.


    // COMMENT THIS CODE IN THE FINAL VERSION
    std::cout << this->obstacles[this->current_index].give_name() << " placed at the following coordinates : " << std::endl;

    for(int i = 0; i < 4; i++) // i represents blocks
    {
        for(int j = 0; j < 2; j++) // j 0 represents x , j 1 y
        {
            if(i == 0)
            {
                if(j == 0)
                {
                    std::cout << "Block 1 (x) : " << final_placement[i][j] << std::endl;
                }
                else 
                {
                    std::cout << "Block 1 (y) : " << final_placement[i][j] << std::endl;
                }
            }

            if(i == 1)
            {
                if(j == 0)
                {
                    std::cout << "Block 2 (x) : " << final_placement[i][j] << std::endl;
                }
                else 
                {
                    std::cout << "Block 2 (y) : " << final_placement[i][j] << std::endl;
                }
            }

            if(i == 2)
            {
                if(j == 0)
                {
                    std::cout << "Block 3 (x) : " << final_placement[i][j] << std::endl;
                }
                else 
                {
                    std::cout << "Block 3 (y) : " << final_placement[i][j] << std::endl;
                }
            }

            
            if(i == 3)
            {
                if(j == 0)
                {
                    std::cout << "Block 4 (x) : " << final_placement[i][j] << std::endl;
                }
                else 
                {
                    std::cout << "Block 4 (y) : " << final_placement[i][j] << std::endl;
                }
            }



        }
    } // all debug stuff


    //now checking the placement 

   // firstly , we will check which row is object sitting on.
    // we will check each y pos of every block.




    for(int i = 0 ; i < 20 ; i++) // where i -> rows of grid
    {
        for(int j = 0; j <= 3; j++) // where j ->  block 1, 2, 3, 4
        {
            // firstly, checking the rows of the final placement of the object.
            if(this->g1.getRowPosition(i) == final_placement[j][1])
            {
                for(int k = 0; k < 10; k++) // where k -> columns of grid
                {
                    // TODO : Do something about this l loop, this is not necessary to compare y positions of the object again and again.
                    for(int l = 0; l < 2; l++) // where l -> y (column) of final obj placement 
                    {
                        if(this->g1.getColumnPosition(k) == final_placement[j][l])
                        {
                            this->g1.setCell(i,k, 1);
                        }
                    }
                    

                }
            }
        }
    }

    // now checking the values ..
    for(int i = 0 ; i < 20 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            std::cout << "Row " << i+1 << "\n" << "Column : " << j+1 << "\n" 
            << "Value : " << this->g1.getValue(i, j) << std::endl;
        }
    }

    


}

GameManager::GameManager()
{
    this->initialise_obstacles();
    this->score_font = LoadFont("UI FONT 1.TTF");
    this->obstacle_colors.push_back(ORANGE);
    this->obstacle_colors.push_back(RED);
    this->obstacle_colors.push_back(GREEN);
    this->obstacle_colors.push_back(YELLOW);
    this->obstacle_colors.push_back(PURPLE);
    this->obstacle_colors.push_back(BLUE);


}

void GameManager::initialise_obstacles()
{
    this->obstacles.push_back(OBSTACLE ("IDK",50,90,130,170,150,150,150,150,40,40));
    this->obstacles.push_back(OBSTACLE ("I shape", 50,50,50,50,150,190,230,270,40,40)); // i shape
    this->obstacles.push_back(OBSTACLE ("T shape", 50,90,130,90,150,150,150,190,40,40)); // T shape
    this->obstacles.push_back(OBSTACLE ("O shape", 50,90,50,90,150,150,190,190,40,40)); // o shape
    this->obstacles.push_back(OBSTACLE ("S shape", 50,90,90,130,190,150,190,150,40,40)); // s shape
    this->obstacles.push_back(OBSTACLE ("L shape", 50,50,50,90,150,190,230,230,40,40));
}

void GameManager::spawn( )
{

    if(this->current_index < this->spawn_limit - 1)
    {
        if(this->obstacles[this->current_index].get_placementState())
        {
            this->current_index++;
        }
    }
    

}