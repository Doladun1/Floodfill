enum Heading{
    north=1;    
    east=2;
    south=4;
    west=8;
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
int Brain::solve_maze(cell* input){


    if(input == NULL) return 0;
    else if( !(heading & input) ) {x_pos++;y_pos++;solve_maze(input++);} //update pos and move to next cell
    else{
        heading>>1
    }

}

//add members

//add init function