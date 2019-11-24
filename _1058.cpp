#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int popular(int, int*);
int friend_calc(int, int, int*);
int int_or(int, int);

int main () {
    int num;
    int* grid;
    string buf;
    int ret = 0;

    cin >> num;
    
    grid = new int[num * num];
    
    for(int i = 0; i < num; i++) {
        cin >> buf;
        for(int j = 0; j < num; j++) {
            if(buf.at(j)=='Y') grid[num * i + j] = 1;
            else grid[num * i + j] = 0;
        }
    }

    ret = popular(num, grid);
    delete[] grid;

    cout << ret << endl;

    return 0;
}

int popular(int num, int* grid) {
    int top = 0;
    int temp = 0;

    for(int i = 0; i < num; i++) {
        temp = friend_calc(i, num, grid);
        if(top < temp) top = temp;    
    }
    
    return top;
}

int friend_calc(int index, int num, int* grid) {
    int ret = 0;
    queue<int> q;
    int* temp = new int[num];
    int iter;

    for(int i = 0; i < num; i++) {
        temp[i] = grid[index*num + i];
        if(grid[index*num + i] == 1) q.push(i);
    }

    while(q.size()) {
        iter = q.front();
        for(int i = 0; i < num; i++){
            temp[i] = int_or(temp[i], grid[iter*num + i]);
        }
        q.pop();
    }
    
    temp[index] = 0;

    for(int i = 0; i < num; i++){
        ret += temp[i];
    }

    delete[] temp;

    return ret;
}

int int_or(int a, int b){
    if(a == 1 || b == 1) return 1;
    else return 0;
}