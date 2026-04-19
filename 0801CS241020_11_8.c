/*
Anshu Lakshkar
0801CS241020
Assignment number - 11(Sorting)
Problem number - 8
Date of submission - 22nd March 2026
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node25{
    int DA25;
    struct Node25* NXT25;
} Node25;

Node25* INS25(Node25* HD25, int VAL25){

    Node25* NEW25 = (Node25*)malloc(sizeof(Node25));

    NEW25->DA25 = VAL25;
    NEW25->NXT25 = NULL;

    if (HD25 == NULL)
        return NEW25;

    Node25* TMP25 = HD25;

    while (TMP25->NXT25)
        TMP25 = TMP25->NXT25;

    TMP25->NXT25 = NEW25;

    return HD25;
}

Node25* SPLIT25(Node25* HD25, int SZ25){

    for (int I25 = 1; HD25 && I25 < SZ25; I25++)
        HD25 = HD25->NXT25;

    if (!HD25) return NULL;

    Node25* SEC25 = HD25->NXT25;
    HD25->NXT25 = NULL;

    return SEC25;
}

Node25* MERGE25(Node25* L125, Node25* L225){

    Node25 DUM25;
    Node25* TL25 = &DUM25;

    DUM25.NXT25 = NULL;

    while (L125 && L225){

        if (L125->DA25 < L225->DA25){
            TL25->NXT25 = L125;
            L125 = L125->NXT25;
        } else{
            TL25->NXT25 = L225;
            L225 = L225->NXT25;
        }

        TL25 = TL25->NXT25;
    }

    if (L125) TL25->NXT25 = L125;
    else TL25->NXT25 = L225;

    return DUM25.NXT25;
}

Node25* SORT25(Node25* HD25){

    if (!HD25 || !HD25->NXT25)
        return HD25;

    int N25 = 0;
    Node25* TMP25 = HD25;

    while (TMP25){
        N25++;
        TMP25 = TMP25->NXT25;
    }

    Node25 DUM25;
    DUM25.NXT25 = HD25;

    for (int SZ25 = 1; SZ25 < N25; SZ25 *= 2){

        Node25* CUR25 = DUM25.NXT25;
        Node25* TL25 = &DUM25;

        while (CUR25){

            Node25* L125 = CUR25;
            Node25* L225 = SPLIT25(L125, SZ25);
            CUR25 = SPLIT25(L225, SZ25);
            Node25* MR25 = MERGE25(L125, L225);
            TL25->NXT25 = MR25;

            while (TL25->NXT25)
                TL25 = TL25->NXT25;
        }
    }

    return DUM25.NXT25;
}

void PRINT25(Node25* HD25){

    while (HD25){
        printf("%d -> ", HD25->DA25);
        HD25 = HD25->NXT25;
    }

    printf("NULL\n");
}

int main(){

    Node25* HD25 = NULL;

    HD25 = INS25(HD25, 4);
    HD25 = INS25(HD25, 2);
    HD25 = INS25(HD25, 1);
    HD25 = INS25(HD25, 3);

    printf("Original List:\n");
    PRINT25(HD25);

    HD25 = SORT25(HD25);

    printf("Sorted List:\n");
    PRINT25(HD25);

    return 0;
}