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
    fun mergeTwoLists(list1Fixed: ListNode?, list2Fixed: ListNode?): ListNode? {
        val mergeHead = ListNode(0)
        var curr=mergeHead
        var list1=list1Fixed
        var list2=list2Fixed
        
        while(list1!=null && list2!=null) {
            if(list2.`val`>=list1.`val`) {
                curr.next = list1
                list1=list1.next
            }
            else {
                curr.next=list2
                list2=list2.next
            }
            curr=curr.next
        }
        
        curr.next = if(list1==null)  list2 else list1
        return mergeHead.next
    }
}
