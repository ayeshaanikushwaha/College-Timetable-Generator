/*
Anshu Lakshkar
0801CS241020
Assignment number - 13(Hashing)
Problem number - 06
Date of submission - 5th April 2026
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE25 101
typedef struct Node25{
    int KEY25;
    int CNT25;
    struct Node25* NXT25;
} Node25;

Node25* HT25[SIZE25];
int HASH25(int KEY25){
    return abs(KEY25) % SIZE25;
}
void INC25(int KEY25){

    int IDX25 = HASH25(KEY25);
    Node25* TMP25 = HT25[IDX25];

    while (TMP25) {
        if (TMP25->KEY25 == KEY25){
            TMP25->CNT25++;
            return;
        }
        TMP25 = TMP25->NXT25;
    }

    Node25* NEW25 = (Node25*)malloc(sizeof(Node25));
    NEW25->KEY25 = KEY25;
    NEW25->CNT25 = 1;
    NEW25->NXT25 = HT25[IDX25];

    HT25[IDX25] = NEW25;
}

int DEC25(int KEY25){

    int IDX25 = HASH25(KEY25);
    Node25* TMP25 = HT25[IDX25];

    while (TMP25){

        if (TMP25->KEY25 == KEY25){
            TMP25->CNT25--;

            if (TMP25->CNT25 < 0)
                return 0;

            return 1;
        }

        TMP25 = TMP25->NXT25;
    }

    return 0;
}
int MATCH25(int A25[], int B25[], int N25){

    for (int I25 = 0; I25 < SIZE25; I25++)
        HT25[I25] = NULL;
    for (int I25 = 0; I25 < N25; I25++)
        INC25(A25[I25]);

    // subtract using B
    for (int I25 = 0; I25 < N25; I25++)
        if (!DEC25(B25[I25]))
            return 0;

    // final check
    for (int I25 = 0; I25 < SIZE25; I25++) {
        Node25* TMP25 = HT25[I25];
        while (TMP25) {
            if (TMP25->CNT25 != 0)
                return 0;
            TMP25 = TMP25->NXT25;
        }
    }

    return 1;
}
int main(){

    // Case 1
    int A25_1[] = {10, 20, 20, 30};
    int B25_1[] = {20, 10, 30, 20};

    // Case 2
    int A25_2[] = {5, 7, 9};
    int B25_2[] = {5, 7, 7};

    int N25 = 4;

    printf("Case 1: %s\n",
        MATCH25(A25_1, B25_1, 4) ? "MATCH" : "NOT MATCH");

    printf("Case 2: %s\n",
        MATCH25(A25_2, B25_2, 3) ? "MATCH" : "NOT MATCH");

    return 0;
}