#include <iostream>
#include <cstring>

#define CHESS_ROW 8

using namespace std;

int func(string, int);

int main(){
    int output = 0;
    string row;

    for(int i = 0; i < CHESS_ROW; i++){
        cin >> row;

        output += func(row, i % 2);
    }

    cout << output << endl;

    return 0;
}

int func(string row, int input){
    int output = 0;
    
    for(int i = 0; i < CHESS_ROW; i++){
        if((i+input)%2 == 0 && row.at(i) == 'F')output++;
    }

    return output;
}