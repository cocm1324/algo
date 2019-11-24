#include <iostream>
#include <cmath>

using namespace std;

int* max_pow(int);
int dismentle(int);

int main() {
    int p = 0;
    int calc_count = 1;
    int* initial = NULL;

    cin >> p;

    initial = max_pow(p);
    
    //cout << initial[0] << initial[1] << initial[2] << endl;
    calc_count += initial[0];
    calc_count += dismentle(initial[2]);

    delete[] initial;
    initial = NULL;

    cout << calc_count << endl;

    return 0;
}

int* max_pow(int number) {
    int i = 1;
    int* ret = new int[3];
    
    if(number == 1) {
        ret[0] = 0;
        ret[1] = 1;
        ret[2] = 0;
        return ret;
    } 
    else {
        while (true) {
            if(number - pow(2, i) < 0) break;
            i++;
        } 
        
        if(abs(pow(2, i) - number) < abs(pow(2, i - 1) - number)){
            ret[0] = i;
            ret[1] = pow(2, i);
            ret[2] = abs(number - ret[1]);    
        }
        else {
            ret[0] = i - 1;
            ret[1] = pow(2, i - 1);
            ret[2] = number - ret[1];
        }
        
        return ret;
    }
}

int dismentle(int leftover) {
    int count = 0;
    int temp = leftover;
    int* iteration = NULL;

    if(temp == 0) {
        return 0;
    }
    else if(temp == 1){
        return 0;
    }
    else {
        while(temp != 0 && temp != 1){
            iteration = max_pow(temp);
            temp = iteration[2];
            //cout << temp << endl;
            count++;
        }
        return count;
    }
}