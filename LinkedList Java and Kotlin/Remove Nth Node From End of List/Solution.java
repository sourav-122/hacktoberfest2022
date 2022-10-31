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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode nAhead= head;
        ListNode back=new ListNode(0,head);
        ListNode dummyHead=back;
        
        //Move a pointer to n nodes ahead
        while(n-->0)
            nAhead=nAhead.next;
        
        //Start moving both pointers by one
        while(nAhead!=null) {
            back=back.next;
            nAhead=nAhead.next;
        }
        
        //Remove next of slow pointer as it will be n+1 nodes behind
        back.next = back.next.next;
        
        return dummyHead.next;    
    }
}
