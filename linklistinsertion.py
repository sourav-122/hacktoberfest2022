class Node:
 
    
    def __init__(self, data):
        self.data = data  # Assign data
        self.next = None  
 
 
class LinkedList:
 

    def __init__(self):
        self.head = None
 
 
  
    def push(self, new_data):
 
       
        new_node = Node(new_data)
 
 
        new_node.next = self.head
 
        self.head = new_node
 
    def insertAfter(self, prev_node, new_data):
 
        # 1. check if the given prev_node exists
        if prev_node is None:
            print("The given previous node must inLinkedList.")
            return
 
        
        new_node = Node(new_data)
 
        new_node.next = prev_node.next
 
        prev_node.next = new_node
 
 

    def append(self, new_data):
 
 
        new_node = Node(new_data)
 

        if self.head is None:
            self.head = new_node
            return
 
      
        last = self.head
        while (last.next):
            last = last.next
 
        # 6. Change the next of last node
        last.next =  new_node
 
 
    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data,end=" ")
            temp = temp.next
 

if __name__=='__main__':
 
    # Start with the empty list
    llist = LinkedList()
 
    llist.append(6)
 

    llist.push(7);

    llist.push(1);
 
    llist.append(4)
 
    llist.insertAfter(llist.head.next, 8)
 
    print('Created linked list is: ')
    llist.printList()
 
