// Author: Prof. Surendra Gupta
// Date: 9th Jan 2026
// Linked List program
#include <stdio.h>
#include <stdlib.h>
struct LinkNode
{
    int data;
    struct LinkNode *next;
};
typedef struct LinkNode NODE;

NODE* getNode(int num)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = num;
    newNode->next = NULL;
return newNode;
}

NODE* addNodeBegin(NODE* head, int num)
{
    NODE* newNode = getNode(num);
    newNode->next = head;
return newNode;
}

NODE* addNodeEnd(NODE* head, int num)
{
    NODE* temp=head;
    NODE* newNode = getNode(num);
    if (head == NULL) return newNode;
    while(temp->next !=NULL)
        temp = temp->next;
    temp->next = newNode;
return head;
}
NODE* addNodeBefore(NODE *head , int item , int num)
{
    NODE *curr = head , *prev ;
    int count = 1;
    while (curr->data != item && curr != NULL)
    {
        prev= curr ;
        count++;
        curr = curr->next ;
        if(curr == NULL)
            break ;
    }
    if (count==1)
    {
        head = addNodeBegin(head , num);
        return head ;
    }
    else if (curr == NULL)
    printf("\nElement not found in the List\n");
    else
    {
        NODE* newNode = getNode(num);
        prev->next = newNode;
        newNode->next = curr ;
    }
 return head ;
}
NODE* deleteNodeBegin(NODE* head)
{
    if ( head != NULL)
    {
        NODE* temp = head->next;
        free(head);
        return temp;
    }
    return 0;
}
NODE *reverseList(NODE *head) {
    NODE *curr = head, *prev = NULL, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
 return prev;
}

void DISPLAY25(NODE* h25){
    while (h25 != NULL) {
        printf("%d -> ", h25->data);
        h25 = h25->next;
    }
    printf("NULL\n");
}
// NODE* createList(NODE* head,int size)
// {   int i=0;
//     for(i=1; i<=size;i++)
//         head= addNodeEnd(head,rand()%3);
// return head;
// }
int getSize(NODE* head)
{
    int size=0;
    NODE* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        size = size+1;
    }
return size;
}

// NODE* convert3To9(NODE* head)
// {
//     NODE* temp=head;
//         int count = getSize(head);
//         int r = count % 2 ;
//         if (r == 1) temp = temp->next ;

//         while(temp != NULL)
//         {
//             temp->data = (temp->data*3)+(temp->next->data);
//             temp->next = temp->next->next;
//             temp = temp->next;
//         }
//     return head;
// }
// NODE* convert2to8(NODE* head)
//     {
//         NODE* temp=head;
//         int count = getSize(head);
//         int r = count % 3 ;
//         if (r == 1) temp = temp->next ;
//         if (r == 2)
//         {
//             temp->data = (temp->data*2)+(temp->next->data);
//             temp->next = temp->next->next;
//             temp = temp->next;
//         }
//         while(temp != NULL)
//         {
//             temp->data = (temp->data*4)+(temp->next->data*2)+(temp->next->next->data);
//             temp->next = temp->next->next->next;
//             temp = temp->next;
//         }
//     return head;
// }

// int main()
// {
//     NODE* head=NULL;
//     printf("Base 3 Number:");
//     head = createList(head,40);
//     printList(head);
//     printf("\nBase 9 Number:");
//     head=convert3To9(head);
//     printList(head);
// }
