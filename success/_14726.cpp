#include <iostream>
#include <string>
#include <vector>

#define MAX_CARD_NUM 16

using namespace std;

char validate(string);

int main(){
  int input;
  vector<char> record;
  char temp = '0';
  string card_num;

  cin >> input;
  for(int i = 0; i < input; i++){
    //cout << i << "mark0" << endl;
    cin >> card_num;
    temp = validate(card_num);
    record.push_back(temp);
  }

  for(int i = 0; i < record.size(); i++){
    cout << record.at(i) << endl;
  }

  return 0;
}

char validate(string str){
  int check_sum = 0;
  int temp = 0;

  //cout << "mark1" << endl;

  if(str.size() < 16){
    return 'F';
  }

  //cout << "mark2" << endl;

  for(int i = 0; i < MAX_CARD_NUM; i++){
    if(i % 2 == 0){
      temp = 2 * (str.at(i) - '0');
      if(temp >= 10){
        temp = (temp % 10) + 1;
      }
    }
    else{
      temp = str.at(i) - '0';
    }
    check_sum += temp;
  }

  //cout << "mark3" << endl;

  if(check_sum % 10 == 0){
    return 'T';
  }
  else{
    return 'F';
  }
}
