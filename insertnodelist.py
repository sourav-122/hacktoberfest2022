
class Node:
 
   
    def __init__(self, data):
        self.data = data  
        self.next = None  
 
 

class LinkedList:
 
    
    def __init__(self):
        self.head = None
 
 
    # Function to insert a new node at the beginning
    def push(self, x):
 
      
        new_node = Node(x)
 
        new_node.next = self.head
 
       
        self.head = new_node
 
 
    
    def insertAfter(self, prev_node, x):
 
      
        if prev_node is None:
            print("The given previous node must inLinkedList.")
            return
 
       
        new_node = Node(x)
 
        
        new_node.next = prev_node.next
 
        
        prev_node.next = new_node
 
 
   
    def append(self, x):
 
        new_node = Node(x)
 
        if self.head is None:
            self.head = new_node
            return
 
        last = self.head
        while (last.next):
            last = last.next
 
        last.next =  new_node
 
 
    
    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data,end=" ")
            temp = temp.next
 
 
 
# Code execution starts here
if __name__=='__main__':
 
    
    llist = LinkedList()
 
  
    llist.append(6)
 
    llist.push(7);
 
   
    llist.push(1);
 

    llist.append(4)
 
    llist.insertAfter(llist.head.next, 8)
 
    print('Created linked list is: ')
    llist.printList()
