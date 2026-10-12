#include "maze.h"

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

const char* toStringInt(int direction) {
    switch (direction) {
        case 0:   return "north";
        case 1: return "east";
        case 2:  return "south";
        case 3: return "west";

        default: return "Unknown";
    }
    return "Unknown";
}

#if NO_VEC
int Brain::solve_maze(int* cell,Direction curr_dir, int count,int width){
    if(cell == NULL) return 0;
    if(!*cell) return 0;
    int res =1;
    int next_cell = 0;
    int x=1,y=-width;
    //if (count == 10 ) return 0;
    cout << "Checking Cell:" << count << " - " << *cell << endl;

    Direction directions[] = {
        Direction::north,        Direction::east,
        Direction::south,        Direction::west
    };
       // return 0;
    for(Direction new_dir : directions){
        if ( !(1<< (static_cast<int>(new_dir)) & *cell) 
            && ( (static_cast<int>(new_dir)^static_cast<int>(curr_dir)) != 2) ){
               /**/ cout << " Going: " << toString(new_dir) << endl;
              /**/  cout << " for:" <<  *cell << endl;
              /**/  cout << " From: " << toString(curr_dir) << endl;
                next_cell = (static_cast<int>(new_dir)%2) ? x : y;
                next_cell = (static_cast<int>(new_dir)>1) ? -next_cell : next_cell;
                    cout << "Next up: " << next_cell << endl;
                //if (visited_cells.find(*cell+next_cell) != visited_cells.end() ){
                //    cout << "Loop Found holy shit" << endl;
                //    return 1;
                //}
                visited_cells.insert(*cell+next_cell);
                res = solve_maze( (cell+next_cell) ,new_dir,++count, width);
            }
            
        if(!res) {
            shortest_path.push_back(static_cast<int>(new_dir));
            return 0;
        }
    }
    // Add loop detector
    cout<< "Dead End Found Returning..." << endl;
    return 1;
}
#else
int Brain::solve_maze(vector<int> map, int index, Direction curr_dir, int count,int width){
    if(map[index] == NULL) return 0;
    if(!*cell) return 0;
    int res =1;
    int next_cell = 0;
    int x=1,y=width;
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
                res = solve_maze( (cell+next_cell) ,new_dir,++count, width);
            }
            
        if(!res) return 0;
    }
    cout<< "Dead End Found Returning..." << endl;
    return 1;
}
#endif