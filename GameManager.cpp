#include "GameManager.h"


void GameManager::Dropping()
{
    // if(this->approve_drop())
    // {
    //     this->obstacles[this->current_index].drop_obstacle();

    // }

    int block1_posX = this->obstacles[this->current_index].getBlock1PosX();
    int block1_posY = this->obstacles[this->current_index].getBlock1PosY();

    int block2_posX = this->obstacles[this->current_index].getBlock2PosX();
    int block2_posY = this->obstacles[this->current_index].getBlock2PosY();

    int block3_posX = this->obstacles[this->current_index].getBlock3PosX();
    int block3_posY = this->obstacles[this->current_index].getBlock3PosY();

    int block4_posX = this->obstacles[this->current_index].getBlock4PosX();
    int block4_posY = this->obstacles[this->current_index].getBlock4PosY();


    std::cout << this->obstacles[this->current_index].give_name() << " Block 1 free bottom block is : " <<this->g1.getValueFromCoordinates(block1_posX, block1_posY + 40) << std::endl;

    std::cout << this->obstacles[this->current_index].give_name() << " Block 2 free bottom block is : " <<this->g1.getValueFromCoordinates(block2_posX, block2_posY - 40) << std::endl;

    std::cout << this->obstacles[this->current_index].give_name() << " Block 3 free bottom block is : " <<this->g1.getValueFromCoordinates(block3_posX, block3_posY - 40) << std::endl;

    std::cout << this->obstacles[this->current_index].give_name() << " Block 4 free bottom block is : " <<this->g1.getValueFromCoordinates(block4_posX, block4_posY - 40) << std::endl;

           


    

    if(this->g1.getValueFromCoordinates(block1_posX ,block1_posY + 40 ) != 1 && this->g1.getValueFromCoordinates(block2_posX ,block2_posY + 40 ) != 1
        && this->g1.getValueFromCoordinates(block3_posX , block3_posY + 40 ) != 1 && this->g1.getValueFromCoordinates(block4_posX ,block4_posY + 40 ) != 1 )
    {
        this->obstacles[this->current_index].drop_obstacle();

    }

    


}

bool GameManager::approve_drop()
{
    bool approve;



    

    



    return approve;
}


void GameManager::Draw()
{

    this->g1.draw_grid();
    for(int i = 0; i <= this->current_index ; i++)
    {
        
        this->obstacles[i].draw_obstacle(this->obstacle_colors[i]);

    }

    int block1_posX = this->obstacles[this->current_index].getBlock1PosX();
    int block1_posY = this->obstacles[this->current_index].getBlock1PosY();

    int block2_posX = this->obstacles[this->current_index].getBlock2PosX();
    int block2_posY = this->obstacles[this->current_index].getBlock2PosY();

    int block3_posX = this->obstacles[this->current_index].getBlock3PosX();
    int block3_posY = this->obstacles[this->current_index].getBlock3PosY();

    int block4_posX = this->obstacles[this->current_index].getBlock4PosX();
    int block4_posY = this->obstacles[this->current_index].getBlock4PosY();

    bool can_move_left = false, can_move_right = false;

    // blocks x right comparison
    if(this->g1.getValueFromCoordinates(block1_posX + 40,block1_posY ) != 1 && this->g1.getValueFromCoordinates(block2_posX + 40,block2_posY ) != 1 && this->g1.getValueFromCoordinates(block3_posX + 40,block3_posY ) != 1 &&
        this->g1.getValueFromCoordinates(block4_posX + 40,block4_posY ) != 1)
    {
        can_move_right = true;
    }

    // blocks x left comparison
    if(this->g1.getValueFromCoordinates(block1_posX - 40,block1_posY ) != 1 && this->g1.getValueFromCoordinates(block2_posX - 40,block2_posY ) != 1 && this->g1.getValueFromCoordinates(block3_posX - 40, block3_posY ) != 1
     && this->g1.getValueFromCoordinates(block4_posX - 40, block4_posY ) != 1 )
    {
        can_move_left = true;
    }


    this->obstacles[this->current_index].movement(can_move_left, can_move_right);
    DrawTextEx(this->score_font, TextFormat("Score : %d" , this->score), score_txt_loc , 30, 2, WHITE);

    // this->ob1.draw_obstacle(ORANGE);
    // this->ob1.movement();

}

bool GameManager::approve()
{
    return this->obstacles[this->current_index].get_placementState();
    // return this->ob1.get_placementState();
}


