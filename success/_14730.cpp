#include <iostream>
using namespace std;

int main(){
      int input;
      int a, b;
      int sum = 0;

      cin >> input;
      for(int i = 0; i < input; i++){
            cin >> a >> b;
            sum += a*b;
      }

      cout << sum << endl;

      return 0;
}
