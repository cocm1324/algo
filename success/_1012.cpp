#include <stdio.h>
#include <iostream>

#define MAX_SIZE 50

using namespace std;

int wormCalc(int n, int m, int grid[][MAX_SIZE]);
void deleteAdjacent(int x, int y, int grid[][MAX_SIZE]);

int main(){
  int testCase = 0;
  int n, m, k;
  int grid[MAX_SIZE][MAX_SIZE];
  int temp1, temp2;
  int worm = 0;

  scanf("%d", &testCase);
  for(int i = 0; i < testCase; i++){

    for(int a = 0; a < MAX_SIZE; a++){
      for(int b = 0; b < MAX_SIZE; b++){
        grid[a][b] = 0;
      }
    }

    scanf("%d %d %d", &n, &m, &k);
    for(int j = 0; j < k; j++){
      scanf("%d %d", &temp1, &temp2);
      grid[temp1][temp2] = 1;
    }

    worm = wormCalc(n, m, grid);
    printf("%d\n", worm);
  }

  return 0;
}

int wormCalc(int n, int m, int grid[][MAX_SIZE]){
  int ret = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] != 0){
        ret++;
        deleteAdjacent(i, j, grid);
      }
    }
  }

  return ret;
}

void deleteAdjacent(int x, int y, int grid[][MAX_SIZE]){
  grid[x][y] = 0;

  if(x != 0 && grid[x-1][y] == 1){
    deleteAdjacent(x - 1, y, grid);
  }
  if(x != MAX_SIZE - 1 && grid[x+1][y] == 1){
    deleteAdjacent(x + 1, y, grid);
  }
  if(y != 0 && grid[x][y-1] == 1){
    deleteAdjacent(x, y-1, grid);
  }
  if(y != MAX_SIZE -1 && grid[x][y+1] == 1){
    deleteAdjacent(x, y+1, grid);
  }
}
