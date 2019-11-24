#include <iostream>

#define START 1000
#define END 9999

using namespace std;

int singi10(int);
int singi12(int);
int singi16(int);

int main () {
    for(int i = START; i <= END; i++) {
        if(singi10(i) == singi12(i) && singi10(i) == singi16(i)) cout << i << endl;
    }
}

int singi10(int singi10) {
    int _3 = singi10 / 1000;
    int _2 = (singi10 % 1000) / 100;
    int _1 = (singi10 % 100) / 10;
    int _0 = singi10 % 10;
    
    return _3 + _2 + _1 + _0;
}

int singi12(int singi10) {
    int _3 = singi10 / 1728;
    int _2 = (singi10 % 1728) / 144;
    int _1 = (singi10 % 144) / 12;
    int _0 = singi10 % 12;

    return _3 + _2 + _1 + _0;
}

int singi16(int singi10) {
    int _3 = singi10 / 4096;
    int _2 = (singi10 % 4096) / 256;
    int _1 = (singi10 % 256) / 16;
    int _0 = singi10 % 16;

    return _3 + _2 + _1 + _0;
}