/*
Anshu Lakshkar
0801CS241020
Assignment number - 12(Searching)
Problem number - 06
Date of submission - 29th March 2026
*/
#include <stdio.h>
#include <string.h>
#define SIZE25 256
int ISO25(char S125[], char S225[]){

    int MAP125[SIZE25];
    int MAP225[SIZE25];

    for (int I25 = 0; I25 < SIZE25; I25++){
        MAP125[I25] = -1;
        MAP225[I25] = -1;
    }

    int N25 = strlen(S125);

    if (N25 != strlen(S225))
        return 0;

    for (int I25 = 0; I25 < N25; I25++){

        char C125 = S125[I25];
        char C225 = S225[I25];
        if (MAP125[C125] == -1 && MAP225[C225] == -1) {
            MAP125[C125] = C225;
            MAP225[C225] = C125;
        }
        else{
            if (MAP125[C125] != C225 ||
                MAP225[C225] != C125)
                return 0;
        }
    }

    return 1;
}
int main() {

    // Case 1 
    char S125_1[] = "egg";
    char S225_1[] = "add";

    // Case 2 
    char S125_2[] = "foo";
    char S225_2[] = "bar";

    // Case 3 
    char S125_3[] = "paper";
    char S225_3[] = "title";

    printf("Case 1: %s\n",
        ISO25(S125_1, S225_1) ? "Isomorphic" : "Not Isomorphic");

    printf("Case 2: %s\n",
        ISO25(S125_2, S225_2) ? "Isomorphic" : "Not Isomorphic");

    printf("Case 3: %s\n",
        ISO25(S125_3, S225_3) ? "Isomorphic" : "Not Isomorphic");

    return 0;
}