#include <iostream>
#include <cstring>

using namespace std;

int func(int, string);

int main(){
    int K = 0;
    int h = 0;
    string action;
    int left = 0;


    cin >> K;

    for(int i = 0; i< K; i++){
        cin >> h;
        cin >> action;

        left = func(h, action);

        cout << "Data Set " << i + 1 << ": \n" << left << endl;
        if(i != K-1){
            cout << endl;
        }
    }

    return 0;
}

int func(int h, string action){
    int left = h;

    for(int i = 0; i < action.length(); i++){
        if(action.at(i) == 'c'){
            left += 1;
        }
        else if(action.at(i) == 'b'){
            left -= 1;
        }
    }

    return left;
}
