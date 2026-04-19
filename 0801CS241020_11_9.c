/*
Anshu Lakshkar
0801CS241020
Assignment number - 11(Sorting)
Problem number - 09
Date of submission - 22nd March 2026
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node25{
    float DA25;
    struct Node25* NXT25;
} Node25;

Node25* INS25(Node25* HD25, float VAL25){

    Node25* NEW25 = (Node25*)malloc(sizeof(Node25));

    NEW25->DA25 = VAL25;
    NEW25->NXT25 = NULL;

    if(!HD25 || VAL25 < HD25->DA25){
        NEW25->NXT25 = HD25;
        return NEW25;
    }

    Node25* TMP25 = HD25;

    while (TMP25->NXT25 && TMP25->NXT25->DA25 < VAL25)
        TMP25 = TMP25->NXT25;

    NEW25->NXT25 = TMP25->NXT25;
    TMP25->NXT25 = NEW25;

    return HD25;
}
void BSORT25(float ARR25[], int N25){

    Node25* BKT25[N25];
    for (int I25 = 0; I25 < N25; I25++)
        BKT25[I25] = NULL;

    for (int I25 = 0; I25 < N25; I25++){
        int IDX25 = N25 * ARR25[I25];
        BKT25[IDX25] = INS25(BKT25[IDX25], ARR25[I25]);
    }
    int K25 = 0;

    for (int I25 = 0; I25 < N25; I25++){

        Node25* TMP25 = BKT25[I25];

        while (TMP25){
            ARR25[K25++] = TMP25->DA25;
            TMP25 = TMP25->NXT25;
        }
    }
}
int main(){

    float ARR25[] = {0.42, 0.32, 0.23, 0.52, 0.25};
    int N25 = 5;

    BSORT25(ARR25, N25);

    printf("Sorted Array:\n");

    for (int I25 = 0; I25 < N25; I25++)
        printf("%.2f ", ARR25[I25]);

    return 0;
}