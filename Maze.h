#include <iostream>
#include <string>

using std::cout;
using std::endl;

enum class Direction{
    north=0,    
    east=1,
    south=2,
    west=3,
    count = 4
};

const char* toString(Direction direction) {
    switch (direction) {
        case Direction::north:   return "north";
        case Direction::south: return "south";
        case Direction::east:  return "east";
        case Direction::west: return "west";
    }

    return "Unknown";
}

/*
int *TestBank[6]={
    {6,6,6,4,2,1};
};*/


typedef struct cell{
    bool top,bottom,left,right;
}cell;
