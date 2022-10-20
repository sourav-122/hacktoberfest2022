// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Structure of a node of linked list
struct Node
{
    int data;
    Node *next;
    Node *random;

    // Constructor
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->random = NULL;
    }
};

// inserting new nodes in between
Node* duplicate(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *cur = head;
    while (cur != NULL)
    {
        Node *temp = cur->next;
        cur->next = new Node(cur->data);
        cur->next->next = temp;
        cur = temp;
    }
     head;
    
    //seting random pointer 

    while(cur!=NULL){
        if(cur->next !=NULL){
            cur->next->random = (cur->random!=NULL) ? cur->random->next : NULL;
        }
        cur = cur->next->next;
    }

    // seperating both linked lists 
    Node* org = head;
    Node* copy = head->next;
    Node* temp = copy;
    while(org!= NULL){
        org->next = org->next->next;
        copy->next = copy->next->next;
        org = copy->next;
        copy  = org->next;
    }
    return temp;
}

// Function to print the linked list
void printList(Node *head)
{
    cout << head->data << "("
         << head->random->data << ")";
    head = head->next;
    while (head != NULL)
    {
        cout << " -> " << head->data << "("
             << head->random->data << ")";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main()
{
    // Creating a linked list with random pointer
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    // Print the original list
    cout << "The original linked list:\n";
    printList(head);

    // Function call
    Node *sol = duplicate(head);

    cout << "The cloned linked list:\n";
    printList(sol);

    return 0;
}
