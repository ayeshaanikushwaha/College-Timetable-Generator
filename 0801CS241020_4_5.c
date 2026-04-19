/*
Anshu Lakshkar
0801CS241020
Assignment number - 4(Linked List-2)
Problem number - 5
Date of submission - 1st Feb 2026
*/
#include "LinkedList.h"
#include <stdio.h>
int CY25CLE(NODE* h25){
    NODE* SL25OW = h25;
    NODE* FA25ST = h25;

    while(FA25ST!=NULL && FA25ST->next!=NULL){
        FA25ST = FA25ST->next->next;
        SL25OW = SL25OW->next;
        if(SL25OW==FA25ST){
            SL25OW = h25;
            while (SL25OW != FA25ST) {
                SL25OW = SL25OW->next;
                FA25ST = FA25ST->next;
            }
            DISPLAY25(SL25OW);
            return 1;
        }
    }
    return 0;
}
int main(){
     NODE* head = NULL;

    head = addNodeEnd(head, 35);
    head = addNodeEnd(head, 44);
    head = addNodeEnd(head, 47);
    head = addNodeEnd(head, 89);
    head = addNodeEnd(head, 90);
    head = addNodeEnd(head, 93);

    if(CY25CLE(head)){
        printf("There is loop in given linkedlist");
    }else{
        printf("There is no loop in given linkedlist");
    }
}
