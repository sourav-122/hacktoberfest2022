#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data=d;
        this -> next=NULL;
    }

    //DESTRUCTOR
    ~Node(){
        int val=this -> data;

        if(this -> next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory freed for node with value: "<<val<<endl;
    }
};

void insertNode(Node* &tail,int element,int d){
    //empty list
    if(tail==NULL){
        Node* newnode=new Node(d);
        tail=newnode;
        newnode -> next=newnode;
    }

    //non-empty list
    else{
        Node* curr=tail;

        while(curr -> data!=element){
            curr=curr -> next;
        }

        //element found
        Node* temp =new Node(d);
        temp -> next=curr -> next;
        curr -> next=temp;
    }
}

void deleteNode(Node* &tail,int element){
    //empty list
    if(tail==NULL){
        cout<<"List is already empty!"<<endl;
        return;
    }

    else{
        Node* prev=tail;
        Node* curr=prev -> next;

        while(curr -> data!=element){
            prev=curr;
            curr=curr -> next;
        }

        prev -> next=curr -> next;
        //1 node ll
        if(prev ==curr){
            tail = NULL;
        }

        //>=2 node ll
        else if(tail==curr){
            tail=prev;
        }

        curr -> next=NULL;
        delete curr;
    }
}

void print(Node* tail){
    Node* temp=tail;

    //empty list
    if(tail==NULL){
        cout<<"List is empty!"<<endl;
    }

    do{
        cout<<tail -> data<<" ";
        tail=tail -> next;
    }while(tail!=temp);
    cout<<endl;
}

int main(){
    Node* tail=NULL;

    insertNode(tail,5,1);
    print(tail);

    insertNode(tail,1,2);
    print(tail);
    
    insertNode(tail,2,4);
    print(tail);

    insertNode(tail,2,3);
    print(tail);

    deleteNode(tail,1);
    print(tail);
}