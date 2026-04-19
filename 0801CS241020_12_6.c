/*
Anshu Lakshkar
0801CS241020
Assignment number - 12(Searching)
Problem number - 06
Date of submission - 29th March 2026
*/
#include <stdio.h>

int BS25(int ARR25[], int N25, int KEY25){

    int L25 = 0, H25 = N25 - 1;
    while (L25 <= H25) {
        int M25 = L25 + (H25 - L25)/2;

        if (ARR25[M25] == KEY25)
            return M25;
        if (ARR25[L25] == ARR25[M25] && ARR25[M25] == ARR25[H25]){
            L25++;
            H25--;
        }
        else if (ARR25[L25] <= ARR25[M25]){

            if (KEY25 >= ARR25[L25] && KEY25 < ARR25[M25])
                H25 = M25 - 1;
            else
                L25 = M25 + 1;
        }
        else{

            if (KEY25 > ARR25[M25] && KEY25 <= ARR25[H25])
                L25 = M25 + 1;
            else
                H25 = M25 - 1;
        }
    }

    return -1;
}
int main(){
    //Test case 1
    int ARR25_1[] = {15, 18, 2, 3, 6, 12};
    int N25_1 = sizeof(ARR25_1) / sizeof(ARR25_1[0]);
    int KEY25_1 = 3;
    // //Test case 2
    // int ARR25_1[] = {7, 7, 8, 1, 2, 3, 7};
    // int N25_1 = sizeof(ARR25_1) / sizeof(ARR25_1[0]);
    // int KEY25_1= 8;
    // //Test case 3
    // int ARR25_1[] = {30, 40, 50, 5, 10, 20};
    // int N25_1 = sizeof(ARR25_1) / sizeof(ARR25_1[0]);
    // int KEY25_1 = 100;

    printf("Index: %d\n", BS25(ARR25_1, N25_1, KEY25_1));

    return 0;
}