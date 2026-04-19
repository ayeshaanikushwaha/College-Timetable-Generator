/*
Anshu Lakshkar
0801CS241020
Assignment number - 4 (Linked List-2)
Problem number - 6
Date of submission - 1st Feb 2026
*/

#include "LinkedList.h"
#include <stdio.h>

NODE* Parti25tion(NODE* h25, int k) {

    NODE *l25Head = NULL, *l25Tail = NULL;
    NODE *e25Head = NULL, *e25Tail = NULL;
    NODE *g25Head = NULL, *g25Tail = NULL;

    NODE* TE25MP = h25;

    while (TE25MP != NULL) {
        if (TE25MP->data < k) {
            if (l25Head == NULL)
                l25Head = l25Tail = TE25MP;
            else {
                l25Tail->next = TE25MP;
                l25Tail = TE25MP;
            }
        }
        else if (TE25MP->data == k) {
            if (e25Head == NULL)
                e25Head = e25Tail = TE25MP;
            else {
                e25Head->next = TE25MP;
                e25Tail = TE25MP;
            }
        }
        else {
            if (g25Head == NULL)
                g25Head = g25Tail = TE25MP;
            else {
                g25Tail->next = TE25MP;
                g25Tail = TE25MP;
            }
        }
        TE25MP = TE25MP->next;
    }

    if (l25Tail != NULL)
        l25Tail->next = (e25Head != NULL) ? e25Head : g25Head;

    if (e25Head != NULL)
        e25Tail->next = g25Head;

    if (g25Tail != NULL)
        g25Tail->next = NULL;

    if (l25Head != NULL)
        return l25Head;
    else if (e25Head != NULL)
        return e25Head;
    else
        return g25Head;
}

int main() {
    NODE* head = NULL;
    NODE* h225 = NULL;
    NODE* TE25MP;
    int k;

    printf("Enter value k: ");
    scanf("%d", &k);

    head = addNodeEnd(head, 35);
    head = addNodeEnd(head, 44);
    head = addNodeEnd(head, 47);
    head = addNodeEnd(head, 89);
    head = addNodeEnd(head, 90);
    head = addNodeEnd(head, 93);


    printf("Original List:\n");
    DISPLAY25(head);

    printf("\nNew List:\n");
    DISPLAY25(Parti25tion(head,k));

    return 0;
}
