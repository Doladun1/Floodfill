#include <utility>
#include <fstream>

#include "Maze.h"


//Create brain class
class Brain{
    public:
    cell** map;
    int x_pos;
    int y_pos;
    Direction dir;
    int solve_maze(int* cell, Direction curr_dir, int count);
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
int Brain::solve_maze(int* cell,Direction curr_dir, int count){
    if(cell == NULL) return 0;
    if(!*cell) return 0;
    int res =1;
    int next_cell = 0;
    int x=1,y=5;
    //if (count == 10 ) return 0;
    cout << "Checking Cell:" << count << " - " << *cell << endl;

    Direction directions[] = {
        Direction::north,
        Direction::east,
        Direction::south,
        Direction::west
    };
       // return 0;
    for(Direction new_dir : directions){
        if ( !(1<< (static_cast<int>(new_dir)) & *cell) 
            && ( (static_cast<int>(new_dir)^static_cast<int>(curr_dir)) != 2) ){
                cout << " Going: " << toString(new_dir) << endl;
                cout << " for:" <<  *cell << endl;
                cout << " From: " << toString(curr_dir) << endl;
                next_cell = (static_cast<int>(new_dir)%2) ? x : y;
                next_cell = (static_cast<int>(new_dir)>1) ? -next_cell : next_cell;
                res = solve_maze( (cell+next_cell) ,new_dir,++count);
            }
            
        if(!res) return 0;
    }
    cout<< "Dead End Found Returning..." << endl;
    return 1;
}

int main(){
    Brain brain;
    //int arr[10] = {1,2,5,10,3,4,5};
    //int arr[10] = {6,6,6,9,5,5,7,5,13,6};
    int arr[10] = {10,10,1,5,5,6,10,11,5};
    int map[4*4] = {0,0,0,0,
                    10,15,15,0,
                    9,6,15,0,
                    15,9,5,0};

    int map2[5*5] = {0,0,0,0,0,
                    10,15,10,15,0,
                    9,4,1,7,0,
                    15,10,15,15,0,
                    15,9,5,7,0};

    //cout << test << endl;
    //cout << *(map2+10) << endl;
    std::cout << brain.solve_maze(map2+7,Direction::north,0);
    return 0;
}

//add members

//add init function