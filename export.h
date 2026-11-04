// Export csv to file
//import and open fstream
//write out each value to right row + column
// translate it to format tkinter understands

#include <fstream>
#include <vector>

using std::ofstream;
using std::endl;
using std::fstream;

void export_map_to_csv(std::vector<int>& map, int width){

    std::fstream file("Test.csv", std::ios::out);

    int count =0;

    for(int number : map ) {
        if (count == width-1){
            file << number << endl;
            count = 0;
        }else{
            file << number << ',';
            count++;
        }
    }
}

void export_FFmap_to_csv(std::vector<std::vector<int> >& map,int width){

    std::fstream file("Test2.csv", std::ios::out);

    for(auto i = 0; i < width; i++){
        for(auto j = 0; j < width; j++){ 
            if (j == width-1)
                file <<  map[i][j];
            else   
                file <<  map[i][j] << ", ";   
        }
        file << endl;
    }
}

void export_path(std::vector<int> path, int width){
    fstream file("path.txt", std::ios::out);

    for(std::size_t i =0; i < path.size(); ++i){
        file << path[i]/width << "," << path[i]%width << endl;
    }
}

void exportFF_path(std::vector<std::vector<int> >& path){
    fstream file("path2.txt", std::ios::out);

    for(std::size_t i =0; i < path.size(); ++i){
        file << path[i][0] << "," << path[i][1] << endl;
    }
}