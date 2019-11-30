#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int, int, int, int);

int main(){
    int x, y, w, h;
    int output = 0;

    cin >> x >> y >> w >> h;

    output = func(x, y, w, h);

    cout << output << endl;

    return 0;
}

int func(int x, int y, int w, int h){
    vector<int> range;

    range.push_back(x);
    range.push_back(y);
    range.push_back(w - x);
    range.push_back(h - y);

    sort(range.begin(), range.end());
    
    return range.front();
}