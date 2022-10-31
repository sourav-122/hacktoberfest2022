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
    fun removeNthFromEnd(head: ListNode?, n: Int): ListNode? {
        var nAhead= head
        var back=ListNode(0,head)
        val dummyHead=back
        var count = n
        
        //Move a pointer to n nodes ahead
        while(count-->0)
            nAhead=nAhead?.next
        
        //Start moving both pointers by one
        while(nAhead!=null) {
            back=back?.next
            nAhead=nAhead.next
        }
        
        //Remove next of slow pointer as it will be n+1 nodes behind
        back.next = back.next.next
        
        return dummyHead.next
    }
}
