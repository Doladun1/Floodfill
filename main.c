#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//Brain

//Recursion solver

//Input format

//cell structure | Top, bottom , left, right
typedef struct cell{
    _Bool top,bottom,left,right;
}cell;

//cell map[3][3];

// Create matrix of cells | populate the values
cell** initialize_map(int x, int y){
    cell **map = calloc(x, sizeof *map);

    for(int i=0; i< x; i++){
        map[i] = calloc(y,sizeof *map[i]);
    }

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            map[i][j].top = rand() % 2;
            map[i][j].bottom = rand() % 2;
            map[i][j].left = rand() % 2;
            map[i][j].right = rand() % 2;
            
        }
    }
    return map;
}



//index map
//map[0][1];


void main(){
    srand(time(NULL));

    cell** map = initialize_map(3,3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("cell ID: (%d,%d) Wall setting | T:%d, B:%d, L:%d, R:%d\n",
            i,j,map[i][j].top,map[i][j].bottom,map[i][j].left,map[i][j].right);
        }
    }
}


