#include <iostream>

using namespace std;

int main() {
    int h = 0;
    unsigned long long int a = 0;
    unsigned long long int b = 1;
    unsigned long long int temp = 0;

    cin >> h;

    for(int i = 1; i < h; i++) {
        temp = b * 2;
        b = b + a;
        a = temp;
    }

    temp = a + b;

    cout << temp << endl;

    return 0;
}