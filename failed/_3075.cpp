#include <iostream>
#include <queue>
#include <cmath>

#define MAX_VAL 101

using namespace std;

void meeting();
void calc_dist(int*, int*, int, int);

int main() {
    int iteration = 0;

    cin >> iteration;

    for(int i = 0; i < iteration; i++) {
        meeting();
    }

    return 0;
}

void meeting() {
    int people = 0;
    int galaxy = 0;
    int route = 0;
    int temp0 = 0;
    int temp1 = 0;
    int temp2 = 0;
    queue<int> pos;
    int* grid = NULL;
    int* dist = NULL;

    cin >> people >> galaxy >> route;

    grid = new int[galaxy * galaxy];
    dist = new int[galaxy];

    for(int i = 0; i < galaxy*galaxy; i++) {
        grid[i] = MAX_VAL;
    }

    for(int i = 0; i < galaxy; i++) {
        dist[i] = 0;
    }

    for(int i = 0; i < people; i++) {
        cin >> temp0;
        pos.push(temp0);
    }

    for(int i = 0; i < route; i++) {
        cin >> temp0 >> temp1 >> temp2;
        grid[(temp0 - 1) * galaxy + (temp1 - 1)] = temp2;
        grid[(temp1 - 1) * galaxy + (temp0 - 1)] = temp2;
    }
    
    // //print grid
    // for(int i = 0; i < galaxy*galaxy; i++) {
    //     cout << grid[i] << " ";
    //     if(i % galaxy == galaxy - 1) cout << endl;
    // }

    while(!pos.empty()){
        temp0 = pos.front();
        pos.pop();
        //cout << temp0 << endl;
        calc_dist(grid, dist, galaxy, temp0);
    }

    //from dist, cout least item temp0 is index, temp1 is value;
    temp1 = MAX_VAL;
    for(int i = 0; i < galaxy; i++) {
        // cout << dist[i] << " ";
        if(temp1 > dist[i]) {
            temp1 = dist[i];
            temp0 = i;
        }
    }
    // cout << endl;
    cout << temp0 + 1 << " " << temp1 <<  endl;


    delete[] grid;
    grid = NULL;
    delete[] dist;
    dist = NULL;
}

void calc_dist(int* grid, int* dist, int size, int starting){
    bool* visited = new bool[size];
    int* distance = new int[size];
    int current_pos = 0;
    int current_val = 0;

    for(int i = 0; i < size; i++) {
        visited[i] = false;
        distance[i] = MAX_VAL;
        if(i == starting - 1) distance[i] = 0;
    }


    for(int index = 0; index < size; index++) {
        current_val = MAX_VAL;
        for(int i = 0; i < size; i++) {
            if(!visited[i]) {
                if(current_val > distance[i]){
                    current_val = distance[i];
                    current_pos = i;
                }
            }
        }
        // cout << current_pos << ": " << current_val << endl;
        visited[current_pos] = true;
        for(int i = 0; i < size; i++) {
            if(grid[current_pos * size + i] + current_val < distance[i]){
                distance[i] = grid[current_pos * size + i] + current_val;
            }
        }

        // for(int i = 0; i < size; i++) {
        //     cout << distance[i] << " ";
        // }
        // cout << endl;
    }
    
    for(int i = 0; i < size; i++) {
        // cout << distance[i] << " ";
        dist[i] += pow(distance[i], 2);
    }
    // for(int i = 0; i < size; i++) {
    //     cout << distance[i] << " ";
    // }
    // cout << endl;

    delete[] visited;
    visited = NULL;
    delete[] distance;
    distance = NULL;

    return;
}