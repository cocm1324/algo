#include <stdio.h>
#include <iostream>

using namespace std;

int lastComputerCalc(int a, int b);

int main(){
  int testCase = 0;
  int a, b;
  int lastComputer = 0;

  scanf("%d", &testCase);
  for(int i = 0; i < testCase; i++){
    scanf("%d %d", &a, &b);
    lastComputer = lastComputerCalc(a, b);

    printf("%d\n", lastComputer);
  }

  return 0;
}

int lastComputerCalc(int a, int b){
  int ret = 0;
  int firstDigit = a % 10;

  switch (firstDigit) {
    case 0: ret = 10; break;
    case 1: ret = 1; break;

    case 2:
    if(b % 4 == 1){
      ret = 2;
    }
    else if(b % 4 == 2){
      ret = 4;
    }
    else if(b % 4 == 3){
      ret = 8;
    }
    else{
      ret = 6;
    }
    break;

    case 3:
    if(b % 4 == 1){
      ret = 3;
    }
    else if(b % 4 == 2){
      ret = 9;
    }
    else if(b % 4 == 3){
      ret = 7;
    }
    else{
      ret = 1;
    }
    break;

    case 4: b % 2 == 1 ? ret = 4 : ret = 6; break;
    case 5: ret = 5; break;
    case 6: ret = 6; break;

    case 7:
    if(b % 4 == 1){
      ret = 7;
    }
    else if(b % 4 == 2){
      ret = 9;
    }
    else if(b % 4 == 3){
      ret = 3;
    }
    else{
      ret = 1;
    }
    break;

    case 8:
    if(b % 4 == 1){
      ret = 8;
    }
    else if(b % 4 == 2){
      ret = 4;
    }
    else if(b % 4 == 3){
      ret = 2;
    }
    else{
      ret = 6;
    }
    break;

    case 9: b % 2 == 1 ? ret = 9 : ret = 1; break;
  }

  return ret;
}
