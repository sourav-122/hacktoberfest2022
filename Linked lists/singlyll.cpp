#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data=data;
        this -> next=NULL;
    }

    //destructor
    ~Node(){
        int value=this -> data;
        //memory free
        if(this -> next!=NULL){
            delete next;
            this -> next=NULL;
        }
        cout<<"Memory freed for node with data: "<<value<<endl;
    }

};

void insertAtHead(Node* &head,int d){
    //creating new node
    Node* temp= new Node(d);

    temp -> next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int d){
    //creating new node
    Node* temp= new Node(d);

    tail -> next=temp;
    tail=temp;
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //insert at start
    if(position==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp=head;
    int count=1;

    while(count<position-1){
        temp= temp -> next;
        count++;
    }

    //insert at tail
    if(temp -> next==NULL){
        insertAtTail(tail,d);
        return;
    }

    //creating a node for d
    Node* nodetoinsert= new Node(d);
    nodetoinsert -> next= temp -> next;
    temp -> next= nodetoinsert;
}

void deletenode(Node* &head,int pos){
    //deleting first or start node
    if(pos==1){
        Node* temp=head;
        head=head -> next;
        //free start node
        temp -> next=NULL;
        delete temp;
    }

    else{
        //deleting any middle or last node
        Node* curr=head;
        Node* prev=NULL;

        int count=1;
        while(count<pos){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next=curr -> next;
        curr -> next= NULL;
        delete curr;
    }
}

void print(Node* &head){
    if(head ==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }

    Node* temp=head;

    while(temp!= NULL){
        cout<<temp -> data<<" ";
        temp=temp -> next;
    }
    cout<<endl;
}

int main(){
    //creating a new node
    Node* node1= new Node(100);
    //cout<<node1 -> data<<endl;
    //cout<<node1 -> next<<endl;

    //head pointing to new node
    Node* head=node1;
    Node* tail=node1;
    print(head);

    insertAtHead(head,12);
    print(head);

    insertAtHead(head,0);
    print(head);

    insertAtTail(tail,9);
    print(head);

    insertAtPosition(head,tail,4,69);
    print(head);

    cout<<"head: "<<head -> data<<endl;
    cout<<"tail: "<<tail -> data<<endl;

    deletenode(head,5);
    print(head);

    cout<<"head: "<<head -> data<<endl;
    cout<<"tail: "<<tail -> data<<endl;

    return 0;
}