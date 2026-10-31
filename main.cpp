#include <utility>
#include <fstream>

#include "print.h"
#include "maze.h"
#include "export.h"



int main(){
    Brain brain; 

    const int sel = 1;
    int* map = mazes[sel].data();
    int width = sizes[sel];
    int res;
    vector<int> out;

    export_map_to_csv(mazes[sel],width); 

    int row,col,*starting_point;
    row = 4;col = 4;
    starting_point = map + row*width + col;

    res = brain.solve_maze(map, starting_point, width);    
    out = brain.solve_shortest_path(starting_point, width, map);

    export_path(out,width);
    print("Tostado is",res);

    return 0;
}

//add members

//add init function