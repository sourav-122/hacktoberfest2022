#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};

void printLinkedList(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ", temp->value);
        temp=temp->next;
    }
    printf("\n");

}

struct node* takeInput(){
    
    struct node* head=NULL;
    struct node* tail=NULL;
    int check=1;
    while(check!=0){
        int data;
        scanf("%d",&data);
        struct node* newNode= (struct node*)malloc(sizeof(struct node));
        newNode->value=data;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        printf("Do you want to take input again!! : ");
        scanf("%d",&check);
        
    }
    return head;
}
struct node* deletionAB(struct node* head){
	struct node* temp=head;
	head=head->next;
	free(temp);
	return head;
}
void deletionAE(struct node* head){
	struct node* temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
}
void deletionATPoint(struct node *head,int pos){
	struct node* temp1=head;
	int count=0;
	while(temp1!=NULL){
		count++;
		temp1=temp1->next;
	}
	if(pos>count){
		printf("Invalid position !!\n");
	}
	else{
		struct node* temp=head;
		int i=1;
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		struct node* temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
	}
}
	int main(){
		struct node* head1=takeInput();
		printLinkedList(head1);
		struct node* head2=deletionAB(head1);
		printLinkedList(head2);
		deletionAE(head2);
		printLinkedList(head2);
		deletionATPoint(head2,2);
		printLinkedList(head2);
		return 0;
	
	
}
