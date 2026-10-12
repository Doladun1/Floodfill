#include <utility>
#include <fstream>


#include "maze.h"
#include "export.h"

 
 
int main(){
    Brain brain; 
    //int arr[10] = {1,2,5,10,3,4,5};
    //int arr[10] = {6,6,6,9,5,5,7,5,13,6};
    int arr[10] = {10,10,1,5,5,6,10,11,5};
    int map[4*4] = {0,0,0,0,
                    10,15,15,0,
                    9,6,15,0,
                    15,9,5,0};

    const int len =6,width=6;

#if NO_VEC
    int map2[(len)*(width)] =    { 0, 0, 0, 0, 0, 0,
                                   0,13, 5, 3,11, 0,
                                   0,10,15,10,14, 0,
                                   0,13, 1, 4, 3, 0,
                                   0,15,10,15,14, 0,
                                   0, 0, 0, 0, 0, 0};
#else 
    vector<int> map2 = { 0, 0, 0, 0, 0, 0,
                         0,13, 5, 3,15, 0,
                         0,15,15,10,15, 0,
                         0,13, 1, 4, 3, 0,
                         0,15,10,15,14, 0,
                         0, 0, 0, 0, 0, 0};
#endif

    std::vector<int> values( 
        std::begin(map2),
        std::end(map2)
    );
    export_map_to_csv(values,width); 
    //cout << test << endl;
    //cout << *(map2+10) << endl;
    int row,col,*starting_point;
    row = 1;col = 1;
    starting_point = map2+row*width+col;
    std::cout << brain.solve_maze(starting_point, Direction::north,0,width) << endl;
    
    cout << "Best way out: ";
    while(!brain.shortest_path.empty()){        
        cout << toStringInt(brain.shortest_path.back()) << "->";
        brain.shortest_path.pop_back();
    }
    cout << endl;
    return 0;
}

//add members

//add init function