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
    Brain(int width,int* head,int* starting_point);
    void initialize_map(int width);

    void operator()();

    bool isThereAWall(int dir, int cell);
    bool isOppositeDir(int a, int b);
    
    int solve_maze(int* cell);/**/
    int next_step(int* cell, int last_dir = 5);/**/

    void export_map(vector< vector<int> >& des);
    void print_map();

    void update_path();
    void export_path(vector<vector<int> >& des);

    int next_cell(int dir, int width);
    int next_cell_x(int dir);
    int next_cell_y(int dir);

    private:
    int x_pos;
    int y_pos;
    int* head;
    int width;

    vector< vector<int> > map;    
    vector< vector<int> > path;
    vector<int> shortest_path;
    
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