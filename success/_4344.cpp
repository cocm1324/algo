#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main () {
    int iteration = 0;
    int student_count = 0;
    int sum = 0;
    float percentage = 0;
    int score = 0;
    int over = 0;
    queue<int> q;

    cin >> iteration;

    for(int i = 0; i < iteration; i++) {
        cin >> student_count;
        sum = 0;
        over = 0;
        
        for(int j = 0; j < student_count; j++) {
            cin >> score;
            q.push(score);
            sum += score;
        }

        while(!q.empty()) {
            score = q.front();
            over += (float)sum / (float)student_count < score ? 1 : 0;
            q.pop();
        }

        percentage = ((float)over / (float)student_count) * 100;

        printf("%2.3f%%\n", percentage);
    }


    return 0;
}