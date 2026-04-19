/*
Anshu Lakshkar
0801CS241020
Assignment number - 11(Sorting)
Problem number - 5
Date of submission - 22nd March 2026
*/
#include <stdio.h>

void CSORT25(int ARR25[], int N25){

    int MAX25 = ARR25[0];

    for (int I25 = 1; I25 < N25; I25++)
        if (ARR25[I25] > MAX25)
            MAX25 = ARR25[I25];

    int CNT25[MAX25 + 1];

    for (int I25 = 0; I25 <= MAX25; I25++)
        CNT25[I25] = 0;

    for (int I25 = 0; I25 < N25; I25++)
        CNT25[ARR25[I25]]++;

    for (int I25 = 1; I25 <= MAX25; I25++)
        CNT25[I25] += CNT25[I25 - 1];

    int OUT25[N25];

    for (int I25 = N25 - 1; I25 >= 0; I25--) {
        OUT25[CNT25[ARR25[I25]] - 1] = ARR25[I25];
        CNT25[ARR25[I25]]--;
    }

    for (int I25 = 0; I25 < N25; I25++)
        ARR25[I25] = OUT25[I25];
}

int main(){

    int ARR25[] = {4, 2, 2, 8, 3, 3, 1};
    int N25 = 7;

    CSORT25(ARR25, N25);

    printf("Sorted Array: ");

    for (int I25 = 0; I25 < N25; I25++)
        printf("%d ", ARR25[I25]);

    return 0;
}