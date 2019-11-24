#include <iostream>
#include <queue>

#define ROWLEN 5

using namespace std;

int loop(int*, int, int, int, int, int);
int zero_factor(int*, int, int, int, int, int, int, int);
int count_line(int*, int, int, int, int, int, int, int);
bool grid_check(int*);

int main() {
    int* grid = new int[ROWLEN * ROWLEN];
    int count = 0;
    string temp;

    for(int i = 0; i < ROWLEN; i++) {
        cin >> temp;
        for(int j = 0; j < ROWLEN; j++) {
            grid[i * ROWLEN + j] = temp.at(j) == '*' ? 1 : 0;
        }
    }

    count = loop(grid, 0, ROWLEN - 1, 0, ROWLEN - 1, count);
    

    cout << count << endl;

    return 0;
}

int loop(int* grid, int x_win_start, int x_win_end, int y_win_start, int y_win_end, int loop_count) {
    int count = loop_count;
    int temp = 0;
    int temp_factor = 0;
    queue<int> q;

    int biggest = -1;
    int pos = 0;
    int dir = 0;
    int is_delete = 0;

    int x_start = x_win_start;
    int x_end = x_win_end;
    int y_start = y_win_start;
    int y_end = y_win_end;

    for(int i = 0; i < ROWLEN * ROWLEN; i++) {
        if(grid[i] == 1) q.push(i);
    }
    
    while(q.size()) {
        temp = q.front();

        for(int i = 0; i < 4; i++) {
            temp_factor = zero_factor(grid, temp % ROWLEN, temp / ROWLEN, x_win_start, x_win_end, y_win_start, y_win_end, i);
            if(biggest < temp_factor){
                biggest = temp_factor;
                pos = temp;
                dir = i;
                temp_factor != 0 ? is_delete = 1 : is_delete = 0;
            }
        }
    }

    switch (dir) {
        case 0:
            grid[pos - ROWLEN] = 1;
            grid[pos] = 0;
            is_delete == 1 ? y_end-- : y_end;  
            break;
        case 1:
            grid[pos - 1] = 1;
            grid[pos] = 0;
            is_delete == 1 ? x_end-- : x_end;  
            break;
        case 2:
            grid[pos + ROWLEN] = 1;
            grid[pos] = 0;
            is_delete == 1 ? y_start-- : x_start;  
            break;
        case 3:
            grid[pos + 1] = 1;
            grid[pos] = 0;
            is_delete == 1 ? x_start-- : x_start;  
            break;    
    }

    count++;

    if(grid_check(grid)){
        return count;
    }
    else {
        count = loop(grid, x_start, x_end, y_start, y_end, count);
        return count;
    }
    
    return 0;
} 

//dir is direction, 0 -> up, 1 -> left, 2 -> down, 3->right
//returns -1 when it cannot be done (ex -> moving out of window)
int zero_factor(int* grid, int x, int y, int x_win_start, int x_win_end, int y_win_start, int y_win_end, int dir){
    int count = 0;
    
    switch (dir){
        case 0:
            if(y == y_win_end){
                count = count_line(grid, x, y, x_win_start, x_win_end, y_win_start, y_win_end, 0);
                count = count == 1 ? x_win_end - x_win_start + 1 : 0;
            } else if(y == y_win_start) return -1;
            break;
        case 1:
            if(x == x_win_end){
                count = count_line(grid, x, y, x_win_start, x_win_end, y_win_start, y_win_end, 1);
                count = count == 1 ? y_win_end - y_win_start + 1 : 0;
            } else if(x == x_win_start) return -1;
            break;
        case 2:
            if(y == y_win_start){
                count = count_line(grid, x, y, x_win_start, x_win_end, y_win_start, y_win_end, 0);
                count = count == 1 ? x_win_end - x_win_start + 1 : 0;
            } else if(y == y_win_end) return -1;
            break;
        case 3:
            if(x == x_win_start){
                count = count_line(grid, x, y, x_win_start, x_win_end, y_win_start, y_win_end, 1);
                count = count == 1 ? y_win_end - y_win_start + 1 : 0;
            } else if(x == x_win_end) return -1;
            break;
    }
    return count;
}

//dir is direction 0 -> x direction, 1 -> y direction
int count_line(int* grid, int x, int y, int x_win_start, int x_win_end, int y_win_start, int y_win_end, int dir){
    int count = 0;
    
    switch (dir)
    {
    case 0:
        for(int i = x_win_start; i <= x_win_end; i++){
            count += grid[i + y * ROWLEN];
        }
        break;
    case 1:
        for(int i = y_win_start; i <= y_win_end; i++){
            count += grid[x + i * ROWLEN];
        }
        break;
    }
    return count;
}

bool grid_check(int* grid){
    bool check = true;
    bool flag = false;

    for(int i = 0; i < ROWLEN * ROWLEN; i++) {
        if(grid[i] == 1){
            flag = false;
            if(i / ROWLEN != 0 && grid[i - ROWLEN] == 1)flag = true;
            else if(i % ROWLEN != 0 && grid[i - 1] == 1)flag = true;
            else if(i / ROWLEN != ROWLEN - 1 && grid[i + ROWLEN] == 1) flag = true;
            else if(i % ROWLEN != ROWLEN - 1 && grid[i + 1] == 1) flag = true;

            if(flag == false) check = false;
        } 
    }

    return check;
}