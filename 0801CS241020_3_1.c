/*
Anshu Lakshkar
0801CS241020
Assignment number - 3 (Linked List-1)
Problem number - 1
Date of submission - 25th Jan 2026
*/
#include "LinkedList.h"
#include <stdio.h>

NODE* K25REVERSE(NODE* h25, int k25){
    NODE* cu25rr = h25;
    NODE* pr25ev = NULL;
    NODE* ne25xt = NULL;
    int c25 = 0;

    while (cu25rr != NULL && c25 < k25){
        ne25xt = cu25rr->next;
        cu25rr->next = pr25ev;
        pr25ev = cu25rr;
        cu25rr = ne25xt;
        c25++;
    }

    if (ne25xt != NULL){
        h25->next = K25REVERSE(ne25xt, k25);
    }

    return pr25ev;
}

int main() {
    NODE* head = NULL;
    int k;

    printf("Enter value of k: ");
    scanf("%d", &k);

    head = addNodeEnd(head, 35);
    head = addNodeEnd(head, 44);
    head = addNodeEnd(head, 44);
    head = addNodeEnd(head, 89);
    head = addNodeEnd(head, 90);
    head = addNodeEnd(head, 93);

    printf("Original List:\n");
    DISPLAY25(head);

    head = K25REVERSE(head, k);

    printf("After reversing in groups of %d:\n", k);
    DISPLAY25(head);

    return 0;
}
