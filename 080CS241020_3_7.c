/*
Anshu Lakshkar
0801CS241020
Assignment number - 3 (Linked List-1)
Problem number - 7
Date of submission - 25th Jan 2026
*/

#include "LinkedList.h"
#include <stdio.h>

NODE* INC25REVERSE(NODE* h25) {
    NODE* cu25rr = h25;
    NODE* prevTail = NULL;
    NODE* h225 = NULL;
    int s225 = 1; 
    NODE* TEMP = h25;
    int s25 = 0;
    
    while (TEMP != NULL) {
        s25++;
        TEMP = TEMP->next;
    }

    while (cu25rr != NULL && s25 >= s225) {
        NODE* groupHead = cu25rr;
        NODE* pr25ev = NULL;
        NODE* ne25xt = NULL;
        int c25 = 0;

        while (cu25rr != NULL && c25 < s225) {
            ne25xt = cu25rr->next;
            cu25rr->next = pr25ev;
            pr25ev = cu25rr;
            cu25rr = ne25xt;
            c25++;
        }
        if (h225 == NULL)
            h225 = pr25ev;
        if (prevTail != NULL)
            prevTail->next = pr25ev;

        prevTail = groupHead;
        s25 -= s225;
        s225++;
    }

    if (prevTail != NULL)
        prevTail->next = cu25rr;

    return h225;
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

    head = INC25REVERSE(head);
    printf("After Incremental Reverse:\n");
    DISPLAY25(head);

    return 0;
}
