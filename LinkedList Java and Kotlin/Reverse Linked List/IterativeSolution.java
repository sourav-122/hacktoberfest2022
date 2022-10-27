/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null)
            return head;
        
        //Now the linked list has atleast 2 nodes
        ListNode prev = head;
        ListNode curr=head.next;
        prev.next=null;
        
        do {
            ListNode nextN = curr.next;
            curr.next=prev;
            prev=curr;
            curr=nextN;
        }while(curr!=null);
        
        return prev;
    }
}
