#ifndef MAZE_H
#define MAZE_H
#define NO_VEC 1

#include <iostream>
#include <string>
#include <climits>

#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;



using std::cout;
using std::endl;

enum class Direction{
    north=0,    
    east=1,
    south=2,
    west=3,
    max=4
};

const char* toString(Direction direction) ;
const char* toStringInt(int direction) ;

typedef struct cell{
    bool top,bottom,left,right;
}cell;


//Create brain class
class Brain{
    public:
    int x_pos;
    int y_pos;
    Direction dir;
    std::unordered_set<int> visited_cells;
    vector<int> shortest_path;
    #if NO_VEC
    int solve_maze(int* cell, Direction curr_dir, int count, int width);
    #else
    int solve_maze(vector<int> map,int index, Direction curr_dir, int count,int width);
    #endif
    void update_map(int wall_select, int x_index, int y_index);

};

/*solve maze - Recursively solve maze
    New idea. Like a binary tree with n children we'll loop through each
    direction and recurse path with a path. ONly works for maze w/ no loops
    Probably takes longer to solve... who cares. 

    Same conditions if wall exists dont go | If last move was complement don't go
    If we see deadend return until we're back
    Only break for loop when zero is returned

*/

#endif