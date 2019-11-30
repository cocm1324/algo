#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, k, l;
    int point = 1;
    int start = 1;
    cin >> n >> k >> l;

    while(true){
        if(n > pow(2, point))point++;
        else break;
    }

    if(n < k || n < l){
        cout << -1 << endl;
        return 0;
    }
    
    while(point > 0){
        if(point == 0){
            
        }

        if(start <= k && k <= pow(2, point - 1) + start - 1){
            if(pow(2, point - 1) + start <= l && l <= start - 1 + pow(2, point)){
                break;
            }
            else{
                point--;
                continue;
            }
        }
        else{
            if(start <= l && l <= pow(2, point - 1) + start - 1){
                break;
            }
            else{
                start += pow(2, point - 1);
                point--;
                continue;
            }
        }
    }

    cout << point << endl;

    return 0;
}