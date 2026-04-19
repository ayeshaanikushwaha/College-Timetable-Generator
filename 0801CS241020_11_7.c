/*
Anshu Lakshkar
0801CS241020
Assignment number - 11(Sorting)
Problem number - 7
Date of submission - 22nd March 2026
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int VAL25;
    int WT25;
} Item25;
void MERGE25(Item25 ARR25[], int L25, int M25, int R25){
    int N125 = M25 - L25 + 1;
    int N225 = R25 - M25;

    Item25 LARR25[N125], RARR25[N225];
    for (int I25 = 0; I25 < N125; I25++)
        LARR25[I25] = ARR25[L25 + I25];

    for (int J25 = 0; J25 < N225; J25++)
        RARR25[J25] = ARR25[M25 + 1 + J25];

    int I25 = 0, J25 = 0, K25 = L25;
    while (I25 < N125 && J25 < N225){

        if (LARR25[I25].WT25 > RARR25[J25].WT25 || (LARR25[I25].WT25 == RARR25[J25].WT25 &&
            LARR25[I25].VAL25 < RARR25[J25].VAL25)){

            ARR25[K25++] = LARR25[I25++];

        } else{

            ARR25[K25++] = RARR25[J25++];
        }
    }

    while (I25 < N125)
        ARR25[K25++] = LARR25[I25++];

    while (J25 < N225)
        ARR25[K25++] = RARR25[J25++];
}

void MSORT25(Item25 ARR25[], int L25, int R25){

    if (L25 < R25){
        int M25 = (L25 + R25)/2;
        MSORT25(ARR25, L25, M25);
        MSORT25(ARR25, M25 + 1, R25);
        MERGE25(ARR25, L25, M25, R25);
    }
}
int main(){

    Item25 ARR25[] = {{10, 2}, {5, 3},{8, 2},{1, 3}};

    int N25 = 4;
    MSORT25(ARR25, 0, N25 - 1);

    printf("Sorted Items (value, weight):\n");

    for (int I25 = 0; I25 < N25; I25++)
        printf("(%d, %d) ",ARR25[I25].VAL25,ARR25[I25].WT25);

    return 0;
}