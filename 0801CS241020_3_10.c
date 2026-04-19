/*
Anshu Lakshkar
0801CS241020
Assignment number - 3 (Linked List-1)
Problem number - 10
Date of submission - 25th Jan 2026
*/

#include <stdio.h>
#include "LinkedList.h"

NODE* MID25NODE(NODE* h25) {
    NODE* SLOW25 = h25;
    NODE* FAST25= h25->next;

    while (FAST25 != NULL && FAST25->next != NULL) {
        SLOW25 = SLOW25->next;
        FAST25 = FAST25->next->next;
    }
    return SLOW25;
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

    NODE* mid25 = MID25NODE(head);

    NODE* secondHalf = mid25->next;
    mid25->next = NULL;

    NODE* temp = secondHalf;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head = secondHalf;

    printf("After rearranging:\n");
    DISPLAY25(head);

    return 0;
}
