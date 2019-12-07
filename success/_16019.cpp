#include <cstdio>

using namespace std;

int main () {
    int elapsetime[4] = {0, 0, 0, 0};

    scanf("%d %d %d %d", &elapsetime[0],&elapsetime[1],&elapsetime[2],&elapsetime[3]);

    printf("0 %d %d %d %d\n", elapsetime[0], elapsetime[0]+elapsetime[1], elapsetime[0]+elapsetime[1]+elapsetime[2], elapsetime[0]+elapsetime[1]+elapsetime[2]+elapsetime[3]);
    printf("%d 0 %d %d %d\n", elapsetime[0], elapsetime[1], elapsetime[1]+elapsetime[2], elapsetime[1]+elapsetime[2]+elapsetime[3]);
    printf("%d %d 0 %d %d\n", elapsetime[0]+elapsetime[1], elapsetime[1], elapsetime[2], elapsetime[2]+elapsetime[3]);
    printf("%d %d %d 0 %d\n", elapsetime[0]+elapsetime[1]+elapsetime[2], elapsetime[1]+elapsetime[2], elapsetime[2], elapsetime[3]);
    printf("%d %d %d %d 0\n", elapsetime[0]+elapsetime[1]+elapsetime[2]+elapsetime[3], elapsetime[1]+elapsetime[2]+elapsetime[3], elapsetime[2]+elapsetime[3], elapsetime[3]);

    return 0;
}