#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
}*start=NULL;
void create(int);
int IsEmpty();
int NodeCount();
void traverse();
void delete();
void Delete(int);
void add(int);
void Add(int ,int );
void reverse(int);
void main()
{
    int ch,n=1;
    do{
        printf("1 - Create List\n2 - Display\n3 - Add Node at starting position\n4 - Add node at Nth position\n5 - Deletion of First Node\n6 - Deletion of Node at Nth position\n7 - reverse \n8 - exit");
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter data in node : ");
                int dat;
                scanf("%d",&dat);
                create(dat);
                break;
            case 2:
                traverse();
                break;
            case 3:
                printf("\nEnter data in first node : ");
                int dat1;
                scanf("%d",&dat1);
                add(dat1);
                break;
            case 4:
                printf("\nEnter position at which do you want to add node : ");
                int position;
                scanf("%d",&position);
                printf("Enter data you want to add at that position : ");
                int value;
                scanf("%d",&value);
                Add(position,value);
                break;
            case 5:
                delete();
                break;
            case 6:
                printf("\nEnter position of deletion : ");
                int p;
                scanf("%d",&p);
                Delete(p);
                break;
            case 7:
                int c=NodeCount();
                reverse(c);
                break;
            case 8:
                exit(0);
        }
        printf("\nPress 1 to continue OR 0 to exit : ");
        scanf("%d",&n);
    }while(n==1);
}
int NodeCount()
{
    struct node *temp=start;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void reverse(int n)
{
    int ar[n];
    int i=0;
    struct node *temp=start;
    while(temp!=NULL)
    {
        ar[i++]=temp->data;
        temp=temp->next;
    }
    int k=i-1;
    struct node *t1=start;
    while(t1!=NULL)
    {
        t1->data=ar[k--];
        t1=t1->next;
    }
}

int IsEmpty()
{
    if(start==NULL)
        return 1;
    else 
        return 0;
}
void create(int n1)
{
    struct node *temp;
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=n1;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
void traverse()
{
    printf("The link list :\n");
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
   
}
void Add(int p,int v)
{
    struct node *t1,*t2;
    int count=1;
    t1=start;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=v;
    while(count < p-1 && t1!=NULL)
    {   
        t1=t1->next;
        count++;
    }
    t2=t1->next;
    t1->next=temp;
    temp->next=t2;
}
void add(int n1)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n1;
    temp->next=start;
    start=temp;
}
void delete()
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp=start;
    start=start->next;
    free(temp);
}
void Delete(int p)
{
    struct node *t1;
    int count=1;
    t1=start;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    while(count < p-1 && t1!=NULL)
    {   
        t1=t1->next;
        count++;
    }
    temp=t1->next;
    t1=t1->next;
    free(temp);
}