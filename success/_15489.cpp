#include <stdio.h>
#include <iostream>

#define MAX_SIZE 512

using namespace std;

class Pascal{
protected:
  int* record;

public:
  Pascal();
  ~Pascal();
  int getRecord(int);
  void setRecord(int, int);
  int pascalCalc(int, int, int);
  int pascalItemCalc(int, int);
  int indexFinder(int, int);
};

int main(){
  int r, c, w;
  int sum = 0;
  Pascal* ps = new Pascal();

  scanf("%d %d %d",&r, &c, &w);
  sum = ps->pascalCalc(r,c,w);

  printf("%d\n", sum);

  return 0;
}

Pascal::Pascal(){
  this->record = new int[MAX_SIZE];
  for(int i = 0; i < MAX_SIZE; i++){
    this->record[i] = -1;
  }
}

Pascal::~Pascal(){
  delete[] this->record;
  this->record = NULL;
}

int Pascal::getRecord(int index){
  return this->record[index];
}

void Pascal::setRecord(int item, int index){
  this->record[index] = item;
}

int Pascal::pascalCalc(int r, int c, int w){
  int ret = 0;
  int temp = 0;

  for(int i = 0; i < w; i++){
    for(int j = i; j < w; j++){
      temp = pascalItemCalc(r+j, c+i);
      //printf("%d\n", temp);
      ret += temp;
    }
  }

  return ret;
}

int Pascal::pascalItemCalc(int r, int c){
  int index = indexFinder(r,c);
  int temp = getRecord(index);

  if(temp != -1){
    return temp;
  }
  else{
    if(r == 1){
      temp = 1;
    }
    else{
      if(c == 1){
        temp = 1;
      }
      else if(c == r){
        temp = 1;
      }
      else{
        temp = pascalItemCalc(r - 1, c - 1) + pascalItemCalc(r - 1, c);
      }
    }

    setRecord(temp, index);
    return temp;
  }
}

int Pascal::indexFinder(int r, int c){
  return (c - 1) + r * (r - 1) / 2;
}
