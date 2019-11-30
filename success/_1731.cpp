#include <iostream>
#include <cstring>
#include <list>

using namespace std;

int func(list<int>);

int main(){
    int N = 0;
    int input = 0;
    list<int> input_list;
    int ouput = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> input;
        input_list.push_back(input);
    }

    ouput = func(input_list);

    cout << ouput << endl;

    return 0;
}

int func(list<int> input_list){
    int first, second, thrid;
    
    first = input_list.front();
    input_list.pop_front();
    
    second = input_list.front();
    input_list.pop_front();

    thrid = input_list.front();
    
    if(second - first == thrid - second){
        return input_list.back() + (second - first);
    }
    else{
        return input_list.back() * (second / first);
    }
}