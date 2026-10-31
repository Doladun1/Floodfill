#include "maze.h"
#include "print.h"

const char* toString(int direction) {
    switch (direction) {
        case 0: return "north";
        case 1: return "east";
        case 2: return "south";
        case 3: return "west";

        default: return "Unknown";
    }
    return "Unknown";
}

bool Brain::isThereAWall(int dir, int cell){
    return ((1<< dir) & cell) ? 1 : 0;
}

bool Brain::isOppositeDir(int a, int b){

    return ( b < 5 ? (a ^ b) == 2 : 0 );
}

int Brain::next_cell(int dir,int width){
    int buf;
    buf = (dir%2) ? 1 : -width;
    buf = (dir>1) ? -buf : buf;

    return buf;
}

int Brain::solve_maze(int*head, int* cell, int width, int curr_dir){
    if(!*cell) return 0;

    int res =1;
    int n_cell = 0;

    print("Checking Cell: [", (cell-head)/width,"][", (cell-head)%width,"]");
    print(cell-head,width);

    for(int new_dir = 0; new_dir < 4; ++new_dir){
        if ( !isThereAWall(new_dir,*cell) && 
             !isOppositeDir(new_dir,curr_dir) ) {

            print("Going", toString(new_dir));

            n_cell = next_cell(new_dir,width);
            
            //check if already visited then add to visited 
            //then go to next cell
            if (visited_cells.find(cell - head + n_cell) != visited_cells.end() ){
                print("Loop Found SHITT");
                visited_cells.erase(cell - head);
                return 1;
            }

            visited_cells.insert( cell - head );
            res = solve_maze(head, (cell+n_cell), width, new_dir);
            }

        if(!res) {
            shortest_path.push_back(new_dir);
            return 0;
        }
    }
    visited_cells.erase(cell - head);
    print("Dead End Found Returning...");
    return 1;
}

vector<int> Brain::solve_shortest_path(int* cell,int width, int* head){
    print("Solving...", *cell);
    vector<int> out;
    for(auto item = shortest_path.rbegin();
        item != shortest_path.rend(); item++ ){
        
        out.push_back(cell-head);
        print("Current Cell:", *cell, "Going:", toString(*item));
        
        cell = cell + next_cell(*item,width);
    } 
    out.push_back(cell-head);
    return out;   
}

