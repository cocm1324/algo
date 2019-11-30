#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
  int temp = 0;
  int local = 0;
  int top = 0;
  int* record;
  int* stack;
  string printSt = "";
  cin >> temp;
  record = new int[temp];
  stack = new int[temp+1];

  vector<char> V;

  for(int i = 0; i < temp; i++){
    scanf("%d", &record[i]);
    stack[i] = i;
  }
  stack[temp] = temp;

  /*
  for(int i = 0; i < temp+1; i++){
    cout << stack[i];
  }
  cout << endl;
  */

  for(int i = 0; i < temp; i++){
    //cout << "iteration " << i << "\ttop : " << top << endl;
    //larger than top
    if(record[i] > top){
      //cout << "case : branch" << endl;
      //cout << "record - top : " << record[i] - top << endl;
      local = top;
      for(int j = 0; j < record[i] - local; j++){
        //cout << "stack[" << top + j + 1 << "] is " << stack[top + j + 1] << endl;
        if(stack[top + 1] != -1){
          //printSt.append("+\n");
          V.push_back('+');
          //cout << "push" << endl;
        }
        top++;
      }
      //cout <<"top after iter : "<< top << endl;
      //printSt.append("-\n");
      V.push_back('-');
      //cout << "pop" << endl;
      stack[top] = -1;
      while(stack[top] == -1){
        //cout << "backward jump" << endl;
        top--;
      }
    }
    //just equal to top
    else if(record[i] == top){
      //cout << "case : pop" << endl;
      //printSt.append("-\n");
      V.push_back('-');
      //cout << "pop" << endl;
      stack[top] = -1;
      while(stack[top] == -1){
        top--;
      }
    }
    else{
      //cout << "case : not" << endl;
      printf("NO\n");
      return 0;
    }
  }

  for (int i = 0; i < V.size(); i++) {
		printf("%c\n", V[i]);
	}
  //printf("%s", printSt.c_str());

  return 0;
}
