/*
Anshu Lakshkar
0801CS241020
Assignment number - 13(Hashing)
Problem number - 05
Date of submission - 5th April 2026
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE25 100
typedef struct Node25{
    int KEY25;
    int CNT25;
    struct Node25* NXT25;
} Node25;

Node25* HT25[SIZE25];

int HASH25(int KEY25){
    return KEY25 % SIZE25;
}

void INS25(int KEY25){

    int IDX25 = HASH25(KEY25);

    Node25* TMP25 = HT25[IDX25];

    while (TMP25){

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
void ODD25(){
    printf("Odd occurring elements: ");

    for (int I25 = 0; I25 < SIZE25; I25++){
        Node25* TMP25 = HT25[I25];
        while (TMP25){

            if (TMP25->CNT25 % 2 != 0)
                printf("%d ", TMP25->KEY25);

            TMP25 = TMP25->NXT25;
        }
    }
}

int main() {

    int ARR25[] = {7, 3, 7, 2, 2, 5, 5, 9, 9, 9};

    int N25 = sizeof(ARR25) / sizeof(ARR25[0]);
    for (int I25 = 0; I25 < SIZE25; I25++)
        HT25[I25] = NULL;

    for (int I25 = 0; I25 < N25; I25++)
        INS25(ARR25[I25]);
    ODD25();

    return 0;
}