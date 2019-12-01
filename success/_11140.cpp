#include <iostream>
#include <cstring>

using namespace std;

int findout(string);

int main() {
    int test_case = 0;
    string word;

    cin >> test_case;

    for(int i = 0; i < test_case; i++) {
        cin >> word;
        cout << findout(word) << endl;
    }
}

/** 
 * first, find lol, do iteration
 * in the iteration, mark ll, lo, ol, l*l 
 * also mark if it has l, o 
*/
int findout(string word) {
    int size = word.size();
    bool need2 = false, need1 = false;

    for(int i = 0; i < size; i++){

        if(word.at(i) == 'l'){
            need2 = true;

            if(i + 2 == size) {
                if(word.at(i + 1) == 'l' || word.at(i + 1) == 'o'){
                    need1 = true;       
                }   
            }
            else if(i + 1 == size){
                continue;
            }
            else {
                if(word.at(i + 1) == 'l' || word.at(i + 1) == 'o' || word.at(i + 2) == 'l'){
                    need1 = true;
                    if(word.at(i + 1) == 'o' && word.at(i + 2) == 'l'){
                        return 0;
                    }          
                }   
            }
        }
        else if(word.at(i) == 'o') { 
            need2 = true;
            if(i + 1 == size){
                continue;
            }
            else {
                if(word.at(i + 1) == 'l') {
                    need1 = true;
                }
            }
        }
    }

    if(need1) {
        return 1;
    }
    else {
        if(need2) {
            return 2;
        }
        else {
            return 3;
        }
    }
}