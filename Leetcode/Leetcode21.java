import java.util.*;

public class Leetcode21 {
    // Definition for singly-linked list.
    class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    public static void main(String[] args) {
        
    }
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode head = null;
        ListNode p = list1;
        ListNode q = list2;
        ListNode r = head;
        while(p != null && q != null){
            if(p.val > q.val){
                ListNode temp = new ListNode(q.val);
                if(head == null){
                    head = temp;
                    r = head;
                }
                r.next = temp;
                q = q.next;
                r = r.next;
            }
            else if(p.val < q.val){
                ListNode temp = new ListNode(p.val);
                if(head == null){
                    head = temp;
                    r = head;
                }
                r.next = temp;
                p = p.next;
                r = r.next;
            }
            else{
                ListNode temp = new ListNode(p.val);
                ListNode temp1 = new ListNode(p.val);
                if(head == null){
                    head = temp;
                    r = head;
                }
                r.next = temp;
                p = p.next;
                q = q.next;
                r = r.next;
                r.next = temp1;
                r = r.next;
            }
        }
        while(p != null){
            ListNode temp = new ListNode(p.val);
            if(head == null){
                    head = temp;
                r = head;
                }
                r.next = temp;
                p = p.next;
                r = r.next;
            r.next = null;
        }
        while(q != null){
            ListNode temp = new ListNode(q.val);
            if(head == null){
                    head = temp;
                r = head;
                }
                r.next = temp;
                q = q.next;
                r = r.next;
                r.next = null;
        }
        return head;
    }

}
