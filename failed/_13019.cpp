#include <iostream>
#include <cstring>

using namespace std;

bool check_impossible(string, string);
int move_count(string, string);
bool find_substr(string, string);

int main() {
    string a, b;
    int movement = 0;

    cin >> a >> b;

    if(check_impossible(a, b)) {
        cout << -1 << endl;
        return 0;
    }

    movement = move_count(a, b);

    cout << movement << endl;

    return 0;
}

bool check_impossible(string a, string b) {
    int a_digest = 0;
    int b_digest = 0;
    
    if(a.length() != b.length()) return true;

    for(unsigned int i = 0; i < a.length(); i++) {
        a_digest += a.at(i);
        b_digest += b.at(i);
    }

    if(a_digest != b_digest) return true;

    return false;
}

int move_count(string a, string b) {
    unsigned int max_count = 0;
    
    for(unsigned int i = 0; i < b.length();  i++) {
        string temp_str = b.substr(b.length() - 1 - i, i + 1);
        
        if(find_substr(temp_str, a)) {
            if(max_count < i + 1) max_count = i + 1;
        }
    }
    
    return b.length() - max_count;
}

bool find_substr(string str, string target) {
    for(unsigned int i = 0; i <= target.length() - str.length(); i++) {
        int flag = 1;

        for(unsigned int j = 0; j < str.length(); j++) {
            if(str.at(j) != target.at(i + j)) {
                flag = 0;
                break;
            }
        }
        if(flag == 0) continue;

        return true;
        // temp = target.substr(i, str.length()).compare(str) == 0;
        // cout << target.substr(i, str.length()) << " : " << str << " : " << temp << endl;
    }

    return false;
}