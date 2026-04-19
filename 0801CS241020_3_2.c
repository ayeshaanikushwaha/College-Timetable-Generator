/*
Anshu Lakshkar
0801CS241020
Assignment number - 3 (Linked List-1)
Problem number - 2
Date of submission - 25th Jan 2026
*/

#include "LinkedList.h"
#include <stdio.h>

NODE* REVERSE_M_TO_N(NODE* h25, int m25, int n25) {
    if (h25 == NULL || m25 == n25)
        return h25;

    NODE* cu25 = h25;
    NODE* pr25 = NULL;
    int p25 = 1;

    while (cu25 != NULL && p25 < m25) {
        pr25 = cu25;
        cu25 = cu25->next;
        p25++;
    }

    NODE* conn25 = pr25; 
    NODE* tail25 = cu25;  

    NODE* ne25 = NULL;
    NODE* prev25 = NULL;

    while (cu25 != NULL && p25 <= n25) {
        ne25 = cu25->next;
        cu25->next = prev25;
        prev25 = cu25;
        cu25 = ne25;
        p25++;
    }

    if (conn25 != NULL)
        conn25->next = prev25;
    else
        h25 = prev25;

    tail25->next = cu25;

    return h25;
}

int main() {
    NODE* head = NULL;

    head = addNodeEnd(head, 35);
    head = addNodeEnd(head, 44);
    head = addNodeEnd(head, 47);
    head = addNodeEnd(head, 89);
    head = addNodeEnd(head, 90);
    head = addNodeEnd(head, 93);

    printf("Original List:\n");
    DISPLAY25(head);

    head = REVERSE_M_TO_N(head, 2, 5);

    printf("After Reversing Between 2 and 5:\n");
    DISPLAY25(head);

    return 0;
}
