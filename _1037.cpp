#include <iostream>
#include <vector>
#include <algorithm>

#define CAPA 1000000

using namespace std;

int main(){
    vector<int> temp, temp1;
    vector<int> prime;
    int capa = CAPA;
    int n;
    int temp_int;
    long int temp_long_int = 1;
    
    for(int i = 0; i <= capa; i++){
        temp.push_back(i);
    }

    for (int i = 2; i <= capa; i++) { 
        if (temp[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
            continue;
        for (int j = i + i; j <= capa; j += i) { // i를 제외한 i의 배수들은 0으로 체크
            temp[j] = 0;
        }
    }

    for (int i = 2; i <= capa; i++) {
        if (temp[i] != 0)prime.push_back(temp[i]);
    }
    temp.clear();

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp_int;
        temp.push_back(temp_int);
        temp_long_int *= temp_int;
    }

    for(int i = 0; i < prime.size(); i++){
        if(temp_long_int % prime[i] == 0)temp1.push_back(prime[i]);
    }

    sort(temp.begin(), temp.end());

    cout << temp.back() * temp1.front() << endl; 

    return 0;
}