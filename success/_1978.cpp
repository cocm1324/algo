#include <iostream>
using namespace std;

int isPrime(int);

int main(){
      int n, temp;
      int count = 0;

      cin >> n;
      for(int i = 0; i < n; i++){
            cin >> temp;
            if(isPrime(temp))count++;
      }

      cout << count << endl;

      return 18;
}

int isPrime(int temp){
      if(temp == 1)return 0;

      for(int i = 2; i <= temp/2; i++){
            if(temp % i == 0)return 0;
      }

      return 1;
}
