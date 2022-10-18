# created a program to insert new node at the start of the linked list using python.

class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

class LinkedList:
  def __init__(self):
    self.head = None
  def push_front(self, newElement):
    newNode = Node(newElement)
    newNode.next = self.head 
    self.head = newNode   
  def PrintList(self):
    temp = self.head
    if(temp != None):
      print("The list contains:", end=" ")
      while (temp != None):
        print(temp.data, end=" ")
        temp = temp.next
      print()
    else:
      print("The list is empty.")
                 
MyList = LinkedList()
MyList.push_front(10)
MyList.push_front(20)
MyList.push_front(30)
MyList.PrintList()
