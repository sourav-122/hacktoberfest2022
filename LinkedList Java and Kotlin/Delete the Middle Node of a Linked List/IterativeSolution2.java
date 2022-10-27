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
    public ListNode deleteMiddle(ListNode head) {
        if(head==null || head.next==null)
            return null;

        //We need to reduce one iteration 
        //thus, fast = fast.next.next
        // So that one slow.next statement is reduced
        // and slow points at element just before middle
        ListNode slow=head, fast=head.next.next;
        
        while(fast!=null && fast.next!=null) {
            slow=slow.next;
            fast=fast.next.next;
        }
        
        slow.next= slow.next.next;
        
        return head;
    }
}
