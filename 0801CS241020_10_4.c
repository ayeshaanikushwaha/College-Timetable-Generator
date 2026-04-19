/*
Anshu Lakshkar
0801CS241020
Assignment number - 10(Graph-II)
Problem number - 4
Date of submission - 15th March 2026
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node25{
    int PID25;
    struct node25* NXT25;
} Node25;

typedef struct{
    int TP25;
    Node25** ADJ25;
    int* CIT25;
} Net25;

Node25* NEW25(int ID25){

    Node25* ND25 = malloc(sizeof(Node25));

    if(ND25){
        ND25->PID25 = ID25;
        ND25->NXT25 = NULL;
    }

    return ND25;
}

void ADD25(Net25* NET25,int A25,int B25){

    Node25* ND25 = NEW25(B25);

    ND25->NXT25 = NET25->ADJ25[A25];
    NET25->ADJ25[A25] = ND25;

    NET25->CIT25[B25]++;
}

void PATH25(Net25* NET25,int ST25,int EN25){

    int* Q25 = malloc(sizeof(int)*NET25->TP25);
    int* PAR25 = malloc(sizeof(int)*NET25->TP25);
    bool* VIS25 = calloc(NET25->TP25,sizeof(bool));

    int FR25=0,RE25=0;

    for(int I25=0; I25<NET25->TP25; I25++)
        PAR25[I25] = -1;

    VIS25[ST25] = true;
    Q25[RE25++] = ST25;

    bool FND25 = false;

    while(FR25 < RE25){

        int CUR25 = Q25[FR25++];

        if(CUR25 == EN25){
            FND25 = true;
            break;
        }

        Node25* TMP25 = NET25->ADJ25[CUR25];

        while(TMP25){

            if(!VIS25[TMP25->PID25]){

                VIS25[TMP25->PID25] = true;
                PAR25[TMP25->PID25] = CUR25;

                Q25[RE25++] = TMP25->PID25;
            }

            TMP25 = TMP25->NXT25;
        }
    }

    if(FND25){

        printf("Path found: ");

        int CUR25 = EN25;

        while(CUR25 != -1){

            printf("%d%s",CUR25,(CUR25==ST25?"":" <- "));
            CUR25 = PAR25[CUR25];
        }

        printf("\n");

    }else{

        printf("No citation link between %d and %d\n",ST25,EN25);
    }

    free(Q25);
    free(PAR25);
    free(VIS25);
}

int main(){

    int NP25 = 10;
    Net25 NET25;
    NET25.TP25 = NP25;

    NET25.ADJ25 = malloc(sizeof(Node25*)*NP25);
    NET25.CIT25 = calloc(NP25,sizeof(int));

    for(int I25=0; I25<NP25; I25++)
        NET25.ADJ25[I25] = NULL;

    ADD25(&NET25,0,1);
    ADD25(&NET25,1,2);
    ADD25(&NET25,2,3);
    ADD25(&NET25,0,3);

    printf("Citation Analysis\n");

    for(int I25=0; I25<4; I25++){
        printf("Paper %d has %d citations\n", I25, NET25.CIT25[I25]);
    }

    PATH25(&NET25,0,3);

    free(NET25.ADJ25);
    free(NET25.CIT25);

    return 0;
}