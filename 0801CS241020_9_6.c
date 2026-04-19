/*
Anshu Lakshkar
0801CS241020
Assignment number -  9 (Graph-I)
Problem number - 6
Date of submission - 8th March 2026
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX25 20
struct Node25{
    int VTX25;
    struct Node25* NXT25;
};

struct Node25* GR25[MAX25];
int VIS25[MAX25];

struct Node25* NEW25(int V25){
    struct Node25* ND25 = (struct Node25*)malloc(sizeof(struct Node25));

    ND25->VTX25 = V25;
    ND25->NXT25 = NULL;

    return ND25;
}

void ADD25(int SRC25,int DEST25){
    struct Node25* ND25 = NEW25(DEST25);
    ND25->NXT25 = GR25[SRC25];
    GR25[SRC25] = ND25;
}
 
void DFS25(int V25){
    VIS25[V25] = 1;

    printf("%d ", V25);
    struct Node25* TMP25 = GR25[V25];

    while(TMP25){
        int NX25 = TMP25->VTX25;
        if(!VIS25[NX25])
            DFS25(NX25);

        TMP25 = TMP25->NXT25;
    }
}

void COMP25(int N25){

    for(int I25=0; I25<N25; I25++)
        VIS25[I25] = 0;

    for(int I25=0; I25<N25; I25++){

        if(!VIS25[I25]){
            printf("Component: ");
            DFS25(I25);
            printf("\n");
        }
    }
}

void RESET25(int N25){
    for(int I25=0; I25<N25; I25++)
        GR25[I25] = NULL;
}

int main(){

    int N25 = 7;

    RESET25(N25);
 
    ADD25(0,1);
    ADD25(1,0);
    ADD25(1,2);
    ADD25(2,1);
    ADD25(3,4);
    ADD25(4,3);
    ADD25(5,6);
    ADD25(6,5);

    printf("Connected Components:\n");

    COMP25(N25);

    return 0;
}