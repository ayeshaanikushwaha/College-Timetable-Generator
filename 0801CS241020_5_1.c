/*
Anshu Lakshkar
0801CS241020
Assignment number - 5 (Stack)
Problem number - 1
Date of submission - 8th Feb 2026
*/
#include <stdio.h>

int HIS25TOGRAM(int h[], int N25UM) {
    int sT[100000];   
    int top = -1;
    int M_25A = 0;
    int W_25;
    int H_25;

    for (int a = 0; a <= N25UM; a++) {
        int C_25H = (a == N25UM) ? 0 : h[a];
        while (top != -1 && C_25H < h[sT[top]]) {
            H_25 = h[sT[top--]];
            if (top == -1)
                W_25 = a;
            else
                W_25 = a - sT[top] - 1;
            int A_25 = H_25 * W_25;
            if (A_25 > M_25A)
                M_25A=A_25;
        }

        sT[++top] = a;  
    }

    return M_25A;
}

int main() {
    // //case 1
    // int h[] = {2, 1, 5, 6, 2, 3};
    // //case 2
    // int h[] = {2, 4};
    // case 3
    int h[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(h) / sizeof(h[0]);

    printf("Largest Area = %d", HIS25TOGRAM(h, n));
    return 0;
}
