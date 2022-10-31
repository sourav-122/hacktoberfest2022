class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode *t=head;
        //find the length
        while(t){
        l++;
        t=t->next;
        
    }
    //index from front
    l=l-n;
    //case 1
    if(l==0){
    head=head->next;
    return head;
    }
    //case 2
    t=head;
    for(int i=0; i!=l-1; i++)
    {
        t=t->next;
    }
    t->next=(t->next)->next;
    return head;
    }
