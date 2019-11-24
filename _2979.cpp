#include <iostream>

#define MAX 100

using namespace std;

int main() {
    int charge = 0;
    int a, b, c;
    int start, end;
    int* timetable = new int[MAX];
    for(int i = 0; i < MAX; i++) {
        timetable[i] = 0;
    }

    cin >> a >> b >> c;
    
    cin >> start >> end;
    for(int i = start; i < end; i++) {
        timetable[i]++;
    }
    cin >> start >> end;
    for(int i = start; i < end; i++) {
        timetable[i]++;
    }
    cin >> start >> end;
    for(int i = start; i < end; i++) {
        timetable[i]++;
    }

    for(int i = 0; i < MAX; i++) {
        // cout << timetable[i];
        
        timetable[i] == 3 ? charge += c * 3 : timetable[i] == 2 ? charge += b * 2 : timetable[i] == 1 ? charge += a : NULL;
    }

    cout << charge << endl;

    return 0;
}