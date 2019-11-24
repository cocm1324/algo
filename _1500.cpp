#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    int s, k, temp_int;
    double temp_double;
    queue<double> q;

    cin >> s >> k;

    if(s >= (s - k) * 2) {
        temp_double = pow(2, k);
        cout << temp_double << endl;
    }
    else {
        temp_int = s / k;
        for(int i = 0; i < k; i++) {
            q.push(temp_int);
            //cout << "mark" << endl;
        }
        temp_int = s % k;
        temp_double = 1;
        while(!q.empty()){
            if(temp_int > 0){
                temp_double *= q.front() + 1;
                q.pop();
                temp_int--;
            }
            else{
                temp_double *= q.front();
                q.pop();
            }
            //cout << temp_double << endl;    
        }
        cout << temp_double << endl;
    }

    return 0;
}