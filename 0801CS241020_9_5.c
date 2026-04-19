/*
Anshu Lakshkar
0801CS241020
Assignment number -  9 (Graph-I)
Problem number - 5
Date of submission - 8th March 2026
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX25 20
struct Node25{
    int VTX25;
    struct Node25 *NXT25;
};

struct Node25* GR25[MAX25];
int VIS25[MAX25];

struct Node25* NEW25(int V25){
    struct Node25* ND25 = (struct Node25*)malloc(sizeof(struct Node25));

    ND25->VTX25 = V25;
    ND25->NXT25 = NULL;

    return ND25;
}
void ADD25(int SRC25, int DEST25){
    struct Node25* ND25 = NEW25(DEST25);
    ND25->NXT25 = GR25[SRC25];
    GR25[SRC25] = ND25;
}
int CNTPATH25(int SRC25, int DEST25){
    if (SRC25 == DEST25)
        return 1;

    VIS25[SRC25] = 1;
    int CNT25 = 0;

    struct Node25* TMP25 = GR25[SRC25];

    while (TMP25 != NULL){
        int NX25 = TMP25->VTX25;
        if (!VIS25[NX25])
            CNT25 += CNTPATH25(NX25, DEST25);
        TMP25 = TMP25->NXT25;
    }

    VIS25[SRC25] = 0;

    return CNT25;
}

int main(){
    int N25, E25;

    printf("Enter number of vertices: ");
    scanf("%d", &N25);

    printf("Enter number of edges: ");
    scanf("%d", &E25);
    for (int I25 = 0; I25 < N25; I25++){
        GR25[I25] = NULL;
        VIS25[I25] = 0;
    }

    printf("Enter edges (u v):\n");

    for (int I25 = 0; I25 < E25; I25++){
        int U25, V25;
        scanf("%d %d", &U25, &V25);

        ADD25(U25, V25);   
    }

    int SRC25, DEST25;

    printf("Enter source: ");
    scanf("%d", &SRC25);

    printf("Enter destination: ");
    scanf("%d", &DEST25);

    int RES25 = CNTPATH25(SRC25, DEST25);

    printf("Total Paths = %d\n", RES25);

    return 0;
}