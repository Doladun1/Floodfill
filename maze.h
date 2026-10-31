#ifndef MAZE_H
#define MAZE_H


#include <iostream>
#include <string>
#include <climits>

#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;


using std::cout;
using std::endl;


//const char* toString(Direction direction) ;
const char* toString(int direction) ;

//Create brain class
class Brain{
    public:
    int x_pos;
    int y_pos;
    std::unordered_set<int> visited_cells;
    vector<int> shortest_path;

    int solve_maze(int* head, int* cell, int width, int curr_dir = 5);/**/
    vector<int> solve_shortest_path(int* cell,int width, int* head);
    bool isThereAWall(int dir, int cell);
    bool isOppositeDir(int a, int b);

    void update_map(int wall_select, int x_index, int y_index);
    int next_cell(int dir,int width);
};

/*solve maze - Recursively solve maze
    New idea. Like a binary tree with n children we'll loop through each
    direction and recurse path with a path. ONly works for maze w/ no loops
    Probably takes longer to solve... who cares. 

    Same conditions if wall exists dont go | If last move was complement don't go
    If we see deadend return until we're back
    Only break for loop when zero is returned

*/

#endif //MAZE_H