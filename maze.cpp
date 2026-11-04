#include "maze.h"
#include "common.h"

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

int Brain::next_cell_x(int dir){
    int buf;
    buf = (dir%2) ? 1 : 0;
    buf = (dir>1) ? -buf : buf;

    return buf;
}

int Brain::next_cell_y(int dir){
    int buf;

    buf = (dir%2) ? 0 : 1;
    buf = (dir>1) ? buf : -buf;

    return buf;
}

Brain::Brain(int width,int* head,int* starting_point)
    :head(head), width(width) {

    initialize_map(width);
    y_pos = (starting_point-head)/width;
    x_pos = (starting_point-head)%width;
}

void Brain::operator()(){
        //print("\n Agent: 0");
        print("\n{ Maze: ",head);
        print("  Current Pos: [",y_pos,"][",x_pos,"]"); 
        print("  Size: ", width,"x",width);
        print_map();
        print("}");
    }

void Brain::initialize_map(int width){
    int x_sol = width/2 - 1, y_sol = x_sol;
    int x_off =0,y_off =0;
    
    for(auto i =0; i<width;i++){
        map.push_back(vector<int>(width,0));
    }

    print("[",y_sol,"][",x_sol,"]"); 
    for(auto i = 0; i < width; i++){
        for(auto j = 0; j < width; j++){
            x_off = j > x_sol ? 1 : 0;
            y_off = i > y_sol ? 1 : 0;
            map[i][j] = abs(j-(x_sol+x_off) ) + abs(i-(y_sol+y_off)) ;   
        }
    }
}

void Brain::print_map(){

    for(auto i = 0; i < width; i++){
        cout << "\t";
        for(auto j = 0; j < width; j++){ 
            cout <<  map[i][j] << " ";   
        }
        cout << endl;
    }
}

void Brain::export_map(vector< vector<int> >& des){
    des = map;
}

void Brain::export_path(vector< vector<int> >& des){
    des = path;
}

//Create the weighted map based on dimensions
//matrix might be better for this w/ traversal

//Create traversal function / try recursion once
//It will check all possible moves and
//go to next lower step if no wall
//go to higher point and increment visited cells

//Traversal function - next_step() + solve_maze()
/*
    Next step will be given current index | From here it
    will check neighboring cells | We're interested in cell:
    That is not opposiite direction, that is one step less,
    and/or has no obstruction. Don't take immediately after find
    we have to save poll results then pick the best

    isOppositeDir: -inf
    isWallPresent: -inf
    isOneStepLess: +1

    Pick the best step

    Dont backbridge until we get to next_cell YES!!!

    Check if cell_value is zero YES: return NO: continue;

    Needs: x_pos,y_pos,map[y][x] value, 0-3, path, *curr_cell
*/
int Brain::next_step(int* cell,int last_dir){
    
    //initial map value check
    int best = INT_MAX, next_dir =0;
    int x_buf=0,y_buf=0;
    print("[",y_pos,"][",x_pos,"]"); 
    if (!map[y_pos][x_pos]) {
        //print("[",y_pos,"][",x_pos,"]"); 
        print("All done Leaving...");
        update_path();
        path.push_back({y_pos,x_pos});return 0;}

    
    //Backbridge check
    //if current_cell > last_cell : update_path()
    /*if(!path.empty()){
        if (  map[y_pos][x_pos] >= map[path.back()[0]][path.back()[1]] )
            update_path();
        print(path.back()[0],path.back()[1]);
    }*/

    //Ranker
    for(int new_dir = 0; new_dir < 4; ++new_dir){
        if (isOppositeDir(new_dir,last_dir) ||
            isThereAWall(new_dir,*cell) ) continue;//{
                //print("Wall:",*cell,"Dir:",new_dir,"Skipping...");continue;}

        x_buf = next_cell_x(new_dir);
        y_buf = next_cell_y(new_dir);

        if(map[y_pos+y_buf][x_pos+x_buf] < best) {
            //print("Current:",best);
            next_dir = new_dir;
            best = map[y_pos+y_buf][x_pos+x_buf];

        }
    }

    print("New:",best,"Going",toString(next_dir));
    
    //add the visited cell ( after Ranker ) : 
    //We want the indices not the value
    path.push_back({y_pos,x_pos});


    

    //make the jump
    x_buf = next_cell_x(next_dir);
    y_buf = next_cell_y(next_dir);
    x_pos += x_buf;
    y_pos += y_buf;
    next_step(cell + x_buf + y_buf*width,next_dir);

    

    return 0;
}

int Brain::solve_maze(int*cell){
   return next_step(cell);
}

void Brain::update_path(){
    //take value at curr_idx
    //assign all previous idx +1 
    //map[path.back()[0]][path.back()[1]] = map[y_pos][x_pos] + 1;
    int count =1;
    for(auto coord = path.rbegin();
        coord != path.rend(); coord++ ){ 
        map[(*coord)[0]][(*coord)[1]] = map[y_pos][x_pos] + count;
        count++;  
    }
}