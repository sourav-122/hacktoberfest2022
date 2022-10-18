import java.util.*;

public class Leetcode237{
    
    //      Definition for singly-linked list.
          public class ListNode {
              int val;
              ListNode next;
              ListNode(int x) { val = x; }
          }

    public static void main(String[] args) {
        
    }

    public void deleteNode(ListNode node) {
        ListNode temp = node;
        temp.val = temp.next.val;
        temp.next = temp.next.next;
        
    }
}