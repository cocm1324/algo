#include <iostream>

using namespace std;

int scan_line(string, int);

int main() {
    int width, height;
    string* grid = NULL;
    int space = 0;

    cin >> height >> width;
    
    grid = new string[height];

    for(int i = 0; i < height; i++) {
        cin >> grid[i];
        space += scan_line(grid[i], width);
    }

    // visibility line
    // for(int i = 0; i < height; i++) {
    //     cout << grid[i] << endl;
    // }

    cout << space << endl;

    delete[] grid;
    grid = NULL;

    return 0;
}

int scan_line(string line, int size) {
    int count = 0;
    bool inside = false;

    for(int i = 0; i < size; i++) {
        //start or end of poligon
        if(line.at(i) == '/' || line.at(i) == '\\'){
            //start of poligon
            if(!inside) inside = !inside;
            //end of poligon
            else {
                inside = !inside;
                count++;
            }
        }
        //outside or inside of poligon
        else {
            if(inside) count++;
        }
    }
    
    return count;
}