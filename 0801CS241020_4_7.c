/*
Anshu Lakshkar
0801CS241020
Assignment number - 4 (Linked List-2)
Problem number - 7
Date of submission - 1st Feb 2026
*/

#include "LinkedList.h"
#include <stdio.h>

void PU25SHNODE(NODE** head, int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}


NODE* ADD25(NODE* l1, NODE* l2) {
    NODE* RRR = NULL;
    int CAR25RY = 0;

    while (l1 || l2 || CAR25RY) {
        int SOO = CAR25RY;
        if (l1) {
            SOO += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            SOO += l2->data;
            l2 = l2->next;
        }
        PU25SHNODE(&RRR, SOO % 10);
        CAR25RY = SOO / 10;
    }
    return RRR;
}
int main() {
    NODE*list1 = NULL, *list2 = NULL;

    // //case 1:
    // PU25SHNODE(&list1, 2);
    // PU25SHNODE(&list1, 4);
    // PU25SHNODE(&list1, 3);
    // printf("First list: \n");
    // DISPLAY25(list1);

    // PU25SHNODE(&list2, 6);
    // PU25SHNODE(&list2, 5);
    // PU25SHNODE(&list2, 1);
    // printf("Second list: \n");
    // DISPLAY25(list2);
    
    //case 2:
    PU25SHNODE(&list1, 2);
    PU25SHNODE(&list1, 1);
    printf("First list: \n");
    DISPLAY25(list1);

    PU25SHNODE(&list2, 6);
    PU25SHNODE(&list2, 5);
    printf("Second list: \n");
    DISPLAY25(list2);

    // //case 3:
    // PU25SHNODE(&list1, 1);
    // PU25SHNODE(&list1, 6);
    // PU25SHNODE(&list1, 3);
    // PU25SHNODE(&list1, 3);
    // printf("First list: \n");
    // DISPLAY25(list1);

    // PU25SHNODE(&list2, 8);
    // PU25SHNODE(&list2, 5);
    // PU25SHNODE(&list2, 2);
    // printf("Second list: \n");
    // DISPLAY25(list2);

    NODE* A25DD = reverseList(ADD25(list1, list2));

    printf("Product: ");
    DISPLAY25(A25DD);

    return 0;
}