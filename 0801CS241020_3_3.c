/*
Anshu Lakshkar
0801CS241020
Assignment number - 3 (Linked List-1)
Problem number - 3
Date of submission - 25th Jan 2026
*/

#include "LinkedList.h"
#include <stdio.h>
NODE* LEFT25K(NODE* h25, int k25){
    NODE* TEMP = h25;
    int c=1;
    while(c<k25&&TEMP){
        TEMP = TEMP->next;
        c++;
    }
    NODE* h225;
    h225 = TEMP->next;
    TEMP->next = NULL;
    TEMP = h225;
    while(TEMP->next!=NULL){
        TEMP=TEMP->next;
    }
    TEMP->next = h25;
    return h225;
}
int main() {
    NODE* head = NULL;
    int k;

    printf("Enter value of k: ");
    scanf("%d", &k);

    head = addNodeEnd(head, 35);
    head = addNodeEnd(head, 44);
    head = addNodeEnd(head, 47);
    head = addNodeEnd(head, 89);
    head = addNodeEnd(head, 90);
    head = addNodeEnd(head, 93);

    printf("Original List:\n");
    DISPLAY25(head);

    head = LEFT25K(head, k);

    printf("After Rotate Left by %d Nodes:\n", k);
    DISPLAY25(head);

    return 0;
}
