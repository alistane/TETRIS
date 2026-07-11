#include "GameManager.h"


void GameManager::Dropping()
{
    ob1.drop_obstacle();

}


void GameManager::Draw()
{
    this->g1.draw_grid();
    this->ob1.draw_obstacle(ORANGE);
    this->ob1.movement();

}

bool GameManager::approve()
{
    return this->ob1.get_placementState();
}


void GameManager::check_placement()
{
    

    std::vector<std::vector<float>>  final_placement;
   
    final_placement = this->ob1.give_position();

    // now we will run a for loop and ask the grid to give us coordinates of visual rects and if the position of object blocks is equal to visual rect, then we will turn grid_logic variable grid cells equal to 1.


    // COMMENT THIS CODE IN THE FINAL VERSION
    std::cout << "Object placed at the following coordinates : " << std::endl;

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




    for(int i = 0 ; i < 8 ; i++) // where i -> rows of grid
    {
        for(int j = 0; j <= 3; j++) // where j ->  block 1, 2, 3, 4
        {
            // firstly, checking the rows of the final placement of the object.
            if(this->g1.getRowPosition(i) == final_placement[j][1])
            {
                std::cout << "In ROW : " << i << "\n" << "Now checking for columns";
                for(int k = 0; k < 8; k++) // where k -> columns of grid
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
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            std::cout << "Row " << i << "\n" << "Column : " << j << "\n" 
            << "Value : " << this->g1.getValue(i, j) << std::endl;
        }
    }

    


}