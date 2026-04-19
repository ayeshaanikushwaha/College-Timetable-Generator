/*
Anshu Lakshkar
0801CS241020
Assignment number - 4 (Linked List-2)
Problem number - 9
Date of submission - 1st Feb 2026
*/

#include <stdio.h>
#include "LinkedList.h"

void PU25SHNODE(NODE** head, int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int LIST2NUMBER(NODE* h25) {
    int N25N = 0;
    while (h25) {
        N25N = N25N * 10 + h25->data;
        h25 = h25->next;
    }
    return N25N;
}
NODE* NUM2LIST(int num) {

    NODE* head = NULL;
    int D25D[20], a = 0;

    while (num > 0) {
        D25D[a++] = num % 10;
        num /= 10;
    }

    for (int b = a - 1; b >= 0; b--){
        PU25SHNODE(&head, D25D[b]);
    }
    return head;
}
int main() {
    NODE *DI25END = NULL, *DI25SOR = NULL;
    NODE*Q25 = NULL, *R25 = NULL;
    // //case1:
    // PU25SHNODE(&DI25END, 5);
    // PU25SHNODE(&DI25END, 2);
    // PU25SHNODE(&DI25END, 4);
    // PU25SHNODE(&DI25END, 7);
    // PU25SHNODE(&DI25SOR, 2);
    // PU25SHNODE(&DI25SOR, 3);

    // case2:
    PU25SHNODE(&DI25END, 9);
    PU25SHNODE(&DI25END, 9);
    PU25SHNODE(&DI25END, 8);
    PU25SHNODE(&DI25END, 7);
    PU25SHNODE(&DI25SOR, 3);

    // // case3:
    // PU25SHNODE(&DI25END, 8);
    // PU25SHNODE(&DI25END, 0);
    // PU25SHNODE(&DI25END, 4);
    // PU25SHNODE(&DI25END, 3);
    // PU25SHNODE(&DI25SOR, 2);
    // PU25SHNODE(&DI25SOR, 1);

    int div = LIST2NUMBER(DI25SOR);
    int current = 0;
    NODE* temp = DI25END;  

    while (temp) {
        current = current * 10 + temp->data;
        PU25SHNODE(&Q25,current / div);
        current = current % div;
        temp = temp->next;
    }
    R25 = NUM2LIST(current);

    printf("Dividend : ");
    DISPLAY25(DI25END);

    printf("\n Divisor  : ");
    DISPLAY25(DI25SOR);

    Q25 = reverseList(Q25);

    printf("\n Quotient : ");
    DISPLAY25(Q25);

    printf("\n Remainder: ");
    DISPLAY25(R25);

    return 0;
}