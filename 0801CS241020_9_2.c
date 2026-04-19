/*
Anshu Lakshkar
0801CS241020
Assignment number -  9 (Graph-I)
Problem number - 2
Date of submission - 8th March 2026
*/
#include <stdio.h>
#define MAX25 20
int DFS25(int VTX25, int PAR25,
          int VIS25[],
          int GR25[][MAX25],
          int N25) {

    VIS25[VTX25] = 1;

    for (int I25 = 0; I25 < N25; I25++) {
        if (GR25[VTX25][I25]) {
            if (!VIS25[I25]) {
                if (DFS25(I25, VTX25,VIS25, GR25, N25))
                    return 1;
            }
            else if (I25 != PAR25)
                return 1;
        }
    }

    return 0;
}

int CYCLE25(int VTX25,int VIS25[] ,int REC25[],int GR25[][MAX25],int N25) {

    VIS25[VTX25] = 1;
    REC25[VTX25] = 1;

    for (int I25 = 0; I25 < N25; I25++) {
        if (GR25[VTX25][I25]) {
            if (!VIS25[I25] && CYCLE25(I25, VIS25,REC25, GR25, N25))
                return 1;
            else if (REC25[I25])
                return 1;
        }
    }
    REC25[VTX25] = 0;
return 0;
}
int main() {

    int GR25[MAX25][MAX25];
    int VIS25[MAX25] = {0};
    int REC25[MAX25] = {0},  N25;

    printf("Enter number of vertices: ");
    scanf("%d", &N25);

    printf("Enter adjacency matrix:\n");

    for (int I25 = 0; I25 < N25; I25++)
        for (int J25 = 0; J25 < N25; J25++)
            scanf("%d", &GR25[I25][J25]);
    int FLAG25 = 0;

    for (int I25 = 0; I25 < N25; I25++) {
        if (!VIS25[I25]) {
            if (DFS25(I25, -1,VIS25, GR25, N25)) {
                FLAG25 = 1;
                break;
            }
        }
    }

    if (FLAG25)
        printf("Cycle found (Undirected Graph)\n");
    else
        printf("No cycle (Undirected Graph)\n");
    for (int I25 = 0; I25 < N25; I25++)
        VIS25[I25] = 0;
    FLAG25 = 0;

    for (int I25 = 0; I25 < N25; I25++) {

        if (!VIS25[I25]) {

            if (CYCLE25(I25,VIS25,REC25,GR25,N25)) {
                FLAG25 = 1;
                break;
            }
        }
    }
    if (FLAG25)
        printf("Cycle found (Directed Graph)\n");
    else
        printf("No cycle (Directed Graph)\n");

    return 0;
}