/*
Anshu Lakshkar
0801CS241020
Assignment number -  9 (Graph-I)
Problem number - 4
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
int COL25[MAX25];
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

int ISBIP25(int N25){
    int Q25[MAX25];
    int FR25,RE25;

    for(int I25=0; I25<N25; I25++)
        COL25[I25] = -1;
    for(int S25=0; S25<N25; S25++){
        if(COL25[S25] != -1)
            continue;

        FR25 = RE25 = 0;
        Q25[RE25++] = S25;
        COL25[S25] = 0;

        while(FR25 < RE25){
            int U25 = Q25[FR25++];
            struct Node25* TMP25 = GR25[U25];

            while(TMP25){
                int V25 = TMP25->VTX25;

                if(COL25[V25] == -1){
                    COL25[V25] = 1 - COL25[U25];
                    Q25[RE25++] = V25;
                }
                else if(COL25[V25] == COL25[U25]){
                    return 0;
                }

                TMP25 = TMP25->NXT25;
            }
        }
    }

    return 1;
}

void RESET25(int N25){
    for(int I25=0; I25<N25; I25++)
        GR25[I25] = NULL;
}

int main(){

    int N25 = 4;

    //TEST CASE 1
    RESET25(N25);

    ADD25(0,1);
    ADD25(1,0);
    ADD25(1,2);
    ADD25(2,1);
    ADD25(2,3);
    ADD25(3,2);

    // TEST CASE 2

    // ADD25(0,1);
    // ADD25(1,0);
    // ADD25(1,2);
    // ADD25(2,1);
    // ADD25(2,0);
    // ADD25(0,2);

    if(ISBIP25(N25))
        printf("Graph is Bipartite\n");
    else
        printf("Graph is NOT Bipartite\n");

    return 0;
}