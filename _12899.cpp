#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void min_heap_push(vector<int>&, int);
int min_heap_pop(vector<int>&);

int heap_root(int);
int heap_right_leaf(int);
int heap_left_leaf(int);

int main() {
    int n = 0;
    int type = 0;
    int value = 0;
    vector<int> v;
    stack<int> s;
    v.push_back(-1);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> type >> value;

        if(type == 1) {
            min_heap_push(v, value);
        }
        else {
            for(int j = 0; j < value; j++) {
                s.push(min_heap_pop(v));   
            }
            cout << s.top() << endl;
            s.pop();
            while(!s.empty()){
                min_heap_push(v, s.top());
                s.pop();
            }
        }
    }

    return 0;
}

void min_heap_push(vector<int> &v, int value) { 
    int pos = 0;
    int temp = 0;

    v.push_back(value);


    pos = v.size() - 1;

    while(pos != 1) {
        if(v[pos] < v[heap_root(pos)]){
            temp = v[pos];
            v[pos] = v[heap_root(pos)];
            v[heap_root(pos)] = temp;
            pos = heap_root(pos);
        }
        else {
            break;
        }
    }
}

int min_heap_pop(vector<int> &v) {
    int value = v[1];
    int pos = 1;
    int temp = 0;
    vector<int>::iterator it = v.begin();

    v.erase(v.begin());
    v.erase(v.begin());
    v.insert(v.begin(), -1);

    while(v.size() > heap_left_leaf(pos) && v.size() > heap_right_leaf(pos)) {
        if(v[pos] > v[heap_left_leaf(pos)] && v[pos] < v[heap_right_leaf(pos)]){
            temp = v[pos];
            v[pos] = v[heap_left_leaf(pos)];
            v[heap_left_leaf(pos)] = temp;
            pos = heap_left_leaf(pos);
        }
        else if(v[pos] < v[heap_left_leaf(pos)] && v[pos] > v[heap_right_leaf(pos)]){
            temp = v[pos];
            v[pos] = v[heap_right_leaf(pos)];
            v[heap_right_leaf(pos)] = temp;
            pos = heap_right_leaf(pos);
        }
        else if(v[pos] > v[heap_left_leaf(pos)] && v[pos] > v[heap_right_leaf(pos)]){
            if(v[heap_left_leaf(pos)] < v[heap_right_leaf(pos)]){
                temp = v[pos];
                v[pos] = v[heap_left_leaf(pos)];
                v[heap_left_leaf(pos)] = temp;
                pos = heap_left_leaf(pos);
            }
            else {
                temp = v[pos];
                v[pos] = v[heap_right_leaf(pos)];
                v[heap_right_leaf(pos)] = temp;
                pos = heap_right_leaf(pos);
            }
        }
        else {
            break;
        }
    }

    return value;
}

int heap_root(int number) {
    return number / 2;
}

int heap_right_leaf(int number) {
    return number * 2 + 1;
}

int heap_left_leaf(int number) {
    return number * 2;
}