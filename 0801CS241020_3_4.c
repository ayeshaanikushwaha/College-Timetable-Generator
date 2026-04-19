/*
Anshu Lakshkar
0801CS241020
Assignment number - 3 (Linked List-1)
Problem number - 4
Date of submission - 25th Jan 2026
*/

#include "LinkedList.h"
#include <stdio.h>

NODE* K25REVERSE(NODE* h25, int k25);

NODE* NORMAL(NODE* h25, int k25) {
    NODE* TEMP = h25;
    int c25 = 1;

    while (TEMP != NULL && c25 < k25) {
        TEMP = TEMP->next;
        c25++;
    }

    if (TEMP != NULL && TEMP->next != NULL) {
        TEMP->next = K25REVERSE(TEMP->next, k25);
    }

    return h25;
}

NODE* K25REVERSE(NODE* h25, int k25) {
    NODE* cu25rr = h25;
    NODE* pr25ev = NULL;
    NODE* ne25xt = NULL;
    int c25 = 0;

    while (cu25rr != NULL && c25 < k25) {
        ne25xt = cu25rr->next;
        cu25rr->next = pr25ev;
        pr25ev = cu25rr;
        cu25rr = ne25xt;
        c25++;
    }

    if (ne25xt != NULL) {
        h25->next = NORMAL(ne25xt, k25);
    }

    return pr25ev;
}

int main() {
    NODE* head = NULL;
    int k25;

    printf("Enter value of k: ");
    scanf("%d", &k25);

    head = addNodeEnd(head, 35);
    head = addNodeEnd(head, 44);
    head = addNodeEnd(head, 47);
    head = addNodeEnd(head, 89);
    head = addNodeEnd(head, 90);
    head = addNodeEnd(head, 93);

    printf("Original List:\n");
    DISPLAY25(head);

    head = K25REVERSE(head, k25);

    printf("After reversing alternate %d nodes:\n", k25);
    DISPLAY25(head);

    return 0;
}
