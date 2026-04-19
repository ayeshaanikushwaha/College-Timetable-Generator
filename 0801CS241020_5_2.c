/*
Anshu Lakshkar
0801CS241020
Assignment number - 5 (Stack)
Problem number - 2
Date of submission - 8th Feb 2026
*/
#include <stdio.h>
#define max 100
void STOCK25SPAN(int P[], int N) {
    int ST[max];  
    int top = -1;
    int SP[max];   

    for (int a = 0; a < N; a++) {
        while (top != -1 && P[a] >= P[ST[top]]) {
            top--;
        }
        if (top == -1)
            SP[a] = a + 1;
        else
            SP[a] = a - ST[top];
        ST[++top] = a;
    }
    printf("Span = ");
    for (int a = 0; a < N; a++) {
        printf("%d ", SP[a]);
    }
}

int main() {

    // CASE 1
    int P[] = {100, 80, 60, 70, 60, 75, 85};
    // CASE 2
    // int P[] = {10, 4, 5, 90, 120, 80};
    int N = sizeof(P) / sizeof(P[0]);
    STOCK25SPAN(P, N);

    return 0;
}
