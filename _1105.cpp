#include <iostream>
#include <cmath>

using namespace std;

int radix(int);
int eight_count(int);

int main() {
    int l, r;

    cin >> l >> r;

    if(radix(l) != radix(r)) cout << 0 << endl;
    else if(l == r) cout << eight_count(l) << endl;
    else cout << eight_count(r / pow(10, radix(r - l))) << endl;
}

int radix(int num) {
    if(num <= 0) return 1;
    int i = 0;
    while(num >= 1) {
        num /= 10;
        i++;
    }
    return i;
}

int eight_count(int num) {
    if(num <= 0) return 0;
    int count = 0;
    while(num >= 1) {
        if(num % 10 == 8) count++;
        num /= 10;
    }
    return count;
}