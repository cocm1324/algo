#include <iostream>
#include <deque>

using namespace std;

void rightShift(deque <int>&);
int shiftCalc(deque <int>&, int);

int main(){
      int n, m, temp;
      int count = 0;
      deque <int> deq;

      cin >> n >> m;
      for(int i = 0; i < n; i++){
            deq.push_back(i+1);
      }
      for(int i = 0; i < m; i++){
            cin >> temp;

            count += shiftCalc(deq, temp);
            //printf("%d\n", count);
      }

      printf("%d\n", count);
}

void rightShift(deque <int>& deq){
      int temp = 0;

      if(!deq.empty()){
            temp = deq.front();
            deq.pop_front();
            deq.push_back(temp);
      }
}

int shiftCalc(deque <int>& deq, int temp){
      int base = 0;
      int count = 0;

      while(deq.front() != temp){
            count++;
            rightShift(deq);
      }

      if(count > (deq.size() / 2)){
            count = deq.size() - count;
      }

      deq.pop_front();
      return count;
}
