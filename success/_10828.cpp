#include <iostream>
using namespace std;

class Stack{
private:
  int* record;
  int size;
  int maxSize;

public:
  Stack(int stackSize){
    this->maxSize = stackSize;
    this->size = 0;
    record = new int[stackSize + 1];
    //cout << "stack size " << stackSize +1 << "has initialized!" << endl;
  }
  ~Stack(){
    delete[] this->record;
  }

  void push(int input){
    this->size++;
    record[size] = input;
    //cout << "pushing " << input << "into stack" << endl;
  }

  int pop(){
    int retVal = -1;
    if(isEmpty() != 1){
      retVal = record[size];
      this->size--;
    }
    //cout << "element " << retVal << "has popped" << endl;
    return retVal;
  }

  int getSize(){
    //cout << "checking size " << endl;
    return this->size;
  }

  int isEmpty(){
    if(size == 0){
      return 1;
    }
    else{
      return 0;
    }
  }

  int peek(){
    int retVal = -1;
    if(isEmpty() != 1) {
      retVal = record[size];
    }
    return retVal;
  }
};

int main(){
  int temp = 0;
  string strBuffer = "";
  int iteration = 0;

  cin >> temp;
  Stack* stack = new Stack(temp);
  iteration = temp;

  for(int i = 0; i < iteration; i++){
    //cout << "iteration " << i + 1 << endl;
    cin >> strBuffer;
    if (strBuffer.compare("push") == 0) {
      cin >> temp;
      stack->push(temp);
    }
    else if(strBuffer.compare("pop") == 0){
      cout << stack->pop() << endl;
    }
    else if(strBuffer.compare("size") == 0){
      cout << stack->getSize() << endl;
    }
    else if(strBuffer.compare("top") == 0){
      cout << stack->peek() << endl;
    }
    else if(strBuffer.compare("empty") == 0){
      cout << stack->isEmpty() << endl;
    }
  }

  delete (stack);

  return 0;
}
