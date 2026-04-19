/*
Anshu Lakshkar
0801CS241020
Assignment number - 12(Searching)
Problem number - 02
Date of submission - 29th March 2026
*/
#include <stdio.h>

int BS25(int ARR25[], int L25, int H25, int KEY25) {

    while (L25 <= H25) {
        int M25 = L25 + (H25 - L25)/2;

        if (ARR25[M25] == KEY25)
            return M25;

        else if (ARR25[M25] < KEY25)
            L25 = M25 + 1;

         else
            H25 = M25 - 1;
    }

    return -1;
}
int ES25(int ARR25[], int N25, int KEY25) {

    if (ARR25[0] == KEY25)
        return 0;

    int I25 = 1;

    while (I25 < N25 && ARR25[I25] <= KEY25)
        I25 *= 2;
    int L25 = I25 / 2;
    int H25 = (I25 < N25) ? I25 : N25 - 1;

    return BS25(ARR25, L25, H25, KEY25);
}
int main() {

    int ARR25[] = {1, 4, 7, 9, 13, 16, 19, 25, 31, 40};
    int N25 = sizeof(ARR25) / sizeof(ARR25[0]);
    //Test case 1
    int KEY25_1 = 13;
    //Test case 2
    // int KEY25_1 = 40;
    //Test case 3
    // int KEY25_1 = 25;

    printf("Index: %d\n", ES25(ARR25, N25, KEY25_1));

    return 0;
}