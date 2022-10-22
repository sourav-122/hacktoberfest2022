#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node *prev;
};struct node *head=NULL;
struct node *create(struct node *head){
    struct node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert:");
    newnode->next=NULL;
    newnode->prev=NULL;
    scanf("%d",&newnode->data);
    struct node *p;
    if(head==NULL){
        head=newnode;
        p=newnode;
        return head;
    }
    else{
        newnode->prev=p;
        p->next=newnode;
        p=newnode;
        return head;
    }
}
struct node *reverse(struct node *head){
    struct node *previous=NULL;
    struct node *current=head;
    struct node *forward;
    while(current!=NULL){
        forward=current->next;
        current->next=previous;
        current->prev=forward;
        previous=current;
        current=forward;

    }
    return previous;
}
void traversal(struct node *ptr){
    int i=1;
    while(ptr!=NULL){
        printf("Value at node[%d]:%d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
}
int main(){
    int n;
    printf("How many nodes wants to create:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head=create(head);
    }
    traversal(head);
    printf("Doubly Linked List after reverse:\n");
    head=reverse(head);
    traversal(head);
}