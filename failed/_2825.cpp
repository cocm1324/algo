#include <iostream>
#include <cmath>

using namespace std;

void desolve(int*, unsigned long long int);

int main() {
    int count = 0;
    unsigned long long int number = 0;
    int record[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int friend_count = 0;

    cin >> count;

    for(int i = 0; i < count; i++) {
        cin >> number;
        desolve(record, number);
    }

    for(int i = 0; i < 10; i++) {
        if(record[i] > 0) friend_count += record[i] - 1;
    }

    cout << friend_count << endl;

    return 0;
}

void desolve(int* digit_array, unsigned long long int num) {
    bool digit[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int each_digit = 0;

    if(num == 0) {
        digit_array[0] += 1;
        return;
    }

    for(unsigned long long int i = 1; i <= 1000000000000000000; i *= 10) {
        if(num >= i) {
            each_digit = (num / i) % 10;
        } 
        else {
            break;
        }
        digit[each_digit] = true;
    }

    for(int i = 0; i < 10; i++){
        if(digit[i]) digit_array[i]++;
    }

    return;
}