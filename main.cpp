#include <utility>
#include <iostream>
#include <fstream>

enum Heading{
    north=0;    
    east=1;
    south=2;
    west=3;
}

//Create brain class
class Brain{
    cell** map;
    int x_pos;
    int y_pos;
    Heading heading;
    int solve_maze(cell* input);
    void update_map(int wall_select, int x_index, int y_index);

}

/*solve maze - Recursively solve maze
    start from zero brain will 
    "take" in a cell
    if no wall -> go forward 'call solve on next cell'
    if wall -> turn right 'go to next clause'
    if no wall -> check if last move was this move 'prevent loop'
    if wall -> dead-end pop stack "streak" number of spaces
    for every successful move update pos accordingly
    when we hit all zero return 0;



*/
std::pair<int,int> Brain::solve_maze(cell* input,Heading heading, Heading last_heading, _Bool chng_dir){
    std::pair<int,int> res;

    if(input == NULL) 
        return {0,0};
    else if( !(1>>heading & input) && ( (heading^last_heading) != 2) ) {
        x_pos++;y_pos++;
        res = solve_maze(input++,heading,heading,0,res+1);
    } //update pos and move to next cell
    
    else if( (heading == last_heading) && chng_dir )
        return res; //backtrack
    
    else {   
        res = solve_maze(input,heading++,last_heading,1);//try next direction      
    }

    if ( res.first ){
            //undo pos change subtract res by 1 <- yes
            if (heading == last_heading)
                return {res.first--,res.second};
            return res;//until last_heading != heading comp
            //return res until we reach first wall pos
    }
    else if ( res.second ){
        res = solve_maze(input,heading++,last_heading,1);
    }

    return 0;
}

//add members

//add init function