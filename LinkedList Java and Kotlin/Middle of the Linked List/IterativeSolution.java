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
    public ListNode middleNode(ListNode head) {
        // Use head as slow pointer
        // Use fast as fast pointer
        ListNode fast=head;
        while(fast!=null && fast.next!=null) {
            head=head.next;
            fast=fast.next.next;    
        }
        
        return head;
    }
}
