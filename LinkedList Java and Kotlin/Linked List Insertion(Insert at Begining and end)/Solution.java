/*
class Node{
    int data;
    Node next;
    
    Node(int x){
        data = x;
        next = null;
    }
}
*/
class Solution
{
    //Function to insert a node at the beginning of the linked list.
    Node insertAtBeginning(Node head, int x)
    {
        Node first=new Node(x);
        first.next=head;
        return first;
    }
    
    //Function to insert a node at the end of the linked list.
    Node insertAtEnd(Node head, int x)
    {
        if(head==null) {
            head=new Node(x);
            return head;
        }
        
        Node temp=head;
        while(temp.next!=null)
            temp=temp.next;
            
        Node last = new Node(x);
        temp.next=last;
        
        return head;
    }
}
