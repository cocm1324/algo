#include <iostream>
#include <cstring>

#define MAX_STRING_SIZE 50

using namespace std;

int main(){
    string a, b;
    int a_length, b_length;
    int min, counter;

    cin >> a >> b;

    a_length = a.size();
    b_length = b.size();

    min = MAX_STRING_SIZE;

    for(int i = 0; i < b_length - a_length + 1; i++){
        counter = 0;
        for(int j = 0; j < a_length; j++){
            if(a.at(j) != b.at(j+i))counter++;
        }
        //cout << i << ": " << counter << endl;
        if(min > counter)min = counter;
    }

    cout << min << endl;

    return 0;
}