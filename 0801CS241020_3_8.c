/*
Anshu Lakshkar
0801CS241020
Assignment number - 3 (Linked List-1)
Problem number - 8
Date of submission - 25th Jan 2026
*/

#include "LinkedList.h"
#include <stdio.h>
NODE* NODES25SWAP(NODE* b25){
    NODE* curr25ent = b25;
    NODE* prev25ious = NULL;
    NODE* n25 = NULL;
    int c25 = 0;

    while (curr25ent != NULL && c25 < 2){
        n25 = curr25ent->next;
        curr25ent->next = prev25ious;
        prev25ious = curr25ent;
        curr25ent = n25;
        c25++;
    }

    if (curr25ent != NULL){
        b25->next = NODES25SWAP(n25);
    }

    return prev25ious;
}

int main() {
    NODE* head = NULL;

    head = addNodeEnd(head, 35);
    head = addNodeEnd(head, 44);
    head = addNodeEnd(head, 44);
    head = addNodeEnd(head, 89);
    head = addNodeEnd(head, 90);
    head = addNodeEnd(head, 93);

    printf("Original List:\n");
    DISPLAY25(head);
    head = NODES25SWAP(head);
    printf("After swaping nodes:\n");
    DISPLAY25(head);

    return 0;
}