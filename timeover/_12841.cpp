#include <iostream>
#include <climits>

#define CROSS_COUNT_MAX 1000000

using namespace std;

int main() {
    int cross_count = 0;
    unsigned long* cross = NULL;
    unsigned long* distance = NULL;
    unsigned long temp = 0;

    int where = CROSS_COUNT_MAX;
    unsigned long int dist = ULONG_MAX;

    cin >> cross_count;

    cross = new unsigned long[cross_count];
    distance = new unsigned long[cross_count];

    for(int i = 0; i < cross_count; i++) {
        distance[i] = 0;
    }

    for(int i = 0; i < cross_count; i++) {
        cin >> temp;
        cross[i] = temp;
        distance[i] += temp;
    }

    for(int i = 0; i < cross_count - 1; i++) {
        cin >> temp;
        distance[i + 1] += distance[i] - cross[i] + temp;
    }

    for(int i = 0; i < cross_count - 1; i++) {
        cin >> temp;
        for(int j = 0; j <= i; j++) {
            distance[j] += temp;
        }
    }

    for(int i = 0; i < cross_count; i++) {
        if(distance[i] < dist) {
            dist = distance[i];
            where = i + 1;
        }
    }

    cout << where << " " <<dist << endl;


    delete[] cross;
    delete[] distance;

    cross = NULL;
    distance = NULL;

    return 0; 
}