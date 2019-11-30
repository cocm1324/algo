#include <iostream>
#define GRID_MAX_SIZE 500

using namespace std;

void mark(int**, int, int, int, int);
int grid_surface(int**);

int main(){
      int input;
      int x1, y1, x2, y2;
      int** grid;
      int surface = 0;

      grid = new int*[GRID_MAX_SIZE];
      for(int i = 0; i < GRID_MAX_SIZE; i++){
            grid[i] = new int[GRID_MAX_SIZE];
            for(int j = 0; j < GRID_MAX_SIZE; j++){
                  grid[i][j] = 0;
            }
      }

      cin >> input;
      for(int i = 0; i < input; i++){
            cin >> x1 >> y1 >> x2 >> y2;
            mark(grid, x1, y1, x2, y2);
      }

      surface = grid_surface(grid);

      cout << surface << endl;

      return 0;
}

void mark(int** grid, int x1, int y1, int x2, int y2){
      for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++){
                  grid[i][j] = 1;
            }
      }
}

int grid_surface(int** grid){
      int sum = 0;

      for(int i = 0; i < GRID_MAX_SIZE; i++){
            for(int j = 0; j < GRID_MAX_SIZE; j++){
                  sum += grid[i][j];
            }
      }

      return sum;
}
