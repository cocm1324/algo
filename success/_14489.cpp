#include <iostream>
using namespace std;

int main(){
      int a, b, chicken;

      cin >> a >> b;
      cin >> chicken;

      if(a + b >= chicken * 2){
            cout << a + b - chicken * 2 << endl;
      }
      else{
            cout << a + b << endl;
      }

      return 18;
}
