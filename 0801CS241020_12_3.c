/*
Anshu Lakshkar
0801CS241020
Assignment number - 12(Searching)
Problem number - 03
Date of submission - 29th March 2026
*/
#include <stdio.h>
int BS25(int ARR25[], int N25, int KEY25){

    int L25 = 0;
    int H25 = N25 - 1;

    while (L25 <= H25){

        int M25 = L25 + (H25 - L25) / 2;

        if (ARR25[M25] == KEY25)
            return M25;
        if (M25 > L25 && ARR25[M25 - 1] == KEY25)
            return M25 - 1;
        if (M25 < H25 && ARR25[M25 + 1] == KEY25)
            return M25 + 1;

        if (ARR25[M25] > KEY25)
            H25 = M25 - 2;
        else
            L25 = M25 + 2;
    }

    return -1;
}

int main(){

    int ARR25[] = {5, 3, 12, 10, 22, 18, 30, 28, 40};
    int N25 = sizeof(ARR25) / sizeof(ARR25[0]);
    int KEY25 = 18;
    int B25 = BS25(ARR25, N25, KEY25);

    if (B25 != -1)
        printf("Element found at index: %d", B25);
    else
        printf("Element not found");

    return 0;
}