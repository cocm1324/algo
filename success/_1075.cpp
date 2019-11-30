#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int lastDigitsCalc(int n, int f);

int main(){
  int n, f;
  int lastDigits = 0;
  string digits = "00";

  scanf("%d\n%d", &n, &f);
  lastDigits = lastDigitsCalc(n,f);

  if(lastDigits < 10){
    digits[1] = lastDigits + '0';
  }
  else{
    digits[0] = (lastDigits / 10) + '0';
    digits[1] = (lastDigits % 10) + '0';
  }

  cout << digits << endl;

  return 0;
}

int lastDigitsCalc( int n, int f){
  int temp = n % (f * 100);
  temp = temp - (temp % 100);

  while(true){
    if(temp % f == 0){
      break;
    }
    temp++;
  }

  return temp % 100;
}
