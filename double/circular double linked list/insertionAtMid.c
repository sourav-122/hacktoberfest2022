#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
   
   for (int i = 0; i < 10; i++)
    {
        printf("%d",ptr->data);
        ptr=ptr->prev;
    }
        printf("\n");

}

void insertionAtMid(struct node *head,int poss)
{
    struct node *ptr = head;
    for(int i = 0 ; i < poss-1 ; i++){
        ptr = ptr->next;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 9;
    newNode->next = ptr->next;
    ptr->next = newNode;
   
}
int main()
{
    struct node * head ;
    
    struct node *first = (struct node *)malloc(sizeof(struct node));
    head = first;
    first->next = head;
    first->prev=NULL;
    first->data = 1;

    struct node *second = (struct node *)malloc(sizeof(struct node));
    first->next = second;
    second->next = head;
    second->prev=first;
    first->prev=second;
    second->data = 2;

   int poss = 2;
   insertionAtMid(head,poss);
    display(head);
}
