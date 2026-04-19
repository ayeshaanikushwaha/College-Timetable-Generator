/*
Anshu Lakshkar
0801CS241020
Assignment number - 11(Sorting)
Problem number - 4
Date of submission - 22nd March 2026
*/
#include <stdio.h>

void HEAPIFY25(int ARR25[], int N25, int I25) {

    int LARG25 = I25;
    int L25 = 2 * I25 + 1;
    int R25 = 2 * I25 + 2;

    if (L25 < N25 && ARR25[L25] > ARR25[LARG25])
        LARG25 = L25;

    if (R25 < N25 && ARR25[R25] > ARR25[LARG25])
        LARG25 = R25;

    if (LARG25 != I25) {

        int T25 = ARR25[I25];
        ARR25[I25] = ARR25[LARG25];
        ARR25[LARG25] = T25;

        HEAPIFY25(ARR25, N25, LARG25);
    }
}

void HSORT25(int ARR25[], int N25){

    for (int I25 = N25 / 2 - 1; I25 >= 0; I25--)
        HEAPIFY25(ARR25, N25, I25);

    for (int I25 = N25 - 1; I25 >= 0; I25--){

        int T25 = ARR25[0];
        ARR25[0] = ARR25[I25];
        ARR25[I25] = T25;

        HEAPIFY25(ARR25, I25, 0);
    }
}
int main(){

    int ARR25[] = {4, 10, 3, 5, 1};
    int N25 = 5;

    HSORT25(ARR25, N25);

    printf("Sorted Array: ");

    for (int I25 = 0; I25 < N25; I25++)
        printf("%d ", ARR25[I25]);

    return 0;
}