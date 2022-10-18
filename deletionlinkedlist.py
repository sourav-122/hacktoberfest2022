# Delecting the node of the linked list 
class ListNode:
   def __init__(self, data, next = None):
      self.val = data
      self.next = next
      
def make_list(elements):
   head = ListNode(elements[0])
   for element in elements[1:]:
      ptr = head
      while ptr.next:
         ptr = ptr.next
      ptr.next = ListNode(element)
   return head

def print_list(head):
   ptr = head
   print('[', end = "")
   while ptr:
      print(ptr.val, end = ", ")
      ptr = ptr.next
   print(']')
  
class Solution(object):
   def deleteNode(self, node, data):
      while node.val is not data:
         node = node.next
      node.val = node.next.val
      node.next = node.next.next
      
head = make_list([1,3,5,7,9])
ob1 = Solution()
ob1.deleteNode(head, 3)
print_list(head)
