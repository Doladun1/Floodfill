#include <iostream>
#include <string>
#include <climits>

using std::cout;
using std::endl;

enum class Direction{
    north=0,    
    east=1,
    south=2,
    west=3,
    max=4
};

const char* toString(Direction direction) {
    switch (direction) {
        case Direction::north:   return "north";
        case Direction::south: return "south";
        case Direction::east:  return "east";
        case Direction::west: return "west";

        default: return "Unknown";
    }

    return "Unknown";
}

/*
int *TestBank[6]={
    {6,6,6,4,2,1};
};

//object w/ variable size arrays | all const
// Union??

const int maps[5][5] =
                    {{0,0,0,0,
                    10,15,15,0,
                    9,6,15,0,
                    15,9,5,0},
                    {0,0,0,0,0,
                    10,15,10,15,0,
                    9,4,1,7,0,
                    15,10,15,15,0,
                    15,9,5,7,0}};

union test { int var; };

*/

typedef struct cell{
    bool top,bottom,left,right;
}cell;
