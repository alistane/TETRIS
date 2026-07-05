#ifndef GRID
#include <raylib.h>
#include <iostream>
class GRID
{
    private:
        // these int variables will indicate whether they are filled or not. 0 for empty and 1 for filled.
        int r1c1 = 0, r1c2 = 0, r1c3 = 0, r1c4 = 0, r1c5 = 0, r1c6 = 0, r1c7 = 0, r1c8 = 0;
        int r2c1 = 0, r2c2 = 0, r2c3 = 0, r2c4 = 0, r2c5 = 0, r2c6 = 0, r2c7 = 0, r2c8 = 0;
        int r3c1 = 0, r3c2 = 0, r3c3 = 0, r3c4 = 0, r3c5 = 0, r3c6 = 0, r3c7 = 0, r3c8 = 0;
        int r4c1 = 0, r4c2 = 0, r4c3 = 0, r4c4 = 0, r4c5 = 0, r4c6 = 0, r4c7 = 0, r4c8 = 0;

        int r5c1 = 0, r5c2 = 0, r5c3 = 0, r5c4 = 0, r5c5 = 0, r5c6 = 0, r5c7 = 0, r5c8 = 0;
        int r6c1 = 0, r6c2 = 0, r6c3 = 0, r6c4 = 0, r6c5 = 0, r6c6 = 0, r6c7 = 0, r6c8 = 0;
        int r7c1 = 0, r7c2 = 0, r7c3 = 0, r7c4 = 0, r7c5 = 0, r7c6 = 0, r7c7 = 0, r7c8 = 0;
        int r8c1 = 0, r8c2 = 0, r8c3 = 0, r8c4 = 0, r8c5 = 0, r8c6 = 0, r8c7 = 0, r8c8 = 0;

        Rectangle r1c1_rec = {50,510,40,40};
        Rectangle r1c2_rec = {90,510,40,40};
        Rectangle r1c3_rec = {130,510,40,40};
        Rectangle r1c4_rec = {170,510,40,40};
        Rectangle r1c5_rec = {210,510,40,40};
        Rectangle r1c6_rec = {250,510,40,40};
        Rectangle r1c7_rec = {290,510,40,40};
        Rectangle r1c8_rec = {330,510,40,40};

        Rectangle r2c1_rec = {50,470,40,40};
        Rectangle r2c2_rec = {90,470,40,40};
        Rectangle r2c3_rec = {130,470,40,40};
        Rectangle r2c4_rec = {170,470,40,40};
        Rectangle r2c5_rec = {210,470,40,40};
        Rectangle r2c6_rec = {250,470,40,40};
        Rectangle r2c7_rec = {290,470,40,40};
        Rectangle r2c8_rec = {330,470,40,40};


        Rectangle r3c1_rec = {50,430,40,40};
        Rectangle r3c2_rec = {90,430,40,40};
        Rectangle r3c3_rec = {130,430,40,40};
        Rectangle r3c4_rec = {170,430,40,40};
        Rectangle r3c5_rec = {210,430,40,40};
        Rectangle r3c6_rec = {250,430,40,40};
        Rectangle r3c7_rec = {290,430,40,40};
        Rectangle r3c8_rec = {330,430,40,40};

        Rectangle r4c1_rec = {50,390,40,40};
        Rectangle r4c2_rec = {90,390,40,40};
        Rectangle r4c3_rec = {130,390,40,40};
        Rectangle r4c4_rec = {170,390,40,40};
        Rectangle r4c5_rec = {210,390,40,40};
        Rectangle r4c6_rec = {250,390,40,40};
        Rectangle r4c7_rec = {290,390,40,40};
        Rectangle r4c8_rec = {330,390,40,40};

        Rectangle r5c1_rec = {50,350,40,40};
        Rectangle r5c2_rec = {90,350,40,40};
        Rectangle r5c3_rec = {130,350,40,40};
        Rectangle r5c4_rec = {170,350,40,40};
        Rectangle r5c5_rec = {210,350,40,40};
        Rectangle r5c6_rec = {250,350,40,40};
        Rectangle r5c7_rec = {290,350,40,40};
        Rectangle r5c8_rec = {330,350,40,40};

        Rectangle r6c1_rec = {50,310,40,40};
        Rectangle r6c2_rec = {90,310,40,40};
        Rectangle r6c3_rec = {130,310,40,40};
        Rectangle r6c4_rec = {170,310,40,40};
        Rectangle r6c5_rec = {210,310,40,40};
        Rectangle r6c6_rec = {250,310,40,40};
        Rectangle r6c7_rec = {290,310,40,40};
        Rectangle r6c8_rec = {330,310,40,40};

        Rectangle r7c1_rec = {50,270,40,40};
        Rectangle r7c2_rec = {90,270,40,40};
        Rectangle r7c3_rec = {130,270,40,40};
        Rectangle r7c4_rec = {170,270,40,40};
        Rectangle r7c5_rec = {210,270,40,40};
        Rectangle r7c6_rec = {250,270,40,40};
        Rectangle r7c7_rec = {290,270,40,40};
        Rectangle r7c8_rec = {330,270,40,40};

        Rectangle r8c1_rec = {50,230,40,40};
        Rectangle r8c2_rec = {90,230,40,40};
        Rectangle r8c3_rec = {130,230,40,40};
        Rectangle r8c4_rec = {170,230,40,40};
        Rectangle r8c5_rec = {210,230,40,40};
        Rectangle r8c6_rec = {250,230,40,40};
        Rectangle r8c7_rec = {290,230,40,40};
        Rectangle r8c8_rec = {330,230,40,40};

    public:
        void draw_grid();
        

};
#endif