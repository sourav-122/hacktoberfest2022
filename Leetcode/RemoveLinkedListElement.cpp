class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
       while(head!=NULL && head->val==val)
       {
           head=head->next;
       }
        if(head==NULL)
            return NULL;
        
        ListNode *p=head;
        while(p->next!=nullptr)
        {
            if(p->next->val==val)
            {
                p->next=p->next->next;
            }
            else{
                p=p->next;
            }
        }
        return head;
    }
}
