// The flood fill
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
Create an algorithm that traverses a maze | Before that we have to 
Create a maze
Create a GUI | Create an rover/rat/dot to traverse maze | 
Define the walls of the maze 
Define the start point and final point
Create traversal technique | Update at each step
Each tile has four sides | Some sides are connected |
In the matrix you share with others | elm [2][1] speaks to [2][0],[2][2],[1][1], & [3][1]
map update algorithm is gonna be messy just use a switch 
Each tile will have four elms top,down,left,right | and they will be 0 or 1
All corners will be preblocked
Omit the maze class | create Tile array call it maze 
Need to do some maze research
*/

/*side enum*/
enum Wall{
    Top,
    Left,
    Right,
    Bottom
};


//Create FloodFil Maze Object
//Define constructors and creator scheme
//Add walls + solution tile
//Define start and end tiles
typedef struct Tile{
    _Bool left,right,top,bottom;
}Tile;

void setWall(Tile**maze,int col,int row, int combo);

//TODO: Deal with shared borders
void fill_maze(int len, int wid, Tile **maze){
    int count =0;

    for(int i=0;i<len;i++){
        maze[i][0].left = true;
        maze[i][wid-1].right = true;
    }

    for(int i=0;i<wid;i++){
        maze[0][i].top = true;
        maze[len-1][i].bottom = true;
    }

    for(int i=0;i<wid;i++){
        setWall(maze,2,i,15);
        setWall(maze,3,i,15);
        setWall(maze,0,i,15);
        setWall(maze,1,i,15);
        
    }
}

//TODO: Use strcat + strdub print combo
//We want to print all the top first 
//then print the sides
//then the bottom
void print_maze(int len, int wid, Tile**maze){
    int csr, line=0;

    //print top
    for(csr = 0;csr<wid;csr++){
        if(maze[line][csr].top) printf(" _ _ _ _");
        else printf("\t");
    }
    printf("\n");

    for(line = 0;line<len;line++){
        
        //print left and bottom
  
        for(csr = 0;csr<wid;csr++){
            if(maze[line][csr].left) printf("|");
            else printf(" ");
            if(maze[line][csr].bottom) printf("_ _ _ _");
            else printf("\t");
        }
        //print right hand border
        if(maze[line][csr-1].right) printf("|");

        //round off
        printf("\n"); 
    }
    
}

/*   Set walls in maze based
    on value. 0-15 set each bit
    0- left wall, 1-bottom, 2-right, 3-top

    Ex: 5- left+right wall
*/
void setWall(Tile**maze,int col,int row, int combo){
    if(combo & 1<<0)    maze[col][row].left = true;
    else maze[col][row].left = false;

    if(combo & 1<<1)    maze[col][row].bottom = true;
    else maze[col][row].bottom = false;

    if(combo & 1<<2)    maze[col][row].right = true;
    else maze[col][row].right = false;

    if(combo & 1<<3)    maze[col][row].top = true;
    else maze[col][row].top = false;
}


/*
class Maze {
    public:
        int length;
        int width;
        Tile **maze;

    private:
}

Maze::Maze(int len, int wid){
    maze = calloc(sizeof(Tile)*len*wid);
}
*/

//Create agent to traverse
//Add traversal technique

//TODO: Create GUI/console output for demo


void main() {
    int len=6,wid=4;

    //Tile maze[4][3];
    Tile **maze = (Tile**) calloc(len,sizeof(Tile*));
    if(!maze) return;

    for(int i=0;i<len;i++){
        maze[i] = (Tile*) calloc(wid,sizeof(Tile));
    }

    //print_maze(len,wid,maze);
    fill_maze(len,wid,maze);
    print_maze(len,wid,maze);

    // new Maze maze1 = Maze(4,3); // returns Maze of size 4x3
}
