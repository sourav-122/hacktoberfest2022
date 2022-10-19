#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int val=this -> data;

        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory freed for node with data: "<<val<<endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    // insertion at start
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    // insertion at tail
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void deletenode(Node* &head,int pos){
    //deleting first or start node
    if(pos==1){
        Node* temp=head;
        temp -> next -> prev=NULL;
        head=temp -> next;
        temp -> next=NULL;
        delete temp;
    }
    else{
        //deleting any middle node
        Node* curr=head;
        Node* prev=NULL;

        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr -> next;
            count++;
        }

        curr -> prev=NULL;
        prev -> next=curr -> next;
        curr -> next=NULL;
        delete curr;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlen(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    // cout<<getlen(head)<<endl;;

    insertAtHead(head, 6);
    insertAtHead(head, 3);
    insertAtHead(head, 7);
    print(head);

    insertAtTail(tail, 8);
    print(head);

    insertAtPos(head, tail, 3, 0);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deletenode(head,6);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}