void GameManager::check_filledrows() // this checks if a row is filled and then rewards the user with score points.
{
    // InitAudioDevice(); // play some song here dude.
    for(int i = 0; i < this->g1.get_no_of_rows(); i++)
    {
        int counter = {};
        int filled_row = {};
        for(int j = 0; j < this->g1.get_no_of_columns(); j++)
        {
            if(g1.getValue(i,j) == 1)
            {
                counter++;
            }
            if(counter == 10)
            {
                filled_row = i;
                std::cout << filled_row << " Row is filled now" << std::endl;
                this->score += 100;

                for(int i = 0; i < this->spawned_objects; i++)
                {
                    // we will check every object's block position relative to the cells position of the filled row.

                    for(int j = 0; j < this->g1.get_no_of_columns(); j++)
                    {
                        if(this->obstacles[i].getBlock1PosX() == g1.getColumnPosition(j) && this->obstacles[i].getBlock1PosY() == g1.getRowPosition(filled_row))
                        {
                            std::cout << this->obstacles[i].give_name() << "'s block 1  is on the r" << filled_row << "c" << j << std::endl;

                            this->obstacles[i].set_block1_state(false);
                        }

                        if(this->obstacles[i].getBlock2PosX() == g1.getColumnPosition(j) && this->obstacles[i].getBlock2PosY() == g1.getRowPosition(filled_row))
                        {
                            std::cout << this->obstacles[i].give_name() << " 's block 2  is on the r" << filled_row << "c" << j << std::endl;

                            this->obstacles[i].set_block2_state(false);
                        }

                        if(this->obstacles[i].getBlock3PosX() == g1.getColumnPosition(j) && this->obstacles[i].getBlock3PosY() == g1.getRowPosition(filled_row))
                        {
                            std::cout << this->obstacles[i].give_name() << "'s block 3  is on the r" << filled_row << "c" << j << std::endl;

                            this->obstacles[i].set_block3_state(false);
                        }

                        if(this->obstacles[i].getBlock4PosX() == g1.getColumnPosition(j) && this->obstacles[i].getBlock4PosY() == g1.getRowPosition(filled_row))
                        {
                            std::cout << this->obstacles[i].give_name() << "'s block 4  is on the r" << filled_row << "c" << j << std::endl;

                            this->obstacles[i].set_block4_state(false);
                        }
                    }
                }


                
                for(int columns = 0; columns < this->g1.get_no_of_columns(); columns++)
                {
                    this->g1.setCell(filled_row, columns, 0);
                }


            }

        }
        
        // now resetting the state might want to look here in the future for optimisation.. this loop maybe try putting it in the if condition counter==10.

        
    }
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
    // 710 say 740, 780, 820
    // this->obstacles.push_back(OBSTACLE ("IDK",50,90,130,170,150,150,150,150,40,40));
    // this->obstacles.push_back(OBSTACLE ("I shape", 50,50,50,50,150,190,230,270,40,40)); // i shape
    // this->obstacles.push_back(OBSTACLE ("T shape", 50,90,130,90,150,150,150,190,40,40)); // T shape
    // this->obstacles.push_back(OBSTACLE ("O shape", 50,90,50,90,150,150,190,190,40,40)); // o shape
    // this->obstacles.push_back(OBSTACLE ("S shape", 50,90,90,130,190,150,190,150,40,40)); // s shape
    // this->obstacles.push_back(OBSTACLE ("L shape", 50,50,50,90,150,190,230,230,40,40));


    // test objects
    this->obstacles.push_back(OBSTACLE ("1st shape",50,90,130,170,270,270,270,270,40,40));
    this->obstacles.push_back(OBSTACLE ("2nd shape",50,90,130,170,270,270,270,270,40,40));
    this->obstacles.push_back(OBSTACLE ("3rd shape", 50,50,50,50,270,310,350,390,40,40)); 
    this->obstacles.push_back(OBSTACLE ("4th shape", 50,50,50,50,270,310,350,390,40,40)); 

    this->obstacles.push_back(OBSTACLE ("5th shape", 50,50,50,50,270,310,350,390,40,40)); 
    this->obstacles.push_back(OBSTACLE ("5th shape", 50,50,50,50,270,310,350,390,40,40)); 
    this->obstacles.push_back(OBSTACLE ("5th shape", 50,50,50,50,270,310,350,390,40,40)); 
    this->obstacles.push_back(OBSTACLE ("5th shape", 50,50,50,50,270,310,350,390,40,40)); 
    this->obstacles.push_back(OBSTACLE ("5th shape", 50,50,50,50,270,310,350,390,40,40)); 
    this->obstacles.push_back(OBSTACLE ("5th shape", 50,50,50,50,270,310,350,390,40,40)); 
    this->obstacles.push_back(OBSTACLE ("5th shape", 50,50,50,50,270,310,350,390,40,40)); 
    this->obstacles.push_back(OBSTACLE ("5th shape", 50,50,50,50,270,310,350,390,40,40)); 

    
}

void GameManager::spawn( )
{

    if(this->current_index < this->spawn_limit - 1)
    {
        if(this->obstacles[this->current_index].get_placementState())
        {
            this->current_index++;
            this->spawned_objects++;
        }
    }
    

}