#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string plain, key;
    string cipher = "";
    int block, len;
    int temp1, temp2, temp3;

    getline(cin, plain);
    getline(cin, key);

    block = key.size();
    len = plain.size();

    for(int i = 0; i < len; i++){
        if(plain.at(i) == ' '){
            cipher += ' ';
            continue;
        }
        
        temp1 = plain.at(i) - '`';
        temp2 = key.at(i%block) - '`';
        temp3 = (temp1 - temp2) % 26;
        if(temp3 <= 0) temp3 += 26;

        //cout << "1: " << temp1 << " 2: " << temp2 << " 3: " << temp3 << endl;

        cipher += '`' + temp3;
    }

    cout << cipher << endl;

    return 0;
}