// Export csv to file
//import and open fstream
//write out each value to right row + column
// translate it to format tkinter understands

#include <fstream>
#include <vector>

using std::ofstream;
using std::endl;

void export_map_to_csv(std::vector<int>& map, int width){

    //cout << map.size();

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