#include <iostream>

using namespace std;

int main(){
    int n, temp;

    cin >> n;
    temp = 0;
    
    if(n == 64){
        cout << 1 << endl;
        return 0;
    }

    if(n >= 32){
        temp++;
        n -= 32;
    }
    
    if(n >= 16){
        temp++;
        n -= 16;
    }

    if(n >= 8){
        temp++;
        n -= 8;
    }

    if(n >= 4){
        temp++;
        n -= 4;
    }

    if(n >= 2){
        temp++;
        n -= 2;
    }

    if(n == 1){
        temp++;
    }

    cout << temp << endl;

    return 0;
}