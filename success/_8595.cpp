#include <iostream>
#include <inttypes.h>
#include <string>
#include <cmath>

using namespace std;

int64_t hidden_num_sum(int, string);
int is_num(char);

int main(){
      int str_length = 0;
      int64_t sum = 0;
      string str;


      cin >> str_length;
      cin >> str;

      sum = hidden_num_sum(str_length, str);

      cout << sum << endl;

      return 0;
}

int64_t hidden_num_sum(int length, string str){
      int64_t sum = 0;
      int flag = 0;
      int temp = 0;

      for(int i = length - 1; i >= 0; i--){
            //cout << i << " : " << str.at(i) << endl;
            if(is_num(str.at(i))){
                  flag++;
                  temp = (int)(str.at(i) - '0');
                  temp = temp * pow(10, flag - 1);
                  sum += temp;
            }
            else{
                  flag = 0;
            }
      }

      return sum;
}

int is_num(char ch){
      if(ch >= 48 && ch <= 57){
            return 1;
      }
      else{
            return 0;
      }
}
