/*
Anshu Lakshkar
0801CS241020
Assignment number - 11(Sorting)
Problem number - 2
Date of submission - 22nd March 2026
*/
#include <stdio.h>
#include <string.h>

struct Student25{
    char NM25[50];
    int AG25;
    int GR25;
};
void MERGE25(struct Student25 ARR25[], int L25, int M25, int R25){

    int N125 = M25 - L25 + 1;
    int N225 = R25 - M25;

    struct Student25 LARR25[N125], RARR25[N225];

    for (int I25 = 0; I25 < N125; I25++)
        LARR25[I25] = ARR25[L25 + I25];

    for (int J25 = 0; J25 < N225; J25++)
        RARR25[J25] = ARR25[M25 + 1 + J25];

    int I25 = 0, J25 = 0, K25 = L25;

    while (I25 < N125 && J25 < N225){

        if (LARR25[I25].GR25 > RARR25[J25].GR25 ||(LARR25[I25].GR25 == RARR25[J25].GR25 && LARR25[I25].AG25 < RARR25[J25].AG25) ||
            (LARR25[I25].GR25 == RARR25[J25].GR25 && LARR25[I25].AG25 == RARR25[J25].AG25 &&
            strcmp(LARR25[I25].NM25, RARR25[J25].NM25) < 0)){

            ARR25[K25++] = LARR25[I25++];

        }else{
            ARR25[K25++] = RARR25[J25++];
        }
    }
    while (I25 < N125)
        ARR25[K25++] = LARR25[I25++];

    while (J25 < N225)
        ARR25[K25++] = RARR25[J25++];
}

void MSORT25(struct Student25 ARR25[], int L25, int R25) {

    if (L25 < R25){
        int M25 = (L25 + R25) / 2;
        MSORT25(ARR25, L25, M25);
        MSORT25(ARR25, M25 + 1, R25);
       MERGE25(ARR25, L25, M25, R25);
    }
}

int main() {

    struct Student25 ARR25[] = {{"Anshu", 20, 90},{"Shradha", 19, 90},{"Prakrati", 20, 85}};

    int N25 = 3;
    MSORT25(ARR25, 0, N25 - 1);

    for (int I25 = 0; I25 < N25; I25++)
        printf("%s %d %d\n",ARR25[I25].NM25,ARR25[I25].AG25,ARR25[I25].GR25);

    return 0;
}