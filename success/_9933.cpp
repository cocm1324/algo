#include <iostream>
#include <string>

#define RECORD_MAX_SIZE 100

using namespace std;

int finder(string*, int);
int strComp(string, string);
char charAtCenter(string);

int main(){
      int input_num = 0;
      int target_index = 0;
      string* str = new string[RECORD_MAX_SIZE];
      cin >> input_num;

      for(int i = 0; i < input_num; i++){
            cin >> str[i];
      }

      if(input_num == 1){
            cout << str[0].length() << " " << charAtCenter(str[0]) << endl;

            delete[] str;
            str = NULL;

            return 0;
      }

      target_index = finder(str, input_num);

      if(target_index == -1){
            cout << "error!" << endl;
      }
      else{
            cout << str[target_index].length() << " " << charAtCenter(str[target_index]) << endl;
      }

      delete[] str;
      str = NULL;

      return 0;
}

int finder(string* str, int size){
      for(int i = 0; i < size - 1; i++){
            for(int j = i; j < size; j++){
                  if(strComp(str[i], str[j])){
                        return i;
                  }
            }
      }
      return -1;
}

int strComp(string str1, string str2){
      int base_length = str1.length();

      if(base_length != str2.length()){
            return 0;
      }
      else{
            for(int i = 0; i < base_length; i++){
                  if(str1.at(i) != str2.at(base_length - 1 - i)){
                        return 0;
                  }
            }
            return 1;
      }
}

char charAtCenter(string str){
      int length = str.length();
      length = length / 2;

      return str.at(length);
}
