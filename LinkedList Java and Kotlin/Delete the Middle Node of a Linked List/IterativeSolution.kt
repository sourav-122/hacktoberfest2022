/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun deleteMiddle(head: ListNode?): ListNode? {
        if(head==null || head.next==null)
            return null;

        //We need to reduce one iteration 
        //thus, fast = fast.next.next
        // So that one slow.next statement is reduced
        // and slow points at element just before middle
        var slow:ListNode? = head
        var fast:ListNode? = head.next.next
        
        while(fast!=null && fast.next!=null) {
            slow=slow!!.next
            fast=fast!!.next?.next
        }
        
        slow?.next= slow?.next?.next
        
        return head
    }
}
