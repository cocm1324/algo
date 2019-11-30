#include <iostream>
#include <cmath>

using namespace std;

void print_capital(int *, int);
void trick(int*, int);

int main () {
    int bank_count = 0;
    int temp = 0;
    int* capital = NULL;

    cin >> bank_count;

    capital = new int[bank_count];    

    for(int i = 0; i < bank_count; i++) {
        cin >> temp;
        capital[i] = temp;
    }

    cout << "initial" << endl;
    print_capital(capital, bank_count);


    for(int i = 0; i < 9; i++) {
        trick(capital, bank_count);

        cout << "iteration " << i << endl;
        print_capital(capital, bank_count);
    }

    return 0;
}

void print_capital(int* record, int size) {
    for(int i = 0; i < size; i++) {
        cout << i << ": " << record[i] << endl;
    }
}

void trick(int* record, int size) {
    int number = 0;
    int min_index = 0;
    
    //get index
    for(int i = 0; i < size; i++) {
        if(record[i] < number) {
            number = record[i];
            min_index = i;
        }
    }

    //magic on that index
    number = abs(record[min_index]);
    record[min_index] = number;
    if(min_index == 0) record[size - 1] -= number;
    else record[min_index - 1] -= number;
    if(min_index == size - 1) record[0] -= number;
    else record[min_index + 1] -= number;
}