/*
Anshu Lakshkar
0801CS241020
Assignment number -  8 (Tree-II)
Problem number - 4
Date of submission - 1st March 2026
*/
#include <stdio.h>
#define MAX25 100

int HEAP25[MAX25];
int SZ25 = 0;

void SWAP25(int *A25, int *B25) {
    int T25 = *A25;
    *A25 = *B25;
    *B25 = T25;
}

void INS25(int VAL25) {

    HEAP25[SZ25] = VAL25;
    int I25 = SZ25;
    SZ25++;
    while (I25 > 0 &&HEAP25[(I25 - 1) / 2] < HEAP25[I25]) {

        SWAP25(&HEAP25[(I25 - 1) / 2],&HEAP25[I25]);
        I25 = (I25 - 1) / 2;
    }
}
void HEAPIFY25(int I25) {

    int LARG25 = I25;
    int L25 = 2 * I25 + 1;
    int R25 = 2 * I25 + 2;

    if (L25 < SZ25 && HEAP25[L25] > HEAP25[LARG25])
        LARG25 = L25;
    if (R25 < SZ25 && HEAP25[R25] > HEAP25[LARG25])
        LARG25 = R25;

    if (LARG25 != I25) {
        SWAP25(&HEAP25[I25], &HEAP25[LARG25]);
        HEAPIFY25(LARG25);
    }
}
int DELMAX25() {
    if (SZ25 <= 0)
        return -1;
    int ROOT25 = HEAP25[0];
    HEAP25[0] = HEAP25[SZ25 - 1];
    SZ25--;
    HEAPIFY25(0);

    return ROOT25;
}

void HEAPSORT25(int ARR25[], int N25) {
    SZ25 = 0;
    for (int I25 = 0; I25 < N25; I25++)
        INS25(ARR25[I25]);
    for (int I25 = N25 - 1; I25 >= 0; I25--)
        ARR25[I25] = DELMAX25();
}
void DISP25(int ARR25[], int N25) {
    for (int I25 = 0; I25 < N25; I25++)
        printf("%d ", ARR25[I25]);
    printf("\n");
}
int main() {
    INS25(50);
    INS25(30);
    INS25(20);
    INS25(40);

    printf("Deleted Max = %d\n", DELMAX25());
    int ARR25[] = {25, 10, 35, 5, 15};
    int N25 = 5;

    printf("Original Array: ");
    DISP25(ARR25, N25);

    HEAPSORT25(ARR25, N25);

    printf("Sorted Array: ");
    DISP25(ARR25, N25);

    return 0;
}