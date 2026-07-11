#ifndef GRID
#include <raylib.h>
#include <iostream>
class GRID
{
    private:
        // these int variables will indicate whether they are filled or not. 0 for empty and 1 for filled.
        
        const int rows = 8, columns = 8;
        int grid_logic[8][8] = {};

        
        Rectangle visual_recs[8][8] = {};


    public:
        GRID();
        void draw_grid();
        

        int getRowPosition(int row);
        int getColumnPosition(int column);
        int getValue(int row, int column);

        // sets the individual blocks in the grid to filled or empty, 0 means empty , 1 means filled.
        void setCell(int row, int column, int value);



};
#endif