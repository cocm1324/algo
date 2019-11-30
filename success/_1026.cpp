#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int, vector<int>, vector<int>);

int main(){
    int N = 0;
    vector<int> A,B;
    int input = 0;
    int output = 0;

    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> input;
        A.push_back(input);
    }

    for(int i = 0; i < N; i++){
        cin >> input;
        B.push_back(input);
    }

    output = func(N, A, B);

    cout << output << endl;

    return 0;
}

int func(int N, vector<int> A, vector<int> B){
    int S = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i = 0; i < N; i++){
        S += A[i] * B[N - i - 1];
    }

    return S;
}