#include "Grid.h"


GRID::GRID()
{
    

}


void GRID::draw_grid()
{
    
    int addx = 50; // starting point of our c1
    int addy = 990;// starting point of our r1
    
    for(int i = 0; i < this->rows; i++)
    {
        // we are adding x wagera
        for(int j = 0; j < this->columns; j++)
        {
            this->visual_recs[i][j].x = addx;
            this->visual_recs[i][j].height = 40;
            this->visual_recs[i][j].width = 40;
            this->visual_recs[i][j].y = addy;
            DrawRectangleLinesEx(this->visual_recs[i][j], 1.5, {45,45,45,255});
            addx+=40;
        }
        addx = 50;
        addy-= 40;

    }

}

int GRID::getRowPosition(int row)
{
    return this->visual_recs[row][0].y;
}


int GRID::getColumnPosition(int column)
{
    return this->visual_recs[0][column].x;
}


void GRID::setCell(int row, int column, int value)
{
    if(value >= 0 && value <= 1)
        this->grid_logic[row][column] = value;
    else
        std::cout << "Invalid value cannot be assigned.." << std::endl;
}





int GRID::getValue(int row, int column) 
{
    return this->grid_logic[row][column];
}

int GRID::getValueFromCoordinates(int x, int y)
{
    for(int i = 0; i < this->rows; i++)
    {
        for(int j = 0; j < this->columns; j++)
        {

             if(this->visual_recs[i][j].x == x && this->visual_recs[i][j].y == y)
             {
                return this->grid_logic[i][j];
             }
           
        }
    }

    return -1; // if we dont find anything.
}








int GRID::get_no_of_rows()
{
    return this->rows;
}

int GRID::get_no_of_columns()
{
    return this->columns;
}
