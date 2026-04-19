/*
Anshu Lakshkar
0801CS241020
Assignment number -  6 (Queue)
Problem number - 2
Date of submission - 13th Feb 2026
*/
#include <stdio.h>

#define MAX 100000

int Q25[MAX];
int F25 = 0, R25 = -1, SZ25 = 0;

// ENQUEUE
void ENQ25(int x) {
    R25 = (R25 + 1) % MAX;
    Q25[R25] = x;
    SZ25++;
}

// DEQUEUE
int DEQ25() {
    int val = Q25[F25];
    F25 = (F25 + 1) % MAX;
    SZ25--;
    return val;
}

int main() {
    int N25 = 7;   
    int K25 = 3;   
    for (int I25 = 1; I25 <= N25; I25++)
        ENQ25(I25);
    while (SZ25 > 1) {
        for (int C25 = 1; C25 < K25; C25++) {
            int X25 = DEQ25();
            ENQ25(X25);
        }
        int REM25 = DEQ25();
        printf("Eliminated: %d\n", REM25);
    }

    printf("Safe Position = %d\n", DEQ25());
    return 0;
}
