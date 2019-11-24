#include <iostream>
#include <cstring>

using namespace std;

int big_square(int, int, int*);
int square_calc(int, int, int, int*);
int is_square(int, int, int, int*, int);

int main () {
    int n, m;
    int* grid;
    string line;
    int res;

    cin >> n >> m;

    grid = new int[n * m];

    for(int i = 0; i < n; i++) {
        cin >> line;
        for(int j = 0; j < m; j++) grid[m * i + j] = line.at(j);
    } 

    res = big_square(n, m, grid);
    
    cout << res << endl;

    return 0;
}

int big_square(int n, int m, int* grid){
    int big = 1;
    int iteration = 0;

    for(int i = 0; i < n * m; i++) {
        iteration = square_calc(i, n, m, grid);
        if(big < iteration) big = iteration;
        //cout << big << endl;
    }

    return big;
}

int square_calc(int index, int n, int m, int* grid) {
    int top_size = 1;
    int temp = 0;
    int size = 2;

    //cout << "current Position: " << index << endl;

    while(true) {
        temp = is_square(index, n, m, grid, size);
        //cout << "size iteration" << size << endl;
        if(temp == -1) break;
        else if(temp == 1) top_size = size++;
        else size++;
    }

    top_size++;

    return top_size * top_size;
}

int is_square(int current_pos, int n, int m, int* grid, int size) {
    if(current_pos + (m * size) + size >= n * m) return -1;
    if(grid[current_pos] == grid[current_pos + m * size + size] && grid[current_pos] == grid[current_pos + size] && grid[current_pos] == grid[current_pos + m * size]) return 1;
    else return 0;
}