#include <iostream>
using namespace std;

void insertionSort(int* record, int recordLength){
  int key = 0;
  int j = 0;

  for(int i = 1; i < recordLength; i++){
    //cout << "iteration " << i << endl;
    key = record[i];
    //cout << "key = " << key << endl;
    j = i - 1;
    while(j >= 0 && record[j] > key){
      //cout << "inner iteration count" << endl;
      record[j+1] = record[j];
      j--;
    }
    record[j+1] = key;
  }
}

int main(){
  int temp = 0;
  cin >> temp;
  int* record = new int[temp];

  for(int i = 0; i < temp; i++){
    cin >> record[i];
  }

  //sorting
  insertionSort(record, temp);

  for(int i = 0; i < temp; i++){
    cout << record[i] << endl;
  }

  return 0;
}
