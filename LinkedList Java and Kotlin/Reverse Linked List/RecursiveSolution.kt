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
    tailrec fun reverseList(head: ListNode?, prev:ListNode?=null): ListNode? {
        head?: return prev

        // First current head.next is passed to fun parameter
        // Then its value is updated in also block
        return reverseList(head.next,head).also {
            head.next = prev
        }
    }
}
