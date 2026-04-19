/*
Anshu Lakshkar
0801CS241020
Assignment number - 3 (Linked List-1)
Problem number - 6
Date of submission - 25th Jan 2026
*/

#include "LinkedList.h"
#include <stdio.h>

NODE* ROTATERIGHT1(NODE* h25) {
    if (h25 == NULL || h25->next == NULL)
        return h25;

    NODE* cu25 = h25;

    while (cu25->next->next != NULL)
        cu25 = cu25->next;

    NODE* la25 = cu25->next;
    cu25->next = NULL;
    la25->next = h25;

    return la25;
}

NODE* ROTATERIGHTREC(NODE* h25, int k25) {
    if (h25 == NULL || h25->next == NULL || k25 == 0)
        return h25;

    h25 = ROTATERIGHT1(h25);
    return ROTATERIGHTREC(h25, k25 - 1);
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

    head = ROTATERIGHTREC(head, k);

    printf("After Rotating Right by %d:\n", k);
    DISPLAY25(head);

    return 0;
}
