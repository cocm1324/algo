#include <iostream>
#include <queue>

using namespace std;

int main() {
    unsigned long long int count = 0;
    string single_case;
    string temp;
    int index = 0;
    queue<string> q;

    cin >> single_case;

    q.push(single_case);
    
    while(!q.empty()) {
        single_case = q.front();
        
        // search for last f
        for(int i = single_case.size() - 1; i >= 0; i--) {
            if(single_case.at(i) == 'f'){
                index = i;
                break;
            }
        }
        //cout << "mark" << endl;

        // if the last f is in first index, thats a single case so count it
        if(index == 0) {
            count += single_case.size() - 1;
        }
        else {
            temp = single_case.substr(0, index);
            for(int i = 0; i < single_case.size() - index - 1; i++) {
                temp = temp.append("e");
                //cout << temp << endl;
                q.push(temp);
            }
        }
        q.pop();
    }

    cout << count << endl;
}