/*
Anshu Lakshkar
0801CS241020
Assignment number -  6 (Queue)
Problem number - 4
Date of submission - 13th Feb 2026
*/
#include <stdio.h>
#define MAX25 5  

int BUF25[MAX25];
int F25 = 0, R25 = -1, CNT25 = 0;
void DISP25() {
    printf("Buffer: ");
    if (CNT25 == 0) {
        printf("Empty");
    } else {
        for (int i = 0; i < CNT25; i++) {
            int idx = (F25 + i) % MAX25;
            printf("%d ", BUF25[idx]);
        }
    }
    printf("\n");
}
void PROD25(int item) {
    if (CNT25 == MAX25) {
        printf("Producer: Buffer Overflow! Cannot insert %d\n", item);
        return;
    }

    R25 = (R25 + 1) % MAX25;
    BUF25[R25] = item;
    CNT25++;

    printf("Producer inserted: %d\n", item);
    DISP25();
}
void CONS25() {
    if (CNT25 == 0) {
        printf("Consumer: Buffer Underflow! Nothing to consume\n");
        return;
    }

    int val = BUF25[F25];
    F25 = (F25 + 1) % MAX25;
    CNT25--;

    printf("Consumer removed: %d\n", val);
    DISP25();
}

int main() {
    PROD25(10);
    PROD25(20);
    PROD25(30);
    CONS25();
    PROD25(40);
    PROD25(50);
    PROD25(60); 
    CONS25();
    CONS25();
    CONS25();
    CONS25();  

    return 0;
}
