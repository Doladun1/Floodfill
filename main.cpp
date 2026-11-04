#include <utility>
#include <fstream>

#include "common.h"
#include "maze.h"
#include "export.h"



int main(){ 

    const int sel = 2;
    int* map = mazes[sel].data();
    int width = sizes[sel];
    int row,col,*starting_point;
    vector< vector< int > > out_map;
    vector< vector< int > > out_path;

    row = 3;col = 0;
    starting_point = map + row*width + col;

    

    Brain brain(width,map,starting_point); 

    brain();    

    brain.solve_maze(starting_point);   

    brain();

    brain.export_map(out_map);
    export_map_to_csv(mazes[sel],width); 
    export_FFmap_to_csv(out_map,width); 

    brain.export_path(out_path);
    exportFF_path(out_path);
    /* out = brain.solve_shortest_path(starting_point, width);

    export_path(out,width);
    print("Tostado is",res); */

    return 0;
}

//add members

//add init function