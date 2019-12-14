#include <iostream>

#define STUDENT_COUNT 30
#define NOT_SUBMITTED 2

using namespace std;

int main() {
    int temp = 0;
    int submitted_student_count = STUDENT_COUNT - NOT_SUBMITTED;
    
    //cout << submitted_student_count << endl;
    int submition_list[STUDENT_COUNT] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    for(int i = 0; i < submitted_student_count; i++) {
        cin >> temp;
        submition_list[temp - 1] = 1;
    }

    for(int i = 0; i < STUDENT_COUNT; i++) {
        if(submition_list[i] == 0) cout << i + 1 << endl;
    }
    
    return 0;
}