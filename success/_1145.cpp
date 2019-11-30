#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int, int, int, int, int);
int lcm(int, int);
int gcd(int, int);

int main(){
    int a, b, c, d, e;
    int output = 0;

    cin >> a >> b >> c >> d >> e;

    output = func(a, b, c, d, e);

    cout << output << endl;

    return 0;
}

int func(int a, int b, int c, int d, int e){
    vector<int> multiplier;
    
    multiplier.push_back(lcm(lcm(a,b),c));
    multiplier.push_back(lcm(lcm(a,b),d));
    multiplier.push_back(lcm(lcm(a,b),e));
    multiplier.push_back(lcm(lcm(a,c),d));
    multiplier.push_back(lcm(lcm(a,c),e));
    multiplier.push_back(lcm(lcm(a,d),e));
    multiplier.push_back(lcm(lcm(b,c),d));
    multiplier.push_back(lcm(lcm(b,c),e));
    multiplier.push_back(lcm(lcm(b,d),e));
    multiplier.push_back(lcm(lcm(c,d),e));
    
    sort(multiplier.begin(), multiplier.end());

    return multiplier.front();
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int gcd(int a, int b){
    int num = 0;
    int divisor = a;
    int divided = 0;
    int mod = b;

    do{
        num = divisor;
        divisor = mod;
        divided = num / divisor;
        mod = num % divisor;
    }while(mod != 0);

    return divisor;
}